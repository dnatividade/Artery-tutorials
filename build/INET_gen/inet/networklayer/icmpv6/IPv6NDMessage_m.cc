//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/icmpv6/IPv6NDMessage.msg.
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
#include "IPv6NDMessage_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IPv6NDOptionLength");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IPv6NDOptionLength"));
    e->insert(IPv6ND_LINK_LAYER_ADDRESS_OPTION_LENGTH, "IPv6ND_LINK_LAYER_ADDRESS_OPTION_LENGTH");
    e->insert(IPv6ND_PREFIX_INFORMATION_OPTION_LENGTH, "IPv6ND_PREFIX_INFORMATION_OPTION_LENGTH");
    e->insert(IPv6ND_REDIRECTED_HEADER_OPTION_LENGTH, "IPv6ND_REDIRECTED_HEADER_OPTION_LENGTH");
    e->insert(IPv6ND_MTU_OPTION_LENGTH, "IPv6ND_MTU_OPTION_LENGTH");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IPv6NDOptionTypes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IPv6NDOptionTypes"));
    e->insert(IPv6ND_SOURCE_LINK_LAYER_ADDR_OPTION, "IPv6ND_SOURCE_LINK_LAYER_ADDR_OPTION");
    e->insert(IPv6ND_TARGET_LINK_LAYER_ADDR_OPTION, "IPv6ND_TARGET_LINK_LAYER_ADDR_OPTION");
)

Register_Class(IPv6NDPrefixInformation)

IPv6NDPrefixInformation::IPv6NDPrefixInformation() : ::omnetpp::cObject()
{
    this->prefixLength = 0;
    this->onlinkFlag = false;
    this->autoAddressConfFlag = false;
    this->routerAddressFlag = false;
    this->validLifetime = 0;
    this->preferredLifetime = 0;
}

IPv6NDPrefixInformation::IPv6NDPrefixInformation(const IPv6NDPrefixInformation& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

IPv6NDPrefixInformation::~IPv6NDPrefixInformation()
{
}

IPv6NDPrefixInformation& IPv6NDPrefixInformation::operator=(const IPv6NDPrefixInformation& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void IPv6NDPrefixInformation::copy(const IPv6NDPrefixInformation& other)
{
    this->prefixLength = other.prefixLength;
    this->onlinkFlag = other.onlinkFlag;
    this->autoAddressConfFlag = other.autoAddressConfFlag;
    this->routerAddressFlag = other.routerAddressFlag;
    this->validLifetime = other.validLifetime;
    this->preferredLifetime = other.preferredLifetime;
    this->prefix = other.prefix;
}

void IPv6NDPrefixInformation::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->prefixLength);
    doParsimPacking(b,this->onlinkFlag);
    doParsimPacking(b,this->autoAddressConfFlag);
    doParsimPacking(b,this->routerAddressFlag);
    doParsimPacking(b,this->validLifetime);
    doParsimPacking(b,this->preferredLifetime);
    doParsimPacking(b,this->prefix);
}

void IPv6NDPrefixInformation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->prefixLength);
    doParsimUnpacking(b,this->onlinkFlag);
    doParsimUnpacking(b,this->autoAddressConfFlag);
    doParsimUnpacking(b,this->routerAddressFlag);
    doParsimUnpacking(b,this->validLifetime);
    doParsimUnpacking(b,this->preferredLifetime);
    doParsimUnpacking(b,this->prefix);
}

unsigned short IPv6NDPrefixInformation::getPrefixLength() const
{
    return this->prefixLength;
}

void IPv6NDPrefixInformation::setPrefixLength(unsigned short prefixLength)
{
    this->prefixLength = prefixLength;
}

bool IPv6NDPrefixInformation::getOnlinkFlag() const
{
    return this->onlinkFlag;
}

void IPv6NDPrefixInformation::setOnlinkFlag(bool onlinkFlag)
{
    this->onlinkFlag = onlinkFlag;
}

bool IPv6NDPrefixInformation::getAutoAddressConfFlag() const
{
    return this->autoAddressConfFlag;
}

void IPv6NDPrefixInformation::setAutoAddressConfFlag(bool autoAddressConfFlag)
{
    this->autoAddressConfFlag = autoAddressConfFlag;
}

bool IPv6NDPrefixInformation::getRouterAddressFlag() const
{
    return this->routerAddressFlag;
}

void IPv6NDPrefixInformation::setRouterAddressFlag(bool routerAddressFlag)
{
    this->routerAddressFlag = routerAddressFlag;
}

unsigned int IPv6NDPrefixInformation::getValidLifetime() const
{
    return this->validLifetime;
}

void IPv6NDPrefixInformation::setValidLifetime(unsigned int validLifetime)
{
    this->validLifetime = validLifetime;
}

unsigned int IPv6NDPrefixInformation::getPreferredLifetime() const
{
    return this->preferredLifetime;
}

void IPv6NDPrefixInformation::setPreferredLifetime(unsigned int preferredLifetime)
{
    this->preferredLifetime = preferredLifetime;
}

IPv6Address& IPv6NDPrefixInformation::getPrefix()
{
    return this->prefix;
}

void IPv6NDPrefixInformation::setPrefix(const IPv6Address& prefix)
{
    this->prefix = prefix;
}

class IPv6NDPrefixInformationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6NDPrefixInformationDescriptor();
    virtual ~IPv6NDPrefixInformationDescriptor();

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

Register_ClassDescriptor(IPv6NDPrefixInformationDescriptor)

IPv6NDPrefixInformationDescriptor::IPv6NDPrefixInformationDescriptor() : omnetpp::cClassDescriptor("inet::IPv6NDPrefixInformation", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IPv6NDPrefixInformationDescriptor::~IPv6NDPrefixInformationDescriptor()
{
    delete[] propertynames;
}

bool IPv6NDPrefixInformationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6NDPrefixInformation *>(obj)!=nullptr;
}

