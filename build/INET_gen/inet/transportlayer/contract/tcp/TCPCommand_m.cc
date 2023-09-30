//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/contract/tcp/TCPCommand.msg.
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
#include "TCPCommand_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TcpCommandCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TcpCommandCode"));
    e->insert(TCP_C_OPEN_ACTIVE, "TCP_C_OPEN_ACTIVE");
    e->insert(TCP_C_OPEN_PASSIVE, "TCP_C_OPEN_PASSIVE");
    e->insert(TCP_C_SEND, "TCP_C_SEND");
    e->insert(TCP_C_CLOSE, "TCP_C_CLOSE");
    e->insert(TCP_C_ABORT, "TCP_C_ABORT");
    e->insert(TCP_C_STATUS, "TCP_C_STATUS");
    e->insert(TCP_C_QUEUE_BYTES_LIMIT, "TCP_C_QUEUE_BYTES_LIMIT");
    e->insert(TCP_C_READ, "TCP_C_READ");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TcpStatusInd");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TcpStatusInd"));
    e->insert(TCP_I_DATA, "TCP_I_DATA");
    e->insert(TCP_I_URGENT_DATA, "TCP_I_URGENT_DATA");
    e->insert(TCP_I_ESTABLISHED, "TCP_I_ESTABLISHED");
    e->insert(TCP_I_PEER_CLOSED, "TCP_I_PEER_CLOSED");
    e->insert(TCP_I_CLOSED, "TCP_I_CLOSED");
    e->insert(TCP_I_CONNECTION_REFUSED, "TCP_I_CONNECTION_REFUSED");
    e->insert(TCP_I_CONNECTION_RESET, "TCP_I_CONNECTION_RESET");
    e->insert(TCP_I_TIMED_OUT, "TCP_I_TIMED_OUT");
    e->insert(TCP_I_STATUS, "TCP_I_STATUS");
    e->insert(TCP_I_SEND_MSG, "TCP_I_SEND_MSG");
    e->insert(TCP_I_DATA_NOTIFICATION, "TCP_I_DATA_NOTIFICATION");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TCPErrorCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TCPErrorCode"));
)

Register_Class(TCPCommand)

TCPCommand::TCPCommand() : ::omnetpp::cObject()
{
    this->connId = -1;
    this->userId = -1;
}

TCPCommand::TCPCommand(const TCPCommand& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

TCPCommand::~TCPCommand()
{
}

TCPCommand& TCPCommand::operator=(const TCPCommand& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void TCPCommand::copy(const TCPCommand& other)
{
    this->connId = other.connId;
    this->userId = other.userId;
}

void TCPCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->connId);
    doParsimPacking(b,this->userId);
}

void TCPCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->connId);
    doParsimUnpacking(b,this->userId);
}

int TCPCommand::getConnId() const
{
    return this->connId;
}

void TCPCommand::setConnId(int connId)
{
    this->connId = connId;
}

int TCPCommand::getUserId() const
{
    return this->userId;
}

void TCPCommand::setUserId(int userId)
{
    this->userId = userId;
}

class TCPCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPCommandDescriptor();
    virtual ~TCPCommandDescriptor();

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

Register_ClassDescriptor(TCPCommandDescriptor)

TCPCommandDescriptor::TCPCommandDescriptor() : omnetpp::cClassDescriptor("inet::TCPCommand", "omnetpp::cObject")
{
    propertynames = nullptr;
}

TCPCommandDescriptor::~TCPCommandDescriptor()
{
    delete[] propertynames;
}

bool TCPCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPCommand *>(obj)!=nullptr;
}

const char **TCPCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TCPCommandDescriptor::getFieldTypeFlags(int field) const
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

const char *TCPCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "connId",
        "userId",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int TCPCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "connId")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "userId")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPCommand *pp = (TCPCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPCommand *pp = (TCPCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPCommand *pp = (TCPCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getConnId());
        case 1: return long2string(pp->getUserId());
        default: return "";
    }
}

