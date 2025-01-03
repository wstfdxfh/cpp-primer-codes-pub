#include <string>
#include <iostream>
#include <cctype>
#include <vector>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::getline;
using std::ispunct;
using std::toupper;
using std::vector;

int main(int argc, char* argv[]) {
  vector<int> v = {1, 2, 3, 4, 5, -1};
  for (auto& item : v) {
    item = (item % 2 == 0) ? item : item * 2;
    // item = ((item % 2 == 1) ? item * 2 : item);
    cout << item << " ";
  }
	
  return 0;
}