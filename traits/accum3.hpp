#pragma once

// for context goto accum1.hpp

template <typename T>
struct AccuTrait {
  using AccT = T;
  static constexpr T zero = T{};
};

template <>
struct AccuTrait<char> {
  using AccT = int;
  static constexpr AccT zero = 0;
};

template <>
struct AccuTrait<int> {
  using AccT = long;
  static constexpr AccT zero = 0l;
};

template <>
struct AccuTrait<unsigned int> {
  using AccT = unsigned long;
  static constexpr AccT zero = 0ul;
};

template <>
struct AccuTrait<float> {
  using AccT = double;
  static constexpr AccT zero = 0.;
};

struct BigInt {
  BigInt(long long l) : ll {l} {}
  long long operator+=(BigInt other) {
    return ll + other.ll;
  }
private:
  long long ll;
};

// assigning, to const or consexpr of a type which is a
// non-literal type -
// a type which has to allocate stuff in the heap
// or if the constructor of the type is not a constexpr
//./accum3.hpp:48:25: error: constexpr variable cannot have non-literal type
// 'const AccuTrait<BigInt>::AccT' (aka 'const BigInt')
//  static constexpr AccT zero = BigInt{0};
// ./accum3.hpp:35:8: note: 'BigInt' is not literal because
// it is not an aggregate and has no constexpr constructors other than copy or move constructors
// intialization is not possible only for static const data member inside the class
// so a declaration here and definition in a .cpp will do the trick
// in .cpp file it looks like
// BigInt const AccuTrait<BigInt>::zero = BigInt{0};
// drawback? definition in other files are not known to compilers and
// hence could produce less optimal code

//template <>
//struct AccuTrait<BigInt> {
//  using AccT = BigInt;
//  static constexpr AccT zero = BigInt{0};
//};

// solution?
// simple, add inline and change constexpr to const in the static member
// if BigInt has constexpr constructor, constexpr can be kept unchanged.
// this works from c++17. what to do in ealier versions?
//template <>
//struct AccuTrait<BigInt> {
//  using AccT = BigInt;
//  inline static const AccT zero = BigInt{0};
//};

//template <typename T>
//auto accum4(T* start, T* end) {
//  // 0 for built-in types
//  // false for bool
//  // nulptr if T is a pointer type
//  typename AccuTrait<T>::AccT result {AccuTrait<T>::zero};
//  while (start != end) {
//    result += *start;
//    start++;
//  }
//  return result;
//}

template <>
struct AccuTrait<BigInt> {
  using AccT = BigInt;
  static AccT zero() {
    return BigInt{0};
  }
};

// all T except BigInt
template <typename T, typename = std::enable_if_t<!std::is_same_v<std::decay_t<T>, BigInt>>>
auto accum5(T* start, T* end) {
  // 0 for built-in types
  // false for bool
  // nulptr if T is a pointer type
  typename AccuTrait<T>::AccT result {AccuTrait<T>::zero};
  while (start != end) {
    result += *start;
    start++;
  }
  return result;
}

// when T is BigInt
template <typename T>
auto accum5(T* start, T* end) {
  // 0 for built-in types
  // false for bool
  // nulptr if T is a pointer type
  typename AccuTrait<T>::AccT result {AccuTrait<T>::zero()};
  while (start != end) {
    result += *start;
    start++;
  }
  return result;
}
