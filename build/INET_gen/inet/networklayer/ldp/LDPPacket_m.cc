//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/ldp/LDPPacket.msg.
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
#include "LDPPacket_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::LDP_MESSAGE_TYPES");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::LDP_MESSAGE_TYPES"));
    e->insert(NOTIFICATION, "NOTIFICATION");
    e->insert(HELLO, "HELLO");
    e->insert(INITIALIZATION, "INITIALIZATION");
    e->insert(KEEP_ALIVE, "KEEP_ALIVE");
    e->insert(ADDRESS, "ADDRESS");
    e->insert(ADDRESS_WITHDRAW, "ADDRESS_WITHDRAW");
    e->insert(LABEL_MAPPING, "LABEL_MAPPING");
    e->insert(LABEL_REQUEST, "LABEL_REQUEST");
    e->insert(LABEL_WITHDRAW, "LABEL_WITHDRAW");
    e->insert(LABEL_RELEASE, "LABEL_RELEASE");
    e->insert(UNKNOWN, "UNKNOWN");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::LDP_STATUS_TYPES");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::LDP_STATUS_TYPES"));
    e->insert(NO_ROUTE, "NO_ROUTE");
)

FEC_TLV::FEC_TLV()
{
    this->length = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const FEC_TLV& a)
{
    doParsimPacking(b,a.addr);
    doParsimPacking(b,a.length);
}

void __doUnpacking(omnetpp::cCommBuffer *b, FEC_TLV& a)
{
    doParsimUnpacking(b,a.addr);
    doParsimUnpacking(b,a.length);
}

class FEC_TLVDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    FEC_TLVDescriptor();
    virtual ~FEC_TLVDescriptor();

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

Register_ClassDescriptor(FEC_TLVDescriptor)

FEC_TLVDescriptor::FEC_TLVDescriptor() : omnetpp::cClassDescriptor("inet::FEC_TLV", "")
{
    propertynames = nullptr;
}

FEC_TLVDescriptor::~FEC_TLVDescriptor()
{
    delete[] propertynames;
}

bool FEC_TLVDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<FEC_TLV *>(obj)!=nullptr;
}

const char **FEC_TLVDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *FEC_TLVDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int FEC_TLVDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int FEC_TLVDescriptor::getFieldTypeFlags(int field) const
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

const char *FEC_TLVDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "addr",
        "length",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int FEC_TLVDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addr")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *FEC_TLVDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **FEC_TLVDescriptor::getFieldPropertyNames(int field) const
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

const char *FEC_TLVDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int FEC_TLVDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    FEC_TLV *pp = (FEC_TLV *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *FEC_TLVDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    FEC_TLV *pp = (FEC_TLV *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string FEC_TLVDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    FEC_TLV *pp = (FEC_TLV *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->addr; return out.str();}
        case 1: return long2string(pp->length);
        default: return "";
    }
}

bool FEC_TLVDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    FEC_TLV *pp = (FEC_TLV *)object; (void)pp;
    switch (field) {
        case 1: pp->length = string2long(value); return true;
        default: return false;
    }
}

const char *FEC_TLVDescriptor::getFieldStructName(int field) const
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

void *FEC_TLVDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    FEC_TLV *pp = (FEC_TLV *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->addr); break;
        default: return nullptr;
    }
}

Register_Class(LDPPacket)

LDPPacket::LDPPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->type = 0;
}

LDPPacket::LDPPacket(const LDPPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

LDPPacket::~LDPPacket()
{
}

LDPPacket& LDPPacket::operator=(const LDPPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void LDPPacket::copy(const LDPPacket& other)
{
    this->type = other.type;
    this->senderAddress = other.senderAddress;
    this->receiverAddress = other.receiverAddress;
}

void LDPPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->senderAddress);
    doParsimPacking(b,this->receiverAddress);
}

void LDPPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->senderAddress);
    doParsimUnpacking(b,this->receiverAddress);
}

int LDPPacket::getType() const
{
    return this->type;
}

