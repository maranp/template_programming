#pragma once

#pragma once

#include <cassert>

#include "../ihelper.h"
#include "stack.hpp"

// parameterized for T
// but specialized for T*
template <typename T>
class stack<T*> {
private:
  vector<T*> elems;
public:
  void push(T*);
  T* pop();
  T* top() const;
  bool empty() const {
    return elems.empty();
  }

  stack & operator=(stack const &s) {
    elems = s.elems;
    return *this;
  }

  // method 2
  template <typename U>
  friend std::ostream & operator<<(std::ostream & strm, stack<U*> const & s);
};


template <typename T>
void stack<T*>::push(T* elem) {
  elems.push_back(elem);
}

template <typename T>
T* stack<T*>::pop() {
  assert(!elems.empty());
  T* temp = elems.back();
  elems.pop_back();
  return temp;
}

template <typename T>
T* stack<T*>::top() const {
  assert(!elems.empty());
  return elems.back();
}

// method 2
template <typename U>
std::ostream & operator<<(std::ostream & strm, stack<U*> const & s) {
  for (auto const & e : s.elems) {
    strm << e << '\n';
  }
  return strm;
}
