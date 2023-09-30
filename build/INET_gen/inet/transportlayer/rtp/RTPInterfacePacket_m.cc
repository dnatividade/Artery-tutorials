//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/rtp/RTPInterfacePacket.msg.
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
#include "RTPInterfacePacket_m.h"

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
namespace rtp {

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::rtp::RTP_IFP_TYPE");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::rtp::RTP_IFP_TYPE"));
    e->insert(RTP_IFP_ENTER_SESSION, "RTP_IFP_ENTER_SESSION");
    e->insert(RTP_IFP_SESSION_ENTERED, "RTP_IFP_SESSION_ENTERED");
    e->insert(RTP_IFP_CREATE_SENDER_MODULE, "RTP_IFP_CREATE_SENDER_MODULE");
    e->insert(RTP_IFP_SENDER_MODULE_CREATED, "RTP_IFP_SENDER_MODULE_CREATED");
    e->insert(RTP_IFP_DELETE_SENDER_MODULE, "RTP_IFP_DELETE_SENDER_MODULE");
    e->insert(RTP_IFP_SENDER_MODULE_DELETED, "RTP_IFP_SENDER_MODULE_DELETED");
    e->insert(RTP_IFP_SENDER_CONTROL, "RTP_IFP_SENDER_CONTROL");
    e->insert(RTP_IFP_SENDER_STATUS, "RTP_IFP_SENDER_STATUS");
    e->insert(RTP_IFP_LEAVE_SESSION, "RTP_IFP_LEAVE_SESSION");
    e->insert(RTP_IFP_SESSION_LEFT, "RTP_IFP_SESSION_LEFT");
)

Register_Class(RTPControlMsg)

RTPControlMsg::RTPControlMsg(const char *name, short kind) : ::omnetpp::cMessage(name,kind)
{
}

RTPControlMsg::RTPControlMsg(const RTPControlMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

RTPControlMsg::~RTPControlMsg()
{
}

RTPControlMsg& RTPControlMsg::operator=(const RTPControlMsg& other)
{
    if (this==&other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void RTPControlMsg::copy(const RTPControlMsg& other)
{
}

void RTPControlMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
}

void RTPControlMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
}

class RTPControlMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPControlMsgDescriptor();
    virtual ~RTPControlMsgDescriptor();

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

Register_ClassDescriptor(RTPControlMsgDescriptor)

RTPControlMsgDescriptor::RTPControlMsgDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPControlMsg", "omnetpp::cMessage")
{
    propertynames = nullptr;
}

RTPControlMsgDescriptor::~RTPControlMsgDescriptor()
{
    delete[] propertynames;
}

bool RTPControlMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPControlMsg *>(obj)!=nullptr;
}

const char **RTPControlMsgDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPControlMsgDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPControlMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RTPControlMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RTPControlMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RTPControlMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPControlMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RTPControlMsgDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPControlMsgDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPControlMsgDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPControlMsg *pp = (RTPControlMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPControlMsgDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPControlMsg *pp = (RTPControlMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPControlMsgDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPControlMsg *pp = (RTPControlMsg *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RTPControlMsgDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPControlMsg *pp = (RTPControlMsg *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RTPControlMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RTPControlMsgDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPControlMsg *pp = (RTPControlMsg *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPControlInfo)

RTPControlInfo::RTPControlInfo() : ::omnetpp::cObject()
{
    this->type = 0;
}

RTPControlInfo::RTPControlInfo(const RTPControlInfo& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

RTPControlInfo::~RTPControlInfo()
{
}

RTPControlInfo& RTPControlInfo::operator=(const RTPControlInfo& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void RTPControlInfo::copy(const RTPControlInfo& other)
{
    this->type = other.type;
}

void RTPControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
}

void RTPControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
}

short RTPControlInfo::getType() const
{
    return this->type;
}

void RTPControlInfo::setType(short type)
{
    this->type = type;
}

class RTPControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPControlInfoDescriptor();
    virtual ~RTPControlInfoDescriptor();

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

Register_ClassDescriptor(RTPControlInfoDescriptor)

RTPControlInfoDescriptor::RTPControlInfoDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPControlInfo", "omnetpp::cObject")
{
    propertynames = nullptr;
}

RTPControlInfoDescriptor::~RTPControlInfoDescriptor()
{
    delete[] propertynames;
}

bool RTPControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPControlInfo *>(obj)!=nullptr;
}

const char **RTPControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RTPControlInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *RTPControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int RTPControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPControlInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **RTPControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::rtp::RTP_IFP_TYPE";
            return nullptr;
        default: return nullptr;
    }
}

int RTPControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPControlInfo *pp = (RTPControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPControlInfo *pp = (RTPControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPControlInfo *pp = (RTPControlInfo *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::rtp::RTP_IFP_TYPE");
        default: return "";
    }
}

bool RTPControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPControlInfo *pp = (RTPControlInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::rtp::RTP_IFP_TYPE)string2enum(value, "inet::rtp::RTP_IFP_TYPE")); return true;
        default: return false;
    }
}

