#include "ch19_02.h"

#include <iostream>
class Base;
bool operator==(const Base& lhs, const Base& rhs);

class Base {
  friend bool operator==(const Base& lhs, const Base& rhs);

 public:
  virtual void print_id() const {
    std::cout << "Id = " << base_id << std::endl;
  }

 protected:
  virtual bool equal(const Base& other) const {
    return base_id == other.base_id;
  }

 private:
  int base_id = 21;
};

class Derived : public Base {
 public:
  void print_id() const { std::cout << "Id = " << derived_id << std::endl; }

 protected:
  bool equal(const Base& other) const override {
    auto r = dynamic_cast<const Derived&>(other);
    return Base::equal(r) && r.derived_id == derived_id;
  }

 private:
  int derived_id = 42;
};

bool operator==(const Base& lhs, const Base& rhs) {
  return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

int main() {
  Derived d;
  Base b;
  Base* bp = &d;
  Base& br = d;
  //   bp->print_id();

  // 指针的dynamic_cast
  if (Derived* dp = dynamic_cast<Derived*>(bp)) {
    dp->print_id();
  } else {
    bp->print_id();
  }
  try {
    Derived& dr = dynamic_cast<Derived&>(br);
    dr.print_id();
  } catch (const std::exception& e) {
    std::cerr << e.what() << '\n';
  }

  if (typeid(*bp) == typeid(Derived)) {
    std::cout << "Same Type!" << std::endl;
  }
  if (typeid(*dynamic_cast<Derived*>(bp)) == typeid(Derived)) {
    std::cout << "Same Type!" << std::endl;
  }

  if (*bp == d) {
    std::cout << "Same Object!" << std::endl;
  } else {
    std::cout << "Not Same Object!" << std::endl;
  }

  return 0;
}
