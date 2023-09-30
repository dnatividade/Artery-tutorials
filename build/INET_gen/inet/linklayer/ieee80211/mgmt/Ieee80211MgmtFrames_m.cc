//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/linklayer/ieee80211/mgmt/Ieee80211MgmtFrames.msg.
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
#include "Ieee80211MgmtFrames_m.h"

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

Ieee80211CapabilityInformation::Ieee80211CapabilityInformation()
{
    this->ESS = false;
    this->IBSS = false;
    this->CFPollable = false;
    this->CFPollRequest = false;
    this->privacy = false;
    this->DelayedBlockAck = false;
    this->InmediateBlockAck = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const Ieee80211CapabilityInformation& a)
{
    doParsimPacking(b,a.ESS);
    doParsimPacking(b,a.IBSS);
    doParsimPacking(b,a.CFPollable);
    doParsimPacking(b,a.CFPollRequest);
    doParsimPacking(b,a.privacy);
    doParsimPacking(b,a.DelayedBlockAck);
    doParsimPacking(b,a.InmediateBlockAck);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ieee80211CapabilityInformation& a)
{
    doParsimUnpacking(b,a.ESS);
    doParsimUnpacking(b,a.IBSS);
    doParsimUnpacking(b,a.CFPollable);
    doParsimUnpacking(b,a.CFPollRequest);
    doParsimUnpacking(b,a.privacy);
    doParsimUnpacking(b,a.DelayedBlockAck);
    doParsimUnpacking(b,a.InmediateBlockAck);
}

class Ieee80211CapabilityInformationDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211CapabilityInformationDescriptor();
    virtual ~Ieee80211CapabilityInformationDescriptor();

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

Register_ClassDescriptor(Ieee80211CapabilityInformationDescriptor)

Ieee80211CapabilityInformationDescriptor::Ieee80211CapabilityInformationDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211CapabilityInformation", "")
{
    propertynames = nullptr;
}

Ieee80211CapabilityInformationDescriptor::~Ieee80211CapabilityInformationDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211CapabilityInformationDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211CapabilityInformation *>(obj)!=nullptr;
}

const char **Ieee80211CapabilityInformationDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211CapabilityInformationDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211CapabilityInformationDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 7+basedesc->getFieldCount() : 7;
}

unsigned int Ieee80211CapabilityInformationDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211CapabilityInformationDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ESS",
        "IBSS",
        "CFPollable",
        "CFPollRequest",
        "privacy",
        "DelayedBlockAck",
        "InmediateBlockAck",
    };
    return (field>=0 && field<7) ? fieldNames[field] : nullptr;
}

int Ieee80211CapabilityInformationDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='E' && strcmp(fieldName, "ESS")==0) return base+0;
    if (fieldName[0]=='I' && strcmp(fieldName, "IBSS")==0) return base+1;
    if (fieldName[0]=='C' && strcmp(fieldName, "CFPollable")==0) return base+2;
    if (fieldName[0]=='C' && strcmp(fieldName, "CFPollRequest")==0) return base+3;
    if (fieldName[0]=='p' && strcmp(fieldName, "privacy")==0) return base+4;
    if (fieldName[0]=='D' && strcmp(fieldName, "DelayedBlockAck")==0) return base+5;
    if (fieldName[0]=='I' && strcmp(fieldName, "InmediateBlockAck")==0) return base+6;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211CapabilityInformationDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<7) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211CapabilityInformationDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211CapabilityInformationDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211CapabilityInformationDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211CapabilityInformationDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211CapabilityInformationDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->ESS);
        case 1: return bool2string(pp->IBSS);
        case 2: return bool2string(pp->CFPollable);
        case 3: return bool2string(pp->CFPollRequest);
        case 4: return bool2string(pp->privacy);
        case 5: return bool2string(pp->DelayedBlockAck);
        case 6: return bool2string(pp->InmediateBlockAck);
        default: return "";
    }
}

bool Ieee80211CapabilityInformationDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        case 0: pp->ESS = string2bool(value); return true;
        case 1: pp->IBSS = string2bool(value); return true;
        case 2: pp->CFPollable = string2bool(value); return true;
        case 3: pp->CFPollRequest = string2bool(value); return true;
        case 4: pp->privacy = string2bool(value); return true;
        case 5: pp->DelayedBlockAck = string2bool(value); return true;
        case 6: pp->InmediateBlockAck = string2bool(value); return true;
        default: return false;
    }
}

const char *Ieee80211CapabilityInformationDescriptor::getFieldStructName(int field) const
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

void *Ieee80211CapabilityInformationDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211CapabilityInformation *pp = (Ieee80211CapabilityInformation *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Ieee80211HandoverParameters::Ieee80211HandoverParameters()
{
    this->avgBackoffTime = 0;
    this->avgWaitTime = 0;
    this->avgErrorRate = 0;
    this->estAvailBW = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const Ieee80211HandoverParameters& a)
{
    doParsimPacking(b,a.avgBackoffTime);
    doParsimPacking(b,a.avgWaitTime);
    doParsimPacking(b,a.avgErrorRate);
    doParsimPacking(b,a.estAvailBW);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ieee80211HandoverParameters& a)
{
    doParsimUnpacking(b,a.avgBackoffTime);
    doParsimUnpacking(b,a.avgWaitTime);
    doParsimUnpacking(b,a.avgErrorRate);
    doParsimUnpacking(b,a.estAvailBW);
}

class Ieee80211HandoverParametersDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211HandoverParametersDescriptor();
    virtual ~Ieee80211HandoverParametersDescriptor();

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

Register_ClassDescriptor(Ieee80211HandoverParametersDescriptor)

Ieee80211HandoverParametersDescriptor::Ieee80211HandoverParametersDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211HandoverParameters", "")
{
    propertynames = nullptr;
}

Ieee80211HandoverParametersDescriptor::~Ieee80211HandoverParametersDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211HandoverParametersDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211HandoverParameters *>(obj)!=nullptr;
}

const char **Ieee80211HandoverParametersDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211HandoverParametersDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211HandoverParametersDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int Ieee80211HandoverParametersDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211HandoverParametersDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "avgBackoffTime",
        "avgWaitTime",
        "avgErrorRate",
        "estAvailBW",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int Ieee80211HandoverParametersDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='a' && strcmp(fieldName, "avgBackoffTime")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "avgWaitTime")==0) return base+1;
    if (fieldName[0]=='a' && strcmp(fieldName, "avgErrorRate")==0) return base+2;
    if (fieldName[0]=='e' && strcmp(fieldName, "estAvailBW")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211HandoverParametersDescriptor::getFieldTypeString(int field) const
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
        "double",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211HandoverParametersDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211HandoverParametersDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211HandoverParametersDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211HandoverParametersDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211HandoverParametersDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        case 0: return double2string(pp->avgBackoffTime);
        case 1: return double2string(pp->avgWaitTime);
        case 2: return double2string(pp->avgErrorRate);
        case 3: return double2string(pp->estAvailBW);
        default: return "";
    }
}

bool Ieee80211HandoverParametersDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        case 0: pp->avgBackoffTime = string2double(value); return true;
        case 1: pp->avgWaitTime = string2double(value); return true;
        case 2: pp->avgErrorRate = string2double(value); return true;
        case 3: pp->estAvailBW = string2double(value); return true;
        default: return false;
    }
}

const char *Ieee80211HandoverParametersDescriptor::getFieldStructName(int field) const
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

