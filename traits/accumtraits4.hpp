#pragma once

template <typename T>
struct AccuTrait;

template <>
struct AccuTrait<char> {
  using AccT = int;
  static constexpr AccT zero() {
    return 0;
  }
};

template <>
struct AccuTrait<int> {
  using AccT = long;
  static constexpr AccT zero() {
    return 0l;
  }
};

template <>
struct AccuTrait<unsigned int> {
  using AccT = unsigned long;
  static constexpr AccT zero() {
    return 0ul;
  }
};

template <>
struct AccuTrait<float> {
  using AccT = double;
  static constexpr AccT zero() {
    return 0.;
  }
};

template <>
struct AccuTrait<double> {
  using AccT = double;
  static constexpr AccT zero() {
    return 0.;
  }
};

struct BigInt {
  BigInt(long long l) : ll {l} {}
  long long operator+=(BigInt other) {
    return ll + other.ll;
  }
private:
  long long ll;
};

template <>
struct AccuTrait<BigInt> {
  using AccT = BigInt;
  static AccT zero() {
    return BigInt{0};
  }
};

template <typename T>
auto accum(T* start, T* end) {
  typename AccuTrait<T>::AccT result {AccuTrait<T>::zero()};
  while (start != end) {
    result += *start;
    start++;
  }
  return result;
}
