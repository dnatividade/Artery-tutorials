//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/physicallayer/ieee80211/packetlevel/Ieee80211ControlInfo.msg.
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
#include "Ieee80211ControlInfo_m.h"

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
namespace physicallayer {

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

class IIeee80211BandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IIeee80211BandDescriptor();
    virtual ~IIeee80211BandDescriptor();

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

Register_ClassDescriptor(IIeee80211BandDescriptor)

IIeee80211BandDescriptor::IIeee80211BandDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::IIeee80211Band", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IIeee80211BandDescriptor::~IIeee80211BandDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211BandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211Band *>(obj)!=nullptr;
}

const char **IIeee80211BandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211BandDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211BandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int IIeee80211BandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211BandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "name",
        "centerFrequency",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int IIeee80211BandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "name")==0) return base+0;
    if (fieldName[0]=='c' && strcmp(fieldName, "centerFrequency")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211BandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "string",
        "Hz",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211BandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "opaque", "sizeGetter",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *IIeee80211BandDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"opaque")) return "";
            if (!strcmp(propertyname,"sizeGetter")) return "getNumChannels";
            return nullptr;
        default: return nullptr;
    }
}

int IIeee80211BandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Band *pp = (IIeee80211Band *)object; (void)pp;
    switch (field) {
        case 1: return pp->getNumChannels();
        default: return 0;
    }
}

const char *IIeee80211BandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Band *pp = (IIeee80211Band *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IIeee80211BandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Band *pp = (IIeee80211Band *)object; (void)pp;
    switch (field) {
        case 0: return oppstring2string(pp->getName());
        case 1: {std::stringstream out; out << pp->getCenterFrequency(i); return out.str();}
        default: return "";
    }
}