void *Ieee80211HandoverParametersDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211HandoverParameters *pp = (Ieee80211HandoverParameters *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211ReasonCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211ReasonCode"));
    e->insert(RC_UNSPECIFIED, "RC_UNSPECIFIED");
    e->insert(RC_PREV_AUTH_EXPIRED, "RC_PREV_AUTH_EXPIRED");
    e->insert(RC_DEAUTH_MS_LEAVING, "RC_DEAUTH_MS_LEAVING");
    e->insert(RC_DISASS_INACTIVITY, "RC_DISASS_INACTIVITY");
    e->insert(RC_DISASS_TOO_MANY_MS, "RC_DISASS_TOO_MANY_MS");
    e->insert(RC_NONAUTH_CLASS2, "RC_NONAUTH_CLASS2");
    e->insert(RC_NONASS_CLASS3, "RC_NONASS_CLASS3");
    e->insert(RC_DIASS_MS_LEAVING, "RC_DIASS_MS_LEAVING");
    e->insert(RC_NONAUTH_ASS_REQUEST, "RC_NONAUTH_ASS_REQUEST");
    e->insert(RC_MESH_PEERING_CANCELLED, "RC_MESH_PEERING_CANCELLED");
    e->insert(RC_MESH_MAX_PEERS, "RC_MESH_MAX_PEERS");
    e->insert(RC_MESH_CONFIGURATION_POLICY_VIOLATION, "RC_MESH_CONFIGURATION_POLICY_VIOLATION");
    e->insert(RC_MESH_CLOSE_RCVD, "RC_MESH_CLOSE_RCVD");
    e->insert(RC_MESH_MAX_RETRIES, "RC_MESH_MAX_RETRIES");
    e->insert(RC_MESH_CONFIRM_TIMEOUT, "RC_MESH_CONFIRM_TIMEOUT");
    e->insert(RC_MESH_INVALID_GTK, "RC_MESH_INVALID_GTK");
    e->insert(RC_MESH_INCONSISTENT_PARAMETERS, "RC_MESH_INCONSISTENT_PARAMETERS");
    e->insert(RC_MESH_INVALID_SECURITY_CAPABILITY, "RC_MESH_INVALID_SECURITY_CAPABILITY");
    e->insert(RC_MESH_PATH_ERROR_NO_PROXY_INFORMATION, "RC_MESH_PATH_ERROR_NO_PROXY_INFORMATION");
    e->insert(RC_MESH_PATH_ERROR_NO_FORWARDING_INFORMATION, "RC_MESH_PATH_ERROR_NO_FORWARDING_INFORMATION");
    e->insert(RC_MESH_PATH_ERROR_DESTINATION_UNREACHABLE, "RC_MESH_PATH_ERROR_DESTINATION_UNREACHABLE");
    e->insert(RC_MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS, "RC_MAC_ADDRESS_ALREADY_EXISTS_IN_MBSS");
    e->insert(RC_MESH_CHANNEL_SWITCH_REGULATORY_REQUIREMENTS, "RC_MESH_CHANNEL_SWITCH_REGULATORY_REQUIREMENTS");
    e->insert(RC_MESH_CHANNEL_SWITCH_UNSPECIFIED, "RC_MESH_CHANNEL_SWITCH_UNSPECIFIED");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211StatusCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211StatusCode"));
    e->insert(SC_SUCCESSFUL, "SC_SUCCESSFUL");
    e->insert(SC_UNSPECIFIED, "SC_UNSPECIFIED");
    e->insert(SC_UNSUP_CAP, "SC_UNSUP_CAP");
    e->insert(SC_REASS_DENIED, "SC_REASS_DENIED");
    e->insert(SC_ASS_DENIED_UNKNOWN, "SC_ASS_DENIED_UNKNOWN");
    e->insert(SC_AUTH_ALG0_UNSUP, "SC_AUTH_ALG0_UNSUP");
    e->insert(SC_AUTH_OUT_OF_SEQ, "SC_AUTH_OUT_OF_SEQ");
    e->insert(SC_AUTH_CHALLENGE_FAIL, "SC_AUTH_CHALLENGE_FAIL");
    e->insert(SC_AUTH_TIMEOUT, "SC_AUTH_TIMEOUT");
    e->insert(SC_ASS_TOO_MANY_MS, "SC_ASS_TOO_MANY_MS");
    e->insert(SC_DATARATE_UNSUP, "SC_DATARATE_UNSUP");
    e->insert(SC_AUTH_REJECT_ANTI_CLOGING, "SC_AUTH_REJECT_ANTI_CLOGING");
    e->insert(SC_AUTH_REJECT_FINITE_CYC_GROUP_UNS, "SC_AUTH_REJECT_FINITE_CYC_GROUP_UNS");
    e->insert(SC_TBTT_REQUEST, "SC_TBTT_REQUEST");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::ieee80211::Ieee80211HWMPCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::ieee80211::Ieee80211HWMPCode"));
    e->insert(IE11S_GANN, "IE11S_GANN");
    e->insert(IE11S_RANN, "IE11S_RANN");
    e->insert(IE11S_PREQ, "IE11S_PREQ");
    e->insert(IE11S_PREP, "IE11S_PREP");
    e->insert(IE11S_PERR, "IE11S_PERR");
)

Ieee80211SupportedRatesElement::Ieee80211SupportedRatesElement()
{
    this->numRates = 0;
    for (unsigned int i=0; i<8; i++)
        this->rate[i] = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const Ieee80211SupportedRatesElement& a)
{
    doParsimPacking(b,a.numRates);
    doParsimArrayPacking(b,a.rate,8);
}

void __doUnpacking(omnetpp::cCommBuffer *b, Ieee80211SupportedRatesElement& a)
{
    doParsimUnpacking(b,a.numRates);
    doParsimArrayUnpacking(b,a.rate,8);
}

class Ieee80211SupportedRatesElementDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211SupportedRatesElementDescriptor();
    virtual ~Ieee80211SupportedRatesElementDescriptor();

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

Register_ClassDescriptor(Ieee80211SupportedRatesElementDescriptor)

Ieee80211SupportedRatesElementDescriptor::Ieee80211SupportedRatesElementDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211SupportedRatesElement", "")
{
    propertynames = nullptr;
}

Ieee80211SupportedRatesElementDescriptor::~Ieee80211SupportedRatesElementDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211SupportedRatesElementDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211SupportedRatesElement *>(obj)!=nullptr;
}

const char **Ieee80211SupportedRatesElementDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211SupportedRatesElementDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211SupportedRatesElementDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211SupportedRatesElementDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211SupportedRatesElementDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "numRates",
        "rate",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int Ieee80211SupportedRatesElementDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numRates")==0) return base+0;
    if (fieldName[0]=='r' && strcmp(fieldName, "rate")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211SupportedRatesElementDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "double",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211SupportedRatesElementDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211SupportedRatesElementDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211SupportedRatesElementDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        case 1: return 8;
        default: return 0;
    }
}

const char *Ieee80211SupportedRatesElementDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211SupportedRatesElementDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->numRates);
        case 1: if (i>=8) return "";
                return double2string(pp->rate[i]);
        default: return "";
    }
}

bool Ieee80211SupportedRatesElementDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        case 0: pp->numRates = string2long(value); return true;
        case 1: if (i>=8) return false;
                pp->rate[i] = string2double(value); return true;
        default: return false;
    }
}

const char *Ieee80211SupportedRatesElementDescriptor::getFieldStructName(int field) const
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

void *Ieee80211SupportedRatesElementDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211SupportedRatesElement *pp = (Ieee80211SupportedRatesElement *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211FrameBody)

Ieee80211FrameBody::Ieee80211FrameBody() : ::omnetpp::cObject()
{
    this->bodyLength = 0;
}

Ieee80211FrameBody::Ieee80211FrameBody(const Ieee80211FrameBody& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

Ieee80211FrameBody::~Ieee80211FrameBody()
{
}

Ieee80211FrameBody& Ieee80211FrameBody::operator=(const Ieee80211FrameBody& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211FrameBody::copy(const Ieee80211FrameBody& other)
{
    this->bodyLength = other.bodyLength;
}

void Ieee80211FrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->bodyLength);
}

void Ieee80211FrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->bodyLength);
}

short Ieee80211FrameBody::getBodyLength() const
{
    return this->bodyLength;
}

void Ieee80211FrameBody::setBodyLength(short bodyLength)
{
    this->bodyLength = bodyLength;
}

class Ieee80211FrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211FrameBodyDescriptor();
    virtual ~Ieee80211FrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211FrameBodyDescriptor)

Ieee80211FrameBodyDescriptor::Ieee80211FrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211FrameBody", "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ieee80211FrameBodyDescriptor::~Ieee80211FrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211FrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211FrameBody *>(obj)!=nullptr;
}

const char **Ieee80211FrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211FrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211FrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211FrameBodyDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211FrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bodyLength",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211FrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bodyLength")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211FrameBodyDescriptor::getFieldTypeString(int field) const
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

const char **Ieee80211FrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211FrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211FrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FrameBody *pp = (Ieee80211FrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211FrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FrameBody *pp = (Ieee80211FrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211FrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FrameBody *pp = (Ieee80211FrameBody *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getBodyLength());
        default: return "";
    }
}

bool Ieee80211FrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FrameBody *pp = (Ieee80211FrameBody *)object; (void)pp;
    switch (field) {
        case 0: pp->setBodyLength(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211FrameBodyDescriptor::getFieldStructName(int field) const
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

void *Ieee80211FrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211FrameBody *pp = (Ieee80211FrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211AuthenticationFrameBody)

Ieee80211AuthenticationFrameBody::Ieee80211AuthenticationFrameBody() : ::inet::ieee80211::Ieee80211FrameBody()
{
    this->setBodyLength(6);

    this->sequenceNumber = 0;
    this->statusCode = 0;
    this->isLast = false;
}

Ieee80211AuthenticationFrameBody::Ieee80211AuthenticationFrameBody(const Ieee80211AuthenticationFrameBody& other) : ::inet::ieee80211::Ieee80211FrameBody(other)
{
    copy(other);
}

Ieee80211AuthenticationFrameBody::~Ieee80211AuthenticationFrameBody()
{
}

Ieee80211AuthenticationFrameBody& Ieee80211AuthenticationFrameBody::operator=(const Ieee80211AuthenticationFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211FrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AuthenticationFrameBody::copy(const Ieee80211AuthenticationFrameBody& other)
{
    this->sequenceNumber = other.sequenceNumber;
    this->statusCode = other.statusCode;
    this->isLast = other.isLast;
}

void Ieee80211AuthenticationFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimPack(b);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->statusCode);
    doParsimPacking(b,this->isLast);
}

void Ieee80211AuthenticationFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimUnpack(b);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->statusCode);
    doParsimUnpacking(b,this->isLast);
}

