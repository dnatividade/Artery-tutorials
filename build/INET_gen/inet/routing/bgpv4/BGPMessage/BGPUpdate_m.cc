//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPUpdate.msg.
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
#include "BGPUpdate_m.h"

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
namespace bgp {

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

BGPUpdateWithdrawnRoutes::BGPUpdateWithdrawnRoutes()
{
    this->length = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BGPUpdateWithdrawnRoutes& a)
{
    doParsimPacking(b,a.length);
    doParsimPacking(b,a.prefix);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BGPUpdateWithdrawnRoutes& a)
{
    doParsimUnpacking(b,a.length);
    doParsimUnpacking(b,a.prefix);
}

class BGPUpdateWithdrawnRoutesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdateWithdrawnRoutesDescriptor();
    virtual ~BGPUpdateWithdrawnRoutesDescriptor();

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

Register_ClassDescriptor(BGPUpdateWithdrawnRoutesDescriptor)

BGPUpdateWithdrawnRoutesDescriptor::BGPUpdateWithdrawnRoutesDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdateWithdrawnRoutes", "")
{
    propertynames = nullptr;
}

BGPUpdateWithdrawnRoutesDescriptor::~BGPUpdateWithdrawnRoutesDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdateWithdrawnRoutesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdateWithdrawnRoutes *>(obj)!=nullptr;
}

const char **BGPUpdateWithdrawnRoutesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdateWithdrawnRoutesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdateWithdrawnRoutesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BGPUpdateWithdrawnRoutesDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *BGPUpdateWithdrawnRoutesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "prefix",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int BGPUpdateWithdrawnRoutesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefix")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdateWithdrawnRoutesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "IPv4Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdateWithdrawnRoutesDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdateWithdrawnRoutesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdateWithdrawnRoutesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateWithdrawnRoutes *pp = (BGPUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdateWithdrawnRoutesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateWithdrawnRoutes *pp = (BGPUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdateWithdrawnRoutesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateWithdrawnRoutes *pp = (BGPUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->length);
        case 1: {std::stringstream out; out << pp->prefix; return out.str();}
        default: return "";
    }
}

bool BGPUpdateWithdrawnRoutesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateWithdrawnRoutes *pp = (BGPUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case 0: pp->length = string2ulong(value); return true;
        default: return false;
    }
}

const char *BGPUpdateWithdrawnRoutesDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *BGPUpdateWithdrawnRoutesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateWithdrawnRoutes *pp = (BGPUpdateWithdrawnRoutes *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->prefix); break;
        default: return nullptr;
    }
}

BGPUpdateNLRI::BGPUpdateNLRI()
{
    this->length = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BGPUpdateNLRI& a)
{
    doParsimPacking(b,a.length);
    doParsimPacking(b,a.prefix);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BGPUpdateNLRI& a)
{
    doParsimUnpacking(b,a.length);
    doParsimUnpacking(b,a.prefix);
}

class BGPUpdateNLRIDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdateNLRIDescriptor();
    virtual ~BGPUpdateNLRIDescriptor();

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

Register_ClassDescriptor(BGPUpdateNLRIDescriptor)

BGPUpdateNLRIDescriptor::BGPUpdateNLRIDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdateNLRI", "")
{
    propertynames = nullptr;
}

BGPUpdateNLRIDescriptor::~BGPUpdateNLRIDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdateNLRIDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdateNLRI *>(obj)!=nullptr;
}

const char **BGPUpdateNLRIDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdateNLRIDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdateNLRIDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BGPUpdateNLRIDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *BGPUpdateNLRIDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "length",
        "prefix",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int BGPUpdateNLRIDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefix")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdateNLRIDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "IPv4Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdateNLRIDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdateNLRIDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdateNLRIDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateNLRI *pp = (BGPUpdateNLRI *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdateNLRIDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateNLRI *pp = (BGPUpdateNLRI *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdateNLRIDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateNLRI *pp = (BGPUpdateNLRI *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->length);
        case 1: {std::stringstream out; out << pp->prefix; return out.str();}
        default: return "";
    }
}