const char **IPv6NDPrefixInformationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6NDPrefixInformationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6NDPrefixInformationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int IPv6NDPrefixInformationDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *IPv6NDPrefixInformationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "prefixLength",
        "onlinkFlag",
        "autoAddressConfFlag",
        "routerAddressFlag",
        "validLifetime",
        "preferredLifetime",
        "prefix",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int IPv6NDPrefixInformationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixLength")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "onlinkFlag")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "autoAddressConfFlag")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerAddressFlag")==0) return base+3;
    if (fieldName[0]=='v' && strcmp(fieldName, "validLifetime")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "preferredLifetime")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefix")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6NDPrefixInformationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "bool",
        "bool",
        "bool",
        "unsigned int",
        "unsigned int",
        "IPv6Address",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6NDPrefixInformationDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6NDPrefixInformationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6NDPrefixInformationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6NDPrefixInformation *pp = (IPv6NDPrefixInformation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6NDPrefixInformationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDPrefixInformation *pp = (IPv6NDPrefixInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6NDPrefixInformationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDPrefixInformation *pp = (IPv6NDPrefixInformation *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPrefixLength());
        case 1: return bool2string(pp->getOnlinkFlag());
        case 2: return bool2string(pp->getAutoAddressConfFlag());
        case 3: return bool2string(pp->getRouterAddressFlag());
        case 4: return ulong2string(pp->getValidLifetime());
        case 5: return ulong2string(pp->getPreferredLifetime());
        case 6: {std::stringstream out; out << pp->getPrefix(); return out.str();}
        default: return "";
    }
}

bool IPv6NDPrefixInformationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6NDPrefixInformation *pp = (IPv6NDPrefixInformation *)object; (void)pp;
    switch (field) {
        case 0: pp->setPrefixLength(string2ulong(value)); return true;
        case 1: pp->setOnlinkFlag(string2bool(value)); return true;
        case 2: pp->setAutoAddressConfFlag(string2bool(value)); return true;
        case 3: pp->setRouterAddressFlag(string2bool(value)); return true;
        case 4: pp->setValidLifetime(string2ulong(value)); return true;
        case 5: pp->setPreferredLifetime(string2ulong(value)); return true;
        default: return false;
    }
}

const char *IPv6NDPrefixInformationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 6: return omnetpp::opp_typename(typeid(IPv6Address));
        default: return nullptr;
    };
}

void *IPv6NDPrefixInformationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDPrefixInformation *pp = (IPv6NDPrefixInformation *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getPrefix()); break;
        default: return nullptr;
    }
}

Register_Class(MIPv6NDAdvertisementInterval)

MIPv6NDAdvertisementInterval::MIPv6NDAdvertisementInterval() : ::omnetpp::cObject()
{
    this->advertisementInterval = 0;
}

MIPv6NDAdvertisementInterval::MIPv6NDAdvertisementInterval(const MIPv6NDAdvertisementInterval& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

MIPv6NDAdvertisementInterval::~MIPv6NDAdvertisementInterval()
{
}

MIPv6NDAdvertisementInterval& MIPv6NDAdvertisementInterval::operator=(const MIPv6NDAdvertisementInterval& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void MIPv6NDAdvertisementInterval::copy(const MIPv6NDAdvertisementInterval& other)
{
    this->advertisementInterval = other.advertisementInterval;
}

void MIPv6NDAdvertisementInterval::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->advertisementInterval);
}

void MIPv6NDAdvertisementInterval::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->advertisementInterval);
}

unsigned int MIPv6NDAdvertisementInterval::getAdvertisementInterval() const
{
    return this->advertisementInterval;
}

void MIPv6NDAdvertisementInterval::setAdvertisementInterval(unsigned int advertisementInterval)
{
    this->advertisementInterval = advertisementInterval;
}

class MIPv6NDAdvertisementIntervalDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    MIPv6NDAdvertisementIntervalDescriptor();
    virtual ~MIPv6NDAdvertisementIntervalDescriptor();

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

Register_ClassDescriptor(MIPv6NDAdvertisementIntervalDescriptor)

MIPv6NDAdvertisementIntervalDescriptor::MIPv6NDAdvertisementIntervalDescriptor() : omnetpp::cClassDescriptor("inet::MIPv6NDAdvertisementInterval", "omnetpp::cObject")
{
    propertynames = nullptr;
}

MIPv6NDAdvertisementIntervalDescriptor::~MIPv6NDAdvertisementIntervalDescriptor()
{
    delete[] propertynames;
}

bool MIPv6NDAdvertisementIntervalDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MIPv6NDAdvertisementInterval *>(obj)!=nullptr;
}

const char **MIPv6NDAdvertisementIntervalDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MIPv6NDAdvertisementIntervalDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MIPv6NDAdvertisementIntervalDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int MIPv6NDAdvertisementIntervalDescriptor::getFieldTypeFlags(int field) const
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

const char *MIPv6NDAdvertisementIntervalDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "advertisementInterval",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int MIPv6NDAdvertisementIntervalDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "advertisementInterval")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MIPv6NDAdvertisementIntervalDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **MIPv6NDAdvertisementIntervalDescriptor::getFieldPropertyNames(int field) const
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

const char *MIPv6NDAdvertisementIntervalDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MIPv6NDAdvertisementIntervalDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MIPv6NDAdvertisementInterval *pp = (MIPv6NDAdvertisementInterval *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MIPv6NDAdvertisementIntervalDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MIPv6NDAdvertisementInterval *pp = (MIPv6NDAdvertisementInterval *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MIPv6NDAdvertisementIntervalDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MIPv6NDAdvertisementInterval *pp = (MIPv6NDAdvertisementInterval *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getAdvertisementInterval());
        default: return "";
    }
}

bool MIPv6NDAdvertisementIntervalDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MIPv6NDAdvertisementInterval *pp = (MIPv6NDAdvertisementInterval *)object; (void)pp;
    switch (field) {
        case 0: pp->setAdvertisementInterval(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MIPv6NDAdvertisementIntervalDescriptor::getFieldStructName(int field) const
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

void *MIPv6NDAdvertisementIntervalDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MIPv6NDAdvertisementInterval *pp = (MIPv6NDAdvertisementInterval *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(MIPv6HAInformation)

MIPv6HAInformation::MIPv6HAInformation() : ::omnetpp::cObject()
{
    this->homeAgentPreference = 0;
    this->homeAgentLifetime = 0;
}

MIPv6HAInformation::MIPv6HAInformation(const MIPv6HAInformation& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

MIPv6HAInformation::~MIPv6HAInformation()
{
}

MIPv6HAInformation& MIPv6HAInformation::operator=(const MIPv6HAInformation& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void MIPv6HAInformation::copy(const MIPv6HAInformation& other)
{
    this->homeAgentPreference = other.homeAgentPreference;
    this->homeAgentLifetime = other.homeAgentLifetime;
}

void MIPv6HAInformation::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->homeAgentPreference);
    doParsimPacking(b,this->homeAgentLifetime);
}

void MIPv6HAInformation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->homeAgentPreference);
    doParsimUnpacking(b,this->homeAgentLifetime);
}

unsigned int MIPv6HAInformation::getHomeAgentPreference() const
{
    return this->homeAgentPreference;
}

void MIPv6HAInformation::setHomeAgentPreference(unsigned int homeAgentPreference)
{
    this->homeAgentPreference = homeAgentPreference;
}

unsigned int MIPv6HAInformation::getHomeAgentLifetime() const
{
    return this->homeAgentLifetime;
}

void MIPv6HAInformation::setHomeAgentLifetime(unsigned int homeAgentLifetime)
{
    this->homeAgentLifetime = homeAgentLifetime;
}

class MIPv6HAInformationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    MIPv6HAInformationDescriptor();
    virtual ~MIPv6HAInformationDescriptor();

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

Register_ClassDescriptor(MIPv6HAInformationDescriptor)

MIPv6HAInformationDescriptor::MIPv6HAInformationDescriptor() : omnetpp::cClassDescriptor("inet::MIPv6HAInformation", "omnetpp::cObject")
{
    propertynames = nullptr;
}

MIPv6HAInformationDescriptor::~MIPv6HAInformationDescriptor()
{
    delete[] propertynames;
}

bool MIPv6HAInformationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MIPv6HAInformation *>(obj)!=nullptr;
}

const char **MIPv6HAInformationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *MIPv6HAInformationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int MIPv6HAInformationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int MIPv6HAInformationDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *MIPv6HAInformationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "homeAgentPreference",
        "homeAgentLifetime",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int MIPv6HAInformationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeAgentPreference")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeAgentLifetime")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *MIPv6HAInformationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **MIPv6HAInformationDescriptor::getFieldPropertyNames(int field) const
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

const char *MIPv6HAInformationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int MIPv6HAInformationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    MIPv6HAInformation *pp = (MIPv6HAInformation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *MIPv6HAInformationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MIPv6HAInformation *pp = (MIPv6HAInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MIPv6HAInformationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    MIPv6HAInformation *pp = (MIPv6HAInformation *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getHomeAgentPreference());
        case 1: return ulong2string(pp->getHomeAgentLifetime());
        default: return "";
    }
}

bool MIPv6HAInformationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    MIPv6HAInformation *pp = (MIPv6HAInformation *)object; (void)pp;
    switch (field) {
        case 0: pp->setHomeAgentPreference(string2ulong(value)); return true;
        case 1: pp->setHomeAgentLifetime(string2ulong(value)); return true;
        default: return false;
    }
}

const char *MIPv6HAInformationDescriptor::getFieldStructName(int field) const
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

void *MIPv6HAInformationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    MIPv6HAInformation *pp = (MIPv6HAInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IPv6NDMessage)

IPv6NDMessage::IPv6NDMessage(const char *name, short kind) : ::inet::ICMPv6Message(name,kind)
{
    this->code = 0;
}

IPv6NDMessage::IPv6NDMessage(const IPv6NDMessage& other) : ::inet::ICMPv6Message(other)
{
    copy(other);
}

IPv6NDMessage::~IPv6NDMessage()
{
}

IPv6NDMessage& IPv6NDMessage::operator=(const IPv6NDMessage& other)
{
    if (this==&other) return *this;
    ::inet::ICMPv6Message::operator=(other);
    copy(other);
    return *this;
}

void IPv6NDMessage::copy(const IPv6NDMessage& other)
{
    this->code = other.code;
}

void IPv6NDMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ICMPv6Message::parsimPack(b);
    doParsimPacking(b,this->code);
}

void IPv6NDMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ICMPv6Message::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
}

int IPv6NDMessage::getCode() const
{
    return this->code;
}

void IPv6NDMessage::setCode(int code)
{
    this->code = code;
}

class IPv6NDMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6NDMessageDescriptor();
    virtual ~IPv6NDMessageDescriptor();

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

Register_ClassDescriptor(IPv6NDMessageDescriptor)

IPv6NDMessageDescriptor::IPv6NDMessageDescriptor() : omnetpp::cClassDescriptor("inet::IPv6NDMessage", "inet::ICMPv6Message")
{
    propertynames = nullptr;
}

IPv6NDMessageDescriptor::~IPv6NDMessageDescriptor()
{
    delete[] propertynames;
}

bool IPv6NDMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6NDMessage *>(obj)!=nullptr;
}

const char **IPv6NDMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6NDMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6NDMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IPv6NDMessageDescriptor::getFieldTypeFlags(int field) const
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

const char *IPv6NDMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IPv6NDMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6NDMessageDescriptor::getFieldTypeString(int field) const
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

const char **IPv6NDMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6NDMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6NDMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6NDMessage *pp = (IPv6NDMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6NDMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDMessage *pp = (IPv6NDMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6NDMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDMessage *pp = (IPv6NDMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCode());
        default: return "";
    }
}

bool IPv6NDMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6NDMessage *pp = (IPv6NDMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode(string2long(value)); return true;
        default: return false;
    }
}

const char *IPv6NDMessageDescriptor::getFieldStructName(int field) const
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

void *IPv6NDMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDMessage *pp = (IPv6NDMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IPv6RouterSolicitation)

IPv6RouterSolicitation::IPv6RouterSolicitation(const char *name, short kind) : ::inet::IPv6NDMessage(name,kind)
{
}

IPv6RouterSolicitation::IPv6RouterSolicitation(const IPv6RouterSolicitation& other) : ::inet::IPv6NDMessage(other)
{
    copy(other);
}

IPv6RouterSolicitation::~IPv6RouterSolicitation()
{
}

IPv6RouterSolicitation& IPv6RouterSolicitation::operator=(const IPv6RouterSolicitation& other)
{
    if (this==&other) return *this;
    ::inet::IPv6NDMessage::operator=(other);
    copy(other);
    return *this;
}

void IPv6RouterSolicitation::copy(const IPv6RouterSolicitation& other)
{
    this->sourceLinkLayerAddress = other.sourceLinkLayerAddress;
}

void IPv6RouterSolicitation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IPv6NDMessage::parsimPack(b);
    doParsimPacking(b,this->sourceLinkLayerAddress);
}

void IPv6RouterSolicitation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IPv6NDMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceLinkLayerAddress);
}

MACAddress& IPv6RouterSolicitation::getSourceLinkLayerAddress()
{
    return this->sourceLinkLayerAddress;
}

