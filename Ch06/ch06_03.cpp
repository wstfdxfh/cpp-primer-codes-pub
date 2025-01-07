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

// 返回数组的引用，并且包含10个string
string (&func(string (&arr)[10]))[10] { return arr; }

// 类型别名
using arrS = string[10];
arrS &func2(arrS &arr);

// 尾置返回类型
auto func3(arrS &arr) -> string (&)[10];

// decltype
string strarr[10] = {"Hello", ", World", "!!!"};
decltype(strarr) &func4(arrS &arr);

// 返回数组引用

int odd[] = {1, 3, 5, 7, 9};
int even[] = {2, 4, 6, 8, 10};

using arrI = int[5];
arrI &arrRef(int i) { return (i % 2) ? odd : even; }

int main(int argc, char const *argv[]) {
  cout << func(strarr)[0] << endl;
  cout << arrRef(42)[0] << endl;
  return 0;
}
