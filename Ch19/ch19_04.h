#ifndef CH19_04_H
#define CH19_04_H

#include <string>

// 头文件内容将在这里添加

class Screen {
 public:
  using pos = std::string::size_type;
  static const std::string Screen::* data() { return &Screen::contents; }
  char get(pos i) const { return contents[i]; }
  char get() const { return contents[cursor]; }

 private:
  std::string contents = std::string("Hello");  // 内容
  pos cursor = 0;                               // 光标位置
};

#endif  // CH19_04_H
