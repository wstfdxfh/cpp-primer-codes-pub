#ifndef CH16_04_H
#define CH16_04_H

#include <iostream>
#include <string>

// void foo() {}  // 基准情况

template <typename T>
void foo(const T& t) {
  std::cout << t << std::endl;
}

template <typename T, typename... Args>
void foo(const T& t, const Args&... rest) {
  std::cout << t << std::endl;
  std::cout << sizeof...(rest) << std::endl;
  foo(rest...);
}

#endif  // CH16_04_H