//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/ipv4/ICMPMessage.msg.
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
#include "ICMPMessage_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPType"));
    e->insert(ICMP_DESTINATION_UNREACHABLE, "ICMP_DESTINATION_UNREACHABLE");
    e->insert(ICMP_SOURCEQUENCH, "ICMP_SOURCEQUENCH");
    e->insert(ICMP_REDIRECT, "ICMP_REDIRECT");
    e->insert(ICMP_ECHO_REQUEST, "ICMP_ECHO_REQUEST");
    e->insert(ICMP_ROUTER_ADVERTISEMENT, "ICMP_ROUTER_ADVERTISEMENT");
    e->insert(ICMP_ROUTER_SOLICITATION, "ICMP_ROUTER_SOLICITATION");
    e->insert(ICMP_TIME_EXCEEDED, "ICMP_TIME_EXCEEDED");
    e->insert(ICMP_PARAMETER_PROBLEM, "ICMP_PARAMETER_PROBLEM");
    e->insert(ICMP_ECHO_REPLY, "ICMP_ECHO_REPLY");
    e->insert(ICMP_TIMESTAMP_REQUEST, "ICMP_TIMESTAMP_REQUEST");
    e->insert(ICMP_TIMESTAMP_REPLY, "ICMP_TIMESTAMP_REPLY");
    e->insert(ICMP_INFORMATION_REQUEST, "ICMP_INFORMATION_REQUEST");
    e->insert(ICMP_INFORMATION_REPLY, "ICMP_INFORMATION_REPLY");
    e->insert(ICMP_MASK_REQUEST, "ICMP_MASK_REQUEST");
    e->insert(ICMP_MASK_REPLY, "ICMP_MASK_REPLY");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPRedirectSubcodes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPRedirectSubcodes"));
    e->insert(ICMP_REDIRECT_NET, "ICMP_REDIRECT_NET");
    e->insert(ICMP_REDIRECT_HOST, "ICMP_REDIRECT_HOST");
    e->insert(ICMP_REDIRECT_TOSNET, "ICMP_REDIRECT_TOSNET");
    e->insert(ICMP_REDIRECT_TOSHOST, "ICMP_REDIRECT_TOSHOST");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPTimeExceededSubcodes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPTimeExceededSubcodes"));
    e->insert(ICMP_TIMXCEED_INTRANS, "ICMP_TIMXCEED_INTRANS");
    e->insert(ICMP_TIMXCEED_REASS, "ICMP_TIMXCEED_REASS");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPParameterProblemSubcodes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPParameterProblemSubcodes"));
    e->insert(ICMP_PARAMPROB_ERRATPTR, "ICMP_PARAMPROB_ERRATPTR");
    e->insert(ICMP_PARAMPROB_OPTABSENT, "ICMP_PARAMPROB_OPTABSENT");
    e->insert(ICMP_PARAMPROB_LENGTH, "ICMP_PARAMPROB_LENGTH");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ICMPDestinationUnreachableCodes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ICMPDestinationUnreachableCodes"));
    e->insert(ICMP_DU_NETWORK_UNREACHABLE, "ICMP_DU_NETWORK_UNREACHABLE");
    e->insert(ICMP_DU_HOST_UNREACHABLE, "ICMP_DU_HOST_UNREACHABLE");
    e->insert(ICMP_DU_PROTOCOL_UNREACHABLE, "ICMP_DU_PROTOCOL_UNREACHABLE");
    e->insert(ICMP_DU_PORT_UNREACHABLE, "ICMP_DU_PORT_UNREACHABLE");
    e->insert(ICMP_DU_FRAGMENTATION_NEEDED, "ICMP_DU_FRAGMENTATION_NEEDED");
    e->insert(ICMP_DU_SOURCE_ROUTE_FAILED, "ICMP_DU_SOURCE_ROUTE_FAILED");
    e->insert(ICMP_DU_DESTINATION_NETWORK_UNKNOWN, "ICMP_DU_DESTINATION_NETWORK_UNKNOWN");
    e->insert(ICMP_DU_DESTINATION_HOST_UNKNOWN, "ICMP_DU_DESTINATION_HOST_UNKNOWN");
    e->insert(ICMP_DU_SOURCE_HOST_ISOLATED, "ICMP_DU_SOURCE_HOST_ISOLATED");
    e->insert(ICMP_DU_NETWORK_PROHIBITED, "ICMP_DU_NETWORK_PROHIBITED");
    e->insert(ICMP_DU_HOST_PROHIBITED, "ICMP_DU_HOST_PROHIBITED");
    e->insert(ICMP_DU_NETWORK_UNREACHABLE_FOR_TYPE_OF_SERVICE, "ICMP_DU_NETWORK_UNREACHABLE_FOR_TYPE_OF_SERVICE");
    e->insert(ICMP_DU_HOST_UNREACHABLE_FOR_TYPE_OF_SERVICE, "ICMP_DU_HOST_UNREACHABLE_FOR_TYPE_OF_SERVICE");
    e->insert(ICMP_DU_COMMUNICATION_PROHIBITED, "ICMP_DU_COMMUNICATION_PROHIBITED");
    e->insert(ICMP_DU_HOST_PRECEDENCE_VIOLATION, "ICMP_DU_HOST_PRECEDENCE_VIOLATION");
    e->insert(ICMP_DU_PRECEDENCE_CUTOFF_IN_EFFECT, "ICMP_DU_PRECEDENCE_CUTOFF_IN_EFFECT");
    e->insert(ICMP_AODV_QUEUE_FULL, "ICMP_AODV_QUEUE_FULL");
)

