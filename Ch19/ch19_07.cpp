#include "ch19_07.h"

#include <iostream>

void foo() {
  static int si = 0;
  enum Loc { a, b };
  // 局部类
  struct Bar {
    Loc locVal;
    int barVal;
    void fooBar(Loc l = a) {
      barVal = si;
      locVal = l;
    }
  };
  Bar bar;
  bar.fooBar(b);
}

int main() {
  foo();
  return 0;
}
