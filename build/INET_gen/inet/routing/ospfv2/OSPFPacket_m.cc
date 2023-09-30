//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/routing/ospfv2/OSPFPacket.msg.
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
#include "OSPFPacket_m.h"

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
namespace ospf {

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospf::OSPFPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospf::OSPFPacketType"));
    e->insert(HELLO_PACKET, "HELLO_PACKET");
    e->insert(DATABASE_DESCRIPTION_PACKET, "DATABASE_DESCRIPTION_PACKET");
    e->insert(LINKSTATE_REQUEST_PACKET, "LINKSTATE_REQUEST_PACKET");
    e->insert(LINKSTATE_UPDATE_PACKET, "LINKSTATE_UPDATE_PACKET");
    e->insert(LINKSTATE_ACKNOWLEDGEMENT_PACKET, "LINKSTATE_ACKNOWLEDGEMENT_PACKET");
)

OSPFOptions::OSPFOptions()
{
    this->unused_1 = false;
    this->E_ExternalRoutingCapability = false;
    this->MC_MulticastForwarding = false;
    this->NP_Type7LSA = false;
    this->EA_ForwardExternalLSAs = false;
    this->DC_DemandCircuits = false;
    this->unused_2 = false;
    this->unused_3 = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const OSPFOptions& a)
{
    doParsimPacking(b,a.unused_1);
    doParsimPacking(b,a.E_ExternalRoutingCapability);
    doParsimPacking(b,a.MC_MulticastForwarding);
    doParsimPacking(b,a.NP_Type7LSA);
    doParsimPacking(b,a.EA_ForwardExternalLSAs);
    doParsimPacking(b,a.DC_DemandCircuits);
    doParsimPacking(b,a.unused_2);
    doParsimPacking(b,a.unused_3);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OSPFOptions& a)
{
    doParsimUnpacking(b,a.unused_1);
    doParsimUnpacking(b,a.E_ExternalRoutingCapability);
    doParsimUnpacking(b,a.MC_MulticastForwarding);
    doParsimUnpacking(b,a.NP_Type7LSA);
    doParsimUnpacking(b,a.EA_ForwardExternalLSAs);
    doParsimUnpacking(b,a.DC_DemandCircuits);
    doParsimUnpacking(b,a.unused_2);
    doParsimUnpacking(b,a.unused_3);
}

class OSPFOptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFOptionsDescriptor();
    virtual ~OSPFOptionsDescriptor();

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

Register_ClassDescriptor(OSPFOptionsDescriptor)

OSPFOptionsDescriptor::OSPFOptionsDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFOptions", "")
{
    propertynames = nullptr;
}

OSPFOptionsDescriptor::~OSPFOptionsDescriptor()
{
    delete[] propertynames;
}

bool OSPFOptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFOptions *>(obj)!=nullptr;
}

const char **OSPFOptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFOptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFOptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OSPFOptionsDescriptor::getFieldTypeFlags(int field) const
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

const char *OSPFOptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "unused_1",
        "E_ExternalRoutingCapability",
        "MC_MulticastForwarding",
        "NP_Type7LSA",
        "EA_ForwardExternalLSAs",
        "DC_DemandCircuits",
        "unused_2",
        "unused_3",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int OSPFOptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='u' && strcmp(fieldName, "unused_1")==0) return base+0;
    if (fieldName[0]=='E' && strcmp(fieldName, "E_ExternalRoutingCapability")==0) return base+1;
    if (fieldName[0]=='M' && strcmp(fieldName, "MC_MulticastForwarding")==0) return base+2;
    if (fieldName[0]=='N' && strcmp(fieldName, "NP_Type7LSA")==0) return base+3;
    if (fieldName[0]=='E' && strcmp(fieldName, "EA_ForwardExternalLSAs")==0) return base+4;
    if (fieldName[0]=='D' && strcmp(fieldName, "DC_DemandCircuits")==0) return base+5;
    if (fieldName[0]=='u' && strcmp(fieldName, "unused_2")==0) return base+6;
    if (fieldName[0]=='u' && strcmp(fieldName, "unused_3")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFOptionsDescriptor::getFieldTypeString(int field) const
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
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFOptionsDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFOptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFOptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFOptions *pp = (OSPFOptions *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OSPFOptionsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFOptions *pp = (OSPFOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFOptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFOptions *pp = (OSPFOptions *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->unused_1);
        case 1: return bool2string(pp->E_ExternalRoutingCapability);
        case 2: return bool2string(pp->MC_MulticastForwarding);
        case 3: return bool2string(pp->NP_Type7LSA);
        case 4: return bool2string(pp->EA_ForwardExternalLSAs);
        case 5: return bool2string(pp->DC_DemandCircuits);
        case 6: return bool2string(pp->unused_2);
        case 7: return bool2string(pp->unused_3);
        default: return "";
    }
}

bool OSPFOptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFOptions *pp = (OSPFOptions *)object; (void)pp;
    switch (field) {
        case 0: pp->unused_1 = string2bool(value); return true;
        case 1: pp->E_ExternalRoutingCapability = string2bool(value); return true;
        case 2: pp->MC_MulticastForwarding = string2bool(value); return true;
        case 3: pp->NP_Type7LSA = string2bool(value); return true;
        case 4: pp->EA_ForwardExternalLSAs = string2bool(value); return true;
        case 5: pp->DC_DemandCircuits = string2bool(value); return true;
        case 6: pp->unused_2 = string2bool(value); return true;
        case 7: pp->unused_3 = string2bool(value); return true;
        default: return false;
    }
}

const char *OSPFOptionsDescriptor::getFieldStructName(int field) const
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

void *OSPFOptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFOptions *pp = (OSPFOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(OSPFPacket)

OSPFPacket::OSPFPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->version = 2;
    this->type = HELLO_PACKET;
    this->authenticationType = 0;
    for (unsigned int i=0; i<8; i++)
        this->authentication[i] = 0;
}

OSPFPacket::OSPFPacket(const OSPFPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

OSPFPacket::~OSPFPacket()
{
}

OSPFPacket& OSPFPacket::operator=(const OSPFPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void OSPFPacket::copy(const OSPFPacket& other)
{
    this->version = other.version;
    this->type = other.type;
    this->routerID = other.routerID;
    this->areaID = other.areaID;
    this->authenticationType = other.authenticationType;
    for (unsigned int i=0; i<8; i++)
        this->authentication[i] = other.authentication[i];
}

void OSPFPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->routerID);
    doParsimPacking(b,this->areaID);
    doParsimPacking(b,this->authenticationType);
    doParsimArrayPacking(b,this->authentication,8);
}

void OSPFPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->routerID);
    doParsimUnpacking(b,this->areaID);
    doParsimUnpacking(b,this->authenticationType);
    doParsimArrayUnpacking(b,this->authentication,8);
}

char OSPFPacket::getVersion() const
{
    return this->version;
}

void OSPFPacket::setVersion(char version)
{
    this->version = version;
}

char OSPFPacket::getType() const
{
    return this->type;
}

void OSPFPacket::setType(char type)
{
    this->type = type;
}

IPv4Address& OSPFPacket::getRouterID()
{
    return this->routerID;
}

void OSPFPacket::setRouterID(const IPv4Address& routerID)
{
    this->routerID = routerID;
}

IPv4Address& OSPFPacket::getAreaID()
{
    return this->areaID;
}

void OSPFPacket::setAreaID(const IPv4Address& areaID)
{
    this->areaID = areaID;
}

short OSPFPacket::getAuthenticationType() const
{
    return this->authenticationType;
}

void OSPFPacket::setAuthenticationType(short authenticationType)
{
    this->authenticationType = authenticationType;
}

unsigned int OSPFPacket::getAuthenticationArraySize() const
{
    return 8;
}

char OSPFPacket::getAuthentication(unsigned int k) const
{
    if (k>=8) throw omnetpp::cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    return this->authentication[k];
}

void OSPFPacket::setAuthentication(unsigned int k, char authentication)
{
    if (k>=8) throw omnetpp::cRuntimeError("Array of size 8 indexed by %lu", (unsigned long)k);
    this->authentication[k] = authentication;
}

class OSPFPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFPacketDescriptor();
    virtual ~OSPFPacketDescriptor();

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

Register_ClassDescriptor(OSPFPacketDescriptor)

OSPFPacketDescriptor::OSPFPacketDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

OSPFPacketDescriptor::~OSPFPacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFPacket *>(obj)!=nullptr;
}

const char **OSPFPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int OSPFPacketDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *OSPFPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "version",
        "type",
        "routerID",
        "areaID",
        "authenticationType",
        "authentication",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int OSPFPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerID")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "areaID")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "authenticationType")==0) return base+4;
    if (fieldName[0]=='a' && strcmp(fieldName, "authentication")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "char",
        "char",
        "IPv4Address",
        "IPv4Address",
        "short",
        "char",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *OSPFPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "inet::ospf::OSPFPacketType";
            return nullptr;
        default: return nullptr;
    }
}

int OSPFPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFPacket *pp = (OSPFPacket *)object; (void)pp;
    switch (field) {
        case 5: return 8;
        default: return 0;
    }
}

const char *OSPFPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFPacket *pp = (OSPFPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFPacket *pp = (OSPFPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVersion());
        case 1: return enum2string(pp->getType(), "inet::ospf::OSPFPacketType");
        case 2: {std::stringstream out; out << pp->getRouterID(); return out.str();}
        case 3: {std::stringstream out; out << pp->getAreaID(); return out.str();}
        case 4: return long2string(pp->getAuthenticationType());
        case 5: return long2string(pp->getAuthentication(i));
        default: return "";
    }
}

bool OSPFPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFPacket *pp = (OSPFPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2long(value)); return true;
        case 1: pp->setType((inet::ospf::OSPFPacketType)string2enum(value, "inet::ospf::OSPFPacketType")); return true;
        case 4: pp->setAuthenticationType(string2long(value)); return true;
        case 5: pp->setAuthentication(i,string2long(value)); return true;
        default: return false;
    }
}

const char *OSPFPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFPacket *pp = (OSPFPacket *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getRouterID()); break;
        case 3: return (void *)(&pp->getAreaID()); break;
        default: return nullptr;
    }
}

Register_Class(OSPFHelloPacket)

OSPFHelloPacket::OSPFHelloPacket(const char *name, short kind) : ::inet::ospf::OSPFPacket(name,kind)
{
    this->helloInterval = 5;
    this->routerPriority = 0;
    this->routerDeadInterval = 0;
    neighbor_arraysize = 0;
    this->neighbor = 0;
}

OSPFHelloPacket::OSPFHelloPacket(const OSPFHelloPacket& other) : ::inet::ospf::OSPFPacket(other)
{
    neighbor_arraysize = 0;
    this->neighbor = 0;
    copy(other);
}

OSPFHelloPacket::~OSPFHelloPacket()
{
    delete [] this->neighbor;
}

OSPFHelloPacket& OSPFHelloPacket::operator=(const OSPFHelloPacket& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFPacket::operator=(other);
    copy(other);
    return *this;
}

void OSPFHelloPacket::copy(const OSPFHelloPacket& other)
{
    this->networkMask = other.networkMask;
    this->helloInterval = other.helloInterval;
    this->options = other.options;
    this->routerPriority = other.routerPriority;
    this->routerDeadInterval = other.routerDeadInterval;
    this->designatedRouter = other.designatedRouter;
    this->backupDesignatedRouter = other.backupDesignatedRouter;
    delete [] this->neighbor;
    this->neighbor = (other.neighbor_arraysize==0) ? nullptr : new IPv4Address[other.neighbor_arraysize];
    neighbor_arraysize = other.neighbor_arraysize;
    for (unsigned int i=0; i<neighbor_arraysize; i++)
        this->neighbor[i] = other.neighbor[i];
}

void OSPFHelloPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFPacket::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    doParsimPacking(b,this->helloInterval);
    doParsimPacking(b,this->options);
    doParsimPacking(b,this->routerPriority);
    doParsimPacking(b,this->routerDeadInterval);
    doParsimPacking(b,this->designatedRouter);
    doParsimPacking(b,this->backupDesignatedRouter);
    b->pack(neighbor_arraysize);
    doParsimArrayPacking(b,this->neighbor,neighbor_arraysize);
}

void OSPFHelloPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    doParsimUnpacking(b,this->helloInterval);
    doParsimUnpacking(b,this->options);
    doParsimUnpacking(b,this->routerPriority);
    doParsimUnpacking(b,this->routerDeadInterval);
    doParsimUnpacking(b,this->designatedRouter);
    doParsimUnpacking(b,this->backupDesignatedRouter);
    delete [] this->neighbor;
    b->unpack(neighbor_arraysize);
    if (neighbor_arraysize==0) {
        this->neighbor = 0;
    } else {
        this->neighbor = new IPv4Address[neighbor_arraysize];
        doParsimArrayUnpacking(b,this->neighbor,neighbor_arraysize);
    }
}

IPv4Address& OSPFHelloPacket::getNetworkMask()
{
    return this->networkMask;
}

void OSPFHelloPacket::setNetworkMask(const IPv4Address& networkMask)
{
    this->networkMask = networkMask;
}

