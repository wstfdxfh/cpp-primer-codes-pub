#ifndef CH16_01_4_H
#define CH16_01_4_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class DebugDelete {
 public:
  DebugDelete(std::ostream& s = std::cerr) : os(s) {}
  template <typename T>
  void operator()(T* p) const {
    os << "deleting unique_ptr" << std::endl;
    delete p;
  }

 private:
  std::ostream& os;
};

template <typename T>
class Blob {
 public:
  typedef T value_type;
  typedef typename std::vector<T>::size_type size_type;

  Blob() : data(std::make_shared<std::vector<T>>()) {}
  Blob(std::initializer_list<T> il)
      : data(std::make_shared<std::vector<T>>(il)) {}
  template <typename It>
  Blob(It b, It e);

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
  void check(size_type i, const std::string& msg) const {
    if (i >= data->size()) {
      throw std::out_of_range(msg);
    }
  }
};

template <typename T>
template <typename It>
Blob<T>::Blob(It b, It e) : data(std::make_shared<std::vector<T>>(b, e)) {}

#endif  // CH16_01_4_H