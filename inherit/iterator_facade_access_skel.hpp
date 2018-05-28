#pragma once

class Iterator_Facade_Access {
  template <typename Derived, typename Value, typename Category,
  typename Reference = Value&, typename Distance = std::ptrdiff_t>
  friend class Iterator_Facade;

  // all the interfaces are private
  // since Iterator_Facade is friend, it has access to the interfaces
  template <typename Reference, typename Iterator>
  static Reference dereference(Iterator const& i) {
    // Iterator should declare Iterator_Facade_Access as friend
    // so as to access its private members here
    return i.dereference();
  }
  template <typename Iterator>
  static void increment(Iterator& i) {
    return i.increment();
  }
};
