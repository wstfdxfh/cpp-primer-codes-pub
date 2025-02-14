#ifndef CH16_02_4_H
#define CH16_02_4_H

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
int compare(const T& v1, const T& v2) {
  if (v1 < v2) return -1;
  if (v2 < v1) return 1;
  return 0;
}

#endif  // CH16_02_4_H