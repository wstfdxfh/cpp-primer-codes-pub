#ifndef CH16_01_2_H
#define CH16_01_2_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

template <typename>
class BlobPtr;

template <typename>
class Blob;

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
  return *lhs.data == *rhs.data;
}

template <typename T>
class Blob {
  // 每个Blob实例将访问权限授予给相同类型实例化的BlobPtr和相等运算符
  friend class BlobPtr<T>;
  friend bool operator== <T>(const Blob<T>&, const Blob<T>&);

 public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;

  Blob() : data(std::make_shared<std::vector<T>>()) {}
  Blob(std::initializer_list<T> il)
      : data(std::make_shared<std::vector<T>>(il)) {}

  void push_back(const T& t) { data->push_back(t); }
  void push_back(T&& t) { data->push_back(std::move(t)); }
  void pop_back() {
    check(0, "pop_back on empty Blob");
    data->pop_back();
  }
  T& back() {
    check(0, "back on empty Blob");
    return data->back();
  }

  void push_front(const T& t) { data->insert(data->begin(), t); }
  void push_front(T&& t) { data->insert(data->begin(), std::move(t)); }

  void pop_front() {
    check(0, "pop_front on empty Blob");
    data->erase(data->begin());
  }
  T& front() {
    check(0, "front on empty Blob");
    return data->front();
  }

  T& operator[](size_type index) {
    check(index, "subscript out of range");
    return (*data)[index];
  }

  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }

 private:
  std::shared_ptr<std::vector<T>> data;
  // 若data[i]无效，则抛出msg
  void check(size_type i, const std::string& msg) const;
};

template <typename T>
void Blob<T>::check(size_type i, const std::string& msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

template <typename T>
class BlobPtr {
  // 将模板类型参数声明为自己的友元
  friend T;

 public:
  BlobPtr() : curr(0) {}
  BlobPtr(Blob<T>& a, size_t sz = 0) : wptr(a.data), curr(sz) {}

  T& operator*() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
  }

  // BlobPtr<T> &的简化写法
  BlobPtr& operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
  }
  BlobPtr& operator--() {
    check(curr, "decrement past beginning of BlobPtr");
    --curr;
    return *this;
  }
  BlobPtr operator++(int) {
    BlobPtr ret = *this;
    ++*this;
    return ret;
  }
  BlobPtr operator--(int);

 private:
  // 若检查成功，则返回指向vector的shared_ptr
  std::shared_ptr<std::vector<T>> check(std::size_t i,
                                        const std::string& msg) const;
  std::weak_ptr<std::vector<T>> wptr;
  std::size_t curr;
};

// 返回类型因为在类作用域外，所以必须写清类模板名
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
  BlobPtr ret = *this;
  --*this;
  return ret;
}

#endif  // CH16_01_2_H