//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/wiseroute/WiseRouteDatagram.msg.
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
#include "WiseRouteDatagram_m.h"

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

WiseRouteDatagram_Base::WiseRouteDatagram_Base(const char *name, short kind) : ::inet::NetworkDatagramBase(name,kind)
{
    this->seqNum = 0;
    this->isFlood = 0;
    this->nbHops = 0;
    this->transportProtocol = -1;
}

WiseRouteDatagram_Base::WiseRouteDatagram_Base(const WiseRouteDatagram_Base& other) : ::inet::NetworkDatagramBase(other)
{
    copy(other);
}

WiseRouteDatagram_Base::~WiseRouteDatagram_Base()
{
}

WiseRouteDatagram_Base& WiseRouteDatagram_Base::operator=(const WiseRouteDatagram_Base& other)
{
    if (this==&other) return *this;
    ::inet::NetworkDatagramBase::operator=(other);
    copy(other);
    return *this;
}

void WiseRouteDatagram_Base::copy(const WiseRouteDatagram_Base& other)
{
    this->seqNum = other.seqNum;
    this->isFlood = other.isFlood;
    this->nbHops = other.nbHops;
    this->transportProtocol = other.transportProtocol;
    this->finalDestAddr = other.finalDestAddr;
    this->initialSrcAddr = other.initialSrcAddr;
}

void WiseRouteDatagram_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::NetworkDatagramBase::parsimPack(b);
    doParsimPacking(b,this->seqNum);
    doParsimPacking(b,this->isFlood);
    doParsimPacking(b,this->nbHops);
    doParsimPacking(b,this->transportProtocol);
    doParsimPacking(b,this->finalDestAddr);
    doParsimPacking(b,this->initialSrcAddr);
}

void WiseRouteDatagram_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::NetworkDatagramBase::parsimUnpack(b);
    doParsimUnpacking(b,this->seqNum);
    doParsimUnpacking(b,this->isFlood);
    doParsimUnpacking(b,this->nbHops);
    doParsimUnpacking(b,this->transportProtocol);
    doParsimUnpacking(b,this->finalDestAddr);
    doParsimUnpacking(b,this->initialSrcAddr);
}

unsigned long WiseRouteDatagram_Base::getSeqNum() const
{
    return this->seqNum;
}

void WiseRouteDatagram_Base::setSeqNum(unsigned long seqNum)
{
    this->seqNum = seqNum;
}

int WiseRouteDatagram_Base::getIsFlood() const
{
    return this->isFlood;
}

void WiseRouteDatagram_Base::setIsFlood(int isFlood)
{
    this->isFlood = isFlood;
}

int WiseRouteDatagram_Base::getNbHops() const
{
    return this->nbHops;
}

void WiseRouteDatagram_Base::setNbHops(int nbHops)
{
    this->nbHops = nbHops;
}

int WiseRouteDatagram_Base::getTransportProtocol() const
{
    return this->transportProtocol;
}

void WiseRouteDatagram_Base::setTransportProtocol(int transportProtocol)
{
    this->transportProtocol = transportProtocol;
}

L3Address& WiseRouteDatagram_Base::getFinalDestAddr()
{
    return this->finalDestAddr;
}

void WiseRouteDatagram_Base::setFinalDestAddr(const L3Address& finalDestAddr)
{
    this->finalDestAddr = finalDestAddr;
}

L3Address& WiseRouteDatagram_Base::getInitialSrcAddr()
{
    return this->initialSrcAddr;
}

void WiseRouteDatagram_Base::setInitialSrcAddr(const L3Address& initialSrcAddr)
{
    this->initialSrcAddr = initialSrcAddr;
}

class WiseRouteDatagramDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    WiseRouteDatagramDescriptor();
    virtual ~WiseRouteDatagramDescriptor();

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

Register_ClassDescriptor(WiseRouteDatagramDescriptor)

WiseRouteDatagramDescriptor::WiseRouteDatagramDescriptor() : omnetpp::cClassDescriptor("inet::WiseRouteDatagram", "inet::NetworkDatagramBase")
{
    propertynames = nullptr;
}

WiseRouteDatagramDescriptor::~WiseRouteDatagramDescriptor()
{
    delete[] propertynames;
}

bool WiseRouteDatagramDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<WiseRouteDatagram_Base *>(obj)!=nullptr;
}

const char **WiseRouteDatagramDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *WiseRouteDatagramDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int WiseRouteDatagramDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 6+basedesc->getFieldCount() : 6;
}

unsigned int WiseRouteDatagramDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<6) ? fieldTypeFlags[field] : 0;
}

const char *WiseRouteDatagramDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "seqNum",
        "isFlood",
        "nbHops",
        "transportProtocol",
        "finalDestAddr",
        "initialSrcAddr",
    };
    return (field>=0 && field<6) ? fieldNames[field] : nullptr;
}

int WiseRouteDatagramDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "seqNum")==0) return base+0;
    if (fieldName[0]=='i' && strcmp(fieldName, "isFlood")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "nbHops")==0) return base+2;
    if (fieldName[0]=='t' && strcmp(fieldName, "transportProtocol")==0) return base+3;
    if (fieldName[0]=='f' && strcmp(fieldName, "finalDestAddr")==0) return base+4;
    if (fieldName[0]=='i' && strcmp(fieldName, "initialSrcAddr")==0) return base+5;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *WiseRouteDatagramDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned long",
        "int",
        "int",
        "int",
        "L3Address",
        "L3Address",
    };
    return (field>=0 && field<6) ? fieldTypeStrings[field] : nullptr;
}

const char **WiseRouteDatagramDescriptor::getFieldPropertyNames(int field) const
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

const char *WiseRouteDatagramDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int WiseRouteDatagramDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    WiseRouteDatagram_Base *pp = (WiseRouteDatagram_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *WiseRouteDatagramDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WiseRouteDatagram_Base *pp = (WiseRouteDatagram_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string WiseRouteDatagramDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    WiseRouteDatagram_Base *pp = (WiseRouteDatagram_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSeqNum());
        case 1: return long2string(pp->getIsFlood());
        case 2: return long2string(pp->getNbHops());
        case 3: return long2string(pp->getTransportProtocol());
        case 4: {std::stringstream out; out << pp->getFinalDestAddr(); return out.str();}
        case 5: {std::stringstream out; out << pp->getInitialSrcAddr(); return out.str();}
        default: return "";
    }
}

bool WiseRouteDatagramDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    WiseRouteDatagram_Base *pp = (WiseRouteDatagram_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSeqNum(string2ulong(value)); return true;
        case 1: pp->setIsFlood(string2long(value)); return true;
        case 2: pp->setNbHops(string2long(value)); return true;
        case 3: pp->setTransportProtocol(string2long(value)); return true;
        default: return false;
    }
}

const char *WiseRouteDatagramDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 4: return omnetpp::opp_typename(typeid(L3Address));
        case 5: return omnetpp::opp_typename(typeid(L3Address));
        default: return nullptr;
    };
}

void *WiseRouteDatagramDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    WiseRouteDatagram_Base *pp = (WiseRouteDatagram_Base *)object; (void)pp;
    switch (field) {
        case 4: return (void *)(&pp->getFinalDestAddr()); break;
        case 5: return (void *)(&pp->getInitialSrcAddr()); break;
        default: return nullptr;
    }
}

} // namespace inet

