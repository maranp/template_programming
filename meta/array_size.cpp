/*
 * array_szize.cpp
 *
 *  Created on: 05-Aug-2018
 *      Author: maran
 */

#include <iostream>
#include "../ihelper.h"

template <typename T, size_t N>
constexpr auto ARRAY_SIZE(const T (&)[N]) {
    return N;
}

template <typename T, size_t N = 0>
struct extent {
  static constexpr size_t value = N;
};

template <typename T>
struct extent<T, 0> {
  static constexpr size_t value = 0;
  static_assert(value != 0, "not array");
};

template <typename T, size_t N>
struct extent<T[N], 0> {
  static constexpr size_t value = N;
  static_assert(N != 0, "not array");
};

template <typename T, size_t N = extent<std::remove_reference_t<T>>::value>
static constexpr auto get_size() {
  static_assert(N != 0, "get_size: not array");
  return N;
}

struct S {
    int a[42];
};

int main() {
    S *sp = nullptr;
    ARRAY_SIZE(sp->a);
    //static_assert(ARRAY_SIZE(sp->a) == 42);
    //return sizeof(sp->a);

    cout << extent<decltype(sp->a)>::value << endl;

    int a[42];
    cout << extent<decltype(a)>::value << endl;

//    int (&b)[42] = a;
//    cout << extent<decltype(b)>::value << endl;

    int (&b)[42] = a;
    cout << extent<std::remove_reference_t<decltype(b)>>::value << endl;
    cout << get_size<decltype(b)>() << endl;
}

