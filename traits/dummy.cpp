/*
 * dummy.cpp
 *
 *  Created on: 23-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T, typename = std::void_t<>>
struct has_size_type : std::false_type {};

template <typename T>
struct has_size_type<T, std::void_t<typename std::remove_reference_t<T>::size_type>> : std::true_type {};

struct S {
  using size_type = int;
};

template <typename T, typename = std::void_t<>>
struct has_begin_t : std::false_type {};

template <typename T>
struct has_begin_t<T, std::void_t<decltype(declval<T>().begin())>> : std::true_type {};


int main() {
  cout << boolalpha;
  cout << has_size_type<int>::value << endl;
  cout << has_size_type<S>::value << endl;
  cout << has_size_type<S&>::value << endl;

  cout << has_begin_t<vector<int>>::value << endl;
  cout << has_begin_t<S>::value << endl;
}
