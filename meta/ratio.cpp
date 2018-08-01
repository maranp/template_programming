/*
 * ratio.cpp
 *
 *  Created on: 27-Jul-2018
 *      Author: maran
 */

#include "../ihelper.h"

// Ratio<N, D> is a type. The type can be generated for
// each fraction N/D
// What's its purpose?
// When talking about duration where the basic unit is seconds,
// a duration variable, say d, being attached to a type Ratio<N, D>
// means its value is d * (N/D) seconds
template <unsigned N, unsigned D = 1>
struct Ratio {
  static constexpr unsigned num = N;
  static constexpr unsigned den = D;
  using type = Ratio<num, den>;
};

// think about addition of 2 durations with different ratios
// what's the ratio of the resultant duration?
// 1 min + 1 ms = 60s + 1/1000s = 60001/1000s
// 1 60/1 + 1 1/1000 = 1 (60/1 + 1/1000) =1 ((60 * 1000 + 1 * 1) / 1 * 1000))
// Ratio<60, 1> + Ratio<1, 1000> = Ratio<(60 * 1000 + 1 * 1), 1 * 1000>

template <typename R1, typename R2>
struct RatioAddImpl {
private:
  static constexpr unsigned num = (R1::num * R2::den) + (R2::num * R1::den);
  static constexpr unsigned den = (R1::den * R2::den);
public:
  using type = Ratio<num, den>;
};

template <typename R1, typename R2>
using RatioAdd = typename RatioAddImpl<R1, R2>::type;

// Duration is the object to hold time quantity
// the value is stored as int or float or ...
// the basic unit is second
// but how should the value be interpreted is
// dictated by the associated unittype which is nothing but
// the fraction (or ratio) of second
// the default fraction is 1 (Ratio<1>) which corresponds to second as unit.
template <typename T, typename U = Ratio<1>>
struct Duration {
  using ValueType = T;
  using UnitType = U;
  constexpr Duration(T val_) : val {val_} {}
  constexpr ValueType value() const {
    return val;
  }
private:
  T val;
};

// lhs = <x, 1/1000>
// rhs = <y, 2/3>
// lhs + rhs = 1.x/1000 + 2.y/3
// = (3.1.x + 2.1000.y)/3000
template <typename T1, typename U1,
typename T2, typename U2>
auto operator+(Duration<T1, U1> lhs, Duration<T2, U2> rhs) {
  auto resultant_value = U2::den * U1::num * lhs.value() + U2::num * U1::den * rhs.value();
  return Duration<decltype(resultant_value), Ratio<1, U1::den * U2::den>> {
    resultant_value
  };
}

int main() {
  using R1 = Ratio<1, 1000>;
  using R2 = Ratio<60, 1>;
  using RS = RatioAdd<R1, R2>;

  cout << RS::num << "/" << RS::den << "\n";
}
