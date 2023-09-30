//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/ipv4/IPv4Datagram.msg.
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
#include "IPv4Datagram_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IPOptionClass");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IPOptionClass"));
    e->insert(IPOPTION_CLASS_CONTROL, "IPOPTION_CLASS_CONTROL");
    e->insert(IPOPTION_CLASS_RESERVED, "IPOPTION_CLASS_RESERVED");
    e->insert(IPOPTION_CLASS_DEBUGGING, "IPOPTION_CLASS_DEBUGGING");
    e->insert(IPOPTION_CLASS_RESERVED2, "IPOPTION_CLASS_RESERVED2");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IPOption");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IPOption"));
    e->insert(IPOPTION_END_OF_OPTIONS, "IPOPTION_END_OF_OPTIONS");
    e->insert(IPOPTION_NO_OPTION, "IPOPTION_NO_OPTION");
    e->insert(IPOPTION_STREAM_ID, "IPOPTION_STREAM_ID");
    e->insert(IPOPTION_TIMESTAMP, "IPOPTION_TIMESTAMP");
    e->insert(IPOPTION_SECURITY, "IPOPTION_SECURITY");
    e->insert(IPOPTION_LOOSE_SOURCE_ROUTING, "IPOPTION_LOOSE_SOURCE_ROUTING");
    e->insert(IPOPTION_RECORD_ROUTE, "IPOPTION_RECORD_ROUTE");
    e->insert(IPOPTION_STRICT_SOURCE_ROUTING, "IPOPTION_STRICT_SOURCE_ROUTING");
    e->insert(IPOPTION_ROUTER_ALERT, "IPOPTION_ROUTER_ALERT");
    e->insert(IPOPTION_TLV_GPSR, "IPOPTION_TLV_GPSR");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TimestampFlag");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TimestampFlag"));
    e->insert(IP_TIMESTAMP_TIMESTAMP_ONLY, "IP_TIMESTAMP_TIMESTAMP_ONLY");
    e->insert(IP_TIMESTAMP_WITH_ADDRESS, "IP_TIMESTAMP_WITH_ADDRESS");
    e->insert(IP_TIMESTAMP_SENDER_INIT_ADDRESS, "IP_TIMESTAMP_SENDER_INIT_ADDRESS");
)

IPv4Option::IPv4Option() : ::inet::TLVOptionBase()
{
}

IPv4Option::IPv4Option(const IPv4Option& other) : ::inet::TLVOptionBase(other)
{
    copy(other);
}

IPv4Option::~IPv4Option()
{
}

IPv4Option& IPv4Option::operator=(const IPv4Option& other)
{
    if (this==&other) return *this;
    ::inet::TLVOptionBase::operator=(other);
    copy(other);
    return *this;
}

void IPv4Option::copy(const IPv4Option& other)
{
}

void IPv4Option::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::TLVOptionBase&)*this);
}

void IPv4Option::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::TLVOptionBase&)*this);
}

class IPv4OptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4OptionDescriptor();
    virtual ~IPv4OptionDescriptor();

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

Register_ClassDescriptor(IPv4OptionDescriptor)

IPv4OptionDescriptor::IPv4OptionDescriptor() : omnetpp::cClassDescriptor("inet::IPv4Option", "inet::TLVOptionBase")
{
    propertynames = nullptr;
}

IPv4OptionDescriptor::~IPv4OptionDescriptor()
{
    delete[] propertynames;
}

bool IPv4OptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4Option *>(obj)!=nullptr;
}

const char **IPv4OptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4OptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4OptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int IPv4OptionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *IPv4OptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int IPv4OptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4OptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **IPv4OptionDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4OptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv4OptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4Option *pp = (IPv4Option *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv4OptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4Option *pp = (IPv4Option *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4OptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4Option *pp = (IPv4Option *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool IPv4OptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4Option *pp = (IPv4Option *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv4OptionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *IPv4OptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4Option *pp = (IPv4Option *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

IPv4OptionNop::IPv4OptionNop() : ::inet::IPv4Option()
{
    this->setType(IPOPTION_NO_OPTION);
    this->setLength(1);
}

IPv4OptionNop::IPv4OptionNop(const IPv4OptionNop& other) : ::inet::IPv4Option(other)
{
    copy(other);
}

IPv4OptionNop::~IPv4OptionNop()
{
}

IPv4OptionNop& IPv4OptionNop::operator=(const IPv4OptionNop& other)
{
    if (this==&other) return *this;
    ::inet::IPv4Option::operator=(other);
    copy(other);
    return *this;
}

void IPv4OptionNop::copy(const IPv4OptionNop& other)
{
}

void IPv4OptionNop::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv4Option&)*this);
}

void IPv4OptionNop::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv4Option&)*this);
}

class IPv4OptionNopDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4OptionNopDescriptor();
    virtual ~IPv4OptionNopDescriptor();

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

Register_ClassDescriptor(IPv4OptionNopDescriptor)

