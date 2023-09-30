//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/linklayer/ieee80211/mac/Ieee80211Frame.msg.
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
#include "Ieee80211Frame_m.h"

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
namespace ieee80211 {

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211FrameType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211FrameType"));
    e->insert(ST_ASSOCIATIONREQUEST, "ST_ASSOCIATIONREQUEST");
    e->insert(ST_ASSOCIATIONRESPONSE, "ST_ASSOCIATIONRESPONSE");
    e->insert(ST_REASSOCIATIONREQUEST, "ST_REASSOCIATIONREQUEST");
    e->insert(ST_REASSOCIATIONRESPONSE, "ST_REASSOCIATIONRESPONSE");
    e->insert(ST_PROBEREQUEST, "ST_PROBEREQUEST");
    e->insert(ST_PROBERESPONSE, "ST_PROBERESPONSE");
    e->insert(ST_BEACON, "ST_BEACON");
    e->insert(ST_ATIM, "ST_ATIM");
    e->insert(ST_DISASSOCIATION, "ST_DISASSOCIATION");
    e->insert(ST_AUTHENTICATION, "ST_AUTHENTICATION");
    e->insert(ST_DEAUTHENTICATION, "ST_DEAUTHENTICATION");
    e->insert(ST_ACTION, "ST_ACTION");
    e->insert(ST_NOACKACTION, "ST_NOACKACTION");
    e->insert(ST_PSPOLL, "ST_PSPOLL");
    e->insert(ST_RTS, "ST_RTS");
    e->insert(ST_CTS, "ST_CTS");
    e->insert(ST_ACK, "ST_ACK");
    e->insert(ST_BLOCKACK_REQ, "ST_BLOCKACK_REQ");
    e->insert(ST_BLOCKACK, "ST_BLOCKACK");
    e->insert(ST_DATA, "ST_DATA");
    e->insert(ST_DATA_WITH_QOS, "ST_DATA_WITH_QOS");
    e->insert(ST_LBMS_REQUEST, "ST_LBMS_REQUEST");
    e->insert(ST_LBMS_REPORT, "ST_LBMS_REPORT");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::AckPolicy");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::AckPolicy"));
    e->insert(NORMAL_ACK, "NORMAL_ACK");
    e->insert(NO_ACK, "NO_ACK");
    e->insert(NO_EXPLICIT_ACK, "NO_EXPLICIT_ACK");
    e->insert(BLOCK_ACK, "BLOCK_ACK");
)

Register_Class(Ieee80211Frame)

Ieee80211Frame::Ieee80211Frame(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->setByteLength(LENGTH_ACK / 8);

    this->type = 0;
    this->toDS = false;
    this->fromDS = false;
    this->retry = false;
    this->moreFragments = false;
    this->duration = -1;
    this->AID = -1;
    this->MACArrive = 0;
}

Ieee80211Frame::Ieee80211Frame(const Ieee80211Frame& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

Ieee80211Frame::~Ieee80211Frame()
{
}

Ieee80211Frame& Ieee80211Frame::operator=(const Ieee80211Frame& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211Frame::copy(const Ieee80211Frame& other)
{
    this->type = other.type;
    this->toDS = other.toDS;
    this->fromDS = other.fromDS;
    this->retry = other.retry;
    this->moreFragments = other.moreFragments;
    this->duration = other.duration;
    this->AID = other.AID;
    this->receiverAddress = other.receiverAddress;
    this->MACArrive = other.MACArrive;
}

void Ieee80211Frame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->toDS);
    doParsimPacking(b,this->fromDS);
    doParsimPacking(b,this->retry);
    doParsimPacking(b,this->moreFragments);
    doParsimPacking(b,this->duration);
    doParsimPacking(b,this->AID);
    doParsimPacking(b,this->receiverAddress);
    doParsimPacking(b,this->MACArrive);
}

void Ieee80211Frame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->toDS);
    doParsimUnpacking(b,this->fromDS);
    doParsimUnpacking(b,this->retry);
    doParsimUnpacking(b,this->moreFragments);
    doParsimUnpacking(b,this->duration);
    doParsimUnpacking(b,this->AID);
    doParsimUnpacking(b,this->receiverAddress);
    doParsimUnpacking(b,this->MACArrive);
}

short Ieee80211Frame::getType() const
{
    return this->type;
}

void Ieee80211Frame::setType(short type)
{
    this->type = type;
}

bool Ieee80211Frame::getToDS() const
{
    return this->toDS;
}

void Ieee80211Frame::setToDS(bool toDS)
{
    this->toDS = toDS;
}

bool Ieee80211Frame::getFromDS() const
{
    return this->fromDS;
}

void Ieee80211Frame::setFromDS(bool fromDS)
{
    this->fromDS = fromDS;
}

bool Ieee80211Frame::getRetry() const
{
    return this->retry;
}

void Ieee80211Frame::setRetry(bool retry)
{
    this->retry = retry;
}

bool Ieee80211Frame::getMoreFragments() const
{
    return this->moreFragments;
}

void Ieee80211Frame::setMoreFragments(bool moreFragments)
{
    this->moreFragments = moreFragments;
}

::omnetpp::simtime_t Ieee80211Frame::getDuration() const
{
    return this->duration;
}

void Ieee80211Frame::setDuration(::omnetpp::simtime_t duration)
{
    this->duration = duration;
}

short Ieee80211Frame::getAID() const
{
    return this->AID;
}

void Ieee80211Frame::setAID(short AID)
{
    this->AID = AID;
}

MACAddress& Ieee80211Frame::getReceiverAddress()
{
    return this->receiverAddress;
}

void Ieee80211Frame::setReceiverAddress(const MACAddress& receiverAddress)
{
    this->receiverAddress = receiverAddress;
}

::omnetpp::simtime_t Ieee80211Frame::getMACArrive() const
{
    return this->MACArrive;
}

void Ieee80211Frame::setMACArrive(::omnetpp::simtime_t MACArrive)
{
    this->MACArrive = MACArrive;
}

class Ieee80211FrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211FrameDescriptor();
    virtual ~Ieee80211FrameDescriptor();

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

Register_ClassDescriptor(Ieee80211FrameDescriptor)

Ieee80211FrameDescriptor::Ieee80211FrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211Frame", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

Ieee80211FrameDescriptor::~Ieee80211FrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211FrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211Frame *>(obj)!=nullptr;
}

const char **Ieee80211FrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211FrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211FrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee80211FrameDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211FrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
        "toDS",
        "fromDS",
        "retry",
        "moreFragments",
        "duration",
        "AID",
        "receiverAddress",
        "MACArrive",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int Ieee80211FrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "toDS")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "fromDS")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "retry")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "moreFragments")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+5;
    if (fieldName[0]=='A' && strcmp(fieldName, "AID")==0) return base+6;
    if (fieldName[0]=='r' && strcmp(fieldName, "receiverAddress")==0) return base+7;
    if (fieldName[0]=='M' && strcmp(fieldName, "MACArrive")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211FrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "bool",
        "bool",
        "bool",
        "bool",
        "simtime_t",
        "short",
        "MACAddress",
        "simtime_t",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211FrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211FrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ieee80211::Ieee80211FrameType";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211FrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211FrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211FrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::ieee80211::Ieee80211FrameType");
        case 1: return bool2string(pp->getToDS());
        case 2: return bool2string(pp->getFromDS());
        case 3: return bool2string(pp->getRetry());
        case 4: return bool2string(pp->getMoreFragments());
        case 5: return simtime2string(pp->getDuration());
        case 6: return long2string(pp->getAID());
        case 7: {std::stringstream out; out << pp->getReceiverAddress(); return out.str();}
        case 8: return simtime2string(pp->getMACArrive());
        default: return "";
    }
}

bool Ieee80211FrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::ieee80211::Ieee80211FrameType)string2enum(value, "inet::ieee80211::Ieee80211FrameType")); return true;
        case 1: pp->setToDS(string2bool(value)); return true;
        case 2: pp->setFromDS(string2bool(value)); return true;
        case 3: pp->setRetry(string2bool(value)); return true;
        case 4: pp->setMoreFragments(string2bool(value)); return true;
        case 5: pp->setDuration(string2simtime(value)); return true;
        case 6: pp->setAID(string2long(value)); return true;
        case 8: pp->setMACArrive(string2simtime(value)); return true;
        default: return false;
    }
}

const char *Ieee80211FrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211FrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Frame *pp = (Ieee80211Frame *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getReceiverAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211OneAddressFrame)

Ieee80211OneAddressFrame::Ieee80211OneAddressFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211Frame(name,kind)
{
}

Ieee80211OneAddressFrame::Ieee80211OneAddressFrame(const Ieee80211OneAddressFrame& other) : ::inet::ieee80211::Ieee80211Frame(other)
{
    copy(other);
}

Ieee80211OneAddressFrame::~Ieee80211OneAddressFrame()
{
}

Ieee80211OneAddressFrame& Ieee80211OneAddressFrame::operator=(const Ieee80211OneAddressFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211Frame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211OneAddressFrame::copy(const Ieee80211OneAddressFrame& other)
{
}

void Ieee80211OneAddressFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211Frame::parsimPack(b);
}

void Ieee80211OneAddressFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211Frame::parsimUnpack(b);
}

class Ieee80211OneAddressFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211OneAddressFrameDescriptor();
    virtual ~Ieee80211OneAddressFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211OneAddressFrameDescriptor)

Ieee80211OneAddressFrameDescriptor::Ieee80211OneAddressFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211OneAddressFrame", "inet::ieee80211::Ieee80211Frame")
{
    propertynames = nullptr;
}

Ieee80211OneAddressFrameDescriptor::~Ieee80211OneAddressFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211OneAddressFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211OneAddressFrame *>(obj)!=nullptr;
}

const char **Ieee80211OneAddressFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211OneAddressFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211OneAddressFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211OneAddressFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211OneAddressFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211OneAddressFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211OneAddressFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211OneAddressFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211OneAddressFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211OneAddressFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211OneAddressFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211OneAddressFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211OneAddressFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211OneAddressFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211OneAddressFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211OneAddressFrame *pp = (Ieee80211OneAddressFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ACKFrame)

Ieee80211ACKFrame::Ieee80211ACKFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211OneAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_ACK / 8);
    this->setType(ST_ACK);
}

Ieee80211ACKFrame::Ieee80211ACKFrame(const Ieee80211ACKFrame& other) : ::inet::ieee80211::Ieee80211OneAddressFrame(other)
{
    copy(other);
}

Ieee80211ACKFrame::~Ieee80211ACKFrame()
{
}

