//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/contract/udp/UDPControlInfo.msg.
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
#include "UDPControlInfo_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::UDPCommandCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::UDPCommandCode"));
    e->insert(UDP_C_DATA, "UDP_C_DATA");
    e->insert(UDP_C_BIND, "UDP_C_BIND");
    e->insert(UDP_C_CONNECT, "UDP_C_CONNECT");
    e->insert(UDP_C_SETOPTION, "UDP_C_SETOPTION");
    e->insert(UDP_C_CLOSE, "UDP_C_CLOSE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::UDPStatusInd");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::UDPStatusInd"));
    e->insert(UDP_I_DATA, "UDP_I_DATA");
    e->insert(UDP_I_ERROR, "UDP_I_ERROR");
)

Register_Class(UDPControlInfo)

UDPControlInfo::UDPControlInfo() : ::omnetpp::cObject()
{
    this->sockId = -1;
}

UDPControlInfo::UDPControlInfo(const UDPControlInfo& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

UDPControlInfo::~UDPControlInfo()
{
}

UDPControlInfo& UDPControlInfo::operator=(const UDPControlInfo& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void UDPControlInfo::copy(const UDPControlInfo& other)
{
    this->sockId = other.sockId;
}

void UDPControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->sockId);
}

void UDPControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->sockId);
}

int UDPControlInfo::getSockId() const
{
    return this->sockId;
}

void UDPControlInfo::setSockId(int sockId)
{
    this->sockId = sockId;
}

class UDPControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPControlInfoDescriptor();
    virtual ~UDPControlInfoDescriptor();

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

Register_ClassDescriptor(UDPControlInfoDescriptor)

UDPControlInfoDescriptor::UDPControlInfoDescriptor() : omnetpp::cClassDescriptor("inet::UDPControlInfo", "omnetpp::cObject")
{
    propertynames = nullptr;
}

UDPControlInfoDescriptor::~UDPControlInfoDescriptor()
{
    delete[] propertynames;
}

bool UDPControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPControlInfo *>(obj)!=nullptr;
}

const char **UDPControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UDPControlInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *UDPControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sockId",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UDPControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sockId")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPControlInfo *pp = (UDPControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPControlInfo *pp = (UDPControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPControlInfo *pp = (UDPControlInfo *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSockId());
        default: return "";
    }
}

bool UDPControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPControlInfo *pp = (UDPControlInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setSockId(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPControlInfoDescriptor::getFieldStructName(int field) const
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

void *UDPControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPControlInfo *pp = (UDPControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPBindCommand)

UDPBindCommand::UDPBindCommand() : ::inet::UDPControlInfo()
{
    this->localPort = -1;
}

UDPBindCommand::UDPBindCommand(const UDPBindCommand& other) : ::inet::UDPControlInfo(other)
{
    copy(other);
}

UDPBindCommand::~UDPBindCommand()
{
}

UDPBindCommand& UDPBindCommand::operator=(const UDPBindCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UDPBindCommand::copy(const UDPBindCommand& other)
{
    this->localAddr = other.localAddr;
    this->localPort = other.localPort;
}

void UDPBindCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPControlInfo::parsimPack(b);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->localPort);
}

void UDPBindCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->localPort);
}

L3Address& UDPBindCommand::getLocalAddr()
{
    return this->localAddr;
}

void UDPBindCommand::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

int UDPBindCommand::getLocalPort() const
{
    return this->localPort;
}

void UDPBindCommand::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

class UDPBindCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPBindCommandDescriptor();
    virtual ~UDPBindCommandDescriptor();

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

Register_ClassDescriptor(UDPBindCommandDescriptor)

UDPBindCommandDescriptor::UDPBindCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPBindCommand", "inet::UDPControlInfo")
{
    propertynames = nullptr;
}

UDPBindCommandDescriptor::~UDPBindCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPBindCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPBindCommand *>(obj)!=nullptr;
}

const char **UDPBindCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPBindCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPBindCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UDPBindCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *UDPBindCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddr",
        "localPort",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int UDPBindCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localAddr")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localPort")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPBindCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPBindCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPBindCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPBindCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPBindCommand *pp = (UDPBindCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPBindCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPBindCommand *pp = (UDPBindCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPBindCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPBindCommand *pp = (UDPBindCommand *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getLocalAddr(); return out.str();}
        case 1: return long2string(pp->getLocalPort());
        default: return "";
    }
}

bool UDPBindCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPBindCommand *pp = (UDPBindCommand *)object; (void)pp;
    switch (field) {
        case 1: pp->setLocalPort(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPBindCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPBindCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPBindCommand *pp = (UDPBindCommand *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getLocalAddr()); break;
        default: return nullptr;
    }
}

Register_Class(UDPConnectCommand)

UDPConnectCommand::UDPConnectCommand() : ::inet::UDPControlInfo()
{
    this->remotePort = -1;
}

UDPConnectCommand::UDPConnectCommand(const UDPConnectCommand& other) : ::inet::UDPControlInfo(other)
{
    copy(other);
}

UDPConnectCommand::~UDPConnectCommand()
{
}

UDPConnectCommand& UDPConnectCommand::operator=(const UDPConnectCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UDPConnectCommand::copy(const UDPConnectCommand& other)
{
    this->remoteAddr = other.remoteAddr;
    this->remotePort = other.remotePort;
}

void UDPConnectCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPControlInfo::parsimPack(b);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->remotePort);
}

void UDPConnectCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->remotePort);
}

L3Address& UDPConnectCommand::getRemoteAddr()
{
    return this->remoteAddr;
}

void UDPConnectCommand::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int UDPConnectCommand::getRemotePort() const
{
    return this->remotePort;
}

void UDPConnectCommand::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

class UDPConnectCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPConnectCommandDescriptor();
    virtual ~UDPConnectCommandDescriptor();

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

Register_ClassDescriptor(UDPConnectCommandDescriptor)

UDPConnectCommandDescriptor::UDPConnectCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPConnectCommand", "inet::UDPControlInfo")
{
    propertynames = nullptr;
}

UDPConnectCommandDescriptor::~UDPConnectCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPConnectCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPConnectCommand *>(obj)!=nullptr;
}

const char **UDPConnectCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPConnectCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPConnectCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UDPConnectCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *UDPConnectCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddr",
        "remotePort",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int UDPConnectCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remotePort")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPConnectCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPConnectCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPConnectCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPConnectCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPConnectCommand *pp = (UDPConnectCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPConnectCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPConnectCommand *pp = (UDPConnectCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPConnectCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPConnectCommand *pp = (UDPConnectCommand *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 1: return long2string(pp->getRemotePort());
        default: return "";
    }
}

bool UDPConnectCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPConnectCommand *pp = (UDPConnectCommand *)object; (void)pp;
    switch (field) {
        case 1: pp->setRemotePort(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPConnectCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPConnectCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPConnectCommand *pp = (UDPConnectCommand *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(UDPSendCommand)

UDPSendCommand::UDPSendCommand() : ::inet::UDPControlInfo()
{
    this->destPort = -1;
    this->interfaceId = -1;
}

UDPSendCommand::UDPSendCommand(const UDPSendCommand& other) : ::inet::UDPControlInfo(other)
{
    copy(other);
}

UDPSendCommand::~UDPSendCommand()
{
}

UDPSendCommand& UDPSendCommand::operator=(const UDPSendCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UDPSendCommand::copy(const UDPSendCommand& other)
{
    this->destAddr = other.destAddr;
    this->destPort = other.destPort;
    this->srcAddr = other.srcAddr;
    this->interfaceId = other.interfaceId;
}

void UDPSendCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPControlInfo::parsimPack(b);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->interfaceId);
}

void UDPSendCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->interfaceId);
}

L3Address& UDPSendCommand::getDestAddr()
{
    return this->destAddr;
}

void UDPSendCommand::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

int UDPSendCommand::getDestPort() const
{
    return this->destPort;
}

void UDPSendCommand::setDestPort(int destPort)
{
    this->destPort = destPort;
}

L3Address& UDPSendCommand::getSrcAddr()
{
    return this->srcAddr;
}

void UDPSendCommand::setSrcAddr(const L3Address& srcAddr)
{
    this->srcAddr = srcAddr;
}

int UDPSendCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UDPSendCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

class UDPSendCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSendCommandDescriptor();
    virtual ~UDPSendCommandDescriptor();

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

Register_ClassDescriptor(UDPSendCommandDescriptor)

UDPSendCommandDescriptor::UDPSendCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSendCommand", "inet::UDPControlInfo")
{
    propertynames = nullptr;
}

UDPSendCommandDescriptor::~UDPSendCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSendCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSendCommand *>(obj)!=nullptr;
}

