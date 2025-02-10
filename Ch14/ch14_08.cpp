#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct absInt {
  // 重载函数调用运算符
  int operator()(int val) const { return val < 0 ? -val : val; }
};

class PrintString {
 public:
  PrintString(std::ostream &o = std::cout, char c = ' ') : os(o), sep(c) {}
  void operator()(const std::string &s) const { os << s << sep; }

 private:
  std::ostream &os;
  char sep;
};

int main() {
  int i = -42;
  absInt absObj;
  // 获取绝对值
  std::cout << absObj(i) << std::endl;
  PrintString errors(std::cerr, '\n');
  errors("DingDongJi");
  errors("DaGouJiao");

  std::vector<std::string> vs{"DingDongJi", "DaGouJiao", "DaiShuJi",
                              "JianGangMa"};
  std::for_each(vs.begin(), vs.end(), errors);

  std::sort(vs.begin(), vs.end(), std::greater<std::string>());
  std::for_each(vs.begin(), vs.end(),
                [](const std::string &s) { std::cout << s << " "; });
  std::function<void(const std::string &)> f = PrintString(std::cout, '\t');
  std::cout << std::endl;
  f("NanChangJi");
  f("BaiZhanJi");
  return 0;
}