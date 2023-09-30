//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/contract/ipv6/IPv6ControlInfo.msg.
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
#include "IPv6ControlInfo_m.h"

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

IPv6ControlInfo_Base::IPv6ControlInfo_Base() : ::omnetpp::cObject()
{
    this->protocol = 0;
    this->trafficClass = 0;
    this->hopLimit = 0;
    this->interfaceId = -1;
    this->multicastLoop = false;
}

IPv6ControlInfo_Base::IPv6ControlInfo_Base(const IPv6ControlInfo_Base& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

IPv6ControlInfo_Base::~IPv6ControlInfo_Base()
{
}

IPv6ControlInfo_Base& IPv6ControlInfo_Base::operator=(const IPv6ControlInfo_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void IPv6ControlInfo_Base::copy(const IPv6ControlInfo_Base& other)
{
    this->protocol = other.protocol;
    this->destAddr = other.destAddr;
    this->srcAddr = other.srcAddr;
    this->trafficClass = other.trafficClass;
    this->hopLimit = other.hopLimit;
    this->interfaceId = other.interfaceId;
    this->multicastLoop = other.multicastLoop;
}

void IPv6ControlInfo_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->protocol);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->trafficClass);
    // field diffServCodePoint is abstract -- please do packing in customized class
    // field explicitCongestionNotification is abstract -- please do packing in customized class
    doParsimPacking(b,this->hopLimit);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastLoop);
    // field extensionHeader is abstract -- please do packing in customized class
}

void IPv6ControlInfo_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->protocol);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->trafficClass);
    // field diffServCodePoint is abstract -- please do unpacking in customized class
    // field explicitCongestionNotification is abstract -- please do unpacking in customized class
    doParsimUnpacking(b,this->hopLimit);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastLoop);
    // field extensionHeader is abstract -- please do unpacking in customized class
}

short IPv6ControlInfo_Base::getProtocol() const
{
    return this->protocol;
}

void IPv6ControlInfo_Base::setProtocol(short protocol)
{
    this->protocol = protocol;
}

IPv6Address& IPv6ControlInfo_Base::getDestAddr()
{
    return this->destAddr;
}

void IPv6ControlInfo_Base::setDestAddr(const IPv6Address& destAddr)
{
    this->destAddr = destAddr;
}

IPv6Address& IPv6ControlInfo_Base::getSrcAddr()
{
    return this->srcAddr;
}

void IPv6ControlInfo_Base::setSrcAddr(const IPv6Address& srcAddr)
{
    this->srcAddr = srcAddr;
}

unsigned char IPv6ControlInfo_Base::getTrafficClass() const
{
    return this->trafficClass;
}

void IPv6ControlInfo_Base::setTrafficClass(unsigned char trafficClass)
{
    this->trafficClass = trafficClass;
}

short IPv6ControlInfo_Base::getHopLimit() const
{
    return this->hopLimit;
}

void IPv6ControlInfo_Base::setHopLimit(short hopLimit)
{
    this->hopLimit = hopLimit;
}

int IPv6ControlInfo_Base::getInterfaceId() const
{
    return this->interfaceId;
}

void IPv6ControlInfo_Base::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

bool IPv6ControlInfo_Base::getMulticastLoop() const
{
    return this->multicastLoop;
}

void IPv6ControlInfo_Base::setMulticastLoop(bool multicastLoop)
{
    this->multicastLoop = multicastLoop;
}

class IPv6ControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6ControlInfoDescriptor();
    virtual ~IPv6ControlInfoDescriptor();

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

Register_ClassDescriptor(IPv6ControlInfoDescriptor)

IPv6ControlInfoDescriptor::IPv6ControlInfoDescriptor() : omnetpp::cClassDescriptor("inet::IPv6ControlInfo", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IPv6ControlInfoDescriptor::~IPv6ControlInfoDescriptor()
{
    delete[] propertynames;
}

bool IPv6ControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6ControlInfo_Base *>(obj)!=nullptr;
}

const char **IPv6ControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6ControlInfoDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6ControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int IPv6ControlInfoDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *IPv6ControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "protocol",
        "destAddr",
        "srcAddr",
        "trafficClass",
        "diffServCodePoint",
        "explicitCongestionNotification",
        "hopLimit",
        "interfaceId",
        "multicastLoop",
        "extensionHeader",
    };
    return (field>=0 && field<10) ? fieldNames[field] : nullptr;
}

int IPv6ControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocol")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "trafficClass")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "diffServCodePoint")==0) return base+4;
    if (fieldName[0]=='e' && strcmp(fieldName, "explicitCongestionNotification")==0) return base+5;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopLimit")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+7;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastLoop")==0) return base+8;
    if (fieldName[0]=='e' && strcmp(fieldName, "extensionHeader")==0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6ControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "IPv6Address",
        "IPv6Address",
        "unsigned char",
        "int",
        "int",
        "short",
        "int",
        "bool",
        "IPv6ExtensionHeaderPtr",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6ControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6ControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::IPProtocolId";
            return nullptr;
        default: return nullptr;
    }
}

int IPv6ControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6ControlInfo_Base *pp = (IPv6ControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 9: return pp->getExtensionHeaderArraySize();
        default: return 0;
    }
}

const char *IPv6ControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6ControlInfo_Base *pp = (IPv6ControlInfo_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6ControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6ControlInfo_Base *pp = (IPv6ControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getProtocol(), "inet::IPProtocolId");
        case 1: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSrcAddr(); return out.str();}
        case 3: return ulong2string(pp->getTrafficClass());
        case 4: return long2string(pp->getDiffServCodePoint());
        case 5: return long2string(pp->getExplicitCongestionNotification());
        case 6: return long2string(pp->getHopLimit());
        case 7: return long2string(pp->getInterfaceId());
        case 8: return bool2string(pp->getMulticastLoop());
        case 9: {std::stringstream out; out << pp->getExtensionHeader(i); return out.str();}
        default: return "";
    }
}

bool IPv6ControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6ControlInfo_Base *pp = (IPv6ControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setProtocol((inet::IPProtocolId)string2enum(value, "inet::IPProtocolId")); return true;
        case 3: pp->setTrafficClass(string2ulong(value)); return true;
        case 4: pp->setDiffServCodePoint(string2long(value)); return true;
        case 5: pp->setExplicitCongestionNotification(string2long(value)); return true;
        case 6: pp->setHopLimit(string2long(value)); return true;
        case 7: pp->setInterfaceId(string2long(value)); return true;
        case 8: pp->setMulticastLoop(string2bool(value)); return true;
        default: return false;
    }
}

const char *IPv6ControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(IPv6Address));
        case 2: return omnetpp::opp_typename(typeid(IPv6Address));
        case 9: return omnetpp::opp_typename(typeid(IPv6ExtensionHeaderPtr));
        default: return nullptr;
    };
}

void *IPv6ControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6ControlInfo_Base *pp = (IPv6ControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getDestAddr()); break;
        case 2: return (void *)(&pp->getSrcAddr()); break;
        case 9: return (void *)(&pp->getExtensionHeader(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

