//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/transportlayer/tcp_common/TCPSegment.msg.
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
#include "TCPSegment_m.h"

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
namespace tcp {

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

TCPPayloadMessage::TCPPayloadMessage()
{
    this->endSequenceNo = 0;
    this->msg = nullptr;
}

void __doPacking(omnetpp::cCommBuffer *b, const TCPPayloadMessage& a)
{
    doParsimPacking(b,a.endSequenceNo);
    doParsimPacking(b,a.msg);
}

void __doUnpacking(omnetpp::cCommBuffer *b, TCPPayloadMessage& a)
{
    doParsimUnpacking(b,a.endSequenceNo);
    doParsimUnpacking(b,a.msg);
}

class TCPPayloadMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPPayloadMessageDescriptor();
    virtual ~TCPPayloadMessageDescriptor();

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

Register_ClassDescriptor(TCPPayloadMessageDescriptor)

TCPPayloadMessageDescriptor::TCPPayloadMessageDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPPayloadMessage", "")
{
    propertynames = nullptr;
}

TCPPayloadMessageDescriptor::~TCPPayloadMessageDescriptor()
{
    delete[] propertynames;
}

bool TCPPayloadMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPPayloadMessage *>(obj)!=nullptr;
}

const char **TCPPayloadMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPPayloadMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPPayloadMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TCPPayloadMessageDescriptor::getFieldTypeFlags(int field) const
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

const char *TCPPayloadMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "endSequenceNo",
        "msg",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int TCPPayloadMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='e' && strcmp(fieldName, "endSequenceNo")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "msg")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPPayloadMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned int",
        "cPacketPtr",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPPayloadMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPPayloadMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPPayloadMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPPayloadMessage *pp = (TCPPayloadMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPPayloadMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPPayloadMessage *pp = (TCPPayloadMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPPayloadMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPPayloadMessage *pp = (TCPPayloadMessage *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->endSequenceNo);
        case 1: {std::stringstream out; out << pp->msg; return out.str();}
        default: return "";
    }
}

bool TCPPayloadMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPPayloadMessage *pp = (TCPPayloadMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->endSequenceNo = string2ulong(value); return true;
        default: return false;
    }
}

const char *TCPPayloadMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(cPacketPtr));
        default: return nullptr;
    };
}

void *TCPPayloadMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPPayloadMessage *pp = (TCPPayloadMessage *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->msg); break;
        default: return nullptr;
    }
}

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::tcp::TCPOptionNumbers");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::tcp::TCPOptionNumbers"));
    e->insert(TCPOPTION_END_OF_OPTION_LIST, "TCPOPTION_END_OF_OPTION_LIST");
    e->insert(TCPOPTION_NO_OPERATION, "TCPOPTION_NO_OPERATION");
    e->insert(TCPOPTION_MAXIMUM_SEGMENT_SIZE, "TCPOPTION_MAXIMUM_SEGMENT_SIZE");
    e->insert(TCPOPTION_WINDOW_SCALE, "TCPOPTION_WINDOW_SCALE");
    e->insert(TCPOPTION_SACK_PERMITTED, "TCPOPTION_SACK_PERMITTED");
    e->insert(TCPOPTION_SACK, "TCPOPTION_SACK");
    e->insert(TCPOPTION_TIMESTAMP, "TCPOPTION_TIMESTAMP");
)

Register_Class(SackItem)

SackItem::SackItem() : ::omnetpp::cObject()
{
    this->start = 0;
    this->end = 0;
}

SackItem::SackItem(const SackItem& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

SackItem::~SackItem()
{
}

SackItem& SackItem::operator=(const SackItem& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void SackItem::copy(const SackItem& other)
{
    this->start = other.start;
    this->end = other.end;
}

void SackItem::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->start);
    doParsimPacking(b,this->end);
}

void SackItem::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->start);
    doParsimUnpacking(b,this->end);
}

unsigned int SackItem::getStart() const
{
    return this->start;
}

void SackItem::setStart(unsigned int start)
{
    this->start = start;
}

unsigned int SackItem::getEnd() const
{
    return this->end;
}

void SackItem::setEnd(unsigned int end)
{
    this->end = end;
}

class SackItemDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SackItemDescriptor();
    virtual ~SackItemDescriptor();

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

Register_ClassDescriptor(SackItemDescriptor)

SackItemDescriptor::SackItemDescriptor() : omnetpp::cClassDescriptor("inet::tcp::SackItem", "omnetpp::cObject")
{
    propertynames = nullptr;
}

SackItemDescriptor::~SackItemDescriptor()
{
    delete[] propertynames;
}

bool SackItemDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<SackItem *>(obj)!=nullptr;
}

const char **SackItemDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SackItemDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SackItemDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int SackItemDescriptor::getFieldTypeFlags(int field) const
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

const char *SackItemDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "start",
        "end",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int SackItemDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "start")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "end")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SackItemDescriptor::getFieldTypeString(int field) const
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
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **SackItemDescriptor::getFieldPropertyNames(int field) const
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

const char *SackItemDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SackItemDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    SackItem *pp = (SackItem *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SackItemDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SackItem *pp = (SackItem *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SackItemDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    SackItem *pp = (SackItem *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getStart());
        case 1: return ulong2string(pp->getEnd());
        default: return "";
    }
}

bool SackItemDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    SackItem *pp = (SackItem *)object; (void)pp;
    switch (field) {
        case 0: pp->setStart(string2ulong(value)); return true;
        case 1: pp->setEnd(string2ulong(value)); return true;
        default: return false;
    }
}

const char *SackItemDescriptor::getFieldStructName(int field) const
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

void *SackItemDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    SackItem *pp = (SackItem *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Sack_Base::Sack_Base() : ::inet::tcp::SackItem()
{
}

Sack_Base::Sack_Base(const Sack_Base& other) : ::inet::tcp::SackItem(other)
{
    copy(other);
}

Sack_Base::~Sack_Base()
{
}

Sack_Base& Sack_Base::operator=(const Sack_Base& other)
{
    if (this==&other) return *this;
    ::inet::tcp::SackItem::operator=(other);
    copy(other);
    return *this;
}

void Sack_Base::copy(const Sack_Base& other)
{
}

void Sack_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::SackItem::parsimPack(b);
}

