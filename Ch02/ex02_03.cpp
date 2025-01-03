// 引用和指针
#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
  // 引用
  int i, &ri = i;
  i = 5;
  ri = 10;
  // 10 10
  std::cout << i << " " << ri << std::endl;

  // 指针
  // 推荐的空指针初始化方法
  int* p1 = nullptr;
  // 不推荐的方法
  int* p2 = 0;
  int* p3 = NULL;

  i = 42;
  void* p = &i;
  // long *lp = &i

  // 这段程序的含义是 初始化int指针并将其位置指向i变量 之后再将p4指向位置的变量(i)自乘后复制到本来位置
  int* p4 = &i;
  std::cout << *p4 << std::endl;
  *p4 = *p4 * *p4;
  std::cout << *p4 << std::endl;

  // 指针的引用
  int *p5;
  int *&r = p5;
  r = &i;  // 等价于p5 = &i
  *r = 0;  //等价于p5 = nullptr

  return 0;
}