IPv4OptionNopDescriptor::IPv4OptionNopDescriptor() : omnetpp::cClassDescriptor("inet::IPv4OptionNop", "inet::IPv4Option")
{
    propertynames = nullptr;
}

IPv4OptionNopDescriptor::~IPv4OptionNopDescriptor()
{
    delete[] propertynames;
}

bool IPv4OptionNopDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4OptionNop *>(obj)!=nullptr;
}

const char **IPv4OptionNopDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4OptionNopDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4OptionNopDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int IPv4OptionNopDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *IPv4OptionNopDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int IPv4OptionNopDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4OptionNopDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **IPv4OptionNopDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4OptionNopDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv4OptionNopDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionNop *pp = (IPv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv4OptionNopDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionNop *pp = (IPv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4OptionNopDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionNop *pp = (IPv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool IPv4OptionNopDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionNop *pp = (IPv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv4OptionNopDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *IPv4OptionNopDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionNop *pp = (IPv4OptionNop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

IPv4OptionEnd::IPv4OptionEnd() : ::inet::IPv4Option()
{
    this->setType(IPOPTION_END_OF_OPTIONS);
    this->setLength(1);
}

IPv4OptionEnd::IPv4OptionEnd(const IPv4OptionEnd& other) : ::inet::IPv4Option(other)
{
    copy(other);
}

IPv4OptionEnd::~IPv4OptionEnd()
{
}

IPv4OptionEnd& IPv4OptionEnd::operator=(const IPv4OptionEnd& other)
{
    if (this==&other) return *this;
    ::inet::IPv4Option::operator=(other);
    copy(other);
    return *this;
}

void IPv4OptionEnd::copy(const IPv4OptionEnd& other)
{
}

void IPv4OptionEnd::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv4Option&)*this);
}

void IPv4OptionEnd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv4Option&)*this);
}

class IPv4OptionEndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4OptionEndDescriptor();
    virtual ~IPv4OptionEndDescriptor();

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

Register_ClassDescriptor(IPv4OptionEndDescriptor)

IPv4OptionEndDescriptor::IPv4OptionEndDescriptor() : omnetpp::cClassDescriptor("inet::IPv4OptionEnd", "inet::IPv4Option")
{
    propertynames = nullptr;
}

IPv4OptionEndDescriptor::~IPv4OptionEndDescriptor()
{
    delete[] propertynames;
}

bool IPv4OptionEndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4OptionEnd *>(obj)!=nullptr;
}

const char **IPv4OptionEndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4OptionEndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4OptionEndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int IPv4OptionEndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *IPv4OptionEndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int IPv4OptionEndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4OptionEndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **IPv4OptionEndDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4OptionEndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv4OptionEndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionEnd *pp = (IPv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv4OptionEndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionEnd *pp = (IPv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4OptionEndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionEnd *pp = (IPv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool IPv4OptionEndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionEnd *pp = (IPv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv4OptionEndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *IPv4OptionEndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionEnd *pp = (IPv4OptionEnd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

IPv4OptionRecordRoute::IPv4OptionRecordRoute() : ::inet::IPv4Option()
{
    this->nextAddressIdx = 0;
    recordAddress_arraysize = 0;
    this->recordAddress = 0;
}

IPv4OptionRecordRoute::IPv4OptionRecordRoute(const IPv4OptionRecordRoute& other) : ::inet::IPv4Option(other)
{
    recordAddress_arraysize = 0;
    this->recordAddress = 0;
    copy(other);
}

IPv4OptionRecordRoute::~IPv4OptionRecordRoute()
{
    delete [] this->recordAddress;
}

IPv4OptionRecordRoute& IPv4OptionRecordRoute::operator=(const IPv4OptionRecordRoute& other)
{
    if (this==&other) return *this;
    ::inet::IPv4Option::operator=(other);
    copy(other);
    return *this;
}

void IPv4OptionRecordRoute::copy(const IPv4OptionRecordRoute& other)
{
    this->nextAddressIdx = other.nextAddressIdx;
    delete [] this->recordAddress;
    this->recordAddress = (other.recordAddress_arraysize==0) ? nullptr : new IPv4Address[other.recordAddress_arraysize];
    recordAddress_arraysize = other.recordAddress_arraysize;
    for (unsigned int i=0; i<recordAddress_arraysize; i++)
        this->recordAddress[i] = other.recordAddress[i];
}

void IPv4OptionRecordRoute::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv4Option&)*this);
    doParsimPacking(b,this->nextAddressIdx);
    b->pack(recordAddress_arraysize);
    doParsimArrayPacking(b,this->recordAddress,recordAddress_arraysize);
}

void IPv4OptionRecordRoute::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv4Option&)*this);
    doParsimUnpacking(b,this->nextAddressIdx);
    delete [] this->recordAddress;
    b->unpack(recordAddress_arraysize);
    if (recordAddress_arraysize==0) {
        this->recordAddress = 0;
    } else {
        this->recordAddress = new IPv4Address[recordAddress_arraysize];
        doParsimArrayUnpacking(b,this->recordAddress,recordAddress_arraysize);
    }
}

