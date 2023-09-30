//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/linklayer/common/Ieee802Ctrl.msg.
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
#include "Ieee802Ctrl_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::Ieee802MessageKind");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::Ieee802MessageKind"));
    e->insert(IEEE802CTRL_DATA, "IEEE802CTRL_DATA");
    e->insert(IEEE802CTRL_REGISTER_DSAP, "IEEE802CTRL_REGISTER_DSAP");
    e->insert(IEEE802CTRL_DEREGISTER_DSAP, "IEEE802CTRL_DEREGISTER_DSAP");
    e->insert(IEEE802CTRL_SENDPAUSE, "IEEE802CTRL_SENDPAUSE");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::SAPCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::SAPCode"));
    e->insert(SAP_IBM_SNA, "SAP_IBM_SNA");
    e->insert(SAP_IP, "SAP_IP");
    e->insert(SAP_3COM, "SAP_3COM");
    e->insert(SAP_SNAP, "SAP_SNAP");
    e->insert(SAP_BANYAN, "SAP_BANYAN");
    e->insert(SAP_NOVELL_IPX, "SAP_NOVELL_IPX");
    e->insert(SAP_LAN_MANAGER, "SAP_LAN_MANAGER");
    e->insert(SAP_CLNS, "SAP_CLNS");
    e->insert(SAP_STP, "SAP_STP");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::EtherType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::EtherType"));
    e->insert(ETHERTYPE_IPv4, "ETHERTYPE_IPv4");
    e->insert(ETHERTYPE_ARP, "ETHERTYPE_ARP");
    e->insert(ETHERTYPE_TRILL, "ETHERTYPE_TRILL");
    e->insert(ETHERTYPE_L2_ISIS, "ETHERTYPE_L2_ISIS");
    e->insert(ETHERTYPE_RARP, "ETHERTYPE_RARP");
    e->insert(ETHERTYPE_IPv6, "ETHERTYPE_IPv6");
    e->insert(ETHERTYPE_INET_GENERIC, "ETHERTYPE_INET_GENERIC");
    e->insert(ETHERTYPE_MPLS_UNICAST, "ETHERTYPE_MPLS_UNICAST");
    e->insert(ETHERTYPE_MPLS_MULTICAST, "ETHERTYPE_MPLS_MULTICAST");
)

Ieee802Ctrl_Base::Ieee802Ctrl_Base() : ::omnetpp::cObject()
{
    this->etherType = 0;
    this->interfaceId = 0;
    this->switchPort = -1;
    this->userPriority = -1;
    this->ssap = 0;
    this->dsap = 0;
    this->pauseUnits = 0;
}

Ieee802Ctrl_Base::Ieee802Ctrl_Base(const Ieee802Ctrl_Base& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ieee802Ctrl_Base::~Ieee802Ctrl_Base()
{
}

Ieee802Ctrl_Base& Ieee802Ctrl_Base::operator=(const Ieee802Ctrl_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ieee802Ctrl_Base::copy(const Ieee802Ctrl_Base& other)
{
    this->src = other.src;
    this->dest = other.dest;
    this->etherType = other.etherType;
    this->interfaceId = other.interfaceId;
    this->switchPort = other.switchPort;
    this->userPriority = other.userPriority;
    this->ssap = other.ssap;
    this->dsap = other.dsap;
    this->pauseUnits = other.pauseUnits;
}

void Ieee802Ctrl_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->src);
    doParsimPacking(b,this->dest);
    doParsimPacking(b,this->etherType);
    doParsimPacking(b,this->interfaceId);
    doParsimPacking(b,this->switchPort);
    doParsimPacking(b,this->userPriority);
    doParsimPacking(b,this->ssap);
    doParsimPacking(b,this->dsap);
    doParsimPacking(b,this->pauseUnits);
}

void Ieee802Ctrl_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->src);
    doParsimUnpacking(b,this->dest);
    doParsimUnpacking(b,this->etherType);
    doParsimUnpacking(b,this->interfaceId);
    doParsimUnpacking(b,this->switchPort);
    doParsimUnpacking(b,this->userPriority);
    doParsimUnpacking(b,this->ssap);
    doParsimUnpacking(b,this->dsap);
    doParsimUnpacking(b,this->pauseUnits);
}

MACAddress& Ieee802Ctrl_Base::getSrc()
{
    return this->src;
}

void Ieee802Ctrl_Base::setSrc(const MACAddress& src)
{
    this->src = src;
}

MACAddress& Ieee802Ctrl_Base::getDest()
{
    return this->dest;
}

void Ieee802Ctrl_Base::setDest(const MACAddress& dest)
{
    this->dest = dest;
}

int Ieee802Ctrl_Base::getEtherType() const
{
    return this->etherType;
}