bool BGPUpdateNLRIDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateNLRI *pp = (BGPUpdateNLRI *)object; (void)pp;
    switch (field) {
        case 0: pp->length = string2ulong(value); return true;
        default: return false;
    }
}

const char *BGPUpdateNLRIDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *BGPUpdateNLRIDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateNLRI *pp = (BGPUpdateNLRI *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->prefix); break;
        default: return nullptr;
    }
}

Register_Class(BGPUpdatePathAttributeList)

BGPUpdatePathAttributeList::BGPUpdatePathAttributeList() : ::omnetpp::cObject()
{
    asPath_arraysize = 0;
    this->asPath = 0;
    localPref_arraysize = 0;
    this->localPref = 0;
    atomicAggregate_arraysize = 0;
    this->atomicAggregate = 0;
}

BGPUpdatePathAttributeList::BGPUpdatePathAttributeList(const BGPUpdatePathAttributeList& other) : ::omnetpp::cObject(other)
{
    asPath_arraysize = 0;
    this->asPath = 0;
    localPref_arraysize = 0;
    this->localPref = 0;
    atomicAggregate_arraysize = 0;
    this->atomicAggregate = 0;
    copy(other);
}

BGPUpdatePathAttributeList::~BGPUpdatePathAttributeList()
{
    delete [] this->asPath;
    delete [] this->localPref;
    delete [] this->atomicAggregate;
}

BGPUpdatePathAttributeList& BGPUpdatePathAttributeList::operator=(const BGPUpdatePathAttributeList& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void BGPUpdatePathAttributeList::copy(const BGPUpdatePathAttributeList& other)
{
    this->origin = other.origin;
    delete [] this->asPath;
    this->asPath = (other.asPath_arraysize==0) ? nullptr : new BGPUpdatePathAttributesASPath[other.asPath_arraysize];
    asPath_arraysize = other.asPath_arraysize;
    for (unsigned int i=0; i<asPath_arraysize; i++)
        this->asPath[i] = other.asPath[i];
    this->nextHop = other.nextHop;
    delete [] this->localPref;
    this->localPref = (other.localPref_arraysize==0) ? nullptr : new BGPUpdatePathAttributesLocalPref[other.localPref_arraysize];
    localPref_arraysize = other.localPref_arraysize;
    for (unsigned int i=0; i<localPref_arraysize; i++)
        this->localPref[i] = other.localPref[i];
    delete [] this->atomicAggregate;
    this->atomicAggregate = (other.atomicAggregate_arraysize==0) ? nullptr : new BGPUpdatePathAttributesAtomicAggregate[other.atomicAggregate_arraysize];
    atomicAggregate_arraysize = other.atomicAggregate_arraysize;
    for (unsigned int i=0; i<atomicAggregate_arraysize; i++)
        this->atomicAggregate[i] = other.atomicAggregate[i];
}

void BGPUpdatePathAttributeList::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->origin);
    b->pack(asPath_arraysize);
    doParsimArrayPacking(b,this->asPath,asPath_arraysize);
    doParsimPacking(b,this->nextHop);
    b->pack(localPref_arraysize);
    doParsimArrayPacking(b,this->localPref,localPref_arraysize);
    b->pack(atomicAggregate_arraysize);
    doParsimArrayPacking(b,this->atomicAggregate,atomicAggregate_arraysize);
}

void BGPUpdatePathAttributeList::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->origin);
    delete [] this->asPath;
    b->unpack(asPath_arraysize);
    if (asPath_arraysize==0) {
        this->asPath = 0;
    } else {
        this->asPath = new BGPUpdatePathAttributesASPath[asPath_arraysize];
        doParsimArrayUnpacking(b,this->asPath,asPath_arraysize);
    }
    doParsimUnpacking(b,this->nextHop);
    delete [] this->localPref;
    b->unpack(localPref_arraysize);
    if (localPref_arraysize==0) {
        this->localPref = 0;
    } else {
        this->localPref = new BGPUpdatePathAttributesLocalPref[localPref_arraysize];
        doParsimArrayUnpacking(b,this->localPref,localPref_arraysize);
    }
    delete [] this->atomicAggregate;
    b->unpack(atomicAggregate_arraysize);
    if (atomicAggregate_arraysize==0) {
        this->atomicAggregate = 0;
    } else {
        this->atomicAggregate = new BGPUpdatePathAttributesAtomicAggregate[atomicAggregate_arraysize];
        doParsimArrayUnpacking(b,this->atomicAggregate,atomicAggregate_arraysize);
    }
}

