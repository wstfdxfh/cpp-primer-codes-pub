#include <vector>
#include <iostream>
#include <cstring>
#include <string>
using std::vector;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::string;

// #define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)


int main(int argc, char* argv[]) {
  int arr[10];
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  int arr_copy[10];
  for (int i = 0; i < 10; i++) {
    arr_copy[i] = arr[i];
  }

  vector<int> vec;
  vector<int> vec_copy;
  for (int i = 0; i < 10; i++) {
    vec.push_back(i);
  }
  vec_copy = vec;
  for (auto num : vec_copy) {
    cout << num << endl;
  }

  int *beg = arr_copy, *e = &arr_copy[10];
  // 等价于以下的写法
  // beg = begin(arr_copy);
  // e = end(arr_copy);
  for (int* p = beg; p != e; ++p) {
    cout << *p << endl;
  }

  char cstr[] = "Hello, World!";
  char cstr2[] = "Hello, World!";
  // 如果相等返回0
  cout << strcmp(cstr, cstr2) << endl;
  char largeStr[100];

  // 容易引发错误 不推荐使用
  strcpy(largeStr, cstr);
  strcat(largeStr, " ");
  strcat(largeStr, cstr2);

  string longStr(largeStr);
  cout << longStr << endl;
  cout << longStr.size() << endl;

  // 如果longStr被改变，str可能会失效
  const char* str = longStr.c_str();

  // 使用数组初始化vector
  vector<int> ivec(begin(arr), end(arr));
  

  return 0;
}