bool TCPCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPCommand *pp = (TCPCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setConnId(string2long(value)); return true;
        case 1: pp->setUserId(string2long(value)); return true;
        default: return false;
    }
}

const char *TCPCommandDescriptor::getFieldStructName(int field) const
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

void *TCPCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPCommand *pp = (TCPCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPErrorInfo)

TCPErrorInfo::TCPErrorInfo() : ::inet::TCPCommand()
{
    this->errorCode = 0;
}

TCPErrorInfo::TCPErrorInfo(const TCPErrorInfo& other) : ::inet::TCPCommand(other)
{
    copy(other);
}

TCPErrorInfo::~TCPErrorInfo()
{
}

TCPErrorInfo& TCPErrorInfo::operator=(const TCPErrorInfo& other)
{
    if (this==&other) return *this;
    ::inet::TCPCommand::operator=(other);
    copy(other);
    return *this;
}

void TCPErrorInfo::copy(const TCPErrorInfo& other)
{
    this->errorCode = other.errorCode;
    this->messageText = other.messageText;
}

void TCPErrorInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TCPCommand::parsimPack(b);
    doParsimPacking(b,this->errorCode);
    doParsimPacking(b,this->messageText);
}

void TCPErrorInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TCPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->errorCode);
    doParsimUnpacking(b,this->messageText);
}

int TCPErrorInfo::getErrorCode() const
{
    return this->errorCode;
}

void TCPErrorInfo::setErrorCode(int errorCode)
{
    this->errorCode = errorCode;
}

const char * TCPErrorInfo::getMessageText() const
{
    return this->messageText.c_str();
}

void TCPErrorInfo::setMessageText(const char * messageText)
{
    this->messageText = messageText;
}

class TCPErrorInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPErrorInfoDescriptor();
    virtual ~TCPErrorInfoDescriptor();

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

Register_ClassDescriptor(TCPErrorInfoDescriptor)

TCPErrorInfoDescriptor::TCPErrorInfoDescriptor() : omnetpp::cClassDescriptor("inet::TCPErrorInfo", "inet::TCPCommand")
{
    propertynames = nullptr;
}

TCPErrorInfoDescriptor::~TCPErrorInfoDescriptor()
{
    delete[] propertynames;
}

bool TCPErrorInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPErrorInfo *>(obj)!=nullptr;
}

const char **TCPErrorInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPErrorInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPErrorInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TCPErrorInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *TCPErrorInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "errorCode",
        "messageText",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int TCPErrorInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorCode")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageText")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPErrorInfoDescriptor::getFieldTypeString(int field) const
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

const char **TCPErrorInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPErrorInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::TCPErrorCode";
            return nullptr;
        default: return nullptr;
    }
}

int TCPErrorInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPErrorInfo *pp = (TCPErrorInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPErrorInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPErrorInfo *pp = (TCPErrorInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPErrorInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPErrorInfo *pp = (TCPErrorInfo *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getErrorCode(), "inet::TCPErrorCode");
        case 1: return oppstring2string(pp->getMessageText());
        default: return "";
    }
}

bool TCPErrorInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPErrorInfo *pp = (TCPErrorInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setErrorCode((inet::TCPErrorCode)string2enum(value, "inet::TCPErrorCode")); return true;
        case 1: pp->setMessageText((value)); return true;
        default: return false;
    }
}

const char *TCPErrorInfoDescriptor::getFieldStructName(int field) const
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

void *TCPErrorInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPErrorInfo *pp = (TCPErrorInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::TCPDataTransferMode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::TCPDataTransferMode"));
    e->insert(TCP_TRANSFER_UNDEFINED, "TCP_TRANSFER_UNDEFINED");
    e->insert(TCP_TRANSFER_BYTECOUNT, "TCP_TRANSFER_BYTECOUNT");
    e->insert(TCP_TRANSFER_OBJECT, "TCP_TRANSFER_OBJECT");
    e->insert(TCP_TRANSFER_BYTESTREAM, "TCP_TRANSFER_BYTESTREAM");
)