void LDPPacket::setType(int type)
{
    this->type = type;
}

IPv4Address& LDPPacket::getSenderAddress()
{
    return this->senderAddress;
}

void LDPPacket::setSenderAddress(const IPv4Address& senderAddress)
{
    this->senderAddress = senderAddress;
}

IPv4Address& LDPPacket::getReceiverAddress()
{
    return this->receiverAddress;
}

void LDPPacket::setReceiverAddress(const IPv4Address& receiverAddress)
{
    this->receiverAddress = receiverAddress;
}

class LDPPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LDPPacketDescriptor();
    virtual ~LDPPacketDescriptor();

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

Register_ClassDescriptor(LDPPacketDescriptor)

LDPPacketDescriptor::LDPPacketDescriptor() : omnetpp::cClassDescriptor("inet::LDPPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

LDPPacketDescriptor::~LDPPacketDescriptor()
{
    delete[] propertynames;
}

bool LDPPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LDPPacket *>(obj)!=nullptr;
}

const char **LDPPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LDPPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LDPPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LDPPacketDescriptor::getFieldTypeFlags(int field) const
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

const char *LDPPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "senderAddress",
        "receiverAddress",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int LDPPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderAddress")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiverAddress")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LDPPacketDescriptor::getFieldTypeString(int field) const
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
        "IPv4Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **LDPPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *LDPPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LDPPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LDPPacket *pp = (LDPPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LDPPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPPacket *pp = (LDPPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LDPPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPPacket *pp = (LDPPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getType());
        case 1: {std::stringstream out; out << pp->getSenderAddress(); return out.str();}
        case 2: {std::stringstream out; out << pp->getReceiverAddress(); return out.str();}
        default: return "";
    }
}

bool LDPPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LDPPacket *pp = (LDPPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setType(string2long(value)); return true;
        default: return false;
    }
}

const char *LDPPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *LDPPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LDPPacket *pp = (LDPPacket *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getSenderAddress()); break;
        case 2: return (void *)(&pp->getReceiverAddress()); break;
        default: return nullptr;
    }
}

Register_Class(LDPLabelMapping)

LDPLabelMapping::LDPLabelMapping(const char *name, short kind) : ::inet::LDPPacket(name,kind)
{
    this->label = 0;
}

LDPLabelMapping::LDPLabelMapping(const LDPLabelMapping& other) : ::inet::LDPPacket(other)
{
    copy(other);
}

LDPLabelMapping::~LDPLabelMapping()
{
}

LDPLabelMapping& LDPLabelMapping::operator=(const LDPLabelMapping& other)
{
    if (this==&other) return *this;
    ::inet::LDPPacket::operator=(other);
    copy(other);
    return *this;
}

void LDPLabelMapping::copy(const LDPLabelMapping& other)
{
    this->fec = other.fec;
    this->label = other.label;
}

void LDPLabelMapping::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LDPPacket::parsimPack(b);
    doParsimPacking(b,this->fec);
    doParsimPacking(b,this->label);
}

void LDPLabelMapping::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LDPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->fec);
    doParsimUnpacking(b,this->label);
}

FEC_TLV& LDPLabelMapping::getFec()
{
    return this->fec;
}

void LDPLabelMapping::setFec(const FEC_TLV& fec)
{
    this->fec = fec;
}

int LDPLabelMapping::getLabel() const
{
    return this->label;
}

void LDPLabelMapping::setLabel(int label)
{
    this->label = label;
}

class LDPLabelMappingDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LDPLabelMappingDescriptor();
    virtual ~LDPLabelMappingDescriptor();

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

Register_ClassDescriptor(LDPLabelMappingDescriptor)

LDPLabelMappingDescriptor::LDPLabelMappingDescriptor() : omnetpp::cClassDescriptor("inet::LDPLabelMapping", "inet::LDPPacket")
{
    propertynames = nullptr;
}

LDPLabelMappingDescriptor::~LDPLabelMappingDescriptor()
{
    delete[] propertynames;
}

