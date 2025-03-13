#include "ch17_01.h"

#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main() {
  tuple<size_t, size_t, size_t> threeD(1, 2, 3);
  cout << "threeD: " << get<0>(threeD) << endl;
  size_t sz = tuple_size<decltype(threeD)>::value;

  cout << "Size of threeD: " << sz << endl;
  tuple_element<0, decltype(threeD)>::type i = get<0>(threeD);

  return 0;
}
