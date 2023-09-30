//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/rtp/RTCPPacket2.msg.
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
#include "RTCPPacket2_m.h"

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

RTCPReceiverReportPacket_Base::RTCPReceiverReportPacket_Base(const char *name, short kind) : ::inet::rtp::RTCPPacket(name,kind)
{
    this->setPacketType(RTCP_PT_RR);

    this->ssrc = 0;
    take(&(this->receptionReports));
}

RTCPReceiverReportPacket_Base::RTCPReceiverReportPacket_Base(const RTCPReceiverReportPacket_Base& other) : ::inet::rtp::RTCPPacket(other)
{
    take(&(this->receptionReports));
    copy(other);
}

RTCPReceiverReportPacket_Base::~RTCPReceiverReportPacket_Base()
{
    drop(&(this->receptionReports));
}

RTCPReceiverReportPacket_Base& RTCPReceiverReportPacket_Base::operator=(const RTCPReceiverReportPacket_Base& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTCPPacket::operator=(other);
    copy(other);
    return *this;
}

void RTCPReceiverReportPacket_Base::copy(const RTCPReceiverReportPacket_Base& other)
{
    this->ssrc = other.ssrc;
    this->receptionReports = other.receptionReports;
    this->receptionReports.setName(other.receptionReports.getName());
}

void RTCPReceiverReportPacket_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTCPPacket::parsimPack(b);
    doParsimPacking(b,this->ssrc);
    doParsimPacking(b,this->receptionReports);
}

void RTCPReceiverReportPacket_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTCPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->ssrc);
    doParsimUnpacking(b,this->receptionReports);
}

uint32_t RTCPReceiverReportPacket_Base::getSsrc() const
{
    return this->ssrc;
}

void RTCPReceiverReportPacket_Base::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

cArray& RTCPReceiverReportPacket_Base::getReceptionReports()
{
    return this->receptionReports;
}

void RTCPReceiverReportPacket_Base::setReceptionReports(const cArray& receptionReports)
{
    this->receptionReports = receptionReports;
}

class RTCPReceiverReportPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTCPReceiverReportPacketDescriptor();
    virtual ~RTCPReceiverReportPacketDescriptor();

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

Register_ClassDescriptor(RTCPReceiverReportPacketDescriptor)

RTCPReceiverReportPacketDescriptor::RTCPReceiverReportPacketDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTCPReceiverReportPacket", "inet::rtp::RTCPPacket")
{
    propertynames = nullptr;
}

RTCPReceiverReportPacketDescriptor::~RTCPReceiverReportPacketDescriptor()
{
    delete[] propertynames;
}

bool RTCPReceiverReportPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTCPReceiverReportPacket_Base *>(obj)!=nullptr;
}

const char **RTCPReceiverReportPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTCPReceiverReportPacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTCPReceiverReportPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RTCPReceiverReportPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *RTCPReceiverReportPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ssrc",
        "receptionReports",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int RTCPReceiverReportPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssrc")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "receptionReports")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTCPReceiverReportPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "cArray",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **RTCPReceiverReportPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RTCPReceiverReportPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTCPReceiverReportPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTCPReceiverReportPacket_Base *pp = (RTCPReceiverReportPacket_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTCPReceiverReportPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTCPReceiverReportPacket_Base *pp = (RTCPReceiverReportPacket_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTCPReceiverReportPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTCPReceiverReportPacket_Base *pp = (RTCPReceiverReportPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSsrc());
        case 1: {std::stringstream out; out << pp->getReceptionReports(); return out.str();}
        default: return "";
    }
}

bool RTCPReceiverReportPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTCPReceiverReportPacket_Base *pp = (RTCPReceiverReportPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSsrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RTCPReceiverReportPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cArray));
        default: return nullptr;
    };
}

void *RTCPReceiverReportPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTCPReceiverReportPacket_Base *pp = (RTCPReceiverReportPacket_Base *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(&pp->getReceptionReports()); break;
        default: return nullptr;
    }
}

RTCPSDESPacket_Base::RTCPSDESPacket_Base(const char *name, short kind) : ::inet::rtp::RTCPPacket(name,kind)
{
    this->setPacketType(RTCP_PT_SDES);

    take(&(this->sdesChunks));
}

RTCPSDESPacket_Base::RTCPSDESPacket_Base(const RTCPSDESPacket_Base& other) : ::inet::rtp::RTCPPacket(other)
{
    take(&(this->sdesChunks));
    copy(other);
}

RTCPSDESPacket_Base::~RTCPSDESPacket_Base()
{
    drop(&(this->sdesChunks));
}

RTCPSDESPacket_Base& RTCPSDESPacket_Base::operator=(const RTCPSDESPacket_Base& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTCPPacket::operator=(other);
    copy(other);
    return *this;
}

