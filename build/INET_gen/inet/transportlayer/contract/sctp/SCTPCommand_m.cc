//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/contract/sctp/SCTPCommand.msg.
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
#include "SCTPCommand_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::SCTPErrorCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::SCTPErrorCode"));
)

Register_Class(SCTPCommand)

SCTPCommand::SCTPCommand(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->assocId = -1;
    this->sid = -1;
    this->numMsgs = 1;
    this->ssn = -1;
    this->sendUnordered = false;
    this->prValue = 0;
    this->localPort = -1;
    this->remotePort = -1;
    this->gate = -1;
    this->fd = -1;
}

SCTPCommand::SCTPCommand(const SCTPCommand& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SCTPCommand::~SCTPCommand()
{
}

SCTPCommand& SCTPCommand::operator=(const SCTPCommand& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPCommand::copy(const SCTPCommand& other)
{
    this->assocId = other.assocId;
    this->sid = other.sid;
    this->numMsgs = other.numMsgs;
    this->ssn = other.ssn;
    this->sendUnordered = other.sendUnordered;
    this->prValue = other.prValue;
    this->localAddr = other.localAddr;
    this->remoteAddr = other.remoteAddr;
    this->localPort = other.localPort;
    this->remotePort = other.remotePort;
    this->gate = other.gate;
    this->fd = other.fd;
}

void SCTPCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->assocId);
    doParsimPacking(b,this->sid);
    doParsimPacking(b,this->numMsgs);
    doParsimPacking(b,this->ssn);
    doParsimPacking(b,this->sendUnordered);
    doParsimPacking(b,this->prValue);
    doParsimPacking(b,this->localAddr);
    doParsimPacking(b,this->remoteAddr);
    doParsimPacking(b,this->localPort);
    doParsimPacking(b,this->remotePort);
    doParsimPacking(b,this->gate);
    doParsimPacking(b,this->fd);
}

void SCTPCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->assocId);
    doParsimUnpacking(b,this->sid);
    doParsimUnpacking(b,this->numMsgs);
    doParsimUnpacking(b,this->ssn);
    doParsimUnpacking(b,this->sendUnordered);
    doParsimUnpacking(b,this->prValue);
    doParsimUnpacking(b,this->localAddr);
    doParsimUnpacking(b,this->remoteAddr);
    doParsimUnpacking(b,this->localPort);
    doParsimUnpacking(b,this->remotePort);
    doParsimUnpacking(b,this->gate);
    doParsimUnpacking(b,this->fd);
}

int SCTPCommand::getAssocId() const
{
    return this->assocId;
}

void SCTPCommand::setAssocId(int assocId)
{
    this->assocId = assocId;
}

int SCTPCommand::getSid() const
{
    return this->sid;
}

void SCTPCommand::setSid(int sid)
{
    this->sid = sid;
}

int SCTPCommand::getNumMsgs() const
{
    return this->numMsgs;
}

void SCTPCommand::setNumMsgs(int numMsgs)
{
    this->numMsgs = numMsgs;
}

int SCTPCommand::getSsn() const
{
    return this->ssn;
}

void SCTPCommand::setSsn(int ssn)
{
    this->ssn = ssn;
}

unsigned short SCTPCommand::getSendUnordered() const
{
    return this->sendUnordered;
}

void SCTPCommand::setSendUnordered(unsigned short sendUnordered)
{
    this->sendUnordered = sendUnordered;
}

double SCTPCommand::getPrValue() const
{
    return this->prValue;
}

void SCTPCommand::setPrValue(double prValue)
{
    this->prValue = prValue;
}

L3Address& SCTPCommand::getLocalAddr()
{
    return this->localAddr;
}

void SCTPCommand::setLocalAddr(const L3Address& localAddr)
{
    this->localAddr = localAddr;
}

L3Address& SCTPCommand::getRemoteAddr()
{
    return this->remoteAddr;
}

void SCTPCommand::setRemoteAddr(const L3Address& remoteAddr)
{
    this->remoteAddr = remoteAddr;
}

int SCTPCommand::getLocalPort() const
{
    return this->localPort;
}

void SCTPCommand::setLocalPort(int localPort)
{
    this->localPort = localPort;
}

int SCTPCommand::getRemotePort() const
{
    return this->remotePort;
}

void SCTPCommand::setRemotePort(int remotePort)
{
    this->remotePort = remotePort;
}

int SCTPCommand::getGate() const
{
    return this->gate;
}

void SCTPCommand::setGate(int gate)
{
    this->gate = gate;
}

int SCTPCommand::getFd() const
{
    return this->fd;
}

void SCTPCommand::setFd(int fd)
{
    this->fd = fd;
}

class SCTPCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPCommandDescriptor();
    virtual ~SCTPCommandDescriptor();

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

Register_ClassDescriptor(SCTPCommandDescriptor)

SCTPCommandDescriptor::SCTPCommandDescriptor() : omnetpp::cClassDescriptor("inet::SCTPCommand", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SCTPCommandDescriptor::~SCTPCommandDescriptor()
{
    delete[] propertynames;
}

bool SCTPCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPCommand *>(obj)!=nullptr;
}

const char **SCTPCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int SCTPCommandDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *SCTPCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "assocId",
        "sid",
        "numMsgs",
        "ssn",
        "sendUnordered",
        "prValue",
        "localAddr",
        "remoteAddr",
        "localPort",
        "remotePort",
        "gate",
        "fd",
    };
    return (field>=0 && field<12) ? fieldNames[field] : nullptr;
}

int SCTPCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "assocId")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sid")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "numMsgs")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssn")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "sendUnordered")==0) return base+4;
    if (fieldName[0]=='p' && strcmp(fieldName, "prValue")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "localAddr")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddr")==0) return base+7;
    if (fieldName[0]=='l' && strcmp(fieldName, "localPort")==0) return base+8;
    if (fieldName[0]=='r' && strcmp(fieldName, "remotePort")==0) return base+9;
    if (fieldName[0]=='g' && strcmp(fieldName, "gate")==0) return base+10;
    if (fieldName[0]=='f' && strcmp(fieldName, "fd")==0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPCommandDescriptor::getFieldTypeString(int field) const
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
        "int",
        "int",
        "unsigned short",
        "double",
        "L3Address",
        "L3Address",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPCommand *pp = (SCTPCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPCommand *pp = (SCTPCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPCommand *pp = (SCTPCommand *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getAssocId());
        case 1: return long2string(pp->getSid());
        case 2: return long2string(pp->getNumMsgs());
        case 3: return long2string(pp->getSsn());
        case 4: return ulong2string(pp->getSendUnordered());
        case 5: return double2string(pp->getPrValue());
        case 6: {std::stringstream out; out << pp->getLocalAddr(); return out.str();}
        case 7: {std::stringstream out; out << pp->getRemoteAddr(); return out.str();}
        case 8: return long2string(pp->getLocalPort());
        case 9: return long2string(pp->getRemotePort());
        case 10: return long2string(pp->getGate());
        case 11: return long2string(pp->getFd());
        default: return "";
    }
}

bool SCTPCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPCommand *pp = (SCTPCommand *)object; (void)pp;
    switch (field) {
        case 0: pp->setAssocId(string2long(value)); return true;
        case 1: pp->setSid(string2long(value)); return true;
        case 2: pp->setNumMsgs(string2long(value)); return true;
        case 3: pp->setSsn(string2long(value)); return true;
        case 4: pp->setSendUnordered(string2ulong(value)); return true;
        case 5: pp->setPrValue(string2double(value)); return true;
        case 8: pp->setLocalPort(string2long(value)); return true;
        case 9: pp->setRemotePort(string2long(value)); return true;
        case 10: pp->setGate(string2long(value)); return true;
        case 11: pp->setFd(string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 6: return omnetpp::opp_typename(typeid(L3Address));
        case 7: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPCommand *pp = (SCTPCommand *)object; (void)pp;
    switch (field) {
        case 6: return (void *)(&pp->getLocalAddr()); break;
        case 7: return (void *)(&pp->getRemoteAddr()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPErrorInfo)

SCTPErrorInfo::SCTPErrorInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->errorCode = 0;
}

SCTPErrorInfo::SCTPErrorInfo(const SCTPErrorInfo& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPErrorInfo::~SCTPErrorInfo()
{
}

SCTPErrorInfo& SCTPErrorInfo::operator=(const SCTPErrorInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPErrorInfo::copy(const SCTPErrorInfo& other)
{
    this->errorCode = other.errorCode;
    this->messageText = other.messageText;
}

void SCTPErrorInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->errorCode);
    doParsimPacking(b,this->messageText);
}

void SCTPErrorInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->errorCode);
    doParsimUnpacking(b,this->messageText);
}

int SCTPErrorInfo::getErrorCode() const
{
    return this->errorCode;
}

void SCTPErrorInfo::setErrorCode(int errorCode)
{
    this->errorCode = errorCode;
}

const char * SCTPErrorInfo::getMessageText() const
{
    return this->messageText.c_str();
}

void SCTPErrorInfo::setMessageText(const char * messageText)
{
    this->messageText = messageText;
}

class SCTPErrorInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPErrorInfoDescriptor();
    virtual ~SCTPErrorInfoDescriptor();

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

Register_ClassDescriptor(SCTPErrorInfoDescriptor)

SCTPErrorInfoDescriptor::SCTPErrorInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPErrorInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPErrorInfoDescriptor::~SCTPErrorInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPErrorInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPErrorInfo *>(obj)!=nullptr;
}

const char **SCTPErrorInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPErrorInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPErrorInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SCTPErrorInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPErrorInfoDescriptor::getFieldName(int field) const
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

int SCTPErrorInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "errorCode")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageText")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPErrorInfoDescriptor::getFieldTypeString(int field) const
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

const char **SCTPErrorInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPErrorInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::SCTPErrorCode";
            return nullptr;
        default: return nullptr;
    }
}

int SCTPErrorInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorInfo *pp = (SCTPErrorInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPErrorInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorInfo *pp = (SCTPErrorInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPErrorInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorInfo *pp = (SCTPErrorInfo *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getErrorCode(), "inet::SCTPErrorCode");
        case 1: return oppstring2string(pp->getMessageText());
        default: return "";
    }
}

bool SCTPErrorInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorInfo *pp = (SCTPErrorInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setErrorCode((inet::SCTPErrorCode)string2enum(value, "inet::SCTPErrorCode")); return true;
        case 1: pp->setMessageText((value)); return true;
        default: return false;
    }
}

const char *SCTPErrorInfoDescriptor::getFieldStructName(int field) const
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

void *SCTPErrorInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPErrorInfo *pp = (SCTPErrorInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPOpenCommand)

SCTPOpenCommand::SCTPOpenCommand(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->fork = false;
    this->queueClass = "SCTPQueue";
    this->inboundStreams = 0;
    this->outboundStreams = 0;
    this->streamReset = false;
    this->appLimited = false;
    this->prMethod = 0;
    this->numRequests = 0;
    this->messagesToPush = 0;
}

SCTPOpenCommand::SCTPOpenCommand(const SCTPOpenCommand& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPOpenCommand::~SCTPOpenCommand()
{
}

SCTPOpenCommand& SCTPOpenCommand::operator=(const SCTPOpenCommand& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPOpenCommand::copy(const SCTPOpenCommand& other)
{
    this->localAddresses = other.localAddresses;
    this->remoteAddresses = other.remoteAddresses;
    this->fork = other.fork;
    this->queueClass = other.queueClass;
    this->sctpAlgorithmClass = other.sctpAlgorithmClass;
    this->inboundStreams = other.inboundStreams;
    this->outboundStreams = other.outboundStreams;
    this->streamReset = other.streamReset;
    this->appLimited = other.appLimited;
    this->prMethod = other.prMethod;
    this->numRequests = other.numRequests;
    this->messagesToPush = other.messagesToPush;
}

void SCTPOpenCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->localAddresses);
    doParsimPacking(b,this->remoteAddresses);
    doParsimPacking(b,this->fork);
    doParsimPacking(b,this->queueClass);
    doParsimPacking(b,this->sctpAlgorithmClass);
    doParsimPacking(b,this->inboundStreams);
    doParsimPacking(b,this->outboundStreams);
    doParsimPacking(b,this->streamReset);
    doParsimPacking(b,this->appLimited);
    doParsimPacking(b,this->prMethod);
    doParsimPacking(b,this->numRequests);
    doParsimPacking(b,this->messagesToPush);
}

void SCTPOpenCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->localAddresses);
    doParsimUnpacking(b,this->remoteAddresses);
    doParsimUnpacking(b,this->fork);
    doParsimUnpacking(b,this->queueClass);
    doParsimUnpacking(b,this->sctpAlgorithmClass);
    doParsimUnpacking(b,this->inboundStreams);
    doParsimUnpacking(b,this->outboundStreams);
    doParsimUnpacking(b,this->streamReset);
    doParsimUnpacking(b,this->appLimited);
    doParsimUnpacking(b,this->prMethod);
    doParsimUnpacking(b,this->numRequests);
    doParsimUnpacking(b,this->messagesToPush);
}

AddressVector& SCTPOpenCommand::getLocalAddresses()
{
    return this->localAddresses;
}

void SCTPOpenCommand::setLocalAddresses(const AddressVector& localAddresses)
{
    this->localAddresses = localAddresses;
}

AddressVector& SCTPOpenCommand::getRemoteAddresses()
{
    return this->remoteAddresses;
}

void SCTPOpenCommand::setRemoteAddresses(const AddressVector& remoteAddresses)
{
    this->remoteAddresses = remoteAddresses;
}

bool SCTPOpenCommand::getFork() const
{
    return this->fork;
}

void SCTPOpenCommand::setFork(bool fork)
{
    this->fork = fork;
}

const char * SCTPOpenCommand::getQueueClass() const
{
    return this->queueClass.c_str();
}

void SCTPOpenCommand::setQueueClass(const char * queueClass)
{
    this->queueClass = queueClass;
}

const char * SCTPOpenCommand::getSctpAlgorithmClass() const
{
    return this->sctpAlgorithmClass.c_str();
}

void SCTPOpenCommand::setSctpAlgorithmClass(const char * sctpAlgorithmClass)
{
    this->sctpAlgorithmClass = sctpAlgorithmClass;
}

