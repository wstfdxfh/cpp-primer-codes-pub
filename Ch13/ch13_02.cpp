#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "ch13_02.h"

HasPtr2::~HasPtr2() {
  if (--*use == 0) {
    delete ps;
    delete use;
  }
}

HasPtr2& HasPtr2::operator=(const HasPtr2& hasPtr) {
  ++*hasPtr.use;
  if (--*use == 0) {
    delete ps;
    delete use;
  }
  ps = hasPtr.ps;
  i = hasPtr.i;
  use = hasPtr.use;
  return *this;
}

int main() {
  HasPtr p1("Hiya!");
  HasPtr2 p2("Hello!");
  HasPtr2 p22 = p2;
  cout << *p22.ps << " " << *p22.use << endl;
  (*p22.ps).append(", World!");
  cout << *p2.ps << " " << *p2.use << endl;
  return 0;
}