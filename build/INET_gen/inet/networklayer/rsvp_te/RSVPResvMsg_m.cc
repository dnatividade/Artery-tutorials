//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/rsvp_te/RSVPResvMsg.msg.
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
#include "RSVPResvMsg_m.h"

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

RSVPResvMsg_Base::RSVPResvMsg_Base(const char *name, short kind) : ::inet::RSVPPacket(name,kind)
{
    this->setRsvpKind(RESV_MESSAGE);

}

RSVPResvMsg_Base::RSVPResvMsg_Base(const RSVPResvMsg_Base& other) : ::inet::RSVPPacket(other)
{
    copy(other);
}

RSVPResvMsg_Base::~RSVPResvMsg_Base()
{
}

RSVPResvMsg_Base& RSVPResvMsg_Base::operator=(const RSVPResvMsg_Base& other)
{
    if (this==&other) return *this;
    ::inet::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPResvMsg_Base::copy(const RSVPResvMsg_Base& other)
{
    this->hop = other.hop;
    this->flowDescriptor = other.flowDescriptor;
}

void RSVPResvMsg_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::RSVPPacket::parsimPack(b);
    doParsimPacking(b,this->hop);
    doParsimPacking(b,this->flowDescriptor);
}

void RSVPResvMsg_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::RSVPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->hop);
    doParsimUnpacking(b,this->flowDescriptor);
}

RsvpHopObj_t& RSVPResvMsg_Base::getHop()
{
    return this->hop;
}

void RSVPResvMsg_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop = hop;
}

FlowDescriptorVector& RSVPResvMsg_Base::getFlowDescriptor()
{
    return this->flowDescriptor;
}

void RSVPResvMsg_Base::setFlowDescriptor(const FlowDescriptorVector& flowDescriptor)
{
    this->flowDescriptor = flowDescriptor;
}

class RSVPResvMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RSVPResvMsgDescriptor();
    virtual ~RSVPResvMsgDescriptor();

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

Register_ClassDescriptor(RSVPResvMsgDescriptor)

RSVPResvMsgDescriptor::RSVPResvMsgDescriptor() : omnetpp::cClassDescriptor("inet::RSVPResvMsg", "inet::RSVPPacket")
{
    propertynames = nullptr;
}

RSVPResvMsgDescriptor::~RSVPResvMsgDescriptor()
{
    delete[] propertynames;
}

bool RSVPResvMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RSVPResvMsg_Base *>(obj)!=nullptr;
}

const char **RSVPResvMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RSVPResvMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RSVPResvMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RSVPResvMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *RSVPResvMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "hop",
        "flowDescriptor",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int RSVPResvMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flowDescriptor")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RSVPResvMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "FlowDescriptorVector",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **RSVPResvMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *RSVPResvMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RSVPResvMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RSVPResvMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RSVPResvMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: {std::stringstream out; out << pp->getFlowDescriptor(); return out.str();}
        default: return "";
    }
}

bool RSVPResvMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RSVPResvMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(RsvpHopObj_t));
        case 1: return omnetpp::opp_typename(typeid(FlowDescriptorVector));
        default: return nullptr;
    };
}

void *RSVPResvMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvMsg_Base *pp = (RSVPResvMsg_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 1: return (void *)(&pp->getFlowDescriptor()); break;
        default: return nullptr;
    }
}

RSVPResvTear_Base::RSVPResvTear_Base(const char *name, short kind) : ::inet::RSVPPacket(name,kind)
{
    this->setRsvpKind(RTEAR_MESSAGE);

}

RSVPResvTear_Base::RSVPResvTear_Base(const RSVPResvTear_Base& other) : ::inet::RSVPPacket(other)
{
    copy(other);
}

RSVPResvTear_Base::~RSVPResvTear_Base()
{
}

RSVPResvTear_Base& RSVPResvTear_Base::operator=(const RSVPResvTear_Base& other)
{
    if (this==&other) return *this;
    ::inet::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPResvTear_Base::copy(const RSVPResvTear_Base& other)
{
    this->hop = other.hop;
    this->flowDescriptor = other.flowDescriptor;
}

void RSVPResvTear_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::RSVPPacket::parsimPack(b);
    doParsimPacking(b,this->hop);
    doParsimPacking(b,this->flowDescriptor);
}

void RSVPResvTear_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::RSVPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->hop);
    doParsimUnpacking(b,this->flowDescriptor);
}

RsvpHopObj_t& RSVPResvTear_Base::getHop()
{
    return this->hop;
}

void RSVPResvTear_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop = hop;
}

FlowDescriptorVector& RSVPResvTear_Base::getFlowDescriptor()
{
    return this->flowDescriptor;
}

void RSVPResvTear_Base::setFlowDescriptor(const FlowDescriptorVector& flowDescriptor)
{
    this->flowDescriptor = flowDescriptor;
}

class RSVPResvTearDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RSVPResvTearDescriptor();
    virtual ~RSVPResvTearDescriptor();

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

