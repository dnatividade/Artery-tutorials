//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/sctp/SCTPMessage.msg.
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
#include "SCTPMessage_m.h"

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
namespace sctp {

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

SCTPMessage_Base::SCTPMessage_Base(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->srcPort = 0;
    this->destPort = 0;
    this->tag = 0;
    this->checksumOk = false;
}

SCTPMessage_Base::SCTPMessage_Base(const SCTPMessage_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SCTPMessage_Base::~SCTPMessage_Base()
{
}

SCTPMessage_Base& SCTPMessage_Base::operator=(const SCTPMessage_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPMessage_Base::copy(const SCTPMessage_Base& other)
{
    this->srcPort = other.srcPort;
    this->destPort = other.destPort;
    this->tag = other.tag;
    this->checksumOk = other.checksumOk;
}

void SCTPMessage_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->tag);
    doParsimPacking(b,this->checksumOk);
    // field chunks is abstract -- please do packing in customized class
}

void SCTPMessage_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->tag);
    doParsimUnpacking(b,this->checksumOk);
    // field chunks is abstract -- please do unpacking in customized class
}

uint16_t SCTPMessage_Base::getSrcPort() const
{
    return this->srcPort;
}

void SCTPMessage_Base::setSrcPort(uint16_t srcPort)
{
    this->srcPort = srcPort;
}

uint16_t SCTPMessage_Base::getDestPort() const
{
    return this->destPort;
}

void SCTPMessage_Base::setDestPort(uint16_t destPort)
{
    this->destPort = destPort;
}

uint32_t SCTPMessage_Base::getTag() const
{
    return this->tag;
}

void SCTPMessage_Base::setTag(uint32_t tag)
{
    this->tag = tag;
}

bool SCTPMessage_Base::getChecksumOk() const
{
    return this->checksumOk;
}

void SCTPMessage_Base::setChecksumOk(bool checksumOk)
{
    this->checksumOk = checksumOk;
}

class SCTPMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPMessageDescriptor();
    virtual ~SCTPMessageDescriptor();

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

Register_ClassDescriptor(SCTPMessageDescriptor)

SCTPMessageDescriptor::SCTPMessageDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPMessage", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SCTPMessageDescriptor::~SCTPMessageDescriptor()
{
    delete[] propertynames;
}

bool SCTPMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPMessage_Base *>(obj)!=nullptr;
}

const char **SCTPMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPMessageDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int SCTPMessageDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *SCTPMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcPort",
        "destPort",
        "tag",
        "checksumOk",
        "chunks",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int SCTPMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPort")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tag")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "checksumOk")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunks")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
        "uint16",
        "uint32",
        "bool",
        "cPacketPtr",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        case 4: return pp->getChunksArraySize();
        default: return 0;
    }
}

const char *SCTPMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSrcPort());
        case 1: return ulong2string(pp->getDestPort());
        case 2: return ulong2string(pp->getTag());
        case 3: return bool2string(pp->getChecksumOk());
        case 4: {std::stringstream out; out << pp->getChunks(i); return out.str();}
        default: return "";
    }
}

bool SCTPMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcPort(string2ulong(value)); return true;
        case 1: pp->setDestPort(string2ulong(value)); return true;
        case 2: pp->setTag(string2ulong(value)); return true;
        case 3: pp->setChecksumOk(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(cPacketPtr));
        default: return nullptr;
    };
}

void *SCTPMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPMessage_Base *pp = (SCTPMessage_Base *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getChunks(i)); break;
        default: return nullptr;
    }
}

Register_Class(SCTPChunk)

SCTPChunk::SCTPChunk(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->chunkType = 0;
    this->flags = 0;
}

SCTPChunk::SCTPChunk(const SCTPChunk& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SCTPChunk::~SCTPChunk()
{
}

SCTPChunk& SCTPChunk::operator=(const SCTPChunk& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPChunk::copy(const SCTPChunk& other)
{
    this->chunkType = other.chunkType;
    this->flags = other.flags;
}

void SCTPChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->chunkType);
    doParsimPacking(b,this->flags);
}

void SCTPChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->chunkType);
    doParsimUnpacking(b,this->flags);
}

uint8_t SCTPChunk::getChunkType() const
{
    return this->chunkType;
}

void SCTPChunk::setChunkType(uint8_t chunkType)
{
    this->chunkType = chunkType;
}

uint32_t SCTPChunk::getFlags() const
{
    return this->flags;
}

void SCTPChunk::setFlags(uint32_t flags)
{
    this->flags = flags;
}

class SCTPChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPChunkDescriptor();
    virtual ~SCTPChunkDescriptor();

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

Register_ClassDescriptor(SCTPChunkDescriptor)

SCTPChunkDescriptor::SCTPChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPChunk", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SCTPChunkDescriptor::~SCTPChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPChunk *>(obj)!=nullptr;
}

const char **SCTPChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "false";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SCTPChunkDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "chunkType",
        "flags",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SCTPChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunkType")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flags")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8",
        "uint32",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getChunkType());
        case 1: return ulong2string(pp->getFlags());
        default: return "";
    }
}

bool SCTPChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setChunkType(string2ulong(value)); return true;
        case 1: pp->setFlags(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPChunk *pp = (SCTPChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPInitChunk)

SCTPInitChunk::SCTPInitChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->initTag = 0;
    this->a_rwnd = 0;
    this->noOutStreams = 0;
    this->noInStreams = 0;
    this->initTSN = 0;
    this->forwardTsn = false;
    this->ipv4Supported = false;
    this->ipv6Supported = false;
    addresses_arraysize = 0;
    this->addresses = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters = 0;
    this->msg_rwnd = 0;
    chunkTypes_arraysize = 0;
    this->chunkTypes = 0;
    sepChunks_arraysize = 0;
    this->sepChunks = 0;
    hmacTypes_arraysize = 0;
    this->hmacTypes = 0;
    random_arraysize = 0;
    this->random = 0;
}

SCTPInitChunk::SCTPInitChunk(const SCTPInitChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    addresses_arraysize = 0;
    this->addresses = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters = 0;
    chunkTypes_arraysize = 0;
    this->chunkTypes = 0;
    sepChunks_arraysize = 0;
    this->sepChunks = 0;
    hmacTypes_arraysize = 0;
    this->hmacTypes = 0;
    random_arraysize = 0;
    this->random = 0;
    copy(other);
}

SCTPInitChunk::~SCTPInitChunk()
{
    delete [] this->addresses;
    delete [] this->unrecognizedParameters;
    delete [] this->chunkTypes;
    delete [] this->sepChunks;
    delete [] this->hmacTypes;
    delete [] this->random;
}

SCTPInitChunk& SCTPInitChunk::operator=(const SCTPInitChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPInitChunk::copy(const SCTPInitChunk& other)
{
    this->initTag = other.initTag;
    this->a_rwnd = other.a_rwnd;
    this->noOutStreams = other.noOutStreams;
    this->noInStreams = other.noInStreams;
    this->initTSN = other.initTSN;
    this->forwardTsn = other.forwardTsn;
    this->ipv4Supported = other.ipv4Supported;
    this->ipv6Supported = other.ipv6Supported;
    delete [] this->addresses;
    this->addresses = (other.addresses_arraysize==0) ? nullptr : new L3Address[other.addresses_arraysize];
    addresses_arraysize = other.addresses_arraysize;
    for (unsigned int i=0; i<addresses_arraysize; i++)
        this->addresses[i] = other.addresses[i];
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = (other.unrecognizedParameters_arraysize==0) ? nullptr : new uint8_t[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (unsigned int i=0; i<unrecognizedParameters_arraysize; i++)
        this->unrecognizedParameters[i] = other.unrecognizedParameters[i];
    this->msg_rwnd = other.msg_rwnd;
    delete [] this->chunkTypes;
    this->chunkTypes = (other.chunkTypes_arraysize==0) ? nullptr : new uint16_t[other.chunkTypes_arraysize];
    chunkTypes_arraysize = other.chunkTypes_arraysize;
    for (unsigned int i=0; i<chunkTypes_arraysize; i++)
        this->chunkTypes[i] = other.chunkTypes[i];
    delete [] this->sepChunks;
    this->sepChunks = (other.sepChunks_arraysize==0) ? nullptr : new uint16_t[other.sepChunks_arraysize];
    sepChunks_arraysize = other.sepChunks_arraysize;
    for (unsigned int i=0; i<sepChunks_arraysize; i++)
        this->sepChunks[i] = other.sepChunks[i];
    delete [] this->hmacTypes;
    this->hmacTypes = (other.hmacTypes_arraysize==0) ? nullptr : new uint16_t[other.hmacTypes_arraysize];
    hmacTypes_arraysize = other.hmacTypes_arraysize;
    for (unsigned int i=0; i<hmacTypes_arraysize; i++)
        this->hmacTypes[i] = other.hmacTypes[i];
    delete [] this->random;
    this->random = (other.random_arraysize==0) ? nullptr : new uint8_t[other.random_arraysize];
    random_arraysize = other.random_arraysize;
    for (unsigned int i=0; i<random_arraysize; i++)
        this->random[i] = other.random[i];
}

void SCTPInitChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->initTag);
    doParsimPacking(b,this->a_rwnd);
    doParsimPacking(b,this->noOutStreams);
    doParsimPacking(b,this->noInStreams);
    doParsimPacking(b,this->initTSN);
    doParsimPacking(b,this->forwardTsn);
    doParsimPacking(b,this->ipv4Supported);
    doParsimPacking(b,this->ipv6Supported);
    b->pack(addresses_arraysize);
    doParsimArrayPacking(b,this->addresses,addresses_arraysize);
    b->pack(unrecognizedParameters_arraysize);
    doParsimArrayPacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    doParsimPacking(b,this->msg_rwnd);
    b->pack(chunkTypes_arraysize);
    doParsimArrayPacking(b,this->chunkTypes,chunkTypes_arraysize);
    b->pack(sepChunks_arraysize);
    doParsimArrayPacking(b,this->sepChunks,sepChunks_arraysize);
    b->pack(hmacTypes_arraysize);
    doParsimArrayPacking(b,this->hmacTypes,hmacTypes_arraysize);
    b->pack(random_arraysize);
    doParsimArrayPacking(b,this->random,random_arraysize);
}

void SCTPInitChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->initTag);
    doParsimUnpacking(b,this->a_rwnd);
    doParsimUnpacking(b,this->noOutStreams);
    doParsimUnpacking(b,this->noInStreams);
    doParsimUnpacking(b,this->initTSN);
    doParsimUnpacking(b,this->forwardTsn);
    doParsimUnpacking(b,this->ipv4Supported);
    doParsimUnpacking(b,this->ipv6Supported);
    delete [] this->addresses;
    b->unpack(addresses_arraysize);
    if (addresses_arraysize==0) {
        this->addresses = 0;
    } else {
        this->addresses = new L3Address[addresses_arraysize];
        doParsimArrayUnpacking(b,this->addresses,addresses_arraysize);
    }
    delete [] this->unrecognizedParameters;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize==0) {
        this->unrecognizedParameters = 0;
    } else {
        this->unrecognizedParameters = new uint8_t[unrecognizedParameters_arraysize];
        doParsimArrayUnpacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    }
    doParsimUnpacking(b,this->msg_rwnd);
    delete [] this->chunkTypes;
    b->unpack(chunkTypes_arraysize);
    if (chunkTypes_arraysize==0) {
        this->chunkTypes = 0;
    } else {
        this->chunkTypes = new uint16_t[chunkTypes_arraysize];
        doParsimArrayUnpacking(b,this->chunkTypes,chunkTypes_arraysize);
    }
    delete [] this->sepChunks;
    b->unpack(sepChunks_arraysize);
    if (sepChunks_arraysize==0) {
        this->sepChunks = 0;
    } else {
        this->sepChunks = new uint16_t[sepChunks_arraysize];
        doParsimArrayUnpacking(b,this->sepChunks,sepChunks_arraysize);
    }
    delete [] this->hmacTypes;
    b->unpack(hmacTypes_arraysize);
    if (hmacTypes_arraysize==0) {
        this->hmacTypes = 0;
    } else {
        this->hmacTypes = new uint16_t[hmacTypes_arraysize];
        doParsimArrayUnpacking(b,this->hmacTypes,hmacTypes_arraysize);
    }
    delete [] this->random;
    b->unpack(random_arraysize);
    if (random_arraysize==0) {
        this->random = 0;
    } else {
        this->random = new uint8_t[random_arraysize];
        doParsimArrayUnpacking(b,this->random,random_arraysize);
    }
}

uint32_t SCTPInitChunk::getInitTag() const
{
    return this->initTag;
}

void SCTPInitChunk::setInitTag(uint32_t initTag)
{
    this->initTag = initTag;
}

uint32_t SCTPInitChunk::getA_rwnd() const
{
    return this->a_rwnd;
}

void SCTPInitChunk::setA_rwnd(uint32_t a_rwnd)
{
    this->a_rwnd = a_rwnd;
}

uint16_t SCTPInitChunk::getNoOutStreams() const
{
    return this->noOutStreams;
}

void SCTPInitChunk::setNoOutStreams(uint16_t noOutStreams)
{
    this->noOutStreams = noOutStreams;
}

uint16_t SCTPInitChunk::getNoInStreams() const
{
    return this->noInStreams;
}

void SCTPInitChunk::setNoInStreams(uint16_t noInStreams)
{
    this->noInStreams = noInStreams;
}

uint32_t SCTPInitChunk::getInitTSN() const
{
    return this->initTSN;
}

void SCTPInitChunk::setInitTSN(uint32_t initTSN)
{
    this->initTSN = initTSN;
}

bool SCTPInitChunk::getForwardTsn() const
{
    return this->forwardTsn;
}

void SCTPInitChunk::setForwardTsn(bool forwardTsn)
{
    this->forwardTsn = forwardTsn;
}

bool SCTPInitChunk::getIpv4Supported() const
{
    return this->ipv4Supported;
}

void SCTPInitChunk::setIpv4Supported(bool ipv4Supported)
{
    this->ipv4Supported = ipv4Supported;
}

bool SCTPInitChunk::getIpv6Supported() const
{
    return this->ipv6Supported;
}

void SCTPInitChunk::setIpv6Supported(bool ipv6Supported)
{
    this->ipv6Supported = ipv6Supported;
}

void SCTPInitChunk::setAddressesArraySize(unsigned int size)
{
    L3Address *addresses2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = addresses_arraysize < size ? addresses_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        addresses2[i] = this->addresses[i];
    addresses_arraysize = size;
    delete [] this->addresses;
    this->addresses = addresses2;
}

unsigned int SCTPInitChunk::getAddressesArraySize() const
{
    return addresses_arraysize;
}

L3Address& SCTPInitChunk::getAddresses(unsigned int k)
{
    if (k>=addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    return this->addresses[k];
}

void SCTPInitChunk::setAddresses(unsigned int k, const L3Address& addresses)
{
    if (k>=addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    this->addresses[k] = addresses;
}

void SCTPInitChunk::setUnrecognizedParametersArraySize(unsigned int size)
{
    uint8_t *unrecognizedParameters2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = unrecognizedParameters_arraysize < size ? unrecognizedParameters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (unsigned int i=sz; i<size; i++)
        unrecognizedParameters2[i] = 0;
    unrecognizedParameters_arraysize = size;
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
}

unsigned int SCTPInitChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8_t SCTPInitChunk::getUnrecognizedParameters(unsigned int k) const
{
    if (k>=unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    return this->unrecognizedParameters[k];
}

void SCTPInitChunk::setUnrecognizedParameters(unsigned int k, uint8_t unrecognizedParameters)
{
    if (k>=unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    this->unrecognizedParameters[k] = unrecognizedParameters;
}

uint32_t SCTPInitChunk::getMsg_rwnd() const
{
    return this->msg_rwnd;
}

void SCTPInitChunk::setMsg_rwnd(uint32_t msg_rwnd)
{
    this->msg_rwnd = msg_rwnd;
}

void SCTPInitChunk::setChunkTypesArraySize(unsigned int size)
{
    uint16_t *chunkTypes2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = chunkTypes_arraysize < size ? chunkTypes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        chunkTypes2[i] = this->chunkTypes[i];
    for (unsigned int i=sz; i<size; i++)
        chunkTypes2[i] = 0;
    chunkTypes_arraysize = size;
    delete [] this->chunkTypes;
    this->chunkTypes = chunkTypes2;
}

unsigned int SCTPInitChunk::getChunkTypesArraySize() const
{
    return chunkTypes_arraysize;
}

uint16_t SCTPInitChunk::getChunkTypes(unsigned int k) const
{
    if (k>=chunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", chunkTypes_arraysize, k);
    return this->chunkTypes[k];
}

void SCTPInitChunk::setChunkTypes(unsigned int k, uint16_t chunkTypes)
{
    if (k>=chunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", chunkTypes_arraysize, k);
    this->chunkTypes[k] = chunkTypes;
}

void SCTPInitChunk::setSepChunksArraySize(unsigned int size)
{
    uint16_t *sepChunks2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = sepChunks_arraysize < size ? sepChunks_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sepChunks2[i] = this->sepChunks[i];
    for (unsigned int i=sz; i<size; i++)
        sepChunks2[i] = 0;
    sepChunks_arraysize = size;
    delete [] this->sepChunks;
    this->sepChunks = sepChunks2;
}

unsigned int SCTPInitChunk::getSepChunksArraySize() const
{
    return sepChunks_arraysize;
}

uint16_t SCTPInitChunk::getSepChunks(unsigned int k) const
{
    if (k>=sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sepChunks_arraysize, k);
    return this->sepChunks[k];
}

void SCTPInitChunk::setSepChunks(unsigned int k, uint16_t sepChunks)
{
    if (k>=sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sepChunks_arraysize, k);
    this->sepChunks[k] = sepChunks;
}

void SCTPInitChunk::setHmacTypesArraySize(unsigned int size)
{
    uint16_t *hmacTypes2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = hmacTypes_arraysize < size ? hmacTypes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        hmacTypes2[i] = this->hmacTypes[i];
    for (unsigned int i=sz; i<size; i++)
        hmacTypes2[i] = 0;
    hmacTypes_arraysize = size;
    delete [] this->hmacTypes;
    this->hmacTypes = hmacTypes2;
}

unsigned int SCTPInitChunk::getHmacTypesArraySize() const
{
    return hmacTypes_arraysize;
}

uint16_t SCTPInitChunk::getHmacTypes(unsigned int k) const
{
    if (k>=hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", hmacTypes_arraysize, k);
    return this->hmacTypes[k];
}

void SCTPInitChunk::setHmacTypes(unsigned int k, uint16_t hmacTypes)
{
    if (k>=hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", hmacTypes_arraysize, k);
    this->hmacTypes[k] = hmacTypes;
}

void SCTPInitChunk::setRandomArraySize(unsigned int size)
{
    uint8_t *random2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = random_arraysize < size ? random_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        random2[i] = this->random[i];
    for (unsigned int i=sz; i<size; i++)
        random2[i] = 0;
    random_arraysize = size;
    delete [] this->random;
    this->random = random2;
}

unsigned int SCTPInitChunk::getRandomArraySize() const
{
    return random_arraysize;
}

uint8_t SCTPInitChunk::getRandom(unsigned int k) const
{
    if (k>=random_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", random_arraysize, k);
    return this->random[k];
}

void SCTPInitChunk::setRandom(unsigned int k, uint8_t random)
{
    if (k>=random_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", random_arraysize, k);
    this->random[k] = random;
}

class SCTPInitChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPInitChunkDescriptor();
    virtual ~SCTPInitChunkDescriptor();

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

Register_ClassDescriptor(SCTPInitChunkDescriptor)

SCTPInitChunkDescriptor::SCTPInitChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPInitChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPInitChunkDescriptor::~SCTPInitChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPInitChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPInitChunk *>(obj)!=nullptr;
}

const char **SCTPInitChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPInitChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPInitChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount() : 15;
}

unsigned int SCTPInitChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<15) ? fieldTypeFlags[field] : 0;
}

const char *SCTPInitChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "initTag",
        "a_rwnd",
        "noOutStreams",
        "noInStreams",
        "initTSN",
        "forwardTsn",
        "ipv4Supported",
        "ipv6Supported",
        "addresses",
        "unrecognizedParameters",
        "msg_rwnd",
        "chunkTypes",
        "sepChunks",
        "hmacTypes",
        "random",
    };
    return (field>=0 && field<15) ? fieldNames[field] : nullptr;
}

int SCTPInitChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "initTag")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a_rwnd")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "noOutStreams")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "noInStreams")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "initTSN")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardTsn")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "ipv4Supported")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "ipv6Supported")==0) return base+7;
    if (fieldName[0]=='a' && strcmp(fieldName, "addresses")==0) return base+8;
    if (fieldName[0]=='u' && strcmp(fieldName, "unrecognizedParameters")==0) return base+9;
    if (fieldName[0]=='m' && strcmp(fieldName, "msg_rwnd")==0) return base+10;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunkTypes")==0) return base+11;
    if (fieldName[0]=='s' && strcmp(fieldName, "sepChunks")==0) return base+12;
    if (fieldName[0]=='h' && strcmp(fieldName, "hmacTypes")==0) return base+13;
    if (fieldName[0]=='r' && strcmp(fieldName, "random")==0) return base+14;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPInitChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
        "uint16",
        "uint16",
        "uint32",
        "bool",
        "bool",
        "bool",
        "L3Address",
        "uint8",
        "uint32",
        "uint16",
        "uint16",
        "uint16",
        "uint8",
    };
    return (field>=0 && field<15) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPInitChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPInitChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPInitChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        case 8: return pp->getAddressesArraySize();
        case 9: return pp->getUnrecognizedParametersArraySize();
        case 11: return pp->getChunkTypesArraySize();
        case 12: return pp->getSepChunksArraySize();
        case 13: return pp->getHmacTypesArraySize();
        case 14: return pp->getRandomArraySize();
        default: return 0;
    }
}

const char *SCTPInitChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPInitChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getInitTag());
        case 1: return ulong2string(pp->getA_rwnd());
        case 2: return ulong2string(pp->getNoOutStreams());
        case 3: return ulong2string(pp->getNoInStreams());
        case 4: return ulong2string(pp->getInitTSN());
        case 5: return bool2string(pp->getForwardTsn());
        case 6: return bool2string(pp->getIpv4Supported());
        case 7: return bool2string(pp->getIpv6Supported());
        case 8: {std::stringstream out; out << pp->getAddresses(i); return out.str();}
        case 9: return ulong2string(pp->getUnrecognizedParameters(i));
        case 10: return ulong2string(pp->getMsg_rwnd());
        case 11: return ulong2string(pp->getChunkTypes(i));
        case 12: return ulong2string(pp->getSepChunks(i));
        case 13: return ulong2string(pp->getHmacTypes(i));
        case 14: return ulong2string(pp->getRandom(i));
        default: return "";
    }
}

bool SCTPInitChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setInitTag(string2ulong(value)); return true;
        case 1: pp->setA_rwnd(string2ulong(value)); return true;
        case 2: pp->setNoOutStreams(string2ulong(value)); return true;
        case 3: pp->setNoInStreams(string2ulong(value)); return true;
        case 4: pp->setInitTSN(string2ulong(value)); return true;
        case 5: pp->setForwardTsn(string2bool(value)); return true;
        case 6: pp->setIpv4Supported(string2bool(value)); return true;
        case 7: pp->setIpv6Supported(string2bool(value)); return true;
        case 9: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        case 10: pp->setMsg_rwnd(string2ulong(value)); return true;
        case 11: pp->setChunkTypes(i,string2ulong(value)); return true;
        case 12: pp->setSepChunks(i,string2ulong(value)); return true;
        case 13: pp->setHmacTypes(i,string2ulong(value)); return true;
        case 14: pp->setRandom(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPInitChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 8: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPInitChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPInitChunk *pp = (SCTPInitChunk *)object; (void)pp;
    switch (field) {
        case 8: return (void *)(&pp->getAddresses(i)); break;
        default: return nullptr;
    }
}

Register_Class(SCTPInitAckChunk)

SCTPInitAckChunk::SCTPInitAckChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->initTag = 0;
    this->a_rwnd = 0;
    this->noOutStreams = 0;
    this->noInStreams = 0;
    this->initTSN = 0;
    this->forwardTsn = false;
    this->ipv4Supported = false;
    this->ipv6Supported = false;
    addresses_arraysize = 0;
    this->addresses = 0;
    cookie_arraysize = 0;
    this->cookie = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters = 0;
    this->stateCookie = nullptr;
    this->msg_rwnd = 0;
    random_arraysize = 0;
    this->random = 0;
    chunkTypes_arraysize = 0;
    this->chunkTypes = 0;
    sepChunks_arraysize = 0;
    this->sepChunks = 0;
    hmacTypes_arraysize = 0;
    this->hmacTypes = 0;
}