BGPUpdatePathAttributesOrigin& BGPUpdatePathAttributeList::getOrigin()
{
    return this->origin;
}

void BGPUpdatePathAttributeList::setOrigin(const BGPUpdatePathAttributesOrigin& origin)
{
    this->origin = origin;
}

void BGPUpdatePathAttributeList::setAsPathArraySize(unsigned int size)
{
    BGPUpdatePathAttributesASPath *asPath2 = (size==0) ? nullptr : new BGPUpdatePathAttributesASPath[size];
    unsigned int sz = asPath_arraysize < size ? asPath_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        asPath2[i] = this->asPath[i];
    asPath_arraysize = size;
    delete [] this->asPath;
    this->asPath = asPath2;
}

unsigned int BGPUpdatePathAttributeList::getAsPathArraySize() const
{
    return asPath_arraysize;
}

BGPUpdatePathAttributesASPath& BGPUpdatePathAttributeList::getAsPath(unsigned int k)
{
    if (k>=asPath_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", asPath_arraysize, k);
    return this->asPath[k];
}

void BGPUpdatePathAttributeList::setAsPath(unsigned int k, const BGPUpdatePathAttributesASPath& asPath)
{
    if (k>=asPath_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", asPath_arraysize, k);
    this->asPath[k] = asPath;
}

BGPUpdatePathAttributesNextHop& BGPUpdatePathAttributeList::getNextHop()
{
    return this->nextHop;
}

void BGPUpdatePathAttributeList::setNextHop(const BGPUpdatePathAttributesNextHop& nextHop)
{
    this->nextHop = nextHop;
}

void BGPUpdatePathAttributeList::setLocalPrefArraySize(unsigned int size)
{
    BGPUpdatePathAttributesLocalPref *localPref2 = (size==0) ? nullptr : new BGPUpdatePathAttributesLocalPref[size];
    unsigned int sz = localPref_arraysize < size ? localPref_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        localPref2[i] = this->localPref[i];
    localPref_arraysize = size;
    delete [] this->localPref;
    this->localPref = localPref2;
}

unsigned int BGPUpdatePathAttributeList::getLocalPrefArraySize() const
{
    return localPref_arraysize;
}

BGPUpdatePathAttributesLocalPref& BGPUpdatePathAttributeList::getLocalPref(unsigned int k)
{
    if (k>=localPref_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", localPref_arraysize, k);
    return this->localPref[k];
}

void BGPUpdatePathAttributeList::setLocalPref(unsigned int k, const BGPUpdatePathAttributesLocalPref& localPref)
{
    if (k>=localPref_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", localPref_arraysize, k);
    this->localPref[k] = localPref;
}

void BGPUpdatePathAttributeList::setAtomicAggregateArraySize(unsigned int size)
{
    BGPUpdatePathAttributesAtomicAggregate *atomicAggregate2 = (size==0) ? nullptr : new BGPUpdatePathAttributesAtomicAggregate[size];
    unsigned int sz = atomicAggregate_arraysize < size ? atomicAggregate_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        atomicAggregate2[i] = this->atomicAggregate[i];
    atomicAggregate_arraysize = size;
    delete [] this->atomicAggregate;
    this->atomicAggregate = atomicAggregate2;
}

unsigned int BGPUpdatePathAttributeList::getAtomicAggregateArraySize() const
{
    return atomicAggregate_arraysize;
}

BGPUpdatePathAttributesAtomicAggregate& BGPUpdatePathAttributeList::getAtomicAggregate(unsigned int k)
{
    if (k>=atomicAggregate_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", atomicAggregate_arraysize, k);
    return this->atomicAggregate[k];
}

void BGPUpdatePathAttributeList::setAtomicAggregate(unsigned int k, const BGPUpdatePathAttributesAtomicAggregate& atomicAggregate)
{
    if (k>=atomicAggregate_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", atomicAggregate_arraysize, k);
    this->atomicAggregate[k] = atomicAggregate;
}

class BGPUpdatePathAttributeListDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdatePathAttributeListDescriptor();
    virtual ~BGPUpdatePathAttributeListDescriptor();

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

Register_ClassDescriptor(BGPUpdatePathAttributeListDescriptor)

BGPUpdatePathAttributeListDescriptor::BGPUpdatePathAttributeListDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdatePathAttributeList", "omnetpp::cObject")
{
    propertynames = nullptr;
}

BGPUpdatePathAttributeListDescriptor::~BGPUpdatePathAttributeListDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdatePathAttributeListDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdatePathAttributeList *>(obj)!=nullptr;
}

const char **BGPUpdatePathAttributeListDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdatePathAttributeListDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdatePathAttributeListDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int BGPUpdatePathAttributeListDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *BGPUpdatePathAttributeListDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "origin",
        "asPath",
        "nextHop",
        "localPref",
        "atomicAggregate",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int BGPUpdatePathAttributeListDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "origin")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "asPath")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHop")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "localPref")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "atomicAggregate")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdatePathAttributeListDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "BGPUpdatePathAttributesOrigin",
        "BGPUpdatePathAttributesASPath",
        "BGPUpdatePathAttributesNextHop",
        "BGPUpdatePathAttributesLocalPref",
        "BGPUpdatePathAttributesAtomicAggregate",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdatePathAttributeListDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdatePathAttributeListDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdatePathAttributeListDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributeList *pp = (BGPUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        case 1: return pp->getAsPathArraySize();
        case 3: return pp->getLocalPrefArraySize();
        case 4: return pp->getAtomicAggregateArraySize();
        default: return 0;
    }
}

const char *BGPUpdatePathAttributeListDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributeList *pp = (BGPUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdatePathAttributeListDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributeList *pp = (BGPUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOrigin(); return out.str();}
        case 1: {std::stringstream out; out << pp->getAsPath(i); return out.str();}
        case 2: {std::stringstream out; out << pp->getNextHop(); return out.str();}
        case 3: {std::stringstream out; out << pp->getLocalPref(i); return out.str();}
        case 4: {std::stringstream out; out << pp->getAtomicAggregate(i); return out.str();}
        default: return "";
    }
}

bool BGPUpdatePathAttributeListDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributeList *pp = (BGPUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BGPUpdatePathAttributeListDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(BGPUpdatePathAttributesOrigin));
        case 1: return omnetpp::opp_typename(typeid(BGPUpdatePathAttributesASPath));
        case 2: return omnetpp::opp_typename(typeid(BGPUpdatePathAttributesNextHop));
        case 3: return omnetpp::opp_typename(typeid(BGPUpdatePathAttributesLocalPref));
        case 4: return omnetpp::opp_typename(typeid(BGPUpdatePathAttributesAtomicAggregate));
        default: return nullptr;
    };
}

void *BGPUpdatePathAttributeListDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributeList *pp = (BGPUpdatePathAttributeList *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getOrigin()); break;
        case 1: return (void *)(&pp->getAsPath(i)); break;
        case 2: return (void *)(&pp->getNextHop()); break;
        case 3: return (void *)(&pp->getLocalPref(i)); break;
        case 4: return (void *)(&pp->getAtomicAggregate(i)); break;
        default: return nullptr;
    }
}

BGPUpdateMessage_Base::BGPUpdateMessage_Base(const char *name, short kind) : ::inet::bgp::BGPHeader(name,kind)
{
    this->setType(BGP_UPDATE);
    this->setByteLength(BGP_HEADER_OCTETS + BGP_EMPTY_UPDATE_OCTETS);

    withdrawnRoutes_arraysize = 0;
    this->withdrawnRoutes = 0;
    pathAttributeList_arraysize = 0;
    this->pathAttributeList = 0;
}

BGPUpdateMessage_Base::BGPUpdateMessage_Base(const BGPUpdateMessage_Base& other) : ::inet::bgp::BGPHeader(other)
{
    withdrawnRoutes_arraysize = 0;
    this->withdrawnRoutes = 0;
    pathAttributeList_arraysize = 0;
    this->pathAttributeList = 0;
    copy(other);
}