short IPv4OptionRecordRoute::getNextAddressIdx() const
{
    return this->nextAddressIdx;
}

void IPv4OptionRecordRoute::setNextAddressIdx(short nextAddressIdx)
{
    this->nextAddressIdx = nextAddressIdx;
}

void IPv4OptionRecordRoute::setRecordAddressArraySize(unsigned int size)
{
    IPv4Address *recordAddress2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = recordAddress_arraysize < size ? recordAddress_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        recordAddress2[i] = this->recordAddress[i];
    recordAddress_arraysize = size;
    delete [] this->recordAddress;
    this->recordAddress = recordAddress2;
}

unsigned int IPv4OptionRecordRoute::getRecordAddressArraySize() const
{
    return recordAddress_arraysize;
}

IPv4Address& IPv4OptionRecordRoute::getRecordAddress(unsigned int k)
{
    if (k>=recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", recordAddress_arraysize, k);
    return this->recordAddress[k];
}

void IPv4OptionRecordRoute::setRecordAddress(unsigned int k, const IPv4Address& recordAddress)
{
    if (k>=recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", recordAddress_arraysize, k);
    this->recordAddress[k] = recordAddress;
}

class IPv4OptionRecordRouteDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4OptionRecordRouteDescriptor();
    virtual ~IPv4OptionRecordRouteDescriptor();

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

Register_ClassDescriptor(IPv4OptionRecordRouteDescriptor)

IPv4OptionRecordRouteDescriptor::IPv4OptionRecordRouteDescriptor() : omnetpp::cClassDescriptor("inet::IPv4OptionRecordRoute", "inet::IPv4Option")
{
    propertynames = nullptr;
}

IPv4OptionRecordRouteDescriptor::~IPv4OptionRecordRouteDescriptor()
{
    delete[] propertynames;
}

bool IPv4OptionRecordRouteDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4OptionRecordRoute *>(obj)!=nullptr;
}

const char **IPv4OptionRecordRouteDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4OptionRecordRouteDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4OptionRecordRouteDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int IPv4OptionRecordRouteDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *IPv4OptionRecordRouteDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nextAddressIdx",
        "recordAddress",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int IPv4OptionRecordRouteDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextAddressIdx")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "recordAddress")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4OptionRecordRouteDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "IPv4Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv4OptionRecordRouteDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4OptionRecordRouteDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv4OptionRecordRouteDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionRecordRoute *pp = (IPv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        case 1: return pp->getRecordAddressArraySize();
        default: return 0;
    }
}

const char *IPv4OptionRecordRouteDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionRecordRoute *pp = (IPv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4OptionRecordRouteDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionRecordRoute *pp = (IPv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getNextAddressIdx());
        case 1: {std::stringstream out; out << pp->getRecordAddress(i); return out.str();}
        default: return "";
    }
}

bool IPv4OptionRecordRouteDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionRecordRoute *pp = (IPv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        case 0: pp->setNextAddressIdx(string2long(value)); return true;
        default: return false;
    }
}

const char *IPv4OptionRecordRouteDescriptor::getFieldStructName(int field) const
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

void *IPv4OptionRecordRouteDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionRecordRoute *pp = (IPv4OptionRecordRoute *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getRecordAddress(i)); break;
        default: return nullptr;
    }
}

IPv4OptionTimestamp::IPv4OptionTimestamp() : ::inet::IPv4Option()
{
    this->setType(IPOPTION_TIMESTAMP);

    this->flag = 0;
    this->overflow = 0;
    this->nextIdx = 0;
    recordAddress_arraysize = 0;
    this->recordAddress = 0;
    recordTimestamp_arraysize = 0;
    this->recordTimestamp = 0;
}

IPv4OptionTimestamp::IPv4OptionTimestamp(const IPv4OptionTimestamp& other) : ::inet::IPv4Option(other)
{
    recordAddress_arraysize = 0;
    this->recordAddress = 0;
    recordTimestamp_arraysize = 0;
    this->recordTimestamp = 0;
    copy(other);
}

IPv4OptionTimestamp::~IPv4OptionTimestamp()
{
    delete [] this->recordAddress;
    delete [] this->recordTimestamp;
}

IPv4OptionTimestamp& IPv4OptionTimestamp::operator=(const IPv4OptionTimestamp& other)
{
    if (this==&other) return *this;
    ::inet::IPv4Option::operator=(other);
    copy(other);
    return *this;
}

void IPv4OptionTimestamp::copy(const IPv4OptionTimestamp& other)
{
    this->flag = other.flag;
    this->overflow = other.overflow;
    this->nextIdx = other.nextIdx;
    delete [] this->recordAddress;
    this->recordAddress = (other.recordAddress_arraysize==0) ? nullptr : new IPv4Address[other.recordAddress_arraysize];
    recordAddress_arraysize = other.recordAddress_arraysize;
    for (unsigned int i=0; i<recordAddress_arraysize; i++)
        this->recordAddress[i] = other.recordAddress[i];
    delete [] this->recordTimestamp;
    this->recordTimestamp = (other.recordTimestamp_arraysize==0) ? nullptr : new ::omnetpp::simtime_t[other.recordTimestamp_arraysize];
    recordTimestamp_arraysize = other.recordTimestamp_arraysize;
    for (unsigned int i=0; i<recordTimestamp_arraysize; i++)
        this->recordTimestamp[i] = other.recordTimestamp[i];
}