void Sack_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::SackItem::parsimUnpack(b);
}

class SackDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    SackDescriptor();
    virtual ~SackDescriptor();

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

Register_ClassDescriptor(SackDescriptor)

SackDescriptor::SackDescriptor() : omnetpp::cClassDescriptor("inet::tcp::Sack", "inet::tcp::SackItem")
{
    propertynames = nullptr;
}

SackDescriptor::~SackDescriptor()
{
    delete[] propertynames;
}

bool SackDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Sack_Base *>(obj)!=nullptr;
}

const char **SackDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *SackDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int SackDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int SackDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *SackDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int SackDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *SackDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **SackDescriptor::getFieldPropertyNames(int field) const
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

const char *SackDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int SackDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    Sack_Base *pp = (Sack_Base *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *SackDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Sack_Base *pp = (Sack_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string SackDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    Sack_Base *pp = (Sack_Base *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool SackDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    Sack_Base *pp = (Sack_Base *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *SackDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *SackDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    Sack_Base *pp = (Sack_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPOption)

TCPOption::TCPOption() : ::omnetpp::cObject()
{
    this->kind = -1;
    this->length = 1;
}

TCPOption::TCPOption(const TCPOption& other) : ::omnetpp::cObject(other)
{
    copy(other);
}

TCPOption::~TCPOption()
{
}

TCPOption& TCPOption::operator=(const TCPOption& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void TCPOption::copy(const TCPOption& other)
{
    this->kind = other.kind;
    this->length = other.length;
}

void TCPOption::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->kind);
    doParsimPacking(b,this->length);
}

void TCPOption::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->kind);
    doParsimUnpacking(b,this->length);
}

unsigned short TCPOption::getKind() const
{
    return this->kind;
}

void TCPOption::setKind(unsigned short kind)
{
    this->kind = kind;
}

unsigned short TCPOption::getLength() const
{
    return this->length;
}

void TCPOption::setLength(unsigned short length)
{
    this->length = length;
}

class TCPOptionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionDescriptor();
    virtual ~TCPOptionDescriptor();

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

Register_ClassDescriptor(TCPOptionDescriptor)

TCPOptionDescriptor::TCPOptionDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOption", "omnetpp::cObject")
{
    propertynames = nullptr;
}

TCPOptionDescriptor::~TCPOptionDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOption *>(obj)!=nullptr;
}

const char **TCPOptionDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TCPOptionDescriptor::getFieldTypeFlags(int field) const
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

const char *TCPOptionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "kind",
        "length",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int TCPOptionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "kind")==0) return base+0;
    if (fieldName[0]=='l' && strcmp(fieldName, "length")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned short",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPOptionDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::tcp::TCPOptionNumbers";
            return nullptr;
        default: return nullptr;
    }
}

int TCPOptionDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOption *pp = (TCPOption *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPOptionDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOption *pp = (TCPOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOption *pp = (TCPOption *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getKind(), "inet::tcp::TCPOptionNumbers");
        case 1: return ulong2string(pp->getLength());
        default: return "";
    }
}

bool TCPOptionDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOption *pp = (TCPOption *)object; (void)pp;
    switch (field) {
        case 0: pp->setKind((inet::tcp::TCPOptionNumbers)string2enum(value, "inet::tcp::TCPOptionNumbers")); return true;
        case 1: pp->setLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *TCPOptionDescriptor::getFieldStructName(int field) const
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

void *TCPOptionDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOption *pp = (TCPOption *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPOptionEnd)

TCPOptionEnd::TCPOptionEnd() : ::inet::tcp::TCPOption()
{
    this->setKind(TCPOPTION_END_OF_OPTION_LIST);
    this->setLength(1);
}

TCPOptionEnd::TCPOptionEnd(const TCPOptionEnd& other) : ::inet::tcp::TCPOption(other)
{
    copy(other);
}

TCPOptionEnd::~TCPOptionEnd()
{
}

TCPOptionEnd& TCPOptionEnd::operator=(const TCPOptionEnd& other)
{
    if (this==&other) return *this;
    ::inet::tcp::TCPOption::operator=(other);
    copy(other);
    return *this;
}

void TCPOptionEnd::copy(const TCPOptionEnd& other)
{
}

void TCPOptionEnd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::TCPOption::parsimPack(b);
}

void TCPOptionEnd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::TCPOption::parsimUnpack(b);
}

class TCPOptionEndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionEndDescriptor();
    virtual ~TCPOptionEndDescriptor();

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

Register_ClassDescriptor(TCPOptionEndDescriptor)

TCPOptionEndDescriptor::TCPOptionEndDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOptionEnd", "inet::tcp::TCPOption")
{
    propertynames = nullptr;
}

TCPOptionEndDescriptor::~TCPOptionEndDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionEndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOptionEnd *>(obj)!=nullptr;
}

