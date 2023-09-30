//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/linklayer/ppp/PPPFrame.msg.
//

#ifndef __INET_PPPFRAME_M_H
#define __INET_PPPFRAME_M_H

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
#include "inet/common/INETDefs.h"
// }}


namespace inet {

// cplusplus {{
const int PPP_OVERHEAD_BYTES = 7;
// }}

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/linklayer/ppp/PPPFrame.msg:49</tt> by nedtool.
 * <pre>
 * //
 * // PPP frame.
 * //
 * // Constant-value header fields are not modelled:
 * // Flag (=0x7e), address (=0xff), control (=0x03), CRC (bitError())
 * //
 * // CRC is modelled only via cMessage's bit error attribute.
 * //
 * // Protocol field is not modelled because types of encapsulated messages
 * // wil be determined from their class (using C++ dynamic_cast).
 * //
 * packet PPPFrame
 * {
 * }
 * </pre>
 */
class PPPFrame : public ::omnetpp::cPacket
{
  protected:

  private:
    void copy(const PPPFrame& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const PPPFrame&);

  public:
    PPPFrame(const char *name=nullptr, short kind=0);
    PPPFrame(const PPPFrame& other);
    virtual ~PPPFrame();
    PPPFrame& operator=(const PPPFrame& other);
    virtual PPPFrame *dup() const override {return new PPPFrame(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const PPPFrame& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, PPPFrame& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_PPPFRAME_M_H