Register_Class(ICMPMessage)

ICMPMessage::ICMPMessage(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->type = 0;
    this->code = 0;
}

ICMPMessage::ICMPMessage(const ICMPMessage& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

ICMPMessage::~ICMPMessage()
{
}

ICMPMessage& ICMPMessage::operator=(const ICMPMessage& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ICMPMessage::copy(const ICMPMessage& other)
{
    this->type = other.type;
    this->code = other.code;
}

void ICMPMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->code);
}

void ICMPMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->code);
}

int ICMPMessage::getType() const
{
    return this->type;
}

void ICMPMessage::setType(int type)
{
    this->type = type;
}

int ICMPMessage::getCode() const
{
    return this->code;
}

void ICMPMessage::setCode(int code)
{
    this->code = code;
}

class ICMPMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ICMPMessageDescriptor();
    virtual ~ICMPMessageDescriptor();

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

Register_ClassDescriptor(ICMPMessageDescriptor)

ICMPMessageDescriptor::ICMPMessageDescriptor() : omnetpp::cClassDescriptor("inet::ICMPMessage", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

ICMPMessageDescriptor::~ICMPMessageDescriptor()
{
    delete[] propertynames;
}

bool ICMPMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ICMPMessage *>(obj)!=nullptr;
}

const char **ICMPMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ICMPMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ICMPMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int ICMPMessageDescriptor::getFieldTypeFlags(int field) const
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

const char *ICMPMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "code",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int ICMPMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "code")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ICMPMessageDescriptor::getFieldTypeString(int field) const
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

const char **ICMPMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *ICMPMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ICMPType";
            return nullptr;
        default: return nullptr;
    }
}

int ICMPMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ICMPMessage *pp = (ICMPMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ICMPMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPMessage *pp = (ICMPMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ICMPMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ICMPMessage *pp = (ICMPMessage *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::ICMPType");
        case 1: return long2string(pp->getCode());
        default: return "";
    }
}

bool ICMPMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ICMPMessage *pp = (ICMPMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::ICMPType)string2enum(value, "inet::ICMPType")); return true;
        case 1: pp->setCode(string2long(value)); return true;
        default: return false;
    }
}

const char *ICMPMessageDescriptor::getFieldStructName(int field) const
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

void *ICMPMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ICMPMessage *pp = (ICMPMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

