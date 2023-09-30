//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/icmpv6/ICMPv6Message.msg.
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
#include "ICMPv6Message_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPv6Type");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPv6Type"));
    e->insert(ICMPv6_UNSPECIFIED, "ICMPv6_UNSPECIFIED");
    e->insert(ICMPv6_DESTINATION_UNREACHABLE, "ICMPv6_DESTINATION_UNREACHABLE");
    e->insert(ICMPv6_PACKET_TOO_BIG, "ICMPv6_PACKET_TOO_BIG");
    e->insert(ICMPv6_TIME_EXCEEDED, "ICMPv6_TIME_EXCEEDED");
    e->insert(ICMPv6_PARAMETER_PROBLEM, "ICMPv6_PARAMETER_PROBLEM");
    e->insert(ICMPv6_ECHO_REQUEST, "ICMPv6_ECHO_REQUEST");
    e->insert(ICMPv6_ECHO_REPLY, "ICMPv6_ECHO_REPLY");
    e->insert(ICMPv6_MLD_QUERY, "ICMPv6_MLD_QUERY");
    e->insert(ICMPv6_MLD_REPORT, "ICMPv6_MLD_REPORT");
    e->insert(ICMPv6_MLD_DONE, "ICMPv6_MLD_DONE");
    e->insert(ICMPv6_ROUTER_SOL, "ICMPv6_ROUTER_SOL");
    e->insert(ICMPv6_ROUTER_AD, "ICMPv6_ROUTER_AD");
    e->insert(ICMPv6_NEIGHBOUR_SOL, "ICMPv6_NEIGHBOUR_SOL");
    e->insert(ICMPv6_NEIGHBOUR_AD, "ICMPv6_NEIGHBOUR_AD");
    e->insert(ICMPv6_REDIRECT, "ICMPv6_REDIRECT");
    e->insert(ICMPv6_MLDv2_REPORT, "ICMPv6_MLDv2_REPORT");
    e->insert(ICMPv6_EXPERIMENTAL_MOBILITY, "ICMPv6_EXPERIMENTAL_MOBILITY");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPv6DEST_UN");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPv6DEST_UN"));
    e->insert(NO_ROUTE_TO_DEST, "NO_ROUTE_TO_DEST");
    e->insert(COMM_WITH_DEST_PROHIBITED, "COMM_WITH_DEST_PROHIBITED");
    e->insert(ADDRESS_UNREACHABLE, "ADDRESS_UNREACHABLE");
    e->insert(PORT_UNREACHABLE, "PORT_UNREACHABLE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPv6_TIME_EX");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPv6_TIME_EX"));
    e->insert(ND_HOP_LIMIT_EXCEEDED, "ND_HOP_LIMIT_EXCEEDED");
    e->insert(ND_FRAGMENT_REASSEMBLY_TIME, "ND_FRAGMENT_REASSEMBLY_TIME");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPv6_PARAMETER_PROB");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPv6_PARAMETER_PROB"));
    e->insert(ERROREOUS_HDR_FIELD, "ERROREOUS_HDR_FIELD");
    e->insert(UNRECOGNIZED_NEXT_HDR_TYPE, "UNRECOGNIZED_NEXT_HDR_TYPE");
    e->insert(UNRECOGNIZED_IPV6_OPTION, "UNRECOGNIZED_IPV6_OPTION");
)

Register_Class(ICMPv6Message)

ICMPv6Message::ICMPv6Message(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->type = 0;
}

ICMPv6Message::ICMPv6Message(const ICMPv6Message& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

ICMPv6Message::~ICMPv6Message()
{
}

ICMPv6Message& ICMPv6Message::operator=(const ICMPv6Message& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ICMPv6Message::copy(const ICMPv6Message& other)
{
    this->type = other.type;
}

void ICMPv6Message::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
}

void ICMPv6Message::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
}

int ICMPv6Message::getType() const
{
    return this->type;
}

void ICMPv6Message::setType(int type)
{
    this->type = type;
}