BGPUpdateMessage_Base::~BGPUpdateMessage_Base()
{
    delete [] this->withdrawnRoutes;
    delete [] this->pathAttributeList;
}

BGPUpdateMessage_Base& BGPUpdateMessage_Base::operator=(const BGPUpdateMessage_Base& other)
{
    if (this==&other) return *this;
    ::inet::bgp::BGPHeader::operator=(other);
    copy(other);
    return *this;
}

void BGPUpdateMessage_Base::copy(const BGPUpdateMessage_Base& other)
{
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = (other.withdrawnRoutes_arraysize==0) ? nullptr : new BGPUpdateWithdrawnRoutes[other.withdrawnRoutes_arraysize];
    withdrawnRoutes_arraysize = other.withdrawnRoutes_arraysize;
    for (unsigned int i=0; i<withdrawnRoutes_arraysize; i++)
        this->withdrawnRoutes[i] = other.withdrawnRoutes[i];
    delete [] this->pathAttributeList;
    this->pathAttributeList = (other.pathAttributeList_arraysize==0) ? nullptr : new BGPUpdatePathAttributeList[other.pathAttributeList_arraysize];
    pathAttributeList_arraysize = other.pathAttributeList_arraysize;
    for (unsigned int i=0; i<pathAttributeList_arraysize; i++)
        this->pathAttributeList[i] = other.pathAttributeList[i];
    this->NLRI = other.NLRI;
}

void BGPUpdateMessage_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BGPHeader::parsimPack(b);
    b->pack(withdrawnRoutes_arraysize);
    doParsimArrayPacking(b,this->withdrawnRoutes,withdrawnRoutes_arraysize);
    b->pack(pathAttributeList_arraysize);
    doParsimArrayPacking(b,this->pathAttributeList,pathAttributeList_arraysize);
    doParsimPacking(b,this->NLRI);
}

void BGPUpdateMessage_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BGPHeader::parsimUnpack(b);
    delete [] this->withdrawnRoutes;
    b->unpack(withdrawnRoutes_arraysize);
    if (withdrawnRoutes_arraysize==0) {
        this->withdrawnRoutes = 0;
    } else {
        this->withdrawnRoutes = new BGPUpdateWithdrawnRoutes[withdrawnRoutes_arraysize];
        doParsimArrayUnpacking(b,this->withdrawnRoutes,withdrawnRoutes_arraysize);
    }
    delete [] this->pathAttributeList;
    b->unpack(pathAttributeList_arraysize);
    if (pathAttributeList_arraysize==0) {
        this->pathAttributeList = 0;
    } else {
        this->pathAttributeList = new BGPUpdatePathAttributeList[pathAttributeList_arraysize];
        doParsimArrayUnpacking(b,this->pathAttributeList,pathAttributeList_arraysize);
    }
    doParsimUnpacking(b,this->NLRI);
}

void BGPUpdateMessage_Base::setWithdrawnRoutesArraySize(unsigned int size)
{
    BGPUpdateWithdrawnRoutes *withdrawnRoutes2 = (size==0) ? nullptr : new BGPUpdateWithdrawnRoutes[size];
    unsigned int sz = withdrawnRoutes_arraysize < size ? withdrawnRoutes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        withdrawnRoutes2[i] = this->withdrawnRoutes[i];
    withdrawnRoutes_arraysize = size;
    delete [] this->withdrawnRoutes;
    this->withdrawnRoutes = withdrawnRoutes2;
}

unsigned int BGPUpdateMessage_Base::getWithdrawnRoutesArraySize() const
{
    return withdrawnRoutes_arraysize;
}

