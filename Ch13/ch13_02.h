#ifndef CH1302H
#define CH1302H

#include <string>
// 行为像值的类
class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &hasPtr) : ps(new std::string(*hasPtr.ps)), i(hasPtr.i) {}
  ~HasPtr() { delete ps; };
  HasPtr &operator=(const HasPtr &);

 private:
  std::string *ps;
  int i;
};

HasPtr &HasPtr::operator=(const HasPtr &hasPtr) {
  auto newp = new std::string(*hasPtr.ps);
  delete ps;
  ps = newp;
  i = hasPtr.i;
  return *this;
}

#endif