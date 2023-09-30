//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/rtp/RTPInnerPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "RTPInnerPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {
namespace rtp {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::rtp::RTP_INP_TYPE");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::rtp::RTP_INP_TYPE"));
    e->insert(RTP_INP_UNDEF, "RTP_INP_UNDEF");
    e->insert(RTP_INP_INITIALIZE_PROFILE, "RTP_INP_INITIALIZE_PROFILE");
    e->insert(RTP_INP_PROFILE_INITIALIZED, "RTP_INP_PROFILE_INITIALIZED");
    e->insert(RTP_INP_INITIALIZE_RTCP, "RTP_INP_INITIALIZE_RTCP");
    e->insert(RTP_INP_RTCP_INITIALIZED, "RTP_INP_RTCP_INITIALIZED");
    e->insert(RTP_INP_CREATE_SENDER_MODULE, "RTP_INP_CREATE_SENDER_MODULE");
    e->insert(RTP_INP_SENDER_MODULE_CREATED, "RTP_INP_SENDER_MODULE_CREATED");
    e->insert(RTP_INP_DELETE_SENDER_MODULE, "RTP_INP_DELETE_SENDER_MODULE");
    e->insert(RTP_INP_SENDER_MODULE_DELETED, "RTP_INP_SENDER_MODULE_DELETED");
    e->insert(RTP_INP_INITIALIZE_SENDER_MODULE, "RTP_INP_INITIALIZE_SENDER_MODULE");
    e->insert(RTP_INP_SENDER_MODULE_INITIALIZED, "RTP_INP_SENDER_MODULE_INITIALIZED");
    e->insert(RTP_INP_SENDER_MODULE_CONTROL, "RTP_INP_SENDER_MODULE_CONTROL");
    e->insert(RTP_INP_SENDER_MODULE_STATUS, "RTP_INP_SENDER_MODULE_STATUS");
    e->insert(RTP_INP_LEAVE_SESSION, "RTP_INP_LEAVE_SESSION");
    e->insert(RTP_INP_SESSION_LEFT, "RTP_INP_SESSION_LEFT");
    e->insert(RTP_INP_DATA_OUT, "RTP_INP_DATA_OUT");
    e->insert(RTP_INP_DATA_IN, "RTP_INP_DATA_IN");
)

RTPInnerPacket_Base::RTPInnerPacket_Base(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->type = RTP_INP_UNDEF;
    this->mtu = 0;
    this->bandwidth = 0;
    this->rtcpPercentage = 0;
    this->address = IPv4Address::UNSPECIFIED_ADDRESS;
    this->port = PORT_UNDEF;
    this->ssrc = 0;
    this->payloadType = 0;
    this->clockRate = 0;
    this->timeStampBase = 0;
    this->sequenceNumberBase = 0;
}

RTPInnerPacket_Base::RTPInnerPacket_Base(const RTPInnerPacket_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

RTPInnerPacket_Base::~RTPInnerPacket_Base()
{
}

RTPInnerPacket_Base& RTPInnerPacket_Base::operator=(const RTPInnerPacket_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RTPInnerPacket_Base::copy(const RTPInnerPacket_Base& other)
{
    this->type = other.type;
    this->commonName = other.commonName;
    this->mtu = other.mtu;
    this->bandwidth = other.bandwidth;
    this->rtcpPercentage = other.rtcpPercentage;
    this->address = other.address;
    this->port = other.port;
    this->ssrc = other.ssrc;
    this->payloadType = other.payloadType;
    this->fileName = other.fileName;
    this->clockRate = other.clockRate;
    this->timeStampBase = other.timeStampBase;
    this->sequenceNumberBase = other.sequenceNumberBase;
}

void RTPInnerPacket_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->commonName);
    doParsimPacking(b,this->mtu);
    doParsimPacking(b,this->bandwidth);
    doParsimPacking(b,this->rtcpPercentage);
    doParsimPacking(b,this->address);
    doParsimPacking(b,this->port);
    doParsimPacking(b,this->ssrc);
    doParsimPacking(b,this->payloadType);
    doParsimPacking(b,this->fileName);
    doParsimPacking(b,this->clockRate);
    doParsimPacking(b,this->timeStampBase);
    doParsimPacking(b,this->sequenceNumberBase);
}

void RTPInnerPacket_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->commonName);
    doParsimUnpacking(b,this->mtu);
    doParsimUnpacking(b,this->bandwidth);
    doParsimUnpacking(b,this->rtcpPercentage);
    doParsimUnpacking(b,this->address);
    doParsimUnpacking(b,this->port);
    doParsimUnpacking(b,this->ssrc);
    doParsimUnpacking(b,this->payloadType);
    doParsimUnpacking(b,this->fileName);
    doParsimUnpacking(b,this->clockRate);
    doParsimUnpacking(b,this->timeStampBase);
    doParsimUnpacking(b,this->sequenceNumberBase);
}

short RTPInnerPacket_Base::getType() const
{
    return this->type;
}

void RTPInnerPacket_Base::setType(short type)
{
    this->type = type;
}

const char * RTPInnerPacket_Base::getCommonName() const
{
    return this->commonName.c_str();
}

void RTPInnerPacket_Base::setCommonName(const char * commonName)
{
    this->commonName = commonName;
}

int RTPInnerPacket_Base::getMtu() const
{
    return this->mtu;
}

void RTPInnerPacket_Base::setMtu(int mtu)
{
    this->mtu = mtu;
}

int RTPInnerPacket_Base::getBandwidth() const
{
    return this->bandwidth;
}

void RTPInnerPacket_Base::setBandwidth(int bandwidth)
{
    this->bandwidth = bandwidth;
}