short OSPFHelloPacket::getHelloInterval() const
{
    return this->helloInterval;
}

void OSPFHelloPacket::setHelloInterval(short helloInterval)
{
    this->helloInterval = helloInterval;
}

OSPFOptions& OSPFHelloPacket::getOptions()
{
    return this->options;
}

void OSPFHelloPacket::setOptions(const OSPFOptions& options)
{
    this->options = options;
}

char OSPFHelloPacket::getRouterPriority() const
{
    return this->routerPriority;
}

void OSPFHelloPacket::setRouterPriority(char routerPriority)
{
    this->routerPriority = routerPriority;
}

long OSPFHelloPacket::getRouterDeadInterval() const
{
    return this->routerDeadInterval;
}

void OSPFHelloPacket::setRouterDeadInterval(long routerDeadInterval)
{
    this->routerDeadInterval = routerDeadInterval;
}

IPv4Address& OSPFHelloPacket::getDesignatedRouter()
{
    return this->designatedRouter;
}

void OSPFHelloPacket::setDesignatedRouter(const IPv4Address& designatedRouter)
{
    this->designatedRouter = designatedRouter;
}

IPv4Address& OSPFHelloPacket::getBackupDesignatedRouter()
{
    return this->backupDesignatedRouter;
}

void OSPFHelloPacket::setBackupDesignatedRouter(const IPv4Address& backupDesignatedRouter)
{
    this->backupDesignatedRouter = backupDesignatedRouter;
}

void OSPFHelloPacket::setNeighborArraySize(unsigned int size)
{
    IPv4Address *neighbor2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = neighbor_arraysize < size ? neighbor_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        neighbor2[i] = this->neighbor[i];
    neighbor_arraysize = size;
    delete [] this->neighbor;
    this->neighbor = neighbor2;
}

unsigned int OSPFHelloPacket::getNeighborArraySize() const
{
    return neighbor_arraysize;
}

IPv4Address& OSPFHelloPacket::getNeighbor(unsigned int k)
{
    if (k>=neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", neighbor_arraysize, k);
    return this->neighbor[k];
}

void OSPFHelloPacket::setNeighbor(unsigned int k, const IPv4Address& neighbor)
{
    if (k>=neighbor_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", neighbor_arraysize, k);
    this->neighbor[k] = neighbor;
}

class OSPFHelloPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFHelloPacketDescriptor();
    virtual ~OSPFHelloPacketDescriptor();

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

Register_ClassDescriptor(OSPFHelloPacketDescriptor)

OSPFHelloPacketDescriptor::OSPFHelloPacketDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFHelloPacket", "inet::ospf::OSPFPacket")
{
    propertynames = nullptr;
}

OSPFHelloPacketDescriptor::~OSPFHelloPacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFHelloPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFHelloPacket *>(obj)!=nullptr;
}

const char **OSPFHelloPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFHelloPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFHelloPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OSPFHelloPacketDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<8) ? fieldTypeFlags[field] : 0;
}

const char *OSPFHelloPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "helloInterval",
        "options",
        "routerPriority",
        "routerDeadInterval",
        "designatedRouter",
        "backupDesignatedRouter",
        "neighbor",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int OSPFHelloPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "networkMask")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "helloInterval")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+2;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerPriority")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerDeadInterval")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "designatedRouter")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "backupDesignatedRouter")==0) return base+6;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighbor")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFHelloPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "short",
        "OSPFOptions",
        "char",
        "long",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFHelloPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFHelloPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFHelloPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFHelloPacket *pp = (OSPFHelloPacket *)object; (void)pp;
    switch (field) {
        case 7: return pp->getNeighborArraySize();
        default: return 0;
    }
}

const char *OSPFHelloPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFHelloPacket *pp = (OSPFHelloPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFHelloPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFHelloPacket *pp = (OSPFHelloPacket *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getNetworkMask(); return out.str();}
        case 1: return long2string(pp->getHelloInterval());
        case 2: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 3: return long2string(pp->getRouterPriority());
        case 4: return long2string(pp->getRouterDeadInterval());
        case 5: {std::stringstream out; out << pp->getDesignatedRouter(); return out.str();}
        case 6: {std::stringstream out; out << pp->getBackupDesignatedRouter(); return out.str();}
        case 7: {std::stringstream out; out << pp->getNeighbor(i); return out.str();}
        default: return "";
    }
}

bool OSPFHelloPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFHelloPacket *pp = (OSPFHelloPacket *)object; (void)pp;
    switch (field) {
        case 1: pp->setHelloInterval(string2long(value)); return true;
        case 3: pp->setRouterPriority(string2long(value)); return true;
        case 4: pp->setRouterDeadInterval(string2long(value)); return true;
        default: return false;
    }
}

const char *OSPFHelloPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(OSPFOptions));
        case 5: return omnetpp::opp_typename(typeid(IPv4Address));
        case 6: return omnetpp::opp_typename(typeid(IPv4Address));
        case 7: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFHelloPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFHelloPacket *pp = (OSPFHelloPacket *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getNetworkMask()); break;
        case 2: return (void *)(&pp->getOptions()); break;
        case 5: return (void *)(&pp->getDesignatedRouter()); break;
        case 6: return (void *)(&pp->getBackupDesignatedRouter()); break;
        case 7: return (void *)(&pp->getNeighbor(i)); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospf::LSAType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospf::LSAType"));
    e->insert(ROUTERLSA_TYPE, "ROUTERLSA_TYPE");
    e->insert(NETWORKLSA_TYPE, "NETWORKLSA_TYPE");
    e->insert(SUMMARYLSA_NETWORKS_TYPE, "SUMMARYLSA_NETWORKS_TYPE");
    e->insert(SUMMARYLSA_ASBOUNDARYROUTERS_TYPE, "SUMMARYLSA_ASBOUNDARYROUTERS_TYPE");
    e->insert(AS_EXTERNAL_LSA_TYPE, "AS_EXTERNAL_LSA_TYPE");
)

Register_Class(OSPFLSAHeader)

OSPFLSAHeader::OSPFLSAHeader() : ::omnetpp::cObject()
{
    this->lsAge = 0;
    this->lsType = ROUTERLSA_TYPE;
    this->lsSequenceNumber = 0;
    this->lsaLength = 0;
}

OSPFLSAHeader::OSPFLSAHeader(const OSPFLSAHeader& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OSPFLSAHeader::~OSPFLSAHeader()
{
}

OSPFLSAHeader& OSPFLSAHeader::operator=(const OSPFLSAHeader& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OSPFLSAHeader::copy(const OSPFLSAHeader& other)
{
    this->lsAge = other.lsAge;
    this->lsOptions = other.lsOptions;
    this->lsType = other.lsType;
    this->linkStateID = other.linkStateID;
    this->advertisingRouter = other.advertisingRouter;
    this->lsSequenceNumber = other.lsSequenceNumber;
    this->lsaLength = other.lsaLength;
}

void OSPFLSAHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->lsAge);
    doParsimPacking(b,this->lsOptions);
    doParsimPacking(b,this->lsType);
    doParsimPacking(b,this->linkStateID);
    doParsimPacking(b,this->advertisingRouter);
    doParsimPacking(b,this->lsSequenceNumber);
    doParsimPacking(b,this->lsaLength);
}

void OSPFLSAHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->lsAge);
    doParsimUnpacking(b,this->lsOptions);
    doParsimUnpacking(b,this->lsType);
    doParsimUnpacking(b,this->linkStateID);
    doParsimUnpacking(b,this->advertisingRouter);
    doParsimUnpacking(b,this->lsSequenceNumber);
    doParsimUnpacking(b,this->lsaLength);
}

unsigned short OSPFLSAHeader::getLsAge() const
{
    return this->lsAge;
}

void OSPFLSAHeader::setLsAge(unsigned short lsAge)
{
    this->lsAge = lsAge;
}

OSPFOptions& OSPFLSAHeader::getLsOptions()
{
    return this->lsOptions;
}

void OSPFLSAHeader::setLsOptions(const OSPFOptions& lsOptions)
{
    this->lsOptions = lsOptions;
}

char OSPFLSAHeader::getLsType() const
{
    return this->lsType;
}

void OSPFLSAHeader::setLsType(char lsType)
{
    this->lsType = lsType;
}

IPv4Address& OSPFLSAHeader::getLinkStateID()
{
    return this->linkStateID;
}

void OSPFLSAHeader::setLinkStateID(const IPv4Address& linkStateID)
{
    this->linkStateID = linkStateID;
}

IPv4Address& OSPFLSAHeader::getAdvertisingRouter()
{
    return this->advertisingRouter;
}

void OSPFLSAHeader::setAdvertisingRouter(const IPv4Address& advertisingRouter)
{
    this->advertisingRouter = advertisingRouter;
}

long OSPFLSAHeader::getLsSequenceNumber() const
{
    return this->lsSequenceNumber;
}

void OSPFLSAHeader::setLsSequenceNumber(long lsSequenceNumber)
{
    this->lsSequenceNumber = lsSequenceNumber;
}

unsigned short OSPFLSAHeader::getLsaLength() const
{
    return this->lsaLength;
}

void OSPFLSAHeader::setLsaLength(unsigned short lsaLength)
{
    this->lsaLength = lsaLength;
}

class OSPFLSAHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFLSAHeaderDescriptor();
    virtual ~OSPFLSAHeaderDescriptor();

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

Register_ClassDescriptor(OSPFLSAHeaderDescriptor)

OSPFLSAHeaderDescriptor::OSPFLSAHeaderDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFLSAHeader", "omnetpp::cObject")
{
    propertynames = nullptr;
}

OSPFLSAHeaderDescriptor::~OSPFLSAHeaderDescriptor()
{
    delete[] propertynames;
}

bool OSPFLSAHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFLSAHeader *>(obj)!=nullptr;
}

const char **OSPFLSAHeaderDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFLSAHeaderDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFLSAHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int OSPFLSAHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *OSPFLSAHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsAge",
        "lsOptions",
        "lsType",
        "linkStateID",
        "advertisingRouter",
        "lsSequenceNumber",
        "lsaLength",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int OSPFLSAHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsAge")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsOptions")==0) return base+1;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsType")==0) return base+2;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkStateID")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "advertisingRouter")==0) return base+4;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsSequenceNumber")==0) return base+5;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaLength")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFLSAHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "OSPFOptions",
        "char",
        "IPv4Address",
        "IPv4Address",
        "long",
        "unsigned short",
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFLSAHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFLSAHeaderDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "inet::ospf::LSAType";
            return nullptr;
        default: return nullptr;
    }
}

int OSPFLSAHeaderDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFLSAHeader *pp = (OSPFLSAHeader *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OSPFLSAHeaderDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLSAHeader *pp = (OSPFLSAHeader *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFLSAHeaderDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLSAHeader *pp = (OSPFLSAHeader *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getLsAge());
        case 1: {std::stringstream out; out << pp->getLsOptions(); return out.str();}
        case 2: return enum2string(pp->getLsType(), "inet::ospf::LSAType");
        case 3: {std::stringstream out; out << pp->getLinkStateID(); return out.str();}
        case 4: {std::stringstream out; out << pp->getAdvertisingRouter(); return out.str();}
        case 5: return long2string(pp->getLsSequenceNumber());
        case 6: return ulong2string(pp->getLsaLength());
        default: return "";
    }
}

bool OSPFLSAHeaderDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFLSAHeader *pp = (OSPFLSAHeader *)object; (void)pp;
    switch (field) {
        case 0: pp->setLsAge(string2ulong(value)); return true;
        case 2: pp->setLsType((inet::ospf::LSAType)string2enum(value, "inet::ospf::LSAType")); return true;
        case 5: pp->setLsSequenceNumber(string2long(value)); return true;
        case 6: pp->setLsaLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFLSAHeaderDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(OSPFOptions));
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        case 4: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *OSPFLSAHeaderDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFLSAHeader *pp = (OSPFLSAHeader *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getLsOptions()); break;
        case 3: return (void *)(&pp->getLinkStateID()); break;
        case 4: return (void *)(&pp->getAdvertisingRouter()); break;
        default: return nullptr;
    }
}

Register_Class(OSPFLSA)

OSPFLSA::OSPFLSA() : ::omnetpp::cObject()
{
}

OSPFLSA::OSPFLSA(const OSPFLSA& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

OSPFLSA::~OSPFLSA()
{
}

OSPFLSA& OSPFLSA::operator=(const OSPFLSA& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OSPFLSA::copy(const OSPFLSA& other)
{
    this->header = other.header;
}

void OSPFLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->header);
}

void OSPFLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->header);
}

OSPFLSAHeader& OSPFLSA::getHeader()
{
    return this->header;
}

void OSPFLSA::setHeader(const OSPFLSAHeader& header)
{
    this->header = header;
}

class OSPFLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFLSADescriptor();
    virtual ~OSPFLSADescriptor();

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

Register_ClassDescriptor(OSPFLSADescriptor)

OSPFLSADescriptor::OSPFLSADescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFLSA", "omnetpp::cObject")
{
    propertynames = nullptr;
}

OSPFLSADescriptor::~OSPFLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFLSA *>(obj)!=nullptr;
}

