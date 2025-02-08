#ifndef CH1301H
#define CH1301H

#include <string>

class Point {
 public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}

  //  private:
  int x;
  int y;
};

class HasPtr {
 public:
  HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) {}
  //  拷贝构造函数
  HasPtr(const HasPtr &);
  // 析构函数
  ~HasPtr() { delete ps; };
  // 拷贝赋值运算符
  HasPtr &operator=(const HasPtr &);

  //  private:
  std::string *ps;
  int i;
};

class Employee {
  /**
   * @brief 每个对象都有不同的id
   *
   */
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
    // id = ++maxid;
    return *this;
  }
  const std::string &GetName() const { return name; }
  const int &GetID() const { return id; }
};

#endif
