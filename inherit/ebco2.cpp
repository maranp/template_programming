/*
 * ebco2.cpp
 *
 *  Created on: 25-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

class EmptyBase {
  using Int = int;
};

class EmptyTwo : public EmptyBase {};
// size 2
class EmptyThree : public EmptyBase, public EmptyTwo {};

int main() {
  cout << sizeof(EmptyBase) << endl;
  cout << sizeof(EmptyTwo) << endl;
  cout << sizeof(EmptyThree) << endl;
}


