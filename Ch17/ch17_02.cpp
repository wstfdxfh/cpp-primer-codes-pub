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
  cout << "bitvec3: " << bitvec3 << '\n' << bitvec3.count() << endl;
  bitvec3.set();
  cout << "bitvec3 after set: " << bitvec3 << endl;

  bool status;
  unsigned long quizA = 0;
  quizA |= 1UL << 27;
  // Check if the quizA has the 27th bit set
  status = quizA & (1UL << 27);
  cout << "quizA status: " << status << endl;
  quizA &= ~(1UL << 27);
  // 使用标准库bitset完成相同的工作
  bitset<30> quizB;
  quizB.set(27);
  status = quizB[27];
  quizB.reset(27);
  cout << "quizB status: " << status << endl;
  return 0;
}