Ieee80211ACKFrame& Ieee80211ACKFrame::operator=(const Ieee80211ACKFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ACKFrame::copy(const Ieee80211ACKFrame& other)
{
}

void Ieee80211ACKFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimPack(b);
}

void Ieee80211ACKFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimUnpack(b);
}

class Ieee80211ACKFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ACKFrameDescriptor();
    virtual ~Ieee80211ACKFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ACKFrameDescriptor)

Ieee80211ACKFrameDescriptor::Ieee80211ACKFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ACKFrame", "inet::ieee80211::Ieee80211OneAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211ACKFrameDescriptor::~Ieee80211ACKFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ACKFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ACKFrame *>(obj)!=nullptr;
}

const char **Ieee80211ACKFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ACKFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ACKFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ACKFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ACKFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ACKFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ACKFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ACKFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ACKFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ACKFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ACKFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ACKFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ACKFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ACKFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ACKFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ACKFrame *pp = (Ieee80211ACKFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211TwoAddressFrame)

Ieee80211TwoAddressFrame::Ieee80211TwoAddressFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211OneAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_RTS / 8);

}

Ieee80211TwoAddressFrame::Ieee80211TwoAddressFrame(const Ieee80211TwoAddressFrame& other) : ::inet::ieee80211::Ieee80211OneAddressFrame(other)
{
    copy(other);
}

Ieee80211TwoAddressFrame::~Ieee80211TwoAddressFrame()
{
}

Ieee80211TwoAddressFrame& Ieee80211TwoAddressFrame::operator=(const Ieee80211TwoAddressFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211TwoAddressFrame::copy(const Ieee80211TwoAddressFrame& other)
{
    this->transmitterAddress = other.transmitterAddress;
}

void Ieee80211TwoAddressFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimPack(b);
    doParsimPacking(b,this->transmitterAddress);
}

void Ieee80211TwoAddressFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->transmitterAddress);
}

MACAddress& Ieee80211TwoAddressFrame::getTransmitterAddress()
{
    return this->transmitterAddress;
}

void Ieee80211TwoAddressFrame::setTransmitterAddress(const MACAddress& transmitterAddress)
{
    this->transmitterAddress = transmitterAddress;
}

class Ieee80211TwoAddressFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211TwoAddressFrameDescriptor();
    virtual ~Ieee80211TwoAddressFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211TwoAddressFrameDescriptor)

Ieee80211TwoAddressFrameDescriptor::Ieee80211TwoAddressFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211TwoAddressFrame", "inet::ieee80211::Ieee80211OneAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211TwoAddressFrameDescriptor::~Ieee80211TwoAddressFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211TwoAddressFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211TwoAddressFrame *>(obj)!=nullptr;
}

const char **Ieee80211TwoAddressFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211TwoAddressFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211TwoAddressFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211TwoAddressFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211TwoAddressFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "transmitterAddress",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211TwoAddressFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "transmitterAddress")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211TwoAddressFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211TwoAddressFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211TwoAddressFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211TwoAddressFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211TwoAddressFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211TwoAddressFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getTransmitterAddress(); return out.str();}
        default: return "";
    }
}

bool Ieee80211TwoAddressFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211TwoAddressFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211TwoAddressFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211TwoAddressFrame *pp = (Ieee80211TwoAddressFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getTransmitterAddress()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211RTSFrame)

Ieee80211RTSFrame::Ieee80211RTSFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211TwoAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_RTS / 8);
    this->setType(ST_RTS);
}

Ieee80211RTSFrame::Ieee80211RTSFrame(const Ieee80211RTSFrame& other) : ::inet::ieee80211::Ieee80211TwoAddressFrame(other)
{
    copy(other);
}

Ieee80211RTSFrame::~Ieee80211RTSFrame()
{
}

Ieee80211RTSFrame& Ieee80211RTSFrame::operator=(const Ieee80211RTSFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211RTSFrame::copy(const Ieee80211RTSFrame& other)
{
}

void Ieee80211RTSFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimPack(b);
}

void Ieee80211RTSFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimUnpack(b);
}

class Ieee80211RTSFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211RTSFrameDescriptor();
    virtual ~Ieee80211RTSFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211RTSFrameDescriptor)

Ieee80211RTSFrameDescriptor::Ieee80211RTSFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211RTSFrame", "inet::ieee80211::Ieee80211TwoAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211RTSFrameDescriptor::~Ieee80211RTSFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211RTSFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211RTSFrame *>(obj)!=nullptr;
}

const char **Ieee80211RTSFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211RTSFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211RTSFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211RTSFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211RTSFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211RTSFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211RTSFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211RTSFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211RTSFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211RTSFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211RTSFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211RTSFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211RTSFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211RTSFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211RTSFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211RTSFrame *pp = (Ieee80211RTSFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211CTSFrame)

Ieee80211CTSFrame::Ieee80211CTSFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211OneAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_CTS / 8);
    this->setType(ST_CTS);
}

Ieee80211CTSFrame::Ieee80211CTSFrame(const Ieee80211CTSFrame& other) : ::inet::ieee80211::Ieee80211OneAddressFrame(other)
{
    copy(other);
}

Ieee80211CTSFrame::~Ieee80211CTSFrame()
{
}

Ieee80211CTSFrame& Ieee80211CTSFrame::operator=(const Ieee80211CTSFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211OneAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211CTSFrame::copy(const Ieee80211CTSFrame& other)
{
}

void Ieee80211CTSFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimPack(b);
}

void Ieee80211CTSFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211OneAddressFrame::parsimUnpack(b);
}

class Ieee80211CTSFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211CTSFrameDescriptor();
    virtual ~Ieee80211CTSFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211CTSFrameDescriptor)

Ieee80211CTSFrameDescriptor::Ieee80211CTSFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211CTSFrame", "inet::ieee80211::Ieee80211OneAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211CTSFrameDescriptor::~Ieee80211CTSFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CTSFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CTSFrame *>(obj)!=nullptr;
}

const char **Ieee80211CTSFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CTSFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CTSFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211CTSFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211CTSFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211CTSFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CTSFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211CTSFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211CTSFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211CTSFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211CTSFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211CTSFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211CTSFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211CTSFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211CTSFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CTSFrame *pp = (Ieee80211CTSFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DataOrMgmtFrame)

Ieee80211DataOrMgmtFrame::Ieee80211DataOrMgmtFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211TwoAddressFrame(name,kind)
{
    this->setByteLength(LENGTH_MGMT / 8);

    this->fragmentNumber = 0;
    this->sequenceNumber = 0;
}

Ieee80211DataOrMgmtFrame::Ieee80211DataOrMgmtFrame(const Ieee80211DataOrMgmtFrame& other) : ::inet::ieee80211::Ieee80211TwoAddressFrame(other)
{
    copy(other);
}

Ieee80211DataOrMgmtFrame::~Ieee80211DataOrMgmtFrame()
{
}

Ieee80211DataOrMgmtFrame& Ieee80211DataOrMgmtFrame::operator=(const Ieee80211DataOrMgmtFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DataOrMgmtFrame::copy(const Ieee80211DataOrMgmtFrame& other)
{
    this->address3 = other.address3;
    this->fragmentNumber = other.fragmentNumber;
    this->sequenceNumber = other.sequenceNumber;
}

void Ieee80211DataOrMgmtFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimPack(b);
    doParsimPacking(b,this->address3);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->sequenceNumber);
}

void Ieee80211DataOrMgmtFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->address3);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->sequenceNumber);
}

MACAddress& Ieee80211DataOrMgmtFrame::getAddress3()
{
    return this->address3;
}

void Ieee80211DataOrMgmtFrame::setAddress3(const MACAddress& address3)
{
    this->address3 = address3;
}

short Ieee80211DataOrMgmtFrame::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211DataOrMgmtFrame::setFragmentNumber(short fragmentNumber)
{
    this->fragmentNumber = fragmentNumber;
}

uint16_t Ieee80211DataOrMgmtFrame::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void Ieee80211DataOrMgmtFrame::setSequenceNumber(uint16_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

class Ieee80211DataOrMgmtFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DataOrMgmtFrameDescriptor();
    virtual ~Ieee80211DataOrMgmtFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211DataOrMgmtFrameDescriptor)

Ieee80211DataOrMgmtFrameDescriptor::Ieee80211DataOrMgmtFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DataOrMgmtFrame", "inet::ieee80211::Ieee80211TwoAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211DataOrMgmtFrameDescriptor::~Ieee80211DataOrMgmtFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DataOrMgmtFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DataOrMgmtFrame *>(obj)!=nullptr;
}

const char **Ieee80211DataOrMgmtFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DataOrMgmtFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211DataOrMgmtFrameDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "address3",
        "fragmentNumber",
        "sequenceNumber",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211DataOrMgmtFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address3")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentNumber")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
        "short",
        "uint16",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DataOrMgmtFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211DataOrMgmtFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DataOrMgmtFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getAddress3(); return out.str();}
        case 1: return long2string(pp->getFragmentNumber());
        case 2: return ulong2string(pp->getSequenceNumber());
        default: return "";
    }
}

bool Ieee80211DataOrMgmtFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        case 1: pp->setFragmentNumber(string2long(value)); return true;
        case 2: pp->setSequenceNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DataOrMgmtFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211DataOrMgmtFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataOrMgmtFrame *pp = (Ieee80211DataOrMgmtFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getAddress3()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211DataFrame)

Ieee80211DataFrame::Ieee80211DataFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211DataOrMgmtFrame(name,kind)
{
    this->setByteLength(DATAFRAME_HEADER_MINLENGTH / 8);
    this->setType(ST_DATA);

    this->qos = 0;
    this->ackPolicy = 0;
    this->tid = 0;
    this->aMsduPresent = false;
}

Ieee80211DataFrame::Ieee80211DataFrame(const Ieee80211DataFrame& other) : ::inet::ieee80211::Ieee80211DataOrMgmtFrame(other)
{
    copy(other);
}

Ieee80211DataFrame::~Ieee80211DataFrame()
{
}

Ieee80211DataFrame& Ieee80211DataFrame::operator=(const Ieee80211DataFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DataFrame::copy(const Ieee80211DataFrame& other)
{
    this->address4 = other.address4;
    this->qos = other.qos;
    this->ackPolicy = other.ackPolicy;
    this->tid = other.tid;
    this->aMsduPresent = other.aMsduPresent;
}

void Ieee80211DataFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::parsimPack(b);
    doParsimPacking(b,this->address4);
    doParsimPacking(b,this->qos);
    doParsimPacking(b,this->ackPolicy);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->aMsduPresent);
}

