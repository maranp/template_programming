#pragma once

#include <vector>
using std::vector;

#include <cassert>

#include "../ihelper.h"

template <typename T>
class stack {
private:
  vector<T> elems;
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

//  void printon(std::ostream & strm) const {
//    for (auto const & e : elems) {
//      strm << e << '\n';
//    }
//  }
  template <typename U>
  friend std::ostream & operator<<(std::ostream & strm, stack<U> const & s);
};


template <typename T>
void stack<T>::push(T const & elem) {
  elems.push_back(elem);
}

template <typename T>
void stack<T>::pop() {
  assert(!elems.empty());
  elems.pop_back();
}

template <typename T>
T const & stack<T>::top() const {
  assert(!elems.empty());
  return elems.back();
}

//template <typename T>
//std::ostream & operator<<(std::ostream & strm, stack<T> const & s) {
//  s.printon(strm);
//  return strm;
//}

template <typename U>
std::ostream & operator<<(std::ostream & strm, stack<U> const & s) {
  for (auto const & e : s.elems) {
    strm << e << '\n';
  }
  return strm;
}
