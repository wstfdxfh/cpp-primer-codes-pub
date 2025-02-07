#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() {
  // 错误
  // char arr[0];
  // 正确
  char *cp = new char[0];
  delete[] cp;
  unique_ptr<int[]> up(new int[10]{1, 2});
  cout << up[1] << endl;
  up.release();

  shared_ptr<int> sp(new int[10]{11, 12}, [](int *p) { delete[] p; });
  cout << *(sp.get() + 1) << endl;

  sp.reset();

  //   cout << "Please Input the Length of sequence: ";
  //   size_t len;
  //   cin >> len;
  //   cp = new char[len + 1];
  //   cin.ignore();
  //   cin.get(cp, len + 1);
  //   cout << cp << endl;
  //   delete[] cp;

  // 分配空间和构造分离
  allocator<string> alloc;
  auto ap = alloc.allocate(10);
  auto start = ap;
  string s;
  while (cin >> s) {
    alloc.construct(ap++, s);
  }
  for (auto t = start; t != ap; ++t) {
    cout << *t << " ";
  }
  cout << endl;
  // 使用完对象后
  while (start != ap) {
    alloc.destroy(--ap);
  }
  alloc.deallocate(ap, 10);

  return 0;
}