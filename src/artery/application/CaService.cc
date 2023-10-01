/*
* Artery V2X Simulation Framework
* Copyright 2014-2019 Raphael Riebl et al.
* Licensed under GPLv2, see COPYING file for detailed license and warranty terms.
*/

//@dnat
//version: 0.2_2023-10-01

/* ONDE FICA O CODIGO DE RECEPCAO DE CAMS????
 * O OMNET++ disponibiliza uma função padrão, da classe cSimpleModule, para o tratamento
 * de recepções de mensagens. Buscar essa função aqui no CaService.
 */

#include "artery/application/CaObject.h"
#include "artery/application/CaService.h"
#include "artery/application/Asn1PacketVisitor.h"
#include "artery/application/MultiChannelPolicy.h"
#include "artery/application/VehicleDataProvider.h"
#include "artery/utility/simtime_cast.h"
#include "veins/base/utils/Coord.h"
#include <boost/units/cmath.hpp>
#include <boost/units/systems/si/prefixes.hpp>
#include <omnetpp/cexception.h>
#include <vanetza/btp/ports.hpp>
#include <vanetza/dcc/transmission.hpp>
#include <vanetza/dcc/transmit_rate_control.hpp>
#include <vanetza/facilities/cam_functions.hpp>
#include <chrono>

