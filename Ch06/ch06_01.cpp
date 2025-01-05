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

#include "ch06.h"

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i != 10; i++) {
    cout << count_calls() << endl;
  }
  return 0;
}
