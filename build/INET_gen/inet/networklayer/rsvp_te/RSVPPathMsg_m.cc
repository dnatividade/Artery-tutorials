//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/rsvp_te/RSVPPathMsg.msg.
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
#include "RSVPPathMsg_m.h"

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

RSVPPathMsg_Base::RSVPPathMsg_Base(const char *name, short kind) : ::inet::RSVPPacket(name,kind)
{
    this->setRsvpKind(PATH_MESSAGE);

    this->color = 0;
}

RSVPPathMsg_Base::RSVPPathMsg_Base(const RSVPPathMsg_Base& other) : ::inet::RSVPPacket(other)
{
    copy(other);
}

RSVPPathMsg_Base::~RSVPPathMsg_Base()
{
}

RSVPPathMsg_Base& RSVPPathMsg_Base::operator=(const RSVPPathMsg_Base& other)
{
    if (this==&other) return *this;
    ::inet::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPPathMsg_Base::copy(const RSVPPathMsg_Base& other)
{
    this->hop = other.hop;
    this->label_request = other.label_request;
    this->sender_descriptor = other.sender_descriptor;
    this->ERO = other.ERO;
    this->color = other.color;
}

void RSVPPathMsg_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::RSVPPacket::parsimPack(b);
    doParsimPacking(b,this->hop);
    doParsimPacking(b,this->label_request);
    doParsimPacking(b,this->sender_descriptor);
    doParsimPacking(b,this->ERO);
    doParsimPacking(b,this->color);
}

void RSVPPathMsg_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::RSVPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->hop);
    doParsimUnpacking(b,this->label_request);
    doParsimUnpacking(b,this->sender_descriptor);
    doParsimUnpacking(b,this->ERO);
    doParsimUnpacking(b,this->color);
}

RsvpHopObj_t& RSVPPathMsg_Base::getHop()
{
    return this->hop;
}

void RSVPPathMsg_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop = hop;
}

LabelRequestObj_t& RSVPPathMsg_Base::getLabel_request()
{
    return this->label_request;
}

void RSVPPathMsg_Base::setLabel_request(const LabelRequestObj_t& label_request)
{
    this->label_request = label_request;
}

SenderDescriptor_t& RSVPPathMsg_Base::getSender_descriptor()
{
    return this->sender_descriptor;
}

void RSVPPathMsg_Base::setSender_descriptor(const SenderDescriptor_t& sender_descriptor)
{
    this->sender_descriptor = sender_descriptor;
}

EroVector& RSVPPathMsg_Base::getERO()
{
    return this->ERO;
}

void RSVPPathMsg_Base::setERO(const EroVector& ERO)
{
    this->ERO = ERO;
}

int RSVPPathMsg_Base::getColor() const
{
    return this->color;
}

void RSVPPathMsg_Base::setColor(int color)
{
    this->color = color;
}

class RSVPPathMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RSVPPathMsgDescriptor();
    virtual ~RSVPPathMsgDescriptor();

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

Register_ClassDescriptor(RSVPPathMsgDescriptor)

RSVPPathMsgDescriptor::RSVPPathMsgDescriptor() : omnetpp::cClassDescriptor("inet::RSVPPathMsg", "inet::RSVPPacket")
{
    propertynames = nullptr;
}

RSVPPathMsgDescriptor::~RSVPPathMsgDescriptor()
{
    delete[] propertynames;
}

bool RSVPPathMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RSVPPathMsg_Base *>(obj)!=nullptr;
}

const char **RSVPPathMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RSVPPathMsgDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RSVPPathMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int RSVPPathMsgDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *RSVPPathMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "hop",
        "label_request",
        "sender_descriptor",
        "ERO",
        "color",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int RSVPPathMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "label_request")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sender_descriptor")==0) return base+2;
    if (fieldName[0]=='E' && strcmp(fieldName, "ERO")==0) return base+3;
    if (fieldName[0]=='c' && strcmp(fieldName, "color")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RSVPPathMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "LabelRequestObj_t",
        "SenderDescriptor_t",
        "EroVector",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **RSVPPathMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *RSVPPathMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RSVPPathMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RSVPPathMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RSVPPathMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: {std::stringstream out; out << pp->getLabel_request(); return out.str();}
        case 2: {std::stringstream out; out << pp->getSender_descriptor(); return out.str();}
        case 3: {std::stringstream out; out << pp->getERO(); return out.str();}
        case 4: return long2string(pp->getColor());
        default: return "";
    }
}