SCTPInitAckChunk::SCTPInitAckChunk(const SCTPInitAckChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    addresses_arraysize = 0;
    this->addresses = 0;
    cookie_arraysize = 0;
    this->cookie = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters = 0;
    random_arraysize = 0;
    this->random = 0;
    chunkTypes_arraysize = 0;
    this->chunkTypes = 0;
    sepChunks_arraysize = 0;
    this->sepChunks = 0;
    hmacTypes_arraysize = 0;
    this->hmacTypes = 0;
    copy(other);
}

SCTPInitAckChunk::~SCTPInitAckChunk()
{
    delete [] this->addresses;
    delete [] this->cookie;
    delete [] this->unrecognizedParameters;
    delete [] this->random;
    delete [] this->chunkTypes;
    delete [] this->sepChunks;
    delete [] this->hmacTypes;
}

SCTPInitAckChunk& SCTPInitAckChunk::operator=(const SCTPInitAckChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPInitAckChunk::copy(const SCTPInitAckChunk& other)
{
    this->initTag = other.initTag;
    this->a_rwnd = other.a_rwnd;
    this->noOutStreams = other.noOutStreams;
    this->noInStreams = other.noInStreams;
    this->initTSN = other.initTSN;
    this->forwardTsn = other.forwardTsn;
    this->ipv4Supported = other.ipv4Supported;
    this->ipv6Supported = other.ipv6Supported;
    delete [] this->addresses;
    this->addresses = (other.addresses_arraysize==0) ? nullptr : new L3Address[other.addresses_arraysize];
    addresses_arraysize = other.addresses_arraysize;
    for (unsigned int i=0; i<addresses_arraysize; i++)
        this->addresses[i] = other.addresses[i];
    delete [] this->cookie;
    this->cookie = (other.cookie_arraysize==0) ? nullptr : new char[other.cookie_arraysize];
    cookie_arraysize = other.cookie_arraysize;
    for (unsigned int i=0; i<cookie_arraysize; i++)
        this->cookie[i] = other.cookie[i];
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = (other.unrecognizedParameters_arraysize==0) ? nullptr : new uint8_t[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (unsigned int i=0; i<unrecognizedParameters_arraysize; i++)
        this->unrecognizedParameters[i] = other.unrecognizedParameters[i];
    this->stateCookie = other.stateCookie;
    this->msg_rwnd = other.msg_rwnd;
    delete [] this->random;
    this->random = (other.random_arraysize==0) ? nullptr : new uint8_t[other.random_arraysize];
    random_arraysize = other.random_arraysize;
    for (unsigned int i=0; i<random_arraysize; i++)
        this->random[i] = other.random[i];
    delete [] this->chunkTypes;
    this->chunkTypes = (other.chunkTypes_arraysize==0) ? nullptr : new uint16_t[other.chunkTypes_arraysize];
    chunkTypes_arraysize = other.chunkTypes_arraysize;
    for (unsigned int i=0; i<chunkTypes_arraysize; i++)
        this->chunkTypes[i] = other.chunkTypes[i];
    delete [] this->sepChunks;
    this->sepChunks = (other.sepChunks_arraysize==0) ? nullptr : new uint16_t[other.sepChunks_arraysize];
    sepChunks_arraysize = other.sepChunks_arraysize;
    for (unsigned int i=0; i<sepChunks_arraysize; i++)
        this->sepChunks[i] = other.sepChunks[i];
    delete [] this->hmacTypes;
    this->hmacTypes = (other.hmacTypes_arraysize==0) ? nullptr : new uint16_t[other.hmacTypes_arraysize];
    hmacTypes_arraysize = other.hmacTypes_arraysize;
    for (unsigned int i=0; i<hmacTypes_arraysize; i++)
        this->hmacTypes[i] = other.hmacTypes[i];
}

void SCTPInitAckChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->initTag);
    doParsimPacking(b,this->a_rwnd);
    doParsimPacking(b,this->noOutStreams);
    doParsimPacking(b,this->noInStreams);
    doParsimPacking(b,this->initTSN);
    doParsimPacking(b,this->forwardTsn);
    doParsimPacking(b,this->ipv4Supported);
    doParsimPacking(b,this->ipv6Supported);
    b->pack(addresses_arraysize);
    doParsimArrayPacking(b,this->addresses,addresses_arraysize);
    b->pack(cookie_arraysize);
    doParsimArrayPacking(b,this->cookie,cookie_arraysize);
    b->pack(unrecognizedParameters_arraysize);
    doParsimArrayPacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    doParsimPacking(b,this->stateCookie);
    doParsimPacking(b,this->msg_rwnd);
    b->pack(random_arraysize);
    doParsimArrayPacking(b,this->random,random_arraysize);
    b->pack(chunkTypes_arraysize);
    doParsimArrayPacking(b,this->chunkTypes,chunkTypes_arraysize);
    b->pack(sepChunks_arraysize);
    doParsimArrayPacking(b,this->sepChunks,sepChunks_arraysize);
    b->pack(hmacTypes_arraysize);
    doParsimArrayPacking(b,this->hmacTypes,hmacTypes_arraysize);
}

void SCTPInitAckChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->initTag);
    doParsimUnpacking(b,this->a_rwnd);
    doParsimUnpacking(b,this->noOutStreams);
    doParsimUnpacking(b,this->noInStreams);
    doParsimUnpacking(b,this->initTSN);
    doParsimUnpacking(b,this->forwardTsn);
    doParsimUnpacking(b,this->ipv4Supported);
    doParsimUnpacking(b,this->ipv6Supported);
    delete [] this->addresses;
    b->unpack(addresses_arraysize);
    if (addresses_arraysize==0) {
        this->addresses = 0;
    } else {
        this->addresses = new L3Address[addresses_arraysize];
        doParsimArrayUnpacking(b,this->addresses,addresses_arraysize);
    }
    delete [] this->cookie;
    b->unpack(cookie_arraysize);
    if (cookie_arraysize==0) {
        this->cookie = 0;
    } else {
        this->cookie = new char[cookie_arraysize];
        doParsimArrayUnpacking(b,this->cookie,cookie_arraysize);
    }
    delete [] this->unrecognizedParameters;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize==0) {
        this->unrecognizedParameters = 0;
    } else {
        this->unrecognizedParameters = new uint8_t[unrecognizedParameters_arraysize];
        doParsimArrayUnpacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    }
    doParsimUnpacking(b,this->stateCookie);
    doParsimUnpacking(b,this->msg_rwnd);
    delete [] this->random;
    b->unpack(random_arraysize);
    if (random_arraysize==0) {
        this->random = 0;
    } else {
        this->random = new uint8_t[random_arraysize];
        doParsimArrayUnpacking(b,this->random,random_arraysize);
    }
    delete [] this->chunkTypes;
    b->unpack(chunkTypes_arraysize);
    if (chunkTypes_arraysize==0) {
        this->chunkTypes = 0;
    } else {
        this->chunkTypes = new uint16_t[chunkTypes_arraysize];
        doParsimArrayUnpacking(b,this->chunkTypes,chunkTypes_arraysize);
    }
    delete [] this->sepChunks;
    b->unpack(sepChunks_arraysize);
    if (sepChunks_arraysize==0) {
        this->sepChunks = 0;
    } else {
        this->sepChunks = new uint16_t[sepChunks_arraysize];
        doParsimArrayUnpacking(b,this->sepChunks,sepChunks_arraysize);
    }
    delete [] this->hmacTypes;
    b->unpack(hmacTypes_arraysize);
    if (hmacTypes_arraysize==0) {
        this->hmacTypes = 0;
    } else {
        this->hmacTypes = new uint16_t[hmacTypes_arraysize];
        doParsimArrayUnpacking(b,this->hmacTypes,hmacTypes_arraysize);
    }
}

uint32_t SCTPInitAckChunk::getInitTag() const
{
    return this->initTag;
}

void SCTPInitAckChunk::setInitTag(uint32_t initTag)
{
    this->initTag = initTag;
}

uint32_t SCTPInitAckChunk::getA_rwnd() const
{
    return this->a_rwnd;
}

void SCTPInitAckChunk::setA_rwnd(uint32_t a_rwnd)
{
    this->a_rwnd = a_rwnd;
}

uint16_t SCTPInitAckChunk::getNoOutStreams() const
{
    return this->noOutStreams;
}

void SCTPInitAckChunk::setNoOutStreams(uint16_t noOutStreams)
{
    this->noOutStreams = noOutStreams;
}

uint16_t SCTPInitAckChunk::getNoInStreams() const
{
    return this->noInStreams;
}

void SCTPInitAckChunk::setNoInStreams(uint16_t noInStreams)
{
    this->noInStreams = noInStreams;
}

uint32_t SCTPInitAckChunk::getInitTSN() const
{
    return this->initTSN;
}

void SCTPInitAckChunk::setInitTSN(uint32_t initTSN)
{
    this->initTSN = initTSN;
}

bool SCTPInitAckChunk::getForwardTsn() const
{
    return this->forwardTsn;
}

void SCTPInitAckChunk::setForwardTsn(bool forwardTsn)
{
    this->forwardTsn = forwardTsn;
}

bool SCTPInitAckChunk::getIpv4Supported() const
{
    return this->ipv4Supported;
}

void SCTPInitAckChunk::setIpv4Supported(bool ipv4Supported)
{
    this->ipv4Supported = ipv4Supported;
}

bool SCTPInitAckChunk::getIpv6Supported() const
{
    return this->ipv6Supported;
}

void SCTPInitAckChunk::setIpv6Supported(bool ipv6Supported)
{
    this->ipv6Supported = ipv6Supported;
}

void SCTPInitAckChunk::setAddressesArraySize(unsigned int size)
{
    L3Address *addresses2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = addresses_arraysize < size ? addresses_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        addresses2[i] = this->addresses[i];
    addresses_arraysize = size;
    delete [] this->addresses;
    this->addresses = addresses2;
}

unsigned int SCTPInitAckChunk::getAddressesArraySize() const
{
    return addresses_arraysize;
}

L3Address& SCTPInitAckChunk::getAddresses(unsigned int k)
{
    if (k>=addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    return this->addresses[k];
}

void SCTPInitAckChunk::setAddresses(unsigned int k, const L3Address& addresses)
{
    if (k>=addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", addresses_arraysize, k);
    this->addresses[k] = addresses;
}

void SCTPInitAckChunk::setCookieArraySize(unsigned int size)
{
    char *cookie2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = cookie_arraysize < size ? cookie_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        cookie2[i] = this->cookie[i];
    for (unsigned int i=sz; i<size; i++)
        cookie2[i] = 0;
    cookie_arraysize = size;
    delete [] this->cookie;
    this->cookie = cookie2;
}

unsigned int SCTPInitAckChunk::getCookieArraySize() const
{
    return cookie_arraysize;
}

char SCTPInitAckChunk::getCookie(unsigned int k) const
{
    if (k>=cookie_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", cookie_arraysize, k);
    return this->cookie[k];
}

void SCTPInitAckChunk::setCookie(unsigned int k, char cookie)
{
    if (k>=cookie_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", cookie_arraysize, k);
    this->cookie[k] = cookie;
}

void SCTPInitAckChunk::setUnrecognizedParametersArraySize(unsigned int size)
{
    uint8_t *unrecognizedParameters2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = unrecognizedParameters_arraysize < size ? unrecognizedParameters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (unsigned int i=sz; i<size; i++)
        unrecognizedParameters2[i] = 0;
    unrecognizedParameters_arraysize = size;
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
}

unsigned int SCTPInitAckChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8_t SCTPInitAckChunk::getUnrecognizedParameters(unsigned int k) const
{
    if (k>=unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    return this->unrecognizedParameters[k];
}

void SCTPInitAckChunk::setUnrecognizedParameters(unsigned int k, uint8_t unrecognizedParameters)
{
    if (k>=unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    this->unrecognizedParameters[k] = unrecognizedParameters;
}

cPacketPtr& SCTPInitAckChunk::getStateCookie()
{
    return this->stateCookie;
}

void SCTPInitAckChunk::setStateCookie(const cPacketPtr& stateCookie)
{
    this->stateCookie = stateCookie;
}

uint32_t SCTPInitAckChunk::getMsg_rwnd() const
{
    return this->msg_rwnd;
}

void SCTPInitAckChunk::setMsg_rwnd(uint32_t msg_rwnd)
{
    this->msg_rwnd = msg_rwnd;
}

void SCTPInitAckChunk::setRandomArraySize(unsigned int size)
{
    uint8_t *random2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = random_arraysize < size ? random_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        random2[i] = this->random[i];
    for (unsigned int i=sz; i<size; i++)
        random2[i] = 0;
    random_arraysize = size;
    delete [] this->random;
    this->random = random2;
}

unsigned int SCTPInitAckChunk::getRandomArraySize() const
{
    return random_arraysize;
}

uint8_t SCTPInitAckChunk::getRandom(unsigned int k) const
{
    if (k>=random_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", random_arraysize, k);
    return this->random[k];
}

void SCTPInitAckChunk::setRandom(unsigned int k, uint8_t random)
{
    if (k>=random_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", random_arraysize, k);
    this->random[k] = random;
}

void SCTPInitAckChunk::setChunkTypesArraySize(unsigned int size)
{
    uint16_t *chunkTypes2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = chunkTypes_arraysize < size ? chunkTypes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        chunkTypes2[i] = this->chunkTypes[i];
    for (unsigned int i=sz; i<size; i++)
        chunkTypes2[i] = 0;
    chunkTypes_arraysize = size;
    delete [] this->chunkTypes;
    this->chunkTypes = chunkTypes2;
}

unsigned int SCTPInitAckChunk::getChunkTypesArraySize() const
{
    return chunkTypes_arraysize;
}

uint16_t SCTPInitAckChunk::getChunkTypes(unsigned int k) const
{
    if (k>=chunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", chunkTypes_arraysize, k);
    return this->chunkTypes[k];
}

void SCTPInitAckChunk::setChunkTypes(unsigned int k, uint16_t chunkTypes)
{
    if (k>=chunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", chunkTypes_arraysize, k);
    this->chunkTypes[k] = chunkTypes;
}

void SCTPInitAckChunk::setSepChunksArraySize(unsigned int size)
{
    uint16_t *sepChunks2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = sepChunks_arraysize < size ? sepChunks_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sepChunks2[i] = this->sepChunks[i];
    for (unsigned int i=sz; i<size; i++)
        sepChunks2[i] = 0;
    sepChunks_arraysize = size;
    delete [] this->sepChunks;
    this->sepChunks = sepChunks2;
}

unsigned int SCTPInitAckChunk::getSepChunksArraySize() const
{
    return sepChunks_arraysize;
}

uint16_t SCTPInitAckChunk::getSepChunks(unsigned int k) const
{
    if (k>=sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sepChunks_arraysize, k);
    return this->sepChunks[k];
}

void SCTPInitAckChunk::setSepChunks(unsigned int k, uint16_t sepChunks)
{
    if (k>=sepChunks_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sepChunks_arraysize, k);
    this->sepChunks[k] = sepChunks;
}

void SCTPInitAckChunk::setHmacTypesArraySize(unsigned int size)
{
    uint16_t *hmacTypes2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = hmacTypes_arraysize < size ? hmacTypes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        hmacTypes2[i] = this->hmacTypes[i];
    for (unsigned int i=sz; i<size; i++)
        hmacTypes2[i] = 0;
    hmacTypes_arraysize = size;
    delete [] this->hmacTypes;
    this->hmacTypes = hmacTypes2;
}

unsigned int SCTPInitAckChunk::getHmacTypesArraySize() const
{
    return hmacTypes_arraysize;
}

uint16_t SCTPInitAckChunk::getHmacTypes(unsigned int k) const
{
    if (k>=hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", hmacTypes_arraysize, k);
    return this->hmacTypes[k];
}

void SCTPInitAckChunk::setHmacTypes(unsigned int k, uint16_t hmacTypes)
{
    if (k>=hmacTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", hmacTypes_arraysize, k);
    this->hmacTypes[k] = hmacTypes;
}

class SCTPInitAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPInitAckChunkDescriptor();
    virtual ~SCTPInitAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPInitAckChunkDescriptor)

SCTPInitAckChunkDescriptor::SCTPInitAckChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPInitAckChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPInitAckChunkDescriptor::~SCTPInitAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPInitAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPInitAckChunk *>(obj)!=nullptr;
}

const char **SCTPInitAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPInitAckChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPInitAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 17+basedesc->getFieldCount() : 17;
}

unsigned int SCTPInitAckChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<17) ? fieldTypeFlags[field] : 0;
}

const char *SCTPInitAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "initTag",
        "a_rwnd",
        "noOutStreams",
        "noInStreams",
        "initTSN",
        "forwardTsn",
        "ipv4Supported",
        "ipv6Supported",
        "addresses",
        "cookie",
        "unrecognizedParameters",
        "stateCookie",
        "msg_rwnd",
        "random",
        "chunkTypes",
        "sepChunks",
        "hmacTypes",
    };
    return (field>=0 && field<17) ? fieldNames[field] : nullptr;
}

int SCTPInitAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "initTag")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a_rwnd")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "noOutStreams")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "noInStreams")==0) return base+3;
    if (fieldName[0]=='i' && strcmp(fieldName, "initTSN")==0) return base+4;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardTsn")==0) return base+5;
    if (fieldName[0]=='i' && strcmp(fieldName, "ipv4Supported")==0) return base+6;
    if (fieldName[0]=='i' && strcmp(fieldName, "ipv6Supported")==0) return base+7;
    if (fieldName[0]=='a' && strcmp(fieldName, "addresses")==0) return base+8;
    if (fieldName[0]=='c' && strcmp(fieldName, "cookie")==0) return base+9;
    if (fieldName[0]=='u' && strcmp(fieldName, "unrecognizedParameters")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "stateCookie")==0) return base+11;
    if (fieldName[0]=='m' && strcmp(fieldName, "msg_rwnd")==0) return base+12;
    if (fieldName[0]=='r' && strcmp(fieldName, "random")==0) return base+13;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunkTypes")==0) return base+14;
    if (fieldName[0]=='s' && strcmp(fieldName, "sepChunks")==0) return base+15;
    if (fieldName[0]=='h' && strcmp(fieldName, "hmacTypes")==0) return base+16;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPInitAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
        "uint16",
        "uint16",
        "uint32",
        "bool",
        "bool",
        "bool",
        "L3Address",
        "char",
        "uint8",
        "cPacketPtr",
        "uint32",
        "uint8",
        "uint16",
        "uint16",
        "uint16",
    };
    return (field>=0 && field<17) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPInitAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPInitAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPInitAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        case 8: return pp->getAddressesArraySize();
        case 9: return pp->getCookieArraySize();
        case 10: return pp->getUnrecognizedParametersArraySize();
        case 13: return pp->getRandomArraySize();
        case 14: return pp->getChunkTypesArraySize();
        case 15: return pp->getSepChunksArraySize();
        case 16: return pp->getHmacTypesArraySize();
        default: return 0;
    }
}

const char *SCTPInitAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPInitAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getInitTag());
        case 1: return ulong2string(pp->getA_rwnd());
        case 2: return ulong2string(pp->getNoOutStreams());
        case 3: return ulong2string(pp->getNoInStreams());
        case 4: return ulong2string(pp->getInitTSN());
        case 5: return bool2string(pp->getForwardTsn());
        case 6: return bool2string(pp->getIpv4Supported());
        case 7: return bool2string(pp->getIpv6Supported());
        case 8: {std::stringstream out; out << pp->getAddresses(i); return out.str();}
        case 9: return long2string(pp->getCookie(i));
        case 10: return ulong2string(pp->getUnrecognizedParameters(i));
        case 11: {std::stringstream out; out << pp->getStateCookie(); return out.str();}
        case 12: return ulong2string(pp->getMsg_rwnd());
        case 13: return ulong2string(pp->getRandom(i));
        case 14: return ulong2string(pp->getChunkTypes(i));
        case 15: return ulong2string(pp->getSepChunks(i));
        case 16: return ulong2string(pp->getHmacTypes(i));
        default: return "";
    }
}

bool SCTPInitAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setInitTag(string2ulong(value)); return true;
        case 1: pp->setA_rwnd(string2ulong(value)); return true;
        case 2: pp->setNoOutStreams(string2ulong(value)); return true;
        case 3: pp->setNoInStreams(string2ulong(value)); return true;
        case 4: pp->setInitTSN(string2ulong(value)); return true;
        case 5: pp->setForwardTsn(string2bool(value)); return true;
        case 6: pp->setIpv4Supported(string2bool(value)); return true;
        case 7: pp->setIpv6Supported(string2bool(value)); return true;
        case 9: pp->setCookie(i,string2long(value)); return true;
        case 10: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        case 12: pp->setMsg_rwnd(string2ulong(value)); return true;
        case 13: pp->setRandom(i,string2ulong(value)); return true;
        case 14: pp->setChunkTypes(i,string2ulong(value)); return true;
        case 15: pp->setSepChunks(i,string2ulong(value)); return true;
        case 16: pp->setHmacTypes(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPInitAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 8: return omnetpp::opp_typename(typeid(L3Address));
        case 11: return omnetpp::opp_typename(typeid(cPacketPtr));
        default: return nullptr;
    };
}

void *SCTPInitAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPInitAckChunk *pp = (SCTPInitAckChunk *)object; (void)pp;
    switch (field) {
        case 8: return (void *)(&pp->getAddresses(i)); break;
        case 11: return (void *)(&pp->getStateCookie()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPCookieEchoChunk)

SCTPCookieEchoChunk::SCTPCookieEchoChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    cookie_arraysize = 0;
    this->cookie = 0;
    this->stateCookie = nullptr;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters = 0;
}

SCTPCookieEchoChunk::SCTPCookieEchoChunk(const SCTPCookieEchoChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    cookie_arraysize = 0;
    this->cookie = 0;
    unrecognizedParameters_arraysize = 0;
    this->unrecognizedParameters = 0;
    copy(other);
}

SCTPCookieEchoChunk::~SCTPCookieEchoChunk()
{
    delete [] this->cookie;
    delete [] this->unrecognizedParameters;
}

SCTPCookieEchoChunk& SCTPCookieEchoChunk::operator=(const SCTPCookieEchoChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPCookieEchoChunk::copy(const SCTPCookieEchoChunk& other)
{
    delete [] this->cookie;
    this->cookie = (other.cookie_arraysize==0) ? nullptr : new char[other.cookie_arraysize];
    cookie_arraysize = other.cookie_arraysize;
    for (unsigned int i=0; i<cookie_arraysize; i++)
        this->cookie[i] = other.cookie[i];
    this->stateCookie = other.stateCookie;
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = (other.unrecognizedParameters_arraysize==0) ? nullptr : new uint8_t[other.unrecognizedParameters_arraysize];
    unrecognizedParameters_arraysize = other.unrecognizedParameters_arraysize;
    for (unsigned int i=0; i<unrecognizedParameters_arraysize; i++)
        this->unrecognizedParameters[i] = other.unrecognizedParameters[i];
}

void SCTPCookieEchoChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    b->pack(cookie_arraysize);
    doParsimArrayPacking(b,this->cookie,cookie_arraysize);
    doParsimPacking(b,this->stateCookie);
    b->pack(unrecognizedParameters_arraysize);
    doParsimArrayPacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
}

void SCTPCookieEchoChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    delete [] this->cookie;
    b->unpack(cookie_arraysize);
    if (cookie_arraysize==0) {
        this->cookie = 0;
    } else {
        this->cookie = new char[cookie_arraysize];
        doParsimArrayUnpacking(b,this->cookie,cookie_arraysize);
    }
    doParsimUnpacking(b,this->stateCookie);
    delete [] this->unrecognizedParameters;
    b->unpack(unrecognizedParameters_arraysize);
    if (unrecognizedParameters_arraysize==0) {
        this->unrecognizedParameters = 0;
    } else {
        this->unrecognizedParameters = new uint8_t[unrecognizedParameters_arraysize];
        doParsimArrayUnpacking(b,this->unrecognizedParameters,unrecognizedParameters_arraysize);
    }
}

void SCTPCookieEchoChunk::setCookieArraySize(unsigned int size)
{
    char *cookie2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = cookie_arraysize < size ? cookie_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        cookie2[i] = this->cookie[i];
    for (unsigned int i=sz; i<size; i++)
        cookie2[i] = 0;
    cookie_arraysize = size;
    delete [] this->cookie;
    this->cookie = cookie2;
}

unsigned int SCTPCookieEchoChunk::getCookieArraySize() const
{
    return cookie_arraysize;
}

