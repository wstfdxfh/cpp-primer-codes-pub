
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using std::begin;
using std::cerr;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::getline;
using std::initializer_list;
using std::ispunct;
using std::isupper;
using std::string;
using std::toupper;
using std::vector;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

string::size_type find_char(const string &s, char c,
                            string::size_type &occurs) {
  auto ret = s.size();
  occurs = 0;
  for (size_t i = 0; i != s.size(); i++) {
    if (s[i] == c) {
      if (ret == s.size()) {
        ret = i;
      }
      ++occurs;
    }
  }
  return ret;
}

// 应当加上const
bool is_empty(const string s) { return s.empty(); }

// 判断string是否含有大写字符
bool hasUpper(const string s) {
  for (auto ch : s) {
    if (isupper(ch)) return true;
  }
  return false;
}
// 将string全部改成小写形式
void tolower(string &s) {
  for (auto &ch : s) {
    ch = tolower(ch);
  }
}

// 使用标准库规范
void print(const int *beg, const int *end) {
  while (beg != end) {
    cout << *beg++ << endl;
  }
}

// 传递多维数组
void print(int (*matrix)[10], int rowSize) {
  for (int i = 0; i < rowSize; ++i) {
    for (int j = 0; j < 10; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
// 等于以下的声明：
// void print(int matrix[][10], int rowSize)

// 交换指针
void swapPointer(int *&p1, int *&p2) {
  auto temp = p1;
  p1 = p2;
  p2 = temp;
}

int sumInts(initializer_list<int> li) {
  int sum = 0;
  for (auto &i : li) {
    sum += i;
  }
  return sum;
}

int main(int argc, char const *argv[]) {
  int a = 25, b = 24;
  swap(&a, &b);
  cout << a << " " << b << endl;

  string s = "Hello, World!";
  string::size_type occurs = 0;
  auto ret = find_char(s, 'o', occurs);
  cout << ret << " " << occurs << endl;

  cout << is_empty(s) << endl;
  cout << hasUpper(s) << endl;
  tolower(s);
  cout << s << endl;

  int j[2] = {1, 2};
  print(begin(j), end(j));

  int mat[2][10] = {{1, 2, 3}, {}};
  print(mat, 2);

  cout << sumInts({42, 42, 24}) << endl;

  return 0;
}

// https://github.com/jaege/Cpp-Primer-5th-Exercises/blob/master/ch6/6.25.cpp
//  int main(int argc, char *argv[]) {
//    std::cout << "All " << argc << " argument"
//              << (argc > 1 ? "s are:" : " is:") << std::endl;
//    for (int i = 0; i < argc; ++i)
//      std::cout << i << "\t" << argv[i] << std::endl;
//    if (argc < 3)  // programname argument1 argument2 0
//      return -1;
//    std::string args(argv[1]);
//    args += argv[2];
//    std::cout << args << std::endl;
//    return 0;
//  }