bool IIeee80211BandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Band *pp = (IIeee80211Band *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211BandDescriptor::getFieldStructName(int field) const
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

void *IIeee80211BandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Band *pp = (IIeee80211Band *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class Ieee80211EnumeratedBandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211EnumeratedBandDescriptor();
    virtual ~Ieee80211EnumeratedBandDescriptor();

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

Register_ClassDescriptor(Ieee80211EnumeratedBandDescriptor)

Ieee80211EnumeratedBandDescriptor::Ieee80211EnumeratedBandDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::Ieee80211EnumeratedBand", "inet::physicallayer::IIeee80211Band")
{
    propertynames = nullptr;
}

Ieee80211EnumeratedBandDescriptor::~Ieee80211EnumeratedBandDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211EnumeratedBandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211EnumeratedBand *>(obj)!=nullptr;
}

const char **Ieee80211EnumeratedBandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211EnumeratedBandDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211EnumeratedBandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211EnumeratedBandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211EnumeratedBandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211EnumeratedBandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211EnumeratedBandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211EnumeratedBandDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211EnumeratedBandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211EnumeratedBandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211EnumeratedBand *pp = (Ieee80211EnumeratedBand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211EnumeratedBandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211EnumeratedBand *pp = (Ieee80211EnumeratedBand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211EnumeratedBandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211EnumeratedBand *pp = (Ieee80211EnumeratedBand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211EnumeratedBandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211EnumeratedBand *pp = (Ieee80211EnumeratedBand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211EnumeratedBandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211EnumeratedBandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211EnumeratedBand *pp = (Ieee80211EnumeratedBand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class Ieee80211ArithmeticalBandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ArithmeticalBandDescriptor();
    virtual ~Ieee80211ArithmeticalBandDescriptor();

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

Register_ClassDescriptor(Ieee80211ArithmeticalBandDescriptor)

Ieee80211ArithmeticalBandDescriptor::Ieee80211ArithmeticalBandDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::Ieee80211ArithmeticalBand", "inet::physicallayer::IIeee80211Band")
{
    propertynames = nullptr;
}

Ieee80211ArithmeticalBandDescriptor::~Ieee80211ArithmeticalBandDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ArithmeticalBandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ArithmeticalBand *>(obj)!=nullptr;
}

const char **Ieee80211ArithmeticalBandDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ArithmeticalBandDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ArithmeticalBandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int Ieee80211ArithmeticalBandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *Ieee80211ArithmeticalBandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int Ieee80211ArithmeticalBandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ArithmeticalBandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **Ieee80211ArithmeticalBandDescriptor::getFieldPropertyNames(int field) const
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

const char *Ieee80211ArithmeticalBandDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int Ieee80211ArithmeticalBandDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ArithmeticalBand *pp = (Ieee80211ArithmeticalBand *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ArithmeticalBandDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ArithmeticalBand *pp = (Ieee80211ArithmeticalBand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ArithmeticalBandDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ArithmeticalBand *pp = (Ieee80211ArithmeticalBand *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool Ieee80211ArithmeticalBandDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ArithmeticalBand *pp = (Ieee80211ArithmeticalBand *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ArithmeticalBandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *Ieee80211ArithmeticalBandDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ArithmeticalBand *pp = (Ieee80211ArithmeticalBand *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class IIeee80211PreambleModeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IIeee80211PreambleModeDescriptor();
    virtual ~IIeee80211PreambleModeDescriptor();

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

Register_ClassDescriptor(IIeee80211PreambleModeDescriptor)

IIeee80211PreambleModeDescriptor::IIeee80211PreambleModeDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::IIeee80211PreambleMode", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IIeee80211PreambleModeDescriptor::~IIeee80211PreambleModeDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211PreambleModeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211PreambleMode *>(obj)!=nullptr;
}

const char **IIeee80211PreambleModeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211PreambleModeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211PreambleModeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int IIeee80211PreambleModeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211PreambleModeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "duration",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int IIeee80211PreambleModeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211PreambleModeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "simtime_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211PreambleModeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *IIeee80211PreambleModeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        default: return nullptr;
    }
}

int IIeee80211PreambleModeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IIeee80211PreambleModeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IIeee80211PreambleModeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        case 0: return simtime2string(pp->getDuration());
        default: return "";
    }
}

bool IIeee80211PreambleModeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211PreambleModeDescriptor::getFieldStructName(int field) const
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

void *IIeee80211PreambleModeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211PreambleMode *pp = (IIeee80211PreambleMode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class IIeee80211HeaderModeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IIeee80211HeaderModeDescriptor();
    virtual ~IIeee80211HeaderModeDescriptor();

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

Register_ClassDescriptor(IIeee80211HeaderModeDescriptor)

IIeee80211HeaderModeDescriptor::IIeee80211HeaderModeDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::IIeee80211HeaderMode", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IIeee80211HeaderModeDescriptor::~IIeee80211HeaderModeDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211HeaderModeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211HeaderMode *>(obj)!=nullptr;
}

const char **IIeee80211HeaderModeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211HeaderModeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211HeaderModeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int IIeee80211HeaderModeDescriptor::getFieldTypeFlags(int field) const
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
        0,
        0,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211HeaderModeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "netBitrate",
        "grossBitrate",
        "bitLength",
        "duration",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int IIeee80211HeaderModeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "netBitrate")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "grossBitrate")==0) return base+1;
    if (fieldName[0]=='b' && strcmp(fieldName, "bitLength")==0) return base+2;
    if (fieldName[0]=='d' && strcmp(fieldName, "duration")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211HeaderModeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bps",
        "bps",
        "int",
        "simtime_t",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211HeaderModeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "opaque",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "opaque",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *IIeee80211HeaderModeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"opaque")) return "";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"opaque")) return "";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        default: return nullptr;
    }
}

int IIeee80211HeaderModeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IIeee80211HeaderModeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IIeee80211HeaderModeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getNetBitrate(); return out.str();}
        case 1: {std::stringstream out; out << pp->getGrossBitrate(); return out.str();}
        case 2: return long2string(pp->getBitLength());
        case 3: return simtime2string(pp->getDuration());
        default: return "";
    }
}

bool IIeee80211HeaderModeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211HeaderModeDescriptor::getFieldStructName(int field) const
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

void *IIeee80211HeaderModeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211HeaderMode *pp = (IIeee80211HeaderMode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class IIeee80211DataModeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IIeee80211DataModeDescriptor();
    virtual ~IIeee80211DataModeDescriptor();

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

Register_ClassDescriptor(IIeee80211DataModeDescriptor)

IIeee80211DataModeDescriptor::IIeee80211DataModeDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::IIeee80211DataMode", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IIeee80211DataModeDescriptor::~IIeee80211DataModeDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211DataModeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211DataMode *>(obj)!=nullptr;
}