char SCTPCookieEchoChunk::getCookie(unsigned int k) const
{
    if (k>=cookie_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", cookie_arraysize, k);
    return this->cookie[k];
}

void SCTPCookieEchoChunk::setCookie(unsigned int k, char cookie)
{
    if (k>=cookie_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", cookie_arraysize, k);
    this->cookie[k] = cookie;
}

cPacketPtr& SCTPCookieEchoChunk::getStateCookie()
{
    return this->stateCookie;
}

void SCTPCookieEchoChunk::setStateCookie(const cPacketPtr& stateCookie)
{
    this->stateCookie = stateCookie;
}

void SCTPCookieEchoChunk::setUnrecognizedParametersArraySize(unsigned int size)
{
    uint8_t *unrecognizedParameters2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = unrecognizedParameters_arraysize < size ? unrecognizedParameters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        unrecognizedParameters2[i] = this->unrecognizedParameters[i];
    for (unsigned int i=sz; i<size; i++)
        unrecognizedParameters2[i] = 0;
    unrecognizedParameters_arraysize = size;
    delete [] this->unrecognizedParameters;
    this->unrecognizedParameters = unrecognizedParameters2;
}

unsigned int SCTPCookieEchoChunk::getUnrecognizedParametersArraySize() const
{
    return unrecognizedParameters_arraysize;
}

uint8_t SCTPCookieEchoChunk::getUnrecognizedParameters(unsigned int k) const
{
    if (k>=unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    return this->unrecognizedParameters[k];
}

void SCTPCookieEchoChunk::setUnrecognizedParameters(unsigned int k, uint8_t unrecognizedParameters)
{
    if (k>=unrecognizedParameters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", unrecognizedParameters_arraysize, k);
    this->unrecognizedParameters[k] = unrecognizedParameters;
}

class SCTPCookieEchoChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPCookieEchoChunkDescriptor();
    virtual ~SCTPCookieEchoChunkDescriptor();

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

Register_ClassDescriptor(SCTPCookieEchoChunkDescriptor)

SCTPCookieEchoChunkDescriptor::SCTPCookieEchoChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPCookieEchoChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPCookieEchoChunkDescriptor::~SCTPCookieEchoChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPCookieEchoChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPCookieEchoChunk *>(obj)!=nullptr;
}

const char **SCTPCookieEchoChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPCookieEchoChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPCookieEchoChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SCTPCookieEchoChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SCTPCookieEchoChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cookie",
        "stateCookie",
        "unrecognizedParameters",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int SCTPCookieEchoChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cookie")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stateCookie")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "unrecognizedParameters")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPCookieEchoChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "cPacketPtr",
        "uint8",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPCookieEchoChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPCookieEchoChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPCookieEchoChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case 0: return pp->getCookieArraySize();
        case 2: return pp->getUnrecognizedParametersArraySize();
        default: return 0;
    }
}

const char *SCTPCookieEchoChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPCookieEchoChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCookie(i));
        case 1: {std::stringstream out; out << pp->getStateCookie(); return out.str();}
        case 2: return ulong2string(pp->getUnrecognizedParameters(i));
        default: return "";
    }
}

bool SCTPCookieEchoChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setCookie(i,string2long(value)); return true;
        case 2: pp->setUnrecognizedParameters(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPCookieEchoChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cPacketPtr));
        default: return nullptr;
    };
}

void *SCTPCookieEchoChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieEchoChunk *pp = (SCTPCookieEchoChunk *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getStateCookie()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPCookie)

SCTPCookie::SCTPCookie(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->creationTime = 0;
    this->localTag = 0;
    this->peerTag = 0;
    localTieTag_arraysize = 0;
    this->localTieTag = 0;
    peerTieTag_arraysize = 0;
    this->peerTieTag = 0;
}

SCTPCookie::SCTPCookie(const SCTPCookie& other) : ::omnetpp::cPacket(other)
{
    localTieTag_arraysize = 0;
    this->localTieTag = 0;
    peerTieTag_arraysize = 0;
    this->peerTieTag = 0;
    copy(other);
}

SCTPCookie::~SCTPCookie()
{
    delete [] this->localTieTag;
    delete [] this->peerTieTag;
}

SCTPCookie& SCTPCookie::operator=(const SCTPCookie& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPCookie::copy(const SCTPCookie& other)
{
    this->creationTime = other.creationTime;
    this->localTag = other.localTag;
    this->peerTag = other.peerTag;
    delete [] this->localTieTag;
    this->localTieTag = (other.localTieTag_arraysize==0) ? nullptr : new uint8_t[other.localTieTag_arraysize];
    localTieTag_arraysize = other.localTieTag_arraysize;
    for (unsigned int i=0; i<localTieTag_arraysize; i++)
        this->localTieTag[i] = other.localTieTag[i];
    delete [] this->peerTieTag;
    this->peerTieTag = (other.peerTieTag_arraysize==0) ? nullptr : new uint8_t[other.peerTieTag_arraysize];
    peerTieTag_arraysize = other.peerTieTag_arraysize;
    for (unsigned int i=0; i<peerTieTag_arraysize; i++)
        this->peerTieTag[i] = other.peerTieTag[i];
}

void SCTPCookie::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->creationTime);
    doParsimPacking(b,this->localTag);
    doParsimPacking(b,this->peerTag);
    b->pack(localTieTag_arraysize);
    doParsimArrayPacking(b,this->localTieTag,localTieTag_arraysize);
    b->pack(peerTieTag_arraysize);
    doParsimArrayPacking(b,this->peerTieTag,peerTieTag_arraysize);
}

void SCTPCookie::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->creationTime);
    doParsimUnpacking(b,this->localTag);
    doParsimUnpacking(b,this->peerTag);
    delete [] this->localTieTag;
    b->unpack(localTieTag_arraysize);
    if (localTieTag_arraysize==0) {
        this->localTieTag = 0;
    } else {
        this->localTieTag = new uint8_t[localTieTag_arraysize];
        doParsimArrayUnpacking(b,this->localTieTag,localTieTag_arraysize);
    }
    delete [] this->peerTieTag;
    b->unpack(peerTieTag_arraysize);
    if (peerTieTag_arraysize==0) {
        this->peerTieTag = 0;
    } else {
        this->peerTieTag = new uint8_t[peerTieTag_arraysize];
        doParsimArrayUnpacking(b,this->peerTieTag,peerTieTag_arraysize);
    }
}

::omnetpp::simtime_t SCTPCookie::getCreationTime() const
{
    return this->creationTime;
}

void SCTPCookie::setCreationTime(::omnetpp::simtime_t creationTime)
{
    this->creationTime = creationTime;
}

uint32_t SCTPCookie::getLocalTag() const
{
    return this->localTag;
}

void SCTPCookie::setLocalTag(uint32_t localTag)
{
    this->localTag = localTag;
}

uint32_t SCTPCookie::getPeerTag() const
{
    return this->peerTag;
}

void SCTPCookie::setPeerTag(uint32_t peerTag)
{
    this->peerTag = peerTag;
}

void SCTPCookie::setLocalTieTagArraySize(unsigned int size)
{
    uint8_t *localTieTag2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = localTieTag_arraysize < size ? localTieTag_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        localTieTag2[i] = this->localTieTag[i];
    for (unsigned int i=sz; i<size; i++)
        localTieTag2[i] = 0;
    localTieTag_arraysize = size;
    delete [] this->localTieTag;
    this->localTieTag = localTieTag2;
}

unsigned int SCTPCookie::getLocalTieTagArraySize() const
{
    return localTieTag_arraysize;
}

uint8_t SCTPCookie::getLocalTieTag(unsigned int k) const
{
    if (k>=localTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", localTieTag_arraysize, k);
    return this->localTieTag[k];
}

void SCTPCookie::setLocalTieTag(unsigned int k, uint8_t localTieTag)
{
    if (k>=localTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", localTieTag_arraysize, k);
    this->localTieTag[k] = localTieTag;
}

void SCTPCookie::setPeerTieTagArraySize(unsigned int size)
{
    uint8_t *peerTieTag2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = peerTieTag_arraysize < size ? peerTieTag_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        peerTieTag2[i] = this->peerTieTag[i];
    for (unsigned int i=sz; i<size; i++)
        peerTieTag2[i] = 0;
    peerTieTag_arraysize = size;
    delete [] this->peerTieTag;
    this->peerTieTag = peerTieTag2;
}

unsigned int SCTPCookie::getPeerTieTagArraySize() const
{
    return peerTieTag_arraysize;
}

uint8_t SCTPCookie::getPeerTieTag(unsigned int k) const
{
    if (k>=peerTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", peerTieTag_arraysize, k);
    return this->peerTieTag[k];
}

void SCTPCookie::setPeerTieTag(unsigned int k, uint8_t peerTieTag)
{
    if (k>=peerTieTag_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", peerTieTag_arraysize, k);
    this->peerTieTag[k] = peerTieTag;
}

class SCTPCookieDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPCookieDescriptor();
    virtual ~SCTPCookieDescriptor();

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

Register_ClassDescriptor(SCTPCookieDescriptor)

SCTPCookieDescriptor::SCTPCookieDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPCookie", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SCTPCookieDescriptor::~SCTPCookieDescriptor()
{
    delete[] propertynames;
}

bool SCTPCookieDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPCookie *>(obj)!=nullptr;
}

const char **SCTPCookieDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPCookieDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPCookieDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int SCTPCookieDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *SCTPCookieDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "creationTime",
        "localTag",
        "peerTag",
        "localTieTag",
        "peerTieTag",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int SCTPCookieDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localTag")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerTag")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "localTieTag")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerTieTag")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPCookieDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
        "uint32",
        "uint32",
        "uint8",
        "uint8",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPCookieDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPCookieDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPCookieDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        case 3: return pp->getLocalTieTagArraySize();
        case 4: return pp->getPeerTieTagArraySize();
        default: return 0;
    }
}

const char *SCTPCookieDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPCookieDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        case 0: return simtime2string(pp->getCreationTime());
        case 1: return ulong2string(pp->getLocalTag());
        case 2: return ulong2string(pp->getPeerTag());
        case 3: return ulong2string(pp->getLocalTieTag(i));
        case 4: return ulong2string(pp->getPeerTieTag(i));
        default: return "";
    }
}

bool SCTPCookieDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        case 0: pp->setCreationTime(string2simtime(value)); return true;
        case 1: pp->setLocalTag(string2ulong(value)); return true;
        case 2: pp->setPeerTag(string2ulong(value)); return true;
        case 3: pp->setLocalTieTag(i,string2ulong(value)); return true;
        case 4: pp->setPeerTieTag(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPCookieDescriptor::getFieldStructName(int field) const
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

void *SCTPCookieDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookie *pp = (SCTPCookie *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPCookieAckChunk)

SCTPCookieAckChunk::SCTPCookieAckChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
}

SCTPCookieAckChunk::SCTPCookieAckChunk(const SCTPCookieAckChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPCookieAckChunk::~SCTPCookieAckChunk()
{
}

SCTPCookieAckChunk& SCTPCookieAckChunk::operator=(const SCTPCookieAckChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPCookieAckChunk::copy(const SCTPCookieAckChunk& other)
{
}

void SCTPCookieAckChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
}

void SCTPCookieAckChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
}

class SCTPCookieAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPCookieAckChunkDescriptor();
    virtual ~SCTPCookieAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPCookieAckChunkDescriptor)

SCTPCookieAckChunkDescriptor::SCTPCookieAckChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPCookieAckChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPCookieAckChunkDescriptor::~SCTPCookieAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPCookieAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPCookieAckChunk *>(obj)!=nullptr;
}

const char **SCTPCookieAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPCookieAckChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPCookieAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SCTPCookieAckChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SCTPCookieAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SCTPCookieAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPCookieAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SCTPCookieAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPCookieAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPCookieAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPCookieAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPCookieAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SCTPCookieAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SCTPCookieAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SCTPCookieAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPCookieAckChunk *pp = (SCTPCookieAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPDataMsg)

SCTPDataMsg::SCTPDataMsg(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->eBit = 0;
    this->bBit = 0;
    this->enqueuingTime = 0;
    this->expiryTime = 0;
    this->ppid = 0;
    this->msgNum = 0;
    this->sid = 0;
    this->ordered = false;
    this->booksize = 0;
    this->rtx = 0;
    this->fragment = false;
    this->prMethod = 0;
    this->priority = 0;
    this->strReset = false;
    this->sackNow = false;
}

SCTPDataMsg::SCTPDataMsg(const SCTPDataMsg& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SCTPDataMsg::~SCTPDataMsg()
{
}

SCTPDataMsg& SCTPDataMsg::operator=(const SCTPDataMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPDataMsg::copy(const SCTPDataMsg& other)
{
    this->eBit = other.eBit;
    this->bBit = other.bBit;
    this->enqueuingTime = other.enqueuingTime;
    this->expiryTime = other.expiryTime;
    this->ppid = other.ppid;
    this->initialDestination = other.initialDestination;
    this->msgNum = other.msgNum;
    this->sid = other.sid;
    this->ordered = other.ordered;
    this->booksize = other.booksize;
    this->rtx = other.rtx;
    this->fragment = other.fragment;
    this->prMethod = other.prMethod;
    this->priority = other.priority;
    this->strReset = other.strReset;
    this->sackNow = other.sackNow;
}

void SCTPDataMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->eBit);
    doParsimPacking(b,this->bBit);
    doParsimPacking(b,this->enqueuingTime);
    doParsimPacking(b,this->expiryTime);
    doParsimPacking(b,this->ppid);
    doParsimPacking(b,this->initialDestination);
    doParsimPacking(b,this->msgNum);
    doParsimPacking(b,this->sid);
    doParsimPacking(b,this->ordered);
    doParsimPacking(b,this->booksize);
    doParsimPacking(b,this->rtx);
    doParsimPacking(b,this->fragment);
    doParsimPacking(b,this->prMethod);
    doParsimPacking(b,this->priority);
    doParsimPacking(b,this->strReset);
    doParsimPacking(b,this->sackNow);
}

void SCTPDataMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->eBit);
    doParsimUnpacking(b,this->bBit);
    doParsimUnpacking(b,this->enqueuingTime);
    doParsimUnpacking(b,this->expiryTime);
    doParsimUnpacking(b,this->ppid);
    doParsimUnpacking(b,this->initialDestination);
    doParsimUnpacking(b,this->msgNum);
    doParsimUnpacking(b,this->sid);
    doParsimUnpacking(b,this->ordered);
    doParsimUnpacking(b,this->booksize);
    doParsimUnpacking(b,this->rtx);
    doParsimUnpacking(b,this->fragment);
    doParsimUnpacking(b,this->prMethod);
    doParsimUnpacking(b,this->priority);
    doParsimUnpacking(b,this->strReset);
    doParsimUnpacking(b,this->sackNow);
}

bool SCTPDataMsg::getEBit() const
{
    return this->eBit;
}

void SCTPDataMsg::setEBit(bool eBit)
{
    this->eBit = eBit;
}

bool SCTPDataMsg::getBBit() const
{
    return this->bBit;
}

void SCTPDataMsg::setBBit(bool bBit)
{
    this->bBit = bBit;
}

::omnetpp::simtime_t SCTPDataMsg::getEnqueuingTime() const
{
    return this->enqueuingTime;
}

void SCTPDataMsg::setEnqueuingTime(::omnetpp::simtime_t enqueuingTime)
{
    this->enqueuingTime = enqueuingTime;
}

::omnetpp::simtime_t SCTPDataMsg::getExpiryTime() const
{
    return this->expiryTime;
}

void SCTPDataMsg::setExpiryTime(::omnetpp::simtime_t expiryTime)
{
    this->expiryTime = expiryTime;
}

uint32_t SCTPDataMsg::getPpid() const
{
    return this->ppid;
}

void SCTPDataMsg::setPpid(uint32_t ppid)
{
    this->ppid = ppid;
}

L3Address& SCTPDataMsg::getInitialDestination()
{
    return this->initialDestination;
}

void SCTPDataMsg::setInitialDestination(const L3Address& initialDestination)
{
    this->initialDestination = initialDestination;
}

uint32_t SCTPDataMsg::getMsgNum() const
{
    return this->msgNum;
}

void SCTPDataMsg::setMsgNum(uint32_t msgNum)
{
    this->msgNum = msgNum;
}

uint16_t SCTPDataMsg::getSid() const
{
    return this->sid;
}

void SCTPDataMsg::setSid(uint16_t sid)
{
    this->sid = sid;
}

bool SCTPDataMsg::getOrdered() const
{
    return this->ordered;
}

void SCTPDataMsg::setOrdered(bool ordered)
{
    this->ordered = ordered;
}

uint32_t SCTPDataMsg::getBooksize() const
{
    return this->booksize;
}

void SCTPDataMsg::setBooksize(uint32_t booksize)
{
    this->booksize = booksize;
}

uint32_t SCTPDataMsg::getRtx() const
{
    return this->rtx;
}

void SCTPDataMsg::setRtx(uint32_t rtx)
{
    this->rtx = rtx;
}

bool SCTPDataMsg::getFragment() const
{
    return this->fragment;
}

void SCTPDataMsg::setFragment(bool fragment)
{
    this->fragment = fragment;
}

uint32_t SCTPDataMsg::getPrMethod() const
{
    return this->prMethod;
}

void SCTPDataMsg::setPrMethod(uint32_t prMethod)
{
    this->prMethod = prMethod;
}

uint32_t SCTPDataMsg::getPriority() const
{
    return this->priority;
}

void SCTPDataMsg::setPriority(uint32_t priority)
{
    this->priority = priority;
}

bool SCTPDataMsg::getStrReset() const
{
    return this->strReset;
}

void SCTPDataMsg::setStrReset(bool strReset)
{
    this->strReset = strReset;
}

bool SCTPDataMsg::getSackNow() const
{
    return this->sackNow;
}

void SCTPDataMsg::setSackNow(bool sackNow)
{
    this->sackNow = sackNow;
}

class SCTPDataMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPDataMsgDescriptor();
    virtual ~SCTPDataMsgDescriptor();

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

Register_ClassDescriptor(SCTPDataMsgDescriptor)

SCTPDataMsgDescriptor::SCTPDataMsgDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPDataMsg", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SCTPDataMsgDescriptor::~SCTPDataMsgDescriptor()
{
    delete[] propertynames;
}

bool SCTPDataMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPDataMsg *>(obj)!=nullptr;
}

const char **SCTPDataMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPDataMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPDataMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount() : 16;
}

unsigned int SCTPDataMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<16) ? fieldTypeFlags[field] : 0;
}

const char *SCTPDataMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "eBit",
        "bBit",
        "enqueuingTime",
        "expiryTime",
        "ppid",
        "initialDestination",
        "msgNum",
        "sid",
        "ordered",
        "booksize",
        "rtx",
        "fragment",
        "prMethod",
        "priority",
        "strReset",
        "sackNow",
    };
    return (field>=0 && field<16) ? fieldNames[field] : nullptr;
}

int SCTPDataMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eBit")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bBit")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "enqueuingTime")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "expiryTime")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "ppid")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "initialDestination")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "msgNum")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sid")==0) return base+7;
    if (fieldName[0]=='o' && strcmp(fieldName, "ordered")==0) return base+8;
    if (fieldName[0]=='b' && strcmp(fieldName, "booksize")==0) return base+9;
    if (fieldName[0]=='r' && strcmp(fieldName, "rtx")==0) return base+10;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragment")==0) return base+11;
    if (fieldName[0]=='p' && strcmp(fieldName, "prMethod")==0) return base+12;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+13;
    if (fieldName[0]=='s' && strcmp(fieldName, "strReset")==0) return base+14;
    if (fieldName[0]=='s' && strcmp(fieldName, "sackNow")==0) return base+15;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPDataMsgDescriptor::getFieldTypeString(int field) const
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
        "simtime_t",
        "simtime_t",
        "uint32",
        "L3Address",
        "uint32",
        "uint16",
        "bool",
        "uint32",
        "uint32",
        "bool",
        "uint32",
        "uint32",
        "bool",
        "bool",
    };
    return (field>=0 && field<16) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPDataMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPDataMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPDataMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPDataMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPDataMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getEBit());
        case 1: return bool2string(pp->getBBit());
        case 2: return simtime2string(pp->getEnqueuingTime());
        case 3: return simtime2string(pp->getExpiryTime());
        case 4: return ulong2string(pp->getPpid());
        case 5: {std::stringstream out; out << pp->getInitialDestination(); return out.str();}
        case 6: return ulong2string(pp->getMsgNum());
        case 7: return ulong2string(pp->getSid());
        case 8: return bool2string(pp->getOrdered());
        case 9: return ulong2string(pp->getBooksize());
        case 10: return ulong2string(pp->getRtx());
        case 11: return bool2string(pp->getFragment());
        case 12: return ulong2string(pp->getPrMethod());
        case 13: return ulong2string(pp->getPriority());
        case 14: return bool2string(pp->getStrReset());
        case 15: return bool2string(pp->getSackNow());
        default: return "";
    }
}

bool SCTPDataMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setEBit(string2bool(value)); return true;
        case 1: pp->setBBit(string2bool(value)); return true;
        case 2: pp->setEnqueuingTime(string2simtime(value)); return true;
        case 3: pp->setExpiryTime(string2simtime(value)); return true;
        case 4: pp->setPpid(string2ulong(value)); return true;
        case 6: pp->setMsgNum(string2ulong(value)); return true;
        case 7: pp->setSid(string2ulong(value)); return true;
        case 8: pp->setOrdered(string2bool(value)); return true;
        case 9: pp->setBooksize(string2ulong(value)); return true;
        case 10: pp->setRtx(string2ulong(value)); return true;
        case 11: pp->setFragment(string2bool(value)); return true;
        case 12: pp->setPrMethod(string2ulong(value)); return true;
        case 13: pp->setPriority(string2ulong(value)); return true;
        case 14: pp->setStrReset(string2bool(value)); return true;
        case 15: pp->setSackNow(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPDataMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPDataMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPDataMsg *pp = (SCTPDataMsg *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getInitialDestination()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPDataChunk)

SCTPDataChunk::SCTPDataChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->eBit = 0;
    this->bBit = 0;
    this->uBit = 0;
    this->iBit = 0;
    this->tsn = 0;
    this->sid = 0;
    this->ssn = 0;
    this->ppid = 0;
    this->enqueuingTime = 0;
    this->firstSendTime = 0;
}

SCTPDataChunk::SCTPDataChunk(const SCTPDataChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPDataChunk::~SCTPDataChunk()
{
}

SCTPDataChunk& SCTPDataChunk::operator=(const SCTPDataChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPDataChunk::copy(const SCTPDataChunk& other)
{
    this->eBit = other.eBit;
    this->bBit = other.bBit;
    this->uBit = other.uBit;
    this->iBit = other.iBit;
    this->tsn = other.tsn;
    this->sid = other.sid;
    this->ssn = other.ssn;
    this->ppid = other.ppid;
    this->enqueuingTime = other.enqueuingTime;
    this->firstSendTime = other.firstSendTime;
}

void SCTPDataChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->eBit);
    doParsimPacking(b,this->bBit);
    doParsimPacking(b,this->uBit);
    doParsimPacking(b,this->iBit);
    doParsimPacking(b,this->tsn);
    doParsimPacking(b,this->sid);
    doParsimPacking(b,this->ssn);
    doParsimPacking(b,this->ppid);
    doParsimPacking(b,this->enqueuingTime);
    doParsimPacking(b,this->firstSendTime);
}

void SCTPDataChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->eBit);
    doParsimUnpacking(b,this->bBit);
    doParsimUnpacking(b,this->uBit);
    doParsimUnpacking(b,this->iBit);
    doParsimUnpacking(b,this->tsn);
    doParsimUnpacking(b,this->sid);
    doParsimUnpacking(b,this->ssn);
    doParsimUnpacking(b,this->ppid);
    doParsimUnpacking(b,this->enqueuingTime);
    doParsimUnpacking(b,this->firstSendTime);
}

bool SCTPDataChunk::getEBit() const
{
    return this->eBit;
}

void SCTPDataChunk::setEBit(bool eBit)
{
    this->eBit = eBit;
}

bool SCTPDataChunk::getBBit() const
{
    return this->bBit;
}

void SCTPDataChunk::setBBit(bool bBit)
{
    this->bBit = bBit;
}

bool SCTPDataChunk::getUBit() const
{
    return this->uBit;
}

void SCTPDataChunk::setUBit(bool uBit)
{
    this->uBit = uBit;
}

bool SCTPDataChunk::getIBit() const
{
    return this->iBit;
}

void SCTPDataChunk::setIBit(bool iBit)
{
    this->iBit = iBit;
}

uint32_t SCTPDataChunk::getTsn() const
{
    return this->tsn;
}

void SCTPDataChunk::setTsn(uint32_t tsn)
{
    this->tsn = tsn;
}

uint16_t SCTPDataChunk::getSid() const
{
    return this->sid;
}

void SCTPDataChunk::setSid(uint16_t sid)
{
    this->sid = sid;
}

uint16_t SCTPDataChunk::getSsn() const
{
    return this->ssn;
}

void SCTPDataChunk::setSsn(uint16_t ssn)
{
    this->ssn = ssn;
}

uint32_t SCTPDataChunk::getPpid() const
{
    return this->ppid;
}

