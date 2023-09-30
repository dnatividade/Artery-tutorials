//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/rtp/RTPPacket.msg.
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
#include "RTPPacket_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::rtp::RTPPacketEnums");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::rtp::RTPPacketEnums"));
    e->insert(RTPPACKET_FIX_HEADERLENGTH, "RTPPACKET_FIX_HEADERLENGTH");
)

RTPPacket_Base::RTPPacket_Base(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->setByteLength(RTPPACKET_FIX_HEADERLENGTH);

    this->version = 2;
    this->padding = false;
    this->extension = false;
    this->marker = false;
    this->payloadType = 0;
    this->sequenceNumber = 0;
    this->timeStamp = 0;
    this->ssrc = 0;
    csrc_arraysize = 0;
    this->csrc = 0;
}

RTPPacket_Base::RTPPacket_Base(const RTPPacket_Base& other) : ::omnetpp::cPacket(other)
{
    csrc_arraysize = 0;
    this->csrc = 0;
    copy(other);
}

RTPPacket_Base::~RTPPacket_Base()
{
    delete [] this->csrc;
}

RTPPacket_Base& RTPPacket_Base::operator=(const RTPPacket_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void RTPPacket_Base::copy(const RTPPacket_Base& other)
{
    this->version = other.version;
    this->padding = other.padding;
    this->extension = other.extension;
    this->marker = other.marker;
    this->payloadType = other.payloadType;
    this->sequenceNumber = other.sequenceNumber;
    this->timeStamp = other.timeStamp;
    this->ssrc = other.ssrc;
    delete [] this->csrc;
    this->csrc = (other.csrc_arraysize==0) ? nullptr : new uint32_t[other.csrc_arraysize];
    csrc_arraysize = other.csrc_arraysize;
    for (unsigned int i=0; i<csrc_arraysize; i++)
        this->csrc[i] = other.csrc[i];
}

void RTPPacket_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->padding);
    doParsimPacking(b,this->extension);
    doParsimPacking(b,this->marker);
    doParsimPacking(b,this->payloadType);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->timeStamp);
    doParsimPacking(b,this->ssrc);
    b->pack(csrc_arraysize);
    doParsimArrayPacking(b,this->csrc,csrc_arraysize);
    // field headerLength is abstract -- please do packing in customized class
    // field payloadLength is abstract -- please do packing in customized class
}

void RTPPacket_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->padding);
    doParsimUnpacking(b,this->extension);
    doParsimUnpacking(b,this->marker);
    doParsimUnpacking(b,this->payloadType);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->timeStamp);
    doParsimUnpacking(b,this->ssrc);
    delete [] this->csrc;
    b->unpack(csrc_arraysize);
    if (csrc_arraysize==0) {
        this->csrc = 0;
    } else {
        this->csrc = new uint32_t[csrc_arraysize];
        doParsimArrayUnpacking(b,this->csrc,csrc_arraysize);
    }
    // field headerLength is abstract -- please do unpacking in customized class
    // field payloadLength is abstract -- please do unpacking in customized class
}

uint8_t RTPPacket_Base::getVersion() const
{
    return this->version;
}

void RTPPacket_Base::setVersion(uint8_t version)
{
    this->version = version;
}

bool RTPPacket_Base::getPadding() const
{
    return this->padding;
}

void RTPPacket_Base::setPadding(bool padding)
{
    this->padding = padding;
}

bool RTPPacket_Base::getExtension() const
{
    return this->extension;
}

void RTPPacket_Base::setExtension(bool extension)
{
    this->extension = extension;
}

bool RTPPacket_Base::getMarker() const
{
    return this->marker;
}

void RTPPacket_Base::setMarker(bool marker)
{
    this->marker = marker;
}

int8_t RTPPacket_Base::getPayloadType() const
{
    return this->payloadType;
}

void RTPPacket_Base::setPayloadType(int8_t payloadType)
{
    this->payloadType = payloadType;
}

