#include "ch19_04.h"

#include <iostream>

int main() {
  // 成员变量指针
  auto pdata = Screen::data();
  Screen myScreen, *pMyScreen = &myScreen;
  auto s = myScreen.*pdata;     // 访问成员变量
  auto s2 = pMyScreen->*pdata;  // 访问成员变量

  // 成员函数指针pf
  char (Screen::*pf)(Screen::pos) const = &Screen::get;

  return 0;
}
