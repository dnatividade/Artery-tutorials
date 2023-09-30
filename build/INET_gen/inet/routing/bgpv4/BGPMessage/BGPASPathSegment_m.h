//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPASPathSegment.msg.
//

#ifndef __INET__BGP_BGPASPATHSEGMENT_M_H
#define __INET__BGP_BGPASPATHSEGMENT_M_H

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
#include "inet/routing/bgpv4/BGPCommon_m.h"
// }}


namespace inet {
namespace bgp {

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/routing/bgpv4/BGPMessage/BGPASPathSegment.msg:30</tt> by nedtool.
 * <pre>
 * //
 * // Represents a BGPv4 AS_PATH path attribute (RFC 4271 Section 4.3)
 * //
 * class BGPASPathSegment
 * {
 *     unsigned char type \@enum(BGPPathSegmentType);
 *     unsigned char length;
 *     unsigned short asValue[];
 * }
 * </pre>
 */
class BGPASPathSegment : public ::omnetpp::cObject
{
  protected:
    unsigned char type;
    unsigned char length;
    unsigned short *asValue; // array ptr
    unsigned int asValue_arraysize;

  private:
    void copy(const BGPASPathSegment& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BGPASPathSegment&);

  public:
    BGPASPathSegment();
    BGPASPathSegment(const BGPASPathSegment& other);
    virtual ~BGPASPathSegment();
    BGPASPathSegment& operator=(const BGPASPathSegment& other);
    virtual BGPASPathSegment *dup() const override {return new BGPASPathSegment(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual unsigned char getType() const;
    virtual void setType(unsigned char type);
    virtual unsigned char getLength() const;
    virtual void setLength(unsigned char length);
    virtual void setAsValueArraySize(unsigned int size);
    virtual unsigned int getAsValueArraySize() const;
    virtual unsigned short getAsValue(unsigned int k) const;
    virtual void setAsValue(unsigned int k, unsigned short asValue);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BGPASPathSegment& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BGPASPathSegment& obj) {obj.parsimUnpack(b);}

} // namespace bgp
} // namespace inet

#endif // ifndef __INET__BGP_BGPASPATHSEGMENT_M_H