bool LDPLabelMappingDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LDPLabelMapping *>(obj)!=nullptr;
}

const char **LDPLabelMappingDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LDPLabelMappingDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LDPLabelMappingDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int LDPLabelMappingDescriptor::getFieldTypeFlags(int field) const
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

const char *LDPLabelMappingDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fec",
        "label",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int LDPLabelMappingDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fec")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "label")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LDPLabelMappingDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "FEC_TLV",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **LDPLabelMappingDescriptor::getFieldPropertyNames(int field) const
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

const char *LDPLabelMappingDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LDPLabelMappingDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LDPLabelMapping *pp = (LDPLabelMapping *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LDPLabelMappingDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPLabelMapping *pp = (LDPLabelMapping *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LDPLabelMappingDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPLabelMapping *pp = (LDPLabelMapping *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getFec(); return out.str();}
        case 1: return long2string(pp->getLabel());
        default: return "";
    }
}

bool LDPLabelMappingDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LDPLabelMapping *pp = (LDPLabelMapping *)object; (void)pp;
    switch (field) {
        case 1: pp->setLabel(string2long(value)); return true;
        default: return false;
    }
}

const char *LDPLabelMappingDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(FEC_TLV));
        default: return nullptr;
    };
}

void *LDPLabelMappingDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LDPLabelMapping *pp = (LDPLabelMapping *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getFec()); break;
        default: return nullptr;
    }
}

Register_Class(LDPLabelRequest)

LDPLabelRequest::LDPLabelRequest(const char *name, short kind) : ::inet::LDPPacket(name,kind)
{
}

LDPLabelRequest::LDPLabelRequest(const LDPLabelRequest& other) : ::inet::LDPPacket(other)
{
    copy(other);
}

LDPLabelRequest::~LDPLabelRequest()
{
}

LDPLabelRequest& LDPLabelRequest::operator=(const LDPLabelRequest& other)
{
    if (this==&other) return *this;
    ::inet::LDPPacket::operator=(other);
    copy(other);
    return *this;
}

void LDPLabelRequest::copy(const LDPLabelRequest& other)
{
    this->fec = other.fec;
}

void LDPLabelRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LDPPacket::parsimPack(b);
    doParsimPacking(b,this->fec);
}

void LDPLabelRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LDPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->fec);
}

FEC_TLV& LDPLabelRequest::getFec()
{
    return this->fec;
}

void LDPLabelRequest::setFec(const FEC_TLV& fec)
{
    this->fec = fec;
}

class LDPLabelRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LDPLabelRequestDescriptor();
    virtual ~LDPLabelRequestDescriptor();

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

Register_ClassDescriptor(LDPLabelRequestDescriptor)

LDPLabelRequestDescriptor::LDPLabelRequestDescriptor() : omnetpp::cClassDescriptor("inet::LDPLabelRequest", "inet::LDPPacket")
{
    propertynames = nullptr;
}

LDPLabelRequestDescriptor::~LDPLabelRequestDescriptor()
{
    delete[] propertynames;
}

bool LDPLabelRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LDPLabelRequest *>(obj)!=nullptr;
}

const char **LDPLabelRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LDPLabelRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LDPLabelRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int LDPLabelRequestDescriptor::getFieldTypeFlags(int field) const
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

const char *LDPLabelRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fec",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int LDPLabelRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fec")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LDPLabelRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "FEC_TLV",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **LDPLabelRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *LDPLabelRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LDPLabelRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LDPLabelRequest *pp = (LDPLabelRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LDPLabelRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPLabelRequest *pp = (LDPLabelRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LDPLabelRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPLabelRequest *pp = (LDPLabelRequest *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getFec(); return out.str();}
        default: return "";
    }
}

bool LDPLabelRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LDPLabelRequest *pp = (LDPLabelRequest *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *LDPLabelRequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(FEC_TLV));
        default: return nullptr;
    };
}

