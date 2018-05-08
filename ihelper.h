#pragma once

#include <algorithm>

#include <numeric>
// partial_sum

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include <array>
using std::array;

#include <tuple>
using std::tuple;

#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

#include <string>
using std::string;

#include <complex>
using std::complex;

using std::boolalpha;

#include <utility>
using std::move;
using std::forward;

#include <functional>
using std::cref;
using std::ref;

// print the container
auto cprint = [](auto const & c) {
  std::for_each(begin(c), end(c), [](auto const &e) {
    cout << e << " ";
  });
  cout << '\n';
};

// print the iterator range
auto iprint = [](auto && from, auto && to) {
  std::for_each(from, to, [](auto const &e) {
    cout << e << " ";
  });
  cout << '\n';
};

template <typename Arg>
void vprint(Arg arg) {
  cout << arg << endl;
}

template <typename Arg, typename... Args>
void vprint(Arg arg, Args... args) {
  cout << arg << ' ';
  vprint(args...);
}

#include <typeinfo>
#include <cxxabi.h>

template <typename T>
auto type_print_pretty() {
  auto status = 0;

  // To pacify leaksanitizer
  // ==9699==ERROR: LeakSanitizer: detected memory leaks
  std::string name {typeid(T).name()};
  return std::string {abi::__cxa_demangle(name.c_str(), nullptr, 0, &status)};
}

template <typename T>
auto type_print_raw() {

  // To pacify leaksanitizer
  // ==9699==ERROR: LeakSanitizer: detected memory leaks
  return std::string {typeid(T).name()};
}
