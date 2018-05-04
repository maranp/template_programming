/*
 * sfinae.cpp
 *
 *  Created on: 03-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

// foo<T>() is defined if enable_if_t has value defined. Else, foo<T> is not defined
// useful when a function call has many candidate function templates,
// sfinae can be used to filter one correct function template based on sfinae condition
template <typename T, typename = std::enable_if_t<(sizeof(T) > 4)>>
void foo() {
  cout << "foo()\n";
}

int main() {
  //foo<int>();
  foo<long>();
}


