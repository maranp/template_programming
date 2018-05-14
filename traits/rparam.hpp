#pragma once

#include "../ihelper.h"

template <typename T>
struct RParam {
  using type = std::conditional_t<
      (sizeof(T) <= 2 * sizeof(void *))
      && std::is_trivially_copy_constructible<T>::value
      && std::is_trivially_move_constructible<T>::value,
      T, T const&>;
};

