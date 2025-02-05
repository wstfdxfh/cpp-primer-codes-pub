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
  multimap<string, string> last_first;
  string last_name;
  string first_name;
  while (cin >> last_name) {
    cin >> first_name;
    // 两个方法效果一样
    // last_first.insert({last_name, first_name});
    last_first.emplace(last_name, first_name);
  }
  // Zhang San Zhang Wu Li Si Li Liu
  for_each(last_first.begin(), last_first.end(), [](auto fullname) {
    cout << fullname.first << " " << fullname.second << endl;
  });

  // 作者-作品multimap
  multimap<string, string> author_works = {{"Zhang San", "Harry Potter"},
                                           {"Zhang San", "Harry Potter"},
                                           {"Zhang San", "Three Body"},
                                           {"Zhang San", "C++ Primer"},
                                           {"Li Si", "Mathematics"}};
  pair<string, string> want_to_del = {"Zhang San", "Harry Potter"};
  auto it = author_works.find(want_to_del.first);
  auto num = author_works.count(want_to_del.first);
  for (; num > 0; --num) {
    if (it->second == want_to_del.second) {
      it = author_works.erase(it);
    }
  }

  for_each(author_works.begin(), author_works.end(),
           [](auto aw) { cout << aw.first << " " << aw.second << endl; });

  return 0;
}