const char **IIeee80211DataModeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211DataModeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211DataModeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int IIeee80211DataModeDescriptor::getFieldTypeFlags(int field) const
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
        0,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211DataModeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "netBitrate",
        "grossBitrate",
        "numberOfSpatialStreams",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int IIeee80211DataModeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='n' && strcmp(fieldName, "netBitrate")==0) return base+0;
    if (fieldName[0]=='g' && strcmp(fieldName, "grossBitrate")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfSpatialStreams")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211DataModeDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "bps",
        "bps",
        "int",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211DataModeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "opaque",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "opaque",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *IIeee80211DataModeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"opaque")) return "";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"opaque")) return "";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        default: return nullptr;
    }
}

int IIeee80211DataModeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IIeee80211DataModeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IIeee80211DataModeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getNetBitrate(); return out.str();}
        case 1: {std::stringstream out; out << pp->getGrossBitrate(); return out.str();}
        case 2: return long2string(pp->getNumberOfSpatialStreams());
        default: return "";
    }
}

bool IIeee80211DataModeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211DataModeDescriptor::getFieldStructName(int field) const
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

void *IIeee80211DataModeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211DataMode *pp = (IIeee80211DataMode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

class IIeee80211ModeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    IIeee80211ModeDescriptor();
    virtual ~IIeee80211ModeDescriptor();

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

Register_ClassDescriptor(IIeee80211ModeDescriptor)

IIeee80211ModeDescriptor::IIeee80211ModeDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::IIeee80211Mode", "omnetpp::cObject")
{
    propertynames = nullptr;
}

IIeee80211ModeDescriptor::~IIeee80211ModeDescriptor()
{
    delete[] propertynames;
}

bool IIeee80211ModeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<IIeee80211Mode *>(obj)!=nullptr;
}

const char **IIeee80211ModeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *IIeee80211ModeDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int IIeee80211ModeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 15+basedesc->getFieldCount() : 15;
}

unsigned int IIeee80211ModeDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,
        0,
        0,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<15) ? fieldTypeFlags[field] : 0;
}

const char *IIeee80211ModeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "legacyCwMin",
        "legacyCwMax",
        "name",
        "preambleMode",
        "headerMode",
        "dataMode",
        "slotTime",
        "sifsTime",
        "rifsTime",
        "ccaTime",
        "phyRxStartDelay",
        "rxTxTurnaroundTime",
        "preambleLength",
        "plcpHeaderLength",
        "mpduMaxLength",
    };
    return (field>=0 && field<15) ? fieldNames[field] : nullptr;
}

int IIeee80211ModeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "legacyCwMin")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "legacyCwMax")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "name")==0) return base+2;
    if (fieldName[0]=='p' && strcmp(fieldName, "preambleMode")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerMode")==0) return base+4;
    if (fieldName[0]=='d' && strcmp(fieldName, "dataMode")==0) return base+5;
    if (fieldName[0]=='s' && strcmp(fieldName, "slotTime")==0) return base+6;
    if (fieldName[0]=='s' && strcmp(fieldName, "sifsTime")==0) return base+7;
    if (fieldName[0]=='r' && strcmp(fieldName, "rifsTime")==0) return base+8;
    if (fieldName[0]=='c' && strcmp(fieldName, "ccaTime")==0) return base+9;
    if (fieldName[0]=='p' && strcmp(fieldName, "phyRxStartDelay")==0) return base+10;
    if (fieldName[0]=='r' && strcmp(fieldName, "rxTxTurnaroundTime")==0) return base+11;
    if (fieldName[0]=='p' && strcmp(fieldName, "preambleLength")==0) return base+12;
    if (fieldName[0]=='p' && strcmp(fieldName, "plcpHeaderLength")==0) return base+13;
    if (fieldName[0]=='m' && strcmp(fieldName, "mpduMaxLength")==0) return base+14;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *IIeee80211ModeDescriptor::getFieldTypeString(int field) const
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
        "string",
        "IIeee80211PreambleMode",
        "IIeee80211HeaderMode",
        "IIeee80211DataMode",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "int",
    };
    return (field>=0 && field<15) ? fieldTypeStrings[field] : nullptr;
}

