
// 在cassert之前define NDEBUG可以阻止断言的产生
// #define NDEBUG

#include <cassert>
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

// 如果ctr>1，返回word的复数形式
string make_plural(size_t ctr, const string &word, const string &ending = "s") {
  return (ctr > 1) ? word + ending : word;
}

// 内联函数
inline bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

void vecPrint(const vector<int> &vec, vector<int>::iterator &it) {
#ifndef NDEBUG
  cerr << vec.size() << endl;
#endif
  if (it == vec.end()) {
    return;
  } else {
    cout << *it << " ";
    vecPrint(vec, ++it);
  }
}

int main(int argc, char const *argv[]) {
  cout << make_plural(1, "success", "es") << " "
       << make_plural(2, "success", "es") << " " << make_plural(1, "failure")
       << " " << make_plural(2, "failure") << endl;

  cout << isShorter("Hello", "World!!!") << endl;

  vector<int> vecInt = {1, 2, 3, 4, 5};
  auto it = vecInt.begin();
  vecPrint(vecInt, it);

  // 预处理宏
  assert(isShorter("Hello     ", "World!!!"));

#ifndef NDEBUG
  cerr << __func__ << endl;
  cerr << __TIME__ << endl;
#endif

  return 0;
}