void SCTPDataChunk::setPpid(uint32_t ppid)
{
    this->ppid = ppid;
}

::omnetpp::simtime_t SCTPDataChunk::getEnqueuingTime() const
{
    return this->enqueuingTime;
}

void SCTPDataChunk::setEnqueuingTime(::omnetpp::simtime_t enqueuingTime)
{
    this->enqueuingTime = enqueuingTime;
}

::omnetpp::simtime_t SCTPDataChunk::getFirstSendTime() const
{
    return this->firstSendTime;
}

void SCTPDataChunk::setFirstSendTime(::omnetpp::simtime_t firstSendTime)
{
    this->firstSendTime = firstSendTime;
}

class SCTPDataChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPDataChunkDescriptor();
    virtual ~SCTPDataChunkDescriptor();

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

Register_ClassDescriptor(SCTPDataChunkDescriptor)

SCTPDataChunkDescriptor::SCTPDataChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPDataChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPDataChunkDescriptor::~SCTPDataChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPDataChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPDataChunk *>(obj)!=nullptr;
}

const char **SCTPDataChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPDataChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPDataChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 10+basedesc->getFieldCount() : 10;
}

unsigned int SCTPDataChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<10) ? fieldTypeFlags[field] : 0;
}

const char *SCTPDataChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "eBit",
        "bBit",
        "uBit",
        "iBit",
        "tsn",
        "sid",
        "ssn",
        "ppid",
        "enqueuingTime",
        "firstSendTime",
    };
    return (field>=0 && field<10) ? fieldNames[field] : nullptr;
}

int SCTPDataChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "eBit")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bBit")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "uBit")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "iBit")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "tsn")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "sid")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssn")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "ppid")==0) return base+7;
    if (fieldName[0]=='e' && strcmp(fieldName, "enqueuingTime")==0) return base+8;
    if (fieldName[0]=='f' && strcmp(fieldName, "firstSendTime")==0) return base+9;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPDataChunkDescriptor::getFieldTypeString(int field) const
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
        "uint32",
        "uint16",
        "uint16",
        "uint32",
        "simtime_t",
        "simtime_t",
    };
    return (field>=0 && field<10) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPDataChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPDataChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPDataChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPDataChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPDataChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getEBit());
        case 1: return bool2string(pp->getBBit());
        case 2: return bool2string(pp->getUBit());
        case 3: return bool2string(pp->getIBit());
        case 4: return ulong2string(pp->getTsn());
        case 5: return ulong2string(pp->getSid());
        case 6: return ulong2string(pp->getSsn());
        case 7: return ulong2string(pp->getPpid());
        case 8: return simtime2string(pp->getEnqueuingTime());
        case 9: return simtime2string(pp->getFirstSendTime());
        default: return "";
    }
}

bool SCTPDataChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setEBit(string2bool(value)); return true;
        case 1: pp->setBBit(string2bool(value)); return true;
        case 2: pp->setUBit(string2bool(value)); return true;
        case 3: pp->setIBit(string2bool(value)); return true;
        case 4: pp->setTsn(string2ulong(value)); return true;
        case 5: pp->setSid(string2ulong(value)); return true;
        case 6: pp->setSsn(string2ulong(value)); return true;
        case 7: pp->setPpid(string2ulong(value)); return true;
        case 8: pp->setEnqueuingTime(string2simtime(value)); return true;
        case 9: pp->setFirstSendTime(string2simtime(value)); return true;
        default: return false;
    }
}

const char *SCTPDataChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPDataChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPDataChunk *pp = (SCTPDataChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPForwardTsnChunk)

SCTPForwardTsnChunk::SCTPForwardTsnChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->newCumTsn = 0;
    sid_arraysize = 0;
    this->sid = 0;
    ssn_arraysize = 0;
    this->ssn = 0;
}

SCTPForwardTsnChunk::SCTPForwardTsnChunk(const SCTPForwardTsnChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    sid_arraysize = 0;
    this->sid = 0;
    ssn_arraysize = 0;
    this->ssn = 0;
    copy(other);
}

SCTPForwardTsnChunk::~SCTPForwardTsnChunk()
{
    delete [] this->sid;
    delete [] this->ssn;
}

SCTPForwardTsnChunk& SCTPForwardTsnChunk::operator=(const SCTPForwardTsnChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPForwardTsnChunk::copy(const SCTPForwardTsnChunk& other)
{
    this->newCumTsn = other.newCumTsn;
    delete [] this->sid;
    this->sid = (other.sid_arraysize==0) ? nullptr : new uint16_t[other.sid_arraysize];
    sid_arraysize = other.sid_arraysize;
    for (unsigned int i=0; i<sid_arraysize; i++)
        this->sid[i] = other.sid[i];
    delete [] this->ssn;
    this->ssn = (other.ssn_arraysize==0) ? nullptr : new short[other.ssn_arraysize];
    ssn_arraysize = other.ssn_arraysize;
    for (unsigned int i=0; i<ssn_arraysize; i++)
        this->ssn[i] = other.ssn[i];
}

void SCTPForwardTsnChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->newCumTsn);
    b->pack(sid_arraysize);
    doParsimArrayPacking(b,this->sid,sid_arraysize);
    b->pack(ssn_arraysize);
    doParsimArrayPacking(b,this->ssn,ssn_arraysize);
}

void SCTPForwardTsnChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->newCumTsn);
    delete [] this->sid;
    b->unpack(sid_arraysize);
    if (sid_arraysize==0) {
        this->sid = 0;
    } else {
        this->sid = new uint16_t[sid_arraysize];
        doParsimArrayUnpacking(b,this->sid,sid_arraysize);
    }
    delete [] this->ssn;
    b->unpack(ssn_arraysize);
    if (ssn_arraysize==0) {
        this->ssn = 0;
    } else {
        this->ssn = new short[ssn_arraysize];
        doParsimArrayUnpacking(b,this->ssn,ssn_arraysize);
    }
}

uint32_t SCTPForwardTsnChunk::getNewCumTsn() const
{
    return this->newCumTsn;
}

void SCTPForwardTsnChunk::setNewCumTsn(uint32_t newCumTsn)
{
    this->newCumTsn = newCumTsn;
}

void SCTPForwardTsnChunk::setSidArraySize(unsigned int size)
{
    uint16_t *sid2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = sid_arraysize < size ? sid_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sid2[i] = this->sid[i];
    for (unsigned int i=sz; i<size; i++)
        sid2[i] = 0;
    sid_arraysize = size;
    delete [] this->sid;
    this->sid = sid2;
}

unsigned int SCTPForwardTsnChunk::getSidArraySize() const
{
    return sid_arraysize;
}

uint16_t SCTPForwardTsnChunk::getSid(unsigned int k) const
{
    if (k>=sid_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sid_arraysize, k);
    return this->sid[k];
}

void SCTPForwardTsnChunk::setSid(unsigned int k, uint16_t sid)
{
    if (k>=sid_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sid_arraysize, k);
    this->sid[k] = sid;
}

void SCTPForwardTsnChunk::setSsnArraySize(unsigned int size)
{
    short *ssn2 = (size==0) ? nullptr : new short[size];
    unsigned int sz = ssn_arraysize < size ? ssn_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        ssn2[i] = this->ssn[i];
    for (unsigned int i=sz; i<size; i++)
        ssn2[i] = 0;
    ssn_arraysize = size;
    delete [] this->ssn;
    this->ssn = ssn2;
}

unsigned int SCTPForwardTsnChunk::getSsnArraySize() const
{
    return ssn_arraysize;
}

short SCTPForwardTsnChunk::getSsn(unsigned int k) const
{
    if (k>=ssn_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", ssn_arraysize, k);
    return this->ssn[k];
}

void SCTPForwardTsnChunk::setSsn(unsigned int k, short ssn)
{
    if (k>=ssn_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", ssn_arraysize, k);
    this->ssn[k] = ssn;
}

class SCTPForwardTsnChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPForwardTsnChunkDescriptor();
    virtual ~SCTPForwardTsnChunkDescriptor();

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

Register_ClassDescriptor(SCTPForwardTsnChunkDescriptor)

SCTPForwardTsnChunkDescriptor::SCTPForwardTsnChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPForwardTsnChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPForwardTsnChunkDescriptor::~SCTPForwardTsnChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPForwardTsnChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPForwardTsnChunk *>(obj)!=nullptr;
}

const char **SCTPForwardTsnChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPForwardTsnChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPForwardTsnChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SCTPForwardTsnChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SCTPForwardTsnChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "newCumTsn",
        "sid",
        "ssn",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int SCTPForwardTsnChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "newCumTsn")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sid")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssn")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPForwardTsnChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint16",
        "short",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPForwardTsnChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPForwardTsnChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPForwardTsnChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case 1: return pp->getSidArraySize();
        case 2: return pp->getSsnArraySize();
        default: return 0;
    }
}

const char *SCTPForwardTsnChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPForwardTsnChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getNewCumTsn());
        case 1: return ulong2string(pp->getSid(i));
        case 2: return long2string(pp->getSsn(i));
        default: return "";
    }
}

bool SCTPForwardTsnChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setNewCumTsn(string2ulong(value)); return true;
        case 1: pp->setSid(i,string2ulong(value)); return true;
        case 2: pp->setSsn(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPForwardTsnChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPForwardTsnChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPForwardTsnChunk *pp = (SCTPForwardTsnChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPSackChunk)

SCTPSackChunk::SCTPSackChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->cumTsnAck = 0;
    this->a_rwnd = 0;
    this->numGaps = 0;
    this->numNrGaps = 0;
    this->numDupTsns = 0;
    this->isNrSack = false;
    gapStart_arraysize = 0;
    this->gapStart = 0;
    gapStop_arraysize = 0;
    this->gapStop = 0;
    dupTsns_arraysize = 0;
    this->dupTsns = 0;
    this->sackSeqNum = 0;
    nrGapStart_arraysize = 0;
    this->nrGapStart = 0;
    nrGapStop_arraysize = 0;
    this->nrGapStop = 0;
    this->msg_rwnd = 0;
    this->dacPacketsRcvd = 0;
    this->nrSubtractRGaps = false;
}

SCTPSackChunk::SCTPSackChunk(const SCTPSackChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    gapStart_arraysize = 0;
    this->gapStart = 0;
    gapStop_arraysize = 0;
    this->gapStop = 0;
    dupTsns_arraysize = 0;
    this->dupTsns = 0;
    nrGapStart_arraysize = 0;
    this->nrGapStart = 0;
    nrGapStop_arraysize = 0;
    this->nrGapStop = 0;
    copy(other);
}

SCTPSackChunk::~SCTPSackChunk()
{
    delete [] this->gapStart;
    delete [] this->gapStop;
    delete [] this->dupTsns;
    delete [] this->nrGapStart;
    delete [] this->nrGapStop;
}

SCTPSackChunk& SCTPSackChunk::operator=(const SCTPSackChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPSackChunk::copy(const SCTPSackChunk& other)
{
    this->cumTsnAck = other.cumTsnAck;
    this->a_rwnd = other.a_rwnd;
    this->numGaps = other.numGaps;
    this->numNrGaps = other.numNrGaps;
    this->numDupTsns = other.numDupTsns;
    this->isNrSack = other.isNrSack;
    delete [] this->gapStart;
    this->gapStart = (other.gapStart_arraysize==0) ? nullptr : new uint32_t[other.gapStart_arraysize];
    gapStart_arraysize = other.gapStart_arraysize;
    for (unsigned int i=0; i<gapStart_arraysize; i++)
        this->gapStart[i] = other.gapStart[i];
    delete [] this->gapStop;
    this->gapStop = (other.gapStop_arraysize==0) ? nullptr : new uint32_t[other.gapStop_arraysize];
    gapStop_arraysize = other.gapStop_arraysize;
    for (unsigned int i=0; i<gapStop_arraysize; i++)
        this->gapStop[i] = other.gapStop[i];
    delete [] this->dupTsns;
    this->dupTsns = (other.dupTsns_arraysize==0) ? nullptr : new uint32_t[other.dupTsns_arraysize];
    dupTsns_arraysize = other.dupTsns_arraysize;
    for (unsigned int i=0; i<dupTsns_arraysize; i++)
        this->dupTsns[i] = other.dupTsns[i];
    this->sackSeqNum = other.sackSeqNum;
    delete [] this->nrGapStart;
    this->nrGapStart = (other.nrGapStart_arraysize==0) ? nullptr : new uint32_t[other.nrGapStart_arraysize];
    nrGapStart_arraysize = other.nrGapStart_arraysize;
    for (unsigned int i=0; i<nrGapStart_arraysize; i++)
        this->nrGapStart[i] = other.nrGapStart[i];
    delete [] this->nrGapStop;
    this->nrGapStop = (other.nrGapStop_arraysize==0) ? nullptr : new uint32_t[other.nrGapStop_arraysize];
    nrGapStop_arraysize = other.nrGapStop_arraysize;
    for (unsigned int i=0; i<nrGapStop_arraysize; i++)
        this->nrGapStop[i] = other.nrGapStop[i];
    this->msg_rwnd = other.msg_rwnd;
    this->dacPacketsRcvd = other.dacPacketsRcvd;
    this->nrSubtractRGaps = other.nrSubtractRGaps;
}

void SCTPSackChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->cumTsnAck);
    doParsimPacking(b,this->a_rwnd);
    doParsimPacking(b,this->numGaps);
    doParsimPacking(b,this->numNrGaps);
    doParsimPacking(b,this->numDupTsns);
    doParsimPacking(b,this->isNrSack);
    b->pack(gapStart_arraysize);
    doParsimArrayPacking(b,this->gapStart,gapStart_arraysize);
    b->pack(gapStop_arraysize);
    doParsimArrayPacking(b,this->gapStop,gapStop_arraysize);
    b->pack(dupTsns_arraysize);
    doParsimArrayPacking(b,this->dupTsns,dupTsns_arraysize);
    doParsimPacking(b,this->sackSeqNum);
    b->pack(nrGapStart_arraysize);
    doParsimArrayPacking(b,this->nrGapStart,nrGapStart_arraysize);
    b->pack(nrGapStop_arraysize);
    doParsimArrayPacking(b,this->nrGapStop,nrGapStop_arraysize);
    doParsimPacking(b,this->msg_rwnd);
    doParsimPacking(b,this->dacPacketsRcvd);
    doParsimPacking(b,this->nrSubtractRGaps);
}

void SCTPSackChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->cumTsnAck);
    doParsimUnpacking(b,this->a_rwnd);
    doParsimUnpacking(b,this->numGaps);
    doParsimUnpacking(b,this->numNrGaps);
    doParsimUnpacking(b,this->numDupTsns);
    doParsimUnpacking(b,this->isNrSack);
    delete [] this->gapStart;
    b->unpack(gapStart_arraysize);
    if (gapStart_arraysize==0) {
        this->gapStart = 0;
    } else {
        this->gapStart = new uint32_t[gapStart_arraysize];
        doParsimArrayUnpacking(b,this->gapStart,gapStart_arraysize);
    }
    delete [] this->gapStop;
    b->unpack(gapStop_arraysize);
    if (gapStop_arraysize==0) {
        this->gapStop = 0;
    } else {
        this->gapStop = new uint32_t[gapStop_arraysize];
        doParsimArrayUnpacking(b,this->gapStop,gapStop_arraysize);
    }
    delete [] this->dupTsns;
    b->unpack(dupTsns_arraysize);
    if (dupTsns_arraysize==0) {
        this->dupTsns = 0;
    } else {
        this->dupTsns = new uint32_t[dupTsns_arraysize];
        doParsimArrayUnpacking(b,this->dupTsns,dupTsns_arraysize);
    }
    doParsimUnpacking(b,this->sackSeqNum);
    delete [] this->nrGapStart;
    b->unpack(nrGapStart_arraysize);
    if (nrGapStart_arraysize==0) {
        this->nrGapStart = 0;
    } else {
        this->nrGapStart = new uint32_t[nrGapStart_arraysize];
        doParsimArrayUnpacking(b,this->nrGapStart,nrGapStart_arraysize);
    }
    delete [] this->nrGapStop;
    b->unpack(nrGapStop_arraysize);
    if (nrGapStop_arraysize==0) {
        this->nrGapStop = 0;
    } else {
        this->nrGapStop = new uint32_t[nrGapStop_arraysize];
        doParsimArrayUnpacking(b,this->nrGapStop,nrGapStop_arraysize);
    }
    doParsimUnpacking(b,this->msg_rwnd);
    doParsimUnpacking(b,this->dacPacketsRcvd);
    doParsimUnpacking(b,this->nrSubtractRGaps);
}

uint32_t SCTPSackChunk::getCumTsnAck() const
{
    return this->cumTsnAck;
}

void SCTPSackChunk::setCumTsnAck(uint32_t cumTsnAck)
{
    this->cumTsnAck = cumTsnAck;
}

uint32_t SCTPSackChunk::getA_rwnd() const
{
    return this->a_rwnd;
}

void SCTPSackChunk::setA_rwnd(uint32_t a_rwnd)
{
    this->a_rwnd = a_rwnd;
}

uint16_t SCTPSackChunk::getNumGaps() const
{
    return this->numGaps;
}

void SCTPSackChunk::setNumGaps(uint16_t numGaps)
{
    this->numGaps = numGaps;
}

uint16_t SCTPSackChunk::getNumNrGaps() const
{
    return this->numNrGaps;
}

void SCTPSackChunk::setNumNrGaps(uint16_t numNrGaps)
{
    this->numNrGaps = numNrGaps;
}

uint16_t SCTPSackChunk::getNumDupTsns() const
{
    return this->numDupTsns;
}

void SCTPSackChunk::setNumDupTsns(uint16_t numDupTsns)
{
    this->numDupTsns = numDupTsns;
}

bool SCTPSackChunk::getIsNrSack() const
{
    return this->isNrSack;
}

void SCTPSackChunk::setIsNrSack(bool isNrSack)
{
    this->isNrSack = isNrSack;
}

void SCTPSackChunk::setGapStartArraySize(unsigned int size)
{
    uint32_t *gapStart2 = (size==0) ? nullptr : new uint32_t[size];
    unsigned int sz = gapStart_arraysize < size ? gapStart_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        gapStart2[i] = this->gapStart[i];
    for (unsigned int i=sz; i<size; i++)
        gapStart2[i] = 0;
    gapStart_arraysize = size;
    delete [] this->gapStart;
    this->gapStart = gapStart2;
}

unsigned int SCTPSackChunk::getGapStartArraySize() const
{
    return gapStart_arraysize;
}

uint32_t SCTPSackChunk::getGapStart(unsigned int k) const
{
    if (k>=gapStart_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", gapStart_arraysize, k);
    return this->gapStart[k];
}

void SCTPSackChunk::setGapStart(unsigned int k, uint32_t gapStart)
{
    if (k>=gapStart_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", gapStart_arraysize, k);
    this->gapStart[k] = gapStart;
}

void SCTPSackChunk::setGapStopArraySize(unsigned int size)
{
    uint32_t *gapStop2 = (size==0) ? nullptr : new uint32_t[size];
    unsigned int sz = gapStop_arraysize < size ? gapStop_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        gapStop2[i] = this->gapStop[i];
    for (unsigned int i=sz; i<size; i++)
        gapStop2[i] = 0;
    gapStop_arraysize = size;
    delete [] this->gapStop;
    this->gapStop = gapStop2;
}

unsigned int SCTPSackChunk::getGapStopArraySize() const
{
    return gapStop_arraysize;
}

uint32_t SCTPSackChunk::getGapStop(unsigned int k) const
{
    if (k>=gapStop_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", gapStop_arraysize, k);
    return this->gapStop[k];
}

void SCTPSackChunk::setGapStop(unsigned int k, uint32_t gapStop)
{
    if (k>=gapStop_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", gapStop_arraysize, k);
    this->gapStop[k] = gapStop;
}

void SCTPSackChunk::setDupTsnsArraySize(unsigned int size)
{
    uint32_t *dupTsns2 = (size==0) ? nullptr : new uint32_t[size];
    unsigned int sz = dupTsns_arraysize < size ? dupTsns_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        dupTsns2[i] = this->dupTsns[i];
    for (unsigned int i=sz; i<size; i++)
        dupTsns2[i] = 0;
    dupTsns_arraysize = size;
    delete [] this->dupTsns;
    this->dupTsns = dupTsns2;
}

unsigned int SCTPSackChunk::getDupTsnsArraySize() const
{
    return dupTsns_arraysize;
}

uint32_t SCTPSackChunk::getDupTsns(unsigned int k) const
{
    if (k>=dupTsns_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", dupTsns_arraysize, k);
    return this->dupTsns[k];
}

void SCTPSackChunk::setDupTsns(unsigned int k, uint32_t dupTsns)
{
    if (k>=dupTsns_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", dupTsns_arraysize, k);
    this->dupTsns[k] = dupTsns;
}

uint32_t SCTPSackChunk::getSackSeqNum() const
{
    return this->sackSeqNum;
}

void SCTPSackChunk::setSackSeqNum(uint32_t sackSeqNum)
{
    this->sackSeqNum = sackSeqNum;
}

void SCTPSackChunk::setNrGapStartArraySize(unsigned int size)
{
    uint32_t *nrGapStart2 = (size==0) ? nullptr : new uint32_t[size];
    unsigned int sz = nrGapStart_arraysize < size ? nrGapStart_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        nrGapStart2[i] = this->nrGapStart[i];
    for (unsigned int i=sz; i<size; i++)
        nrGapStart2[i] = 0;
    nrGapStart_arraysize = size;
    delete [] this->nrGapStart;
    this->nrGapStart = nrGapStart2;
}

unsigned int SCTPSackChunk::getNrGapStartArraySize() const
{
    return nrGapStart_arraysize;
}

uint32_t SCTPSackChunk::getNrGapStart(unsigned int k) const
{
    if (k>=nrGapStart_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", nrGapStart_arraysize, k);
    return this->nrGapStart[k];
}

void SCTPSackChunk::setNrGapStart(unsigned int k, uint32_t nrGapStart)
{
    if (k>=nrGapStart_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", nrGapStart_arraysize, k);
    this->nrGapStart[k] = nrGapStart;
}

void SCTPSackChunk::setNrGapStopArraySize(unsigned int size)
{
    uint32_t *nrGapStop2 = (size==0) ? nullptr : new uint32_t[size];
    unsigned int sz = nrGapStop_arraysize < size ? nrGapStop_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        nrGapStop2[i] = this->nrGapStop[i];
    for (unsigned int i=sz; i<size; i++)
        nrGapStop2[i] = 0;
    nrGapStop_arraysize = size;
    delete [] this->nrGapStop;
    this->nrGapStop = nrGapStop2;
}

unsigned int SCTPSackChunk::getNrGapStopArraySize() const
{
    return nrGapStop_arraysize;
}

uint32_t SCTPSackChunk::getNrGapStop(unsigned int k) const
{
    if (k>=nrGapStop_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", nrGapStop_arraysize, k);
    return this->nrGapStop[k];
}

void SCTPSackChunk::setNrGapStop(unsigned int k, uint32_t nrGapStop)
{
    if (k>=nrGapStop_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", nrGapStop_arraysize, k);
    this->nrGapStop[k] = nrGapStop;
}

uint32_t SCTPSackChunk::getMsg_rwnd() const
{
    return this->msg_rwnd;
}

void SCTPSackChunk::setMsg_rwnd(uint32_t msg_rwnd)
{
    this->msg_rwnd = msg_rwnd;
}

uint8_t SCTPSackChunk::getDacPacketsRcvd() const
{
    return this->dacPacketsRcvd;
}

void SCTPSackChunk::setDacPacketsRcvd(uint8_t dacPacketsRcvd)
{
    this->dacPacketsRcvd = dacPacketsRcvd;
}

bool SCTPSackChunk::getNrSubtractRGaps() const
{
    return this->nrSubtractRGaps;
}

void SCTPSackChunk::setNrSubtractRGaps(bool nrSubtractRGaps)
{
    this->nrSubtractRGaps = nrSubtractRGaps;
}

class SCTPSackChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSackChunkDescriptor();
    virtual ~SCTPSackChunkDescriptor();

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

Register_ClassDescriptor(SCTPSackChunkDescriptor)

SCTPSackChunkDescriptor::SCTPSackChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPSackChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPSackChunkDescriptor::~SCTPSackChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPSackChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSackChunk *>(obj)!=nullptr;
}

const char **SCTPSackChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSackChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSackChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount() : 15;
}

unsigned int SCTPSackChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<15) ? fieldTypeFlags[field] : 0;
}

const char *SCTPSackChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cumTsnAck",
        "a_rwnd",
        "numGaps",
        "numNrGaps",
        "numDupTsns",
        "isNrSack",
        "gapStart",
        "gapStop",
        "dupTsns",
        "sackSeqNum",
        "nrGapStart",
        "nrGapStop",
        "msg_rwnd",
        "dacPacketsRcvd",
        "nrSubtractRGaps",
    };
    return (field>=0 && field<15) ? fieldNames[field] : nullptr;
}

int SCTPSackChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cumTsnAck")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "a_rwnd")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "numGaps")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numNrGaps")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "numDupTsns")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "isNrSack")==0) return base+5;
    if (fieldName[0]=='g' && strcmp(fieldName, "gapStart")==0) return base+6;
    if (fieldName[0]=='g' && strcmp(fieldName, "gapStop")==0) return base+7;
    if (fieldName[0]=='d' && strcmp(fieldName, "dupTsns")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "sackSeqNum")==0) return base+9;
    if (fieldName[0]=='n' && strcmp(fieldName, "nrGapStart")==0) return base+10;
    if (fieldName[0]=='n' && strcmp(fieldName, "nrGapStop")==0) return base+11;
    if (fieldName[0]=='m' && strcmp(fieldName, "msg_rwnd")==0) return base+12;
    if (fieldName[0]=='d' && strcmp(fieldName, "dacPacketsRcvd")==0) return base+13;
    if (fieldName[0]=='n' && strcmp(fieldName, "nrSubtractRGaps")==0) return base+14;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSackChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
        "uint16",
        "uint16",
        "uint16",
        "bool",
        "uint32",
        "uint32",
        "uint32",
        "uint32",
        "uint32",
        "uint32",
        "uint32",
        "uint8",
        "bool",
    };
    return (field>=0 && field<15) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSackChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSackChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSackChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        case 6: return pp->getGapStartArraySize();
        case 7: return pp->getGapStopArraySize();
        case 8: return pp->getDupTsnsArraySize();
        case 10: return pp->getNrGapStartArraySize();
        case 11: return pp->getNrGapStopArraySize();
        default: return 0;
    }
}