class ICMPv6MessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ICMPv6MessageDescriptor();
    virtual ~ICMPv6MessageDescriptor();

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

Register_ClassDescriptor(ICMPv6MessageDescriptor)

ICMPv6MessageDescriptor::ICMPv6MessageDescriptor() : omnetpp::cClassDescriptor("inet::ICMPv6Message", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

ICMPv6MessageDescriptor::~ICMPv6MessageDescriptor()
{
    delete[] propertynames;
}

bool ICMPv6MessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMPv6Message *>(obj)!=nullptr;
}

const char **ICMPv6MessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMPv6MessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMPv6MessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ICMPv6MessageDescriptor::getFieldTypeFlags(int field) const
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

const char *ICMPv6MessageDescriptor::getFieldName(int field) const
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

int ICMPv6MessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMPv6MessageDescriptor::getFieldTypeString(int field) const
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

const char **ICMPv6MessageDescriptor::getFieldPropertyNames(int field) const
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

const char *ICMPv6MessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ICMPv6Type";
            return nullptr;
        default: return nullptr;
    }
}

int ICMPv6MessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMPv6Message *pp = (ICMPv6Message *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMPv6MessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6Message *pp = (ICMPv6Message *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMPv6MessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6Message *pp = (ICMPv6Message *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::ICMPv6Type");
        default: return "";
    }
}

bool ICMPv6MessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMPv6Message *pp = (ICMPv6Message *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::ICMPv6Type)string2enum(value, "inet::ICMPv6Type")); return true;
        default: return false;
    }
}

const char *ICMPv6MessageDescriptor::getFieldStructName(int field) const
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

void *ICMPv6MessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6Message *pp = (ICMPv6Message *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ICMPv6DestUnreachableMsg)

ICMPv6DestUnreachableMsg::ICMPv6DestUnreachableMsg(const char *name, short kind) : ::inet::ICMPv6Message(name,kind)
{
    this->code = 0;
}

ICMPv6DestUnreachableMsg::ICMPv6DestUnreachableMsg(const ICMPv6DestUnreachableMsg& other) : ::inet::ICMPv6Message(other)
{
    copy(other);
}

ICMPv6DestUnreachableMsg::~ICMPv6DestUnreachableMsg()
{
}

ICMPv6DestUnreachableMsg& ICMPv6DestUnreachableMsg::operator=(const ICMPv6DestUnreachableMsg& other)
{
    if (this==&other) return *this;
    ::inet::ICMPv6Message::operator=(other);
    copy(other);
    return *this;
}

void ICMPv6DestUnreachableMsg::copy(const ICMPv6DestUnreachableMsg& other)
{
    this->code = other.code;
}

void ICMPv6DestUnreachableMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ICMPv6Message::parsimPack(b);
    doParsimPacking(b,this->code);
}

void ICMPv6DestUnreachableMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ICMPv6Message::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
}

int ICMPv6DestUnreachableMsg::getCode() const
{
    return this->code;
}

void ICMPv6DestUnreachableMsg::setCode(int code)
{
    this->code = code;
}

class ICMPv6DestUnreachableMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ICMPv6DestUnreachableMsgDescriptor();
    virtual ~ICMPv6DestUnreachableMsgDescriptor();

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

Register_ClassDescriptor(ICMPv6DestUnreachableMsgDescriptor)

ICMPv6DestUnreachableMsgDescriptor::ICMPv6DestUnreachableMsgDescriptor() : omnetpp::cClassDescriptor("inet::ICMPv6DestUnreachableMsg", "inet::ICMPv6Message")
{
    propertynames = nullptr;
}

ICMPv6DestUnreachableMsgDescriptor::~ICMPv6DestUnreachableMsgDescriptor()
{
    delete[] propertynames;
}

bool ICMPv6DestUnreachableMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMPv6DestUnreachableMsg *>(obj)!=nullptr;
}

const char **ICMPv6DestUnreachableMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMPv6DestUnreachableMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMPv6DestUnreachableMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ICMPv6DestUnreachableMsgDescriptor::getFieldTypeFlags(int field) const
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

