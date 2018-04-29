/*
 * stackauto.cpp
 *
 *  Created on: 28-Apr-2018
 *      Author: maran
 */

#include <cassert>
#include "../ihelper.h"

template <typename T, auto MaxSize>
class stack {
public:
  using size_type = decltype(MaxSize);
private:
  array<T, MaxSize> elems;
  size_type numElems;
public:
  stack() : numElems {0} {}
  void push(T const &);
  void pop();
  T const & top() const;
  bool empty() const {
    return numElems == 0;
  }
  auto size() const {
    return numElems;
  }
  //stack(stack const &s) : elems {s.elems} {}
  stack & operator=(stack const &s) {
    elems = s.elems;
    return *this;
  }

  // method 2
  template <typename U, auto MaxUElems>
  friend std::ostream & operator<<(std::ostream & strm, stack<U, MaxUElems> const & s);

};


template <typename T, auto MaxElems>
void stack<T, MaxElems>::push(T const & elem) {
  assert(numElems < MaxElems);
  elems[numElems++] = elem;
}

template <typename T, auto MaxElems>
void stack<T, MaxElems>::pop() {
  assert(!elems.empty());
  --numElems;
}

template <typename T, auto MaxElems>
T const & stack<T,  MaxElems>::top() const {
  assert(!elems.empty());
  // returns the value at emes[MaxSize - 1]
  // which is not we intend to seek
  // return elems.back();
  return elems[numElems - 1];
}

// method 2
template <typename U, auto MaxUElems>
std::ostream & operator<<(std::ostream & strm, stack<U, MaxUElems> const & s) {
  for (auto const & e : s.elems) {
    strm << e << '\n';
  }
  return strm;
}

int main() {
  stack<int, 20u> s20i;
  s20i.push(30);
  cout << s20i;
  auto s20i_s = s20i.size();

  stack<string, 10> s10s;
  s10s.push("hello");
  cout << s10s;
  auto s10s_s = s10s.size();

  cout <<
      type_print_pretty<decltype(s20i_s)>() << endl <<
      type_print_pretty<decltype(s10s_s)>() << endl;
}