const char **UDPSendCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSendCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSendCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int UDPSendCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *UDPSendCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "destAddr",
        "destPort",
        "srcAddr",
        "interfaceId",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int UDPSendCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSendCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "int",
        "L3Address",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPSendCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPSendCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPSendCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSendCommand *pp = (UDPSendCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPSendCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSendCommand *pp = (UDPSendCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSendCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSendCommand *pp = (UDPSendCommand *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 1: return long2string(pp->getDestPort());
        case 2: {std::stringstream out; out << pp->getSrcAddr(); return out.str();}
        case 3: return long2string(pp->getInterfaceId());
        default: return "";
    }
}

bool UDPSendCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSendCommand *pp = (UDPSendCommand *)object; (void)pp;
    switch (field) {
        case 1: pp->setDestPort(string2long(value)); return true;
        case 3: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPSendCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPSendCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSendCommand *pp = (UDPSendCommand *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getDestAddr()); break;
        case 2: return (void *)(&pp->getSrcAddr()); break;
        default: return nullptr;
    }
}

Register_Class(UDPCloseCommand)

UDPCloseCommand::UDPCloseCommand() : ::inet::UDPControlInfo()
{
}

UDPCloseCommand::UDPCloseCommand(const UDPCloseCommand& other) : ::inet::UDPControlInfo(other)
{
    copy(other);
}

UDPCloseCommand::~UDPCloseCommand()
{
}

UDPCloseCommand& UDPCloseCommand::operator=(const UDPCloseCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UDPCloseCommand::copy(const UDPCloseCommand& other)
{
}

void UDPCloseCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPControlInfo::parsimPack(b);
}

void UDPCloseCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPControlInfo::parsimUnpack(b);
}

class UDPCloseCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPCloseCommandDescriptor();
    virtual ~UDPCloseCommandDescriptor();

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

Register_ClassDescriptor(UDPCloseCommandDescriptor)

UDPCloseCommandDescriptor::UDPCloseCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPCloseCommand", "inet::UDPControlInfo")
{
    propertynames = nullptr;
}

UDPCloseCommandDescriptor::~UDPCloseCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPCloseCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPCloseCommand *>(obj)!=nullptr;
}

const char **UDPCloseCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPCloseCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPCloseCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UDPCloseCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UDPCloseCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UDPCloseCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPCloseCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UDPCloseCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPCloseCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPCloseCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPCloseCommand *pp = (UDPCloseCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPCloseCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPCloseCommand *pp = (UDPCloseCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPCloseCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPCloseCommand *pp = (UDPCloseCommand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UDPCloseCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPCloseCommand *pp = (UDPCloseCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UDPCloseCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UDPCloseCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPCloseCommand *pp = (UDPCloseCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPDataIndication)

UDPDataIndication::UDPDataIndication() : ::inet::UDPControlInfo()
{
    this->srcPort = 0;
    this->destPort = 0;
    this->ttl = 0;
    this->interfaceId = 0;
    this->typeOfService = 0;
}

UDPDataIndication::UDPDataIndication(const UDPDataIndication& other) : ::inet::UDPControlInfo(other)
{
    copy(other);
}

UDPDataIndication::~UDPDataIndication()
{
}

UDPDataIndication& UDPDataIndication::operator=(const UDPDataIndication& other)
{
    if (this==&other) return *this;
    ::inet::UDPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UDPDataIndication::copy(const UDPDataIndication& other)
{
    this->srcAddr = other.srcAddr;
    this->destAddr = other.destAddr;
    this->srcPort = other.srcPort;
    this->destPort = other.destPort;
    this->ttl = other.ttl;
    this->interfaceId = other.interfaceId;
    this->typeOfService = other.typeOfService;
}

void UDPDataIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPControlInfo::parsimPack(b);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->typeOfService);
}

void UDPDataIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->typeOfService);
}

L3Address& UDPDataIndication::getSrcAddr()
{
    return this->srcAddr;
}

void UDPDataIndication::setSrcAddr(const L3Address& srcAddr)
{
    this->srcAddr = srcAddr;
}

L3Address& UDPDataIndication::getDestAddr()
{
    return this->destAddr;
}

void UDPDataIndication::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

int UDPDataIndication::getSrcPort() const
{
    return this->srcPort;
}

void UDPDataIndication::setSrcPort(int srcPort)
{
    this->srcPort = srcPort;
}

int UDPDataIndication::getDestPort() const
{
    return this->destPort;
}

void UDPDataIndication::setDestPort(int destPort)
{
    this->destPort = destPort;
}

int UDPDataIndication::getTtl() const
{
    return this->ttl;
}

void UDPDataIndication::setTtl(int ttl)
{
    this->ttl = ttl;
}

int UDPDataIndication::getInterfaceId() const
{
    return this->interfaceId;
}

void UDPDataIndication::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

unsigned char UDPDataIndication::getTypeOfService() const
{
    return this->typeOfService;
}

void UDPDataIndication::setTypeOfService(unsigned char typeOfService)
{
    this->typeOfService = typeOfService;
}

class UDPDataIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPDataIndicationDescriptor();
    virtual ~UDPDataIndicationDescriptor();

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

Register_ClassDescriptor(UDPDataIndicationDescriptor)

UDPDataIndicationDescriptor::UDPDataIndicationDescriptor() : omnetpp::cClassDescriptor("inet::UDPDataIndication", "inet::UDPControlInfo")
{
    propertynames = nullptr;
}

UDPDataIndicationDescriptor::~UDPDataIndicationDescriptor()
{
    delete[] propertynames;
}

bool UDPDataIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPDataIndication *>(obj)!=nullptr;
}

const char **UDPDataIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPDataIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPDataIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int UDPDataIndicationDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *UDPDataIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddr",
        "destAddr",
        "srcPort",
        "destPort",
        "ttl",
        "interfaceId",
        "typeOfService",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int UDPDataIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPort")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "ttl")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "typeOfService")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPDataIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "L3Address",
        "int",
        "int",
        "int",
        "int",
        "unsigned char",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPDataIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPDataIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPDataIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPDataIndication *pp = (UDPDataIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPDataIndicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPDataIndication *pp = (UDPDataIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPDataIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPDataIndication *pp = (UDPDataIndication *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcAddr(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 2: return long2string(pp->getSrcPort());
        case 3: return long2string(pp->getDestPort());
        case 4: return long2string(pp->getTtl());
        case 5: return long2string(pp->getInterfaceId());
        case 6: return ulong2string(pp->getTypeOfService());
        default: return "";
    }
}

bool UDPDataIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPDataIndication *pp = (UDPDataIndication *)object; (void)pp;
    switch (field) {
        case 2: pp->setSrcPort(string2long(value)); return true;
        case 3: pp->setDestPort(string2long(value)); return true;
        case 4: pp->setTtl(string2long(value)); return true;
        case 5: pp->setInterfaceId(string2long(value)); return true;
        case 6: pp->setTypeOfService(string2ulong(value)); return true;
        default: return false;
    }
}

const char *UDPDataIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPDataIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPDataIndication *pp = (UDPDataIndication *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcAddr()); break;
        case 1: return (void *)(&pp->getDestAddr()); break;
        default: return nullptr;
    }
}

Register_Class(UDPErrorIndication)

UDPErrorIndication::UDPErrorIndication() : ::inet::UDPControlInfo()
{
    this->srcPort = 0;
    this->destPort = 0;
}

UDPErrorIndication::UDPErrorIndication(const UDPErrorIndication& other) : ::inet::UDPControlInfo(other)
{
    copy(other);
}

UDPErrorIndication::~UDPErrorIndication()
{
}

UDPErrorIndication& UDPErrorIndication::operator=(const UDPErrorIndication& other)
{
    if (this==&other) return *this;
    ::inet::UDPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UDPErrorIndication::copy(const UDPErrorIndication& other)
{
    this->srcAddr = other.srcAddr;
    this->destAddr = other.destAddr;
    this->srcPort = other.srcPort;
    this->destPort = other.destPort;
}

void UDPErrorIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPControlInfo::parsimPack(b);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destPort);
}

void UDPErrorIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destPort);
}

L3Address& UDPErrorIndication::getSrcAddr()
{
    return this->srcAddr;
}

void UDPErrorIndication::setSrcAddr(const L3Address& srcAddr)
{
    this->srcAddr = srcAddr;
}

L3Address& UDPErrorIndication::getDestAddr()
{
    return this->destAddr;
}

void UDPErrorIndication::setDestAddr(const L3Address& destAddr)
{
    this->destAddr = destAddr;
}

int UDPErrorIndication::getSrcPort() const
{
    return this->srcPort;
}

void UDPErrorIndication::setSrcPort(int srcPort)
{
    this->srcPort = srcPort;
}

int UDPErrorIndication::getDestPort() const
{
    return this->destPort;
}

void UDPErrorIndication::setDestPort(int destPort)
{
    this->destPort = destPort;
}

class UDPErrorIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPErrorIndicationDescriptor();
    virtual ~UDPErrorIndicationDescriptor();

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

Register_ClassDescriptor(UDPErrorIndicationDescriptor)

UDPErrorIndicationDescriptor::UDPErrorIndicationDescriptor() : omnetpp::cClassDescriptor("inet::UDPErrorIndication", "inet::UDPControlInfo")
{
    propertynames = nullptr;
}

UDPErrorIndicationDescriptor::~UDPErrorIndicationDescriptor()
{
    delete[] propertynames;
}

bool UDPErrorIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPErrorIndication *>(obj)!=nullptr;
}

const char **UDPErrorIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPErrorIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPErrorIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int UDPErrorIndicationDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *UDPErrorIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddr",
        "destAddr",
        "srcPort",
        "destPort",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int UDPErrorIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddr")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddr")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPort")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPErrorIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "L3Address",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPErrorIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPErrorIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPErrorIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPErrorIndication *pp = (UDPErrorIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPErrorIndicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPErrorIndication *pp = (UDPErrorIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPErrorIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPErrorIndication *pp = (UDPErrorIndication *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcAddr(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDestAddr(); return out.str();}
        case 2: return long2string(pp->getSrcPort());
        case 3: return long2string(pp->getDestPort());
        default: return "";
    }
}

bool UDPErrorIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPErrorIndication *pp = (UDPErrorIndication *)object; (void)pp;
    switch (field) {
        case 2: pp->setSrcPort(string2long(value)); return true;
        case 3: pp->setDestPort(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPErrorIndicationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPErrorIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPErrorIndication *pp = (UDPErrorIndication *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcAddr()); break;
        case 1: return (void *)(&pp->getDestAddr()); break;
        default: return nullptr;
    }
}

Register_Class(UDPSetOptionCommand)

UDPSetOptionCommand::UDPSetOptionCommand() : ::inet::UDPControlInfo()
{
}

UDPSetOptionCommand::UDPSetOptionCommand(const UDPSetOptionCommand& other) : ::inet::UDPControlInfo(other)
{
    copy(other);
}

UDPSetOptionCommand::~UDPSetOptionCommand()
{
}

UDPSetOptionCommand& UDPSetOptionCommand::operator=(const UDPSetOptionCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void UDPSetOptionCommand::copy(const UDPSetOptionCommand& other)
{
}

void UDPSetOptionCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPControlInfo::parsimPack(b);
}

void UDPSetOptionCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPControlInfo::parsimUnpack(b);
}

class UDPSetOptionCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSetOptionCommandDescriptor();
    virtual ~UDPSetOptionCommandDescriptor();

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

Register_ClassDescriptor(UDPSetOptionCommandDescriptor)

UDPSetOptionCommandDescriptor::UDPSetOptionCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSetOptionCommand", "inet::UDPControlInfo")
{
    propertynames = nullptr;
}

UDPSetOptionCommandDescriptor::~UDPSetOptionCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSetOptionCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSetOptionCommand *>(obj)!=nullptr;
}

const char **UDPSetOptionCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSetOptionCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSetOptionCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int UDPSetOptionCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *UDPSetOptionCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int UDPSetOptionCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSetOptionCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **UDPSetOptionCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPSetOptionCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPSetOptionCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSetOptionCommand *pp = (UDPSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPSetOptionCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetOptionCommand *pp = (UDPSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSetOptionCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetOptionCommand *pp = (UDPSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool UDPSetOptionCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSetOptionCommand *pp = (UDPSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UDPSetOptionCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *UDPSetOptionCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSetOptionCommand *pp = (UDPSetOptionCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPSetTimeToLiveCommand)

UDPSetTimeToLiveCommand::UDPSetTimeToLiveCommand() : ::inet::UDPSetOptionCommand()
{
    this->ttl = 0;
}

UDPSetTimeToLiveCommand::UDPSetTimeToLiveCommand(const UDPSetTimeToLiveCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    copy(other);
}

UDPSetTimeToLiveCommand::~UDPSetTimeToLiveCommand()
{
}

UDPSetTimeToLiveCommand& UDPSetTimeToLiveCommand::operator=(const UDPSetTimeToLiveCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPSetTimeToLiveCommand::copy(const UDPSetTimeToLiveCommand& other)
{
    this->ttl = other.ttl;
}

void UDPSetTimeToLiveCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->ttl);
}

void UDPSetTimeToLiveCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->ttl);
}

int UDPSetTimeToLiveCommand::getTtl() const
{
    return this->ttl;
}

void UDPSetTimeToLiveCommand::setTtl(int ttl)
{
    this->ttl = ttl;
}

class UDPSetTimeToLiveCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSetTimeToLiveCommandDescriptor();
    virtual ~UDPSetTimeToLiveCommandDescriptor();

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

Register_ClassDescriptor(UDPSetTimeToLiveCommandDescriptor)

UDPSetTimeToLiveCommandDescriptor::UDPSetTimeToLiveCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSetTimeToLiveCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPSetTimeToLiveCommandDescriptor::~UDPSetTimeToLiveCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSetTimeToLiveCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSetTimeToLiveCommand *>(obj)!=nullptr;
}

const char **UDPSetTimeToLiveCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSetTimeToLiveCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSetTimeToLiveCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UDPSetTimeToLiveCommandDescriptor::getFieldTypeFlags(int field) const
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

const char *UDPSetTimeToLiveCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ttl",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UDPSetTimeToLiveCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "ttl")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSetTimeToLiveCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPSetTimeToLiveCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPSetTimeToLiveCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPSetTimeToLiveCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSetTimeToLiveCommand *pp = (UDPSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPSetTimeToLiveCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetTimeToLiveCommand *pp = (UDPSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSetTimeToLiveCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetTimeToLiveCommand *pp = (UDPSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTtl());
        default: return "";
    }
}

bool UDPSetTimeToLiveCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSetTimeToLiveCommand *pp = (UDPSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setTtl(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPSetTimeToLiveCommandDescriptor::getFieldStructName(int field) const
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

void *UDPSetTimeToLiveCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSetTimeToLiveCommand *pp = (UDPSetTimeToLiveCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPSetTypeOfServiceCommand)

UDPSetTypeOfServiceCommand::UDPSetTypeOfServiceCommand() : ::inet::UDPSetOptionCommand()
{
    this->tos = 0;
}

UDPSetTypeOfServiceCommand::UDPSetTypeOfServiceCommand(const UDPSetTypeOfServiceCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    copy(other);
}

UDPSetTypeOfServiceCommand::~UDPSetTypeOfServiceCommand()
{
}

UDPSetTypeOfServiceCommand& UDPSetTypeOfServiceCommand::operator=(const UDPSetTypeOfServiceCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPSetTypeOfServiceCommand::copy(const UDPSetTypeOfServiceCommand& other)
{
    this->tos = other.tos;
}

void UDPSetTypeOfServiceCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->tos);
}

void UDPSetTypeOfServiceCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->tos);
}

char UDPSetTypeOfServiceCommand::getTos() const
{
    return this->tos;
}

void UDPSetTypeOfServiceCommand::setTos(char tos)
{
    this->tos = tos;
}

class UDPSetTypeOfServiceCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSetTypeOfServiceCommandDescriptor();
    virtual ~UDPSetTypeOfServiceCommandDescriptor();

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

Register_ClassDescriptor(UDPSetTypeOfServiceCommandDescriptor)

UDPSetTypeOfServiceCommandDescriptor::UDPSetTypeOfServiceCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSetTypeOfServiceCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPSetTypeOfServiceCommandDescriptor::~UDPSetTypeOfServiceCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSetTypeOfServiceCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSetTypeOfServiceCommand *>(obj)!=nullptr;
}

const char **UDPSetTypeOfServiceCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSetTypeOfServiceCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSetTypeOfServiceCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UDPSetTypeOfServiceCommandDescriptor::getFieldTypeFlags(int field) const
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

const char *UDPSetTypeOfServiceCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tos",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UDPSetTypeOfServiceCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tos")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSetTypeOfServiceCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPSetTypeOfServiceCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPSetTypeOfServiceCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPSetTypeOfServiceCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSetTypeOfServiceCommand *pp = (UDPSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPSetTypeOfServiceCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetTypeOfServiceCommand *pp = (UDPSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSetTypeOfServiceCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetTypeOfServiceCommand *pp = (UDPSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTos());
        default: return "";
    }
}

bool UDPSetTypeOfServiceCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSetTypeOfServiceCommand *pp = (UDPSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setTos(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPSetTypeOfServiceCommandDescriptor::getFieldStructName(int field) const
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

void *UDPSetTypeOfServiceCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSetTypeOfServiceCommand *pp = (UDPSetTypeOfServiceCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPSetBroadcastCommand)

UDPSetBroadcastCommand::UDPSetBroadcastCommand() : ::inet::UDPSetOptionCommand()
{
    this->broadcast = false;
}

UDPSetBroadcastCommand::UDPSetBroadcastCommand(const UDPSetBroadcastCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    copy(other);
}

UDPSetBroadcastCommand::~UDPSetBroadcastCommand()
{
}

UDPSetBroadcastCommand& UDPSetBroadcastCommand::operator=(const UDPSetBroadcastCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPSetBroadcastCommand::copy(const UDPSetBroadcastCommand& other)
{
    this->broadcast = other.broadcast;
}

void UDPSetBroadcastCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->broadcast);
}

void UDPSetBroadcastCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->broadcast);
}

bool UDPSetBroadcastCommand::getBroadcast() const
{
    return this->broadcast;
}

void UDPSetBroadcastCommand::setBroadcast(bool broadcast)
{
    this->broadcast = broadcast;
}

class UDPSetBroadcastCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSetBroadcastCommandDescriptor();
    virtual ~UDPSetBroadcastCommandDescriptor();

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

Register_ClassDescriptor(UDPSetBroadcastCommandDescriptor)

UDPSetBroadcastCommandDescriptor::UDPSetBroadcastCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSetBroadcastCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPSetBroadcastCommandDescriptor::~UDPSetBroadcastCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSetBroadcastCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSetBroadcastCommand *>(obj)!=nullptr;
}

const char **UDPSetBroadcastCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSetBroadcastCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSetBroadcastCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UDPSetBroadcastCommandDescriptor::getFieldTypeFlags(int field) const
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

const char *UDPSetBroadcastCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "broadcast",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UDPSetBroadcastCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "broadcast")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSetBroadcastCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPSetBroadcastCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPSetBroadcastCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPSetBroadcastCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSetBroadcastCommand *pp = (UDPSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPSetBroadcastCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetBroadcastCommand *pp = (UDPSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSetBroadcastCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetBroadcastCommand *pp = (UDPSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getBroadcast());
        default: return "";
    }
}

bool UDPSetBroadcastCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSetBroadcastCommand *pp = (UDPSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setBroadcast(string2bool(value)); return true;
        default: return false;
    }
}

const char *UDPSetBroadcastCommandDescriptor::getFieldStructName(int field) const
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

void *UDPSetBroadcastCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSetBroadcastCommand *pp = (UDPSetBroadcastCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPSetMulticastInterfaceCommand)

UDPSetMulticastInterfaceCommand::UDPSetMulticastInterfaceCommand() : ::inet::UDPSetOptionCommand()
{
    this->interfaceId = 0;
}

UDPSetMulticastInterfaceCommand::UDPSetMulticastInterfaceCommand(const UDPSetMulticastInterfaceCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    copy(other);
}

UDPSetMulticastInterfaceCommand::~UDPSetMulticastInterfaceCommand()
{
}

UDPSetMulticastInterfaceCommand& UDPSetMulticastInterfaceCommand::operator=(const UDPSetMulticastInterfaceCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPSetMulticastInterfaceCommand::copy(const UDPSetMulticastInterfaceCommand& other)
{
    this->interfaceId = other.interfaceId;
}

void UDPSetMulticastInterfaceCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
}

void UDPSetMulticastInterfaceCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
}

int UDPSetMulticastInterfaceCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UDPSetMulticastInterfaceCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

class UDPSetMulticastInterfaceCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSetMulticastInterfaceCommandDescriptor();
    virtual ~UDPSetMulticastInterfaceCommandDescriptor();

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

Register_ClassDescriptor(UDPSetMulticastInterfaceCommandDescriptor)

UDPSetMulticastInterfaceCommandDescriptor::UDPSetMulticastInterfaceCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSetMulticastInterfaceCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPSetMulticastInterfaceCommandDescriptor::~UDPSetMulticastInterfaceCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSetMulticastInterfaceCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSetMulticastInterfaceCommand *>(obj)!=nullptr;
}

const char **UDPSetMulticastInterfaceCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSetMulticastInterfaceCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSetMulticastInterfaceCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UDPSetMulticastInterfaceCommandDescriptor::getFieldTypeFlags(int field) const
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

const char *UDPSetMulticastInterfaceCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UDPSetMulticastInterfaceCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSetMulticastInterfaceCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPSetMulticastInterfaceCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPSetMulticastInterfaceCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPSetMulticastInterfaceCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastInterfaceCommand *pp = (UDPSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPSetMulticastInterfaceCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastInterfaceCommand *pp = (UDPSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSetMulticastInterfaceCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastInterfaceCommand *pp = (UDPSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInterfaceId());
        default: return "";
    }
}

bool UDPSetMulticastInterfaceCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastInterfaceCommand *pp = (UDPSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPSetMulticastInterfaceCommandDescriptor::getFieldStructName(int field) const
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

void *UDPSetMulticastInterfaceCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastInterfaceCommand *pp = (UDPSetMulticastInterfaceCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPSetMulticastLoopCommand)

UDPSetMulticastLoopCommand::UDPSetMulticastLoopCommand() : ::inet::UDPSetOptionCommand()
{
    this->loop = false;
}

UDPSetMulticastLoopCommand::UDPSetMulticastLoopCommand(const UDPSetMulticastLoopCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    copy(other);
}

UDPSetMulticastLoopCommand::~UDPSetMulticastLoopCommand()
{
}

UDPSetMulticastLoopCommand& UDPSetMulticastLoopCommand::operator=(const UDPSetMulticastLoopCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPSetMulticastLoopCommand::copy(const UDPSetMulticastLoopCommand& other)
{
    this->loop = other.loop;
}

void UDPSetMulticastLoopCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->loop);
}

void UDPSetMulticastLoopCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->loop);
}

bool UDPSetMulticastLoopCommand::getLoop() const
{
    return this->loop;
}

void UDPSetMulticastLoopCommand::setLoop(bool loop)
{
    this->loop = loop;
}

class UDPSetMulticastLoopCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSetMulticastLoopCommandDescriptor();
    virtual ~UDPSetMulticastLoopCommandDescriptor();

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

Register_ClassDescriptor(UDPSetMulticastLoopCommandDescriptor)

UDPSetMulticastLoopCommandDescriptor::UDPSetMulticastLoopCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSetMulticastLoopCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPSetMulticastLoopCommandDescriptor::~UDPSetMulticastLoopCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSetMulticastLoopCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSetMulticastLoopCommand *>(obj)!=nullptr;
}

const char **UDPSetMulticastLoopCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSetMulticastLoopCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSetMulticastLoopCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UDPSetMulticastLoopCommandDescriptor::getFieldTypeFlags(int field) const
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

const char *UDPSetMulticastLoopCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "loop",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UDPSetMulticastLoopCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "loop")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSetMulticastLoopCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPSetMulticastLoopCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPSetMulticastLoopCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPSetMulticastLoopCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastLoopCommand *pp = (UDPSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPSetMulticastLoopCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastLoopCommand *pp = (UDPSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSetMulticastLoopCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastLoopCommand *pp = (UDPSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getLoop());
        default: return "";
    }
}

bool UDPSetMulticastLoopCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastLoopCommand *pp = (UDPSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setLoop(string2bool(value)); return true;
        default: return false;
    }
}

const char *UDPSetMulticastLoopCommandDescriptor::getFieldStructName(int field) const
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

void *UDPSetMulticastLoopCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastLoopCommand *pp = (UDPSetMulticastLoopCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPSetReuseAddressCommand)

UDPSetReuseAddressCommand::UDPSetReuseAddressCommand() : ::inet::UDPSetOptionCommand()
{
    this->reuseAddress = false;
}

UDPSetReuseAddressCommand::UDPSetReuseAddressCommand(const UDPSetReuseAddressCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    copy(other);
}

UDPSetReuseAddressCommand::~UDPSetReuseAddressCommand()
{
}

UDPSetReuseAddressCommand& UDPSetReuseAddressCommand::operator=(const UDPSetReuseAddressCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPSetReuseAddressCommand::copy(const UDPSetReuseAddressCommand& other)
{
    this->reuseAddress = other.reuseAddress;
}

void UDPSetReuseAddressCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->reuseAddress);
}

void UDPSetReuseAddressCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->reuseAddress);
}

bool UDPSetReuseAddressCommand::getReuseAddress() const
{
    return this->reuseAddress;
}

void UDPSetReuseAddressCommand::setReuseAddress(bool reuseAddress)
{
    this->reuseAddress = reuseAddress;
}

class UDPSetReuseAddressCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSetReuseAddressCommandDescriptor();
    virtual ~UDPSetReuseAddressCommandDescriptor();

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

Register_ClassDescriptor(UDPSetReuseAddressCommandDescriptor)

UDPSetReuseAddressCommandDescriptor::UDPSetReuseAddressCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSetReuseAddressCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPSetReuseAddressCommandDescriptor::~UDPSetReuseAddressCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSetReuseAddressCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSetReuseAddressCommand *>(obj)!=nullptr;
}