namespace artery
{

using namespace omnetpp;

auto microdegree = vanetza::units::degree * boost::units::si::micro;
auto decidegree = vanetza::units::degree * boost::units::si::deci;
auto degree_per_second = vanetza::units::degree / vanetza::units::si::second;
auto centimeter_per_second = vanetza::units::si::meter_per_second * boost::units::si::centi;

/******
 * Os sinais "CamReceived" e "CamSent" são definidos no arquivo .ned.
 * La também são definidos quais dados são gravados nos resultados. Mas como acrescentar mais dados nos resultados??
 */
static const simsignal_t scSignalCamReceived = cComponent::registerSignal("CamReceived");
static const simsignal_t scSignalCamSent = cComponent::registerSignal("CamSent");
static const auto scLowFrequencyContainerInterval = std::chrono::milliseconds(500);

template<typename T, typename U>
long round(const boost::units::quantity<T>& q, const U& u)
{
	boost::units::quantity<U> v { q };
	return std::round(v.value());
}


#include <iostream>
#include <cmath>

// Função para calcular a distância usando a fórmula de Haversine
#include <iostream>
#include <cmath>

#include <iostream>
#include <cmath>

#include <iostream>
#include <cmath>

double CAM_X, CAM_Y;


SpeedValue_t buildSpeedValue(const vanetza::units::Velocity& v)
{
	static const vanetza::units::Velocity lower { 0.0 * boost::units::si::meter_per_second };
	static const vanetza::units::Velocity upper { 163.82 * boost::units::si::meter_per_second };

	SpeedValue_t speed = SpeedValue_unavailable;
	if (v >= upper) {
		speed = 16382; // see CDD A.74 (TS 102 894 v1.2.1)
	} else if (v >= lower) {
		speed = round(v, centimeter_per_second) * SpeedValue_oneCentimeterPerSec;
	}
	return speed;
}

//Funçao OMNET++ para registrar uma classe
Define_Module(CaService)

//Construtor da classe
CaService::CaService() :
		mGenCamMin { 100, SIMTIME_MS },
		mGenCamMax { 1000, SIMTIME_MS },
		mGenCam(mGenCamMax),
		mGenCamLowDynamicsCounter(0),
		mGenCamLowDynamicsLimit(3)
{
}

//@dnat
// Função para calcular a distância usando a fórmula de Haversine
/*
* HAVERSINE: a fórmula de Haversine é uma das fórmulas mais simples para calcular a distância entre dois pontos geográficos em uma esfera
*  (ou aproximadamente em uma esfera, como a Terra). Ela é adequada para distâncias curtas e usa coordenadas de latitude e longitude em graus.
*  A distância (d) entre dois pontos (lat1, lon1) e (lat2, lon2) é calculada da seguinte forma:
*  a = sin²((lat2 - lat1) / 2) + cos(lat1) * cos(lat2) * sin²((lon2 - lon1) / 2)
*  c = 2 * atan2(sqrt(a), sqrt(1 - a))
*  d = R * c
*
* Onde:
*  lat1 e lat2 = as latitudes dos pontos em radianos
*  lon1 e lon2 = as longitudes dos pontos em radianos
*  R = o raio da Terra (em unidades de escolha, como quilômetros ou milhas)
*/
double CaService::haversine(double lat1, double lon1, double lat2, double lon2) {
	// Raio da Terra em quilômetros
	const double r = 6371.0;

	// Converte graus em radianos
	lat1 = lat1 * M_PI / 180.0;
	lon1 = lon1 * M_PI / 180.0;
	lat2 = lat2 * M_PI / 180.0;
	lon2 = lon2 * M_PI / 180.0;

	// Diferenças nas latitudes e longitudes
	double dlat = lat2 - lat1;
	double dlon = lon2 - lon1;

	// Fórmula de Haversine
	double a = sin(dlat / 2) * sin(dlat / 2) + cos(lat1) * cos(lat2) * sin(dlon / 2) * sin(dlon / 2);
	double c = 2 * atan2(sqrt(a), sqrt(1 - a));

	// Distância em quilômetros
	double distance_km = r * c;

	// Converta para metros
	double distance_m = distance_km * 1000;

	return distance_m;
}


//@dnat
// Função para calcular a distância usando a fórmula de Vincenty
/*
 * VINCENTY: a fórmula de Vincenty é mais precisa do que a fórmula de Haversine e é adequada para cálculos de distâncias maiores na Terra.
 * Ela leva em consideração a forma elipsoidal da Terra e utiliza coordenadas de latitude, longitude e altitude.
 * A distância (s) entre dois pontos (lat1, lon1, alt1) e (lat2, lon2, alt2) é calculada da seguinte forma:
 *
 * a = semimajor axis (raio do equador)
 * b = semiminor axis (raio do polo)
 * f = flattening (achatamento da Terra)
 *
 * L = lon2 - lon1
 * U1 = atan((1 - f) * tan(lat1))
 * U2 = atan((1 - f) * tan(lat2))
 * sinU1 = sin(U1), cosU1 = cos(U1)
 * sinU2 = sin(U2), cosU2 = cos(U2)
 *
 * lambda = L, lambdaP = 2 * pi
 * iterLimit = 100
 * while (|lambda - lambdaP| > 1e-12 and iter < iterLimit):
 *     sinLambda = sin(lambda), cosLambda = cos(lambda)
 *     sinSigma = sqrt((cosU2 * sinLambda) * (cosU2 * sinLambda) + (cosU1 * sinU2 - sinU1 * cosU2 * cosLambda) * (cosU1 * sinU2 - sinU1 * cosU2 * cosLambda))
 *     cosSigma = sinU1 * sinU2 + cosU1 * cosU2 * cosLambda
 *     sigma = atan2(sinSigma, cosSigma)
 *     sinAlpha = cosU1 * cosU2 * sinLambda / sinSigma
 *     cosSqAlpha = 1 - sinAlpha * sinAlpha
 *     cos2SigmaM = cosSigma - 2 * sinU1 * sinU2 / cosSqAlpha
 *     C = f / 16 * cosSqAlpha * (4 + f * (4 - 3 * cosSqAlpha))
 *     lambdaP = lambda
 *     lambda = L + (1 - C) * f * sinAlpha * (sigma + C * sinSigma * (cos2SigmaM + C * cosSigma * (-1 + 2 * cos2SigmaM * cos2SigmaM)))
 * s = b * atan2(sqrt(1 + (1 - f) * (1 - f) * cosAlpha * cosAlpha) * sinAlpha, cosAlpha)
 *
 * Onde:
 *  lat1, lat2 = as latitudes dos pontos em radianos.
 *  lon1, lon2 = as longitudes dos pontos em radianos.
 *  alt1, alt2 = as altitudes dos pontos acima do elipsoide (geralmente em metros)
 *  a = o semieixo maior da Terra
 *  b = o semieixo menor da Terra
 *  f = o achatamento da Terra
 */
double CaService::vincenty(double lat1, double lon1, double alt1, double lat2, double lon2, double alt2) {
	// Raio médio da Terra (semi-eixo maior) em metros
	const double a = 6378137.0;

	// Achatamento da Terra (f) - aproximadamente 1/298.257223563
	const double f = 1 / 298.257223563;

	// Cálculos de latitude reduzida
	double lat1_rad = atan((1 - f) * tan(lat1 * M_PI / 180.0));
	double lat2_rad = atan((1 - f) * tan(lat2 * M_PI / 180.0));

	// Diferenças nas longitudes
	double lon_diff = abs(lon2 - lon1) * M_PI / 180.0;

	// Cálculos intermediários
	double sin_lat1 = sin(lat1_rad);
	double cos_lat1 = cos(lat1_rad);
	double sin_lat2 = sin(lat2_rad);
	double cos_lat2 = cos(lat2_rad);

	// Fórmula de Vincenty
	double numerator = sqrt(pow(cos_lat2 * sin(lon_diff), 2) + pow(cos_lat1 * sin_lat2 - sin_lat1 * cos_lat2 * cos(lon_diff), 2));
	double denominator = sin_lat1 * sin_lat2 + cos_lat1 * cos_lat2 * cos(lon_diff);

	// Ângulo azimutal inicial entre os pontos
	double azimuth1 = atan2(cos_lat2 * sin(lon_diff), cos_lat1 * sin_lat2 - sin_lat1 * cos_lat2 * cos(lon_diff));

	// Cálculo da distância
	double s = atan2(numerator, denominator);
	double distance = s * a;

	return distance;
}


void CaService::initialize() {
	ItsG5BaseService::initialize();
	mNetworkInterfaceTable = &getFacilities().get_const<NetworkInterfaceTable>();
	mVehicleDataProvider = &getFacilities().get_const<VehicleDataProvider>();
	mTimer = &getFacilities().get_const<Timer>();
	mLocalDynamicMap = &getFacilities().get_mutable<artery::LocalDynamicMap>();

	// avoid unreasonable high elapsed time values for newly inserted vehicles
	mLastCamTimestamp = simTime();

	//Abrindo arquivo para escrita de dados
	//this->logfile_CAM.open("./results/InfoCAMs.csv");

	// first generated CAM shall include the low frequency container
	mLastLowCamTimestamp = mLastCamTimestamp - artery::simtime_cast(scLowFrequencyContainerInterval);

	// generation rate boundaries
	mGenCamMin = par("minInterval");
	mGenCamMax = par("maxInterval");
	mGenCam = mGenCamMax;

	// vehicle dynamics thresholds
	mHeadingDelta = vanetza::units::Angle { par("headingDelta").doubleValue() * vanetza::units::degree };
	mPositionDelta = par("positionDelta").doubleValue() * vanetza::units::si::meter;
	mSpeedDelta = par("speedDelta").doubleValue() * vanetza::units::si::meter_per_second;

	mDccRestriction = par("withDccRestriction");
	mFixedRate = par("fixedRate");

	// look up primary channel for CA
	mPrimaryChannel = getFacilities().get_const<MultiChannelPolicy>().primaryChannel(vanetza::aid::CA);

	// Gravando dados de inicializacao da simulacao
	//this->logfile_CAM << "time,vehicle,position,payload\n";

	//@dnat
	//std::cout << "ID: " << mVehicleDataProvider->station_id() << endl; //DEBUG ONLY
}

void CaService::trigger()
{
	Enter_Method("trigger");
	checkTriggeringConditions(simTime());

}


// Acho que é nesta função que a recepção de CAMs é realizada
// Como solicitar que o ID da mensagem seja incluida nos traces de resultados
void CaService::indicate(const vanetza::btp::DataIndication& ind, std::unique_ptr<vanetza::UpPacket> packet) {
	Enter_Method("indicate");

	Asn1PacketVisitor<vanetza::asn1::Cam> visitor;
	const vanetza::asn1::Cam* cam = boost::apply_visitor(visitor, *packet);
	if (cam && cam->validate()) {
		CaObject obj = visitor.shared_wrapper;
		emit(scSignalCamReceived, &obj);
		mLocalDynamicMap->updateAwareness(obj);

	    //@dnat /////////////////////////////////////////////////
		/* Estou fazendo testes com os veiculos: ID:11 e ID96
		 * ID:96 enviando a msg CAM e ID:11 recebendo a msg CAM
		*/
		// //////////////////////////////////////////////////////

		// se veículo ID:11 está recebendo uma msg CAM do veículo ID:96...
	    if (mVehicleDataProvider->station_id() == 11 and (*cam)->header.stationID == 96) {
			auto posCamLat = (*cam)->cam.camParameters.basicContainer.referencePosition.latitude;  //obtém a latitude do veículo ID:96 na msg CAM
			auto posCamLon = (*cam)->cam.camParameters.basicContainer.referencePosition.longitude; //obtém a longitude do veículo ID:96 na msg CAM

			double lat1, lat2, lon1, lon2, alt1, alt2; //variáveis temporárias: latitude, longitude e altitude (esta usada apenas na eq. de Vincenty)
			double X = 0, Y = 0, d = 0, D = 0;		   //variáveis temporárias para o "cálculo de prova" (veja explicação a diante)

			/*
			 *  Latitude/Longitude são recebidas na msg CAM como inteiros, mas precisamos converte-las para float
			 *  Para isso, dividimos por 10.000.000
			 *
			 *  Ex.:
			 *  Latitude recebida: 492529854
			 *  Latitude convertida: 492529854 / 10000000.0 = 49.2529854
			*/
			lat1 = posCamLat/10000000.0; //converte para float a latitude recebida
			lon1 = posCamLon/10000000.0; //converte para float a latitude recebida

			/*
			 * Aqui eu obtenho as coordenadas (latitude/longitude) atuais do veiculo que está recebendo a msg CAM
			*/
			const PositionProvider* mPositionProvider1 = nullptr;
			mPositionProvider1 = &getFacilities().get_const<PositionProvider>(); //tipo de dados (struct) contendo latidude e longitude
			lat2 = mPositionProvider1->getGeodeticPosition().latitude.value();	 //pego somente a latitude
			lon2 = mPositionProvider1->getGeodeticPosition().longitude.value();	 //pego somente a longitude

			/*
			 * A fim de encontrar a melhor formula para calcular a distancias entre os dois nós, implementei as formulas de *Haversine* e *Vincenty*
			 * Harversine é mais simples
			 * Vincenty é mais complexa e leva em consideração a altitudo, que neste caso estou setando em ZERO
			 *
			 * De acordo com a documentação do Atery,
			 * "GeoPosition representa um dado geodésico horizontal (latitude e longitude). Salvo indicação em contrário, o dado refere-se ao elipsóide WGS84".
			 *
			 *  Uma coordenada geodésica (ou geodética) é um sistema de coordenadas que descreve a posição de um ponto na superfície de um objeto tridimensional,
			 *  como a Terra, usando valores de latitude, longitude e altitude (ou altura) acima de uma superfície de referência, geralmente um elipsoide que se
			 *  ajusta ao formato da Terra. Aqui está uma breve explicação dos componentes das coordenadas geodésicas:
			 *
			 *  Latitude: é a medida angular da posição de um ponto em relação ao equador terrestre. Ela varia de -90 graus (pólo sul) a +90 graus (pólo norte)
			 *  e é representada em graus, minutos e segundos (por exemplo, 40° 26' 46" N). A latitude 0° corresponde à linha do equador.
			 *
			 *  Longitude: é a medida angular da posição de um ponto em relação ao meridiano de Greenwich (ou outro meridiano de referência).
			 *  Ela varia de -180 graus a +180 graus e também é representada em graus, minutos e segundos (por exemplo, 73° 58' 26" W). A longitude 0°
			 *  corresponde ao meridiano de Greenwich.
			 *
			 *  Altitude (ou Altura): é a distância vertical de um ponto em relação a uma superfície de referência. Geralmente, a altitude é medida em metros
			 *  acima ou abaixo de um elipsoide de referência, como o WGS 84 (World Geodetic System 1984).
			 *
			 *  As coordenadas geodésicas são usadas para descrever a localização precisa de pontos na Terra ou em outros corpos celestes. Elas são amplamente
			 *  utilizadas em geodésia, cartografia, navegação, geofísica e em muitas outras disciplinas que envolvem a representação precisa da superfície da
			 *  Terra ou a localização de objetos na Terra.
			 *  É importante notar que, para cálculos de distância precisa entre pontos na superfície da Terra, especialmente em distâncias maiores (que não é
			 *  o nosso caso), é necessário levar em consideração a forma elipsoidal da Terra, em vez de assumir uma esfera perfeita. Isso é feito usando
			 *  fórmulas geodésicas como a fórmula de Vincenty.
			*/
			// Calcula a distância entre dois pontos no Globo Terrestre usando a equação de Vincenty
			double distanceV_m = vincenty(lat1, lon1, 0, lat2, lon2, 0);

			// Calcula a distância entre dois pontos no Globo Terrestre usando a equação de Haversine
			double distanceH_m = haversine(lat1, lon1, lat2, lon2);

			/*
			 *  "CALCULO DE PROVA"
			 *    d = √((x2 - x1)² + (y2 - y1)²)
			 *
			 *   o "cálculo de prova" é um cálculo realizado obtendo a posição em metros (x,y) do veículo que recebe a msg CAM
			 *   e a posição em metros (x,y) do veículo que envia a msg CAM. Utiliza-se a distância Euclidiana para este cálculo.
			 *   Como a posição (x,y) não e enviada na msg CAM (somente coordenadas lat/long), para fazer esse teste, eu criei duas variáveis globais,
			 *   CAM_X e CAM_Y, que são setadas com as posições X e Y, respectivamente, do veículo que envia a msg CAM (neste exemplo o ID:96).
			 *   Por se tratar de uma variável global desta classe, todos os veículos podem acessá-la.
			 *
			 *   Desta forma, o veículo que recebe a msg CAM faz o cálculo que chamei de "calculo de prova", a fim de verificar se os
			 *   cálculos com as equações de Harvesine e Vinventy convergem.
			*/
			// Variáveis usadas no "cálculo de prova", que recebem a posição X,Y do veículo que recebe a msg CAM
			double CAR_X = mVehicleDataProvider->position().x.value(); //variável temporária para a posição X do veículo que recebeu a msg CAM
			double CAR_Y = mVehicleDataProvider->position().y.value(); //variável temporária para a posição X do veículo que recebeu a msg CAM

			X = pow((CAM_X - CAR_X), 2); //diferença entre o X do veículo que recebeu e o X do veículo que enviou a msg CAM, elevado ao quadrado = (x1-x2)²
			Y = pow((CAM_Y - CAR_Y), 2); //diferença entre o Y do veículo que recebeu e o Y do veículo que enviou a msg CAM, elevado ao quadrado = (y1-y2)²
			D = sqrt(X+Y); //a distância (D) é a raíz quadrada da soma dos valores encontrados nas duas equações anteriores

			/*
			 * Print information:
			 * ID Sent: ID do veículo que enviou a msg CAM
			 * ID Recv: ID do veículo que recebeu a msg CAM
			 *
			 * H: distância obtida usando a equação de Haversine
			 * V: distância obtida usando a equação de Vincenty
			 * E: distância Euclidiana - "cálculo de prova"
			 */
			std::cout << "ID Sent: " << (*cam)->header.stationID << " Lat/Lon: " << lat1 << "/" << lon1; //print information
			std::cout << " | ID Recv: " << mVehicleDataProvider->station_id() << " Lat/Lon: " << lat2 << "/" << lon2; //print information
			std::cout << " | Dist. V: " << distanceV_m << " / H: " << distanceH_m << " / E: " << D << endl;
         }
	}

/*  // DISTANCIA -- [ OK ]
    //@dnat///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //std::cout << "@dnat - Estou em: CaService.cc - indicate() | SimTime:" << simTime() << endl;
    std::cout << "ID: " << mVehicleDataProvider->station_id() << " | ";

    // Obtém a velocidade
    vanetza::units::Velocity vehicleSpeed = mVehicleDataProvider->speed();

    // Converte a velocidade para um valor de ponto flutuante
    double speedValue = vehicleSpeed.value();

    // Imprime a velocidade
    std::cout << "Speed: " << speedValue << " m/s | ";

    // Imprime a posição (x,y)
    //std::cout << "Position (x, y): (" << mVehicleDataProvider->position().x.value() << "m, ";
    //std::cout << mVehicleDataProvider->position().y.value() << "m)" << endl;

    // Imprime a posição (latitude,longitude)  -- ONT WORK
    //std::cout << "Position (lat, lon): (" << mVehicleDataProvider->position().latitude.value() << "m, ";
    //std::cout << mVehicleDataProvider->position().longitude.value() << "m)" << endl;

    //artery::Position vehiclePosition = mVehicleDataProvider->position();
    //double positionValue = vehiclePosition.x().value(); //vehiclePosition.value();
    //std::cout << "Latitude: " << vehiclePosition->x() << std::endl;
    //std::cout << "Longitude: " << vehiclePosition->y() << std::endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
}

void CaService::checkTriggeringConditions(const SimTime& T_now)
{
	// provide variables named like in EN 302 637-2 V1.3.2 (section 6.1.3)
	SimTime& T_GenCam = mGenCam;
	const SimTime& T_GenCamMin = mGenCamMin;
	const SimTime& T_GenCamMax = mGenCamMax;
	const SimTime T_GenCamDcc = mDccRestriction ? genCamDcc() : T_GenCamMin;
	const SimTime T_elapsed = T_now - mLastCamTimestamp;

	if (T_elapsed >= T_GenCamDcc) {
		if (mFixedRate) {
			sendCam(T_now);
		} else if (checkHeadingDelta() || checkPositionDelta() || checkSpeedDelta()) {
			sendCam(T_now);
			T_GenCam = std::min(T_elapsed, T_GenCamMax); /*< if middleware update interval is too long */
			mGenCamLowDynamicsCounter = 0;
		} else if (T_elapsed >= T_GenCam) {
			sendCam(T_now);
			if (++mGenCamLowDynamicsCounter >= mGenCamLowDynamicsLimit) {
				T_GenCam = T_GenCamMax;
			}
		}
	}
}

