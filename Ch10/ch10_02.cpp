#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// 比较字符串长度的二元谓词
bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

int main() {
  vector<string> vs{"Hello, ", "World!", "C++ Primer Ch10"};
  vector<string> vs2{"Hello, ", "World!"};
  vector<double> vd{3.14, 2.4};
  // 第三个参数不能使用const char*, 比如""
  auto res = accumulate(vs.cbegin(), vs.cend(), string(""));
  // 第二个序列至少和第一个一样长
  cout << equal(vs.begin(), vs.end(), vs2.begin()) << endl;
  // 错误示例 小数部分被丢弃了
  cout << accumulate(vd.begin(), vd.end(), 0) << endl;
  cout << accumulate(vd.begin(), vd.end(), 0.0) << endl;

  fill(vs.begin(), vs.end(), "Is C++ the Best Language?");
  cout << vs[0] << " " << vs[1] << " " << vs[2] << endl;

  fill_n(vs.begin(), 2, "Is Python the Best Language?");
  cout << vs[0] << " " << vs[1] << " " << vs[2] << endl;

  vector<int> vec;
  fill_n(back_inserter(vec), 10, 0);

  vector<int> new_vec;
  replace_copy(vec.cbegin(), vec.cend(), back_inserter(new_vec), 0, 42);

  cout << new_vec[0] << endl;

  

  return 0;
}