void Ieee80211DataFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->address4);
    doParsimUnpacking(b,this->qos);
    doParsimUnpacking(b,this->ackPolicy);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->aMsduPresent);
}

MACAddress& Ieee80211DataFrame::getAddress4()
{
    return this->address4;
}

void Ieee80211DataFrame::setAddress4(const MACAddress& address4)
{
    this->address4 = address4;
}

uint16_t Ieee80211DataFrame::getQos() const
{
    return this->qos;
}

void Ieee80211DataFrame::setQos(uint16_t qos)
{
    this->qos = qos;
}

int Ieee80211DataFrame::getAckPolicy() const
{
    return this->ackPolicy;
}

void Ieee80211DataFrame::setAckPolicy(int ackPolicy)
{
    this->ackPolicy = ackPolicy;
}

uint8_t Ieee80211DataFrame::getTid() const
{
    return this->tid;
}

void Ieee80211DataFrame::setTid(uint8_t tid)
{
    this->tid = tid;
}

bool Ieee80211DataFrame::getAMsduPresent() const
{
    return this->aMsduPresent;
}

void Ieee80211DataFrame::setAMsduPresent(bool aMsduPresent)
{
    this->aMsduPresent = aMsduPresent;
}

class Ieee80211DataFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DataFrameDescriptor();
    virtual ~Ieee80211DataFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211DataFrameDescriptor)

Ieee80211DataFrameDescriptor::Ieee80211DataFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DataFrame", "inet::ieee80211::Ieee80211DataOrMgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211DataFrameDescriptor::~Ieee80211DataFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DataFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DataFrame *>(obj)!=nullptr;
}

const char **Ieee80211DataFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DataFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DataFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int Ieee80211DataFrameDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211DataFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "address4",
        "qos",
        "ackPolicy",
        "tid",
        "aMsduPresent",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int Ieee80211DataFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "address4")==0) return base+0;
    if (fieldName[0]=='q' && strcmp(fieldName, "qos")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackPolicy")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "tid")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "aMsduPresent")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DataFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
        "uint16",
        "int",
        "uint8",
        "bool",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DataFrameDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211DataFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "inet::ieee80211::AckPolicy";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DataFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DataFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DataFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getAddress4(); return out.str();}
        case 1: return ulong2string(pp->getQos());
        case 2: return enum2string(pp->getAckPolicy(), "inet::ieee80211::AckPolicy");
        case 3: return ulong2string(pp->getTid());
        case 4: return bool2string(pp->getAMsduPresent());
        default: return "";
    }
}

bool Ieee80211DataFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        case 1: pp->setQos(string2ulong(value)); return true;
        case 2: pp->setAckPolicy((inet::ieee80211::AckPolicy)string2enum(value, "inet::ieee80211::AckPolicy")); return true;
        case 3: pp->setTid(string2ulong(value)); return true;
        case 4: pp->setAMsduPresent(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DataFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211DataFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrame *pp = (Ieee80211DataFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getAddress4()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211DataFrameWithSNAP)

Ieee80211DataFrameWithSNAP::Ieee80211DataFrameWithSNAP(const char *name, short kind) : ::inet::ieee80211::Ieee80211DataFrame(name,kind)
{
    this->setByteLength(DATAFRAME_HEADER_MINLENGTH / 8 + SNAP_HEADER_BYTES);

    this->etherType = 0;
}

Ieee80211DataFrameWithSNAP::Ieee80211DataFrameWithSNAP(const Ieee80211DataFrameWithSNAP& other) : ::inet::ieee80211::Ieee80211DataFrame(other)
{
    copy(other);
}

Ieee80211DataFrameWithSNAP::~Ieee80211DataFrameWithSNAP()
{
}

Ieee80211DataFrameWithSNAP& Ieee80211DataFrameWithSNAP::operator=(const Ieee80211DataFrameWithSNAP& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211DataFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DataFrameWithSNAP::copy(const Ieee80211DataFrameWithSNAP& other)
{
    this->etherType = other.etherType;
}

void Ieee80211DataFrameWithSNAP::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211DataFrame::parsimPack(b);
    doParsimPacking(b,this->etherType);
}

void Ieee80211DataFrameWithSNAP::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211DataFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->etherType);
}

int Ieee80211DataFrameWithSNAP::getEtherType() const
{
    return this->etherType;
}

void Ieee80211DataFrameWithSNAP::setEtherType(int etherType)
{
    this->etherType = etherType;
}

class Ieee80211DataFrameWithSNAPDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DataFrameWithSNAPDescriptor();
    virtual ~Ieee80211DataFrameWithSNAPDescriptor();

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

Register_ClassDescriptor(Ieee80211DataFrameWithSNAPDescriptor)

Ieee80211DataFrameWithSNAPDescriptor::Ieee80211DataFrameWithSNAPDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DataFrameWithSNAP", "inet::ieee80211::Ieee80211DataFrame")
{
    propertynames = nullptr;
}

Ieee80211DataFrameWithSNAPDescriptor::~Ieee80211DataFrameWithSNAPDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DataFrameWithSNAPDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DataFrameWithSNAP *>(obj)!=nullptr;
}

const char **Ieee80211DataFrameWithSNAPDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DataFrameWithSNAPDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211DataFrameWithSNAPDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "etherType",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211DataFrameWithSNAPDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "etherType")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldTypeString(int field) const
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

const char **Ieee80211DataFrameWithSNAPDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "EtherType";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DataFrameWithSNAPDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DataFrameWithSNAPDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getEtherType(), "EtherType");
        default: return "";
    }
}

bool Ieee80211DataFrameWithSNAPDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        case 0: pp->setEtherType((EtherType)string2enum(value, "EtherType")); return true;
        default: return false;
    }
}

const char *Ieee80211DataFrameWithSNAPDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DataFrameWithSNAPDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DataFrameWithSNAP *pp = (Ieee80211DataFrameWithSNAP *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ManagementFrame)

Ieee80211ManagementFrame::Ieee80211ManagementFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211DataOrMgmtFrame(name,kind)
{
}

Ieee80211ManagementFrame::Ieee80211ManagementFrame(const Ieee80211ManagementFrame& other) : ::inet::ieee80211::Ieee80211DataOrMgmtFrame(other)
{
    copy(other);
}

Ieee80211ManagementFrame::~Ieee80211ManagementFrame()
{
}

Ieee80211ManagementFrame& Ieee80211ManagementFrame::operator=(const Ieee80211ManagementFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ManagementFrame::copy(const Ieee80211ManagementFrame& other)
{
}

void Ieee80211ManagementFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::parsimPack(b);
}

void Ieee80211ManagementFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211DataOrMgmtFrame::parsimUnpack(b);
}

class Ieee80211ManagementFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ManagementFrameDescriptor();
    virtual ~Ieee80211ManagementFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ManagementFrameDescriptor)

Ieee80211ManagementFrameDescriptor::Ieee80211ManagementFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ManagementFrame", "inet::ieee80211::Ieee80211DataOrMgmtFrame")
{
    propertynames = nullptr;
}

Ieee80211ManagementFrameDescriptor::~Ieee80211ManagementFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ManagementFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ManagementFrame *>(obj)!=nullptr;
}

const char **Ieee80211ManagementFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ManagementFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ManagementFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ManagementFrameDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ManagementFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ManagementFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ManagementFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ManagementFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ManagementFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ManagementFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ManagementFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ManagementFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ManagementFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ManagementFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ManagementFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ManagementFrame *pp = (Ieee80211ManagementFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ActionFrame)

Ieee80211ActionFrame::Ieee80211ActionFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_ACTION);

    this->category = 0;
}

Ieee80211ActionFrame::Ieee80211ActionFrame(const Ieee80211ActionFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211ActionFrame::~Ieee80211ActionFrame()
{
}

Ieee80211ActionFrame& Ieee80211ActionFrame::operator=(const Ieee80211ActionFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ActionFrame::copy(const Ieee80211ActionFrame& other)
{
    this->category = other.category;
}

void Ieee80211ActionFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->category);
}

void Ieee80211ActionFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->category);
}

short Ieee80211ActionFrame::getCategory() const
{
    return this->category;
}

void Ieee80211ActionFrame::setCategory(short category)
{
    this->category = category;
}

class Ieee80211ActionFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ActionFrameDescriptor();
    virtual ~Ieee80211ActionFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ActionFrameDescriptor)

Ieee80211ActionFrameDescriptor::Ieee80211ActionFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ActionFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211ActionFrameDescriptor::~Ieee80211ActionFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ActionFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ActionFrame *>(obj)!=nullptr;
}

const char **Ieee80211ActionFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ActionFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ActionFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ActionFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211ActionFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "category",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211ActionFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "category")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ActionFrameDescriptor::getFieldTypeString(int field) const
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

const char **Ieee80211ActionFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ActionFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ActionFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ActionFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ActionFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getCategory());
        default: return "";
    }
}

bool Ieee80211ActionFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        case 0: pp->setCategory(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211ActionFrameDescriptor::getFieldStructName(int field) const
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

void *Ieee80211ActionFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrame *pp = (Ieee80211ActionFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211MsduSubframe)

Ieee80211MsduSubframe::Ieee80211MsduSubframe(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->setBitLength(LENGTH_A_MSDU_SUBFRAME_HEADER);

    this->length = 0;
    this->etherType = 0;
}

Ieee80211MsduSubframe::Ieee80211MsduSubframe(const Ieee80211MsduSubframe& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

Ieee80211MsduSubframe::~Ieee80211MsduSubframe()
{
}

Ieee80211MsduSubframe& Ieee80211MsduSubframe::operator=(const Ieee80211MsduSubframe& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MsduSubframe::copy(const Ieee80211MsduSubframe& other)
{
    this->sa = other.sa;
    this->da = other.da;
    this->length = other.length;
    this->etherType = other.etherType;
}

void Ieee80211MsduSubframe::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sa);
    doParsimPacking(b,this->da);
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->etherType);
}

void Ieee80211MsduSubframe::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sa);
    doParsimUnpacking(b,this->da);
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->etherType);
}

MACAddress& Ieee80211MsduSubframe::getSa()
{
    return this->sa;
}

void Ieee80211MsduSubframe::setSa(const MACAddress& sa)
{
    this->sa = sa;
}

MACAddress& Ieee80211MsduSubframe::getDa()
{
    return this->da;
}

void Ieee80211MsduSubframe::setDa(const MACAddress& da)
{
    this->da = da;
}

int Ieee80211MsduSubframe::getLength() const
{
    return this->length;
}

void Ieee80211MsduSubframe::setLength(int length)
{
    this->length = length;
}