const char *SCTPSackChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSackChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCumTsnAck());
        case 1: return ulong2string(pp->getA_rwnd());
        case 2: return ulong2string(pp->getNumGaps());
        case 3: return ulong2string(pp->getNumNrGaps());
        case 4: return ulong2string(pp->getNumDupTsns());
        case 5: return bool2string(pp->getIsNrSack());
        case 6: return ulong2string(pp->getGapStart(i));
        case 7: return ulong2string(pp->getGapStop(i));
        case 8: return ulong2string(pp->getDupTsns(i));
        case 9: return ulong2string(pp->getSackSeqNum());
        case 10: return ulong2string(pp->getNrGapStart(i));
        case 11: return ulong2string(pp->getNrGapStop(i));
        case 12: return ulong2string(pp->getMsg_rwnd());
        case 13: return ulong2string(pp->getDacPacketsRcvd());
        case 14: return bool2string(pp->getNrSubtractRGaps());
        default: return "";
    }
}

bool SCTPSackChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setCumTsnAck(string2ulong(value)); return true;
        case 1: pp->setA_rwnd(string2ulong(value)); return true;
        case 2: pp->setNumGaps(string2ulong(value)); return true;
        case 3: pp->setNumNrGaps(string2ulong(value)); return true;
        case 4: pp->setNumDupTsns(string2ulong(value)); return true;
        case 5: pp->setIsNrSack(string2bool(value)); return true;
        case 6: pp->setGapStart(i,string2ulong(value)); return true;
        case 7: pp->setGapStop(i,string2ulong(value)); return true;
        case 8: pp->setDupTsns(i,string2ulong(value)); return true;
        case 9: pp->setSackSeqNum(string2ulong(value)); return true;
        case 10: pp->setNrGapStart(i,string2ulong(value)); return true;
        case 11: pp->setNrGapStop(i,string2ulong(value)); return true;
        case 12: pp->setMsg_rwnd(string2ulong(value)); return true;
        case 13: pp->setDacPacketsRcvd(string2ulong(value)); return true;
        case 14: pp->setNrSubtractRGaps(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPSackChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPSackChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSackChunk *pp = (SCTPSackChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPAbortChunk)

SCTPAbortChunk::SCTPAbortChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->T_Bit = 0;
}

SCTPAbortChunk::SCTPAbortChunk(const SCTPAbortChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPAbortChunk::~SCTPAbortChunk()
{
}

SCTPAbortChunk& SCTPAbortChunk::operator=(const SCTPAbortChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPAbortChunk::copy(const SCTPAbortChunk& other)
{
    this->T_Bit = other.T_Bit;
}

void SCTPAbortChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->T_Bit);
}

void SCTPAbortChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->T_Bit);
}

bool SCTPAbortChunk::getT_Bit() const
{
    return this->T_Bit;
}

void SCTPAbortChunk::setT_Bit(bool T_Bit)
{
    this->T_Bit = T_Bit;
}

class SCTPAbortChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPAbortChunkDescriptor();
    virtual ~SCTPAbortChunkDescriptor();

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

Register_ClassDescriptor(SCTPAbortChunkDescriptor)

SCTPAbortChunkDescriptor::SCTPAbortChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPAbortChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPAbortChunkDescriptor::~SCTPAbortChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPAbortChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPAbortChunk *>(obj)!=nullptr;
}

const char **SCTPAbortChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPAbortChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPAbortChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPAbortChunkDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPAbortChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "T_Bit",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPAbortChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='T' && strcmp(fieldName, "T_Bit")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPAbortChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPAbortChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPAbortChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPAbortChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPAbortChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPAbortChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getT_Bit());
        default: return "";
    }
}

bool SCTPAbortChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setT_Bit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPAbortChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPAbortChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPAbortChunk *pp = (SCTPAbortChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPHeartbeatChunk)

SCTPHeartbeatChunk::SCTPHeartbeatChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->timeField = 0;
    info_arraysize = 0;
    this->info = 0;
}

SCTPHeartbeatChunk::SCTPHeartbeatChunk(const SCTPHeartbeatChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    info_arraysize = 0;
    this->info = 0;
    copy(other);
}

SCTPHeartbeatChunk::~SCTPHeartbeatChunk()
{
    delete [] this->info;
}

SCTPHeartbeatChunk& SCTPHeartbeatChunk::operator=(const SCTPHeartbeatChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPHeartbeatChunk::copy(const SCTPHeartbeatChunk& other)
{
    this->remoteAddr = other.remoteAddr;
    this->timeField = other.timeField;
    delete [] this->info;
    this->info = (other.info_arraysize==0) ? nullptr : new char[other.info_arraysize];
    info_arraysize = other.info_arraysize;
    for (unsigned int i=0; i<info_arraysize; i++)
        this->info[i] = other.info[i];
}

void SCTPHeartbeatChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->timeField);
    b->pack(info_arraysize);
    doParsimArrayPacking(b,this->info,info_arraysize);
}

void SCTPHeartbeatChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->timeField);
    delete [] this->info;
    b->unpack(info_arraysize);
    if (info_arraysize==0) {
        this->info = 0;
    } else {
        this->info = new char[info_arraysize];
        doParsimArrayUnpacking(b,this->info,info_arraysize);
    }
}

L3Address& SCTPHeartbeatChunk::getRemoteAddr()
{
    return this->remoteAddr;
}

void SCTPHeartbeatChunk::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

::omnetpp::simtime_t SCTPHeartbeatChunk::getTimeField() const
{
    return this->timeField;
}

void SCTPHeartbeatChunk::setTimeField(::omnetpp::simtime_t timeField)
{
    this->timeField = timeField;
}

void SCTPHeartbeatChunk::setInfoArraySize(unsigned int size)
{
    char *info2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = info_arraysize < size ? info_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        info2[i] = this->info[i];
    for (unsigned int i=sz; i<size; i++)
        info2[i] = 0;
    info_arraysize = size;
    delete [] this->info;
    this->info = info2;
}

unsigned int SCTPHeartbeatChunk::getInfoArraySize() const
{
    return info_arraysize;
}

char SCTPHeartbeatChunk::getInfo(unsigned int k) const
{
    if (k>=info_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", info_arraysize, k);
    return this->info[k];
}

void SCTPHeartbeatChunk::setInfo(unsigned int k, char info)
{
    if (k>=info_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", info_arraysize, k);
    this->info[k] = info;
}

class SCTPHeartbeatChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPHeartbeatChunkDescriptor();
    virtual ~SCTPHeartbeatChunkDescriptor();

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

Register_ClassDescriptor(SCTPHeartbeatChunkDescriptor)

SCTPHeartbeatChunkDescriptor::SCTPHeartbeatChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPHeartbeatChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPHeartbeatChunkDescriptor::~SCTPHeartbeatChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPHeartbeatChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPHeartbeatChunk *>(obj)!=nullptr;
}

const char **SCTPHeartbeatChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPHeartbeatChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPHeartbeatChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SCTPHeartbeatChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SCTPHeartbeatChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddr",
        "timeField",
        "info",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int SCTPHeartbeatChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeField")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "info")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPHeartbeatChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "simtime_t",
        "char",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPHeartbeatChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPHeartbeatChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPHeartbeatChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case 2: return pp->getInfoArraySize();
        default: return 0;
    }
}

const char *SCTPHeartbeatChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPHeartbeatChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 1: return simtime2string(pp->getTimeField());
        case 2: return long2string(pp->getInfo(i));
        default: return "";
    }
}

bool SCTPHeartbeatChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case 1: pp->setTimeField(string2simtime(value)); return true;
        case 2: pp->setInfo(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPHeartbeatChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPHeartbeatChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatChunk *pp = (SCTPHeartbeatChunk *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPHeartbeatAckChunk)

SCTPHeartbeatAckChunk::SCTPHeartbeatAckChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->timeField = 0;
    info_arraysize = 0;
    this->info = 0;
}

SCTPHeartbeatAckChunk::SCTPHeartbeatAckChunk(const SCTPHeartbeatAckChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    info_arraysize = 0;
    this->info = 0;
    copy(other);
}

SCTPHeartbeatAckChunk::~SCTPHeartbeatAckChunk()
{
    delete [] this->info;
}

SCTPHeartbeatAckChunk& SCTPHeartbeatAckChunk::operator=(const SCTPHeartbeatAckChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPHeartbeatAckChunk::copy(const SCTPHeartbeatAckChunk& other)
{
    this->remoteAddr = other.remoteAddr;
    this->timeField = other.timeField;
    delete [] this->info;
    this->info = (other.info_arraysize==0) ? nullptr : new char[other.info_arraysize];
    info_arraysize = other.info_arraysize;
    for (unsigned int i=0; i<info_arraysize; i++)
        this->info[i] = other.info[i];
}

void SCTPHeartbeatAckChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->timeField);
    b->pack(info_arraysize);
    doParsimArrayPacking(b,this->info,info_arraysize);
}

void SCTPHeartbeatAckChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->timeField);
    delete [] this->info;
    b->unpack(info_arraysize);
    if (info_arraysize==0) {
        this->info = 0;
    } else {
        this->info = new char[info_arraysize];
        doParsimArrayUnpacking(b,this->info,info_arraysize);
    }
}

L3Address& SCTPHeartbeatAckChunk::getRemoteAddr()
{
    return this->remoteAddr;
}

void SCTPHeartbeatAckChunk::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

::omnetpp::simtime_t SCTPHeartbeatAckChunk::getTimeField() const
{
    return this->timeField;
}

void SCTPHeartbeatAckChunk::setTimeField(::omnetpp::simtime_t timeField)
{
    this->timeField = timeField;
}

void SCTPHeartbeatAckChunk::setInfoArraySize(unsigned int size)
{
    char *info2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = info_arraysize < size ? info_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        info2[i] = this->info[i];
    for (unsigned int i=sz; i<size; i++)
        info2[i] = 0;
    info_arraysize = size;
    delete [] this->info;
    this->info = info2;
}

unsigned int SCTPHeartbeatAckChunk::getInfoArraySize() const
{
    return info_arraysize;
}

char SCTPHeartbeatAckChunk::getInfo(unsigned int k) const
{
    if (k>=info_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", info_arraysize, k);
    return this->info[k];
}

void SCTPHeartbeatAckChunk::setInfo(unsigned int k, char info)
{
    if (k>=info_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", info_arraysize, k);
    this->info[k] = info;
}

class SCTPHeartbeatAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPHeartbeatAckChunkDescriptor();
    virtual ~SCTPHeartbeatAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPHeartbeatAckChunkDescriptor)

SCTPHeartbeatAckChunkDescriptor::SCTPHeartbeatAckChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPHeartbeatAckChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPHeartbeatAckChunkDescriptor::~SCTPHeartbeatAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPHeartbeatAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPHeartbeatAckChunk *>(obj)!=nullptr;
}

const char **SCTPHeartbeatAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPHeartbeatAckChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPHeartbeatAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SCTPHeartbeatAckChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *SCTPHeartbeatAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddr",
        "timeField",
        "info",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int SCTPHeartbeatAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeField")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "info")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPHeartbeatAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "simtime_t",
        "char",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPHeartbeatAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPHeartbeatAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPHeartbeatAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case 2: return pp->getInfoArraySize();
        default: return 0;
    }
}

const char *SCTPHeartbeatAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPHeartbeatAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 1: return simtime2string(pp->getTimeField());
        case 2: return long2string(pp->getInfo(i));
        default: return "";
    }
}

bool SCTPHeartbeatAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case 1: pp->setTimeField(string2simtime(value)); return true;
        case 2: pp->setInfo(i,string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPHeartbeatAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPHeartbeatAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPHeartbeatAckChunk *pp = (SCTPHeartbeatAckChunk *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPShutdownChunk)

SCTPShutdownChunk::SCTPShutdownChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->cumTsnAck = 0;
}

SCTPShutdownChunk::SCTPShutdownChunk(const SCTPShutdownChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPShutdownChunk::~SCTPShutdownChunk()
{
}

SCTPShutdownChunk& SCTPShutdownChunk::operator=(const SCTPShutdownChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPShutdownChunk::copy(const SCTPShutdownChunk& other)
{
    this->cumTsnAck = other.cumTsnAck;
}

void SCTPShutdownChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->cumTsnAck);
}

void SCTPShutdownChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->cumTsnAck);
}

uint32_t SCTPShutdownChunk::getCumTsnAck() const
{
    return this->cumTsnAck;
}

void SCTPShutdownChunk::setCumTsnAck(uint32_t cumTsnAck)
{
    this->cumTsnAck = cumTsnAck;
}

class SCTPShutdownChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPShutdownChunkDescriptor();
    virtual ~SCTPShutdownChunkDescriptor();

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

Register_ClassDescriptor(SCTPShutdownChunkDescriptor)

SCTPShutdownChunkDescriptor::SCTPShutdownChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPShutdownChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPShutdownChunkDescriptor::~SCTPShutdownChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPShutdownChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPShutdownChunk *>(obj)!=nullptr;
}

const char **SCTPShutdownChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPShutdownChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPShutdownChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPShutdownChunkDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPShutdownChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cumTsnAck",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPShutdownChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cumTsnAck")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPShutdownChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPShutdownChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPShutdownChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPShutdownChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPShutdownChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPShutdownChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getCumTsnAck());
        default: return "";
    }
}

bool SCTPShutdownChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setCumTsnAck(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPShutdownChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPShutdownChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownChunk *pp = (SCTPShutdownChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPShutdownAckChunk)

SCTPShutdownAckChunk::SCTPShutdownAckChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
}

SCTPShutdownAckChunk::SCTPShutdownAckChunk(const SCTPShutdownAckChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPShutdownAckChunk::~SCTPShutdownAckChunk()
{
}

SCTPShutdownAckChunk& SCTPShutdownAckChunk::operator=(const SCTPShutdownAckChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPShutdownAckChunk::copy(const SCTPShutdownAckChunk& other)
{
}

void SCTPShutdownAckChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
}

void SCTPShutdownAckChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
}

class SCTPShutdownAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPShutdownAckChunkDescriptor();
    virtual ~SCTPShutdownAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPShutdownAckChunkDescriptor)

SCTPShutdownAckChunkDescriptor::SCTPShutdownAckChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPShutdownAckChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPShutdownAckChunkDescriptor::~SCTPShutdownAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPShutdownAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPShutdownAckChunk *>(obj)!=nullptr;
}

const char **SCTPShutdownAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPShutdownAckChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPShutdownAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SCTPShutdownAckChunkDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SCTPShutdownAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SCTPShutdownAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPShutdownAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SCTPShutdownAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPShutdownAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPShutdownAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPShutdownAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPShutdownAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SCTPShutdownAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SCTPShutdownAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SCTPShutdownAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownAckChunk *pp = (SCTPShutdownAckChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPShutdownCompleteChunk)

SCTPShutdownCompleteChunk::SCTPShutdownCompleteChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->TBit = 0;
}

SCTPShutdownCompleteChunk::SCTPShutdownCompleteChunk(const SCTPShutdownCompleteChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPShutdownCompleteChunk::~SCTPShutdownCompleteChunk()
{
}

SCTPShutdownCompleteChunk& SCTPShutdownCompleteChunk::operator=(const SCTPShutdownCompleteChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPShutdownCompleteChunk::copy(const SCTPShutdownCompleteChunk& other)
{
    this->TBit = other.TBit;
}

void SCTPShutdownCompleteChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->TBit);
}

void SCTPShutdownCompleteChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->TBit);
}

bool SCTPShutdownCompleteChunk::getTBit() const
{
    return this->TBit;
}

void SCTPShutdownCompleteChunk::setTBit(bool TBit)
{
    this->TBit = TBit;
}

class SCTPShutdownCompleteChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPShutdownCompleteChunkDescriptor();
    virtual ~SCTPShutdownCompleteChunkDescriptor();

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

Register_ClassDescriptor(SCTPShutdownCompleteChunkDescriptor)

SCTPShutdownCompleteChunkDescriptor::SCTPShutdownCompleteChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPShutdownCompleteChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPShutdownCompleteChunkDescriptor::~SCTPShutdownCompleteChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPShutdownCompleteChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPShutdownCompleteChunk *>(obj)!=nullptr;
}

const char **SCTPShutdownCompleteChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPShutdownCompleteChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPShutdownCompleteChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPShutdownCompleteChunkDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPShutdownCompleteChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "TBit",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPShutdownCompleteChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='T' && strcmp(fieldName, "TBit")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPShutdownCompleteChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPShutdownCompleteChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPShutdownCompleteChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPShutdownCompleteChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPShutdownCompleteChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPShutdownCompleteChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getTBit());
        default: return "";
    }
}

bool SCTPShutdownCompleteChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setTBit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPShutdownCompleteChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPShutdownCompleteChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPShutdownCompleteChunk *pp = (SCTPShutdownCompleteChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

SCTPErrorChunk_Base::SCTPErrorChunk_Base(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->TBit = 0;
    this->MBit = 0;
}

SCTPErrorChunk_Base::SCTPErrorChunk_Base(const SCTPErrorChunk_Base& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPErrorChunk_Base::~SCTPErrorChunk_Base()
{
}

SCTPErrorChunk_Base& SCTPErrorChunk_Base::operator=(const SCTPErrorChunk_Base& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPErrorChunk_Base::copy(const SCTPErrorChunk_Base& other)
{
    this->TBit = other.TBit;
    this->MBit = other.MBit;
}

void SCTPErrorChunk_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->TBit);
    doParsimPacking(b,this->MBit);
    // field parameters is abstract -- please do packing in customized class
}

void SCTPErrorChunk_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->TBit);
    doParsimUnpacking(b,this->MBit);
    // field parameters is abstract -- please do unpacking in customized class
}

bool SCTPErrorChunk_Base::getTBit() const
{
    return this->TBit;
}

void SCTPErrorChunk_Base::setTBit(bool TBit)
{
    this->TBit = TBit;
}

bool SCTPErrorChunk_Base::getMBit() const
{
    return this->MBit;
}

void SCTPErrorChunk_Base::setMBit(bool MBit)
{
    this->MBit = MBit;
}

class SCTPErrorChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPErrorChunkDescriptor();
    virtual ~SCTPErrorChunkDescriptor();

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

Register_ClassDescriptor(SCTPErrorChunkDescriptor)

SCTPErrorChunkDescriptor::SCTPErrorChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPErrorChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPErrorChunkDescriptor::~SCTPErrorChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPErrorChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPErrorChunk_Base *>(obj)!=nullptr;
}

const char **SCTPErrorChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPErrorChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPErrorChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SCTPErrorChunkDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPErrorChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "TBit",
        "MBit",
        "parameters",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int SCTPErrorChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='T' && strcmp(fieldName, "TBit")==0) return base+0;
    if (fieldName[0]=='M' && strcmp(fieldName, "MBit")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameters")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPErrorChunkDescriptor::getFieldTypeString(int field) const
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
        "cPacketPtr",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPErrorChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPErrorChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPErrorChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case 2: return pp->getParametersArraySize();
        default: return 0;
    }
}

const char *SCTPErrorChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPErrorChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getTBit());
        case 1: return bool2string(pp->getMBit());
        case 2: {std::stringstream out; out << pp->getParameters(i); return out.str();}
        default: return "";
    }
}

bool SCTPErrorChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setTBit(string2bool(value)); return true;
        case 1: pp->setMBit(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPErrorChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(cPacketPtr));
        default: return nullptr;
    };
}

void *SCTPErrorChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorChunk_Base *pp = (SCTPErrorChunk_Base *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getParameters(i)); break;
        default: return nullptr;
    }
}

Register_Class(SCTPParameter)

SCTPParameter::SCTPParameter(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->parameterType = 0;
}

SCTPParameter::SCTPParameter(const SCTPParameter& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SCTPParameter::~SCTPParameter()
{
}

SCTPParameter& SCTPParameter::operator=(const SCTPParameter& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPParameter::copy(const SCTPParameter& other)
{
    this->parameterType = other.parameterType;
}

void SCTPParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->parameterType);
}

void SCTPParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->parameterType);
}

uint16_t SCTPParameter::getParameterType() const
{
    return this->parameterType;
}

void SCTPParameter::setParameterType(uint16_t parameterType)
{
    this->parameterType = parameterType;
}

class SCTPParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPParameterDescriptor();
    virtual ~SCTPParameterDescriptor();

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

Register_ClassDescriptor(SCTPParameterDescriptor)

SCTPParameterDescriptor::SCTPParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPParameter", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SCTPParameterDescriptor::~SCTPParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPParameter *>(obj)!=nullptr;
}

const char **SCTPParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameterType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameterType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getParameterType());
        default: return "";
    }
}

bool SCTPParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setParameterType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPParameter *pp = (SCTPParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPPacketDropChunk)

SCTPPacketDropChunk::SCTPPacketDropChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->cFlag = false;
    this->tFlag = false;
    this->bFlag = false;
    this->mFlag = false;
    this->maxRwnd = 0;
    this->queuedData = 0;
    this->truncLength = 0;
}

SCTPPacketDropChunk::SCTPPacketDropChunk(const SCTPPacketDropChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPPacketDropChunk::~SCTPPacketDropChunk()
{
}

SCTPPacketDropChunk& SCTPPacketDropChunk::operator=(const SCTPPacketDropChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPPacketDropChunk::copy(const SCTPPacketDropChunk& other)
{
    this->cFlag = other.cFlag;
    this->tFlag = other.tFlag;
    this->bFlag = other.bFlag;
    this->mFlag = other.mFlag;
    this->maxRwnd = other.maxRwnd;
    this->queuedData = other.queuedData;
    this->truncLength = other.truncLength;
}

void SCTPPacketDropChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->cFlag);
    doParsimPacking(b,this->tFlag);
    doParsimPacking(b,this->bFlag);
    doParsimPacking(b,this->mFlag);
    doParsimPacking(b,this->maxRwnd);
    doParsimPacking(b,this->queuedData);
    doParsimPacking(b,this->truncLength);
}

void SCTPPacketDropChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->cFlag);
    doParsimUnpacking(b,this->tFlag);
    doParsimUnpacking(b,this->bFlag);
    doParsimUnpacking(b,this->mFlag);
    doParsimUnpacking(b,this->maxRwnd);
    doParsimUnpacking(b,this->queuedData);
    doParsimUnpacking(b,this->truncLength);
}

bool SCTPPacketDropChunk::getCFlag() const
{
    return this->cFlag;
}

void SCTPPacketDropChunk::setCFlag(bool cFlag)
{
    this->cFlag = cFlag;
}

bool SCTPPacketDropChunk::getTFlag() const
{
    return this->tFlag;
}

void SCTPPacketDropChunk::setTFlag(bool tFlag)
{
    this->tFlag = tFlag;
}

bool SCTPPacketDropChunk::getBFlag() const
{
    return this->bFlag;
}

