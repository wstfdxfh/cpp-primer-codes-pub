
#include <iostream>
#include <string>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

string::size_type find_char(const string &s, char c,
                            string::size_type &occurs) {
  auto ret = s.size();
  occurs = 0;
  for (size_t i = 0; i != s.size(); i++) {
    if (s[i] == c) {
      if (ret == s.size()) {
        ret = i;
      }
      ++occurs;
    }
  }
  return ret;
}

int main(int argc, char const *argv[]) {
  int a = 25, b = 24;
  swap(&a, &b);
  cout << a << " " << b << endl;

  string s = "Hello, World!";
  string::size_type occurs = 0;
  auto ret = find_char(s, 'o', occurs);
  cout << ret << " " << occurs << endl;

  return 0;
}
