//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/ted/TED.msg.
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
#include "TED_m.h"

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

TELinkStateInfo::TELinkStateInfo()
{
    this->metric = 0;
    this->MaxBandwidth = 0;
    for (unsigned int i=0; i<8; i++)
        this->UnResvBandwidth[i] = 0;
    this->timestamp = 0;
    this->sourceId = 0;
    this->messageId = 0;
    this->state = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const TELinkStateInfo& a)
{
    doParsimPacking(b,a.advrouter);
    doParsimPacking(b,a.linkid);
    doParsimPacking(b,a.local);
    doParsimPacking(b,a.remote);
    doParsimPacking(b,a.metric);
    doParsimPacking(b,a.MaxBandwidth);
    doParsimArrayPacking(b,a.UnResvBandwidth,8);
    doParsimPacking(b,a.timestamp);
    doParsimPacking(b,a.sourceId);
    doParsimPacking(b,a.messageId);
    doParsimPacking(b,a.state);
}

void __doUnpacking(omnetpp::cCommBuffer *b, TELinkStateInfo& a)
{
    doParsimUnpacking(b,a.advrouter);
    doParsimUnpacking(b,a.linkid);
    doParsimUnpacking(b,a.local);
    doParsimUnpacking(b,a.remote);
    doParsimUnpacking(b,a.metric);
    doParsimUnpacking(b,a.MaxBandwidth);
    doParsimArrayUnpacking(b,a.UnResvBandwidth,8);
    doParsimUnpacking(b,a.timestamp);
    doParsimUnpacking(b,a.sourceId);
    doParsimUnpacking(b,a.messageId);
    doParsimUnpacking(b,a.state);
}

class TELinkStateInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TELinkStateInfoDescriptor();
    virtual ~TELinkStateInfoDescriptor();

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

Register_ClassDescriptor(TELinkStateInfoDescriptor)

TELinkStateInfoDescriptor::TELinkStateInfoDescriptor() : omnetpp::cClassDescriptor("inet::TELinkStateInfo", "")
{
    propertynames = nullptr;
}

TELinkStateInfoDescriptor::~TELinkStateInfoDescriptor()
{
    delete[] propertynames;
}

bool TELinkStateInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TELinkStateInfo *>(obj)!=nullptr;
}

const char **TELinkStateInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TELinkStateInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TELinkStateInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int TELinkStateInfoDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *TELinkStateInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "advrouter",
        "linkid",
        "local",
        "remote",
        "metric",
        "MaxBandwidth",
        "UnResvBandwidth",
        "timestamp",
        "sourceId",
        "messageId",
        "state",
    };
    return (field>=0 && field<11) ? fieldNames[field] : nullptr;
}

int TELinkStateInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "advrouter")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkid")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "local")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "remote")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+4;
    if (fieldName[0]=='M' && strcmp(fieldName, "MaxBandwidth")==0) return base+5;
    if (fieldName[0]=='U' && strcmp(fieldName, "UnResvBandwidth")==0) return base+6;
    if (fieldName[0]=='t' && strcmp(fieldName, "timestamp")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceId")==0) return base+8;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageId")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "state")==0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TELinkStateInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "double",
        "double",
        "double",
        "simtime_t",
        "unsigned int",
        "unsigned int",
        "bool",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : nullptr;
}

const char **TELinkStateInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *TELinkStateInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TELinkStateInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TELinkStateInfo *pp = (TELinkStateInfo *)object; (void)pp;
    switch (field) {
        case 6: return 8;
        default: return 0;
    }
}

const char *TELinkStateInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TELinkStateInfo *pp = (TELinkStateInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TELinkStateInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TELinkStateInfo *pp = (TELinkStateInfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->advrouter; return out.str();}
        case 1: {std::stringstream out; out << pp->linkid; return out.str();}
        case 2: {std::stringstream out; out << pp->local; return out.str();}
        case 3: {std::stringstream out; out << pp->remote; return out.str();}
        case 4: return double2string(pp->metric);
        case 5: return double2string(pp->MaxBandwidth);
        case 6: if (i>=8) return "";
                return double2string(pp->UnResvBandwidth[i]);
        case 7: return simtime2string(pp->timestamp);
        case 8: return ulong2string(pp->sourceId);
        case 9: return ulong2string(pp->messageId);
        case 10: return bool2string(pp->state);
        default: return "";
    }
}

bool TELinkStateInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TELinkStateInfo *pp = (TELinkStateInfo *)object; (void)pp;
    switch (field) {
        case 4: pp->metric = string2double(value); return true;
        case 5: pp->MaxBandwidth = string2double(value); return true;
        case 6: if (i>=8) return false;
                pp->UnResvBandwidth[i] = string2double(value); return true;
        case 7: pp->timestamp = string2simtime(value); return true;
        case 8: pp->sourceId = string2ulong(value); return true;
        case 9: pp->messageId = string2ulong(value); return true;
        case 10: pp->state = string2bool(value); return true;
        default: return false;
    }
}

