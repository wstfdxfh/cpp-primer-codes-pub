#include "ch16_01_1.h"

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::vector;

int main() {
  list<string> ls = {"Hello", "World"};
  vector<int> vi = {1, 2, 3, 42};

  auto it = ::find(ls.begin(), ls.end(), "Hello");
  auto index = std::distance(ls.begin(), it);
  if (it != ls.end()) {
    cout << *it << " at index " << index << endl;
  }

  auto posit = ::find(vi.begin(), vi.end(), 42);
  if (posit != vi.end()) {
    cout << *posit << " at index " << posit - vi.begin() << endl;
  }

  return 0;
}