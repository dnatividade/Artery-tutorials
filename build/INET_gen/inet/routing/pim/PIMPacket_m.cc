//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/routing/pim/PIMPacket.msg.
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
#include "PIMPacket_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::PIMPacketType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::PIMPacketType"));
    e->insert(Hello, "Hello");
    e->insert(Register, "Register");
    e->insert(RegisterStop, "RegisterStop");
    e->insert(JoinPrune, "JoinPrune");
    e->insert(Bootstrap, "Bootstrap");
    e->insert(Assert, "Assert");
    e->insert(Graft, "Graft");
    e->insert(GraftAck, "GraftAck");
    e->insert(CandidateRPAdvertisement, "CandidateRPAdvertisement");
    e->insert(StateRefresh, "StateRefresh");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::PIMHelloOptionType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::PIMHelloOptionType"));
    e->insert(Holdtime, "Holdtime");
    e->insert(LANPruneDelay, "LANPruneDelay");
    e->insert(DRPriority, "DRPriority");
    e->insert(GenerationID, "GenerationID");
    e->insert(StateRefreshCapable, "StateRefreshCapable");
    e->insert(AddressList, "AddressList");
)

Register_Class(HelloOption)

HelloOption::HelloOption() : ::omnetpp::cObject()
{
    this->type = 0;
}

HelloOption::HelloOption(const HelloOption& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

HelloOption::~HelloOption()
{
}

HelloOption& HelloOption::operator=(const HelloOption& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void HelloOption::copy(const HelloOption& other)
{
    this->type = other.type;
}

void HelloOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->type);
}

void HelloOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->type);
}

short HelloOption::getType() const
{
    return this->type;
}

void HelloOption::setType(short type)
{
    this->type = type;
}

class HelloOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    HelloOptionDescriptor();
    virtual ~HelloOptionDescriptor();

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

Register_ClassDescriptor(HelloOptionDescriptor)

HelloOptionDescriptor::HelloOptionDescriptor() : omnetpp::cClassDescriptor("inet::HelloOption", "omnetpp::cObject")
{
    propertynames = nullptr;
}

HelloOptionDescriptor::~HelloOptionDescriptor()
{
    delete[] propertynames;
}

bool HelloOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HelloOption *>(obj)!=nullptr;
}

const char **HelloOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HelloOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HelloOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int HelloOptionDescriptor::getFieldTypeFlags(int field) const
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

const char *HelloOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "type",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int HelloOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HelloOptionDescriptor::getFieldTypeString(int field) const
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

const char **HelloOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *HelloOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::PIMHelloOptionType";
            return nullptr;
        default: return nullptr;
    }
}

int HelloOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HelloOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HelloOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getType(), "inet::PIMHelloOptionType");
        default: return "";
    }
}

bool HelloOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        case 0: pp->setType((inet::PIMHelloOptionType)string2enum(value, "inet::PIMHelloOptionType")); return true;
        default: return false;
    }
}

const char *HelloOptionDescriptor::getFieldStructName(int field) const
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

void *HelloOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HelloOption *pp = (HelloOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(HoldtimeOption)

HoldtimeOption::HoldtimeOption() : ::inet::HelloOption()
{
    this->setType(Holdtime);

    this->holdTime = 0;
}

HoldtimeOption::HoldtimeOption(const HoldtimeOption& other) : ::inet::HelloOption(other)
{
    copy(other);
}

HoldtimeOption::~HoldtimeOption()
{
}

HoldtimeOption& HoldtimeOption::operator=(const HoldtimeOption& other)
{
    if (this==&other) return *this;
    ::inet::HelloOption::operator=(other);
    copy(other);
    return *this;
}

void HoldtimeOption::copy(const HoldtimeOption& other)
{
    this->holdTime = other.holdTime;
}

void HoldtimeOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::HelloOption::parsimPack(b);
    doParsimPacking(b,this->holdTime);
}

void HoldtimeOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::HelloOption::parsimUnpack(b);
    doParsimUnpacking(b,this->holdTime);
}

uint16_t HoldtimeOption::getHoldTime() const
{
    return this->holdTime;
}

void HoldtimeOption::setHoldTime(uint16_t holdTime)
{
    this->holdTime = holdTime;
}

class HoldtimeOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    HoldtimeOptionDescriptor();
    virtual ~HoldtimeOptionDescriptor();

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

Register_ClassDescriptor(HoldtimeOptionDescriptor)

HoldtimeOptionDescriptor::HoldtimeOptionDescriptor() : omnetpp::cClassDescriptor("inet::HoldtimeOption", "inet::HelloOption")
{
    propertynames = nullptr;
}

HoldtimeOptionDescriptor::~HoldtimeOptionDescriptor()
{
    delete[] propertynames;
}

bool HoldtimeOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<HoldtimeOption *>(obj)!=nullptr;
}

const char **HoldtimeOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *HoldtimeOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int HoldtimeOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int HoldtimeOptionDescriptor::getFieldTypeFlags(int field) const
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

const char *HoldtimeOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "holdTime",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int HoldtimeOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *HoldtimeOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **HoldtimeOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *HoldtimeOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int HoldtimeOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *HoldtimeOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string HoldtimeOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getHoldTime());
        default: return "";
    }
}

bool HoldtimeOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        case 0: pp->setHoldTime(string2ulong(value)); return true;
        default: return false;
    }
}

const char *HoldtimeOptionDescriptor::getFieldStructName(int field) const
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

void *HoldtimeOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    HoldtimeOption *pp = (HoldtimeOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(LANPruneDelayOption)

LANPruneDelayOption::LANPruneDelayOption() : ::inet::HelloOption()
{
    this->setType(LANPruneDelay);

    this->propagationDelay = 0;
    this->overrideInterval = 0;
}

LANPruneDelayOption::LANPruneDelayOption(const LANPruneDelayOption& other) : ::inet::HelloOption(other)
{
    copy(other);
}

LANPruneDelayOption::~LANPruneDelayOption()
{
}

LANPruneDelayOption& LANPruneDelayOption::operator=(const LANPruneDelayOption& other)
{
    if (this==&other) return *this;
    ::inet::HelloOption::operator=(other);
    copy(other);
    return *this;
}

void LANPruneDelayOption::copy(const LANPruneDelayOption& other)
{
    this->propagationDelay = other.propagationDelay;
    this->overrideInterval = other.overrideInterval;
}

void LANPruneDelayOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::HelloOption::parsimPack(b);
    doParsimPacking(b,this->propagationDelay);
    doParsimPacking(b,this->overrideInterval);
}

void LANPruneDelayOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::HelloOption::parsimUnpack(b);
    doParsimUnpacking(b,this->propagationDelay);
    doParsimUnpacking(b,this->overrideInterval);
}

uint16_t LANPruneDelayOption::getPropagationDelay() const
{
    return this->propagationDelay;
}

void LANPruneDelayOption::setPropagationDelay(uint16_t propagationDelay)
{
    this->propagationDelay = propagationDelay;
}

uint16_t LANPruneDelayOption::getOverrideInterval() const
{
    return this->overrideInterval;
}

