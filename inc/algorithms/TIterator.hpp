#ifndef __TITERATOR_HPP__
#define __TITERATOR_HPP__

#include <iostream>

class TIterator
{
   public:
      // Equality operators
      virtual bool operator==(TIterator& rhs) const = 0;
      bool operator!=(TIterator& rhs) const { return !this->operator==(rhs); }

      virtual bool operator==(const TIterator& rhs) const = 0;
      bool operator!=(const TIterator& rhs) const { return !this->operator==(rhs); }

      // Increment operators
      virtual const TIterator& operator++() const = 0;
};

#endif //__TITERATOR_HPP__
