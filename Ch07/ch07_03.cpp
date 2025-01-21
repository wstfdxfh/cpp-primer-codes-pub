#include <iostream>
#include <string>
#include <vector>

class Window_mgr;

class Screen {
  friend class Window_mgr;

 public:
  using pos = std::string::size_type;
  // 默认构造函数
  Screen() = default;
  // 成员初始值列表构造函数
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}
  // 委托构造函数
  Screen(pos ht, pos wd) : Screen(ht, wd, ' ') {}

  char get() const { return contents[cursor]; }
  inline char get(pos ht, pos wd) const;

  Screen &set(char c) {
    contents[cursor] = c;
    return *this;
  }
  Screen &set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
  }

  Screen &move(pos r, pos c);
  // const重载
  Screen &display(std::ostream &os) {
    doDisplay(os);
    return *this;
  }
  const Screen &display(std::ostream &os) const {
    doDisplay(os);
    return *this;
  }

  pos size() const { return height * width; }

 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  void doDisplay(std::ostream &os) const { os << contents; }
};

/*类内定义的成员默认是内联函数，也可以通过在类内部或者外部实现的时候指明inline*/
inline Screen &Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

class Window_mgr {
 private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};

 public:
  using ScreenIndex = std::vector<Screen>::size_type;
  ScreenIndex addScreen(const Screen &s) {
    screens.push_back(s);
    return screens.size() - 1;
  }
  void clear(ScreenIndex i) {
    Screen &s = screens[i];
    s.contents = std::string(s.height * s.width, ' ');
  }
};

int main() {
  Screen screen(20, 5, 'e');
  screen.display(std::cout);

  Window_mgr window;
  return 0;
}