const char *RTPControlInfoDescriptor::getFieldStructName(int field) const
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

void *RTPControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPControlInfo *pp = (RTPControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPSessionControlInfo)

RTPSessionControlInfo::RTPSessionControlInfo() : ::inet::rtp::RTPControlInfo()
{
    this->ssrc = 0;
}

RTPSessionControlInfo::RTPSessionControlInfo(const RTPSessionControlInfo& other) : ::inet::rtp::RTPControlInfo(other)
{
    copy(other);
}

RTPSessionControlInfo::~RTPSessionControlInfo()
{
}

RTPSessionControlInfo& RTPSessionControlInfo::operator=(const RTPSessionControlInfo& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPSessionControlInfo::copy(const RTPSessionControlInfo& other)
{
    this->ssrc = other.ssrc;
}

void RTPSessionControlInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPControlInfo::parsimPack(b);
    doParsimPacking(b,this->ssrc);
}

void RTPSessionControlInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->ssrc);
}

uint32_t RTPSessionControlInfo::getSsrc() const
{
    return this->ssrc;
}

void RTPSessionControlInfo::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

class RTPSessionControlInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPSessionControlInfoDescriptor();
    virtual ~RTPSessionControlInfoDescriptor();

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

Register_ClassDescriptor(RTPSessionControlInfoDescriptor)

RTPSessionControlInfoDescriptor::RTPSessionControlInfoDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPSessionControlInfo", "inet::rtp::RTPControlInfo")
{
    propertynames = nullptr;
}

RTPSessionControlInfoDescriptor::~RTPSessionControlInfoDescriptor()
{
    delete[] propertynames;
}

bool RTPSessionControlInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPSessionControlInfo *>(obj)!=nullptr;
}

const char **RTPSessionControlInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPSessionControlInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPSessionControlInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int RTPSessionControlInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *RTPSessionControlInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ssrc",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int RTPSessionControlInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssrc")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPSessionControlInfoDescriptor::getFieldTypeString(int field) const
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

const char **RTPSessionControlInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPSessionControlInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPSessionControlInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPSessionControlInfo *pp = (RTPSessionControlInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPSessionControlInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPSessionControlInfo *pp = (RTPSessionControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPSessionControlInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPSessionControlInfo *pp = (RTPSessionControlInfo *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSsrc());
        default: return "";
    }
}

bool RTPSessionControlInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPSessionControlInfo *pp = (RTPSessionControlInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setSsrc(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RTPSessionControlInfoDescriptor::getFieldStructName(int field) const
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

void *RTPSessionControlInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPSessionControlInfo *pp = (RTPSessionControlInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCIEnterSession)

RTPCIEnterSession::RTPCIEnterSession() : ::inet::rtp::RTPControlInfo()
{
    this->setType(RTP_IFP_ENTER_SESSION);

    this->bandwidth = 0;
    this->port = 0;
}

RTPCIEnterSession::RTPCIEnterSession(const RTPCIEnterSession& other) : ::inet::rtp::RTPControlInfo(other)
{
    copy(other);
}

RTPCIEnterSession::~RTPCIEnterSession()
{
}

RTPCIEnterSession& RTPCIEnterSession::operator=(const RTPCIEnterSession& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCIEnterSession::copy(const RTPCIEnterSession& other)
{
    this->commonName = other.commonName;
    this->profileName = other.profileName;
    this->bandwidth = other.bandwidth;
    this->destinationAddress = other.destinationAddress;
    this->port = other.port;
}

void RTPCIEnterSession::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPControlInfo::parsimPack(b);
    doParsimPacking(b,this->commonName);
    doParsimPacking(b,this->profileName);
    doParsimPacking(b,this->bandwidth);
    doParsimPacking(b,this->destinationAddress);
    doParsimPacking(b,this->port);
}

void RTPCIEnterSession::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->commonName);
    doParsimUnpacking(b,this->profileName);
    doParsimUnpacking(b,this->bandwidth);
    doParsimUnpacking(b,this->destinationAddress);
    doParsimUnpacking(b,this->port);
}

const char * RTPCIEnterSession::getCommonName() const
{
    return this->commonName.c_str();
}

