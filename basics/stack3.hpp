#pragma once

#include <cassert>

#include "../ihelper.h"

template <typename T, typename Cont = vector<T>>
class stack {
private:
  Cont elems;
public:
  void push(T const &);
  void pop();
  T const & top() const;
  bool empty() const {
    return elems.empty();
  }

  //stack(stack const &s) : elems {s.elems} {}
  stack & operator=(stack const &s) {
    elems = s.elems;
    return *this;
  }

  // method 2
  template <typename U, typename UCont>
  friend std::ostream & operator<<(std::ostream & strm, stack<U, UCont> const & s);
};


template <typename T, typename Cont>
void stack<T, Cont>::push(T const & elem) {
  elems.push_back(elem);
}

template <typename T, typename Cont>
void stack<T, Cont>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T, typename Cont>
T const & stack<T, Cont>::top() const {
  assert(!elems.empty());
  return elems.back();
}

// method 2
template <typename U, typename UCont>
std::ostream & operator<<(std::ostream & strm, stack<U, UCont> const & s) {
  for (auto const & e : s.elems) {
    strm << e << '\n';
  }
  return strm;
}
