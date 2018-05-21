/*
 * tag_dispatch.cpp
 *
 *  Created on: 21-May-2018
 *      Author: maran
 */

#include "../ihelper.h"

template <typename Iterator, typename Distance>
void advance_iter_impl(Iterator& it, Distance n, std::input_iterator_tag) {
  cout << "input" << endl;
  while (n--) {
    it++;
  }
}

template <typename Iterator, typename Distance>
void advance_iter_impl(Iterator& it, Distance n, std::random_access_iterator_tag) {
  cout << "random" << endl;
  it += n;
}

template <typename Iterator, typename Distance>
void advance_iter(Iterator& it, Distance n) {
  advance_iter_impl(it, n, typename std::iterator_traits<Iterator>::iterator_category{});
}

template <typename Iterator>
constexpr bool is_random_acc_it =
std::is_convertible_v<typename std::iterator_traits<Iterator>::iterator_category, std::random_access_iterator_tag>;

template <typename Iterator>
constexpr bool is_bidirectional_it =
std::is_convertible_v<typename std::iterator_traits<Iterator>::iterator_category, std::bidirectional_iterator_tag>;

// using enable_if
template <typename Iterator, typename Distance>
std::enable_if_t<is_random_acc_it<Iterator>>
advance_iter_1(Iterator& it, Distance n) {
  cout << "random" << endl;
  it += n;
}

template <typename Iterator, typename Distance>
std::enable_if_t<is_bidirectional_it<Iterator> && !is_random_acc_it<Iterator>>
advance_iter_1(Iterator& it, Distance n) {
  cout << "bidirectional" << endl;
  if (n < 0) {
    while (n++) {
      it--;
    }
  } else {
    while (n--) {
      it++;
    }
  }
}

template <typename Iterator, typename Distance>
std::enable_if_t<!is_random_acc_it<Iterator> && !is_bidirectional_it<Iterator>>
advance_iter_1(Iterator& it, Distance n) {
  if (n < 0) {
    throw("input_iterator invalid for negative advancement");
  }
  cout << "input" << endl;
  while (n--) {
    it++;
  }
}

// using if constexpr
template <typename Iterator, typename Distance>
void advance_iter_2(Iterator& it, Distance n) {
  cout << "if constexpr" << endl;
  if constexpr (is_random_acc_it<Iterator>) {
    cout << "random" << endl;
    it += n;
  } else if constexpr (is_bidirectional_it<Iterator>) {
    cout << "bidirectional" << endl;
    if (n < 0) {
      while (n++) {
        it--;
      }
    } else {
      while (n--) {
        it++;
      }
    }
  } else {
    if (n < 0) {
      throw("input_iterator invalid for negative advancement");
    }
    cout << "input" << endl;
    while (n--) {
      it++;
    }
  }
}

int main() {
  {
  vector<int> vi {0, 1, 2, 3, 4, 5};
  auto it = begin(vi);
  advance_iter(it, 2);
  cout << *it << endl;
  }
  {
  list<int> li {0, 1, 2, 3, 4, 5};
  auto lit = begin(li);
  advance_iter(lit, 2);
  cout << *lit << endl;
  }
  {
    vector<int> vi {0, 1, 2, 3, 4, 5};
    auto it = begin(vi);
    advance_iter_1(it, 2);
    cout << *it << endl;
    advance_iter_1(it, -1);
    cout << *it << endl;
  }
  {
    list<int> li {0, 1, 2, 3, 4, 5};
    auto lit = begin(li);
    advance_iter_1(lit, 2);
    cout << *lit << endl;
    advance_iter_1(lit, -1);
    cout << *lit << endl;
  }
  {
    vector<int> vi {0, 1, 2, 3, 4, 5};
    auto it = begin(vi);
    advance_iter_2(it, 2);
    cout << *it << endl;
    advance_iter_2(it, -1);
    cout << *it << endl;
  }
  {
    list<int> li {0, 1, 2, 3, 4, 5};
    auto lit = begin(li);
    advance_iter_2(lit, 2);
    cout << *lit << endl;
    advance_iter_2(lit, -1);
    cout << *lit << endl;
  }
}



