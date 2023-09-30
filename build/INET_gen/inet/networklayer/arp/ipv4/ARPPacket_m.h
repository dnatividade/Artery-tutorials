//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/networklayer/arp/ipv4/ARPPacket.msg.
//

#ifndef __INET_ARPPACKET_M_H
#define __INET_ARPPACKET_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0507
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
#include "inet/networklayer/contract/ipv4/IPv4Address.h"
#include "inet/linklayer/common/MACAddress.h"
// }}


namespace inet {

// cplusplus {{
// ARP header length for IPv4 (4-byte addresses) and 802 LANs (6-byte MAC addrs)
#define ARP_HEADER_BYTES   28
// }}

/**
 * Enum generated from <tt>/home/veins/artery/extern/inet/src/inet/networklayer/arp/ipv4/ARPPacket.msg:42</tt> by nedtool.
 * <pre>
 * //
 * // The list of practically important ARP opcodes
 * //
 * enum ARPOpcode
 * {
 *     ARP_REQUEST = 1;      // Request. RFC 826
 *     ARP_REPLY = 2;        // Reply. RFC 826, RFC 1868
 *     ARP_RARP_REQUEST = 3; // Request Reverse. RFC 903
 *     ARP_RARP_REPLY = 4;   // Reply Reverse. RFC 903
 * }
 * </pre>
 */
enum ARPOpcode {
    ARP_REQUEST = 1,
    ARP_REPLY = 2,
    ARP_RARP_REQUEST = 3,
    ARP_RARP_REPLY = 4
};

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/networklayer/arp/ipv4/ARPPacket.msg:62</tt> by nedtool.
 * <pre>
 * //
 * // ARP packet. This is a specialized version: prepared for IEEE 802 hardware
 * // addresses and IPv4. Packet fields are therefore represented by C++ classes
 * // MACAddress and IPv4Address. Also, some ARP protocol header fields are
 * // not modelled explicitly (their values are implied):
 * //   - hardwareType (not needed for modelling);
 * //   - protocol type (0x800 IPv4)
 * //   - hardware address length (6)
 * //   - protocol address length (4)
 * //
 * packet ARPPacket
 * {
 *     int opcode \@enum(ARPOpcode);
 *     MACAddress srcMACAddress;
 *     MACAddress destMACAddress;
 *     IPv4Address srcIPAddress;
 *     IPv4Address destIPAddress;
 * }
 * </pre>
 */
class ARPPacket : public ::omnetpp::cPacket
{
  protected:
    int opcode;
    MACAddress srcMACAddress;
    MACAddress destMACAddress;
    IPv4Address srcIPAddress;
    IPv4Address destIPAddress;

  private:
    void copy(const ARPPacket& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ARPPacket&);

  public:
    ARPPacket(const char *name=nullptr, short kind=0);
    ARPPacket(const ARPPacket& other);
    virtual ~ARPPacket();
    ARPPacket& operator=(const ARPPacket& other);
    virtual ARPPacket *dup() const override {return new ARPPacket(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual int getOpcode() const;
    virtual void setOpcode(int opcode);
    virtual MACAddress& getSrcMACAddress();
    virtual const MACAddress& getSrcMACAddress() const {return const_cast<ARPPacket*>(this)->getSrcMACAddress();}
    virtual void setSrcMACAddress(const MACAddress& srcMACAddress);
    virtual MACAddress& getDestMACAddress();
    virtual const MACAddress& getDestMACAddress() const {return const_cast<ARPPacket*>(this)->getDestMACAddress();}
    virtual void setDestMACAddress(const MACAddress& destMACAddress);
    virtual IPv4Address& getSrcIPAddress();
    virtual const IPv4Address& getSrcIPAddress() const {return const_cast<ARPPacket*>(this)->getSrcIPAddress();}
    virtual void setSrcIPAddress(const IPv4Address& srcIPAddress);
    virtual IPv4Address& getDestIPAddress();
    virtual const IPv4Address& getDestIPAddress() const {return const_cast<ARPPacket*>(this)->getDestIPAddress();}
    virtual void setDestIPAddress(const IPv4Address& destIPAddress);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ARPPacket& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ARPPacket& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_ARPPACKET_M_H