const char **TCPOptionEndDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionEndDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionEndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TCPOptionEndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TCPOptionEndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TCPOptionEndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionEndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TCPOptionEndDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionEndDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPOptionEndDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOptionEnd *pp = (TCPOptionEnd *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPOptionEndDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionEnd *pp = (TCPOptionEnd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionEndDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionEnd *pp = (TCPOptionEnd *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TCPOptionEndDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOptionEnd *pp = (TCPOptionEnd *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TCPOptionEndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TCPOptionEndDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionEnd *pp = (TCPOptionEnd *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPOptionNop)

TCPOptionNop::TCPOptionNop() : ::inet::tcp::TCPOption()
{
    this->setKind(TCPOPTION_NO_OPERATION);
    this->setLength(1);
}

TCPOptionNop::TCPOptionNop(const TCPOptionNop& other) : ::inet::tcp::TCPOption(other)
{
    copy(other);
}

TCPOptionNop::~TCPOptionNop()
{
}

TCPOptionNop& TCPOptionNop::operator=(const TCPOptionNop& other)
{
    if (this==&other) return *this;
    ::inet::tcp::TCPOption::operator=(other);
    copy(other);
    return *this;
}

void TCPOptionNop::copy(const TCPOptionNop& other)
{
}

void TCPOptionNop::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::TCPOption::parsimPack(b);
}

void TCPOptionNop::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::TCPOption::parsimUnpack(b);
}

class TCPOptionNopDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionNopDescriptor();
    virtual ~TCPOptionNopDescriptor();

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

Register_ClassDescriptor(TCPOptionNopDescriptor)

TCPOptionNopDescriptor::TCPOptionNopDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOptionNop", "inet::tcp::TCPOption")
{
    propertynames = nullptr;
}

TCPOptionNopDescriptor::~TCPOptionNopDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionNopDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOptionNop *>(obj)!=nullptr;
}

const char **TCPOptionNopDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionNopDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionNopDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TCPOptionNopDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TCPOptionNopDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TCPOptionNopDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionNopDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TCPOptionNopDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionNopDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPOptionNopDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOptionNop *pp = (TCPOptionNop *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPOptionNopDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionNop *pp = (TCPOptionNop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionNopDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionNop *pp = (TCPOptionNop *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TCPOptionNopDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOptionNop *pp = (TCPOptionNop *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TCPOptionNopDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TCPOptionNopDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionNop *pp = (TCPOptionNop *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPOptionMaxSegmentSize)

TCPOptionMaxSegmentSize::TCPOptionMaxSegmentSize() : ::inet::tcp::TCPOption()
{
    this->setKind(TCPOPTION_MAXIMUM_SEGMENT_SIZE);
    this->setLength(4);

    this->maxSegmentSize = 0;
}

TCPOptionMaxSegmentSize::TCPOptionMaxSegmentSize(const TCPOptionMaxSegmentSize& other) : ::inet::tcp::TCPOption(other)
{
    copy(other);
}

TCPOptionMaxSegmentSize::~TCPOptionMaxSegmentSize()
{
}

TCPOptionMaxSegmentSize& TCPOptionMaxSegmentSize::operator=(const TCPOptionMaxSegmentSize& other)
{
    if (this==&other) return *this;
    ::inet::tcp::TCPOption::operator=(other);
    copy(other);
    return *this;
}

void TCPOptionMaxSegmentSize::copy(const TCPOptionMaxSegmentSize& other)
{
    this->maxSegmentSize = other.maxSegmentSize;
}

void TCPOptionMaxSegmentSize::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::TCPOption::parsimPack(b);
    doParsimPacking(b,this->maxSegmentSize);
}

void TCPOptionMaxSegmentSize::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::TCPOption::parsimUnpack(b);
    doParsimUnpacking(b,this->maxSegmentSize);
}

uint16_t TCPOptionMaxSegmentSize::getMaxSegmentSize() const
{
    return this->maxSegmentSize;
}

void TCPOptionMaxSegmentSize::setMaxSegmentSize(uint16_t maxSegmentSize)
{
    this->maxSegmentSize = maxSegmentSize;
}

class TCPOptionMaxSegmentSizeDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionMaxSegmentSizeDescriptor();
    virtual ~TCPOptionMaxSegmentSizeDescriptor();

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

Register_ClassDescriptor(TCPOptionMaxSegmentSizeDescriptor)

TCPOptionMaxSegmentSizeDescriptor::TCPOptionMaxSegmentSizeDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOptionMaxSegmentSize", "inet::tcp::TCPOption")
{
    propertynames = nullptr;
}

TCPOptionMaxSegmentSizeDescriptor::~TCPOptionMaxSegmentSizeDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionMaxSegmentSizeDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOptionMaxSegmentSize *>(obj)!=nullptr;
}

const char **TCPOptionMaxSegmentSizeDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionMaxSegmentSizeDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionMaxSegmentSizeDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TCPOptionMaxSegmentSizeDescriptor::getFieldTypeFlags(int field) const
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

const char *TCPOptionMaxSegmentSizeDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "maxSegmentSize",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int TCPOptionMaxSegmentSizeDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "maxSegmentSize")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionMaxSegmentSizeDescriptor::getFieldTypeString(int field) const
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

const char **TCPOptionMaxSegmentSizeDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionMaxSegmentSizeDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPOptionMaxSegmentSizeDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOptionMaxSegmentSize *pp = (TCPOptionMaxSegmentSize *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPOptionMaxSegmentSizeDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionMaxSegmentSize *pp = (TCPOptionMaxSegmentSize *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionMaxSegmentSizeDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionMaxSegmentSize *pp = (TCPOptionMaxSegmentSize *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getMaxSegmentSize());
        default: return "";
    }
}

bool TCPOptionMaxSegmentSizeDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOptionMaxSegmentSize *pp = (TCPOptionMaxSegmentSize *)object; (void)pp;
    switch (field) {
        case 0: pp->setMaxSegmentSize(string2ulong(value)); return true;
        default: return false;
    }
}

const char *TCPOptionMaxSegmentSizeDescriptor::getFieldStructName(int field) const
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

void *TCPOptionMaxSegmentSizeDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionMaxSegmentSize *pp = (TCPOptionMaxSegmentSize *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPOptionWindowScale)

TCPOptionWindowScale::TCPOptionWindowScale() : ::inet::tcp::TCPOption()
{
    this->setKind(TCPOPTION_WINDOW_SCALE);
    this->setLength(3);

    this->windowScale = 0;
}

TCPOptionWindowScale::TCPOptionWindowScale(const TCPOptionWindowScale& other) : ::inet::tcp::TCPOption(other)
{
    copy(other);
}

TCPOptionWindowScale::~TCPOptionWindowScale()
{
}

TCPOptionWindowScale& TCPOptionWindowScale::operator=(const TCPOptionWindowScale& other)
{
    if (this==&other) return *this;
    ::inet::tcp::TCPOption::operator=(other);
    copy(other);
    return *this;
}

void TCPOptionWindowScale::copy(const TCPOptionWindowScale& other)
{
    this->windowScale = other.windowScale;
}

void TCPOptionWindowScale::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::TCPOption::parsimPack(b);
    doParsimPacking(b,this->windowScale);
}

void TCPOptionWindowScale::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::TCPOption::parsimUnpack(b);
    doParsimUnpacking(b,this->windowScale);
}

