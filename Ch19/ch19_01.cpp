#include "ch19_01.h"

#include <cstdlib>
#include <iostream>
// new 的步骤：
// 1.使用operator new分配空间
// 2.进行对象构造
// 3.返回构造对象指针

void* operator new(size_t size) {
  if (void* mem = malloc(size)) {
    return mem;
  } else {
    throw std::bad_alloc();
  }
}
// delete 的步骤：
// 1.执行析构函数
// 2.使用operator delete释放空间
void operator delete(void* mem) noexcept { free(mem); }

struct Point {
  double x, y;
};

int main() {
  void* p = malloc(4);
  new (p) int(42);
  std::cout << "*p = " << *(static_cast<int*>(p)) << std::endl;
  // 释放内存时，先调用析构函数，再释放内存
  free(p);

  void* p2 = malloc(sizeof(Point));
  new (p2) Point{1.0, 2.0};
  std::cout << "p2 = " << (static_cast<Point*>(p2))->x << ", "
            << (static_cast<Point*>(p2))->y << std::endl;
  // 释放内存时，先调用析构函数，再释放内存
  static_cast<Point*>(p2)->~Point();  // 显式调用析构函数
  free(p2);

  return 0;
}
