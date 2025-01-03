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

int main(int argc, char* argv[]) {
  // 初始化方法：可以使用方括号进行初始元素值初始化，而不能使用圆括号
  vector<string> v1{"a", "an", "the"};
  vector<string> v2(10, "Hi");

  // 下标返回引用类型
  v2[0] = "World";

  cout << v2[0] << endl;
  vector<string> strs;
  string temp;
  while (cin >> temp) {
    strs.push_back(temp);
  }
  for (auto s : strs) {
    for (auto& ch : s) {
      ch = toupper(ch);
    }
    cout << s;
  }
  cout << endl;

  cin.clear();

  vector<int> ivec;
  int itemp;
  while (cin >> itemp) {
    ivec.push_back(itemp);
    cout << itemp;
  }
  cout << endl;

  getchar();
  return 0;
}