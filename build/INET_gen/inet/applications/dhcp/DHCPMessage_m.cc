//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/applications/dhcp/DHCPMessage.msg.
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
#include "DHCPMessage_m.h"

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
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::DHCPOpcode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::DHCPOpcode"));
    e->insert(BOOTREQUEST, "BOOTREQUEST");
    e->insert(BOOTREPLY, "BOOTREPLY");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::DHCPMessageType");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::DHCPMessageType"));
    e->insert(DHCPDISCOVER, "DHCPDISCOVER");
    e->insert(DHCPOFFER, "DHCPOFFER");
    e->insert(DHCPREQUEST, "DHCPREQUEST");
    e->insert(DHCPDECLINE, "DHCPDECLINE");
    e->insert(DHCPACK, "DHCPACK");
    e->insert(DHCPNAK, "DHCPNAK");
    e->insert(DHCPRELEASE, "DHCPRELEASE");
    e->insert(DHCPINFORM, "DHCPINFORM");
)

EXECUTE_ON_STARTUP(
    omnetpp::cEnum *e = omnetpp::cEnum::find("inet::DHCPOptionCode");
    if (!e) omnetpp::enums.getInstance()->add(e = new omnetpp::cEnum("inet::DHCPOptionCode"));
    e->insert(DHCP_MSG_TYPE, "DHCP_MSG_TYPE");
    e->insert(CLIENT_ID, "CLIENT_ID");
    e->insert(HOSTNAME, "HOSTNAME");
    e->insert(REQUESTED_IP, "REQUESTED_IP");
    e->insert(PARAM_LIST, "PARAM_LIST");
    e->insert(SUBNET_MASK, "SUBNET_MASK");
    e->insert(ROUTER, "ROUTER");
    e->insert(DNS, "DNS");
    e->insert(NTP_SRV, "NTP_SRV");
    e->insert(RENEWAL_TIME, "RENEWAL_TIME");
    e->insert(REBIND_TIME, "REBIND_TIME");
    e->insert(LEASE_TIME, "LEASE_TIME");
    e->insert(SERVER_ID, "SERVER_ID");
)

Register_Class(DHCPOptions)

DHCPOptions::DHCPOptions() : ::omnetpp::cObject()
{
    this->messageType = 0;
    parameterRequestList_arraysize = 0;
    this->parameterRequestList = 0;
    router_arraysize = 0;
    this->router = 0;
    dns_arraysize = 0;
    this->dns = 0;
    ntp_arraysize = 0;
    this->ntp = 0;
    this->renewalTime = 0;
    this->rebindingTime = 0;
    this->leaseTime = 0;
}

DHCPOptions::DHCPOptions(const DHCPOptions& other) : ::omnetpp::cObject(other)
{
    parameterRequestList_arraysize = 0;
    this->parameterRequestList = 0;
    router_arraysize = 0;
    this->router = 0;
    dns_arraysize = 0;
    this->dns = 0;
    ntp_arraysize = 0;
    this->ntp = 0;
    copy(other);
}

DHCPOptions::~DHCPOptions()
{
    delete [] this->parameterRequestList;
    delete [] this->router;
    delete [] this->dns;
    delete [] this->ntp;
}

DHCPOptions& DHCPOptions::operator=(const DHCPOptions& other)
{
    if (this==&other) return *this;
    ::omnetpp::cObject::operator=(other);
    copy(other);
    return *this;
}

void DHCPOptions::copy(const DHCPOptions& other)
{
    this->messageType = other.messageType;
    this->hostName = other.hostName;
    delete [] this->parameterRequestList;
    this->parameterRequestList = (other.parameterRequestList_arraysize==0) ? nullptr : new int[other.parameterRequestList_arraysize];
    parameterRequestList_arraysize = other.parameterRequestList_arraysize;
    for (unsigned int i=0; i<parameterRequestList_arraysize; i++)
        this->parameterRequestList[i] = other.parameterRequestList[i];
    this->clientIdentifier = other.clientIdentifier;
    this->requestedIp = other.requestedIp;
    this->subnetMask = other.subnetMask;
    delete [] this->router;
    this->router = (other.router_arraysize==0) ? nullptr : new IPv4Address[other.router_arraysize];
    router_arraysize = other.router_arraysize;
    for (unsigned int i=0; i<router_arraysize; i++)
        this->router[i] = other.router[i];
    delete [] this->dns;
    this->dns = (other.dns_arraysize==0) ? nullptr : new IPv4Address[other.dns_arraysize];
    dns_arraysize = other.dns_arraysize;
    for (unsigned int i=0; i<dns_arraysize; i++)
        this->dns[i] = other.dns[i];
    delete [] this->ntp;
    this->ntp = (other.ntp_arraysize==0) ? nullptr : new IPv4Address[other.ntp_arraysize];
    ntp_arraysize = other.ntp_arraysize;
    for (unsigned int i=0; i<ntp_arraysize; i++)
        this->ntp[i] = other.ntp[i];
    this->serverIdentifier = other.serverIdentifier;
    this->renewalTime = other.renewalTime;
    this->rebindingTime = other.rebindingTime;
    this->leaseTime = other.leaseTime;
}

