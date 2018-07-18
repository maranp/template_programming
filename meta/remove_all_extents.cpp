/*
 * remove_all_extents.cpp
 *
 *  Created on: 15-Jul-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T>
struct remove_all_extents {
  using type = T;
};

template <typename T, size_t SZ>
struct remove_all_extents<T[SZ]> {
  using type = typename remove_all_extents<T>::type;
};

template <typename T>
struct remove_all_extents<T[]> {
  using type = typename remove_all_extents<T>::type;
};

template <typename T>
using remove_all_extents_t = typename remove_all_extents<T>::type;

template <typename T>
struct foo {
  foo() {
    cout << "foo<T>" << endl;
  }
};

template <typename T>
struct foo<T[]> {
  foo() {
    cout << "foo<T[]>" << endl;
  }
};

template <typename T, size_t SZ>
struct foo<T[SZ]> {
  foo() {
    cout << "foo<T[" << SZ << "]>" << endl;
  }
};

int main() {
  foo<int> f1; // foo<T>
  foo<int[0]> f4; // foo<T>
  foo<int[0][2]> f6; // foo<T>

  foo<int[]> f2; // foo<T[]>
  foo<int[][2]> f7; // foo<T[]>

  foo<int[32]> f3; // foo<T[SZ]>
  foo<int[2][2]> f5; // foo<T[SZ]>
  foo<int[2][2][2]> f8; // foo<T[SZ]>

  cout << type_print_pretty<remove_all_extents_t<int[2][2][2]>>() << endl;
  cout << type_print_pretty<int[2][2][2]>() << endl;
  cout << type_print_pretty<decltype(f8)>() << endl;

  // foo<int[][]> f8; compile error; incomeplete type
  // foo<int[2][]> f9; compile error; incomeplete type
}
