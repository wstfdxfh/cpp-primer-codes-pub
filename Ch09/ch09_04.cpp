#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
  vector<int> ivec;
  cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl;
  for (size_t i = 0; i < 24; i++) {
    ivec.push_back(i);
  }
  cout << "ivec size: " << ivec.size() << " capacity: " << ivec.capacity()
       << endl;

  return 0;
}