void DHCPOptions::parsimPack(omnetpp::cCommBuffer *b) const
{
    doParsimPacking(b,this->messageType);
    doParsimPacking(b,this->hostName);
    b->pack(parameterRequestList_arraysize);
    doParsimArrayPacking(b,this->parameterRequestList,parameterRequestList_arraysize);
    doParsimPacking(b,this->clientIdentifier);
    doParsimPacking(b,this->requestedIp);
    doParsimPacking(b,this->subnetMask);
    b->pack(router_arraysize);
    doParsimArrayPacking(b,this->router,router_arraysize);
    b->pack(dns_arraysize);
    doParsimArrayPacking(b,this->dns,dns_arraysize);
    b->pack(ntp_arraysize);
    doParsimArrayPacking(b,this->ntp,ntp_arraysize);
    doParsimPacking(b,this->serverIdentifier);
    doParsimPacking(b,this->renewalTime);
    doParsimPacking(b,this->rebindingTime);
    doParsimPacking(b,this->leaseTime);
}

void DHCPOptions::parsimUnpack(omnetpp::cCommBuffer *b)
{
    doParsimUnpacking(b,this->messageType);
    doParsimUnpacking(b,this->hostName);
    delete [] this->parameterRequestList;
    b->unpack(parameterRequestList_arraysize);
    if (parameterRequestList_arraysize==0) {
        this->parameterRequestList = 0;
    } else {
        this->parameterRequestList = new int[parameterRequestList_arraysize];
        doParsimArrayUnpacking(b,this->parameterRequestList,parameterRequestList_arraysize);
    }
    doParsimUnpacking(b,this->clientIdentifier);
    doParsimUnpacking(b,this->requestedIp);
    doParsimUnpacking(b,this->subnetMask);
    delete [] this->router;
    b->unpack(router_arraysize);
    if (router_arraysize==0) {
        this->router = 0;
    } else {
        this->router = new IPv4Address[router_arraysize];
        doParsimArrayUnpacking(b,this->router,router_arraysize);
    }
    delete [] this->dns;
    b->unpack(dns_arraysize);
    if (dns_arraysize==0) {
        this->dns = 0;
    } else {
        this->dns = new IPv4Address[dns_arraysize];
        doParsimArrayUnpacking(b,this->dns,dns_arraysize);
    }
    delete [] this->ntp;
    b->unpack(ntp_arraysize);
    if (ntp_arraysize==0) {
        this->ntp = 0;
    } else {
        this->ntp = new IPv4Address[ntp_arraysize];
        doParsimArrayUnpacking(b,this->ntp,ntp_arraysize);
    }
    doParsimUnpacking(b,this->serverIdentifier);
    doParsimUnpacking(b,this->renewalTime);
    doParsimUnpacking(b,this->rebindingTime);
    doParsimUnpacking(b,this->leaseTime);
}

int DHCPOptions::getMessageType() const
{
    return this->messageType;
}

void DHCPOptions::setMessageType(int messageType)
{
    this->messageType = messageType;
}

const char * DHCPOptions::getHostName() const
{
    return this->hostName.c_str();
}

void DHCPOptions::setHostName(const char * hostName)
{
    this->hostName = hostName;
}

