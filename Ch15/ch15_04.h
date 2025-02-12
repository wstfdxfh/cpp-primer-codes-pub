#ifndef CH15_04_H
#define CH15_04_H

#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}
  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }
  virtual ~Quote() = default;
  virtual void print_total(std::ostream &os, std::size_t n) const {
    double total = net_price(n);
    os << "ISBN: " << isbn() << " size: " << n << " total price: " << total
       << std::endl;
  }
  virtual void debug(std::ostream &os) const {
    os << "bookNo: " << bookNo << " price: " << price << std::endl;
  }

 private:
  std::string bookNo;

 protected:
  double price = 0.0;
};

// 用于保存折扣值和购买量的抽象基类
class Disc_quote : public Quote {
 public:
  Disc_quote() = default;
  Disc_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Quote(book, price), quantity(qty), discount(disc) {}
  void debug(std::ostream &os) const override {
    Quote::debug(os);
    os << "quantity: " << quantity << " discount: " << discount << std::endl;
  }
  // 纯虚函数，必须在派生类中实现
  double net_price(std::size_t) const = 0;

 protected:
  std::size_t quantity = 0;
  double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double price, std::size_t qty,
             double disc)
      : Disc_quote(book, price, qty, disc) {}
  double net_price(std::size_t) const override;
};

#endif  // CH15_04_H