unsigned short TCPOptionWindowScale::getWindowScale() const
{
    return this->windowScale;
}

void TCPOptionWindowScale::setWindowScale(unsigned short windowScale)
{
    this->windowScale = windowScale;
}

class TCPOptionWindowScaleDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionWindowScaleDescriptor();
    virtual ~TCPOptionWindowScaleDescriptor();

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

Register_ClassDescriptor(TCPOptionWindowScaleDescriptor)

TCPOptionWindowScaleDescriptor::TCPOptionWindowScaleDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOptionWindowScale", "inet::tcp::TCPOption")
{
    propertynames = nullptr;
}

TCPOptionWindowScaleDescriptor::~TCPOptionWindowScaleDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionWindowScaleDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOptionWindowScale *>(obj)!=nullptr;
}

const char **TCPOptionWindowScaleDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionWindowScaleDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionWindowScaleDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TCPOptionWindowScaleDescriptor::getFieldTypeFlags(int field) const
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

const char *TCPOptionWindowScaleDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "windowScale",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int TCPOptionWindowScaleDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='w' && strcmp(fieldName, "windowScale")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionWindowScaleDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPOptionWindowScaleDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionWindowScaleDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPOptionWindowScaleDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOptionWindowScale *pp = (TCPOptionWindowScale *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPOptionWindowScaleDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionWindowScale *pp = (TCPOptionWindowScale *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionWindowScaleDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionWindowScale *pp = (TCPOptionWindowScale *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getWindowScale());
        default: return "";
    }
}

bool TCPOptionWindowScaleDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOptionWindowScale *pp = (TCPOptionWindowScale *)object; (void)pp;
    switch (field) {
        case 0: pp->setWindowScale(string2ulong(value)); return true;
        default: return false;
    }
}

const char *TCPOptionWindowScaleDescriptor::getFieldStructName(int field) const
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

void *TCPOptionWindowScaleDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionWindowScale *pp = (TCPOptionWindowScale *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPOptionSackPermitted)

TCPOptionSackPermitted::TCPOptionSackPermitted() : ::inet::tcp::TCPOption()
{
    this->setKind(TCPOPTION_SACK_PERMITTED);
    this->setLength(2);
}

TCPOptionSackPermitted::TCPOptionSackPermitted(const TCPOptionSackPermitted& other) : ::inet::tcp::TCPOption(other)
{
    copy(other);
}

TCPOptionSackPermitted::~TCPOptionSackPermitted()
{
}

TCPOptionSackPermitted& TCPOptionSackPermitted::operator=(const TCPOptionSackPermitted& other)
{
    if (this==&other) return *this;
    ::inet::tcp::TCPOption::operator=(other);
    copy(other);
    return *this;
}

void TCPOptionSackPermitted::copy(const TCPOptionSackPermitted& other)
{
}

void TCPOptionSackPermitted::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::TCPOption::parsimPack(b);
}

void TCPOptionSackPermitted::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::TCPOption::parsimUnpack(b);
}

class TCPOptionSackPermittedDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionSackPermittedDescriptor();
    virtual ~TCPOptionSackPermittedDescriptor();

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

Register_ClassDescriptor(TCPOptionSackPermittedDescriptor)

TCPOptionSackPermittedDescriptor::TCPOptionSackPermittedDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOptionSackPermitted", "inet::tcp::TCPOption")
{
    propertynames = nullptr;
}

TCPOptionSackPermittedDescriptor::~TCPOptionSackPermittedDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionSackPermittedDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOptionSackPermitted *>(obj)!=nullptr;
}

const char **TCPOptionSackPermittedDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionSackPermittedDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionSackPermittedDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 0+basedesc->getFieldCount() : 0;
}

unsigned int TCPOptionSackPermittedDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    return 0;
}

const char *TCPOptionSackPermittedDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

int TCPOptionSackPermittedDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionSackPermittedDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

const char **TCPOptionSackPermittedDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionSackPermittedDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPOptionSackPermittedDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSackPermitted *pp = (TCPOptionSackPermitted *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPOptionSackPermittedDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSackPermitted *pp = (TCPOptionSackPermitted *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionSackPermittedDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSackPermitted *pp = (TCPOptionSackPermitted *)object; (void)pp;
    switch (field) {
        default: return "";
    }
}

bool TCPOptionSackPermittedDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSackPermitted *pp = (TCPOptionSackPermitted *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TCPOptionSackPermittedDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    return nullptr;
}

void *TCPOptionSackPermittedDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSackPermitted *pp = (TCPOptionSackPermitted *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPOptionSack)

TCPOptionSack::TCPOptionSack() : ::inet::tcp::TCPOption()
{
    this->setKind(TCPOPTION_SACK);
    this->setLength(2);

    sackItem_arraysize = 0;
    this->sackItem = 0;
}

TCPOptionSack::TCPOptionSack(const TCPOptionSack& other) : ::inet::tcp::TCPOption(other)
{
    sackItem_arraysize = 0;
    this->sackItem = 0;
    copy(other);
}

TCPOptionSack::~TCPOptionSack()
{
    delete [] this->sackItem;
}

TCPOptionSack& TCPOptionSack::operator=(const TCPOptionSack& other)
{
    if (this==&other) return *this;
    ::inet::tcp::TCPOption::operator=(other);
    copy(other);
    return *this;
}

void TCPOptionSack::copy(const TCPOptionSack& other)
{
    delete [] this->sackItem;
    this->sackItem = (other.sackItem_arraysize==0) ? nullptr : new SackItem[other.sackItem_arraysize];
    sackItem_arraysize = other.sackItem_arraysize;
    for (unsigned int i=0; i<sackItem_arraysize; i++)
        this->sackItem[i] = other.sackItem[i];
}

void TCPOptionSack::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::TCPOption::parsimPack(b);
    b->pack(sackItem_arraysize);
    doParsimArrayPacking(b,this->sackItem,sackItem_arraysize);
}

