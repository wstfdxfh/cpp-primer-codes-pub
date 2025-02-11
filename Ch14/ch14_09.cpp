#include <iostream>
#include <stdexcept>

class SmallInt {
 public:
  SmallInt(int i = 0) {
    if (i < 0 || i > 255) {
      throw std::out_of_range("Value out of range");
    }
    val = i;
  }

  explicit operator int() const { return val; }

  //  private:
  unsigned val;
};

int main() {
  SmallInt si;
  // 4被隐式转换成了SmallInt对象
  si = 4;
  // 由于类型转换函数是explicit的，所以不能进行隐式转换
  //   si + 3;
  static_cast<int>(si) + 3;
  std::cout << si.val << std::endl;
  return 0;
}
