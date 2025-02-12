#include "ch15_02.h"

#include <string>

double Bulk_quote::net_price(std::size_t cnt) const {
  if (cnt >= min_qty) {
    return cnt * (1 - discount) * price;
  } else {
    return cnt * price;
  }
}

int main() {
  Bulk_quote bulk("1234567890", 100, 10, 0.1);
  Quote *p = &bulk;
  // 全部使用了继承类的价格计算方式
  p->print_total(std::cout, 10);
  bulk.print_total(std::cout, 10);
  // 进行值初始化时，只能保留基类的成员
  Quote q = bulk;
  // 使用基类成员的价格计算方式
  q.print_total(std::cout, 10);

  return 0;
}