unsigned short Ieee80211AuthenticationFrameBody::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void Ieee80211AuthenticationFrameBody::setSequenceNumber(unsigned short sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

int Ieee80211AuthenticationFrameBody::getStatusCode() const
{
    return this->statusCode;
}

void Ieee80211AuthenticationFrameBody::setStatusCode(int statusCode)
{
    this->statusCode = statusCode;
}

bool Ieee80211AuthenticationFrameBody::getIsLast() const
{
    return this->isLast;
}

void Ieee80211AuthenticationFrameBody::setIsLast(bool isLast)
{
    this->isLast = isLast;
}

class Ieee80211AuthenticationFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AuthenticationFrameBodyDescriptor();
    virtual ~Ieee80211AuthenticationFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211AuthenticationFrameBodyDescriptor)

Ieee80211AuthenticationFrameBodyDescriptor::Ieee80211AuthenticationFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AuthenticationFrameBody", "inet::ieee80211::Ieee80211FrameBody")
{
    propertynames = nullptr;
}

Ieee80211AuthenticationFrameBodyDescriptor::~Ieee80211AuthenticationFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AuthenticationFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AuthenticationFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211AuthenticationFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AuthenticationFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AuthenticationFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211AuthenticationFrameBodyDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211AuthenticationFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sequenceNumber",
        "statusCode",
        "isLast",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211AuthenticationFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "statusCode")==0) return base+1;
    if (fieldName[0]=='i' && strcmp(fieldName, "isLast")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AuthenticationFrameBodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "int",
        "bool",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AuthenticationFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AuthenticationFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "inet::ieee80211::Ieee80211StatusCode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211AuthenticationFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrameBody *pp = (Ieee80211AuthenticationFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AuthenticationFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrameBody *pp = (Ieee80211AuthenticationFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AuthenticationFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrameBody *pp = (Ieee80211AuthenticationFrameBody *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSequenceNumber());
        case 1: return enum2string(pp->getStatusCode(), "inet::ieee80211::Ieee80211StatusCode");
        case 2: return bool2string(pp->getIsLast());
        default: return "";
    }
}

bool Ieee80211AuthenticationFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrameBody *pp = (Ieee80211AuthenticationFrameBody *)object; (void)pp;
    switch (field) {
        case 0: pp->setSequenceNumber(string2ulong(value)); return true;
        case 1: pp->setStatusCode((inet::ieee80211::Ieee80211StatusCode)string2enum(value, "inet::ieee80211::Ieee80211StatusCode")); return true;
        case 2: pp->setIsLast(string2bool(value)); return true;
        default: return false;
    }
}

const char *Ieee80211AuthenticationFrameBodyDescriptor::getFieldStructName(int field) const
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

void *Ieee80211AuthenticationFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrameBody *pp = (Ieee80211AuthenticationFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DeauthenticationFrameBody)

Ieee80211DeauthenticationFrameBody::Ieee80211DeauthenticationFrameBody() : ::inet::ieee80211::Ieee80211FrameBody()
{
    this->setBodyLength(2);

    this->reasonCode = 0;
}

Ieee80211DeauthenticationFrameBody::Ieee80211DeauthenticationFrameBody(const Ieee80211DeauthenticationFrameBody& other) : ::inet::ieee80211::Ieee80211FrameBody(other)
{
    copy(other);
}

Ieee80211DeauthenticationFrameBody::~Ieee80211DeauthenticationFrameBody()
{
}

Ieee80211DeauthenticationFrameBody& Ieee80211DeauthenticationFrameBody::operator=(const Ieee80211DeauthenticationFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211FrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DeauthenticationFrameBody::copy(const Ieee80211DeauthenticationFrameBody& other)
{
    this->reasonCode = other.reasonCode;
}

void Ieee80211DeauthenticationFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimPack(b);
    doParsimPacking(b,this->reasonCode);
}

void Ieee80211DeauthenticationFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimUnpack(b);
    doParsimUnpacking(b,this->reasonCode);
}

int Ieee80211DeauthenticationFrameBody::getReasonCode() const
{
    return this->reasonCode;
}

void Ieee80211DeauthenticationFrameBody::setReasonCode(int reasonCode)
{
    this->reasonCode = reasonCode;
}

class Ieee80211DeauthenticationFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DeauthenticationFrameBodyDescriptor();
    virtual ~Ieee80211DeauthenticationFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211DeauthenticationFrameBodyDescriptor)

Ieee80211DeauthenticationFrameBodyDescriptor::Ieee80211DeauthenticationFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DeauthenticationFrameBody", "inet::ieee80211::Ieee80211FrameBody")
{
    propertynames = nullptr;
}

Ieee80211DeauthenticationFrameBodyDescriptor::~Ieee80211DeauthenticationFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DeauthenticationFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DeauthenticationFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211DeauthenticationFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DeauthenticationFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DeauthenticationFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211DeauthenticationFrameBodyDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211DeauthenticationFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reasonCode",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211DeauthenticationFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "reasonCode")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DeauthenticationFrameBodyDescriptor::getFieldTypeString(int field) const
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

const char **Ieee80211DeauthenticationFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DeauthenticationFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ieee80211::Ieee80211ReasonCode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DeauthenticationFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrameBody *pp = (Ieee80211DeauthenticationFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DeauthenticationFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrameBody *pp = (Ieee80211DeauthenticationFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DeauthenticationFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrameBody *pp = (Ieee80211DeauthenticationFrameBody *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getReasonCode(), "inet::ieee80211::Ieee80211ReasonCode");
        default: return "";
    }
}

bool Ieee80211DeauthenticationFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrameBody *pp = (Ieee80211DeauthenticationFrameBody *)object; (void)pp;
    switch (field) {
        case 0: pp->setReasonCode((inet::ieee80211::Ieee80211ReasonCode)string2enum(value, "inet::ieee80211::Ieee80211ReasonCode")); return true;
        default: return false;
    }
}

const char *Ieee80211DeauthenticationFrameBodyDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DeauthenticationFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrameBody *pp = (Ieee80211DeauthenticationFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211DisassociationFrameBody)

Ieee80211DisassociationFrameBody::Ieee80211DisassociationFrameBody() : ::inet::ieee80211::Ieee80211FrameBody()
{
    this->setBodyLength(2);

    this->reasonCode = 0;
}

Ieee80211DisassociationFrameBody::Ieee80211DisassociationFrameBody(const Ieee80211DisassociationFrameBody& other) : ::inet::ieee80211::Ieee80211FrameBody(other)
{
    copy(other);
}

Ieee80211DisassociationFrameBody::~Ieee80211DisassociationFrameBody()
{
}

Ieee80211DisassociationFrameBody& Ieee80211DisassociationFrameBody::operator=(const Ieee80211DisassociationFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211FrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DisassociationFrameBody::copy(const Ieee80211DisassociationFrameBody& other)
{
    this->reasonCode = other.reasonCode;
}

void Ieee80211DisassociationFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimPack(b);
    doParsimPacking(b,this->reasonCode);
}

void Ieee80211DisassociationFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimUnpack(b);
    doParsimUnpacking(b,this->reasonCode);
}

int Ieee80211DisassociationFrameBody::getReasonCode() const
{
    return this->reasonCode;
}

void Ieee80211DisassociationFrameBody::setReasonCode(int reasonCode)
{
    this->reasonCode = reasonCode;
}

class Ieee80211DisassociationFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DisassociationFrameBodyDescriptor();
    virtual ~Ieee80211DisassociationFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211DisassociationFrameBodyDescriptor)

Ieee80211DisassociationFrameBodyDescriptor::Ieee80211DisassociationFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DisassociationFrameBody", "inet::ieee80211::Ieee80211FrameBody")
{
    propertynames = nullptr;
}

Ieee80211DisassociationFrameBodyDescriptor::~Ieee80211DisassociationFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DisassociationFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DisassociationFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211DisassociationFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DisassociationFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DisassociationFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211DisassociationFrameBodyDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211DisassociationFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "reasonCode",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211DisassociationFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='r' && strcmp(fieldName, "reasonCode")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DisassociationFrameBodyDescriptor::getFieldTypeString(int field) const
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

const char **Ieee80211DisassociationFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DisassociationFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ieee80211::Ieee80211ReasonCode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211DisassociationFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrameBody *pp = (Ieee80211DisassociationFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DisassociationFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrameBody *pp = (Ieee80211DisassociationFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DisassociationFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrameBody *pp = (Ieee80211DisassociationFrameBody *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getReasonCode(), "inet::ieee80211::Ieee80211ReasonCode");
        default: return "";
    }
}

bool Ieee80211DisassociationFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrameBody *pp = (Ieee80211DisassociationFrameBody *)object; (void)pp;
    switch (field) {
        case 0: pp->setReasonCode((inet::ieee80211::Ieee80211ReasonCode)string2enum(value, "inet::ieee80211::Ieee80211ReasonCode")); return true;
        default: return false;
    }
}