void IPv4OptionTimestamp::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv4Option&)*this);
    doParsimPacking(b,this->flag);
    doParsimPacking(b,this->overflow);
    doParsimPacking(b,this->nextIdx);
    b->pack(recordAddress_arraysize);
    doParsimArrayPacking(b,this->recordAddress,recordAddress_arraysize);
    b->pack(recordTimestamp_arraysize);
    doParsimArrayPacking(b,this->recordTimestamp,recordTimestamp_arraysize);
}

void IPv4OptionTimestamp::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv4Option&)*this);
    doParsimUnpacking(b,this->flag);
    doParsimUnpacking(b,this->overflow);
    doParsimUnpacking(b,this->nextIdx);
    delete [] this->recordAddress;
    b->unpack(recordAddress_arraysize);
    if (recordAddress_arraysize==0) {
        this->recordAddress = 0;
    } else {
        this->recordAddress = new IPv4Address[recordAddress_arraysize];
        doParsimArrayUnpacking(b,this->recordAddress,recordAddress_arraysize);
    }
    delete [] this->recordTimestamp;
    b->unpack(recordTimestamp_arraysize);
    if (recordTimestamp_arraysize==0) {
        this->recordTimestamp = 0;
    } else {
        this->recordTimestamp = new ::omnetpp::simtime_t[recordTimestamp_arraysize];
        doParsimArrayUnpacking(b,this->recordTimestamp,recordTimestamp_arraysize);
    }
}

int IPv4OptionTimestamp::getFlag() const
{
    return this->flag;
}

void IPv4OptionTimestamp::setFlag(int flag)
{
    this->flag = flag;
}

short IPv4OptionTimestamp::getOverflow() const
{
    return this->overflow;
}

void IPv4OptionTimestamp::setOverflow(short overflow)
{
    this->overflow = overflow;
}

short IPv4OptionTimestamp::getNextIdx() const
{
    return this->nextIdx;
}

void IPv4OptionTimestamp::setNextIdx(short nextIdx)
{
    this->nextIdx = nextIdx;
}

void IPv4OptionTimestamp::setRecordAddressArraySize(unsigned int size)
{
    IPv4Address *recordAddress2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = recordAddress_arraysize < size ? recordAddress_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        recordAddress2[i] = this->recordAddress[i];
    recordAddress_arraysize = size;
    delete [] this->recordAddress;
    this->recordAddress = recordAddress2;
}

unsigned int IPv4OptionTimestamp::getRecordAddressArraySize() const
{
    return recordAddress_arraysize;
}

IPv4Address& IPv4OptionTimestamp::getRecordAddress(unsigned int k)
{
    if (k>=recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", recordAddress_arraysize, k);
    return this->recordAddress[k];
}

void IPv4OptionTimestamp::setRecordAddress(unsigned int k, const IPv4Address& recordAddress)
{
    if (k>=recordAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", recordAddress_arraysize, k);
    this->recordAddress[k] = recordAddress;
}

void IPv4OptionTimestamp::setRecordTimestampArraySize(unsigned int size)
{
    ::omnetpp::simtime_t *recordTimestamp2 = (size==0) ? nullptr : new ::omnetpp::simtime_t[size];
    unsigned int sz = recordTimestamp_arraysize < size ? recordTimestamp_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        recordTimestamp2[i] = this->recordTimestamp[i];
    for (unsigned int i=sz; i<size; i++)
        recordTimestamp2[i] = 0;
    recordTimestamp_arraysize = size;
    delete [] this->recordTimestamp;
    this->recordTimestamp = recordTimestamp2;
}

unsigned int IPv4OptionTimestamp::getRecordTimestampArraySize() const
{
    return recordTimestamp_arraysize;
}

::omnetpp::simtime_t IPv4OptionTimestamp::getRecordTimestamp(unsigned int k) const
{
    if (k>=recordTimestamp_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", recordTimestamp_arraysize, k);
    return this->recordTimestamp[k];
}

void IPv4OptionTimestamp::setRecordTimestamp(unsigned int k, ::omnetpp::simtime_t recordTimestamp)
{
    if (k>=recordTimestamp_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", recordTimestamp_arraysize, k);
    this->recordTimestamp[k] = recordTimestamp;
}

class IPv4OptionTimestampDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4OptionTimestampDescriptor();
    virtual ~IPv4OptionTimestampDescriptor();

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

Register_ClassDescriptor(IPv4OptionTimestampDescriptor)

IPv4OptionTimestampDescriptor::IPv4OptionTimestampDescriptor() : omnetpp::cClassDescriptor("inet::IPv4OptionTimestamp", "inet::IPv4Option")
{
    propertynames = nullptr;
}

IPv4OptionTimestampDescriptor::~IPv4OptionTimestampDescriptor()
{
    delete[] propertynames;
}

bool IPv4OptionTimestampDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4OptionTimestamp *>(obj)!=nullptr;
}

const char **IPv4OptionTimestampDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4OptionTimestampDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4OptionTimestampDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int IPv4OptionTimestampDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *IPv4OptionTimestampDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "flag",
        "overflow",
        "nextIdx",
        "recordAddress",
        "recordTimestamp",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int IPv4OptionTimestampDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flag")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "overflow")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextIdx")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "recordAddress")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "recordTimestamp")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4OptionTimestampDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "short",
        "short",
        "IPv4Address",
        "simtime_t",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv4OptionTimestampDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4OptionTimestampDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::TimestampFlag";
            return nullptr;
        default: return nullptr;
    }
}

