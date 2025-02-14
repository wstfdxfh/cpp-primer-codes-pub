#ifndef CH16_02_3_H
#define CH16_02_3_H

#include <iostream>
#include <string>

// 返回序列中一个元素的引用 使用尾置返回类型
template <typename It>
auto fcn(It beg, It end) -> decltype(*beg) {
  return *beg;
}

// 返回序列中一个元素的值 使用尾置返回类型
template <typename It>
auto fcn2(It beg, It end) ->
    typename std::remove_reference<decltype(*beg)>::type {
  return *beg;
}

#endif  // CH16_02_3_H