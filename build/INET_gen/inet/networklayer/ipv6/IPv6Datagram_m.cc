//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/ipv6/IPv6Datagram.msg.
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
#include "IPv6Datagram_m.h"

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

IPv6Datagram_Base::IPv6Datagram_Base(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->trafficClass = 0;
    this->flowLabel = 0;
    this->hopLimit = 0;
    this->transportProtocol = 0;
}

IPv6Datagram_Base::IPv6Datagram_Base(const IPv6Datagram_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

IPv6Datagram_Base::~IPv6Datagram_Base()
{
}

IPv6Datagram_Base& IPv6Datagram_Base::operator=(const IPv6Datagram_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void IPv6Datagram_Base::copy(const IPv6Datagram_Base& other)
{
    this->srcAddress = other.srcAddress;
    this->destAddress = other.destAddress;
    this->trafficClass = other.trafficClass;
    this->flowLabel = other.flowLabel;
    this->hopLimit = other.hopLimit;
    this->transportProtocol = other.transportProtocol;
}

void IPv6Datagram_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcAddress);
    doParsimPacking(b,this->destAddress);
    doParsimPacking(b,this->trafficClass);
    // field diffServCodePoint is abstract -- please do packing in customized class
    // field explicitCongestionNotification is abstract -- please do packing in customized class
    doParsimPacking(b,this->flowLabel);
    doParsimPacking(b,this->hopLimit);
    doParsimPacking(b,this->transportProtocol);
    // field extensionHeader is abstract -- please do packing in customized class
}

void IPv6Datagram_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddress);
    doParsimUnpacking(b,this->destAddress);
    doParsimUnpacking(b,this->trafficClass);
    // field diffServCodePoint is abstract -- please do unpacking in customized class
    // field explicitCongestionNotification is abstract -- please do unpacking in customized class
    doParsimUnpacking(b,this->flowLabel);
    doParsimUnpacking(b,this->hopLimit);
    doParsimUnpacking(b,this->transportProtocol);
    // field extensionHeader is abstract -- please do unpacking in customized class
}

IPv6Address& IPv6Datagram_Base::getSrcAddress()
{
    return this->srcAddress;
}

void IPv6Datagram_Base::setSrcAddress(const IPv6Address& srcAddress)
{
    this->srcAddress = srcAddress;
}

IPv6Address& IPv6Datagram_Base::getDestAddress()
{
    return this->destAddress;
}

void IPv6Datagram_Base::setDestAddress(const IPv6Address& destAddress)
{
    this->destAddress = destAddress;
}

unsigned char IPv6Datagram_Base::getTrafficClass() const
{
    return this->trafficClass;
}

void IPv6Datagram_Base::setTrafficClass(unsigned char trafficClass)
{
    this->trafficClass = trafficClass;
}

unsigned int IPv6Datagram_Base::getFlowLabel() const
{
    return this->flowLabel;
}

void IPv6Datagram_Base::setFlowLabel(unsigned int flowLabel)
{
    this->flowLabel = flowLabel;
}

short IPv6Datagram_Base::getHopLimit() const
{
    return this->hopLimit;
}

void IPv6Datagram_Base::setHopLimit(short hopLimit)
{
    this->hopLimit = hopLimit;
}

int IPv6Datagram_Base::getTransportProtocol() const
{
    return this->transportProtocol;
}

void IPv6Datagram_Base::setTransportProtocol(int transportProtocol)
{
    this->transportProtocol = transportProtocol;
}

class IPv6DatagramDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6DatagramDescriptor();
    virtual ~IPv6DatagramDescriptor();

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

Register_ClassDescriptor(IPv6DatagramDescriptor)

IPv6DatagramDescriptor::IPv6DatagramDescriptor() : omnetpp::cClassDescriptor("inet::IPv6Datagram", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

IPv6DatagramDescriptor::~IPv6DatagramDescriptor()
{
    delete[] propertynames;
}

bool IPv6DatagramDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6Datagram_Base *>(obj)!=nullptr;
}

const char **IPv6DatagramDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6DatagramDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6DatagramDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int IPv6DatagramDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *IPv6DatagramDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddress",
        "destAddress",
        "trafficClass",
        "diffServCodePoint",
        "explicitCongestionNotification",
        "flowLabel",
        "hopLimit",
        "transportProtocol",
        "extensionHeader",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int IPv6DatagramDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcAddress")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destAddress")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "trafficClass")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "diffServCodePoint")==0) return base+3;
    if (fieldName[0]=='e' && strcmp(fieldName, "explicitCongestionNotification")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "flowLabel")==0) return base+5;
    if (fieldName[0]=='h' && strcmp(fieldName, "hopLimit")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "transportProtocol")==0) return base+7;
    if (fieldName[0]=='e' && strcmp(fieldName, "extensionHeader")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6DatagramDescriptor::getFieldTypeString(int field) const
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
        "unsigned char",
        "int",
        "int",
        "unsigned int",
        "short",
        "int",
        "IPv6ExtensionHeaderPtr",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6DatagramDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *IPv6DatagramDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7:
            if (!strcmp(propertyname,"enum")) return "inet::IPProtocolId";
            return nullptr;
        default: return nullptr;
    }
}

