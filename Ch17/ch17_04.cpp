#include "ch17_04.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <random>
#include <vector>
using namespace std;

vector<unsigned> randVec() {
  /**
   * @brief 生成随机vector，这里使用静态default_random_engine和
   * uniform_int_distribution使得多次调用产生不同结果
   *
   */
  static default_random_engine e;
  static uniform_int_distribution<unsigned> u(0, 9);
  vector<unsigned> ret;
  for (int i = 0; i < 5; ++i) {
    ret.push_back(u(e));
  }
  return ret;
}

int main() {
  default_random_engine e;
  //   e.seed(42);
  e.seed(time(0));
  for (size_t i = 0; i < 10; ++i) {
    // 随机生成unsigned
    // cout << e() << endl;
  }
  // 默认是int
  uniform_int_distribution<unsigned> u(0, 9);
  for (size_t i = 0; i < 10; ++i) {
    // cout << u(e) << endl;
  }
  auto vec = randVec();
  // for_each(vec.begin(), vec.end(), [](const auto &i) { cout << i << endl; });

  // 默认是double
  uniform_real_distribution<> ur(0, 1);
  // for (size_t i = 0; i < 5; i++) {
  //   cout << ur(e) << endl;
  // }

  normal_distribution<> n(4, 1.5);
  vector<unsigned> vals(9);
  for (size_t i = 0; i < 200; i++) {
    unsigned v = lround(n(e));
    if (v < vals.size()) {
      ++vals[v];
    }
  }
  for_each(vals.begin(), vals.end(),
           [](auto const &v) { cout << string(v, '*') << endl; });

  // 使用参数控制True的概率
  bernoulli_distribution b(.55);
  vector<int> vc(2);
  for (size_t i = 0; i < 100; i++) {
    if (b(e)) {
      ++vc[1];
    } else {
      ++vc[0];
    }
  }
  cout << string(vc[0], '=') << endl;
  cout << string(vc[1], '=') << endl;

  return 0;
}
