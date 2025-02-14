#include "ch16_02_1.h"

#include <functional>
#include <iostream>
#include <string>

using namespace std;

template <typename T, typename F = less<T>>
int compare(const T& v1, const T& v2, F f = F()) {
  if (f(v1, v2)) return -1;
  if (f(v2, v1)) return 1;
  return 0;
}

int main() {
  int i = 100;
  long lng = 1000;
  // 错误，实例化过程中不能执行算数类型转换
  // compare(i, long);

  return 0;
}