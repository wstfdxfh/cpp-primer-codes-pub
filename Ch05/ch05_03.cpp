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
  const string s("Hello World!!! flcl ffcl ffff ffii");
  unsigned vowelCnt = 0;
  unsigned otherCnt = 0;
  unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
  bool fPresent = false;
  unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;

  for (auto ch : s) {
    switch (ch) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        ++vowelCnt;
        break;
      default:
        ++otherCnt;
        break;
    }

    switch (ch) {
      case 'f':
        if (fPresent) {
          ++ffCnt;
        } else {
          fPresent = true;
        }
        break;
      case 'l':
        if (fPresent) {
          ++flCnt;
        }
        fPresent = false;
        break;
      case 'a':
      case 'A':
        ++aCnt;
        fPresent = false;
        break;
      case 'e':
      case 'E':
        ++eCnt;
        fPresent = false;
        break;
      case 'i':
      case 'I':
        ++iCnt;
        if (fPresent) {
          ++fiCnt;
        }
        fPresent = false;
        break;
      case 'o':
      case 'O':
        ++oCnt;
        fPresent = false;
        break;
      case 'u':
      case 'U':
        ++uCnt;
        fPresent = false;
        break;
      default:
        fPresent = false;
        break;
    }
  }

  cout << "Number of vowels: " << vowelCnt << endl;
  cout << "Number of other characters: " << otherCnt << endl;
  cout << "a/A: " << aCnt << " e/E: " << eCnt << " i/I:  " << iCnt
       << " o/O: " << oCnt << " u/U: " << uCnt << endl;
  cout << "ff: " << ffCnt << " fl: " << flCnt << " fi: " << fiCnt << endl;

  return 0;
}
