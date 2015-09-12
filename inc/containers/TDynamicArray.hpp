#ifndef __TDYNAMICARRAY_HPP__
#define __TDYNAMICARRAY_HPP__

#include "TContainer.hpp"

#define DEFAULT_CAPACITY 10

template <typename T> class TDynamicArray : public TContainer<T>
{
   T *array_;
   unsigned size_, capacity_;

   // double the capacity of the array
   void double_capacity();

public:
   TDynamicArray(unsigned initial_capacity = DEFAULT_CAPACITY);
   TDynamicArray(const T *initial_array, unsigned initial_capacity = DEFAULT_CAPACITY);

   ~TDynamicArray();

   bool contains(const T &item) const override;

   unsigned size() const override;

   void add_item(const T &item) override;

   void remove_item(const T &item) override;

   void clear() override;
};

#endif //__TDYNAMICARRAY_HPP__