int Ieee80211MsduSubframe::getEtherType() const
{
    return this->etherType;
}

void Ieee80211MsduSubframe::setEtherType(int etherType)
{
    this->etherType = etherType;
}

class Ieee80211MsduSubframeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211MsduSubframeDescriptor();
    virtual ~Ieee80211MsduSubframeDescriptor();

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

Register_ClassDescriptor(Ieee80211MsduSubframeDescriptor)

Ieee80211MsduSubframeDescriptor::Ieee80211MsduSubframeDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211MsduSubframe", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

Ieee80211MsduSubframeDescriptor::~Ieee80211MsduSubframeDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MsduSubframeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MsduSubframe *>(obj)!=nullptr;
}

const char **Ieee80211MsduSubframeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MsduSubframeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MsduSubframeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211MsduSubframeDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211MsduSubframeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sa",
        "da",
        "length",
        "etherType",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int Ieee80211MsduSubframeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sa")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "da")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "etherType")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MsduSubframeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "MACAddress",
        "MACAddress",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211MsduSubframeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211MsduSubframeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3:
            if (!strcmp(propertyname,"enum")) return "EtherType";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211MsduSubframeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframe *pp = (Ieee80211MsduSubframe *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MsduSubframeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframe *pp = (Ieee80211MsduSubframe *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MsduSubframeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframe *pp = (Ieee80211MsduSubframe *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSa(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDa(); return out.str();}
        case 2: return long2string(pp->getLength());
        case 3: return enum2string(pp->getEtherType(), "EtherType");
        default: return "";
    }
}

bool Ieee80211MsduSubframeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframe *pp = (Ieee80211MsduSubframe *)object; (void)pp;
    switch (field) {
        case 2: pp->setLength(string2long(value)); return true;
        case 3: pp->setEtherType((EtherType)string2enum(value, "EtherType")); return true;
        default: return false;
    }
}

const char *Ieee80211MsduSubframeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(MACAddress));
        case 1: return omnetpp::opp_typename(typeid(MACAddress));
        default: return nullptr;
    };
}

void *Ieee80211MsduSubframeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MsduSubframe *pp = (Ieee80211MsduSubframe *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSa()); break;
        case 1: return (void *)(&pp->getDa()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AMsdu)

Ieee80211AMsdu::Ieee80211AMsdu(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    subframes_arraysize = 0;
    this->subframes = 0;
}

Ieee80211AMsdu::Ieee80211AMsdu(const Ieee80211AMsdu& other) : ::omnetpp::cPacket(other)
{
    subframes_arraysize = 0;
    this->subframes = 0;
    copy(other);
}

Ieee80211AMsdu::~Ieee80211AMsdu()
{
    for (unsigned int i=0; i<subframes_arraysize; i++)
        drop(&(this->subframes[i]));
    delete [] this->subframes;
}

Ieee80211AMsdu& Ieee80211AMsdu::operator=(const Ieee80211AMsdu& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AMsdu::copy(const Ieee80211AMsdu& other)
{
    delete [] this->subframes;
    this->subframes = (other.subframes_arraysize==0) ? nullptr : new Ieee80211MsduSubframe[other.subframes_arraysize];
    subframes_arraysize = other.subframes_arraysize;
    for (unsigned int i=0; i<subframes_arraysize; i++)
    {
        take(&(this->subframes[i]));
        this->subframes[i] = other.subframes[i];
        this->subframes[i].setName(other.subframes[i].getName());
    }
}

void Ieee80211AMsdu::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    b->pack(subframes_arraysize);
    doParsimArrayPacking(b,this->subframes,subframes_arraysize);
}

void Ieee80211AMsdu::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    delete [] this->subframes;
    b->unpack(subframes_arraysize);
    if (subframes_arraysize==0) {
        this->subframes = 0;
    } else {
        this->subframes = new Ieee80211MsduSubframe[subframes_arraysize];
        doParsimArrayUnpacking(b,this->subframes,subframes_arraysize);
    }
}

void Ieee80211AMsdu::setSubframesArraySize(unsigned int size)
{
    Ieee80211MsduSubframe *subframes2 = (size==0) ? nullptr : new Ieee80211MsduSubframe[size];
    unsigned int sz = subframes_arraysize < size ? subframes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        subframes2[i] = this->subframes[i];
    for (unsigned int i=sz; i<size; i++)
        take(&(subframes2[i]));
    subframes_arraysize = size;
    delete [] this->subframes;
    this->subframes = subframes2;
}

unsigned int Ieee80211AMsdu::getSubframesArraySize() const
{
    return subframes_arraysize;
}

Ieee80211MsduSubframe& Ieee80211AMsdu::getSubframes(unsigned int k)
{
    if (k>=subframes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", subframes_arraysize, k);
    return this->subframes[k];
}

void Ieee80211AMsdu::setSubframes(unsigned int k, const Ieee80211MsduSubframe& subframes)
{
    if (k>=subframes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", subframes_arraysize, k);
    this->subframes[k] = subframes;
}

class Ieee80211AMsduDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AMsduDescriptor();
    virtual ~Ieee80211AMsduDescriptor();

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

Register_ClassDescriptor(Ieee80211AMsduDescriptor)

Ieee80211AMsduDescriptor::Ieee80211AMsduDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AMsdu", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

Ieee80211AMsduDescriptor::~Ieee80211AMsduDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AMsduDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AMsdu *>(obj)!=nullptr;
}

const char **Ieee80211AMsduDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AMsduDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AMsduDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211AMsduDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT | FD_ISCOWNEDOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AMsduDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "subframes",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211AMsduDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "subframes")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AMsduDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211MsduSubframe",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AMsduDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AMsduDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AMsduDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AMsdu *pp = (Ieee80211AMsdu *)object; (void)pp;
    switch (field) {
        case 0: return pp->getSubframesArraySize();
        default: return 0;
    }
}

const char *Ieee80211AMsduDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AMsdu *pp = (Ieee80211AMsdu *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AMsduDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AMsdu *pp = (Ieee80211AMsdu *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSubframes(i); return out.str();}
        default: return "";
    }
}

bool Ieee80211AMsduDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AMsdu *pp = (Ieee80211AMsdu *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211AMsduDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211MsduSubframe));
        default: return nullptr;
    };
}

void *Ieee80211AMsduDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AMsdu *pp = (Ieee80211AMsdu *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getSubframes(i)); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AddbaRequest)

Ieee80211AddbaRequest::Ieee80211AddbaRequest(const char *name, short kind) : ::inet::ieee80211::Ieee80211ActionFrame(name,kind)
{
    this->setByteLength(LENGTH_ADDBAREQ / 8);
    this->setCategory(3);

    this->blockAckAction = 0;
    this->dialogToken = 1;
    this->aMsduSupported = false;
    this->blockAckPolicy = false;
    this->tid = 0;
    this->bufferSize = 0;
    this->blockAckTimeoutValue = 0;
    this->_fragmentNumber = 0;
    this->startingSequenceNumber = 0;
}

Ieee80211AddbaRequest::Ieee80211AddbaRequest(const Ieee80211AddbaRequest& other) : ::inet::ieee80211::Ieee80211ActionFrame(other)
{
    copy(other);
}

Ieee80211AddbaRequest::~Ieee80211AddbaRequest()
{
}

Ieee80211AddbaRequest& Ieee80211AddbaRequest::operator=(const Ieee80211AddbaRequest& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ActionFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AddbaRequest::copy(const Ieee80211AddbaRequest& other)
{
    this->blockAckAction = other.blockAckAction;
    this->dialogToken = other.dialogToken;
    this->aMsduSupported = other.aMsduSupported;
    this->blockAckPolicy = other.blockAckPolicy;
    this->tid = other.tid;
    this->bufferSize = other.bufferSize;
    this->blockAckTimeoutValue = other.blockAckTimeoutValue;
    this->_fragmentNumber = other._fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
}

void Ieee80211AddbaRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimPack(b);
    doParsimPacking(b,this->blockAckAction);
    doParsimPacking(b,this->dialogToken);
    doParsimPacking(b,this->aMsduSupported);
    doParsimPacking(b,this->blockAckPolicy);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->bufferSize);
    doParsimPacking(b,this->blockAckTimeoutValue);
    doParsimPacking(b,this->_fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
}

void Ieee80211AddbaRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->blockAckAction);
    doParsimUnpacking(b,this->dialogToken);
    doParsimUnpacking(b,this->aMsduSupported);
    doParsimUnpacking(b,this->blockAckPolicy);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->bufferSize);
    doParsimUnpacking(b,this->blockAckTimeoutValue);
    doParsimUnpacking(b,this->_fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
}

int Ieee80211AddbaRequest::getBlockAckAction() const
{
    return this->blockAckAction;
}

void Ieee80211AddbaRequest::setBlockAckAction(int blockAckAction)
{
    this->blockAckAction = blockAckAction;
}

int Ieee80211AddbaRequest::getDialogToken() const
{
    return this->dialogToken;
}

void Ieee80211AddbaRequest::setDialogToken(int dialogToken)
{
    this->dialogToken = dialogToken;
}

bool Ieee80211AddbaRequest::getAMsduSupported() const
{
    return this->aMsduSupported;
}

void Ieee80211AddbaRequest::setAMsduSupported(bool aMsduSupported)
{
    this->aMsduSupported = aMsduSupported;
}

bool Ieee80211AddbaRequest::getBlockAckPolicy() const
{
    return this->blockAckPolicy;
}

void Ieee80211AddbaRequest::setBlockAckPolicy(bool blockAckPolicy)
{
    this->blockAckPolicy = blockAckPolicy;
}

int Ieee80211AddbaRequest::getTid() const
{
    return this->tid;
}

void Ieee80211AddbaRequest::setTid(int tid)
{
    this->tid = tid;
}

int Ieee80211AddbaRequest::getBufferSize() const
{
    return this->bufferSize;
}

void Ieee80211AddbaRequest::setBufferSize(int bufferSize)
{
    this->bufferSize = bufferSize;
}

::omnetpp::simtime_t Ieee80211AddbaRequest::getBlockAckTimeoutValue() const
{
    return this->blockAckTimeoutValue;
}

void Ieee80211AddbaRequest::setBlockAckTimeoutValue(::omnetpp::simtime_t blockAckTimeoutValue)
{
    this->blockAckTimeoutValue = blockAckTimeoutValue;
}

int Ieee80211AddbaRequest::get_fragmentNumber() const
{
    return this->_fragmentNumber;
}

void Ieee80211AddbaRequest::set_fragmentNumber(int _fragmentNumber)
{
    this->_fragmentNumber = _fragmentNumber;
}

