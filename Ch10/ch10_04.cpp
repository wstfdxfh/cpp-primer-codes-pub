#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

#define IOSTREAM_ITER

int main() {
  vector<int> vi = {12, 34, 56, 56, 56, 114};
  list<int> li;
  unique_copy(vi.begin(), vi.end(), inserter(li, li.begin()));
  for_each(li.cbegin(), li.cend(), [](int i) { cout << i << " "; });
  cout << endl;
#ifdef IOSTREAM_ITER
  istream_iterator<int> in_iter(cin), eof;
  vector<int> vec(in_iter, eof);
  // 使用ostream_iterator打印
  ostream_iterator<int> out_iter(cout, " ");
  copy(vec.begin(), vec.end(), out_iter);
#endif
  // 3到7之间的元素反向拷贝
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  list<int> target;
  copy(nums.crbegin() + 3, nums.crbegin() + 7 + 1,
       inserter(target, target.begin()));
  for_each(target.cbegin(), target.cend(), [](int i) { cout << i << " "; });

  return 0;
}
