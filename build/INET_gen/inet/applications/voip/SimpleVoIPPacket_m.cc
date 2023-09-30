//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/applications/voip/SimpleVoIPPacket.msg.
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
#include "SimpleVoIPPacket_m.h"

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

Register_Class(SimpleVoIPPacket)

SimpleVoIPPacket::SimpleVoIPPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->talkspurtID = 0;
    this->talkspurtNumPackets = 0;
    this->packetID = 0;
    this->voipTimestamp = 0;
    this->voiceDuration = 0;
}

SimpleVoIPPacket::SimpleVoIPPacket(const SimpleVoIPPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

SimpleVoIPPacket::~SimpleVoIPPacket()
{
}

SimpleVoIPPacket& SimpleVoIPPacket::operator=(const SimpleVoIPPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void SimpleVoIPPacket::copy(const SimpleVoIPPacket& other)
{
    this->talkspurtID = other.talkspurtID;
    this->talkspurtNumPackets = other.talkspurtNumPackets;
    this->packetID = other.packetID;
    this->voipTimestamp = other.voipTimestamp;
    this->voiceDuration = other.voiceDuration;
}

void SimpleVoIPPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->talkspurtID);
    doParsimPacking(b,this->talkspurtNumPackets);
    doParsimPacking(b,this->packetID);
    doParsimPacking(b,this->voipTimestamp);
    doParsimPacking(b,this->voiceDuration);
}

void SimpleVoIPPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->talkspurtID);
    doParsimUnpacking(b,this->talkspurtNumPackets);
    doParsimUnpacking(b,this->packetID);
    doParsimUnpacking(b,this->voipTimestamp);
    doParsimUnpacking(b,this->voiceDuration);
}

unsigned int SimpleVoIPPacket::getTalkspurtID() const
{
    return this->talkspurtID;
}

void SimpleVoIPPacket::setTalkspurtID(unsigned int talkspurtID)
{
    this->talkspurtID = talkspurtID;
}

unsigned int SimpleVoIPPacket::getTalkspurtNumPackets() const
{
    return this->talkspurtNumPackets;
}

void SimpleVoIPPacket::setTalkspurtNumPackets(unsigned int talkspurtNumPackets)
{
    this->talkspurtNumPackets = talkspurtNumPackets;
}

unsigned int SimpleVoIPPacket::getPacketID() const
{
    return this->packetID;
}

void SimpleVoIPPacket::setPacketID(unsigned int packetID)
{
    this->packetID = packetID;
}

::omnetpp::simtime_t SimpleVoIPPacket::getVoipTimestamp() const
{
    return this->voipTimestamp;
}

void SimpleVoIPPacket::setVoipTimestamp(::omnetpp::simtime_t voipTimestamp)
{
    this->voipTimestamp = voipTimestamp;
}

::omnetpp::simtime_t SimpleVoIPPacket::getVoiceDuration() const
{
    return this->voiceDuration;
}

void SimpleVoIPPacket::setVoiceDuration(::omnetpp::simtime_t voiceDuration)
{
    this->voiceDuration = voiceDuration;
}

class SimpleVoIPPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SimpleVoIPPacketDescriptor();
    virtual ~SimpleVoIPPacketDescriptor();

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

Register_ClassDescriptor(SimpleVoIPPacketDescriptor)

SimpleVoIPPacketDescriptor::SimpleVoIPPacketDescriptor() : omnetpp::cClassDescriptor("inet::SimpleVoIPPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

SimpleVoIPPacketDescriptor::~SimpleVoIPPacketDescriptor()
{
    delete[] propertynames;
}

bool SimpleVoIPPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SimpleVoIPPacket *>(obj)!=nullptr;
}

const char **SimpleVoIPPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SimpleVoIPPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SimpleVoIPPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int SimpleVoIPPacketDescriptor::getFieldTypeFlags(int field) const
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

const char *SimpleVoIPPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "talkspurtID",
        "talkspurtNumPackets",
        "packetID",
        "voipTimestamp",
        "voiceDuration",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int SimpleVoIPPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "talkspurtID")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "talkspurtNumPackets")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "packetID")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "voipTimestamp")==0) return base+3;
    if (fieldName[0]=='v' && strcmp(fieldName, "voiceDuration")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SimpleVoIPPacketDescriptor::getFieldTypeString(int field) const
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
        "simtime_t",
        "simtime_t",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **SimpleVoIPPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *SimpleVoIPPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SimpleVoIPPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SimpleVoIPPacket *pp = (SimpleVoIPPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SimpleVoIPPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SimpleVoIPPacket *pp = (SimpleVoIPPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SimpleVoIPPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SimpleVoIPPacket *pp = (SimpleVoIPPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getTalkspurtID());
        case 1: return ulong2string(pp->getTalkspurtNumPackets());
        case 2: return ulong2string(pp->getPacketID());
        case 3: return simtime2string(pp->getVoipTimestamp());
        case 4: return simtime2string(pp->getVoiceDuration());
        default: return "";
    }
}

bool SimpleVoIPPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SimpleVoIPPacket *pp = (SimpleVoIPPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setTalkspurtID(string2ulong(value)); return true;
        case 1: pp->setTalkspurtNumPackets(string2ulong(value)); return true;
        case 2: pp->setPacketID(string2ulong(value)); return true;
        case 3: pp->setVoipTimestamp(string2simtime(value)); return true;
        case 4: pp->setVoiceDuration(string2simtime(value)); return true;
        default: return false;
    }
}

const char *SimpleVoIPPacketDescriptor::getFieldStructName(int field) const
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

void *SimpleVoIPPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SimpleVoIPPacket *pp = (SimpleVoIPPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace inet

