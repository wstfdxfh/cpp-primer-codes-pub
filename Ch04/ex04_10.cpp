#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::ispunct;
using std::string;
using std::toupper;
using std::vector;

int main() {
  vector<int> ivec(10, 1);
  vector<int>::size_type cnt = ivec.size();
  // 逗号运算符从左向右求值
  for (vector<int>::size_type i = 0; i != ivec.size(); ++i, --cnt) {
    ivec[i] = cnt;
  }
  for (auto it = ivec.begin(); it != ivec.end(); ++it) {
    cout << *it << " ";
  }
  // 使用后置运算符的方法
  cnt = ivec.size();
  cout << endl;

  for (vector<int>::size_type i = 0; i != ivec.size(); i++, cnt--) {
    ivec[i] = cnt;
  }
  for (auto it = ivec.begin(); it != ivec.end(); ++it) {
    cout << *it << " ";
  }
}