bool RSVPPathMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        case 4: pp->setColor(string2long(value)); return true;
        default: return false;
    }
}

const char *RSVPPathMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(RsvpHopObj_t));
        case 1: return omnetpp::opp_typename(typeid(LabelRequestObj_t));
        case 2: return omnetpp::opp_typename(typeid(SenderDescriptor_t));
        case 3: return omnetpp::opp_typename(typeid(EroVector));
        default: return nullptr;
    };
}

void *RSVPPathMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathMsg_Base *pp = (RSVPPathMsg_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 1: return (void *)(&pp->getLabel_request()); break;
        case 2: return (void *)(&pp->getSender_descriptor()); break;
        case 3: return (void *)(&pp->getERO()); break;
        default: return nullptr;
    }
}

RSVPPathTear_Base::RSVPPathTear_Base(const char *name, short kind) : ::inet::RSVPPacket(name,kind)
{
    this->setRsvpKind(PTEAR_MESSAGE);

    this->force = false;
}

RSVPPathTear_Base::RSVPPathTear_Base(const RSVPPathTear_Base& other) : ::inet::RSVPPacket(other)
{
    copy(other);
}

RSVPPathTear_Base::~RSVPPathTear_Base()
{
}

RSVPPathTear_Base& RSVPPathTear_Base::operator=(const RSVPPathTear_Base& other)
{
    if (this==&other) return *this;
    ::inet::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPPathTear_Base::copy(const RSVPPathTear_Base& other)
{
    this->hop = other.hop;
    this->senderTemplate = other.senderTemplate;
    this->force = other.force;
}

void RSVPPathTear_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::RSVPPacket::parsimPack(b);
    doParsimPacking(b,this->hop);
    doParsimPacking(b,this->senderTemplate);
    doParsimPacking(b,this->force);
}

void RSVPPathTear_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::RSVPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->hop);
    doParsimUnpacking(b,this->senderTemplate);
    doParsimUnpacking(b,this->force);
}

RsvpHopObj_t& RSVPPathTear_Base::getHop()
{
    return this->hop;
}

void RSVPPathTear_Base::setHop(const RsvpHopObj_t& hop)
{
    this->hop = hop;
}

SenderTemplateObj_t& RSVPPathTear_Base::getSenderTemplate()
{
    return this->senderTemplate;
}

void RSVPPathTear_Base::setSenderTemplate(const SenderTemplateObj_t& senderTemplate)
{
    this->senderTemplate = senderTemplate;
}

bool RSVPPathTear_Base::getForce() const
{
    return this->force;
}

void RSVPPathTear_Base::setForce(bool force)
{
    this->force = force;
}

class RSVPPathTearDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RSVPPathTearDescriptor();
    virtual ~RSVPPathTearDescriptor();

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

Register_ClassDescriptor(RSVPPathTearDescriptor)

RSVPPathTearDescriptor::RSVPPathTearDescriptor() : omnetpp::cClassDescriptor("inet::RSVPPathTear", "inet::RSVPPacket")
{
    propertynames = nullptr;
}

RSVPPathTearDescriptor::~RSVPPathTearDescriptor()
{
    delete[] propertynames;
}

bool RSVPPathTearDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RSVPPathTear_Base *>(obj)!=nullptr;
}

const char **RSVPPathTearDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RSVPPathTearDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RSVPPathTearDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int RSVPPathTearDescriptor::getFieldTypeFlags(int field) const
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

const char *RSVPPathTearDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "hop",
        "senderTemplate",
        "force",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int RSVPPathTearDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hop")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderTemplate")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "force")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RSVPPathTearDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "RsvpHopObj_t",
        "SenderTemplateObj_t",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **RSVPPathTearDescriptor::getFieldPropertyNames(int field) const
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

const char *RSVPPathTearDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RSVPPathTearDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RSVPPathTearDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RSVPPathTearDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHop(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSenderTemplate(); return out.str();}
        case 2: return bool2string(pp->getForce());
        default: return "";
    }
}

bool RSVPPathTearDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        case 2: pp->setForce(string2bool(value)); return true;
        default: return false;
    }
}

