/*
 * use_boolstring.cpp
 *
 *  Created on: 30-Apr-2018
 *      Author: maran
 */

#include "boolstring.hpp"

int main() {
  boolstring b {"hello"};
  cout << boolalpha;
  cout << b.get() << endl;
  cout << b.get<bool>() << endl;
  boolstring b1 {"true"};
  cout << b1.get<bool>() << endl;
}


