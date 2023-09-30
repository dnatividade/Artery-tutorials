//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/ipv6/IPv6ExtensionHeaders.msg.
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
#include "IPv6ExtensionHeaders_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::IPv6TLVOptionTypes");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::IPv6TLVOptionTypes"));
    e->insert(IPv6TLVOPTION_NOP1, "IPv6TLVOPTION_NOP1");
    e->insert(IPv6TLVOPTION_NOPN, "IPv6TLVOPTION_NOPN");
    e->insert(IPv6TLVOPTION_TLV_GPSR, "IPv6TLVOPTION_TLV_GPSR");
)

IPv6HopByHopOptionsHeader::IPv6HopByHopOptionsHeader() : ::inet::IPv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_HOP);

}

IPv6HopByHopOptionsHeader::IPv6HopByHopOptionsHeader(const IPv6HopByHopOptionsHeader& other) : ::inet::IPv6ExtensionHeader(other)
{
    copy(other);
}

IPv6HopByHopOptionsHeader::~IPv6HopByHopOptionsHeader()
{
}

IPv6HopByHopOptionsHeader& IPv6HopByHopOptionsHeader::operator=(const IPv6HopByHopOptionsHeader& other)
{
    if (this==&other) return *this;
    ::inet::IPv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void IPv6HopByHopOptionsHeader::copy(const IPv6HopByHopOptionsHeader& other)
{
    this->tlvOptions = other.tlvOptions;
}

void IPv6HopByHopOptionsHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv6ExtensionHeader&)*this);
    doParsimPacking(b,this->tlvOptions);
}

void IPv6HopByHopOptionsHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv6ExtensionHeader&)*this);
    doParsimUnpacking(b,this->tlvOptions);
}

TLVOptions& IPv6HopByHopOptionsHeader::getTlvOptions()
{
    return this->tlvOptions;
}

void IPv6HopByHopOptionsHeader::setTlvOptions(const TLVOptions& tlvOptions)
{
    this->tlvOptions = tlvOptions;
}

class IPv6HopByHopOptionsHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6HopByHopOptionsHeaderDescriptor();
    virtual ~IPv6HopByHopOptionsHeaderDescriptor();

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

Register_ClassDescriptor(IPv6HopByHopOptionsHeaderDescriptor)

IPv6HopByHopOptionsHeaderDescriptor::IPv6HopByHopOptionsHeaderDescriptor() : omnetpp::cClassDescriptor("inet::IPv6HopByHopOptionsHeader", "inet::IPv6ExtensionHeader")
{
    propertynames = nullptr;
}

IPv6HopByHopOptionsHeaderDescriptor::~IPv6HopByHopOptionsHeaderDescriptor()
{
    delete[] propertynames;
}

bool IPv6HopByHopOptionsHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6HopByHopOptionsHeader *>(obj)!=nullptr;
}

const char **IPv6HopByHopOptionsHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6HopByHopOptionsHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6HopByHopOptionsHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IPv6HopByHopOptionsHeaderDescriptor::getFieldTypeFlags(int field) const
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

const char *IPv6HopByHopOptionsHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tlvOptions",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IPv6HopByHopOptionsHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tlvOptions")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6HopByHopOptionsHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "TLVOptions",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6HopByHopOptionsHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6HopByHopOptionsHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6HopByHopOptionsHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6HopByHopOptionsHeader *pp = (IPv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6HopByHopOptionsHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6HopByHopOptionsHeader *pp = (IPv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6HopByHopOptionsHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6HopByHopOptionsHeader *pp = (IPv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getTlvOptions(); return out.str();}
        default: return "";
    }
}

bool IPv6HopByHopOptionsHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6HopByHopOptionsHeader *pp = (IPv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv6HopByHopOptionsHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(TLVOptions));
        default: return nullptr;
    };
}

void *IPv6HopByHopOptionsHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6HopByHopOptionsHeader *pp = (IPv6HopByHopOptionsHeader *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getTlvOptions()); break;
        default: return nullptr;
    }
}

IPv6RoutingHeader_Base::IPv6RoutingHeader_Base() : ::inet::IPv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_ROUTING);
    this->setByteLength(8);

    this->routingType = 0;
    this->segmentsLeft = 0;
    address_arraysize = 0;
    this->address = 0;
}

IPv6RoutingHeader_Base::IPv6RoutingHeader_Base(const IPv6RoutingHeader_Base& other) : ::inet::IPv6ExtensionHeader(other)
{
    address_arraysize = 0;
    this->address = 0;
    copy(other);
}

