//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/linklayer/ieee8021d/common/Ieee8021dBPDU.msg.
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
#include "Ieee8021dBPDU_m.h"

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

Register_Class(BPDU)

BPDU::BPDU(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->setByteLength(35);

    this->protocolIdentifier = 0;
    this->protocolVersionIdentifier = 0;
    this->bpduType = 0;
    this->tcaFlag = false;
    this->tcFlag = false;
    this->rootPriority = 0;
    this->rootPathCost = 0;
    this->bridgePriority = 0;
    this->portNum = 0;
    this->portPriority = 0;
    this->messageAge = 0;
    this->maxAge = 0;
    this->helloTime = 0;
    this->forwardDelay = 0;
}

BPDU::BPDU(const BPDU& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

BPDU::~BPDU()
{
}

BPDU& BPDU::operator=(const BPDU& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void BPDU::copy(const BPDU& other)
{
    this->protocolIdentifier = other.protocolIdentifier;
    this->protocolVersionIdentifier = other.protocolVersionIdentifier;
    this->bpduType = other.bpduType;
    this->tcaFlag = other.tcaFlag;
    this->tcFlag = other.tcFlag;
    this->rootAddress = other.rootAddress;
    this->rootPriority = other.rootPriority;
    this->rootPathCost = other.rootPathCost;
    this->bridgeAddress = other.bridgeAddress;
    this->bridgePriority = other.bridgePriority;
    this->portNum = other.portNum;
    this->portPriority = other.portPriority;
    this->messageAge = other.messageAge;
    this->maxAge = other.maxAge;
    this->helloTime = other.helloTime;
    this->forwardDelay = other.forwardDelay;
}

void BPDU::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->protocolIdentifier);
    doParsimPacking(b,this->protocolVersionIdentifier);
    doParsimPacking(b,this->bpduType);
    doParsimPacking(b,this->tcaFlag);
    doParsimPacking(b,this->tcFlag);
    doParsimPacking(b,this->rootAddress);
    doParsimPacking(b,this->rootPriority);
    doParsimPacking(b,this->rootPathCost);
    doParsimPacking(b,this->bridgeAddress);
    doParsimPacking(b,this->bridgePriority);
    doParsimPacking(b,this->portNum);
    doParsimPacking(b,this->portPriority);
    doParsimPacking(b,this->messageAge);
    doParsimPacking(b,this->maxAge);
    doParsimPacking(b,this->helloTime);
    doParsimPacking(b,this->forwardDelay);
}

void BPDU::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->protocolIdentifier);
    doParsimUnpacking(b,this->protocolVersionIdentifier);
    doParsimUnpacking(b,this->bpduType);
    doParsimUnpacking(b,this->tcaFlag);
    doParsimUnpacking(b,this->tcFlag);
    doParsimUnpacking(b,this->rootAddress);
    doParsimUnpacking(b,this->rootPriority);
    doParsimUnpacking(b,this->rootPathCost);
    doParsimUnpacking(b,this->bridgeAddress);
    doParsimUnpacking(b,this->bridgePriority);
    doParsimUnpacking(b,this->portNum);
    doParsimUnpacking(b,this->portPriority);
    doParsimUnpacking(b,this->messageAge);
    doParsimUnpacking(b,this->maxAge);
    doParsimUnpacking(b,this->helloTime);
    doParsimUnpacking(b,this->forwardDelay);
}

unsigned int BPDU::getProtocolIdentifier() const
{
    return this->protocolIdentifier;
}

void BPDU::setProtocolIdentifier(unsigned int protocolIdentifier)
{
    this->protocolIdentifier = protocolIdentifier;
}

unsigned int BPDU::getProtocolVersionIdentifier() const
{
    return this->protocolVersionIdentifier;
}

void BPDU::setProtocolVersionIdentifier(unsigned int protocolVersionIdentifier)
{
    this->protocolVersionIdentifier = protocolVersionIdentifier;
}

unsigned int BPDU::getBpduType() const
{
    return this->bpduType;
}

