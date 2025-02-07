#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

vector<int> *make_vector() { return new vector<int>; }
shared_ptr<vector<int>> make_shared_vector() {
  return make_shared<vector<int>>();
}
vector<int> *read_to_vector(vector<int> *pv) {
  cout << "Please input int you want to save..." << endl;
  int temp;
  while (cin >> temp) {
    pv->push_back(temp);
  }
  return pv;
}

shared_ptr<vector<int>> read_to_vector(shared_ptr<vector<int>> pv) {
  cout << "Please input int you want to save..." << endl;
  int temp;
  while (cin >> temp) {
    pv->push_back(temp);
  }
  return pv;
}
void print_vector(vector<int> *pv) {
  for (auto i : *pv) {
    cout << i << " ";
  }
  cout << endl;
}

void print_vector(shared_ptr<vector<int>> pv) {
  for (auto i : *pv) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  shared_ptr<string> p1;
  p1 = make_shared<string>(10, '9');
  cout << *p1 << endl;
  const auto *ps = new const auto(*p1);  // 如果内存耗尽，抛出std::bad_alloc
  cout << *ps << endl;
  delete ps;

  // 如果内存耗尽，返回一个空指针
  int *pi = new (nothrow) int();
  delete pi;

  auto pv = make_vector();
  read_to_vector(pv);
  print_vector(pv);
  delete pv;

  cin.clear();

  auto spv = make_shared_vector();
  read_to_vector(spv);
  print_vector(spv);
  return 0;
}