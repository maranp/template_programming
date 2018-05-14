#pragma once

template <typename T1, typename T2>
struct is_same0 {
  static constexpr bool value = false;
};

template <typename T>
struct is_same0<T, T> {
  static constexpr bool value = true;
};

// the above works, solves the purpose
// but if we want to resolve overload of two functions
// for eg:
// f(T, is_same<T, int>)
// => call version of f when T is int
//    and call another version of f when T is not int
// the overload resolution is not possible with above implementation
// because, the type is_same<T,int> is same irrespective of what type T is
// but in the below implementation, is_same<T, int> effectively becomes TrueType
// when T is int and becomes FalseType otherwise
// so, f(t, is_same<T, int>) resolves to f(T t, TrueType) when T is int
// and resolves to f(T t, FalseType) when T is not int,
// besides providing the original purpose, ie is_same<T, int>::value
// indicates equality of T and int
// the techinqie is called tag dispatching
// look at the illustration of base class resolution for derived class parameter
// in is_same1.cpp
// for this reason, in general, the traits (class templates) that
// yield boolean values (predicate traits) should derive from std::true_type and std::false_type

template <bool val>
struct BoolType {
  static constexpr bool value = val;
};

using TrueType = BoolType<true>;
using FalseType = BoolType<false>;

template <typename T1, typename T2>
struct is_same1 : FalseType {};

template <typename T>
struct is_same1<T, T> : TrueType {};