void *LDPLabelRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LDPLabelRequest *pp = (LDPLabelRequest *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getFec()); break;
        default: return nullptr;
    }
}

Register_Class(LDPHello)

LDPHello::LDPHello(const char *name, short kind) : ::inet::LDPPacket(name,kind)
{
    this->holdTime = 0;
    this->tbit = false;
    this->rbit = false;
}

LDPHello::LDPHello(const LDPHello& other) : ::inet::LDPPacket(other)
{
    copy(other);
}

LDPHello::~LDPHello()
{
}

LDPHello& LDPHello::operator=(const LDPHello& other)
{
    if (this==&other) return *this;
    ::inet::LDPPacket::operator=(other);
    copy(other);
    return *this;
}

void LDPHello::copy(const LDPHello& other)
{
    this->holdTime = other.holdTime;
    this->tbit = other.tbit;
    this->rbit = other.rbit;
}

void LDPHello::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LDPPacket::parsimPack(b);
    doParsimPacking(b,this->holdTime);
    doParsimPacking(b,this->tbit);
    doParsimPacking(b,this->rbit);
}

void LDPHello::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LDPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->holdTime);
    doParsimUnpacking(b,this->tbit);
    doParsimUnpacking(b,this->rbit);
}

double LDPHello::getHoldTime() const
{
    return this->holdTime;
}

void LDPHello::setHoldTime(double holdTime)
{
    this->holdTime = holdTime;
}

bool LDPHello::getTbit() const
{
    return this->tbit;
}

void LDPHello::setTbit(bool tbit)
{
    this->tbit = tbit;
}

bool LDPHello::getRbit() const
{
    return this->rbit;
}

void LDPHello::setRbit(bool rbit)
{
    this->rbit = rbit;
}

class LDPHelloDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LDPHelloDescriptor();
    virtual ~LDPHelloDescriptor();

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

Register_ClassDescriptor(LDPHelloDescriptor)

LDPHelloDescriptor::LDPHelloDescriptor() : omnetpp::cClassDescriptor("inet::LDPHello", "inet::LDPPacket")
{
    propertynames = nullptr;
}

LDPHelloDescriptor::~LDPHelloDescriptor()
{
    delete[] propertynames;
}

bool LDPHelloDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LDPHello *>(obj)!=nullptr;
}

const char **LDPHelloDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LDPHelloDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LDPHelloDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LDPHelloDescriptor::getFieldTypeFlags(int field) const
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

const char *LDPHelloDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "holdTime",
        "tbit",
        "rbit",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int LDPHelloDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tbit")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "rbit")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LDPHelloDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "bool",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **LDPHelloDescriptor::getFieldPropertyNames(int field) const
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

const char *LDPHelloDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LDPHelloDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LDPHello *pp = (LDPHello *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LDPHelloDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPHello *pp = (LDPHello *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LDPHelloDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPHello *pp = (LDPHello *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getHoldTime());
        case 1: return bool2string(pp->getTbit());
        case 2: return bool2string(pp->getRbit());
        default: return "";
    }
}

bool LDPHelloDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LDPHello *pp = (LDPHello *)object; (void)pp;
    switch (field) {
        case 0: pp->setHoldTime(string2double(value)); return true;
        case 1: pp->setTbit(string2bool(value)); return true;
        case 2: pp->setRbit(string2bool(value)); return true;
        default: return false;
    }
}

const char *LDPHelloDescriptor::getFieldStructName(int field) const
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

void *LDPHelloDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LDPHello *pp = (LDPHello *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LDPNotify)

LDPNotify::LDPNotify(const char *name, short kind) : ::inet::LDPPacket(name,kind)
{
    this->status = 0;
}

LDPNotify::LDPNotify(const LDPNotify& other) : ::inet::LDPPacket(other)
{
    copy(other);
}

LDPNotify::~LDPNotify()
{
}

LDPNotify& LDPNotify::operator=(const LDPNotify& other)
{
    if (this==&other) return *this;
    ::inet::LDPPacket::operator=(other);
    copy(other);
    return *this;
}