const char **UDPSetReuseAddressCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSetReuseAddressCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSetReuseAddressCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UDPSetReuseAddressCommandDescriptor::getFieldTypeFlags(int field) const
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

const char *UDPSetReuseAddressCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reuseAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UDPSetReuseAddressCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "reuseAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSetReuseAddressCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPSetReuseAddressCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPSetReuseAddressCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPSetReuseAddressCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSetReuseAddressCommand *pp = (UDPSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *UDPSetReuseAddressCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetReuseAddressCommand *pp = (UDPSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSetReuseAddressCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetReuseAddressCommand *pp = (UDPSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getReuseAddress());
        default: return "";
    }
}

bool UDPSetReuseAddressCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSetReuseAddressCommand *pp = (UDPSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setReuseAddress(string2bool(value)); return true;
        default: return false;
    }
}

const char *UDPSetReuseAddressCommandDescriptor::getFieldStructName(int field) const
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

void *UDPSetReuseAddressCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSetReuseAddressCommand *pp = (UDPSetReuseAddressCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(UDPJoinMulticastGroupsCommand)

UDPJoinMulticastGroupsCommand::UDPJoinMulticastGroupsCommand() : ::inet::UDPSetOptionCommand()
{
    multicastAddr_arraysize = 0;
    this->multicastAddr = 0;
    interfaceId_arraysize = 0;
    this->interfaceId = 0;
}

UDPJoinMulticastGroupsCommand::UDPJoinMulticastGroupsCommand(const UDPJoinMulticastGroupsCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    multicastAddr_arraysize = 0;
    this->multicastAddr = 0;
    interfaceId_arraysize = 0;
    this->interfaceId = 0;
    copy(other);
}

UDPJoinMulticastGroupsCommand::~UDPJoinMulticastGroupsCommand()
{
    delete [] this->multicastAddr;
    delete [] this->interfaceId;
}

UDPJoinMulticastGroupsCommand& UDPJoinMulticastGroupsCommand::operator=(const UDPJoinMulticastGroupsCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPJoinMulticastGroupsCommand::copy(const UDPJoinMulticastGroupsCommand& other)
{
    delete [] this->multicastAddr;
    this->multicastAddr = (other.multicastAddr_arraysize==0) ? nullptr : new L3Address[other.multicastAddr_arraysize];
    multicastAddr_arraysize = other.multicastAddr_arraysize;
    for (unsigned int i=0; i<multicastAddr_arraysize; i++)
        this->multicastAddr[i] = other.multicastAddr[i];
    delete [] this->interfaceId;
    this->interfaceId = (other.interfaceId_arraysize==0) ? nullptr : new int[other.interfaceId_arraysize];
    interfaceId_arraysize = other.interfaceId_arraysize;
    for (unsigned int i=0; i<interfaceId_arraysize; i++)
        this->interfaceId[i] = other.interfaceId[i];
}

void UDPJoinMulticastGroupsCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    b->pack(multicastAddr_arraysize);
    doParsimArrayPacking(b,this->multicastAddr,multicastAddr_arraysize);
    b->pack(interfaceId_arraysize);
    doParsimArrayPacking(b,this->interfaceId,interfaceId_arraysize);
}

void UDPJoinMulticastGroupsCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    delete [] this->multicastAddr;
    b->unpack(multicastAddr_arraysize);
    if (multicastAddr_arraysize==0) {
        this->multicastAddr = 0;
    } else {
        this->multicastAddr = new L3Address[multicastAddr_arraysize];
        doParsimArrayUnpacking(b,this->multicastAddr,multicastAddr_arraysize);
    }
    delete [] this->interfaceId;
    b->unpack(interfaceId_arraysize);
    if (interfaceId_arraysize==0) {
        this->interfaceId = 0;
    } else {
        this->interfaceId = new int[interfaceId_arraysize];
        doParsimArrayUnpacking(b,this->interfaceId,interfaceId_arraysize);
    }
}

void UDPJoinMulticastGroupsCommand::setMulticastAddrArraySize(unsigned int size)
{
    L3Address *multicastAddr2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = multicastAddr_arraysize < size ? multicastAddr_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        multicastAddr2[i] = this->multicastAddr[i];
    multicastAddr_arraysize = size;
    delete [] this->multicastAddr;
    this->multicastAddr = multicastAddr2;
}

unsigned int UDPJoinMulticastGroupsCommand::getMulticastAddrArraySize() const
{
    return multicastAddr_arraysize;
}

L3Address& UDPJoinMulticastGroupsCommand::getMulticastAddr(unsigned int k)
{
    if (k>=multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", multicastAddr_arraysize, k);
    return this->multicastAddr[k];
}

void UDPJoinMulticastGroupsCommand::setMulticastAddr(unsigned int k, const L3Address& multicastAddr)
{
    if (k>=multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", multicastAddr_arraysize, k);
    this->multicastAddr[k] = multicastAddr;
}

void UDPJoinMulticastGroupsCommand::setInterfaceIdArraySize(unsigned int size)
{
    int *interfaceId2 = (size==0) ? nullptr : new int[size];
    unsigned int sz = interfaceId_arraysize < size ? interfaceId_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        interfaceId2[i] = this->interfaceId[i];
    for (unsigned int i=sz; i<size; i++)
        interfaceId2[i] = 0;
    interfaceId_arraysize = size;
    delete [] this->interfaceId;
    this->interfaceId = interfaceId2;
}

unsigned int UDPJoinMulticastGroupsCommand::getInterfaceIdArraySize() const
{
    return interfaceId_arraysize;
}

int UDPJoinMulticastGroupsCommand::getInterfaceId(unsigned int k) const
{
    if (k>=interfaceId_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", interfaceId_arraysize, k);
    return this->interfaceId[k];
}

void UDPJoinMulticastGroupsCommand::setInterfaceId(unsigned int k, int interfaceId)
{
    if (k>=interfaceId_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", interfaceId_arraysize, k);
    this->interfaceId[k] = interfaceId;
}

class UDPJoinMulticastGroupsCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPJoinMulticastGroupsCommandDescriptor();
    virtual ~UDPJoinMulticastGroupsCommandDescriptor();

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

Register_ClassDescriptor(UDPJoinMulticastGroupsCommandDescriptor)

UDPJoinMulticastGroupsCommandDescriptor::UDPJoinMulticastGroupsCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPJoinMulticastGroupsCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPJoinMulticastGroupsCommandDescriptor::~UDPJoinMulticastGroupsCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPJoinMulticastGroupsCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPJoinMulticastGroupsCommand *>(obj)!=nullptr;
}

const char **UDPJoinMulticastGroupsCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPJoinMulticastGroupsCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPJoinMulticastGroupsCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int UDPJoinMulticastGroupsCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *UDPJoinMulticastGroupsCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "multicastAddr",
        "interfaceId",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int UDPJoinMulticastGroupsCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastAddr")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPJoinMulticastGroupsCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPJoinMulticastGroupsCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPJoinMulticastGroupsCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPJoinMulticastGroupsCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastGroupsCommand *pp = (UDPJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case 0: return pp->getMulticastAddrArraySize();
        case 1: return pp->getInterfaceIdArraySize();
        default: return 0;
    }
}

const char *UDPJoinMulticastGroupsCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastGroupsCommand *pp = (UDPJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPJoinMulticastGroupsCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastGroupsCommand *pp = (UDPJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getMulticastAddr(i); return out.str();}
        case 1: return long2string(pp->getInterfaceId(i));
        default: return "";
    }
}

bool UDPJoinMulticastGroupsCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastGroupsCommand *pp = (UDPJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case 1: pp->setInterfaceId(i,string2long(value)); return true;
        default: return false;
    }
}

const char *UDPJoinMulticastGroupsCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPJoinMulticastGroupsCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastGroupsCommand *pp = (UDPJoinMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getMulticastAddr(i)); break;
        default: return nullptr;
    }
}

Register_Class(UDPLeaveMulticastGroupsCommand)

UDPLeaveMulticastGroupsCommand::UDPLeaveMulticastGroupsCommand() : ::inet::UDPSetOptionCommand()
{
    multicastAddr_arraysize = 0;
    this->multicastAddr = 0;
}

UDPLeaveMulticastGroupsCommand::UDPLeaveMulticastGroupsCommand(const UDPLeaveMulticastGroupsCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    multicastAddr_arraysize = 0;
    this->multicastAddr = 0;
    copy(other);
}

UDPLeaveMulticastGroupsCommand::~UDPLeaveMulticastGroupsCommand()
{
    delete [] this->multicastAddr;
}