void SCTPPacketDropChunk::setBFlag(bool bFlag)
{
    this->bFlag = bFlag;
}

bool SCTPPacketDropChunk::getMFlag() const
{
    return this->mFlag;
}

void SCTPPacketDropChunk::setMFlag(bool mFlag)
{
    this->mFlag = mFlag;
}

uint32_t SCTPPacketDropChunk::getMaxRwnd() const
{
    return this->maxRwnd;
}

void SCTPPacketDropChunk::setMaxRwnd(uint32_t maxRwnd)
{
    this->maxRwnd = maxRwnd;
}

uint32_t SCTPPacketDropChunk::getQueuedData() const
{
    return this->queuedData;
}

void SCTPPacketDropChunk::setQueuedData(uint32_t queuedData)
{
    this->queuedData = queuedData;
}

uint16_t SCTPPacketDropChunk::getTruncLength() const
{
    return this->truncLength;
}

void SCTPPacketDropChunk::setTruncLength(uint16_t truncLength)
{
    this->truncLength = truncLength;
}

class SCTPPacketDropChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPPacketDropChunkDescriptor();
    virtual ~SCTPPacketDropChunkDescriptor();

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

Register_ClassDescriptor(SCTPPacketDropChunkDescriptor)

SCTPPacketDropChunkDescriptor::SCTPPacketDropChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPPacketDropChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPPacketDropChunkDescriptor::~SCTPPacketDropChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPPacketDropChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPPacketDropChunk *>(obj)!=nullptr;
}

const char **SCTPPacketDropChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPPacketDropChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPPacketDropChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int SCTPPacketDropChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *SCTPPacketDropChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "cFlag",
        "tFlag",
        "bFlag",
        "mFlag",
        "maxRwnd",
        "queuedData",
        "truncLength",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int SCTPPacketDropChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "cFlag")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tFlag")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bFlag")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "mFlag")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxRwnd")==0) return base+4;
    if (fieldName[0]=='q' && strcmp(fieldName, "queuedData")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "truncLength")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPPacketDropChunkDescriptor::getFieldTypeString(int field) const
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
        "uint32",
        "uint32",
        "uint16",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPPacketDropChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPPacketDropChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPPacketDropChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPPacketDropChunk *pp = (SCTPPacketDropChunk *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPPacketDropChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPPacketDropChunk *pp = (SCTPPacketDropChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPPacketDropChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPPacketDropChunk *pp = (SCTPPacketDropChunk *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getCFlag());
        case 1: return bool2string(pp->getTFlag());
        case 2: return bool2string(pp->getBFlag());
        case 3: return bool2string(pp->getMFlag());
        case 4: return ulong2string(pp->getMaxRwnd());
        case 5: return ulong2string(pp->getQueuedData());
        case 6: return ulong2string(pp->getTruncLength());
        default: return "";
    }
}

bool SCTPPacketDropChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPPacketDropChunk *pp = (SCTPPacketDropChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setCFlag(string2bool(value)); return true;
        case 1: pp->setTFlag(string2bool(value)); return true;
        case 2: pp->setBFlag(string2bool(value)); return true;
        case 3: pp->setMFlag(string2bool(value)); return true;
        case 4: pp->setMaxRwnd(string2ulong(value)); return true;
        case 5: pp->setQueuedData(string2ulong(value)); return true;
        case 6: pp->setTruncLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPPacketDropChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPPacketDropChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPPacketDropChunk *pp = (SCTPPacketDropChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

SCTPStreamResetChunk_Base::SCTPStreamResetChunk_Base(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
}

SCTPStreamResetChunk_Base::SCTPStreamResetChunk_Base(const SCTPStreamResetChunk_Base& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPStreamResetChunk_Base::~SCTPStreamResetChunk_Base()
{
}

SCTPStreamResetChunk_Base& SCTPStreamResetChunk_Base::operator=(const SCTPStreamResetChunk_Base& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPStreamResetChunk_Base::copy(const SCTPStreamResetChunk_Base& other)
{
}

void SCTPStreamResetChunk_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    // field parameters is abstract -- please do packing in customized class
}

void SCTPStreamResetChunk_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    // field parameters is abstract -- please do unpacking in customized class
}

class SCTPStreamResetChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPStreamResetChunkDescriptor();
    virtual ~SCTPStreamResetChunkDescriptor();

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

Register_ClassDescriptor(SCTPStreamResetChunkDescriptor)

SCTPStreamResetChunkDescriptor::SCTPStreamResetChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPStreamResetChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPStreamResetChunkDescriptor::~SCTPStreamResetChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPStreamResetChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPStreamResetChunk_Base *>(obj)!=nullptr;
}

const char **SCTPStreamResetChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPStreamResetChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPStreamResetChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPStreamResetChunkDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPStreamResetChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "parameters",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPStreamResetChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameters")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPStreamResetChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "cPacketPtr",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPStreamResetChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPStreamResetChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPStreamResetChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetChunk_Base *pp = (SCTPStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: return pp->getParametersArraySize();
        default: return 0;
    }
}

const char *SCTPStreamResetChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetChunk_Base *pp = (SCTPStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPStreamResetChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetChunk_Base *pp = (SCTPStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getParameters(i); return out.str();}
        default: return "";
    }
}

bool SCTPStreamResetChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetChunk_Base *pp = (SCTPStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SCTPStreamResetChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(cPacketPtr));
        default: return nullptr;
    };
}

void *SCTPStreamResetChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetChunk_Base *pp = (SCTPStreamResetChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getParameters(i)); break;
        default: return nullptr;
    }
}

Register_Class(SCTPOutgoingSSNResetRequestParameter)

SCTPOutgoingSSNResetRequestParameter::SCTPOutgoingSSNResetRequestParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->srReqSn = 0;
    this->srResSn = 0;
    this->lastTsn = 0;
    streamNumbers_arraysize = 0;
    this->streamNumbers = 0;
}

SCTPOutgoingSSNResetRequestParameter::SCTPOutgoingSSNResetRequestParameter(const SCTPOutgoingSSNResetRequestParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    streamNumbers_arraysize = 0;
    this->streamNumbers = 0;
    copy(other);
}

SCTPOutgoingSSNResetRequestParameter::~SCTPOutgoingSSNResetRequestParameter()
{
    delete [] this->streamNumbers;
}

SCTPOutgoingSSNResetRequestParameter& SCTPOutgoingSSNResetRequestParameter::operator=(const SCTPOutgoingSSNResetRequestParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPOutgoingSSNResetRequestParameter::copy(const SCTPOutgoingSSNResetRequestParameter& other)
{
    this->srReqSn = other.srReqSn;
    this->srResSn = other.srResSn;
    this->lastTsn = other.lastTsn;
    delete [] this->streamNumbers;
    this->streamNumbers = (other.streamNumbers_arraysize==0) ? nullptr : new uint16_t[other.streamNumbers_arraysize];
    streamNumbers_arraysize = other.streamNumbers_arraysize;
    for (unsigned int i=0; i<streamNumbers_arraysize; i++)
        this->streamNumbers[i] = other.streamNumbers[i];
}

void SCTPOutgoingSSNResetRequestParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->srReqSn);
    doParsimPacking(b,this->srResSn);
    doParsimPacking(b,this->lastTsn);
    b->pack(streamNumbers_arraysize);
    doParsimArrayPacking(b,this->streamNumbers,streamNumbers_arraysize);
}

void SCTPOutgoingSSNResetRequestParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srReqSn);
    doParsimUnpacking(b,this->srResSn);
    doParsimUnpacking(b,this->lastTsn);
    delete [] this->streamNumbers;
    b->unpack(streamNumbers_arraysize);
    if (streamNumbers_arraysize==0) {
        this->streamNumbers = 0;
    } else {
        this->streamNumbers = new uint16_t[streamNumbers_arraysize];
        doParsimArrayUnpacking(b,this->streamNumbers,streamNumbers_arraysize);
    }
}

uint32_t SCTPOutgoingSSNResetRequestParameter::getSrReqSn() const
{
    return this->srReqSn;
}

void SCTPOutgoingSSNResetRequestParameter::setSrReqSn(uint32_t srReqSn)
{
    this->srReqSn = srReqSn;
}

uint32_t SCTPOutgoingSSNResetRequestParameter::getSrResSn() const
{
    return this->srResSn;
}

void SCTPOutgoingSSNResetRequestParameter::setSrResSn(uint32_t srResSn)
{
    this->srResSn = srResSn;
}

uint32_t SCTPOutgoingSSNResetRequestParameter::getLastTsn() const
{
    return this->lastTsn;
}

void SCTPOutgoingSSNResetRequestParameter::setLastTsn(uint32_t lastTsn)
{
    this->lastTsn = lastTsn;
}

void SCTPOutgoingSSNResetRequestParameter::setStreamNumbersArraySize(unsigned int size)
{
    uint16_t *streamNumbers2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = streamNumbers_arraysize < size ? streamNumbers_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        streamNumbers2[i] = this->streamNumbers[i];
    for (unsigned int i=sz; i<size; i++)
        streamNumbers2[i] = 0;
    streamNumbers_arraysize = size;
    delete [] this->streamNumbers;
    this->streamNumbers = streamNumbers2;
}

unsigned int SCTPOutgoingSSNResetRequestParameter::getStreamNumbersArraySize() const
{
    return streamNumbers_arraysize;
}

uint16_t SCTPOutgoingSSNResetRequestParameter::getStreamNumbers(unsigned int k) const
{
    if (k>=streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", streamNumbers_arraysize, k);
    return this->streamNumbers[k];
}

void SCTPOutgoingSSNResetRequestParameter::setStreamNumbers(unsigned int k, uint16_t streamNumbers)
{
    if (k>=streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", streamNumbers_arraysize, k);
    this->streamNumbers[k] = streamNumbers;
}

class SCTPOutgoingSSNResetRequestParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPOutgoingSSNResetRequestParameterDescriptor();
    virtual ~SCTPOutgoingSSNResetRequestParameterDescriptor();

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

Register_ClassDescriptor(SCTPOutgoingSSNResetRequestParameterDescriptor)

SCTPOutgoingSSNResetRequestParameterDescriptor::SCTPOutgoingSSNResetRequestParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPOutgoingSSNResetRequestParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPOutgoingSSNResetRequestParameterDescriptor::~SCTPOutgoingSSNResetRequestParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPOutgoingSSNResetRequestParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPOutgoingSSNResetRequestParameter *>(obj)!=nullptr;
}

const char **SCTPOutgoingSSNResetRequestParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPOutgoingSSNResetRequestParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srReqSn",
        "srResSn",
        "lastTsn",
        "streamNumbers",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPOutgoingSSNResetRequestParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srReqSn")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srResSn")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "lastTsn")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "streamNumbers")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
        "uint32",
        "uint16",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPOutgoingSSNResetRequestParameter *pp = (SCTPOutgoingSSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        case 3: return pp->getStreamNumbersArraySize();
        default: return 0;
    }
}

const char *SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPOutgoingSSNResetRequestParameter *pp = (SCTPOutgoingSSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPOutgoingSSNResetRequestParameter *pp = (SCTPOutgoingSSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSrReqSn());
        case 1: return ulong2string(pp->getSrResSn());
        case 2: return ulong2string(pp->getLastTsn());
        case 3: return ulong2string(pp->getStreamNumbers(i));
        default: return "";
    }
}

bool SCTPOutgoingSSNResetRequestParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPOutgoingSSNResetRequestParameter *pp = (SCTPOutgoingSSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrReqSn(string2ulong(value)); return true;
        case 1: pp->setSrResSn(string2ulong(value)); return true;
        case 2: pp->setLastTsn(string2ulong(value)); return true;
        case 3: pp->setStreamNumbers(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPOutgoingSSNResetRequestParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPOutgoingSSNResetRequestParameter *pp = (SCTPOutgoingSSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

SCTPIncomingSSNResetRequestParameter_Base::SCTPIncomingSSNResetRequestParameter_Base(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->srReqSn = 0;
    streamNumbers_arraysize = 0;
    this->streamNumbers = 0;
}

SCTPIncomingSSNResetRequestParameter_Base::SCTPIncomingSSNResetRequestParameter_Base(const SCTPIncomingSSNResetRequestParameter_Base& other) : ::inet::sctp::SCTPParameter(other)
{
    streamNumbers_arraysize = 0;
    this->streamNumbers = 0;
    copy(other);
}

SCTPIncomingSSNResetRequestParameter_Base::~SCTPIncomingSSNResetRequestParameter_Base()
{
    delete [] this->streamNumbers;
}

SCTPIncomingSSNResetRequestParameter_Base& SCTPIncomingSSNResetRequestParameter_Base::operator=(const SCTPIncomingSSNResetRequestParameter_Base& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPIncomingSSNResetRequestParameter_Base::copy(const SCTPIncomingSSNResetRequestParameter_Base& other)
{
    this->srReqSn = other.srReqSn;
    delete [] this->streamNumbers;
    this->streamNumbers = (other.streamNumbers_arraysize==0) ? nullptr : new uint16_t[other.streamNumbers_arraysize];
    streamNumbers_arraysize = other.streamNumbers_arraysize;
    for (unsigned int i=0; i<streamNumbers_arraysize; i++)
        this->streamNumbers[i] = other.streamNumbers[i];
}

void SCTPIncomingSSNResetRequestParameter_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->srReqSn);
    b->pack(streamNumbers_arraysize);
    doParsimArrayPacking(b,this->streamNumbers,streamNumbers_arraysize);
}

void SCTPIncomingSSNResetRequestParameter_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srReqSn);
    delete [] this->streamNumbers;
    b->unpack(streamNumbers_arraysize);
    if (streamNumbers_arraysize==0) {
        this->streamNumbers = 0;
    } else {
        this->streamNumbers = new uint16_t[streamNumbers_arraysize];
        doParsimArrayUnpacking(b,this->streamNumbers,streamNumbers_arraysize);
    }
}

uint32_t SCTPIncomingSSNResetRequestParameter_Base::getSrReqSn() const
{
    return this->srReqSn;
}

void SCTPIncomingSSNResetRequestParameter_Base::setSrReqSn(uint32_t srReqSn)
{
    this->srReqSn = srReqSn;
}

void SCTPIncomingSSNResetRequestParameter_Base::setStreamNumbersArraySize(unsigned int size)
{
    uint16_t *streamNumbers2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = streamNumbers_arraysize < size ? streamNumbers_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        streamNumbers2[i] = this->streamNumbers[i];
    for (unsigned int i=sz; i<size; i++)
        streamNumbers2[i] = 0;
    streamNumbers_arraysize = size;
    delete [] this->streamNumbers;
    this->streamNumbers = streamNumbers2;
}

unsigned int SCTPIncomingSSNResetRequestParameter_Base::getStreamNumbersArraySize() const
{
    return streamNumbers_arraysize;
}

uint16_t SCTPIncomingSSNResetRequestParameter_Base::getStreamNumbers(unsigned int k) const
{
    if (k>=streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", streamNumbers_arraysize, k);
    return this->streamNumbers[k];
}

void SCTPIncomingSSNResetRequestParameter_Base::setStreamNumbers(unsigned int k, uint16_t streamNumbers)
{
    if (k>=streamNumbers_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", streamNumbers_arraysize, k);
    this->streamNumbers[k] = streamNumbers;
}

class SCTPIncomingSSNResetRequestParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPIncomingSSNResetRequestParameterDescriptor();
    virtual ~SCTPIncomingSSNResetRequestParameterDescriptor();

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

Register_ClassDescriptor(SCTPIncomingSSNResetRequestParameterDescriptor)

SCTPIncomingSSNResetRequestParameterDescriptor::SCTPIncomingSSNResetRequestParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPIncomingSSNResetRequestParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPIncomingSSNResetRequestParameterDescriptor::~SCTPIncomingSSNResetRequestParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPIncomingSSNResetRequestParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPIncomingSSNResetRequestParameter_Base *>(obj)!=nullptr;
}

const char **SCTPIncomingSSNResetRequestParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPIncomingSSNResetRequestParameterDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPIncomingSSNResetRequestParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SCTPIncomingSSNResetRequestParameterDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *SCTPIncomingSSNResetRequestParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srReqSn",
        "streamNumbers",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SCTPIncomingSSNResetRequestParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srReqSn")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "streamNumbers")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPIncomingSSNResetRequestParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint16",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPIncomingSSNResetRequestParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPIncomingSSNResetRequestParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPIncomingSSNResetRequestParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPIncomingSSNResetRequestParameter_Base *pp = (SCTPIncomingSSNResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        case 1: return pp->getStreamNumbersArraySize();
        default: return 0;
    }
}

const char *SCTPIncomingSSNResetRequestParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPIncomingSSNResetRequestParameter_Base *pp = (SCTPIncomingSSNResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPIncomingSSNResetRequestParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPIncomingSSNResetRequestParameter_Base *pp = (SCTPIncomingSSNResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSrReqSn());
        case 1: return ulong2string(pp->getStreamNumbers(i));
        default: return "";
    }
}

bool SCTPIncomingSSNResetRequestParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPIncomingSSNResetRequestParameter_Base *pp = (SCTPIncomingSSNResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrReqSn(string2ulong(value)); return true;
        case 1: pp->setStreamNumbers(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPIncomingSSNResetRequestParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPIncomingSSNResetRequestParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPIncomingSSNResetRequestParameter_Base *pp = (SCTPIncomingSSNResetRequestParameter_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPSSNTSNResetRequestParameter)

SCTPSSNTSNResetRequestParameter::SCTPSSNTSNResetRequestParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->srReqSn = 0;
}

SCTPSSNTSNResetRequestParameter::SCTPSSNTSNResetRequestParameter(const SCTPSSNTSNResetRequestParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPSSNTSNResetRequestParameter::~SCTPSSNTSNResetRequestParameter()
{
}

SCTPSSNTSNResetRequestParameter& SCTPSSNTSNResetRequestParameter::operator=(const SCTPSSNTSNResetRequestParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPSSNTSNResetRequestParameter::copy(const SCTPSSNTSNResetRequestParameter& other)
{
    this->srReqSn = other.srReqSn;
}

void SCTPSSNTSNResetRequestParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->srReqSn);
}

void SCTPSSNTSNResetRequestParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srReqSn);
}

uint32_t SCTPSSNTSNResetRequestParameter::getSrReqSn() const
{
    return this->srReqSn;
}

void SCTPSSNTSNResetRequestParameter::setSrReqSn(uint32_t srReqSn)
{
    this->srReqSn = srReqSn;
}

class SCTPSSNTSNResetRequestParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSSNTSNResetRequestParameterDescriptor();
    virtual ~SCTPSSNTSNResetRequestParameterDescriptor();

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

Register_ClassDescriptor(SCTPSSNTSNResetRequestParameterDescriptor)

SCTPSSNTSNResetRequestParameterDescriptor::SCTPSSNTSNResetRequestParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPSSNTSNResetRequestParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPSSNTSNResetRequestParameterDescriptor::~SCTPSSNTSNResetRequestParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPSSNTSNResetRequestParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSSNTSNResetRequestParameter *>(obj)!=nullptr;
}

const char **SCTPSSNTSNResetRequestParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSSNTSNResetRequestParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSSNTSNResetRequestParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPSSNTSNResetRequestParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPSSNTSNResetRequestParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srReqSn",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPSSNTSNResetRequestParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srReqSn")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSSNTSNResetRequestParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSSNTSNResetRequestParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSSNTSNResetRequestParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSSNTSNResetRequestParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSSNTSNResetRequestParameter *pp = (SCTPSSNTSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPSSNTSNResetRequestParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSSNTSNResetRequestParameter *pp = (SCTPSSNTSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSSNTSNResetRequestParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSSNTSNResetRequestParameter *pp = (SCTPSSNTSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSrReqSn());
        default: return "";
    }
}

bool SCTPSSNTSNResetRequestParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSSNTSNResetRequestParameter *pp = (SCTPSSNTSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrReqSn(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPSSNTSNResetRequestParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPSSNTSNResetRequestParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSSNTSNResetRequestParameter *pp = (SCTPSSNTSNResetRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPStreamResetResponseParameter)

SCTPStreamResetResponseParameter::SCTPStreamResetResponseParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->srResSn = 0;
    this->result = 0;
    this->sendersNextTsn = 0;
    this->receiversNextTsn = 0;
}

SCTPStreamResetResponseParameter::SCTPStreamResetResponseParameter(const SCTPStreamResetResponseParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPStreamResetResponseParameter::~SCTPStreamResetResponseParameter()
{
}

SCTPStreamResetResponseParameter& SCTPStreamResetResponseParameter::operator=(const SCTPStreamResetResponseParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPStreamResetResponseParameter::copy(const SCTPStreamResetResponseParameter& other)
{
    this->srResSn = other.srResSn;
    this->result = other.result;
    this->sendersNextTsn = other.sendersNextTsn;
    this->receiversNextTsn = other.receiversNextTsn;
}

void SCTPStreamResetResponseParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->srResSn);
    doParsimPacking(b,this->result);
    doParsimPacking(b,this->sendersNextTsn);
    doParsimPacking(b,this->receiversNextTsn);
}

void SCTPStreamResetResponseParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srResSn);
    doParsimUnpacking(b,this->result);
    doParsimUnpacking(b,this->sendersNextTsn);
    doParsimUnpacking(b,this->receiversNextTsn);
}

uint32_t SCTPStreamResetResponseParameter::getSrResSn() const
{
    return this->srResSn;
}

void SCTPStreamResetResponseParameter::setSrResSn(uint32_t srResSn)
{
    this->srResSn = srResSn;
}

uint32_t SCTPStreamResetResponseParameter::getResult() const
{
    return this->result;
}

void SCTPStreamResetResponseParameter::setResult(uint32_t result)
{
    this->result = result;
}

uint32_t SCTPStreamResetResponseParameter::getSendersNextTsn() const
{
    return this->sendersNextTsn;
}

void SCTPStreamResetResponseParameter::setSendersNextTsn(uint32_t sendersNextTsn)
{
    this->sendersNextTsn = sendersNextTsn;
}

uint32_t SCTPStreamResetResponseParameter::getReceiversNextTsn() const
{
    return this->receiversNextTsn;
}

void SCTPStreamResetResponseParameter::setReceiversNextTsn(uint32_t receiversNextTsn)
{
    this->receiversNextTsn = receiversNextTsn;
}

class SCTPStreamResetResponseParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPStreamResetResponseParameterDescriptor();
    virtual ~SCTPStreamResetResponseParameterDescriptor();

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

Register_ClassDescriptor(SCTPStreamResetResponseParameterDescriptor)

SCTPStreamResetResponseParameterDescriptor::SCTPStreamResetResponseParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPStreamResetResponseParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPStreamResetResponseParameterDescriptor::~SCTPStreamResetResponseParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPStreamResetResponseParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPStreamResetResponseParameter *>(obj)!=nullptr;
}

const char **SCTPStreamResetResponseParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPStreamResetResponseParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPStreamResetResponseParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPStreamResetResponseParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPStreamResetResponseParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srResSn",
        "result",
        "sendersNextTsn",
        "receiversNextTsn",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPStreamResetResponseParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srResSn")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "result")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sendersNextTsn")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiversNextTsn")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPStreamResetResponseParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
        "uint32",
        "uint32",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPStreamResetResponseParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPStreamResetResponseParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPStreamResetResponseParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetResponseParameter *pp = (SCTPStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPStreamResetResponseParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetResponseParameter *pp = (SCTPStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPStreamResetResponseParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetResponseParameter *pp = (SCTPStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSrResSn());
        case 1: return ulong2string(pp->getResult());
        case 2: return ulong2string(pp->getSendersNextTsn());
        case 3: return ulong2string(pp->getReceiversNextTsn());
        default: return "";
    }
}

bool SCTPStreamResetResponseParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetResponseParameter *pp = (SCTPStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrResSn(string2ulong(value)); return true;
        case 1: pp->setResult(string2ulong(value)); return true;
        case 2: pp->setSendersNextTsn(string2ulong(value)); return true;
        case 3: pp->setReceiversNextTsn(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPStreamResetResponseParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPStreamResetResponseParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPStreamResetResponseParameter *pp = (SCTPStreamResetResponseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPAddStreamsRequestParameter)

SCTPAddStreamsRequestParameter::SCTPAddStreamsRequestParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->srReqSn = 0;
    this->numberOfStreams = 0;
    this->reserved = 0;
}

SCTPAddStreamsRequestParameter::SCTPAddStreamsRequestParameter(const SCTPAddStreamsRequestParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPAddStreamsRequestParameter::~SCTPAddStreamsRequestParameter()
{
}

SCTPAddStreamsRequestParameter& SCTPAddStreamsRequestParameter::operator=(const SCTPAddStreamsRequestParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPAddStreamsRequestParameter::copy(const SCTPAddStreamsRequestParameter& other)
{
    this->srReqSn = other.srReqSn;
    this->numberOfStreams = other.numberOfStreams;
    this->reserved = other.reserved;
}

void SCTPAddStreamsRequestParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->srReqSn);
    doParsimPacking(b,this->numberOfStreams);
    doParsimPacking(b,this->reserved);
}

void SCTPAddStreamsRequestParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->srReqSn);
    doParsimUnpacking(b,this->numberOfStreams);
    doParsimUnpacking(b,this->reserved);
}

