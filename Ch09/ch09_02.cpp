#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <list>
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

void copy_to(list<const char*> &la, vector<string> &vs){
  vs.assign(la.cbegin(), la.cend());

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

  list<const char*>la = {"Hello", " ,World!"};
  vector<string> vs;
  copy_to(la, vs);
  cout << vs[0] << " " << vs[1] << endl;
  return 0;
}