void DHCPOptions::setParameterRequestListArraySize(unsigned int size)
{
    int *parameterRequestList2 = (size==0) ? nullptr : new int[size];
    unsigned int sz = parameterRequestList_arraysize < size ? parameterRequestList_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        parameterRequestList2[i] = this->parameterRequestList[i];
    for (unsigned int i=sz; i<size; i++)
        parameterRequestList2[i] = 0;
    parameterRequestList_arraysize = size;
    delete [] this->parameterRequestList;
    this->parameterRequestList = parameterRequestList2;
}

unsigned int DHCPOptions::getParameterRequestListArraySize() const
{
    return parameterRequestList_arraysize;
}

int DHCPOptions::getParameterRequestList(unsigned int k) const
{
    if (k>=parameterRequestList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", parameterRequestList_arraysize, k);
    return this->parameterRequestList[k];
}

void DHCPOptions::setParameterRequestList(unsigned int k, int parameterRequestList)
{
    if (k>=parameterRequestList_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", parameterRequestList_arraysize, k);
    this->parameterRequestList[k] = parameterRequestList;
}

MACAddress& DHCPOptions::getClientIdentifier()
{
    return this->clientIdentifier;
}

void DHCPOptions::setClientIdentifier(const MACAddress& clientIdentifier)
{
    this->clientIdentifier = clientIdentifier;
}

IPv4Address& DHCPOptions::getRequestedIp()
{
    return this->requestedIp;
}

void DHCPOptions::setRequestedIp(const IPv4Address& requestedIp)
{
    this->requestedIp = requestedIp;
}

IPv4Address& DHCPOptions::getSubnetMask()
{
    return this->subnetMask;
}

void DHCPOptions::setSubnetMask(const IPv4Address& subnetMask)
{
    this->subnetMask = subnetMask;
}

void DHCPOptions::setRouterArraySize(unsigned int size)
{
    IPv4Address *router2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = router_arraysize < size ? router_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        router2[i] = this->router[i];
    router_arraysize = size;
    delete [] this->router;
    this->router = router2;
}

unsigned int DHCPOptions::getRouterArraySize() const
{
    return router_arraysize;
}

IPv4Address& DHCPOptions::getRouter(unsigned int k)
{
    if (k>=router_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", router_arraysize, k);
    return this->router[k];
}

void DHCPOptions::setRouter(unsigned int k, const IPv4Address& router)
{
    if (k>=router_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", router_arraysize, k);
    this->router[k] = router;
}

void DHCPOptions::setDnsArraySize(unsigned int size)
{
    IPv4Address *dns2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = dns_arraysize < size ? dns_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        dns2[i] = this->dns[i];
    dns_arraysize = size;
    delete [] this->dns;
    this->dns = dns2;
}

unsigned int DHCPOptions::getDnsArraySize() const
{
    return dns_arraysize;
}

IPv4Address& DHCPOptions::getDns(unsigned int k)
{
    if (k>=dns_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", dns_arraysize, k);
    return this->dns[k];
}

void DHCPOptions::setDns(unsigned int k, const IPv4Address& dns)
{
    if (k>=dns_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", dns_arraysize, k);
    this->dns[k] = dns;
}

void DHCPOptions::setNtpArraySize(unsigned int size)
{
    IPv4Address *ntp2 = (size==0) ? nullptr : new IPv4Address[size];
    unsigned int sz = ntp_arraysize < size ? ntp_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        ntp2[i] = this->ntp[i];
    ntp_arraysize = size;
    delete [] this->ntp;
    this->ntp = ntp2;
}

unsigned int DHCPOptions::getNtpArraySize() const
{
    return ntp_arraysize;
}

IPv4Address& DHCPOptions::getNtp(unsigned int k)
{
    if (k>=ntp_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", ntp_arraysize, k);
    return this->ntp[k];
}

void DHCPOptions::setNtp(unsigned int k, const IPv4Address& ntp)
{
    if (k>=ntp_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", ntp_arraysize, k);
    this->ntp[k] = ntp;
}

IPv4Address& DHCPOptions::getServerIdentifier()
{
    return this->serverIdentifier;
}

void DHCPOptions::setServerIdentifier(const IPv4Address& serverIdentifier)
{
    this->serverIdentifier = serverIdentifier;
}

::omnetpp::simtime_t DHCPOptions::getRenewalTime() const
{
    return this->renewalTime;
}

void DHCPOptions::setRenewalTime(::omnetpp::simtime_t renewalTime)
{
    this->renewalTime = renewalTime;
}

::omnetpp::simtime_t DHCPOptions::getRebindingTime() const
{
    return this->rebindingTime;
}

void DHCPOptions::setRebindingTime(::omnetpp::simtime_t rebindingTime)
{
    this->rebindingTime = rebindingTime;
}

::omnetpp::simtime_t DHCPOptions::getLeaseTime() const
{
    return this->leaseTime;
}

void DHCPOptions::setLeaseTime(::omnetpp::simtime_t leaseTime)
{
    this->leaseTime = leaseTime;
}

class DHCPOptionsDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    DHCPOptionsDescriptor();
    virtual ~DHCPOptionsDescriptor();

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

Register_ClassDescriptor(DHCPOptionsDescriptor)

DHCPOptionsDescriptor::DHCPOptionsDescriptor() : omnetpp::cClassDescriptor("inet::DHCPOptions", "omnetpp::cObject")
{
    propertynames = nullptr;
}

DHCPOptionsDescriptor::~DHCPOptionsDescriptor()
{
    delete[] propertynames;
}

bool DHCPOptionsDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DHCPOptions *>(obj)!=nullptr;
}

const char **DHCPOptionsDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DHCPOptionsDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DHCPOptionsDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 13+basedesc->getFieldCount() : 13;
}

unsigned int DHCPOptionsDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISARRAY | FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<13) ? fieldTypeFlags[field] : 0;
}

const char *DHCPOptionsDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageType",
        "hostName",
        "parameterRequestList",
        "clientIdentifier",
        "requestedIp",
        "subnetMask",
        "router",
        "dns",
        "ntp",
        "serverIdentifier",
        "renewalTime",
        "rebindingTime",
        "leaseTime",
    };
    return (field>=0 && field<13) ? fieldNames[field] : nullptr;
}

int DHCPOptionsDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='m' && strcmp(fieldName, "messageType")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "hostName")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "parameterRequestList")==0) return base+2;
    if (fieldName[0]=='c' && strcmp(fieldName, "clientIdentifier")==0) return base+3;
    if (fieldName[0]=='r' && strcmp(fieldName, "requestedIp")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "subnetMask")==0) return base+5;
    if (fieldName[0]=='r' && strcmp(fieldName, "router")==0) return base+6;
    if (fieldName[0]=='d' && strcmp(fieldName, "dns")==0) return base+7;
    if (fieldName[0]=='n' && strcmp(fieldName, "ntp")==0) return base+8;
    if (fieldName[0]=='s' && strcmp(fieldName, "serverIdentifier")==0) return base+9;
    if (fieldName[0]=='r' && strcmp(fieldName, "renewalTime")==0) return base+10;
    if (fieldName[0]=='r' && strcmp(fieldName, "rebindingTime")==0) return base+11;
    if (fieldName[0]=='l' && strcmp(fieldName, "leaseTime")==0) return base+12;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DHCPOptionsDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "string",
        "int",
        "MACAddress",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "simtime_t",
        "simtime_t",
        "simtime_t",
    };
    return (field>=0 && field<13) ? fieldTypeStrings[field] : nullptr;
}

