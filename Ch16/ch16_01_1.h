#ifndef CH16_01_1_H
#define CH16_01_1_H

#include <iostream>
#include <string>

template <typename It, typename T>
It find(It begin, It end, T val) {
  while (begin != end) {
    if (*begin == val) {
      return begin;
    }
    ++begin;
  }
  return end;
}

#endif  // CH16_01_1_H