const char **IIeee80211ModeDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 8: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 9: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 10: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 11: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 12: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 13: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 14: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *IIeee80211ModeDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"getter")) return "_getPreambleMode";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"getter")) return "_getHeaderMode";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"getter")) return "_getDataMode";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 8:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 9:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 10:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 11:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 12:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 13:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 14:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        default: return nullptr;
    }
}

int IIeee80211ModeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *IIeee80211ModeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string IIeee80211ModeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getLegacyCwMin());
        case 1: return long2string(pp->getLegacyCwMax());
        case 2: return oppstring2string(pp->getName());
        case 3: {std::stringstream out; out << pp->_getPreambleMode(); return out.str();}
        case 4: {std::stringstream out; out << pp->_getHeaderMode(); return out.str();}
        case 5: {std::stringstream out; out << pp->_getDataMode(); return out.str();}
        case 6: return simtime2string(pp->getSlotTime());
        case 7: return simtime2string(pp->getSifsTime());
        case 8: return simtime2string(pp->getRifsTime());
        case 9: return simtime2string(pp->getCcaTime());
        case 10: return simtime2string(pp->getPhyRxStartDelay());
        case 11: return simtime2string(pp->getRxTxTurnaroundTime());
        case 12: return simtime2string(pp->getPreambleLength());
        case 13: return simtime2string(pp->getPlcpHeaderLength());
        case 14: return long2string(pp->getMpduMaxLength());
        default: return "";
    }
}

bool IIeee80211ModeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *IIeee80211ModeDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(IIeee80211PreambleMode));
        case 4: return omnetpp::opp_typename(typeid(IIeee80211HeaderMode));
        case 5: return omnetpp::opp_typename(typeid(IIeee80211DataMode));
        default: return nullptr;
    };
}

void *IIeee80211ModeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    IIeee80211Mode *pp = (IIeee80211Mode *)object; (void)pp;
    switch (field) {
        case 3: return (void *)static_cast<omnetpp::cObject *>(pp->_getPreambleMode()); break;
        case 4: return (void *)static_cast<omnetpp::cObject *>(pp->_getHeaderMode()); break;
        case 5: return (void *)static_cast<omnetpp::cObject *>(pp->_getDataMode()); break;
        default: return nullptr;
    }
}

class Ieee80211ModeSetDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    Ieee80211ModeSetDescriptor();
    virtual ~Ieee80211ModeSetDescriptor();

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

Register_ClassDescriptor(Ieee80211ModeSetDescriptor)

Ieee80211ModeSetDescriptor::Ieee80211ModeSetDescriptor() : omnetpp::cClassDescriptor("inet::physicallayer::Ieee80211ModeSet", "omnetpp::cObject")
{
    propertynames = nullptr;
}

Ieee80211ModeSetDescriptor::~Ieee80211ModeSetDescriptor()
{
    delete[] propertynames;
}

bool Ieee80211ModeSetDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Ieee80211ModeSet *>(obj)!=nullptr;
}

const char **Ieee80211ModeSetDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *Ieee80211ModeSetDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"existingClass")) return "";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int Ieee80211ModeSetDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int Ieee80211ModeSetDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT,
        0,
        0,
        0,
        0,
        0,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *Ieee80211ModeSetDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "slowestMode",
        "fastestMode",
        "slowestMandatoryMode",
        "fastestMandatoryMode",
        "sifsTime",
        "slotTime",
        "phyRxStartDelay",
        "cwMin",
        "cwMax",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int Ieee80211ModeSetDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "slowestMode")==0) return base+0;
    if (fieldName[0]=='f' && strcmp(fieldName, "fastestMode")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "slowestMandatoryMode")==0) return base+2;
    if (fieldName[0]=='f' && strcmp(fieldName, "fastestMandatoryMode")==0) return base+3;
    if (fieldName[0]=='s' && strcmp(fieldName, "sifsTime")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "slotTime")==0) return base+5;
    if (fieldName[0]=='p' && strcmp(fieldName, "phyRxStartDelay")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "cwMin")==0) return base+7;
    if (fieldName[0]=='c' && strcmp(fieldName, "cwMax")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *Ieee80211ModeSetDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IIeee80211Mode",
        "IIeee80211Mode",
        "IIeee80211Mode",
        "IIeee80211Mode",
        "simtime_t",
        "simtime_t",
        "simtime_t",
        "int",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **Ieee80211ModeSetDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 1: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 2: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 3: {
            static const char *names[] = { "editable", "getter",  nullptr };
            return names;
        }
        case 4: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 5: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 6: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 7: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        case 8: {
            static const char *names[] = { "editable",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *Ieee80211ModeSetDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"getter")) return "_getSlowestMode";
            return nullptr;
        case 1:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"getter")) return "_getFastestMode";
            return nullptr;
        case 2:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"getter")) return "_getSlowestMandatoryMode";
            return nullptr;
        case 3:
            if (!strcmp(propertyname,"editable")) return "false";
            if (!strcmp(propertyname,"getter")) return "_getFastestMandatoryMode";
            return nullptr;
        case 4:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 5:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 6:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 7:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        case 8:
            if (!strcmp(propertyname,"editable")) return "false";
            return nullptr;
        default: return nullptr;
    }
}

