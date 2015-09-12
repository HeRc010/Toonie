#include "../../inc/containers/TDynamicArray.hpp"

template <typename T> TDynamicArray<T>::TDynamicArray(unsigned capacity)
   :array_(0), size_(0), capacity_(capacity)
{
   array_ = new T[capacity];
}

template <typename T> TDynamicArray<T>::TDynamicArray(const T *initial_array, unsigned capacity)
   :array_(0), size_(0), capacity_(capacity)
{
   // compute the size of the initial array
   T *next_initial_item = initial_array;
   while (next_initial_item)
   {
      ++size_;
      ++next_initial_item;
   }

   // replace capacity with the size of the initial array if the size is greater than the capacity
   if (size_ > capacity_)
   {
      capacity_ = size_;
   }

   array_ = new T[capacity_];

   // copy the values from the intial array
   next_initial_item = initial_array;
   T *next_item = array_;
   while (next_initial_item)
   {
      next_item++ = next_initial_item++;
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
   T *new_array = new T[capacity_];

   // copy the contents of the array to the new array
   T *next_item = array_;
   T *next_new_item = new_array;
   while (next_item)
   {
      next_new_item++ = next_item++;
   }

   // alternatively
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
   for (auto &next_item : array_)
   {
      if (next_item == item)
         return true;
   }

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
   // TODO: implement
}

template <typename T> void TDynamicArray<T>::clear()
{
   // TODO: implement
}