void LDPNotify::copy(const LDPNotify& other)
{
    this->status = other.status;
    this->fec = other.fec;
}

void LDPNotify::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LDPPacket::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->fec);
}

void LDPNotify::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LDPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->fec);
}

int LDPNotify::getStatus() const
{
    return this->status;
}

void LDPNotify::setStatus(int status)
{
    this->status = status;
}

FEC_TLV& LDPNotify::getFec()
{
    return this->fec;
}

void LDPNotify::setFec(const FEC_TLV& fec)
{
    this->fec = fec;
}

class LDPNotifyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LDPNotifyDescriptor();
    virtual ~LDPNotifyDescriptor();

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

Register_ClassDescriptor(LDPNotifyDescriptor)

LDPNotifyDescriptor::LDPNotifyDescriptor() : omnetpp::cClassDescriptor("inet::LDPNotify", "inet::LDPPacket")
{
    propertynames = nullptr;
}

LDPNotifyDescriptor::~LDPNotifyDescriptor()
{
    delete[] propertynames;
}

bool LDPNotifyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LDPNotify *>(obj)!=nullptr;
}

const char **LDPNotifyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LDPNotifyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LDPNotifyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int LDPNotifyDescriptor::getFieldTypeFlags(int field) const
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

const char *LDPNotifyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "fec",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int LDPNotifyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fec")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LDPNotifyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "FEC_TLV",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **LDPNotifyDescriptor::getFieldPropertyNames(int field) const
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

const char *LDPNotifyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LDPNotifyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LDPNotify *pp = (LDPNotify *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LDPNotifyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPNotify *pp = (LDPNotify *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LDPNotifyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPNotify *pp = (LDPNotify *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getStatus());
        case 1: {std::stringstream out; out << pp->getFec(); return out.str();}
        default: return "";
    }
}

bool LDPNotifyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LDPNotify *pp = (LDPNotify *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus(string2long(value)); return true;
        default: return false;
    }
}

const char *LDPNotifyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(FEC_TLV));
        default: return nullptr;
    };
}

void *LDPNotifyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LDPNotify *pp = (LDPNotify *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getFec()); break;
        default: return nullptr;
    }
}

Register_Class(LDPIni)

LDPIni::LDPIni(const char *name, short kind) : ::inet::LDPPacket(name,kind)
{
    this->keepAliveTime = 0;
    this->abit = false;
    this->dbit = false;
    this->pvLim = 0;
}

LDPIni::LDPIni(const LDPIni& other) : ::inet::LDPPacket(other)
{
    copy(other);
}

LDPIni::~LDPIni()
{
}

LDPIni& LDPIni::operator=(const LDPIni& other)
{
    if (this==&other) return *this;
    ::inet::LDPPacket::operator=(other);
    copy(other);
    return *this;
}

void LDPIni::copy(const LDPIni& other)
{
    this->keepAliveTime = other.keepAliveTime;
    this->abit = other.abit;
    this->dbit = other.dbit;
    this->pvLim = other.pvLim;
    this->receiverLDPIdentifier = other.receiverLDPIdentifier;
}

void LDPIni::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LDPPacket::parsimPack(b);
    doParsimPacking(b,this->keepAliveTime);
    doParsimPacking(b,this->abit);
    doParsimPacking(b,this->dbit);
    doParsimPacking(b,this->pvLim);
    doParsimPacking(b,this->receiverLDPIdentifier);
}

void LDPIni::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LDPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->keepAliveTime);
    doParsimUnpacking(b,this->abit);
    doParsimUnpacking(b,this->dbit);
    doParsimUnpacking(b,this->pvLim);
    doParsimUnpacking(b,this->receiverLDPIdentifier);
}

double LDPIni::getKeepAliveTime() const
{
    return this->keepAliveTime;
}

void LDPIni::setKeepAliveTime(double keepAliveTime)
{
    this->keepAliveTime = keepAliveTime;
}