IPv6RoutingHeader_Base::~IPv6RoutingHeader_Base()
{
    delete [] this->address;
}

IPv6RoutingHeader_Base& IPv6RoutingHeader_Base::operator=(const IPv6RoutingHeader_Base& other)
{
    if (this==&other) return *this;
    ::inet::IPv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void IPv6RoutingHeader_Base::copy(const IPv6RoutingHeader_Base& other)
{
    this->routingType = other.routingType;
    this->segmentsLeft = other.segmentsLeft;
    delete [] this->address;
    this->address = (other.address_arraysize==0) ? nullptr : new IPv6Address[other.address_arraysize];
    address_arraysize = other.address_arraysize;
    for (unsigned int i=0; i<address_arraysize; i++)
        this->address[i] = other.address[i];
}

void IPv6RoutingHeader_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv6ExtensionHeader&)*this);
    doParsimPacking(b,this->routingType);
    doParsimPacking(b,this->segmentsLeft);
    b->pack(address_arraysize);
    doParsimArrayPacking(b,this->address,address_arraysize);
}

void IPv6RoutingHeader_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv6ExtensionHeader&)*this);
    doParsimUnpacking(b,this->routingType);
    doParsimUnpacking(b,this->segmentsLeft);
    delete [] this->address;
    b->unpack(address_arraysize);
    if (address_arraysize==0) {
        this->address = 0;
    } else {
        this->address = new IPv6Address[address_arraysize];
        doParsimArrayUnpacking(b,this->address,address_arraysize);
    }
}

uint8_t IPv6RoutingHeader_Base::getRoutingType() const
{
    return this->routingType;
}

void IPv6RoutingHeader_Base::setRoutingType(uint8_t routingType)
{
    this->routingType = routingType;
}

uint8_t IPv6RoutingHeader_Base::getSegmentsLeft() const
{
    return this->segmentsLeft;
}

void IPv6RoutingHeader_Base::setSegmentsLeft(uint8_t segmentsLeft)
{
    this->segmentsLeft = segmentsLeft;
}

void IPv6RoutingHeader_Base::setAddressArraySize(unsigned int size)
{
    IPv6Address *address2 = (size==0) ? nullptr : new IPv6Address[size];
    unsigned int sz = address_arraysize < size ? address_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        address2[i] = this->address[i];
    address_arraysize = size;
    delete [] this->address;
    this->address = address2;
}

unsigned int IPv6RoutingHeader_Base::getAddressArraySize() const
{
    return address_arraysize;
}

IPv6Address& IPv6RoutingHeader_Base::getAddress(unsigned int k)
{
    if (k>=address_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", address_arraysize, k);
    return this->address[k];
}

void IPv6RoutingHeader_Base::setAddress(unsigned int k, const IPv6Address& address)
{
    if (k>=address_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", address_arraysize, k);
    this->address[k] = address;
}

class IPv6RoutingHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6RoutingHeaderDescriptor();
    virtual ~IPv6RoutingHeaderDescriptor();

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

Register_ClassDescriptor(IPv6RoutingHeaderDescriptor)

IPv6RoutingHeaderDescriptor::IPv6RoutingHeaderDescriptor() : omnetpp::cClassDescriptor("inet::IPv6RoutingHeader", "inet::IPv6ExtensionHeader")
{
    propertynames = nullptr;
}

IPv6RoutingHeaderDescriptor::~IPv6RoutingHeaderDescriptor()
{
    delete[] propertynames;
}

bool IPv6RoutingHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6RoutingHeader_Base *>(obj)!=nullptr;
}

const char **IPv6RoutingHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6RoutingHeaderDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6RoutingHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int IPv6RoutingHeaderDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *IPv6RoutingHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "routingType",
        "segmentsLeft",
        "address",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int IPv6RoutingHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routingType")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "segmentsLeft")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "address")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6RoutingHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8",
        "uint8",
        "IPv6Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6RoutingHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6RoutingHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6RoutingHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6RoutingHeader_Base *pp = (IPv6RoutingHeader_Base *)object; (void)pp;
    switch (field) {
        case 2: return pp->getAddressArraySize();
        default: return 0;
    }
}

const char *IPv6RoutingHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6RoutingHeader_Base *pp = (IPv6RoutingHeader_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6RoutingHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6RoutingHeader_Base *pp = (IPv6RoutingHeader_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRoutingType());
        case 1: return ulong2string(pp->getSegmentsLeft());
        case 2: {std::stringstream out; out << pp->getAddress(i); return out.str();}
        default: return "";
    }
}