const char *ICMPv6DestUnreachableMsgDescriptor::getFieldName(int field) const
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

int ICMPv6DestUnreachableMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMPv6DestUnreachableMsgDescriptor::getFieldTypeString(int field) const
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

const char **ICMPv6DestUnreachableMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *ICMPv6DestUnreachableMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ICMPv6DEST_UN";
            return nullptr;
        default: return nullptr;
    }
}

int ICMPv6DestUnreachableMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMPv6DestUnreachableMsg *pp = (ICMPv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMPv6DestUnreachableMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6DestUnreachableMsg *pp = (ICMPv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMPv6DestUnreachableMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6DestUnreachableMsg *pp = (ICMPv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getCode(), "inet::ICMPv6DEST_UN");
        default: return "";
    }
}

bool ICMPv6DestUnreachableMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMPv6DestUnreachableMsg *pp = (ICMPv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode((inet::ICMPv6DEST_UN)string2enum(value, "inet::ICMPv6DEST_UN")); return true;
        default: return false;
    }
}

const char *ICMPv6DestUnreachableMsgDescriptor::getFieldStructName(int field) const
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

void *ICMPv6DestUnreachableMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6DestUnreachableMsg *pp = (ICMPv6DestUnreachableMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ICMPv6PacketTooBigMsg)

ICMPv6PacketTooBigMsg::ICMPv6PacketTooBigMsg(const char *name, short kind) : ::inet::ICMPv6Message(name,kind)
{
    this->code = 0;
    this->MTU = 0;
}

ICMPv6PacketTooBigMsg::ICMPv6PacketTooBigMsg(const ICMPv6PacketTooBigMsg& other) : ::inet::ICMPv6Message(other)
{
    copy(other);
}

ICMPv6PacketTooBigMsg::~ICMPv6PacketTooBigMsg()
{
}

ICMPv6PacketTooBigMsg& ICMPv6PacketTooBigMsg::operator=(const ICMPv6PacketTooBigMsg& other)
{
    if (this==&other) return *this;
    ::inet::ICMPv6Message::operator=(other);
    copy(other);
    return *this;
}

void ICMPv6PacketTooBigMsg::copy(const ICMPv6PacketTooBigMsg& other)
{
    this->code = other.code;
    this->MTU = other.MTU;
}

void ICMPv6PacketTooBigMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ICMPv6Message::parsimPack(b);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->MTU);
}

void ICMPv6PacketTooBigMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ICMPv6Message::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->MTU);
}

int ICMPv6PacketTooBigMsg::getCode() const
{
    return this->code;
}

void ICMPv6PacketTooBigMsg::setCode(int code)
{
    this->code = code;
}

int ICMPv6PacketTooBigMsg::getMTU() const
{
    return this->MTU;
}

void ICMPv6PacketTooBigMsg::setMTU(int MTU)
{
    this->MTU = MTU;
}

class ICMPv6PacketTooBigMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ICMPv6PacketTooBigMsgDescriptor();
    virtual ~ICMPv6PacketTooBigMsgDescriptor();

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

Register_ClassDescriptor(ICMPv6PacketTooBigMsgDescriptor)

ICMPv6PacketTooBigMsgDescriptor::ICMPv6PacketTooBigMsgDescriptor() : omnetpp::cClassDescriptor("inet::ICMPv6PacketTooBigMsg", "inet::ICMPv6Message")
{
    propertynames = nullptr;
}

ICMPv6PacketTooBigMsgDescriptor::~ICMPv6PacketTooBigMsgDescriptor()
{
    delete[] propertynames;
}

bool ICMPv6PacketTooBigMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMPv6PacketTooBigMsg *>(obj)!=nullptr;
}

const char **ICMPv6PacketTooBigMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMPv6PacketTooBigMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMPv6PacketTooBigMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int ICMPv6PacketTooBigMsgDescriptor::getFieldTypeFlags(int field) const
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

