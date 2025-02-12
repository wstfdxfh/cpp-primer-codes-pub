#include "ch15_08.h"

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

double Bulk_quote::net_price(std::size_t cnt) const {
  if (cnt >= quantity) {
    return cnt * (1 - discount) * price;
  } else {
    return cnt * price;
  }
}

double Basket::total_receipt(ostream &os) const {
  double sum = 0.0;
  for (auto it = items.cbegin(); it != items.cend();
       it = items.upper_bound(*it)) {
    sum += (**it).print_total(cout, items.count(*it));
  }
  os << "Total Sale: " << sum << endl;
  return sum;
}

int main() {
  vector<shared_ptr<Quote>> basket;
  basket.push_back(make_shared<Bulk_quote>("1234567890", 100, 10, 0.1));
  cout << basket.back()->net_price(10) << endl;

  Quote q("1234567890", 100);
  Bulk_quote bq("1234567890", 100, 10, 0.1);
  q.debug(cout);
  bq.debug(cout);

  Basket baskit;
  baskit.add_item(q);
  for (size_t i = 0; i < 10; ++i) {
    baskit.add_item(bq);
  }
  // 由于q和bq的isbn号相同，在进行统计时，
  // 会被全部同时进行价格的计算，而且使用的是Quote类型的统计方法
  baskit.total_receipt(cout);
  return 0;
}