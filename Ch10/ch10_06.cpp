#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

int main() {
  // 链表的操作，对于链表更为高效
  list<int> li = {114, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5};
  li.sort();
  li.unique();
  for_each(li.cbegin(), li.cend(), [](int i) { cout << i << " "; });
  return 0;
}
