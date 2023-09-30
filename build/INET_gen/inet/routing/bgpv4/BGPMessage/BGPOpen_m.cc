//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPOpen.msg.
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
#include "BGPOpen_m.h"

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

BGPParameterValues::BGPParameterValues()
{
    this->authCode = 0;
    this->authenticationData = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BGPParameterValues& a)
{
    doParsimPacking(b,a.authCode);
    doParsimPacking(b,a.authenticationData);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BGPParameterValues& a)
{
    doParsimUnpacking(b,a.authCode);
    doParsimUnpacking(b,a.authenticationData);
}

class BGPParameterValuesDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPParameterValuesDescriptor();
    virtual ~BGPParameterValuesDescriptor();

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

Register_ClassDescriptor(BGPParameterValuesDescriptor)

BGPParameterValuesDescriptor::BGPParameterValuesDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPParameterValues", "")
{
    propertynames = nullptr;
}

BGPParameterValuesDescriptor::~BGPParameterValuesDescriptor()
{
    delete[] propertynames;
}

bool BGPParameterValuesDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPParameterValues *>(obj)!=nullptr;
}

const char **BGPParameterValuesDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPParameterValuesDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPParameterValuesDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int BGPParameterValuesDescriptor::getFieldTypeFlags(int field) const
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

const char *BGPParameterValuesDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "authCode",
        "authenticationData",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int BGPParameterValuesDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "authCode")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "authenticationData")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPParameterValuesDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "long",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPParameterValuesDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPParameterValuesDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPParameterValuesDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPParameterValues *pp = (BGPParameterValues *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPParameterValuesDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPParameterValues *pp = (BGPParameterValues *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPParameterValuesDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPParameterValues *pp = (BGPParameterValues *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->authCode);
        case 1: return long2string(pp->authenticationData);
        default: return "";
    }
}

bool BGPParameterValuesDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPParameterValues *pp = (BGPParameterValues *)object; (void)pp;
    switch (field) {
        case 0: pp->authCode = string2long(value); return true;
        case 1: pp->authenticationData = string2long(value); return true;
        default: return false;
    }
}

const char *BGPParameterValuesDescriptor::getFieldStructName(int field) const
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

void *BGPParameterValuesDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPParameterValues *pp = (BGPParameterValues *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

BGPOptionalParameters::BGPOptionalParameters()
{
    this->parameterType = 0;
    this->parameterLength = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const BGPOptionalParameters& a)
{
    doParsimPacking(b,a.parameterType);
    doParsimPacking(b,a.parameterLength);
    doParsimPacking(b,a.parameterValues);
}

void __doUnpacking(omnetpp::cCommBuffer *b, BGPOptionalParameters& a)
{
    doParsimUnpacking(b,a.parameterType);
    doParsimUnpacking(b,a.parameterLength);
    doParsimUnpacking(b,a.parameterValues);
}

class BGPOptionalParametersDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPOptionalParametersDescriptor();
    virtual ~BGPOptionalParametersDescriptor();

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

Register_ClassDescriptor(BGPOptionalParametersDescriptor)

BGPOptionalParametersDescriptor::BGPOptionalParametersDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPOptionalParameters", "")
{
    propertynames = nullptr;
}

BGPOptionalParametersDescriptor::~BGPOptionalParametersDescriptor()
{
    delete[] propertynames;
}

bool BGPOptionalParametersDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPOptionalParameters *>(obj)!=nullptr;
}

const char **BGPOptionalParametersDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPOptionalParametersDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPOptionalParametersDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int BGPOptionalParametersDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *BGPOptionalParametersDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameterType",
        "parameterLength",
        "parameterValues",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int BGPOptionalParametersDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameterType")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameterLength")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameterValues")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPOptionalParametersDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "unsigned short",
        "BGPParameterValues",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPOptionalParametersDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPOptionalParametersDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPOptionalParametersDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPOptionalParameters *pp = (BGPOptionalParameters *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BGPOptionalParametersDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPOptionalParameters *pp = (BGPOptionalParameters *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPOptionalParametersDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPOptionalParameters *pp = (BGPOptionalParameters *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->parameterType);
        case 1: return ulong2string(pp->parameterLength);
        case 2: {std::stringstream out; out << pp->parameterValues; return out.str();}
        default: return "";
    }
}

