#include "ch16_03.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
  string s("hi");
  cout << debug_rep(s) << endl;
  cout << debug_rep(&s) << endl;
  const string *sp = &s;
  // 模板匹配的特例：const T* 优先匹配 T* 版本 这里T=const string
  cout << debug_rep(sp) << endl;
  cout << debug_rep("hi") << endl;

  return 0;
}