const char *ICMPv6PacketTooBigMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
        "MTU",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int ICMPv6PacketTooBigMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    if (fieldName[0]=='M' && strcmp(fieldName, "MTU")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMPv6PacketTooBigMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **ICMPv6PacketTooBigMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *ICMPv6PacketTooBigMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ICMPv6PacketTooBigMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMPv6PacketTooBigMsg *pp = (ICMPv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMPv6PacketTooBigMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6PacketTooBigMsg *pp = (ICMPv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMPv6PacketTooBigMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6PacketTooBigMsg *pp = (ICMPv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCode());
        case 1: return long2string(pp->getMTU());
        default: return "";
    }
}

bool ICMPv6PacketTooBigMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMPv6PacketTooBigMsg *pp = (ICMPv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode(string2long(value)); return true;
        case 1: pp->setMTU(string2long(value)); return true;
        default: return false;
    }
}

const char *ICMPv6PacketTooBigMsgDescriptor::getFieldStructName(int field) const
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

void *ICMPv6PacketTooBigMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6PacketTooBigMsg *pp = (ICMPv6PacketTooBigMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ICMPv6TimeExceededMsg)

ICMPv6TimeExceededMsg::ICMPv6TimeExceededMsg(const char *name, short kind) : ::inet::ICMPv6Message(name,kind)
{
    this->code = 0;
}

ICMPv6TimeExceededMsg::ICMPv6TimeExceededMsg(const ICMPv6TimeExceededMsg& other) : ::inet::ICMPv6Message(other)
{
    copy(other);
}

ICMPv6TimeExceededMsg::~ICMPv6TimeExceededMsg()
{
}

ICMPv6TimeExceededMsg& ICMPv6TimeExceededMsg::operator=(const ICMPv6TimeExceededMsg& other)
{
    if (this==&other) return *this;
    ::inet::ICMPv6Message::operator=(other);
    copy(other);
    return *this;
}

void ICMPv6TimeExceededMsg::copy(const ICMPv6TimeExceededMsg& other)
{
    this->code = other.code;
}

void ICMPv6TimeExceededMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ICMPv6Message::parsimPack(b);
    doParsimPacking(b,this->code);
}

void ICMPv6TimeExceededMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ICMPv6Message::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
}

int ICMPv6TimeExceededMsg::getCode() const
{
    return this->code;
}

void ICMPv6TimeExceededMsg::setCode(int code)
{
    this->code = code;
}

class ICMPv6TimeExceededMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ICMPv6TimeExceededMsgDescriptor();
    virtual ~ICMPv6TimeExceededMsgDescriptor();

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

Register_ClassDescriptor(ICMPv6TimeExceededMsgDescriptor)

ICMPv6TimeExceededMsgDescriptor::ICMPv6TimeExceededMsgDescriptor() : omnetpp::cClassDescriptor("inet::ICMPv6TimeExceededMsg", "inet::ICMPv6Message")
{
    propertynames = nullptr;
}

ICMPv6TimeExceededMsgDescriptor::~ICMPv6TimeExceededMsgDescriptor()
{
    delete[] propertynames;
}

bool ICMPv6TimeExceededMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMPv6TimeExceededMsg *>(obj)!=nullptr;
}

const char **ICMPv6TimeExceededMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMPv6TimeExceededMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMPv6TimeExceededMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ICMPv6TimeExceededMsgDescriptor::getFieldTypeFlags(int field) const
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

const char *ICMPv6TimeExceededMsgDescriptor::getFieldName(int field) const
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

int ICMPv6TimeExceededMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMPv6TimeExceededMsgDescriptor::getFieldTypeString(int field) const
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

const char **ICMPv6TimeExceededMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *ICMPv6TimeExceededMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ICMPv6_TIME_EX";
            return nullptr;
        default: return nullptr;
    }
}

int ICMPv6TimeExceededMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMPv6TimeExceededMsg *pp = (ICMPv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMPv6TimeExceededMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6TimeExceededMsg *pp = (ICMPv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMPv6TimeExceededMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6TimeExceededMsg *pp = (ICMPv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getCode(), "inet::ICMPv6_TIME_EX");
        default: return "";
    }
}

