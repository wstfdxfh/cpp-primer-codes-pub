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

int main(int argc, char const *argv[]) {
  // 检查输入中连续单词的个数
  string temp;
  string repeatWord;
  string maxRepeatWord;
  unsigned repeatCnt = 0;
  unsigned maxCnt = 0;

  // how now now now brown cow cow cow
  while (cin >> temp) {
    if (temp == repeatWord) {
      ++repeatCnt;
    } else {
      repeatCnt = 1;
      repeatWord = temp;
    }

    if (maxCnt <= repeatCnt) {
      maxCnt = repeatCnt;
      maxRepeatWord = repeatWord;
    }
  }

  if (maxCnt <= 1) {
    cout << "No Repeat Word!" << endl;
  } else {
    cout << "Word " << maxRepeatWord << " has repeated " << maxCnt << " times!"
         << endl;
  }

  // 检查一个vector是否是另一个的前缀
  vector<int> v1 = {1, 2, 3, 42};
  vector<int> v2 = {1, 2, 3, 42, 42, 5};
  bool isPrefix = true;
  for (vector<int>::size_type i = 0; i < v1.size(); i++) {
    if (v1[i] != v2[i]) {
      isPrefix = false;
    }
  }
  cout << "Is " << (isPrefix ? "" : "not ") << "prefix!" << endl;

  // 重复执行以下任务：输入2个string对象 挑选较短输出
  cin.clear();
  string rsp;
  do {
    cout << "Pls enter two str: ";
    string val1, val2;
    cin >> val1 >> val2;
    cout << (val1.size() > val2.size() ? val2 : val1) << endl;
    cout << "More? Enter y or n: ";
    cin >> rsp;
  } while (!rsp.empty() && rsp[0] != 'n');

  return 0;
}
