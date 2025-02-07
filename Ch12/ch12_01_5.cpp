#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct destination {
  unsigned id;
  explicit destination(unsigned des_id = 0) : id(des_id) {}
};  // resource

struct connection {
  destination *dest;
};

connection connect(destination *dest) {
  connection new_conn;
  new_conn.dest = dest;
  cout << "Setup connection to " << new_conn.dest->id << endl;
  return new_conn;
}

void disconnect(connection conn) {
  cout << "Stop connection to " << conn.dest->id << endl;
  conn.dest = nullptr;
}

void f(destination &d) {
  connection c = connect(&d);
  unique_ptr<connection, decltype(disconnect) *> p(&c, disconnect);
  std::cout << "Using connection " << c.dest->id << std::endl;
}

int main() {
  unique_ptr<string> p1(new string("Str"));
  // 将所有权从p1转移到p2
  unique_ptr<string> p2(p1.release());
  unique_ptr<string> p3(new string("Another Str"));
  p2.reset(p3.release());
  cout << *p2 << endl;
  auto p = p2.release();
  // 如果转移给了普通指针 必须手动管理资源释放
  delete p;

  destination d(1001);
  f(d);

  return 0;
}