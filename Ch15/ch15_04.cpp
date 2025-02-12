#include "ch15_04.h"

#include <string>

double Bulk_quote::net_price(std::size_t cnt) const {
  if (cnt >= quantity) {
    return cnt * (1 - discount) * price;
  } else {
    return cnt * price;
  }
}

int main() {
  // 相较于15_03，类的设计进行了重构，但是并没有影响main函数的运行和结果
  Bulk_quote bulk("1234567890", 100, 10, 0.1);
  Quote *p = &bulk;
  p->debug(std::cout);
  bulk.debug(std::cout);
  Quote q = bulk;
  q.debug(std::cout);
  return 0;
}