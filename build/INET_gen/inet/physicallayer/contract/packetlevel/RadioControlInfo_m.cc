//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/physicallayer/contract/packetlevel/RadioControlInfo.msg.
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
#include "RadioControlInfo_m.h"

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
namespace physicallayer {

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::physicallayer::RadioCommandCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::physicallayer::RadioCommandCode"));
    e->insert(RADIO_C_CONFIGURE, "RADIO_C_CONFIGURE");
)

Register_Class(ConfigureRadioCommand)

ConfigureRadioCommand::ConfigureRadioCommand() : ::omnetpp::cObject()
{
    this->radioMode = -1;
    this->power = W(NaN);
    this->bitrate = bps(NaN);
    this->modulation = nullptr;
    this->carrierFrequency = Hz(NaN);
    this->bandwidth = Hz(NaN);
}

ConfigureRadioCommand::ConfigureRadioCommand(const ConfigureRadioCommand& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

ConfigureRadioCommand::~ConfigureRadioCommand()
{
}

ConfigureRadioCommand& ConfigureRadioCommand::operator=(const ConfigureRadioCommand& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void ConfigureRadioCommand::copy(const ConfigureRadioCommand& other)
{
    this->radioMode = other.radioMode;
    this->power = other.power;
    this->bitrate = other.bitrate;
    this->modulation = other.modulation;
    this->carrierFrequency = other.carrierFrequency;
    this->bandwidth = other.bandwidth;
}

void ConfigureRadioCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->radioMode);
    doParsimPacking(b,this->power);
    doParsimPacking(b,this->bitrate);
    doParsimPacking(b,this->modulation);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->bandwidth);
}

void ConfigureRadioCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->radioMode);
    doParsimUnpacking(b,this->power);
    doParsimUnpacking(b,this->bitrate);
    doParsimUnpacking(b,this->modulation);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->bandwidth);
}

int ConfigureRadioCommand::getRadioMode() const
{
    return this->radioMode;
}

void ConfigureRadioCommand::setRadioMode(int radioMode)
{
    this->radioMode = radioMode;
}

W& ConfigureRadioCommand::getPower()
{
    return this->power;
}

void ConfigureRadioCommand::setPower(const W& power)
{
    this->power = power;
}

bps& ConfigureRadioCommand::getBitrate()
{
    return this->bitrate;
}

void ConfigureRadioCommand::setBitrate(const bps& bitrate)
{
    this->bitrate = bitrate;
}

IModulationPtr& ConfigureRadioCommand::getModulation()
{
    return this->modulation;
}

void ConfigureRadioCommand::setModulation(const IModulationPtr& modulation)
{
    this->modulation = modulation;
}

Hz& ConfigureRadioCommand::getCarrierFrequency()
{
    return this->carrierFrequency;
}

void ConfigureRadioCommand::setCarrierFrequency(const Hz& carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

Hz& ConfigureRadioCommand::getBandwidth()
{
    return this->bandwidth;
}

void ConfigureRadioCommand::setBandwidth(const Hz& bandwidth)
{
    this->bandwidth = bandwidth;
}

class ConfigureRadioCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ConfigureRadioCommandDescriptor();
    virtual ~ConfigureRadioCommandDescriptor();

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

Register_ClassDescriptor(ConfigureRadioCommandDescriptor)

ConfigureRadioCommandDescriptor::ConfigureRadioCommandDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::ConfigureRadioCommand", "omnetpp::cObject")
{
    propertynames = nullptr;
}

ConfigureRadioCommandDescriptor::~ConfigureRadioCommandDescriptor()
{
    delete[] propertynames;
}

bool ConfigureRadioCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ConfigureRadioCommand *>(obj)!=nullptr;
}