uint32_t SCTPAddStreamsRequestParameter::getSrReqSn() const
{
    return this->srReqSn;
}

void SCTPAddStreamsRequestParameter::setSrReqSn(uint32_t srReqSn)
{
    this->srReqSn = srReqSn;
}

uint16_t SCTPAddStreamsRequestParameter::getNumberOfStreams() const
{
    return this->numberOfStreams;
}

void SCTPAddStreamsRequestParameter::setNumberOfStreams(uint16_t numberOfStreams)
{
    this->numberOfStreams = numberOfStreams;
}

uint16_t SCTPAddStreamsRequestParameter::getReserved() const
{
    return this->reserved;
}

void SCTPAddStreamsRequestParameter::setReserved(uint16_t reserved)
{
    this->reserved = reserved;
}

class SCTPAddStreamsRequestParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPAddStreamsRequestParameterDescriptor();
    virtual ~SCTPAddStreamsRequestParameterDescriptor();

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

Register_ClassDescriptor(SCTPAddStreamsRequestParameterDescriptor)

SCTPAddStreamsRequestParameterDescriptor::SCTPAddStreamsRequestParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPAddStreamsRequestParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPAddStreamsRequestParameterDescriptor::~SCTPAddStreamsRequestParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPAddStreamsRequestParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPAddStreamsRequestParameter *>(obj)!=nullptr;
}

const char **SCTPAddStreamsRequestParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPAddStreamsRequestParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPAddStreamsRequestParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SCTPAddStreamsRequestParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPAddStreamsRequestParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srReqSn",
        "numberOfStreams",
        "reserved",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int SCTPAddStreamsRequestParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srReqSn")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfStreams")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "reserved")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPAddStreamsRequestParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint16",
        "uint16",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPAddStreamsRequestParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPAddStreamsRequestParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPAddStreamsRequestParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPAddStreamsRequestParameter *pp = (SCTPAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPAddStreamsRequestParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAddStreamsRequestParameter *pp = (SCTPAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPAddStreamsRequestParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAddStreamsRequestParameter *pp = (SCTPAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSrReqSn());
        case 1: return ulong2string(pp->getNumberOfStreams());
        case 2: return ulong2string(pp->getReserved());
        default: return "";
    }
}

bool SCTPAddStreamsRequestParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPAddStreamsRequestParameter *pp = (SCTPAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrReqSn(string2ulong(value)); return true;
        case 1: pp->setNumberOfStreams(string2ulong(value)); return true;
        case 2: pp->setReserved(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPAddStreamsRequestParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPAddStreamsRequestParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPAddStreamsRequestParameter *pp = (SCTPAddStreamsRequestParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPResetTimer)

SCTPResetTimer::SCTPResetTimer(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->inSN = 0;
    this->inAcked = false;
    this->outSN = 0;
    this->outAcked = false;
}

SCTPResetTimer::SCTPResetTimer(const SCTPResetTimer& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SCTPResetTimer::~SCTPResetTimer()
{
}

SCTPResetTimer& SCTPResetTimer::operator=(const SCTPResetTimer& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPResetTimer::copy(const SCTPResetTimer& other)
{
    this->inSN = other.inSN;
    this->inAcked = other.inAcked;
    this->outSN = other.outSN;
    this->outAcked = other.outAcked;
}

void SCTPResetTimer::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->inSN);
    doParsimPacking(b,this->inAcked);
    doParsimPacking(b,this->outSN);
    doParsimPacking(b,this->outAcked);
}

void SCTPResetTimer::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->inSN);
    doParsimUnpacking(b,this->inAcked);
    doParsimUnpacking(b,this->outSN);
    doParsimUnpacking(b,this->outAcked);
}

uint32_t SCTPResetTimer::getInSN() const
{
    return this->inSN;
}

void SCTPResetTimer::setInSN(uint32_t inSN)
{
    this->inSN = inSN;
}

bool SCTPResetTimer::getInAcked() const
{
    return this->inAcked;
}

void SCTPResetTimer::setInAcked(bool inAcked)
{
    this->inAcked = inAcked;
}

uint32_t SCTPResetTimer::getOutSN() const
{
    return this->outSN;
}

void SCTPResetTimer::setOutSN(uint32_t outSN)
{
    this->outSN = outSN;
}

bool SCTPResetTimer::getOutAcked() const
{
    return this->outAcked;
}

void SCTPResetTimer::setOutAcked(bool outAcked)
{
    this->outAcked = outAcked;
}

class SCTPResetTimerDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPResetTimerDescriptor();
    virtual ~SCTPResetTimerDescriptor();

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

Register_ClassDescriptor(SCTPResetTimerDescriptor)

SCTPResetTimerDescriptor::SCTPResetTimerDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPResetTimer", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SCTPResetTimerDescriptor::~SCTPResetTimerDescriptor()
{
    delete[] propertynames;
}

bool SCTPResetTimerDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPResetTimer *>(obj)!=nullptr;
}

const char **SCTPResetTimerDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPResetTimerDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPResetTimerDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPResetTimerDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPResetTimerDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "inSN",
        "inAcked",
        "outSN",
        "outAcked",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPResetTimerDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "inSN")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "inAcked")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "outSN")==0) return base+2;
    if (fieldName[0]=='o' && strcmp(fieldName, "outAcked")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPResetTimerDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "bool",
        "uint32",
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPResetTimerDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPResetTimerDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPResetTimerDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPResetTimer *pp = (SCTPResetTimer *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPResetTimerDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPResetTimer *pp = (SCTPResetTimer *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPResetTimerDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPResetTimer *pp = (SCTPResetTimer *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getInSN());
        case 1: return bool2string(pp->getInAcked());
        case 2: return ulong2string(pp->getOutSN());
        case 3: return bool2string(pp->getOutAcked());
        default: return "";
    }
}

bool SCTPResetTimerDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPResetTimer *pp = (SCTPResetTimer *)object; (void)pp;
    switch (field) {
        case 0: pp->setInSN(string2ulong(value)); return true;
        case 1: pp->setInAcked(string2bool(value)); return true;
        case 2: pp->setOutSN(string2ulong(value)); return true;
        case 3: pp->setOutAcked(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPResetTimerDescriptor::getFieldStructName(int field) const
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

void *SCTPResetTimerDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPResetTimer *pp = (SCTPResetTimer *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPAuthenticationChunk)

SCTPAuthenticationChunk::SCTPAuthenticationChunk(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->sharedKey = 0;
    this->hMacIdentifier = 0;
    this->hMacOk = false;
    HMAC_arraysize = 0;
    this->HMAC = 0;
}

SCTPAuthenticationChunk::SCTPAuthenticationChunk(const SCTPAuthenticationChunk& other) : ::inet::sctp::SCTPChunk(other)
{
    HMAC_arraysize = 0;
    this->HMAC = 0;
    copy(other);
}

SCTPAuthenticationChunk::~SCTPAuthenticationChunk()
{
    delete [] this->HMAC;
}

SCTPAuthenticationChunk& SCTPAuthenticationChunk::operator=(const SCTPAuthenticationChunk& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPAuthenticationChunk::copy(const SCTPAuthenticationChunk& other)
{
    this->sharedKey = other.sharedKey;
    this->hMacIdentifier = other.hMacIdentifier;
    this->hMacOk = other.hMacOk;
    delete [] this->HMAC;
    this->HMAC = (other.HMAC_arraysize==0) ? nullptr : new uint32_t[other.HMAC_arraysize];
    HMAC_arraysize = other.HMAC_arraysize;
    for (unsigned int i=0; i<HMAC_arraysize; i++)
        this->HMAC[i] = other.HMAC[i];
}

void SCTPAuthenticationChunk::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->sharedKey);
    doParsimPacking(b,this->hMacIdentifier);
    doParsimPacking(b,this->hMacOk);
    b->pack(HMAC_arraysize);
    doParsimArrayPacking(b,this->HMAC,HMAC_arraysize);
}

void SCTPAuthenticationChunk::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sharedKey);
    doParsimUnpacking(b,this->hMacIdentifier);
    doParsimUnpacking(b,this->hMacOk);
    delete [] this->HMAC;
    b->unpack(HMAC_arraysize);
    if (HMAC_arraysize==0) {
        this->HMAC = 0;
    } else {
        this->HMAC = new uint32_t[HMAC_arraysize];
        doParsimArrayUnpacking(b,this->HMAC,HMAC_arraysize);
    }
}

uint16_t SCTPAuthenticationChunk::getSharedKey() const
{
    return this->sharedKey;
}

void SCTPAuthenticationChunk::setSharedKey(uint16_t sharedKey)
{
    this->sharedKey = sharedKey;
}

uint16_t SCTPAuthenticationChunk::getHMacIdentifier() const
{
    return this->hMacIdentifier;
}

void SCTPAuthenticationChunk::setHMacIdentifier(uint16_t hMacIdentifier)
{
    this->hMacIdentifier = hMacIdentifier;
}

bool SCTPAuthenticationChunk::getHMacOk() const
{
    return this->hMacOk;
}

void SCTPAuthenticationChunk::setHMacOk(bool hMacOk)
{
    this->hMacOk = hMacOk;
}

void SCTPAuthenticationChunk::setHMACArraySize(unsigned int size)
{
    uint32_t *HMAC2 = (size==0) ? nullptr : new uint32_t[size];
    unsigned int sz = HMAC_arraysize < size ? HMAC_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        HMAC2[i] = this->HMAC[i];
    for (unsigned int i=sz; i<size; i++)
        HMAC2[i] = 0;
    HMAC_arraysize = size;
    delete [] this->HMAC;
    this->HMAC = HMAC2;
}

unsigned int SCTPAuthenticationChunk::getHMACArraySize() const
{
    return HMAC_arraysize;
}

uint32_t SCTPAuthenticationChunk::getHMAC(unsigned int k) const
{
    if (k>=HMAC_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", HMAC_arraysize, k);
    return this->HMAC[k];
}

void SCTPAuthenticationChunk::setHMAC(unsigned int k, uint32_t HMAC)
{
    if (k>=HMAC_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", HMAC_arraysize, k);
    this->HMAC[k] = HMAC;
}

class SCTPAuthenticationChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPAuthenticationChunkDescriptor();
    virtual ~SCTPAuthenticationChunkDescriptor();

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

Register_ClassDescriptor(SCTPAuthenticationChunkDescriptor)

SCTPAuthenticationChunkDescriptor::SCTPAuthenticationChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPAuthenticationChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPAuthenticationChunkDescriptor::~SCTPAuthenticationChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPAuthenticationChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPAuthenticationChunk *>(obj)!=nullptr;
}

const char **SCTPAuthenticationChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPAuthenticationChunkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPAuthenticationChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPAuthenticationChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *SCTPAuthenticationChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sharedKey",
        "hMacIdentifier",
        "hMacOk",
        "HMAC",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPAuthenticationChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sharedKey")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hMacIdentifier")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hMacOk")==0) return base+2;
    if (fieldName[0]=='H' && strcmp(fieldName, "HMAC")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPAuthenticationChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
        "uint16",
        "bool",
        "uint32",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPAuthenticationChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPAuthenticationChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPAuthenticationChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPAuthenticationChunk *pp = (SCTPAuthenticationChunk *)object; (void)pp;
    switch (field) {
        case 3: return pp->getHMACArraySize();
        default: return 0;
    }
}

const char *SCTPAuthenticationChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAuthenticationChunk *pp = (SCTPAuthenticationChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPAuthenticationChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAuthenticationChunk *pp = (SCTPAuthenticationChunk *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSharedKey());
        case 1: return ulong2string(pp->getHMacIdentifier());
        case 2: return bool2string(pp->getHMacOk());
        case 3: return ulong2string(pp->getHMAC(i));
        default: return "";
    }
}

bool SCTPAuthenticationChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPAuthenticationChunk *pp = (SCTPAuthenticationChunk *)object; (void)pp;
    switch (field) {
        case 0: pp->setSharedKey(string2ulong(value)); return true;
        case 1: pp->setHMacIdentifier(string2ulong(value)); return true;
        case 2: pp->setHMacOk(string2bool(value)); return true;
        case 3: pp->setHMAC(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPAuthenticationChunkDescriptor::getFieldStructName(int field) const
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

void *SCTPAuthenticationChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPAuthenticationChunk *pp = (SCTPAuthenticationChunk *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

SCTPAsconfChunk_Base::SCTPAsconfChunk_Base(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->serialNumber = 0;
    this->peerVTag = 0;
}

SCTPAsconfChunk_Base::SCTPAsconfChunk_Base(const SCTPAsconfChunk_Base& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPAsconfChunk_Base::~SCTPAsconfChunk_Base()
{
}

SCTPAsconfChunk_Base& SCTPAsconfChunk_Base::operator=(const SCTPAsconfChunk_Base& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPAsconfChunk_Base::copy(const SCTPAsconfChunk_Base& other)
{
    this->serialNumber = other.serialNumber;
    this->addressParam = other.addressParam;
    this->peerVTag = other.peerVTag;
}

void SCTPAsconfChunk_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->serialNumber);
    doParsimPacking(b,this->addressParam);
    doParsimPacking(b,this->peerVTag);
    // field asconfParams is abstract -- please do packing in customized class
}

void SCTPAsconfChunk_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->serialNumber);
    doParsimUnpacking(b,this->addressParam);
    doParsimUnpacking(b,this->peerVTag);
    // field asconfParams is abstract -- please do unpacking in customized class
}

uint32_t SCTPAsconfChunk_Base::getSerialNumber() const
{
    return this->serialNumber;
}

void SCTPAsconfChunk_Base::setSerialNumber(uint32_t serialNumber)
{
    this->serialNumber = serialNumber;
}

L3Address& SCTPAsconfChunk_Base::getAddressParam()
{
    return this->addressParam;
}

void SCTPAsconfChunk_Base::setAddressParam(const L3Address& addressParam)
{
    this->addressParam = addressParam;
}

uint32_t SCTPAsconfChunk_Base::getPeerVTag() const
{
    return this->peerVTag;
}

void SCTPAsconfChunk_Base::setPeerVTag(uint32_t peerVTag)
{
    this->peerVTag = peerVTag;
}

class SCTPAsconfChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPAsconfChunkDescriptor();
    virtual ~SCTPAsconfChunkDescriptor();

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

Register_ClassDescriptor(SCTPAsconfChunkDescriptor)

SCTPAsconfChunkDescriptor::SCTPAsconfChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPAsconfChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPAsconfChunkDescriptor::~SCTPAsconfChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPAsconfChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPAsconfChunk_Base *>(obj)!=nullptr;
}

const char **SCTPAsconfChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPAsconfChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPAsconfChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPAsconfChunkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *SCTPAsconfChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serialNumber",
        "addressParam",
        "peerVTag",
        "asconfParams",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPAsconfChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "serialNumber")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressParam")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "peerVTag")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "asconfParams")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPAsconfChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "L3Address",
        "uint32",
        "cPacketPtr",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPAsconfChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPAsconfChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPAsconfChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfChunk_Base *pp = (SCTPAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case 3: return pp->getAsconfParamsArraySize();
        default: return 0;
    }
}

const char *SCTPAsconfChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfChunk_Base *pp = (SCTPAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPAsconfChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfChunk_Base *pp = (SCTPAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSerialNumber());
        case 1: {std::stringstream out; out << pp->getAddressParam(); return out.str();}
        case 2: return ulong2string(pp->getPeerVTag());
        case 3: {std::stringstream out; out << pp->getAsconfParams(i); return out.str();}
        default: return "";
    }
}

bool SCTPAsconfChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfChunk_Base *pp = (SCTPAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSerialNumber(string2ulong(value)); return true;
        case 2: pp->setPeerVTag(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPAsconfChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        case 3: return omnetpp::opp_typename(typeid(cPacketPtr));
        default: return nullptr;
    };
}

void *SCTPAsconfChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfChunk_Base *pp = (SCTPAsconfChunk_Base *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getAddressParam()); break;
        case 3: return (void *)(&pp->getAsconfParams(i)); break;
        default: return nullptr;
    }
}

SCTPAsconfAckChunk_Base::SCTPAsconfAckChunk_Base(const char *name, short kind) : ::inet::sctp::SCTPChunk(name,kind)
{
    this->serialNumber = 0;
}

SCTPAsconfAckChunk_Base::SCTPAsconfAckChunk_Base(const SCTPAsconfAckChunk_Base& other) : ::inet::sctp::SCTPChunk(other)
{
    copy(other);
}

SCTPAsconfAckChunk_Base::~SCTPAsconfAckChunk_Base()
{
}

SCTPAsconfAckChunk_Base& SCTPAsconfAckChunk_Base::operator=(const SCTPAsconfAckChunk_Base& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPChunk::operator=(other);
    copy(other);
    return *this;
}

void SCTPAsconfAckChunk_Base::copy(const SCTPAsconfAckChunk_Base& other)
{
    this->serialNumber = other.serialNumber;
}

void SCTPAsconfAckChunk_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPChunk::parsimPack(b);
    doParsimPacking(b,this->serialNumber);
    // field asconfResponse is abstract -- please do packing in customized class
}

void SCTPAsconfAckChunk_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->serialNumber);
    // field asconfResponse is abstract -- please do unpacking in customized class
}

uint32_t SCTPAsconfAckChunk_Base::getSerialNumber() const
{
    return this->serialNumber;
}

void SCTPAsconfAckChunk_Base::setSerialNumber(uint32_t serialNumber)
{
    this->serialNumber = serialNumber;
}

class SCTPAsconfAckChunkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPAsconfAckChunkDescriptor();
    virtual ~SCTPAsconfAckChunkDescriptor();

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

Register_ClassDescriptor(SCTPAsconfAckChunkDescriptor)

SCTPAsconfAckChunkDescriptor::SCTPAsconfAckChunkDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPAsconfAckChunk", "inet::sctp::SCTPChunk")
{
    propertynames = nullptr;
}

SCTPAsconfAckChunkDescriptor::~SCTPAsconfAckChunkDescriptor()
{
    delete[] propertynames;
}

bool SCTPAsconfAckChunkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPAsconfAckChunk_Base *>(obj)!=nullptr;
}

const char **SCTPAsconfAckChunkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPAsconfAckChunkDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPAsconfAckChunkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SCTPAsconfAckChunkDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPAsconfAckChunkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "serialNumber",
        "asconfResponse",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SCTPAsconfAckChunkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "serialNumber")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "asconfResponse")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPAsconfAckChunkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "cPacketPtr",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPAsconfAckChunkDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPAsconfAckChunkDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPAsconfAckChunkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfAckChunk_Base *pp = (SCTPAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case 1: return pp->getAsconfResponseArraySize();
        default: return 0;
    }
}

const char *SCTPAsconfAckChunkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfAckChunk_Base *pp = (SCTPAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPAsconfAckChunkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfAckChunk_Base *pp = (SCTPAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSerialNumber());
        case 1: {std::stringstream out; out << pp->getAsconfResponse(i); return out.str();}
        default: return "";
    }
}

bool SCTPAsconfAckChunkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfAckChunk_Base *pp = (SCTPAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSerialNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPAsconfAckChunkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cPacketPtr));
        default: return nullptr;
    };
}

void *SCTPAsconfAckChunkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPAsconfAckChunk_Base *pp = (SCTPAsconfAckChunk_Base *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getAsconfResponse(i)); break;
        default: return nullptr;
    }
}

Register_Class(SCTPAddIPParameter)

SCTPAddIPParameter::SCTPAddIPParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->requestCorrelationId = 0;
}

SCTPAddIPParameter::SCTPAddIPParameter(const SCTPAddIPParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPAddIPParameter::~SCTPAddIPParameter()
{
}

SCTPAddIPParameter& SCTPAddIPParameter::operator=(const SCTPAddIPParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPAddIPParameter::copy(const SCTPAddIPParameter& other)
{
    this->requestCorrelationId = other.requestCorrelationId;
    this->addressParam = other.addressParam;
}

void SCTPAddIPParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->requestCorrelationId);
    doParsimPacking(b,this->addressParam);
}

void SCTPAddIPParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->requestCorrelationId);
    doParsimUnpacking(b,this->addressParam);
}

uint32_t SCTPAddIPParameter::getRequestCorrelationId() const
{
    return this->requestCorrelationId;
}

void SCTPAddIPParameter::setRequestCorrelationId(uint32_t requestCorrelationId)
{
    this->requestCorrelationId = requestCorrelationId;
}

L3Address& SCTPAddIPParameter::getAddressParam()
{
    return this->addressParam;
}

void SCTPAddIPParameter::setAddressParam(const L3Address& addressParam)
{
    this->addressParam = addressParam;
}

class SCTPAddIPParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPAddIPParameterDescriptor();
    virtual ~SCTPAddIPParameterDescriptor();

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

Register_ClassDescriptor(SCTPAddIPParameterDescriptor)

SCTPAddIPParameterDescriptor::SCTPAddIPParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPAddIPParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPAddIPParameterDescriptor::~SCTPAddIPParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPAddIPParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPAddIPParameter *>(obj)!=nullptr;
}

const char **SCTPAddIPParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPAddIPParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPAddIPParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SCTPAddIPParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPAddIPParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requestCorrelationId",
        "addressParam",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SCTPAddIPParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestCorrelationId")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressParam")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPAddIPParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "L3Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPAddIPParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPAddIPParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPAddIPParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPAddIPParameter *pp = (SCTPAddIPParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPAddIPParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAddIPParameter *pp = (SCTPAddIPParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPAddIPParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPAddIPParameter *pp = (SCTPAddIPParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRequestCorrelationId());
        case 1: {std::stringstream out; out << pp->getAddressParam(); return out.str();}
        default: return "";
    }
}

bool SCTPAddIPParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPAddIPParameter *pp = (SCTPAddIPParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setRequestCorrelationId(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPAddIPParameterDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPAddIPParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPAddIPParameter *pp = (SCTPAddIPParameter *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getAddressParam()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPDeleteIPParameter)

SCTPDeleteIPParameter::SCTPDeleteIPParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->requestCorrelationId = 0;
}

SCTPDeleteIPParameter::SCTPDeleteIPParameter(const SCTPDeleteIPParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPDeleteIPParameter::~SCTPDeleteIPParameter()
{
}

SCTPDeleteIPParameter& SCTPDeleteIPParameter::operator=(const SCTPDeleteIPParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPDeleteIPParameter::copy(const SCTPDeleteIPParameter& other)
{
    this->requestCorrelationId = other.requestCorrelationId;
    this->addressParam = other.addressParam;
}

void SCTPDeleteIPParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->requestCorrelationId);
    doParsimPacking(b,this->addressParam);
}

void SCTPDeleteIPParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->requestCorrelationId);
    doParsimUnpacking(b,this->addressParam);
}

uint32_t SCTPDeleteIPParameter::getRequestCorrelationId() const
{
    return this->requestCorrelationId;
}

void SCTPDeleteIPParameter::setRequestCorrelationId(uint32_t requestCorrelationId)
{
    this->requestCorrelationId = requestCorrelationId;
}

L3Address& SCTPDeleteIPParameter::getAddressParam()
{
    return this->addressParam;
}

void SCTPDeleteIPParameter::setAddressParam(const L3Address& addressParam)
{
    this->addressParam = addressParam;
}

class SCTPDeleteIPParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPDeleteIPParameterDescriptor();
    virtual ~SCTPDeleteIPParameterDescriptor();

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

Register_ClassDescriptor(SCTPDeleteIPParameterDescriptor)

SCTPDeleteIPParameterDescriptor::SCTPDeleteIPParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPDeleteIPParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPDeleteIPParameterDescriptor::~SCTPDeleteIPParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPDeleteIPParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPDeleteIPParameter *>(obj)!=nullptr;
}

const char **SCTPDeleteIPParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPDeleteIPParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPDeleteIPParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SCTPDeleteIPParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPDeleteIPParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requestCorrelationId",
        "addressParam",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SCTPDeleteIPParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestCorrelationId")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressParam")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPDeleteIPParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "L3Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPDeleteIPParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPDeleteIPParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPDeleteIPParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPDeleteIPParameter *pp = (SCTPDeleteIPParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPDeleteIPParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPDeleteIPParameter *pp = (SCTPDeleteIPParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPDeleteIPParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPDeleteIPParameter *pp = (SCTPDeleteIPParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRequestCorrelationId());
        case 1: {std::stringstream out; out << pp->getAddressParam(); return out.str();}
        default: return "";
    }
}