BGPUpdateWithdrawnRoutes& BGPUpdateMessage_Base::getWithdrawnRoutes(unsigned int k)
{
    if (k>=withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", withdrawnRoutes_arraysize, k);
    return this->withdrawnRoutes[k];
}

void BGPUpdateMessage_Base::setWithdrawnRoutes(unsigned int k, const BGPUpdateWithdrawnRoutes& withdrawnRoutes)
{
    if (k>=withdrawnRoutes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", withdrawnRoutes_arraysize, k);
    this->withdrawnRoutes[k] = withdrawnRoutes;
}

void BGPUpdateMessage_Base::setPathAttributeListArraySize(unsigned int size)
{
    BGPUpdatePathAttributeList *pathAttributeList2 = (size==0) ? nullptr : new BGPUpdatePathAttributeList[size];
    unsigned int sz = pathAttributeList_arraysize < size ? pathAttributeList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        pathAttributeList2[i] = this->pathAttributeList[i];
    pathAttributeList_arraysize = size;
    delete [] this->pathAttributeList;
    this->pathAttributeList = pathAttributeList2;
}

unsigned int BGPUpdateMessage_Base::getPathAttributeListArraySize() const
{
    return pathAttributeList_arraysize;
}

BGPUpdatePathAttributeList& BGPUpdateMessage_Base::getPathAttributeList(unsigned int k)
{
    if (k>=pathAttributeList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", pathAttributeList_arraysize, k);
    return this->pathAttributeList[k];
}

void BGPUpdateMessage_Base::setPathAttributeList(unsigned int k, const BGPUpdatePathAttributeList& pathAttributeList)
{
    if (k>=pathAttributeList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", pathAttributeList_arraysize, k);
    this->pathAttributeList[k] = pathAttributeList;
}

BGPUpdateNLRI& BGPUpdateMessage_Base::getNLRI()
{
    return this->NLRI;
}

void BGPUpdateMessage_Base::setNLRI(const BGPUpdateNLRI& NLRI)
{
    this->NLRI = NLRI;
}

class BGPUpdateMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdateMessageDescriptor();
    virtual ~BGPUpdateMessageDescriptor();

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

Register_ClassDescriptor(BGPUpdateMessageDescriptor)

BGPUpdateMessageDescriptor::BGPUpdateMessageDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdateMessage", "inet::bgp::BGPHeader")
{
    propertynames = nullptr;
}

BGPUpdateMessageDescriptor::~BGPUpdateMessageDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdateMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdateMessage_Base *>(obj)!=nullptr;
}

const char **BGPUpdateMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdateMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdateMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int BGPUpdateMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *BGPUpdateMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "withdrawnRoutes",
        "pathAttributeList",
        "NLRI",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int BGPUpdateMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='w' && strcmp(fieldName, "withdrawnRoutes")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathAttributeList")==0) return base+1;
    if (fieldName[0]=='N' && strcmp(fieldName, "NLRI")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdateMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "BGPUpdateWithdrawnRoutes",
        "BGPUpdatePathAttributeList",
        "BGPUpdateNLRI",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdateMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdateMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdateMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateMessage_Base *pp = (BGPUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        case 0: return pp->getWithdrawnRoutesArraySize();
        case 1: return pp->getPathAttributeListArraySize();
        default: return 0;
    }
}

const char *BGPUpdateMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateMessage_Base *pp = (BGPUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdateMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateMessage_Base *pp = (BGPUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getWithdrawnRoutes(i); return out.str();}
        case 1: {std::stringstream out; out << pp->getPathAttributeList(i); return out.str();}
        case 2: {std::stringstream out; out << pp->getNLRI(); return out.str();}
        default: return "";
    }
}

bool BGPUpdateMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateMessage_Base *pp = (BGPUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BGPUpdateMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(BGPUpdateWithdrawnRoutes));
        case 1: return omnetpp::opp_typename(typeid(BGPUpdatePathAttributeList));
        case 2: return omnetpp::opp_typename(typeid(BGPUpdateNLRI));
        default: return nullptr;
    };
}

void *BGPUpdateMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateMessage_Base *pp = (BGPUpdateMessage_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getWithdrawnRoutes(i)); break;
        case 1: return (void *)static_cast<omnetpp::cObject *>(&pp->getPathAttributeList(i)); break;
        case 2: return (void *)(&pp->getNLRI()); break;
        default: return nullptr;
    }
}

} // namespace bgp
} // namespace inet

