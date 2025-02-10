#include "ch13_03.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// 相较于默认的swap函数，内存开销更小
inline void swap(HasPtr &lhs, HasPtr &rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
}

// 赋值运算符使用swap实现方法
HasPtr &HasPtr::operator=(HasPtr hasPtr) {
  swap(*this, hasPtr);
  return *this;
}

int main() {
  HasPtr p1("Wow");
  HasPtr p2("Hello");
  swap(p1, p2);
  cout << *p2.ps << endl;
  return 0;
}