int Ieee80211ModeSetDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *Ieee80211ModeSetDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string Ieee80211ModeSetDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->_getSlowestMode(); return out.str();}
        case 1: {std::stringstream out; out << pp->_getFastestMode(); return out.str();}
        case 2: {std::stringstream out; out << pp->_getSlowestMandatoryMode(); return out.str();}
        case 3: {std::stringstream out; out << pp->_getFastestMandatoryMode(); return out.str();}
        case 4: return simtime2string(pp->getSifsTime());
        case 5: return simtime2string(pp->getSlotTime());
        case 6: return simtime2string(pp->getPhyRxStartDelay());
        case 7: return long2string(pp->getCwMin());
        case 8: return long2string(pp->getCwMax());
        default: return "";
    }
}

bool Ieee80211ModeSetDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *Ieee80211ModeSetDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        case 1: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        case 2: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        case 3: return omnetpp::opp_typename(typeid(IIeee80211Mode));
        default: return nullptr;
    };
}

void *Ieee80211ModeSetDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Ieee80211ModeSet *pp = (Ieee80211ModeSet *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(pp->_getSlowestMode()); break;
        case 1: return (void *)static_cast<omnetpp::cObject *>(pp->_getFastestMode()); break;
        case 2: return (void *)static_cast<omnetpp::cObject *>(pp->_getSlowestMandatoryMode()); break;
        case 3: return (void *)static_cast<omnetpp::cObject *>(pp->_getFastestMandatoryMode()); break;
        default: return nullptr;
    }
}

Ieee80211ConfigureRadioCommand::Ieee80211ConfigureRadioCommand() : ::inet::physicallayer::ConfigureRadioCommand()
{
    this->modeSet = nullptr;
    this->mode = nullptr;
    this->band = nullptr;
    this->channel = nullptr;
    this->channelNumber = -1;
}

Ieee80211ConfigureRadioCommand::Ieee80211ConfigureRadioCommand(const Ieee80211ConfigureRadioCommand& other) : ::inet::physicallayer::ConfigureRadioCommand(other)
{
    copy(other);
}

Ieee80211ConfigureRadioCommand::~Ieee80211ConfigureRadioCommand()
{
}

Ieee80211ConfigureRadioCommand& Ieee80211ConfigureRadioCommand::operator=(const Ieee80211ConfigureRadioCommand& other)
{
    if (this==&other) return *this;
    ::inet::physicallayer::ConfigureRadioCommand::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ConfigureRadioCommand::copy(const Ieee80211ConfigureRadioCommand& other)
{
    this->opMode = other.opMode;
    this->modeSet = other.modeSet;
    this->mode = other.mode;
    this->band = other.band;
    this->channel = other.channel;
    this->channelNumber = other.channelNumber;
}

void Ieee80211ConfigureRadioCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::physicallayer::ConfigureRadioCommand&)*this);
    doParsimPacking(b,this->opMode);
    doParsimPacking(b,this->modeSet);
    doParsimPacking(b,this->mode);
    doParsimPacking(b,this->band);
    doParsimPacking(b,this->channel);
    doParsimPacking(b,this->channelNumber);
}

void Ieee80211ConfigureRadioCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::physicallayer::ConfigureRadioCommand&)*this);
    doParsimUnpacking(b,this->opMode);
    doParsimUnpacking(b,this->modeSet);
    doParsimUnpacking(b,this->mode);
    doParsimUnpacking(b,this->band);
    doParsimUnpacking(b,this->channel);
    doParsimUnpacking(b,this->channelNumber);
}