void LANPruneDelayOption::setOverrideInterval(uint16_t overrideInterval)
{
    this->overrideInterval = overrideInterval;
}

class LANPruneDelayOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    LANPruneDelayOptionDescriptor();
    virtual ~LANPruneDelayOptionDescriptor();

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

Register_ClassDescriptor(LANPruneDelayOptionDescriptor)

LANPruneDelayOptionDescriptor::LANPruneDelayOptionDescriptor() : omnetpp::cClassDescriptor("inet::LANPruneDelayOption", "inet::HelloOption")
{
    propertynames = nullptr;
}

LANPruneDelayOptionDescriptor::~LANPruneDelayOptionDescriptor()
{
    delete[] propertynames;
}

bool LANPruneDelayOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<LANPruneDelayOption *>(obj)!=nullptr;
}

const char **LANPruneDelayOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *LANPruneDelayOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int LANPruneDelayOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int LANPruneDelayOptionDescriptor::getFieldTypeFlags(int field) const
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

const char *LANPruneDelayOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "propagationDelay",
        "overrideInterval",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int LANPruneDelayOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "propagationDelay")==0) return base+0;
    if (fieldName[0]=='o' && strcmp(fieldName, "overrideInterval")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *LANPruneDelayOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint16_t",
        "uint16_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **LANPruneDelayOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *LANPruneDelayOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int LANPruneDelayOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    LANPruneDelayOption *pp = (LANPruneDelayOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *LANPruneDelayOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LANPruneDelayOption *pp = (LANPruneDelayOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string LANPruneDelayOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    LANPruneDelayOption *pp = (LANPruneDelayOption *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPropagationDelay());
        case 1: return ulong2string(pp->getOverrideInterval());
        default: return "";
    }
}

bool LANPruneDelayOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    LANPruneDelayOption *pp = (LANPruneDelayOption *)object; (void)pp;
    switch (field) {
        case 0: pp->setPropagationDelay(string2ulong(value)); return true;
        case 1: pp->setOverrideInterval(string2ulong(value)); return true;
        default: return false;
    }
}

const char *LANPruneDelayOptionDescriptor::getFieldStructName(int field) const
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

void *LANPruneDelayOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    LANPruneDelayOption *pp = (LANPruneDelayOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(DRPriorityOption)

DRPriorityOption::DRPriorityOption() : ::inet::HelloOption()
{
    this->setType(DRPriority);

    this->priority = 0;
}

DRPriorityOption::DRPriorityOption(const DRPriorityOption& other) : ::inet::HelloOption(other)
{
    copy(other);
}

DRPriorityOption::~DRPriorityOption()
{
}

DRPriorityOption& DRPriorityOption::operator=(const DRPriorityOption& other)
{
    if (this==&other) return *this;
    ::inet::HelloOption::operator=(other);
    copy(other);
    return *this;
}

void DRPriorityOption::copy(const DRPriorityOption& other)
{
    this->priority = other.priority;
}

void DRPriorityOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::HelloOption::parsimPack(b);
    doParsimPacking(b,this->priority);
}

void DRPriorityOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::HelloOption::parsimUnpack(b);
    doParsimUnpacking(b,this->priority);
}

uint32_t DRPriorityOption::getPriority() const
{
    return this->priority;
}

void DRPriorityOption::setPriority(uint32_t priority)
{
    this->priority = priority;
}

class DRPriorityOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    DRPriorityOptionDescriptor();
    virtual ~DRPriorityOptionDescriptor();

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

Register_ClassDescriptor(DRPriorityOptionDescriptor)

DRPriorityOptionDescriptor::DRPriorityOptionDescriptor() : omnetpp::cClassDescriptor("inet::DRPriorityOption", "inet::HelloOption")
{
    propertynames = nullptr;
}

DRPriorityOptionDescriptor::~DRPriorityOptionDescriptor()
{
    delete[] propertynames;
}

bool DRPriorityOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DRPriorityOption *>(obj)!=nullptr;
}

const char **DRPriorityOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DRPriorityOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DRPriorityOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int DRPriorityOptionDescriptor::getFieldTypeFlags(int field) const
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

const char *DRPriorityOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "priority",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int DRPriorityOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='p' && strcmp(fieldName, "priority")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DRPriorityOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **DRPriorityOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *DRPriorityOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int DRPriorityOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DRPriorityOption *pp = (DRPriorityOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DRPriorityOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DRPriorityOption *pp = (DRPriorityOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DRPriorityOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DRPriorityOption *pp = (DRPriorityOption *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getPriority());
        default: return "";
    }
}

bool DRPriorityOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DRPriorityOption *pp = (DRPriorityOption *)object; (void)pp;
    switch (field) {
        case 0: pp->setPriority(string2ulong(value)); return true;
        default: return false;
    }
}

const char *DRPriorityOptionDescriptor::getFieldStructName(int field) const
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

void *DRPriorityOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DRPriorityOption *pp = (DRPriorityOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(GenerationIDOption)

GenerationIDOption::GenerationIDOption() : ::inet::HelloOption()
{
    this->setType(GenerationID);

    this->generationID = 0;
}

GenerationIDOption::GenerationIDOption(const GenerationIDOption& other) : ::inet::HelloOption(other)
{
    copy(other);
}

GenerationIDOption::~GenerationIDOption()
{
}

GenerationIDOption& GenerationIDOption::operator=(const GenerationIDOption& other)
{
    if (this==&other) return *this;
    ::inet::HelloOption::operator=(other);
    copy(other);
    return *this;
}

void GenerationIDOption::copy(const GenerationIDOption& other)
{
    this->generationID = other.generationID;
}

void GenerationIDOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::HelloOption::parsimPack(b);
    doParsimPacking(b,this->generationID);
}

void GenerationIDOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::HelloOption::parsimUnpack(b);
    doParsimUnpacking(b,this->generationID);
}

uint32_t GenerationIDOption::getGenerationID() const
{
    return this->generationID;
}

void GenerationIDOption::setGenerationID(uint32_t generationID)
{
    this->generationID = generationID;
}

class GenerationIDOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    GenerationIDOptionDescriptor();
    virtual ~GenerationIDOptionDescriptor();

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

Register_ClassDescriptor(GenerationIDOptionDescriptor)

GenerationIDOptionDescriptor::GenerationIDOptionDescriptor() : omnetpp::cClassDescriptor("inet::GenerationIDOption", "inet::HelloOption")
{
    propertynames = nullptr;
}

GenerationIDOptionDescriptor::~GenerationIDOptionDescriptor()
{
    delete[] propertynames;
}

bool GenerationIDOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<GenerationIDOption *>(obj)!=nullptr;
}

const char **GenerationIDOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *GenerationIDOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int GenerationIDOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int GenerationIDOptionDescriptor::getFieldTypeFlags(int field) const
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

const char *GenerationIDOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "generationID",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int GenerationIDOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "generationID")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *GenerationIDOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **GenerationIDOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *GenerationIDOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int GenerationIDOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    GenerationIDOption *pp = (GenerationIDOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *GenerationIDOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GenerationIDOption *pp = (GenerationIDOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string GenerationIDOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    GenerationIDOption *pp = (GenerationIDOption *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getGenerationID());
        default: return "";
    }
}

