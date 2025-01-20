#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::getline;
using std::initializer_list;
using std::ispunct;
using std::isupper;
using std::string;
using std::toupper;
using std::vector;

int bigger(int i1, int i2) { return i1 > i2 ? i1 : i2; }
int add(int i1, int i2) { return i1 + i2; }
int minus(int i1, int i2) { return i1 - i2; }
int multiply(int i1, int i2) { return i1 * i2; }
int divide(int i1, int i2) { return i1 / i2; }

int main() {
  int (*fp)(int, int) = bigger;
  vector<decltype(bigger) *> fpvec = {fp, add, minus, multiply, divide};
  for (auto fpit : fpvec) {
    cout << (*fpit)(2, 1) << endl;
  }

  return 0;
}