const char * Ieee80211ConfigureRadioCommand::getOpMode() const
{
    return this->opMode.c_str();
}

void Ieee80211ConfigureRadioCommand::setOpMode(const char * opMode)
{
    this->opMode = opMode;
}

Ieee80211ModeSetPtr& Ieee80211ConfigureRadioCommand::getModeSet()
{
    return this->modeSet;
}

void Ieee80211ConfigureRadioCommand::setModeSet(const Ieee80211ModeSetPtr& modeSet)
{
    this->modeSet = modeSet;
}

IIeee80211ModePtr& Ieee80211ConfigureRadioCommand::getMode()
{
    return this->mode;
}

void Ieee80211ConfigureRadioCommand::setMode(const IIeee80211ModePtr& mode)
{
    this->mode = mode;
}

IIeee80211BandPtr& Ieee80211ConfigureRadioCommand::getBand()
{
    return this->band;
}

void Ieee80211ConfigureRadioCommand::setBand(const IIeee80211BandPtr& band)
{
    this->band = band;
}

Ieee80211ChannelPtr& Ieee80211ConfigureRadioCommand::getChannel()
{
    return this->channel;
}

void Ieee80211ConfigureRadioCommand::setChannel(const Ieee80211ChannelPtr& channel)
{
    this->channel = channel;
}

int Ieee80211ConfigureRadioCommand::getChannelNumber() const
{
    return this->channelNumber;
}

void Ieee80211ConfigureRadioCommand::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

Ieee80211TransmissionRequest::Ieee80211TransmissionRequest() : ::inet::physicallayer::TransmissionRequest()
{
    this->mode = nullptr;
    this->channelNumber = -1;
    this->channel = nullptr;
}

Ieee80211TransmissionRequest::Ieee80211TransmissionRequest(const Ieee80211TransmissionRequest& other) : ::inet::physicallayer::TransmissionRequest(other)
{
    copy(other);
}

Ieee80211TransmissionRequest::~Ieee80211TransmissionRequest()
{
}

Ieee80211TransmissionRequest& Ieee80211TransmissionRequest::operator=(const Ieee80211TransmissionRequest& other)
{
    if (this==&other) return *this;
    ::inet::physicallayer::TransmissionRequest::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211TransmissionRequest::copy(const Ieee80211TransmissionRequest& other)
{
    this->mode = other.mode;
    this->channelNumber = other.channelNumber;
    this->channel = other.channel;
}

void Ieee80211TransmissionRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::physicallayer::TransmissionRequest&)*this);
    doParsimPacking(b,this->mode);
    doParsimPacking(b,this->channelNumber);
    doParsimPacking(b,this->channel);
}

void Ieee80211TransmissionRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::physicallayer::TransmissionRequest&)*this);
    doParsimUnpacking(b,this->mode);
    doParsimUnpacking(b,this->channelNumber);
    doParsimUnpacking(b,this->channel);
}

IIeee80211ModePtr& Ieee80211TransmissionRequest::getMode()
{
    return this->mode;
}

void Ieee80211TransmissionRequest::setMode(const IIeee80211ModePtr& mode)
{
    this->mode = mode;
}

int Ieee80211TransmissionRequest::getChannelNumber() const
{
    return this->channelNumber;
}

void Ieee80211TransmissionRequest::setChannelNumber(int channelNumber)
{
    this->channelNumber = channelNumber;
}

Ieee80211ChannelPtr& Ieee80211TransmissionRequest::getChannel()
{
    return this->channel;
}

void Ieee80211TransmissionRequest::setChannel(const Ieee80211ChannelPtr& channel)
{
    this->channel = channel;
}

Ieee80211ReceptionIndication::Ieee80211ReceptionIndication() : ::inet::physicallayer::ReceptionIndication()
{
    this->mode = nullptr;
    this->channel = nullptr;
    this->snr = 0;
    this->lossRate = 0;
    this->recPow = 0;
    this->airtimeMetric = false;
    this->testFrameDuration = 0;
    this->testFrameError = 0;
    this->testFrameSize = 0;
}

