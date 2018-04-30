#pragma once

#include "../ihelper.h"
template <typename T>
class stack {
private:
  // we need push_front. So using deque instead of vector
  deque<T> elems;
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
  template <typename T2>
  stack& operator=(stack<T2> const & op2);

  template <typename U>
  friend ostream& operator<<(ostream& out, stack<U> const &);
};

template <typename T>
template <typename T2>
stack<T>& stack<T>::operator=(stack<T2> const & op2) {
  // op2's type is different from *this
  // so op2's private members are not accessible
  // so, we need to use op2's public interfaces to perform the job
  // we have only top and pop for the mission
  // since op2 is const&, pop can't be operated on it.
  // so, copy op2 into tmp and then.. just do it.
  auto tmp = op2;
  elems.clear();
  // at the end of the loop,
  // top of op2 should be top of this->elems
  // push_back will put top of op2 to bottom of this->elems
  while (!tmp.empty()) {
    elems.push_front(tmp.top());
    tmp.pop();
  }
  return *this;
}

template <typename T>
ostream& operator<<(ostream& out, stack<T> const &s) {
  for (auto const & e : s.elems) {
    out << e << '\n';
  }
  return out;
}
