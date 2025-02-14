#ifndef CH16_02_6_H
#define CH16_02_6_H

#include <iostream>
#include <string>
#include <utility>

void g(int &&i, int &j) { std::cout << i << " " << j << std::endl; }

template <typename F, typename T1, typename T2>
// 该函数将会保留实参的左右值属性
void flip(F f, T1 &&t1, T2 &&t2) {
  f(std::forward<T2>(t2), std::forward<T1>(t1));
}

#endif  // CH16_02_6_H