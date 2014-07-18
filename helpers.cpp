#include "helpers.h"

#include <iomanip>
#include <sstream>

using namespace std;

const char* BINARY2[4] = { "00", "01", "10", "11" };
const char* BINARY3[8] = {
    "000", "001", "010", "011", "100", "101", "110", "111" };

const char* REG16_DESC[13] = {
    "AX", "BX", "CX", "DX", "CS", "DS", "SS", "ES", "BP", "SP", "DI", "SI", "IP" };

const char* REG8_DESC[8] = {
    "AL", "AH", "BL", "BH", "CL", "CH", "DL", "DH" };

_Hex8 Hex8;
_Hex16 Hex16;

ostream& operator<< (ostream& os, const _Hex8&) {
  os << hex << setw(2) << setfill('0') << uppercase; 
  return os;
}

ostream& operator<< (ostream& os, const _Hex16&) {
  os << hex << setw(4) << setfill('0') << uppercase; 
  return os;
}

ostream& operator<< (ostream& os, const Addr& addr) {
  os << "[" << Hex16 << addr.seg_ << ":" << Hex16 << addr.off_ << "]";
  return os;
}

string hex8ToString(byte val) {
  stringstream ss;
  ss << Hex8 << (int)val;
  return ss.str();
}


string hex16ToString(word val) {
  stringstream ss;
  ss << Hex16 << (int)val;
  return ss.str();
}


string addrToString(const Addr& addr) {
  stringstream ss;
  ss << addr;
  return ss.str();
}
