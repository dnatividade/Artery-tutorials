//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPUpdatePathAttributes.msg.
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
#include "BGPUpdatePathAttributes_m.h"

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

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::bgp::BGPUpdateAttributeTypeCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::bgp::BGPUpdateAttributeTypeCode"));
    e->insert(ORIGIN, "ORIGIN");
    e->insert(AS_PATH, "AS_PATH");
    e->insert(NEXT_HOP, "NEXT_HOP");
    e->insert(LOCAL_PREF, "LOCAL_PREF");
    e->insert(ATOMIC_AGGREGATE, "ATOMIC_AGGREGATE");
)

BGPUpdateAttributeFlags::BGPUpdateAttributeFlags()
{
    this->optionalBit = false;
    this->transitiveBit = false;
    this->partialBit = false;
    this->estendedLengthBit = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const BGPUpdateAttributeFlags& a)
{
    doParsimPacking(b,a.optionalBit);
    doParsimPacking(b,a.transitiveBit);
    doParsimPacking(b,a.partialBit);
    doParsimPacking(b,a.estendedLengthBit);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BGPUpdateAttributeFlags& a)
{
    doParsimUnpacking(b,a.optionalBit);
    doParsimUnpacking(b,a.transitiveBit);
    doParsimUnpacking(b,a.partialBit);
    doParsimUnpacking(b,a.estendedLengthBit);
}

class BGPUpdateAttributeFlagsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdateAttributeFlagsDescriptor();
    virtual ~BGPUpdateAttributeFlagsDescriptor();

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

Register_ClassDescriptor(BGPUpdateAttributeFlagsDescriptor)

BGPUpdateAttributeFlagsDescriptor::BGPUpdateAttributeFlagsDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdateAttributeFlags", "")
{
    propertynames = nullptr;
}

BGPUpdateAttributeFlagsDescriptor::~BGPUpdateAttributeFlagsDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdateAttributeFlagsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdateAttributeFlags *>(obj)!=nullptr;
}

const char **BGPUpdateAttributeFlagsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdateAttributeFlagsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdateAttributeFlagsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int BGPUpdateAttributeFlagsDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPUpdateAttributeFlagsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "optionalBit",
        "transitiveBit",
        "partialBit",
        "estendedLengthBit",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int BGPUpdateAttributeFlagsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "optionalBit")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transitiveBit")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "partialBit")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "estendedLengthBit")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdateAttributeFlagsDescriptor::getFieldTypeString(int field) const
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
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdateAttributeFlagsDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdateAttributeFlagsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdateAttributeFlagsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeFlags *pp = (BGPUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdateAttributeFlagsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeFlags *pp = (BGPUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdateAttributeFlagsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeFlags *pp = (BGPUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->optionalBit);
        case 1: return bool2string(pp->transitiveBit);
        case 2: return bool2string(pp->partialBit);
        case 3: return bool2string(pp->estendedLengthBit);
        default: return "";
    }
}

bool BGPUpdateAttributeFlagsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeFlags *pp = (BGPUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        case 0: pp->optionalBit = string2bool(value); return true;
        case 1: pp->transitiveBit = string2bool(value); return true;
        case 2: pp->partialBit = string2bool(value); return true;
        case 3: pp->estendedLengthBit = string2bool(value); return true;
        default: return false;
    }
}

const char *BGPUpdateAttributeFlagsDescriptor::getFieldStructName(int field) const
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

void *BGPUpdateAttributeFlagsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeFlags *pp = (BGPUpdateAttributeFlags *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

BGPUpdateAttributeType::BGPUpdateAttributeType()
{
    this->typeCode = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BGPUpdateAttributeType& a)
{
    doParsimPacking(b,a.flags);
    doParsimPacking(b,a.typeCode);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BGPUpdateAttributeType& a)
{
    doParsimUnpacking(b,a.flags);
    doParsimUnpacking(b,a.typeCode);
}

class BGPUpdateAttributeTypeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdateAttributeTypeDescriptor();
    virtual ~BGPUpdateAttributeTypeDescriptor();

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

Register_ClassDescriptor(BGPUpdateAttributeTypeDescriptor)

BGPUpdateAttributeTypeDescriptor::BGPUpdateAttributeTypeDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdateAttributeType", "")
{
    propertynames = nullptr;
}

BGPUpdateAttributeTypeDescriptor::~BGPUpdateAttributeTypeDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdateAttributeTypeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdateAttributeType *>(obj)!=nullptr;
}

const char **BGPUpdateAttributeTypeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdateAttributeTypeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdateAttributeTypeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BGPUpdateAttributeTypeDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPUpdateAttributeTypeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flags",
        "typeCode",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int BGPUpdateAttributeTypeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flags")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "typeCode")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdateAttributeTypeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "BGPUpdateAttributeFlags",
        "unsigned char",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdateAttributeTypeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *BGPUpdateAttributeTypeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "inet::bgp::BGPUpdateAttributeTypeCode";
            return nullptr;
        default: return nullptr;
    }
}

int BGPUpdateAttributeTypeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeType *pp = (BGPUpdateAttributeType *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdateAttributeTypeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeType *pp = (BGPUpdateAttributeType *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdateAttributeTypeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeType *pp = (BGPUpdateAttributeType *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->flags; return out.str();}
        case 1: return enum2string(pp->typeCode, "inet::bgp::BGPUpdateAttributeTypeCode");
        default: return "";
    }
}

bool BGPUpdateAttributeTypeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeType *pp = (BGPUpdateAttributeType *)object; (void)pp;
    switch (field) {
        case 1: pp->typeCode = (inet::bgp::BGPUpdateAttributeTypeCode)string2enum(value, "inet::bgp::BGPUpdateAttributeTypeCode"); return true;
        default: return false;
    }
}

const char *BGPUpdateAttributeTypeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(BGPUpdateAttributeFlags));
        default: return nullptr;
    };
}

void *BGPUpdateAttributeTypeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdateAttributeType *pp = (BGPUpdateAttributeType *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->flags); break;
        default: return nullptr;
    }
}

Register_Class(BGPUpdatePathAttributes)

BGPUpdatePathAttributes::BGPUpdatePathAttributes() : ::omnetpp::cObject()
{
    this->length = 0;
}

BGPUpdatePathAttributes::BGPUpdatePathAttributes(const BGPUpdatePathAttributes& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

BGPUpdatePathAttributes::~BGPUpdatePathAttributes()
{
}

BGPUpdatePathAttributes& BGPUpdatePathAttributes::operator=(const BGPUpdatePathAttributes& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void BGPUpdatePathAttributes::copy(const BGPUpdatePathAttributes& other)
{
    this->type = other.type;
    this->length = other.length;
}

void BGPUpdatePathAttributes::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->length);
}

void BGPUpdatePathAttributes::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->length);
}

BGPUpdateAttributeType& BGPUpdatePathAttributes::getType()
{
    return this->type;
}

void BGPUpdatePathAttributes::setType(const BGPUpdateAttributeType& type)
{
    this->type = type;
}

unsigned short BGPUpdatePathAttributes::getLength() const
{
    return this->length;
}

void BGPUpdatePathAttributes::setLength(unsigned short length)
{
    this->length = length;
}

class BGPUpdatePathAttributesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdatePathAttributesDescriptor();
    virtual ~BGPUpdatePathAttributesDescriptor();

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

Register_ClassDescriptor(BGPUpdatePathAttributesDescriptor)

BGPUpdatePathAttributesDescriptor::BGPUpdatePathAttributesDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdatePathAttributes", "omnetpp::cObject")
{
    propertynames = nullptr;
}

BGPUpdatePathAttributesDescriptor::~BGPUpdatePathAttributesDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdatePathAttributesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdatePathAttributes *>(obj)!=nullptr;
}

const char **BGPUpdatePathAttributesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdatePathAttributesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdatePathAttributesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BGPUpdatePathAttributesDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPUpdatePathAttributesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "length",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int BGPUpdatePathAttributesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdatePathAttributesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "BGPUpdateAttributeType",
        "unsigned short",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdatePathAttributesDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdatePathAttributesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdatePathAttributesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributes *pp = (BGPUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdatePathAttributesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributes *pp = (BGPUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdatePathAttributesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributes *pp = (BGPUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getType(); return out.str();}
        case 1: return ulong2string(pp->getLength());
        default: return "";
    }
}

bool BGPUpdatePathAttributesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributes *pp = (BGPUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        case 1: pp->setLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *BGPUpdatePathAttributesDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(BGPUpdateAttributeType));
        default: return nullptr;
    };
}

void *BGPUpdatePathAttributesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributes *pp = (BGPUpdatePathAttributes *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getType()); break;
        default: return nullptr;
    }
}

Register_Class(BGPUpdatePathAttributesOrigin)

BGPUpdatePathAttributesOrigin::BGPUpdatePathAttributesOrigin() : ::inet::bgp::BGPUpdatePathAttributes()
{
    this->value = 0;
}