const char **OSPFLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OSPFLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "header",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int OSPFLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "header")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "OSPFLSAHeader",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFLSADescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFLSADescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFLSA *pp = (OSPFLSA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OSPFLSADescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLSA *pp = (OSPFLSA *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLSA *pp = (OSPFLSA *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getHeader(); return out.str();}
        default: return "";
    }
}

bool OSPFLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFLSA *pp = (OSPFLSA *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OSPFLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(OSPFLSAHeader));
        default: return nullptr;
    };
}

void *OSPFLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFLSA *pp = (OSPFLSA *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getHeader()); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ospf::LinkType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ospf::LinkType"));
    e->insert(POINTTOPOINT_LINK, "POINTTOPOINT_LINK");
    e->insert(TRANSIT_LINK, "TRANSIT_LINK");
    e->insert(STUB_LINK, "STUB_LINK");
    e->insert(VIRTUAL_LINK, "VIRTUAL_LINK");
)

TOSData::TOSData()
{
    this->tos = 0;
    for (unsigned int i=0; i<3; i++)
        this->tosMetric[i] = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const TOSData& a)
{
    doParsimPacking(b,a.tos);
    doParsimArrayPacking(b,a.tosMetric,3);
}

void __doUnpacking(omnetpp::cCommBuffer *b, TOSData& a)
{
    doParsimUnpacking(b,a.tos);
    doParsimArrayUnpacking(b,a.tosMetric,3);
}

class TOSDataDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TOSDataDescriptor();
    virtual ~TOSDataDescriptor();

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

Register_ClassDescriptor(TOSDataDescriptor)

TOSDataDescriptor::TOSDataDescriptor() : omnetpp::cClassDescriptor("inet::ospf::TOSData", "")
{
    propertynames = nullptr;
}

TOSDataDescriptor::~TOSDataDescriptor()
{
    delete[] propertynames;
}

bool TOSDataDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TOSData *>(obj)!=nullptr;
}

const char **TOSDataDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TOSDataDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TOSDataDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TOSDataDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *TOSDataDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tos",
        "tosMetric",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int TOSDataDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tos")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tosMetric")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TOSDataDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned char",
        "unsigned char",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **TOSDataDescriptor::getFieldPropertyNames(int field) const
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

const char *TOSDataDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TOSDataDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TOSData *pp = (TOSData *)object; (void)pp;
    switch (field) {
        case 1: return 3;
        default: return 0;
    }
}

const char *TOSDataDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TOSData *pp = (TOSData *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TOSDataDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TOSData *pp = (TOSData *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->tos);
        case 1: if (i>=3) return "";
                return ulong2string(pp->tosMetric[i]);
        default: return "";
    }
}

bool TOSDataDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TOSData *pp = (TOSData *)object; (void)pp;
    switch (field) {
        case 0: pp->tos = string2ulong(value); return true;
        case 1: if (i>=3) return false;
                pp->tosMetric[i] = string2ulong(value); return true;
        default: return false;
    }
}

const char *TOSDataDescriptor::getFieldStructName(int field) const
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

void *TOSDataDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TOSData *pp = (TOSData *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Link)

Link::Link() : ::omnetpp::cObject()
{
    this->linkData = 0;
    this->type = POINTTOPOINT_LINK;
    this->numberOfTOS = 0;
    this->linkCost = 1;
    tosData_arraysize = 0;
    this->tosData = 0;
}

Link::Link(const Link& other) : ::omnetpp::cObject(other)
{
    tosData_arraysize = 0;
    this->tosData = 0;
    copy(other);
}

Link::~Link()
{
    delete [] this->tosData;
}

Link& Link::operator=(const Link& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Link::copy(const Link& other)
{
    this->linkID = other.linkID;
    this->linkData = other.linkData;
    this->type = other.type;
    this->numberOfTOS = other.numberOfTOS;
    this->linkCost = other.linkCost;
    delete [] this->tosData;
    this->tosData = (other.tosData_arraysize==0) ? nullptr : new TOSData[other.tosData_arraysize];
    tosData_arraysize = other.tosData_arraysize;
    for (unsigned int i=0; i<tosData_arraysize; i++)
        this->tosData[i] = other.tosData[i];
}

void Link::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->linkID);
    doParsimPacking(b,this->linkData);
    doParsimPacking(b,this->type);
    doParsimPacking(b,this->numberOfTOS);
    doParsimPacking(b,this->linkCost);
    b->pack(tosData_arraysize);
    doParsimArrayPacking(b,this->tosData,tosData_arraysize);
}

void Link::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->linkID);
    doParsimUnpacking(b,this->linkData);
    doParsimUnpacking(b,this->type);
    doParsimUnpacking(b,this->numberOfTOS);
    doParsimUnpacking(b,this->linkCost);
    delete [] this->tosData;
    b->unpack(tosData_arraysize);
    if (tosData_arraysize==0) {
        this->tosData = 0;
    } else {
        this->tosData = new TOSData[tosData_arraysize];
        doParsimArrayUnpacking(b,this->tosData,tosData_arraysize);
    }
}

IPv4Address& Link::getLinkID()
{
    return this->linkID;
}

void Link::setLinkID(const IPv4Address& linkID)
{
    this->linkID = linkID;
}

unsigned long Link::getLinkData() const
{
    return this->linkData;
}

void Link::setLinkData(unsigned long linkData)
{
    this->linkData = linkData;
}

unsigned char Link::getType() const
{
    return this->type;
}

void Link::setType(unsigned char type)
{
    this->type = type;
}

unsigned char Link::getNumberOfTOS() const
{
    return this->numberOfTOS;
}

void Link::setNumberOfTOS(unsigned char numberOfTOS)
{
    this->numberOfTOS = numberOfTOS;
}

unsigned long Link::getLinkCost() const
{
    return this->linkCost;
}

void Link::setLinkCost(unsigned long linkCost)
{
    this->linkCost = linkCost;
}

void Link::setTosDataArraySize(unsigned int size)
{
    TOSData *tosData2 = (size==0) ? nullptr : new TOSData[size];
    unsigned int sz = tosData_arraysize < size ? tosData_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        tosData2[i] = this->tosData[i];
    tosData_arraysize = size;
    delete [] this->tosData;
    this->tosData = tosData2;
}

unsigned int Link::getTosDataArraySize() const
{
    return tosData_arraysize;
}

TOSData& Link::getTosData(unsigned int k)
{
    if (k>=tosData_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", tosData_arraysize, k);
    return this->tosData[k];
}

void Link::setTosData(unsigned int k, const TOSData& tosData)
{
    if (k>=tosData_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", tosData_arraysize, k);
    this->tosData[k] = tosData;
}

class LinkDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LinkDescriptor();
    virtual ~LinkDescriptor();

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

Register_ClassDescriptor(LinkDescriptor)

LinkDescriptor::LinkDescriptor() : omnetpp::cClassDescriptor("inet::ospf::Link", "omnetpp::cObject")
{
    propertynames = nullptr;
}

LinkDescriptor::~LinkDescriptor()
{
    delete[] propertynames;
}

bool LinkDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Link *>(obj)!=nullptr;
}

const char **LinkDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LinkDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LinkDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int LinkDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *LinkDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "linkID",
        "linkData",
        "type",
        "numberOfTOS",
        "linkCost",
        "tosData",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int LinkDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkID")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkData")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfTOS")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkCost")==0) return base+4;
    if (fieldName[0]=='t' && strcmp(fieldName, "tosData")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LinkDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "unsigned long",
        "unsigned char",
        "unsigned char",
        "unsigned long",
        "TOSData",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **LinkDescriptor::getFieldPropertyNames(int field) const
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

const char *LinkDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "inet::ospf::LinkType";
            return nullptr;
        default: return nullptr;
    }
}

int LinkDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        case 5: return pp->getTosDataArraySize();
        default: return 0;
    }
}

const char *LinkDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LinkDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getLinkID(); return out.str();}
        case 1: return ulong2string(pp->getLinkData());
        case 2: return enum2string(pp->getType(), "inet::ospf::LinkType");
        case 3: return ulong2string(pp->getNumberOfTOS());
        case 4: return ulong2string(pp->getLinkCost());
        case 5: {std::stringstream out; out << pp->getTosData(i); return out.str();}
        default: return "";
    }
}

bool LinkDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        case 1: pp->setLinkData(string2ulong(value)); return true;
        case 2: pp->setType((inet::ospf::LinkType)string2enum(value, "inet::ospf::LinkType")); return true;
        case 3: pp->setNumberOfTOS(string2ulong(value)); return true;
        case 4: pp->setLinkCost(string2ulong(value)); return true;
        default: return false;
    }
}

const char *LinkDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 5: return omnetpp::opp_typename(typeid(TOSData));
        default: return nullptr;
    };
}

void *LinkDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Link *pp = (Link *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getLinkID()); break;
        case 5: return (void *)(&pp->getTosData(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFRouterLSA)

OSPFRouterLSA::OSPFRouterLSA() : ::inet::ospf::OSPFLSA()
{
    this->V_VirtualLinkEndpoint = false;
    this->E_ASBoundaryRouter = false;
    this->B_AreaBorderRouter = false;
    this->numberOfLinks = 0;
    links_arraysize = 0;
    this->links = 0;
}

OSPFRouterLSA::OSPFRouterLSA(const OSPFRouterLSA& other) : ::inet::ospf::OSPFLSA(other)
{
    links_arraysize = 0;
    this->links = 0;
    copy(other);
}

OSPFRouterLSA::~OSPFRouterLSA()
{
    delete [] this->links;
}

OSPFRouterLSA& OSPFRouterLSA::operator=(const OSPFRouterLSA& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFLSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFRouterLSA::copy(const OSPFRouterLSA& other)
{
    this->V_VirtualLinkEndpoint = other.V_VirtualLinkEndpoint;
    this->E_ASBoundaryRouter = other.E_ASBoundaryRouter;
    this->B_AreaBorderRouter = other.B_AreaBorderRouter;
    this->numberOfLinks = other.numberOfLinks;
    delete [] this->links;
    this->links = (other.links_arraysize==0) ? nullptr : new Link[other.links_arraysize];
    links_arraysize = other.links_arraysize;
    for (unsigned int i=0; i<links_arraysize; i++)
        this->links[i] = other.links[i];
}

void OSPFRouterLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFLSA::parsimPack(b);
    doParsimPacking(b,this->V_VirtualLinkEndpoint);
    doParsimPacking(b,this->E_ASBoundaryRouter);
    doParsimPacking(b,this->B_AreaBorderRouter);
    doParsimPacking(b,this->numberOfLinks);
    b->pack(links_arraysize);
    doParsimArrayPacking(b,this->links,links_arraysize);
}

void OSPFRouterLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFLSA::parsimUnpack(b);
    doParsimUnpacking(b,this->V_VirtualLinkEndpoint);
    doParsimUnpacking(b,this->E_ASBoundaryRouter);
    doParsimUnpacking(b,this->B_AreaBorderRouter);
    doParsimUnpacking(b,this->numberOfLinks);
    delete [] this->links;
    b->unpack(links_arraysize);
    if (links_arraysize==0) {
        this->links = 0;
    } else {
        this->links = new Link[links_arraysize];
        doParsimArrayUnpacking(b,this->links,links_arraysize);
    }
}

bool OSPFRouterLSA::getV_VirtualLinkEndpoint() const
{
    return this->V_VirtualLinkEndpoint;
}

void OSPFRouterLSA::setV_VirtualLinkEndpoint(bool V_VirtualLinkEndpoint)
{
    this->V_VirtualLinkEndpoint = V_VirtualLinkEndpoint;
}

bool OSPFRouterLSA::getE_ASBoundaryRouter() const
{
    return this->E_ASBoundaryRouter;
}

void OSPFRouterLSA::setE_ASBoundaryRouter(bool E_ASBoundaryRouter)
{
    this->E_ASBoundaryRouter = E_ASBoundaryRouter;
}

bool OSPFRouterLSA::getB_AreaBorderRouter() const
{
    return this->B_AreaBorderRouter;
}

void OSPFRouterLSA::setB_AreaBorderRouter(bool B_AreaBorderRouter)
{
    this->B_AreaBorderRouter = B_AreaBorderRouter;
}

unsigned short OSPFRouterLSA::getNumberOfLinks() const
{
    return this->numberOfLinks;
}

void OSPFRouterLSA::setNumberOfLinks(unsigned short numberOfLinks)
{
    this->numberOfLinks = numberOfLinks;
}

void OSPFRouterLSA::setLinksArraySize(unsigned int size)
{
    Link *links2 = (size==0) ? nullptr : new Link[size];
    unsigned int sz = links_arraysize < size ? links_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        links2[i] = this->links[i];
    links_arraysize = size;
    delete [] this->links;
    this->links = links2;
}

unsigned int OSPFRouterLSA::getLinksArraySize() const
{
    return links_arraysize;
}

