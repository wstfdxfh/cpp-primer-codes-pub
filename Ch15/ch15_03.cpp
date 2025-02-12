#include "ch15_03.h"

#include <iostream>
#include <string>

double Bulk_quote::net_price(std::size_t cnt) const {
  if (cnt >= min_qty) {
    return cnt * (1 - discount) * price;
  } else {
    return cnt * price;
  }
}

void Bulk_quote::debug(std::ostream &os) const {
  os << "bookNo: " << isbn() << " price: " << price << " min_qty: " << min_qty
     << " discount: " << discount << std::endl;
}

int main() {
  Bulk_quote bulk("1234567890", 100, 10, 0.1);
  Quote *p = &bulk;
  p->debug(std::cout);
  bulk.debug(std::cout);
  Quote q = bulk;
  q.debug(std::cout);
  return 0;
}