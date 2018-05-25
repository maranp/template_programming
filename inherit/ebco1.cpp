/*
 * ebco1.cpp
 *
 *  Created on: 25-May-2018
 *      Author: maran
 */
#include "../ihelper.h"

class EmptyBase {
  using Int = int; // still empty
};

// still empty due to empty base class optimization
class EmptyTwo : EmptyBase {};
// still empty due to EBCO
class EmptyThree : EmptyTwo {};

int main() {
  cout << sizeof(EmptyBase) << endl;
  cout << sizeof(EmptyTwo) << endl;
  cout << sizeof(EmptyThree) << endl;
}