void IPv6RouterSolicitation::setSourceLinkLayerAddress(const MACAddress& sourceLinkLayerAddress)
{
    this->sourceLinkLayerAddress = sourceLinkLayerAddress;
}

class IPv6RouterSolicitationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6RouterSolicitationDescriptor();
    virtual ~IPv6RouterSolicitationDescriptor();

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

Register_ClassDescriptor(IPv6RouterSolicitationDescriptor)

IPv6RouterSolicitationDescriptor::IPv6RouterSolicitationDescriptor() : omnetpp::cClassDescriptor("inet::IPv6RouterSolicitation", "inet::IPv6NDMessage")
{
    propertynames = nullptr;
}

IPv6RouterSolicitationDescriptor::~IPv6RouterSolicitationDescriptor()
{
    delete[] propertynames;
}

bool IPv6RouterSolicitationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6RouterSolicitation *>(obj)!=nullptr;
}

const char **IPv6RouterSolicitationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6RouterSolicitationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6RouterSolicitationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IPv6RouterSolicitationDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *IPv6RouterSolicitationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceLinkLayerAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IPv6RouterSolicitationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceLinkLayerAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6RouterSolicitationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6RouterSolicitationDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6RouterSolicitationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6RouterSolicitationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterSolicitation *pp = (IPv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6RouterSolicitationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterSolicitation *pp = (IPv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6RouterSolicitationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterSolicitation *pp = (IPv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSourceLinkLayerAddress(); return out.str();}
        default: return "";
    }
}

bool IPv6RouterSolicitationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterSolicitation *pp = (IPv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv6RouterSolicitationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *IPv6RouterSolicitationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterSolicitation *pp = (IPv6RouterSolicitation *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSourceLinkLayerAddress()); break;
        default: return nullptr;
    }
}

Register_Class(IPv6RouterAdvertisement)

IPv6RouterAdvertisement::IPv6RouterAdvertisement(const char *name, short kind) : ::inet::IPv6NDMessage(name,kind)
{
    this->curHopLimit = 0;
    this->managedAddrConfFlag = false;
    this->otherStatefulConfFlag = false;
    this->homeAgentFlag = false;
    this->routerLifetime = 0;
    this->reachableTime = 0;
    this->retransTimer = 0;
    this->MTU = 0;
    prefixInformation_arraysize = 0;
    this->prefixInformation = 0;
}

IPv6RouterAdvertisement::IPv6RouterAdvertisement(const IPv6RouterAdvertisement& other) : ::inet::IPv6NDMessage(other)
{
    prefixInformation_arraysize = 0;
    this->prefixInformation = 0;
    copy(other);
}

IPv6RouterAdvertisement::~IPv6RouterAdvertisement()
{
    delete [] this->prefixInformation;
}

IPv6RouterAdvertisement& IPv6RouterAdvertisement::operator=(const IPv6RouterAdvertisement& other)
{
    if (this==&other) return *this;
    ::inet::IPv6NDMessage::operator=(other);
    copy(other);
    return *this;
}

void IPv6RouterAdvertisement::copy(const IPv6RouterAdvertisement& other)
{
    this->curHopLimit = other.curHopLimit;
    this->managedAddrConfFlag = other.managedAddrConfFlag;
    this->otherStatefulConfFlag = other.otherStatefulConfFlag;
    this->homeAgentFlag = other.homeAgentFlag;
    this->routerLifetime = other.routerLifetime;
    this->reachableTime = other.reachableTime;
    this->retransTimer = other.retransTimer;
    this->sourceLinkLayerAddress = other.sourceLinkLayerAddress;
    this->MTU = other.MTU;
    delete [] this->prefixInformation;
    this->prefixInformation = (other.prefixInformation_arraysize==0) ? nullptr : new IPv6NDPrefixInformation[other.prefixInformation_arraysize];
    prefixInformation_arraysize = other.prefixInformation_arraysize;
    for (unsigned int i=0; i<prefixInformation_arraysize; i++)
        this->prefixInformation[i] = other.prefixInformation[i];
    this->advInterval = other.advInterval;
    this->haInformation = other.haInformation;
}

void IPv6RouterAdvertisement::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IPv6NDMessage::parsimPack(b);
    doParsimPacking(b,this->curHopLimit);
    doParsimPacking(b,this->managedAddrConfFlag);
    doParsimPacking(b,this->otherStatefulConfFlag);
    doParsimPacking(b,this->homeAgentFlag);
    doParsimPacking(b,this->routerLifetime);
    doParsimPacking(b,this->reachableTime);
    doParsimPacking(b,this->retransTimer);
    doParsimPacking(b,this->sourceLinkLayerAddress);
    doParsimPacking(b,this->MTU);
    b->pack(prefixInformation_arraysize);
    doParsimArrayPacking(b,this->prefixInformation,prefixInformation_arraysize);
    doParsimPacking(b,this->advInterval);
    doParsimPacking(b,this->haInformation);
}

void IPv6RouterAdvertisement::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IPv6NDMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->curHopLimit);
    doParsimUnpacking(b,this->managedAddrConfFlag);
    doParsimUnpacking(b,this->otherStatefulConfFlag);
    doParsimUnpacking(b,this->homeAgentFlag);
    doParsimUnpacking(b,this->routerLifetime);
    doParsimUnpacking(b,this->reachableTime);
    doParsimUnpacking(b,this->retransTimer);
    doParsimUnpacking(b,this->sourceLinkLayerAddress);
    doParsimUnpacking(b,this->MTU);
    delete [] this->prefixInformation;
    b->unpack(prefixInformation_arraysize);
    if (prefixInformation_arraysize==0) {
        this->prefixInformation = 0;
    } else {
        this->prefixInformation = new IPv6NDPrefixInformation[prefixInformation_arraysize];
        doParsimArrayUnpacking(b,this->prefixInformation,prefixInformation_arraysize);
    }
    doParsimUnpacking(b,this->advInterval);
    doParsimUnpacking(b,this->haInformation);
}

unsigned short IPv6RouterAdvertisement::getCurHopLimit() const
{
    return this->curHopLimit;
}

void IPv6RouterAdvertisement::setCurHopLimit(unsigned short curHopLimit)
{
    this->curHopLimit = curHopLimit;
}

bool IPv6RouterAdvertisement::getManagedAddrConfFlag() const
{
    return this->managedAddrConfFlag;
}