uint32_t SCTPOpenCommand::getInboundStreams() const
{
    return this->inboundStreams;
}

void SCTPOpenCommand::setInboundStreams(uint32_t inboundStreams)
{
    this->inboundStreams = inboundStreams;
}

uint32_t SCTPOpenCommand::getOutboundStreams() const
{
    return this->outboundStreams;
}

void SCTPOpenCommand::setOutboundStreams(uint32_t outboundStreams)
{
    this->outboundStreams = outboundStreams;
}

bool SCTPOpenCommand::getStreamReset() const
{
    return this->streamReset;
}

void SCTPOpenCommand::setStreamReset(bool streamReset)
{
    this->streamReset = streamReset;
}

bool SCTPOpenCommand::getAppLimited() const
{
    return this->appLimited;
}

void SCTPOpenCommand::setAppLimited(bool appLimited)
{
    this->appLimited = appLimited;
}

int SCTPOpenCommand::getPrMethod() const
{
    return this->prMethod;
}

void SCTPOpenCommand::setPrMethod(int prMethod)
{
    this->prMethod = prMethod;
}

uint32_t SCTPOpenCommand::getNumRequests() const
{
    return this->numRequests;
}

void SCTPOpenCommand::setNumRequests(uint32_t numRequests)
{
    this->numRequests = numRequests;
}

uint32_t SCTPOpenCommand::getMessagesToPush() const
{
    return this->messagesToPush;
}

void SCTPOpenCommand::setMessagesToPush(uint32_t messagesToPush)
{
    this->messagesToPush = messagesToPush;
}

class SCTPOpenCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPOpenCommandDescriptor();
    virtual ~SCTPOpenCommandDescriptor();

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

Register_ClassDescriptor(SCTPOpenCommandDescriptor)

SCTPOpenCommandDescriptor::SCTPOpenCommandDescriptor() : omnetpp::cClassDescriptor("inet::SCTPOpenCommand", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPOpenCommandDescriptor::~SCTPOpenCommandDescriptor()
{
    delete[] propertynames;
}

bool SCTPOpenCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPOpenCommand *>(obj)!=nullptr;
}

const char **SCTPOpenCommandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPOpenCommandDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPOpenCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 12+basedesc->getFieldCount() : 12;
}

unsigned int SCTPOpenCommandDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<12) ? fieldTypeFlags[field] : 0;
}

const char *SCTPOpenCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddresses",
        "remoteAddresses",
        "fork",
        "queueClass",
        "sctpAlgorithmClass",
        "inboundStreams",
        "outboundStreams",
        "streamReset",
        "appLimited",
        "prMethod",
        "numRequests",
        "messagesToPush",
    };
    return (field>=0 && field<12) ? fieldNames[field] : nullptr;
}

int SCTPOpenCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localAddresses")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddresses")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fork")==0) return base+2;
    if (fieldName[0]=='q' && strcmp(fieldName, "queueClass")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "sctpAlgorithmClass")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "inboundStreams")==0) return base+5;
    if (fieldName[0]=='o' && strcmp(fieldName, "outboundStreams")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "streamReset")==0) return base+7;
    if (fieldName[0]=='a' && strcmp(fieldName, "appLimited")==0) return base+8;
    if (fieldName[0]=='p' && strcmp(fieldName, "prMethod")==0) return base+9;
    if (fieldName[0]=='n' && strcmp(fieldName, "numRequests")==0) return base+10;
    if (fieldName[0]=='m' && strcmp(fieldName, "messagesToPush")==0) return base+11;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPOpenCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "AddressVector",
        "AddressVector",
        "bool",
        "string",
        "string",
        "uint32",
        "uint32",
        "bool",
        "bool",
        "int",
        "uint32",
        "uint32",
    };
    return (field>=0 && field<12) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPOpenCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPOpenCommandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPOpenCommandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPOpenCommand *pp = (SCTPOpenCommand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPOpenCommandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPOpenCommand *pp = (SCTPOpenCommand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPOpenCommandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPOpenCommand *pp = (SCTPOpenCommand *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getLocalAddresses(); return out.str();}
        case 1: {std::stringstream out; out << pp->getRemoteAddresses(); return out.str();}
        case 2: return bool2string(pp->getFork());
        case 3: return oppstring2string(pp->getQueueClass());
        case 4: return oppstring2string(pp->getSctpAlgorithmClass());
        case 5: return ulong2string(pp->getInboundStreams());
        case 6: return ulong2string(pp->getOutboundStreams());
        case 7: return bool2string(pp->getStreamReset());
        case 8: return bool2string(pp->getAppLimited());
        case 9: return long2string(pp->getPrMethod());
        case 10: return ulong2string(pp->getNumRequests());
        case 11: return ulong2string(pp->getMessagesToPush());
        default: return "";
    }
}

bool SCTPOpenCommandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPOpenCommand *pp = (SCTPOpenCommand *)object; (void)pp;
    switch (field) {
        case 2: pp->setFork(string2bool(value)); return true;
        case 3: pp->setQueueClass((value)); return true;
        case 4: pp->setSctpAlgorithmClass((value)); return true;
        case 5: pp->setInboundStreams(string2ulong(value)); return true;
        case 6: pp->setOutboundStreams(string2ulong(value)); return true;
        case 7: pp->setStreamReset(string2bool(value)); return true;
        case 8: pp->setAppLimited(string2bool(value)); return true;
        case 9: pp->setPrMethod(string2long(value)); return true;
        case 10: pp->setNumRequests(string2ulong(value)); return true;
        case 11: pp->setMessagesToPush(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPOpenCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(AddressVector));
        case 1: return omnetpp::opp_typename(typeid(AddressVector));
        default: return nullptr;
    };
}

void *SCTPOpenCommandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPOpenCommand *pp = (SCTPOpenCommand *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getLocalAddresses()); break;
        case 1: return (void *)(&pp->getRemoteAddresses()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPSendInfo)

SCTPSendInfo::SCTPSendInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->prMethod = 0;
    this->last = false;
    this->ppid = 0;
    this->primary = true;
    this->sackNow = false;
}

SCTPSendInfo::SCTPSendInfo(const SCTPSendInfo& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPSendInfo::~SCTPSendInfo()
{
}

SCTPSendInfo& SCTPSendInfo::operator=(const SCTPSendInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPSendInfo::copy(const SCTPSendInfo& other)
{
    this->prMethod = other.prMethod;
    this->last = other.last;
    this->ppid = other.ppid;
    this->primary = other.primary;
    this->sackNow = other.sackNow;
}

void SCTPSendInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->prMethod);
    doParsimPacking(b,this->last);
    doParsimPacking(b,this->ppid);
    doParsimPacking(b,this->primary);
    doParsimPacking(b,this->sackNow);
}

void SCTPSendInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->prMethod);
    doParsimUnpacking(b,this->last);
    doParsimUnpacking(b,this->ppid);
    doParsimUnpacking(b,this->primary);
    doParsimUnpacking(b,this->sackNow);
}

unsigned int SCTPSendInfo::getPrMethod() const
{
    return this->prMethod;
}

void SCTPSendInfo::setPrMethod(unsigned int prMethod)
{
    this->prMethod = prMethod;
}

bool SCTPSendInfo::getLast() const
{
    return this->last;
}

void SCTPSendInfo::setLast(bool last)
{
    this->last = last;
}

