#include <iostream>
#include <stdexcept>
// https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch5/5.25.cpp
int main() {
  int a, b;
  bool tryAgain;
  do {
    tryAgain = false;
    try {
      std::cin >> a >> b;
      if (b == 0) throw std::runtime_error("Divide by 0.");
      std::cout << a / b << std::endl;
    } catch (std::runtime_error err) {
      std::cout << err.what() << "\nTry again? (y/n)" << std::endl;
      char c;
      if (std::cin >> c && (c == 'y' || c == 'Y')) tryAgain = true;
    }
  } while (tryAgain);

  return 0;
}
