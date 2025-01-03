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
  bool flag;
  char cval;
  short sval;
  unsigned short usval;
  int ival;
  unsigned int uival;
  long lval;
  unsigned long ulval;
  float fval;
  double dval;
  3.14159L +
      'a';       //  'a' promoted to int, then that int converted to long double
  dval + ival;   //  ival converted to double
  dval + fval;   //  fval converted to double
  ival = dval;   //  dval converted (by truncation) to int
  flag = dval;   //  if dval is 0, then flag is false, otherwise true
  cval + fval;   //  cval promoted to int, then that int converted to float
  sval + cval;   //  sval and cval promoted to int
  cval + lval;   //  cval converted to long
  ival + ulval;  //  ival converted to unsigned long
  usval + ival;  //  promotion depends on the size of unsigned short and int
  uival + lval;  //  conversion depends on the size of unsigned int and long

  int i = 1, j = 2;
  int const &ri = i;  // const 指针或者引用可以指向或者引用非常量
  void *p = &i;       // 任何非常量对象的地址都可以存放在void*指针中
  // p = ri;             // 错误，不能将const int&转换为void*
  cout << ri << endl;
  // 强制类型转换
  double slope = static_cast<double>(i) / j;
  cout << slope << endl;
  double *dp = static_cast<double *>(p);
  // const类型转换

  return 0;
}