int Ieee80211AddbaRequest::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211AddbaRequest::setStartingSequenceNumber(int startingSequenceNumber)
{
    this->startingSequenceNumber = startingSequenceNumber;
}

class Ieee80211AddbaRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AddbaRequestDescriptor();
    virtual ~Ieee80211AddbaRequestDescriptor();

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

Register_ClassDescriptor(Ieee80211AddbaRequestDescriptor)

Ieee80211AddbaRequestDescriptor::Ieee80211AddbaRequestDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AddbaRequest", "inet::ieee80211::Ieee80211ActionFrame")
{
    propertynames = nullptr;
}

Ieee80211AddbaRequestDescriptor::~Ieee80211AddbaRequestDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AddbaRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AddbaRequest *>(obj)!=nullptr;
}

const char **Ieee80211AddbaRequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AddbaRequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AddbaRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee80211AddbaRequestDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AddbaRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "blockAckAction",
        "dialogToken",
        "aMsduSupported",
        "blockAckPolicy",
        "tid",
        "bufferSize",
        "blockAckTimeoutValue",
        "_fragmentNumber",
        "startingSequenceNumber",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int Ieee80211AddbaRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckAction")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dialogToken")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "aMsduSupported")==0) return base+2;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckPolicy")==0) return base+3;
    if (fieldName[0]=='t' && strcmp(fieldName, "tid")==0) return base+4;
    if (fieldName[0]=='b' && strcmp(fieldName, "bufferSize")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckTimeoutValue")==0) return base+6;
    if (fieldName[0]=='_' && strcmp(fieldName, "_fragmentNumber")==0) return base+7;
    if (fieldName[0]=='s' && strcmp(fieldName, "startingSequenceNumber")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AddbaRequestDescriptor::getFieldTypeString(int field) const
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
        "bool",
        "bool",
        "int",
        "int",
        "simtime_t",
        "int",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AddbaRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AddbaRequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AddbaRequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AddbaRequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AddbaRequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getBlockAckAction());
        case 1: return long2string(pp->getDialogToken());
        case 2: return bool2string(pp->getAMsduSupported());
        case 3: return bool2string(pp->getBlockAckPolicy());
        case 4: return long2string(pp->getTid());
        case 5: return long2string(pp->getBufferSize());
        case 6: return simtime2string(pp->getBlockAckTimeoutValue());
        case 7: return long2string(pp->get_fragmentNumber());
        case 8: return long2string(pp->getStartingSequenceNumber());
        default: return "";
    }
}

bool Ieee80211AddbaRequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        case 0: pp->setBlockAckAction(string2long(value)); return true;
        case 1: pp->setDialogToken(string2long(value)); return true;
        case 2: pp->setAMsduSupported(string2bool(value)); return true;
        case 3: pp->setBlockAckPolicy(string2bool(value)); return true;
        case 4: pp->setTid(string2long(value)); return true;
        case 5: pp->setBufferSize(string2long(value)); return true;
        case 6: pp->setBlockAckTimeoutValue(string2simtime(value)); return true;
        case 7: pp->set_fragmentNumber(string2long(value)); return true;
        case 8: pp->setStartingSequenceNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211AddbaRequestDescriptor::getFieldStructName(int field) const
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

void *Ieee80211AddbaRequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaRequest *pp = (Ieee80211AddbaRequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211AddbaResponse)

Ieee80211AddbaResponse::Ieee80211AddbaResponse(const char *name, short kind) : ::inet::ieee80211::Ieee80211ActionFrame(name,kind)
{
    this->setCategory(3);

    this->blockAckAction = 1;
    this->dialogToken = 1;
    this->statusCode = 0;
    this->aMsduSupported = false;
    this->blockAckPolicy = false;
    this->tid = 0;
    this->bufferSize = 0;
    this->blockAckTimeoutValue = 0;
}

Ieee80211AddbaResponse::Ieee80211AddbaResponse(const Ieee80211AddbaResponse& other) : ::inet::ieee80211::Ieee80211ActionFrame(other)
{
    copy(other);
}

Ieee80211AddbaResponse::~Ieee80211AddbaResponse()
{
}

Ieee80211AddbaResponse& Ieee80211AddbaResponse::operator=(const Ieee80211AddbaResponse& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ActionFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AddbaResponse::copy(const Ieee80211AddbaResponse& other)
{
    this->blockAckAction = other.blockAckAction;
    this->dialogToken = other.dialogToken;
    this->statusCode = other.statusCode;
    this->aMsduSupported = other.aMsduSupported;
    this->blockAckPolicy = other.blockAckPolicy;
    this->tid = other.tid;
    this->bufferSize = other.bufferSize;
    this->blockAckTimeoutValue = other.blockAckTimeoutValue;
}

void Ieee80211AddbaResponse::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimPack(b);
    doParsimPacking(b,this->blockAckAction);
    doParsimPacking(b,this->dialogToken);
    doParsimPacking(b,this->statusCode);
    doParsimPacking(b,this->aMsduSupported);
    doParsimPacking(b,this->blockAckPolicy);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->bufferSize);
    doParsimPacking(b,this->blockAckTimeoutValue);
}

void Ieee80211AddbaResponse::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->blockAckAction);
    doParsimUnpacking(b,this->dialogToken);
    doParsimUnpacking(b,this->statusCode);
    doParsimUnpacking(b,this->aMsduSupported);
    doParsimUnpacking(b,this->blockAckPolicy);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->bufferSize);
    doParsimUnpacking(b,this->blockAckTimeoutValue);
}

int Ieee80211AddbaResponse::getBlockAckAction() const
{
    return this->blockAckAction;
}

void Ieee80211AddbaResponse::setBlockAckAction(int blockAckAction)
{
    this->blockAckAction = blockAckAction;
}

int Ieee80211AddbaResponse::getDialogToken() const
{
    return this->dialogToken;
}

void Ieee80211AddbaResponse::setDialogToken(int dialogToken)
{
    this->dialogToken = dialogToken;
}

int Ieee80211AddbaResponse::getStatusCode() const
{
    return this->statusCode;
}

void Ieee80211AddbaResponse::setStatusCode(int statusCode)
{
    this->statusCode = statusCode;
}

bool Ieee80211AddbaResponse::getAMsduSupported() const
{
    return this->aMsduSupported;
}

void Ieee80211AddbaResponse::setAMsduSupported(bool aMsduSupported)
{
    this->aMsduSupported = aMsduSupported;
}

bool Ieee80211AddbaResponse::getBlockAckPolicy() const
{
    return this->blockAckPolicy;
}

void Ieee80211AddbaResponse::setBlockAckPolicy(bool blockAckPolicy)
{
    this->blockAckPolicy = blockAckPolicy;
}

int Ieee80211AddbaResponse::getTid() const
{
    return this->tid;
}

void Ieee80211AddbaResponse::setTid(int tid)
{
    this->tid = tid;
}

int Ieee80211AddbaResponse::getBufferSize() const
{
    return this->bufferSize;
}

void Ieee80211AddbaResponse::setBufferSize(int bufferSize)
{
    this->bufferSize = bufferSize;
}

::omnetpp::simtime_t Ieee80211AddbaResponse::getBlockAckTimeoutValue() const
{
    return this->blockAckTimeoutValue;
}

void Ieee80211AddbaResponse::setBlockAckTimeoutValue(::omnetpp::simtime_t blockAckTimeoutValue)
{
    this->blockAckTimeoutValue = blockAckTimeoutValue;
}

class Ieee80211AddbaResponseDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AddbaResponseDescriptor();
    virtual ~Ieee80211AddbaResponseDescriptor();

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

Register_ClassDescriptor(Ieee80211AddbaResponseDescriptor)

Ieee80211AddbaResponseDescriptor::Ieee80211AddbaResponseDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AddbaResponse", "inet::ieee80211::Ieee80211ActionFrame")
{
    propertynames = nullptr;
}

Ieee80211AddbaResponseDescriptor::~Ieee80211AddbaResponseDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AddbaResponseDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AddbaResponse *>(obj)!=nullptr;
}

const char **Ieee80211AddbaResponseDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AddbaResponseDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AddbaResponseDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int Ieee80211AddbaResponseDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AddbaResponseDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "blockAckAction",
        "dialogToken",
        "statusCode",
        "aMsduSupported",
        "blockAckPolicy",
        "tid",
        "bufferSize",
        "blockAckTimeoutValue",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int Ieee80211AddbaResponseDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckAction")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dialogToken")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "statusCode")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "aMsduSupported")==0) return base+3;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckPolicy")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "tid")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "bufferSize")==0) return base+6;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckTimeoutValue")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AddbaResponseDescriptor::getFieldTypeString(int field) const
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
        "bool",
        "bool",
        "int",
        "int",
        "simtime_t",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AddbaResponseDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AddbaResponseDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AddbaResponseDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AddbaResponseDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AddbaResponseDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getBlockAckAction());
        case 1: return long2string(pp->getDialogToken());
        case 2: return long2string(pp->getStatusCode());
        case 3: return bool2string(pp->getAMsduSupported());
        case 4: return bool2string(pp->getBlockAckPolicy());
        case 5: return long2string(pp->getTid());
        case 6: return long2string(pp->getBufferSize());
        case 7: return simtime2string(pp->getBlockAckTimeoutValue());
        default: return "";
    }
}

bool Ieee80211AddbaResponseDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        case 0: pp->setBlockAckAction(string2long(value)); return true;
        case 1: pp->setDialogToken(string2long(value)); return true;
        case 2: pp->setStatusCode(string2long(value)); return true;
        case 3: pp->setAMsduSupported(string2bool(value)); return true;
        case 4: pp->setBlockAckPolicy(string2bool(value)); return true;
        case 5: pp->setTid(string2long(value)); return true;
        case 6: pp->setBufferSize(string2long(value)); return true;
        case 7: pp->setBlockAckTimeoutValue(string2simtime(value)); return true;
        default: return false;
    }
}

const char *Ieee80211AddbaResponseDescriptor::getFieldStructName(int field) const
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

void *Ieee80211AddbaResponseDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AddbaResponse *pp = (Ieee80211AddbaResponse *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211Delba)

Ieee80211Delba::Ieee80211Delba(const char *name, short kind) : ::inet::ieee80211::Ieee80211ActionFrame(name,kind)
{
    this->setCategory(3);

    this->blockAckAction = 2;
    this->initiator = false;
    this->tid = 0;
    this->reasonCode = 0;
}

