#pragma once

// problem: if its char array,
// the result being char type will
// most probably overflow
template <typename T>
T accum1(T* start, T* end) {
  // 0 for built-in types
  // false for bool
  // nulptr if T is a pointer type
  T result = T{};
  while (start != end) {
    result += *start;
    start++;
  }
  return result;
}

// problem: caller has to find the correct
// return type for the given array type
// and the call with return type specified
// accum2<int>(char*, char*);
// accum2<long>(int*, int*);
template <typename RT, typename T>
RT accum2(T* start, T* end) {
  // 0 for built-in types
  // false for bool
  // nulptr if T is a pointer type
  RT result = RT{};
  while (start != end) {
    result += *start;
    start++;
  }
  return result;
}


// we want the user to avoid
// detecting what should be the accumulation type
// of the given array type.
// each type(T) (of array) has an appropriate accumulation type(AccT)
// we call AccT the accumulation trait of the type T

// primary template is best left undefined
// useful to be defined when T is double
// but cannot be a sensible default for all types.
template <typename T>
struct AccuTrait {
  using AccT = T;
};

template <>
struct AccuTrait<char> {
  using AccT = int;
};

template <>
struct AccuTrait<int> {
  using AccT = long;
};

template <>
struct AccuTrait<unsigned int> {
  using AccT = unsigned long;
};

template <>
struct AccuTrait<float> {
  using AccT = double;
};

template <typename T>
auto accum3(T* start, T* end) {
  // 0 for built-in types
  // false for bool
  // nulptr if T is a pointer type
  typename AccuTrait<T>::AccT result {};
  while (start != end) {
    result += *start;
    start++;
  }
  return result;
}

// we still assume T{} will give zero value
// for all T (which may not be true beyond primitive types
// lets add zero value for the types in its traits structure
// go to accum3.hpp
