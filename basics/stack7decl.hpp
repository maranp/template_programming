#pragma once

#include "../ihelper.h"

template <typename T, typename Cont = deque<T>>
class stack {
private:
  // we need push_front. So using deque instead of vector
  Cont elems;
public:
  void push(T const & elem) {
    elems.push_back(elem);
  }
  void pop() {
    elems.pop_back();
  }
  T const & top() const {
    return elems.back();
  }
  bool empty() const {
    return elems.empty();
  }
  template <typename T2, typename C2>
  stack& operator=(stack<T2, C2> const & op2);

  // allow stack<U, C2> where U != T and C2 != Cont to access stack<T, Cont>'s private members
  template <typename, typename>
  friend class stack;

  template <typename U, typename C2>
  friend ostream& operator<<(ostream& out, stack<U, C2> const &);
};

template <typename T, typename Cont>
template <typename T2, typename C2>
stack<T, Cont>& stack<T, Cont>::operator=(stack<T2, C2> const & op2) {
  elems.clear();
  // at the end of the loop,
  // top of op2 should be top of this->elems
  // push_back will put top of op2 to bottom of this->elems
  elems.insert(begin(elems), begin(op2.elems), end(op2.elems));
  return *this;
}

template <typename T, typename C>
ostream& operator<<(ostream& out, stack<T, C> const &s) {
  for (auto const & e : s.elems) {
    out << e << '\n';
  }
  return out;
}
