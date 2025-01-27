#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<int>::iterator find_value(vector<int>::iterator beg,
                                 vector<int>::iterator end, int value) {
  while (beg != end) {
    if (value == *beg) {
      return beg;
    }
    ++beg;
  }
  return beg;
}

int main(int argc, char const *argv[]) {
  vector<int> iv = {1, 2, 3, 4, 5};
  int value = 33;
  auto it = find_value(iv.begin(), iv.end(), value);
  if (it != iv.end()) {
    cout << "Found " << *it << endl;
  } else {
    cout << value << " Not Found!" << endl;
  }
  return 0;
}