const char **DHCPOptionsDescriptor::getFieldPropertyNames(int field) const
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

const char *DHCPOptionsDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::DHCPMessageType";
            return nullptr;
        default: return nullptr;
    }
}

int DHCPOptionsDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DHCPOptions *pp = (DHCPOptions *)object; (void)pp;
    switch (field) {
        case 2: return pp->getParameterRequestListArraySize();
        case 6: return pp->getRouterArraySize();
        case 7: return pp->getDnsArraySize();
        case 8: return pp->getNtpArraySize();
        default: return 0;
    }
}

const char *DHCPOptionsDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DHCPOptions *pp = (DHCPOptions *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DHCPOptionsDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DHCPOptions *pp = (DHCPOptions *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getMessageType(), "inet::DHCPMessageType");
        case 1: return oppstring2string(pp->getHostName());
        case 2: return long2string(pp->getParameterRequestList(i));
        case 3: {std::stringstream out; out << pp->getClientIdentifier(); return out.str();}
        case 4: {std::stringstream out; out << pp->getRequestedIp(); return out.str();}
        case 5: {std::stringstream out; out << pp->getSubnetMask(); return out.str();}
        case 6: {std::stringstream out; out << pp->getRouter(i); return out.str();}
        case 7: {std::stringstream out; out << pp->getDns(i); return out.str();}
        case 8: {std::stringstream out; out << pp->getNtp(i); return out.str();}
        case 9: {std::stringstream out; out << pp->getServerIdentifier(); return out.str();}
        case 10: return simtime2string(pp->getRenewalTime());
        case 11: return simtime2string(pp->getRebindingTime());
        case 12: return simtime2string(pp->getLeaseTime());
        default: return "";
    }
}

