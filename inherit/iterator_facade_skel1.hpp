#pragma once

#include "../ihelper.h"
#include "iterator_facade_access_skel.hpp"

// adapts CRTP
// base class, the facade, defines the iterator interface
// mainly maps the iterator syntax to the iterator(derived type)'s minimal interface
template <typename Derived, typename Value, typename Category,
typename Reference = Value&, typename Distance = std::ptrdiff_t>
class Iterator_Facade {
  // we have to define iterator's typical interfaces
  // by calling the derived's (actual iterator) minimal interface
  // For this, we need a handle to the derived object (Actual iterator)
  // let's write a helper to get the handle of the derived.
  Derived& as_derived() {
    return *(static_cast<Derived*>(this));
  }
  Derived const& as_derived() const {
    return *(static_cast<Derived const*>(this));
  }

public:
  // dereferencing iterator should return the value (as reference)
  Reference operator*() const {
    return Iterator_Facade_Access::dereference(as_derived());
  }

  // incrementing the iterator should yield the next position (iterator)
  Derived& operator++() {
    Iterator_Facade_Access::increment(as_derived());
    return as_derived();
  }

//  friend bool operator==(Iterator_Facade const& lhs, Iterator_Facade const& rhs) {
//    return as_derived().equals(rhs.as_derived());
//  }
};
