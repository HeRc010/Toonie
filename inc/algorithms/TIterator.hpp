#ifndef __TITERATOR_HPP__
#define __TITERATOR_HPP__

/*
   This isn't as secure as I'd like it to be; should be pure virtual but some methods need to return an instance of a subclass of the iterator class.
   So the compiler won't allow a function to return an instance of an abstract class.
   Temporary solution to make the constructor private and let functions be virtual not pure virtual, still not completely safe; allows subclasses to not override certain functions.
   One workaround would be to implement the functions in the base class but throw exceptions in the implementations indicating that the functions shouldn't be called, and/or cause seg faults.
*/

#include <iostream>

template <typename T> class TIterator
{
   public:
      TIterator() {}
      ~TIterator() {}

      // uneeded; overload increment instead
      // virtual TIterator<T> next() const;

      virtual T get() const {}

      virtual bool operator==(const TIterator &rhs) const { std::cout << "iterator.. :S" << std::endl; }
      virtual bool operator!=(const TIterator &rhs) const {}
      // virtual TIterator<T> operator++() const { std::cout << "base iterator.. :S" << std::endl; }
      virtual TIterator<T>& operator++() { std::cout << "base iterator.. :S" << std::endl; }
};

// base class implementations shouldn't be called
// ...

#endif //__TITERATOR_HPP__