int RTPInnerPacket_Base::getRtcpPercentage() const
{
    return this->rtcpPercentage;
}

void RTPInnerPacket_Base::setRtcpPercentage(int rtcpPercentage)
{
    this->rtcpPercentage = rtcpPercentage;
}

IPv4Address& RTPInnerPacket_Base::getAddress()
{
    return this->address;
}

void RTPInnerPacket_Base::setAddress(const IPv4Address& address)
{
    this->address = address;
}

int RTPInnerPacket_Base::getPort() const
{
    return this->port;
}

void RTPInnerPacket_Base::setPort(int port)
{
    this->port = port;
}

uint32_t RTPInnerPacket_Base::getSsrc() const
{
    return this->ssrc;
}

void RTPInnerPacket_Base::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

int RTPInnerPacket_Base::getPayloadType() const
{
    return this->payloadType;
}

void RTPInnerPacket_Base::setPayloadType(int payloadType)
{
    this->payloadType = payloadType;
}

const char * RTPInnerPacket_Base::getFileName() const
{
    return this->fileName.c_str();
}

void RTPInnerPacket_Base::setFileName(const char * fileName)
{
    this->fileName = fileName;
}

int RTPInnerPacket_Base::getClockRate() const
{
    return this->clockRate;
}

void RTPInnerPacket_Base::setClockRate(int clockRate)
{
    this->clockRate = clockRate;
}

int RTPInnerPacket_Base::getTimeStampBase() const
{
    return this->timeStampBase;
}

void RTPInnerPacket_Base::setTimeStampBase(int timeStampBase)
{
    this->timeStampBase = timeStampBase;
}

int RTPInnerPacket_Base::getSequenceNumberBase() const
{
    return this->sequenceNumberBase;
}

void RTPInnerPacket_Base::setSequenceNumberBase(int sequenceNumberBase)
{
    this->sequenceNumberBase = sequenceNumberBase;
}

class RTPInnerPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPInnerPacketDescriptor();
    virtual ~RTPInnerPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(RTPInnerPacketDescriptor)

RTPInnerPacketDescriptor::RTPInnerPacketDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPInnerPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

RTPInnerPacketDescriptor::~RTPInnerPacketDescriptor()
{
    delete[] propertynames;
}

bool RTPInnerPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPInnerPacket_Base *>(obj)!=nullptr;
}

const char **RTPInnerPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPInnerPacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPInnerPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount() : 13;
}

unsigned int RTPInnerPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<13) ? fieldTypeFlags[field] : 0;
}

const char *RTPInnerPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "commonName",
        "mtu",
        "bandwidth",
        "rtcpPercentage",
        "address",
        "port",
        "ssrc",
        "payloadType",
        "fileName",
        "clockRate",
        "timeStampBase",
        "sequenceNumberBase",
    };
    return (field>=0 && field<13) ? fieldNames[field] : nullptr;
}

int RTPInnerPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "commonName")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "mtu")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "bandwidth")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "rtcpPercentage")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "address")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "port")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssrc")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadType")==0) return base+8;
    if (fieldName[0]=='f' && strcmp(fieldName, "fileName")==0) return base+9;
    if (fieldName[0]=='c' && strcmp(fieldName, "clockRate")==0) return base+10;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeStampBase")==0) return base+11;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumberBase")==0) return base+12;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPInnerPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "string",
        "int",
        "int",
        "int",
        "IPv4Address",
        "int",
        "uint32",
        "int",
        "string",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<13) ? fieldTypeStrings[field] : nullptr;
}

const char **RTPInnerPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *RTPInnerPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::rtp::RTP_INP_TYPE";
            return nullptr;
        default: return nullptr;
    }
}

int RTPInnerPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPInnerPacket_Base *pp = (RTPInnerPacket_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPInnerPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPInnerPacket_Base *pp = (RTPInnerPacket_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPInnerPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPInnerPacket_Base *pp = (RTPInnerPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::rtp::RTP_INP_TYPE");
        case 1: return oppstring2string(pp->getCommonName());
        case 2: return long2string(pp->getMtu());
        case 3: return long2string(pp->getBandwidth());
        case 4: return long2string(pp->getRtcpPercentage());
        case 5: {std::stringstream out; out << pp->getAddress(); return out.str();}
        case 6: return long2string(pp->getPort());
        case 7: return ulong2string(pp->getSsrc());
        case 8: return long2string(pp->getPayloadType());
        case 9: return oppstring2string(pp->getFileName());
        case 10: return long2string(pp->getClockRate());
        case 11: return long2string(pp->getTimeStampBase());
        case 12: return long2string(pp->getSequenceNumberBase());
        default: return "";
    }
}

bool RTPInnerPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPInnerPacket_Base *pp = (RTPInnerPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::rtp::RTP_INP_TYPE)string2enum(value, "inet::rtp::RTP_INP_TYPE")); return true;
        case 1: pp->setCommonName((value)); return true;
        case 2: pp->setMtu(string2long(value)); return true;
        case 3: pp->setBandwidth(string2long(value)); return true;
        case 4: pp->setRtcpPercentage(string2long(value)); return true;
        case 6: pp->setPort(string2long(value)); return true;
        case 7: pp->setSsrc(string2ulong(value)); return true;
        case 8: pp->setPayloadType(string2long(value)); return true;
        case 9: pp->setFileName((value)); return true;
        case 10: pp->setClockRate(string2long(value)); return true;
        case 11: pp->setTimeStampBase(string2long(value)); return true;
        case 12: pp->setSequenceNumberBase(string2long(value)); return true;
        default: return false;
    }
}

const char *RTPInnerPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *RTPInnerPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPInnerPacket_Base *pp = (RTPInnerPacket_Base *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getAddress()); break;
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