Link& OSPFRouterLSA::getLinks(unsigned int k)
{
    if (k>=links_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", links_arraysize, k);
    return this->links[k];
}

void OSPFRouterLSA::setLinks(unsigned int k, const Link& links)
{
    if (k>=links_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", links_arraysize, k);
    this->links[k] = links;
}

class OSPFRouterLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFRouterLSADescriptor();
    virtual ~OSPFRouterLSADescriptor();

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

Register_ClassDescriptor(OSPFRouterLSADescriptor)

OSPFRouterLSADescriptor::OSPFRouterLSADescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFRouterLSA", "inet::ospf::OSPFLSA")
{
    propertynames = nullptr;
}

OSPFRouterLSADescriptor::~OSPFRouterLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFRouterLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFRouterLSA *>(obj)!=nullptr;
}

const char **OSPFRouterLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFRouterLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFRouterLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OSPFRouterLSADescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OSPFRouterLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "V_VirtualLinkEndpoint",
        "E_ASBoundaryRouter",
        "B_AreaBorderRouter",
        "numberOfLinks",
        "links",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OSPFRouterLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='V' && strcmp(fieldName, "V_VirtualLinkEndpoint")==0) return base+0;
    if (fieldName[0]=='E' && strcmp(fieldName, "E_ASBoundaryRouter")==0) return base+1;
    if (fieldName[0]=='B' && strcmp(fieldName, "B_AreaBorderRouter")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfLinks")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "links")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFRouterLSADescriptor::getFieldTypeString(int field) const
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
        "unsigned short",
        "Link",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFRouterLSADescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFRouterLSADescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFRouterLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFRouterLSA *pp = (OSPFRouterLSA *)object; (void)pp;
    switch (field) {
        case 4: return pp->getLinksArraySize();
        default: return 0;
    }
}

const char *OSPFRouterLSADescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFRouterLSA *pp = (OSPFRouterLSA *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFRouterLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFRouterLSA *pp = (OSPFRouterLSA *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getV_VirtualLinkEndpoint());
        case 1: return bool2string(pp->getE_ASBoundaryRouter());
        case 2: return bool2string(pp->getB_AreaBorderRouter());
        case 3: return ulong2string(pp->getNumberOfLinks());
        case 4: {std::stringstream out; out << pp->getLinks(i); return out.str();}
        default: return "";
    }
}

bool OSPFRouterLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFRouterLSA *pp = (OSPFRouterLSA *)object; (void)pp;
    switch (field) {
        case 0: pp->setV_VirtualLinkEndpoint(string2bool(value)); return true;
        case 1: pp->setE_ASBoundaryRouter(string2bool(value)); return true;
        case 2: pp->setB_AreaBorderRouter(string2bool(value)); return true;
        case 3: pp->setNumberOfLinks(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFRouterLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(Link));
        default: return nullptr;
    };
}

void *OSPFRouterLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFRouterLSA *pp = (OSPFRouterLSA *)object; (void)pp;
    switch (field) {
        case 4: return (void *)static_cast<omnetpp::cObject *>(&pp->getLinks(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFNetworkLSA)

OSPFNetworkLSA::OSPFNetworkLSA() : ::inet::ospf::OSPFLSA()
{
    attachedRouters_arraysize = 0;
    this->attachedRouters = 0;
}

OSPFNetworkLSA::OSPFNetworkLSA(const OSPFNetworkLSA& other) : ::inet::ospf::OSPFLSA(other)
{
    attachedRouters_arraysize = 0;
    this->attachedRouters = 0;
    copy(other);
}

OSPFNetworkLSA::~OSPFNetworkLSA()
{
    delete [] this->attachedRouters;
}

OSPFNetworkLSA& OSPFNetworkLSA::operator=(const OSPFNetworkLSA& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFLSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFNetworkLSA::copy(const OSPFNetworkLSA& other)
{
    this->networkMask = other.networkMask;
    delete [] this->attachedRouters;
    this->attachedRouters = (other.attachedRouters_arraysize==0) ? nullptr : new IPv4Address[other.attachedRouters_arraysize];
    attachedRouters_arraysize = other.attachedRouters_arraysize;
    for (unsigned int i=0; i<attachedRouters_arraysize; i++)
        this->attachedRouters[i] = other.attachedRouters[i];
}

void OSPFNetworkLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFLSA::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    b->pack(attachedRouters_arraysize);
    doParsimArrayPacking(b,this->attachedRouters,attachedRouters_arraysize);
}

void OSPFNetworkLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFLSA::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    delete [] this->attachedRouters;
    b->unpack(attachedRouters_arraysize);
    if (attachedRouters_arraysize==0) {
        this->attachedRouters = 0;
    } else {
        this->attachedRouters = new IPv4Address[attachedRouters_arraysize];
        doParsimArrayUnpacking(b,this->attachedRouters,attachedRouters_arraysize);
    }
}

IPv4Address& OSPFNetworkLSA::getNetworkMask()
{
    return this->networkMask;
}

void OSPFNetworkLSA::setNetworkMask(const IPv4Address& networkMask)
{
    this->networkMask = networkMask;
}

void OSPFNetworkLSA::setAttachedRoutersArraySize(unsigned int size)
{
    IPv4Address *attachedRouters2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = attachedRouters_arraysize < size ? attachedRouters_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        attachedRouters2[i] = this->attachedRouters[i];
    attachedRouters_arraysize = size;
    delete [] this->attachedRouters;
    this->attachedRouters = attachedRouters2;
}

unsigned int OSPFNetworkLSA::getAttachedRoutersArraySize() const
{
    return attachedRouters_arraysize;
}

IPv4Address& OSPFNetworkLSA::getAttachedRouters(unsigned int k)
{
    if (k>=attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", attachedRouters_arraysize, k);
    return this->attachedRouters[k];
}

void OSPFNetworkLSA::setAttachedRouters(unsigned int k, const IPv4Address& attachedRouters)
{
    if (k>=attachedRouters_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", attachedRouters_arraysize, k);
    this->attachedRouters[k] = attachedRouters;
}

class OSPFNetworkLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFNetworkLSADescriptor();
    virtual ~OSPFNetworkLSADescriptor();

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

Register_ClassDescriptor(OSPFNetworkLSADescriptor)

OSPFNetworkLSADescriptor::OSPFNetworkLSADescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFNetworkLSA", "inet::ospf::OSPFLSA")
{
    propertynames = nullptr;
}

OSPFNetworkLSADescriptor::~OSPFNetworkLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFNetworkLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFNetworkLSA *>(obj)!=nullptr;
}

const char **OSPFNetworkLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFNetworkLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFNetworkLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int OSPFNetworkLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *OSPFNetworkLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "attachedRouters",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int OSPFNetworkLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "networkMask")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "attachedRouters")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFNetworkLSADescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFNetworkLSADescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFNetworkLSADescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFNetworkLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFNetworkLSA *pp = (OSPFNetworkLSA *)object; (void)pp;
    switch (field) {
        case 1: return pp->getAttachedRoutersArraySize();
        default: return 0;
    }
}

const char *OSPFNetworkLSADescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFNetworkLSA *pp = (OSPFNetworkLSA *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFNetworkLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFNetworkLSA *pp = (OSPFNetworkLSA *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getNetworkMask(); return out.str();}
        case 1: {std::stringstream out; out << pp->getAttachedRouters(i); return out.str();}
        default: return "";
    }
}

bool OSPFNetworkLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFNetworkLSA *pp = (OSPFNetworkLSA *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OSPFNetworkLSADescriptor::getFieldStructName(int field) const
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
        default: return nullptr;
    };
}

void *OSPFNetworkLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFNetworkLSA *pp = (OSPFNetworkLSA *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getNetworkMask()); break;
        case 1: return (void *)(&pp->getAttachedRouters(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFSummaryLSA)

OSPFSummaryLSA::OSPFSummaryLSA() : ::inet::ospf::OSPFLSA()
{
    this->routeCost = 1;
    tosData_arraysize = 0;
    this->tosData = 0;
}

OSPFSummaryLSA::OSPFSummaryLSA(const OSPFSummaryLSA& other) : ::inet::ospf::OSPFLSA(other)
{
    tosData_arraysize = 0;
    this->tosData = 0;
    copy(other);
}

OSPFSummaryLSA::~OSPFSummaryLSA()
{
    delete [] this->tosData;
}

OSPFSummaryLSA& OSPFSummaryLSA::operator=(const OSPFSummaryLSA& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFLSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFSummaryLSA::copy(const OSPFSummaryLSA& other)
{
    this->networkMask = other.networkMask;
    this->routeCost = other.routeCost;
    delete [] this->tosData;
    this->tosData = (other.tosData_arraysize==0) ? nullptr : new TOSData[other.tosData_arraysize];
    tosData_arraysize = other.tosData_arraysize;
    for (unsigned int i=0; i<tosData_arraysize; i++)
        this->tosData[i] = other.tosData[i];
}

void OSPFSummaryLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFLSA::parsimPack(b);
    doParsimPacking(b,this->networkMask);
    doParsimPacking(b,this->routeCost);
    b->pack(tosData_arraysize);
    doParsimArrayPacking(b,this->tosData,tosData_arraysize);
}

void OSPFSummaryLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFLSA::parsimUnpack(b);
    doParsimUnpacking(b,this->networkMask);
    doParsimUnpacking(b,this->routeCost);
    delete [] this->tosData;
    b->unpack(tosData_arraysize);
    if (tosData_arraysize==0) {
        this->tosData = 0;
    } else {
        this->tosData = new TOSData[tosData_arraysize];
        doParsimArrayUnpacking(b,this->tosData,tosData_arraysize);
    }
}

IPv4Address& OSPFSummaryLSA::getNetworkMask()
{
    return this->networkMask;
}

void OSPFSummaryLSA::setNetworkMask(const IPv4Address& networkMask)
{
    this->networkMask = networkMask;
}

unsigned long OSPFSummaryLSA::getRouteCost() const
{
    return this->routeCost;
}

void OSPFSummaryLSA::setRouteCost(unsigned long routeCost)
{
    this->routeCost = routeCost;
}

void OSPFSummaryLSA::setTosDataArraySize(unsigned int size)
{
    TOSData *tosData2 = (size==0) ? nullptr : new TOSData[size];
    unsigned int sz = tosData_arraysize < size ? tosData_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        tosData2[i] = this->tosData[i];
    tosData_arraysize = size;
    delete [] this->tosData;
    this->tosData = tosData2;
}

unsigned int OSPFSummaryLSA::getTosDataArraySize() const
{
    return tosData_arraysize;
}

TOSData& OSPFSummaryLSA::getTosData(unsigned int k)
{
    if (k>=tosData_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", tosData_arraysize, k);
    return this->tosData[k];
}

void OSPFSummaryLSA::setTosData(unsigned int k, const TOSData& tosData)
{
    if (k>=tosData_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", tosData_arraysize, k);
    this->tosData[k] = tosData;
}

class OSPFSummaryLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFSummaryLSADescriptor();
    virtual ~OSPFSummaryLSADescriptor();

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

Register_ClassDescriptor(OSPFSummaryLSADescriptor)

OSPFSummaryLSADescriptor::OSPFSummaryLSADescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFSummaryLSA", "inet::ospf::OSPFLSA")
{
    propertynames = nullptr;
}

OSPFSummaryLSADescriptor::~OSPFSummaryLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFSummaryLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFSummaryLSA *>(obj)!=nullptr;
}

const char **OSPFSummaryLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFSummaryLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFSummaryLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int OSPFSummaryLSADescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *OSPFSummaryLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "routeCost",
        "tosData",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int OSPFSummaryLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "networkMask")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routeCost")==0) return base+1;
    if (fieldName[0]=='t' && strcmp(fieldName, "tosData")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFSummaryLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "unsigned long",
        "TOSData",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFSummaryLSADescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFSummaryLSADescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFSummaryLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFSummaryLSA *pp = (OSPFSummaryLSA *)object; (void)pp;
    switch (field) {
        case 2: return pp->getTosDataArraySize();
        default: return 0;
    }
}

const char *OSPFSummaryLSADescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFSummaryLSA *pp = (OSPFSummaryLSA *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFSummaryLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFSummaryLSA *pp = (OSPFSummaryLSA *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getNetworkMask(); return out.str();}
        case 1: return ulong2string(pp->getRouteCost());
        case 2: {std::stringstream out; out << pp->getTosData(i); return out.str();}
        default: return "";
    }
}

bool OSPFSummaryLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFSummaryLSA *pp = (OSPFSummaryLSA *)object; (void)pp;
    switch (field) {
        case 1: pp->setRouteCost(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFSummaryLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(TOSData));
        default: return nullptr;
    };
}

void *OSPFSummaryLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFSummaryLSA *pp = (OSPFSummaryLSA *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getNetworkMask()); break;
        case 2: return (void *)(&pp->getTosData(i)); break;
        default: return nullptr;
    }
}

ExternalTOSInfo::ExternalTOSInfo()
{
    this->E_ExternalMetricType = false;
    this->externalRouteTag = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const ExternalTOSInfo& a)
{
    doParsimPacking(b,a.tosData);
    doParsimPacking(b,a.E_ExternalMetricType);
    doParsimPacking(b,a.forwardingAddress);
    doParsimPacking(b,a.externalRouteTag);
}

