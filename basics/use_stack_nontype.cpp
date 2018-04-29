/*
 * use_stack_nontype.cpp
 *
 *  Created on: 28-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "stacknontype.hpp"

int main() {
  stack<int> si;
  si.push(7);
  cout << si.top() << endl;
  stack<string, 2> ss;
  ss.push("hello");
  ss.push("world");
  cout << ss.top() << endl;

  cout << ss;

  stack<int *> sip;
  int x = 10;
  sip.push(&x);
  int *y = new int {10};
  sip.push(y);
  cout << sip;
  //delete sip.pop();
  cout << *sip.top() << endl;


}