const char *Ieee80211DisassociationFrameBodyDescriptor::getFieldStructName(int field) const
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

void *Ieee80211DisassociationFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrameBody *pp = (Ieee80211DisassociationFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ProbeRequestFrameBody)

Ieee80211ProbeRequestFrameBody::Ieee80211ProbeRequestFrameBody() : ::inet::ieee80211::Ieee80211FrameBody()
{
    this->setBodyLength(12);

}

Ieee80211ProbeRequestFrameBody::Ieee80211ProbeRequestFrameBody(const Ieee80211ProbeRequestFrameBody& other) : ::inet::ieee80211::Ieee80211FrameBody(other)
{
    copy(other);
}

Ieee80211ProbeRequestFrameBody::~Ieee80211ProbeRequestFrameBody()
{
}

Ieee80211ProbeRequestFrameBody& Ieee80211ProbeRequestFrameBody::operator=(const Ieee80211ProbeRequestFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211FrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ProbeRequestFrameBody::copy(const Ieee80211ProbeRequestFrameBody& other)
{
    this->SSID = other.SSID;
    this->supportedRates = other.supportedRates;
}

void Ieee80211ProbeRequestFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimPack(b);
    doParsimPacking(b,this->SSID);
    doParsimPacking(b,this->supportedRates);
}

void Ieee80211ProbeRequestFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimUnpack(b);
    doParsimUnpacking(b,this->SSID);
    doParsimUnpacking(b,this->supportedRates);
}

const char * Ieee80211ProbeRequestFrameBody::getSSID() const
{
    return this->SSID.c_str();
}

void Ieee80211ProbeRequestFrameBody::setSSID(const char * SSID)
{
    this->SSID = SSID;
}

Ieee80211SupportedRatesElement& Ieee80211ProbeRequestFrameBody::getSupportedRates()
{
    return this->supportedRates;
}

void Ieee80211ProbeRequestFrameBody::setSupportedRates(const Ieee80211SupportedRatesElement& supportedRates)
{
    this->supportedRates = supportedRates;
}

class Ieee80211ProbeRequestFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ProbeRequestFrameBodyDescriptor();
    virtual ~Ieee80211ProbeRequestFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211ProbeRequestFrameBodyDescriptor)

Ieee80211ProbeRequestFrameBodyDescriptor::Ieee80211ProbeRequestFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ProbeRequestFrameBody", "inet::ieee80211::Ieee80211FrameBody")
{
    propertynames = nullptr;
}

Ieee80211ProbeRequestFrameBodyDescriptor::~Ieee80211ProbeRequestFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ProbeRequestFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ProbeRequestFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211ProbeRequestFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ProbeRequestFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ProbeRequestFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211ProbeRequestFrameBodyDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ProbeRequestFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SSID",
        "supportedRates",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int Ieee80211ProbeRequestFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SSID")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "supportedRates")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ProbeRequestFrameBodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "Ieee80211SupportedRatesElement",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ProbeRequestFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ProbeRequestFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ProbeRequestFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrameBody *pp = (Ieee80211ProbeRequestFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ProbeRequestFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrameBody *pp = (Ieee80211ProbeRequestFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ProbeRequestFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrameBody *pp = (Ieee80211ProbeRequestFrameBody *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSSID());
        case 1: {std::stringstream out; out << pp->getSupportedRates(); return out.str();}
        default: return "";
    }
}

bool Ieee80211ProbeRequestFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrameBody *pp = (Ieee80211ProbeRequestFrameBody *)object; (void)pp;
    switch (field) {
        case 0: pp->setSSID((value)); return true;
        default: return false;
    }
}

const char *Ieee80211ProbeRequestFrameBodyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(Ieee80211SupportedRatesElement));
        default: return nullptr;
    };
}

void *Ieee80211ProbeRequestFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrameBody *pp = (Ieee80211ProbeRequestFrameBody *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getSupportedRates()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AssociationRequestFrameBody)

Ieee80211AssociationRequestFrameBody::Ieee80211AssociationRequestFrameBody() : ::inet::ieee80211::Ieee80211FrameBody()
{
    this->setBodyLength(16);

}

Ieee80211AssociationRequestFrameBody::Ieee80211AssociationRequestFrameBody(const Ieee80211AssociationRequestFrameBody& other) : ::inet::ieee80211::Ieee80211FrameBody(other)
{
    copy(other);
}

Ieee80211AssociationRequestFrameBody::~Ieee80211AssociationRequestFrameBody()
{
}

Ieee80211AssociationRequestFrameBody& Ieee80211AssociationRequestFrameBody::operator=(const Ieee80211AssociationRequestFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211FrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AssociationRequestFrameBody::copy(const Ieee80211AssociationRequestFrameBody& other)
{
    this->SSID = other.SSID;
    this->supportedRates = other.supportedRates;
}

void Ieee80211AssociationRequestFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimPack(b);
    doParsimPacking(b,this->SSID);
    doParsimPacking(b,this->supportedRates);
}

void Ieee80211AssociationRequestFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimUnpack(b);
    doParsimUnpacking(b,this->SSID);
    doParsimUnpacking(b,this->supportedRates);
}

const char * Ieee80211AssociationRequestFrameBody::getSSID() const
{
    return this->SSID.c_str();
}

void Ieee80211AssociationRequestFrameBody::setSSID(const char * SSID)
{
    this->SSID = SSID;
}

Ieee80211SupportedRatesElement& Ieee80211AssociationRequestFrameBody::getSupportedRates()
{
    return this->supportedRates;
}

void Ieee80211AssociationRequestFrameBody::setSupportedRates(const Ieee80211SupportedRatesElement& supportedRates)
{
    this->supportedRates = supportedRates;
}

class Ieee80211AssociationRequestFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AssociationRequestFrameBodyDescriptor();
    virtual ~Ieee80211AssociationRequestFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211AssociationRequestFrameBodyDescriptor)

Ieee80211AssociationRequestFrameBodyDescriptor::Ieee80211AssociationRequestFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AssociationRequestFrameBody", "inet::ieee80211::Ieee80211FrameBody")
{
    propertynames = nullptr;
}

Ieee80211AssociationRequestFrameBodyDescriptor::~Ieee80211AssociationRequestFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AssociationRequestFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AssociationRequestFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211AssociationRequestFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AssociationRequestFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AssociationRequestFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int Ieee80211AssociationRequestFrameBodyDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AssociationRequestFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SSID",
        "supportedRates",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int Ieee80211AssociationRequestFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SSID")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "supportedRates")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AssociationRequestFrameBodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "Ieee80211SupportedRatesElement",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AssociationRequestFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AssociationRequestFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AssociationRequestFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrameBody *pp = (Ieee80211AssociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AssociationRequestFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrameBody *pp = (Ieee80211AssociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AssociationRequestFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrameBody *pp = (Ieee80211AssociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSSID());
        case 1: {std::stringstream out; out << pp->getSupportedRates(); return out.str();}
        default: return "";
    }
}

bool Ieee80211AssociationRequestFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrameBody *pp = (Ieee80211AssociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        case 0: pp->setSSID((value)); return true;
        default: return false;
    }
}

const char *Ieee80211AssociationRequestFrameBodyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(Ieee80211SupportedRatesElement));
        default: return nullptr;
    };
}

void *Ieee80211AssociationRequestFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrameBody *pp = (Ieee80211AssociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getSupportedRates()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ReassociationRequestFrameBody)

Ieee80211ReassociationRequestFrameBody::Ieee80211ReassociationRequestFrameBody() : ::inet::ieee80211::Ieee80211AssociationRequestFrameBody()
{
    this->setBodyLength(26);

}

Ieee80211ReassociationRequestFrameBody::Ieee80211ReassociationRequestFrameBody(const Ieee80211ReassociationRequestFrameBody& other) : ::inet::ieee80211::Ieee80211AssociationRequestFrameBody(other)
{
    copy(other);
}

Ieee80211ReassociationRequestFrameBody::~Ieee80211ReassociationRequestFrameBody()
{
}

Ieee80211ReassociationRequestFrameBody& Ieee80211ReassociationRequestFrameBody::operator=(const Ieee80211ReassociationRequestFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211AssociationRequestFrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ReassociationRequestFrameBody::copy(const Ieee80211ReassociationRequestFrameBody& other)
{
    this->currentAP = other.currentAP;
}

void Ieee80211ReassociationRequestFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211AssociationRequestFrameBody::parsimPack(b);
    doParsimPacking(b,this->currentAP);
}

void Ieee80211ReassociationRequestFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211AssociationRequestFrameBody::parsimUnpack(b);
    doParsimUnpacking(b,this->currentAP);
}

MACAddress& Ieee80211ReassociationRequestFrameBody::getCurrentAP()
{
    return this->currentAP;
}

void Ieee80211ReassociationRequestFrameBody::setCurrentAP(const MACAddress& currentAP)
{
    this->currentAP = currentAP;
}

class Ieee80211ReassociationRequestFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ReassociationRequestFrameBodyDescriptor();
    virtual ~Ieee80211ReassociationRequestFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211ReassociationRequestFrameBodyDescriptor)