bool IPv6RoutingHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6RoutingHeader_Base *pp = (IPv6RoutingHeader_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setRoutingType(string2ulong(value)); return true;
        case 1: pp->setSegmentsLeft(string2ulong(value)); return true;
        default: return false;
    }
}

const char *IPv6RoutingHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(IPv6Address));
        default: return nullptr;
    };
}

void *IPv6RoutingHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6RoutingHeader_Base *pp = (IPv6RoutingHeader_Base *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getAddress(i)); break;
        default: return nullptr;
    }
}

IPv6FragmentHeader::IPv6FragmentHeader() : ::inet::IPv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_FRAGMENT);
    this->setByteLength(IPv6_FRAGMENT_HEADER_LENGTH);

    this->fragmentOffset = 0;
    this->identification = 0;
    this->moreFragments = false;
}

IPv6FragmentHeader::IPv6FragmentHeader(const IPv6FragmentHeader& other) : ::inet::IPv6ExtensionHeader(other)
{
    copy(other);
}

IPv6FragmentHeader::~IPv6FragmentHeader()
{
}

IPv6FragmentHeader& IPv6FragmentHeader::operator=(const IPv6FragmentHeader& other)
{
    if (this==&other) return *this;
    ::inet::IPv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void IPv6FragmentHeader::copy(const IPv6FragmentHeader& other)
{
    this->fragmentOffset = other.fragmentOffset;
    this->identification = other.identification;
    this->moreFragments = other.moreFragments;
}

void IPv6FragmentHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv6ExtensionHeader&)*this);
    doParsimPacking(b,this->fragmentOffset);
    doParsimPacking(b,this->identification);
    doParsimPacking(b,this->moreFragments);
}

void IPv6FragmentHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv6ExtensionHeader&)*this);
    doParsimUnpacking(b,this->fragmentOffset);
    doParsimUnpacking(b,this->identification);
    doParsimUnpacking(b,this->moreFragments);
}

unsigned short IPv6FragmentHeader::getFragmentOffset() const
{
    return this->fragmentOffset;
}

void IPv6FragmentHeader::setFragmentOffset(unsigned short fragmentOffset)
{
    this->fragmentOffset = fragmentOffset;
}

unsigned int IPv6FragmentHeader::getIdentification() const
{
    return this->identification;
}

void IPv6FragmentHeader::setIdentification(unsigned int identification)
{
    this->identification = identification;
}

bool IPv6FragmentHeader::getMoreFragments() const
{
    return this->moreFragments;
}

void IPv6FragmentHeader::setMoreFragments(bool moreFragments)
{
    this->moreFragments = moreFragments;
}

class IPv6FragmentHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6FragmentHeaderDescriptor();
    virtual ~IPv6FragmentHeaderDescriptor();

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

Register_ClassDescriptor(IPv6FragmentHeaderDescriptor)

IPv6FragmentHeaderDescriptor::IPv6FragmentHeaderDescriptor() : omnetpp::cClassDescriptor("inet::IPv6FragmentHeader", "inet::IPv6ExtensionHeader")
{
    propertynames = nullptr;
}

IPv6FragmentHeaderDescriptor::~IPv6FragmentHeaderDescriptor()
{
    delete[] propertynames;
}

bool IPv6FragmentHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6FragmentHeader *>(obj)!=nullptr;
}

const char **IPv6FragmentHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6FragmentHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6FragmentHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int IPv6FragmentHeaderDescriptor::getFieldTypeFlags(int field) const
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

const char *IPv6FragmentHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fragmentOffset",
        "identification",
        "moreFragments",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int IPv6FragmentHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentOffset")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "identification")==0) return base+1;
    if (fieldName[0]=='m' && strcmp(fieldName, "moreFragments")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6FragmentHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned int",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6FragmentHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6FragmentHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6FragmentHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6FragmentHeader *pp = (IPv6FragmentHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6FragmentHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6FragmentHeader *pp = (IPv6FragmentHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6FragmentHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6FragmentHeader *pp = (IPv6FragmentHeader *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getFragmentOffset());
        case 1: return ulong2string(pp->getIdentification());
        case 2: return bool2string(pp->getMoreFragments());
        default: return "";
    }
}

bool IPv6FragmentHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6FragmentHeader *pp = (IPv6FragmentHeader *)object; (void)pp;
    switch (field) {
        case 0: pp->setFragmentOffset(string2ulong(value)); return true;
        case 1: pp->setIdentification(string2ulong(value)); return true;
        case 2: pp->setMoreFragments(string2bool(value)); return true;
        default: return false;
    }
}

