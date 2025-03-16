#include <iostream>
using namespace std;

// C++中，应该使用未命名的命名空间替代静态声明
namespace {
int i = 0;
}

namespace cpp_primer {
inline namespace fifthEd {
void printHello() {
  cout << "This is 5th edition!" << '\n' << "i = " << ++i << endl;
}
}  // namespace fifthEd
namespace fourthEd {
void printHello() {
  cout << "This is 4th edition" << '\n' << "i = " << ++i << endl;
}
}  // namespace fourthEd
}  // namespace cpp_primer

int main() {
  cpp_primer::printHello();
  cpp_primer::fourthEd::printHello();
  cpp_primer::fifthEd::printHello();

  namespace fed = cpp_primer::fourthEd;
  fed::printHello();

  return 0;
}