Ieee80211ReassociationRequestFrameBodyDescriptor::Ieee80211ReassociationRequestFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ReassociationRequestFrameBody", "inet::ieee80211::Ieee80211AssociationRequestFrameBody")
{
    propertynames = nullptr;
}

Ieee80211ReassociationRequestFrameBodyDescriptor::~Ieee80211ReassociationRequestFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ReassociationRequestFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ReassociationRequestFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211ReassociationRequestFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ReassociationRequestFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "currentAP",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211ReassociationRequestFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='c' && strcmp(fieldName, "currentAP")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldTypeString(int field) const
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

const char **Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrameBody *pp = (Ieee80211ReassociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrameBody *pp = (Ieee80211ReassociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrameBody *pp = (Ieee80211ReassociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getCurrentAP(); return out.str();}
        default: return "";
    }
}

bool Ieee80211ReassociationRequestFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrameBody *pp = (Ieee80211ReassociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldStructName(int field) const
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

void *Ieee80211ReassociationRequestFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrameBody *pp = (Ieee80211ReassociationRequestFrameBody *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getCurrentAP()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AssociationResponseFrameBody)

Ieee80211AssociationResponseFrameBody::Ieee80211AssociationResponseFrameBody() : ::inet::ieee80211::Ieee80211FrameBody()
{
    this->setBodyLength(26);

    this->statusCode = 0;
    this->aid = 0;
}

Ieee80211AssociationResponseFrameBody::Ieee80211AssociationResponseFrameBody(const Ieee80211AssociationResponseFrameBody& other) : ::inet::ieee80211::Ieee80211FrameBody(other)
{
    copy(other);
}

Ieee80211AssociationResponseFrameBody::~Ieee80211AssociationResponseFrameBody()
{
}

Ieee80211AssociationResponseFrameBody& Ieee80211AssociationResponseFrameBody::operator=(const Ieee80211AssociationResponseFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211FrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AssociationResponseFrameBody::copy(const Ieee80211AssociationResponseFrameBody& other)
{
    this->statusCode = other.statusCode;
    this->aid = other.aid;
    this->supportedRates = other.supportedRates;
}

void Ieee80211AssociationResponseFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimPack(b);
    doParsimPacking(b,this->statusCode);
    doParsimPacking(b,this->aid);
    doParsimPacking(b,this->supportedRates);
}

void Ieee80211AssociationResponseFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimUnpack(b);
    doParsimUnpacking(b,this->statusCode);
    doParsimUnpacking(b,this->aid);
    doParsimUnpacking(b,this->supportedRates);
}

int Ieee80211AssociationResponseFrameBody::getStatusCode() const
{
    return this->statusCode;
}

void Ieee80211AssociationResponseFrameBody::setStatusCode(int statusCode)
{
    this->statusCode = statusCode;
}

short Ieee80211AssociationResponseFrameBody::getAid() const
{
    return this->aid;
}

void Ieee80211AssociationResponseFrameBody::setAid(short aid)
{
    this->aid = aid;
}

Ieee80211SupportedRatesElement& Ieee80211AssociationResponseFrameBody::getSupportedRates()
{
    return this->supportedRates;
}

void Ieee80211AssociationResponseFrameBody::setSupportedRates(const Ieee80211SupportedRatesElement& supportedRates)
{
    this->supportedRates = supportedRates;
}

class Ieee80211AssociationResponseFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AssociationResponseFrameBodyDescriptor();
    virtual ~Ieee80211AssociationResponseFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211AssociationResponseFrameBodyDescriptor)

Ieee80211AssociationResponseFrameBodyDescriptor::Ieee80211AssociationResponseFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AssociationResponseFrameBody", "inet::ieee80211::Ieee80211FrameBody")
{
    propertynames = nullptr;
}

Ieee80211AssociationResponseFrameBodyDescriptor::~Ieee80211AssociationResponseFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AssociationResponseFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AssociationResponseFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211AssociationResponseFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AssociationResponseFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AssociationResponseFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int Ieee80211AssociationResponseFrameBodyDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211AssociationResponseFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "statusCode",
        "aid",
        "supportedRates",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int Ieee80211AssociationResponseFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "statusCode")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "aid")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "supportedRates")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AssociationResponseFrameBodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "short",
        "Ieee80211SupportedRatesElement",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AssociationResponseFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AssociationResponseFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::ieee80211::Ieee80211StatusCode";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211AssociationResponseFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrameBody *pp = (Ieee80211AssociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AssociationResponseFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrameBody *pp = (Ieee80211AssociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AssociationResponseFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrameBody *pp = (Ieee80211AssociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getStatusCode(), "inet::ieee80211::Ieee80211StatusCode");
        case 1: return long2string(pp->getAid());
        case 2: {std::stringstream out; out << pp->getSupportedRates(); return out.str();}
        default: return "";
    }
}

bool Ieee80211AssociationResponseFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrameBody *pp = (Ieee80211AssociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        case 0: pp->setStatusCode((inet::ieee80211::Ieee80211StatusCode)string2enum(value, "inet::ieee80211::Ieee80211StatusCode")); return true;
        case 1: pp->setAid(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211AssociationResponseFrameBodyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 2: return omnetpp::opp_typename(typeid(Ieee80211SupportedRatesElement));
        default: return nullptr;
    };
}

void *Ieee80211AssociationResponseFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrameBody *pp = (Ieee80211AssociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        case 2: return (void *)(&pp->getSupportedRates()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ReassociationResponseFrameBody)

Ieee80211ReassociationResponseFrameBody::Ieee80211ReassociationResponseFrameBody() : ::inet::ieee80211::Ieee80211AssociationResponseFrameBody()
{
}

Ieee80211ReassociationResponseFrameBody::Ieee80211ReassociationResponseFrameBody(const Ieee80211ReassociationResponseFrameBody& other) : ::inet::ieee80211::Ieee80211AssociationResponseFrameBody(other)
{
    copy(other);
}

Ieee80211ReassociationResponseFrameBody::~Ieee80211ReassociationResponseFrameBody()
{
}

Ieee80211ReassociationResponseFrameBody& Ieee80211ReassociationResponseFrameBody::operator=(const Ieee80211ReassociationResponseFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211AssociationResponseFrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ReassociationResponseFrameBody::copy(const Ieee80211ReassociationResponseFrameBody& other)
{
}

void Ieee80211ReassociationResponseFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211AssociationResponseFrameBody::parsimPack(b);
}

void Ieee80211ReassociationResponseFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211AssociationResponseFrameBody::parsimUnpack(b);
}

class Ieee80211ReassociationResponseFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ReassociationResponseFrameBodyDescriptor();
    virtual ~Ieee80211ReassociationResponseFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211ReassociationResponseFrameBodyDescriptor)

Ieee80211ReassociationResponseFrameBodyDescriptor::Ieee80211ReassociationResponseFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ReassociationResponseFrameBody", "inet::ieee80211::Ieee80211AssociationResponseFrameBody")
{
    propertynames = nullptr;
}

Ieee80211ReassociationResponseFrameBodyDescriptor::~Ieee80211ReassociationResponseFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ReassociationResponseFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ReassociationResponseFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211ReassociationResponseFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ReassociationResponseFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ReassociationResponseFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrameBody *pp = (Ieee80211ReassociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrameBody *pp = (Ieee80211ReassociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrameBody *pp = (Ieee80211ReassociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ReassociationResponseFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrameBody *pp = (Ieee80211ReassociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ReassociationResponseFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrameBody *pp = (Ieee80211ReassociationResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211BeaconFrameBody)

Ieee80211BeaconFrameBody::Ieee80211BeaconFrameBody() : ::inet::ieee80211::Ieee80211FrameBody()
{
    this->setBodyLength(50);

    this->beaconInterval = 0;
    this->channelNumber = 0;
}

Ieee80211BeaconFrameBody::Ieee80211BeaconFrameBody(const Ieee80211BeaconFrameBody& other) : ::inet::ieee80211::Ieee80211FrameBody(other)
{
    copy(other);
}

Ieee80211BeaconFrameBody::~Ieee80211BeaconFrameBody()
{
}

Ieee80211BeaconFrameBody& Ieee80211BeaconFrameBody::operator=(const Ieee80211BeaconFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211FrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BeaconFrameBody::copy(const Ieee80211BeaconFrameBody& other)
{
    this->SSID = other.SSID;
    this->supportedRates = other.supportedRates;
    this->beaconInterval = other.beaconInterval;
    this->channelNumber = other.channelNumber;
    this->handoverParameters = other.handoverParameters;
}

void Ieee80211BeaconFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimPack(b);
    doParsimPacking(b,this->SSID);
    doParsimPacking(b,this->supportedRates);
    doParsimPacking(b,this->beaconInterval);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->handoverParameters);
}

void Ieee80211BeaconFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimUnpack(b);
    doParsimUnpacking(b,this->SSID);
    doParsimUnpacking(b,this->supportedRates);
    doParsimUnpacking(b,this->beaconInterval);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->handoverParameters);
}

const char * Ieee80211BeaconFrameBody::getSSID() const
{
    return this->SSID.c_str();
}

void Ieee80211BeaconFrameBody::setSSID(const char * SSID)
{
    this->SSID = SSID;
}

Ieee80211SupportedRatesElement& Ieee80211BeaconFrameBody::getSupportedRates()
{
    return this->supportedRates;
}

void Ieee80211BeaconFrameBody::setSupportedRates(const Ieee80211SupportedRatesElement& supportedRates)
{
    this->supportedRates = supportedRates;
}

::omnetpp::simtime_t Ieee80211BeaconFrameBody::getBeaconInterval() const
{
    return this->beaconInterval;
}

void Ieee80211BeaconFrameBody::setBeaconInterval(::omnetpp::simtime_t beaconInterval)
{
    this->beaconInterval = beaconInterval;
}

int Ieee80211BeaconFrameBody::getChannelNumber() const
{
    return this->channelNumber;
}

void Ieee80211BeaconFrameBody::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

Ieee80211HandoverParameters& Ieee80211BeaconFrameBody::getHandoverParameters()
{
    return this->handoverParameters;
}

void Ieee80211BeaconFrameBody::setHandoverParameters(const Ieee80211HandoverParameters& handoverParameters)
{
    this->handoverParameters = handoverParameters;
}

class Ieee80211BeaconFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211BeaconFrameBodyDescriptor();
    virtual ~Ieee80211BeaconFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211BeaconFrameBodyDescriptor)

