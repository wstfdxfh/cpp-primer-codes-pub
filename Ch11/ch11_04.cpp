#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, string> buildMap(ifstream &map_file) {
  unordered_map<string, string> trans_map;
  string key;
  string value;
  while (map_file >> key && getline(map_file, value)) {
    if (value.size() > 1) {
      trans_map[key] = value.substr(1);
    } else {
      throw runtime_error("no rule for " + key);
    }
  }
  return trans_map;
}

const string &transform(const string &s,
                        const unordered_map<string, string> &m) {
  auto map_it = m.find(s);
  if (map_it != m.cend()) {
    return map_it->second;
  }
  return s;
}

void word_transform(ifstream &map_file, ifstream &input) {
  auto trans_map = buildMap(map_file);
  string text;
  while (getline(input, text)) {
    istringstream stream(text);
    string word;
    bool first = true;
    while (stream >> word) {
      if (first) {
        first = false;
      } else {
        cout << " ";
      }
      cout << transform(word, trans_map);
    }
    cout << endl;
  }
}

int main() {
  ifstream map_file("convert"), input("input_file");
  word_transform(map_file, input);
  return 0;
}