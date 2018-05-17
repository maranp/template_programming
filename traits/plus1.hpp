#pragma once

template <typename T1, typename T2>
struct plusresult {
  // issue 1: T1 and T2 should have default constructor for this expression to work
  // issue 2: Integer const operator+(Integer const&, Integer const&);
  // in this case, decltype will yield Integer const as result type which might not be intended
  // so, need remove_cv<remove_reference<plus_result<T1, T2>::type>> whenever the result type is used
  using type = decltype(T1() + T2());
};

// just declared but not defined
// used only in the context of decltype, sizeof
// where expression is not evaluated

// in short, use declval to get an expression of a given Type
// without having to construct(instantiate) an object of that type
// show_declval is an illustrative implementation of std::declval
template <typename T>
std::add_rvalue_reference_t<T> show_declval();

template <typename T1, typename T2>
struct plusresult {
  // issue 1: T1 and T2 should have default constructor for this expression to work
  // solution: use declval
  using type = decltype(std::declval<T1>() + std::declval<T2>());
};
