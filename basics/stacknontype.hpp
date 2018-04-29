#pragma once

#include <cassert>

#include "../ihelper.h"

template <typename T, size_t MaxSize = 100>
class stack {
private:
  array<T, MaxSize> elems;
  size_t numElems;
public:
  stack() : numElems {0} {}
  void push(T const &);
  void pop();
  T const & top() const;
  bool empty() const {
    return numElems == 0;
  }
  size_t size() const {
    return numElems;
  }
  //stack(stack const &s) : elems {s.elems} {}
  stack & operator=(stack const &s) {
    elems = s.elems;
    return *this;
  }

  // method 2
  template <typename U, size_t MaxUElems>
  friend std::ostream & operator<<(std::ostream & strm, stack<U, MaxUElems> const & s);

};


template <typename T, size_t MaxElems>
void stack<T, MaxElems>::push(T const & elem) {
  assert(numElems < MaxElems);
  elems[numElems++] = elem;
}

template <typename T, size_t MaxElems>
void stack<T, MaxElems>::pop() {
  assert(!elems.empty());
  --numElems;
}

template <typename T, size_t MaxElems>
T const & stack<T,  MaxElems>::top() const {
  assert(!elems.empty());
  // returns the value at emes[MaxSize - 1]
  // which is not we intend to seek
  // return elems.back();
  return elems[numElems - 1];
}

// method 2
template <typename U, size_t MaxUElems>
std::ostream & operator<<(std::ostream & strm, stack<U, MaxUElems> const & s) {
  for (auto const & e : s.elems) {
    strm << e << '\n';
  }
  return strm;
}
