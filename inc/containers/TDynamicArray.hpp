#ifndef __TDYNAMICARRAY_HPP__
#define __TDYNAMICARRAY_HPP__

#include "TContainer.hpp"

/*
   Fix pointer uses; there need to be deferences in a few places
*/

template <typename T> class TDynamicArray : public TContainer<T>
{
   T *array_;
   unsigned size_, capacity_;

   // double the capacity of the array
   void double_capacity();

public:
   TDynamicArray(unsigned initial_capacity = 0);
   TDynamicArray(const T *initial_array, unsigned size);

   ~TDynamicArray();

   bool contains(const T &item) const override;

   unsigned size() const override;

   void add_item(const T &item) override;

   void remove_item(const T &item) override;

   void clear() override;
};

// including the source in a .cpp file causes linker problems... need to sort that out, but in the interim:

template <typename T> TDynamicArray<T>::TDynamicArray(unsigned initial_capacity)
   :array_(0), size_(0), capacity_(initial_capacity)
{
   array_ = new T[capacity_];
}

template <typename T> TDynamicArray<T>::TDynamicArray(const T *initial_array, unsigned size)
   :array_(0), size_(size), capacity_(size)
{
   capacity_ = size_ * 2;
   array_ = new T[capacity_];

   // copy contents of initial array
   for (unsigned i = 0; i < size_; ++i)
   {
      array_[i] = initial_array[i];
   }
}

template <typename T> TDynamicArray<T>::~TDynamicArray()
{
   delete array_;
   array_ = 0;
}

template <typename T> void TDynamicArray<T>::double_capacity()
{
   capacity_ *= 2;

   // this could cause a memory leak
   T *new_array = new T[capacity_];

   // copy the contents of the array to the new array
   for (unsigned i = 0; i < size_; ++i)
   {
      new_array[i] = array_[i];
   }

   // alternatively?
   // T *next_item = array_;
   // T *next_new_item = new_array;
   // while (*next_item)
   // {
   //    *(next_new_item++) = *(next_item++);
   // }

   // alternatively??
   // for (unsigned i = 0; next_item; ++i)
   // {
   //    new_array[i] = next_item;
   //    ++next_item;
   // }

   delete array_;
   array_ = new_array;
}

template <typename T> bool TDynamicArray<T>::contains(const T &item) const
{
   for (unsigned i = 0; i < size_; ++i)
   {
      if (array_[i] == item)
         return true;
   }

   // alternatively?
   // for (auto &next_item : array_)
   // {
   //    if (next_item == item)
   //       return true;
   // }

   return false;
}

template <typename T> unsigned TDynamicArray<T>::size() const
{
   return size_;
}

template <typename T> void TDynamicArray<T>::add_item(const T &item)
{
   // TODO: use '==' or '>='; including 'greater than' seems unecessary
   if (size_ >= capacity_)
   {
      double_capacity();
   }

   array_[size_++] = item;
}

template <typename T> void TDynamicArray<T>::remove_item(const T &item)
{
   for (unsigned i = 0; i < size_; ++i)
   {
      if (array_[i] == item)
      {
         for (; i < size_ - 1; ++i)
         {
            array_[i] = array_[i + 1];
         }

         --size_;
         break;
      }
   }
}

template <typename T> void TDynamicArray<T>::clear()
{
   delete array_;
   array_ = new T[capacity_];
   size_ = 0;
}

#endif //__TDYNAMICARRAY_HPP__
