#include <iostream>
#include <string>

class Person {
  // 友元函数
  friend std::istream& read(std::istream& is, Person& person);
  friend std::ostream& print(std::ostream& os, Person const& person);

 public:
  // 默认构造函数
  Person() = default;
  Person(const std::string& name, const std::string& address)
      : name(name), address(address) {}
  // 委托构造函数 通过explicit阻止隐式转换
  explicit Person(const std::string& name) : Person(name, "RenMinGuangChang") {}

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
  os << "Name: " << person.name << ", Address: " << person.address << std::endl;
  return os;
}

// constexpr类
class Debug {
 public:
  constexpr Debug(bool b = true) : hw(b), io(b), other(b) {}
  constexpr Debug(bool h, bool i, bool o) : hw(h), io(i), other(o) {}
  // 原书中没有 但是不加上const会导致编译错误
  constexpr bool any() const { return hw || io || other; }
  void set_hw(bool b) { hw = b; }
  void set_io(bool b) { io = b; }
  void set_other(bool b) { other = b; }

 private:
  bool hw;
  bool io;
  bool other;
};

int main() {
  Person person("ZhangSan", "RenMinGuangChang");
  Person person2("LiSi");

  // read(std::cin, person);
  print(std::cout, person);
  print(std::cout, person2);

  constexpr Debug io_sub(false, true, false);
  if (io_sub.any()) {
    std::cerr << "Error messages" << std::endl;
  }

  return 0;
}