void IPv6RouterAdvertisement::setManagedAddrConfFlag(bool managedAddrConfFlag)
{
    this->managedAddrConfFlag = managedAddrConfFlag;
}

bool IPv6RouterAdvertisement::getOtherStatefulConfFlag() const
{
    return this->otherStatefulConfFlag;
}

void IPv6RouterAdvertisement::setOtherStatefulConfFlag(bool otherStatefulConfFlag)
{
    this->otherStatefulConfFlag = otherStatefulConfFlag;
}

bool IPv6RouterAdvertisement::getHomeAgentFlag() const
{
    return this->homeAgentFlag;
}

void IPv6RouterAdvertisement::setHomeAgentFlag(bool homeAgentFlag)
{
    this->homeAgentFlag = homeAgentFlag;
}

unsigned short IPv6RouterAdvertisement::getRouterLifetime() const
{
    return this->routerLifetime;
}

void IPv6RouterAdvertisement::setRouterLifetime(unsigned short routerLifetime)
{
    this->routerLifetime = routerLifetime;
}

unsigned int IPv6RouterAdvertisement::getReachableTime() const
{
    return this->reachableTime;
}

void IPv6RouterAdvertisement::setReachableTime(unsigned int reachableTime)
{
    this->reachableTime = reachableTime;
}

unsigned int IPv6RouterAdvertisement::getRetransTimer() const
{
    return this->retransTimer;
}

void IPv6RouterAdvertisement::setRetransTimer(unsigned int retransTimer)
{
    this->retransTimer = retransTimer;
}

MACAddress& IPv6RouterAdvertisement::getSourceLinkLayerAddress()
{
    return this->sourceLinkLayerAddress;
}

void IPv6RouterAdvertisement::setSourceLinkLayerAddress(const MACAddress& sourceLinkLayerAddress)
{
    this->sourceLinkLayerAddress = sourceLinkLayerAddress;
}

unsigned int IPv6RouterAdvertisement::getMTU() const
{
    return this->MTU;
}

void IPv6RouterAdvertisement::setMTU(unsigned int MTU)
{
    this->MTU = MTU;
}

void IPv6RouterAdvertisement::setPrefixInformationArraySize(unsigned int size)
{
    IPv6NDPrefixInformation *prefixInformation2 = (size==0) ? nullptr : new IPv6NDPrefixInformation[size];
    unsigned int sz = prefixInformation_arraysize < size ? prefixInformation_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        prefixInformation2[i] = this->prefixInformation[i];
    prefixInformation_arraysize = size;
    delete [] this->prefixInformation;
    this->prefixInformation = prefixInformation2;
}

unsigned int IPv6RouterAdvertisement::getPrefixInformationArraySize() const
{
    return prefixInformation_arraysize;
}

IPv6NDPrefixInformation& IPv6RouterAdvertisement::getPrefixInformation(unsigned int k)
{
    if (k>=prefixInformation_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", prefixInformation_arraysize, k);
    return this->prefixInformation[k];
}

void IPv6RouterAdvertisement::setPrefixInformation(unsigned int k, const IPv6NDPrefixInformation& prefixInformation)
{
    if (k>=prefixInformation_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", prefixInformation_arraysize, k);
    this->prefixInformation[k] = prefixInformation;
}

MIPv6NDAdvertisementInterval& IPv6RouterAdvertisement::getAdvInterval()
{
    return this->advInterval;
}

void IPv6RouterAdvertisement::setAdvInterval(const MIPv6NDAdvertisementInterval& advInterval)
{
    this->advInterval = advInterval;
}

MIPv6HAInformation& IPv6RouterAdvertisement::getHaInformation()
{
    return this->haInformation;
}

void IPv6RouterAdvertisement::setHaInformation(const MIPv6HAInformation& haInformation)
{
    this->haInformation = haInformation;
}

class IPv6RouterAdvertisementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6RouterAdvertisementDescriptor();
    virtual ~IPv6RouterAdvertisementDescriptor();

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

Register_ClassDescriptor(IPv6RouterAdvertisementDescriptor)

IPv6RouterAdvertisementDescriptor::IPv6RouterAdvertisementDescriptor() : omnetpp::cClassDescriptor("inet::IPv6RouterAdvertisement", "inet::IPv6NDMessage")
{
    propertynames = nullptr;
}

IPv6RouterAdvertisementDescriptor::~IPv6RouterAdvertisementDescriptor()
{
    delete[] propertynames;
}

bool IPv6RouterAdvertisementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6RouterAdvertisement *>(obj)!=nullptr;
}

const char **IPv6RouterAdvertisementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6RouterAdvertisementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6RouterAdvertisementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int IPv6RouterAdvertisementDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *IPv6RouterAdvertisementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "curHopLimit",
        "managedAddrConfFlag",
        "otherStatefulConfFlag",
        "homeAgentFlag",
        "routerLifetime",
        "reachableTime",
        "retransTimer",
        "sourceLinkLayerAddress",
        "MTU",
        "prefixInformation",
        "advInterval",
        "haInformation",
    };
    return (field>=0 && field<12) ? fieldNames[field] : nullptr;
}

int IPv6RouterAdvertisementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "curHopLimit")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "managedAddrConfFlag")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "otherStatefulConfFlag")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "homeAgentFlag")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerLifetime")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "reachableTime")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "retransTimer")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceLinkLayerAddress")==0) return base+7;
    if (fieldName[0]=='M' && strcmp(fieldName, "MTU")==0) return base+8;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixInformation")==0) return base+9;
    if (fieldName[0]=='a' && strcmp(fieldName, "advInterval")==0) return base+10;
    if (fieldName[0]=='h' && strcmp(fieldName, "haInformation")==0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6RouterAdvertisementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "bool",
        "bool",
        "bool",
        "unsigned short",
        "unsigned int",
        "unsigned int",
        "MACAddress",
        "unsigned int",
        "IPv6NDPrefixInformation",
        "MIPv6NDAdvertisementInterval",
        "MIPv6HAInformation",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6RouterAdvertisementDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6RouterAdvertisementDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6RouterAdvertisementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterAdvertisement *pp = (IPv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        case 9: return pp->getPrefixInformationArraySize();
        default: return 0;
    }
}

