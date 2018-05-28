#pragma once

template <typename CountedType>
struct ObjectCounter {
private:
  // the count here tracks all instances of ObjectCounter<CountedType>
  // So, ObjectCounter<MyClass> can count instances of ObjectCounter<MyClass>
  // We actually want to count the instances of MyClass.
  // There will be once instance of ObjectCounter<MyClass> for each MyClass instance
  // if MyClass inherits ObjectCounter<MyClass>.
  // So, if a class (MyClass) depends on a property pertaiting to the type ObjectCounter<T>
  // use, Curiously Recurring Template Pattern (CRTP)
  inline static size_t count = 0;
public:
  ObjectCounter() { count++; }
  ObjectCounter(ObjectCounter const&) {
    count++;
  }
  ObjectCounter(ObjectCounter&&) {
    count++;
  }
  ~ObjectCounter() {
    count--;
  }
  // static member function can be called both ways
  // 1. obj.live() 2. class::live()
  // static member function cannot have const qualifier
  inline static size_t live() {
    return count;
  }
};
