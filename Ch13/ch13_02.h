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

  //  private:
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
// 行为像指针的类
class HasPtr2 {
 public:
  HasPtr2(const std::string &s = std::string())
      : ps(new std::string(s)), i(0), use(new std::size_t(1)) {}
  HasPtr2(const HasPtr2 &hasPtr) : ps(hasPtr.ps), i(hasPtr.i), use(hasPtr.use) {
    ++*use;
  }
  HasPtr2 &operator=(const HasPtr2 &);
  ~HasPtr2();

  //  private:
  std::string *ps;
  int i;
  // 用于记录多少对象共享*ps的成员
  std::size_t *use;
};

#endif