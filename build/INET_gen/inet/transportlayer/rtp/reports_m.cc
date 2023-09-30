//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/rtp/reports.msg.
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
#include "reports_m.h"

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

SenderReport_Base::SenderReport_Base() : ::omnetpp::cObject()
{
    this->NTPTimeStamp = 0;
    this->RTPTimeStamp = 0;
    this->packetCount = 0;
    this->byteCount = 0;
}

SenderReport_Base::SenderReport_Base(const SenderReport_Base& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

SenderReport_Base::~SenderReport_Base()
{
}

SenderReport_Base& SenderReport_Base::operator=(const SenderReport_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void SenderReport_Base::copy(const SenderReport_Base& other)
{
    this->NTPTimeStamp = other.NTPTimeStamp;
    this->RTPTimeStamp = other.RTPTimeStamp;
    this->packetCount = other.packetCount;
    this->byteCount = other.byteCount;
}

void SenderReport_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->NTPTimeStamp);
    doParsimPacking(b,this->RTPTimeStamp);
    doParsimPacking(b,this->packetCount);
    doParsimPacking(b,this->byteCount);
}

void SenderReport_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->NTPTimeStamp);
    doParsimUnpacking(b,this->RTPTimeStamp);
    doParsimUnpacking(b,this->packetCount);
    doParsimUnpacking(b,this->byteCount);
}

uint64_t SenderReport_Base::getNTPTimeStamp() const
{
    return this->NTPTimeStamp;
}

void SenderReport_Base::setNTPTimeStamp(uint64_t NTPTimeStamp)
{
    this->NTPTimeStamp = NTPTimeStamp;
}

uint32_t SenderReport_Base::getRTPTimeStamp() const
{
    return this->RTPTimeStamp;
}

void SenderReport_Base::setRTPTimeStamp(uint32_t RTPTimeStamp)
{
    this->RTPTimeStamp = RTPTimeStamp;
}

uint32_t SenderReport_Base::getPacketCount() const
{
    return this->packetCount;
}

void SenderReport_Base::setPacketCount(uint32_t packetCount)
{
    this->packetCount = packetCount;
}

uint32_t SenderReport_Base::getByteCount() const
{
    return this->byteCount;
}

void SenderReport_Base::setByteCount(uint32_t byteCount)
{
    this->byteCount = byteCount;
}

class SenderReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SenderReportDescriptor();
    virtual ~SenderReportDescriptor();

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

Register_ClassDescriptor(SenderReportDescriptor)

SenderReportDescriptor::SenderReportDescriptor() : omnetpp::cClassDescriptor("inet::rtp::SenderReport", "omnetpp::cObject")
{
    propertynames = nullptr;
}

SenderReportDescriptor::~SenderReportDescriptor()
{
    delete[] propertynames;
}

bool SenderReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SenderReport_Base *>(obj)!=nullptr;
}