void __doUnpacking(omnetpp::cCommBuffer *b, ExternalTOSInfo& a)
{
    doParsimUnpacking(b,a.tosData);
    doParsimUnpacking(b,a.E_ExternalMetricType);
    doParsimUnpacking(b,a.forwardingAddress);
    doParsimUnpacking(b,a.externalRouteTag);
}

class ExternalTOSInfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ExternalTOSInfoDescriptor();
    virtual ~ExternalTOSInfoDescriptor();

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

Register_ClassDescriptor(ExternalTOSInfoDescriptor)

ExternalTOSInfoDescriptor::ExternalTOSInfoDescriptor() : omnetpp::cClassDescriptor("inet::ospf::ExternalTOSInfo", "")
{
    propertynames = nullptr;
}

ExternalTOSInfoDescriptor::~ExternalTOSInfoDescriptor()
{
    delete[] propertynames;
}

bool ExternalTOSInfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ExternalTOSInfo *>(obj)!=nullptr;
}

const char **ExternalTOSInfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ExternalTOSInfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ExternalTOSInfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int ExternalTOSInfoDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *ExternalTOSInfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "tosData",
        "E_ExternalMetricType",
        "forwardingAddress",
        "externalRouteTag",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int ExternalTOSInfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "tosData")==0) return base+0;
    if (fieldName[0]=='E' && strcmp(fieldName, "E_ExternalMetricType")==0) return base+1;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardingAddress")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "externalRouteTag")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ExternalTOSInfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "TOSData",
        "bool",
        "IPv4Address",
        "long",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **ExternalTOSInfoDescriptor::getFieldPropertyNames(int field) const
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

const char *ExternalTOSInfoDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int ExternalTOSInfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ExternalTOSInfo *pp = (ExternalTOSInfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *ExternalTOSInfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ExternalTOSInfo *pp = (ExternalTOSInfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ExternalTOSInfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ExternalTOSInfo *pp = (ExternalTOSInfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->tosData; return out.str();}
        case 1: return bool2string(pp->E_ExternalMetricType);
        case 2: {std::stringstream out; out << pp->forwardingAddress; return out.str();}
        case 3: return long2string(pp->externalRouteTag);
        default: return "";
    }
}

bool ExternalTOSInfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ExternalTOSInfo *pp = (ExternalTOSInfo *)object; (void)pp;
    switch (field) {
        case 1: pp->E_ExternalMetricType = string2bool(value); return true;
        case 3: pp->externalRouteTag = string2long(value); return true;
        default: return false;
    }
}

const char *ExternalTOSInfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(TOSData));
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *ExternalTOSInfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ExternalTOSInfo *pp = (ExternalTOSInfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->tosData); break;
        case 2: return (void *)(&pp->forwardingAddress); break;
        default: return nullptr;
    }
}

Register_Class(OSPFASExternalLSAContents)

OSPFASExternalLSAContents::OSPFASExternalLSAContents() : ::omnetpp::cObject()
{
    this->E_ExternalMetricType = false;
    this->routeCost = 1;
    this->externalRouteTag = 0;
    externalTOSInfo_arraysize = 0;
    this->externalTOSInfo = 0;
}

OSPFASExternalLSAContents::OSPFASExternalLSAContents(const OSPFASExternalLSAContents& other) : ::omnetpp::cObject(other)
{
    externalTOSInfo_arraysize = 0;
    this->externalTOSInfo = 0;
    copy(other);
}

OSPFASExternalLSAContents::~OSPFASExternalLSAContents()
{
    delete [] this->externalTOSInfo;
}

OSPFASExternalLSAContents& OSPFASExternalLSAContents::operator=(const OSPFASExternalLSAContents& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void OSPFASExternalLSAContents::copy(const OSPFASExternalLSAContents& other)
{
    this->networkMask = other.networkMask;
    this->E_ExternalMetricType = other.E_ExternalMetricType;
    this->routeCost = other.routeCost;
    this->forwardingAddress = other.forwardingAddress;
    this->externalRouteTag = other.externalRouteTag;
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = (other.externalTOSInfo_arraysize==0) ? nullptr : new ExternalTOSInfo[other.externalTOSInfo_arraysize];
    externalTOSInfo_arraysize = other.externalTOSInfo_arraysize;
    for (unsigned int i=0; i<externalTOSInfo_arraysize; i++)
        this->externalTOSInfo[i] = other.externalTOSInfo[i];
}

void OSPFASExternalLSAContents::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->networkMask);
    doParsimPacking(b,this->E_ExternalMetricType);
    doParsimPacking(b,this->routeCost);
    doParsimPacking(b,this->forwardingAddress);
    doParsimPacking(b,this->externalRouteTag);
    b->pack(externalTOSInfo_arraysize);
    doParsimArrayPacking(b,this->externalTOSInfo,externalTOSInfo_arraysize);
}

void OSPFASExternalLSAContents::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->networkMask);
    doParsimUnpacking(b,this->E_ExternalMetricType);
    doParsimUnpacking(b,this->routeCost);
    doParsimUnpacking(b,this->forwardingAddress);
    doParsimUnpacking(b,this->externalRouteTag);
    delete [] this->externalTOSInfo;
    b->unpack(externalTOSInfo_arraysize);
    if (externalTOSInfo_arraysize==0) {
        this->externalTOSInfo = 0;
    } else {
        this->externalTOSInfo = new ExternalTOSInfo[externalTOSInfo_arraysize];
        doParsimArrayUnpacking(b,this->externalTOSInfo,externalTOSInfo_arraysize);
    }
}

IPv4Address& OSPFASExternalLSAContents::getNetworkMask()
{
    return this->networkMask;
}

void OSPFASExternalLSAContents::setNetworkMask(const IPv4Address& networkMask)
{
    this->networkMask = networkMask;
}

bool OSPFASExternalLSAContents::getE_ExternalMetricType() const
{
    return this->E_ExternalMetricType;
}

void OSPFASExternalLSAContents::setE_ExternalMetricType(bool E_ExternalMetricType)
{
    this->E_ExternalMetricType = E_ExternalMetricType;
}

unsigned long OSPFASExternalLSAContents::getRouteCost() const
{
    return this->routeCost;
}

void OSPFASExternalLSAContents::setRouteCost(unsigned long routeCost)
{
    this->routeCost = routeCost;
}

IPv4Address& OSPFASExternalLSAContents::getForwardingAddress()
{
    return this->forwardingAddress;
}

void OSPFASExternalLSAContents::setForwardingAddress(const IPv4Address& forwardingAddress)
{
    this->forwardingAddress = forwardingAddress;
}

long OSPFASExternalLSAContents::getExternalRouteTag() const
{
    return this->externalRouteTag;
}

void OSPFASExternalLSAContents::setExternalRouteTag(long externalRouteTag)
{
    this->externalRouteTag = externalRouteTag;
}

void OSPFASExternalLSAContents::setExternalTOSInfoArraySize(unsigned int size)
{
    ExternalTOSInfo *externalTOSInfo2 = (size==0) ? nullptr : new ExternalTOSInfo[size];
    unsigned int sz = externalTOSInfo_arraysize < size ? externalTOSInfo_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        externalTOSInfo2[i] = this->externalTOSInfo[i];
    externalTOSInfo_arraysize = size;
    delete [] this->externalTOSInfo;
    this->externalTOSInfo = externalTOSInfo2;
}

unsigned int OSPFASExternalLSAContents::getExternalTOSInfoArraySize() const
{
    return externalTOSInfo_arraysize;
}

ExternalTOSInfo& OSPFASExternalLSAContents::getExternalTOSInfo(unsigned int k)
{
    if (k>=externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", externalTOSInfo_arraysize, k);
    return this->externalTOSInfo[k];
}

void OSPFASExternalLSAContents::setExternalTOSInfo(unsigned int k, const ExternalTOSInfo& externalTOSInfo)
{
    if (k>=externalTOSInfo_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", externalTOSInfo_arraysize, k);
    this->externalTOSInfo[k] = externalTOSInfo;
}

class OSPFASExternalLSAContentsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFASExternalLSAContentsDescriptor();
    virtual ~OSPFASExternalLSAContentsDescriptor();

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

Register_ClassDescriptor(OSPFASExternalLSAContentsDescriptor)

OSPFASExternalLSAContentsDescriptor::OSPFASExternalLSAContentsDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFASExternalLSAContents", "omnetpp::cObject")
{
    propertynames = nullptr;
}

OSPFASExternalLSAContentsDescriptor::~OSPFASExternalLSAContentsDescriptor()
{
    delete[] propertynames;
}

bool OSPFASExternalLSAContentsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFASExternalLSAContents *>(obj)!=nullptr;
}

const char **OSPFASExternalLSAContentsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFASExternalLSAContentsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFASExternalLSAContentsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int OSPFASExternalLSAContentsDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *OSPFASExternalLSAContentsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "networkMask",
        "E_ExternalMetricType",
        "routeCost",
        "forwardingAddress",
        "externalRouteTag",
        "externalTOSInfo",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int OSPFASExternalLSAContentsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "networkMask")==0) return base+0;
    if (fieldName[0]=='E' && strcmp(fieldName, "E_ExternalMetricType")==0) return base+1;
    if (fieldName[0]=='r' && strcmp(fieldName, "routeCost")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "forwardingAddress")==0) return base+3;
    if (fieldName[0]=='e' && strcmp(fieldName, "externalRouteTag")==0) return base+4;
    if (fieldName[0]=='e' && strcmp(fieldName, "externalTOSInfo")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFASExternalLSAContentsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "bool",
        "unsigned long",
        "IPv4Address",
        "long",
        "ExternalTOSInfo",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFASExternalLSAContentsDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFASExternalLSAContentsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFASExternalLSAContentsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSAContents *pp = (OSPFASExternalLSAContents *)object; (void)pp;
    switch (field) {
        case 5: return pp->getExternalTOSInfoArraySize();
        default: return 0;
    }
}

const char *OSPFASExternalLSAContentsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSAContents *pp = (OSPFASExternalLSAContents *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFASExternalLSAContentsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSAContents *pp = (OSPFASExternalLSAContents *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getNetworkMask(); return out.str();}
        case 1: return bool2string(pp->getE_ExternalMetricType());
        case 2: return ulong2string(pp->getRouteCost());
        case 3: {std::stringstream out; out << pp->getForwardingAddress(); return out.str();}
        case 4: return long2string(pp->getExternalRouteTag());
        case 5: {std::stringstream out; out << pp->getExternalTOSInfo(i); return out.str();}
        default: return "";
    }
}

bool OSPFASExternalLSAContentsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSAContents *pp = (OSPFASExternalLSAContents *)object; (void)pp;
    switch (field) {
        case 1: pp->setE_ExternalMetricType(string2bool(value)); return true;
        case 2: pp->setRouteCost(string2ulong(value)); return true;
        case 4: pp->setExternalRouteTag(string2long(value)); return true;
        default: return false;
    }
}

const char *OSPFASExternalLSAContentsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 3: return omnetpp::opp_typename(typeid(IPv4Address));
        case 5: return omnetpp::opp_typename(typeid(ExternalTOSInfo));
        default: return nullptr;
    };
}

void *OSPFASExternalLSAContentsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSAContents *pp = (OSPFASExternalLSAContents *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getNetworkMask()); break;
        case 3: return (void *)(&pp->getForwardingAddress()); break;
        case 5: return (void *)(&pp->getExternalTOSInfo(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFASExternalLSA)

OSPFASExternalLSA::OSPFASExternalLSA() : ::inet::ospf::OSPFLSA()
{
}

OSPFASExternalLSA::OSPFASExternalLSA(const OSPFASExternalLSA& other) : ::inet::ospf::OSPFLSA(other)
{
    copy(other);
}

OSPFASExternalLSA::~OSPFASExternalLSA()
{
}

OSPFASExternalLSA& OSPFASExternalLSA::operator=(const OSPFASExternalLSA& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFLSA::operator=(other);
    copy(other);
    return *this;
}

void OSPFASExternalLSA::copy(const OSPFASExternalLSA& other)
{
    this->contents = other.contents;
}

void OSPFASExternalLSA::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFLSA::parsimPack(b);
    doParsimPacking(b,this->contents);
}

void OSPFASExternalLSA::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFLSA::parsimUnpack(b);
    doParsimUnpacking(b,this->contents);
}

OSPFASExternalLSAContents& OSPFASExternalLSA::getContents()
{
    return this->contents;
}

void OSPFASExternalLSA::setContents(const OSPFASExternalLSAContents& contents)
{
    this->contents = contents;
}

class OSPFASExternalLSADescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFASExternalLSADescriptor();
    virtual ~OSPFASExternalLSADescriptor();

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

Register_ClassDescriptor(OSPFASExternalLSADescriptor)

OSPFASExternalLSADescriptor::OSPFASExternalLSADescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFASExternalLSA", "inet::ospf::OSPFLSA")
{
    propertynames = nullptr;
}

OSPFASExternalLSADescriptor::~OSPFASExternalLSADescriptor()
{
    delete[] propertynames;
}

bool OSPFASExternalLSADescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFASExternalLSA *>(obj)!=nullptr;
}