bool BGPOptionalParametersDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPOptionalParameters *pp = (BGPOptionalParameters *)object; (void)pp;
    switch (field) {
        case 0: pp->parameterType = string2long(value); return true;
        case 1: pp->parameterLength = string2ulong(value); return true;
        default: return false;
    }
}

const char *BGPOptionalParametersDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(BGPParameterValues));
        default: return nullptr;
    };
}

void *BGPOptionalParametersDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPOptionalParameters *pp = (BGPOptionalParameters *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->parameterValues); break;
        default: return nullptr;
    }
}

Register_Class(BGPOpenMessage)

BGPOpenMessage::BGPOpenMessage(const char *name, short kind) : ::inet::bgp::BGPHeader(name,kind)
{
    this->setType(BGP_OPEN);
    this->setByteLength(BGP_HEADER_OCTETS + BGP_OPEN_OCTETS);

    this->version_var = 4;
    this->myAS_var = 0;
    this->holdTime_var = 0;
    optionalParameters_arraysize = 0;
    this->optionalParameters_var = 0;
}

BGPOpenMessage::BGPOpenMessage(const BGPOpenMessage& other) : ::inet::bgp::BGPHeader(other)
{
    optionalParameters_arraysize = 0;
    this->optionalParameters_var = 0;
    copy(other);
}

BGPOpenMessage::~BGPOpenMessage()
{
    delete [] this->optionalParameters_var;
}

BGPOpenMessage& BGPOpenMessage::operator=(const BGPOpenMessage& other)
{
    if (this==&other) return *this;
    ::inet::bgp::BGPHeader::operator=(other);
    copy(other);
    return *this;
}

void BGPOpenMessage::copy(const BGPOpenMessage& other)
{
    this->version_var = other.version_var;
    this->myAS_var = other.myAS_var;
    this->holdTime_var = other.holdTime_var;
    this->BGPIdentifier_var = other.BGPIdentifier_var;
    delete [] this->optionalParameters_var;
    this->optionalParameters_var = (other.optionalParameters_arraysize==0) ? nullptr : new BGPOptionalParameters[other.optionalParameters_arraysize];
    optionalParameters_arraysize = other.optionalParameters_arraysize;
    for (unsigned int i=0; i<optionalParameters_arraysize; i++)
        this->optionalParameters_var[i] = other.optionalParameters_var[i];
}

void BGPOpenMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::bgp::BGPHeader::parsimPack(b);
    doParsimPacking(b,this->version_var);
    doParsimPacking(b,this->myAS_var);
    doParsimPacking(b,this->holdTime_var);
    doParsimPacking(b,this->BGPIdentifier_var);
    b->pack(optionalParameters_arraysize);
    doParsimArrayPacking(b,this->optionalParameters_var,optionalParameters_arraysize);
}

void BGPOpenMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::bgp::BGPHeader::parsimUnpack(b);
    doParsimUnpacking(b,this->version_var);
    doParsimUnpacking(b,this->myAS_var);
    doParsimUnpacking(b,this->holdTime_var);
    doParsimUnpacking(b,this->BGPIdentifier_var);
    delete [] this->optionalParameters_var;
    b->unpack(optionalParameters_arraysize);
    if (optionalParameters_arraysize==0) {
        this->optionalParameters_var = 0;
    } else {
        this->optionalParameters_var = new BGPOptionalParameters[optionalParameters_arraysize];
        doParsimArrayUnpacking(b,this->optionalParameters_var,optionalParameters_arraysize);
    }
}

char BGPOpenMessage::version() const
{
    return this->version_var;
}

void BGPOpenMessage::setVersion(char version)
{
    this->version_var = version;
}

unsigned short BGPOpenMessage::myAS() const
{
    return this->myAS_var;
}

void BGPOpenMessage::setMyAS(unsigned short myAS)
{
    this->myAS_var = myAS;
}

::omnetpp::simtime_t BGPOpenMessage::holdTime() const
{
    return this->holdTime_var;
}

void BGPOpenMessage::setHoldTime(::omnetpp::simtime_t holdTime)
{
    this->holdTime_var = holdTime;
}

