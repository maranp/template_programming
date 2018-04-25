#pragma once

#include <vector>
using std::vector;

#include <cassert>

#include "../ihelper.h"

// method 3 of printing a container on a stream
// forward declaration of stack<T>
// not working
//template <typename T>
//class stack;
// forward declaration of function template
//template <typename T>
//std::ostream & operator>>(std::ostream &, stack<T> const &);

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

//  method 1
//  void printon(std::ostream & strm) const {
//    for (auto const & e : elems) {
//      strm << e << '\n';
//    }
//  }

  // method 2
  template <typename U>
  friend std::ostream & operator<<(std::ostream & strm, stack<U> const & s);

  // method 3
  // specialization of function template operator<< for T, the type of this instance of class
  // mot working
//  friend std::ostream & operator<< <T> (std::ostream &, stack<T> const &);
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

// method 1
//template <typename T>
//std::ostream & operator<<(std::ostream & strm, stack<T> const & s) {
//  s.printon(strm);
//  return strm;
//}

// method 2
template <typename U>
std::ostream & operator<<(std::ostream & strm, stack<U> const & s) {
  for (auto const & e : s.elems) {
    strm << e << '\n';
  }
  return strm;
}

// method 3
// implementation of template specialization of operator<<
// not working
//template <typename T>
//std::ostream & operator<< <T>(std::ostream & strm, stack<T> const & s) {
//  for (auto const & e : s.elems) {
//    strm << e << ' #\n';
//  }
//  return strm;
//}