Ieee80211BeaconFrameBodyDescriptor::Ieee80211BeaconFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211BeaconFrameBody", "inet::ieee80211::Ieee80211FrameBody")
{
    propertynames = nullptr;
}

Ieee80211BeaconFrameBodyDescriptor::~Ieee80211BeaconFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BeaconFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BeaconFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211BeaconFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BeaconFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BeaconFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int Ieee80211BeaconFrameBodyDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211BeaconFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "SSID",
        "supportedRates",
        "beaconInterval",
        "channelNumber",
        "handoverParameters",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int Ieee80211BeaconFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='S' && strcmp(fieldName, "SSID")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "supportedRates")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "beaconInterval")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "channelNumber")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "handoverParameters")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BeaconFrameBodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "Ieee80211SupportedRatesElement",
        "simtime_t",
        "int",
        "Ieee80211HandoverParameters",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BeaconFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BeaconFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BeaconFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrameBody *pp = (Ieee80211BeaconFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BeaconFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrameBody *pp = (Ieee80211BeaconFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BeaconFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrameBody *pp = (Ieee80211BeaconFrameBody *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getSSID());
        case 1: {std::stringstream out; out << pp->getSupportedRates(); return out.str();}
        case 2: return simtime2string(pp->getBeaconInterval());
        case 3: return long2string(pp->getChannelNumber());
        case 4: {std::stringstream out; out << pp->getHandoverParameters(); return out.str();}
        default: return "";
    }
}

bool Ieee80211BeaconFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrameBody *pp = (Ieee80211BeaconFrameBody *)object; (void)pp;
    switch (field) {
        case 0: pp->setSSID((value)); return true;
        case 2: pp->setBeaconInterval(string2simtime(value)); return true;
        case 3: pp->setChannelNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *Ieee80211BeaconFrameBodyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(Ieee80211SupportedRatesElement));
        case 4: return omnetpp::opp_typename(typeid(Ieee80211HandoverParameters));
        default: return nullptr;
    };
}

void *Ieee80211BeaconFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrameBody *pp = (Ieee80211BeaconFrameBody *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getSupportedRates()); break;
        case 4: return (void *)(&pp->getHandoverParameters()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ProbeResponseFrameBody)

Ieee80211ProbeResponseFrameBody::Ieee80211ProbeResponseFrameBody() : ::inet::ieee80211::Ieee80211BeaconFrameBody()
{
}

Ieee80211ProbeResponseFrameBody::Ieee80211ProbeResponseFrameBody(const Ieee80211ProbeResponseFrameBody& other) : ::inet::ieee80211::Ieee80211BeaconFrameBody(other)
{
    copy(other);
}

Ieee80211ProbeResponseFrameBody::~Ieee80211ProbeResponseFrameBody()
{
}

Ieee80211ProbeResponseFrameBody& Ieee80211ProbeResponseFrameBody::operator=(const Ieee80211ProbeResponseFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211BeaconFrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ProbeResponseFrameBody::copy(const Ieee80211ProbeResponseFrameBody& other)
{
}

void Ieee80211ProbeResponseFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211BeaconFrameBody::parsimPack(b);
}

void Ieee80211ProbeResponseFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211BeaconFrameBody::parsimUnpack(b);
}

class Ieee80211ProbeResponseFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ProbeResponseFrameBodyDescriptor();
    virtual ~Ieee80211ProbeResponseFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211ProbeResponseFrameBodyDescriptor)

Ieee80211ProbeResponseFrameBodyDescriptor::Ieee80211ProbeResponseFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ProbeResponseFrameBody", "inet::ieee80211::Ieee80211BeaconFrameBody")
{
    propertynames = nullptr;
}