Ieee80211ReceptionIndication::Ieee80211ReceptionIndication(const Ieee80211ReceptionIndication& other) : ::inet::physicallayer::ReceptionIndication(other)
{
    copy(other);
}

Ieee80211ReceptionIndication::~Ieee80211ReceptionIndication()
{
}

Ieee80211ReceptionIndication& Ieee80211ReceptionIndication::operator=(const Ieee80211ReceptionIndication& other)
{
    if (this==&other) return *this;
    ::inet::physicallayer::ReceptionIndication::operator=(other);
    copy(other);
    return *this;
}

void Ieee80211ReceptionIndication::copy(const Ieee80211ReceptionIndication& other)
{
    this->mode = other.mode;
    this->channel = other.channel;
    this->snr = other.snr;
    this->lossRate = other.lossRate;
    this->recPow = other.recPow;
    this->airtimeMetric = other.airtimeMetric;
    this->testFrameDuration = other.testFrameDuration;
    this->testFrameError = other.testFrameError;
    this->testFrameSize = other.testFrameSize;
}

void Ieee80211ReceptionIndication::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,(::inet::physicallayer::ReceptionIndication&)*this);
    doParsimPacking(b,this->mode);
    doParsimPacking(b,this->channel);
    doParsimPacking(b,this->snr);
    doParsimPacking(b,this->lossRate);
    doParsimPacking(b,this->recPow);
    doParsimPacking(b,this->airtimeMetric);
    doParsimPacking(b,this->testFrameDuration);
    doParsimPacking(b,this->testFrameError);
    doParsimPacking(b,this->testFrameSize);
}

void Ieee80211ReceptionIndication::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,(::inet::physicallayer::ReceptionIndication&)*this);
    doParsimUnpacking(b,this->mode);
    doParsimUnpacking(b,this->channel);
    doParsimUnpacking(b,this->snr);
    doParsimUnpacking(b,this->lossRate);
    doParsimUnpacking(b,this->recPow);
    doParsimUnpacking(b,this->airtimeMetric);
    doParsimUnpacking(b,this->testFrameDuration);
    doParsimUnpacking(b,this->testFrameError);
    doParsimUnpacking(b,this->testFrameSize);
}

IIeee80211ModePtr& Ieee80211ReceptionIndication::getMode()
{
    return this->mode;
}

void Ieee80211ReceptionIndication::setMode(const IIeee80211ModePtr& mode)
{
    this->mode = mode;
}

Ieee80211ChannelPtr& Ieee80211ReceptionIndication::getChannel()
{
    return this->channel;
}

void Ieee80211ReceptionIndication::setChannel(const Ieee80211ChannelPtr& channel)
{
    this->channel = channel;
}

double Ieee80211ReceptionIndication::getSnr() const
{
    return this->snr;
}

void Ieee80211ReceptionIndication::setSnr(double snr)
{
    this->snr = snr;
}

double Ieee80211ReceptionIndication::getLossRate() const
{
    return this->lossRate;
}

void Ieee80211ReceptionIndication::setLossRate(double lossRate)
{
    this->lossRate = lossRate;
}

double Ieee80211ReceptionIndication::getRecPow() const
{
    return this->recPow;
}

void Ieee80211ReceptionIndication::setRecPow(double recPow)
{
    this->recPow = recPow;
}

bool Ieee80211ReceptionIndication::getAirtimeMetric() const
{
    return this->airtimeMetric;
}

void Ieee80211ReceptionIndication::setAirtimeMetric(bool airtimeMetric)
{
    this->airtimeMetric = airtimeMetric;
}

double Ieee80211ReceptionIndication::getTestFrameDuration() const
{
    return this->testFrameDuration;
}

void Ieee80211ReceptionIndication::setTestFrameDuration(double testFrameDuration)
{
    this->testFrameDuration = testFrameDuration;
}

double Ieee80211ReceptionIndication::getTestFrameError() const
{
    return this->testFrameError;
}

void Ieee80211ReceptionIndication::setTestFrameError(double testFrameError)
{
    this->testFrameError = testFrameError;
}

int Ieee80211ReceptionIndication::getTestFrameSize() const
{
    return this->testFrameSize;
}

void Ieee80211ReceptionIndication::setTestFrameSize(int testFrameSize)
{
    this->testFrameSize = testFrameSize;
}

} // namespace physicallayer
} // namespace inet

