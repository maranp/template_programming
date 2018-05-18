/*
 * check_fn_param.cpp
 *
 *  Created on: 17-May-2018
 *      Author: maran
 */

#include "../ihelper.h"
#include "is_valid.hpp"

int main() {

  cout << type_print_pretty<decltype(value_of_type_t(type_t<float>{}))>() << endl;
  cout << type_print_pretty<decltype(value_of_type_t(type_val<float>))>() << endl;
  //cout << type_print_pretty<decltype((void)decltype(value_of_type_t(type_val<double>)))>() << endl;



  cout << boolalpha;

  // a type trait checker essentially wants a type to be passed.
  // since is_def_ctorble is a lambda, type cannot be passed directly, but
  // a value of the type has to be passed.
  // is_def_ctorble(type_val<int>) could infact be called like
  // is_def_ctorble(5) // some int value
  // and auto x, the argument x of is_def_ctorble lambda will be rightly detected as type int
  // however, if the type to be examined is a class type, is_def_ctorble needs to be passed
  // by, at least a default constucted object of that class type.
  // passing a def. constucted object to a lambda that checks whether they type is default constuctible
  // is self defeating. we need a better approach to handle all cases.
  // we wantro pass value(object) from which the type can be deduced without taking the above mentioned pains.
  // the answer is type_t<T> which is a class template that just wraps T and do nothing else
  // it can be default constucted with any type.
  // so, the lambda f which expectst the type to be passed expects type_t<T> and ripps of T from that object
  cout << is_def_ctorble(type_val<int>) << endl;
  cout << is_def_ctorble(type_val<int&>) << endl;

  // f passed to is_valid is /* sfinae'sed and */ captured in returned lambda
  // returned lambda takes the argument, sfinae'ses f and checkes f(arg) is valid.
  cout << is_valid([](auto x) -> decltype((void)decltype(value_of_type_t(x))()) {})(type_val<double>) << endl;

  constexpr auto has_first = is_valid([](auto x) -> decltype((void) value_of_type_t(x).first) {});
  cout << has_first(type_val<std::pair<int,int>>) << endl;
}