UDPLeaveMulticastGroupsCommand& UDPLeaveMulticastGroupsCommand::operator=(const UDPLeaveMulticastGroupsCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPLeaveMulticastGroupsCommand::copy(const UDPLeaveMulticastGroupsCommand& other)
{
    delete [] this->multicastAddr;
    this->multicastAddr = (other.multicastAddr_arraysize==0) ? nullptr : new L3Address[other.multicastAddr_arraysize];
    multicastAddr_arraysize = other.multicastAddr_arraysize;
    for (unsigned int i=0; i<multicastAddr_arraysize; i++)
        this->multicastAddr[i] = other.multicastAddr[i];
}

void UDPLeaveMulticastGroupsCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    b->pack(multicastAddr_arraysize);
    doParsimArrayPacking(b,this->multicastAddr,multicastAddr_arraysize);
}

void UDPLeaveMulticastGroupsCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    delete [] this->multicastAddr;
    b->unpack(multicastAddr_arraysize);
    if (multicastAddr_arraysize==0) {
        this->multicastAddr = 0;
    } else {
        this->multicastAddr = new L3Address[multicastAddr_arraysize];
        doParsimArrayUnpacking(b,this->multicastAddr,multicastAddr_arraysize);
    }
}

void UDPLeaveMulticastGroupsCommand::setMulticastAddrArraySize(unsigned int size)
{
    L3Address *multicastAddr2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = multicastAddr_arraysize < size ? multicastAddr_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        multicastAddr2[i] = this->multicastAddr[i];
    multicastAddr_arraysize = size;
    delete [] this->multicastAddr;
    this->multicastAddr = multicastAddr2;
}

unsigned int UDPLeaveMulticastGroupsCommand::getMulticastAddrArraySize() const
{
    return multicastAddr_arraysize;
}

L3Address& UDPLeaveMulticastGroupsCommand::getMulticastAddr(unsigned int k)
{
    if (k>=multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", multicastAddr_arraysize, k);
    return this->multicastAddr[k];
}

void UDPLeaveMulticastGroupsCommand::setMulticastAddr(unsigned int k, const L3Address& multicastAddr)
{
    if (k>=multicastAddr_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", multicastAddr_arraysize, k);
    this->multicastAddr[k] = multicastAddr;
}

class UDPLeaveMulticastGroupsCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPLeaveMulticastGroupsCommandDescriptor();
    virtual ~UDPLeaveMulticastGroupsCommandDescriptor();

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

Register_ClassDescriptor(UDPLeaveMulticastGroupsCommandDescriptor)

UDPLeaveMulticastGroupsCommandDescriptor::UDPLeaveMulticastGroupsCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPLeaveMulticastGroupsCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPLeaveMulticastGroupsCommandDescriptor::~UDPLeaveMulticastGroupsCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPLeaveMulticastGroupsCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPLeaveMulticastGroupsCommand *>(obj)!=nullptr;
}

const char **UDPLeaveMulticastGroupsCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPLeaveMulticastGroupsCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPLeaveMulticastGroupsCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int UDPLeaveMulticastGroupsCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *UDPLeaveMulticastGroupsCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "multicastAddr",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int UDPLeaveMulticastGroupsCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastAddr")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPLeaveMulticastGroupsCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPLeaveMulticastGroupsCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPLeaveMulticastGroupsCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPLeaveMulticastGroupsCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastGroupsCommand *pp = (UDPLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case 0: return pp->getMulticastAddrArraySize();
        default: return 0;
    }
}

const char *UDPLeaveMulticastGroupsCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastGroupsCommand *pp = (UDPLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPLeaveMulticastGroupsCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastGroupsCommand *pp = (UDPLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getMulticastAddr(i); return out.str();}
        default: return "";
    }
}

bool UDPLeaveMulticastGroupsCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastGroupsCommand *pp = (UDPLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *UDPLeaveMulticastGroupsCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPLeaveMulticastGroupsCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastGroupsCommand *pp = (UDPLeaveMulticastGroupsCommand *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getMulticastAddr(i)); break;
        default: return nullptr;
    }
}

Register_Class(UDPBlockMulticastSourcesCommand)

UDPBlockMulticastSourcesCommand::UDPBlockMulticastSourcesCommand() : ::inet::UDPSetOptionCommand()
{
    this->interfaceId = 0;
    sourceList_arraysize = 0;
    this->sourceList = 0;
}

UDPBlockMulticastSourcesCommand::UDPBlockMulticastSourcesCommand(const UDPBlockMulticastSourcesCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    sourceList_arraysize = 0;
    this->sourceList = 0;
    copy(other);
}

UDPBlockMulticastSourcesCommand::~UDPBlockMulticastSourcesCommand()
{
    delete [] this->sourceList;
}

UDPBlockMulticastSourcesCommand& UDPBlockMulticastSourcesCommand::operator=(const UDPBlockMulticastSourcesCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPBlockMulticastSourcesCommand::copy(const UDPBlockMulticastSourcesCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (unsigned int i=0; i<sourceList_arraysize; i++)
        this->sourceList[i] = other.sourceList[i];
}

void UDPBlockMulticastSourcesCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UDPBlockMulticastSourcesCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize==0) {
        this->sourceList = 0;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UDPBlockMulticastSourcesCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UDPBlockMulticastSourcesCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

L3Address& UDPBlockMulticastSourcesCommand::getMulticastAddr()
{
    return this->multicastAddr;
}

void UDPBlockMulticastSourcesCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

void UDPBlockMulticastSourcesCommand::setSourceListArraySize(unsigned int size)
{
    L3Address *sourceList2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = sourceList_arraysize < size ? sourceList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList_arraysize = size;
    delete [] this->sourceList;
    this->sourceList = sourceList2;
}

unsigned int UDPBlockMulticastSourcesCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

L3Address& UDPBlockMulticastSourcesCommand::getSourceList(unsigned int k)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    return this->sourceList[k];
}

void UDPBlockMulticastSourcesCommand::setSourceList(unsigned int k, const L3Address& sourceList)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    this->sourceList[k] = sourceList;
}

class UDPBlockMulticastSourcesCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPBlockMulticastSourcesCommandDescriptor();
    virtual ~UDPBlockMulticastSourcesCommandDescriptor();

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

Register_ClassDescriptor(UDPBlockMulticastSourcesCommandDescriptor)

UDPBlockMulticastSourcesCommandDescriptor::UDPBlockMulticastSourcesCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPBlockMulticastSourcesCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPBlockMulticastSourcesCommandDescriptor::~UDPBlockMulticastSourcesCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPBlockMulticastSourcesCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPBlockMulticastSourcesCommand *>(obj)!=nullptr;
}

const char **UDPBlockMulticastSourcesCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPBlockMulticastSourcesCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPBlockMulticastSourcesCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UDPBlockMulticastSourcesCommandDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *UDPBlockMulticastSourcesCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "sourceList",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int UDPBlockMulticastSourcesCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastAddr")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceList")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPBlockMulticastSourcesCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "L3Address",
        "L3Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPBlockMulticastSourcesCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPBlockMulticastSourcesCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPBlockMulticastSourcesCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPBlockMulticastSourcesCommand *pp = (UDPBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 2: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UDPBlockMulticastSourcesCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPBlockMulticastSourcesCommand *pp = (UDPBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPBlockMulticastSourcesCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPBlockMulticastSourcesCommand *pp = (UDPBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInterfaceId());
        case 1: {std::stringstream out; out << pp->getMulticastAddr(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSourceList(i); return out.str();}
        default: return "";
    }
}

bool UDPBlockMulticastSourcesCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPBlockMulticastSourcesCommand *pp = (UDPBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPBlockMulticastSourcesCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPBlockMulticastSourcesCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPBlockMulticastSourcesCommand *pp = (UDPBlockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getMulticastAddr()); break;
        case 2: return (void *)(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

Register_Class(UDPUnblockMulticastSourcesCommand)

UDPUnblockMulticastSourcesCommand::UDPUnblockMulticastSourcesCommand() : ::inet::UDPSetOptionCommand()
{
    this->interfaceId = 0;
    sourceList_arraysize = 0;
    this->sourceList = 0;
}

UDPUnblockMulticastSourcesCommand::UDPUnblockMulticastSourcesCommand(const UDPUnblockMulticastSourcesCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    sourceList_arraysize = 0;
    this->sourceList = 0;
    copy(other);
}

UDPUnblockMulticastSourcesCommand::~UDPUnblockMulticastSourcesCommand()
{
    delete [] this->sourceList;
}

UDPUnblockMulticastSourcesCommand& UDPUnblockMulticastSourcesCommand::operator=(const UDPUnblockMulticastSourcesCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPUnblockMulticastSourcesCommand::copy(const UDPUnblockMulticastSourcesCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (unsigned int i=0; i<sourceList_arraysize; i++)
        this->sourceList[i] = other.sourceList[i];
}

void UDPUnblockMulticastSourcesCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UDPUnblockMulticastSourcesCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize==0) {
        this->sourceList = 0;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UDPUnblockMulticastSourcesCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UDPUnblockMulticastSourcesCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

L3Address& UDPUnblockMulticastSourcesCommand::getMulticastAddr()
{
    return this->multicastAddr;
}

void UDPUnblockMulticastSourcesCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

void UDPUnblockMulticastSourcesCommand::setSourceListArraySize(unsigned int size)
{
    L3Address *sourceList2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = sourceList_arraysize < size ? sourceList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList_arraysize = size;
    delete [] this->sourceList;
    this->sourceList = sourceList2;
}

unsigned int UDPUnblockMulticastSourcesCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

L3Address& UDPUnblockMulticastSourcesCommand::getSourceList(unsigned int k)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    return this->sourceList[k];
}

void UDPUnblockMulticastSourcesCommand::setSourceList(unsigned int k, const L3Address& sourceList)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    this->sourceList[k] = sourceList;
}

class UDPUnblockMulticastSourcesCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPUnblockMulticastSourcesCommandDescriptor();
    virtual ~UDPUnblockMulticastSourcesCommandDescriptor();

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

Register_ClassDescriptor(UDPUnblockMulticastSourcesCommandDescriptor)

UDPUnblockMulticastSourcesCommandDescriptor::UDPUnblockMulticastSourcesCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPUnblockMulticastSourcesCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPUnblockMulticastSourcesCommandDescriptor::~UDPUnblockMulticastSourcesCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPUnblockMulticastSourcesCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPUnblockMulticastSourcesCommand *>(obj)!=nullptr;
}

const char **UDPUnblockMulticastSourcesCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPUnblockMulticastSourcesCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPUnblockMulticastSourcesCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UDPUnblockMulticastSourcesCommandDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *UDPUnblockMulticastSourcesCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "sourceList",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int UDPUnblockMulticastSourcesCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastAddr")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceList")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPUnblockMulticastSourcesCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "L3Address",
        "L3Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPUnblockMulticastSourcesCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPUnblockMulticastSourcesCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPUnblockMulticastSourcesCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPUnblockMulticastSourcesCommand *pp = (UDPUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 2: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UDPUnblockMulticastSourcesCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPUnblockMulticastSourcesCommand *pp = (UDPUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPUnblockMulticastSourcesCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPUnblockMulticastSourcesCommand *pp = (UDPUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInterfaceId());
        case 1: {std::stringstream out; out << pp->getMulticastAddr(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSourceList(i); return out.str();}
        default: return "";
    }
}

bool UDPUnblockMulticastSourcesCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPUnblockMulticastSourcesCommand *pp = (UDPUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPUnblockMulticastSourcesCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPUnblockMulticastSourcesCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPUnblockMulticastSourcesCommand *pp = (UDPUnblockMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getMulticastAddr()); break;
        case 2: return (void *)(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

Register_Class(UDPJoinMulticastSourcesCommand)

UDPJoinMulticastSourcesCommand::UDPJoinMulticastSourcesCommand() : ::inet::UDPSetOptionCommand()
{
    this->interfaceId = 0;
    sourceList_arraysize = 0;
    this->sourceList = 0;
}

UDPJoinMulticastSourcesCommand::UDPJoinMulticastSourcesCommand(const UDPJoinMulticastSourcesCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    sourceList_arraysize = 0;
    this->sourceList = 0;
    copy(other);
}

UDPJoinMulticastSourcesCommand::~UDPJoinMulticastSourcesCommand()
{
    delete [] this->sourceList;
}

UDPJoinMulticastSourcesCommand& UDPJoinMulticastSourcesCommand::operator=(const UDPJoinMulticastSourcesCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPJoinMulticastSourcesCommand::copy(const UDPJoinMulticastSourcesCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (unsigned int i=0; i<sourceList_arraysize; i++)
        this->sourceList[i] = other.sourceList[i];
}

void UDPJoinMulticastSourcesCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UDPJoinMulticastSourcesCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize==0) {
        this->sourceList = 0;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UDPJoinMulticastSourcesCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UDPJoinMulticastSourcesCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

L3Address& UDPJoinMulticastSourcesCommand::getMulticastAddr()
{
    return this->multicastAddr;
}

void UDPJoinMulticastSourcesCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

void UDPJoinMulticastSourcesCommand::setSourceListArraySize(unsigned int size)
{
    L3Address *sourceList2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = sourceList_arraysize < size ? sourceList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList_arraysize = size;
    delete [] this->sourceList;
    this->sourceList = sourceList2;
}

unsigned int UDPJoinMulticastSourcesCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

L3Address& UDPJoinMulticastSourcesCommand::getSourceList(unsigned int k)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    return this->sourceList[k];
}

void UDPJoinMulticastSourcesCommand::setSourceList(unsigned int k, const L3Address& sourceList)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    this->sourceList[k] = sourceList;
}

class UDPJoinMulticastSourcesCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPJoinMulticastSourcesCommandDescriptor();
    virtual ~UDPJoinMulticastSourcesCommandDescriptor();

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

Register_ClassDescriptor(UDPJoinMulticastSourcesCommandDescriptor)

UDPJoinMulticastSourcesCommandDescriptor::UDPJoinMulticastSourcesCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPJoinMulticastSourcesCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPJoinMulticastSourcesCommandDescriptor::~UDPJoinMulticastSourcesCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPJoinMulticastSourcesCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPJoinMulticastSourcesCommand *>(obj)!=nullptr;
}

const char **UDPJoinMulticastSourcesCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPJoinMulticastSourcesCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPJoinMulticastSourcesCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UDPJoinMulticastSourcesCommandDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *UDPJoinMulticastSourcesCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "sourceList",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int UDPJoinMulticastSourcesCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastAddr")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceList")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPJoinMulticastSourcesCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "L3Address",
        "L3Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPJoinMulticastSourcesCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPJoinMulticastSourcesCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPJoinMulticastSourcesCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastSourcesCommand *pp = (UDPJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 2: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UDPJoinMulticastSourcesCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastSourcesCommand *pp = (UDPJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPJoinMulticastSourcesCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastSourcesCommand *pp = (UDPJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInterfaceId());
        case 1: {std::stringstream out; out << pp->getMulticastAddr(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSourceList(i); return out.str();}
        default: return "";
    }
}

bool UDPJoinMulticastSourcesCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastSourcesCommand *pp = (UDPJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPJoinMulticastSourcesCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPJoinMulticastSourcesCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPJoinMulticastSourcesCommand *pp = (UDPJoinMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getMulticastAddr()); break;
        case 2: return (void *)(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

Register_Class(UDPLeaveMulticastSourcesCommand)

UDPLeaveMulticastSourcesCommand::UDPLeaveMulticastSourcesCommand() : ::inet::UDPSetOptionCommand()
{
    this->interfaceId = 0;
    sourceList_arraysize = 0;
    this->sourceList = 0;
}

UDPLeaveMulticastSourcesCommand::UDPLeaveMulticastSourcesCommand(const UDPLeaveMulticastSourcesCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    sourceList_arraysize = 0;
    this->sourceList = 0;
    copy(other);
}

UDPLeaveMulticastSourcesCommand::~UDPLeaveMulticastSourcesCommand()
{
    delete [] this->sourceList;
}

UDPLeaveMulticastSourcesCommand& UDPLeaveMulticastSourcesCommand::operator=(const UDPLeaveMulticastSourcesCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPLeaveMulticastSourcesCommand::copy(const UDPLeaveMulticastSourcesCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (unsigned int i=0; i<sourceList_arraysize; i++)
        this->sourceList[i] = other.sourceList[i];
}

void UDPLeaveMulticastSourcesCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UDPLeaveMulticastSourcesCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize==0) {
        this->sourceList = 0;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UDPLeaveMulticastSourcesCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UDPLeaveMulticastSourcesCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

L3Address& UDPLeaveMulticastSourcesCommand::getMulticastAddr()
{
    return this->multicastAddr;
}

void UDPLeaveMulticastSourcesCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

void UDPLeaveMulticastSourcesCommand::setSourceListArraySize(unsigned int size)
{
    L3Address *sourceList2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = sourceList_arraysize < size ? sourceList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList_arraysize = size;
    delete [] this->sourceList;
    this->sourceList = sourceList2;
}

unsigned int UDPLeaveMulticastSourcesCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

L3Address& UDPLeaveMulticastSourcesCommand::getSourceList(unsigned int k)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    return this->sourceList[k];
}

void UDPLeaveMulticastSourcesCommand::setSourceList(unsigned int k, const L3Address& sourceList)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    this->sourceList[k] = sourceList;
}

class UDPLeaveMulticastSourcesCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPLeaveMulticastSourcesCommandDescriptor();
    virtual ~UDPLeaveMulticastSourcesCommandDescriptor();

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

Register_ClassDescriptor(UDPLeaveMulticastSourcesCommandDescriptor)

UDPLeaveMulticastSourcesCommandDescriptor::UDPLeaveMulticastSourcesCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPLeaveMulticastSourcesCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPLeaveMulticastSourcesCommandDescriptor::~UDPLeaveMulticastSourcesCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPLeaveMulticastSourcesCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPLeaveMulticastSourcesCommand *>(obj)!=nullptr;
}

const char **UDPLeaveMulticastSourcesCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPLeaveMulticastSourcesCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPLeaveMulticastSourcesCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int UDPLeaveMulticastSourcesCommandDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *UDPLeaveMulticastSourcesCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "sourceList",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int UDPLeaveMulticastSourcesCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastAddr")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceList")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPLeaveMulticastSourcesCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "L3Address",
        "L3Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPLeaveMulticastSourcesCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *UDPLeaveMulticastSourcesCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int UDPLeaveMulticastSourcesCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastSourcesCommand *pp = (UDPLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 2: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UDPLeaveMulticastSourcesCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastSourcesCommand *pp = (UDPLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPLeaveMulticastSourcesCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastSourcesCommand *pp = (UDPLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInterfaceId());
        case 1: {std::stringstream out; out << pp->getMulticastAddr(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSourceList(i); return out.str();}
        default: return "";
    }
}

bool UDPLeaveMulticastSourcesCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastSourcesCommand *pp = (UDPLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceId(string2long(value)); return true;
        default: return false;
    }
}

const char *UDPLeaveMulticastSourcesCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPLeaveMulticastSourcesCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPLeaveMulticastSourcesCommand *pp = (UDPLeaveMulticastSourcesCommand *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getMulticastAddr()); break;
        case 2: return (void *)(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::UDPSourceFilterMode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::UDPSourceFilterMode"));
    e->insert(UDP_INCLUDE_MCAST_SOURCES, "UDP_INCLUDE_MCAST_SOURCES");
    e->insert(UDP_EXCLUDE_MCAST_SOURCES, "UDP_EXCLUDE_MCAST_SOURCES");
)

Register_Class(UDPSetMulticastSourceFilterCommand)

UDPSetMulticastSourceFilterCommand::UDPSetMulticastSourceFilterCommand() : ::inet::UDPSetOptionCommand()
{
    this->interfaceId = 0;
    this->filterMode = 0;
    sourceList_arraysize = 0;
    this->sourceList = 0;
}

UDPSetMulticastSourceFilterCommand::UDPSetMulticastSourceFilterCommand(const UDPSetMulticastSourceFilterCommand& other) : ::inet::UDPSetOptionCommand(other)
{
    sourceList_arraysize = 0;
    this->sourceList = 0;
    copy(other);
}

UDPSetMulticastSourceFilterCommand::~UDPSetMulticastSourceFilterCommand()
{
    delete [] this->sourceList;
}

UDPSetMulticastSourceFilterCommand& UDPSetMulticastSourceFilterCommand::operator=(const UDPSetMulticastSourceFilterCommand& other)
{
    if (this==&other) return *this;
    ::inet::UDPSetOptionCommand::operator=(other);
    copy(other);
    return *this;
}

void UDPSetMulticastSourceFilterCommand::copy(const UDPSetMulticastSourceFilterCommand& other)
{
    this->interfaceId = other.interfaceId;
    this->multicastAddr = other.multicastAddr;
    this->filterMode = other.filterMode;
    delete [] this->sourceList;
    this->sourceList = (other.sourceList_arraysize==0) ? nullptr : new L3Address[other.sourceList_arraysize];
    sourceList_arraysize = other.sourceList_arraysize;
    for (unsigned int i=0; i<sourceList_arraysize; i++)
        this->sourceList[i] = other.sourceList[i];
}

void UDPSetMulticastSourceFilterCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::UDPSetOptionCommand::parsimPack(b);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->multicastAddr);
    doParsimPacking(b,this->filterMode);
    b->pack(sourceList_arraysize);
    doParsimArrayPacking(b,this->sourceList,sourceList_arraysize);
}

void UDPSetMulticastSourceFilterCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::UDPSetOptionCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->multicastAddr);
    doParsimUnpacking(b,this->filterMode);
    delete [] this->sourceList;
    b->unpack(sourceList_arraysize);
    if (sourceList_arraysize==0) {
        this->sourceList = 0;
    } else {
        this->sourceList = new L3Address[sourceList_arraysize];
        doParsimArrayUnpacking(b,this->sourceList,sourceList_arraysize);
    }
}

int UDPSetMulticastSourceFilterCommand::getInterfaceId() const
{
    return this->interfaceId;
}

void UDPSetMulticastSourceFilterCommand::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

L3Address& UDPSetMulticastSourceFilterCommand::getMulticastAddr()
{
    return this->multicastAddr;
}

void UDPSetMulticastSourceFilterCommand::setMulticastAddr(const L3Address& multicastAddr)
{
    this->multicastAddr = multicastAddr;
}

int UDPSetMulticastSourceFilterCommand::getFilterMode() const
{
    return this->filterMode;
}

void UDPSetMulticastSourceFilterCommand::setFilterMode(int filterMode)
{
    this->filterMode = filterMode;
}

void UDPSetMulticastSourceFilterCommand::setSourceListArraySize(unsigned int size)
{
    L3Address *sourceList2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = sourceList_arraysize < size ? sourceList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sourceList2[i] = this->sourceList[i];
    sourceList_arraysize = size;
    delete [] this->sourceList;
    this->sourceList = sourceList2;
}

unsigned int UDPSetMulticastSourceFilterCommand::getSourceListArraySize() const
{
    return sourceList_arraysize;
}

L3Address& UDPSetMulticastSourceFilterCommand::getSourceList(unsigned int k)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    return this->sourceList[k];
}

void UDPSetMulticastSourceFilterCommand::setSourceList(unsigned int k, const L3Address& sourceList)
{
    if (k>=sourceList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sourceList_arraysize, k);
    this->sourceList[k] = sourceList;
}

class UDPSetMulticastSourceFilterCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    UDPSetMulticastSourceFilterCommandDescriptor();
    virtual ~UDPSetMulticastSourceFilterCommandDescriptor();

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

Register_ClassDescriptor(UDPSetMulticastSourceFilterCommandDescriptor)

UDPSetMulticastSourceFilterCommandDescriptor::UDPSetMulticastSourceFilterCommandDescriptor() : omnetpp::cClassDescriptor("inet::UDPSetMulticastSourceFilterCommand", "inet::UDPSetOptionCommand")
{
    propertynames = nullptr;
}

UDPSetMulticastSourceFilterCommandDescriptor::~UDPSetMulticastSourceFilterCommandDescriptor()
{
    delete[] propertynames;
}

bool UDPSetMulticastSourceFilterCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<UDPSetMulticastSourceFilterCommand *>(obj)!=nullptr;
}

const char **UDPSetMulticastSourceFilterCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *UDPSetMulticastSourceFilterCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int UDPSetMulticastSourceFilterCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int UDPSetMulticastSourceFilterCommandDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *UDPSetMulticastSourceFilterCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceId",
        "multicastAddr",
        "filterMode",
        "sourceList",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int UDPSetMulticastSourceFilterCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multicastAddr")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "filterMode")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceList")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *UDPSetMulticastSourceFilterCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "L3Address",
        "int",
        "L3Address",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **UDPSetMulticastSourceFilterCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *UDPSetMulticastSourceFilterCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "inet::UDPSourceFilterMode";
            return nullptr;
        default: return nullptr;
    }
}

int UDPSetMulticastSourceFilterCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastSourceFilterCommand *pp = (UDPSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        case 3: return pp->getSourceListArraySize();
        default: return 0;
    }
}

const char *UDPSetMulticastSourceFilterCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastSourceFilterCommand *pp = (UDPSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string UDPSetMulticastSourceFilterCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastSourceFilterCommand *pp = (UDPSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getInterfaceId());
        case 1: {std::stringstream out; out << pp->getMulticastAddr(); return out.str();}
        case 2: return enum2string(pp->getFilterMode(), "inet::UDPSourceFilterMode");
        case 3: {std::stringstream out; out << pp->getSourceList(i); return out.str();}
        default: return "";
    }
}

bool UDPSetMulticastSourceFilterCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastSourceFilterCommand *pp = (UDPSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceId(string2long(value)); return true;
        case 2: pp->setFilterMode((inet::UDPSourceFilterMode)string2enum(value, "inet::UDPSourceFilterMode")); return true;
        default: return false;
    }
}

const char *UDPSetMulticastSourceFilterCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        case 3: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *UDPSetMulticastSourceFilterCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    UDPSetMulticastSourceFilterCommand *pp = (UDPSetMulticastSourceFilterCommand *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getMulticastAddr()); break;
        case 3: return (void *)(&pp->getSourceList(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