int IPv4OptionTimestampDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionTimestamp *pp = (IPv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        case 3: return pp->getRecordAddressArraySize();
        case 4: return pp->getRecordTimestampArraySize();
        default: return 0;
    }
}

const char *IPv4OptionTimestampDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionTimestamp *pp = (IPv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4OptionTimestampDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionTimestamp *pp = (IPv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getFlag(), "inet::TimestampFlag");
        case 1: return long2string(pp->getOverflow());
        case 2: return long2string(pp->getNextIdx());
        case 3: {std::stringstream out; out << pp->getRecordAddress(i); return out.str();}
        case 4: return simtime2string(pp->getRecordTimestamp(i));
        default: return "";
    }
}

bool IPv4OptionTimestampDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionTimestamp *pp = (IPv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        case 0: pp->setFlag((inet::TimestampFlag)string2enum(value, "inet::TimestampFlag")); return true;
        case 1: pp->setOverflow(string2long(value)); return true;
        case 2: pp->setNextIdx(string2long(value)); return true;
        case 4: pp->setRecordTimestamp(i,string2simtime(value)); return true;
        default: return false;
    }
}

const char *IPv4OptionTimestampDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *IPv4OptionTimestampDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionTimestamp *pp = (IPv4OptionTimestamp *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getRecordAddress(i)); break;
        default: return nullptr;
    }
}

IPv4OptionStreamId::IPv4OptionStreamId() : ::inet::IPv4Option()
{
    this->setType(IPOPTION_STREAM_ID);
    this->setLength(4);

    this->streamId = 0;
}

IPv4OptionStreamId::IPv4OptionStreamId(const IPv4OptionStreamId& other) : ::inet::IPv4Option(other)
{
    copy(other);
}

IPv4OptionStreamId::~IPv4OptionStreamId()
{
}

IPv4OptionStreamId& IPv4OptionStreamId::operator=(const IPv4OptionStreamId& other)
{
    if (this==&other) return *this;
    ::inet::IPv4Option::operator=(other);
    copy(other);
    return *this;
}

void IPv4OptionStreamId::copy(const IPv4OptionStreamId& other)
{
    this->streamId = other.streamId;
}

void IPv4OptionStreamId::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv4Option&)*this);
    doParsimPacking(b,this->streamId);
}

void IPv4OptionStreamId::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv4Option&)*this);
    doParsimUnpacking(b,this->streamId);
}

short IPv4OptionStreamId::getStreamId() const
{
    return this->streamId;
}

void IPv4OptionStreamId::setStreamId(short streamId)
{
    this->streamId = streamId;
}

class IPv4OptionStreamIdDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4OptionStreamIdDescriptor();
    virtual ~IPv4OptionStreamIdDescriptor();

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

Register_ClassDescriptor(IPv4OptionStreamIdDescriptor)

IPv4OptionStreamIdDescriptor::IPv4OptionStreamIdDescriptor() : omnetpp::cClassDescriptor("inet::IPv4OptionStreamId", "inet::IPv4Option")
{
    propertynames = nullptr;
}

IPv4OptionStreamIdDescriptor::~IPv4OptionStreamIdDescriptor()
{
    delete[] propertynames;
}

bool IPv4OptionStreamIdDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4OptionStreamId *>(obj)!=nullptr;
}

const char **IPv4OptionStreamIdDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4OptionStreamIdDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4OptionStreamIdDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IPv4OptionStreamIdDescriptor::getFieldTypeFlags(int field) const
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

const char *IPv4OptionStreamIdDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "streamId",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IPv4OptionStreamIdDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "streamId")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4OptionStreamIdDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv4OptionStreamIdDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4OptionStreamIdDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv4OptionStreamIdDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionStreamId *pp = (IPv4OptionStreamId *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv4OptionStreamIdDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionStreamId *pp = (IPv4OptionStreamId *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4OptionStreamIdDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionStreamId *pp = (IPv4OptionStreamId *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getStreamId());
        default: return "";
    }
}

bool IPv4OptionStreamIdDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionStreamId *pp = (IPv4OptionStreamId *)object; (void)pp;
    switch (field) {
        case 0: pp->setStreamId(string2long(value)); return true;
        default: return false;
    }
}

