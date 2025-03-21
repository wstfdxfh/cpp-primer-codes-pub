#ifndef CH16_03_H
#define CH16_03_H

#include <iostream>
#include <memory>
#include <sstream>
#include <string>

template <typename T>
std::string debug_rep(const T& t) {
  std::ostringstream ret;
  ret << t;
  return ret.str();
}

template <typename T>
std::string debug_rep(T* p) {
  std::ostringstream ret;
  ret << "pointer: " << p;
  if (p)
    ret << " " << debug_rep(*p);
  else
    ret << " null pointer";
  return ret.str();
}

std::string debug_rep(const std::string& s) { return '"' + s + '"'; }

std::string debug_rep(char* p) { return debug_rep(std::string(p)); }

std::string debug_rep(const char* p) { return debug_rep(std::string(p)); }

#endif  // CH16_03_H