const char *RSVPPathTearDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(RsvpHopObj_t));
        case 1: return omnetpp::opp_typename(typeid(SenderTemplateObj_t));
        default: return nullptr;
    };
}

void *RSVPPathTearDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathTear_Base *pp = (RSVPPathTear_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getHop()); break;
        case 1: return (void *)(&pp->getSenderTemplate()); break;
        default: return nullptr;
    }
}

RSVPPathError_Base::RSVPPathError_Base(const char *name, short kind) : ::inet::RSVPPacket(name,kind)
{
    this->setRsvpKind(PERROR_MESSAGE);

    this->errorCode = 0;
}

RSVPPathError_Base::RSVPPathError_Base(const RSVPPathError_Base& other) : ::inet::RSVPPacket(other)
{
    copy(other);
}

RSVPPathError_Base::~RSVPPathError_Base()
{
}

RSVPPathError_Base& RSVPPathError_Base::operator=(const RSVPPathError_Base& other)
{
    if (this==&other) return *this;
    ::inet::RSVPPacket::operator=(other);
    copy(other);
    return *this;
}

void RSVPPathError_Base::copy(const RSVPPathError_Base& other)
{
    this->errorNode = other.errorNode;
    this->errorCode = other.errorCode;
    this->sender_descriptor = other.sender_descriptor;
}

void RSVPPathError_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::RSVPPacket::parsimPack(b);
    doParsimPacking(b,this->errorNode);
    doParsimPacking(b,this->errorCode);
    doParsimPacking(b,this->sender_descriptor);
}

void RSVPPathError_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::RSVPPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->errorNode);
    doParsimUnpacking(b,this->errorCode);
    doParsimUnpacking(b,this->sender_descriptor);
}

IPv4Address& RSVPPathError_Base::getErrorNode()
{
    return this->errorNode;
}

void RSVPPathError_Base::setErrorNode(const IPv4Address& errorNode)
{
    this->errorNode = errorNode;
}

int RSVPPathError_Base::getErrorCode() const
{
    return this->errorCode;
}

void RSVPPathError_Base::setErrorCode(int errorCode)
{
    this->errorCode = errorCode;
}

SenderDescriptor_t& RSVPPathError_Base::getSender_descriptor()
{
    return this->sender_descriptor;
}

void RSVPPathError_Base::setSender_descriptor(const SenderDescriptor_t& sender_descriptor)
{
    this->sender_descriptor = sender_descriptor;
}

class RSVPPathErrorDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RSVPPathErrorDescriptor();
    virtual ~RSVPPathErrorDescriptor();

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

Register_ClassDescriptor(RSVPPathErrorDescriptor)

RSVPPathErrorDescriptor::RSVPPathErrorDescriptor() : omnetpp::cClassDescriptor("inet::RSVPPathError", "inet::RSVPPacket")
{
    propertynames = nullptr;
}

RSVPPathErrorDescriptor::~RSVPPathErrorDescriptor()
{
    delete[] propertynames;
}

bool RSVPPathErrorDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RSVPPathError_Base *>(obj)!=nullptr;
}

const char **RSVPPathErrorDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RSVPPathErrorDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RSVPPathErrorDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int RSVPPathErrorDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *RSVPPathErrorDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "errorNode",
        "errorCode",
        "sender_descriptor",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int RSVPPathErrorDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorNode")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorCode")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sender_descriptor")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RSVPPathErrorDescriptor::getFieldTypeString(int field) const
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
        "SenderDescriptor_t",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **RSVPPathErrorDescriptor::getFieldPropertyNames(int field) const
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

const char *RSVPPathErrorDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RSVPPathErrorDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RSVPPathErrorDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RSVPPathErrorDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getErrorNode(); return out.str();}
        case 1: return long2string(pp->getErrorCode());
        case 2: {std::stringstream out; out << pp->getSender_descriptor(); return out.str();}
        default: return "";
    }
}

bool RSVPPathErrorDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        case 1: pp->setErrorCode(string2long(value)); return true;
        default: return false;
    }
}

const char *RSVPPathErrorDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(SenderDescriptor_t));
        default: return nullptr;
    };
}

void *RSVPPathErrorDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RSVPPathError_Base *pp = (RSVPPathError_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getErrorNode()); break;
        case 2: return (void *)(&pp->getSender_descriptor()); break;
        default: return nullptr;
    }
}

} // namespace inet

