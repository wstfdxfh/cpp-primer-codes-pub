#ifndef CH15_03_H
#define CH15_03_H

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

class Bulk_quote : public Quote {
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string &book, double p, std::size_t qty, double disc)
      : Quote(book, p), min_qty(qty), discount(disc) {}
  double net_price(std::size_t) const override;
  void debug(std::ostream &os) const override;

 private:
  std::size_t min_qty = 0;
  double discount = 0.0;
};

#endif  // CH15_03_H