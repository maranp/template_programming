#pragma once

#include <vector>
using std::vector;

#include <cassert>

#include "../ihelper.h"
#include "stack.hpp"

template <>
class stack<string> {
private:
  std::deque<string> elems;
public:
  void push(string const &);
  void pop();
  string const & top() const;
  bool empty() const {
    return elems.empty();
  }

  //stack(stack const &s) : elems {s.elems} {}
  stack & operator=(stack const &s) {
    elems = s.elems;
    return *this;
  }

  friend std::ostream & operator<<(std::ostream & strm, stack<string> const & s);
};

void stack<string>::push(string const & elem) {
  elems.push_back(elem);
}

void stack<string>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

string const & stack<string>::top() const {
  assert(!elems.empty());
  return elems.back();
}

std::ostream & operator<<(std::ostream & strm, stack<string> const & s) {
  for (auto const & e : s.elems) {
    strm << e << '\n';
  }
  return strm;
}