const char **ConfigureRadioCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ConfigureRadioCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ConfigureRadioCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int ConfigureRadioCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *ConfigureRadioCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "radioMode",
        "power",
        "bitrate",
        "modulation",
        "carrierFrequency",
        "bandwidth",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int ConfigureRadioCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "radioMode")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "power")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitrate")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "modulation")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "carrierFrequency")==0) return base+4;
    if (fieldName[0]=='b' && strcmp(fieldName, "bandwidth")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ConfigureRadioCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "W",
        "bps",
        "IModulationPtr",
        "Hz",
        "Hz",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **ConfigureRadioCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ConfigureRadioCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ConfigureRadioCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ConfigureRadioCommand *pp = (ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ConfigureRadioCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ConfigureRadioCommand *pp = (ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ConfigureRadioCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ConfigureRadioCommand *pp = (ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getRadioMode());
        case 1: {std::stringstream out; out << pp->getPower(); return out.str();}
        case 2: {std::stringstream out; out << pp->getBitrate(); return out.str();}
        case 3: {std::stringstream out; out << pp->getModulation(); return out.str();}
        case 4: {std::stringstream out; out << pp->getCarrierFrequency(); return out.str();}
        case 5: {std::stringstream out; out << pp->getBandwidth(); return out.str();}
        default: return "";
    }
}

bool ConfigureRadioCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ConfigureRadioCommand *pp = (ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setRadioMode(string2long(value)); return true;
        default: return false;
    }
}

const char *ConfigureRadioCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(W));
        case 2: return omnetpp::opp_typename(typeid(bps));
        case 3: return omnetpp::opp_typename(typeid(IModulationPtr));
        case 4: return omnetpp::opp_typename(typeid(Hz));
        case 5: return omnetpp::opp_typename(typeid(Hz));
        default: return nullptr;
    };
}

void *ConfigureRadioCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ConfigureRadioCommand *pp = (ConfigureRadioCommand *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getPower()); break;
        case 2: return (void *)(&pp->getBitrate()); break;
        case 3: return (void *)(&pp->getModulation()); break;
        case 4: return (void *)(&pp->getCarrierFrequency()); break;
        case 5: return (void *)(&pp->getBandwidth()); break;
        default: return nullptr;
    }
}

Register_Class(TransmissionRequest)

TransmissionRequest::TransmissionRequest() : ::omnetpp::cObject()
{
    this->power = W(NaN);
    this->bitrate = bps(NaN);
    this->carrierFrequency = Hz(NaN);
    this->bandwidth = Hz(NaN);
}

TransmissionRequest::TransmissionRequest(const TransmissionRequest& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

TransmissionRequest::~TransmissionRequest()
{
}

TransmissionRequest& TransmissionRequest::operator=(const TransmissionRequest& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void TransmissionRequest::copy(const TransmissionRequest& other)
{
    this->power = other.power;
    this->bitrate = other.bitrate;
    this->carrierFrequency = other.carrierFrequency;
    this->bandwidth = other.bandwidth;
}

void TransmissionRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->power);
    doParsimPacking(b,this->bitrate);
    doParsimPacking(b,this->carrierFrequency);
    doParsimPacking(b,this->bandwidth);
}

void TransmissionRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->power);
    doParsimUnpacking(b,this->bitrate);
    doParsimUnpacking(b,this->carrierFrequency);
    doParsimUnpacking(b,this->bandwidth);
}

W& TransmissionRequest::getPower()
{
    return this->power;
}

void TransmissionRequest::setPower(const W& power)
{
    this->power = power;
}

bps& TransmissionRequest::getBitrate()
{
    return this->bitrate;
}

void TransmissionRequest::setBitrate(const bps& bitrate)
{
    this->bitrate = bitrate;
}

Hz& TransmissionRequest::getCarrierFrequency()
{
    return this->carrierFrequency;
}

void TransmissionRequest::setCarrierFrequency(const Hz& carrierFrequency)
{
    this->carrierFrequency = carrierFrequency;
}

Hz& TransmissionRequest::getBandwidth()
{
    return this->bandwidth;
}

void TransmissionRequest::setBandwidth(const Hz& bandwidth)
{
    this->bandwidth = bandwidth;
}

class TransmissionRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TransmissionRequestDescriptor();
    virtual ~TransmissionRequestDescriptor();

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

Register_ClassDescriptor(TransmissionRequestDescriptor)

