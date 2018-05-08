/*
 * cref.cpp
 *
 *  Created on: 08-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

void print_string(string const& s) {
  cout << s << endl;
}

template <typename T>
void printT(T arg) {
  print_string(arg);
}

bool is_str_less(string const& t1, string const& t2) {
  return t1 < t2;
}

template <typename T1, typename T2>
bool is_less(T1 t1, T2 t2) {
  return is_str_less(t1, t2);
}

int main() {
  string s = "hi";
  printT(s);

  // created object of
  // std::reference_wrapper<string const>(s)
  // and passed to printT
  printT(cref(s));

  string s1 = "hello";
  cout << boolalpha <<
  is_less(cref(s1), cref(s))
  << endl;;

}