const char *IPv6FragmentHeaderDescriptor::getFieldStructName(int field) const
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

void *IPv6FragmentHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6FragmentHeader *pp = (IPv6FragmentHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

IPv6DestinationOptionsHeader::IPv6DestinationOptionsHeader() : ::inet::IPv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_DEST);
    this->setByteLength(8);

}

IPv6DestinationOptionsHeader::IPv6DestinationOptionsHeader(const IPv6DestinationOptionsHeader& other) : ::inet::IPv6ExtensionHeader(other)
{
    copy(other);
}

IPv6DestinationOptionsHeader::~IPv6DestinationOptionsHeader()
{
}

IPv6DestinationOptionsHeader& IPv6DestinationOptionsHeader::operator=(const IPv6DestinationOptionsHeader& other)
{
    if (this==&other) return *this;
    ::inet::IPv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void IPv6DestinationOptionsHeader::copy(const IPv6DestinationOptionsHeader& other)
{
    this->tlvOptions = other.tlvOptions;
}

void IPv6DestinationOptionsHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv6ExtensionHeader&)*this);
    doParsimPacking(b,this->tlvOptions);
}

void IPv6DestinationOptionsHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv6ExtensionHeader&)*this);
    doParsimUnpacking(b,this->tlvOptions);
}

TLVOptions& IPv6DestinationOptionsHeader::getTlvOptions()
{
    return this->tlvOptions;
}

void IPv6DestinationOptionsHeader::setTlvOptions(const TLVOptions& tlvOptions)
{
    this->tlvOptions = tlvOptions;
}

class IPv6DestinationOptionsHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6DestinationOptionsHeaderDescriptor();
    virtual ~IPv6DestinationOptionsHeaderDescriptor();

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

Register_ClassDescriptor(IPv6DestinationOptionsHeaderDescriptor)

IPv6DestinationOptionsHeaderDescriptor::IPv6DestinationOptionsHeaderDescriptor() : omnetpp::cClassDescriptor("inet::IPv6DestinationOptionsHeader", "inet::IPv6ExtensionHeader")
{
    propertynames = nullptr;
}

IPv6DestinationOptionsHeaderDescriptor::~IPv6DestinationOptionsHeaderDescriptor()
{
    delete[] propertynames;
}

bool IPv6DestinationOptionsHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6DestinationOptionsHeader *>(obj)!=nullptr;
}

const char **IPv6DestinationOptionsHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6DestinationOptionsHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6DestinationOptionsHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IPv6DestinationOptionsHeaderDescriptor::getFieldTypeFlags(int field) const
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

const char *IPv6DestinationOptionsHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tlvOptions",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IPv6DestinationOptionsHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tlvOptions")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6DestinationOptionsHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "TLVOptions",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **IPv6DestinationOptionsHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6DestinationOptionsHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6DestinationOptionsHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6DestinationOptionsHeader *pp = (IPv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6DestinationOptionsHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6DestinationOptionsHeader *pp = (IPv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6DestinationOptionsHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6DestinationOptionsHeader *pp = (IPv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getTlvOptions(); return out.str();}
        default: return "";
    }
}

bool IPv6DestinationOptionsHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6DestinationOptionsHeader *pp = (IPv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv6DestinationOptionsHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(TLVOptions));
        default: return nullptr;
    };
}

void *IPv6DestinationOptionsHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6DestinationOptionsHeader *pp = (IPv6DestinationOptionsHeader *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getTlvOptions()); break;
        default: return nullptr;
    }
}

IPv6AuthenticationHeader::IPv6AuthenticationHeader() : ::inet::IPv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_AUTH);
    this->setByteLength(8);
}

IPv6AuthenticationHeader::IPv6AuthenticationHeader(const IPv6AuthenticationHeader& other) : ::inet::IPv6ExtensionHeader(other)
{
    copy(other);
}

IPv6AuthenticationHeader::~IPv6AuthenticationHeader()
{
}

IPv6AuthenticationHeader& IPv6AuthenticationHeader::operator=(const IPv6AuthenticationHeader& other)
{
    if (this==&other) return *this;
    ::inet::IPv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void IPv6AuthenticationHeader::copy(const IPv6AuthenticationHeader& other)
{
}

void IPv6AuthenticationHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv6ExtensionHeader&)*this);
}

