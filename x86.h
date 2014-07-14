#ifndef __X86_H__
#define __X86_H__

#include "generator/x86_base.h"
#include "types.h"

class Memory;

//
// Registers.
//
struct Registers {
  union {
    word regs16[12];
    struct {
      word ax, bx, cx, dx, cs, ds, ss, es, bp, sp, di, si;
    };

    byte regs8[8];
    struct {
      byte al, ah;
      byte bl, bh;
      byte cl, ch;
      byte dl, dh;
    };
  };

  word ip;
};


//
// x86 CPU.
//
class X86 : public X86Base {
 public:
  X86(Memory* mem);

  Registers* getRegisters();

  void reset();
  virtual void step();

 public:
  int getCS_IP() const;
  int getSS_SP() const;
  int getLinearAddress(word segment, word offset) const;
  void incrementAddress(word& segment, word& offset);
  void decrementAddress(word& segment, word& offset);
 
  //
  // X86Base overrides.
  //
  virtual byte fetch();
  virtual void notImplemented(const char* opcode_name);
  virtual void invalidOpcode();

  virtual word* getReg16Ptr(int reg);
  virtual byte* getReg8Ptr(int reg);
  virtual word* getMem16Ptr(word segment, word offset);

  //
  // Opcode implementations.
  //
  virtual void MOV_w();
  virtual void PUSH();
  virtual void SUB_w();

 private:
  Memory* mem_;
 
  Registers regs_;
  word current_cs_, current_ip_;
};

#endif  // __X86_H__