unsigned int SCTPSendInfo::getPpid() const
{
    return this->ppid;
}

void SCTPSendInfo::setPpid(unsigned int ppid)
{
    this->ppid = ppid;
}

bool SCTPSendInfo::getPrimary() const
{
    return this->primary;
}

void SCTPSendInfo::setPrimary(bool primary)
{
    this->primary = primary;
}

bool SCTPSendInfo::getSackNow() const
{
    return this->sackNow;
}

void SCTPSendInfo::setSackNow(bool sackNow)
{
    this->sackNow = sackNow;
}

class SCTPSendInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSendInfoDescriptor();
    virtual ~SCTPSendInfoDescriptor();

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

Register_ClassDescriptor(SCTPSendInfoDescriptor)

SCTPSendInfoDescriptor::SCTPSendInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPSendInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPSendInfoDescriptor::~SCTPSendInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPSendInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSendInfo *>(obj)!=nullptr;
}

const char **SCTPSendInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSendInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSendInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int SCTPSendInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPSendInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "prMethod",
        "last",
        "ppid",
        "primary",
        "sackNow",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int SCTPSendInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "prMethod")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "last")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "ppid")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "primary")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "sackNow")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSendInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "bool",
        "unsigned int",
        "bool",
        "bool",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSendInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSendInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSendInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSendInfo *pp = (SCTPSendInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPSendInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSendInfo *pp = (SCTPSendInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSendInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSendInfo *pp = (SCTPSendInfo *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPrMethod());
        case 1: return bool2string(pp->getLast());
        case 2: return ulong2string(pp->getPpid());
        case 3: return bool2string(pp->getPrimary());
        case 4: return bool2string(pp->getSackNow());
        default: return "";
    }
}

bool SCTPSendInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSendInfo *pp = (SCTPSendInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setPrMethod(string2ulong(value)); return true;
        case 1: pp->setLast(string2bool(value)); return true;
        case 2: pp->setPpid(string2ulong(value)); return true;
        case 3: pp->setPrimary(string2bool(value)); return true;
        case 4: pp->setSackNow(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPSendInfoDescriptor::getFieldStructName(int field) const
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

void *SCTPSendInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSendInfo *pp = (SCTPSendInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPRtoInfo)

SCTPRtoInfo::SCTPRtoInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->rtoInitial = 0;
    this->rtoMin = 0;
    this->rtoMax = 0;
}

SCTPRtoInfo::SCTPRtoInfo(const SCTPRtoInfo& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPRtoInfo::~SCTPRtoInfo()
{
}

SCTPRtoInfo& SCTPRtoInfo::operator=(const SCTPRtoInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPRtoInfo::copy(const SCTPRtoInfo& other)
{
    this->rtoInitial = other.rtoInitial;
    this->rtoMin = other.rtoMin;
    this->rtoMax = other.rtoMax;
}

void SCTPRtoInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->rtoInitial);
    doParsimPacking(b,this->rtoMin);
    doParsimPacking(b,this->rtoMax);
}

void SCTPRtoInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->rtoInitial);
    doParsimUnpacking(b,this->rtoMin);
    doParsimUnpacking(b,this->rtoMax);
}

double SCTPRtoInfo::getRtoInitial() const
{
    return this->rtoInitial;
}

void SCTPRtoInfo::setRtoInitial(double rtoInitial)
{
    this->rtoInitial = rtoInitial;
}

double SCTPRtoInfo::getRtoMin() const
{
    return this->rtoMin;
}

void SCTPRtoInfo::setRtoMin(double rtoMin)
{
    this->rtoMin = rtoMin;
}

double SCTPRtoInfo::getRtoMax() const
{
    return this->rtoMax;
}

void SCTPRtoInfo::setRtoMax(double rtoMax)
{
    this->rtoMax = rtoMax;
}

class SCTPRtoInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPRtoInfoDescriptor();
    virtual ~SCTPRtoInfoDescriptor();

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

Register_ClassDescriptor(SCTPRtoInfoDescriptor)

SCTPRtoInfoDescriptor::SCTPRtoInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPRtoInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPRtoInfoDescriptor::~SCTPRtoInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPRtoInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPRtoInfo *>(obj)!=nullptr;
}

const char **SCTPRtoInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPRtoInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPRtoInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SCTPRtoInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPRtoInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "rtoInitial",
        "rtoMin",
        "rtoMax",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int SCTPRtoInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rtoInitial")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rtoMin")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "rtoMax")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPRtoInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPRtoInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPRtoInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPRtoInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPRtoInfo *pp = (SCTPRtoInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPRtoInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPRtoInfo *pp = (SCTPRtoInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPRtoInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPRtoInfo *pp = (SCTPRtoInfo *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->getRtoInitial());
        case 1: return double2string(pp->getRtoMin());
        case 2: return double2string(pp->getRtoMax());
        default: return "";
    }
}

bool SCTPRtoInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPRtoInfo *pp = (SCTPRtoInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setRtoInitial(string2double(value)); return true;
        case 1: pp->setRtoMin(string2double(value)); return true;
        case 2: pp->setRtoMax(string2double(value)); return true;
        default: return false;
    }
}

const char *SCTPRtoInfoDescriptor::getFieldStructName(int field) const
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

void *SCTPRtoInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPRtoInfo *pp = (SCTPRtoInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPRcvInfo)

SCTPRcvInfo::SCTPRcvInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->ppid = 0;
    this->tsn = 0;
    this->cumTsn = 0;
}

SCTPRcvInfo::SCTPRcvInfo(const SCTPRcvInfo& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPRcvInfo::~SCTPRcvInfo()
{
}

SCTPRcvInfo& SCTPRcvInfo::operator=(const SCTPRcvInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPRcvInfo::copy(const SCTPRcvInfo& other)
{
    this->ppid = other.ppid;
    this->tsn = other.tsn;
    this->cumTsn = other.cumTsn;
}

void SCTPRcvInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->ppid);
    doParsimPacking(b,this->tsn);
    doParsimPacking(b,this->cumTsn);
}

void SCTPRcvInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->ppid);
    doParsimUnpacking(b,this->tsn);
    doParsimUnpacking(b,this->cumTsn);
}

uint32_t SCTPRcvInfo::getPpid() const
{
    return this->ppid;
}

void SCTPRcvInfo::setPpid(uint32_t ppid)
{
    this->ppid = ppid;
}

uint32_t SCTPRcvInfo::getTsn() const
{
    return this->tsn;
}

void SCTPRcvInfo::setTsn(uint32_t tsn)
{
    this->tsn = tsn;
}

uint32_t SCTPRcvInfo::getCumTsn() const
{
    return this->cumTsn;
}

void SCTPRcvInfo::setCumTsn(uint32_t cumTsn)
{
    this->cumTsn = cumTsn;
}

class SCTPRcvInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPRcvInfoDescriptor();
    virtual ~SCTPRcvInfoDescriptor();

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

Register_ClassDescriptor(SCTPRcvInfoDescriptor)

SCTPRcvInfoDescriptor::SCTPRcvInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPRcvInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPRcvInfoDescriptor::~SCTPRcvInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPRcvInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPRcvInfo *>(obj)!=nullptr;
}

