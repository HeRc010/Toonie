#ifndef __TSTACK_HPP__
#define __TSTACK_HPP__

/*
   This still needs a lot of work

   The idea here is that Stacks can have variable underlying representation
   The implementation can use arrays, dynamic arrays, linked lists, etc.
   So, how to provide that flexibility
*/

#include "TContainer.hpp"

template <typename T> class TStack : public TContainer<T>
{
   T container_;

public:
   TStack();
   ~TStack();

   unsigned size() const override;

   bool contains(const T &item) const override;

   void add_item(const T &item) override;

   void remove_item(const T &item) override;

   void clear() override;
};

template <typename T> TStack<T>::TStack()
   :container_(0)
{
}

template <typename T> TStack<T>::~TStack()
{
}

template <typename T> unsigned TStack<T>::size() const
{
   return container_.size();
}

template <typename T> bool TStack<T>::contains(const T &item) const
{
   return container_.contains(item);
}

template <typename T> void TStack<T>::add_item(const T &item)
{
   container_.add_item(item);
}

template <typename T> void TStack<T>::remove_item(const T &item)
{
   container_.remove_item(item);
}

template <typename T> void TStack<T>::clear()
{
   container_.clear();
}

#endif //__TSTACK_HPP__
