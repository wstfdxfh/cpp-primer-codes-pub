#ifndef CH1306H
#define CH1306H

#include <string>

class Strvec {
 public:
  Strvec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  Strvec(const Strvec &);  // 拷贝构造函数
  // 接收initializer_list的构造函数
  Strvec(std::initializer_list<std::string>);
  Strvec(Strvec &&) noexcept;             // 移动构造函数
  Strvec &operator=(const Strvec &);      // 拷贝赋值运算符
  Strvec &operator=(Strvec &&) noexcept;  // 移动赋值运算符
  ~Strvec();                              // 析构函数
  void push_back(const std::string &);    // 拷贝元素
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }  // 容量
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }
  void reserve(size_t n);
  void resize(size_t n);
  std::string &back() const { return *(first_free - 1); }

 private:
  static std::allocator<std::string> alloc;  // 分配元素
  void chk_n_alloc() {
    if (size() == capacity()) {
      reallocate();
    }
  }
  // 被拷贝构造函数 赋值运算符和析构函数使用
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();  // 销毁元素并释放内存
  void reallocate();
  std::string *elements;
  std::string *first_free;
  std::string *cap;
};

#endif