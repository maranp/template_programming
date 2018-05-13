#pragma once

#include "accumtraits4.hpp"
#include "sumpolicy1.hpp"
#include "multpolicy1.hpp"

template <typename T,
typename Policy = SumPolicy,
typename TTraits = AccuTrait<T>>
auto accum8(T const* begin, T const* end) {
  typename TTraits::AccT result {TTraits::zero()};
  while (begin != end) {
    // if Policy is multpolicy, accumulation is 0
    // as result is initialized with zero
    // problem is AccuTrait doesn't know about the operation policy
    Policy::accumulate(result, *begin);
    begin++;
  }
  return result;
}
