//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/linklayer/bmac/BMacFrame.msg.
//

#ifndef __INET_BMACFRAME_M_H
#define __INET_BMACFRAME_M_H

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
    #include "inet/linklayer/base/MACFrameBase_m.h"
// }}


namespace inet {

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/linklayer/bmac/BMacFrame.msg:28</tt> by nedtool.
 * <pre>
 * packet BMacFrame extends MACFrameBase
 * {
 * }
 * </pre>
 */
class BMacFrame : public ::inet::MACFrameBase
{
  protected:

  private:
    void copy(const BMacFrame& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BMacFrame&);

  public:
    BMacFrame(const char *name=nullptr, short kind=0);
    BMacFrame(const BMacFrame& other);
    virtual ~BMacFrame();
    BMacFrame& operator=(const BMacFrame& other);
    virtual BMacFrame *dup() const override {return new BMacFrame(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BMacFrame& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BMacFrame& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_BMACFRAME_M_H

