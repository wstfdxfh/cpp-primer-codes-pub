#include "ch19_06.h"

#include <iostream>

// union Token {
//   char cval;
//   int ival;
//   double dval;
// };

class Token {
 public:
  Token() : tok(INT), ival(0) {}
  Token(const Token &t) : tok(t.tok) { copyUnion(t); }
  Token &operator=(const Token &t);
  ~Token() {
    if (tok == STR) sval.~basic_string();
  }

  Token &operator=(const std::string &);
  Token &operator=(char);
  Token &operator=(int);
  Token &operator=(double);

 private:
  enum { INT, CHAR, DBL, STR } tok;
  union {
    char cval;
    int ival;
    double dval;
    std::string sval;
  };
  void copyUnion(const Token &);
};

Token &Token::operator=(int i) {
  if (tok == STR) sval.~basic_string();
  ival = i;
  tok = INT;
  return *this;
}
Token &Token::operator=(double d) {
  if (tok == STR) sval.~basic_string();
  dval = d;
  tok = DBL;
  return *this;
}
Token &Token::operator=(char ch) {
  if (tok == STR) sval.~basic_string();
  cval = ch;
  tok = CHAR;
  return *this;
}

Token &Token::operator=(const std::string &s) {
  if (tok == STR)
    sval = s;
  else
    // 定位new表达式
    new (&sval) std::string(s);
  tok = STR;
  return *this;
}

void Token::copyUnion(const Token &t) {
  switch (t.tok) {
    case Token::INT:
      ival = t.ival;
      break;
    case Token::CHAR:
      cval = t.cval;
      break;
    case Token::DBL:
      dval = t.dval;
      break;
    case Token::STR:
      new (&sval) std::string(t.sval);  // 定位new表达式
  }
}

Token &Token::operator=(const Token &t) {
  if (tok == STR && t.tok != STR) sval.~basic_string();
  if (tok == STR && t.tok == STR)
    sval = t.sval;
  else
    copyUnion(t);
  tok = t.tok;
  return *this;
}

int main() {
  union {
    char cval;
    int ival;
    double dval;
  };
  // 用于初始化第一个成员
  Token firstToken;
  firstToken = 'a';
  firstToken = "Hello";
  cval = 'c';
  return 0;
}