void Ieee802Ctrl_Base::setEtherType(int etherType)
{
    this->etherType = etherType;
}

int Ieee802Ctrl_Base::getInterfaceId() const
{
    return this->interfaceId;
}

void Ieee802Ctrl_Base::setInterfaceId(int interfaceId)
{
    this->interfaceId = interfaceId;
}

int Ieee802Ctrl_Base::getSwitchPort() const
{
    return this->switchPort;
}

void Ieee802Ctrl_Base::setSwitchPort(int switchPort)
{
    this->switchPort = switchPort;
}

int Ieee802Ctrl_Base::getUserPriority() const
{
    return this->userPriority;
}

void Ieee802Ctrl_Base::setUserPriority(int userPriority)
{
    this->userPriority = userPriority;
}

int Ieee802Ctrl_Base::getSsap() const
{
    return this->ssap;
}

void Ieee802Ctrl_Base::setSsap(int ssap)
{
    this->ssap = ssap;
}

int Ieee802Ctrl_Base::getDsap() const
{
    return this->dsap;
}

void Ieee802Ctrl_Base::setDsap(int dsap)
{
    this->dsap = dsap;
}

int Ieee802Ctrl_Base::getPauseUnits() const
{
    return this->pauseUnits;
}

void Ieee802Ctrl_Base::setPauseUnits(int pauseUnits)
{
    this->pauseUnits = pauseUnits;
}

class Ieee802CtrlDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee802CtrlDescriptor();
    virtual ~Ieee802CtrlDescriptor();

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

Register_ClassDescriptor(Ieee802CtrlDescriptor)

Ieee802CtrlDescriptor::Ieee802CtrlDescriptor() : omnetpp::cClassDescriptor("inet::Ieee802Ctrl", "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ieee802CtrlDescriptor::~Ieee802CtrlDescriptor()
{
    delete[] propertynames;
}

bool Ieee802CtrlDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee802Ctrl_Base *>(obj)!=nullptr;
}

const char **Ieee802CtrlDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee802CtrlDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee802CtrlDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee802CtrlDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee802CtrlDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "src",
        "dest",
        "etherType",
        "interfaceId",
        "switchPort",
        "userPriority",
        "ssap",
        "dsap",
        "pauseUnits",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int Ieee802CtrlDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "src")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "dest")==0) return base+1;
    if (fieldName[0]=='e' && strcmp(fieldName, "etherType")==0) return base+2;
    if (fieldName[0]=='i' && strcmp(fieldName, "interfaceId")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "switchPort")==0) return base+4;
    if (fieldName[0]=='u' && strcmp(fieldName, "userPriority")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "ssap")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "dsap")==0) return base+7;
    if (fieldName[0]=='p' && strcmp(fieldName, "pauseUnits")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee802CtrlDescriptor::getFieldTypeString(int field) const
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
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee802CtrlDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee802CtrlDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2:
            if (!strcmp(propertyname,"enum")) return "inet::EtherType";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee802CtrlDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee802Ctrl_Base *pp = (Ieee802Ctrl_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee802CtrlDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee802Ctrl_Base *pp = (Ieee802Ctrl_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee802CtrlDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee802Ctrl_Base *pp = (Ieee802Ctrl_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSrc(); return out.str();}
        case 1: {std::stringstream out; out << pp->getDest(); return out.str();}
        case 2: return enum2string(pp->getEtherType(), "inet::EtherType");
        case 3: return long2string(pp->getInterfaceId());
        case 4: return long2string(pp->getSwitchPort());
        case 5: return long2string(pp->getUserPriority());
        case 6: return long2string(pp->getSsap());
        case 7: return long2string(pp->getDsap());
        case 8: return long2string(pp->getPauseUnits());
        default: return "";
    }
}

bool Ieee802CtrlDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee802Ctrl_Base *pp = (Ieee802Ctrl_Base *)object; (void)pp;
    switch (field) {
        case 2: pp->setEtherType((inet::EtherType)string2enum(value, "inet::EtherType")); return true;
        case 3: pp->setInterfaceId(string2long(value)); return true;
        case 4: pp->setSwitchPort(string2long(value)); return true;
        case 5: pp->setUserPriority(string2long(value)); return true;
        case 6: pp->setSsap(string2long(value)); return true;
        case 7: pp->setDsap(string2long(value)); return true;
        case 8: pp->setPauseUnits(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee802CtrlDescriptor::getFieldStructName(int field) const
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

void *Ieee802CtrlDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee802Ctrl_Base *pp = (Ieee802Ctrl_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getSrc()); break;
        case 1: return (void *)(&pp->getDest()); break;
        default: return nullptr;
    }
}

} // namespace inet

