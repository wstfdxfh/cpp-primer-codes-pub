#include "ch16_02_2.h"

#include <functional>
#include <iostream>
#include <string>

using namespace std;

template <typename T1, typename T2, typename T3>
T1 sum(T2 num1, T3 num2) {
  return num1 + num2;
}

template <typename T, typename F = less<T>>
int compare(const T& v1, const T& v2, F f = F()) {
  if (f(v1, v2)) return -1;
  if (f(v2, v1)) return 1;
  return 0;
}

int main() {
  // 显式指定T1类型 T2和T3由编译器通过参数类型推断为int
  auto val3 = sum<long long>(1, 2);

  cout << val3 << endl;
  int i = 100;
  long lng = 1000;
  //   显式指定后可以进行类型转换
  compare<long>(i, lng);

  auto res = max<long>(i, lng);
  cout << res << endl;

  return 0;
}