void RTPCIEnterSession::setCommonName(const char * commonName)
{
    this->commonName = commonName;
}

const char * RTPCIEnterSession::getProfileName() const
{
    return this->profileName.c_str();
}

void RTPCIEnterSession::setProfileName(const char * profileName)
{
    this->profileName = profileName;
}

int RTPCIEnterSession::getBandwidth() const
{
    return this->bandwidth;
}

void RTPCIEnterSession::setBandwidth(int bandwidth)
{
    this->bandwidth = bandwidth;
}

IPv4Address& RTPCIEnterSession::getDestinationAddress()
{
    return this->destinationAddress;
}

void RTPCIEnterSession::setDestinationAddress(const IPv4Address& destinationAddress)
{
    this->destinationAddress = destinationAddress;
}

int RTPCIEnterSession::getPort() const
{
    return this->port;
}

void RTPCIEnterSession::setPort(int port)
{
    this->port = port;
}

class RTPCIEnterSessionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCIEnterSessionDescriptor();
    virtual ~RTPCIEnterSessionDescriptor();

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

Register_ClassDescriptor(RTPCIEnterSessionDescriptor)

RTPCIEnterSessionDescriptor::RTPCIEnterSessionDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCIEnterSession", "inet::rtp::RTPControlInfo")
{
    propertynames = nullptr;
}

RTPCIEnterSessionDescriptor::~RTPCIEnterSessionDescriptor()
{
    delete[] propertynames;
}

bool RTPCIEnterSessionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCIEnterSession *>(obj)!=nullptr;
}

const char **RTPCIEnterSessionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCIEnterSessionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCIEnterSessionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int RTPCIEnterSessionDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *RTPCIEnterSessionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "commonName",
        "profileName",
        "bandwidth",
        "destinationAddress",
        "port",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int RTPCIEnterSessionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "commonName")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "profileName")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bandwidth")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "destinationAddress")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "port")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCIEnterSessionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "string",
        "int",
        "IPv4Address",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **RTPCIEnterSessionDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCIEnterSessionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPCIEnterSessionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCIEnterSession *pp = (RTPCIEnterSession *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCIEnterSessionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCIEnterSession *pp = (RTPCIEnterSession *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCIEnterSessionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCIEnterSession *pp = (RTPCIEnterSession *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getCommonName());
        case 1: return oppstring2string(pp->getProfileName());
        case 2: return long2string(pp->getBandwidth());
        case 3: {std::stringstream out; out << pp->getDestinationAddress(); return out.str();}
        case 4: return long2string(pp->getPort());
        default: return "";
    }
}

bool RTPCIEnterSessionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCIEnterSession *pp = (RTPCIEnterSession *)object; (void)pp;
    switch (field) {
        case 0: pp->setCommonName((value)); return true;
        case 1: pp->setProfileName((value)); return true;
        case 2: pp->setBandwidth(string2long(value)); return true;
        case 4: pp->setPort(string2long(value)); return true;
        default: return false;
    }
}

const char *RTPCIEnterSessionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *RTPCIEnterSessionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCIEnterSession *pp = (RTPCIEnterSession *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getDestinationAddress()); break;
        default: return nullptr;
    }
}

Register_Class(RTPCISessionEntered)

RTPCISessionEntered::RTPCISessionEntered() : ::inet::rtp::RTPSessionControlInfo()
{
    this->setType(RTP_IFP_SESSION_ENTERED);
}

RTPCISessionEntered::RTPCISessionEntered(const RTPCISessionEntered& other) : ::inet::rtp::RTPSessionControlInfo(other)
{
    copy(other);
}

RTPCISessionEntered::~RTPCISessionEntered()
{
}

RTPCISessionEntered& RTPCISessionEntered::operator=(const RTPCISessionEntered& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCISessionEntered::copy(const RTPCISessionEntered& other)
{
}

void RTPCISessionEntered::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPSessionControlInfo::parsimPack(b);
}

void RTPCISessionEntered::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPSessionControlInfo::parsimUnpack(b);
}

class RTPCISessionEnteredDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCISessionEnteredDescriptor();
    virtual ~RTPCISessionEnteredDescriptor();

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

Register_ClassDescriptor(RTPCISessionEnteredDescriptor)

RTPCISessionEnteredDescriptor::RTPCISessionEnteredDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCISessionEntered", "inet::rtp::RTPSessionControlInfo")
{
    propertynames = nullptr;
}

RTPCISessionEnteredDescriptor::~RTPCISessionEnteredDescriptor()
{
    delete[] propertynames;
}

bool RTPCISessionEnteredDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCISessionEntered *>(obj)!=nullptr;
}

