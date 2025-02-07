#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

void process(shared_ptr<int> ptr) { cout << "using *ptr " << *ptr << endl; }

int main() {
  shared_ptr<int> p1(new int());
  if (!p1.unique()) {
    p1.reset(new int(2048));
  }
  *p1 += 1024;

  shared_ptr<int> p2(new int(42));
  process(p2);
  int i = *p2;
  cout << i << endl;

  int *p = new int(128);
  // 合法，但是内存将被释放!
  process(shared_ptr<int>(p));
  // 未定义行为！
  //   int j = *p;
  //  一次调用中 打印 16934752
  //   cout << j << endl;

  return 0;
}