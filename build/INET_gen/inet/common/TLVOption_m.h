//
// Generated file, do not edit! Created by nedtool 5.7 from /home/veins/artery/extern/inet/src/inet/common/TLVOption.msg.
//

#ifndef __INET_TLVOPTION_M_H
#define __INET_TLVOPTION_M_H

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

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/common/TLVOption.msg:28</tt> by nedtool.
 * <pre>
 * class TLVOptionBase
 * {
 *     short type = -1;
 *     short length = 0;   // total length of option
 * }
 * </pre>
 */
class TLVOptionBase : public ::omnetpp::cObject
{
  protected:
    short type;
    short length;

  private:
    void copy(const TLVOptionBase& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TLVOptionBase&);

  public:
    TLVOptionBase();
    TLVOptionBase(const TLVOptionBase& other);
    virtual ~TLVOptionBase();
    TLVOptionBase& operator=(const TLVOptionBase& other);
    virtual TLVOptionBase *dup() const override {return new TLVOptionBase(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual short getType() const;
    virtual void setType(short type);
    virtual short getLength() const;
    virtual void setLength(short length);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TLVOptionBase& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TLVOptionBase& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/common/TLVOption.msg:34</tt> by nedtool.
 * <pre>
 * class TLVOptionRaw extends TLVOptionBase
 * {
 *     char bytes[];
 * }
 * </pre>
 */
class TLVOptionRaw : public ::inet::TLVOptionBase
{
  protected:
    char *bytes; // array ptr
    unsigned int bytes_arraysize;

  private:
    void copy(const TLVOptionRaw& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TLVOptionRaw&);

  public:
    TLVOptionRaw();
    TLVOptionRaw(const TLVOptionRaw& other);
    virtual ~TLVOptionRaw();
    TLVOptionRaw& operator=(const TLVOptionRaw& other);
    virtual TLVOptionRaw *dup() const override {return new TLVOptionRaw(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setBytesArraySize(unsigned int size);
    virtual unsigned int getBytesArraySize() const;
    virtual char getBytes(unsigned int k) const;
    virtual void setBytes(unsigned int k, char bytes);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const TLVOptionRaw& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, TLVOptionRaw& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>/home/veins/artery/extern/inet/src/inet/common/TLVOption.msg:39</tt> by nedtool.
 * <pre>
 * class TLVOptions
 * {
 *     \@customize(true);
 *     abstract TLVOptionBase tlvOption[];
 * }
 * </pre>
 *
 * TLVOptions_Base is only useful if it gets subclassed, and TLVOptions is derived from it.
 * The minimum code to be written for TLVOptions is the following:
 *
 * <pre>
 * class TLVOptions : public TLVOptions_Base
 * {
 *   private:
 *     void copy(const TLVOptions& other) { ... }

 *   public:
 *     TLVOptions() : TLVOptions_Base() {}
 *     TLVOptions(const TLVOptions& other) : TLVOptions_Base(other) {copy(other);}
 *     TLVOptions& operator=(const TLVOptions& other) {if (this==&other) return *this; TLVOptions_Base::operator=(other); copy(other); return *this;}
 *     virtual TLVOptions *dup() const override {return new TLVOptions(*this);}
 *     // ADD CODE HERE to redefine and implement pure virtual functions from TLVOptions_Base
 * };
 * </pre>
 *
 * The following should go into a .cc (.cpp) file:
 *
 * <pre>
 * Register_Class(TLVOptions)
 * </pre>
 */
class TLVOptions_Base : public ::omnetpp::cObject
{
  protected:

  private:
    void copy(const TLVOptions_Base& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TLVOptions_Base&);
    // make constructors protected to avoid instantiation
    TLVOptions_Base();
    TLVOptions_Base(const TLVOptions_Base& other);
    // make assignment operator protected to force the user override it
    TLVOptions_Base& operator=(const TLVOptions_Base& other);

  public:
    virtual ~TLVOptions_Base();
    virtual TLVOptions_Base *dup() const override {throw omnetpp::cRuntimeError("You forgot to manually add a dup() function to class TLVOptions");}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual void setTlvOptionArraySize(unsigned int size) = 0;
    virtual unsigned int getTlvOptionArraySize() const = 0;
    virtual TLVOptionBase& getTlvOption(unsigned int k) = 0;
    virtual const TLVOptionBase& getTlvOption(unsigned int k) const {return const_cast<TLVOptions_Base*>(this)->getTlvOption(k);}
    virtual void setTlvOption(unsigned int k, const TLVOptionBase& tlvOption) = 0;
};

} // namespace inet

#endif // ifndef __INET_TLVOPTION_M_H
