#include <iostream>

int main(int argc, char* argv[]) {
  int sum = 0;
  int i = 50;
  while (i <= 100) {
    sum += i;
    ++i;
  }
  std::cout << sum << std::endl;

  std::cout << "Please input 2 Integer:" << std::endl;
  int v1, v2, temp;
  std::cin >> v1 >> v2;
  // temp = v1;
  //
  // while (v1 <= v2) {
  //   std::cout << v1 << " ";
  //   ++v1;
  // }
  // std::cout << std::endl;
  //
  // v1 = temp;
  if (v1 > v2) {
    for (; v1 >= v2; --v1) {
      std::cout << v1 << " ";
    }
  } else {
    for (; v1 <= v2; ++v1) {
      std::cout << v1 << " ";
    }
  }

  std::cout << std::endl << "Sum Computing:";

  sum = 0;
  temp = 0;
  // 读取数量不定的输入数据
  // 直到遇到结束符ctrl+D
  while (std::cin >> temp) {
    sum += temp;
  }
  std::cout << "Sum is: " << sum << std::endl;
  return 0;
}