bool ICMPv6TimeExceededMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMPv6TimeExceededMsg *pp = (ICMPv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode((inet::ICMPv6_TIME_EX)string2enum(value, "inet::ICMPv6_TIME_EX")); return true;
        default: return false;
    }
}

const char *ICMPv6TimeExceededMsgDescriptor::getFieldStructName(int field) const
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

void *ICMPv6TimeExceededMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6TimeExceededMsg *pp = (ICMPv6TimeExceededMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ICMPv6ParamProblemMsg)

ICMPv6ParamProblemMsg::ICMPv6ParamProblemMsg(const char *name, short kind) : ::inet::ICMPv6Message(name,kind)
{
    this->code = 0;
}

ICMPv6ParamProblemMsg::ICMPv6ParamProblemMsg(const ICMPv6ParamProblemMsg& other) : ::inet::ICMPv6Message(other)
{
    copy(other);
}

ICMPv6ParamProblemMsg::~ICMPv6ParamProblemMsg()
{
}

ICMPv6ParamProblemMsg& ICMPv6ParamProblemMsg::operator=(const ICMPv6ParamProblemMsg& other)
{
    if (this==&other) return *this;
    ::inet::ICMPv6Message::operator=(other);
    copy(other);
    return *this;
}

void ICMPv6ParamProblemMsg::copy(const ICMPv6ParamProblemMsg& other)
{
    this->code = other.code;
}

void ICMPv6ParamProblemMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ICMPv6Message::parsimPack(b);
    doParsimPacking(b,this->code);
}

void ICMPv6ParamProblemMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ICMPv6Message::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
}

int ICMPv6ParamProblemMsg::getCode() const
{
    return this->code;
}

void ICMPv6ParamProblemMsg::setCode(int code)
{
    this->code = code;
}

class ICMPv6ParamProblemMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ICMPv6ParamProblemMsgDescriptor();
    virtual ~ICMPv6ParamProblemMsgDescriptor();

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

Register_ClassDescriptor(ICMPv6ParamProblemMsgDescriptor)

ICMPv6ParamProblemMsgDescriptor::ICMPv6ParamProblemMsgDescriptor() : omnetpp::cClassDescriptor("inet::ICMPv6ParamProblemMsg", "inet::ICMPv6Message")
{
    propertynames = nullptr;
}

ICMPv6ParamProblemMsgDescriptor::~ICMPv6ParamProblemMsgDescriptor()
{
    delete[] propertynames;
}

bool ICMPv6ParamProblemMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMPv6ParamProblemMsg *>(obj)!=nullptr;
}

const char **ICMPv6ParamProblemMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMPv6ParamProblemMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMPv6ParamProblemMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int ICMPv6ParamProblemMsgDescriptor::getFieldTypeFlags(int field) const
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

const char *ICMPv6ParamProblemMsgDescriptor::getFieldName(int field) const
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

int ICMPv6ParamProblemMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMPv6ParamProblemMsgDescriptor::getFieldTypeString(int field) const
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

const char **ICMPv6ParamProblemMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *ICMPv6ParamProblemMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ICMPv6_PARAMETER_PROB";
            return nullptr;
        default: return nullptr;
    }
}

int ICMPv6ParamProblemMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMPv6ParamProblemMsg *pp = (ICMPv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMPv6ParamProblemMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6ParamProblemMsg *pp = (ICMPv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMPv6ParamProblemMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6ParamProblemMsg *pp = (ICMPv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getCode(), "inet::ICMPv6_PARAMETER_PROB");
        default: return "";
    }
}

bool ICMPv6ParamProblemMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMPv6ParamProblemMsg *pp = (ICMPv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode((inet::ICMPv6_PARAMETER_PROB)string2enum(value, "inet::ICMPv6_PARAMETER_PROB")); return true;
        default: return false;
    }
}

const char *ICMPv6ParamProblemMsgDescriptor::getFieldStructName(int field) const
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

void *ICMPv6ParamProblemMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6ParamProblemMsg *pp = (ICMPv6ParamProblemMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ICMPv6EchoRequestMsg)

