#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <vector>

/**
 * @brief 应该将声明放在头文件中才能编译成功
 *
 */

// using namespace std;

// class QueryResult;

// class TextQuery {
//  public:
//   using line_no = vector<string>::size_type;
//   // 使用ifstream构造
//   TextQuery(ifstream& is) : file(new vector<string>) {
//     string text;
//     while (getline(is, text)) {
//       file->push_back(text);
//       // 当前行号
//       int n = file->size() - 1;
//       // 将行文本分解为单词
//       istringstream line(text);
//       string word;
//       while (line >> word) {
//         shared_ptr<set<line_no>>& lines = wm[word];
//         // 第一次遇到这个单词的时候，指针为空
//         if (!lines) {
//           lines.reset(new set<line_no>);
//         }
//         lines->insert(n);
//       }
//     }
//   }
//   QueryResult query(const string& sought) const {
//     // 如果未找到sought, 返回一个指向此set的指针
//     static shared_ptr<set<line_no>> nodata(new set<line_no>);
//     // 使用find而非下标
//     auto loc = wm.find(sought);
//     if (loc == wm.end()) {
//       return QueryResult(sought, nodata, file);
//     } else {
//       return QueryResult(sought, loc->second, file);
//     }
//   }

//  private:
//   shared_ptr<vector<string>> file;
//   map<string, shared_ptr<set<line_no>>> wm;
// };

// class QueryResult {
//   friend ostream& print(ostream&, const QueryResult&);

//  public:
//   using line_no = vector<string>::size_type;
//   QueryResult(string s, shared_ptr<set<line_no>> p,
//               shared_ptr<vector<string>> f)
//       : sought(s), lines(p), file(f) {}

//  private:
//   // 查询单词
//   string sought;
//   // 出现的行号
//   shared_ptr<set<line_no>> lines;
//   // 输入文件
//   shared_ptr<vector<string>> file;
// };

// ostream& print(ostream& os, const QueryResult& qr) {
//   os << qr.sought << " occurs " << qr.lines->size() << " " << "time(s)" <<
//   endl; for (auto num : *qr.lines) {
//     os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
//   }
//   return os;
// }

int main() { return 0; }