const char **OSPFASExternalLSADescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFASExternalLSADescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFASExternalLSADescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OSPFASExternalLSADescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFASExternalLSADescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "contents",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int OSPFASExternalLSADescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "contents")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFASExternalLSADescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "OSPFASExternalLSAContents",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFASExternalLSADescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFASExternalLSADescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFASExternalLSADescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSA *pp = (OSPFASExternalLSA *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OSPFASExternalLSADescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSA *pp = (OSPFASExternalLSA *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFASExternalLSADescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSA *pp = (OSPFASExternalLSA *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getContents(); return out.str();}
        default: return "";
    }
}

bool OSPFASExternalLSADescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSA *pp = (OSPFASExternalLSA *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OSPFASExternalLSADescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(OSPFASExternalLSAContents));
        default: return nullptr;
    };
}

void *OSPFASExternalLSADescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFASExternalLSA *pp = (OSPFASExternalLSA *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getContents()); break;
        default: return nullptr;
    }
}

OSPFDDOptions::OSPFDDOptions()
{
    this->unused_1 = false;
    this->unused_2 = false;
    this->unused_3 = false;
    this->unused_4 = false;
    this->unused_5 = false;
    this->I_Init = false;
    this->M_More = false;
    this->MS_MasterSlave = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const OSPFDDOptions& a)
{
    doParsimPacking(b,a.unused_1);
    doParsimPacking(b,a.unused_2);
    doParsimPacking(b,a.unused_3);
    doParsimPacking(b,a.unused_4);
    doParsimPacking(b,a.unused_5);
    doParsimPacking(b,a.I_Init);
    doParsimPacking(b,a.M_More);
    doParsimPacking(b,a.MS_MasterSlave);
}

void __doUnpacking(omnetpp::cCommBuffer *b, OSPFDDOptions& a)
{
    doParsimUnpacking(b,a.unused_1);
    doParsimUnpacking(b,a.unused_2);
    doParsimUnpacking(b,a.unused_3);
    doParsimUnpacking(b,a.unused_4);
    doParsimUnpacking(b,a.unused_5);
    doParsimUnpacking(b,a.I_Init);
    doParsimUnpacking(b,a.M_More);
    doParsimUnpacking(b,a.MS_MasterSlave);
}

class OSPFDDOptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFDDOptionsDescriptor();
    virtual ~OSPFDDOptionsDescriptor();

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

Register_ClassDescriptor(OSPFDDOptionsDescriptor)

OSPFDDOptionsDescriptor::OSPFDDOptionsDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFDDOptions", "")
{
    propertynames = nullptr;
}

OSPFDDOptionsDescriptor::~OSPFDDOptionsDescriptor()
{
    delete[] propertynames;
}

bool OSPFDDOptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFDDOptions *>(obj)!=nullptr;
}

const char **OSPFDDOptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFDDOptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFDDOptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 8+basedesc->getFieldCount() : 8;
}

unsigned int OSPFDDOptionsDescriptor::getFieldTypeFlags(int field) const
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

const char *OSPFDDOptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "unused_1",
        "unused_2",
        "unused_3",
        "unused_4",
        "unused_5",
        "I_Init",
        "M_More",
        "MS_MasterSlave",
    };
    return (field>=0 && field<8) ? fieldNames[field] : nullptr;
}

int OSPFDDOptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='u' && strcmp(fieldName, "unused_1")==0) return base+0;
    if (fieldName[0]=='u' && strcmp(fieldName, "unused_2")==0) return base+1;
    if (fieldName[0]=='u' && strcmp(fieldName, "unused_3")==0) return base+2;
    if (fieldName[0]=='u' && strcmp(fieldName, "unused_4")==0) return base+3;
    if (fieldName[0]=='u' && strcmp(fieldName, "unused_5")==0) return base+4;
    if (fieldName[0]=='I' && strcmp(fieldName, "I_Init")==0) return base+5;
    if (fieldName[0]=='M' && strcmp(fieldName, "M_More")==0) return base+6;
    if (fieldName[0]=='M' && strcmp(fieldName, "MS_MasterSlave")==0) return base+7;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFDDOptionsDescriptor::getFieldTypeString(int field) const
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
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
    };
    return (field>=0 && field<8) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFDDOptionsDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFDDOptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFDDOptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFDDOptions *pp = (OSPFDDOptions *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *OSPFDDOptionsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFDDOptions *pp = (OSPFDDOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFDDOptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFDDOptions *pp = (OSPFDDOptions *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->unused_1);
        case 1: return bool2string(pp->unused_2);
        case 2: return bool2string(pp->unused_3);
        case 3: return bool2string(pp->unused_4);
        case 4: return bool2string(pp->unused_5);
        case 5: return bool2string(pp->I_Init);
        case 6: return bool2string(pp->M_More);
        case 7: return bool2string(pp->MS_MasterSlave);
        default: return "";
    }
}

bool OSPFDDOptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFDDOptions *pp = (OSPFDDOptions *)object; (void)pp;
    switch (field) {
        case 0: pp->unused_1 = string2bool(value); return true;
        case 1: pp->unused_2 = string2bool(value); return true;
        case 2: pp->unused_3 = string2bool(value); return true;
        case 3: pp->unused_4 = string2bool(value); return true;
        case 4: pp->unused_5 = string2bool(value); return true;
        case 5: pp->I_Init = string2bool(value); return true;
        case 6: pp->M_More = string2bool(value); return true;
        case 7: pp->MS_MasterSlave = string2bool(value); return true;
        default: return false;
    }
}

const char *OSPFDDOptionsDescriptor::getFieldStructName(int field) const
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

void *OSPFDDOptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFDDOptions *pp = (OSPFDDOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(OSPFDatabaseDescriptionPacket)

OSPFDatabaseDescriptionPacket::OSPFDatabaseDescriptionPacket(const char *name, short kind) : ::inet::ospf::OSPFPacket(name,kind)
{
    this->interfaceMTU = 0;
    this->ddSequenceNumber = 0;
    lsaHeaders_arraysize = 0;
    this->lsaHeaders = 0;
}

OSPFDatabaseDescriptionPacket::OSPFDatabaseDescriptionPacket(const OSPFDatabaseDescriptionPacket& other) : ::inet::ospf::OSPFPacket(other)
{
    lsaHeaders_arraysize = 0;
    this->lsaHeaders = 0;
    copy(other);
}

OSPFDatabaseDescriptionPacket::~OSPFDatabaseDescriptionPacket()
{
    delete [] this->lsaHeaders;
}

OSPFDatabaseDescriptionPacket& OSPFDatabaseDescriptionPacket::operator=(const OSPFDatabaseDescriptionPacket& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFPacket::operator=(other);
    copy(other);
    return *this;
}

void OSPFDatabaseDescriptionPacket::copy(const OSPFDatabaseDescriptionPacket& other)
{
    this->interfaceMTU = other.interfaceMTU;
    this->options = other.options;
    this->ddOptions = other.ddOptions;
    this->ddSequenceNumber = other.ddSequenceNumber;
    delete [] this->lsaHeaders;
    this->lsaHeaders = (other.lsaHeaders_arraysize==0) ? nullptr : new OSPFLSAHeader[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (unsigned int i=0; i<lsaHeaders_arraysize; i++)
        this->lsaHeaders[i] = other.lsaHeaders[i];
}

void OSPFDatabaseDescriptionPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFPacket::parsimPack(b);
    doParsimPacking(b,this->interfaceMTU);
    doParsimPacking(b,this->options);
    doParsimPacking(b,this->ddOptions);
    doParsimPacking(b,this->ddSequenceNumber);
    b->pack(lsaHeaders_arraysize);
    doParsimArrayPacking(b,this->lsaHeaders,lsaHeaders_arraysize);
}

void OSPFDatabaseDescriptionPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->interfaceMTU);
    doParsimUnpacking(b,this->options);
    doParsimUnpacking(b,this->ddOptions);
    doParsimUnpacking(b,this->ddSequenceNumber);
    delete [] this->lsaHeaders;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize==0) {
        this->lsaHeaders = 0;
    } else {
        this->lsaHeaders = new OSPFLSAHeader[lsaHeaders_arraysize];
        doParsimArrayUnpacking(b,this->lsaHeaders,lsaHeaders_arraysize);
    }
}

unsigned short OSPFDatabaseDescriptionPacket::getInterfaceMTU() const
{
    return this->interfaceMTU;
}

void OSPFDatabaseDescriptionPacket::setInterfaceMTU(unsigned short interfaceMTU)
{
    this->interfaceMTU = interfaceMTU;
}

OSPFOptions& OSPFDatabaseDescriptionPacket::getOptions()
{
    return this->options;
}

void OSPFDatabaseDescriptionPacket::setOptions(const OSPFOptions& options)
{
    this->options = options;
}

OSPFDDOptions& OSPFDatabaseDescriptionPacket::getDdOptions()
{
    return this->ddOptions;
}

void OSPFDatabaseDescriptionPacket::setDdOptions(const OSPFDDOptions& ddOptions)
{
    this->ddOptions = ddOptions;
}

unsigned long OSPFDatabaseDescriptionPacket::getDdSequenceNumber() const
{
    return this->ddSequenceNumber;
}

void OSPFDatabaseDescriptionPacket::setDdSequenceNumber(unsigned long ddSequenceNumber)
{
    this->ddSequenceNumber = ddSequenceNumber;
}

void OSPFDatabaseDescriptionPacket::setLsaHeadersArraySize(unsigned int size)
{
    OSPFLSAHeader *lsaHeaders2 = (size==0) ? nullptr : new OSPFLSAHeader[size];
    unsigned int sz = lsaHeaders_arraysize < size ? lsaHeaders_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    lsaHeaders_arraysize = size;
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
}

unsigned int OSPFDatabaseDescriptionPacket::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

OSPFLSAHeader& OSPFDatabaseDescriptionPacket::getLsaHeaders(unsigned int k)
{
    if (k>=lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    return this->lsaHeaders[k];
}

void OSPFDatabaseDescriptionPacket::setLsaHeaders(unsigned int k, const OSPFLSAHeader& lsaHeaders)
{
    if (k>=lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    this->lsaHeaders[k] = lsaHeaders;
}

class OSPFDatabaseDescriptionPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFDatabaseDescriptionPacketDescriptor();
    virtual ~OSPFDatabaseDescriptionPacketDescriptor();

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

Register_ClassDescriptor(OSPFDatabaseDescriptionPacketDescriptor)

OSPFDatabaseDescriptionPacketDescriptor::OSPFDatabaseDescriptionPacketDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFDatabaseDescriptionPacket", "inet::ospf::OSPFPacket")
{
    propertynames = nullptr;
}

OSPFDatabaseDescriptionPacketDescriptor::~OSPFDatabaseDescriptionPacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFDatabaseDescriptionPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFDatabaseDescriptionPacket *>(obj)!=nullptr;
}

const char **OSPFDatabaseDescriptionPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFDatabaseDescriptionPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFDatabaseDescriptionPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OSPFDatabaseDescriptionPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OSPFDatabaseDescriptionPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "interfaceMTU",
        "options",
        "ddOptions",
        "ddSequenceNumber",
        "lsaHeaders",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OSPFDatabaseDescriptionPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceMTU")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+1;
    if (fieldName[0]=='d' && strcmp(fieldName, "ddOptions")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "ddSequenceNumber")==0) return base+3;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaHeaders")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFDatabaseDescriptionPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "OSPFOptions",
        "OSPFDDOptions",
        "unsigned long",
        "OSPFLSAHeader",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFDatabaseDescriptionPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFDatabaseDescriptionPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFDatabaseDescriptionPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFDatabaseDescriptionPacket *pp = (OSPFDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case 4: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

const char *OSPFDatabaseDescriptionPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFDatabaseDescriptionPacket *pp = (OSPFDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFDatabaseDescriptionPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFDatabaseDescriptionPacket *pp = (OSPFDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getInterfaceMTU());
        case 1: {std::stringstream out; out << pp->getOptions(); return out.str();}
        case 2: {std::stringstream out; out << pp->getDdOptions(); return out.str();}
        case 3: return ulong2string(pp->getDdSequenceNumber());
        case 4: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

bool OSPFDatabaseDescriptionPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFDatabaseDescriptionPacket *pp = (OSPFDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setInterfaceMTU(string2ulong(value)); return true;
        case 3: pp->setDdSequenceNumber(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFDatabaseDescriptionPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(OSPFOptions));
        case 2: return omnetpp::opp_typename(typeid(OSPFDDOptions));
        case 4: return omnetpp::opp_typename(typeid(OSPFLSAHeader));
        default: return nullptr;
    };
}

void *OSPFDatabaseDescriptionPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFDatabaseDescriptionPacket *pp = (OSPFDatabaseDescriptionPacket *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getOptions()); break;
        case 2: return (void *)(&pp->getDdOptions()); break;
        case 4: return (void *)static_cast<omnetpp::cObject *>(&pp->getLsaHeaders(i)); break;
        default: return nullptr;
    }
}

LSARequest::LSARequest()
{
    this->lsType = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const LSARequest& a)
{
    doParsimPacking(b,a.lsType);
    doParsimPacking(b,a.linkStateID);
    doParsimPacking(b,a.advertisingRouter);
}