Ieee80211Delba::Ieee80211Delba(const Ieee80211Delba& other) : ::inet::ieee80211::Ieee80211ActionFrame(other)
{
    copy(other);
}

Ieee80211Delba::~Ieee80211Delba()
{
}

Ieee80211Delba& Ieee80211Delba::operator=(const Ieee80211Delba& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ActionFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211Delba::copy(const Ieee80211Delba& other)
{
    this->blockAckAction = other.blockAckAction;
    this->initiator = other.initiator;
    this->tid = other.tid;
    this->reasonCode = other.reasonCode;
}

void Ieee80211Delba::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimPack(b);
    doParsimPacking(b,this->blockAckAction);
    doParsimPacking(b,this->initiator);
    doParsimPacking(b,this->tid);
    doParsimPacking(b,this->reasonCode);
}

void Ieee80211Delba::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ActionFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->blockAckAction);
    doParsimUnpacking(b,this->initiator);
    doParsimUnpacking(b,this->tid);
    doParsimUnpacking(b,this->reasonCode);
}

int Ieee80211Delba::getBlockAckAction() const
{
    return this->blockAckAction;
}

void Ieee80211Delba::setBlockAckAction(int blockAckAction)
{
    this->blockAckAction = blockAckAction;
}

bool Ieee80211Delba::getInitiator() const
{
    return this->initiator;
}

void Ieee80211Delba::setInitiator(bool initiator)
{
    this->initiator = initiator;
}

int Ieee80211Delba::getTid() const
{
    return this->tid;
}

void Ieee80211Delba::setTid(int tid)
{
    this->tid = tid;
}

int Ieee80211Delba::getReasonCode() const
{
    return this->reasonCode;
}

void Ieee80211Delba::setReasonCode(int reasonCode)
{
    this->reasonCode = reasonCode;
}

class Ieee80211DelbaDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DelbaDescriptor();
    virtual ~Ieee80211DelbaDescriptor();

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

Register_ClassDescriptor(Ieee80211DelbaDescriptor)

Ieee80211DelbaDescriptor::Ieee80211DelbaDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211Delba", "inet::ieee80211::Ieee80211ActionFrame")
{
    propertynames = nullptr;
}

Ieee80211DelbaDescriptor::~Ieee80211DelbaDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DelbaDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211Delba *>(obj)!=nullptr;
}

const char **Ieee80211DelbaDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DelbaDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DelbaDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211DelbaDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211DelbaDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "blockAckAction",
        "initiator",
        "tid",
        "reasonCode",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int Ieee80211DelbaDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckAction")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "initiator")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tid")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "reasonCode")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DelbaDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "bool",
        "int",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DelbaDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DelbaDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211DelbaDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DelbaDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DelbaDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getBlockAckAction());
        case 1: return bool2string(pp->getInitiator());
        case 2: return long2string(pp->getTid());
        case 3: return long2string(pp->getReasonCode());
        default: return "";
    }
}

bool Ieee80211DelbaDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        case 0: pp->setBlockAckAction(string2long(value)); return true;
        case 1: pp->setInitiator(string2bool(value)); return true;
        case 2: pp->setTid(string2long(value)); return true;
        case 3: pp->setReasonCode(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211DelbaDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DelbaDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211Delba *pp = (Ieee80211Delba *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BlockAckReq)

Ieee80211BlockAckReq::Ieee80211BlockAckReq(const char *name, short kind) : ::inet::ieee80211::Ieee80211TwoAddressFrame(name,kind)
{
    this->setType(ST_BLOCKACK_REQ);

    this->multiTid = false;
    this->compressedBitmap = false;
    this->barAckPolicy = false;
}

Ieee80211BlockAckReq::Ieee80211BlockAckReq(const Ieee80211BlockAckReq& other) : ::inet::ieee80211::Ieee80211TwoAddressFrame(other)
{
    copy(other);
}

Ieee80211BlockAckReq::~Ieee80211BlockAckReq()
{
}

Ieee80211BlockAckReq& Ieee80211BlockAckReq::operator=(const Ieee80211BlockAckReq& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BlockAckReq::copy(const Ieee80211BlockAckReq& other)
{
    this->multiTid = other.multiTid;
    this->compressedBitmap = other.compressedBitmap;
    this->barAckPolicy = other.barAckPolicy;
}

void Ieee80211BlockAckReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimPack(b);
    doParsimPacking(b,this->multiTid);
    doParsimPacking(b,this->compressedBitmap);
    doParsimPacking(b,this->barAckPolicy);
}

void Ieee80211BlockAckReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->multiTid);
    doParsimUnpacking(b,this->compressedBitmap);
    doParsimUnpacking(b,this->barAckPolicy);
}

bool Ieee80211BlockAckReq::getMultiTid() const
{
    return this->multiTid;
}

void Ieee80211BlockAckReq::setMultiTid(bool multiTid)
{
    this->multiTid = multiTid;
}

bool Ieee80211BlockAckReq::getCompressedBitmap() const
{
    return this->compressedBitmap;
}

void Ieee80211BlockAckReq::setCompressedBitmap(bool compressedBitmap)
{
    this->compressedBitmap = compressedBitmap;
}

bool Ieee80211BlockAckReq::getBarAckPolicy() const
{
    return this->barAckPolicy;
}

void Ieee80211BlockAckReq::setBarAckPolicy(bool barAckPolicy)
{
    this->barAckPolicy = barAckPolicy;
}

class Ieee80211BlockAckReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211BlockAckReqDescriptor();
    virtual ~Ieee80211BlockAckReqDescriptor();

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

Register_ClassDescriptor(Ieee80211BlockAckReqDescriptor)

Ieee80211BlockAckReqDescriptor::Ieee80211BlockAckReqDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211BlockAckReq", "inet::ieee80211::Ieee80211TwoAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211BlockAckReqDescriptor::~Ieee80211BlockAckReqDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BlockAckReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BlockAckReq *>(obj)!=nullptr;
}

const char **Ieee80211BlockAckReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BlockAckReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BlockAckReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211BlockAckReqDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211BlockAckReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "multiTid",
        "compressedBitmap",
        "barAckPolicy",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211BlockAckReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multiTid")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "compressedBitmap")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "barAckPolicy")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BlockAckReqDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BlockAckReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BlockAckReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BlockAckReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BlockAckReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BlockAckReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getMultiTid());
        case 1: return bool2string(pp->getCompressedBitmap());
        case 2: return bool2string(pp->getBarAckPolicy());
        default: return "";
    }
}

bool Ieee80211BlockAckReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setMultiTid(string2bool(value)); return true;
        case 1: pp->setCompressedBitmap(string2bool(value)); return true;
        case 2: pp->setBarAckPolicy(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BlockAckReqDescriptor::getFieldStructName(int field) const
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

void *Ieee80211BlockAckReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAckReq *pp = (Ieee80211BlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BasicBlockAckReq)

Ieee80211BasicBlockAckReq::Ieee80211BasicBlockAckReq(const char *name, short kind) : ::inet::ieee80211::Ieee80211BlockAckReq(name,kind)
{
    this->setMultiTid(0);
    this->setCompressedBitmap(0);

    this->tidInfo = 0;
    this->fragmentNumber = 0;
    this->startingSequenceNumber = 0;
}

Ieee80211BasicBlockAckReq::Ieee80211BasicBlockAckReq(const Ieee80211BasicBlockAckReq& other) : ::inet::ieee80211::Ieee80211BlockAckReq(other)
{
    copy(other);
}

Ieee80211BasicBlockAckReq::~Ieee80211BasicBlockAckReq()
{
}

Ieee80211BasicBlockAckReq& Ieee80211BasicBlockAckReq::operator=(const Ieee80211BasicBlockAckReq& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211BlockAckReq::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BasicBlockAckReq::copy(const Ieee80211BasicBlockAckReq& other)
{
    this->tidInfo = other.tidInfo;
    this->fragmentNumber = other.fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
}

void Ieee80211BasicBlockAckReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimPack(b);
    doParsimPacking(b,this->tidInfo);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
}

void Ieee80211BasicBlockAckReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimUnpack(b);
    doParsimUnpacking(b,this->tidInfo);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
}

int Ieee80211BasicBlockAckReq::getTidInfo() const
{
    return this->tidInfo;
}

void Ieee80211BasicBlockAckReq::setTidInfo(int tidInfo)
{
    this->tidInfo = tidInfo;
}

int Ieee80211BasicBlockAckReq::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211BasicBlockAckReq::setFragmentNumber(int fragmentNumber)
{
    this->fragmentNumber = fragmentNumber;
}

int Ieee80211BasicBlockAckReq::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211BasicBlockAckReq::setStartingSequenceNumber(int startingSequenceNumber)
{
    this->startingSequenceNumber = startingSequenceNumber;
}

class Ieee80211BasicBlockAckReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211BasicBlockAckReqDescriptor();
    virtual ~Ieee80211BasicBlockAckReqDescriptor();

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

Register_ClassDescriptor(Ieee80211BasicBlockAckReqDescriptor)

Ieee80211BasicBlockAckReqDescriptor::Ieee80211BasicBlockAckReqDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211BasicBlockAckReq", "inet::ieee80211::Ieee80211BlockAckReq")
{
    propertynames = nullptr;
}

Ieee80211BasicBlockAckReqDescriptor::~Ieee80211BasicBlockAckReqDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BasicBlockAckReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BasicBlockAckReq *>(obj)!=nullptr;
}

const char **Ieee80211BasicBlockAckReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BasicBlockAckReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BasicBlockAckReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211BasicBlockAckReqDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tidInfo",
        "fragmentNumber",
        "startingSequenceNumber",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211BasicBlockAckReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tidInfo")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentNumber")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "startingSequenceNumber")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BasicBlockAckReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BasicBlockAckReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BasicBlockAckReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTidInfo());
        case 1: return long2string(pp->getFragmentNumber());
        case 2: return long2string(pp->getStartingSequenceNumber());
        default: return "";
    }
}

bool Ieee80211BasicBlockAckReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setTidInfo(string2long(value)); return true;
        case 1: pp->setFragmentNumber(string2long(value)); return true;
        case 2: pp->setStartingSequenceNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BasicBlockAckReqDescriptor::getFieldStructName(int field) const
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

void *Ieee80211BasicBlockAckReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAckReq *pp = (Ieee80211BasicBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211CompressedBlockAckReq)