const char **SenderReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SenderReportDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SenderReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SenderReportDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *SenderReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "NTPTimeStamp",
        "RTPTimeStamp",
        "packetCount",
        "byteCount",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SenderReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='N' && strcmp(fieldName, "NTPTimeStamp")==0) return base+0;
    if (fieldName[0]=='R' && strcmp(fieldName, "RTPTimeStamp")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetCount")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "byteCount")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SenderReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64",
        "uint32",
        "uint32",
        "uint32",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SenderReportDescriptor::getFieldPropertyNames(int field) const
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

const char *SenderReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SenderReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SenderReport_Base *pp = (SenderReport_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SenderReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SenderReport_Base *pp = (SenderReport_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SenderReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SenderReport_Base *pp = (SenderReport_Base *)object; (void)pp;
    switch (field) {
        case 0: return uint642string(pp->getNTPTimeStamp());
        case 1: return ulong2string(pp->getRTPTimeStamp());
        case 2: return ulong2string(pp->getPacketCount());
        case 3: return ulong2string(pp->getByteCount());
        default: return "";
    }
}

bool SenderReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SenderReport_Base *pp = (SenderReport_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setNTPTimeStamp(string2uint64(value)); return true;
        case 1: pp->setRTPTimeStamp(string2ulong(value)); return true;
        case 2: pp->setPacketCount(string2ulong(value)); return true;
        case 3: pp->setByteCount(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SenderReportDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *SenderReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SenderReport_Base *pp = (SenderReport_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

ReceptionReport_Base::ReceptionReport_Base() : ::omnetpp::cObject()
{
    this->ssrc = 0;
    this->fractionLost = 0;
    this->packetsLostCumulative = 0;
    this->sequenceNumber = 0;
    this->jitter = 0;
    this->lastSR = 0;
    this->delaySinceLastSR = 0;
}

ReceptionReport_Base::ReceptionReport_Base(const ReceptionReport_Base& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

ReceptionReport_Base::~ReceptionReport_Base()
{
}

ReceptionReport_Base& ReceptionReport_Base::operator=(const ReceptionReport_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void ReceptionReport_Base::copy(const ReceptionReport_Base& other)
{
    this->ssrc = other.ssrc;
    this->fractionLost = other.fractionLost;
    this->packetsLostCumulative = other.packetsLostCumulative;
    this->sequenceNumber = other.sequenceNumber;
    this->jitter = other.jitter;
    this->lastSR = other.lastSR;
    this->delaySinceLastSR = other.delaySinceLastSR;
}

void ReceptionReport_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->ssrc);
    doParsimPacking(b,this->fractionLost);
    doParsimPacking(b,this->packetsLostCumulative);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->jitter);
    doParsimPacking(b,this->lastSR);
    doParsimPacking(b,this->delaySinceLastSR);
}

void ReceptionReport_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->ssrc);
    doParsimUnpacking(b,this->fractionLost);
    doParsimUnpacking(b,this->packetsLostCumulative);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->jitter);
    doParsimUnpacking(b,this->lastSR);
    doParsimUnpacking(b,this->delaySinceLastSR);
}

uint32_t ReceptionReport_Base::getSsrc() const
{
    return this->ssrc;
}

void ReceptionReport_Base::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

uint8_t ReceptionReport_Base::getFractionLost() const
{
    return this->fractionLost;
}

void ReceptionReport_Base::setFractionLost(uint8_t fractionLost)
{
    this->fractionLost = fractionLost;
}

int ReceptionReport_Base::getPacketsLostCumulative() const
{
    return this->packetsLostCumulative;
}

void ReceptionReport_Base::setPacketsLostCumulative(int packetsLostCumulative)
{
    this->packetsLostCumulative = packetsLostCumulative;
}

uint32_t ReceptionReport_Base::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void ReceptionReport_Base::setSequenceNumber(uint32_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

int ReceptionReport_Base::getJitter() const
{
    return this->jitter;
}

void ReceptionReport_Base::setJitter(int jitter)
{
    this->jitter = jitter;
}

int ReceptionReport_Base::getLastSR() const
{
    return this->lastSR;
}

void ReceptionReport_Base::setLastSR(int lastSR)
{
    this->lastSR = lastSR;
}

int ReceptionReport_Base::getDelaySinceLastSR() const
{
    return this->delaySinceLastSR;
}

void ReceptionReport_Base::setDelaySinceLastSR(int delaySinceLastSR)
{
    this->delaySinceLastSR = delaySinceLastSR;
}

class ReceptionReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ReceptionReportDescriptor();
    virtual ~ReceptionReportDescriptor();

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

Register_ClassDescriptor(ReceptionReportDescriptor)

ReceptionReportDescriptor::ReceptionReportDescriptor() : omnetpp::cClassDescriptor("inet::rtp::ReceptionReport", "omnetpp::cObject")
{
    propertynames = nullptr;
}

ReceptionReportDescriptor::~ReceptionReportDescriptor()
{
    delete[] propertynames;
}

bool ReceptionReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ReceptionReport_Base *>(obj)!=nullptr;
}

const char **ReceptionReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ReceptionReportDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ReceptionReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int ReceptionReportDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *ReceptionReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ssrc",
        "fractionLost",
        "packetsLostCumulative",
        "sequenceNumber",
        "jitter",
        "lastSR",
        "delaySinceLastSR",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int ReceptionReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssrc")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fractionLost")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetsLostCumulative")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+3;
    if (fieldName[0]=='j' && strcmp(fieldName, "jitter")==0) return base+4;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastSR")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "delaySinceLastSR")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ReceptionReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint8",
        "int",
        "uint32",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **ReceptionReportDescriptor::getFieldPropertyNames(int field) const
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

const char *ReceptionReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ReceptionReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport_Base *pp = (ReceptionReport_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ReceptionReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport_Base *pp = (ReceptionReport_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ReceptionReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport_Base *pp = (ReceptionReport_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSsrc());
        case 1: return ulong2string(pp->getFractionLost());
        case 2: return long2string(pp->getPacketsLostCumulative());
        case 3: return ulong2string(pp->getSequenceNumber());
        case 4: return long2string(pp->getJitter());
        case 5: return long2string(pp->getLastSR());
        case 6: return long2string(pp->getDelaySinceLastSR());
        default: return "";
    }
}

bool ReceptionReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport_Base *pp = (ReceptionReport_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSsrc(string2ulong(value)); return true;
        case 1: pp->setFractionLost(string2ulong(value)); return true;
        case 2: pp->setPacketsLostCumulative(string2long(value)); return true;
        case 3: pp->setSequenceNumber(string2ulong(value)); return true;
        case 4: pp->setJitter(string2long(value)); return true;
        case 5: pp->setLastSR(string2long(value)); return true;
        case 6: pp->setDelaySinceLastSR(string2long(value)); return true;
        default: return false;
    }
}

const char *ReceptionReportDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

void *ReceptionReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ReceptionReport_Base *pp = (ReceptionReport_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

