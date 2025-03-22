#include "ch19_04.h"

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;  // for _1, _2, _3...

int main() {
  // 成员变量指针
  auto pdata = Screen::data();
  Screen myScreen, *pMyScreen = &myScreen;
  auto s = myScreen.*pdata;     // 访问成员变量
  auto s2 = pMyScreen->*pdata;  // 访问成员变量

  // 成员函数指针pf
  char (Screen::*pf)(Screen::pos) const = &Screen::get;
  char (Screen::*pf2)() const = &Screen::get;
  using Action = char (Screen::*)(Screen::pos) const;
  Action get = &Screen::get;

  char c1 = (myScreen.*pf)(0);  // 访问成员函数
  std::cout << c1 << std::endl;
  char c2 = (pMyScreen->*pf2)();  // 访问成员函数
  std::cout << c2 << std::endl;
  char c3 = (myScreen.*get)(1);  // 访问成员函数
  std::cout << c3 << std::endl;

  // 将成员函数用作可调用对象
  auto fp = &std::string::empty;
  std::function<bool(const std::string&)> fcn = fp;
  std::vector<std::string> vec{"Hello", "World", "", "!"};
  auto it = std::find_if(vec.begin(), vec.end(), fcn);
  if (it != vec.end()) {
    std::cout << "Found empty string at " << it - vec.begin() << std::endl;
  }
  // 使用 std::mem_fn
  auto mem_fn = std::mem_fn(&std::string::empty);
  auto it2 = std::find_if(vec.begin(), vec.end(), mem_fn);
  if (it2 != vec.end()) {
    std::cout << "Found empty string at " << it2 - vec.begin() << std::endl;
  }
  // 使用 std::bind
  auto bind_fn = std::bind(&std::string::empty, _1);
  auto it3 = std::find_if(vec.begin(), vec.end(), bind_fn);
  if (it3 != vec.end()) {
    std::cout << "Found empty string at " << it3 - vec.begin() << std::endl;
  }

  return 0;
}