Ieee80211CompressedBlockAckReq::Ieee80211CompressedBlockAckReq(const char *name, short kind) : ::inet::ieee80211::Ieee80211BlockAckReq(name,kind)
{
    this->setType(ST_BLOCKACK_REQ);
    this->setMultiTid(0);
    this->setCompressedBitmap(1);

    this->tidInfo = 0;
    this->fragmentNumber = 0;
    this->startingSequenceNumber = 0;
}

Ieee80211CompressedBlockAckReq::Ieee80211CompressedBlockAckReq(const Ieee80211CompressedBlockAckReq& other) : ::inet::ieee80211::Ieee80211BlockAckReq(other)
{
    copy(other);
}

Ieee80211CompressedBlockAckReq::~Ieee80211CompressedBlockAckReq()
{
}

Ieee80211CompressedBlockAckReq& Ieee80211CompressedBlockAckReq::operator=(const Ieee80211CompressedBlockAckReq& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211BlockAckReq::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211CompressedBlockAckReq::copy(const Ieee80211CompressedBlockAckReq& other)
{
    this->tidInfo = other.tidInfo;
    this->fragmentNumber = other.fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
}

void Ieee80211CompressedBlockAckReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimPack(b);
    doParsimPacking(b,this->tidInfo);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
}

void Ieee80211CompressedBlockAckReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimUnpack(b);
    doParsimUnpacking(b,this->tidInfo);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
}

int Ieee80211CompressedBlockAckReq::getTidInfo() const
{
    return this->tidInfo;
}

void Ieee80211CompressedBlockAckReq::setTidInfo(int tidInfo)
{
    this->tidInfo = tidInfo;
}

int Ieee80211CompressedBlockAckReq::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211CompressedBlockAckReq::setFragmentNumber(int fragmentNumber)
{
    this->fragmentNumber = fragmentNumber;
}

int Ieee80211CompressedBlockAckReq::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211CompressedBlockAckReq::setStartingSequenceNumber(int startingSequenceNumber)
{
    this->startingSequenceNumber = startingSequenceNumber;
}

class Ieee80211CompressedBlockAckReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211CompressedBlockAckReqDescriptor();
    virtual ~Ieee80211CompressedBlockAckReqDescriptor();

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

Register_ClassDescriptor(Ieee80211CompressedBlockAckReqDescriptor)

Ieee80211CompressedBlockAckReqDescriptor::Ieee80211CompressedBlockAckReqDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211CompressedBlockAckReq", "inet::ieee80211::Ieee80211BlockAckReq")
{
    propertynames = nullptr;
}

Ieee80211CompressedBlockAckReqDescriptor::~Ieee80211CompressedBlockAckReqDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CompressedBlockAckReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CompressedBlockAckReq *>(obj)!=nullptr;
}

const char **Ieee80211CompressedBlockAckReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CompressedBlockAckReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211CompressedBlockAckReqDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tidInfo",
        "fragmentNumber",
        "startingSequenceNumber",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211CompressedBlockAckReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tidInfo")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentNumber")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "startingSequenceNumber")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211CompressedBlockAckReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211CompressedBlockAckReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211CompressedBlockAckReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getTidInfo());
        case 1: return long2string(pp->getFragmentNumber());
        case 2: return long2string(pp->getStartingSequenceNumber());
        default: return "";
    }
}

bool Ieee80211CompressedBlockAckReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        case 0: pp->setTidInfo(string2long(value)); return true;
        case 1: pp->setFragmentNumber(string2long(value)); return true;
        case 2: pp->setStartingSequenceNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211CompressedBlockAckReqDescriptor::getFieldStructName(int field) const
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

void *Ieee80211CompressedBlockAckReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAckReq *pp = (Ieee80211CompressedBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211MultiTidBlockAckReq)

Ieee80211MultiTidBlockAckReq::Ieee80211MultiTidBlockAckReq(const char *name, short kind) : ::inet::ieee80211::Ieee80211BlockAckReq(name,kind)
{
    this->setType(ST_BLOCKACK_REQ);
    this->setMultiTid(1);
    this->setCompressedBitmap(1);
}

Ieee80211MultiTidBlockAckReq::Ieee80211MultiTidBlockAckReq(const Ieee80211MultiTidBlockAckReq& other) : ::inet::ieee80211::Ieee80211BlockAckReq(other)
{
    copy(other);
}

Ieee80211MultiTidBlockAckReq::~Ieee80211MultiTidBlockAckReq()
{
}

Ieee80211MultiTidBlockAckReq& Ieee80211MultiTidBlockAckReq::operator=(const Ieee80211MultiTidBlockAckReq& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211BlockAckReq::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MultiTidBlockAckReq::copy(const Ieee80211MultiTidBlockAckReq& other)
{
}

void Ieee80211MultiTidBlockAckReq::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimPack(b);
}

void Ieee80211MultiTidBlockAckReq::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAckReq::parsimUnpack(b);
}

class Ieee80211MultiTidBlockAckReqDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211MultiTidBlockAckReqDescriptor();
    virtual ~Ieee80211MultiTidBlockAckReqDescriptor();

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

Register_ClassDescriptor(Ieee80211MultiTidBlockAckReqDescriptor)

Ieee80211MultiTidBlockAckReqDescriptor::Ieee80211MultiTidBlockAckReqDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211MultiTidBlockAckReq", "inet::ieee80211::Ieee80211BlockAckReq")
{
    propertynames = nullptr;
}

Ieee80211MultiTidBlockAckReqDescriptor::~Ieee80211MultiTidBlockAckReqDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MultiTidBlockAckReqDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MultiTidBlockAckReq *>(obj)!=nullptr;
}

const char **Ieee80211MultiTidBlockAckReqDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MultiTidBlockAckReqDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211MultiTidBlockAckReqDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211MultiTidBlockAckReqDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211MultiTidBlockAckReqDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211MultiTidBlockAckReqDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MultiTidBlockAckReqDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211MultiTidBlockAckReqDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211MultiTidBlockAckReqDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211MultiTidBlockAckReqDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAckReq *pp = (Ieee80211MultiTidBlockAckReq *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BlockAck)

Ieee80211BlockAck::Ieee80211BlockAck(const char *name, short kind) : ::inet::ieee80211::Ieee80211TwoAddressFrame(name,kind)
{
    this->setType(ST_BLOCKACK);

    this->blockAckPolicy = false;
    this->multiTid = false;
    this->compressedBitmap = false;
}

Ieee80211BlockAck::Ieee80211BlockAck(const Ieee80211BlockAck& other) : ::inet::ieee80211::Ieee80211TwoAddressFrame(other)
{
    copy(other);
}

Ieee80211BlockAck::~Ieee80211BlockAck()
{
}

Ieee80211BlockAck& Ieee80211BlockAck::operator=(const Ieee80211BlockAck& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211TwoAddressFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BlockAck::copy(const Ieee80211BlockAck& other)
{
    this->blockAckPolicy = other.blockAckPolicy;
    this->multiTid = other.multiTid;
    this->compressedBitmap = other.compressedBitmap;
}

void Ieee80211BlockAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimPack(b);
    doParsimPacking(b,this->blockAckPolicy);
    doParsimPacking(b,this->multiTid);
    doParsimPacking(b,this->compressedBitmap);
}

void Ieee80211BlockAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211TwoAddressFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->blockAckPolicy);
    doParsimUnpacking(b,this->multiTid);
    doParsimUnpacking(b,this->compressedBitmap);
}

bool Ieee80211BlockAck::getBlockAckPolicy() const
{
    return this->blockAckPolicy;
}

void Ieee80211BlockAck::setBlockAckPolicy(bool blockAckPolicy)
{
    this->blockAckPolicy = blockAckPolicy;
}

bool Ieee80211BlockAck::getMultiTid() const
{
    return this->multiTid;
}

void Ieee80211BlockAck::setMultiTid(bool multiTid)
{
    this->multiTid = multiTid;
}

bool Ieee80211BlockAck::getCompressedBitmap() const
{
    return this->compressedBitmap;
}

void Ieee80211BlockAck::setCompressedBitmap(bool compressedBitmap)
{
    this->compressedBitmap = compressedBitmap;
}

class Ieee80211BlockAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211BlockAckDescriptor();
    virtual ~Ieee80211BlockAckDescriptor();

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

Register_ClassDescriptor(Ieee80211BlockAckDescriptor)

Ieee80211BlockAckDescriptor::Ieee80211BlockAckDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211BlockAck", "inet::ieee80211::Ieee80211TwoAddressFrame")
{
    propertynames = nullptr;
}

Ieee80211BlockAckDescriptor::~Ieee80211BlockAckDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BlockAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BlockAck *>(obj)!=nullptr;
}

const char **Ieee80211BlockAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BlockAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BlockAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211BlockAckDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211BlockAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "blockAckPolicy",
        "multiTid",
        "compressedBitmap",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211BlockAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckPolicy")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "multiTid")==0) return base+1;
    if (fieldName[0]=='c' && strcmp(fieldName, "compressedBitmap")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BlockAckDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BlockAckDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BlockAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BlockAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BlockAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BlockAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getBlockAckPolicy());
        case 1: return bool2string(pp->getMultiTid());
        case 2: return bool2string(pp->getCompressedBitmap());
        default: return "";
    }
}

bool Ieee80211BlockAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        case 0: pp->setBlockAckPolicy(string2bool(value)); return true;
        case 1: pp->setMultiTid(string2bool(value)); return true;
        case 2: pp->setCompressedBitmap(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BlockAckDescriptor::getFieldStructName(int field) const
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

void *Ieee80211BlockAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BlockAck *pp = (Ieee80211BlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BasicBlockAck)

Ieee80211BasicBlockAck::Ieee80211BasicBlockAck(const char *name, short kind) : ::inet::ieee80211::Ieee80211BlockAck(name,kind)
{
    this->setMultiTid(0);
    this->setCompressedBitmap(0);

    this->fragmentNumber = 0;
    this->startingSequenceNumber = 0;
    this->tidInfo = 0;
}

Ieee80211BasicBlockAck::Ieee80211BasicBlockAck(const Ieee80211BasicBlockAck& other) : ::inet::ieee80211::Ieee80211BlockAck(other)
{
    copy(other);
}

Ieee80211BasicBlockAck::~Ieee80211BasicBlockAck()
{
}

Ieee80211BasicBlockAck& Ieee80211BasicBlockAck::operator=(const Ieee80211BasicBlockAck& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211BlockAck::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BasicBlockAck::copy(const Ieee80211BasicBlockAck& other)
{
    this->fragmentNumber = other.fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
    for (unsigned int i=0; i<64; i++)
        this->blockAckBitmap[i] = other.blockAckBitmap[i];
    this->tidInfo = other.tidInfo;
}

void Ieee80211BasicBlockAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimPack(b);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
    doParsimArrayPacking(b,this->blockAckBitmap,64);
    doParsimPacking(b,this->tidInfo);
}

void Ieee80211BasicBlockAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimUnpack(b);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
    doParsimArrayUnpacking(b,this->blockAckBitmap,64);
    doParsimUnpacking(b,this->tidInfo);
}