bool GenerationIDOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    GenerationIDOption *pp = (GenerationIDOption *)object; (void)pp;
    switch (field) {
        case 0: pp->setGenerationID(string2ulong(value)); return true;
        default: return false;
    }
}

const char *GenerationIDOptionDescriptor::getFieldStructName(int field) const
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

void *GenerationIDOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    GenerationIDOption *pp = (GenerationIDOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

EncodedAddress::EncodedAddress()
{
    this->S = false;
    this->W = false;
    this->R = false;
}

void __doPacking(omnetpp::cCommBuffer *b, const EncodedAddress& a)
{
    doParsimPacking(b,a.IPaddress);
    doParsimPacking(b,a.S);
    doParsimPacking(b,a.W);
    doParsimPacking(b,a.R);
}

void __doUnpacking(omnetpp::cCommBuffer *b, EncodedAddress& a)
{
    doParsimUnpacking(b,a.IPaddress);
    doParsimUnpacking(b,a.S);
    doParsimUnpacking(b,a.W);
    doParsimUnpacking(b,a.R);
}

class EncodedAddressDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    EncodedAddressDescriptor();
    virtual ~EncodedAddressDescriptor();

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

Register_ClassDescriptor(EncodedAddressDescriptor)

EncodedAddressDescriptor::EncodedAddressDescriptor() : omnetpp::cClassDescriptor("inet::EncodedAddress", "")
{
    propertynames = nullptr;
}

EncodedAddressDescriptor::~EncodedAddressDescriptor()
{
    delete[] propertynames;
}

bool EncodedAddressDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<EncodedAddress *>(obj)!=nullptr;
}

const char **EncodedAddressDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *EncodedAddressDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int EncodedAddressDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int EncodedAddressDescriptor::getFieldTypeFlags(int field) const
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

const char *EncodedAddressDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "IPaddress",
        "S",
        "W",
        "R",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int EncodedAddressDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='I' && strcmp(fieldName, "IPaddress")==0) return base+0;
    if (fieldName[0]=='S' && strcmp(fieldName, "S")==0) return base+1;
    if (fieldName[0]=='W' && strcmp(fieldName, "W")==0) return base+2;
    if (fieldName[0]=='R' && strcmp(fieldName, "R")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *EncodedAddressDescriptor::getFieldTypeString(int field) const
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
        "bool",
        "bool",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **EncodedAddressDescriptor::getFieldPropertyNames(int field) const
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

const char *EncodedAddressDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int EncodedAddressDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *EncodedAddressDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string EncodedAddressDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->IPaddress; return out.str();}
        case 1: return bool2string(pp->S);
        case 2: return bool2string(pp->W);
        case 3: return bool2string(pp->R);
        default: return "";
    }
}

bool EncodedAddressDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        case 1: pp->S = string2bool(value); return true;
        case 2: pp->W = string2bool(value); return true;
        case 3: pp->R = string2bool(value); return true;
        default: return false;
    }
}

const char *EncodedAddressDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *EncodedAddressDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    EncodedAddress *pp = (EncodedAddress *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->IPaddress); break;
        default: return nullptr;
    }
}

Register_Class(JoinPruneGroup)

JoinPruneGroup::JoinPruneGroup() : ::omnetpp::cObject()
{
    joinedSourceAddress_arraysize = 0;
    this->joinedSourceAddress = 0;
    prunedSourceAddress_arraysize = 0;
    this->prunedSourceAddress = 0;
}

JoinPruneGroup::JoinPruneGroup(const JoinPruneGroup& other) : ::omnetpp::cObject(other)
{
    joinedSourceAddress_arraysize = 0;
    this->joinedSourceAddress = 0;
    prunedSourceAddress_arraysize = 0;
    this->prunedSourceAddress = 0;
    copy(other);
}

JoinPruneGroup::~JoinPruneGroup()
{
    delete [] this->joinedSourceAddress;
    delete [] this->prunedSourceAddress;
}

JoinPruneGroup& JoinPruneGroup::operator=(const JoinPruneGroup& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void JoinPruneGroup::copy(const JoinPruneGroup& other)
{
    this->groupAddress = other.groupAddress;
    delete [] this->joinedSourceAddress;
    this->joinedSourceAddress = (other.joinedSourceAddress_arraysize==0) ? nullptr : new EncodedAddress[other.joinedSourceAddress_arraysize];
    joinedSourceAddress_arraysize = other.joinedSourceAddress_arraysize;
    for (unsigned int i=0; i<joinedSourceAddress_arraysize; i++)
        this->joinedSourceAddress[i] = other.joinedSourceAddress[i];
    delete [] this->prunedSourceAddress;
    this->prunedSourceAddress = (other.prunedSourceAddress_arraysize==0) ? nullptr : new EncodedAddress[other.prunedSourceAddress_arraysize];
    prunedSourceAddress_arraysize = other.prunedSourceAddress_arraysize;
    for (unsigned int i=0; i<prunedSourceAddress_arraysize; i++)
        this->prunedSourceAddress[i] = other.prunedSourceAddress[i];
}

void JoinPruneGroup::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->groupAddress);
    b->pack(joinedSourceAddress_arraysize);
    doParsimArrayPacking(b,this->joinedSourceAddress,joinedSourceAddress_arraysize);
    b->pack(prunedSourceAddress_arraysize);
    doParsimArrayPacking(b,this->prunedSourceAddress,prunedSourceAddress_arraysize);
}

void JoinPruneGroup::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->groupAddress);
    delete [] this->joinedSourceAddress;
    b->unpack(joinedSourceAddress_arraysize);
    if (joinedSourceAddress_arraysize==0) {
        this->joinedSourceAddress = 0;
    } else {
        this->joinedSourceAddress = new EncodedAddress[joinedSourceAddress_arraysize];
        doParsimArrayUnpacking(b,this->joinedSourceAddress,joinedSourceAddress_arraysize);
    }
    delete [] this->prunedSourceAddress;
    b->unpack(prunedSourceAddress_arraysize);
    if (prunedSourceAddress_arraysize==0) {
        this->prunedSourceAddress = 0;
    } else {
        this->prunedSourceAddress = new EncodedAddress[prunedSourceAddress_arraysize];
        doParsimArrayUnpacking(b,this->prunedSourceAddress,prunedSourceAddress_arraysize);
    }
}

IPv4Address& JoinPruneGroup::getGroupAddress()
{
    return this->groupAddress;
}

