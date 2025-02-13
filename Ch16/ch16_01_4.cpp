#include "ch16_01_4.h"

#include <iostream>
#include <memory>
#include <string>
using namespace std;

int main() {
  double* p = new double;
  DebugDelete d;
  d(p);

  // 重载unique_ptr的删除器
  unique_ptr<int, DebugDelete> ip(new int, DebugDelete());

  vector<int> vi = {1, 2, 3};
  Blob<int> a1(vi.begin(), vi.end());

  return 0;
}