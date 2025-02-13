#include "ch16_01_3.h"

#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template <typename T, typename F = std::less<T>>
int compare(const T& v1, const T& v2, F f = F()) {
  if (f(v1, v2)) return -1;
  if (f(v2, v1)) return 1;
  return 0;
}

template <typename T>
void print(const T& list) {
  using size_type = typename T::size_type;
  size_type sz = list.size();
  for (size_type i = 0; i < sz; ++i) {
    cout << list[i] << " ";
  }
  cout << endl;
}

template <typename It>
void print(It begin, It end) {
  while (begin != end) {
    cout << *begin << " ";
    ++begin;
  }
  cout << endl;
}

int main() {
  int i = compare(1, 2);
  cout << i << endl;

  vector<int> vi = {1, 2, 3};
  print(vi);
  print(vi.begin(), vi.end());
  return 0;
}