void JoinPruneGroup::setGroupAddress(const IPv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

void JoinPruneGroup::setJoinedSourceAddressArraySize(unsigned int size)
{
    EncodedAddress *joinedSourceAddress2 = (size==0) ? nullptr : new EncodedAddress[size];
    unsigned int sz = joinedSourceAddress_arraysize < size ? joinedSourceAddress_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        joinedSourceAddress2[i] = this->joinedSourceAddress[i];
    joinedSourceAddress_arraysize = size;
    delete [] this->joinedSourceAddress;
    this->joinedSourceAddress = joinedSourceAddress2;
}

unsigned int JoinPruneGroup::getJoinedSourceAddressArraySize() const
{
    return joinedSourceAddress_arraysize;
}

EncodedAddress& JoinPruneGroup::getJoinedSourceAddress(unsigned int k)
{
    if (k>=joinedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", joinedSourceAddress_arraysize, k);
    return this->joinedSourceAddress[k];
}

void JoinPruneGroup::setJoinedSourceAddress(unsigned int k, const EncodedAddress& joinedSourceAddress)
{
    if (k>=joinedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", joinedSourceAddress_arraysize, k);
    this->joinedSourceAddress[k] = joinedSourceAddress;
}

void JoinPruneGroup::setPrunedSourceAddressArraySize(unsigned int size)
{
    EncodedAddress *prunedSourceAddress2 = (size==0) ? nullptr : new EncodedAddress[size];
    unsigned int sz = prunedSourceAddress_arraysize < size ? prunedSourceAddress_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        prunedSourceAddress2[i] = this->prunedSourceAddress[i];
    prunedSourceAddress_arraysize = size;
    delete [] this->prunedSourceAddress;
    this->prunedSourceAddress = prunedSourceAddress2;
}

unsigned int JoinPruneGroup::getPrunedSourceAddressArraySize() const
{
    return prunedSourceAddress_arraysize;
}

EncodedAddress& JoinPruneGroup::getPrunedSourceAddress(unsigned int k)
{
    if (k>=prunedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", prunedSourceAddress_arraysize, k);
    return this->prunedSourceAddress[k];
}

void JoinPruneGroup::setPrunedSourceAddress(unsigned int k, const EncodedAddress& prunedSourceAddress)
{
    if (k>=prunedSourceAddress_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", prunedSourceAddress_arraysize, k);
    this->prunedSourceAddress[k] = prunedSourceAddress;
}

class JoinPruneGroupDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    JoinPruneGroupDescriptor();
    virtual ~JoinPruneGroupDescriptor();

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

Register_ClassDescriptor(JoinPruneGroupDescriptor)

JoinPruneGroupDescriptor::JoinPruneGroupDescriptor() : omnetpp::cClassDescriptor("inet::JoinPruneGroup", "omnetpp::cObject")
{
    propertynames = nullptr;
}

JoinPruneGroupDescriptor::~JoinPruneGroupDescriptor()
{
    delete[] propertynames;
}

bool JoinPruneGroupDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<JoinPruneGroup *>(obj)!=nullptr;
}

const char **JoinPruneGroupDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *JoinPruneGroupDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int JoinPruneGroupDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int JoinPruneGroupDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *JoinPruneGroupDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "joinedSourceAddress",
        "prunedSourceAddress",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int JoinPruneGroupDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinedSourceAddress")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "prunedSourceAddress")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *JoinPruneGroupDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "EncodedAddress",
        "EncodedAddress",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **JoinPruneGroupDescriptor::getFieldPropertyNames(int field) const
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

const char *JoinPruneGroupDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int JoinPruneGroupDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        case 1: return pp->getJoinedSourceAddressArraySize();
        case 2: return pp->getPrunedSourceAddressArraySize();
        default: return 0;
    }
}

const char *JoinPruneGroupDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string JoinPruneGroupDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getJoinedSourceAddress(i); return out.str();}
        case 2: {std::stringstream out; out << pp->getPrunedSourceAddress(i); return out.str();}
        default: return "";
    }
}

bool JoinPruneGroupDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *JoinPruneGroupDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 1: return omnetpp::opp_typename(typeid(EncodedAddress));
        case 2: return omnetpp::opp_typename(typeid(EncodedAddress));
        default: return nullptr;
    };
}

void *JoinPruneGroupDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    JoinPruneGroup *pp = (JoinPruneGroup *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        case 1: return (void *)(&pp->getJoinedSourceAddress(i)); break;
        case 2: return (void *)(&pp->getPrunedSourceAddress(i)); break;
        default: return nullptr;
    }
}

Register_Class(PIMPacket)

PIMPacket::PIMPacket(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->version = 2;
    this->type = 0;
}

PIMPacket::PIMPacket(const PIMPacket& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

PIMPacket::~PIMPacket()
{
}

PIMPacket& PIMPacket::operator=(const PIMPacket& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMPacket::copy(const PIMPacket& other)
{
    this->version = other.version;
    this->type = other.type;
}

void PIMPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->version);
    doParsimPacking(b,this->type);
}

void PIMPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->version);
    doParsimUnpacking(b,this->type);
}

short PIMPacket::getVersion() const
{
    return this->version;
}

void PIMPacket::setVersion(short version)
{
    this->version = version;
}

short PIMPacket::getType() const
{
    return this->type;
}

void PIMPacket::setType(short type)
{
    this->type = type;
}

class PIMPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMPacketDescriptor();
    virtual ~PIMPacketDescriptor();

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

Register_ClassDescriptor(PIMPacketDescriptor)

PIMPacketDescriptor::PIMPacketDescriptor() : omnetpp::cClassDescriptor("inet::PIMPacket", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

PIMPacketDescriptor::~PIMPacketDescriptor()
{
    delete[] propertynames;
}

bool PIMPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMPacket *>(obj)!=nullptr;
}

const char **PIMPacketDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMPacketDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int PIMPacketDescriptor::getFieldTypeFlags(int field) const
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

const char *PIMPacketDescriptor::getFieldName(int field) const
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
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int PIMPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='v' && strcmp(fieldName, "version")==0) return base+0;
    if (fieldName[0]=='t' && strcmp(fieldName, "type")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "short",
        "short",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **PIMPacketDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMPacketDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1:
            if (!strcmp(propertyname,"enum")) return "inet::PIMPacketType";
            return nullptr;
        default: return nullptr;
    }
}

int PIMPacketDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PIMPacketDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMPacketDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getVersion());
        case 1: return enum2string(pp->getType(), "inet::PIMPacketType");
        default: return "";
    }
}

bool PIMPacketDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        case 0: pp->setVersion(string2long(value)); return true;
        case 1: pp->setType((inet::PIMPacketType)string2enum(value, "inet::PIMPacketType")); return true;
        default: return false;
    }
}

const char *PIMPacketDescriptor::getFieldStructName(int field) const
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

void *PIMPacketDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMPacket *pp = (PIMPacket *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

PIMHello_Base::PIMHello_Base(const char *name, short kind) : ::inet::PIMPacket(name,kind)
{
    this->setType(Hello);

}

PIMHello_Base::PIMHello_Base(const PIMHello_Base& other) : ::inet::PIMPacket(other)
{
    copy(other);
}

PIMHello_Base::~PIMHello_Base()
{
}

PIMHello_Base& PIMHello_Base::operator=(const PIMHello_Base& other)
{
    if (this==&other) return *this;
    ::inet::PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMHello_Base::copy(const PIMHello_Base& other)
{
}

void PIMHello_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PIMPacket::parsimPack(b);
    // field options is abstract -- please do packing in customized class
}

void PIMHello_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PIMPacket::parsimUnpack(b);
    // field options is abstract -- please do unpacking in customized class
}

class PIMHelloDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMHelloDescriptor();
    virtual ~PIMHelloDescriptor();

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

Register_ClassDescriptor(PIMHelloDescriptor)

PIMHelloDescriptor::PIMHelloDescriptor() : omnetpp::cClassDescriptor("inet::PIMHello", "inet::PIMPacket")
{
    propertynames = nullptr;
}

PIMHelloDescriptor::~PIMHelloDescriptor()
{
    delete[] propertynames;
}

bool PIMHelloDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMHello_Base *>(obj)!=nullptr;
}

const char **PIMHelloDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMHelloDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMHelloDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int PIMHelloDescriptor::getFieldTypeFlags(int field) const
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

const char *PIMHelloDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "options",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int PIMHelloDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMHelloDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "HelloOptionPtr",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **PIMHelloDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMHelloDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PIMHelloDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMHello_Base *pp = (PIMHello_Base *)object; (void)pp;
    switch (field) {
        case 0: return pp->getOptionsArraySize();
        default: return 0;
    }
}

const char *PIMHelloDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMHello_Base *pp = (PIMHello_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMHelloDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMHello_Base *pp = (PIMHello_Base *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getOptions(i); return out.str();}
        default: return "";
    }
}

bool PIMHelloDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMHello_Base *pp = (PIMHello_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PIMHelloDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(HelloOptionPtr));
        default: return nullptr;
    };
}

void *PIMHelloDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMHello_Base *pp = (PIMHello_Base *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getOptions(i)); break;
        default: return nullptr;
    }
}

Register_Class(PIMJoinPrune)

PIMJoinPrune::PIMJoinPrune(const char *name, short kind) : ::inet::PIMPacket(name,kind)
{
    this->setType(JoinPrune);

    this->holdTime = 0;
    joinPruneGroups_arraysize = 0;
    this->joinPruneGroups = 0;
}

PIMJoinPrune::PIMJoinPrune(const PIMJoinPrune& other) : ::inet::PIMPacket(other)
{
    joinPruneGroups_arraysize = 0;
    this->joinPruneGroups = 0;
    copy(other);
}

PIMJoinPrune::~PIMJoinPrune()
{
    delete [] this->joinPruneGroups;
}

PIMJoinPrune& PIMJoinPrune::operator=(const PIMJoinPrune& other)
{
    if (this==&other) return *this;
    ::inet::PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMJoinPrune::copy(const PIMJoinPrune& other)
{
    this->upstreamNeighborAddress = other.upstreamNeighborAddress;
    this->holdTime = other.holdTime;
    delete [] this->joinPruneGroups;
    this->joinPruneGroups = (other.joinPruneGroups_arraysize==0) ? nullptr : new JoinPruneGroup[other.joinPruneGroups_arraysize];
    joinPruneGroups_arraysize = other.joinPruneGroups_arraysize;
    for (unsigned int i=0; i<joinPruneGroups_arraysize; i++)
        this->joinPruneGroups[i] = other.joinPruneGroups[i];
}

void PIMJoinPrune::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PIMPacket::parsimPack(b);
    doParsimPacking(b,this->upstreamNeighborAddress);
    doParsimPacking(b,this->holdTime);
    b->pack(joinPruneGroups_arraysize);
    doParsimArrayPacking(b,this->joinPruneGroups,joinPruneGroups_arraysize);
}

void PIMJoinPrune::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PIMPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->upstreamNeighborAddress);
    doParsimUnpacking(b,this->holdTime);
    delete [] this->joinPruneGroups;
    b->unpack(joinPruneGroups_arraysize);
    if (joinPruneGroups_arraysize==0) {
        this->joinPruneGroups = 0;
    } else {
        this->joinPruneGroups = new JoinPruneGroup[joinPruneGroups_arraysize];
        doParsimArrayUnpacking(b,this->joinPruneGroups,joinPruneGroups_arraysize);
    }
}

IPv4Address& PIMJoinPrune::getUpstreamNeighborAddress()
{
    return this->upstreamNeighborAddress;
}

void PIMJoinPrune::setUpstreamNeighborAddress(const IPv4Address& upstreamNeighborAddress)
{
    this->upstreamNeighborAddress = upstreamNeighborAddress;
}

int PIMJoinPrune::getHoldTime() const
{
    return this->holdTime;
}

void PIMJoinPrune::setHoldTime(int holdTime)
{
    this->holdTime = holdTime;
}

void PIMJoinPrune::setJoinPruneGroupsArraySize(unsigned int size)
{
    JoinPruneGroup *joinPruneGroups2 = (size==0) ? nullptr : new JoinPruneGroup[size];
    unsigned int sz = joinPruneGroups_arraysize < size ? joinPruneGroups_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        joinPruneGroups2[i] = this->joinPruneGroups[i];
    joinPruneGroups_arraysize = size;
    delete [] this->joinPruneGroups;
    this->joinPruneGroups = joinPruneGroups2;
}

unsigned int PIMJoinPrune::getJoinPruneGroupsArraySize() const
{
    return joinPruneGroups_arraysize;
}

JoinPruneGroup& PIMJoinPrune::getJoinPruneGroups(unsigned int k)
{
    if (k>=joinPruneGroups_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", joinPruneGroups_arraysize, k);
    return this->joinPruneGroups[k];
}

void PIMJoinPrune::setJoinPruneGroups(unsigned int k, const JoinPruneGroup& joinPruneGroups)
{
    if (k>=joinPruneGroups_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", joinPruneGroups_arraysize, k);
    this->joinPruneGroups[k] = joinPruneGroups;
}

class PIMJoinPruneDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMJoinPruneDescriptor();
    virtual ~PIMJoinPruneDescriptor();

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

Register_ClassDescriptor(PIMJoinPruneDescriptor)

PIMJoinPruneDescriptor::PIMJoinPruneDescriptor() : omnetpp::cClassDescriptor("inet::PIMJoinPrune", "inet::PIMPacket")
{
    propertynames = nullptr;
}

PIMJoinPruneDescriptor::~PIMJoinPruneDescriptor()
{
    delete[] propertynames;
}

bool PIMJoinPruneDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMJoinPrune *>(obj)!=nullptr;
}

const char **PIMJoinPruneDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMJoinPruneDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMJoinPruneDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 3+basedesc->getFieldCount() : 3;
}

unsigned int PIMJoinPruneDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<3) ? fieldTypeFlags[field] : 0;
}

const char *PIMJoinPruneDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "upstreamNeighborAddress",
        "holdTime",
        "joinPruneGroups",
    };
    return (field>=0 && field<3) ? fieldNames[field] : nullptr;
}

int PIMJoinPruneDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='u' && strcmp(fieldName, "upstreamNeighborAddress")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "holdTime")==0) return base+1;
    if (fieldName[0]=='j' && strcmp(fieldName, "joinPruneGroups")==0) return base+2;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMJoinPruneDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "IPv4Address",
        "int",
        "JoinPruneGroup",
    };
    return (field>=0 && field<3) ? fieldTypeStrings[field] : nullptr;
}