const char *IPv6RouterAdvertisementDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterAdvertisement *pp = (IPv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6RouterAdvertisementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterAdvertisement *pp = (IPv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCurHopLimit());
        case 1: return bool2string(pp->getManagedAddrConfFlag());
        case 2: return bool2string(pp->getOtherStatefulConfFlag());
        case 3: return bool2string(pp->getHomeAgentFlag());
        case 4: return ulong2string(pp->getRouterLifetime());
        case 5: return ulong2string(pp->getReachableTime());
        case 6: return ulong2string(pp->getRetransTimer());
        case 7: {std::stringstream out; out << pp->getSourceLinkLayerAddress(); return out.str();}
        case 8: return ulong2string(pp->getMTU());
        case 9: {std::stringstream out; out << pp->getPrefixInformation(i); return out.str();}
        case 10: {std::stringstream out; out << pp->getAdvInterval(); return out.str();}
        case 11: {std::stringstream out; out << pp->getHaInformation(); return out.str();}
        default: return "";
    }
}

bool IPv6RouterAdvertisementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterAdvertisement *pp = (IPv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        case 0: pp->setCurHopLimit(string2ulong(value)); return true;
        case 1: pp->setManagedAddrConfFlag(string2bool(value)); return true;
        case 2: pp->setOtherStatefulConfFlag(string2bool(value)); return true;
        case 3: pp->setHomeAgentFlag(string2bool(value)); return true;
        case 4: pp->setRouterLifetime(string2ulong(value)); return true;
        case 5: pp->setReachableTime(string2ulong(value)); return true;
        case 6: pp->setRetransTimer(string2ulong(value)); return true;
        case 8: pp->setMTU(string2ulong(value)); return true;
        default: return false;
    }
}

const char *IPv6RouterAdvertisementDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(MACAddress));
        case 9: return omnetpp::opp_typename(typeid(IPv6NDPrefixInformation));
        case 10: return omnetpp::opp_typename(typeid(MIPv6NDAdvertisementInterval));
        case 11: return omnetpp::opp_typename(typeid(MIPv6HAInformation));
        default: return nullptr;
    };
}

void *IPv6RouterAdvertisementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6RouterAdvertisement *pp = (IPv6RouterAdvertisement *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getSourceLinkLayerAddress()); break;
        case 9: return (void *)static_cast<omnetpp::cObject *>(&pp->getPrefixInformation(i)); break;
        case 10: return (void *)static_cast<omnetpp::cObject *>(&pp->getAdvInterval()); break;
        case 11: return (void *)static_cast<omnetpp::cObject *>(&pp->getHaInformation()); break;
        default: return nullptr;
    }
}

Register_Class(IPv6NeighbourSolicitation)

IPv6NeighbourSolicitation::IPv6NeighbourSolicitation(const char *name, short kind) : ::inet::IPv6NDMessage(name,kind)
{
}

IPv6NeighbourSolicitation::IPv6NeighbourSolicitation(const IPv6NeighbourSolicitation& other) : ::inet::IPv6NDMessage(other)
{
    copy(other);
}

IPv6NeighbourSolicitation::~IPv6NeighbourSolicitation()
{
}

IPv6NeighbourSolicitation& IPv6NeighbourSolicitation::operator=(const IPv6NeighbourSolicitation& other)
{
    if (this==&other) return *this;
    ::inet::IPv6NDMessage::operator=(other);
    copy(other);
    return *this;
}

void IPv6NeighbourSolicitation::copy(const IPv6NeighbourSolicitation& other)
{
    this->targetAddress = other.targetAddress;
    this->sourceLinkLayerAddress = other.sourceLinkLayerAddress;
}

void IPv6NeighbourSolicitation::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IPv6NDMessage::parsimPack(b);
    doParsimPacking(b,this->targetAddress);
    doParsimPacking(b,this->sourceLinkLayerAddress);
}

void IPv6NeighbourSolicitation::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IPv6NDMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->targetAddress);
    doParsimUnpacking(b,this->sourceLinkLayerAddress);
}

IPv6Address& IPv6NeighbourSolicitation::getTargetAddress()
{
    return this->targetAddress;
}

void IPv6NeighbourSolicitation::setTargetAddress(const IPv6Address& targetAddress)
{
    this->targetAddress = targetAddress;
}

MACAddress& IPv6NeighbourSolicitation::getSourceLinkLayerAddress()
{
    return this->sourceLinkLayerAddress;
}

void IPv6NeighbourSolicitation::setSourceLinkLayerAddress(const MACAddress& sourceLinkLayerAddress)
{
    this->sourceLinkLayerAddress = sourceLinkLayerAddress;
}

class IPv6NeighbourSolicitationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6NeighbourSolicitationDescriptor();
    virtual ~IPv6NeighbourSolicitationDescriptor();

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

Register_ClassDescriptor(IPv6NeighbourSolicitationDescriptor)

IPv6NeighbourSolicitationDescriptor::IPv6NeighbourSolicitationDescriptor() : omnetpp::cClassDescriptor("inet::IPv6NeighbourSolicitation", "inet::IPv6NDMessage")
{
    propertynames = nullptr;
}

IPv6NeighbourSolicitationDescriptor::~IPv6NeighbourSolicitationDescriptor()
{
    delete[] propertynames;
}

bool IPv6NeighbourSolicitationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6NeighbourSolicitation *>(obj)!=nullptr;
}

const char **IPv6NeighbourSolicitationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6NeighbourSolicitationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6NeighbourSolicitationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int IPv6NeighbourSolicitationDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *IPv6NeighbourSolicitationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "targetAddress",
        "sourceLinkLayerAddress",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int IPv6NeighbourSolicitationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetAddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceLinkLayerAddress")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6NeighbourSolicitationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv6Address",
        "MACAddress",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6NeighbourSolicitationDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6NeighbourSolicitationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6NeighbourSolicitationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourSolicitation *pp = (IPv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6NeighbourSolicitationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourSolicitation *pp = (IPv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6NeighbourSolicitationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourSolicitation *pp = (IPv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getTargetAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSourceLinkLayerAddress(); return out.str();}
        default: return "";
    }
}

bool IPv6NeighbourSolicitationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourSolicitation *pp = (IPv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv6NeighbourSolicitationDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv6Address));
        case 1: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *IPv6NeighbourSolicitationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourSolicitation *pp = (IPv6NeighbourSolicitation *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getTargetAddress()); break;
        case 1: return (void *)(&pp->getSourceLinkLayerAddress()); break;
        default: return nullptr;
    }
}

Register_Class(IPv6NeighbourAdvertisement)

