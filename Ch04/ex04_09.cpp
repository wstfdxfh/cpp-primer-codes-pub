#include <string>
#include <iostream>
#include <cctype>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::getline;
using std::ispunct;
using std::toupper;
using std::vector;

int main(int argc, char* argv[]) {
  double i = 42, &ri = i, *pi = &i;
  cout << sizeof(double) << sizeof i << sizeof ri << sizeof pi << endl;
  int ai[4] = {};
  cout << sizeof ai << endl;
  vector<int> vi;
  cout << sizeof vi << endl;
  string s;
  cout << sizeof s << endl;

  constexpr size_t sz = sizeof(ai) / sizeof(*ai);
  cout << sz << endl;

  return 0;
}