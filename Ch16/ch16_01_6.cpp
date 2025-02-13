#include "ch16_01_6.h"

#include <iostream>
#include <memory>
#include <string>

using namespace std;
int main() {
  // 原始的 shared_ptr
  shared_ptr<int> sp = make_shared<int>(1);
  sp.reset(new int(10), DebugDelete());
  cout << *sp << endl;

  // 使用 DebugDelete 作为删除器的 unique_ptr
  unique_ptr<int, DebugDelete> up(new int(28), DebugDelete());
  cout << *up << endl;

  return 0;
}