IPv6NeighbourAdvertisement::IPv6NeighbourAdvertisement(const char *name, short kind) : ::inet::IPv6NDMessage(name,kind)
{
    this->routerFlag = false;
    this->solicitedFlag = false;
    this->overrideFlag = false;
}

IPv6NeighbourAdvertisement::IPv6NeighbourAdvertisement(const IPv6NeighbourAdvertisement& other) : ::inet::IPv6NDMessage(other)
{
    copy(other);
}

IPv6NeighbourAdvertisement::~IPv6NeighbourAdvertisement()
{
}

IPv6NeighbourAdvertisement& IPv6NeighbourAdvertisement::operator=(const IPv6NeighbourAdvertisement& other)
{
    if (this==&other) return *this;
    ::inet::IPv6NDMessage::operator=(other);
    copy(other);
    return *this;
}

void IPv6NeighbourAdvertisement::copy(const IPv6NeighbourAdvertisement& other)
{
    this->routerFlag = other.routerFlag;
    this->solicitedFlag = other.solicitedFlag;
    this->overrideFlag = other.overrideFlag;
    this->targetAddress = other.targetAddress;
    this->targetLinkLayerAddress = other.targetLinkLayerAddress;
}

void IPv6NeighbourAdvertisement::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IPv6NDMessage::parsimPack(b);
    doParsimPacking(b,this->routerFlag);
    doParsimPacking(b,this->solicitedFlag);
    doParsimPacking(b,this->overrideFlag);
    doParsimPacking(b,this->targetAddress);
    doParsimPacking(b,this->targetLinkLayerAddress);
}

void IPv6NeighbourAdvertisement::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IPv6NDMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->routerFlag);
    doParsimUnpacking(b,this->solicitedFlag);
    doParsimUnpacking(b,this->overrideFlag);
    doParsimUnpacking(b,this->targetAddress);
    doParsimUnpacking(b,this->targetLinkLayerAddress);
}

bool IPv6NeighbourAdvertisement::getRouterFlag() const
{
    return this->routerFlag;
}

void IPv6NeighbourAdvertisement::setRouterFlag(bool routerFlag)
{
    this->routerFlag = routerFlag;
}

bool IPv6NeighbourAdvertisement::getSolicitedFlag() const
{
    return this->solicitedFlag;
}

void IPv6NeighbourAdvertisement::setSolicitedFlag(bool solicitedFlag)
{
    this->solicitedFlag = solicitedFlag;
}

bool IPv6NeighbourAdvertisement::getOverrideFlag() const
{
    return this->overrideFlag;
}

void IPv6NeighbourAdvertisement::setOverrideFlag(bool overrideFlag)
{
    this->overrideFlag = overrideFlag;
}

IPv6Address& IPv6NeighbourAdvertisement::getTargetAddress()
{
    return this->targetAddress;
}

void IPv6NeighbourAdvertisement::setTargetAddress(const IPv6Address& targetAddress)
{
    this->targetAddress = targetAddress;
}

MACAddress& IPv6NeighbourAdvertisement::getTargetLinkLayerAddress()
{
    return this->targetLinkLayerAddress;
}

void IPv6NeighbourAdvertisement::setTargetLinkLayerAddress(const MACAddress& targetLinkLayerAddress)
{
    this->targetLinkLayerAddress = targetLinkLayerAddress;
}

class IPv6NeighbourAdvertisementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6NeighbourAdvertisementDescriptor();
    virtual ~IPv6NeighbourAdvertisementDescriptor();

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

Register_ClassDescriptor(IPv6NeighbourAdvertisementDescriptor)

IPv6NeighbourAdvertisementDescriptor::IPv6NeighbourAdvertisementDescriptor() : omnetpp::cClassDescriptor("inet::IPv6NeighbourAdvertisement", "inet::IPv6NDMessage")
{
    propertynames = nullptr;
}

IPv6NeighbourAdvertisementDescriptor::~IPv6NeighbourAdvertisementDescriptor()
{
    delete[] propertynames;
}

bool IPv6NeighbourAdvertisementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6NeighbourAdvertisement *>(obj)!=nullptr;
}

const char **IPv6NeighbourAdvertisementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6NeighbourAdvertisementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6NeighbourAdvertisementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int IPv6NeighbourAdvertisementDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *IPv6NeighbourAdvertisementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "routerFlag",
        "solicitedFlag",
        "overrideFlag",
        "targetAddress",
        "targetLinkLayerAddress",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int IPv6NeighbourAdvertisementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerFlag")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "solicitedFlag")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "overrideFlag")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetAddress")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetLinkLayerAddress")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6NeighbourAdvertisementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "bool",
        "bool",
        "IPv6Address",
        "MACAddress",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6NeighbourAdvertisementDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6NeighbourAdvertisementDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6NeighbourAdvertisementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourAdvertisement *pp = (IPv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6NeighbourAdvertisementDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourAdvertisement *pp = (IPv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6NeighbourAdvertisementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourAdvertisement *pp = (IPv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getRouterFlag());
        case 1: return bool2string(pp->getSolicitedFlag());
        case 2: return bool2string(pp->getOverrideFlag());
        case 3: {std::stringstream out; out << pp->getTargetAddress(); return out.str();}
        case 4: {std::stringstream out; out << pp->getTargetLinkLayerAddress(); return out.str();}
        default: return "";
    }
}

bool IPv6NeighbourAdvertisementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourAdvertisement *pp = (IPv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        case 0: pp->setRouterFlag(string2bool(value)); return true;
        case 1: pp->setSolicitedFlag(string2bool(value)); return true;
        case 2: pp->setOverrideFlag(string2bool(value)); return true;
        default: return false;
    }
}

const char *IPv6NeighbourAdvertisementDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(IPv6Address));
        case 4: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *IPv6NeighbourAdvertisementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6NeighbourAdvertisement *pp = (IPv6NeighbourAdvertisement *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getTargetAddress()); break;
        case 4: return (void *)(&pp->getTargetLinkLayerAddress()); break;
        default: return nullptr;
    }
}

Register_Class(IPv6Redirect)

IPv6Redirect::IPv6Redirect(const char *name, short kind) : ::inet::IPv6NDMessage(name,kind)
{
}

IPv6Redirect::IPv6Redirect(const IPv6Redirect& other) : ::inet::IPv6NDMessage(other)
{
    copy(other);
}

IPv6Redirect::~IPv6Redirect()
{
}

IPv6Redirect& IPv6Redirect::operator=(const IPv6Redirect& other)
{
    if (this==&other) return *this;
    ::inet::IPv6NDMessage::operator=(other);
    copy(other);
    return *this;
}

