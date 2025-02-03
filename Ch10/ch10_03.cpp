#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

using namespace std;
using namespace std::placeholders;

// 比较字符串长度的二元谓词
bool isShorter(const string &s1, const string &s2) {
  return s1.size() < s2.size();
}

bool isEqOrLongerThanFive(const string &s) { return s.size() >= 5; }

int main() {
  // 排序并且消除重复
  vector<string> words{"the",  "quick", "red",  "fox", "jumps",
                       "over", "the",   "slow", "red", "turtle"};
  sort(words.begin(), words.end());
  auto unique_end = unique(words.begin(), words.end());
  words.erase(unique_end, words.end());
  // 按照长度重新排序，并且等长string保留原有的顺序
  stable_sort(words.begin(), words.end(), isShorter);
  for (auto s : words) {
    cout << s << " ";
  }
  cout << endl;

  vector<string> wordsCopy;
  copy(words.begin(), words.end(), back_inserter(wordsCopy));

  // 打印长度大于等于5的元素 true 排在前半部分 false 排在后半部分

  auto endit =
      stable_partition(words.begin(), words.end(), isEqOrLongerThanFive);
  for (auto it = words.begin(); it != endit; ++it) {
    cout << *it << " ";
  }
  cout << endl;

  // 寻找并且打印长度大于等于sz的元素（前面已经排序）
  size_t sz = 4;
  auto wc = find_if(wordsCopy.begin(), wordsCopy.end(),
                    [sz](const string &a) { return a.size() >= sz; });
  for_each(wc, wordsCopy.end(), [](const string &s) { cout << s << " "; });
  cout << endl;

  // 返回大小大于size的元素个数
  auto times = count_if(wordsCopy.begin(), wordsCopy.end(),
                        [sz](const string &s) { return s.size() > sz; });
  cout << times << " time(s) longer than " << sz << endl;

  // 递减直到为0
  int i = 10;
  auto dec = [i]() mutable -> bool {
    if (i > 0) {
      --i;
      return false;
    }
    return true;
  };

  cout << dec() << endl;

  // 从长到短进行排序
  sort(wordsCopy.begin(), wordsCopy.end(), bind(isShorter, _2, _1));
  for_each(wordsCopy.begin(), wordsCopy.end(),
           [](const string &s) { cout << s << " "; });
  cout << endl;

  return 0;
}
