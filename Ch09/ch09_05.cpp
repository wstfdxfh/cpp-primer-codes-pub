#include <iostream>
#include <string>
#include <vector>

using namespace std;

void replace_str(string &s, const string &oldVal, const string &newVal) {
  size_t oldLen = oldVal.size();
  size_t newLen = newVal.size();
  for (auto it = s.begin(); it != s.end(); ++it) {
    size_t pos = it - s.begin();
    if (s.substr(pos, oldLen) == oldVal) {
      s.replace(it, it + oldLen, newVal);
      it = s.begin() + pos + newLen - 1;
    }
  }
}

string call_name(const string &name, const string &pre, const string &post) {
  string res;
  res.append(pre);
  res.append(name);
  res.append(post);
  return res;
}

int sumOfStr(const vector<string> &svec) {
  int res;
  for (auto s : svec) {
    res += stoi(s);
  }
  return res;
}

int main() {
  string s("It's a good day.");
  string oldVal("'s");
  string newVal(" is");
  replace_str(s, oldVal, newVal);
  cout << s << endl;

  cout << call_name("Napoleon", "Mr.", " III") << endl;

  // 字符串搜索
  string::size_type pos = 0;
  string name = "AnnaBelle1999";
  string numbers = "0123456789";
  while ((pos = name.find_first_of(numbers, pos)) != string::npos) {
    cout << "found number at index: " << pos << " element is: " << name[pos]
         << endl;
    ++pos;
  }

  // 数值转换
  cout << sumOfStr({"1", "-1", "0", "114514"}) << endl;

  return 0;
}
