#include "Sales_item.h"

typedef double wages;
// p 即 double*
typedef wages base;
using SI = Sales_item;

typedef char* pstring;
// 指向char的常量指针
const pstring cstr = 0;

// auto会进行类型的调整
int i = 0, &r = i;
auto a = r;
const int ci = i, &cr = ci;
// 顶层const一般会忽略 底层会保留
auto e = &ci;
// 可以为常量引用绑定字面值
const auto& j = 42;

int main(int argc, char* argv[]) {
  const int i = 42;
  auto j = i;
  const auto& k = i;
  auto* p = &i;
  const auto j2 = i;
  const auto& k2 = i;

  return 0;
}