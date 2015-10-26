#ifndef __TLINKEDLIST_HPP__
#define __TLINKEDLIST_HPP__

#include "TContainer.hpp"

template <typename T> class TNode
{
public:
   TNode(const T &data);
   ~TNode();

   T data;
   TNode<T> *next;
};

template <typename T> class TLinkedListIterator : public TIterator<T>
{
public:
   void operator++() const override;
};

template <typename T> class TLinkedList : public TContainer<T>
{
   TNode<T> *head;
   unsigned size_;

public:
   TLinkedList();
   ~TLinkedList();

   unsigned size() const override;

   bool contains(const T &item) const override;

   void add_item(const T &item) override;

   void remove_item(const T &item) override;

   // TODO:
   TIterator<T> begin() const;

   TIterator<T> end() const;

   void clear() override;
};

////////////////////////////////////////////////////////////////
// TNode
template <typename T> TNode<T>::TNode(const T &initial_data)
   :data(initial_data), next(0)
{
}

template <typename T> TNode<T>::~TNode()
{
}

////////////////////////////////////////////////////////////////
// TLinkedList
template <typename T> TLinkedList<T>::TLinkedList()
   :head(0), size_(0)
{
}

template <typename T> TLinkedList<T>::~TLinkedList()
{
   TNode<T> *next_node = head;
   while (next_node)
   {
      TNode<T> *temp = next_node->next;
      delete next_node;
      next_node = temp;
   }
}

template <typename T> unsigned TLinkedList<T>::size() const
{
   return size_;
}

template <typename T> bool TLinkedList<T>::contains(const T &item) const
{
   TNode<T> *next_node = head;
   while (next_node)
   {
      if (next_node->data == item)
         return true;

      next_node = next_node->next;
   }

   return false;
}

template <typename T> void TLinkedList<T>::add_item(const T &item)
{
   TNode<T> *new_node = new TNode<T>(item);

   if (head)
   {
      TNode<T> *next_node = head;
      while (next_node)
      {
         if (!next_node->next)
         {
            next_node->next = new_node;
            break;
         }

         next_node = next_node->next;
      }
   }
   else
   {
      head = new_node;
   }

   ++size_;
}

// TODO: this is incorrect in some ways; it assumes that the data entries in all the nodes are unique amongst themselves; which obviously isn't a safe assumption, should take in an iterator as a parameter and use pointers as unique identifiers
template <typename T> void TLinkedList<T>::remove_item(const T &item)
{
   TNode<T> *prev_node = 0;
   TNode<T> *next_node = head;
   while (next_node)
   {
      if (next_node->data == item)
      {
         if (prev_node)
            prev_node->next = next_node->next;

         delete next_node;
         --size_;

         break;
      }

      prev_node = next_node;
      next_node = next_node->next;
   }
}

// TODO: add iterator functions
template <typename T> TIterator<T> TLinkedList<T>::begin() const
{
   // TLinkedListIterator<T> temp;
   // return temp;
}

template <typename T> TIterator<T> TLinkedList<T>::end() const
{

}

template <typename T> void TLinkedList<T>::clear()
{
   TNode<T> *next_node = head;
   while (next_node)
   {
      TNode<T> *temp = next_node->next;
      delete next_node;
      next_node = temp;
   }

   size_ = 0;
}

#endif //__TLINKEDLIST_HPP__
