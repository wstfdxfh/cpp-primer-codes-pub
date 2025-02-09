#ifndef CH1303H
#define CH1303H

#include <string>

// 行为像值的类
class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &hasPtr) : ps(new std::string(*hasPtr.ps)), i(hasPtr.i) {}
  ~HasPtr() { delete ps; };
  HasPtr &operator=(HasPtr);

  //  private:
  std::string *ps;
  int i;
};

#endif