void __doUnpacking(omnetpp::cCommBuffer *b, LSARequest& a)
{
    doParsimUnpacking(b,a.lsType);
    doParsimUnpacking(b,a.linkStateID);
    doParsimUnpacking(b,a.advertisingRouter);
}

class LSARequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LSARequestDescriptor();
    virtual ~LSARequestDescriptor();

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

Register_ClassDescriptor(LSARequestDescriptor)

LSARequestDescriptor::LSARequestDescriptor() : omnetpp::cClassDescriptor("inet::ospf::LSARequest", "")
{
    propertynames = nullptr;
}

LSARequestDescriptor::~LSARequestDescriptor()
{
    delete[] propertynames;
}

bool LSARequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LSARequest *>(obj)!=nullptr;
}

const char **LSARequestDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LSARequestDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LSARequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int LSARequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *LSARequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsType",
        "linkStateID",
        "advertisingRouter",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int LSARequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsType")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "linkStateID")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "advertisingRouter")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LSARequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",
        "IPv4Address",
        "IPv4Address",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **LSARequestDescriptor::getFieldPropertyNames(int field) const
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

const char *LSARequestDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LSARequestDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LSARequest *pp = (LSARequest *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LSARequestDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LSARequest *pp = (LSARequest *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LSARequestDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LSARequest *pp = (LSARequest *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->lsType);
        case 1: {std::stringstream out; out << pp->linkStateID; return out.str();}
        case 2: {std::stringstream out; out << pp->advertisingRouter; return out.str();}
        default: return "";
    }
}

bool LSARequestDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LSARequest *pp = (LSARequest *)object; (void)pp;
    switch (field) {
        case 0: pp->lsType = string2ulong(value); return true;
        default: return false;
    }
}

const char *LSARequestDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *LSARequestDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LSARequest *pp = (LSARequest *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->linkStateID); break;
        case 2: return (void *)(&pp->advertisingRouter); break;
        default: return nullptr;
    }
}

Register_Class(OSPFLinkStateRequestPacket)

OSPFLinkStateRequestPacket::OSPFLinkStateRequestPacket(const char *name, short kind) : ::inet::ospf::OSPFPacket(name,kind)
{
    requests_arraysize = 0;
    this->requests = 0;
}

OSPFLinkStateRequestPacket::OSPFLinkStateRequestPacket(const OSPFLinkStateRequestPacket& other) : ::inet::ospf::OSPFPacket(other)
{
    requests_arraysize = 0;
    this->requests = 0;
    copy(other);
}

OSPFLinkStateRequestPacket::~OSPFLinkStateRequestPacket()
{
    delete [] this->requests;
}

OSPFLinkStateRequestPacket& OSPFLinkStateRequestPacket::operator=(const OSPFLinkStateRequestPacket& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFPacket::operator=(other);
    copy(other);
    return *this;
}

void OSPFLinkStateRequestPacket::copy(const OSPFLinkStateRequestPacket& other)
{
    delete [] this->requests;
    this->requests = (other.requests_arraysize==0) ? nullptr : new LSARequest[other.requests_arraysize];
    requests_arraysize = other.requests_arraysize;
    for (unsigned int i=0; i<requests_arraysize; i++)
        this->requests[i] = other.requests[i];
}

void OSPFLinkStateRequestPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFPacket::parsimPack(b);
    b->pack(requests_arraysize);
    doParsimArrayPacking(b,this->requests,requests_arraysize);
}

void OSPFLinkStateRequestPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFPacket::parsimUnpack(b);
    delete [] this->requests;
    b->unpack(requests_arraysize);
    if (requests_arraysize==0) {
        this->requests = 0;
    } else {
        this->requests = new LSARequest[requests_arraysize];
        doParsimArrayUnpacking(b,this->requests,requests_arraysize);
    }
}

void OSPFLinkStateRequestPacket::setRequestsArraySize(unsigned int size)
{
    LSARequest *requests2 = (size==0) ? nullptr : new LSARequest[size];
    unsigned int sz = requests_arraysize < size ? requests_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        requests2[i] = this->requests[i];
    requests_arraysize = size;
    delete [] this->requests;
    this->requests = requests2;
}

unsigned int OSPFLinkStateRequestPacket::getRequestsArraySize() const
{
    return requests_arraysize;
}

LSARequest& OSPFLinkStateRequestPacket::getRequests(unsigned int k)
{
    if (k>=requests_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", requests_arraysize, k);
    return this->requests[k];
}

void OSPFLinkStateRequestPacket::setRequests(unsigned int k, const LSARequest& requests)
{
    if (k>=requests_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", requests_arraysize, k);
    this->requests[k] = requests;
}

class OSPFLinkStateRequestPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFLinkStateRequestPacketDescriptor();
    virtual ~OSPFLinkStateRequestPacketDescriptor();

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

Register_ClassDescriptor(OSPFLinkStateRequestPacketDescriptor)

OSPFLinkStateRequestPacketDescriptor::OSPFLinkStateRequestPacketDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFLinkStateRequestPacket", "inet::ospf::OSPFPacket")
{
    propertynames = nullptr;
}

OSPFLinkStateRequestPacketDescriptor::~OSPFLinkStateRequestPacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFLinkStateRequestPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFLinkStateRequestPacket *>(obj)!=nullptr;
}

const char **OSPFLinkStateRequestPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFLinkStateRequestPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFLinkStateRequestPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OSPFLinkStateRequestPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFLinkStateRequestPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "requests",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int OSPFLinkStateRequestPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "requests")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFLinkStateRequestPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "LSARequest",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFLinkStateRequestPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFLinkStateRequestPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFLinkStateRequestPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateRequestPacket *pp = (OSPFLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case 0: return pp->getRequestsArraySize();
        default: return 0;
    }
}

const char *OSPFLinkStateRequestPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateRequestPacket *pp = (OSPFLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFLinkStateRequestPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateRequestPacket *pp = (OSPFLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getRequests(i); return out.str();}
        default: return "";
    }
}

bool OSPFLinkStateRequestPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateRequestPacket *pp = (OSPFLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OSPFLinkStateRequestPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(LSARequest));
        default: return nullptr;
    };
}

void *OSPFLinkStateRequestPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateRequestPacket *pp = (OSPFLinkStateRequestPacket *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getRequests(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFLinkStateUpdatePacket)

OSPFLinkStateUpdatePacket::OSPFLinkStateUpdatePacket(const char *name, short kind) : ::inet::ospf::OSPFPacket(name,kind)
{
    this->numberOfLSAs = 0;
    routerLSAs_arraysize = 0;
    this->routerLSAs = 0;
    networkLSAs_arraysize = 0;
    this->networkLSAs = 0;
    summaryLSAs_arraysize = 0;
    this->summaryLSAs = 0;
    asExternalLSAs_arraysize = 0;
    this->asExternalLSAs = 0;
}

OSPFLinkStateUpdatePacket::OSPFLinkStateUpdatePacket(const OSPFLinkStateUpdatePacket& other) : ::inet::ospf::OSPFPacket(other)
{
    routerLSAs_arraysize = 0;
    this->routerLSAs = 0;
    networkLSAs_arraysize = 0;
    this->networkLSAs = 0;
    summaryLSAs_arraysize = 0;
    this->summaryLSAs = 0;
    asExternalLSAs_arraysize = 0;
    this->asExternalLSAs = 0;
    copy(other);
}

OSPFLinkStateUpdatePacket::~OSPFLinkStateUpdatePacket()
{
    delete [] this->routerLSAs;
    delete [] this->networkLSAs;
    delete [] this->summaryLSAs;
    delete [] this->asExternalLSAs;
}

OSPFLinkStateUpdatePacket& OSPFLinkStateUpdatePacket::operator=(const OSPFLinkStateUpdatePacket& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFPacket::operator=(other);
    copy(other);
    return *this;
}

void OSPFLinkStateUpdatePacket::copy(const OSPFLinkStateUpdatePacket& other)
{
    this->numberOfLSAs = other.numberOfLSAs;
    delete [] this->routerLSAs;
    this->routerLSAs = (other.routerLSAs_arraysize==0) ? nullptr : new OSPFRouterLSA[other.routerLSAs_arraysize];
    routerLSAs_arraysize = other.routerLSAs_arraysize;
    for (unsigned int i=0; i<routerLSAs_arraysize; i++)
        this->routerLSAs[i] = other.routerLSAs[i];
    delete [] this->networkLSAs;
    this->networkLSAs = (other.networkLSAs_arraysize==0) ? nullptr : new OSPFNetworkLSA[other.networkLSAs_arraysize];
    networkLSAs_arraysize = other.networkLSAs_arraysize;
    for (unsigned int i=0; i<networkLSAs_arraysize; i++)
        this->networkLSAs[i] = other.networkLSAs[i];
    delete [] this->summaryLSAs;
    this->summaryLSAs = (other.summaryLSAs_arraysize==0) ? nullptr : new OSPFSummaryLSA[other.summaryLSAs_arraysize];
    summaryLSAs_arraysize = other.summaryLSAs_arraysize;
    for (unsigned int i=0; i<summaryLSAs_arraysize; i++)
        this->summaryLSAs[i] = other.summaryLSAs[i];
    delete [] this->asExternalLSAs;
    this->asExternalLSAs = (other.asExternalLSAs_arraysize==0) ? nullptr : new OSPFASExternalLSA[other.asExternalLSAs_arraysize];
    asExternalLSAs_arraysize = other.asExternalLSAs_arraysize;
    for (unsigned int i=0; i<asExternalLSAs_arraysize; i++)
        this->asExternalLSAs[i] = other.asExternalLSAs[i];
}

void OSPFLinkStateUpdatePacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFPacket::parsimPack(b);
    doParsimPacking(b,this->numberOfLSAs);
    b->pack(routerLSAs_arraysize);
    doParsimArrayPacking(b,this->routerLSAs,routerLSAs_arraysize);
    b->pack(networkLSAs_arraysize);
    doParsimArrayPacking(b,this->networkLSAs,networkLSAs_arraysize);
    b->pack(summaryLSAs_arraysize);
    doParsimArrayPacking(b,this->summaryLSAs,summaryLSAs_arraysize);
    b->pack(asExternalLSAs_arraysize);
    doParsimArrayPacking(b,this->asExternalLSAs,asExternalLSAs_arraysize);
}

void OSPFLinkStateUpdatePacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->numberOfLSAs);
    delete [] this->routerLSAs;
    b->unpack(routerLSAs_arraysize);
    if (routerLSAs_arraysize==0) {
        this->routerLSAs = 0;
    } else {
        this->routerLSAs = new OSPFRouterLSA[routerLSAs_arraysize];
        doParsimArrayUnpacking(b,this->routerLSAs,routerLSAs_arraysize);
    }
    delete [] this->networkLSAs;
    b->unpack(networkLSAs_arraysize);
    if (networkLSAs_arraysize==0) {
        this->networkLSAs = 0;
    } else {
        this->networkLSAs = new OSPFNetworkLSA[networkLSAs_arraysize];
        doParsimArrayUnpacking(b,this->networkLSAs,networkLSAs_arraysize);
    }
    delete [] this->summaryLSAs;
    b->unpack(summaryLSAs_arraysize);
    if (summaryLSAs_arraysize==0) {
        this->summaryLSAs = 0;
    } else {
        this->summaryLSAs = new OSPFSummaryLSA[summaryLSAs_arraysize];
        doParsimArrayUnpacking(b,this->summaryLSAs,summaryLSAs_arraysize);
    }
    delete [] this->asExternalLSAs;
    b->unpack(asExternalLSAs_arraysize);
    if (asExternalLSAs_arraysize==0) {
        this->asExternalLSAs = 0;
    } else {
        this->asExternalLSAs = new OSPFASExternalLSA[asExternalLSAs_arraysize];
        doParsimArrayUnpacking(b,this->asExternalLSAs,asExternalLSAs_arraysize);
    }
}

unsigned long OSPFLinkStateUpdatePacket::getNumberOfLSAs() const
{
    return this->numberOfLSAs;
}

void OSPFLinkStateUpdatePacket::setNumberOfLSAs(unsigned long numberOfLSAs)
{
    this->numberOfLSAs = numberOfLSAs;
}

void OSPFLinkStateUpdatePacket::setRouterLSAsArraySize(unsigned int size)
{
    OSPFRouterLSA *routerLSAs2 = (size==0) ? nullptr : new OSPFRouterLSA[size];
    unsigned int sz = routerLSAs_arraysize < size ? routerLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        routerLSAs2[i] = this->routerLSAs[i];
    routerLSAs_arraysize = size;
    delete [] this->routerLSAs;
    this->routerLSAs = routerLSAs2;
}

unsigned int OSPFLinkStateUpdatePacket::getRouterLSAsArraySize() const
{
    return routerLSAs_arraysize;
}

