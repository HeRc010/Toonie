#ifndef __TDYNAMICARRAY_HPP__
#define __TDYNAMICARRAY_HPP__

#include <iostream>

#include "TContainer.hpp"

template <typename T> class TDynamicArrayIterator;

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

   TIterator<T>& begin() const override;

   TIterator<T> end() const override;

   void clear() override;

   friend class TDynamicArrayIterator<T>;
};

// custom iterator
template <typename T> class TDynamicArrayIterator : public TIterator<T>
{
   const TDynamicArray<T> *darray_;
   unsigned index_;

public:
   TDynamicArrayIterator(const TDynamicArray<T> &array, unsigned index = 0);
   ~TDynamicArrayIterator();

   T get() const override;

   bool operator==(const TDynamicArrayIterator<T> &rhs) const;
   bool operator!=(const TDynamicArrayIterator<T> &rhs) const;
   TIterator<T>& operator++() override;
};

////////////////////////////////////////////////////////////////
// TDynamicArrayIterator

template <typename T> TDynamicArrayIterator<T>::TDynamicArrayIterator(const TDynamicArray<T> &array, unsigned index)
   :darray_(&array), index_(index)
{
}

template <typename T> TDynamicArrayIterator<T>::~TDynamicArrayIterator()
{
}

template <typename T> T TDynamicArrayIterator<T>::get() const
{
   return darray_->array_[index_];
}

template <typename T> bool TDynamicArrayIterator<T>::operator==(const TDynamicArrayIterator<T> &rhs) const
{
   std::cout << "yeppers" << std::endl;
   if (darray_ != rhs.darray_)
      return false;
   if (index_ != rhs.index_)
      return false;

   return true;
}

template <typename T> bool TDynamicArrayIterator<T>::operator!=(const TDynamicArrayIterator<T> &rhs) const
{
   return !operator==(rhs);
}

template <typename T> TIterator<T>& TDynamicArrayIterator<T>::operator++()
{
   ++index_;
   std::cout << "from darray it" << std::endl;
   return *this;
}

////////////////////////////////////////////////////////////////
// TDynamicArray
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

   // this could cause a memory leak..
   T *new_array = new T[capacity_];

   // copy the contents of the array to the new array
   for (unsigned i = 0; i < size_; ++i)
   {
      new_array[i] = array_[i];
   }

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

template <typename T> TIterator<T>& TDynamicArray<T>::begin() const
{
   // return std::move(TDynamicArrayIterator<T>(*this));
   std::cout << "test teessstt" << std::endl;

   TDynamicArrayIterator<T>* it = new TDynamicArrayIterator<T>(*this);
   ++(*it);
   return *it;
}

template <typename T> TIterator<T> TDynamicArray<T>::end() const
{
   return std::move(TDynamicArrayIterator<T>(*this, size_));
}

template <typename T> void TDynamicArray<T>::clear()
{
   delete array_;
   array_ = new T[capacity_];
   size_ = 0;
}

#endif //__TDYNAMICARRAY_HPP__
