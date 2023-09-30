//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/ipv4/IGMPMessage.msg.
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
#include "IGMPMessage_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IGMPType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IGMPType"));
    e->insert(IGMP_MEMBERSHIP_QUERY, "IGMP_MEMBERSHIP_QUERY");
    e->insert(IGMPV1_MEMBERSHIP_REPORT, "IGMPV1_MEMBERSHIP_REPORT");
    e->insert(IGMPV2_MEMBERSHIP_REPORT, "IGMPV2_MEMBERSHIP_REPORT");
    e->insert(IGMPV2_LEAVE_GROUP, "IGMPV2_LEAVE_GROUP");
    e->insert(IGMPV3_MEMBERSHIP_REPORT, "IGMPV3_MEMBERSHIP_REPORT");
)

Register_Class(IGMPMessage)

IGMPMessage::IGMPMessage(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->type = 0;
}

IGMPMessage::IGMPMessage(const IGMPMessage& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

IGMPMessage::~IGMPMessage()
{
}

IGMPMessage& IGMPMessage::operator=(const IGMPMessage& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IGMPMessage::copy(const IGMPMessage& other)
{
    this->type = other.type;
}

void IGMPMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
}

void IGMPMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
}

int IGMPMessage::getType() const
{
    return this->type;
}

void IGMPMessage::setType(int type)
{
    this->type = type;
}

class IGMPMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPMessageDescriptor();
    virtual ~IGMPMessageDescriptor();

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

Register_ClassDescriptor(IGMPMessageDescriptor)

IGMPMessageDescriptor::IGMPMessageDescriptor() : omnetpp::cClassDescriptor("inet::IGMPMessage", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

IGMPMessageDescriptor::~IGMPMessageDescriptor()
{
    delete[] propertynames;
}

bool IGMPMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPMessage *>(obj)!=nullptr;
}

const char **IGMPMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IGMPMessageDescriptor::getFieldTypeFlags(int field) const
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

const char *IGMPMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IGMPMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPMessageDescriptor::getFieldTypeString(int field) const
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

const char **IGMPMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::IGMPType";
            return nullptr;
        default: return nullptr;
    }
}

int IGMPMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPMessage *pp = (IGMPMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IGMPMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPMessage *pp = (IGMPMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPMessage *pp = (IGMPMessage *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::IGMPType");
        default: return "";
    }
}

bool IGMPMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPMessage *pp = (IGMPMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::IGMPType)string2enum(value, "inet::IGMPType")); return true;
        default: return false;
    }
}

const char *IGMPMessageDescriptor::getFieldStructName(int field) const
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

void *IGMPMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPMessage *pp = (IGMPMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IGMPQuery)

IGMPQuery::IGMPQuery(const char *name, short kind) : ::inet::IGMPMessage(name,kind)
{
}

IGMPQuery::IGMPQuery(const IGMPQuery& other) : ::inet::IGMPMessage(other)
{
    copy(other);
}

IGMPQuery::~IGMPQuery()
{
}

IGMPQuery& IGMPQuery::operator=(const IGMPQuery& other)
{
    if (this==&other) return *this;
    ::inet::IGMPMessage::operator=(other);
    copy(other);
    return *this;
}

void IGMPQuery::copy(const IGMPQuery& other)
{
    this->groupAddress = other.groupAddress;
}

void IGMPQuery::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IGMPMessage::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
}

void IGMPQuery::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IGMPMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
}

IPv4Address& IGMPQuery::getGroupAddress()
{
    return this->groupAddress;
}

void IGMPQuery::setGroupAddress(const IPv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

class IGMPQueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPQueryDescriptor();
    virtual ~IGMPQueryDescriptor();

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

Register_ClassDescriptor(IGMPQueryDescriptor)

IGMPQueryDescriptor::IGMPQueryDescriptor() : omnetpp::cClassDescriptor("inet::IGMPQuery", "inet::IGMPMessage")
{
    propertynames = nullptr;
}

IGMPQueryDescriptor::~IGMPQueryDescriptor()
{
    delete[] propertynames;
}

bool IGMPQueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPQuery *>(obj)!=nullptr;
}

const char **IGMPQueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPQueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPQueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IGMPQueryDescriptor::getFieldTypeFlags(int field) const
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

const char *IGMPQueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IGMPQueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPQueryDescriptor::getFieldTypeString(int field) const
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

