#include "ch16_01_2.h"

#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main() {
  Blob<int> ia;
  Blob<int> ia2 = {0, 1, 2};
  ia.push_back(0);
  ia.push_back(1);
  ia.push_back(2);

  for (size_t i = 0; i < ia2.size(); i++) {
    cout << ia2[i] << endl;
  }

  cout << ((ia == ia2) ? "eq" : "neq") << endl;

  return 0;
}