#include <bitset>
#include <iostream>
#include <string>

std::istream &read(std::istream &is) {
  auto oldstate = is.rdstate();
  is.clear();
  while (!is.eof()) {
    std::string temp;
    is >> temp;
    std::cout << temp << std::endl;
  }
  std::cout << std::bitset<8>(is.rdstate()) << std::endl;
  // 下面四个都是constexpr
  std::cout << std::bitset<8>(is.failbit) << std::endl;
  std::cout << std::bitset<8>(is.badbit) << std::endl;
  std::cout << std::bitset<8>(is.goodbit) << std::endl;
  std::cout << std::bitset<8>(is.eofbit) << std::endl;

  is.clear();
  std::cout << std::bitset<8>(is.rdstate()) << std::endl;

  return is;
}

int main() {
  read(std::cin);
  return 0;
}
