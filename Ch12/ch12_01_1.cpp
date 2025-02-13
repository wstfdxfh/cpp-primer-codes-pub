#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class StrBlob {
 public:
  typedef vector<string>::size_type size_type;
  StrBlob();
  StrBlob(initializer_list<string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  // 添加删除元素
  void push_back(const string &t) { data->push_back(t); }
  void pop_back();
  // 访问元素
  string &front();
  string &back();
  const string &front() const;
  const string &back() const;

 private:
  shared_ptr<vector<string>> data;
  void check(size_type i, const string &msg) const;
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il)
    : data(make_shared<vector<string>>(il)) {}

void StrBlob::check(size_type i, const string &msg) const {
  if (i >= data->size()) {
    throw out_of_range(msg);
  }
}

string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

const string &StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

template <typename T>
using twin = pair<T, T>;

int main() {
  shared_ptr<string> p1;
  p1 = make_shared<string>(10, '9');
  cout << *p1 << endl;
  auto q1 = make_shared<string>("Init");
  // q1原本指向的内容引用数减为0，被自动释放
  q1 = p1;
  cout << *q1 << endl;
  StrBlob b1;
  {
    StrBlob b2 = {"a", "an", "the"};
    b1 = b2;
    b2.push_back("about");
  }
  cout << b1.size() << endl;

  twin<string> authors = {"James", "Joyce"};

  return 0;
}