//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/linklayer/common/Ieee802Ctrl.msg.
//

#ifndef __INET_IEEE802CTRL_M_H
#define __INET_IEEE802CTRL_M_H

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
#include "inet/linklayer/common/MACAddress.h"
// }}


namespace inet {

/**
 * Enum generated from <tt>/home/veins/artery/extern/inet/src/inet/linklayer/common/Ieee802Ctrl.msg:31</tt> by nedtool.
 * <pre>
 * //
 * // Message kind values used with in communication between L3 and IEEE 802 L2
 * //
 * enum Ieee802MessageKind
 * {
 *     IEEE802CTRL_DATA = 2003;  // data to/from higher layer
 *     IEEE802CTRL_REGISTER_DSAP = 2004;  // higher layer registers itself in LLC
 *     IEEE802CTRL_DEREGISTER_DSAP = 2005;  // higher layer deregisters itself in LLC
 *     IEEE802CTRL_SENDPAUSE = 2006;  // higher layer wants MAC to send PAUSE frame
 * }
 * </pre>
 */
enum Ieee802MessageKind {
    IEEE802CTRL_DATA = 2003,
    IEEE802CTRL_REGISTER_DSAP = 2004,
    IEEE802CTRL_DEREGISTER_DSAP = 2005,
    IEEE802CTRL_SENDPAUSE = 2006
};

/**
 * Enum generated from <tt>/home/veins/artery/extern/inet/src/inet/linklayer/common/Ieee802Ctrl.msg:43</tt> by nedtool.
 * <pre>
 * //
 * // Some 8-bit SAP values for IEEE 802.x LLC headers.
 * //
 * enum SAPCode
 * {
 *     SAP_IBM_SNA = 0x04;
 *     SAP_IP = 0x06;
 *     SAP_3COM = 0x80;
 *     SAP_SNAP = 0xAA;
 *     SAP_BANYAN = 0xBC;
 *     SAP_NOVELL_IPX = 0xE0;
 *     SAP_LAN_MANAGER = 0xF4;
 *     SAP_CLNS = 0xFE;
 *     SAP_STP = 0x42;
 * }
 * </pre>
 */
enum SAPCode {
    SAP_IBM_SNA = 0x04,
    SAP_IP = 0x06,
    SAP_3COM = 0x80,
    SAP_SNAP = 0xAA,
    SAP_BANYAN = 0xBC,
    SAP_NOVELL_IPX = 0xE0,
    SAP_LAN_MANAGER = 0xF4,
    SAP_CLNS = 0xFE,
    SAP_STP = 0x42
};

/**
 * Enum generated from <tt>/home/veins/artery/extern/inet/src/inet/linklayer/common/Ieee802Ctrl.msg:60</tt> by nedtool.
 * <pre>
 * //
 * // Some EtherType values (Ethernet II).
 * //
 * enum EtherType
 * {
 *     ETHERTYPE_IPv4 = 0x0800;
 *     ETHERTYPE_ARP = 0x0806;
 *     ETHERTYPE_TRILL = 0x22F3;
 *     ETHERTYPE_L2_ISIS = 0x22F4;
 *     ETHERTYPE_RARP = 0x8035;
 *     ETHERTYPE_IPv6 = 0x86DD;
 *     ETHERTYPE_INET_GENERIC = 0x86FF;    // not in standard, INET spceific value for \@GenericNetworkProtocol
 *     ETHERTYPE_MPLS_UNICAST = 0x8847;
 *     ETHERTYPE_MPLS_MULTICAST = 0x8848;
 * }
 * </pre>
 */
enum EtherType {
    ETHERTYPE_IPv4 = 0x0800,
    ETHERTYPE_ARP = 0x0806,
    ETHERTYPE_TRILL = 0x22F3,
    ETHERTYPE_L2_ISIS = 0x22F4,
    ETHERTYPE_RARP = 0x8035,
    ETHERTYPE_IPv6 = 0x86DD,
    ETHERTYPE_INET_GENERIC = 0x86FF,
    ETHERTYPE_MPLS_UNICAST = 0x8847,
    ETHERTYPE_MPLS_MULTICAST = 0x8848
};

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/linklayer/common/Ieee802Ctrl.msg:77</tt> by nedtool.
 * <pre>
 * //
 * // Control structure for communication between LLC and higher layers
 * //
 * class Ieee802Ctrl
 * {
 *     \@customize(true);
 * 
 *     MACAddress src;  // src MAC address (can be left empty when sending)
 *     MACAddress dest; // dest MAC address
 *     int etherType \@enum(EtherType);   // used with ~EthernetIIFrame
 *     int interfaceId; // incoming or outgoing interface (not needed everywhere)
 *     int switchPort = -1; // swich port index (only in swiches)
 *     int userPriority = -1; // 802.1d User Priority (UP), 0..7. Note: In 802.11, UP corresponds to 0..7 TID values, and there's a standard static mapping from TID to AC (Access Category)
 *     int ssap;        // used with IEEE 802 LLC (see ~EtherFrameWithLLC)
 *     int dsap;        // used with IEEE 802 LLC (see ~EtherFrameWithLLC)
 *     int pauseUnits;  // used with IEEE802CTRL_SENDPAUSE
 * }
 * </pre>
 *
 * Ieee802Ctrl_Base is only useful if it gets subclassed, and Ieee802Ctrl is derived from it.
 * The minimum code to be written for Ieee802Ctrl is the following:
 *
 * <pre>
 * class Ieee802Ctrl : public Ieee802Ctrl_Base
 * {
 *   private:
 *     void copy(const Ieee802Ctrl& other) { ... }

 *   public:
 *     Ieee802Ctrl() : Ieee802Ctrl_Base() {}
 *     Ieee802Ctrl(const Ieee802Ctrl& other) : Ieee802Ctrl_Base(other) {copy(other);}
 *     Ieee802Ctrl& operator=(const Ieee802Ctrl& other) {if (this==&other) return *this; Ieee802Ctrl_Base::operator=(other); copy(other); return *this;}
 *     virtual Ieee802Ctrl *dup() const override {return new Ieee802Ctrl(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from Ieee802Ctrl_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(Ieee802Ctrl)
 * </pre>
 */
class Ieee802Ctrl_Base : public ::omnetpp::cObject
{
  protected:
    MACAddress src;
    MACAddress dest;
    int etherType;
    int interfaceId;
    int switchPort;
    int userPriority;
    int ssap;
    int dsap;
    int pauseUnits;

  private:
    void copy(const Ieee802Ctrl_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const Ieee802Ctrl_Base&);
    // make constructors protected to avoid instantiation
    Ieee802Ctrl_Base();
    Ieee802Ctrl_Base(const Ieee802Ctrl_Base& other);
    // make assignment operator protected to force the user override it
    Ieee802Ctrl_Base& operator=(const Ieee802Ctrl_Base& other);

  public:
    virtual ~Ieee802Ctrl_Base();
    virtual Ieee802Ctrl_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class Ieee802Ctrl");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual MACAddress& getSrc();
    virtual const MACAddress& getSrc() const {return const_cast<Ieee802Ctrl_Base*>(this)->getSrc();}
    virtual void setSrc(const MACAddress& src);
    virtual MACAddress& getDest();
    virtual const MACAddress& getDest() const {return const_cast<Ieee802Ctrl_Base*>(this)->getDest();}
    virtual void setDest(const MACAddress& dest);
    virtual int getEtherType() const;
    virtual void setEtherType(int etherType);
    virtual int getInterfaceId() const;
    virtual void setInterfaceId(int interfaceId);
    virtual int getSwitchPort() const;
    virtual void setSwitchPort(int switchPort);
    virtual int getUserPriority() const;
    virtual void setUserPriority(int userPriority);
    virtual int getSsap() const;
    virtual void setSsap(int ssap);
    virtual int getDsap() const;
    virtual void setDsap(int dsap);
    virtual int getPauseUnits() const;
    virtual void setPauseUnits(int pauseUnits);
};

} // namespace inet

#endif // ifndef __INET_IEEE802CTRL_M_H

