//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/routing/rip/RIPPacket.msg.
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
#include "RIPPacket_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::RIPCommand");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::RIPCommand"));
    e->insert(RIP_REQUEST, "RIP_REQUEST");
    e->insert(RIP_RESPONSE, "RIP_RESPONSE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::RIP_AF");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::RIP_AF"));
    e->insert(RIP_AF_NONE, "RIP_AF_NONE");
    e->insert(RIP_AF_INET, "RIP_AF_INET");
)

RIPEntry::RIPEntry()
{
    this->addressFamilyId = 0;
    this->routeTag = 0;
    this->prefixLength = 0;
    this->metric = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const RIPEntry& a)
{
    doParsimPacking(b,a.addressFamilyId);
    doParsimPacking(b,a.routeTag);
    doParsimPacking(b,a.address);
    doParsimPacking(b,a.prefixLength);
    doParsimPacking(b,a.nextHop);
    doParsimPacking(b,a.metric);
}

void __doUnpacking(omnetpp::cCommBuffer *b, RIPEntry& a)
{
    doParsimUnpacking(b,a.addressFamilyId);
    doParsimUnpacking(b,a.routeTag);
    doParsimUnpacking(b,a.address);
    doParsimUnpacking(b,a.prefixLength);
    doParsimUnpacking(b,a.nextHop);
    doParsimUnpacking(b,a.metric);
}

class RIPEntryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RIPEntryDescriptor();
    virtual ~RIPEntryDescriptor();

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

Register_ClassDescriptor(RIPEntryDescriptor)

RIPEntryDescriptor::RIPEntryDescriptor() : omnetpp::cClassDescriptor("inet::RIPEntry", "")
{
    propertynames = nullptr;
}

RIPEntryDescriptor::~RIPEntryDescriptor()
{
    delete[] propertynames;
}

bool RIPEntryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RIPEntry *>(obj)!=nullptr;
}

const char **RIPEntryDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RIPEntryDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RIPEntryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int RIPEntryDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *RIPEntryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "addressFamilyId",
        "routeTag",
        "address",
        "prefixLength",
        "nextHop",
        "metric",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int RIPEntryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "addressFamilyId")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routeTag")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "address")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "prefixLength")==0) return base+3;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHop")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RIPEntryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned short",
        "L3Address",
        "int",
        "L3Address",
        "unsigned int",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **RIPEntryDescriptor::getFieldPropertyNames(int field) const
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

const char *RIPEntryDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::RIP_AF";
            return nullptr;
        default: return nullptr;
    }
}

int RIPEntryDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RIPEntry *pp = (RIPEntry *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RIPEntryDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RIPEntry *pp = (RIPEntry *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RIPEntryDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RIPEntry *pp = (RIPEntry *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->addressFamilyId, "inet::RIP_AF");
        case 1: return ulong2string(pp->routeTag);
        case 2: {std::stringstream out; out << pp->address; return out.str();}
        case 3: return long2string(pp->prefixLength);
        case 4: {std::stringstream out; out << pp->nextHop; return out.str();}
        case 5: return ulong2string(pp->metric);
        default: return "";
    }
}

bool RIPEntryDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RIPEntry *pp = (RIPEntry *)object; (void)pp;
    switch (field) {
        case 0: pp->addressFamilyId = (inet::RIP_AF)string2enum(value, "inet::RIP_AF"); return true;
        case 1: pp->routeTag = string2ulong(value); return true;
        case 3: pp->prefixLength = string2long(value); return true;
        case 5: pp->metric = string2ulong(value); return true;
        default: return false;
    }
}

const char *RIPEntryDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        case 4: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *RIPEntryDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RIPEntry *pp = (RIPEntry *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->address); break;
        case 4: return (void *)(&pp->nextHop); break;
        default: return nullptr;
    }
}

Register_Class(RIPPacket)

RIPPacket::RIPPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->command = 0;
    entry_arraysize = 0;
    this->entry = 0;
}

RIPPacket::RIPPacket(const RIPPacket& other) : ::omnetpp::cPacket(other)
{
    entry_arraysize = 0;
    this->entry = 0;
    copy(other);
}

RIPPacket::~RIPPacket()
{
    delete [] this->entry;
}

RIPPacket& RIPPacket::operator=(const RIPPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RIPPacket::copy(const RIPPacket& other)
{
    this->command = other.command;
    delete [] this->entry;
    this->entry = (other.entry_arraysize==0) ? nullptr : new RIPEntry[other.entry_arraysize];
    entry_arraysize = other.entry_arraysize;
    for (unsigned int i=0; i<entry_arraysize; i++)
        this->entry[i] = other.entry[i];
}

void RIPPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->command);
    b->pack(entry_arraysize);
    doParsimArrayPacking(b,this->entry,entry_arraysize);
}

void RIPPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->command);
    delete [] this->entry;
    b->unpack(entry_arraysize);
    if (entry_arraysize==0) {
        this->entry = 0;
    } else {
        this->entry = new RIPEntry[entry_arraysize];
        doParsimArrayUnpacking(b,this->entry,entry_arraysize);
    }
}

unsigned char RIPPacket::getCommand() const
{
    return this->command;
}

void RIPPacket::setCommand(unsigned char command)
{
    this->command = command;
}

void RIPPacket::setEntryArraySize(unsigned int size)
{
    RIPEntry *entry2 = (size==0) ? nullptr : new RIPEntry[size];
    unsigned int sz = entry_arraysize < size ? entry_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        entry2[i] = this->entry[i];
    entry_arraysize = size;
    delete [] this->entry;
    this->entry = entry2;
}

unsigned int RIPPacket::getEntryArraySize() const
{
    return entry_arraysize;
}

RIPEntry& RIPPacket::getEntry(unsigned int k)
{
    if (k>=entry_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", entry_arraysize, k);
    return this->entry[k];
}

void RIPPacket::setEntry(unsigned int k, const RIPEntry& entry)
{
    if (k>=entry_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", entry_arraysize, k);
    this->entry[k] = entry;
}

class RIPPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RIPPacketDescriptor();
    virtual ~RIPPacketDescriptor();

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

Register_ClassDescriptor(RIPPacketDescriptor)

RIPPacketDescriptor::RIPPacketDescriptor() : omnetpp::cClassDescriptor("inet::RIPPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

RIPPacketDescriptor::~RIPPacketDescriptor()
{
    delete[] propertynames;
}

bool RIPPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RIPPacket *>(obj)!=nullptr;
}

const char **RIPPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RIPPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RIPPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RIPPacketDescriptor::getFieldTypeFlags(int field) const
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

const char *RIPPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "command",
        "entry",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int RIPPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "command")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "entry")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RIPPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "RIPEntry",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **RIPPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RIPPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::RIPCommand";
            return nullptr;
        default: return nullptr;
    }
}

int RIPPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        case 1: return pp->getEntryArraySize();
        default: return 0;
    }
}

const char *RIPPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RIPPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getCommand(), "inet::RIPCommand");
        case 1: {std::stringstream out; out << pp->getEntry(i); return out.str();}
        default: return "";
    }
}

bool RIPPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setCommand((inet::RIPCommand)string2enum(value, "inet::RIPCommand")); return true;
        default: return false;
    }
}

const char *RIPPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(RIPEntry));
        default: return nullptr;
    };
}

void *RIPPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RIPPacket *pp = (RIPPacket *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getEntry(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