Register_Class(TCPOpenCommand)

TCPOpenCommand::TCPOpenCommand() : ::inet::TCPCommand()
{
    this->localPort = -1;
    this->remotePort = -1;
    this->fork = false;
    this->dataTransferMode = 0;
}

TCPOpenCommand::TCPOpenCommand(const TCPOpenCommand& other) : ::inet::TCPCommand(other)
{
    copy(other);
}

TCPOpenCommand::~TCPOpenCommand()
{
}

TCPOpenCommand& TCPOpenCommand::operator=(const TCPOpenCommand& other)
{
    if (this==&other) return *this;
    ::inet::TCPCommand::operator=(other);
    copy(other);
    return *this;
}

void TCPOpenCommand::copy(const TCPOpenCommand& other)
{
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
    this->fork = other.fork;
    this->dataTransferMode = other.dataTransferMode;
    this->tcpAlgorithmClass = other.tcpAlgorithmClass;
}

void TCPOpenCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TCPCommand::parsimPack(b);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
    doParsimPacking(b,this->fork);
    doParsimPacking(b,this->dataTransferMode);
    doParsimPacking(b,this->tcpAlgorithmClass);
}

void TCPOpenCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TCPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
    doParsimUnpacking(b,this->fork);
    doParsimUnpacking(b,this->dataTransferMode);
    doParsimUnpacking(b,this->tcpAlgorithmClass);
}

L3Address& TCPOpenCommand::getLocalAddr()
{
    return this->localAddr;
}

void TCPOpenCommand::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

L3Address& TCPOpenCommand::getRemoteAddr()
{
    return this->remoteAddr;
}

void TCPOpenCommand::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int TCPOpenCommand::getLocalPort() const
{
    return this->localPort;
}

void TCPOpenCommand::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int TCPOpenCommand::getRemotePort() const
{
    return this->remotePort;
}

void TCPOpenCommand::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

bool TCPOpenCommand::getFork() const
{
    return this->fork;
}

void TCPOpenCommand::setFork(bool fork)
{
    this->fork = fork;
}

int TCPOpenCommand::getDataTransferMode() const
{
    return this->dataTransferMode;
}

void TCPOpenCommand::setDataTransferMode(int dataTransferMode)
{
    this->dataTransferMode = dataTransferMode;
}

const char * TCPOpenCommand::getTcpAlgorithmClass() const
{
    return this->tcpAlgorithmClass.c_str();
}

void TCPOpenCommand::setTcpAlgorithmClass(const char * tcpAlgorithmClass)
{
    this->tcpAlgorithmClass = tcpAlgorithmClass;
}

class TCPOpenCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOpenCommandDescriptor();
    virtual ~TCPOpenCommandDescriptor();

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

Register_ClassDescriptor(TCPOpenCommandDescriptor)

TCPOpenCommandDescriptor::TCPOpenCommandDescriptor() : omnetpp::cClassDescriptor("inet::TCPOpenCommand", "inet::TCPCommand")
{
    propertynames = nullptr;
}

TCPOpenCommandDescriptor::~TCPOpenCommandDescriptor()
{
    delete[] propertynames;
}

bool TCPOpenCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOpenCommand *>(obj)!=nullptr;
}

const char **TCPOpenCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOpenCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOpenCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int TCPOpenCommandDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *TCPOpenCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
        "fork",
        "dataTransferMode",
        "tcpAlgorithmClass",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int TCPOpenCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localAddr")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "localPort")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "remotePort")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "fork")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataTransferMode")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "tcpAlgorithmClass")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOpenCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "L3Address",
        "int",
        "int",
        "bool",
        "int",
        "string",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPOpenCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *TCPOpenCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5:
            if (!strcmp(propertyname,"enum")) return "inet::TCPDataTransferMode";
            return nullptr;
        default: return nullptr;
    }
}

int TCPOpenCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOpenCommand *pp = (TCPOpenCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPOpenCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOpenCommand *pp = (TCPOpenCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOpenCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOpenCommand *pp = (TCPOpenCommand *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getLocalAddr(); return out.str();}
        case 1: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 2: return long2string(pp->getLocalPort());
        case 3: return long2string(pp->getRemotePort());
        case 4: return bool2string(pp->getFork());
        case 5: return enum2string(pp->getDataTransferMode(), "inet::TCPDataTransferMode");
        case 6: return oppstring2string(pp->getTcpAlgorithmClass());
        default: return "";
    }
}

bool TCPOpenCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOpenCommand *pp = (TCPOpenCommand *)object; (void)pp;
    switch (field) {
        case 2: pp->setLocalPort(string2long(value)); return true;
        case 3: pp->setRemotePort(string2long(value)); return true;
        case 4: pp->setFork(string2bool(value)); return true;
        case 5: pp->setDataTransferMode((inet::TCPDataTransferMode)string2enum(value, "inet::TCPDataTransferMode")); return true;
        case 6: pp->setTcpAlgorithmClass((value)); return true;
        default: return false;
    }
}

const char *TCPOpenCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *TCPOpenCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOpenCommand *pp = (TCPOpenCommand *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getLocalAddr()); break;
        case 1: return (void *)(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(TCPSendCommand)

TCPSendCommand::TCPSendCommand() : ::inet::TCPCommand()
{
}

TCPSendCommand::TCPSendCommand(const TCPSendCommand& other) : ::inet::TCPCommand(other)
{
    copy(other);
}

TCPSendCommand::~TCPSendCommand()
{
}

TCPSendCommand& TCPSendCommand::operator=(const TCPSendCommand& other)
{
    if (this==&other) return *this;
    ::inet::TCPCommand::operator=(other);
    copy(other);
    return *this;
}

void TCPSendCommand::copy(const TCPSendCommand& other)
{
}

void TCPSendCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TCPCommand::parsimPack(b);
}

void TCPSendCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TCPCommand::parsimUnpack(b);
}

class TCPSendCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPSendCommandDescriptor();
    virtual ~TCPSendCommandDescriptor();

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

Register_ClassDescriptor(TCPSendCommandDescriptor)

TCPSendCommandDescriptor::TCPSendCommandDescriptor() : omnetpp::cClassDescriptor("inet::TCPSendCommand", "inet::TCPCommand")
{
    propertynames = nullptr;
}

TCPSendCommandDescriptor::~TCPSendCommandDescriptor()
{
    delete[] propertynames;
}

bool TCPSendCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPSendCommand *>(obj)!=nullptr;
}

