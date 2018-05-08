/*
 * container_size.cpp
 *
 *  Created on: 08-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

//template <typename T>
//void asize(T& arg) {
//  if(std::is_array<T>::value) {
//    cout << std::extent<T>::value << endl;
//  }
//}

// if asize is not called for array (for eg. called for vector), compilation error
// as std::extent_v<T> does not make sense for T other than an array
template <
typename T,
typename = std::enable_if_t<std::is_array<T>::value>
>
void asize(T& arg) {

  static_assert(std::is_array<T>::value);
  cout << std::extent<T>::value << endl;
}

int main() {
  int arr[4];
  asize(arr);
  char str[] = "hello";
  asize(str);

  // do not call array size for a vector
//  vector<int> v(5);
//  asize(v);

  return 0;
}