const char *TELinkStateInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *TELinkStateInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TELinkStateInfo *pp = (TELinkStateInfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->advrouter); break;
        case 1: return (void *)(&pp->linkid); break;
        case 2: return (void *)(&pp->local); break;
        case 3: return (void *)(&pp->remote); break;
        default: return nullptr;
    }
}

Register_Class(TEDChangeInfo)

TEDChangeInfo::TEDChangeInfo() : ::omnetpp::cObject()
{
    tedLinkIndices_arraysize = 0;
    this->tedLinkIndices = 0;
}

TEDChangeInfo::TEDChangeInfo(const TEDChangeInfo& other) : ::omnetpp::cObject(other)
{
    tedLinkIndices_arraysize = 0;
    this->tedLinkIndices = 0;
    copy(other);
}

TEDChangeInfo::~TEDChangeInfo()
{
    delete [] this->tedLinkIndices;
}

TEDChangeInfo& TEDChangeInfo::operator=(const TEDChangeInfo& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void TEDChangeInfo::copy(const TEDChangeInfo& other)
{
    delete [] this->tedLinkIndices;
    this->tedLinkIndices = (other.tedLinkIndices_arraysize==0) ? nullptr : new int[other.tedLinkIndices_arraysize];
    tedLinkIndices_arraysize = other.tedLinkIndices_arraysize;
    for (unsigned int i=0; i<tedLinkIndices_arraysize; i++)
        this->tedLinkIndices[i] = other.tedLinkIndices[i];
}

void TEDChangeInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    b->pack(tedLinkIndices_arraysize);
    doParsimArrayPacking(b,this->tedLinkIndices,tedLinkIndices_arraysize);
}

void TEDChangeInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    delete [] this->tedLinkIndices;
    b->unpack(tedLinkIndices_arraysize);
    if (tedLinkIndices_arraysize==0) {
        this->tedLinkIndices = 0;
    } else {
        this->tedLinkIndices = new int[tedLinkIndices_arraysize];
        doParsimArrayUnpacking(b,this->tedLinkIndices,tedLinkIndices_arraysize);
    }
}

void TEDChangeInfo::setTedLinkIndicesArraySize(unsigned int size)
{
    int *tedLinkIndices2 = (size==0) ? nullptr : new int[size];
    unsigned int sz = tedLinkIndices_arraysize < size ? tedLinkIndices_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        tedLinkIndices2[i] = this->tedLinkIndices[i];
    for (unsigned int i=sz; i<size; i++)
        tedLinkIndices2[i] = 0;
    tedLinkIndices_arraysize = size;
    delete [] this->tedLinkIndices;
    this->tedLinkIndices = tedLinkIndices2;
}

unsigned int TEDChangeInfo::getTedLinkIndicesArraySize() const
{
    return tedLinkIndices_arraysize;
}

int TEDChangeInfo::getTedLinkIndices(unsigned int k) const
{
    if (k>=tedLinkIndices_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", tedLinkIndices_arraysize, k);
    return this->tedLinkIndices[k];
}

void TEDChangeInfo::setTedLinkIndices(unsigned int k, int tedLinkIndices)
{
    if (k>=tedLinkIndices_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", tedLinkIndices_arraysize, k);
    this->tedLinkIndices[k] = tedLinkIndices;
}

class TEDChangeInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TEDChangeInfoDescriptor();
    virtual ~TEDChangeInfoDescriptor();

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

Register_ClassDescriptor(TEDChangeInfoDescriptor)

TEDChangeInfoDescriptor::TEDChangeInfoDescriptor() : omnetpp::cClassDescriptor("inet::TEDChangeInfo", "omnetpp::cObject")
{
    propertynames = nullptr;
}

TEDChangeInfoDescriptor::~TEDChangeInfoDescriptor()
{
    delete[] propertynames;
}

bool TEDChangeInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TEDChangeInfo *>(obj)!=nullptr;
}

const char **TEDChangeInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TEDChangeInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TEDChangeInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TEDChangeInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *TEDChangeInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tedLinkIndices",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int TEDChangeInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tedLinkIndices")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TEDChangeInfoDescriptor::getFieldTypeString(int field) const
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

const char **TEDChangeInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *TEDChangeInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TEDChangeInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TEDChangeInfo *pp = (TEDChangeInfo *)object; (void)pp;
    switch (field) {
        case 0: return pp->getTedLinkIndicesArraySize();
        default: return 0;
    }
}

const char *TEDChangeInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TEDChangeInfo *pp = (TEDChangeInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TEDChangeInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TEDChangeInfo *pp = (TEDChangeInfo *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTedLinkIndices(i));
        default: return "";
    }
}

bool TEDChangeInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TEDChangeInfo *pp = (TEDChangeInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setTedLinkIndices(i,string2long(value)); return true;
        default: return false;
    }
}

const char *TEDChangeInfoDescriptor::getFieldStructName(int field) const
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

void *TEDChangeInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TEDChangeInfo *pp = (TEDChangeInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