uint16_t RTPPacket_Base::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void RTPPacket_Base::setSequenceNumber(uint16_t sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

uint32_t RTPPacket_Base::getTimeStamp() const
{
    return this->timeStamp;
}

void RTPPacket_Base::setTimeStamp(uint32_t timeStamp)
{
    this->timeStamp = timeStamp;
}

uint32_t RTPPacket_Base::getSsrc() const
{
    return this->ssrc;
}

void RTPPacket_Base::setSsrc(uint32_t ssrc)
{
    this->ssrc = ssrc;
}

void RTPPacket_Base::setCsrcArraySize(unsigned int size)
{
    uint32_t *csrc2 = (size==0) ? nullptr : new uint32_t[size];
    unsigned int sz = csrc_arraysize < size ? csrc_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        csrc2[i] = this->csrc[i];
    for (unsigned int i=sz; i<size; i++)
        csrc2[i] = 0;
    csrc_arraysize = size;
    delete [] this->csrc;
    this->csrc = csrc2;
}

unsigned int RTPPacket_Base::getCsrcArraySize() const
{
    return csrc_arraysize;
}

uint32_t RTPPacket_Base::getCsrc(unsigned int k) const
{
    if (k>=csrc_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", csrc_arraysize, k);
    return this->csrc[k];
}

void RTPPacket_Base::setCsrc(unsigned int k, uint32_t csrc)
{
    if (k>=csrc_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", csrc_arraysize, k);
    this->csrc[k] = csrc;
}

class RTPPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    RTPPacketDescriptor();
    virtual ~RTPPacketDescriptor();

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

Register_ClassDescriptor(RTPPacketDescriptor)

RTPPacketDescriptor::RTPPacketDescriptor() : omnetpp::cClassDescriptor("inet::rtp::RTPPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

RTPPacketDescriptor::~RTPPacketDescriptor()
{
    delete[] propertynames;
}

bool RTPPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<RTPPacket_Base *>(obj)!=nullptr;
}

const char **RTPPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *RTPPacketDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int RTPPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 11+basedesc->getFieldCount() : 11;
}

unsigned int RTPPacketDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<11) ? fieldTypeFlags[field] : 0;
}

const char *RTPPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "padding",
        "extension",
        "marker",
        "payloadType",
        "sequenceNumber",
        "timeStamp",
        "ssrc",
        "csrc",
        "headerLength",
        "payloadLength",
    };
    return (field>=0 && field<11) ? fieldNames[field] : nullptr;
}

int RTPPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='p' && strcmp(fieldName, "padding")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "extension")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "marker")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadType")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "timeStamp")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssrc")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "csrc")==0) return base+8;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+9;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLength")==0) return base+10;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *RTPPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8",
        "bool",
        "bool",
        "bool",
        "int8",
        "uint16",
        "uint32",
        "uint32",
        "uint32",
        "int",
        "int",
    };
    return (field>=0 && field<11) ? fieldTypeStrings[field] : nullptr;
}

const char **RTPPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *RTPPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int RTPPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    RTPPacket_Base *pp = (RTPPacket_Base *)object; (void)pp;
    switch (field) {
        case 8: return pp->getCsrcArraySize();
        default: return 0;
    }
}

const char *RTPPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPPacket_Base *pp = (RTPPacket_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string RTPPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    RTPPacket_Base *pp = (RTPPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getVersion());
        case 1: return bool2string(pp->getPadding());
        case 2: return bool2string(pp->getExtension());
        case 3: return bool2string(pp->getMarker());
        case 4: return long2string(pp->getPayloadType());
        case 5: return ulong2string(pp->getSequenceNumber());
        case 6: return ulong2string(pp->getTimeStamp());
        case 7: return ulong2string(pp->getSsrc());
        case 8: return ulong2string(pp->getCsrc(i));
        case 9: return long2string(pp->getHeaderLength());
        case 10: return long2string(pp->getPayloadLength());
        default: return "";
    }
}

bool RTPPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    RTPPacket_Base *pp = (RTPPacket_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2ulong(value)); return true;
        case 1: pp->setPadding(string2bool(value)); return true;
        case 2: pp->setExtension(string2bool(value)); return true;
        case 3: pp->setMarker(string2bool(value)); return true;
        case 4: pp->setPayloadType(string2long(value)); return true;
        case 5: pp->setSequenceNumber(string2ulong(value)); return true;
        case 6: pp->setTimeStamp(string2ulong(value)); return true;
        case 7: pp->setSsrc(string2ulong(value)); return true;
        case 8: pp->setCsrc(i,string2ulong(value)); return true;
        case 9: pp->setHeaderLength(string2long(value)); return true;
        case 10: pp->setPayloadLength(string2long(value)); return true;
        default: return false;
    }
}

const char *RTPPacketDescriptor::getFieldStructName(int field) const
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

void *RTPPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    RTPPacket_Base *pp = (RTPPacket_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

} // namespace rtp
} // namespace inet