IPv4Address& BGPOpenMessage::BGPIdentifier()
{
    return this->BGPIdentifier_var;
}

void BGPOpenMessage::setBGPIdentifier(const IPv4Address& BGPIdentifier)
{
    this->BGPIdentifier_var = BGPIdentifier;
}

void BGPOpenMessage::setOptionalParametersArraySize(unsigned int size)
{
    BGPOptionalParameters *optionalParameters_var2 = (size==0) ? nullptr : new BGPOptionalParameters[size];
    unsigned int sz = optionalParameters_arraysize < size ? optionalParameters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        optionalParameters_var2[i] = this->optionalParameters_var[i];
    optionalParameters_arraysize = size;
    delete [] this->optionalParameters_var;
    this->optionalParameters_var = optionalParameters_var2;
}

unsigned int BGPOpenMessage::optionalParametersArraySize() const
{
    return optionalParameters_arraysize;
}

BGPOptionalParameters& BGPOpenMessage::optionalParameters(unsigned int k)
{
    if (k>=optionalParameters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", optionalParameters_arraysize, k);
    return this->optionalParameters_var[k];
}

void BGPOpenMessage::setOptionalParameters(unsigned int k, const BGPOptionalParameters& optionalParameters)
{
    if (k>=optionalParameters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", optionalParameters_arraysize, k);
    this->optionalParameters_var[k] = optionalParameters;
}

class BGPOpenMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BGPOpenMessageDescriptor();
    virtual ~BGPOpenMessageDescriptor();

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

Register_ClassDescriptor(BGPOpenMessageDescriptor)

BGPOpenMessageDescriptor::BGPOpenMessageDescriptor() : omnetpp::cClassDescriptor("inet::bgp::BGPOpenMessage", "inet::bgp::BGPHeader")
{
    propertynames = nullptr;
}

BGPOpenMessageDescriptor::~BGPOpenMessageDescriptor()
{
    delete[] propertynames;
}

bool BGPOpenMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BGPOpenMessage *>(obj)!=nullptr;
}

const char **BGPOpenMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "fieldNameSuffix", "omitGetVerb",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BGPOpenMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"fieldNameSuffix")) return "_var";
    if (!strcmp(propertyname,"omitGetVerb")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BGPOpenMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int BGPOpenMessageDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *BGPOpenMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "myAS",
        "holdTime",
        "BGPIdentifier",
        "optionalParameters",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int BGPOpenMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "myAS")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+2;
    if (fieldName[0]=='B' && strcmp(fieldName, "BGPIdentifier")==0) return base+3;
    if (fieldName[0]=='o' && strcmp(fieldName, "optionalParameters")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BGPOpenMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "unsigned short",
        "simtime_t",
        "IPv4Address",
        "BGPOptionalParameters",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **BGPOpenMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *BGPOpenMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BGPOpenMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BGPOpenMessage *pp = (BGPOpenMessage *)object; (void)pp;
    switch (field) {
        case 4: return pp->optionalParametersArraySize();
        default: return 0;
    }
}

const char *BGPOpenMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPOpenMessage *pp = (BGPOpenMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BGPOpenMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BGPOpenMessage *pp = (BGPOpenMessage *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->version());
        case 1: return ulong2string(pp->myAS());
        case 2: return simtime2string(pp->holdTime());
        case 3: {std::stringstream out; out << pp->BGPIdentifier(); return out.str();}
        case 4: {std::stringstream out; out << pp->optionalParameters(i); return out.str();}
        default: return "";
    }
}

bool BGPOpenMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BGPOpenMessage *pp = (BGPOpenMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2long(value)); return true;
        case 1: pp->setMyAS(string2ulong(value)); return true;
        case 2: pp->setHoldTime(string2simtime(value)); return true;
        default: return false;
    }
}

const char *BGPOpenMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        case 4: return omnetpp::opp_typename(typeid(BGPOptionalParameters));
        default: return nullptr;
    };
}

void *BGPOpenMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BGPOpenMessage *pp = (BGPOpenMessage *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->BGPIdentifier()); break;
        case 4: return (void *)(&pp->optionalParameters(i)); break;
        default: return nullptr;
    }
}

} // namespace bgp
} // namespace inet