const char **IGMPQueryDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPQueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IGMPQueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPQuery *pp = (IGMPQuery *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IGMPQueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPQuery *pp = (IGMPQuery *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPQueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPQuery *pp = (IGMPQuery *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        default: return "";
    }
}

bool IGMPQueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPQuery *pp = (IGMPQuery *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IGMPQueryDescriptor::getFieldStructName(int field) const
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

void *IGMPQueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPQuery *pp = (IGMPQuery *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        default: return nullptr;
    }
}

Register_Class(IGMPv1Query)

IGMPv1Query::IGMPv1Query(const char *name, short kind) : ::inet::IGMPQuery(name,kind)
{
    this->setType(IGMP_MEMBERSHIP_QUERY);
}

IGMPv1Query::IGMPv1Query(const IGMPv1Query& other) : ::inet::IGMPQuery(other)
{
    copy(other);
}

IGMPv1Query::~IGMPv1Query()
{
}

IGMPv1Query& IGMPv1Query::operator=(const IGMPv1Query& other)
{
    if (this==&other) return *this;
    ::inet::IGMPQuery::operator=(other);
    copy(other);
    return *this;
}

void IGMPv1Query::copy(const IGMPv1Query& other)
{
}

void IGMPv1Query::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IGMPQuery::parsimPack(b);
}

void IGMPv1Query::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IGMPQuery::parsimUnpack(b);
}

class IGMPv1QueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPv1QueryDescriptor();
    virtual ~IGMPv1QueryDescriptor();

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

Register_ClassDescriptor(IGMPv1QueryDescriptor)

IGMPv1QueryDescriptor::IGMPv1QueryDescriptor() : omnetpp::cClassDescriptor("inet::IGMPv1Query", "inet::IGMPQuery")
{
    propertynames = nullptr;
}

IGMPv1QueryDescriptor::~IGMPv1QueryDescriptor()
{
    delete[] propertynames;
}

bool IGMPv1QueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPv1Query *>(obj)!=nullptr;
}

