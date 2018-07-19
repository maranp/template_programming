/*
 * dot_product.cpp
 *
 *  Created on: 19-Jul-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T, size_t N>
struct dot_product {
  static inline T result(T const* a, T const* b) {
    return *a * *b + dot_product<T, N - 1>::result(a + 1, b + 1);
  }
};

template <typename T>
struct dot_product<T, 0> {
  static inline T result(T const* a, T const* b) {
    return T {};
  }
};

template <typename T, size_t N>
auto dotproduct(array<T, N> const& a1, array<T, N> const& a2) {
  return dot_product<T, N>::result(begin(a1), begin(a2));
}

int main() {
  array<int, 3> a {1, 2, 3};
  array<int, 3> b {1, 2, 3};
  cout << dotproduct(a, b) << endl;
}
