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

// const_cast 用于重载函数实现
const string &shortenString(const string &s1, const string &s2) {
  return s1.size() <= s2.size() ? s1 : s2;
}
string &shortenString(string &s1, string &s2) {
  auto &r = shortenString(const_cast<const string &>(s1),
                          const_cast<const string &>(s2));
  return const_cast<string &>(r);
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