bool LDPIni::getAbit() const
{
    return this->abit;
}

void LDPIni::setAbit(bool abit)
{
    this->abit = abit;
}

bool LDPIni::getDbit() const
{
    return this->dbit;
}

void LDPIni::setDbit(bool dbit)
{
    this->dbit = dbit;
}

int LDPIni::getPvLim() const
{
    return this->pvLim;
}

void LDPIni::setPvLim(int pvLim)
{
    this->pvLim = pvLim;
}

const char * LDPIni::getReceiverLDPIdentifier() const
{
    return this->receiverLDPIdentifier.c_str();
}

void LDPIni::setReceiverLDPIdentifier(const char * receiverLDPIdentifier)
{
    this->receiverLDPIdentifier = receiverLDPIdentifier;
}

class LDPIniDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LDPIniDescriptor();
    virtual ~LDPIniDescriptor();

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

Register_ClassDescriptor(LDPIniDescriptor)

LDPIniDescriptor::LDPIniDescriptor() : omnetpp::cClassDescriptor("inet::LDPIni", "inet::LDPPacket")
{
    propertynames = nullptr;
}

LDPIniDescriptor::~LDPIniDescriptor()
{
    delete[] propertynames;
}

bool LDPIniDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LDPIni *>(obj)!=nullptr;
}

const char **LDPIniDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LDPIniDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LDPIniDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int LDPIniDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *LDPIniDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "keepAliveTime",
        "abit",
        "dbit",
        "pvLim",
        "receiverLDPIdentifier",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int LDPIniDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "keepAliveTime")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "abit")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "dbit")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "pvLim")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiverLDPIdentifier")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LDPIniDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "bool",
        "bool",
        "int",
        "string",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **LDPIniDescriptor::getFieldPropertyNames(int field) const
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

const char *LDPIniDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LDPIniDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LDPIni *pp = (LDPIni *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LDPIniDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPIni *pp = (LDPIni *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LDPIniDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPIni *pp = (LDPIni *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getKeepAliveTime());
        case 1: return bool2string(pp->getAbit());
        case 2: return bool2string(pp->getDbit());
        case 3: return long2string(pp->getPvLim());
        case 4: return oppstring2string(pp->getReceiverLDPIdentifier());
        default: return "";
    }
}

bool LDPIniDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LDPIni *pp = (LDPIni *)object; (void)pp;
    switch (field) {
        case 0: pp->setKeepAliveTime(string2double(value)); return true;
        case 1: pp->setAbit(string2bool(value)); return true;
        case 2: pp->setDbit(string2bool(value)); return true;
        case 3: pp->setPvLim(string2long(value)); return true;
        case 4: pp->setReceiverLDPIdentifier((value)); return true;
        default: return false;
    }
}

const char *LDPIniDescriptor::getFieldStructName(int field) const
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

void *LDPIniDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LDPIni *pp = (LDPIni *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LDPAddress)

LDPAddress::LDPAddress(const char *name, short kind) : ::inet::LDPPacket(name,kind)
{
    this->isWithdraw = false;
    addresses_arraysize = 0;
    this->addresses = 0;
}

LDPAddress::LDPAddress(const LDPAddress& other) : ::inet::LDPPacket(other)
{
    addresses_arraysize = 0;
    this->addresses = 0;
    copy(other);
}

LDPAddress::~LDPAddress()
{
    delete [] this->addresses;
}

LDPAddress& LDPAddress::operator=(const LDPAddress& other)
{
    if (this==&other) return *this;
    ::inet::LDPPacket::operator=(other);
    copy(other);
    return *this;
}

void LDPAddress::copy(const LDPAddress& other)
{
    this->isWithdraw = other.isWithdraw;
    this->family = other.family;
    delete [] this->addresses;
    this->addresses = (other.addresses_arraysize==0) ? nullptr : new ::omnetpp::opp_string[other.addresses_arraysize];
    addresses_arraysize = other.addresses_arraysize;
    for (unsigned int i=0; i<addresses_arraysize; i++)
        this->addresses[i] = other.addresses[i];
}