void IPv6Redirect::copy(const IPv6Redirect& other)
{
    this->targetAddress = other.targetAddress;
    this->destinationAddress = other.destinationAddress;
    this->targetLinkLayerAddress = other.targetLinkLayerAddress;
}

void IPv6Redirect::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IPv6NDMessage::parsimPack(b);
    doParsimPacking(b,this->targetAddress);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->targetLinkLayerAddress);
}

void IPv6Redirect::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IPv6NDMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->targetAddress);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->targetLinkLayerAddress);
}

IPv6Address& IPv6Redirect::getTargetAddress()
{
    return this->targetAddress;
}

void IPv6Redirect::setTargetAddress(const IPv6Address& targetAddress)
{
    this->targetAddress = targetAddress;
}

IPv6Address& IPv6Redirect::getDestinationAddress()
{
    return this->destinationAddress;
}

void IPv6Redirect::setDestinationAddress(const IPv6Address& destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

MACAddress& IPv6Redirect::getTargetLinkLayerAddress()
{
    return this->targetLinkLayerAddress;
}

void IPv6Redirect::setTargetLinkLayerAddress(const MACAddress& targetLinkLayerAddress)
{
    this->targetLinkLayerAddress = targetLinkLayerAddress;
}

class IPv6RedirectDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6RedirectDescriptor();
    virtual ~IPv6RedirectDescriptor();

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

Register_ClassDescriptor(IPv6RedirectDescriptor)

IPv6RedirectDescriptor::IPv6RedirectDescriptor() : omnetpp::cClassDescriptor("inet::IPv6Redirect", "inet::IPv6NDMessage")
{
    propertynames = nullptr;
}

IPv6RedirectDescriptor::~IPv6RedirectDescriptor()
{
    delete[] propertynames;
}

bool IPv6RedirectDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6Redirect *>(obj)!=nullptr;
}

const char **IPv6RedirectDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6RedirectDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6RedirectDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int IPv6RedirectDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *IPv6RedirectDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "targetAddress",
        "destinationAddress",
        "targetLinkLayerAddress",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int IPv6RedirectDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "targetLinkLayerAddress")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6RedirectDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv6Address",
        "IPv6Address",
        "MACAddress",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6RedirectDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6RedirectDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6RedirectDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6Redirect *pp = (IPv6Redirect *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6RedirectDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6Redirect *pp = (IPv6Redirect *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6RedirectDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6Redirect *pp = (IPv6Redirect *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getTargetAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDestinationAddress(); return out.str();}
        case 2: {std::stringstream out; out << pp->getTargetLinkLayerAddress(); return out.str();}
        default: return "";
    }
}

bool IPv6RedirectDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6Redirect *pp = (IPv6Redirect *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv6RedirectDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv6Address));
        case 1: return omnetpp::opp_typename(typeid(IPv6Address));
        case 2: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *IPv6RedirectDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6Redirect *pp = (IPv6Redirect *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getTargetAddress()); break;
        case 1: return (void *)(&pp->getDestinationAddress()); break;
        case 2: return (void *)(&pp->getTargetLinkLayerAddress()); break;
        default: return nullptr;
    }
}

Register_Class(IPv6NDControlInfo)

IPv6NDControlInfo::IPv6NDControlInfo() : ::omnetpp::cObject()
{
    this->interfaceId = -1;
    this->fromHL = false;
}

IPv6NDControlInfo::IPv6NDControlInfo(const IPv6NDControlInfo& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

IPv6NDControlInfo::~IPv6NDControlInfo()
{
}

IPv6NDControlInfo& IPv6NDControlInfo::operator=(const IPv6NDControlInfo& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void IPv6NDControlInfo::copy(const IPv6NDControlInfo& other)
{
    this->nextHop = other.nextHop;
    this->interfaceId = other.interfaceId;
    this->fromHL = other.fromHL;
}

void IPv6NDControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->nextHop);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->fromHL);
}

void IPv6NDControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->nextHop);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->fromHL);
}

IPv6Address& IPv6NDControlInfo::getNextHop()
{
    return this->nextHop;
}

void IPv6NDControlInfo::setNextHop(const IPv6Address& nextHop)
{
    this->nextHop = nextHop;
}

int IPv6NDControlInfo::getInterfaceId() const
{
    return this->interfaceId;
}

void IPv6NDControlInfo::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

bool IPv6NDControlInfo::getFromHL() const
{
    return this->fromHL;
}

void IPv6NDControlInfo::setFromHL(bool fromHL)
{
    this->fromHL = fromHL;
}

class IPv6NDControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6NDControlInfoDescriptor();
    virtual ~IPv6NDControlInfoDescriptor();

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

Register_ClassDescriptor(IPv6NDControlInfoDescriptor)

IPv6NDControlInfoDescriptor::IPv6NDControlInfoDescriptor() : omnetpp::cClassDescriptor("inet::IPv6NDControlInfo", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IPv6NDControlInfoDescriptor::~IPv6NDControlInfoDescriptor()
{
    delete[] propertynames;
}

bool IPv6NDControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6NDControlInfo *>(obj)!=nullptr;
}

const char **IPv6NDControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6NDControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6NDControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int IPv6NDControlInfoDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *IPv6NDControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nextHop",
        "interfaceId",
        "fromHL",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int IPv6NDControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHop")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fromHL")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6NDControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv6Address",
        "int",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6NDControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6NDControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6NDControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6NDControlInfo *pp = (IPv6NDControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6NDControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDControlInfo *pp = (IPv6NDControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6NDControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDControlInfo *pp = (IPv6NDControlInfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getNextHop(); return out.str();}
        case 1: return long2string(pp->getInterfaceId());
        case 2: return bool2string(pp->getFromHL());
        default: return "";
    }
}

bool IPv6NDControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6NDControlInfo *pp = (IPv6NDControlInfo *)object; (void)pp;
    switch (field) {
        case 1: pp->setInterfaceId(string2long(value)); return true;
        case 2: pp->setFromHL(string2bool(value)); return true;
        default: return false;
    }
}

const char *IPv6NDControlInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv6Address));
        default: return nullptr;
    };
}

void *IPv6NDControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6NDControlInfo *pp = (IPv6NDControlInfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getNextHop()); break;
        default: return nullptr;
    }
}

} // namespace inet