const char **SCTPRcvInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPRcvInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPRcvInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int SCTPRcvInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPRcvInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ppid",
        "tsn",
        "cumTsn",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int SCTPRcvInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "ppid")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tsn")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "cumTsn")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPRcvInfoDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPRcvInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPRcvInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPRcvInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPRcvInfo *pp = (SCTPRcvInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPRcvInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPRcvInfo *pp = (SCTPRcvInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPRcvInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPRcvInfo *pp = (SCTPRcvInfo *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPpid());
        case 1: return ulong2string(pp->getTsn());
        case 2: return ulong2string(pp->getCumTsn());
        default: return "";
    }
}

bool SCTPRcvInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPRcvInfo *pp = (SCTPRcvInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setPpid(string2ulong(value)); return true;
        case 1: pp->setTsn(string2ulong(value)); return true;
        case 2: pp->setCumTsn(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPRcvInfoDescriptor::getFieldStructName(int field) const
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

void *SCTPRcvInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPRcvInfo *pp = (SCTPRcvInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPConnectInfo)

SCTPConnectInfo::SCTPConnectInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->status = 0;
    this->inboundStreams = 0;
    this->outboundStreams = 0;
}

SCTPConnectInfo::SCTPConnectInfo(const SCTPConnectInfo& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPConnectInfo::~SCTPConnectInfo()
{
}

SCTPConnectInfo& SCTPConnectInfo::operator=(const SCTPConnectInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPConnectInfo::copy(const SCTPConnectInfo& other)
{
    this->remoteAddresses = other.remoteAddresses;
    this->status = other.status;
    this->inboundStreams = other.inboundStreams;
    this->outboundStreams = other.outboundStreams;
}

void SCTPConnectInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->remoteAddresses);
    doParsimPacking(b,this->status);
    doParsimPacking(b,this->inboundStreams);
    doParsimPacking(b,this->outboundStreams);
}

void SCTPConnectInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddresses);
    doParsimUnpacking(b,this->status);
    doParsimUnpacking(b,this->inboundStreams);
    doParsimUnpacking(b,this->outboundStreams);
}

AddressVector& SCTPConnectInfo::getRemoteAddresses()
{
    return this->remoteAddresses;
}

void SCTPConnectInfo::setRemoteAddresses(const AddressVector& remoteAddresses)
{
    this->remoteAddresses = remoteAddresses;
}

int SCTPConnectInfo::getStatus() const
{
    return this->status;
}

void SCTPConnectInfo::setStatus(int status)
{
    this->status = status;
}

int SCTPConnectInfo::getInboundStreams() const
{
    return this->inboundStreams;
}

void SCTPConnectInfo::setInboundStreams(int inboundStreams)
{
    this->inboundStreams = inboundStreams;
}

int SCTPConnectInfo::getOutboundStreams() const
{
    return this->outboundStreams;
}

void SCTPConnectInfo::setOutboundStreams(int outboundStreams)
{
    this->outboundStreams = outboundStreams;
}

class SCTPConnectInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPConnectInfoDescriptor();
    virtual ~SCTPConnectInfoDescriptor();

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

Register_ClassDescriptor(SCTPConnectInfoDescriptor)

SCTPConnectInfoDescriptor::SCTPConnectInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPConnectInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPConnectInfoDescriptor::~SCTPConnectInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPConnectInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPConnectInfo *>(obj)!=nullptr;
}

const char **SCTPConnectInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPConnectInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPConnectInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPConnectInfoDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *SCTPConnectInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddresses",
        "status",
        "inboundStreams",
        "outboundStreams",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPConnectInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddresses")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "status")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "inboundStreams")==0) return base+2;
    if (fieldName[0]=='o' && strcmp(fieldName, "outboundStreams")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPConnectInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "AddressVector",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPConnectInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPConnectInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPConnectInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPConnectInfo *pp = (SCTPConnectInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPConnectInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPConnectInfo *pp = (SCTPConnectInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPConnectInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPConnectInfo *pp = (SCTPConnectInfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteAddresses(); return out.str();}
        case 1: return long2string(pp->getStatus());
        case 2: return long2string(pp->getInboundStreams());
        case 3: return long2string(pp->getOutboundStreams());
        default: return "";
    }
}

bool SCTPConnectInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPConnectInfo *pp = (SCTPConnectInfo *)object; (void)pp;
    switch (field) {
        case 1: pp->setStatus(string2long(value)); return true;
        case 2: pp->setInboundStreams(string2long(value)); return true;
        case 3: pp->setOutboundStreams(string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPConnectInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(AddressVector));
        default: return nullptr;
    };
}

void *SCTPConnectInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPConnectInfo *pp = (SCTPConnectInfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRemoteAddresses()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPStatusInfo)

SCTPStatusInfo::SCTPStatusInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->state = 0;
    this->active = false;
}

SCTPStatusInfo::SCTPStatusInfo(const SCTPStatusInfo& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPStatusInfo::~SCTPStatusInfo()
{
}

SCTPStatusInfo& SCTPStatusInfo::operator=(const SCTPStatusInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPStatusInfo::copy(const SCTPStatusInfo& other)
{
    this->state = other.state;
    this->stateName = other.stateName;
    this->pathId = other.pathId;
    this->active = other.active;
}

void SCTPStatusInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->state);
    doParsimPacking(b,this->stateName);
    doParsimPacking(b,this->pathId);
    doParsimPacking(b,this->active);
}

void SCTPStatusInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->state);
    doParsimUnpacking(b,this->stateName);
    doParsimUnpacking(b,this->pathId);
    doParsimUnpacking(b,this->active);
}

int SCTPStatusInfo::getState() const
{
    return this->state;
}

void SCTPStatusInfo::setState(int state)
{
    this->state = state;
}

const char * SCTPStatusInfo::getStateName() const
{
    return this->stateName.c_str();
}

void SCTPStatusInfo::setStateName(const char * stateName)
{
    this->stateName = stateName;
}

L3Address& SCTPStatusInfo::getPathId()
{
    return this->pathId;
}

void SCTPStatusInfo::setPathId(const L3Address& pathId)
{
    this->pathId = pathId;
}

bool SCTPStatusInfo::getActive() const
{
    return this->active;
}

void SCTPStatusInfo::setActive(bool active)
{
    this->active = active;
}

class SCTPStatusInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPStatusInfoDescriptor();
    virtual ~SCTPStatusInfoDescriptor();

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

Register_ClassDescriptor(SCTPStatusInfoDescriptor)

SCTPStatusInfoDescriptor::SCTPStatusInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPStatusInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPStatusInfoDescriptor::~SCTPStatusInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPStatusInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPStatusInfo *>(obj)!=nullptr;
}