bool CaService::checkHeadingDelta() const
{
	return !vanetza::facilities::similar_heading(mLastCamHeading, mVehicleDataProvider->heading(), mHeadingDelta);
}

bool CaService::checkPositionDelta() const
{
	return (distance(mLastCamPosition, mVehicleDataProvider->position()) > mPositionDelta);
}

bool CaService::checkSpeedDelta() const
{
	return abs(mLastCamSpeed - mVehicleDataProvider->speed()) > mSpeedDelta;
}

void CaService::sendCam(const SimTime& T_now)
{
	uint16_t genDeltaTimeMod = countTaiMilliseconds(mTimer->getTimeFor(mVehicleDataProvider->updated()));
	auto cam = createCooperativeAwarenessMessage(*mVehicleDataProvider, genDeltaTimeMod);

	/*
	 * VehicleDataProvider tem um parametro Position. Position é uma struct com os itens x e y.
	 * Há também a struct GeoPosition que contem latitude e longetude.
	 * Pode ser que apenas x e y sejam suficientes para os meus testes.
	 */
	mLastCamPosition = mVehicleDataProvider->position();
	mLastCamSpeed = mVehicleDataProvider->speed();
	mLastCamHeading = mVehicleDataProvider->heading();
	mLastCamTimestamp = T_now;
	if (T_now - mLastLowCamTimestamp >= artery::simtime_cast(scLowFrequencyContainerInterval)) {
		addLowFrequencyContainer(cam, par("pathHistoryLength"));
		mLastLowCamTimestamp = T_now;
	}

	using namespace vanetza;
	btp::DataRequestB request;
	request.destination_port = btp::ports::CAM;
	request.gn.its_aid = aid::CA;
	request.gn.transport_type = geonet::TransportType::SHB;
	request.gn.maximum_lifetime = geonet::Lifetime { geonet::Lifetime::Base::One_Second, 1 };
	request.gn.traffic_class.tc_id(static_cast<unsigned>(dcc::Profile::DP2));
	request.gn.communication_profile = geonet::CommunicationProfile::ITS_G5;

	CaObject obj(std::move(cam));
	// scSignalCamSent é associado ao CamSent definido no .ned.
	emit(scSignalCamSent, &obj);

	using CamByteBuffer = convertible::byte_buffer_impl<asn1::Cam>;
	std::unique_ptr<geonet::DownPacket> payload { new geonet::DownPacket() };
	std::unique_ptr<convertible::byte_buffer> buffer { new CamByteBuffer(obj.shared_ptr()) };
	payload->layer(OsiLayer::Application) = std::move(buffer);
	/*
	 * request é uma função implementada em ItsG5BaseService e ItsG5Service. Ela requisita o envio de mensagens a um
	 * middleware previamente definido.
	 */
	this->request(request, std::move(payload));
	// Gravando dados da mensagem enviada
    //this->logfile_CAM << "Position:" << mVehicleDataProvider->position() << ",Speed:" << mVehicleDataProvider->speed();
    //std::cout << "Position:" << mVehicleDataProvider->position() << ",Speed:" << mVehicleDataProvider->speed() << endl;
	//std::cout << mVehicleDataProvider->speed();
	//std::cout << "Position:" << mVehicleDataProvider->position() << ",Speed:" << mVehicleDataProvider->speed();

    //@dnat///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (mVehicleDataProvider->station_id() == 96) {
		CAM_X = mVehicleDataProvider->position().x.value();
		CAM_Y = mVehicleDataProvider->position().y.value();
	}


	//@dnat///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    /*
	if (mVehicleDataProvider->station_id() == 11) {
        std::cout << "SimTIme: " << simTime() << " | MyID: " << mVehicleDataProvider->station_id() << " | msg sent -->" << endl;
    } */




	/* DISTANCIA PERCORRIDA -- [ OK ]
    //@dnat///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (mVehicleDataProvider->station_id() == 11) {
	    //std::cout << "@dnat - Estou em: CaService.cc - indicate() | SimTime:" << simTime() << endl;
	    std::cout << "SimTime: " << simTime() << " | ID: " << mVehicleDataProvider->station_id() << " | ";
	    // Obtém a velocidade
	    vanetza::units::Velocity vehicleSpeed = mVehicleDataProvider->speed();
	    // Converte a velocidade para um valor de ponto flutuante
	    double speedValue = vehicleSpeed.value();
	    // Imprime a velocidade
	    std::cout << "Speed: " << speedValue << " m/s | ";
	    // Imprime a posição (x,y)
	    std::cout << "Position (x, y): (" << mVehicleDataProvider->position().x.value() << "m, ";
	    std::cout << mVehicleDataProvider->position().y.value() << "m)" << endl;
	    //
        vecX.push_back(mVehicleDataProvider->position().x.value());
        vecY.push_back(mVehicleDataProvider->position().y.value());
	}
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
}

SimTime CaService::genCamDcc()
{
	// network interface may not be ready yet during initialization, so look it up at this later point
	auto netifc = mNetworkInterfaceTable->select(mPrimaryChannel);
	vanetza::dcc::TransmitRateThrottle* trc = netifc ? netifc->getDccEntity().getTransmitRateThrottle() : nullptr;
	if (!trc) {
		throw cRuntimeError("No DCC TRC found for CA's primary channel %i", mPrimaryChannel);
	}

	static const vanetza::dcc::TransmissionLite ca_tx(vanetza::dcc::Profile::DP2, 0);
	vanetza::Clock::duration interval = trc->interval(ca_tx);
	SimTime dcc { std::chrono::duration_cast<std::chrono::milliseconds>(interval).count(), SIMTIME_MS };
	return std::min(mGenCamMax, std::max(mGenCamMin, dcc));
}

vanetza::asn1::Cam createCooperativeAwarenessMessage(const VehicleDataProvider& vdp, uint16_t genDeltaTime)
{
	vanetza::asn1::Cam message;

	ItsPduHeader_t& header = (*message).header;
	header.protocolVersion = 2;
	header.messageID = ItsPduHeader__messageID_cam;
	header.stationID = vdp.station_id();

	CoopAwareness_t& cam = (*message).cam;
	cam.generationDeltaTime = genDeltaTime * GenerationDeltaTime_oneMilliSec;
	BasicContainer_t& basic = cam.camParameters.basicContainer;
	HighFrequencyContainer_t& hfc = cam.camParameters.highFrequencyContainer;

	// Preenchendo a estrutura da CAM. Como faço para imprimir esses dados nos resultados??
	basic.stationType = StationType_passengerCar;
	basic.referencePosition.altitude.altitudeValue = AltitudeValue_unavailable;
	basic.referencePosition.altitude.altitudeConfidence = AltitudeConfidence_unavailable;
	basic.referencePosition.longitude = round(vdp.longitude(), microdegree) * Longitude_oneMicrodegreeEast;
	basic.referencePosition.latitude = round(vdp.latitude(), microdegree) * Latitude_oneMicrodegreeNorth;
	basic.referencePosition.positionConfidenceEllipse.semiMajorOrientation = HeadingValue_unavailable;
	basic.referencePosition.positionConfidenceEllipse.semiMajorConfidence =
			SemiAxisLength_unavailable;
	basic.referencePosition.positionConfidenceEllipse.semiMinorConfidence =
			SemiAxisLength_unavailable;

	hfc.present = HighFrequencyContainer_PR_basicVehicleContainerHighFrequency;
	BasicVehicleContainerHighFrequency& bvc = hfc.choice.basicVehicleContainerHighFrequency;
	bvc.heading.headingValue = round(vdp.heading(), decidegree);
	bvc.heading.headingConfidence = HeadingConfidence_equalOrWithinOneDegree;
	bvc.speed.speedValue = buildSpeedValue(vdp.speed());
	bvc.speed.speedConfidence = SpeedConfidence_equalOrWithinOneCentimeterPerSec * 3;
	bvc.driveDirection = vdp.speed().value() >= 0.0 ?
			DriveDirection_forward : DriveDirection_backward;
	const double lonAccelValue = vdp.acceleration() / vanetza::units::si::meter_per_second_squared;
	// extreme speed changes can occur when SUMO swaps vehicles between lanes (speed is swapped as well)
	if (lonAccelValue >= -160.0 && lonAccelValue <= 161.0) {
		bvc.longitudinalAcceleration.longitudinalAccelerationValue = lonAccelValue * LongitudinalAccelerationValue_pointOneMeterPerSecSquaredForward;
	} else {
		bvc.longitudinalAcceleration.longitudinalAccelerationValue = LongitudinalAccelerationValue_unavailable;
	}
	bvc.longitudinalAcceleration.longitudinalAccelerationConfidence = AccelerationConfidence_unavailable;
	bvc.curvature.curvatureValue = abs(vdp.curvature() / vanetza::units::reciprocal_metre) * 10000.0;
	if (bvc.curvature.curvatureValue >= 1023) {
		bvc.curvature.curvatureValue = 1023;
	}
	bvc.curvature.curvatureConfidence = CurvatureConfidence_unavailable;
	bvc.curvatureCalculationMode = CurvatureCalculationMode_yawRateUsed;
	bvc.yawRate.yawRateValue = round(vdp.yaw_rate(), degree_per_second) * YawRateValue_degSec_000_01ToLeft * 100.0;
	if (bvc.yawRate.yawRateValue < -32766 || bvc.yawRate.yawRateValue > 32766) {
		bvc.yawRate.yawRateValue = YawRateValue_unavailable;
	}
	bvc.vehicleLength.vehicleLengthValue = VehicleLengthValue_unavailable;
	bvc.vehicleLength.vehicleLengthConfidenceIndication =
			VehicleLengthConfidenceIndication_noTrailerPresent;
	bvc.vehicleWidth = VehicleWidth_unavailable;

	std::string error;
	if (!message.validate(error)) {
		throw cRuntimeError("Invalid High Frequency CAM: %s", error.c_str());
	}

	return message;
}

void addLowFrequencyContainer(vanetza::asn1::Cam& message, unsigned pathHistoryLength)
{
	if (pathHistoryLength > 40) {
		EV_WARN << "path history can contain 40 elements at maximum";
		pathHistoryLength = 40;
	}

	LowFrequencyContainer_t*& lfc = message->cam.camParameters.lowFrequencyContainer;
	lfc = vanetza::asn1::allocate<LowFrequencyContainer_t>();
	lfc->present = LowFrequencyContainer_PR_basicVehicleContainerLowFrequency;
	BasicVehicleContainerLowFrequency& bvc = lfc->choice.basicVehicleContainerLowFrequency;
	bvc.vehicleRole = VehicleRole_default;
	bvc.exteriorLights.buf = static_cast<uint8_t*>(vanetza::asn1::allocate(1));
	assert(nullptr != bvc.exteriorLights.buf);
	bvc.exteriorLights.size = 1;
	bvc.exteriorLights.buf[0] |= 1 << (7 - ExteriorLights_daytimeRunningLightsOn);

	for (unsigned i = 0; i < pathHistoryLength; ++i) {
		PathPoint* pathPoint = vanetza::asn1::allocate<PathPoint>();
		pathPoint->pathDeltaTime = vanetza::asn1::allocate<PathDeltaTime_t>();
		*(pathPoint->pathDeltaTime) = (i + 1) * PathDeltaTime_tenMilliSecondsInPast * 10;
		pathPoint->pathPosition.deltaLatitude = DeltaLatitude_unavailable;
		pathPoint->pathPosition.deltaLongitude = DeltaLongitude_unavailable;
		pathPoint->pathPosition.deltaAltitude = DeltaAltitude_unavailable;
		ASN_SEQUENCE_ADD(&bvc.pathHistory, pathPoint);
	}

	std::string error;
	if (!message.validate(error)) {
		throw cRuntimeError("Invalid Low Frequency CAM: %s", error.c_str());
	}
}

// Criei este modulo no intuito de fechar o arquivo de gravação de resultados.
// No entanto, a gravação direta não foi possivel. Este modulo não esta sendo usado.
void CaService::finish() {
    this->logfile_CAM << "CaService finished\n";
    this->logfile_CAM.close();

    /*// DISTANCIA PERCORRIDA -- [ OK ]
    if (mVehicleDataProvider->station_id() == 11) {
        double X = 0, Y = 0, d = 0, D = 0;
        std::cout << endl << endl;
        auto iy = vecY.begin();
        for (auto ix = vecX.begin(); ix != vecX.end()-1; ++ix) {
            //std::cout << *i << " ";
            X = pow(*ix - (*(ix+1)), 2);
            //std::cout << X << " ";
            Y = pow(*iy - (*(iy+1)), 2);
            //std::cout << Y << " ";
            d = sqrt(X+Y);
            //std::cout << D << " ";
            D = D + d;
        }
        std::cout << endl << "ID: " << mVehicleDataProvider->station_id() << " | Distância percorrida: " << D << "m" << endl;
    }
    */
}

} // namespace artery