const char **IGMPv1QueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPv1QueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPv1QueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int IGMPv1QueryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *IGMPv1QueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int IGMPv1QueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPv1QueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **IGMPv1QueryDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPv1QueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IGMPv1QueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Query *pp = (IGMPv1Query *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IGMPv1QueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Query *pp = (IGMPv1Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPv1QueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Query *pp = (IGMPv1Query *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool IGMPv1QueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Query *pp = (IGMPv1Query *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IGMPv1QueryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *IGMPv1QueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Query *pp = (IGMPv1Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IGMPv1Report)

IGMPv1Report::IGMPv1Report(const char *name, short kind) : ::inet::IGMPMessage(name,kind)
{
    this->setType(IGMPV1_MEMBERSHIP_REPORT);

}

IGMPv1Report::IGMPv1Report(const IGMPv1Report& other) : ::inet::IGMPMessage(other)
{
    copy(other);
}

IGMPv1Report::~IGMPv1Report()
{
}

IGMPv1Report& IGMPv1Report::operator=(const IGMPv1Report& other)
{
    if (this==&other) return *this;
    ::inet::IGMPMessage::operator=(other);
    copy(other);
    return *this;
}

void IGMPv1Report::copy(const IGMPv1Report& other)
{
    this->groupAddress = other.groupAddress;
}

void IGMPv1Report::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IGMPMessage::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
}

void IGMPv1Report::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IGMPMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
}

IPv4Address& IGMPv1Report::getGroupAddress()
{
    return this->groupAddress;
}

void IGMPv1Report::setGroupAddress(const IPv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

class IGMPv1ReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPv1ReportDescriptor();
    virtual ~IGMPv1ReportDescriptor();

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

Register_ClassDescriptor(IGMPv1ReportDescriptor)

IGMPv1ReportDescriptor::IGMPv1ReportDescriptor() : omnetpp::cClassDescriptor("inet::IGMPv1Report", "inet::IGMPMessage")
{
    propertynames = nullptr;
}

IGMPv1ReportDescriptor::~IGMPv1ReportDescriptor()
{
    delete[] propertynames;
}

bool IGMPv1ReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPv1Report *>(obj)!=nullptr;
}

const char **IGMPv1ReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPv1ReportDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPv1ReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IGMPv1ReportDescriptor::getFieldTypeFlags(int field) const
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

const char *IGMPv1ReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IGMPv1ReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPv1ReportDescriptor::getFieldTypeString(int field) const
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

const char **IGMPv1ReportDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPv1ReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IGMPv1ReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Report *pp = (IGMPv1Report *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IGMPv1ReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Report *pp = (IGMPv1Report *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPv1ReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Report *pp = (IGMPv1Report *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        default: return "";
    }
}

bool IGMPv1ReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Report *pp = (IGMPv1Report *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IGMPv1ReportDescriptor::getFieldStructName(int field) const
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

void *IGMPv1ReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPv1Report *pp = (IGMPv1Report *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        default: return nullptr;
    }
}

Register_Class(IGMPv2Query)

IGMPv2Query::IGMPv2Query(const char *name, short kind) : ::inet::IGMPQuery(name,kind)
{
    this->setType(IGMP_MEMBERSHIP_QUERY);

    this->maxRespTime = 0;
}

IGMPv2Query::IGMPv2Query(const IGMPv2Query& other) : ::inet::IGMPQuery(other)
{
    copy(other);
}

IGMPv2Query::~IGMPv2Query()
{
}

IGMPv2Query& IGMPv2Query::operator=(const IGMPv2Query& other)
{
    if (this==&other) return *this;
    ::inet::IGMPQuery::operator=(other);
    copy(other);
    return *this;
}

void IGMPv2Query::copy(const IGMPv2Query& other)
{
    this->maxRespTime = other.maxRespTime;
}

void IGMPv2Query::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IGMPQuery::parsimPack(b);
    doParsimPacking(b,this->maxRespTime);
}

void IGMPv2Query::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IGMPQuery::parsimUnpack(b);
    doParsimUnpacking(b,this->maxRespTime);
}

unsigned char IGMPv2Query::getMaxRespTime() const
{
    return this->maxRespTime;
}

void IGMPv2Query::setMaxRespTime(unsigned char maxRespTime)
{
    this->maxRespTime = maxRespTime;
}

class IGMPv2QueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPv2QueryDescriptor();
    virtual ~IGMPv2QueryDescriptor();

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

Register_ClassDescriptor(IGMPv2QueryDescriptor)

IGMPv2QueryDescriptor::IGMPv2QueryDescriptor() : omnetpp::cClassDescriptor("inet::IGMPv2Query", "inet::IGMPQuery")
{
    propertynames = nullptr;
}

IGMPv2QueryDescriptor::~IGMPv2QueryDescriptor()
{
    delete[] propertynames;
}

bool IGMPv2QueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPv2Query *>(obj)!=nullptr;
}

const char **IGMPv2QueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPv2QueryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPv2QueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IGMPv2QueryDescriptor::getFieldTypeFlags(int field) const
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

const char *IGMPv2QueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "maxRespTime",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IGMPv2QueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxRespTime")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPv2QueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **IGMPv2QueryDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPv2QueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IGMPv2QueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Query *pp = (IGMPv2Query *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IGMPv2QueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Query *pp = (IGMPv2Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPv2QueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Query *pp = (IGMPv2Query *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getMaxRespTime());
        default: return "";
    }
}

bool IGMPv2QueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Query *pp = (IGMPv2Query *)object; (void)pp;
    switch (field) {
        case 0: pp->setMaxRespTime(string2ulong(value)); return true;
        default: return false;
    }
}

const char *IGMPv2QueryDescriptor::getFieldStructName(int field) const
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

void *IGMPv2QueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Query *pp = (IGMPv2Query *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(IGMPv2Report)

IGMPv2Report::IGMPv2Report(const char *name, short kind) : ::inet::IGMPMessage(name,kind)
{
    this->setType(IGMPV2_MEMBERSHIP_REPORT);

}

IGMPv2Report::IGMPv2Report(const IGMPv2Report& other) : ::inet::IGMPMessage(other)
{
    copy(other);
}

IGMPv2Report::~IGMPv2Report()
{
}

IGMPv2Report& IGMPv2Report::operator=(const IGMPv2Report& other)
{
    if (this==&other) return *this;
    ::inet::IGMPMessage::operator=(other);
    copy(other);
    return *this;
}

void IGMPv2Report::copy(const IGMPv2Report& other)
{
    this->groupAddress = other.groupAddress;
}

void IGMPv2Report::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IGMPMessage::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
}