ICMPv6EchoRequestMsg::ICMPv6EchoRequestMsg(const char *name, short kind) : ::inet::ICMPv6Message(name,kind)
{
    this->code = 0;
    this->identifier = 0;
    this->seqNumber = 0;
}

ICMPv6EchoRequestMsg::ICMPv6EchoRequestMsg(const ICMPv6EchoRequestMsg& other) : ::inet::ICMPv6Message(other)
{
    copy(other);
}

ICMPv6EchoRequestMsg::~ICMPv6EchoRequestMsg()
{
}

ICMPv6EchoRequestMsg& ICMPv6EchoRequestMsg::operator=(const ICMPv6EchoRequestMsg& other)
{
    if (this==&other) return *this;
    ::inet::ICMPv6Message::operator=(other);
    copy(other);
    return *this;
}

void ICMPv6EchoRequestMsg::copy(const ICMPv6EchoRequestMsg& other)
{
    this->code = other.code;
    this->identifier = other.identifier;
    this->seqNumber = other.seqNumber;
}

void ICMPv6EchoRequestMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ICMPv6Message::parsimPack(b);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->identifier);
    doParsimPacking(b,this->seqNumber);
}

void ICMPv6EchoRequestMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ICMPv6Message::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->identifier);
    doParsimUnpacking(b,this->seqNumber);
}

int ICMPv6EchoRequestMsg::getCode() const
{
    return this->code;
}

void ICMPv6EchoRequestMsg::setCode(int code)
{
    this->code = code;
}

int ICMPv6EchoRequestMsg::getIdentifier() const
{
    return this->identifier;
}

void ICMPv6EchoRequestMsg::setIdentifier(int identifier)
{
    this->identifier = identifier;
}

int ICMPv6EchoRequestMsg::getSeqNumber() const
{
    return this->seqNumber;
}

void ICMPv6EchoRequestMsg::setSeqNumber(int seqNumber)
{
    this->seqNumber = seqNumber;
}

class ICMPv6EchoRequestMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ICMPv6EchoRequestMsgDescriptor();
    virtual ~ICMPv6EchoRequestMsgDescriptor();

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

Register_ClassDescriptor(ICMPv6EchoRequestMsgDescriptor)

ICMPv6EchoRequestMsgDescriptor::ICMPv6EchoRequestMsgDescriptor() : omnetpp::cClassDescriptor("inet::ICMPv6EchoRequestMsg", "inet::ICMPv6Message")
{
    propertynames = nullptr;
}

ICMPv6EchoRequestMsgDescriptor::~ICMPv6EchoRequestMsgDescriptor()
{
    delete[] propertynames;
}

bool ICMPv6EchoRequestMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMPv6EchoRequestMsg *>(obj)!=nullptr;
}

const char **ICMPv6EchoRequestMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMPv6EchoRequestMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMPv6EchoRequestMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int ICMPv6EchoRequestMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *ICMPv6EchoRequestMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
        "identifier",
        "seqNumber",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int ICMPv6EchoRequestMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "identifier")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNumber")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMPv6EchoRequestMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **ICMPv6EchoRequestMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *ICMPv6EchoRequestMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ICMPv6EchoRequestMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoRequestMsg *pp = (ICMPv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMPv6EchoRequestMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoRequestMsg *pp = (ICMPv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMPv6EchoRequestMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoRequestMsg *pp = (ICMPv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCode());
        case 1: return long2string(pp->getIdentifier());
        case 2: return long2string(pp->getSeqNumber());
        default: return "";
    }
}

