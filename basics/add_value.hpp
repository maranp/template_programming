#pragma once

template<int Val, typename T>
T add_value(T x) {
  return Val + x;
}

// ensure the type of parameter variable passed is
// same as that of the non-type parameter
// passed to function template
template <auto Val, typename T = decltype(Val)>
T add_value_1(T x) {
  return Val + x;
}

// same as above but with a subtle difference
// ensure the type of the non-type parameter
// is same as the parameter variable passed to the function
template <typename T, T Val = T {}>
T add_value_2(T x) {
  return Val + x;
}
