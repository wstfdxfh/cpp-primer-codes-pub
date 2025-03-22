#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

// 嵌套类
class Outer {
 public:
  class Inner {
    static int maxId;

   public:
    std::string subName;
    void printMaxID() const { std::cout << "maxId: " << maxId << std::endl; }
    Inner();
  };

 private:
  std::string name;
};

int Outer::Inner::maxId = 0;
Outer::Inner::Inner() : subName() { ++maxId; }

int main() {
  Outer::Inner inner;
  inner.printMaxID();

  return 0;
}
