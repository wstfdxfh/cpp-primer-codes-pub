#ifndef CH15_06_H
#define CH15_06_H

#include <string>

class Base {
 public:
  virtual int func() { return 0; }
};

class D1 : public Base {
 public:
  // 这个函数覆盖了基类的虚函数的名字，使得func()无法被直接访问
  int func(int i) { return i; }
};

#endif  // CH15_06_H