BGPUpdatePathAttributesOrigin::BGPUpdatePathAttributesOrigin(const BGPUpdatePathAttributesOrigin& other) : ::inet::bgp::BGPUpdatePathAttributes(other)
{
    copy(other);
}

BGPUpdatePathAttributesOrigin::~BGPUpdatePathAttributesOrigin()
{
}

BGPUpdatePathAttributesOrigin& BGPUpdatePathAttributesOrigin::operator=(const BGPUpdatePathAttributesOrigin& other)
{
    if (this==&other) return *this;
    ::inet::bgp::BGPUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BGPUpdatePathAttributesOrigin::copy(const BGPUpdatePathAttributesOrigin& other)
{
    this->value = other.value;
}

void BGPUpdatePathAttributesOrigin::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BGPUpdatePathAttributesOrigin::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

int BGPUpdatePathAttributesOrigin::getValue() const
{
    return this->value;
}

void BGPUpdatePathAttributesOrigin::setValue(int value)
{
    this->value = value;
}

class BGPUpdatePathAttributesOriginDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdatePathAttributesOriginDescriptor();
    virtual ~BGPUpdatePathAttributesOriginDescriptor();

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

Register_ClassDescriptor(BGPUpdatePathAttributesOriginDescriptor)

BGPUpdatePathAttributesOriginDescriptor::BGPUpdatePathAttributesOriginDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdatePathAttributesOrigin", "inet::bgp::BGPUpdatePathAttributes")
{
    propertynames = nullptr;
}

BGPUpdatePathAttributesOriginDescriptor::~BGPUpdatePathAttributesOriginDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdatePathAttributesOriginDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdatePathAttributesOrigin *>(obj)!=nullptr;
}

const char **BGPUpdatePathAttributesOriginDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdatePathAttributesOriginDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdatePathAttributesOriginDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BGPUpdatePathAttributesOriginDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPUpdatePathAttributesOriginDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int BGPUpdatePathAttributesOriginDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdatePathAttributesOriginDescriptor::getFieldTypeString(int field) const
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

const char **BGPUpdatePathAttributesOriginDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdatePathAttributesOriginDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::bgp::BGPSessionType";
            return nullptr;
        default: return nullptr;
    }
}

int BGPUpdatePathAttributesOriginDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesOrigin *pp = (BGPUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdatePathAttributesOriginDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesOrigin *pp = (BGPUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdatePathAttributesOriginDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesOrigin *pp = (BGPUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getValue(), "inet::bgp::BGPSessionType");
        default: return "";
    }
}

bool BGPUpdatePathAttributesOriginDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesOrigin *pp = (BGPUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        case 0: pp->setValue((inet::bgp::BGPSessionType)string2enum(value, "inet::bgp::BGPSessionType")); return true;
        default: return false;
    }
}

const char *BGPUpdatePathAttributesOriginDescriptor::getFieldStructName(int field) const
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

void *BGPUpdatePathAttributesOriginDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesOrigin *pp = (BGPUpdatePathAttributesOrigin *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(BGPUpdatePathAttributesASPath)

BGPUpdatePathAttributesASPath::BGPUpdatePathAttributesASPath() : ::inet::bgp::BGPUpdatePathAttributes()
{
    value_arraysize = 0;
    this->value = 0;
}

BGPUpdatePathAttributesASPath::BGPUpdatePathAttributesASPath(const BGPUpdatePathAttributesASPath& other) : ::inet::bgp::BGPUpdatePathAttributes(other)
{
    value_arraysize = 0;
    this->value = 0;
    copy(other);
}

BGPUpdatePathAttributesASPath::~BGPUpdatePathAttributesASPath()
{
    delete [] this->value;
}

BGPUpdatePathAttributesASPath& BGPUpdatePathAttributesASPath::operator=(const BGPUpdatePathAttributesASPath& other)
{
    if (this==&other) return *this;
    ::inet::bgp::BGPUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BGPUpdatePathAttributesASPath::copy(const BGPUpdatePathAttributesASPath& other)
{
    delete [] this->value;
    this->value = (other.value_arraysize==0) ? nullptr : new BGPASPathSegment[other.value_arraysize];
    value_arraysize = other.value_arraysize;
    for (unsigned int i=0; i<value_arraysize; i++)
        this->value[i] = other.value[i];
}

void BGPUpdatePathAttributesASPath::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimPack(b);
    b->pack(value_arraysize);
    doParsimArrayPacking(b,this->value,value_arraysize);
}

void BGPUpdatePathAttributesASPath::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimUnpack(b);
    delete [] this->value;
    b->unpack(value_arraysize);
    if (value_arraysize==0) {
        this->value = 0;
    } else {
        this->value = new BGPASPathSegment[value_arraysize];
        doParsimArrayUnpacking(b,this->value,value_arraysize);
    }
}

