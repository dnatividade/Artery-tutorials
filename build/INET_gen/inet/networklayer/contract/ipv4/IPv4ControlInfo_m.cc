//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/contract/ipv4/IPv4ControlInfo.msg.
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
#include "IPv4ControlInfo_m.h"

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

IPv4ControlInfo_Base::IPv4ControlInfo_Base() : ::omnetpp::cObject()
{
    this->interfaceId = -1;
    this->multicastLoop = false;
    this->protocol = 0;
    this->typeOfService = 0;
    this->timeToLive = 0;
    this->dontFragment = false;
}

IPv4ControlInfo_Base::IPv4ControlInfo_Base(const IPv4ControlInfo_Base& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

IPv4ControlInfo_Base::~IPv4ControlInfo_Base()
{
}

IPv4ControlInfo_Base& IPv4ControlInfo_Base::operator=(const IPv4ControlInfo_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void IPv4ControlInfo_Base::copy(const IPv4ControlInfo_Base& other)
{
    this->destAddr = other.destAddr;
    this->srcAddr = other.srcAddr;
    this->interfaceId = other.interfaceId;
    this->multicastLoop = other.multicastLoop;
    this->protocol = other.protocol;
    this->typeOfService = other.typeOfService;
    this->timeToLive = other.timeToLive;
    this->dontFragment = other.dontFragment;
}

void IPv4ControlInfo_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastLoop);
    doParsimPacking(b,this->protocol);
    doParsimPacking(b,this->typeOfService);
    // field diffServCodePoint is abstract -- please do packing in customized class
    // field explicitCongestionNotification is abstract -- please do packing in customized class
    doParsimPacking(b,this->timeToLive);
    doParsimPacking(b,this->dontFragment);
}

void IPv4ControlInfo_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastLoop);
    doParsimUnpacking(b,this->protocol);
    doParsimUnpacking(b,this->typeOfService);
    // field diffServCodePoint is abstract -- please do unpacking in customized class
    // field explicitCongestionNotification is abstract -- please do unpacking in customized class
    doParsimUnpacking(b,this->timeToLive);
    doParsimUnpacking(b,this->dontFragment);
}

IPv4Address& IPv4ControlInfo_Base::getDestAddr()
{
    return this->destAddr;
}

void IPv4ControlInfo_Base::setDestAddr(const IPv4Address& destAddr)
{
    this->destAddr = destAddr;
}

IPv4Address& IPv4ControlInfo_Base::getSrcAddr()
{
    return this->srcAddr;
}

void IPv4ControlInfo_Base::setSrcAddr(const IPv4Address& srcAddr)
{
    this->srcAddr = srcAddr;
}

int IPv4ControlInfo_Base::getInterfaceId() const
{
    return this->interfaceId;
}

void IPv4ControlInfo_Base::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

bool IPv4ControlInfo_Base::getMulticastLoop() const
{
    return this->multicastLoop;
}

void IPv4ControlInfo_Base::setMulticastLoop(bool multicastLoop)
{
    this->multicastLoop = multicastLoop;
}

short IPv4ControlInfo_Base::getProtocol() const
{
    return this->protocol;
}

void IPv4ControlInfo_Base::setProtocol(short protocol)
{
    this->protocol = protocol;
}

unsigned char IPv4ControlInfo_Base::getTypeOfService() const
{
    return this->typeOfService;
}

void IPv4ControlInfo_Base::setTypeOfService(unsigned char typeOfService)
{
    this->typeOfService = typeOfService;
}

short IPv4ControlInfo_Base::getTimeToLive() const
{
    return this->timeToLive;
}

void IPv4ControlInfo_Base::setTimeToLive(short timeToLive)
{
    this->timeToLive = timeToLive;
}

bool IPv4ControlInfo_Base::getDontFragment() const
{
    return this->dontFragment;
}

void IPv4ControlInfo_Base::setDontFragment(bool dontFragment)
{
    this->dontFragment = dontFragment;
}

class IPv4ControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4ControlInfoDescriptor();
    virtual ~IPv4ControlInfoDescriptor();

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

Register_ClassDescriptor(IPv4ControlInfoDescriptor)

IPv4ControlInfoDescriptor::IPv4ControlInfoDescriptor() : omnetpp::cClassDescriptor("inet::IPv4ControlInfo", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IPv4ControlInfoDescriptor::~IPv4ControlInfoDescriptor()
{
    delete[] propertynames;
}

bool IPv4ControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4ControlInfo_Base *>(obj)!=nullptr;
}

const char **IPv4ControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4ControlInfoDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4ControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int IPv4ControlInfoDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *IPv4ControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destAddr",
        "srcAddr",
        "interfaceId",
        "multicastLoop",
        "protocol",
        "typeOfService",
        "diffServCodePoint",
        "explicitCongestionNotification",
        "timeToLive",
        "dontFragment",
    };
    return (field>=0 && field<10) ? fieldNames[field] : nullptr;
}

int IPv4ControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastLoop")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocol")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "typeOfService")==0) return base+5;
    if (fieldName[0]=='d' && strcmp(fieldName, "diffServCodePoint")==0) return base+6;
    if (fieldName[0]=='e' && strcmp(fieldName, "explicitCongestionNotification")==0) return base+7;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeToLive")==0) return base+8;
    if (fieldName[0]=='d' && strcmp(fieldName, "dontFragment")==0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4ControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "IPv4Address",
        "int",
        "bool",
        "short",
        "unsigned char",
        "int",
        "int",
        "short",
        "bool",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv4ControlInfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *IPv4ControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4:
            if (!strcmp(propertyname,"enum")) return "inet::IPProtocolId";
            return nullptr;
        default: return nullptr;
    }
}

int IPv4ControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4ControlInfo_Base *pp = (IPv4ControlInfo_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv4ControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4ControlInfo_Base *pp = (IPv4ControlInfo_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4ControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4ControlInfo_Base *pp = (IPv4ControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSrcAddr(); return out.str();}
        case 2: return long2string(pp->getInterfaceId());
        case 3: return bool2string(pp->getMulticastLoop());
        case 4: return enum2string(pp->getProtocol(), "inet::IPProtocolId");
        case 5: return ulong2string(pp->getTypeOfService());
        case 6: return long2string(pp->getDiffServCodePoint());
        case 7: return long2string(pp->getExplicitCongestionNotification());
        case 8: return long2string(pp->getTimeToLive());
        case 9: return bool2string(pp->getDontFragment());
        default: return "";
    }
}

bool IPv4ControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4ControlInfo_Base *pp = (IPv4ControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 2: pp->setInterfaceId(string2long(value)); return true;
        case 3: pp->setMulticastLoop(string2bool(value)); return true;
        case 4: pp->setProtocol((inet::IPProtocolId)string2enum(value, "inet::IPProtocolId")); return true;
        case 5: pp->setTypeOfService(string2ulong(value)); return true;
        case 6: pp->setDiffServCodePoint(string2long(value)); return true;
        case 7: pp->setExplicitCongestionNotification(string2long(value)); return true;
        case 8: pp->setTimeToLive(string2long(value)); return true;
        case 9: pp->setDontFragment(string2bool(value)); return true;
        default: return false;
    }
}

const char *IPv4ControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *IPv4ControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4ControlInfo_Base *pp = (IPv4ControlInfo_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDestAddr()); break;
        case 1: return (void *)(&pp->getSrcAddr()); break;
        default: return nullptr;
    }
}

} // namespace inet