Ieee80211ProbeResponseFrameBodyDescriptor::~Ieee80211ProbeResponseFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ProbeResponseFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ProbeResponseFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211ProbeResponseFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ProbeResponseFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ProbeResponseFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ProbeResponseFrameBodyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ProbeResponseFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ProbeResponseFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ProbeResponseFrameBodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ProbeResponseFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ProbeResponseFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ProbeResponseFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrameBody *pp = (Ieee80211ProbeResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ProbeResponseFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrameBody *pp = (Ieee80211ProbeResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ProbeResponseFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrameBody *pp = (Ieee80211ProbeResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ProbeResponseFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrameBody *pp = (Ieee80211ProbeResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ProbeResponseFrameBodyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ProbeResponseFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrameBody *pp = (Ieee80211ProbeResponseFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211ActionFrameBody)

Ieee80211ActionFrameBody::Ieee80211ActionFrameBody() : ::inet::ieee80211::Ieee80211FrameBody()
{
}

Ieee80211ActionFrameBody::Ieee80211ActionFrameBody(const Ieee80211ActionFrameBody& other) : ::inet::ieee80211::Ieee80211FrameBody(other)
{
    copy(other);
}

Ieee80211ActionFrameBody::~Ieee80211ActionFrameBody()
{
}

Ieee80211ActionFrameBody& Ieee80211ActionFrameBody::operator=(const Ieee80211ActionFrameBody& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211FrameBody::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ActionFrameBody::copy(const Ieee80211ActionFrameBody& other)
{
}

void Ieee80211ActionFrameBody::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimPack(b);
}

void Ieee80211ActionFrameBody::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211FrameBody::parsimUnpack(b);
}

class Ieee80211ActionFrameBodyDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ActionFrameBodyDescriptor();
    virtual ~Ieee80211ActionFrameBodyDescriptor();

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

Register_ClassDescriptor(Ieee80211ActionFrameBodyDescriptor)

Ieee80211ActionFrameBodyDescriptor::Ieee80211ActionFrameBodyDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ActionFrameBody", "inet::ieee80211::Ieee80211FrameBody")
{
    propertynames = nullptr;
}

Ieee80211ActionFrameBodyDescriptor::~Ieee80211ActionFrameBodyDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ActionFrameBodyDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ActionFrameBody *>(obj)!=nullptr;
}

const char **Ieee80211ActionFrameBodyDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ActionFrameBodyDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ActionFrameBodyDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ActionFrameBodyDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ActionFrameBodyDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ActionFrameBodyDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ActionFrameBodyDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ActionFrameBodyDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ActionFrameBodyDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ActionFrameBodyDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrameBody *pp = (Ieee80211ActionFrameBody *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ActionFrameBodyDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrameBody *pp = (Ieee80211ActionFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ActionFrameBodyDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrameBody *pp = (Ieee80211ActionFrameBody *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ActionFrameBodyDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrameBody *pp = (Ieee80211ActionFrameBody *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ActionFrameBodyDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ActionFrameBodyDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ActionFrameBody *pp = (Ieee80211ActionFrameBody *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(Ieee80211AuthenticationFrame)

Ieee80211AuthenticationFrame::Ieee80211AuthenticationFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_AUTHENTICATION);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211AuthenticationFrame::Ieee80211AuthenticationFrame(const Ieee80211AuthenticationFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211AuthenticationFrame::~Ieee80211AuthenticationFrame()
{
}

Ieee80211AuthenticationFrame& Ieee80211AuthenticationFrame::operator=(const Ieee80211AuthenticationFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AuthenticationFrame::copy(const Ieee80211AuthenticationFrame& other)
{
    this->body = other.body;
}

void Ieee80211AuthenticationFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211AuthenticationFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211AuthenticationFrameBody& Ieee80211AuthenticationFrame::getBody()
{
    return this->body;
}

void Ieee80211AuthenticationFrame::setBody(const Ieee80211AuthenticationFrameBody& body)
{
    this->body = body;
}

class Ieee80211AuthenticationFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AuthenticationFrameDescriptor();
    virtual ~Ieee80211AuthenticationFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211AuthenticationFrameDescriptor)

Ieee80211AuthenticationFrameDescriptor::Ieee80211AuthenticationFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AuthenticationFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211AuthenticationFrameDescriptor::~Ieee80211AuthenticationFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AuthenticationFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AuthenticationFrame *>(obj)!=nullptr;
}

const char **Ieee80211AuthenticationFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AuthenticationFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AuthenticationFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211AuthenticationFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211AuthenticationFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211AuthenticationFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AuthenticationFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211AuthenticationFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AuthenticationFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AuthenticationFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AuthenticationFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AuthenticationFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AuthenticationFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211AuthenticationFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211AuthenticationFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211AuthenticationFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211AuthenticationFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AuthenticationFrame *pp = (Ieee80211AuthenticationFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211DeauthenticationFrame)

Ieee80211DeauthenticationFrame::Ieee80211DeauthenticationFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_DEAUTHENTICATION);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211DeauthenticationFrame::Ieee80211DeauthenticationFrame(const Ieee80211DeauthenticationFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211DeauthenticationFrame::~Ieee80211DeauthenticationFrame()
{
}

Ieee80211DeauthenticationFrame& Ieee80211DeauthenticationFrame::operator=(const Ieee80211DeauthenticationFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DeauthenticationFrame::copy(const Ieee80211DeauthenticationFrame& other)
{
    this->body = other.body;
}

void Ieee80211DeauthenticationFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211DeauthenticationFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211DeauthenticationFrameBody& Ieee80211DeauthenticationFrame::getBody()
{
    return this->body;
}

void Ieee80211DeauthenticationFrame::setBody(const Ieee80211DeauthenticationFrameBody& body)
{
    this->body = body;
}

class Ieee80211DeauthenticationFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DeauthenticationFrameDescriptor();
    virtual ~Ieee80211DeauthenticationFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211DeauthenticationFrameDescriptor)

Ieee80211DeauthenticationFrameDescriptor::Ieee80211DeauthenticationFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DeauthenticationFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211DeauthenticationFrameDescriptor::~Ieee80211DeauthenticationFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DeauthenticationFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DeauthenticationFrame *>(obj)!=nullptr;
}

const char **Ieee80211DeauthenticationFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DeauthenticationFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DeauthenticationFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211DeauthenticationFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211DeauthenticationFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211DeauthenticationFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DeauthenticationFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211DeauthenticationFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DeauthenticationFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211DeauthenticationFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211DeauthenticationFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211DeauthenticationFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211DeauthenticationFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DeauthenticationFrame *pp = (Ieee80211DeauthenticationFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211DisassociationFrame)

Ieee80211DisassociationFrame::Ieee80211DisassociationFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_DISASSOCIATION);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211DisassociationFrame::Ieee80211DisassociationFrame(const Ieee80211DisassociationFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211DisassociationFrame::~Ieee80211DisassociationFrame()
{
}

Ieee80211DisassociationFrame& Ieee80211DisassociationFrame::operator=(const Ieee80211DisassociationFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211DisassociationFrame::copy(const Ieee80211DisassociationFrame& other)
{
    this->body = other.body;
}

void Ieee80211DisassociationFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211DisassociationFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211DisassociationFrameBody& Ieee80211DisassociationFrame::getBody()
{
    return this->body;
}

void Ieee80211DisassociationFrame::setBody(const Ieee80211DisassociationFrameBody& body)
{
    this->body = body;
}

class Ieee80211DisassociationFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211DisassociationFrameDescriptor();
    virtual ~Ieee80211DisassociationFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211DisassociationFrameDescriptor)

Ieee80211DisassociationFrameDescriptor::Ieee80211DisassociationFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211DisassociationFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211DisassociationFrameDescriptor::~Ieee80211DisassociationFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211DisassociationFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211DisassociationFrame *>(obj)!=nullptr;
}

const char **Ieee80211DisassociationFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211DisassociationFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211DisassociationFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211DisassociationFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211DisassociationFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211DisassociationFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211DisassociationFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211DisassociationFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211DisassociationFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211DisassociationFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211DisassociationFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211DisassociationFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211DisassociationFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211DisassociationFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211DisassociationFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211DisassociationFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211DisassociationFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211DisassociationFrame *pp = (Ieee80211DisassociationFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ProbeRequestFrame)

Ieee80211ProbeRequestFrame::Ieee80211ProbeRequestFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_PROBEREQUEST);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211ProbeRequestFrame::Ieee80211ProbeRequestFrame(const Ieee80211ProbeRequestFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211ProbeRequestFrame::~Ieee80211ProbeRequestFrame()
{
}

Ieee80211ProbeRequestFrame& Ieee80211ProbeRequestFrame::operator=(const Ieee80211ProbeRequestFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ProbeRequestFrame::copy(const Ieee80211ProbeRequestFrame& other)
{
    this->body = other.body;
}

void Ieee80211ProbeRequestFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211ProbeRequestFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211ProbeRequestFrameBody& Ieee80211ProbeRequestFrame::getBody()
{
    return this->body;
}

void Ieee80211ProbeRequestFrame::setBody(const Ieee80211ProbeRequestFrameBody& body)
{
    this->body = body;
}

class Ieee80211ProbeRequestFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ProbeRequestFrameDescriptor();
    virtual ~Ieee80211ProbeRequestFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ProbeRequestFrameDescriptor)

Ieee80211ProbeRequestFrameDescriptor::Ieee80211ProbeRequestFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ProbeRequestFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211ProbeRequestFrameDescriptor::~Ieee80211ProbeRequestFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ProbeRequestFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ProbeRequestFrame *>(obj)!=nullptr;
}

const char **Ieee80211ProbeRequestFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ProbeRequestFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ProbeRequestFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ProbeRequestFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211ProbeRequestFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211ProbeRequestFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ProbeRequestFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ProbeRequestFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ProbeRequestFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211ProbeRequestFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ProbeRequestFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211ProbeRequestFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211ProbeRequestFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeRequestFrame *pp = (Ieee80211ProbeRequestFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AssociationRequestFrame)

Ieee80211AssociationRequestFrame::Ieee80211AssociationRequestFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_ASSOCIATIONREQUEST);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211AssociationRequestFrame::Ieee80211AssociationRequestFrame(const Ieee80211AssociationRequestFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211AssociationRequestFrame::~Ieee80211AssociationRequestFrame()
{
}

Ieee80211AssociationRequestFrame& Ieee80211AssociationRequestFrame::operator=(const Ieee80211AssociationRequestFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AssociationRequestFrame::copy(const Ieee80211AssociationRequestFrame& other)
{
    this->body = other.body;
}

void Ieee80211AssociationRequestFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211AssociationRequestFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211AssociationRequestFrameBody& Ieee80211AssociationRequestFrame::getBody()
{
    return this->body;
}

void Ieee80211AssociationRequestFrame::setBody(const Ieee80211AssociationRequestFrameBody& body)
{
    this->body = body;
}

class Ieee80211AssociationRequestFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AssociationRequestFrameDescriptor();
    virtual ~Ieee80211AssociationRequestFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211AssociationRequestFrameDescriptor)

Ieee80211AssociationRequestFrameDescriptor::Ieee80211AssociationRequestFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AssociationRequestFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211AssociationRequestFrameDescriptor::~Ieee80211AssociationRequestFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AssociationRequestFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AssociationRequestFrame *>(obj)!=nullptr;
}

const char **Ieee80211AssociationRequestFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AssociationRequestFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AssociationRequestFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211AssociationRequestFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211AssociationRequestFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211AssociationRequestFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AssociationRequestFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AssociationRequestFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AssociationRequestFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211AssociationRequestFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211AssociationRequestFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211AssociationRequestFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211AssociationRequestFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationRequestFrame *pp = (Ieee80211AssociationRequestFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ReassociationRequestFrame)

Ieee80211ReassociationRequestFrame::Ieee80211ReassociationRequestFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_REASSOCIATIONREQUEST);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211ReassociationRequestFrame::Ieee80211ReassociationRequestFrame(const Ieee80211ReassociationRequestFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211ReassociationRequestFrame::~Ieee80211ReassociationRequestFrame()
{
}

Ieee80211ReassociationRequestFrame& Ieee80211ReassociationRequestFrame::operator=(const Ieee80211ReassociationRequestFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ReassociationRequestFrame::copy(const Ieee80211ReassociationRequestFrame& other)
{
    this->body = other.body;
}

void Ieee80211ReassociationRequestFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211ReassociationRequestFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211ReassociationRequestFrameBody& Ieee80211ReassociationRequestFrame::getBody()
{
    return this->body;
}

void Ieee80211ReassociationRequestFrame::setBody(const Ieee80211ReassociationRequestFrameBody& body)
{
    this->body = body;
}

class Ieee80211ReassociationRequestFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ReassociationRequestFrameDescriptor();
    virtual ~Ieee80211ReassociationRequestFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ReassociationRequestFrameDescriptor)

Ieee80211ReassociationRequestFrameDescriptor::Ieee80211ReassociationRequestFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ReassociationRequestFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211ReassociationRequestFrameDescriptor::~Ieee80211ReassociationRequestFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ReassociationRequestFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ReassociationRequestFrame *>(obj)!=nullptr;
}

const char **Ieee80211ReassociationRequestFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ReassociationRequestFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ReassociationRequestFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211ReassociationRequestFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211ReassociationRequestFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ReassociationRequestFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ReassociationRequestFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ReassociationRequestFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211ReassociationRequestFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ReassociationRequestFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211ReassociationRequestFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211ReassociationRequestFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationRequestFrame *pp = (Ieee80211ReassociationRequestFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211AssociationResponseFrame)

Ieee80211AssociationResponseFrame::Ieee80211AssociationResponseFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_ASSOCIATIONRESPONSE);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211AssociationResponseFrame::Ieee80211AssociationResponseFrame(const Ieee80211AssociationResponseFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211AssociationResponseFrame::~Ieee80211AssociationResponseFrame()
{
}

Ieee80211AssociationResponseFrame& Ieee80211AssociationResponseFrame::operator=(const Ieee80211AssociationResponseFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211AssociationResponseFrame::copy(const Ieee80211AssociationResponseFrame& other)
{
    this->body = other.body;
}

void Ieee80211AssociationResponseFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211AssociationResponseFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211AssociationResponseFrameBody& Ieee80211AssociationResponseFrame::getBody()
{
    return this->body;
}

void Ieee80211AssociationResponseFrame::setBody(const Ieee80211AssociationResponseFrameBody& body)
{
    this->body = body;
}

class Ieee80211AssociationResponseFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211AssociationResponseFrameDescriptor();
    virtual ~Ieee80211AssociationResponseFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211AssociationResponseFrameDescriptor)

Ieee80211AssociationResponseFrameDescriptor::Ieee80211AssociationResponseFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211AssociationResponseFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211AssociationResponseFrameDescriptor::~Ieee80211AssociationResponseFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211AssociationResponseFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211AssociationResponseFrame *>(obj)!=nullptr;
}

