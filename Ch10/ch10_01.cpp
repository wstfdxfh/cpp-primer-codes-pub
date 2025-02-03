
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> vi = {1, 2, 3, 4, 11, 45, 14, 1, 1};
  cout << count(vi.begin(), vi.end(), 1) << endl;
  return 0;
}
