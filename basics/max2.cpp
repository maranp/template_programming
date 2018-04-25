/*
 * max2.cpp
 *
 *  Created on: 23-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

int max(int a, int b) {
  cout << "max(int, int)" << endl;
  return a > b ? a : b;
}

template <typename T>
T max(T a, T b) {
  cout << "max<" << type_print_pretty<T>() << ">(a, b)" << endl;
  return a > b ? a : b;
}

int main() {
  ::max(5, 7);
  ::max<>(5, 7);
  ::max<double>(5, 7);
  ::max(5.1, 7.2);
  // automatic type conversion is considered for non-template functions
  // ,so char and double are converted to int of non-template function
  ::max('a', 7.2);
  // we force template function to be used and when argument types are deduced to be
  // char and double, abd automatic type conversion is not considered for template functions
  // the next line fails to compile
  //::max<>('a', 7.2);


}



