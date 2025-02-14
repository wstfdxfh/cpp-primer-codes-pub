#ifndef CH16_05_H
#define CH16_05_H

#include <iostream>
#include <string>
struct Sales_data {
  friend class std::hash<Sales_data>;
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

namespace std {
template <>
struct hash<Sales_data> {
  friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
  using result_type = size_t;
  using argument_type = Sales_data;
  size_t operator()(const Sales_data& s) const {
    return hash<string>()(s.bookNo) ^ hash<unsigned>()(s.units_sold) ^
           hash<double>()(s.revenue);
  }
};
bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
  return lhs.bookNo == rhs.bookNo && lhs.units_sold == rhs.units_sold &&
         lhs.revenue == rhs.revenue;
}

}  // namespace std

#endif  // CH16_05_H