TransmissionRequestDescriptor::TransmissionRequestDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::TransmissionRequest", "omnetpp::cObject")
{
    propertynames = nullptr;
}

TransmissionRequestDescriptor::~TransmissionRequestDescriptor()
{
    delete[] propertynames;
}

bool TransmissionRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TransmissionRequest *>(obj)!=nullptr;
}

const char **TransmissionRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TransmissionRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TransmissionRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int TransmissionRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *TransmissionRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "power",
        "bitrate",
        "carrierFrequency",
        "bandwidth",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int TransmissionRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "power")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitrate")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "carrierFrequency")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "bandwidth")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TransmissionRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "W",
        "bps",
        "Hz",
        "Hz",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **TransmissionRequestDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TransmissionRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TransmissionRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TransmissionRequest *pp = (TransmissionRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TransmissionRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransmissionRequest *pp = (TransmissionRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TransmissionRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TransmissionRequest *pp = (TransmissionRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getPower(); return out.str();}
        case 1: {std::stringstream out; out << pp->getBitrate(); return out.str();}
        case 2: {std::stringstream out; out << pp->getCarrierFrequency(); return out.str();}
        case 3: {std::stringstream out; out << pp->getBandwidth(); return out.str();}
        default: return "";
    }
}

bool TransmissionRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TransmissionRequest *pp = (TransmissionRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TransmissionRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(W));
        case 1: return omnetpp::opp_typename(typeid(bps));
        case 2: return omnetpp::opp_typename(typeid(Hz));
        case 3: return omnetpp::opp_typename(typeid(Hz));
        default: return nullptr;
    };
}

void *TransmissionRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TransmissionRequest *pp = (TransmissionRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getPower()); break;
        case 1: return (void *)(&pp->getBitrate()); break;
        case 2: return (void *)(&pp->getCarrierFrequency()); break;
        case 3: return (void *)(&pp->getBandwidth()); break;
        default: return nullptr;
    }
}

Register_Class(ReceptionIndication)

ReceptionIndication::ReceptionIndication() : ::omnetpp::cObject()
{
    this->bitErrorCount = -1;
    this->symbolErrorCount = -1;
    this->packetErrorRate = NaN;
    this->bitErrorRate = NaN;
    this->symbolErrorRate = NaN;
    this->minRSSI = W(NaN);
    this->minSNIR = NaN;
}

ReceptionIndication::ReceptionIndication(const ReceptionIndication& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

ReceptionIndication::~ReceptionIndication()
{
}

ReceptionIndication& ReceptionIndication::operator=(const ReceptionIndication& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void ReceptionIndication::copy(const ReceptionIndication& other)
{
    this->bitErrorCount = other.bitErrorCount;
    this->symbolErrorCount = other.symbolErrorCount;
    this->packetErrorRate = other.packetErrorRate;
    this->bitErrorRate = other.bitErrorRate;
    this->symbolErrorRate = other.symbolErrorRate;
    this->minRSSI = other.minRSSI;
    this->minSNIR = other.minSNIR;
}

void ReceptionIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->bitErrorCount);
    doParsimPacking(b,this->symbolErrorCount);
    doParsimPacking(b,this->packetErrorRate);
    doParsimPacking(b,this->bitErrorRate);
    doParsimPacking(b,this->symbolErrorRate);
    doParsimPacking(b,this->minRSSI);
    doParsimPacking(b,this->minSNIR);
}

void ReceptionIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->bitErrorCount);
    doParsimUnpacking(b,this->symbolErrorCount);
    doParsimUnpacking(b,this->packetErrorRate);
    doParsimUnpacking(b,this->bitErrorRate);
    doParsimUnpacking(b,this->symbolErrorRate);
    doParsimUnpacking(b,this->minRSSI);
    doParsimUnpacking(b,this->minSNIR);
}

int ReceptionIndication::getBitErrorCount() const
{
    return this->bitErrorCount;
}

void ReceptionIndication::setBitErrorCount(int bitErrorCount)
{
    this->bitErrorCount = bitErrorCount;
}

