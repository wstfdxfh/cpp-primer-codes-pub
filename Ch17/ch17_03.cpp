#include "ch17_03.h"

#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;
int main() {
  string pattern("[^c]ei");
  pattern = "[[:alpha:]]*" + pattern + "[[:alpha:]]*";
  regex r(pattern);
  smatch results;
  string test_str = "receipt freind theif receive";
  for (sregex_iterator it(test_str.begin(), test_str.end(), r), end_it;
       it != end_it; ++it) {
    cout << it->str() << endl;
  }

  // TODO 17.3.3节 17.3.4节

  return 0;
}
