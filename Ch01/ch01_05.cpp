#include "Sales_item.h"
#include <iostream>

int main(int argc, char* argv[]) {
  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  if (item1.isbn() == item2.isbn()) {
    std::cout << item1 + item2 << std::endl;
    return 0;
  } else {
    std::cerr << "Data must refer to same ISBN" << std::endl;
    return -1;
  }
  
}