const char **SCTPStatusInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPStatusInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPStatusInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPStatusInfoDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *SCTPStatusInfoDescriptor::getFieldName(int field) const
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
        "pathId",
        "active",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPStatusInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "state")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "stateName")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "pathId")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "active")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPStatusInfoDescriptor::getFieldTypeString(int field) const
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
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPStatusInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPStatusInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPStatusInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPStatusInfo *pp = (SCTPStatusInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPStatusInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPStatusInfo *pp = (SCTPStatusInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPStatusInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPStatusInfo *pp = (SCTPStatusInfo *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getState());
        case 1: return oppstring2string(pp->getStateName());
        case 2: {std::stringstream out; out << pp->getPathId(); return out.str();}
        case 3: return bool2string(pp->getActive());
        default: return "";
    }
}

bool SCTPStatusInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPStatusInfo *pp = (SCTPStatusInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setState(string2long(value)); return true;
        case 1: pp->setStateName((value)); return true;
        case 3: pp->setActive(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPStatusInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *SCTPStatusInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPStatusInfo *pp = (SCTPStatusInfo *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getPathId()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPPathInfo)

SCTPPathInfo::SCTPPathInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
}

SCTPPathInfo::SCTPPathInfo(const SCTPPathInfo& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPPathInfo::~SCTPPathInfo()
{
}

SCTPPathInfo& SCTPPathInfo::operator=(const SCTPPathInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPPathInfo::copy(const SCTPPathInfo& other)
{
    this->remoteAddress = other.remoteAddress;
}

void SCTPPathInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->remoteAddress);
}

void SCTPPathInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->remoteAddress);
}

L3Address& SCTPPathInfo::getRemoteAddress()
{
    return this->remoteAddress;
}

void SCTPPathInfo::setRemoteAddress(const L3Address& remoteAddress)
{
    this->remoteAddress = remoteAddress;
}

class SCTPPathInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPPathInfoDescriptor();
    virtual ~SCTPPathInfoDescriptor();

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

Register_ClassDescriptor(SCTPPathInfoDescriptor)

SCTPPathInfoDescriptor::SCTPPathInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPPathInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPPathInfoDescriptor::~SCTPPathInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPPathInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPPathInfo *>(obj)!=nullptr;
}

const char **SCTPPathInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPPathInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPPathInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPPathInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPPathInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "remoteAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPPathInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "remoteAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPPathInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPPathInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPPathInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPPathInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPPathInfo *pp = (SCTPPathInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPPathInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPPathInfo *pp = (SCTPPathInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPPathInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPPathInfo *pp = (SCTPPathInfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRemoteAddress(); return out.str();}
        default: return "";
    }
}

bool SCTPPathInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPPathInfo *pp = (SCTPPathInfo *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SCTPPathInfoDescriptor::getFieldStructName(int field) const
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

void *SCTPPathInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPPathInfo *pp = (SCTPPathInfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRemoteAddress()); break;
        default: return nullptr;
    }
}

Register_Class(SCTPResetInfo)

SCTPResetInfo::SCTPResetInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->requestType = 0;
    this->instreams = 0;
    this->outstreams = 0;
    streams_arraysize = 0;
    this->streams = 0;
}

SCTPResetInfo::SCTPResetInfo(const SCTPResetInfo& other) : ::inet::SCTPCommand(other)
{
    streams_arraysize = 0;
    this->streams = 0;
    copy(other);
}

SCTPResetInfo::~SCTPResetInfo()
{
    delete [] this->streams;
}

SCTPResetInfo& SCTPResetInfo::operator=(const SCTPResetInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPResetInfo::copy(const SCTPResetInfo& other)
{
    this->requestType = other.requestType;
    this->instreams = other.instreams;
    this->outstreams = other.outstreams;
    delete [] this->streams;
    this->streams = (other.streams_arraysize==0) ? nullptr : new uint16_t[other.streams_arraysize];
    streams_arraysize = other.streams_arraysize;
    for (unsigned int i=0; i<streams_arraysize; i++)
        this->streams[i] = other.streams[i];
}

void SCTPResetInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->requestType);
    doParsimPacking(b,this->instreams);
    doParsimPacking(b,this->outstreams);
    b->pack(streams_arraysize);
    doParsimArrayPacking(b,this->streams,streams_arraysize);
}

void SCTPResetInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->requestType);
    doParsimUnpacking(b,this->instreams);
    doParsimUnpacking(b,this->outstreams);
    delete [] this->streams;
    b->unpack(streams_arraysize);
    if (streams_arraysize==0) {
        this->streams = 0;
    } else {
        this->streams = new uint16_t[streams_arraysize];
        doParsimArrayUnpacking(b,this->streams,streams_arraysize);
    }
}

unsigned short SCTPResetInfo::getRequestType() const
{
    return this->requestType;
}

void SCTPResetInfo::setRequestType(unsigned short requestType)
{
    this->requestType = requestType;
}

uint16_t SCTPResetInfo::getInstreams() const
{
    return this->instreams;
}

void SCTPResetInfo::setInstreams(uint16_t instreams)
{
    this->instreams = instreams;
}

uint16_t SCTPResetInfo::getOutstreams() const
{
    return this->outstreams;
}

void SCTPResetInfo::setOutstreams(uint16_t outstreams)
{
    this->outstreams = outstreams;
}

void SCTPResetInfo::setStreamsArraySize(unsigned int size)
{
    uint16_t *streams2 = (size==0) ? nullptr : new uint16_t[size];
    unsigned int sz = streams_arraysize < size ? streams_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        streams2[i] = this->streams[i];
    for (unsigned int i=sz; i<size; i++)
        streams2[i] = 0;
    streams_arraysize = size;
    delete [] this->streams;
    this->streams = streams2;
}

unsigned int SCTPResetInfo::getStreamsArraySize() const
{
    return streams_arraysize;
}

uint16_t SCTPResetInfo::getStreams(unsigned int k) const
{
    if (k>=streams_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", streams_arraysize, k);
    return this->streams[k];
}

void SCTPResetInfo::setStreams(unsigned int k, uint16_t streams)
{
    if (k>=streams_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", streams_arraysize, k);
    this->streams[k] = streams;
}

class SCTPResetInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPResetInfoDescriptor();
    virtual ~SCTPResetInfoDescriptor();

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

Register_ClassDescriptor(SCTPResetInfoDescriptor)

SCTPResetInfoDescriptor::SCTPResetInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPResetInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPResetInfoDescriptor::~SCTPResetInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPResetInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPResetInfo *>(obj)!=nullptr;
}

const char **SCTPResetInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPResetInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPResetInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPResetInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPResetInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requestType",
        "instreams",
        "outstreams",
        "streams",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPResetInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestType")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "instreams")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "outstreams")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "streams")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPResetInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "uint16",
        "uint16",
        "uint16",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPResetInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPResetInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPResetInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPResetInfo *pp = (SCTPResetInfo *)object; (void)pp;
    switch (field) {
        case 3: return pp->getStreamsArraySize();
        default: return 0;
    }
}

const char *SCTPResetInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPResetInfo *pp = (SCTPResetInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPResetInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPResetInfo *pp = (SCTPResetInfo *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getRequestType());
        case 1: return ulong2string(pp->getInstreams());
        case 2: return ulong2string(pp->getOutstreams());
        case 3: return ulong2string(pp->getStreams(i));
        default: return "";
    }
}

