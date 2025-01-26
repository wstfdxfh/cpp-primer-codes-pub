#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main() {
  std::string ifile2 = "input2.txt";
  std::ifstream in(ifile2);
  std::ostringstream string_init;
  std::string temp;
  // 从input2.txt逐行读入，并且输出到string流
  while (getline(in, temp)) {
    string_init << temp << std::endl;
  }

  std::string whole_record = string_init.str();
  //   "morgan 2015552368 8625550123 \n drew 9735550130 \n lee 6095550132";
  std::cout << whole_record << std::endl;
  std::vector<PersonInfo> people;
  std::string line, word;
  std::istringstream whole_reader(whole_record);
  while (std::getline(whole_reader, line)) {
    PersonInfo info;
    // 如果在外层定义record，则需要每次执行record.clear()
    std::istringstream record(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }

  std::cout << people[1].name << " " << people[1].phones[0] << std::endl;

  return 0;
}