const char *IPv4OptionStreamIdDescriptor::getFieldStructName(int field) const
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

void *IPv4OptionStreamIdDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionStreamId *pp = (IPv4OptionStreamId *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

IPv4OptionUnknown::IPv4OptionUnknown() : ::inet::IPv4Option()
{
    bytes_arraysize = 0;
    this->bytes = 0;
}

IPv4OptionUnknown::IPv4OptionUnknown(const IPv4OptionUnknown& other) : ::inet::IPv4Option(other)
{
    bytes_arraysize = 0;
    this->bytes = 0;
    copy(other);
}

IPv4OptionUnknown::~IPv4OptionUnknown()
{
    delete [] this->bytes;
}

IPv4OptionUnknown& IPv4OptionUnknown::operator=(const IPv4OptionUnknown& other)
{
    if (this==&other) return *this;
    ::inet::IPv4Option::operator=(other);
    copy(other);
    return *this;
}

void IPv4OptionUnknown::copy(const IPv4OptionUnknown& other)
{
    delete [] this->bytes;
    this->bytes = (other.bytes_arraysize==0) ? nullptr : new uint8_t[other.bytes_arraysize];
    bytes_arraysize = other.bytes_arraysize;
    for (unsigned int i=0; i<bytes_arraysize; i++)
        this->bytes[i] = other.bytes[i];
}

void IPv4OptionUnknown::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv4Option&)*this);
    b->pack(bytes_arraysize);
    doParsimArrayPacking(b,this->bytes,bytes_arraysize);
}

void IPv4OptionUnknown::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv4Option&)*this);
    delete [] this->bytes;
    b->unpack(bytes_arraysize);
    if (bytes_arraysize==0) {
        this->bytes = 0;
    } else {
        this->bytes = new uint8_t[bytes_arraysize];
        doParsimArrayUnpacking(b,this->bytes,bytes_arraysize);
    }
}

void IPv4OptionUnknown::setBytesArraySize(unsigned int size)
{
    uint8_t *bytes2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = bytes_arraysize < size ? bytes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        bytes2[i] = this->bytes[i];
    for (unsigned int i=sz; i<size; i++)
        bytes2[i] = 0;
    bytes_arraysize = size;
    delete [] this->bytes;
    this->bytes = bytes2;
}

unsigned int IPv4OptionUnknown::getBytesArraySize() const
{
    return bytes_arraysize;
}

uint8_t IPv4OptionUnknown::getBytes(unsigned int k) const
{
    if (k>=bytes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", bytes_arraysize, k);
    return this->bytes[k];
}

void IPv4OptionUnknown::setBytes(unsigned int k, uint8_t bytes)
{
    if (k>=bytes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", bytes_arraysize, k);
    this->bytes[k] = bytes;
}

class IPv4OptionUnknownDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4OptionUnknownDescriptor();
    virtual ~IPv4OptionUnknownDescriptor();

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

Register_ClassDescriptor(IPv4OptionUnknownDescriptor)

IPv4OptionUnknownDescriptor::IPv4OptionUnknownDescriptor() : omnetpp::cClassDescriptor("inet::IPv4OptionUnknown", "inet::IPv4Option")
{
    propertynames = nullptr;
}

IPv4OptionUnknownDescriptor::~IPv4OptionUnknownDescriptor()
{
    delete[] propertynames;
}

bool IPv4OptionUnknownDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4OptionUnknown *>(obj)!=nullptr;
}

const char **IPv4OptionUnknownDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4OptionUnknownDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4OptionUnknownDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IPv4OptionUnknownDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *IPv4OptionUnknownDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bytes",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IPv4OptionUnknownDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bytes")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4OptionUnknownDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv4OptionUnknownDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4OptionUnknownDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv4OptionUnknownDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionUnknown *pp = (IPv4OptionUnknown *)object; (void)pp;
    switch (field) {
        case 0: return pp->getBytesArraySize();
        default: return 0;
    }
}

const char *IPv4OptionUnknownDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionUnknown *pp = (IPv4OptionUnknown *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4OptionUnknownDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionUnknown *pp = (IPv4OptionUnknown *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getBytes(i));
        default: return "";
    }
}