void TCPOptionSack::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::TCPOption::parsimUnpack(b);
    delete [] this->sackItem;
    b->unpack(sackItem_arraysize);
    if (sackItem_arraysize==0) {
        this->sackItem = 0;
    } else {
        this->sackItem = new SackItem[sackItem_arraysize];
        doParsimArrayUnpacking(b,this->sackItem,sackItem_arraysize);
    }
}

void TCPOptionSack::setSackItemArraySize(unsigned int size)
{
    SackItem *sackItem2 = (size==0) ? nullptr : new SackItem[size];
    unsigned int sz = sackItem_arraysize < size ? sackItem_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        sackItem2[i] = this->sackItem[i];
    sackItem_arraysize = size;
    delete [] this->sackItem;
    this->sackItem = sackItem2;
}

unsigned int TCPOptionSack::getSackItemArraySize() const
{
    return sackItem_arraysize;
}

SackItem& TCPOptionSack::getSackItem(unsigned int k)
{
    if (k>=sackItem_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sackItem_arraysize, k);
    return this->sackItem[k];
}

void TCPOptionSack::setSackItem(unsigned int k, const SackItem& sackItem)
{
    if (k>=sackItem_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", sackItem_arraysize, k);
    this->sackItem[k] = sackItem;
}

class TCPOptionSackDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionSackDescriptor();
    virtual ~TCPOptionSackDescriptor();

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

Register_ClassDescriptor(TCPOptionSackDescriptor)

TCPOptionSackDescriptor::TCPOptionSackDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOptionSack", "inet::tcp::TCPOption")
{
    propertynames = nullptr;
}

TCPOptionSackDescriptor::~TCPOptionSackDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionSackDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOptionSack *>(obj)!=nullptr;
}

const char **TCPOptionSackDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionSackDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionSackDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TCPOptionSackDescriptor::getFieldTypeFlags(int field) const
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

const char *TCPOptionSackDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sackItem",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int TCPOptionSackDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sackItem")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionSackDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "SackItem",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPOptionSackDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionSackDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPOptionSackDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSack *pp = (TCPOptionSack *)object; (void)pp;
    switch (field) {
        case 0: return pp->getSackItemArraySize();
        default: return 0;
    }
}

const char *TCPOptionSackDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSack *pp = (TCPOptionSack *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionSackDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSack *pp = (TCPOptionSack *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->getSackItem(i); return out.str();}
        default: return "";
    }
}

bool TCPOptionSackDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSack *pp = (TCPOptionSack *)object; (void)pp;
    switch (field) {
        default: return false;
    }
}

const char *TCPOptionSackDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(SackItem));
        default: return nullptr;
    };
}

void *TCPOptionSackDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionSack *pp = (TCPOptionSack *)object; (void)pp;
    switch (field) {
        case 0: return (void *)static_cast<omnetpp::cObject *>(&pp->getSackItem(i)); break;
        default: return nullptr;
    }
}

Register_Class(TCPOptionTimestamp)

TCPOptionTimestamp::TCPOptionTimestamp() : ::inet::tcp::TCPOption()
{
    this->setKind(TCPOPTION_TIMESTAMP);
    this->setLength(10);

    this->senderTimestamp = 0;
    this->echoedTimestamp = 0;
}

TCPOptionTimestamp::TCPOptionTimestamp(const TCPOptionTimestamp& other) : ::inet::tcp::TCPOption(other)
{
    copy(other);
}

TCPOptionTimestamp::~TCPOptionTimestamp()
{
}

TCPOptionTimestamp& TCPOptionTimestamp::operator=(const TCPOptionTimestamp& other)
{
    if (this==&other) return *this;
    ::inet::tcp::TCPOption::operator=(other);
    copy(other);
    return *this;
}

void TCPOptionTimestamp::copy(const TCPOptionTimestamp& other)
{
    this->senderTimestamp = other.senderTimestamp;
    this->echoedTimestamp = other.echoedTimestamp;
}

void TCPOptionTimestamp::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::TCPOption::parsimPack(b);
    doParsimPacking(b,this->senderTimestamp);
    doParsimPacking(b,this->echoedTimestamp);
}

void TCPOptionTimestamp::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::TCPOption::parsimUnpack(b);
    doParsimUnpacking(b,this->senderTimestamp);
    doParsimUnpacking(b,this->echoedTimestamp);
}

uint32_t TCPOptionTimestamp::getSenderTimestamp() const
{
    return this->senderTimestamp;
}

void TCPOptionTimestamp::setSenderTimestamp(uint32_t senderTimestamp)
{
    this->senderTimestamp = senderTimestamp;
}

uint32_t TCPOptionTimestamp::getEchoedTimestamp() const
{
    return this->echoedTimestamp;
}

void TCPOptionTimestamp::setEchoedTimestamp(uint32_t echoedTimestamp)
{
    this->echoedTimestamp = echoedTimestamp;
}

class TCPOptionTimestampDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionTimestampDescriptor();
    virtual ~TCPOptionTimestampDescriptor();

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

Register_ClassDescriptor(TCPOptionTimestampDescriptor)

TCPOptionTimestampDescriptor::TCPOptionTimestampDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOptionTimestamp", "inet::tcp::TCPOption")
{
    propertynames = nullptr;
}

TCPOptionTimestampDescriptor::~TCPOptionTimestampDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionTimestampDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOptionTimestamp *>(obj)!=nullptr;
}

const char **TCPOptionTimestampDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionTimestampDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionTimestampDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 2+basedesc->getFieldCount() : 2;
}

unsigned int TCPOptionTimestampDescriptor::getFieldTypeFlags(int field) const
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

const char *TCPOptionTimestampDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "senderTimestamp",
        "echoedTimestamp",
    };
    return (field>=0 && field<2) ? fieldNames[field] : nullptr;
}

int TCPOptionTimestampDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "senderTimestamp")==0) return base+0;
    if (fieldName[0]=='e' && strcmp(fieldName, "echoedTimestamp")==0) return base+1;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionTimestampDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint32_t",
        "uint32_t",
    };
    return (field>=0 && field<2) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPOptionTimestampDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionTimestampDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPOptionTimestampDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOptionTimestamp *pp = (TCPOptionTimestamp *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *TCPOptionTimestampDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionTimestamp *pp = (TCPOptionTimestamp *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionTimestampDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionTimestamp *pp = (TCPOptionTimestamp *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSenderTimestamp());
        case 1: return ulong2string(pp->getEchoedTimestamp());
        default: return "";
    }
}

