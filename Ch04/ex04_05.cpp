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
  vector<int> v = {1, 2, 3, 4, -1};
  auto pbeg = v.begin();
  // 输出元素 直到遇到第一个负数
  while (pbeg != v.end() && *pbeg >= 0) {
    cout << *pbeg++ << endl;
  }

  return 0;
}