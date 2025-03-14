#include "ch17_02.h"

#include <bitset>
#include <iostream>
#include <string>

using namespace std;
int main() {
  bitset<64> bitvec(~0UL);
  cout << "bitvec: " << bitvec << endl;

  string str("00110011");
  bitset<64> bitvec2(str);
  bitset<64> bitvec3(str, 5, 2);
  cout << "bitvec2: " << bitvec2 << endl;
  cout << "bitvec3: " << bitvec3 << endl;

  return 0;
}
