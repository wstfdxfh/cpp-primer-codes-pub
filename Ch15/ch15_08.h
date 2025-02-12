#ifndef CH15_08_H
#define CH15_08_H

#include <iostream>
#include <memory>
#include <set>
#include <string>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price)
      : bookNo(book), price(sales_price) {}
  std::string isbn() const { return bookNo; }
  virtual double net_price(std::size_t n) const { return n * price; }
  virtual ~Quote() = default;

  virtual Quote *clone() const & { return new Quote(*this); }
  virtual Quote *clone() && { return new Quote(std::move(*this)); }

  virtual double print_total(std::ostream &os, std::size_t n) const {
    double total = net_price(n);
    os << "ISBN: " << isbn() << " size: " << n << " total price: " << total
       << std::endl;
    return total;
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

  Bulk_quote *clone() const & override { return new Bulk_quote(*this); }
  Bulk_quote *clone() && override { return new Bulk_quote(std::move(*this)); }
};

class Basket {
 public:
  void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
  void add_item(const Quote &sale) {
    std::cout << "diao yong le const yingyong" << std::endl;
    items.emplace(sale.clone());
  }
  void add_item(Quote &&sale) { items.emplace(std::move(sale).clone()); }
  double total_receipt(std::ostream &) const;

 private:
  static bool compare(const std::shared_ptr<Quote> &lhs,
                      const std::shared_ptr<Quote> &rhs) {
    return lhs->isbn() < rhs->isbn();
  }
  // 存放交易信息 并且所有书号相同的交易信息都存放在一起
  std::multiset<std::shared_ptr<Quote>, decltype(compare) *> items{compare};
};
#endif  // CH15_08_H