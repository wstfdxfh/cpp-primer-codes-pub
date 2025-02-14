#include "ch16_02_3.h"

#include <iostream>
#include <string>

using namespace std;

template <typename T>
auto sum(T lhs, T rhs) -> decltype(lhs + rhs) {
  return lhs + rhs;
}

int main() {
  int i = 1, j = 2;
  auto val = sum(i, j);
  cout << val << endl;
}