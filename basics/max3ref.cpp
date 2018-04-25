/*
 * max3ref.cpp
 *
 *  Created on: 23-Apr-2018
 *      Author: maran
 */

#include <string>
#include <cstring>
#include "../ihelper.h"

template <typename T>
T const & max(T const & a, T const & b) {
  return a > b ? a : b;
}


template <typename T>
T const & max(T const & a, T const & b, T const & c) {
  cout << type_print_pretty<T>() << endl;
  cout << type_print_pretty<decltype(a)>() << endl;
  return max(max(a, b), c);
}

char const * max(char const * a, char const * b, char const * c) {
  //return max(max(a, b), c);
  cout << "max(char const *..): " << type_print_pretty<decltype(a)>() << endl;
  return max<>(a, b, c);
}

template <typename T>
void f(T const & cpr) {
  cout << type_print_pretty<T>() << endl;
}

int main() {
  // T is int *
  // cpr is reference to const pointer to int
  int *x;
  f(x);

  // T is int [5]
  // cpr is reference to const int[5]
  int y[5];
  f(y);

  char const *p1 = "a";
  char const *p2 = "b";
  char const *p3 = "c";
  max(p1, p2, p3);
  char pp1[] = "a";
  char pp2[] = "b";
  char pp3[] = "c";
  max(pp1, pp2, pp3);
}
