#ifndef CH15_02_H
#define CH15_02_H

#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}
  std::string isbn() const { return bookNo; }
  // 返回给定数量的书的销售总额
  // 派生类负责改写并使用不同的折扣计算算法
  virtual double net_price(std::size_t n) const { return n * price; }
  virtual ~Quote() = default;  // 对析构函数进行动态绑定
  // 打印总价
  virtual void print_total(std::ostream &os, std::size_t n) const {
    double total = net_price(n);
    os << "ISBN: " << isbn() << " size: " << n << " total price: " << total
       << std::endl;
  }

 private:
  std::string bookNo;  // 书籍编号

 protected:
  double price = 0.0;  // 代表普通状态下不打折的价格
};

class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Quote(book, p), min_qty(qty), discount(disc) {}
  double net_price(std::size_t) const override;

 private:
  std::size_t min_qty = 0;  // 最小购买量
  double discount = 0.0;    // 折扣
};

#endif  // CH15_02_H