bool TCPOptionTimestampDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOptionTimestamp *pp = (TCPOptionTimestamp *)object; (void)pp;
    switch (field) {
        case 0: pp->setSenderTimestamp(string2ulong(value)); return true;
        case 1: pp->setEchoedTimestamp(string2ulong(value)); return true;
        default: return false;
    }
}

const char *TCPOptionTimestampDescriptor::getFieldStructName(int field) const
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

void *TCPOptionTimestampDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionTimestamp *pp = (TCPOptionTimestamp *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

Register_Class(TCPOptionUnknown)

TCPOptionUnknown::TCPOptionUnknown() : ::inet::tcp::TCPOption()
{
    this->setKind(-1);

    bytes_arraysize = 0;
    this->bytes = 0;
}

TCPOptionUnknown::TCPOptionUnknown(const TCPOptionUnknown& other) : ::inet::tcp::TCPOption(other)
{
    bytes_arraysize = 0;
    this->bytes = 0;
    copy(other);
}

TCPOptionUnknown::~TCPOptionUnknown()
{
    delete [] this->bytes;
}

TCPOptionUnknown& TCPOptionUnknown::operator=(const TCPOptionUnknown& other)
{
    if (this==&other) return *this;
    ::inet::tcp::TCPOption::operator=(other);
    copy(other);
    return *this;
}

void TCPOptionUnknown::copy(const TCPOptionUnknown& other)
{
    delete [] this->bytes;
    this->bytes = (other.bytes_arraysize==0) ? nullptr : new uint8_t[other.bytes_arraysize];
    bytes_arraysize = other.bytes_arraysize;
    for (unsigned int i=0; i<bytes_arraysize; i++)
        this->bytes[i] = other.bytes[i];
}

void TCPOptionUnknown::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::tcp::TCPOption::parsimPack(b);
    b->pack(bytes_arraysize);
    doParsimArrayPacking(b,this->bytes,bytes_arraysize);
}

void TCPOptionUnknown::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::tcp::TCPOption::parsimUnpack(b);
    delete [] this->bytes;
    b->unpack(bytes_arraysize);
    if (bytes_arraysize==0) {
        this->bytes = 0;
    } else {
        this->bytes = new uint8_t[bytes_arraysize];
        doParsimArrayUnpacking(b,this->bytes,bytes_arraysize);
    }
}

void TCPOptionUnknown::setBytesArraySize(unsigned int size)
{
    uint8_t *bytes2 = (size==0) ? nullptr : new uint8_t[size];
    unsigned int sz = bytes_arraysize < size ? bytes_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        bytes2[i] = this->bytes[i];
    for (unsigned int i=sz; i<size; i++)
        bytes2[i] = 0;
    bytes_arraysize = size;
    delete [] this->bytes;
    this->bytes = bytes2;
}

unsigned int TCPOptionUnknown::getBytesArraySize() const
{
    return bytes_arraysize;
}

uint8_t TCPOptionUnknown::getBytes(unsigned int k) const
{
    if (k>=bytes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", bytes_arraysize, k);
    return this->bytes[k];
}

void TCPOptionUnknown::setBytes(unsigned int k, uint8_t bytes)
{
    if (k>=bytes_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", bytes_arraysize, k);
    this->bytes[k] = bytes;
}

class TCPOptionUnknownDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPOptionUnknownDescriptor();
    virtual ~TCPOptionUnknownDescriptor();

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

Register_ClassDescriptor(TCPOptionUnknownDescriptor)

TCPOptionUnknownDescriptor::TCPOptionUnknownDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPOptionUnknown", "inet::tcp::TCPOption")
{
    propertynames = nullptr;
}

TCPOptionUnknownDescriptor::~TCPOptionUnknownDescriptor()
{
    delete[] propertynames;
}

bool TCPOptionUnknownDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPOptionUnknown *>(obj)!=nullptr;
}

const char **TCPOptionUnknownDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPOptionUnknownDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPOptionUnknownDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 1+basedesc->getFieldCount() : 1;
}

unsigned int TCPOptionUnknownDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE,
    };
    return (field>=0 && field<1) ? fieldTypeFlags[field] : 0;
}

const char *TCPOptionUnknownDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bytes",
    };
    return (field>=0 && field<1) ? fieldNames[field] : nullptr;
}

int TCPOptionUnknownDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='b' && strcmp(fieldName, "bytes")==0) return base+0;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPOptionUnknownDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "uint8_t",
    };
    return (field>=0 && field<1) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPOptionUnknownDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPOptionUnknownDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPOptionUnknownDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPOptionUnknown *pp = (TCPOptionUnknown *)object; (void)pp;
    switch (field) {
        case 0: return pp->getBytesArraySize();
        default: return 0;
    }
}

const char *TCPOptionUnknownDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionUnknown *pp = (TCPOptionUnknown *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPOptionUnknownDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionUnknown *pp = (TCPOptionUnknown *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getBytes(i));
        default: return "";
    }
}

bool TCPOptionUnknownDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPOptionUnknown *pp = (TCPOptionUnknown *)object; (void)pp;
    switch (field) {
        case 0: pp->setBytes(i,string2ulong(value)); return true;
        default: return false;
    }
}

const char *TCPOptionUnknownDescriptor::getFieldStructName(int field) const
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