OSPFRouterLSA& OSPFLinkStateUpdatePacket::getRouterLSAs(unsigned int k)
{
    if (k>=routerLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", routerLSAs_arraysize, k);
    return this->routerLSAs[k];
}

void OSPFLinkStateUpdatePacket::setRouterLSAs(unsigned int k, const OSPFRouterLSA& routerLSAs)
{
    if (k>=routerLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", routerLSAs_arraysize, k);
    this->routerLSAs[k] = routerLSAs;
}

void OSPFLinkStateUpdatePacket::setNetworkLSAsArraySize(unsigned int size)
{
    OSPFNetworkLSA *networkLSAs2 = (size==0) ? nullptr : new OSPFNetworkLSA[size];
    unsigned int sz = networkLSAs_arraysize < size ? networkLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        networkLSAs2[i] = this->networkLSAs[i];
    networkLSAs_arraysize = size;
    delete [] this->networkLSAs;
    this->networkLSAs = networkLSAs2;
}

unsigned int OSPFLinkStateUpdatePacket::getNetworkLSAsArraySize() const
{
    return networkLSAs_arraysize;
}

OSPFNetworkLSA& OSPFLinkStateUpdatePacket::getNetworkLSAs(unsigned int k)
{
    if (k>=networkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", networkLSAs_arraysize, k);
    return this->networkLSAs[k];
}

void OSPFLinkStateUpdatePacket::setNetworkLSAs(unsigned int k, const OSPFNetworkLSA& networkLSAs)
{
    if (k>=networkLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", networkLSAs_arraysize, k);
    this->networkLSAs[k] = networkLSAs;
}

void OSPFLinkStateUpdatePacket::setSummaryLSAsArraySize(unsigned int size)
{
    OSPFSummaryLSA *summaryLSAs2 = (size==0) ? nullptr : new OSPFSummaryLSA[size];
    unsigned int sz = summaryLSAs_arraysize < size ? summaryLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        summaryLSAs2[i] = this->summaryLSAs[i];
    summaryLSAs_arraysize = size;
    delete [] this->summaryLSAs;
    this->summaryLSAs = summaryLSAs2;
}

unsigned int OSPFLinkStateUpdatePacket::getSummaryLSAsArraySize() const
{
    return summaryLSAs_arraysize;
}

OSPFSummaryLSA& OSPFLinkStateUpdatePacket::getSummaryLSAs(unsigned int k)
{
    if (k>=summaryLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", summaryLSAs_arraysize, k);
    return this->summaryLSAs[k];
}

void OSPFLinkStateUpdatePacket::setSummaryLSAs(unsigned int k, const OSPFSummaryLSA& summaryLSAs)
{
    if (k>=summaryLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", summaryLSAs_arraysize, k);
    this->summaryLSAs[k] = summaryLSAs;
}

void OSPFLinkStateUpdatePacket::setAsExternalLSAsArraySize(unsigned int size)
{
    OSPFASExternalLSA *asExternalLSAs2 = (size==0) ? nullptr : new OSPFASExternalLSA[size];
    unsigned int sz = asExternalLSAs_arraysize < size ? asExternalLSAs_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        asExternalLSAs2[i] = this->asExternalLSAs[i];
    asExternalLSAs_arraysize = size;
    delete [] this->asExternalLSAs;
    this->asExternalLSAs = asExternalLSAs2;
}

unsigned int OSPFLinkStateUpdatePacket::getAsExternalLSAsArraySize() const
{
    return asExternalLSAs_arraysize;
}

OSPFASExternalLSA& OSPFLinkStateUpdatePacket::getAsExternalLSAs(unsigned int k)
{
    if (k>=asExternalLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", asExternalLSAs_arraysize, k);
    return this->asExternalLSAs[k];
}

void OSPFLinkStateUpdatePacket::setAsExternalLSAs(unsigned int k, const OSPFASExternalLSA& asExternalLSAs)
{
    if (k>=asExternalLSAs_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", asExternalLSAs_arraysize, k);
    this->asExternalLSAs[k] = asExternalLSAs;
}

class OSPFLinkStateUpdatePacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFLinkStateUpdatePacketDescriptor();
    virtual ~OSPFLinkStateUpdatePacketDescriptor();

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

Register_ClassDescriptor(OSPFLinkStateUpdatePacketDescriptor)

OSPFLinkStateUpdatePacketDescriptor::OSPFLinkStateUpdatePacketDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFLinkStateUpdatePacket", "inet::ospf::OSPFPacket")
{
    propertynames = nullptr;
}

OSPFLinkStateUpdatePacketDescriptor::~OSPFLinkStateUpdatePacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFLinkStateUpdatePacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFLinkStateUpdatePacket *>(obj)!=nullptr;
}

const char **OSPFLinkStateUpdatePacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFLinkStateUpdatePacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFLinkStateUpdatePacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int OSPFLinkStateUpdatePacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *OSPFLinkStateUpdatePacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "numberOfLSAs",
        "routerLSAs",
        "networkLSAs",
        "summaryLSAs",
        "asExternalLSAs",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int OSPFLinkStateUpdatePacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfLSAs")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "routerLSAs")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "networkLSAs")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "summaryLSAs")==0) return base+3;
    if (fieldName[0]=='a' && strcmp(fieldName, "asExternalLSAs")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFLinkStateUpdatePacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",
        "OSPFRouterLSA",
        "OSPFNetworkLSA",
        "OSPFSummaryLSA",
        "OSPFASExternalLSA",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFLinkStateUpdatePacketDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFLinkStateUpdatePacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFLinkStateUpdatePacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateUpdatePacket *pp = (OSPFLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case 1: return pp->getRouterLSAsArraySize();
        case 2: return pp->getNetworkLSAsArraySize();
        case 3: return pp->getSummaryLSAsArraySize();
        case 4: return pp->getAsExternalLSAsArraySize();
        default: return 0;
    }
}

const char *OSPFLinkStateUpdatePacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateUpdatePacket *pp = (OSPFLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFLinkStateUpdatePacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateUpdatePacket *pp = (OSPFLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getNumberOfLSAs());
        case 1: {std::stringstream out; out << pp->getRouterLSAs(i); return out.str();}
        case 2: {std::stringstream out; out << pp->getNetworkLSAs(i); return out.str();}
        case 3: {std::stringstream out; out << pp->getSummaryLSAs(i); return out.str();}
        case 4: {std::stringstream out; out << pp->getAsExternalLSAs(i); return out.str();}
        default: return "";
    }
}

bool OSPFLinkStateUpdatePacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateUpdatePacket *pp = (OSPFLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setNumberOfLSAs(string2ulong(value)); return true;
        default: return false;
    }
}

const char *OSPFLinkStateUpdatePacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(OSPFRouterLSA));
        case 2: return omnetpp::opp_typename(typeid(OSPFNetworkLSA));
        case 3: return omnetpp::opp_typename(typeid(OSPFSummaryLSA));
        case 4: return omnetpp::opp_typename(typeid(OSPFASExternalLSA));
        default: return nullptr;
    };
}

void *OSPFLinkStateUpdatePacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateUpdatePacket *pp = (OSPFLinkStateUpdatePacket *)object; (void)pp;
    switch (field) {
        case 1: return (void *)static_cast<omnetpp::cObject *>(&pp->getRouterLSAs(i)); break;
        case 2: return (void *)static_cast<omnetpp::cObject *>(&pp->getNetworkLSAs(i)); break;
        case 3: return (void *)static_cast<omnetpp::cObject *>(&pp->getSummaryLSAs(i)); break;
        case 4: return (void *)static_cast<omnetpp::cObject *>(&pp->getAsExternalLSAs(i)); break;
        default: return nullptr;
    }
}

Register_Class(OSPFLinkStateAcknowledgementPacket)

OSPFLinkStateAcknowledgementPacket::OSPFLinkStateAcknowledgementPacket(const char *name, short kind) : ::inet::ospf::OSPFPacket(name,kind)
{
    lsaHeaders_arraysize = 0;
    this->lsaHeaders = 0;
}

OSPFLinkStateAcknowledgementPacket::OSPFLinkStateAcknowledgementPacket(const OSPFLinkStateAcknowledgementPacket& other) : ::inet::ospf::OSPFPacket(other)
{
    lsaHeaders_arraysize = 0;
    this->lsaHeaders = 0;
    copy(other);
}

OSPFLinkStateAcknowledgementPacket::~OSPFLinkStateAcknowledgementPacket()
{
    delete [] this->lsaHeaders;
}

OSPFLinkStateAcknowledgementPacket& OSPFLinkStateAcknowledgementPacket::operator=(const OSPFLinkStateAcknowledgementPacket& other)
{
    if (this==&other) return *this;
    ::inet::ospf::OSPFPacket::operator=(other);
    copy(other);
    return *this;
}

void OSPFLinkStateAcknowledgementPacket::copy(const OSPFLinkStateAcknowledgementPacket& other)
{
    delete [] this->lsaHeaders;
    this->lsaHeaders = (other.lsaHeaders_arraysize==0) ? nullptr : new OSPFLSAHeader[other.lsaHeaders_arraysize];
    lsaHeaders_arraysize = other.lsaHeaders_arraysize;
    for (unsigned int i=0; i<lsaHeaders_arraysize; i++)
        this->lsaHeaders[i] = other.lsaHeaders[i];
}

void OSPFLinkStateAcknowledgementPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ospf::OSPFPacket::parsimPack(b);
    b->pack(lsaHeaders_arraysize);
    doParsimArrayPacking(b,this->lsaHeaders,lsaHeaders_arraysize);
}

void OSPFLinkStateAcknowledgementPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ospf::OSPFPacket::parsimUnpack(b);
    delete [] this->lsaHeaders;
    b->unpack(lsaHeaders_arraysize);
    if (lsaHeaders_arraysize==0) {
        this->lsaHeaders = 0;
    } else {
        this->lsaHeaders = new OSPFLSAHeader[lsaHeaders_arraysize];
        doParsimArrayUnpacking(b,this->lsaHeaders,lsaHeaders_arraysize);
    }
}

void OSPFLinkStateAcknowledgementPacket::setLsaHeadersArraySize(unsigned int size)
{
    OSPFLSAHeader *lsaHeaders2 = (size==0) ? nullptr : new OSPFLSAHeader[size];
    unsigned int sz = lsaHeaders_arraysize < size ? lsaHeaders_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        lsaHeaders2[i] = this->lsaHeaders[i];
    lsaHeaders_arraysize = size;
    delete [] this->lsaHeaders;
    this->lsaHeaders = lsaHeaders2;
}

unsigned int OSPFLinkStateAcknowledgementPacket::getLsaHeadersArraySize() const
{
    return lsaHeaders_arraysize;
}

OSPFLSAHeader& OSPFLinkStateAcknowledgementPacket::getLsaHeaders(unsigned int k)
{
    if (k>=lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    return this->lsaHeaders[k];
}

void OSPFLinkStateAcknowledgementPacket::setLsaHeaders(unsigned int k, const OSPFLSAHeader& lsaHeaders)
{
    if (k>=lsaHeaders_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", lsaHeaders_arraysize, k);
    this->lsaHeaders[k] = lsaHeaders;
}

class OSPFLinkStateAcknowledgementPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    OSPFLinkStateAcknowledgementPacketDescriptor();
    virtual ~OSPFLinkStateAcknowledgementPacketDescriptor();

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

Register_ClassDescriptor(OSPFLinkStateAcknowledgementPacketDescriptor)

OSPFLinkStateAcknowledgementPacketDescriptor::OSPFLinkStateAcknowledgementPacketDescriptor() : omnetpp::cClassDescriptor("inet::ospf::OSPFLinkStateAcknowledgementPacket", "inet::ospf::OSPFPacket")
{
    propertynames = nullptr;
}

OSPFLinkStateAcknowledgementPacketDescriptor::~OSPFLinkStateAcknowledgementPacketDescriptor()
{
    delete[] propertynames;
}

bool OSPFLinkStateAcknowledgementPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<OSPFLinkStateAcknowledgementPacket *>(obj)!=nullptr;
}

const char **OSPFLinkStateAcknowledgementPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *OSPFLinkStateAcknowledgementPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int OSPFLinkStateAcknowledgementPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int OSPFLinkStateAcknowledgementPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *OSPFLinkStateAcknowledgementPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "lsaHeaders",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int OSPFLinkStateAcknowledgementPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "lsaHeaders")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *OSPFLinkStateAcknowledgementPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "OSPFLSAHeader",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **OSPFLinkStateAcknowledgementPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *OSPFLinkStateAcknowledgementPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int OSPFLinkStateAcknowledgementPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateAcknowledgementPacket *pp = (OSPFLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case 0: return pp->getLsaHeadersArraySize();
        default: return 0;
    }
}

const char *OSPFLinkStateAcknowledgementPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateAcknowledgementPacket *pp = (OSPFLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string OSPFLinkStateAcknowledgementPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateAcknowledgementPacket *pp = (OSPFLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getLsaHeaders(i); return out.str();}
        default: return "";
    }
}

bool OSPFLinkStateAcknowledgementPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateAcknowledgementPacket *pp = (OSPFLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *OSPFLinkStateAcknowledgementPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(OSPFLSAHeader));
        default: return nullptr;
    };
}

void *OSPFLinkStateAcknowledgementPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    OSPFLinkStateAcknowledgementPacket *pp = (OSPFLinkStateAcknowledgementPacket *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getLsaHeaders(i)); break;
        default: return nullptr;
    }
}

} // namespace ospf
} // namespace inet