const char **TCPSendCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPSendCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPSendCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TCPSendCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TCPSendCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TCPSendCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPSendCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TCPSendCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPSendCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPSendCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPSendCommand *pp = (TCPSendCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPSendCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPSendCommand *pp = (TCPSendCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPSendCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPSendCommand *pp = (TCPSendCommand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TCPSendCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPSendCommand *pp = (TCPSendCommand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TCPSendCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TCPSendCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPSendCommand *pp = (TCPSendCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPConnectInfo)

TCPConnectInfo::TCPConnectInfo() : ::inet::TCPCommand()
{
    this->localPort = 0;
    this->remotePort = 0;
}

TCPConnectInfo::TCPConnectInfo(const TCPConnectInfo& other) : ::inet::TCPCommand(other)
{
    copy(other);
}

TCPConnectInfo::~TCPConnectInfo()
{
}

TCPConnectInfo& TCPConnectInfo::operator=(const TCPConnectInfo& other)
{
    if (this==&other) return *this;
    ::inet::TCPCommand::operator=(other);
    copy(other);
    return *this;
}

void TCPConnectInfo::copy(const TCPConnectInfo& other)
{
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
}

void TCPConnectInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TCPCommand::parsimPack(b);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
}

void TCPConnectInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TCPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
}

L3Address& TCPConnectInfo::getLocalAddr()
{
    return this->localAddr;
}

void TCPConnectInfo::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

L3Address& TCPConnectInfo::getRemoteAddr()
{
    return this->remoteAddr;
}

void TCPConnectInfo::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int TCPConnectInfo::getLocalPort() const
{
    return this->localPort;
}

void TCPConnectInfo::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int TCPConnectInfo::getRemotePort() const
{
    return this->remotePort;
}

void TCPConnectInfo::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

class TCPConnectInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPConnectInfoDescriptor();
    virtual ~TCPConnectInfoDescriptor();

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

Register_ClassDescriptor(TCPConnectInfoDescriptor)

TCPConnectInfoDescriptor::TCPConnectInfoDescriptor() : omnetpp::cClassDescriptor("inet::TCPConnectInfo", "inet::TCPCommand")
{
    propertynames = nullptr;
}

TCPConnectInfoDescriptor::~TCPConnectInfoDescriptor()
{
    delete[] propertynames;
}

bool TCPConnectInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPConnectInfo *>(obj)!=nullptr;
}

const char **TCPConnectInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPConnectInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPConnectInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int TCPConnectInfoDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *TCPConnectInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int TCPConnectInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localAddr")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "localPort")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "remotePort")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPConnectInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "L3Address",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPConnectInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPConnectInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPConnectInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPConnectInfo *pp = (TCPConnectInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPConnectInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPConnectInfo *pp = (TCPConnectInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPConnectInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPConnectInfo *pp = (TCPConnectInfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getLocalAddr(); return out.str();}
        case 1: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 2: return long2string(pp->getLocalPort());
        case 3: return long2string(pp->getRemotePort());
        default: return "";
    }
}

bool TCPConnectInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPConnectInfo *pp = (TCPConnectInfo *)object; (void)pp;
    switch (field) {
        case 2: pp->setLocalPort(string2long(value)); return true;
        case 3: pp->setRemotePort(string2long(value)); return true;
        default: return false;
    }
}

const char *TCPConnectInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        case 1: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *TCPConnectInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPConnectInfo *pp = (TCPConnectInfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getLocalAddr()); break;
        case 1: return (void *)(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(TCPStatusInfo)

TCPStatusInfo::TCPStatusInfo() : ::inet::TCPCommand()
{
    this->state = 0;
    this->localPort = 0;
    this->remotePort = 0;
    this->snd_mss = 0;
    this->snd_una = 0;
    this->snd_nxt = 0;
    this->snd_max = 0;
    this->snd_wnd = 0;
    this->snd_up = 0;
    this->snd_wl1 = 0;
    this->snd_wl2 = 0;
    this->iss = 0;
    this->rcv_nxt = 0;
    this->rcv_wnd = 0;
    this->rcv_up = 0;
    this->irs = 0;
    this->fin_ack_rcvd = false;
}

TCPStatusInfo::TCPStatusInfo(const TCPStatusInfo& other) : ::inet::TCPCommand(other)
{
    copy(other);
}

TCPStatusInfo::~TCPStatusInfo()
{
}

TCPStatusInfo& TCPStatusInfo::operator=(const TCPStatusInfo& other)
{
    if (this==&other) return *this;
    ::inet::TCPCommand::operator=(other);
    copy(other);
    return *this;
}

void TCPStatusInfo::copy(const TCPStatusInfo& other)
{
    this->state = other.state;
    this->stateName = other.stateName;
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
    this->snd_mss = other.snd_mss;
    this->snd_una = other.snd_una;
    this->snd_nxt = other.snd_nxt;
    this->snd_max = other.snd_max;
    this->snd_wnd = other.snd_wnd;
    this->snd_up = other.snd_up;
    this->snd_wl1 = other.snd_wl1;
    this->snd_wl2 = other.snd_wl2;
    this->iss = other.iss;
    this->rcv_nxt = other.rcv_nxt;
    this->rcv_wnd = other.rcv_wnd;
    this->rcv_up = other.rcv_up;
    this->irs = other.irs;
    this->fin_ack_rcvd = other.fin_ack_rcvd;
}

void TCPStatusInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::TCPCommand::parsimPack(b);
    doParsimPacking(b,this->state);
    doParsimPacking(b,this->stateName);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
    doParsimPacking(b,this->snd_mss);
    doParsimPacking(b,this->snd_una);
    doParsimPacking(b,this->snd_nxt);
    doParsimPacking(b,this->snd_max);
    doParsimPacking(b,this->snd_wnd);
    doParsimPacking(b,this->snd_up);
    doParsimPacking(b,this->snd_wl1);
    doParsimPacking(b,this->snd_wl2);
    doParsimPacking(b,this->iss);
    doParsimPacking(b,this->rcv_nxt);
    doParsimPacking(b,this->rcv_wnd);
    doParsimPacking(b,this->rcv_up);
    doParsimPacking(b,this->irs);
    doParsimPacking(b,this->fin_ack_rcvd);
}

void TCPStatusInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::TCPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->state);
    doParsimUnpacking(b,this->stateName);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
    doParsimUnpacking(b,this->snd_mss);
    doParsimUnpacking(b,this->snd_una);
    doParsimUnpacking(b,this->snd_nxt);
    doParsimUnpacking(b,this->snd_max);
    doParsimUnpacking(b,this->snd_wnd);
    doParsimUnpacking(b,this->snd_up);
    doParsimUnpacking(b,this->snd_wl1);
    doParsimUnpacking(b,this->snd_wl2);
    doParsimUnpacking(b,this->iss);
    doParsimUnpacking(b,this->rcv_nxt);
    doParsimUnpacking(b,this->rcv_wnd);
    doParsimUnpacking(b,this->rcv_up);
    doParsimUnpacking(b,this->irs);
    doParsimUnpacking(b,this->fin_ack_rcvd);
}

int TCPStatusInfo::getState() const
{
    return this->state;
}

void TCPStatusInfo::setState(int state)
{
    this->state = state;
}

const char * TCPStatusInfo::getStateName() const
{
    return this->stateName.c_str();
}

void TCPStatusInfo::setStateName(const char * stateName)
{
    this->stateName = stateName;
}

L3Address& TCPStatusInfo::getLocalAddr()
{
    return this->localAddr;
}

void TCPStatusInfo::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

L3Address& TCPStatusInfo::getRemoteAddr()
{
    return this->remoteAddr;
}

void TCPStatusInfo::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int TCPStatusInfo::getLocalPort() const
{
    return this->localPort;
}

void TCPStatusInfo::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int TCPStatusInfo::getRemotePort() const
{
    return this->remotePort;
}

void TCPStatusInfo::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

unsigned int TCPStatusInfo::getSnd_mss() const
{
    return this->snd_mss;
}

void TCPStatusInfo::setSnd_mss(unsigned int snd_mss)
{
    this->snd_mss = snd_mss;
}

unsigned int TCPStatusInfo::getSnd_una() const
{
    return this->snd_una;
}

void TCPStatusInfo::setSnd_una(unsigned int snd_una)
{
    this->snd_una = snd_una;
}

unsigned int TCPStatusInfo::getSnd_nxt() const
{
    return this->snd_nxt;
}

void TCPStatusInfo::setSnd_nxt(unsigned int snd_nxt)
{
    this->snd_nxt = snd_nxt;
}

unsigned int TCPStatusInfo::getSnd_max() const
{
    return this->snd_max;
}

void TCPStatusInfo::setSnd_max(unsigned int snd_max)
{
    this->snd_max = snd_max;
}

unsigned int TCPStatusInfo::getSnd_wnd() const
{
    return this->snd_wnd;
}

