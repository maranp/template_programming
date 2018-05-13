/*
 * sizeof.cpp
 *
 *  Created on: 11-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename T>
struct TypeSize {
  constexpr static size_t value = sizeof(T);
};

int main() {
  cout << TypeSize<double>::value << endl;
}