bool IPv4OptionUnknownDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionUnknown *pp = (IPv4OptionUnknown *)object; (void)pp;
    switch (field) {
        case 0: pp->setBytes(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *IPv4OptionUnknownDescriptor::getFieldStructName(int field) const
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

void *IPv4OptionUnknownDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4OptionUnknown *pp = (IPv4OptionUnknown *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

IPv4Datagram_Base::IPv4Datagram_Base(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->version = 4;
    this->headerLength = IP_HEADER_BYTES;
    this->transportProtocol = IP_PROT_NONE;
    this->timeToLive = 0;
    this->identification = 0;
    this->moreFragments = false;
    this->dontFragment = false;
    this->fragmentOffset = 0;
    this->totalLengthField = -1;
    this->typeOfService = 0;
}

IPv4Datagram_Base::IPv4Datagram_Base(const IPv4Datagram_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

IPv4Datagram_Base::~IPv4Datagram_Base()
{
}

IPv4Datagram_Base& IPv4Datagram_Base::operator=(const IPv4Datagram_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IPv4Datagram_Base::copy(const IPv4Datagram_Base& other)
{
    this->version = other.version;
    this->headerLength = other.headerLength;
    this->srcAddress = other.srcAddress;
    this->destAddress = other.destAddress;
    this->transportProtocol = other.transportProtocol;
    this->timeToLive = other.timeToLive;
    this->identification = other.identification;
    this->moreFragments = other.moreFragments;
    this->dontFragment = other.dontFragment;
    this->fragmentOffset = other.fragmentOffset;
    this->totalLengthField = other.totalLengthField;
    this->typeOfService = other.typeOfService;
    this->options = other.options;
}

void IPv4Datagram_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->headerLength);
    doParsimPacking(b,this->srcAddress);
    doParsimPacking(b,this->destAddress);
    doParsimPacking(b,this->transportProtocol);
    doParsimPacking(b,this->timeToLive);
    doParsimPacking(b,this->identification);
    doParsimPacking(b,this->moreFragments);
    doParsimPacking(b,this->dontFragment);
    doParsimPacking(b,this->fragmentOffset);
    doParsimPacking(b,this->totalLengthField);
    doParsimPacking(b,this->typeOfService);
    // field diffServCodePoint is abstract -- please do packing in customized class
    // field explicitCongestionNotification is abstract -- please do packing in customized class
    doParsimPacking(b,this->options);
}

void IPv4Datagram_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->headerLength);
    doParsimUnpacking(b,this->srcAddress);
    doParsimUnpacking(b,this->destAddress);
    doParsimUnpacking(b,this->transportProtocol);
    doParsimUnpacking(b,this->timeToLive);
    doParsimUnpacking(b,this->identification);
    doParsimUnpacking(b,this->moreFragments);
    doParsimUnpacking(b,this->dontFragment);
    doParsimUnpacking(b,this->fragmentOffset);
    doParsimUnpacking(b,this->totalLengthField);
    doParsimUnpacking(b,this->typeOfService);
    // field diffServCodePoint is abstract -- please do unpacking in customized class
    // field explicitCongestionNotification is abstract -- please do unpacking in customized class
    doParsimUnpacking(b,this->options);
}

short IPv4Datagram_Base::getVersion() const
{
    return this->version;
}

void IPv4Datagram_Base::setVersion(short version)
{
    this->version = version;
}

short IPv4Datagram_Base::getHeaderLength() const
{
    return this->headerLength;
}

void IPv4Datagram_Base::setHeaderLength(short headerLength)
{
    this->headerLength = headerLength;
}

IPv4Address& IPv4Datagram_Base::getSrcAddress()
{
    return this->srcAddress;
}

void IPv4Datagram_Base::setSrcAddress(const IPv4Address& srcAddress)
{
    this->srcAddress = srcAddress;
}

IPv4Address& IPv4Datagram_Base::getDestAddress()
{
    return this->destAddress;
}

void IPv4Datagram_Base::setDestAddress(const IPv4Address& destAddress)
{
    this->destAddress = destAddress;
}

int IPv4Datagram_Base::getTransportProtocol() const
{
    return this->transportProtocol;
}

void IPv4Datagram_Base::setTransportProtocol(int transportProtocol)
{
    this->transportProtocol = transportProtocol;
}

short IPv4Datagram_Base::getTimeToLive() const
{
    return this->timeToLive;
}

void IPv4Datagram_Base::setTimeToLive(short timeToLive)
{
    this->timeToLive = timeToLive;
}

int IPv4Datagram_Base::getIdentification() const
{
    return this->identification;
}

void IPv4Datagram_Base::setIdentification(int identification)
{
    this->identification = identification;
}

bool IPv4Datagram_Base::getMoreFragments() const
{
    return this->moreFragments;
}

void IPv4Datagram_Base::setMoreFragments(bool moreFragments)
{
    this->moreFragments = moreFragments;
}

bool IPv4Datagram_Base::getDontFragment() const
{
    return this->dontFragment;
}

void IPv4Datagram_Base::setDontFragment(bool dontFragment)
{
    this->dontFragment = dontFragment;
}

int IPv4Datagram_Base::getFragmentOffset() const
{
    return this->fragmentOffset;
}

void IPv4Datagram_Base::setFragmentOffset(int fragmentOffset)
{
    this->fragmentOffset = fragmentOffset;
}

int IPv4Datagram_Base::getTotalLengthField() const
{
    return this->totalLengthField;
}

void IPv4Datagram_Base::setTotalLengthField(int totalLengthField)
{
    this->totalLengthField = totalLengthField;
}

unsigned char IPv4Datagram_Base::getTypeOfService() const
{
    return this->typeOfService;
}

void IPv4Datagram_Base::setTypeOfService(unsigned char typeOfService)
{
    this->typeOfService = typeOfService;
}

TLVOptions& IPv4Datagram_Base::getOptions()
{
    return this->options;
}

void IPv4Datagram_Base::setOptions(const TLVOptions& options)
{
    this->options = options;
}

class IPv4DatagramDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv4DatagramDescriptor();
    virtual ~IPv4DatagramDescriptor();

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

Register_ClassDescriptor(IPv4DatagramDescriptor)

IPv4DatagramDescriptor::IPv4DatagramDescriptor() : omnetpp::cClassDescriptor("inet::IPv4Datagram", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

IPv4DatagramDescriptor::~IPv4DatagramDescriptor()
{
    delete[] propertynames;
}

bool IPv4DatagramDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv4Datagram_Base *>(obj)!=nullptr;
}

const char **IPv4DatagramDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv4DatagramDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv4DatagramDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount() : 15;
}

