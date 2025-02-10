#ifndef CH1303H
#define CH1303H

#include <string>

// 行为像值的类
class HasPtr {
  friend void swap(HasPtr &, HasPtr &);

 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr &hasPtr) : ps(new std::string(*hasPtr.ps)), i(hasPtr.i) {}
  HasPtr(HasPtr &&hasPtr) noexcept : ps(hasPtr.ps), i(hasPtr.i) {
    hasPtr.ps = 0;
  }
  ~HasPtr() { delete ps; };
  // 同时充当拷贝赋值运算符和移动赋值运算符
  HasPtr &operator=(HasPtr);

  //  private:
  std::string *ps;
  int i;
};

#endif