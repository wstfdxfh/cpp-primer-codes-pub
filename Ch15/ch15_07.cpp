#include "ch15_07.h"

#include <iostream>
#include <string>

double Bulk_quote::net_price(std::size_t cnt) const {
  if (cnt >= quantity) {
    return cnt * (1 - discount) * price;
  } else {
    return cnt * price;
  }
}

int main() {
  Bulk_quote bq("123", 10, 5, 0.1);
  Quote q(bq), *p = &bq;
  q = bq;
  q.debug(std::cout);
  p->debug(std::cout);

  Derived d(1, 2, 3), d2, d3(1);
  // x,y,z都被显式初始化
  d.debug(std::cout);
  // x,y,z 都被默认初始化
  d2.debug(std::cout);
  // x,y 被显式初始化，z 被默认初始化
  d3.debug(std::cout);

  return 0;
}