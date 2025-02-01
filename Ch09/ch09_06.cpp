#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  deque<int> deq = {1, 2, 3, 42};
  stack<int> stk(deq);
  vector<int> vec = {114, 514, 19, 19, 810};
  stack<int, vector<int>> stk2(vec);
  for (size_t i = 0; i != 10; ++i) {
    stk.push(i);
  }

  while (!stk.empty()) {
    int val = stk.top();
    stk.pop();
  }

  priority_queue<int> pque(vec.begin(), vec.end());
  while (!pque.empty()) {
    cout << pque.top() << endl;
    pque.pop();
  }

  return 0;
}
