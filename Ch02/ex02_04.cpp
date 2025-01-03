#include <iostream>
// 定义其他文件中也可以使用的const
extern const int bufSize = 512;

int main(int argc, char* argv[]) {
  // 对const的引用
  const int& r = bufSize;

  const double pi = 3.14;
  const int& rpi = pi;
  // 指向常量的指针 也可以指向变量
  const double* ptr = &pi;
  // const 指针 初始化后不能修改地址
  int errNumb = 0;
  int* const curErr = &errNumb;
  // 从右往左读
  const double* const pip = &pi;

  *curErr += 1;
  std::cout << *curErr << std::endl;

  const int ci = 42;
  // 一个底层const
  const int* p2 = &ci;
  // 底层const与顶层const
  const int* const p3 = p2;
  // 错误：底层const不能赋给一个非底层const
  // int *p = p3;
  // 正确
  p2 = p3;

  // 常量表达式 编译时即可确定值
  constexpr int mf = 20;
  constexpr int limit = mf + 1;

  return 0;
}


constexpr int i = 42;
int j = 0;
// i和j必须在函数体之外定义
constexpr const int* p = &i;
constexpr int* p1 = &j;