const char **Ieee80211AssociationResponseFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211AssociationResponseFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211AssociationResponseFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211AssociationResponseFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211AssociationResponseFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211AssociationResponseFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211AssociationResponseFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211AssociationResponseFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211AssociationResponseFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211AssociationResponseFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211AssociationResponseFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211AssociationResponseFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211AssociationResponseFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211AssociationResponseFrame *pp = (Ieee80211AssociationResponseFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ReassociationResponseFrame)

Ieee80211ReassociationResponseFrame::Ieee80211ReassociationResponseFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_REASSOCIATIONRESPONSE);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211ReassociationResponseFrame::Ieee80211ReassociationResponseFrame(const Ieee80211ReassociationResponseFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211ReassociationResponseFrame::~Ieee80211ReassociationResponseFrame()
{
}

Ieee80211ReassociationResponseFrame& Ieee80211ReassociationResponseFrame::operator=(const Ieee80211ReassociationResponseFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ReassociationResponseFrame::copy(const Ieee80211ReassociationResponseFrame& other)
{
    this->body = other.body;
}

void Ieee80211ReassociationResponseFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211ReassociationResponseFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211ReassociationResponseFrameBody& Ieee80211ReassociationResponseFrame::getBody()
{
    return this->body;
}

void Ieee80211ReassociationResponseFrame::setBody(const Ieee80211ReassociationResponseFrameBody& body)
{
    this->body = body;
}

class Ieee80211ReassociationResponseFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ReassociationResponseFrameDescriptor();
    virtual ~Ieee80211ReassociationResponseFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ReassociationResponseFrameDescriptor)

Ieee80211ReassociationResponseFrameDescriptor::Ieee80211ReassociationResponseFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ReassociationResponseFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211ReassociationResponseFrameDescriptor::~Ieee80211ReassociationResponseFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ReassociationResponseFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ReassociationResponseFrame *>(obj)!=nullptr;
}

const char **Ieee80211ReassociationResponseFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ReassociationResponseFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ReassociationResponseFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211ReassociationResponseFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211ReassociationResponseFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ReassociationResponseFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ReassociationResponseFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ReassociationResponseFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211ReassociationResponseFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ReassociationResponseFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211ReassociationResponseFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211ReassociationResponseFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ReassociationResponseFrame *pp = (Ieee80211ReassociationResponseFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211BeaconFrame)

Ieee80211BeaconFrame::Ieee80211BeaconFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_BEACON);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211BeaconFrame::Ieee80211BeaconFrame(const Ieee80211BeaconFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211BeaconFrame::~Ieee80211BeaconFrame()
{
}

Ieee80211BeaconFrame& Ieee80211BeaconFrame::operator=(const Ieee80211BeaconFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211BeaconFrame::copy(const Ieee80211BeaconFrame& other)
{
    this->body = other.body;
}

void Ieee80211BeaconFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211BeaconFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211BeaconFrameBody& Ieee80211BeaconFrame::getBody()
{
    return this->body;
}

void Ieee80211BeaconFrame::setBody(const Ieee80211BeaconFrameBody& body)
{
    this->body = body;
}

class Ieee80211BeaconFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211BeaconFrameDescriptor();
    virtual ~Ieee80211BeaconFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211BeaconFrameDescriptor)

Ieee80211BeaconFrameDescriptor::Ieee80211BeaconFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211BeaconFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211BeaconFrameDescriptor::~Ieee80211BeaconFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211BeaconFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211BeaconFrame *>(obj)!=nullptr;
}

const char **Ieee80211BeaconFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211BeaconFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211BeaconFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211BeaconFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211BeaconFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211BeaconFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211BeaconFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211BeaconFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211BeaconFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211BeaconFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211BeaconFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211BeaconFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211BeaconFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211BeaconFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211BeaconFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211BeaconFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211BeaconFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211BeaconFrame *pp = (Ieee80211BeaconFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

Register_Class(Ieee80211ProbeResponseFrame)

Ieee80211ProbeResponseFrame::Ieee80211ProbeResponseFrame(const char *name, short kind) : ::inet::ieee80211::Ieee80211ManagementFrame(name,kind)
{
    this->setType(ST_PROBERESPONSE);
    this->setByteLength(28+getBody().getBodyLength());

}

Ieee80211ProbeResponseFrame::Ieee80211ProbeResponseFrame(const Ieee80211ProbeResponseFrame& other) : ::inet::ieee80211::Ieee80211ManagementFrame(other)
{
    copy(other);
}

Ieee80211ProbeResponseFrame::~Ieee80211ProbeResponseFrame()
{
}

Ieee80211ProbeResponseFrame& Ieee80211ProbeResponseFrame::operator=(const Ieee80211ProbeResponseFrame& other)
{
    if (this==&other) return *this;
    ::inet::ieee80211::Ieee80211ManagementFrame::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ProbeResponseFrame::copy(const Ieee80211ProbeResponseFrame& other)
{
    this->body = other.body;
}

void Ieee80211ProbeResponseFrame::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimPack(b);
    doParsimPacking(b,this->body);
}

void Ieee80211ProbeResponseFrame::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::ieee80211::Ieee80211ManagementFrame::parsimUnpack(b);
    doParsimUnpacking(b,this->body);
}

Ieee80211ProbeResponseFrameBody& Ieee80211ProbeResponseFrame::getBody()
{
    return this->body;
}

void Ieee80211ProbeResponseFrame::setBody(const Ieee80211ProbeResponseFrameBody& body)
{
    this->body = body;
}

class Ieee80211ProbeResponseFrameDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ProbeResponseFrameDescriptor();
    virtual ~Ieee80211ProbeResponseFrameDescriptor();

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

Register_ClassDescriptor(Ieee80211ProbeResponseFrameDescriptor)

Ieee80211ProbeResponseFrameDescriptor::Ieee80211ProbeResponseFrameDescriptor() : omnetpp::cClassDescriptor("inet::ieee80211::Ieee80211ProbeResponseFrame", "inet::ieee80211::Ieee80211ManagementFrame")
{
    propertynames = nullptr;
}

Ieee80211ProbeResponseFrameDescriptor::~Ieee80211ProbeResponseFrameDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ProbeResponseFrameDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ProbeResponseFrame *>(obj)!=nullptr;
}

const char **Ieee80211ProbeResponseFrameDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ProbeResponseFrameDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ProbeResponseFrameDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int Ieee80211ProbeResponseFrameDescriptor::getFieldTypeFlags(int field) const
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

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "body",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int Ieee80211ProbeResponseFrameDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "body")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "Ieee80211ProbeResponseFrameBody",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ProbeResponseFrameDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ProbeResponseFrameDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ProbeResponseFrameDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getBody(); return out.str();}
        default: return "";
    }
}

bool Ieee80211ProbeResponseFrameDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ProbeResponseFrameDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(Ieee80211ProbeResponseFrameBody));
        default: return nullptr;
    };
}

void *Ieee80211ProbeResponseFrameDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ProbeResponseFrame *pp = (Ieee80211ProbeResponseFrame *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getBody()); break;
        default: return nullptr;
    }
}

} // namespace ieee80211
} // namespace inet

