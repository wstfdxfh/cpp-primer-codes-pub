#include <iostream>
#include <string>

class Employee {
  /**
   * @brief 每个对象都有不同的id
   *
   */
  friend std::ostream &operator<<(std::ostream &os, const Employee &emp);
  friend std::istream &operator>>(std::istream &is, Employee &emp);

 private:
  std::string name;
  int id;
  static int maxid;

 public:
  // 重新定义默认构造、拷贝构造以及拷贝控制成员
  Employee() : id(++maxid) {}
  Employee(const std::string &s) : name(s), id(++maxid) {}
  Employee(const Employee &emp) : name(emp.name), id(++maxid) {}
  Employee &operator=(const Employee &emp) {
    name = emp.name;
    return *this;
  }
  const std::string &GetName() const { return name; }
  const int &GetID() const { return id; }
};

int Employee::maxid = 0;

// 通常不应该打印换行符等格式控制符
std::ostream &operator<<(std::ostream &os, const Employee &emp) {
  os << emp.name << " " << emp.id;
  return os;
}

std::istream &operator>>(std::istream &is, Employee &emp) {
  std::string name;
  is >> name;
  // 检查输入是否成功
  if (!is) {
    emp = Employee();
  } else {
    emp.name = name;
    emp.id = ++emp.maxid;
  }
  return is;
}

int main() {
  Employee emp;
  std::cin >> emp;
  std::cout << emp << std::endl;
  return 0;
}