void BGPUpdatePathAttributesASPath::setValueArraySize(unsigned int size)
{
    BGPASPathSegment *value2 = (size==0) ? nullptr : new BGPASPathSegment[size];
    unsigned int sz = value_arraysize < size ? value_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        value2[i] = this->value[i];
    value_arraysize = size;
    delete [] this->value;
    this->value = value2;
}

unsigned int BGPUpdatePathAttributesASPath::getValueArraySize() const
{
    return value_arraysize;
}

BGPASPathSegment& BGPUpdatePathAttributesASPath::getValue(unsigned int k)
{
    if (k>=value_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", value_arraysize, k);
    return this->value[k];
}

void BGPUpdatePathAttributesASPath::setValue(unsigned int k, const BGPASPathSegment& value)
{
    if (k>=value_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", value_arraysize, k);
    this->value[k] = value;
}

class BGPUpdatePathAttributesASPathDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdatePathAttributesASPathDescriptor();
    virtual ~BGPUpdatePathAttributesASPathDescriptor();

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

Register_ClassDescriptor(BGPUpdatePathAttributesASPathDescriptor)

BGPUpdatePathAttributesASPathDescriptor::BGPUpdatePathAttributesASPathDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdatePathAttributesASPath", "inet::bgp::BGPUpdatePathAttributes")
{
    propertynames = nullptr;
}

BGPUpdatePathAttributesASPathDescriptor::~BGPUpdatePathAttributesASPathDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdatePathAttributesASPathDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdatePathAttributesASPath *>(obj)!=nullptr;
}

const char **BGPUpdatePathAttributesASPathDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdatePathAttributesASPathDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdatePathAttributesASPathDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BGPUpdatePathAttributesASPathDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPUpdatePathAttributesASPathDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int BGPUpdatePathAttributesASPathDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdatePathAttributesASPathDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "BGPASPathSegment",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdatePathAttributesASPathDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdatePathAttributesASPathDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdatePathAttributesASPathDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesASPath *pp = (BGPUpdatePathAttributesASPath *)object; (void)pp;
    switch (field) {
        case 0: return pp->getValueArraySize();
        default: return 0;
    }
}

const char *BGPUpdatePathAttributesASPathDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesASPath *pp = (BGPUpdatePathAttributesASPath *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdatePathAttributesASPathDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesASPath *pp = (BGPUpdatePathAttributesASPath *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getValue(i); return out.str();}
        default: return "";
    }
}

bool BGPUpdatePathAttributesASPathDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesASPath *pp = (BGPUpdatePathAttributesASPath *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BGPUpdatePathAttributesASPathDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(BGPASPathSegment));
        default: return nullptr;
    };
}

void *BGPUpdatePathAttributesASPathDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesASPath *pp = (BGPUpdatePathAttributesASPath *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getValue(i)); break;
        default: return nullptr;
    }
}

Register_Class(BGPUpdatePathAttributesNextHop)

BGPUpdatePathAttributesNextHop::BGPUpdatePathAttributesNextHop() : ::inet::bgp::BGPUpdatePathAttributes()
{
}

BGPUpdatePathAttributesNextHop::BGPUpdatePathAttributesNextHop(const BGPUpdatePathAttributesNextHop& other) : ::inet::bgp::BGPUpdatePathAttributes(other)
{
    copy(other);
}

BGPUpdatePathAttributesNextHop::~BGPUpdatePathAttributesNextHop()
{
}

BGPUpdatePathAttributesNextHop& BGPUpdatePathAttributesNextHop::operator=(const BGPUpdatePathAttributesNextHop& other)
{
    if (this==&other) return *this;
    ::inet::bgp::BGPUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BGPUpdatePathAttributesNextHop::copy(const BGPUpdatePathAttributesNextHop& other)
{
    this->value = other.value;
}

void BGPUpdatePathAttributesNextHop::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BGPUpdatePathAttributesNextHop::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

IPv4Address& BGPUpdatePathAttributesNextHop::getValue()
{
    return this->value;
}

void BGPUpdatePathAttributesNextHop::setValue(const IPv4Address& value)
{
    this->value = value;
}

class BGPUpdatePathAttributesNextHopDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdatePathAttributesNextHopDescriptor();
    virtual ~BGPUpdatePathAttributesNextHopDescriptor();

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

Register_ClassDescriptor(BGPUpdatePathAttributesNextHopDescriptor)

BGPUpdatePathAttributesNextHopDescriptor::BGPUpdatePathAttributesNextHopDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdatePathAttributesNextHop", "inet::bgp::BGPUpdatePathAttributes")
{
    propertynames = nullptr;
}

BGPUpdatePathAttributesNextHopDescriptor::~BGPUpdatePathAttributesNextHopDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdatePathAttributesNextHopDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdatePathAttributesNextHop *>(obj)!=nullptr;
}

const char **BGPUpdatePathAttributesNextHopDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdatePathAttributesNextHopDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdatePathAttributesNextHopDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BGPUpdatePathAttributesNextHopDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPUpdatePathAttributesNextHopDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int BGPUpdatePathAttributesNextHopDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdatePathAttributesNextHopDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPUpdatePathAttributesNextHopDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdatePathAttributesNextHopDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdatePathAttributesNextHopDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesNextHop *pp = (BGPUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdatePathAttributesNextHopDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesNextHop *pp = (BGPUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdatePathAttributesNextHopDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesNextHop *pp = (BGPUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getValue(); return out.str();}
        default: return "";
    }
}

bool BGPUpdatePathAttributesNextHopDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesNextHop *pp = (BGPUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *BGPUpdatePathAttributesNextHopDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *BGPUpdatePathAttributesNextHopDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesNextHop *pp = (BGPUpdatePathAttributesNextHop *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getValue()); break;
        default: return nullptr;
    }
}

Register_Class(BGPUpdatePathAttributesLocalPref)

BGPUpdatePathAttributesLocalPref::BGPUpdatePathAttributesLocalPref() : ::inet::bgp::BGPUpdatePathAttributes()
{
    this->value = 0;
}

BGPUpdatePathAttributesLocalPref::BGPUpdatePathAttributesLocalPref(const BGPUpdatePathAttributesLocalPref& other) : ::inet::bgp::BGPUpdatePathAttributes(other)
{
    copy(other);
}

BGPUpdatePathAttributesLocalPref::~BGPUpdatePathAttributesLocalPref()
{
}

BGPUpdatePathAttributesLocalPref& BGPUpdatePathAttributesLocalPref::operator=(const BGPUpdatePathAttributesLocalPref& other)
{
    if (this==&other) return *this;
    ::inet::bgp::BGPUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BGPUpdatePathAttributesLocalPref::copy(const BGPUpdatePathAttributesLocalPref& other)
{
    this->value = other.value;
}

void BGPUpdatePathAttributesLocalPref::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BGPUpdatePathAttributesLocalPref::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

unsigned int BGPUpdatePathAttributesLocalPref::getValue() const
{
    return this->value;
}

void BGPUpdatePathAttributesLocalPref::setValue(unsigned int value)
{
    this->value = value;
}

class BGPUpdatePathAttributesLocalPrefDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdatePathAttributesLocalPrefDescriptor();
    virtual ~BGPUpdatePathAttributesLocalPrefDescriptor();

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

Register_ClassDescriptor(BGPUpdatePathAttributesLocalPrefDescriptor)

BGPUpdatePathAttributesLocalPrefDescriptor::BGPUpdatePathAttributesLocalPrefDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdatePathAttributesLocalPref", "inet::bgp::BGPUpdatePathAttributes")
{
    propertynames = nullptr;
}

BGPUpdatePathAttributesLocalPrefDescriptor::~BGPUpdatePathAttributesLocalPrefDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdatePathAttributesLocalPrefDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdatePathAttributesLocalPref *>(obj)!=nullptr;
}

const char **BGPUpdatePathAttributesLocalPrefDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdatePathAttributesLocalPrefDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdatePathAttributesLocalPrefDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BGPUpdatePathAttributesLocalPrefDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPUpdatePathAttributesLocalPrefDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int BGPUpdatePathAttributesLocalPrefDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdatePathAttributesLocalPrefDescriptor::getFieldTypeString(int field) const
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

const char **BGPUpdatePathAttributesLocalPrefDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdatePathAttributesLocalPrefDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPUpdatePathAttributesLocalPrefDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesLocalPref *pp = (BGPUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdatePathAttributesLocalPrefDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesLocalPref *pp = (BGPUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdatePathAttributesLocalPrefDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesLocalPref *pp = (BGPUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getValue());
        default: return "";
    }
}

bool BGPUpdatePathAttributesLocalPrefDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesLocalPref *pp = (BGPUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        case 0: pp->setValue(string2ulong(value)); return true;
        default: return false;
    }
}

const char *BGPUpdatePathAttributesLocalPrefDescriptor::getFieldStructName(int field) const
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

void *BGPUpdatePathAttributesLocalPrefDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesLocalPref *pp = (BGPUpdatePathAttributesLocalPref *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::bgp::BGPUpdateAtomicAggregateValues");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::bgp::BGPUpdateAtomicAggregateValues"));
    e->insert(NO_SPECIFIC_ROUTE, "NO_SPECIFIC_ROUTE");
    e->insert(SPECIFIC_ROUTE, "SPECIFIC_ROUTE");
)

Register_Class(BGPUpdatePathAttributesAtomicAggregate)

BGPUpdatePathAttributesAtomicAggregate::BGPUpdatePathAttributesAtomicAggregate() : ::inet::bgp::BGPUpdatePathAttributes()
{
    this->value = 0;
}

BGPUpdatePathAttributesAtomicAggregate::BGPUpdatePathAttributesAtomicAggregate(const BGPUpdatePathAttributesAtomicAggregate& other) : ::inet::bgp::BGPUpdatePathAttributes(other)
{
    copy(other);
}

BGPUpdatePathAttributesAtomicAggregate::~BGPUpdatePathAttributesAtomicAggregate()
{
}

BGPUpdatePathAttributesAtomicAggregate& BGPUpdatePathAttributesAtomicAggregate::operator=(const BGPUpdatePathAttributesAtomicAggregate& other)
{
    if (this==&other) return *this;
    ::inet::bgp::BGPUpdatePathAttributes::operator=(other);
    copy(other);
    return *this;
}

void BGPUpdatePathAttributesAtomicAggregate::copy(const BGPUpdatePathAttributesAtomicAggregate& other)
{
    this->value = other.value;
}

void BGPUpdatePathAttributesAtomicAggregate::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimPack(b);
    doParsimPacking(b,this->value);
}

void BGPUpdatePathAttributesAtomicAggregate::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BGPUpdatePathAttributes::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

int BGPUpdatePathAttributesAtomicAggregate::getValue() const
{
    return this->value;
}

void BGPUpdatePathAttributesAtomicAggregate::setValue(int value)
{
    this->value = value;
}

class BGPUpdatePathAttributesAtomicAggregateDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPUpdatePathAttributesAtomicAggregateDescriptor();
    virtual ~BGPUpdatePathAttributesAtomicAggregateDescriptor();

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

Register_ClassDescriptor(BGPUpdatePathAttributesAtomicAggregateDescriptor)

BGPUpdatePathAttributesAtomicAggregateDescriptor::BGPUpdatePathAttributesAtomicAggregateDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPUpdatePathAttributesAtomicAggregate", "inet::bgp::BGPUpdatePathAttributes")
{
    propertynames = nullptr;
}

BGPUpdatePathAttributesAtomicAggregateDescriptor::~BGPUpdatePathAttributesAtomicAggregateDescriptor()
{
    delete[] propertynames;
}

bool BGPUpdatePathAttributesAtomicAggregateDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPUpdatePathAttributesAtomicAggregate *>(obj)!=nullptr;
}

const char **BGPUpdatePathAttributesAtomicAggregateDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPUpdatePathAttributesAtomicAggregateDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "value",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int BGPUpdatePathAttributesAtomicAggregateDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldTypeString(int field) const
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

const char **BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::bgp::BGPUpdateAtomicAggregateValues";
            return nullptr;
        default: return nullptr;
    }
}

int BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesAtomicAggregate *pp = (BGPUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesAtomicAggregate *pp = (BGPUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesAtomicAggregate *pp = (BGPUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getValue(), "inet::bgp::BGPUpdateAtomicAggregateValues");
        default: return "";
    }
}

bool BGPUpdatePathAttributesAtomicAggregateDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesAtomicAggregate *pp = (BGPUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        case 0: pp->setValue((inet::bgp::BGPUpdateAtomicAggregateValues)string2enum(value, "inet::bgp::BGPUpdateAtomicAggregateValues")); return true;
        default: return false;
    }
}

const char *BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldStructName(int field) const
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

void *BGPUpdatePathAttributesAtomicAggregateDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPUpdatePathAttributesAtomicAggregate *pp = (BGPUpdatePathAttributesAtomicAggregate *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace bgp
} // namespace inet

