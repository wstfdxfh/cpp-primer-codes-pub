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
using std::isupper;
using std::string;
using std::toupper;
using std::vector;

int main(int argc, char const *argv[]) {
  // 出现两次重复的单词输入时打印重复的单词，且必须是大写单词
  // hello Hello Hello
  string last, temp;
  bool hasRepeat = false;
  while (cin >> temp && !temp.empty()) {
    if (last != temp) {
      last = temp;
    } else {
      if (!isupper(temp[0])) {
        continue;
      }
      hasRepeat = true;
      break;
    }
  }
  if (hasRepeat) {
    cout << "Repeat word: " << temp << endl;
  } else {
    cout << "No Repeat!" << endl;
  }
  cin.clear();

  return 0;
}