bool DHCPOptionsDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DHCPOptions *pp = (DHCPOptions *)object; (void)pp;
    switch (field) {
        case 0: pp->setMessageType((inet::DHCPMessageType)string2enum(value, "inet::DHCPMessageType")); return true;
        case 1: pp->setHostName((value)); return true;
        case 2: pp->setParameterRequestList(i,string2long(value)); return true;
        case 10: pp->setRenewalTime(string2simtime(value)); return true;
        case 11: pp->setRebindingTime(string2simtime(value)); return true;
        case 12: pp->setLeaseTime(string2simtime(value)); return true;
        default: return false;
    }
}

const char *DHCPOptionsDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 3: return omnetpp::opp_typename(typeid(MACAddress));
        case 4: return omnetpp::opp_typename(typeid(IPv4Address));
        case 5: return omnetpp::opp_typename(typeid(IPv4Address));
        case 6: return omnetpp::opp_typename(typeid(IPv4Address));
        case 7: return omnetpp::opp_typename(typeid(IPv4Address));
        case 8: return omnetpp::opp_typename(typeid(IPv4Address));
        case 9: return omnetpp::opp_typename(typeid(IPv4Address));
        default: return nullptr;
    };
}

void *DHCPOptionsDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DHCPOptions *pp = (DHCPOptions *)object; (void)pp;
    switch (field) {
        case 3: return (void *)(&pp->getClientIdentifier()); break;
        case 4: return (void *)(&pp->getRequestedIp()); break;
        case 5: return (void *)(&pp->getSubnetMask()); break;
        case 6: return (void *)(&pp->getRouter(i)); break;
        case 7: return (void *)(&pp->getDns(i)); break;
        case 8: return (void *)(&pp->getNtp(i)); break;
        case 9: return (void *)(&pp->getServerIdentifier()); break;
        default: return nullptr;
    }
}

Register_Class(DHCPMessage)

DHCPMessage::DHCPMessage(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->op = 0;
    this->htype = 0;
    this->hlen = 0;
    this->hops = 0;
    this->xid = 0;
    this->secs = 0;
    this->broadcast = false;
}

DHCPMessage::DHCPMessage(const DHCPMessage& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

DHCPMessage::~DHCPMessage()
{
}

DHCPMessage& DHCPMessage::operator=(const DHCPMessage& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void DHCPMessage::copy(const DHCPMessage& other)
{
    this->op = other.op;
    this->htype = other.htype;
    this->hlen = other.hlen;
    this->hops = other.hops;
    this->xid = other.xid;
    this->secs = other.secs;
    this->broadcast = other.broadcast;
    this->ciaddr = other.ciaddr;
    this->yiaddr = other.yiaddr;
    this->giaddr = other.giaddr;
    this->chaddr = other.chaddr;
    this->sname = other.sname;
    this->file = other.file;
    this->options = other.options;
}

void DHCPMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->op);
    doParsimPacking(b,this->htype);
    doParsimPacking(b,this->hlen);
    doParsimPacking(b,this->hops);
    doParsimPacking(b,this->xid);
    doParsimPacking(b,this->secs);
    doParsimPacking(b,this->broadcast);
    doParsimPacking(b,this->ciaddr);
    doParsimPacking(b,this->yiaddr);
    doParsimPacking(b,this->giaddr);
    doParsimPacking(b,this->chaddr);
    doParsimPacking(b,this->sname);
    doParsimPacking(b,this->file);
    doParsimPacking(b,this->options);
}

void DHCPMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->op);
    doParsimUnpacking(b,this->htype);
    doParsimUnpacking(b,this->hlen);
    doParsimUnpacking(b,this->hops);
    doParsimUnpacking(b,this->xid);
    doParsimUnpacking(b,this->secs);
    doParsimUnpacking(b,this->broadcast);
    doParsimUnpacking(b,this->ciaddr);
    doParsimUnpacking(b,this->yiaddr);
    doParsimUnpacking(b,this->giaddr);
    doParsimUnpacking(b,this->chaddr);
    doParsimUnpacking(b,this->sname);
    doParsimUnpacking(b,this->file);
    doParsimUnpacking(b,this->options);
}