void *TCPOptionUnknownDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPOptionUnknown *pp = (TCPOptionUnknown *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

TCPSegment_Base::TCPSegment_Base(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->srcPort = 0;
    this->destPort = 0;
    this->sequenceNo = 0;
    this->ackNo = 0;
    this->headerLength = TCP_HEADER_OCTETS;
    this->urgBit = false;
    this->ackBit = false;
    this->pshBit = false;
    this->rstBit = false;
    this->synBit = false;
    this->finBit = false;
    this->window = 0;
    this->urgentPointer = 0;
    this->payloadLength = 0;
}

TCPSegment_Base::TCPSegment_Base(const TCPSegment_Base& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

TCPSegment_Base::~TCPSegment_Base()
{
}

TCPSegment_Base& TCPSegment_Base::operator=(const TCPSegment_Base& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void TCPSegment_Base::copy(const TCPSegment_Base& other)
{
    this->srcPort = other.srcPort;
    this->destPort = other.destPort;
    this->sequenceNo = other.sequenceNo;
    this->ackNo = other.ackNo;
    this->headerLength = other.headerLength;
    this->urgBit = other.urgBit;
    this->ackBit = other.ackBit;
    this->pshBit = other.pshBit;
    this->rstBit = other.rstBit;
    this->synBit = other.synBit;
    this->finBit = other.finBit;
    this->window = other.window;
    this->urgentPointer = other.urgentPointer;
    this->payloadLength = other.payloadLength;
    this->byteArray = other.byteArray;
}

void TCPSegment_Base::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->srcPort);
    doParsimPacking(b,this->destPort);
    doParsimPacking(b,this->sequenceNo);
    doParsimPacking(b,this->ackNo);
    doParsimPacking(b,this->headerLength);
    doParsimPacking(b,this->urgBit);
    doParsimPacking(b,this->ackBit);
    doParsimPacking(b,this->pshBit);
    doParsimPacking(b,this->rstBit);
    doParsimPacking(b,this->synBit);
    doParsimPacking(b,this->finBit);
    doParsimPacking(b,this->window);
    doParsimPacking(b,this->urgentPointer);
    // field headerOption is abstract -- please do packing in customized class
    doParsimPacking(b,this->payloadLength);
    // field payload is abstract -- please do packing in customized class
    doParsimPacking(b,this->byteArray);
}

void TCPSegment_Base::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->srcPort);
    doParsimUnpacking(b,this->destPort);
    doParsimUnpacking(b,this->sequenceNo);
    doParsimUnpacking(b,this->ackNo);
    doParsimUnpacking(b,this->headerLength);
    doParsimUnpacking(b,this->urgBit);
    doParsimUnpacking(b,this->ackBit);
    doParsimUnpacking(b,this->pshBit);
    doParsimUnpacking(b,this->rstBit);
    doParsimUnpacking(b,this->synBit);
    doParsimUnpacking(b,this->finBit);
    doParsimUnpacking(b,this->window);
    doParsimUnpacking(b,this->urgentPointer);
    // field headerOption is abstract -- please do unpacking in customized class
    doParsimUnpacking(b,this->payloadLength);
    // field payload is abstract -- please do unpacking in customized class
    doParsimUnpacking(b,this->byteArray);
}

unsigned short TCPSegment_Base::getSrcPort() const
{
    return this->srcPort;
}

void TCPSegment_Base::setSrcPort(unsigned short srcPort)
{
    this->srcPort = srcPort;
}

unsigned short TCPSegment_Base::getDestPort() const
{
    return this->destPort;
}

void TCPSegment_Base::setDestPort(unsigned short destPort)
{
    this->destPort = destPort;
}

unsigned int TCPSegment_Base::getSequenceNo() const
{
    return this->sequenceNo;
}

void TCPSegment_Base::setSequenceNo(unsigned int sequenceNo)
{
    this->sequenceNo = sequenceNo;
}

unsigned int TCPSegment_Base::getAckNo() const
{
    return this->ackNo;
}

void TCPSegment_Base::setAckNo(unsigned int ackNo)
{
    this->ackNo = ackNo;
}

unsigned short TCPSegment_Base::getHeaderLength() const
{
    return this->headerLength;
}

void TCPSegment_Base::setHeaderLength(unsigned short headerLength)
{
    this->headerLength = headerLength;
}

bool TCPSegment_Base::getUrgBit() const
{
    return this->urgBit;
}

void TCPSegment_Base::setUrgBit(bool urgBit)
{
    this->urgBit = urgBit;
}

bool TCPSegment_Base::getAckBit() const
{
    return this->ackBit;
}

void TCPSegment_Base::setAckBit(bool ackBit)
{
    this->ackBit = ackBit;
}

bool TCPSegment_Base::getPshBit() const
{
    return this->pshBit;
}

void TCPSegment_Base::setPshBit(bool pshBit)
{
    this->pshBit = pshBit;
}

bool TCPSegment_Base::getRstBit() const
{
    return this->rstBit;
}

void TCPSegment_Base::setRstBit(bool rstBit)
{
    this->rstBit = rstBit;
}

bool TCPSegment_Base::getSynBit() const
{
    return this->synBit;
}

void TCPSegment_Base::setSynBit(bool synBit)
{
    this->synBit = synBit;
}

bool TCPSegment_Base::getFinBit() const
{
    return this->finBit;
}

void TCPSegment_Base::setFinBit(bool finBit)
{
    this->finBit = finBit;
}

unsigned short TCPSegment_Base::getWindow() const
{
    return this->window;
}

void TCPSegment_Base::setWindow(unsigned short window)
{
    this->window = window;
}

unsigned short TCPSegment_Base::getUrgentPointer() const
{
    return this->urgentPointer;
}

void TCPSegment_Base::setUrgentPointer(unsigned short urgentPointer)
{
    this->urgentPointer = urgentPointer;
}

unsigned long TCPSegment_Base::getPayloadLength() const
{
    return this->payloadLength;
}

void TCPSegment_Base::setPayloadLength(unsigned long payloadLength)
{
    this->payloadLength = payloadLength;
}

ByteArray& TCPSegment_Base::getByteArray()
{
    return this->byteArray;
}

void TCPSegment_Base::setByteArray(const ByteArray& byteArray)
{
    this->byteArray = byteArray;
}

class TCPSegmentDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    TCPSegmentDescriptor();
    virtual ~TCPSegmentDescriptor();

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

Register_ClassDescriptor(TCPSegmentDescriptor)

TCPSegmentDescriptor::TCPSegmentDescriptor() : omnetpp::cClassDescriptor("inet::tcp::TCPSegment", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

TCPSegmentDescriptor::~TCPSegmentDescriptor()
{
    delete[] propertynames;
}

bool TCPSegmentDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TCPSegment_Base *>(obj)!=nullptr;
}

