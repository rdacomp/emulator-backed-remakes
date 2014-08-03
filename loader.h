#ifndef __LOADER_H__
#define __LOADER_H__

#include <string>

class Memory;
class X86Base;

class Loader {
 public:
  static void loadCOM(const std::string& filename, Memory* mem, X86Base* x86, int& start, int& end);
};

#endif  // __LOADER_H__