const char **RTPCISessionEnteredDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCISessionEnteredDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCISessionEnteredDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RTPCISessionEnteredDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RTPCISessionEnteredDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RTPCISessionEnteredDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCISessionEnteredDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RTPCISessionEnteredDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCISessionEnteredDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPCISessionEnteredDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionEntered *pp = (RTPCISessionEntered *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCISessionEnteredDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionEntered *pp = (RTPCISessionEntered *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCISessionEnteredDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionEntered *pp = (RTPCISessionEntered *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RTPCISessionEnteredDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionEntered *pp = (RTPCISessionEntered *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RTPCISessionEnteredDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RTPCISessionEnteredDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionEntered *pp = (RTPCISessionEntered *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCISenderControl)

RTPCISenderControl::RTPCISenderControl() : ::inet::rtp::RTPSessionControlInfo()
{
    this->setType(RTP_IFP_SENDER_CONTROL);

    this->command = 0;
    this->commandParameter1 = 0;
    this->commandParameter2 = 0;
}

RTPCISenderControl::RTPCISenderControl(const RTPCISenderControl& other) : ::inet::rtp::RTPSessionControlInfo(other)
{
    copy(other);
}

RTPCISenderControl::~RTPCISenderControl()
{
}

RTPCISenderControl& RTPCISenderControl::operator=(const RTPCISenderControl& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCISenderControl::copy(const RTPCISenderControl& other)
{
    this->command = other.command;
    this->commandParameter1 = other.commandParameter1;
    this->commandParameter2 = other.commandParameter2;
}

void RTPCISenderControl::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPSessionControlInfo::parsimPack(b);
    doParsimPacking(b,this->command);
    doParsimPacking(b,this->commandParameter1);
    doParsimPacking(b,this->commandParameter2);
}

void RTPCISenderControl::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPSessionControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->command);
    doParsimUnpacking(b,this->commandParameter1);
    doParsimUnpacking(b,this->commandParameter2);
}

short RTPCISenderControl::getCommand() const
{
    return this->command;
}

void RTPCISenderControl::setCommand(short command)
{
    this->command = command;
}

float RTPCISenderControl::getCommandParameter1() const
{
    return this->commandParameter1;
}

void RTPCISenderControl::setCommandParameter1(float commandParameter1)
{
    this->commandParameter1 = commandParameter1;
}

float RTPCISenderControl::getCommandParameter2() const
{
    return this->commandParameter2;
}

void RTPCISenderControl::setCommandParameter2(float commandParameter2)
{
    this->commandParameter2 = commandParameter2;
}

class RTPCISenderControlDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCISenderControlDescriptor();
    virtual ~RTPCISenderControlDescriptor();

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

Register_ClassDescriptor(RTPCISenderControlDescriptor)

RTPCISenderControlDescriptor::RTPCISenderControlDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCISenderControl", "inet::rtp::RTPSessionControlInfo")
{
    propertynames = nullptr;
}

RTPCISenderControlDescriptor::~RTPCISenderControlDescriptor()
{
    delete[] propertynames;
}

bool RTPCISenderControlDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCISenderControl *>(obj)!=nullptr;
}

const char **RTPCISenderControlDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCISenderControlDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCISenderControlDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int RTPCISenderControlDescriptor::getFieldTypeFlags(int field) const
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

const char *RTPCISenderControlDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "command",
        "commandParameter1",
        "commandParameter2",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int RTPCISenderControlDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "command")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "commandParameter1")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "commandParameter2")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCISenderControlDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "float",
        "float",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **RTPCISenderControlDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCISenderControlDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::rtp::RTPSenderControlMessageCommands";
            return nullptr;
        default: return nullptr;
    }
}

int RTPCISenderControlDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderControl *pp = (RTPCISenderControl *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCISenderControlDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderControl *pp = (RTPCISenderControl *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCISenderControlDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderControl *pp = (RTPCISenderControl *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getCommand(), "inet::rtp::RTPSenderControlMessageCommands");
        case 1: return double2string(pp->getCommandParameter1());
        case 2: return double2string(pp->getCommandParameter2());
        default: return "";
    }
}

bool RTPCISenderControlDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderControl *pp = (RTPCISenderControl *)object; (void)pp;
    switch (field) {
        case 0: pp->setCommand((inet::rtp::RTPSenderControlMessageCommands)string2enum(value, "inet::rtp::RTPSenderControlMessageCommands")); return true;
        case 1: pp->setCommandParameter1(string2double(value)); return true;
        case 2: pp->setCommandParameter2(string2double(value)); return true;
        default: return false;
    }
}

const char *RTPCISenderControlDescriptor::getFieldStructName(int field) const
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

void *RTPCISenderControlDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderControl *pp = (RTPCISenderControl *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCISenderStatus)

