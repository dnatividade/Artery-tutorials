//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/ipv4/ipsec/IPsecEncapsulatingSecurityPayload.msg.
//

#ifndef __INET__IPSEC_IPSECENCAPSULATINGSECURITYPAYLOAD_M_H
#define __INET__IPSEC_IPSECENCAPSULATINGSECURITYPAYLOAD_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0507
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif


namespace inet {
namespace ipsec {

// cplusplus {{
const int ESP_FIXED_HEADER_BYTES = 8;  // length of the SPI and Sequence Number fields
const int ESP_FIXED_PAYLOAD_TRAILER_BYTES = 2; // length of the Pad Length and Next Header fields
// }}

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/networklayer/ipv4/ipsec/IPsecEncapsulatingSecurityPayload.msg:28</tt> by nedtool.
 * <pre>
 * //
 * // IPsec ESP packet (RFC 4303).
 * //
 * packet IPsecEncapsulatingSecurityPayload
 * {
 *     uint32_t spi; // security parameters index
 *     uint32_t sequenceNumber;
 *     uint8_t padLength;
 *     uint8_t nextHeader; // IP Protocol number defined by IANA (4 = IPv4; 41 IPv6; 6 = TCP)
 * }
 * </pre>
 */
class IPsecEncapsulatingSecurityPayload : public ::omnetpp::cPacket
{
  protected:
    uint32_t spi;
    uint32_t sequenceNumber;
    uint8_t padLength;
    uint8_t nextHeader;

  private:
    void copy(const IPsecEncapsulatingSecurityPayload& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const IPsecEncapsulatingSecurityPayload&);

  public:
    IPsecEncapsulatingSecurityPayload(const char *name=nullptr, short kind=0);
    IPsecEncapsulatingSecurityPayload(const IPsecEncapsulatingSecurityPayload& other);
    virtual ~IPsecEncapsulatingSecurityPayload();
    IPsecEncapsulatingSecurityPayload& operator=(const IPsecEncapsulatingSecurityPayload& other);
    virtual IPsecEncapsulatingSecurityPayload *dup() const override {return new IPsecEncapsulatingSecurityPayload(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual uint32_t getSpi() const;
    virtual void setSpi(uint32_t spi);
    virtual uint32_t getSequenceNumber() const;
    virtual void setSequenceNumber(uint32_t sequenceNumber);
    virtual uint8_t getPadLength() const;
    virtual void setPadLength(uint8_t padLength);
    virtual uint8_t getNextHeader() const;
    virtual void setNextHeader(uint8_t nextHeader);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const IPsecEncapsulatingSecurityPayload& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, IPsecEncapsulatingSecurityPayload& obj) {obj.parsimUnpack(b);}

} // namespace ipsec
} // namespace inet

#endif // ifndef __INET__IPSEC_IPSECENCAPSULATINGSECURITYPAYLOAD_M_H