void BPDU::setBpduType(unsigned int bpduType)
{
    this->bpduType = bpduType;
}

bool BPDU::getTcaFlag() const
{
    return this->tcaFlag;
}

void BPDU::setTcaFlag(bool tcaFlag)
{
    this->tcaFlag = tcaFlag;
}

bool BPDU::getTcFlag() const
{
    return this->tcFlag;
}

void BPDU::setTcFlag(bool tcFlag)
{
    this->tcFlag = tcFlag;
}

MACAddress& BPDU::getRootAddress()
{
    return this->rootAddress;
}

void BPDU::setRootAddress(const MACAddress& rootAddress)
{
    this->rootAddress = rootAddress;
}

unsigned int BPDU::getRootPriority() const
{
    return this->rootPriority;
}

void BPDU::setRootPriority(unsigned int rootPriority)
{
    this->rootPriority = rootPriority;
}

unsigned int BPDU::getRootPathCost() const
{
    return this->rootPathCost;
}

void BPDU::setRootPathCost(unsigned int rootPathCost)
{
    this->rootPathCost = rootPathCost;
}

MACAddress& BPDU::getBridgeAddress()
{
    return this->bridgeAddress;
}

void BPDU::setBridgeAddress(const MACAddress& bridgeAddress)
{
    this->bridgeAddress = bridgeAddress;
}

unsigned int BPDU::getBridgePriority() const
{
    return this->bridgePriority;
}

void BPDU::setBridgePriority(unsigned int bridgePriority)
{
    this->bridgePriority = bridgePriority;
}

unsigned int BPDU::getPortNum() const
{
    return this->portNum;
}

void BPDU::setPortNum(unsigned int portNum)
{
    this->portNum = portNum;
}

unsigned int BPDU::getPortPriority() const
{
    return this->portPriority;
}

void BPDU::setPortPriority(unsigned int portPriority)
{
    this->portPriority = portPriority;
}

::omnetpp::simtime_t BPDU::getMessageAge() const
{
    return this->messageAge;
}

void BPDU::setMessageAge(::omnetpp::simtime_t messageAge)
{
    this->messageAge = messageAge;
}

::omnetpp::simtime_t BPDU::getMaxAge() const
{
    return this->maxAge;
}

void BPDU::setMaxAge(::omnetpp::simtime_t maxAge)
{
    this->maxAge = maxAge;
}

::omnetpp::simtime_t BPDU::getHelloTime() const
{
    return this->helloTime;
}

void BPDU::setHelloTime(::omnetpp::simtime_t helloTime)
{
    this->helloTime = helloTime;
}

::omnetpp::simtime_t BPDU::getForwardDelay() const
{
    return this->forwardDelay;
}

void BPDU::setForwardDelay(::omnetpp::simtime_t forwardDelay)
{
    this->forwardDelay = forwardDelay;
}

class BPDUDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    BPDUDescriptor();
    virtual ~BPDUDescriptor();

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

Register_ClassDescriptor(BPDUDescriptor)

BPDUDescriptor::BPDUDescriptor() : omnetpp::cClassDescriptor("inet::BPDU", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

BPDUDescriptor::~BPDUDescriptor()
{
    delete[] propertynames;
}

bool BPDUDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BPDU *>(obj)!=nullptr;
}

const char **BPDUDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *BPDUDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int BPDUDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 16+basedesc->getFieldCount() : 16;
}

unsigned int BPDUDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
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

const char *BPDUDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "protocolIdentifier",
        "protocolVersionIdentifier",
        "bpduType",
        "tcaFlag",
        "tcFlag",
        "rootAddress",
        "rootPriority",
        "rootPathCost",
        "bridgeAddress",
        "bridgePriority",
        "portNum",
        "portPriority",
        "messageAge",
        "maxAge",
        "helloTime",
        "forwardDelay",
    };
    return (field>=0 && field<16) ? fieldNames[field] : nullptr;
}

int BPDUDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocolIdentifier")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "protocolVersionIdentifier")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bpduType")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "tcaFlag")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "tcFlag")==0) return base+4;
    if (fieldName[0]=='r' && strcmp(fieldName, "rootAddress")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "rootPriority")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "rootPathCost")==0) return base+7;
    if (fieldName[0]=='b' && strcmp(fieldName, "bridgeAddress")==0) return base+8;
    if (fieldName[0]=='b' && strcmp(fieldName, "bridgePriority")==0) return base+9;
    if (fieldName[0]=='p' && strcmp(fieldName, "portNum")==0) return base+10;
    if (fieldName[0]=='p' && strcmp(fieldName, "portPriority")==0) return base+11;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageAge")==0) return base+12;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxAge")==0) return base+13;
    if (fieldName[0]=='h' && strcmp(fieldName, "helloTime")==0) return base+14;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardDelay")==0) return base+15;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *BPDUDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "bool",
        "bool",
        "MACAddress",
        "unsigned int",
        "unsigned int",
        "MACAddress",
        "unsigned int",
        "unsigned int",
        "unsigned int",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
    };
    return (field>=0 && field<16) ? fieldTypeStrings[field] : nullptr;
}

const char **BPDUDescriptor::getFieldPropertyNames(int field) const
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

const char *BPDUDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int BPDUDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    BPDU *pp = (BPDU *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *BPDUDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BPDU *pp = (BPDU *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BPDUDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    BPDU *pp = (BPDU *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getProtocolIdentifier());
        case 1: return ulong2string(pp->getProtocolVersionIdentifier());
        case 2: return ulong2string(pp->getBpduType());
        case 3: return bool2string(pp->getTcaFlag());
        case 4: return bool2string(pp->getTcFlag());
        case 5: {std::stringstream out; out << pp->getRootAddress(); return out.str();}
        case 6: return ulong2string(pp->getRootPriority());
        case 7: return ulong2string(pp->getRootPathCost());
        case 8: {std::stringstream out; out << pp->getBridgeAddress(); return out.str();}
        case 9: return ulong2string(pp->getBridgePriority());
        case 10: return ulong2string(pp->getPortNum());
        case 11: return ulong2string(pp->getPortPriority());
        case 12: return simtime2string(pp->getMessageAge());
        case 13: return simtime2string(pp->getMaxAge());
        case 14: return simtime2string(pp->getHelloTime());
        case 15: return simtime2string(pp->getForwardDelay());
        default: return "";
    }
}

bool BPDUDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    BPDU *pp = (BPDU *)object; (void)pp;
    switch (field) {
        case 0: pp->setProtocolIdentifier(string2ulong(value)); return true;
        case 1: pp->setProtocolVersionIdentifier(string2ulong(value)); return true;
        case 2: pp->setBpduType(string2ulong(value)); return true;
        case 3: pp->setTcaFlag(string2bool(value)); return true;
        case 4: pp->setTcFlag(string2bool(value)); return true;
        case 6: pp->setRootPriority(string2ulong(value)); return true;
        case 7: pp->setRootPathCost(string2ulong(value)); return true;
        case 9: pp->setBridgePriority(string2ulong(value)); return true;
        case 10: pp->setPortNum(string2ulong(value)); return true;
        case 11: pp->setPortPriority(string2ulong(value)); return true;
        case 12: pp->setMessageAge(string2simtime(value)); return true;
        case 13: pp->setMaxAge(string2simtime(value)); return true;
        case 14: pp->setHelloTime(string2simtime(value)); return true;
        case 15: pp->setForwardDelay(string2simtime(value)); return true;
        default: return false;
    }
}

const char *BPDUDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 5: return omnetpp::opp_typename(typeid(MACAddress));
        case 8: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *BPDUDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    BPDU *pp = (BPDU *)object; (void)pp;
    switch (field) {
        case 5: return (void *)(&pp->getRootAddress()); break;
        case 8: return (void *)(&pp->getBridgeAddress()); break;
        default: return nullptr;
    }
}

} // namespace inet