RTPCISenderStatus::RTPCISenderStatus() : ::inet::rtp::RTPSessionControlInfo()
{
    this->setType(RTP_IFP_SENDER_STATUS);

    this->status = 0;
    this->timeStamp = 0;
}

RTPCISenderStatus::RTPCISenderStatus(const RTPCISenderStatus& other) : ::inet::rtp::RTPSessionControlInfo(other)
{
    copy(other);
}

RTPCISenderStatus::~RTPCISenderStatus()
{
}

RTPCISenderStatus& RTPCISenderStatus::operator=(const RTPCISenderStatus& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCISenderStatus::copy(const RTPCISenderStatus& other)
{
    this->status = other.status;
    this->timeStamp = other.timeStamp;
}

void RTPCISenderStatus::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPSessionControlInfo::parsimPack(b);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->timeStamp);
}

void RTPCISenderStatus::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPSessionControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->timeStamp);
}

short RTPCISenderStatus::getStatus() const
{
    return this->status;
}

void RTPCISenderStatus::setStatus(short status)
{
    this->status = status;
}

uint32_t RTPCISenderStatus::getTimeStamp() const
{
    return this->timeStamp;
}

void RTPCISenderStatus::setTimeStamp(uint32_t timeStamp)
{
    this->timeStamp = timeStamp;
}

class RTPCISenderStatusDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCISenderStatusDescriptor();
    virtual ~RTPCISenderStatusDescriptor();

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

Register_ClassDescriptor(RTPCISenderStatusDescriptor)

RTPCISenderStatusDescriptor::RTPCISenderStatusDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCISenderStatus", "inet::rtp::RTPSessionControlInfo")
{
    propertynames = nullptr;
}

RTPCISenderStatusDescriptor::~RTPCISenderStatusDescriptor()
{
    delete[] propertynames;
}

bool RTPCISenderStatusDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCISenderStatus *>(obj)!=nullptr;
}

const char **RTPCISenderStatusDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCISenderStatusDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCISenderStatusDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RTPCISenderStatusDescriptor::getFieldTypeFlags(int field) const
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

const char *RTPCISenderStatusDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "status",
        "timeStamp",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int RTPCISenderStatusDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeStamp")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCISenderStatusDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "uint32",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **RTPCISenderStatusDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCISenderStatusDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::rtp::RTPSenderStatus";
            return nullptr;
        default: return nullptr;
    }
}

int RTPCISenderStatusDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderStatus *pp = (RTPCISenderStatus *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCISenderStatusDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderStatus *pp = (RTPCISenderStatus *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCISenderStatusDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderStatus *pp = (RTPCISenderStatus *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getStatus(), "inet::rtp::RTPSenderStatus");
        case 1: return ulong2string(pp->getTimeStamp());
        default: return "";
    }
}

bool RTPCISenderStatusDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderStatus *pp = (RTPCISenderStatus *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatus((inet::rtp::RTPSenderStatus)string2enum(value, "inet::rtp::RTPSenderStatus")); return true;
        case 1: pp->setTimeStamp(string2ulong(value)); return true;
        default: return false;
    }
}

const char *RTPCISenderStatusDescriptor::getFieldStructName(int field) const
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

void *RTPCISenderStatusDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderStatus *pp = (RTPCISenderStatus *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCILeaveSession)

RTPCILeaveSession::RTPCILeaveSession() : ::inet::rtp::RTPControlInfo()
{
    this->setType(RTP_IFP_LEAVE_SESSION);
}

RTPCILeaveSession::RTPCILeaveSession(const RTPCILeaveSession& other) : ::inet::rtp::RTPControlInfo(other)
{
    copy(other);
}

RTPCILeaveSession::~RTPCILeaveSession()
{
}

RTPCILeaveSession& RTPCILeaveSession::operator=(const RTPCILeaveSession& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCILeaveSession::copy(const RTPCILeaveSession& other)
{
}

void RTPCILeaveSession::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPControlInfo::parsimPack(b);
}

void RTPCILeaveSession::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPControlInfo::parsimUnpack(b);
}

class RTPCILeaveSessionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCILeaveSessionDescriptor();
    virtual ~RTPCILeaveSessionDescriptor();

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

Register_ClassDescriptor(RTPCILeaveSessionDescriptor)

RTPCILeaveSessionDescriptor::RTPCILeaveSessionDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCILeaveSession", "inet::rtp::RTPControlInfo")
{
    propertynames = nullptr;
}

RTPCILeaveSessionDescriptor::~RTPCILeaveSessionDescriptor()
{
    delete[] propertynames;
}

bool RTPCILeaveSessionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCILeaveSession *>(obj)!=nullptr;
}