const char **TCPSegmentDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = { "customize",  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *TCPSegmentDescriptor::getProperty(const char *propertyname) const
{
    if (!strcmp(propertyname,"customize")) return "true";
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int TCPSegmentDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 17+basedesc->getFieldCount() : 17;
}

unsigned int TCPSegmentDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISCOMPOUND,
    };
    return (field>=0 && field<17) ? fieldTypeFlags[field] : 0;
}

const char *TCPSegmentDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcPort",
        "destPort",
        "sequenceNo",
        "ackNo",
        "headerLength",
        "urgBit",
        "ackBit",
        "pshBit",
        "rstBit",
        "synBit",
        "finBit",
        "window",
        "urgentPointer",
        "headerOption",
        "payloadLength",
        "payload",
        "byteArray",
    };
    return (field>=0 && field<17) ? fieldNames[field] : nullptr;
}

int TCPSegmentDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "srcPort")==0) return base+0;
    if (fieldName[0]=='d' && strcmp(fieldName, "destPort")==0) return base+1;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNo")==0) return base+2;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackNo")==0) return base+3;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerLength")==0) return base+4;
    if (fieldName[0]=='u' && strcmp(fieldName, "urgBit")==0) return base+5;
    if (fieldName[0]=='a' && strcmp(fieldName, "ackBit")==0) return base+6;
    if (fieldName[0]=='p' && strcmp(fieldName, "pshBit")==0) return base+7;
    if (fieldName[0]=='r' && strcmp(fieldName, "rstBit")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "synBit")==0) return base+9;
    if (fieldName[0]=='f' && strcmp(fieldName, "finBit")==0) return base+10;
    if (fieldName[0]=='w' && strcmp(fieldName, "window")==0) return base+11;
    if (fieldName[0]=='u' && strcmp(fieldName, "urgentPointer")==0) return base+12;
    if (fieldName[0]=='h' && strcmp(fieldName, "headerOption")==0) return base+13;
    if (fieldName[0]=='p' && strcmp(fieldName, "payloadLength")==0) return base+14;
    if (fieldName[0]=='p' && strcmp(fieldName, "payload")==0) return base+15;
    if (fieldName[0]=='b' && strcmp(fieldName, "byteArray")==0) return base+16;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *TCPSegmentDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "unsigned short",
        "unsigned short",
        "unsigned int",
        "unsigned int",
        "unsigned short",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "bool",
        "unsigned short",
        "unsigned short",
        "TCPOptionPtr",
        "unsigned long",
        "TCPPayloadMessage",
        "ByteArray",
    };
    return (field>=0 && field<17) ? fieldTypeStrings[field] : nullptr;
}

const char **TCPSegmentDescriptor::getFieldPropertyNames(int field) const
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

const char *TCPSegmentDescriptor::getFieldProperty(int field, const char *propertyname) const
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

int TCPSegmentDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    TCPSegment_Base *pp = (TCPSegment_Base *)object; (void)pp;
    switch (field) {
        case 13: return pp->getHeaderOptionArraySize();
        case 15: return pp->getPayloadArraySize();
        default: return 0;
    }
}

const char *TCPSegmentDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPSegment_Base *pp = (TCPSegment_Base *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TCPSegmentDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    TCPSegment_Base *pp = (TCPSegment_Base *)object; (void)pp;
    switch (field) {
        case 0: return ulong2string(pp->getSrcPort());
        case 1: return ulong2string(pp->getDestPort());
        case 2: return ulong2string(pp->getSequenceNo());
        case 3: return ulong2string(pp->getAckNo());
        case 4: return ulong2string(pp->getHeaderLength());
        case 5: return bool2string(pp->getUrgBit());
        case 6: return bool2string(pp->getAckBit());
        case 7: return bool2string(pp->getPshBit());
        case 8: return bool2string(pp->getRstBit());
        case 9: return bool2string(pp->getSynBit());
        case 10: return bool2string(pp->getFinBit());
        case 11: return ulong2string(pp->getWindow());
        case 12: return ulong2string(pp->getUrgentPointer());
        case 13: {std::stringstream out; out << pp->getHeaderOption(i); return out.str();}
        case 14: return ulong2string(pp->getPayloadLength());
        case 15: {std::stringstream out; out << pp->getPayload(i); return out.str();}
        case 16: {std::stringstream out; out << pp->getByteArray(); return out.str();}
        default: return "";
    }
}

bool TCPSegmentDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    TCPSegment_Base *pp = (TCPSegment_Base *)object; (void)pp;
    switch (field) {
        case 0: pp->setSrcPort(string2ulong(value)); return true;
        case 1: pp->setDestPort(string2ulong(value)); return true;
        case 2: pp->setSequenceNo(string2ulong(value)); return true;
        case 3: pp->setAckNo(string2ulong(value)); return true;
        case 4: pp->setHeaderLength(string2ulong(value)); return true;
        case 5: pp->setUrgBit(string2bool(value)); return true;
        case 6: pp->setAckBit(string2bool(value)); return true;
        case 7: pp->setPshBit(string2bool(value)); return true;
        case 8: pp->setRstBit(string2bool(value)); return true;
        case 9: pp->setSynBit(string2bool(value)); return true;
        case 10: pp->setFinBit(string2bool(value)); return true;
        case 11: pp->setWindow(string2ulong(value)); return true;
        case 12: pp->setUrgentPointer(string2ulong(value)); return true;
        case 14: pp->setPayloadLength(string2ulong(value)); return true;
        default: return false;
    }
}

const char *TCPSegmentDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 13: return omnetpp::opp_typename(typeid(TCPOptionPtr));
        case 15: return omnetpp::opp_typename(typeid(TCPPayloadMessage));
        case 16: return omnetpp::opp_typename(typeid(ByteArray));
        default: return nullptr;
    };
}

void *TCPSegmentDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    TCPSegment_Base *pp = (TCPSegment_Base *)object; (void)pp;
    switch (field) {
        case 13: return (void *)(&pp->getHeaderOption(i)); break;
        case 15: return (void *)(&pp->getPayload(i)); break;
        case 16: return (void *)(&pp->getByteArray()); break;
        default: return nullptr;
    }
}

} // namespace tcp
} // namespace inet