bool SCTPResetInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPResetInfo *pp = (SCTPResetInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setRequestType(string2ulong(value)); return true;
        case 1: pp->setInstreams(string2ulong(value)); return true;
        case 2: pp->setOutstreams(string2ulong(value)); return true;
        case 3: pp->setStreams(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *SCTPResetInfoDescriptor::getFieldStructName(int field) const
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

void *SCTPResetInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPResetInfo *pp = (SCTPResetInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPInfo)

SCTPInfo::SCTPInfo(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->text = 0;
}

SCTPInfo::SCTPInfo(const SCTPInfo& other) : ::inet::SCTPCommand(other)
{
    copy(other);
}

SCTPInfo::~SCTPInfo()
{
}

SCTPInfo& SCTPInfo::operator=(const SCTPInfo& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPInfo::copy(const SCTPInfo& other)
{
    this->text = other.text;
}

void SCTPInfo::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->text);
}

void SCTPInfo::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->text);
}

int SCTPInfo::getText() const
{
    return this->text;
}

void SCTPInfo::setText(int text)
{
    this->text = text;
}

class SCTPInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPInfoDescriptor();
    virtual ~SCTPInfoDescriptor();

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

Register_ClassDescriptor(SCTPInfoDescriptor)

SCTPInfoDescriptor::SCTPInfoDescriptor() : omnetpp::cClassDescriptor("inet::SCTPInfo", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPInfoDescriptor::~SCTPInfoDescriptor()
{
    delete[] propertynames;
}

bool SCTPInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPInfo *>(obj)!=nullptr;
}

const char **SCTPInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int SCTPInfoDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "text",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int SCTPInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "text")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPInfoDescriptor::getFieldTypeString(int field) const
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

const char **SCTPInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPInfo *pp = (SCTPInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SCTPInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPInfo *pp = (SCTPInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPInfo *pp = (SCTPInfo *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getText());
        default: return "";
    }
}

bool SCTPInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPInfo *pp = (SCTPInfo *)object; (void)pp;
    switch (field) {
        case 0: pp->setText(string2long(value)); return true;
        default: return false;
    }
}

const char *SCTPInfoDescriptor::getFieldStructName(int field) const
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

void *SCTPInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPInfo *pp = (SCTPInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPSendQueueAbated)

SCTPSendQueueAbated::SCTPSendQueueAbated(const char *name, short kind) : ::inet::SCTPCommand(name,kind)
{
    this->bytesAvailable = 0;
    this->bytesQueued = 0;
    this->bytesLimit = 0;
    queuedForStream_arraysize = 0;
    this->queuedForStream = 0;
}

SCTPSendQueueAbated::SCTPSendQueueAbated(const SCTPSendQueueAbated& other) : ::inet::SCTPCommand(other)
{
    queuedForStream_arraysize = 0;
    this->queuedForStream = 0;
    copy(other);
}

SCTPSendQueueAbated::~SCTPSendQueueAbated()
{
    delete [] this->queuedForStream;
}

SCTPSendQueueAbated& SCTPSendQueueAbated::operator=(const SCTPSendQueueAbated& other)
{
    if (this==&other) return *this;
    ::inet::SCTPCommand::operator=(other);
    copy(other);
    return *this;
}

void SCTPSendQueueAbated::copy(const SCTPSendQueueAbated& other)
{
    this->bytesAvailable = other.bytesAvailable;
    this->bytesQueued = other.bytesQueued;
    this->bytesLimit = other.bytesLimit;
    delete [] this->queuedForStream;
    this->queuedForStream = (other.queuedForStream_arraysize==0) ? nullptr : new uint64_t[other.queuedForStream_arraysize];
    queuedForStream_arraysize = other.queuedForStream_arraysize;
    for (unsigned int i=0; i<queuedForStream_arraysize; i++)
        this->queuedForStream[i] = other.queuedForStream[i];
}

void SCTPSendQueueAbated::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::SCTPCommand::parsimPack(b);
    doParsimPacking(b,this->bytesAvailable);
    doParsimPacking(b,this->bytesQueued);
    doParsimPacking(b,this->bytesLimit);
    b->pack(queuedForStream_arraysize);
    doParsimArrayPacking(b,this->queuedForStream,queuedForStream_arraysize);
}

void SCTPSendQueueAbated::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::SCTPCommand::parsimUnpack(b);
    doParsimUnpacking(b,this->bytesAvailable);
    doParsimUnpacking(b,this->bytesQueued);
    doParsimUnpacking(b,this->bytesLimit);
    delete [] this->queuedForStream;
    b->unpack(queuedForStream_arraysize);
    if (queuedForStream_arraysize==0) {
        this->queuedForStream = 0;
    } else {
        this->queuedForStream = new uint64_t[queuedForStream_arraysize];
        doParsimArrayUnpacking(b,this->queuedForStream,queuedForStream_arraysize);
    }
}

uint64_t SCTPSendQueueAbated::getBytesAvailable() const
{
    return this->bytesAvailable;
}

void SCTPSendQueueAbated::setBytesAvailable(uint64_t bytesAvailable)
{
    this->bytesAvailable = bytesAvailable;
}

uint64_t SCTPSendQueueAbated::getBytesQueued() const
{
    return this->bytesQueued;
}

void SCTPSendQueueAbated::setBytesQueued(uint64_t bytesQueued)
{
    this->bytesQueued = bytesQueued;
}

uint64_t SCTPSendQueueAbated::getBytesLimit() const
{
    return this->bytesLimit;
}

void SCTPSendQueueAbated::setBytesLimit(uint64_t bytesLimit)
{
    this->bytesLimit = bytesLimit;
}

void SCTPSendQueueAbated::setQueuedForStreamArraySize(unsigned int size)
{
    uint64_t *queuedForStream2 = (size==0) ? nullptr : new uint64_t[size];
    unsigned int sz = queuedForStream_arraysize < size ? queuedForStream_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        queuedForStream2[i] = this->queuedForStream[i];
    for (unsigned int i=sz; i<size; i++)
        queuedForStream2[i] = 0;
    queuedForStream_arraysize = size;
    delete [] this->queuedForStream;
    this->queuedForStream = queuedForStream2;
}

unsigned int SCTPSendQueueAbated::getQueuedForStreamArraySize() const
{
    return queuedForStream_arraysize;
}

uint64_t SCTPSendQueueAbated::getQueuedForStream(unsigned int k) const
{
    if (k>=queuedForStream_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", queuedForStream_arraysize, k);
    return this->queuedForStream[k];
}

void SCTPSendQueueAbated::setQueuedForStream(unsigned int k, uint64_t queuedForStream)
{
    if (k>=queuedForStream_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", queuedForStream_arraysize, k);
    this->queuedForStream[k] = queuedForStream;
}

class SCTPSendQueueAbatedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSendQueueAbatedDescriptor();
    virtual ~SCTPSendQueueAbatedDescriptor();

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

Register_ClassDescriptor(SCTPSendQueueAbatedDescriptor)

SCTPSendQueueAbatedDescriptor::SCTPSendQueueAbatedDescriptor() : omnetpp::cClassDescriptor("inet::SCTPSendQueueAbated", "inet::SCTPCommand")
{
    propertynames = nullptr;
}

SCTPSendQueueAbatedDescriptor::~SCTPSendQueueAbatedDescriptor()
{
    delete[] propertynames;
}

bool SCTPSendQueueAbatedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSendQueueAbated *>(obj)!=nullptr;
}

const char **SCTPSendQueueAbatedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSendQueueAbatedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSendQueueAbatedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPSendQueueAbatedDescriptor::getFieldTypeFlags(int field) const
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

const char *SCTPSendQueueAbatedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bytesAvailable",
        "bytesQueued",
        "bytesLimit",
        "queuedForStream",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPSendQueueAbatedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bytesAvailable")==0) return base+0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bytesQueued")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bytesLimit")==0) return base+2;
    if (fieldName[0]=='q' && strcmp(fieldName, "queuedForStream")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSendQueueAbatedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint64",
        "uint64",
        "uint64",
        "uint64",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSendQueueAbatedDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSendQueueAbatedDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSendQueueAbatedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSendQueueAbated *pp = (SCTPSendQueueAbated *)object; (void)pp;
    switch (field) {
        case 3: return pp->getQueuedForStreamArraySize();
        default: return 0;
    }
}

const char *SCTPSendQueueAbatedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSendQueueAbated *pp = (SCTPSendQueueAbated *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSendQueueAbatedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSendQueueAbated *pp = (SCTPSendQueueAbated *)object; (void)pp;
    switch (field) {
        case 0: return uint642string(pp->getBytesAvailable());
        case 1: return uint642string(pp->getBytesQueued());
        case 2: return uint642string(pp->getBytesLimit());
        case 3: return uint642string(pp->getQueuedForStream(i));
        default: return "";
    }
}

bool SCTPSendQueueAbatedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSendQueueAbated *pp = (SCTPSendQueueAbated *)object; (void)pp;
    switch (field) {
        case 0: pp->setBytesAvailable(string2uint64(value)); return true;
        case 1: pp->setBytesQueued(string2uint64(value)); return true;
        case 2: pp->setBytesLimit(string2uint64(value)); return true;
        case 3: pp->setQueuedForStream(i,string2uint64(value)); return true;
        default: return false;
    }
}

const char *SCTPSendQueueAbatedDescriptor::getFieldStructName(int field) const
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

void *SCTPSendQueueAbatedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSendQueueAbated *pp = (SCTPSendQueueAbated *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(SCTPSimpleMessage)

SCTPSimpleMessage::SCTPSimpleMessage(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->dataLen = 0;
    data_arraysize = 0;
    this->data = 0;
    this->creationTime = 0;
    this->encaps = false;
}

SCTPSimpleMessage::SCTPSimpleMessage(const SCTPSimpleMessage& other) : ::omnetpp::cPacket(other)
{
    data_arraysize = 0;
    this->data = 0;
    copy(other);
}

SCTPSimpleMessage::~SCTPSimpleMessage()
{
    delete [] this->data;
}

SCTPSimpleMessage& SCTPSimpleMessage::operator=(const SCTPSimpleMessage& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SCTPSimpleMessage::copy(const SCTPSimpleMessage& other)
{
    this->dataLen = other.dataLen;
    delete [] this->data;
    this->data = (other.data_arraysize==0) ? nullptr : new char[other.data_arraysize];
    data_arraysize = other.data_arraysize;
    for (unsigned int i=0; i<data_arraysize; i++)
        this->data[i] = other.data[i];
    this->creationTime = other.creationTime;
    this->encaps = other.encaps;
}

void SCTPSimpleMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->dataLen);
    b->pack(data_arraysize);
    doParsimArrayPacking(b,this->data,data_arraysize);
    doParsimPacking(b,this->creationTime);
    doParsimPacking(b,this->encaps);
}

void SCTPSimpleMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->dataLen);
    delete [] this->data;
    b->unpack(data_arraysize);
    if (data_arraysize==0) {
        this->data = 0;
    } else {
        this->data = new char[data_arraysize];
        doParsimArrayUnpacking(b,this->data,data_arraysize);
    }
    doParsimUnpacking(b,this->creationTime);
    doParsimUnpacking(b,this->encaps);
}

uint32_t SCTPSimpleMessage::getDataLen() const
{
    return this->dataLen;
}

void SCTPSimpleMessage::setDataLen(uint32_t dataLen)
{
    this->dataLen = dataLen;
}

void SCTPSimpleMessage::setDataArraySize(unsigned int size)
{
    char *data2 = (size==0) ? nullptr : new char[size];
    unsigned int sz = data_arraysize < size ? data_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        data2[i] = this->data[i];
    for (unsigned int i=sz; i<size; i++)
        data2[i] = 0;
    data_arraysize = size;
    delete [] this->data;
    this->data = data2;
}

unsigned int SCTPSimpleMessage::getDataArraySize() const
{
    return data_arraysize;
}

char SCTPSimpleMessage::getData(unsigned int k) const
{
    if (k>=data_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", data_arraysize, k);
    return this->data[k];
}

void SCTPSimpleMessage::setData(unsigned int k, char data)
{
    if (k>=data_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", data_arraysize, k);
    this->data[k] = data;
}

::omnetpp::simtime_t SCTPSimpleMessage::getCreationTime() const
{
    return this->creationTime;
}

void SCTPSimpleMessage::setCreationTime(::omnetpp::simtime_t creationTime)
{
    this->creationTime = creationTime;
}

bool SCTPSimpleMessage::getEncaps() const
{
    return this->encaps;
}

void SCTPSimpleMessage::setEncaps(bool encaps)
{
    this->encaps = encaps;
}

class SCTPSimpleMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SCTPSimpleMessageDescriptor();
    virtual ~SCTPSimpleMessageDescriptor();

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

Register_ClassDescriptor(SCTPSimpleMessageDescriptor)

SCTPSimpleMessageDescriptor::SCTPSimpleMessageDescriptor() : omnetpp::cClassDescriptor("inet::SCTPSimpleMessage", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SCTPSimpleMessageDescriptor::~SCTPSimpleMessageDescriptor()
{
    delete[] propertynames;
}

bool SCTPSimpleMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SCTPSimpleMessage *>(obj)!=nullptr;
}

const char **SCTPSimpleMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SCTPSimpleMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SCTPSimpleMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int SCTPSimpleMessageDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *SCTPSimpleMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "dataLen",
        "data",
        "creationTime",
        "encaps",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int SCTPSimpleMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataLen")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "data")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "creationTime")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "encaps")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SCTPSimpleMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32",
        "char",
        "simtime_t",
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **SCTPSimpleMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *SCTPSimpleMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SCTPSimpleMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        case 1: return pp->getDataArraySize();
        default: return 0;
    }
}

const char *SCTPSimpleMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SCTPSimpleMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getDataLen());
        case 1: return long2string(pp->getData(i));
        case 2: return simtime2string(pp->getCreationTime());
        case 3: return bool2string(pp->getEncaps());
        default: return "";
    }
}

bool SCTPSimpleMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setDataLen(string2ulong(value)); return true;
        case 1: pp->setData(i,string2long(value)); return true;
        case 2: pp->setCreationTime(string2simtime(value)); return true;
        case 3: pp->setEncaps(string2bool(value)); return true;
        default: return false;
    }
}

const char *SCTPSimpleMessageDescriptor::getFieldStructName(int field) const
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

void *SCTPSimpleMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SCTPSimpleMessage *pp = (SCTPSimpleMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

