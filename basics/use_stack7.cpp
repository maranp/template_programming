/*
 * use_stack6.cpp
 *
 *  Created on: 30-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "stack7decl.hpp"


int main() {
  stack<int> si;
  si.push(7);
  si.push(77);
  cout << si;

  stack<float> sf;
  sf = si;
  cout << sf;

  stack<string> ss;
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





