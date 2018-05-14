#pragma once


template <typename T>
struct is_default_constructible {
private:
  // this test function will be defined only if 2nd template argument is sensible
  // so, the condition of interest for this trait template should go here
  // rest of the things form the framework
  template <typename U, typename = decltype(U())>
  static char test(void *);
  // the fallback function
  // could either be a plain member function
  // or a member function template as below
  // here a memeber function template is required
  // because the test overload is called explicitly with
  // type specialization. so, if the fallback is not a template
  // it wont participate in overload resolution
  template <typename U>
  static long test(...);
public:
  // test is defined with return type char
  // only if T satisfies a template argument condition to char test<T>(void *)
  static constexpr bool value = std::is_same<decltype(test<T>(nullptr)), char>::value;
};


// stare at this one
// is_same is a predicate trait
// predicate traits should derive from true_type or false_type
// for the reasons discussed in is_same0.hpp
// with is_same, the predicate (are types equal?) is derivable
// from template specialization resolution.
// so is_same can be directly derived from true_type or false_type
// based on template specialization resolution
template <typename T1, typename T2>
struct is_same2 : std::false_type {};

template <typename T>
struct is_same2<T, T> : std::true_type {};

// but for predicates likes is_default_construtible,
// the predicate cannot be (or difficult to be)
// resolved just in template specialization resolution
// so, instead of deriving from true_type or false_type
// lets derive from a helper trait which provides true/false_type
// based on T.

// take 2
// instead of using char and long to distinguish
// which test() overload succeeded, lets use
// true_type and false_type
template <typename T>
struct is_default_constructible1 {
private:
  template <typename U, typename = decltype(U())>
  static std::true_type test(void *);
  template <typename U>
  static std::false_type test(...);
public:
  static constexpr bool value = std::is_same<decltype(test<T>(nullptr)), std::true_type>::value;
};

// take 3 make the hardwork done above as helper
template <typename T>
struct is_default_constructible_helper {
private:
  template <typename U, typename = decltype(U())>
  static std::true_type test(void *);
  template <typename U>
  static std::false_type test(...);
public:
  // type is true_type or false_type based on the
  // test() overload chose for the given type
  // here true_type test<T> is chose when T is def. constructible
  using type = decltype(test<T>(nullptr));
};

// use the helper to make is_def._construtible
// predicate trait to be effectively derived from true/fale_type
template <typename T>
struct is_default_constructible2 : is_default_constructible_helper<T>::type {};
