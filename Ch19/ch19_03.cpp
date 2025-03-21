#include "ch19_03.h"

#include <iostream>
// 限定作用域的enum
enum class color { red, green, blue };
// 不限定作用域的enum
enum colour { red, green, blue };

void f1(int) {}
int main() {
  auto c1 = red;
  auto c2 = color::red;
  switch (c2) {
    case color::red:
      std::cout << "Red" << std::endl;
      break;
    case color::green:
      std::cout << "Green" << std::endl;
      break;
    case color::blue:
      std::cout << "Blue" << std::endl;
      break;
    default:
      break;
  }

  f1(1);  // 调用f1(int)
  // 不限定作用域的enum可以隐式转换为int
  f1(red);

  return 0;
}