bool ICMPv6EchoRequestMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoRequestMsg *pp = (ICMPv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode(string2long(value)); return true;
        case 1: pp->setIdentifier(string2long(value)); return true;
        case 2: pp->setSeqNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *ICMPv6EchoRequestMsgDescriptor::getFieldStructName(int field) const
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

void *ICMPv6EchoRequestMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoRequestMsg *pp = (ICMPv6EchoRequestMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(ICMPv6EchoReplyMsg)

ICMPv6EchoReplyMsg::ICMPv6EchoReplyMsg(const char *name, short kind) : ::inet::ICMPv6Message(name,kind)
{
    this->code = 0;
    this->identifier = 0;
    this->seqNumber = 0;
}

ICMPv6EchoReplyMsg::ICMPv6EchoReplyMsg(const ICMPv6EchoReplyMsg& other) : ::inet::ICMPv6Message(other)
{
    copy(other);
}

ICMPv6EchoReplyMsg::~ICMPv6EchoReplyMsg()
{
}

ICMPv6EchoReplyMsg& ICMPv6EchoReplyMsg::operator=(const ICMPv6EchoReplyMsg& other)
{
    if (this==&other) return *this;
    ::inet::ICMPv6Message::operator=(other);
    copy(other);
    return *this;
}

void ICMPv6EchoReplyMsg::copy(const ICMPv6EchoReplyMsg& other)
{
    this->code = other.code;
    this->identifier = other.identifier;
    this->seqNumber = other.seqNumber;
}

void ICMPv6EchoReplyMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ICMPv6Message::parsimPack(b);
    doParsimPacking(b,this->code);
    doParsimPacking(b,this->identifier);
    doParsimPacking(b,this->seqNumber);
}

void ICMPv6EchoReplyMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ICMPv6Message::parsimUnpack(b);
    doParsimUnpacking(b,this->code);
    doParsimUnpacking(b,this->identifier);
    doParsimUnpacking(b,this->seqNumber);
}

int ICMPv6EchoReplyMsg::getCode() const
{
    return this->code;
}

void ICMPv6EchoReplyMsg::setCode(int code)
{
    this->code = code;
}

int ICMPv6EchoReplyMsg::getIdentifier() const
{
    return this->identifier;
}

void ICMPv6EchoReplyMsg::setIdentifier(int identifier)
{
    this->identifier = identifier;
}

int ICMPv6EchoReplyMsg::getSeqNumber() const
{
    return this->seqNumber;
}

void ICMPv6EchoReplyMsg::setSeqNumber(int seqNumber)
{
    this->seqNumber = seqNumber;
}

class ICMPv6EchoReplyMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ICMPv6EchoReplyMsgDescriptor();
    virtual ~ICMPv6EchoReplyMsgDescriptor();

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

Register_ClassDescriptor(ICMPv6EchoReplyMsgDescriptor)

ICMPv6EchoReplyMsgDescriptor::ICMPv6EchoReplyMsgDescriptor() : omnetpp::cClassDescriptor("inet::ICMPv6EchoReplyMsg", "inet::ICMPv6Message")
{
    propertynames = nullptr;
}

ICMPv6EchoReplyMsgDescriptor::~ICMPv6EchoReplyMsgDescriptor()
{
    delete[] propertynames;
}

bool ICMPv6EchoReplyMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMPv6EchoReplyMsg *>(obj)!=nullptr;
}

const char **ICMPv6EchoReplyMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMPv6EchoReplyMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMPv6EchoReplyMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int ICMPv6EchoReplyMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *ICMPv6EchoReplyMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "code",
        "identifier",
        "seqNumber",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int ICMPv6EchoReplyMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "identifier")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNumber")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMPv6EchoReplyMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **ICMPv6EchoReplyMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *ICMPv6EchoReplyMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ICMPv6EchoReplyMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoReplyMsg *pp = (ICMPv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMPv6EchoReplyMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoReplyMsg *pp = (ICMPv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMPv6EchoReplyMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoReplyMsg *pp = (ICMPv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCode());
        case 1: return long2string(pp->getIdentifier());
        case 2: return long2string(pp->getSeqNumber());
        default: return "";
    }
}

bool ICMPv6EchoReplyMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoReplyMsg *pp = (ICMPv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setCode(string2long(value)); return true;
        case 1: pp->setIdentifier(string2long(value)); return true;
        case 2: pp->setSeqNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *ICMPv6EchoReplyMsgDescriptor::getFieldStructName(int field) const
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

void *ICMPv6EchoReplyMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMPv6EchoReplyMsg *pp = (ICMPv6EchoReplyMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