int DHCPMessage::getOp() const
{
    return this->op;
}

void DHCPMessage::setOp(int op)
{
    this->op = op;
}

int DHCPMessage::getHtype() const
{
    return this->htype;
}

void DHCPMessage::setHtype(int htype)
{
    this->htype = htype;
}

int DHCPMessage::getHlen() const
{
    return this->hlen;
}

void DHCPMessage::setHlen(int hlen)
{
    this->hlen = hlen;
}

int DHCPMessage::getHops() const
{
    return this->hops;
}

void DHCPMessage::setHops(int hops)
{
    this->hops = hops;
}

unsigned int DHCPMessage::getXid() const
{
    return this->xid;
}

void DHCPMessage::setXid(unsigned int xid)
{
    this->xid = xid;
}

int DHCPMessage::getSecs() const
{
    return this->secs;
}

void DHCPMessage::setSecs(int secs)
{
    this->secs = secs;
}

bool DHCPMessage::getBroadcast() const
{
    return this->broadcast;
}

void DHCPMessage::setBroadcast(bool broadcast)
{
    this->broadcast = broadcast;
}

IPv4Address& DHCPMessage::getCiaddr()
{
    return this->ciaddr;
}

void DHCPMessage::setCiaddr(const IPv4Address& ciaddr)
{
    this->ciaddr = ciaddr;
}

IPv4Address& DHCPMessage::getYiaddr()
{
    return this->yiaddr;
}

void DHCPMessage::setYiaddr(const IPv4Address& yiaddr)
{
    this->yiaddr = yiaddr;
}

IPv4Address& DHCPMessage::getGiaddr()
{
    return this->giaddr;
}

void DHCPMessage::setGiaddr(const IPv4Address& giaddr)
{
    this->giaddr = giaddr;
}

MACAddress& DHCPMessage::getChaddr()
{
    return this->chaddr;
}

void DHCPMessage::setChaddr(const MACAddress& chaddr)
{
    this->chaddr = chaddr;
}

const char * DHCPMessage::getSname() const
{
    return this->sname.c_str();
}

void DHCPMessage::setSname(const char * sname)
{
    this->sname = sname;
}

const char * DHCPMessage::getFile() const
{
    return this->file.c_str();
}

void DHCPMessage::setFile(const char * file)
{
    this->file = file;
}

DHCPOptions& DHCPMessage::getOptions()
{
    return this->options;
}

void DHCPMessage::setOptions(const DHCPOptions& options)
{
    this->options = options;
}

class DHCPMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    DHCPMessageDescriptor();
    virtual ~DHCPMessageDescriptor();

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

Register_ClassDescriptor(DHCPMessageDescriptor)

DHCPMessageDescriptor::DHCPMessageDescriptor() : omnetpp::cClassDescriptor("inet::DHCPMessage", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

DHCPMessageDescriptor::~DHCPMessageDescriptor()
{
    delete[] propertynames;
}

bool DHCPMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<DHCPMessage *>(obj)!=nullptr;
}

const char **DHCPMessageDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *DHCPMessageDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int DHCPMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 14+basedesc->getFieldCount() : 14;
}

unsigned int DHCPMessageDescriptor::getFieldTypeFlags(int field) const
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
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISCOMPOUND | FD_ISCOBJECT,
    };
    return (field>=0 && field<14) ? fieldTypeFlags[field] : 0;
}

const char *DHCPMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "op",
        "htype",
        "hlen",
        "hops",
        "xid",
        "secs",
        "broadcast",
        "ciaddr",
        "yiaddr",
        "giaddr",
        "chaddr",
        "sname",
        "file",
        "options",
    };
    return (field>=0 && field<14) ? fieldNames[field] : nullptr;
}

int DHCPMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='o' && strcmp(fieldName, "op")==0) return base+0;
    if (fieldName[0]=='h' && strcmp(fieldName, "htype")==0) return base+1;
    if (fieldName[0]=='h' && strcmp(fieldName, "hlen")==0) return base+2;
    if (fieldName[0]=='h' && strcmp(fieldName, "hops")==0) return base+3;
    if (fieldName[0]=='x' && strcmp(fieldName, "xid")==0) return base+4;
    if (fieldName[0]=='s' && strcmp(fieldName, "secs")==0) return base+5;
    if (fieldName[0]=='b' && strcmp(fieldName, "broadcast")==0) return base+6;
    if (fieldName[0]=='c' && strcmp(fieldName, "ciaddr")==0) return base+7;
    if (fieldName[0]=='y' && strcmp(fieldName, "yiaddr")==0) return base+8;
    if (fieldName[0]=='g' && strcmp(fieldName, "giaddr")==0) return base+9;
    if (fieldName[0]=='c' && strcmp(fieldName, "chaddr")==0) return base+10;
    if (fieldName[0]=='s' && strcmp(fieldName, "sname")==0) return base+11;
    if (fieldName[0]=='f' && strcmp(fieldName, "file")==0) return base+12;
    if (fieldName[0]=='o' && strcmp(fieldName, "options")==0) return base+13;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *DHCPMessageDescriptor::getFieldTypeString(int field) const
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
        "int",
        "unsigned int",
        "int",
        "bool",
        "IPv4Address",
        "IPv4Address",
        "IPv4Address",
        "MACAddress",
        "string",
        "string",
        "DHCPOptions",
    };
    return (field>=0 && field<14) ? fieldTypeStrings[field] : nullptr;
}

const char **DHCPMessageDescriptor::getFieldPropertyNames(int field) const
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

const char *DHCPMessageDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "inet::DHCPOpcode";
            return nullptr;
        default: return nullptr;
    }
}

int DHCPMessageDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *DHCPMessageDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string DHCPMessageDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        case 0: return enum2string(pp->getOp(), "inet::DHCPOpcode");
        case 1: return long2string(pp->getHtype());
        case 2: return long2string(pp->getHlen());
        case 3: return long2string(pp->getHops());
        case 4: return ulong2string(pp->getXid());
        case 5: return long2string(pp->getSecs());
        case 6: return bool2string(pp->getBroadcast());
        case 7: {std::stringstream out; out << pp->getCiaddr(); return out.str();}
        case 8: {std::stringstream out; out << pp->getYiaddr(); return out.str();}
        case 9: {std::stringstream out; out << pp->getGiaddr(); return out.str();}
        case 10: {std::stringstream out; out << pp->getChaddr(); return out.str();}
        case 11: return oppstring2string(pp->getSname());
        case 12: return oppstring2string(pp->getFile());
        case 13: {std::stringstream out; out << pp->getOptions(); return out.str();}
        default: return "";
    }
}

bool DHCPMessageDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        case 0: pp->setOp((inet::DHCPOpcode)string2enum(value, "inet::DHCPOpcode")); return true;
        case 1: pp->setHtype(string2long(value)); return true;
        case 2: pp->setHlen(string2long(value)); return true;
        case 3: pp->setHops(string2long(value)); return true;
        case 4: pp->setXid(string2ulong(value)); return true;
        case 5: pp->setSecs(string2long(value)); return true;
        case 6: pp->setBroadcast(string2bool(value)); return true;
        case 11: pp->setSname((value)); return true;
        case 12: pp->setFile((value)); return true;
        default: return false;
    }
}

const char *DHCPMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 7: return omnetpp::opp_typename(typeid(IPv4Address));
        case 8: return omnetpp::opp_typename(typeid(IPv4Address));
        case 9: return omnetpp::opp_typename(typeid(IPv4Address));
        case 10: return omnetpp::opp_typename(typeid(MACAddress));
        case 13: return omnetpp::opp_typename(typeid(DHCPOptions));
        default: return nullptr;
    };
}

void *DHCPMessageDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    DHCPMessage *pp = (DHCPMessage *)object; (void)pp;
    switch (field) {
        case 7: return (void *)(&pp->getCiaddr()); break;
        case 8: return (void *)(&pp->getYiaddr()); break;
        case 9: return (void *)(&pp->getGiaddr()); break;
        case 10: return (void *)(&pp->getChaddr()); break;
        case 13: return (void *)static_cast<omnetpp::cObject *>(&pp->getOptions()); break;
        default: return nullptr;
    }
}

} // namespace inet

