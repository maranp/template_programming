/*
 * main.cpp
 *
 *  Created on: 24-Apr-2018
 *      Author: maran
 */

#include "stack.hpp"
#include "stack1.hpp"
#include "stack_part_spec.hpp"
#include "../ihelper.h"
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
  delete sip.pop();
  cout << *sip.top() << endl;
}

