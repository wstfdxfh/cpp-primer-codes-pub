#include <vector>
#include <string>
#include <iostream>
#include <cctype>

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::toupper;
using std::isspace;

int main(int argc, char* argv[]) {
  string str;
  auto beg = str.begin(), end = str.end();
  if (beg == end) {
    cout << "strΪ���ַ�����" << endl;
  }

  str = "Hello, World!";
  for (auto ch = str.begin(); ch != str.end() && !isspace(*ch); ++ch) {
    *ch = toupper(*ch);
  }
  cout << str << endl;

  vector<unsigned> scores(11, 0);
  unsigned grade;
  auto beg_iter = scores.begin();
  while (cin >> grade) {
    unsigned pos = grade / 10;
    auto temp_iter = beg_iter + pos;
    ++(*temp_iter);
  }
  for (auto num : scores) {
    cout << num << " ";
  }

  getchar();
  return 0;
}