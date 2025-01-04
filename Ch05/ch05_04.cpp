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

  return 0;
}