unsigned int IPv4DatagramDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<15) ? fieldTypeFlags[field] : 0;
}

const char *IPv4DatagramDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "headerLength",
        "srcAddress",
        "destAddress",
        "transportProtocol",
        "timeToLive",
        "identification",
        "moreFragments",
        "dontFragment",
        "fragmentOffset",
        "totalLengthField",
        "typeOfService",
        "diffServCodePoint",
        "explicitCongestionNotification",
        "options",
    };
    return (field>=0 && field<15) ? fieldNames[field] : nullptr;
}

int IPv4DatagramDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddress")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddress")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "transportProtocol")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeToLive")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "identification")==0) return base+6;
    if (fieldName[0]=='m' && strcmp(fieldName, "moreFragments")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "dontFragment")==0) return base+8;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentOffset")==0) return base+9;
    if (fieldName[0]=='t' && strcmp(fieldName, "totalLengthField")==0) return base+10;
    if (fieldName[0]=='t' && strcmp(fieldName, "typeOfService")==0) return base+11;
    if (fieldName[0]=='d' && strcmp(fieldName, "diffServCodePoint")==0) return base+12;
    if (fieldName[0]=='e' && strcmp(fieldName, "explicitCongestionNotification")==0) return base+13;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+14;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv4DatagramDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "short",
        "IPv4Address",
        "IPv4Address",
        "int",
        "short",
        "int",
        "bool",
        "bool",
        "int",
        "int",
        "unsigned char",
        "int",
        "int",
        "TLVOptions",
    };
    return (field>=0 && field<15) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv4DatagramDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv4DatagramDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv4DatagramDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv4Datagram_Base *pp = (IPv4Datagram_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv4DatagramDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4Datagram_Base *pp = (IPv4Datagram_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv4DatagramDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv4Datagram_Base *pp = (IPv4Datagram_Base *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVersion());
        case 1: return long2string(pp->getHeaderLength());
        case 2: {std::stringstream out; out << pp->getSrcAddress(); return out.str();}
        case 3: {std::stringstream out; out << pp->getDestAddress(); return out.str();}
        case 4: return enum2string(pp->getTransportProtocol(), "inet::IPProtocolId");
        case 5: return long2string(pp->getTimeToLive());
        case 6: return long2string(pp->getIdentification());
        case 7: return bool2string(pp->getMoreFragments());
        case 8: return bool2string(pp->getDontFragment());
        case 9: return long2string(pp->getFragmentOffset());
        case 10: return long2string(pp->getTotalLengthField());
        case 11: return ulong2string(pp->getTypeOfService());
        case 12: return long2string(pp->getDiffServCodePoint());
        case 13: return long2string(pp->getExplicitCongestionNotification());
        case 14: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool IPv4DatagramDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv4Datagram_Base *pp = (IPv4Datagram_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2long(value)); return true;
        case 1: pp->setHeaderLength(string2long(value)); return true;
        case 4: pp->setTransportProtocol((inet::IPProtocolId)string2enum(value, "inet::IPProtocolId")); return true;
        case 5: pp->setTimeToLive(string2long(value)); return true;
        case 6: pp->setIdentification(string2long(value)); return true;
        case 7: pp->setMoreFragments(string2bool(value)); return true;
        case 8: pp->setDontFragment(string2bool(value)); return true;
        case 9: pp->setFragmentOffset(string2long(value)); return true;
        case 10: pp->setTotalLengthField(string2long(value)); return true;
        case 11: pp->setTypeOfService(string2ulong(value)); return true;
        case 12: pp->setDiffServCodePoint(string2long(value)); return true;
        case 13: pp->setExplicitCongestionNotification(string2long(value)); return true;
        default: return false;
    }
}

const char *IPv4DatagramDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        case 14: return omnetpp::opp_typename(typeid(TLVOptions));
        default: return nullptr;
    };
}

void *IPv4DatagramDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv4Datagram_Base *pp = (IPv4Datagram_Base *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getSrcAddress()); break;
        case 3: return (void *)(&pp->getDestAddress()); break;
        case 14: return (void *)(&pp->getOptions()); break;
        default: return nullptr;
    }
}

} // namespace inet

