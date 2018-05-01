/*
 * use_stack8.cpp
 *
 *  Created on: 01-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "stack8decl.hpp"


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

  stack<int, vector> siv;
  siv.push(34);
  cout << siv;

  stack<float, vector> sfv;
  sfv = siv;
  sfv.push(3.4);
  cout << sfv;


}




