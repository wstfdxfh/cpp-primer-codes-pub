#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#include "ch13_01.h"

HasPtr::HasPtr(const HasPtr& hasPtr)
    : ps(new string(*hasPtr.ps)), i(hasPtr.i) {}

HasPtr& HasPtr::operator=(const HasPtr& hasPtr) {
  ps = new string(*hasPtr.ps);
  i = hasPtr.i;
  return *this;
}

int Employee::maxid = 0;

int main() {
  Point point1(0, 1);
  // 拷贝构造函数使用场景
  Point point2(point1);
  Point point3 = point1;
  point1.x = 100;
  vector<Point> vp = {point1, point2, point3};
  vp.push_back(point1);

  HasPtr ptr("Example");
  HasPtr ptr2 = ptr;
  ptr.ps->append("Haha");
  cout << *(ptr2.ps) << endl;
  string s("Senpai");
  Employee epe1, epe2("Sec"), epe3, epe4("man"), epe5(s);
  Employee emp = epe2;
  s = "Jason";
  cout << epe4.GetID() << " " << epe4.GetName() << endl;
  cout << epe5.GetID() << " " << epe5.GetName() << endl;
  cout << emp.GetID() << " " << emp.GetName() << endl;
  return 0;
}