#pragma once

#include "accumtraits4.hpp"
#include "sumpolicy2.hpp"

template <typename T,
template <typename, typename>
class Policy = SumPolicy,
typename TTraits = AccuTrait<T>>
auto accum9(T const* begin, T const* end) {
  using AccT = typename TTraits::AccT;
  AccT result {TTraits::zero()};
  while (begin != end) {
    // if Policy is multpolicy, accumulation is 0
    // as result is initialized with zero
    // problem is AccuTrait doesn't know about the operation policy
    Policy<AccT, T>::accumulate(result, *begin);
    begin++;
  }
  return result;
}
