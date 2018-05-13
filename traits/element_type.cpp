/*
 * element_type.cpp
 *
 *  Created on: 12-May-2018
 *      Author: maran
 */

#include "element_type.hpp"

int main() {
  cout <<
  type_print_pretty<element_type<vector<float>>::type>() << endl;
  cout <<
    type_print_pretty<element_type<int[5]>::type>() << endl;
  cout <<
      type_print_pretty<element_type<int[]>::type>() << endl;
  int x[5];
  cout <<
        typeid(x).name() << endl;

}