const char **PIMJoinPruneDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMJoinPruneDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PIMJoinPruneDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        case 2: return pp->getJoinPruneGroupsArraySize();
        default: return 0;
    }
}

const char *PIMJoinPruneDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMJoinPruneDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getUpstreamNeighborAddress(); return out.str();}
        case 1: return long2string(pp->getHoldTime());
        case 2: {std::stringstream out; out << pp->getJoinPruneGroups(i); return out.str();}
        default: return "";
    }
}

bool PIMJoinPruneDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        case 1: pp->setHoldTime(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMJoinPruneDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(IPv4Address));
        case 2: return omnetpp::opp_typename(typeid(JoinPruneGroup));
        default: return nullptr;
    };
}

void *PIMJoinPruneDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMJoinPrune *pp = (PIMJoinPrune *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getUpstreamNeighborAddress()); break;
        case 2: return (void *)static_cast<omnetpp::cObject *>(&pp->getJoinPruneGroups(i)); break;
        default: return nullptr;
    }
}

Register_Class(PIMAssert)

PIMAssert::PIMAssert(const char *name, short kind) : ::inet::PIMPacket(name,kind)
{
    this->setType(Assert);

    this->R = false;
    this->metric = 0;
    this->metricPreference = 0;
}

PIMAssert::PIMAssert(const PIMAssert& other) : ::inet::PIMPacket(other)
{
    copy(other);
}

PIMAssert::~PIMAssert()
{
}

PIMAssert& PIMAssert::operator=(const PIMAssert& other)
{
    if (this==&other) return *this;
    ::inet::PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMAssert::copy(const PIMAssert& other)
{
    this->groupAddress = other.groupAddress;
    this->sourceAddress = other.sourceAddress;
    this->R = other.R;
    this->metric = other.metric;
    this->metricPreference = other.metricPreference;
}

void PIMAssert::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PIMPacket::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->R);
    doParsimPacking(b,this->metric);
    doParsimPacking(b,this->metricPreference);
}

void PIMAssert::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PIMPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->R);
    doParsimUnpacking(b,this->metric);
    doParsimUnpacking(b,this->metricPreference);
}

IPv4Address& PIMAssert::getGroupAddress()
{
    return this->groupAddress;
}

void PIMAssert::setGroupAddress(const IPv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

IPv4Address& PIMAssert::getSourceAddress()
{
    return this->sourceAddress;
}

void PIMAssert::setSourceAddress(const IPv4Address& sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

bool PIMAssert::getR() const
{
    return this->R;
}

void PIMAssert::setR(bool R)
{
    this->R = R;
}

int PIMAssert::getMetric() const
{
    return this->metric;
}

void PIMAssert::setMetric(int metric)
{
    this->metric = metric;
}

int PIMAssert::getMetricPreference() const
{
    return this->metricPreference;
}

void PIMAssert::setMetricPreference(int metricPreference)
{
    this->metricPreference = metricPreference;
}

class PIMAssertDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMAssertDescriptor();
    virtual ~PIMAssertDescriptor();

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

Register_ClassDescriptor(PIMAssertDescriptor)

PIMAssertDescriptor::PIMAssertDescriptor() : omnetpp::cClassDescriptor("inet::PIMAssert", "inet::PIMPacket")
{
    propertynames = nullptr;
}

PIMAssertDescriptor::~PIMAssertDescriptor()
{
    delete[] propertynames;
}

bool PIMAssertDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMAssert *>(obj)!=nullptr;
}

const char **PIMAssertDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMAssertDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMAssertDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount() : 5;
}

unsigned int PIMAssertDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *PIMAssertDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "sourceAddress",
        "R",
        "metric",
        "metricPreference",
    };
    return (field>=0 && field<5) ? fieldNames[field] : nullptr;
}

int PIMAssertDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+1;
    if (fieldName[0]=='R' && strcmp(fieldName, "R")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "metricPreference")==0) return base+4;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMAssertDescriptor::getFieldTypeString(int field) const
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
        "bool",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : nullptr;
}

const char **PIMAssertDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMAssertDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PIMAssertDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PIMAssertDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMAssertDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSourceAddress(); return out.str();}
        case 2: return bool2string(pp->getR());
        case 3: return long2string(pp->getMetric());
        case 4: return long2string(pp->getMetricPreference());
        default: return "";
    }
}

bool PIMAssertDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        case 2: pp->setR(string2bool(value)); return true;
        case 3: pp->setMetric(string2long(value)); return true;
        case 4: pp->setMetricPreference(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMAssertDescriptor::getFieldStructName(int field) const
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

void *PIMAssertDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMAssert *pp = (PIMAssert *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        case 1: return (void *)(&pp->getSourceAddress()); break;
        default: return nullptr;
    }
}

Register_Class(PIMGraft)

PIMGraft::PIMGraft(const char *name, short kind) : ::inet::PIMJoinPrune(name,kind)
{
    this->setType(Graft);
    this->setHoldTime(0);
}

PIMGraft::PIMGraft(const PIMGraft& other) : ::inet::PIMJoinPrune(other)
{
    copy(other);
}

PIMGraft::~PIMGraft()
{
}

PIMGraft& PIMGraft::operator=(const PIMGraft& other)
{
    if (this==&other) return *this;
    ::inet::PIMJoinPrune::operator=(other);
    copy(other);
    return *this;
}

void PIMGraft::copy(const PIMGraft& other)
{
}

void PIMGraft::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PIMJoinPrune::parsimPack(b);
}

void PIMGraft::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PIMJoinPrune::parsimUnpack(b);
}

class PIMGraftDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMGraftDescriptor();
    virtual ~PIMGraftDescriptor();

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

Register_ClassDescriptor(PIMGraftDescriptor)

PIMGraftDescriptor::PIMGraftDescriptor() : omnetpp::cClassDescriptor("inet::PIMGraft", "inet::PIMJoinPrune")
{
    propertynames = nullptr;
}

PIMGraftDescriptor::~PIMGraftDescriptor()
{
    delete[] propertynames;
}

bool PIMGraftDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMGraft *>(obj)!=nullptr;
}

const char **PIMGraftDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMGraftDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMGraftDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int PIMGraftDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *PIMGraftDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int PIMGraftDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMGraftDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **PIMGraftDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMGraftDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PIMGraftDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PIMGraftDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMGraftDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool PIMGraftDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PIMGraftDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *PIMGraftDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMGraft *pp = (PIMGraft *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PIMGraftAck)

PIMGraftAck::PIMGraftAck(const char *name, short kind) : ::inet::PIMGraft(name,kind)
{
    this->setType(GraftAck);
}

PIMGraftAck::PIMGraftAck(const PIMGraftAck& other) : ::inet::PIMGraft(other)
{
    copy(other);
}

PIMGraftAck::~PIMGraftAck()
{
}

PIMGraftAck& PIMGraftAck::operator=(const PIMGraftAck& other)
{
    if (this==&other) return *this;
    ::inet::PIMGraft::operator=(other);
    copy(other);
    return *this;
}

void PIMGraftAck::copy(const PIMGraftAck& other)
{
}

