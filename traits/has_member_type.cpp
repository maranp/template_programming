/*
 * has_member_type.cpp
 *
 *  Created on: 16-May-2018
 *      Author: maran
 */

#include <type_traits>
#include "../ihelper.h"

template <typename T, typename = std::void_t<>>
struct has_type_member_sz_t : std::false_type {};

template <typename T>
struct has_type_member_sz_t<T, std::void_t<typename T::size_type>>
    : std::true_type {};

struct size_type {};
struct sz_derived : size_type {};

int main() {
    static_assert(has_type_member_sz_t<sz_derived>::value,
        "compiler failed to recog. base type as a member type");
    cout << boolalpha <<
        has_type_member_sz_t<int>::value << endl;

    //DEF_HAS_MEMBER(value_type);

}