int IPv6DatagramDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6Datagram_Base *pp = (IPv6Datagram_Base *)object; (void)pp;
    switch (field) {
        case 8: return pp->getExtensionHeaderArraySize();
        default: return 0;
    }
}

const char *IPv6DatagramDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6Datagram_Base *pp = (IPv6Datagram_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6DatagramDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6Datagram_Base *pp = (IPv6Datagram_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrcAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDestAddress(); return out.str();}
        case 2: return ulong2string(pp->getTrafficClass());
        case 3: return long2string(pp->getDiffServCodePoint());
        case 4: return long2string(pp->getExplicitCongestionNotification());
        case 5: return ulong2string(pp->getFlowLabel());
        case 6: return long2string(pp->getHopLimit());
        case 7: return enum2string(pp->getTransportProtocol(), "inet::IPProtocolId");
        case 8: {std::stringstream out; out << pp->getExtensionHeader(i); return out.str();}
        default: return "";
    }
}

bool IPv6DatagramDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6Datagram_Base *pp = (IPv6Datagram_Base *)object; (void)pp;
    switch (field) {
        case 2: pp->setTrafficClass(string2ulong(value)); return true;
        case 3: pp->setDiffServCodePoint(string2long(value)); return true;
        case 4: pp->setExplicitCongestionNotification(string2long(value)); return true;
        case 5: pp->setFlowLabel(string2ulong(value)); return true;
        case 6: pp->setHopLimit(string2long(value)); return true;
        case 7: pp->setTransportProtocol((inet::IPProtocolId)string2enum(value, "inet::IPProtocolId")); return true;
        default: return false;
    }
}

const char *IPv6DatagramDescriptor::getFieldStructName(int field) const
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
        case 8: return omnetpp::opp_typename(typeid(IPv6ExtensionHeaderPtr));
        default: return nullptr;
    };
}

void *IPv6DatagramDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6Datagram_Base *pp = (IPv6Datagram_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrcAddress()); break;
        case 1: return (void *)(&pp->getDestAddress()); break;
        case 8: return (void *)(&pp->getExtensionHeader(i)); break;
        default: return nullptr;
    }
}

Register_Class(IPv6ExtensionHeader)

IPv6ExtensionHeader::IPv6ExtensionHeader() : ::omnetpp::cObject()
{
    this->extensionType = 0;
    this->byteLength = 0;
}

IPv6ExtensionHeader::IPv6ExtensionHeader(const IPv6ExtensionHeader& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

IPv6ExtensionHeader::~IPv6ExtensionHeader()
{
}

IPv6ExtensionHeader& IPv6ExtensionHeader::operator=(const IPv6ExtensionHeader& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void IPv6ExtensionHeader::copy(const IPv6ExtensionHeader& other)
{
    this->extensionType = other.extensionType;
    this->byteLength = other.byteLength;
}

void IPv6ExtensionHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->extensionType);
    doParsimPacking(b,this->byteLength);
}

void IPv6ExtensionHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->extensionType);
    doParsimUnpacking(b,this->byteLength);
}

short IPv6ExtensionHeader::getExtensionType() const
{
    return this->extensionType;
}

void IPv6ExtensionHeader::setExtensionType(short extensionType)
{
    this->extensionType = extensionType;
}

short IPv6ExtensionHeader::getByteLength() const
{
    return this->byteLength;
}

void IPv6ExtensionHeader::setByteLength(short byteLength)
{
    this->byteLength = byteLength;
}

class IPv6ExtensionHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6ExtensionHeaderDescriptor();
    virtual ~IPv6ExtensionHeaderDescriptor();

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

Register_ClassDescriptor(IPv6ExtensionHeaderDescriptor)

IPv6ExtensionHeaderDescriptor::IPv6ExtensionHeaderDescriptor() : omnetpp::cClassDescriptor("inet::IPv6ExtensionHeader", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IPv6ExtensionHeaderDescriptor::~IPv6ExtensionHeaderDescriptor()
{
    delete[] propertynames;
}

bool IPv6ExtensionHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6ExtensionHeader *>(obj)!=nullptr;
}

const char **IPv6ExtensionHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6ExtensionHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6ExtensionHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int IPv6ExtensionHeaderDescriptor::getFieldTypeFlags(int field) const
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

const char *IPv6ExtensionHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "extensionType",
        "byteLength",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int IPv6ExtensionHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "extensionType")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "byteLength")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6ExtensionHeaderDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6ExtensionHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6ExtensionHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6ExtensionHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6ExtensionHeader *pp = (IPv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6ExtensionHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6ExtensionHeader *pp = (IPv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6ExtensionHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6ExtensionHeader *pp = (IPv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getExtensionType());
        case 1: return long2string(pp->getByteLength());
        default: return "";
    }
}

bool IPv6ExtensionHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6ExtensionHeader *pp = (IPv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        case 0: pp->setExtensionType(string2long(value)); return true;
        case 1: pp->setByteLength(string2long(value)); return true;
        default: return false;
    }
}

const char *IPv6ExtensionHeaderDescriptor::getFieldStructName(int field) const
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

void *IPv6ExtensionHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6ExtensionHeader *pp = (IPv6ExtensionHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