void IGMPv2Report::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IGMPMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
}

IPv4Address& IGMPv2Report::getGroupAddress()
{
    return this->groupAddress;
}

void IGMPv2Report::setGroupAddress(const IPv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

class IGMPv2ReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPv2ReportDescriptor();
    virtual ~IGMPv2ReportDescriptor();

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

Register_ClassDescriptor(IGMPv2ReportDescriptor)

IGMPv2ReportDescriptor::IGMPv2ReportDescriptor() : omnetpp::cClassDescriptor("inet::IGMPv2Report", "inet::IGMPMessage")
{
    propertynames = nullptr;
}

IGMPv2ReportDescriptor::~IGMPv2ReportDescriptor()
{
    delete[] propertynames;
}

bool IGMPv2ReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPv2Report *>(obj)!=nullptr;
}

const char **IGMPv2ReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPv2ReportDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPv2ReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IGMPv2ReportDescriptor::getFieldTypeFlags(int field) const
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

const char *IGMPv2ReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IGMPv2ReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPv2ReportDescriptor::getFieldTypeString(int field) const
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

const char **IGMPv2ReportDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPv2ReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IGMPv2ReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Report *pp = (IGMPv2Report *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IGMPv2ReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Report *pp = (IGMPv2Report *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPv2ReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Report *pp = (IGMPv2Report *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        default: return "";
    }
}

bool IGMPv2ReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Report *pp = (IGMPv2Report *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IGMPv2ReportDescriptor::getFieldStructName(int field) const
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

void *IGMPv2ReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Report *pp = (IGMPv2Report *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        default: return nullptr;
    }
}

Register_Class(IGMPv2Leave)

IGMPv2Leave::IGMPv2Leave(const char *name, short kind) : ::inet::IGMPMessage(name,kind)
{
    this->setType(IGMPV2_LEAVE_GROUP);

}

IGMPv2Leave::IGMPv2Leave(const IGMPv2Leave& other) : ::inet::IGMPMessage(other)
{
    copy(other);
}

IGMPv2Leave::~IGMPv2Leave()
{
}

IGMPv2Leave& IGMPv2Leave::operator=(const IGMPv2Leave& other)
{
    if (this==&other) return *this;
    ::inet::IGMPMessage::operator=(other);
    copy(other);
    return *this;
}

void IGMPv2Leave::copy(const IGMPv2Leave& other)
{
    this->groupAddress = other.groupAddress;
}

void IGMPv2Leave::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IGMPMessage::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
}

void IGMPv2Leave::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IGMPMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
}

IPv4Address& IGMPv2Leave::getGroupAddress()
{
    return this->groupAddress;
}

void IGMPv2Leave::setGroupAddress(const IPv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

class IGMPv2LeaveDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPv2LeaveDescriptor();
    virtual ~IGMPv2LeaveDescriptor();

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

Register_ClassDescriptor(IGMPv2LeaveDescriptor)

IGMPv2LeaveDescriptor::IGMPv2LeaveDescriptor() : omnetpp::cClassDescriptor("inet::IGMPv2Leave", "inet::IGMPMessage")
{
    propertynames = nullptr;
}

IGMPv2LeaveDescriptor::~IGMPv2LeaveDescriptor()
{
    delete[] propertynames;
}

bool IGMPv2LeaveDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPv2Leave *>(obj)!=nullptr;
}

const char **IGMPv2LeaveDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPv2LeaveDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPv2LeaveDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IGMPv2LeaveDescriptor::getFieldTypeFlags(int field) const
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

const char *IGMPv2LeaveDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IGMPv2LeaveDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPv2LeaveDescriptor::getFieldTypeString(int field) const
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

