/*
 * use_vprint.cpp
 *
 *  Created on: 28-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "../vprint.hpp"

template <typename Arg>
void l_vprint(Arg arg) {
  cout << arg << endl;
}

// Args is template parameter pack
// args is function parameter pack
template <typename Arg, typename... Args>
void l_vprint(Arg arg, Args... args) {
  cout << sizeof...(args) << endl;
  cout << sizeof...(Args) << endl;
  cout << arg << ' ';
  vprint(args...);
}

//template <typename... Args>
//void vprint_on_strm(Args&&... args) {
    // fold expression -> (... op args)
//  (... << args);
//  cout << endl;
//}

template <typename Arg, typename... Args>
void vprint_on_strm(Arg && out, Args&&... args) {
  // fold expression -> (init op ... op args)
  (out << ... << args);
  out << endl;
}

int main() {
  l_vprint(5.5, "hello", 50.56, 10u);
  vprint_on_strm(cout, 5.5, "hello", 50.56, 10u);
  vprint_space(5.5, "hello", 50.56, 10u);
  print_doubled(5.5, std::string {"hello"}, 50.56, 10u, complex<float> {2.2, 3.3});
  add_one_1(5.5, std::string {"hello"}, 50.56, 10u, complex<float> {2.2, 3.3});
  add_one(5.5, 50.56);

  vector vs {"zero", "one", "two", "three"};
  print_coll_indices(vs, 1, 3);
  print_coll_indices<0, 2>(vs);

  auto t = std::make_tuple<std::string, int, double>("hello", 5, 4.4);
  print_coll_indices(t, Indices<0, 2>());

}


