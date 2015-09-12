#ifndef __TDYNAMICARRAY_HPP__
#define __TDYNAMICARRAY_HPP__

#include "TContainer.hpp"

template <typename T> class TDynamicArray : public TContainer<T>
{
   T *array_;

public:
   TDynamicArray();
   TDynamicArray(const T &initial_array);

   ~TDynamicArray();

   bool contains(const T &item) const override;
};

#endif //__TDYNAMICARRAY_HPP__