const char **IGMPv2LeaveDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPv2LeaveDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IGMPv2LeaveDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Leave *pp = (IGMPv2Leave *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IGMPv2LeaveDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Leave *pp = (IGMPv2Leave *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPv2LeaveDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Leave *pp = (IGMPv2Leave *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        default: return "";
    }
}

bool IGMPv2LeaveDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Leave *pp = (IGMPv2Leave *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IGMPv2LeaveDescriptor::getFieldStructName(int field) const
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

void *IGMPv2LeaveDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPv2Leave *pp = (IGMPv2Leave *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        default: return nullptr;
    }
}

IGMPv3Query_Base::IGMPv3Query_Base(const char *name, short kind) : ::inet::IGMPv2Query(name,kind)
{
    this->suppressRouterProc = false;
    this->robustnessVariable = 0;
    this->queryIntervalCode = 0;
}

IGMPv3Query_Base::IGMPv3Query_Base(const IGMPv3Query_Base& other) : ::inet::IGMPv2Query(other)
{
    copy(other);
}

IGMPv3Query_Base::~IGMPv3Query_Base()
{
}

IGMPv3Query_Base& IGMPv3Query_Base::operator=(const IGMPv3Query_Base& other)
{
    if (this==&other) return *this;
    ::inet::IGMPv2Query::operator=(other);
    copy(other);
    return *this;
}

void IGMPv3Query_Base::copy(const IGMPv3Query_Base& other)
{
    this->suppressRouterProc = other.suppressRouterProc;
    this->robustnessVariable = other.robustnessVariable;
    this->queryIntervalCode = other.queryIntervalCode;
    this->sourceList = other.sourceList;
}

void IGMPv3Query_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IGMPv2Query::parsimPack(b);
    doParsimPacking(b,this->suppressRouterProc);
    doParsimPacking(b,this->robustnessVariable);
    doParsimPacking(b,this->queryIntervalCode);
    doParsimPacking(b,this->sourceList);
    // field maxRespCode is abstract -- please do packing in customized class
}

void IGMPv3Query_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IGMPv2Query::parsimUnpack(b);
    doParsimUnpacking(b,this->suppressRouterProc);
    doParsimUnpacking(b,this->robustnessVariable);
    doParsimUnpacking(b,this->queryIntervalCode);
    doParsimUnpacking(b,this->sourceList);
    // field maxRespCode is abstract -- please do unpacking in customized class
}

bool IGMPv3Query_Base::getSuppressRouterProc() const
{
    return this->suppressRouterProc;
}

void IGMPv3Query_Base::setSuppressRouterProc(bool suppressRouterProc)
{
    this->suppressRouterProc = suppressRouterProc;
}

unsigned char IGMPv3Query_Base::getRobustnessVariable() const
{
    return this->robustnessVariable;
}

void IGMPv3Query_Base::setRobustnessVariable(unsigned char robustnessVariable)
{
    this->robustnessVariable = robustnessVariable;
}

unsigned char IGMPv3Query_Base::getQueryIntervalCode() const
{
    return this->queryIntervalCode;
}

void IGMPv3Query_Base::setQueryIntervalCode(unsigned char queryIntervalCode)
{
    this->queryIntervalCode = queryIntervalCode;
}

IPv4AddressVector& IGMPv3Query_Base::getSourceList()
{
    return this->sourceList;
}

void IGMPv3Query_Base::setSourceList(const IPv4AddressVector& sourceList)
{
    this->sourceList = sourceList;
}

class IGMPv3QueryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPv3QueryDescriptor();
    virtual ~IGMPv3QueryDescriptor();

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

Register_ClassDescriptor(IGMPv3QueryDescriptor)

IGMPv3QueryDescriptor::IGMPv3QueryDescriptor() : omnetpp::cClassDescriptor("inet::IGMPv3Query", "inet::IGMPv2Query")
{
    propertynames = nullptr;
}

IGMPv3QueryDescriptor::~IGMPv3QueryDescriptor()
{
    delete[] propertynames;
}

bool IGMPv3QueryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPv3Query_Base *>(obj)!=nullptr;
}

const char **IGMPv3QueryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPv3QueryDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPv3QueryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int IGMPv3QueryDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *IGMPv3QueryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "suppressRouterProc",
        "robustnessVariable",
        "queryIntervalCode",
        "sourceList",
        "maxRespCode",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int IGMPv3QueryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "suppressRouterProc")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "robustnessVariable")==0) return base+1;
    if (fieldName[0]=='q' && strcmp(fieldName, "queryIntervalCode")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceList")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxRespCode")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPv3QueryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "unsigned char",
        "unsigned char",
        "IPv4AddressVector",
        "unsigned char",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **IGMPv3QueryDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPv3QueryDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IGMPv3QueryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Query_Base *pp = (IGMPv3Query_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IGMPv3QueryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Query_Base *pp = (IGMPv3Query_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPv3QueryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Query_Base *pp = (IGMPv3Query_Base *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getSuppressRouterProc());
        case 1: return ulong2string(pp->getRobustnessVariable());
        case 2: return ulong2string(pp->getQueryIntervalCode());
        case 3: {std::stringstream out; out << pp->getSourceList(); return out.str();}
        case 4: return ulong2string(pp->getMaxRespCode());
        default: return "";
    }
}

