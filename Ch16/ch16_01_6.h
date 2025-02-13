#ifndef CH16_01_6_H
#define CH16_01_6_H

#include <iostream>
#include <memory>
#include <string>

class DebugDelete {
 public:
  DebugDelete(std::ostream& s = std::cerr) : os(s) {}
  template <typename T>
  void operator()(T* p) const {
    os << "deleting ptr" << std::endl;
    delete p;
  }

 private:
  std::ostream& os;
};

#endif  // CH16_01_6_H