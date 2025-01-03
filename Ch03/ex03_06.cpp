#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
  // 将所有值初始化为0
  int arr[3][4] = {0};
  // 部分值显式初始化，其余默认初始化
  int ia[3][4] = {{0}, {4}, {8}};
  cout << ia[0][0] << ia[1][1] << endl;
  // 对长度为4的数组的引用
  int (&row)[4] = ia[1];
  // 访问多维数组元素
  constexpr size_t row_cnt = 3, col_cnt = 4;
  for (size_t i = 0; i != row_cnt; ++i) {
    for (size_t j = 0; j != col_cnt; ++j) {
      ia[i][j] = i * col_cnt + j;
    }
  }
  // c++11方法
  size_t cnt = 0;
  // 即使是只读操作，也要声明为&row，防止自动转换成int*形式
  for (auto& row : ia) {
    for (auto& col : row) {
      col = cnt;
      ++cnt;
    }
  }
  // 使用指针遍历多维数组
  // 指向第一个内层数组的指针
  int (*p)[4] = ia;
  // 简易方法
  for (auto p = begin(ia); p != end(ia); ++p) {
    for (auto q = begin(*p); q != end(*p); ++q) {
      cout << *q << " ";
    }
  }
  cout << endl;
  // 也可以使用下面的方法简化
  using int_array = int[4];
  for (int_array* p = ia; p != ia + 3; ++p) {
    for (int* q = *p; q != *p + 4; ++q) {
      cout << *q << " ";
    }
  }

  return 0;
}