void RTCPSDESPacket_Base::copy(const RTCPSDESPacket_Base& other)
{
    this->sdesChunks = other.sdesChunks;
    this->sdesChunks.setName(other.sdesChunks.getName());
}

void RTCPSDESPacket_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTCPPacket::parsimPack(b);
    doParsimPacking(b,this->sdesChunks);
}

void RTCPSDESPacket_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTCPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sdesChunks);
}

cArray& RTCPSDESPacket_Base::getSdesChunks()
{
    return this->sdesChunks;
}

void RTCPSDESPacket_Base::setSdesChunks(const cArray& sdesChunks)
{
    this->sdesChunks = sdesChunks;
}

class RTCPSDESPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTCPSDESPacketDescriptor();
    virtual ~RTCPSDESPacketDescriptor();

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

Register_ClassDescriptor(RTCPSDESPacketDescriptor)

RTCPSDESPacketDescriptor::RTCPSDESPacketDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTCPSDESPacket", "inet::rtp::RTCPPacket")
{
    propertynames = nullptr;
}

RTCPSDESPacketDescriptor::~RTCPSDESPacketDescriptor()
{
    delete[] propertynames;
}

bool RTCPSDESPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTCPSDESPacket_Base *>(obj)!=nullptr;
}

const char **RTCPSDESPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTCPSDESPacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTCPSDESPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RTCPSDESPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *RTCPSDESPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sdesChunks",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int RTCPSDESPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sdesChunks")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTCPSDESPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cArray",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **RTCPSDESPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RTCPSDESPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTCPSDESPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTCPSDESPacket_Base *pp = (RTCPSDESPacket_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTCPSDESPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTCPSDESPacket_Base *pp = (RTCPSDESPacket_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTCPSDESPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTCPSDESPacket_Base *pp = (RTCPSDESPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSdesChunks(); return out.str();}
        default: return "";
    }
}

bool RTCPSDESPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTCPSDESPacket_Base *pp = (RTCPSDESPacket_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RTCPSDESPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cArray));
        default: return nullptr;
    };
}

void *RTCPSDESPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTCPSDESPacket_Base *pp = (RTCPSDESPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getSdesChunks()); break;
        default: return nullptr;
    }
}

RTCPByePacket_Base::RTCPByePacket_Base(const char *name, short kind) : ::inet::rtp::RTCPPacket(name,kind)
{
    this->setPacketType(RTCP_PT_BYE);
    this->setCount(1);

    this->ssrc = 0;
}

RTCPByePacket_Base::RTCPByePacket_Base(const RTCPByePacket_Base& other) : ::inet::rtp::RTCPPacket(other)
{
    copy(other);
}

RTCPByePacket_Base::~RTCPByePacket_Base()
{
}

RTCPByePacket_Base& RTCPByePacket_Base::operator=(const RTCPByePacket_Base& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTCPPacket::operator=(other);
    copy(other);
    return *this;
}

void RTCPByePacket_Base::copy(const RTCPByePacket_Base& other)
{
    this->ssrc = other.ssrc;
}

void RTCPByePacket_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTCPPacket::parsimPack(b);
    doParsimPacking(b,this->ssrc);
}

void RTCPByePacket_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTCPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->ssrc);
}

uint32_t RTCPByePacket_Base::getSsrc() const
{
    return this->ssrc;
}

void RTCPByePacket_Base::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

class RTCPByePacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTCPByePacketDescriptor();
    virtual ~RTCPByePacketDescriptor();

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

Register_ClassDescriptor(RTCPByePacketDescriptor)

RTCPByePacketDescriptor::RTCPByePacketDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTCPByePacket", "inet::rtp::RTCPPacket")
{
    propertynames = nullptr;
}

RTCPByePacketDescriptor::~RTCPByePacketDescriptor()
{
    delete[] propertynames;
}

bool RTCPByePacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTCPByePacket_Base *>(obj)!=nullptr;
}

const char **RTCPByePacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTCPByePacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTCPByePacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RTCPByePacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *RTCPByePacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ssrc",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int RTCPByePacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssrc")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTCPByePacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **RTCPByePacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RTCPByePacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTCPByePacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTCPByePacket_Base *pp = (RTCPByePacket_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTCPByePacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTCPByePacket_Base *pp = (RTCPByePacket_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTCPByePacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTCPByePacket_Base *pp = (RTCPByePacket_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSsrc());
        default: return "";
    }
}

bool RTCPByePacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTCPByePacket_Base *pp = (RTCPByePacket_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSsrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RTCPByePacketDescriptor::getFieldStructName(int field) const
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

void *RTCPByePacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTCPByePacket_Base *pp = (RTCPByePacket_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