Register_ClassDescriptor(RSVPResvTearDescriptor)

RSVPResvTearDescriptor::RSVPResvTearDescriptor() : omnetpp::cClassDescriptor("inet::RSVPResvTear", "inet::RSVPPacket")
{
    propertynames = nullptr;
}

RSVPResvTearDescriptor::~RSVPResvTearDescriptor()
{
    delete[] propertynames;
}

bool RSVPResvTearDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RSVPResvTear_Base *>(obj)!=nullptr;
}

const char **RSVPResvTearDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RSVPResvTearDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RSVPResvTearDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RSVPResvTearDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *RSVPResvTearDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "hop",
        "flowDescriptor",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int RSVPResvTearDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "flowDescriptor")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RSVPResvTearDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "FlowDescriptorVector",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **RSVPResvTearDescriptor::getFieldPropertyNames(int field) const
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

const char *RSVPResvTearDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RSVPResvTearDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RSVPResvTearDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RSVPResvTearDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: {std::stringstream out; out << pp->getFlowDescriptor(); return out.str();}
        default: return "";
    }
}

bool RSVPResvTearDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RSVPResvTearDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(RsvpHopObj_t));
        case 1: return omnetpp::opp_typename(typeid(FlowDescriptorVector));
        default: return nullptr;
    };
}

void *RSVPResvTearDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvTear_Base *pp = (RSVPResvTear_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 1: return (void *)(&pp->getFlowDescriptor()); break;
        default: return nullptr;
    }
}

RSVPResvError_Base::RSVPResvError_Base(const char *name, short kind) : ::inet::RSVPPacket(name,kind)
{
    this->setRsvpKind(RERROR_MESSAGE);

    this->errorCode = 0;
}

RSVPResvError_Base::RSVPResvError_Base(const RSVPResvError_Base& other) : ::inet::RSVPPacket(other)
{
    copy(other);
}

RSVPResvError_Base::~RSVPResvError_Base()
{
}

RSVPResvError_Base& RSVPResvError_Base::operator=(const RSVPResvError_Base& other)
{
    if (this==&other) return *this;
    ::inet::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPResvError_Base::copy(const RSVPResvError_Base& other)
{
    this->hop = other.hop;
    this->errorNode = other.errorNode;
    this->errorCode = other.errorCode;
}

void RSVPResvError_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::RSVPPacket::parsimPack(b);
    doParsimPacking(b,this->hop);
    doParsimPacking(b,this->errorNode);
    doParsimPacking(b,this->errorCode);
}

void RSVPResvError_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::RSVPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->hop);
    doParsimUnpacking(b,this->errorNode);
    doParsimUnpacking(b,this->errorCode);
}

RsvpHopObj_t& RSVPResvError_Base::getHop()
{
    return this->hop;
}

void RSVPResvError_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop = hop;
}

IPv4Address& RSVPResvError_Base::getErrorNode()
{
    return this->errorNode;
}

void RSVPResvError_Base::setErrorNode(const IPv4Address& errorNode)
{
    this->errorNode = errorNode;
}

int RSVPResvError_Base::getErrorCode() const
{
    return this->errorCode;
}

void RSVPResvError_Base::setErrorCode(int errorCode)
{
    this->errorCode = errorCode;
}

class RSVPResvErrorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RSVPResvErrorDescriptor();
    virtual ~RSVPResvErrorDescriptor();

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

Register_ClassDescriptor(RSVPResvErrorDescriptor)

RSVPResvErrorDescriptor::RSVPResvErrorDescriptor() : omnetpp::cClassDescriptor("inet::RSVPResvError", "inet::RSVPPacket")
{
    propertynames = nullptr;
}

RSVPResvErrorDescriptor::~RSVPResvErrorDescriptor()
{
    delete[] propertynames;
}

bool RSVPResvErrorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RSVPResvError_Base *>(obj)!=nullptr;
}

const char **RSVPResvErrorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RSVPResvErrorDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RSVPResvErrorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int RSVPResvErrorDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *RSVPResvErrorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "hop",
        "errorNode",
        "errorCode",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int RSVPResvErrorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorNode")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorCode")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RSVPResvErrorDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "IPv4Address",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **RSVPResvErrorDescriptor::getFieldPropertyNames(int field) const
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

const char *RSVPResvErrorDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RSVPResvErrorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RSVPResvErrorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RSVPResvErrorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: {std::stringstream out; out << pp->getErrorNode(); return out.str();}
        case 2: return long2string(pp->getErrorCode());
        default: return "";
    }
}

bool RSVPResvErrorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        case 2: pp->setErrorCode(string2long(value)); return true;
        default: return false;
    }
}

const char *RSVPResvErrorDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(RsvpHopObj_t));
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *RSVPResvErrorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RSVPResvError_Base *pp = (RSVPResvError_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 1: return (void *)(&pp->getErrorNode()); break;
        default: return nullptr;
    }
}

} // namespace inet

