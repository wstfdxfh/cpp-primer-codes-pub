#include "ch16_02_4.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
  int (*pf)(const int&, const int&) = compare;

  // 函数重载
  void func(int (*)(const string&, const string&));
  void func(int (*)(const int&, const int&));
  // 错误 使用compare的哪个实例？
  //   func(compare);
  func(compare<string>);
  func(compare<int>);

  return 0;
}