void TCPStatusInfo::setSnd_wnd(unsigned int snd_wnd)
{
    this->snd_wnd = snd_wnd;
}

unsigned int TCPStatusInfo::getSnd_up() const
{
    return this->snd_up;
}

void TCPStatusInfo::setSnd_up(unsigned int snd_up)
{
    this->snd_up = snd_up;
}

unsigned int TCPStatusInfo::getSnd_wl1() const
{
    return this->snd_wl1;
}

void TCPStatusInfo::setSnd_wl1(unsigned int snd_wl1)
{
    this->snd_wl1 = snd_wl1;
}

unsigned int TCPStatusInfo::getSnd_wl2() const
{
    return this->snd_wl2;
}

void TCPStatusInfo::setSnd_wl2(unsigned int snd_wl2)
{
    this->snd_wl2 = snd_wl2;
}

unsigned int TCPStatusInfo::getIss() const
{
    return this->iss;
}

void TCPStatusInfo::setIss(unsigned int iss)
{
    this->iss = iss;
}

unsigned int TCPStatusInfo::getRcv_nxt() const
{
    return this->rcv_nxt;
}

void TCPStatusInfo::setRcv_nxt(unsigned int rcv_nxt)
{
    this->rcv_nxt = rcv_nxt;
}

unsigned int TCPStatusInfo::getRcv_wnd() const
{
    return this->rcv_wnd;
}

void TCPStatusInfo::setRcv_wnd(unsigned int rcv_wnd)
{
    this->rcv_wnd = rcv_wnd;
}

unsigned int TCPStatusInfo::getRcv_up() const
{
    return this->rcv_up;
}

void TCPStatusInfo::setRcv_up(unsigned int rcv_up)
{
    this->rcv_up = rcv_up;
}

unsigned int TCPStatusInfo::getIrs() const
{
    return this->irs;
}

void TCPStatusInfo::setIrs(unsigned int irs)
{
    this->irs = irs;
}

bool TCPStatusInfo::getFin_ack_rcvd() const
{
    return this->fin_ack_rcvd;
}

void TCPStatusInfo::setFin_ack_rcvd(bool fin_ack_rcvd)
{
    this->fin_ack_rcvd = fin_ack_rcvd;
}

class TCPStatusInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPStatusInfoDescriptor();
    virtual ~TCPStatusInfoDescriptor();

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

Register_ClassDescriptor(TCPStatusInfoDescriptor)

TCPStatusInfoDescriptor::TCPStatusInfoDescriptor() : omnetpp::cClassDescriptor("inet::TCPStatusInfo", "inet::TCPCommand")
{
    propertynames = nullptr;
}

TCPStatusInfoDescriptor::~TCPStatusInfoDescriptor()
{
    delete[] propertynames;
}

bool TCPStatusInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPStatusInfo *>(obj)!=nullptr;
}

const char **TCPStatusInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPStatusInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPStatusInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 20+basedesc->getFieldCount() : 20;
}

unsigned int TCPStatusInfoDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<20) ? fieldTypeFlags[field] : 0;
}

const char *TCPStatusInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "state",
        "stateName",
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
        "snd_mss",
        "snd_una",
        "snd_nxt",
        "snd_max",
        "snd_wnd",
        "snd_up",
        "snd_wl1",
        "snd_wl2",
        "iss",
        "rcv_nxt",
        "rcv_wnd",
        "rcv_up",
        "irs",
        "fin_ack_rcvd",
    };
    return (field>=0 && field<20) ? fieldNames[field] : nullptr;
}

int TCPStatusInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "state")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stateName")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "localAddr")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "localPort")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "remotePort")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "snd_mss")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "snd_una")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "snd_nxt")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "snd_max")==0) return base+9;
    if (fieldName[0]=='s' && strcmp(fieldName, "snd_wnd")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "snd_up")==0) return base+11;
    if (fieldName[0]=='s' && strcmp(fieldName, "snd_wl1")==0) return base+12;
    if (fieldName[0]=='s' && strcmp(fieldName, "snd_wl2")==0) return base+13;
    if (fieldName[0]=='i' && strcmp(fieldName, "iss")==0) return base+14;
    if (fieldName[0]=='r' && strcmp(fieldName, "rcv_nxt")==0) return base+15;
    if (fieldName[0]=='r' && strcmp(fieldName, "rcv_wnd")==0) return base+16;
    if (fieldName[0]=='r' && strcmp(fieldName, "rcv_up")==0) return base+17;
    if (fieldName[0]=='i' && strcmp(fieldName, "irs")==0) return base+18;
    if (fieldName[0]=='f' && strcmp(fieldName, "fin_ack_rcvd")==0) return base+19;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPStatusInfoDescriptor::getFieldTypeString(int field) const
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
        "L3Address",
        "L3Address",
        "int",
        "int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "bool",
    };
    return (field>=0 && field<20) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPStatusInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPStatusInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPStatusInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPStatusInfo *pp = (TCPStatusInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPStatusInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPStatusInfo *pp = (TCPStatusInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPStatusInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPStatusInfo *pp = (TCPStatusInfo *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getState());
        case 1: return oppstring2string(pp->getStateName());
        case 2: {std::stringstream out; out << pp->getLocalAddr(); return out.str();}
        case 3: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 4: return long2string(pp->getLocalPort());
        case 5: return long2string(pp->getRemotePort());
        case 6: return ulong2string(pp->getSnd_mss());
        case 7: return ulong2string(pp->getSnd_una());
        case 8: return ulong2string(pp->getSnd_nxt());
        case 9: return ulong2string(pp->getSnd_max());
        case 10: return ulong2string(pp->getSnd_wnd());
        case 11: return ulong2string(pp->getSnd_up());
        case 12: return ulong2string(pp->getSnd_wl1());
        case 13: return ulong2string(pp->getSnd_wl2());
        case 14: return ulong2string(pp->getIss());
        case 15: return ulong2string(pp->getRcv_nxt());
        case 16: return ulong2string(pp->getRcv_wnd());
        case 17: return ulong2string(pp->getRcv_up());
        case 18: return ulong2string(pp->getIrs());
        case 19: return bool2string(pp->getFin_ack_rcvd());
        default: return "";
    }
}

bool TCPStatusInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPStatusInfo *pp = (TCPStatusInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setState(string2long(value)); return true;
        case 1: pp->setStateName((value)); return true;
        case 4: pp->setLocalPort(string2long(value)); return true;
        case 5: pp->setRemotePort(string2long(value)); return true;
        case 6: pp->setSnd_mss(string2ulong(value)); return true;
        case 7: pp->setSnd_una(string2ulong(value)); return true;
        case 8: pp->setSnd_nxt(string2ulong(value)); return true;
        case 9: pp->setSnd_max(string2ulong(value)); return true;
        case 10: pp->setSnd_wnd(string2ulong(value)); return true;
        case 11: pp->setSnd_up(string2ulong(value)); return true;
        case 12: pp->setSnd_wl1(string2ulong(value)); return true;
        case 13: pp->setSnd_wl2(string2ulong(value)); return true;
        case 14: pp->setIss(string2ulong(value)); return true;
        case 15: pp->setRcv_nxt(string2ulong(value)); return true;
        case 16: pp->setRcv_wnd(string2ulong(value)); return true;
        case 17: pp->setRcv_up(string2ulong(value)); return true;
        case 18: pp->setIrs(string2ulong(value)); return true;
        case 19: pp->setFin_ack_rcvd(string2bool(value)); return true;
        default: return false;
    }
}

const char *TCPStatusInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        case 3: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *TCPStatusInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPStatusInfo *pp = (TCPStatusInfo *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getLocalAddr()); break;
        case 3: return (void *)(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

} // namespace inet