int Ieee80211BasicBlockAck::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211BasicBlockAck::setFragmentNumber(int fragmentNumber)
{
    this->fragmentNumber = fragmentNumber;
}

int Ieee80211BasicBlockAck::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211BasicBlockAck::setStartingSequenceNumber(int startingSequenceNumber)
{
    this->startingSequenceNumber = startingSequenceNumber;
}

unsigned int Ieee80211BasicBlockAck::getBlockAckBitmapArraySize() const
{
    return 64;
}

BitVector& Ieee80211BasicBlockAck::getBlockAckBitmap(unsigned int k)
{
    if (k>=64) throw omnetpp::cRuntimeError("Array of size 64 indexed by %lu", (unsigned long)k);
    return this->blockAckBitmap[k];
}

void Ieee80211BasicBlockAck::setBlockAckBitmap(unsigned int k, const BitVector& blockAckBitmap)
{
    if (k>=64) throw omnetpp::cRuntimeError("Array of size 64 indexed by %lu", (unsigned long)k);
    this->blockAckBitmap[k] = blockAckBitmap;
}

int Ieee80211BasicBlockAck::getTidInfo() const
{
    return this->tidInfo;
}

void Ieee80211BasicBlockAck::setTidInfo(int tidInfo)
{
    this->tidInfo = tidInfo;
}

class Ieee80211BasicBlockAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211BasicBlockAckDescriptor();
    virtual ~Ieee80211BasicBlockAckDescriptor();

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

Register_ClassDescriptor(Ieee80211BasicBlockAckDescriptor)

Ieee80211BasicBlockAckDescriptor::Ieee80211BasicBlockAckDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211BasicBlockAck", "inet::ieee80211::Ieee80211BlockAck")
{
    propertynames = nullptr;
}

Ieee80211BasicBlockAckDescriptor::~Ieee80211BasicBlockAckDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BasicBlockAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BasicBlockAck *>(obj)!=nullptr;
}

const char **Ieee80211BasicBlockAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BasicBlockAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BasicBlockAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211BasicBlockAckDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211BasicBlockAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fragmentNumber",
        "startingSequenceNumber",
        "blockAckBitmap",
        "tidInfo",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int Ieee80211BasicBlockAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentNumber")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "startingSequenceNumber")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckBitmap")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "tidInfo")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BasicBlockAckDescriptor::getFieldTypeString(int field) const
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
        "BitVector",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BasicBlockAckDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BasicBlockAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BasicBlockAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        case 2: return 64;
        default: return 0;
    }
}

const char *Ieee80211BasicBlockAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BasicBlockAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFragmentNumber());
        case 1: return long2string(pp->getStartingSequenceNumber());
        case 2: {std::stringstream out; out << pp->getBlockAckBitmap(i); return out.str();}
        case 3: return long2string(pp->getTidInfo());
        default: return "";
    }
}

bool Ieee80211BasicBlockAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        case 0: pp->setFragmentNumber(string2long(value)); return true;
        case 1: pp->setStartingSequenceNumber(string2long(value)); return true;
        case 3: pp->setTidInfo(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BasicBlockAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(BitVector));
        default: return nullptr;
    };
}

void *Ieee80211BasicBlockAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BasicBlockAck *pp = (Ieee80211BasicBlockAck *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getBlockAckBitmap(i)); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211CompressedBlockAck)

Ieee80211CompressedBlockAck::Ieee80211CompressedBlockAck(const char *name, short kind) : ::inet::ieee80211::Ieee80211BlockAck(name,kind)
{
    this->setMultiTid(0);
    this->setCompressedBitmap(1);

    this->fragmentNumber = 0;
    this->startingSequenceNumber = 0;
    this->tidInfo = 0;
}

Ieee80211CompressedBlockAck::Ieee80211CompressedBlockAck(const Ieee80211CompressedBlockAck& other) : ::inet::ieee80211::Ieee80211BlockAck(other)
{
    copy(other);
}

Ieee80211CompressedBlockAck::~Ieee80211CompressedBlockAck()
{
}

Ieee80211CompressedBlockAck& Ieee80211CompressedBlockAck::operator=(const Ieee80211CompressedBlockAck& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211BlockAck::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211CompressedBlockAck::copy(const Ieee80211CompressedBlockAck& other)
{
    this->fragmentNumber = other.fragmentNumber;
    this->startingSequenceNumber = other.startingSequenceNumber;
    this->blockAckBitmap = other.blockAckBitmap;
    this->tidInfo = other.tidInfo;
}

void Ieee80211CompressedBlockAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimPack(b);
    doParsimPacking(b,this->fragmentNumber);
    doParsimPacking(b,this->startingSequenceNumber);
    doParsimPacking(b,this->blockAckBitmap);
    doParsimPacking(b,this->tidInfo);
}

void Ieee80211CompressedBlockAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimUnpack(b);
    doParsimUnpacking(b,this->fragmentNumber);
    doParsimUnpacking(b,this->startingSequenceNumber);
    doParsimUnpacking(b,this->blockAckBitmap);
    doParsimUnpacking(b,this->tidInfo);
}

int Ieee80211CompressedBlockAck::getFragmentNumber() const
{
    return this->fragmentNumber;
}

void Ieee80211CompressedBlockAck::setFragmentNumber(int fragmentNumber)
{
    this->fragmentNumber = fragmentNumber;
}

int Ieee80211CompressedBlockAck::getStartingSequenceNumber() const
{
    return this->startingSequenceNumber;
}

void Ieee80211CompressedBlockAck::setStartingSequenceNumber(int startingSequenceNumber)
{
    this->startingSequenceNumber = startingSequenceNumber;
}

BitVector& Ieee80211CompressedBlockAck::getBlockAckBitmap()
{
    return this->blockAckBitmap;
}

void Ieee80211CompressedBlockAck::setBlockAckBitmap(const BitVector& blockAckBitmap)
{
    this->blockAckBitmap = blockAckBitmap;
}

int Ieee80211CompressedBlockAck::getTidInfo() const
{
    return this->tidInfo;
}

void Ieee80211CompressedBlockAck::setTidInfo(int tidInfo)
{
    this->tidInfo = tidInfo;
}

class Ieee80211CompressedBlockAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211CompressedBlockAckDescriptor();
    virtual ~Ieee80211CompressedBlockAckDescriptor();

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

Register_ClassDescriptor(Ieee80211CompressedBlockAckDescriptor)

Ieee80211CompressedBlockAckDescriptor::Ieee80211CompressedBlockAckDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211CompressedBlockAck", "inet::ieee80211::Ieee80211BlockAck")
{
    propertynames = nullptr;
}

Ieee80211CompressedBlockAckDescriptor::~Ieee80211CompressedBlockAckDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CompressedBlockAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CompressedBlockAck *>(obj)!=nullptr;
}

const char **Ieee80211CompressedBlockAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CompressedBlockAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CompressedBlockAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211CompressedBlockAckDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211CompressedBlockAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "fragmentNumber",
        "startingSequenceNumber",
        "blockAckBitmap",
        "tidInfo",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int Ieee80211CompressedBlockAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fragmentNumber")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "startingSequenceNumber")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "blockAckBitmap")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "tidInfo")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CompressedBlockAckDescriptor::getFieldTypeString(int field) const
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
        "BitVector",
        "int",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211CompressedBlockAckDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211CompressedBlockAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211CompressedBlockAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211CompressedBlockAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211CompressedBlockAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getFragmentNumber());
        case 1: return long2string(pp->getStartingSequenceNumber());
        case 2: {std::stringstream out; out << pp->getBlockAckBitmap(); return out.str();}
        case 3: return long2string(pp->getTidInfo());
        default: return "";
    }
}

bool Ieee80211CompressedBlockAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        case 0: pp->setFragmentNumber(string2long(value)); return true;
        case 1: pp->setStartingSequenceNumber(string2long(value)); return true;
        case 3: pp->setTidInfo(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211CompressedBlockAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(BitVector));
        default: return nullptr;
    };
}

void *Ieee80211CompressedBlockAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CompressedBlockAck *pp = (Ieee80211CompressedBlockAck *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getBlockAckBitmap()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211MultiTidBlockAck)

Ieee80211MultiTidBlockAck::Ieee80211MultiTidBlockAck(const char *name, short kind) : ::inet::ieee80211::Ieee80211BlockAck(name,kind)
{
    this->setMultiTid(1);
    this->setCompressedBitmap(1);
}

Ieee80211MultiTidBlockAck::Ieee80211MultiTidBlockAck(const Ieee80211MultiTidBlockAck& other) : ::inet::ieee80211::Ieee80211BlockAck(other)
{
    copy(other);
}

Ieee80211MultiTidBlockAck::~Ieee80211MultiTidBlockAck()
{
}

Ieee80211MultiTidBlockAck& Ieee80211MultiTidBlockAck::operator=(const Ieee80211MultiTidBlockAck& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211BlockAck::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211MultiTidBlockAck::copy(const Ieee80211MultiTidBlockAck& other)
{
}

void Ieee80211MultiTidBlockAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimPack(b);
}

void Ieee80211MultiTidBlockAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BlockAck::parsimUnpack(b);
}

class Ieee80211MultiTidBlockAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211MultiTidBlockAckDescriptor();
    virtual ~Ieee80211MultiTidBlockAckDescriptor();

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

Register_ClassDescriptor(Ieee80211MultiTidBlockAckDescriptor)

Ieee80211MultiTidBlockAckDescriptor::Ieee80211MultiTidBlockAckDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211MultiTidBlockAck", "inet::ieee80211::Ieee80211BlockAck")
{
    propertynames = nullptr;
}

Ieee80211MultiTidBlockAckDescriptor::~Ieee80211MultiTidBlockAckDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211MultiTidBlockAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211MultiTidBlockAck *>(obj)!=nullptr;
}

const char **Ieee80211MultiTidBlockAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211MultiTidBlockAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211MultiTidBlockAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211MultiTidBlockAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211MultiTidBlockAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211MultiTidBlockAckDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211MultiTidBlockAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211MultiTidBlockAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211MultiTidBlockAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211MultiTidBlockAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211MultiTidBlockAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211MultiTidBlockAck *pp = (Ieee80211MultiTidBlockAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace ieee80211
} // namespace inet