int ReceptionIndication::getSymbolErrorCount() const
{
    return this->symbolErrorCount;
}

void ReceptionIndication::setSymbolErrorCount(int symbolErrorCount)
{
    this->symbolErrorCount = symbolErrorCount;
}

double ReceptionIndication::getPacketErrorRate() const
{
    return this->packetErrorRate;
}

void ReceptionIndication::setPacketErrorRate(double packetErrorRate)
{
    this->packetErrorRate = packetErrorRate;
}

double ReceptionIndication::getBitErrorRate() const
{
    return this->bitErrorRate;
}

void ReceptionIndication::setBitErrorRate(double bitErrorRate)
{
    this->bitErrorRate = bitErrorRate;
}

double ReceptionIndication::getSymbolErrorRate() const
{
    return this->symbolErrorRate;
}

void ReceptionIndication::setSymbolErrorRate(double symbolErrorRate)
{
    this->symbolErrorRate = symbolErrorRate;
}

W& ReceptionIndication::getMinRSSI()
{
    return this->minRSSI;
}

void ReceptionIndication::setMinRSSI(const W& minRSSI)
{
    this->minRSSI = minRSSI;
}

double ReceptionIndication::getMinSNIR() const
{
    return this->minSNIR;
}

void ReceptionIndication::setMinSNIR(double minSNIR)
{
    this->minSNIR = minSNIR;
}

class ReceptionIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ReceptionIndicationDescriptor();
    virtual ~ReceptionIndicationDescriptor();

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

Register_ClassDescriptor(ReceptionIndicationDescriptor)

ReceptionIndicationDescriptor::ReceptionIndicationDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::ReceptionIndication", "omnetpp::cObject")
{
    propertynames = nullptr;
}

ReceptionIndicationDescriptor::~ReceptionIndicationDescriptor()
{
    delete[] propertynames;
}

bool ReceptionIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ReceptionIndication *>(obj)!=nullptr;
}

const char **ReceptionIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ReceptionIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ReceptionIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int ReceptionIndicationDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *ReceptionIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bitErrorCount",
        "symbolErrorCount",
        "packetErrorRate",
        "bitErrorRate",
        "symbolErrorRate",
        "minRSSI",
        "minSNIR",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int ReceptionIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitErrorCount")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "symbolErrorCount")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetErrorRate")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitErrorRate")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "symbolErrorRate")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "minRSSI")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "minSNIR")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ReceptionIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "double",
        "double",
        "double",
        "W",
        "double",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **ReceptionIndicationDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ReceptionIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ReceptionIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ReceptionIndication *pp = (ReceptionIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ReceptionIndicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ReceptionIndication *pp = (ReceptionIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ReceptionIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ReceptionIndication *pp = (ReceptionIndication *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getBitErrorCount());
        case 1: return long2string(pp->getSymbolErrorCount());
        case 2: return double2string(pp->getPacketErrorRate());
        case 3: return double2string(pp->getBitErrorRate());
        case 4: return double2string(pp->getSymbolErrorRate());
        case 5: {std::stringstream out; out << pp->getMinRSSI(); return out.str();}
        case 6: return double2string(pp->getMinSNIR());
        default: return "";
    }
}

bool ReceptionIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ReceptionIndication *pp = (ReceptionIndication *)object; (void)pp;
    switch (field) {
        case 0: pp->setBitErrorCount(string2long(value)); return true;
        case 1: pp->setSymbolErrorCount(string2long(value)); return true;
        case 2: pp->setPacketErrorRate(string2double(value)); return true;
        case 3: pp->setBitErrorRate(string2double(value)); return true;
        case 4: pp->setSymbolErrorRate(string2double(value)); return true;
        case 6: pp->setMinSNIR(string2double(value)); return true;
        default: return false;
    }
}

const char *ReceptionIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(W));
        default: return nullptr;
    };
}

void *ReceptionIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ReceptionIndication *pp = (ReceptionIndication *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getMinRSSI()); break;
        default: return nullptr;
    }
}

} // namespace physicallayer
} // namespace inet