const char **RTPCILeaveSessionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCILeaveSessionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCILeaveSessionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RTPCILeaveSessionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RTPCILeaveSessionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RTPCILeaveSessionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCILeaveSessionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RTPCILeaveSessionDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCILeaveSessionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPCILeaveSessionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCILeaveSession *pp = (RTPCILeaveSession *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCILeaveSessionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCILeaveSession *pp = (RTPCILeaveSession *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCILeaveSessionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCILeaveSession *pp = (RTPCILeaveSession *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RTPCILeaveSessionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCILeaveSession *pp = (RTPCILeaveSession *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RTPCILeaveSessionDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RTPCILeaveSessionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCILeaveSession *pp = (RTPCILeaveSession *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCISessionLeft)

RTPCISessionLeft::RTPCISessionLeft() : ::inet::rtp::RTPControlInfo()
{
    this->setType(RTP_IFP_SESSION_LEFT);
}

RTPCISessionLeft::RTPCISessionLeft(const RTPCISessionLeft& other) : ::inet::rtp::RTPControlInfo(other)
{
    copy(other);
}

RTPCISessionLeft::~RTPCISessionLeft()
{
}

RTPCISessionLeft& RTPCISessionLeft::operator=(const RTPCISessionLeft& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCISessionLeft::copy(const RTPCISessionLeft& other)
{
}

void RTPCISessionLeft::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPControlInfo::parsimPack(b);
}

void RTPCISessionLeft::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPControlInfo::parsimUnpack(b);
}

class RTPCISessionLeftDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCISessionLeftDescriptor();
    virtual ~RTPCISessionLeftDescriptor();

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

Register_ClassDescriptor(RTPCISessionLeftDescriptor)

RTPCISessionLeftDescriptor::RTPCISessionLeftDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCISessionLeft", "inet::rtp::RTPControlInfo")
{
    propertynames = nullptr;
}

RTPCISessionLeftDescriptor::~RTPCISessionLeftDescriptor()
{
    delete[] propertynames;
}

bool RTPCISessionLeftDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCISessionLeft *>(obj)!=nullptr;
}

const char **RTPCISessionLeftDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCISessionLeftDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCISessionLeftDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RTPCISessionLeftDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RTPCISessionLeftDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RTPCISessionLeftDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCISessionLeftDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RTPCISessionLeftDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCISessionLeftDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPCISessionLeftDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionLeft *pp = (RTPCISessionLeft *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCISessionLeftDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionLeft *pp = (RTPCISessionLeft *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCISessionLeftDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionLeft *pp = (RTPCISessionLeft *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RTPCISessionLeftDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionLeft *pp = (RTPCISessionLeft *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RTPCISessionLeftDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RTPCISessionLeftDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCISessionLeft *pp = (RTPCISessionLeft *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCICreateSenderModule)

RTPCICreateSenderModule::RTPCICreateSenderModule() : ::inet::rtp::RTPSessionControlInfo()
{
    this->setType(RTP_IFP_CREATE_SENDER_MODULE);

    this->payloadType = 0;
}

RTPCICreateSenderModule::RTPCICreateSenderModule(const RTPCICreateSenderModule& other) : ::inet::rtp::RTPSessionControlInfo(other)
{
    copy(other);
}

RTPCICreateSenderModule::~RTPCICreateSenderModule()
{
}

RTPCICreateSenderModule& RTPCICreateSenderModule::operator=(const RTPCICreateSenderModule& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCICreateSenderModule::copy(const RTPCICreateSenderModule& other)
{
    this->payloadType = other.payloadType;
    this->fileName = other.fileName;
}

void RTPCICreateSenderModule::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPSessionControlInfo::parsimPack(b);
    doParsimPacking(b,this->payloadType);
    doParsimPacking(b,this->fileName);
}

void RTPCICreateSenderModule::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPSessionControlInfo::parsimUnpack(b);
    doParsimUnpacking(b,this->payloadType);
    doParsimUnpacking(b,this->fileName);
}

int RTPCICreateSenderModule::getPayloadType() const
{
    return this->payloadType;
}

void RTPCICreateSenderModule::setPayloadType(int payloadType)
{
    this->payloadType = payloadType;
}

const char * RTPCICreateSenderModule::getFileName() const
{
    return this->fileName.c_str();
}

void RTPCICreateSenderModule::setFileName(const char * fileName)
{
    this->fileName = fileName;
}

class RTPCICreateSenderModuleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCICreateSenderModuleDescriptor();
    virtual ~RTPCICreateSenderModuleDescriptor();

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

Register_ClassDescriptor(RTPCICreateSenderModuleDescriptor)

RTPCICreateSenderModuleDescriptor::RTPCICreateSenderModuleDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCICreateSenderModule", "inet::rtp::RTPSessionControlInfo")
{
    propertynames = nullptr;
}

RTPCICreateSenderModuleDescriptor::~RTPCICreateSenderModuleDescriptor()
{
    delete[] propertynames;
}

bool RTPCICreateSenderModuleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCICreateSenderModule *>(obj)!=nullptr;
}

const char **RTPCICreateSenderModuleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCICreateSenderModuleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCICreateSenderModuleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int RTPCICreateSenderModuleDescriptor::getFieldTypeFlags(int field) const
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

const char *RTPCICreateSenderModuleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "payloadType",
        "fileName",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int RTPCICreateSenderModuleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadType")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fileName")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCICreateSenderModuleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **RTPCICreateSenderModuleDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCICreateSenderModuleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPCICreateSenderModuleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCICreateSenderModule *pp = (RTPCICreateSenderModule *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCICreateSenderModuleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCICreateSenderModule *pp = (RTPCICreateSenderModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCICreateSenderModuleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCICreateSenderModule *pp = (RTPCICreateSenderModule *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getPayloadType());
        case 1: return oppstring2string(pp->getFileName());
        default: return "";
    }
}

bool RTPCICreateSenderModuleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCICreateSenderModule *pp = (RTPCICreateSenderModule *)object; (void)pp;
    switch (field) {
        case 0: pp->setPayloadType(string2long(value)); return true;
        case 1: pp->setFileName((value)); return true;
        default: return false;
    }
}

const char *RTPCICreateSenderModuleDescriptor::getFieldStructName(int field) const
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

void *RTPCICreateSenderModuleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCICreateSenderModule *pp = (RTPCICreateSenderModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCISenderModuleCreated)

RTPCISenderModuleCreated::RTPCISenderModuleCreated() : ::inet::rtp::RTPSessionControlInfo()
{
    this->setType(RTP_IFP_SENDER_MODULE_CREATED);
}

RTPCISenderModuleCreated::RTPCISenderModuleCreated(const RTPCISenderModuleCreated& other) : ::inet::rtp::RTPSessionControlInfo(other)
{
    copy(other);
}

RTPCISenderModuleCreated::~RTPCISenderModuleCreated()
{
}

RTPCISenderModuleCreated& RTPCISenderModuleCreated::operator=(const RTPCISenderModuleCreated& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCISenderModuleCreated::copy(const RTPCISenderModuleCreated& other)
{
}

void RTPCISenderModuleCreated::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPSessionControlInfo::parsimPack(b);
}

void RTPCISenderModuleCreated::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPSessionControlInfo::parsimUnpack(b);
}

class RTPCISenderModuleCreatedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCISenderModuleCreatedDescriptor();
    virtual ~RTPCISenderModuleCreatedDescriptor();

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

Register_ClassDescriptor(RTPCISenderModuleCreatedDescriptor)

RTPCISenderModuleCreatedDescriptor::RTPCISenderModuleCreatedDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCISenderModuleCreated", "inet::rtp::RTPSessionControlInfo")
{
    propertynames = nullptr;
}

RTPCISenderModuleCreatedDescriptor::~RTPCISenderModuleCreatedDescriptor()
{
    delete[] propertynames;
}

bool RTPCISenderModuleCreatedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCISenderModuleCreated *>(obj)!=nullptr;
}

const char **RTPCISenderModuleCreatedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCISenderModuleCreatedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCISenderModuleCreatedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RTPCISenderModuleCreatedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RTPCISenderModuleCreatedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RTPCISenderModuleCreatedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCISenderModuleCreatedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RTPCISenderModuleCreatedDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCISenderModuleCreatedDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPCISenderModuleCreatedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleCreated *pp = (RTPCISenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCISenderModuleCreatedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleCreated *pp = (RTPCISenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCISenderModuleCreatedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleCreated *pp = (RTPCISenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RTPCISenderModuleCreatedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleCreated *pp = (RTPCISenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RTPCISenderModuleCreatedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RTPCISenderModuleCreatedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleCreated *pp = (RTPCISenderModuleCreated *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCIDeleteSenderModule)

RTPCIDeleteSenderModule::RTPCIDeleteSenderModule() : ::inet::rtp::RTPSessionControlInfo()
{
    this->setType(RTP_IFP_DELETE_SENDER_MODULE);
}

RTPCIDeleteSenderModule::RTPCIDeleteSenderModule(const RTPCIDeleteSenderModule& other) : ::inet::rtp::RTPSessionControlInfo(other)
{
    copy(other);
}

RTPCIDeleteSenderModule::~RTPCIDeleteSenderModule()
{
}

RTPCIDeleteSenderModule& RTPCIDeleteSenderModule::operator=(const RTPCIDeleteSenderModule& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCIDeleteSenderModule::copy(const RTPCIDeleteSenderModule& other)
{
}

void RTPCIDeleteSenderModule::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPSessionControlInfo::parsimPack(b);
}

void RTPCIDeleteSenderModule::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPSessionControlInfo::parsimUnpack(b);
}

class RTPCIDeleteSenderModuleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCIDeleteSenderModuleDescriptor();
    virtual ~RTPCIDeleteSenderModuleDescriptor();

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

Register_ClassDescriptor(RTPCIDeleteSenderModuleDescriptor)

RTPCIDeleteSenderModuleDescriptor::RTPCIDeleteSenderModuleDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCIDeleteSenderModule", "inet::rtp::RTPSessionControlInfo")
{
    propertynames = nullptr;
}

RTPCIDeleteSenderModuleDescriptor::~RTPCIDeleteSenderModuleDescriptor()
{
    delete[] propertynames;
}

bool RTPCIDeleteSenderModuleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCIDeleteSenderModule *>(obj)!=nullptr;
}

const char **RTPCIDeleteSenderModuleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCIDeleteSenderModuleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCIDeleteSenderModuleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RTPCIDeleteSenderModuleDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RTPCIDeleteSenderModuleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RTPCIDeleteSenderModuleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCIDeleteSenderModuleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RTPCIDeleteSenderModuleDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCIDeleteSenderModuleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPCIDeleteSenderModuleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCIDeleteSenderModule *pp = (RTPCIDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCIDeleteSenderModuleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCIDeleteSenderModule *pp = (RTPCIDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCIDeleteSenderModuleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCIDeleteSenderModule *pp = (RTPCIDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RTPCIDeleteSenderModuleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCIDeleteSenderModule *pp = (RTPCIDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RTPCIDeleteSenderModuleDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RTPCIDeleteSenderModuleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCIDeleteSenderModule *pp = (RTPCIDeleteSenderModule *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(RTPCISenderModuleDeleted)

RTPCISenderModuleDeleted::RTPCISenderModuleDeleted() : ::inet::rtp::RTPSessionControlInfo()
{
    this->setType(RTP_IFP_SENDER_MODULE_DELETED);
}

RTPCISenderModuleDeleted::RTPCISenderModuleDeleted(const RTPCISenderModuleDeleted& other) : ::inet::rtp::RTPSessionControlInfo(other)
{
    copy(other);
}

RTPCISenderModuleDeleted::~RTPCISenderModuleDeleted()
{
}

RTPCISenderModuleDeleted& RTPCISenderModuleDeleted::operator=(const RTPCISenderModuleDeleted& other)
{
    if (this==&other) return *this;
    ::inet::rtp::RTPSessionControlInfo::operator=(other);
    copy(other);
    return *this;
}

void RTPCISenderModuleDeleted::copy(const RTPCISenderModuleDeleted& other)
{
}

void RTPCISenderModuleDeleted::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::rtp::RTPSessionControlInfo::parsimPack(b);
}

void RTPCISenderModuleDeleted::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::rtp::RTPSessionControlInfo::parsimUnpack(b);
}

class RTPCISenderModuleDeletedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPCISenderModuleDeletedDescriptor();
    virtual ~RTPCISenderModuleDeletedDescriptor();

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

Register_ClassDescriptor(RTPCISenderModuleDeletedDescriptor)

RTPCISenderModuleDeletedDescriptor::RTPCISenderModuleDeletedDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPCISenderModuleDeleted", "inet::rtp::RTPSessionControlInfo")
{
    propertynames = nullptr;
}

RTPCISenderModuleDeletedDescriptor::~RTPCISenderModuleDeletedDescriptor()
{
    delete[] propertynames;
}

bool RTPCISenderModuleDeletedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPCISenderModuleDeleted *>(obj)!=nullptr;
}

const char **RTPCISenderModuleDeletedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPCISenderModuleDeletedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPCISenderModuleDeletedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int RTPCISenderModuleDeletedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *RTPCISenderModuleDeletedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int RTPCISenderModuleDeletedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPCISenderModuleDeletedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **RTPCISenderModuleDeletedDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPCISenderModuleDeletedDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPCISenderModuleDeletedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleDeleted *pp = (RTPCISenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *RTPCISenderModuleDeletedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleDeleted *pp = (RTPCISenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPCISenderModuleDeletedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleDeleted *pp = (RTPCISenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool RTPCISenderModuleDeletedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleDeleted *pp = (RTPCISenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *RTPCISenderModuleDeletedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *RTPCISenderModuleDeletedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPCISenderModuleDeleted *pp = (RTPCISenderModuleDeleted *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

