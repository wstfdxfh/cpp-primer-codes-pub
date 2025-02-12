#ifndef CH15_07_H
#define CH15_07_H

#include <iostream>
#include <string>

class Quote {
 public:
  Quote() = default;                          // 默认构造函数
  Quote(const Quote &) = default;             // 拷贝构造函数
  Quote(Quote &&) = default;                  // 移动构造函数
  Quote &operator=(const Quote &) = default;  // 拷贝赋值运算符
  Quote &operator=(Quote &&) = default;       // 移动赋值运算符
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}  // 初始化列表

  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }
  virtual void print_total(std::ostream &os, std::size_t n) const {
    double total = net_price(n);
    os << "ISBN: " << isbn() << " size: " << n << " total price: " << total
       << std::endl;
  }
  virtual void debug(std::ostream &os) const {
    os << "bookNo: " << bookNo << " price: " << price << std::endl;
  }
  virtual ~Quote() = default;

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
  Disc_quote(const Disc_quote &disc_quote)
      : Quote(disc_quote),
        quantity(disc_quote.quantity),
        discount(disc_quote.discount) {}  // 拷贝构造函数 和合成版本相同
  Disc_quote &operator=(const Disc_quote &rhs) {
    Quote::operator=(rhs);
    quantity = rhs.quantity;
    discount = rhs.discount;
    return *this;
  }  // 拷贝赋值运算符 和合成版本相同

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
  //   Bulk_quote() = default;
  //   Bulk_quote(const std::string &book, double price, std::size_t qty,
  //              double disc)
  //       : Disc_quote(book, price, qty, disc) {}
  //   Bulk_quote(const Bulk_quote &bulk_quote)
  //       : Disc_quote(bulk_quote) {}  // 拷贝构造函数 和合成版本相同

  // 继承构造函数 不会改变基类成员的访问级别
  using Disc_quote::Disc_quote;
  Bulk_quote &operator=(const Bulk_quote &rhs) {
    Disc_quote::operator=(rhs);
    return *this;
  }  // 拷贝赋值运算符 和合成版本相同
  double net_price(std::size_t) const override;
};

class Base {
 public:
  Base() = default;
  Base(const Base &) = default;
  Base(int i, int j = 10) : x(i), y(j) {}

  virtual void debug(std::ostream &os) const {
    os << "x: " << x << " y: " << y << std::endl;
  }

 private:
  int x, y;
};

class Derived : public Base {
 public:
  using Base::Base;
  Derived(const Derived &) = default;
  Derived(int i, int j, int k) : Base(i, j), z(k) {}

  void debug(std::ostream &os) const override {
    Base::debug(os);
    os << "z: " << z << std::endl;
  }

 private:
  int z;
};
#endif  // CH15_07_H