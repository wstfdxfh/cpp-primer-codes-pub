#include <cctype>
#include <iostream>
#include <string>
#include <vector>

class Person {
  // 友元函数
  friend std::istream& read(std::istream& is, Person& person);
  friend std::ostream& print(std::ostream& os, Person const& person);

 public:
  // 默认构造函数
  Person() = default;
  Person(const std::string& name, const std::string& address)
      : name(name), address(address) {}
  Person(std::istream is) { read(is, *this); }

  const std::string& getName() { return name; }
  const std::string& getAddress() { return address; }

 private:
  // 默认初始化
  std::string name = "";
  std::string address = "";
};

/* 输入和输出函数不在Person类内声明和定义 */
// ZhangSan RenMinGuangChang
std::istream& read(std::istream& is, Person& person) {
  is >> person.name >> person.address;
  return is;
}
std::ostream& print(std::ostream& os, Person const& person) {
  os << "Name: " << person.name << ", Address: " << person.address;
  return os;
}

int main() {
  Person person("ZhangSan", "RenMinGuangChang");

  // read(std::cin, person);
  print(std::cout, person);

  return 0;
}
