/*
 * use_stack3.cpp
 *
 *  Created on: 26-Apr-2018
 *      Author: maran
 */

#include "../ihelper.h"

#include "stack3.hpp"


int main() {
  stack<int> si;
  si.push(7);
  cout << si.top() << endl;
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

  stack<double, deque<double>> sd;
  sd.push(5.5);
  sd.push(6.5);
  cout << sd;

}