void LDPAddress::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::LDPPacket::parsimPack(b);
    doParsimPacking(b,this->isWithdraw);
    doParsimPacking(b,this->family);
    b->pack(addresses_arraysize);
    doParsimArrayPacking(b,this->addresses,addresses_arraysize);
}

void LDPAddress::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::LDPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->isWithdraw);
    doParsimUnpacking(b,this->family);
    delete [] this->addresses;
    b->unpack(addresses_arraysize);
    if (addresses_arraysize==0) {
        this->addresses = 0;
    } else {
        this->addresses = new ::omnetpp::opp_string[addresses_arraysize];
        doParsimArrayUnpacking(b,this->addresses,addresses_arraysize);
    }
}

bool LDPAddress::getIsWithdraw() const
{
    return this->isWithdraw;
}

void LDPAddress::setIsWithdraw(bool isWithdraw)
{
    this->isWithdraw = isWithdraw;
}

const char * LDPAddress::getFamily() const
{
    return this->family.c_str();
}

void LDPAddress::setFamily(const char * family)
{
    this->family = family;
}

void LDPAddress::setAddressesArraySize(unsigned int size)
{
    ::omnetpp::opp_string *addresses2 = (size==0) ? nullptr : new ::omnetpp::opp_string[size];
    unsigned int sz = addresses_arraysize < size ? addresses_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        addresses2[i] = this->addresses[i];
    for (unsigned int i=sz; i<size; i++)
        addresses2[i] = 0;
    addresses_arraysize = size;
    delete [] this->addresses;
    this->addresses = addresses2;
}

unsigned int LDPAddress::getAddressesArraySize() const
{
    return addresses_arraysize;
}

const char * LDPAddress::getAddresses(unsigned int k) const
{
    if (k>=addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    return this->addresses[k].c_str();
}

void LDPAddress::setAddresses(unsigned int k, const char * addresses)
{
    if (k>=addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    this->addresses[k] = addresses;
}

class LDPAddressDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LDPAddressDescriptor();
    virtual ~LDPAddressDescriptor();

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

Register_ClassDescriptor(LDPAddressDescriptor)

LDPAddressDescriptor::LDPAddressDescriptor() : omnetpp::cClassDescriptor("inet::LDPAddress", "inet::LDPPacket")
{
    propertynames = nullptr;
}

LDPAddressDescriptor::~LDPAddressDescriptor()
{
    delete[] propertynames;
}

bool LDPAddressDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LDPAddress *>(obj)!=nullptr;
}

const char **LDPAddressDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LDPAddressDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LDPAddressDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LDPAddressDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *LDPAddressDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "isWithdraw",
        "family",
        "addresses",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int LDPAddressDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isWithdraw")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "family")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "addresses")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LDPAddressDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "string",
        "string",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **LDPAddressDescriptor::getFieldPropertyNames(int field) const
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

const char *LDPAddressDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LDPAddressDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LDPAddress *pp = (LDPAddress *)object; (void)pp;
    switch (field) {
        case 2: return pp->getAddressesArraySize();
        default: return 0;
    }
}

const char *LDPAddressDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPAddress *pp = (LDPAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LDPAddressDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LDPAddress *pp = (LDPAddress *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getIsWithdraw());
        case 1: return oppstring2string(pp->getFamily());
        case 2: return oppstring2string(pp->getAddresses(i));
        default: return "";
    }
}

bool LDPAddressDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LDPAddress *pp = (LDPAddress *)object; (void)pp;
    switch (field) {
        case 0: pp->setIsWithdraw(string2bool(value)); return true;
        case 1: pp->setFamily((value)); return true;
        case 2: pp->setAddresses(i,(value)); return true;
        default: return false;
    }
}

const char *LDPAddressDescriptor::getFieldStructName(int field) const
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

void *LDPAddressDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LDPAddress *pp = (LDPAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

