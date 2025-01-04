#include <string>
#include <iostream>
#include <cctype>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::getline;
using std::ispunct;
using std::toupper;

int main(int argc, char* argv[]) {
  string s("Hello, World!!!");
  decltype(s.size()) punct_cnt = 0;
  for (auto& c : s) {
    if (ispunct(c)) {
      ++punct_cnt;
    }
    c = toupper(c);
  }
  cout << punct_cnt << " punctuation characters in " << s << endl;

  string str;
  string longstr;
  // while (cin >> str) {
  //   cout << str << endl;
  //   if (!str.empty())
  //     longstr += (str + " ");
  // }
  // while (getline(cin, str)) {
  //   cout << str << endl;
  // }
  // cout << longstr << endl;

  // getchar();
  return 0;
}