bool SCTPDeleteIPParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPDeleteIPParameter *pp = (SCTPDeleteIPParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setRequestCorrelationId(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPDeleteIPParameterDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPDeleteIPParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPDeleteIPParameter *pp = (SCTPDeleteIPParameter *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getAddressParam()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPSetPrimaryIPParameter)

SCTPSetPrimaryIPParameter::SCTPSetPrimaryIPParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->requestCorrelationId = 0;
}

SCTPSetPrimaryIPParameter::SCTPSetPrimaryIPParameter(const SCTPSetPrimaryIPParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPSetPrimaryIPParameter::~SCTPSetPrimaryIPParameter()
{
}

SCTPSetPrimaryIPParameter& SCTPSetPrimaryIPParameter::operator=(const SCTPSetPrimaryIPParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPSetPrimaryIPParameter::copy(const SCTPSetPrimaryIPParameter& other)
{
    this->requestCorrelationId = other.requestCorrelationId;
    this->addressParam = other.addressParam;
}

void SCTPSetPrimaryIPParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->requestCorrelationId);
    doParsimPacking(b,this->addressParam);
}

void SCTPSetPrimaryIPParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->requestCorrelationId);
    doParsimUnpacking(b,this->addressParam);
}

uint32_t SCTPSetPrimaryIPParameter::getRequestCorrelationId() const
{
    return this->requestCorrelationId;
}

void SCTPSetPrimaryIPParameter::setRequestCorrelationId(uint32_t requestCorrelationId)
{
    this->requestCorrelationId = requestCorrelationId;
}

L3Address& SCTPSetPrimaryIPParameter::getAddressParam()
{
    return this->addressParam;
}

void SCTPSetPrimaryIPParameter::setAddressParam(const L3Address& addressParam)
{
    this->addressParam = addressParam;
}

class SCTPSetPrimaryIPParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSetPrimaryIPParameterDescriptor();
    virtual ~SCTPSetPrimaryIPParameterDescriptor();

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

Register_ClassDescriptor(SCTPSetPrimaryIPParameterDescriptor)

SCTPSetPrimaryIPParameterDescriptor::SCTPSetPrimaryIPParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPSetPrimaryIPParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPSetPrimaryIPParameterDescriptor::~SCTPSetPrimaryIPParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPSetPrimaryIPParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSetPrimaryIPParameter *>(obj)!=nullptr;
}

const char **SCTPSetPrimaryIPParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSetPrimaryIPParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSetPrimaryIPParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SCTPSetPrimaryIPParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPSetPrimaryIPParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requestCorrelationId",
        "addressParam",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SCTPSetPrimaryIPParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestCorrelationId")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressParam")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSetPrimaryIPParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "L3Address",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSetPrimaryIPParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSetPrimaryIPParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSetPrimaryIPParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSetPrimaryIPParameter *pp = (SCTPSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPSetPrimaryIPParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSetPrimaryIPParameter *pp = (SCTPSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSetPrimaryIPParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSetPrimaryIPParameter *pp = (SCTPSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRequestCorrelationId());
        case 1: {std::stringstream out; out << pp->getAddressParam(); return out.str();}
        default: return "";
    }
}

bool SCTPSetPrimaryIPParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSetPrimaryIPParameter *pp = (SCTPSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setRequestCorrelationId(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPSetPrimaryIPParameterDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPSetPrimaryIPParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSetPrimaryIPParameter *pp = (SCTPSetPrimaryIPParameter *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getAddressParam()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPSupportedExtensionsParameter)

SCTPSupportedExtensionsParameter::SCTPSupportedExtensionsParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    chunkTypes_arraysize = 0;
    this->chunkTypes = 0;
}

SCTPSupportedExtensionsParameter::SCTPSupportedExtensionsParameter(const SCTPSupportedExtensionsParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    chunkTypes_arraysize = 0;
    this->chunkTypes = 0;
    copy(other);
}

SCTPSupportedExtensionsParameter::~SCTPSupportedExtensionsParameter()
{
    delete [] this->chunkTypes;
}

SCTPSupportedExtensionsParameter& SCTPSupportedExtensionsParameter::operator=(const SCTPSupportedExtensionsParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPSupportedExtensionsParameter::copy(const SCTPSupportedExtensionsParameter& other)
{
    delete [] this->chunkTypes;
    this->chunkTypes = (other.chunkTypes_arraysize==0) ? nullptr : new uint16_t[other.chunkTypes_arraysize];
    chunkTypes_arraysize = other.chunkTypes_arraysize;
    for (unsigned int i=0; i<chunkTypes_arraysize; i++)
        this->chunkTypes[i] = other.chunkTypes[i];
}

void SCTPSupportedExtensionsParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    b->pack(chunkTypes_arraysize);
    doParsimArrayPacking(b,this->chunkTypes,chunkTypes_arraysize);
}

void SCTPSupportedExtensionsParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    delete [] this->chunkTypes;
    b->unpack(chunkTypes_arraysize);
    if (chunkTypes_arraysize==0) {
        this->chunkTypes = 0;
    } else {
        this->chunkTypes = new uint16_t[chunkTypes_arraysize];
        doParsimArrayUnpacking(b,this->chunkTypes,chunkTypes_arraysize);
    }
}

void SCTPSupportedExtensionsParameter::setChunkTypesArraySize(unsigned int size)
{
    uint16_t *chunkTypes2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = chunkTypes_arraysize < size ? chunkTypes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        chunkTypes2[i] = this->chunkTypes[i];
    for (unsigned int i=sz; i<size; i++)
        chunkTypes2[i] = 0;
    chunkTypes_arraysize = size;
    delete [] this->chunkTypes;
    this->chunkTypes = chunkTypes2;
}

unsigned int SCTPSupportedExtensionsParameter::getChunkTypesArraySize() const
{
    return chunkTypes_arraysize;
}

uint16_t SCTPSupportedExtensionsParameter::getChunkTypes(unsigned int k) const
{
    if (k>=chunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", chunkTypes_arraysize, k);
    return this->chunkTypes[k];
}

void SCTPSupportedExtensionsParameter::setChunkTypes(unsigned int k, uint16_t chunkTypes)
{
    if (k>=chunkTypes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", chunkTypes_arraysize, k);
    this->chunkTypes[k] = chunkTypes;
}

class SCTPSupportedExtensionsParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSupportedExtensionsParameterDescriptor();
    virtual ~SCTPSupportedExtensionsParameterDescriptor();

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

Register_ClassDescriptor(SCTPSupportedExtensionsParameterDescriptor)

SCTPSupportedExtensionsParameterDescriptor::SCTPSupportedExtensionsParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPSupportedExtensionsParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPSupportedExtensionsParameterDescriptor::~SCTPSupportedExtensionsParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPSupportedExtensionsParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSupportedExtensionsParameter *>(obj)!=nullptr;
}

const char **SCTPSupportedExtensionsParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSupportedExtensionsParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSupportedExtensionsParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPSupportedExtensionsParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPSupportedExtensionsParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "chunkTypes",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPSupportedExtensionsParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "chunkTypes")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSupportedExtensionsParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSupportedExtensionsParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSupportedExtensionsParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSupportedExtensionsParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSupportedExtensionsParameter *pp = (SCTPSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        case 0: return pp->getChunkTypesArraySize();
        default: return 0;
    }
}

const char *SCTPSupportedExtensionsParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSupportedExtensionsParameter *pp = (SCTPSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSupportedExtensionsParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSupportedExtensionsParameter *pp = (SCTPSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getChunkTypes(i));
        default: return "";
    }
}

bool SCTPSupportedExtensionsParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSupportedExtensionsParameter *pp = (SCTPSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setChunkTypes(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPSupportedExtensionsParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPSupportedExtensionsParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSupportedExtensionsParameter *pp = (SCTPSupportedExtensionsParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPErrorCauseParameter)

SCTPErrorCauseParameter::SCTPErrorCauseParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->responseCorrelationId = 0;
    this->errorCauseType = 0;
}

SCTPErrorCauseParameter::SCTPErrorCauseParameter(const SCTPErrorCauseParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPErrorCauseParameter::~SCTPErrorCauseParameter()
{
}

SCTPErrorCauseParameter& SCTPErrorCauseParameter::operator=(const SCTPErrorCauseParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPErrorCauseParameter::copy(const SCTPErrorCauseParameter& other)
{
    this->responseCorrelationId = other.responseCorrelationId;
    this->errorCauseType = other.errorCauseType;
}

void SCTPErrorCauseParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->responseCorrelationId);
    doParsimPacking(b,this->errorCauseType);
}

void SCTPErrorCauseParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->responseCorrelationId);
    doParsimUnpacking(b,this->errorCauseType);
}

uint32_t SCTPErrorCauseParameter::getResponseCorrelationId() const
{
    return this->responseCorrelationId;
}

void SCTPErrorCauseParameter::setResponseCorrelationId(uint32_t responseCorrelationId)
{
    this->responseCorrelationId = responseCorrelationId;
}

uint32_t SCTPErrorCauseParameter::getErrorCauseType() const
{
    return this->errorCauseType;
}

void SCTPErrorCauseParameter::setErrorCauseType(uint32_t errorCauseType)
{
    this->errorCauseType = errorCauseType;
}

class SCTPErrorCauseParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPErrorCauseParameterDescriptor();
    virtual ~SCTPErrorCauseParameterDescriptor();

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

Register_ClassDescriptor(SCTPErrorCauseParameterDescriptor)

SCTPErrorCauseParameterDescriptor::SCTPErrorCauseParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPErrorCauseParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPErrorCauseParameterDescriptor::~SCTPErrorCauseParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPErrorCauseParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPErrorCauseParameter *>(obj)!=nullptr;
}

const char **SCTPErrorCauseParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPErrorCauseParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPErrorCauseParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SCTPErrorCauseParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPErrorCauseParameterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "responseCorrelationId",
        "errorCauseType",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SCTPErrorCauseParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "responseCorrelationId")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorCauseType")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPErrorCauseParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "uint32",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPErrorCauseParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPErrorCauseParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPErrorCauseParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorCauseParameter *pp = (SCTPErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPErrorCauseParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorCauseParameter *pp = (SCTPErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPErrorCauseParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorCauseParameter *pp = (SCTPErrorCauseParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getResponseCorrelationId());
        case 1: return ulong2string(pp->getErrorCauseType());
        default: return "";
    }
}

bool SCTPErrorCauseParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorCauseParameter *pp = (SCTPErrorCauseParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setResponseCorrelationId(string2ulong(value)); return true;
        case 1: pp->setErrorCauseType(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPErrorCauseParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPErrorCauseParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorCauseParameter *pp = (SCTPErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPSimpleErrorCauseParameter)

SCTPSimpleErrorCauseParameter::SCTPSimpleErrorCauseParameter(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->value = 0;
}

SCTPSimpleErrorCauseParameter::SCTPSimpleErrorCauseParameter(const SCTPSimpleErrorCauseParameter& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPSimpleErrorCauseParameter::~SCTPSimpleErrorCauseParameter()
{
}

SCTPSimpleErrorCauseParameter& SCTPSimpleErrorCauseParameter::operator=(const SCTPSimpleErrorCauseParameter& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPSimpleErrorCauseParameter::copy(const SCTPSimpleErrorCauseParameter& other)
{
    this->value = other.value;
}

void SCTPSimpleErrorCauseParameter::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->value);
}

void SCTPSimpleErrorCauseParameter::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->value);
}

uint16_t SCTPSimpleErrorCauseParameter::getValue() const
{
    return this->value;
}

void SCTPSimpleErrorCauseParameter::setValue(uint16_t value)
{
    this->value = value;
}

class SCTPSimpleErrorCauseParameterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSimpleErrorCauseParameterDescriptor();
    virtual ~SCTPSimpleErrorCauseParameterDescriptor();

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

Register_ClassDescriptor(SCTPSimpleErrorCauseParameterDescriptor)

SCTPSimpleErrorCauseParameterDescriptor::SCTPSimpleErrorCauseParameterDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPSimpleErrorCauseParameter", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPSimpleErrorCauseParameterDescriptor::~SCTPSimpleErrorCauseParameterDescriptor()
{
    delete[] propertynames;
}

bool SCTPSimpleErrorCauseParameterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSimpleErrorCauseParameter *>(obj)!=nullptr;
}

const char **SCTPSimpleErrorCauseParameterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSimpleErrorCauseParameterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSimpleErrorCauseParameterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPSimpleErrorCauseParameterDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPSimpleErrorCauseParameterDescriptor::getFieldName(int field) const
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

int SCTPSimpleErrorCauseParameterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "value")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSimpleErrorCauseParameterDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSimpleErrorCauseParameterDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSimpleErrorCauseParameterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSimpleErrorCauseParameterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleErrorCauseParameter *pp = (SCTPSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPSimpleErrorCauseParameterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleErrorCauseParameter *pp = (SCTPSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSimpleErrorCauseParameterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleErrorCauseParameter *pp = (SCTPSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getValue());
        default: return "";
    }
}

bool SCTPSimpleErrorCauseParameterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleErrorCauseParameter *pp = (SCTPSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        case 0: pp->setValue(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPSimpleErrorCauseParameterDescriptor::getFieldStructName(int field) const
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

void *SCTPSimpleErrorCauseParameterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleErrorCauseParameter *pp = (SCTPSimpleErrorCauseParameter *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPSuccessIndication)

SCTPSuccessIndication::SCTPSuccessIndication(const char *name, short kind) : ::inet::sctp::SCTPParameter(name,kind)
{
    this->responseCorrelationId = 0;
}

SCTPSuccessIndication::SCTPSuccessIndication(const SCTPSuccessIndication& other) : ::inet::sctp::SCTPParameter(other)
{
    copy(other);
}

SCTPSuccessIndication::~SCTPSuccessIndication()
{
}

SCTPSuccessIndication& SCTPSuccessIndication::operator=(const SCTPSuccessIndication& other)
{
    if (this==&other) return *this;
    ::inet::sctp::SCTPParameter::operator=(other);
    copy(other);
    return *this;
}

void SCTPSuccessIndication::copy(const SCTPSuccessIndication& other)
{
    this->responseCorrelationId = other.responseCorrelationId;
}

void SCTPSuccessIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::sctp::SCTPParameter::parsimPack(b);
    doParsimPacking(b,this->responseCorrelationId);
}

void SCTPSuccessIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::sctp::SCTPParameter::parsimUnpack(b);
    doParsimUnpacking(b,this->responseCorrelationId);
}

uint32_t SCTPSuccessIndication::getResponseCorrelationId() const
{
    return this->responseCorrelationId;
}

void SCTPSuccessIndication::setResponseCorrelationId(uint32_t responseCorrelationId)
{
    this->responseCorrelationId = responseCorrelationId;
}

class SCTPSuccessIndicationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSuccessIndicationDescriptor();
    virtual ~SCTPSuccessIndicationDescriptor();

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

Register_ClassDescriptor(SCTPSuccessIndicationDescriptor)

SCTPSuccessIndicationDescriptor::SCTPSuccessIndicationDescriptor() : omnetpp::cClassDescriptor("inet::sctp::SCTPSuccessIndication", "inet::sctp::SCTPParameter")
{
    propertynames = nullptr;
}

SCTPSuccessIndicationDescriptor::~SCTPSuccessIndicationDescriptor()
{
    delete[] propertynames;
}

bool SCTPSuccessIndicationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSuccessIndication *>(obj)!=nullptr;
}

const char **SCTPSuccessIndicationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSuccessIndicationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSuccessIndicationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPSuccessIndicationDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPSuccessIndicationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "responseCorrelationId",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPSuccessIndicationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "responseCorrelationId")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSuccessIndicationDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSuccessIndicationDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSuccessIndicationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSuccessIndicationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSuccessIndication *pp = (SCTPSuccessIndication *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPSuccessIndicationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSuccessIndication *pp = (SCTPSuccessIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSuccessIndicationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSuccessIndication *pp = (SCTPSuccessIndication *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getResponseCorrelationId());
        default: return "";
    }
}

bool SCTPSuccessIndicationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSuccessIndication *pp = (SCTPSuccessIndication *)object; (void)pp;
    switch (field) {
        case 0: pp->setResponseCorrelationId(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPSuccessIndicationDescriptor::getFieldStructName(int field) const
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

void *SCTPSuccessIndicationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSuccessIndication *pp = (SCTPSuccessIndication *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(NatMessage)

NatMessage::NatMessage(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->multi = false;
    this->peer1 = 0;
    peer1Addresses_arraysize = 0;
    this->peer1Addresses = 0;
    this->portPeer1 = 0;
    this->peer2 = 0;
    peer2Addresses_arraysize = 0;
    this->peer2Addresses = 0;
    this->portPeer2 = 0;
}

NatMessage::NatMessage(const NatMessage& other) : ::omnetpp::cPacket(other)
{
    peer1Addresses_arraysize = 0;
    this->peer1Addresses = 0;
    peer2Addresses_arraysize = 0;
    this->peer2Addresses = 0;
    copy(other);
}

NatMessage::~NatMessage()
{
    delete [] this->peer1Addresses;
    delete [] this->peer2Addresses;
}

NatMessage& NatMessage::operator=(const NatMessage& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void NatMessage::copy(const NatMessage& other)
{
    this->multi = other.multi;
    this->peer1 = other.peer1;
    delete [] this->peer1Addresses;
    this->peer1Addresses = (other.peer1Addresses_arraysize==0) ? nullptr : new L3Address[other.peer1Addresses_arraysize];
    peer1Addresses_arraysize = other.peer1Addresses_arraysize;
    for (unsigned int i=0; i<peer1Addresses_arraysize; i++)
        this->peer1Addresses[i] = other.peer1Addresses[i];
    this->portPeer1 = other.portPeer1;
    this->peer2 = other.peer2;
    delete [] this->peer2Addresses;
    this->peer2Addresses = (other.peer2Addresses_arraysize==0) ? nullptr : new L3Address[other.peer2Addresses_arraysize];
    peer2Addresses_arraysize = other.peer2Addresses_arraysize;
    for (unsigned int i=0; i<peer2Addresses_arraysize; i++)
        this->peer2Addresses[i] = other.peer2Addresses[i];
    this->portPeer2 = other.portPeer2;
}

void NatMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->multi);
    doParsimPacking(b,this->peer1);
    b->pack(peer1Addresses_arraysize);
    doParsimArrayPacking(b,this->peer1Addresses,peer1Addresses_arraysize);
    doParsimPacking(b,this->portPeer1);
    doParsimPacking(b,this->peer2);
    b->pack(peer2Addresses_arraysize);
    doParsimArrayPacking(b,this->peer2Addresses,peer2Addresses_arraysize);
    doParsimPacking(b,this->portPeer2);
}

void NatMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->multi);
    doParsimUnpacking(b,this->peer1);
    delete [] this->peer1Addresses;
    b->unpack(peer1Addresses_arraysize);
    if (peer1Addresses_arraysize==0) {
        this->peer1Addresses = 0;
    } else {
        this->peer1Addresses = new L3Address[peer1Addresses_arraysize];
        doParsimArrayUnpacking(b,this->peer1Addresses,peer1Addresses_arraysize);
    }
    doParsimUnpacking(b,this->portPeer1);
    doParsimUnpacking(b,this->peer2);
    delete [] this->peer2Addresses;
    b->unpack(peer2Addresses_arraysize);
    if (peer2Addresses_arraysize==0) {
        this->peer2Addresses = 0;
    } else {
        this->peer2Addresses = new L3Address[peer2Addresses_arraysize];
        doParsimArrayUnpacking(b,this->peer2Addresses,peer2Addresses_arraysize);
    }
    doParsimUnpacking(b,this->portPeer2);
}

bool NatMessage::getMulti() const
{
    return this->multi;
}

void NatMessage::setMulti(bool multi)
{
    this->multi = multi;
}

uint16_t NatMessage::getPeer1() const
{
    return this->peer1;
}

void NatMessage::setPeer1(uint16_t peer1)
{
    this->peer1 = peer1;
}

void NatMessage::setPeer1AddressesArraySize(unsigned int size)
{
    L3Address *peer1Addresses2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = peer1Addresses_arraysize < size ? peer1Addresses_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        peer1Addresses2[i] = this->peer1Addresses[i];
    peer1Addresses_arraysize = size;
    delete [] this->peer1Addresses;
    this->peer1Addresses = peer1Addresses2;
}

unsigned int NatMessage::getPeer1AddressesArraySize() const
{
    return peer1Addresses_arraysize;
}

L3Address& NatMessage::getPeer1Addresses(unsigned int k)
{
    if (k>=peer1Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", peer1Addresses_arraysize, k);
    return this->peer1Addresses[k];
}

void NatMessage::setPeer1Addresses(unsigned int k, const L3Address& peer1Addresses)
{
    if (k>=peer1Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", peer1Addresses_arraysize, k);
    this->peer1Addresses[k] = peer1Addresses;
}

uint32_t NatMessage::getPortPeer1() const
{
    return this->portPeer1;
}

void NatMessage::setPortPeer1(uint32_t portPeer1)
{
    this->portPeer1 = portPeer1;
}

uint16_t NatMessage::getPeer2() const
{
    return this->peer2;
}

void NatMessage::setPeer2(uint16_t peer2)
{
    this->peer2 = peer2;
}

void NatMessage::setPeer2AddressesArraySize(unsigned int size)
{
    L3Address *peer2Addresses2 = (size==0) ? nullptr : new L3Address[size];
    unsigned int sz = peer2Addresses_arraysize < size ? peer2Addresses_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        peer2Addresses2[i] = this->peer2Addresses[i];
    peer2Addresses_arraysize = size;
    delete [] this->peer2Addresses;
    this->peer2Addresses = peer2Addresses2;
}

unsigned int NatMessage::getPeer2AddressesArraySize() const
{
    return peer2Addresses_arraysize;
}

L3Address& NatMessage::getPeer2Addresses(unsigned int k)
{
    if (k>=peer2Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", peer2Addresses_arraysize, k);
    return this->peer2Addresses[k];
}

void NatMessage::setPeer2Addresses(unsigned int k, const L3Address& peer2Addresses)
{
    if (k>=peer2Addresses_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", peer2Addresses_arraysize, k);
    this->peer2Addresses[k] = peer2Addresses;
}

uint32_t NatMessage::getPortPeer2() const
{
    return this->portPeer2;
}

void NatMessage::setPortPeer2(uint32_t portPeer2)
{
    this->portPeer2 = portPeer2;
}

class NatMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    NatMessageDescriptor();
    virtual ~NatMessageDescriptor();

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

Register_ClassDescriptor(NatMessageDescriptor)

NatMessageDescriptor::NatMessageDescriptor() : omnetpp::cClassDescriptor("inet::sctp::NatMessage", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

NatMessageDescriptor::~NatMessageDescriptor()
{
    delete[] propertynames;
}

bool NatMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<NatMessage *>(obj)!=nullptr;
}

const char **NatMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *NatMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int NatMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int NatMessageDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *NatMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "multi",
        "peer1",
        "peer1Addresses",
        "portPeer1",
        "peer2",
        "peer2Addresses",
        "portPeer2",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int NatMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multi")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "peer1")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "peer1Addresses")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "portPeer1")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "peer2")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "peer2Addresses")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "portPeer2")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *NatMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bool",
        "uint16",
        "L3Address",
        "uint32",
        "uint16",
        "L3Address",
        "uint32",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **NatMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *NatMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int NatMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        case 2: return pp->getPeer1AddressesArraySize();
        case 5: return pp->getPeer2AddressesArraySize();
        default: return 0;
    }
}

const char *NatMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string NatMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getMulti());
        case 1: return ulong2string(pp->getPeer1());
        case 2: {std::stringstream out; out << pp->getPeer1Addresses(i); return out.str();}
        case 3: return ulong2string(pp->getPortPeer1());
        case 4: return ulong2string(pp->getPeer2());
        case 5: {std::stringstream out; out << pp->getPeer2Addresses(i); return out.str();}
        case 6: return ulong2string(pp->getPortPeer2());
        default: return "";
    }
}

bool NatMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setMulti(string2bool(value)); return true;
        case 1: pp->setPeer1(string2ulong(value)); return true;
        case 3: pp->setPortPeer1(string2ulong(value)); return true;
        case 4: pp->setPeer2(string2ulong(value)); return true;
        case 6: pp->setPortPeer2(string2ulong(value)); return true;
        default: return false;
    }
}

const char *NatMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        case 5: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *NatMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    NatMessage *pp = (NatMessage *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getPeer1Addresses(i)); break;
        case 5: return (void *)(&pp->getPeer2Addresses(i)); break;
        default: return nullptr;
    }
}

} // namespace sctp
} // namespace inet

