#include <bitset>
#include <fstream>
#include <iostream>
#include <string>

std::istream &read(std::istream &is) {
  while (!is.eof()) {
    std::string temp;
    // std::getline(is, temp);
    is >> temp;
    std::cout << temp << std::endl;
  }

  is.clear();
  return is;
}

int main() {
  std::string ifile = "input.txt";
  std::string ifile2 = "input2.txt";
  std::ifstream in(ifile);
  std::ofstream out;

  read(in);
  // 输出时不进行覆盖 std::ofstream::app | std::ofstream::out
  out.open(ifile, std::ofstream::app);
  // out.open(ifile, std::ofstream::trunc);
  if (out) {
    out << "Words from ch08_02.cpp" << std::endl;
  }

  in.close();
  in.open(ifile2);
  read(in);
  return 0;
}