void PIMGraftAck::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PIMGraft::parsimPack(b);
}

void PIMGraftAck::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PIMGraft::parsimUnpack(b);
}

class PIMGraftAckDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMGraftAckDescriptor();
    virtual ~PIMGraftAckDescriptor();

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

Register_ClassDescriptor(PIMGraftAckDescriptor)

PIMGraftAckDescriptor::PIMGraftAckDescriptor() : omnetpp::cClassDescriptor("inet::PIMGraftAck", "inet::PIMGraft")
{
    propertynames = nullptr;
}

PIMGraftAckDescriptor::~PIMGraftAckDescriptor()
{
    delete[] propertynames;
}

bool PIMGraftAckDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMGraftAck *>(obj)!=nullptr;
}

const char **PIMGraftAckDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMGraftAckDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMGraftAckDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int PIMGraftAckDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *PIMGraftAckDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int PIMGraftAckDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMGraftAckDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **PIMGraftAckDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMGraftAckDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PIMGraftAckDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PIMGraftAckDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMGraftAckDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool PIMGraftAckDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PIMGraftAckDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *PIMGraftAckDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMGraftAck *pp = (PIMGraftAck *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PIMStateRefresh)

PIMStateRefresh::PIMStateRefresh(const char *name, short kind) : ::inet::PIMPacket(name,kind)
{
    this->setType(StateRefresh);

    this->metric = 0;
    this->metricPreference = 0;
    this->maskLen = 0;
    this->ttl = 0;
    this->P = false;
    this->interval = 0;
}

PIMStateRefresh::PIMStateRefresh(const PIMStateRefresh& other) : ::inet::PIMPacket(other)
{
    copy(other);
}

PIMStateRefresh::~PIMStateRefresh()
{
}

PIMStateRefresh& PIMStateRefresh::operator=(const PIMStateRefresh& other)
{
    if (this==&other) return *this;
    ::inet::PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMStateRefresh::copy(const PIMStateRefresh& other)
{
    this->groupAddress = other.groupAddress;
    this->sourceAddress = other.sourceAddress;
    this->originatorAddress = other.originatorAddress;
    this->metric = other.metric;
    this->metricPreference = other.metricPreference;
    this->maskLen = other.maskLen;
    this->ttl = other.ttl;
    this->P = other.P;
    this->interval = other.interval;
}

void PIMStateRefresh::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PIMPacket::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
    doParsimPacking(b,this->sourceAddress);
    doParsimPacking(b,this->originatorAddress);
    doParsimPacking(b,this->metric);
    doParsimPacking(b,this->metricPreference);
    doParsimPacking(b,this->maskLen);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->P);
    doParsimPacking(b,this->interval);
}

void PIMStateRefresh::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PIMPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
    doParsimUnpacking(b,this->sourceAddress);
    doParsimUnpacking(b,this->originatorAddress);
    doParsimUnpacking(b,this->metric);
    doParsimUnpacking(b,this->metricPreference);
    doParsimUnpacking(b,this->maskLen);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->P);
    doParsimUnpacking(b,this->interval);
}

IPv4Address& PIMStateRefresh::getGroupAddress()
{
    return this->groupAddress;
}

void PIMStateRefresh::setGroupAddress(const IPv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

IPv4Address& PIMStateRefresh::getSourceAddress()
{
    return this->sourceAddress;
}

void PIMStateRefresh::setSourceAddress(const IPv4Address& sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

IPv4Address& PIMStateRefresh::getOriginatorAddress()
{
    return this->originatorAddress;
}

void PIMStateRefresh::setOriginatorAddress(const IPv4Address& originatorAddress)
{
    this->originatorAddress = originatorAddress;
}

int PIMStateRefresh::getMetric() const
{
    return this->metric;
}

void PIMStateRefresh::setMetric(int metric)
{
    this->metric = metric;
}

int PIMStateRefresh::getMetricPreference() const
{
    return this->metricPreference;
}

void PIMStateRefresh::setMetricPreference(int metricPreference)
{
    this->metricPreference = metricPreference;
}

short PIMStateRefresh::getMaskLen() const
{
    return this->maskLen;
}

void PIMStateRefresh::setMaskLen(short maskLen)
{
    this->maskLen = maskLen;
}

short PIMStateRefresh::getTtl() const
{
    return this->ttl;
}

void PIMStateRefresh::setTtl(short ttl)
{
    this->ttl = ttl;
}

bool PIMStateRefresh::getP() const
{
    return this->P;
}

void PIMStateRefresh::setP(bool P)
{
    this->P = P;
}

int PIMStateRefresh::getInterval() const
{
    return this->interval;
}

void PIMStateRefresh::setInterval(int interval)
{
    this->interval = interval;
}

class PIMStateRefreshDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMStateRefreshDescriptor();
    virtual ~PIMStateRefreshDescriptor();

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

Register_ClassDescriptor(PIMStateRefreshDescriptor)

PIMStateRefreshDescriptor::PIMStateRefreshDescriptor() : omnetpp::cClassDescriptor("inet::PIMStateRefresh", "inet::PIMPacket")
{
    propertynames = nullptr;
}

PIMStateRefreshDescriptor::~PIMStateRefreshDescriptor()
{
    delete[] propertynames;
}

bool PIMStateRefreshDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMStateRefresh *>(obj)!=nullptr;
}

const char **PIMStateRefreshDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMStateRefreshDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMStateRefreshDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 9+basedesc->getFieldCount() : 9;
}

unsigned int PIMStateRefreshDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<9) ? fieldTypeFlags[field] : 0;
}

const char *PIMStateRefreshDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "sourceAddress",
        "originatorAddress",
        "metric",
        "metricPreference",
        "maskLen",
        "ttl",
        "P",
        "interval",
    };
    return (field>=0 && field<9) ? fieldNames[field] : nullptr;
}

int PIMStateRefreshDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+1;
    if (fieldName[0]=='o' && strcmp(fieldName, "originatorAddress")==0) return base+2;
    if (fieldName[0]=='m' && strcmp(fieldName, "metric")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "metricPreference")==0) return base+4;
    if (fieldName[0]=='m' && strcmp(fieldName, "maskLen")==0) return base+5;
    if (fieldName[0]=='t' && strcmp(fieldName, "ttl")==0) return base+6;
    if (fieldName[0]=='P' && strcmp(fieldName, "P")==0) return base+7;
    if (fieldName[0]=='i' && strcmp(fieldName, "interval")==0) return base+8;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMStateRefreshDescriptor::getFieldTypeString(int field) const
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
        "IPv4Address",
        "int",
        "int",
        "short",
        "short",
        "bool",
        "int",
    };
    return (field>=0 && field<9) ? fieldTypeStrings[field] : nullptr;
}

const char **PIMStateRefreshDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMStateRefreshDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PIMStateRefreshDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PIMStateRefreshDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMStateRefreshDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSourceAddress(); return out.str();}
        case 2: {std::stringstream out; out << pp->getOriginatorAddress(); return out.str();}
        case 3: return long2string(pp->getMetric());
        case 4: return long2string(pp->getMetricPreference());
        case 5: return long2string(pp->getMaskLen());
        case 6: return long2string(pp->getTtl());
        case 7: return bool2string(pp->getP());
        case 8: return long2string(pp->getInterval());
        default: return "";
    }
}

