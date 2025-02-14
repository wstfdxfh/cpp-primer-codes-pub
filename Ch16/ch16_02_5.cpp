#include "ch16_02_5.h"

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void f(T&& val) {
  T temp = val;
  temp = 42;
  std::cout << val << std::endl;
  std::cout << temp << std::endl;
}

int main() {
  int i = 10;
  f(10);
  f(i);
  return 0;
}