bool IGMPv3QueryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Query_Base *pp = (IGMPv3Query_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSuppressRouterProc(string2bool(value)); return true;
        case 1: pp->setRobustnessVariable(string2ulong(value)); return true;
        case 2: pp->setQueryIntervalCode(string2ulong(value)); return true;
        case 4: pp->setMaxRespCode(string2ulong(value)); return true;
        default: return false;
    }
}

const char *IGMPv3QueryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(IPv4AddressVector));
        default: return nullptr;
    };
}

void *IGMPv3QueryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Query_Base *pp = (IGMPv3Query_Base *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getSourceList()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::GroupRecordType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::GroupRecordType"));
    e->insert(MODE_IS_INCLUDE, "MODE_IS_INCLUDE");
    e->insert(MODE_IS_EXCLUDE, "MODE_IS_EXCLUDE");
    e->insert(CHANGE_TO_INCLUDE_MODE, "CHANGE_TO_INCLUDE_MODE");
    e->insert(CHANGE_TO_EXCLUDE_MODE, "CHANGE_TO_EXCLUDE_MODE");
    e->insert(ALLOW_NEW_SOURCES, "ALLOW_NEW_SOURCES");
    e->insert(BLOCK_OLD_SOURCE, "BLOCK_OLD_SOURCE");
)

GroupRecord::GroupRecord()
{
    this->recordType = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const GroupRecord& a)
{
    doParsimPacking(b,a.recordType);
    doParsimPacking(b,a.groupAddress);
    doParsimPacking(b,a.sourceList);
}

void __doUnpacking(omnetpp::cCommBuffer *b, GroupRecord& a)
{
    doParsimUnpacking(b,a.recordType);
    doParsimUnpacking(b,a.groupAddress);
    doParsimUnpacking(b,a.sourceList);
}

class GroupRecordDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    GroupRecordDescriptor();
    virtual ~GroupRecordDescriptor();

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

Register_ClassDescriptor(GroupRecordDescriptor)

GroupRecordDescriptor::GroupRecordDescriptor() : omnetpp::cClassDescriptor("inet::GroupRecord", "")
{
    propertynames = nullptr;
}

GroupRecordDescriptor::~GroupRecordDescriptor()
{
    delete[] propertynames;
}

bool GroupRecordDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GroupRecord *>(obj)!=nullptr;
}

const char **GroupRecordDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *GroupRecordDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int GroupRecordDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int GroupRecordDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *GroupRecordDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "recordType",
        "groupAddress",
        "sourceList",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int GroupRecordDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "recordType")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceList")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *GroupRecordDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "IPv4Address",
        "IPv4AddressVector",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **GroupRecordDescriptor::getFieldPropertyNames(int field) const
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

const char *GroupRecordDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::GroupRecordType";
            return nullptr;
        default: return nullptr;
    }
}

int GroupRecordDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *GroupRecordDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GroupRecordDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->recordType, "inet::GroupRecordType");
        case 1: {std::stringstream out; out << pp->groupAddress; return out.str();}
        case 2: {std::stringstream out; out << pp->sourceList; return out.str();}
        default: return "";
    }
}

bool GroupRecordDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        case 0: pp->recordType = (inet::GroupRecordType)string2enum(value, "inet::GroupRecordType"); return true;
        default: return false;
    }
}

const char *GroupRecordDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(IPv4AddressVector));
        default: return nullptr;
    };
}

void *GroupRecordDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    GroupRecord *pp = (GroupRecord *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->groupAddress); break;
        case 2: return (void *)(&pp->sourceList); break;
        default: return nullptr;
    }
}

Register_Class(IGMPv3Report)

IGMPv3Report::IGMPv3Report(const char *name, short kind) : ::inet::IGMPMessage(name,kind)
{
    this->setType(IGMPV3_MEMBERSHIP_REPORT);

    groupRecord_arraysize = 0;
    this->groupRecord = 0;
}

