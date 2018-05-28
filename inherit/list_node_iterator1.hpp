#pragma once

#include "list_node.hpp"
#include "iterator_facade_skel1.hpp"
#include "iterator_facade_access_skel.hpp"

template <typename T>
class list_node_iterator : public Iterator_Facade<list_node_iterator<T>, T, std::forward_iterator_tag> {
  list_node<T>* current = nullptr_t;
  friend class Iterator_Facade_Access;
public:
  bool equals(list_node_iterator const& rhs) const {
    return current == rhs.current;
  }
  list_node_iterator(list_node<T>* current) : current {current} {}
  // the following functions are used by Iterator_Facade
  // kind of the same class using its members fir its own use
  // which is supposed to be private
  // a digression: Iterator_Facade has to be inherited publicly here
  // as the public interfaces of Iterator_Facade should be public for list_node_iterator to be useful
  // and the derived type is just a template parameter of Iterator_Facade
  // so, if the interfaces of derived type has to be accessed from Iterator_Facade,
  // they have to be public.
  // so how to make the interfaces of derived type private?
  // a mediatory class, namely Iterator_Facade_Access class can be a friend of
  // both the derived and Iterator_Facade
  // so, the private interface of derived is accessible to the access class

private:
  T& deference() const {
    return current->value;
  }
  void increment() {
    current = current->next;
  }
};
