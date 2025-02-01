#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print_deque(deque<string> &ds) {
  string temp;
  // An apple a day keep the doctor away
  while (cin >> temp) {
    ds.push_back(temp);
  }
  for (auto it = ds.begin(); it != ds.end(); ++it) {
    cout << *it << endl;
  }
}

int main() {
  vector<string> sv;
  sv.insert(sv.end(), 10, "Anna");
  auto &s = sv.at(1);
  s = "NewName";
  cout << sv[1] << endl;

  if (!sv.empty()) {
    cout << sv.front() << " " << sv.back() << endl;
  }

  cout << "=============================" << endl;

  deque<string> ds;
  // print_deque(ds);

  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  vector<int> vi;
  list<int> li;
  forward_list<int> fli;
  cout << end(ia) - begin(ia) << endl;
  for (int i = 0; i < end(ia) - begin(ia); ++i) {
    vi.push_back(ia[i]);
    li.push_back(ia[i]);
    fli.push_front(ia[end(ia) - begin(ia) - i - 1]);
  }
  // 删除奇数元素
  auto it = vi.begin();
  while (it != vi.end()) {
    if (*it % 2) {
      it = vi.erase(it);
    } else {
      ++it;
    }
  }
  cout << vi.size() << endl;
  // 删除偶数元素

  auto lit = li.begin();
  while (lit != li.end()) {
    if (*lit % 2) {
      ++lit;
    } else {
      lit = li.erase(lit);
    }
  }
  cout << li.size() << endl;

  // 单链表删除奇数元素
  auto prev = fli.before_begin();
  auto curr = fli.begin();
  while (curr != fli.end()) {
    if (*curr % 2) {
      curr = fli.erase_after(prev);
    } else {
      prev = curr;
      ++curr;
    }
  }
  for (auto i : fli) {
    cout << i << " ";
  }

  cout << endl << "=============================" << endl;

  vi = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  li = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

  // 删除偶数元素 复制每个奇数元素
  auto iter = vi.begin();
  while (iter != vi.end()) {
    if (*iter % 2) {
      iter = vi.insert(iter, *iter);
      iter += 2;
    } else {
      iter = vi.erase(iter);
    }
  }

  for (auto i : vi) {
    cout << i << " ";
  }
  cout << endl;
  auto liter = li.begin();
  while (liter != li.end()) {
    if (*liter % 2) {
      liter = li.insert(liter, *liter);
      ++liter;
      ++liter;
    } else {
      liter = li.erase(liter);
    }
  }

  for (auto i : li) {
    cout << i << " ";
  }

  return 0;
}