IGMPv3Report::IGMPv3Report(const IGMPv3Report& other) : ::inet::IGMPMessage(other)
{
    groupRecord_arraysize = 0;
    this->groupRecord = 0;
    copy(other);
}

IGMPv3Report::~IGMPv3Report()
{
    delete [] this->groupRecord;
}

IGMPv3Report& IGMPv3Report::operator=(const IGMPv3Report& other)
{
    if (this==&other) return *this;
    ::inet::IGMPMessage::operator=(other);
    copy(other);
    return *this;
}

void IGMPv3Report::copy(const IGMPv3Report& other)
{
    delete [] this->groupRecord;
    this->groupRecord = (other.groupRecord_arraysize==0) ? nullptr : new GroupRecord[other.groupRecord_arraysize];
    groupRecord_arraysize = other.groupRecord_arraysize;
    for (unsigned int i=0; i<groupRecord_arraysize; i++)
        this->groupRecord[i] = other.groupRecord[i];
}

void IGMPv3Report::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::IGMPMessage::parsimPack(b);
    b->pack(groupRecord_arraysize);
    doParsimArrayPacking(b,this->groupRecord,groupRecord_arraysize);
}

void IGMPv3Report::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::IGMPMessage::parsimUnpack(b);
    delete [] this->groupRecord;
    b->unpack(groupRecord_arraysize);
    if (groupRecord_arraysize==0) {
        this->groupRecord = 0;
    } else {
        this->groupRecord = new GroupRecord[groupRecord_arraysize];
        doParsimArrayUnpacking(b,this->groupRecord,groupRecord_arraysize);
    }
}

void IGMPv3Report::setGroupRecordArraySize(unsigned int size)
{
    GroupRecord *groupRecord2 = (size==0) ? nullptr : new GroupRecord[size];
    unsigned int sz = groupRecord_arraysize < size ? groupRecord_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        groupRecord2[i] = this->groupRecord[i];
    groupRecord_arraysize = size;
    delete [] this->groupRecord;
    this->groupRecord = groupRecord2;
}

unsigned int IGMPv3Report::getGroupRecordArraySize() const
{
    return groupRecord_arraysize;
}

GroupRecord& IGMPv3Report::getGroupRecord(unsigned int k)
{
    if (k>=groupRecord_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", groupRecord_arraysize, k);
    return this->groupRecord[k];
}

void IGMPv3Report::setGroupRecord(unsigned int k, const GroupRecord& groupRecord)
{
    if (k>=groupRecord_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", groupRecord_arraysize, k);
    this->groupRecord[k] = groupRecord;
}

class IGMPv3ReportDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IGMPv3ReportDescriptor();
    virtual ~IGMPv3ReportDescriptor();

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

Register_ClassDescriptor(IGMPv3ReportDescriptor)

IGMPv3ReportDescriptor::IGMPv3ReportDescriptor() : omnetpp::cClassDescriptor("inet::IGMPv3Report", "inet::IGMPMessage")
{
    propertynames = nullptr;
}

IGMPv3ReportDescriptor::~IGMPv3ReportDescriptor()
{
    delete[] propertynames;
}

bool IGMPv3ReportDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IGMPv3Report *>(obj)!=nullptr;
}

const char **IGMPv3ReportDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IGMPv3ReportDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IGMPv3ReportDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IGMPv3ReportDescriptor::getFieldTypeFlags(int field) const
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

const char *IGMPv3ReportDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupRecord",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IGMPv3ReportDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupRecord")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IGMPv3ReportDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "GroupRecord",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **IGMPv3ReportDescriptor::getFieldPropertyNames(int field) const
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

const char *IGMPv3ReportDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IGMPv3ReportDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Report *pp = (IGMPv3Report *)object; (void)pp;
    switch (field) {
        case 0: return pp->getGroupRecordArraySize();
        default: return 0;
    }
}

const char *IGMPv3ReportDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Report *pp = (IGMPv3Report *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IGMPv3ReportDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Report *pp = (IGMPv3Report *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupRecord(i); return out.str();}
        default: return "";
    }
}

bool IGMPv3ReportDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Report *pp = (IGMPv3Report *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IGMPv3ReportDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(GroupRecord));
        default: return nullptr;
    };
}

void *IGMPv3ReportDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IGMPv3Report *pp = (IGMPv3Report *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupRecord(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