bool PIMStateRefreshDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        case 3: pp->setMetric(string2long(value)); return true;
        case 4: pp->setMetricPreference(string2long(value)); return true;
        case 5: pp->setMaskLen(string2long(value)); return true;
        case 6: pp->setTtl(string2long(value)); return true;
        case 7: pp->setP(string2bool(value)); return true;
        case 8: pp->setInterval(string2long(value)); return true;
        default: return false;
    }
}

const char *PIMStateRefreshDescriptor::getFieldStructName(int field) const
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
        case 2: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *PIMStateRefreshDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMStateRefresh *pp = (PIMStateRefresh *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        case 1: return (void *)(&pp->getSourceAddress()); break;
        case 2: return (void *)(&pp->getOriginatorAddress()); break;
        default: return nullptr;
    }
}

Register_Class(PIMRegister)

PIMRegister::PIMRegister(const char *name, short kind) : ::inet::PIMPacket(name,kind)
{
    this->setType(Register);

    this->B = false;
    this->N = false;
}

PIMRegister::PIMRegister(const PIMRegister& other) : ::inet::PIMPacket(other)
{
    copy(other);
}

PIMRegister::~PIMRegister()
{
}

PIMRegister& PIMRegister::operator=(const PIMRegister& other)
{
    if (this==&other) return *this;
    ::inet::PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMRegister::copy(const PIMRegister& other)
{
    this->B = other.B;
    this->N = other.N;
}

void PIMRegister::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PIMPacket::parsimPack(b);
    doParsimPacking(b,this->B);
    doParsimPacking(b,this->N);
}

void PIMRegister::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PIMPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->B);
    doParsimUnpacking(b,this->N);
}

bool PIMRegister::getB() const
{
    return this->B;
}

void PIMRegister::setB(bool B)
{
    this->B = B;
}

bool PIMRegister::getN() const
{
    return this->N;
}

void PIMRegister::setN(bool N)
{
    this->N = N;
}

class PIMRegisterDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMRegisterDescriptor();
    virtual ~PIMRegisterDescriptor();

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

Register_ClassDescriptor(PIMRegisterDescriptor)

PIMRegisterDescriptor::PIMRegisterDescriptor() : omnetpp::cClassDescriptor("inet::PIMRegister", "inet::PIMPacket")
{
    propertynames = nullptr;
}

PIMRegisterDescriptor::~PIMRegisterDescriptor()
{
    delete[] propertynames;
}

bool PIMRegisterDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMRegister *>(obj)!=nullptr;
}

const char **PIMRegisterDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMRegisterDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMRegisterDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int PIMRegisterDescriptor::getFieldTypeFlags(int field) const
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

const char *PIMRegisterDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "B",
        "N",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int PIMRegisterDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='B' && strcmp(fieldName, "B")==0) return base+0;
    if (fieldName[0]=='N' && strcmp(fieldName, "N")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMRegisterDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **PIMRegisterDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMRegisterDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PIMRegisterDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PIMRegisterDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMRegisterDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        case 0: return bool2string(pp->getB());
        case 1: return bool2string(pp->getN());
        default: return "";
    }
}

bool PIMRegisterDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        case 0: pp->setB(string2bool(value)); return true;
        case 1: pp->setN(string2bool(value)); return true;
        default: return false;
    }
}

const char *PIMRegisterDescriptor::getFieldStructName(int field) const
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

void *PIMRegisterDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMRegister *pp = (PIMRegister *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(PIMRegisterStop)

PIMRegisterStop::PIMRegisterStop(const char *name, short kind) : ::inet::PIMPacket(name,kind)
{
    this->setType(RegisterStop);

}

PIMRegisterStop::PIMRegisterStop(const PIMRegisterStop& other) : ::inet::PIMPacket(other)
{
    copy(other);
}

PIMRegisterStop::~PIMRegisterStop()
{
}

PIMRegisterStop& PIMRegisterStop::operator=(const PIMRegisterStop& other)
{
    if (this==&other) return *this;
    ::inet::PIMPacket::operator=(other);
    copy(other);
    return *this;
}

void PIMRegisterStop::copy(const PIMRegisterStop& other)
{
    this->groupAddress = other.groupAddress;
    this->sourceAddress = other.sourceAddress;
}

void PIMRegisterStop::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::PIMPacket::parsimPack(b);
    doParsimPacking(b,this->groupAddress);
    doParsimPacking(b,this->sourceAddress);
}

void PIMRegisterStop::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::PIMPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->groupAddress);
    doParsimUnpacking(b,this->sourceAddress);
}

IPv4Address& PIMRegisterStop::getGroupAddress()
{
    return this->groupAddress;
}

void PIMRegisterStop::setGroupAddress(const IPv4Address& groupAddress)
{
    this->groupAddress = groupAddress;
}

IPv4Address& PIMRegisterStop::getSourceAddress()
{
    return this->sourceAddress;
}

void PIMRegisterStop::setSourceAddress(const IPv4Address& sourceAddress)
{
    this->sourceAddress = sourceAddress;
}

class PIMRegisterStopDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    PIMRegisterStopDescriptor();
    virtual ~PIMRegisterStopDescriptor();

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

Register_ClassDescriptor(PIMRegisterStopDescriptor)

PIMRegisterStopDescriptor::PIMRegisterStopDescriptor() : omnetpp::cClassDescriptor("inet::PIMRegisterStop", "inet::PIMPacket")
{
    propertynames = nullptr;
}

PIMRegisterStopDescriptor::~PIMRegisterStopDescriptor()
{
    delete[] propertynames;
}

bool PIMRegisterStopDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PIMRegisterStop *>(obj)!=nullptr;
}

const char **PIMRegisterStopDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *PIMRegisterStopDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int PIMRegisterStopDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int PIMRegisterStopDescriptor::getFieldTypeFlags(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeFlags[field] : 0;
}

const char *PIMRegisterStopDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "groupAddress",
        "sourceAddress",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int PIMRegisterStopDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='g' && strcmp(fieldName, "groupAddress")==0) return base+0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sourceAddress")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *PIMRegisterStopDescriptor::getFieldTypeString(int field) const
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

const char **PIMRegisterStopDescriptor::getFieldPropertyNames(int field) const
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

const char *PIMRegisterStopDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int PIMRegisterStopDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *PIMRegisterStopDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PIMRegisterStopDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getGroupAddress(); return out.str();}
        case 1: {std::stringstream out; out << pp->getSourceAddress(); return out.str();}
        default: return "";
    }
}

bool PIMRegisterStopDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *PIMRegisterStopDescriptor::getFieldStructName(int field) const
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

void *PIMRegisterStopDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    PIMRegisterStop *pp = (PIMRegisterStop *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->getGroupAddress()); break;
        case 1: return (void *)(&pp->getSourceAddress()); break;
        default: return nullptr;
    }
}

} // namespace inet

