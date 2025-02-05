#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<pair<string, int>> vp;
  string str;
  int i;
  while (cin >> str) {
    cin >> i;
    vp.push_back({str, i});
  }
  for_each(vp.cbegin(), vp.cend(), [](const pair<string, int> si) {
    cout << si.first << " " << si.second << endl;
  });
  return 0;
}