void IPv6AuthenticationHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv6ExtensionHeader&)*this);
}

class IPv6AuthenticationHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6AuthenticationHeaderDescriptor();
    virtual ~IPv6AuthenticationHeaderDescriptor();

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

Register_ClassDescriptor(IPv6AuthenticationHeaderDescriptor)

IPv6AuthenticationHeaderDescriptor::IPv6AuthenticationHeaderDescriptor() : omnetpp::cClassDescriptor("inet::IPv6AuthenticationHeader", "inet::IPv6ExtensionHeader")
{
    propertynames = nullptr;
}

IPv6AuthenticationHeaderDescriptor::~IPv6AuthenticationHeaderDescriptor()
{
    delete[] propertynames;
}

bool IPv6AuthenticationHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6AuthenticationHeader *>(obj)!=nullptr;
}

const char **IPv6AuthenticationHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6AuthenticationHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6AuthenticationHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int IPv6AuthenticationHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *IPv6AuthenticationHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int IPv6AuthenticationHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6AuthenticationHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **IPv6AuthenticationHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6AuthenticationHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6AuthenticationHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6AuthenticationHeader *pp = (IPv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6AuthenticationHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6AuthenticationHeader *pp = (IPv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6AuthenticationHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6AuthenticationHeader *pp = (IPv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool IPv6AuthenticationHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6AuthenticationHeader *pp = (IPv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv6AuthenticationHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *IPv6AuthenticationHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6AuthenticationHeader *pp = (IPv6AuthenticationHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

IPv6EncapsulatingSecurityPayloadHeader::IPv6EncapsulatingSecurityPayloadHeader() : ::inet::IPv6ExtensionHeader()
{
    this->setExtensionType(IP_PROT_IPv6EXT_ESP);
    this->setByteLength(8);
}

IPv6EncapsulatingSecurityPayloadHeader::IPv6EncapsulatingSecurityPayloadHeader(const IPv6EncapsulatingSecurityPayloadHeader& other) : ::inet::IPv6ExtensionHeader(other)
{
    copy(other);
}

IPv6EncapsulatingSecurityPayloadHeader::~IPv6EncapsulatingSecurityPayloadHeader()
{
}

IPv6EncapsulatingSecurityPayloadHeader& IPv6EncapsulatingSecurityPayloadHeader::operator=(const IPv6EncapsulatingSecurityPayloadHeader& other)
{
    if (this==&other) return *this;
    ::inet::IPv6ExtensionHeader::operator=(other);
    copy(other);
    return *this;
}

void IPv6EncapsulatingSecurityPayloadHeader::copy(const IPv6EncapsulatingSecurityPayloadHeader& other)
{
}

void IPv6EncapsulatingSecurityPayloadHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::IPv6ExtensionHeader&)*this);
}

void IPv6EncapsulatingSecurityPayloadHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::IPv6ExtensionHeader&)*this);
}

class IPv6EncapsulatingSecurityPayloadHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IPv6EncapsulatingSecurityPayloadHeaderDescriptor();
    virtual ~IPv6EncapsulatingSecurityPayloadHeaderDescriptor();

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

Register_ClassDescriptor(IPv6EncapsulatingSecurityPayloadHeaderDescriptor)

IPv6EncapsulatingSecurityPayloadHeaderDescriptor::IPv6EncapsulatingSecurityPayloadHeaderDescriptor() : omnetpp::cClassDescriptor("inet::IPv6EncapsulatingSecurityPayloadHeader", "inet::IPv6ExtensionHeader")
{
    propertynames = nullptr;
}

IPv6EncapsulatingSecurityPayloadHeaderDescriptor::~IPv6EncapsulatingSecurityPayloadHeaderDescriptor()
{
    delete[] propertynames;
}

bool IPv6EncapsulatingSecurityPayloadHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IPv6EncapsulatingSecurityPayloadHeader *>(obj)!=nullptr;
}

const char **IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int IPv6EncapsulatingSecurityPayloadHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IPv6EncapsulatingSecurityPayloadHeader *pp = (IPv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6EncapsulatingSecurityPayloadHeader *pp = (IPv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IPv6EncapsulatingSecurityPayloadHeader *pp = (IPv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool IPv6EncapsulatingSecurityPayloadHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IPv6EncapsulatingSecurityPayloadHeader *pp = (IPv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *IPv6EncapsulatingSecurityPayloadHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IPv6EncapsulatingSecurityPayloadHeader *pp = (IPv6EncapsulatingSecurityPayloadHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

