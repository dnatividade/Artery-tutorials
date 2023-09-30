//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/arp/ipv4/ARPPacket.msg.
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
#include "ARPPacket_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ARPOpcode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ARPOpcode"));
    e->insert(ARP_REQUEST, "ARP_REQUEST");
    e->insert(ARP_REPLY, "ARP_REPLY");
    e->insert(ARP_RARP_REQUEST, "ARP_RARP_REQUEST");
    e->insert(ARP_RARP_REPLY, "ARP_RARP_REPLY");
)

Register_Class(ARPPacket)

ARPPacket::ARPPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->opcode = 0;
}

ARPPacket::ARPPacket(const ARPPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

ARPPacket::~ARPPacket()
{
}

ARPPacket& ARPPacket::operator=(const ARPPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ARPPacket::copy(const ARPPacket& other)
{
    this->opcode = other.opcode;
    this->srcMACAddress = other.srcMACAddress;
    this->destMACAddress = other.destMACAddress;
    this->srcIPAddress = other.srcIPAddress;
    this->destIPAddress = other.destIPAddress;
}

void ARPPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->opcode);
    doParsimPacking(b,this->srcMACAddress);
    doParsimPacking(b,this->destMACAddress);
    doParsimPacking(b,this->srcIPAddress);
    doParsimPacking(b,this->destIPAddress);
}

void ARPPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->opcode);
    doParsimUnpacking(b,this->srcMACAddress);
    doParsimUnpacking(b,this->destMACAddress);
    doParsimUnpacking(b,this->srcIPAddress);
    doParsimUnpacking(b,this->destIPAddress);
}

int ARPPacket::getOpcode() const
{
    return this->opcode;
}

void ARPPacket::setOpcode(int opcode)
{
    this->opcode = opcode;
}

MACAddress& ARPPacket::getSrcMACAddress()
{
    return this->srcMACAddress;
}

void ARPPacket::setSrcMACAddress(const MACAddress& srcMACAddress)
{
    this->srcMACAddress = srcMACAddress;
}

MACAddress& ARPPacket::getDestMACAddress()
{
    return this->destMACAddress;
}

void ARPPacket::setDestMACAddress(const MACAddress& destMACAddress)
{
    this->destMACAddress = destMACAddress;
}

IPv4Address& ARPPacket::getSrcIPAddress()
{
    return this->srcIPAddress;
}

void ARPPacket::setSrcIPAddress(const IPv4Address& srcIPAddress)
{
    this->srcIPAddress = srcIPAddress;
}

IPv4Address& ARPPacket::getDestIPAddress()
{
    return this->destIPAddress;
}

void ARPPacket::setDestIPAddress(const IPv4Address& destIPAddress)
{
    this->destIPAddress = destIPAddress;
}

class ARPPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ARPPacketDescriptor();
    virtual ~ARPPacketDescriptor();

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

Register_ClassDescriptor(ARPPacketDescriptor)

ARPPacketDescriptor::ARPPacketDescriptor() : omnetpp::cClassDescriptor("inet::ARPPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

ARPPacketDescriptor::~ARPPacketDescriptor()
{
    delete[] propertynames;
}

bool ARPPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ARPPacket *>(obj)!=nullptr;
}

const char **ARPPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ARPPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ARPPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int ARPPacketDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *ARPPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "opcode",
        "srcMACAddress",
        "destMACAddress",
        "srcIPAddress",
        "destIPAddress",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int ARPPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "opcode")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcMACAddress")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "destMACAddress")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcIPAddress")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destIPAddress")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ARPPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "MACAddress",
        "MACAddress",
        "IPv4Address",
        "IPv4Address",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **ARPPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *ARPPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ARPOpcode";
            return nullptr;
        default: return nullptr;
    }
}

int ARPPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ARPPacket *pp = (ARPPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ARPPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ARPPacket *pp = (ARPPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ARPPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ARPPacket *pp = (ARPPacket *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getOpcode(), "inet::ARPOpcode");
        case 1: {std::stringstream out; out << pp->getSrcMACAddress(); return out.str();}
        case 2: {std::stringstream out; out << pp->getDestMACAddress(); return out.str();}
        case 3: {std::stringstream out; out << pp->getSrcIPAddress(); return out.str();}
        case 4: {std::stringstream out; out << pp->getDestIPAddress(); return out.str();}
        default: return "";
    }
}

bool ARPPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ARPPacket *pp = (ARPPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setOpcode((inet::ARPOpcode)string2enum(value, "inet::ARPOpcode")); return true;
        default: return false;
    }
}

const char *ARPPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(MACAddress));
        case 2: return omnetpp::opp_typename(typeid(MACAddress));
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        case 4: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *ARPPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ARPPacket *pp = (ARPPacket *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getSrcMACAddress()); break;
        case 2: return (void *)(&pp->getDestMACAddress()); break;
        case 3: return (void *)(&pp->getSrcIPAddress()); break;
        case 4: return (void *)(&pp->getDestIPAddress()); break;
        default: return nullptr;
    }
}

} // namespace inet

