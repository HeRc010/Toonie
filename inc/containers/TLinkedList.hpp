#ifndef __TLINKEDLIST_HPP__
#define __TLINKEDLIST_HPP__

#include "TContainer.hpp"

#include "../algorithms/TIterator.hpp"

template <typename T> class TNode
{
public:
   TNode(const T &data);
   TNode(const TNode &rhs);
   ~TNode();

   T data;
   TNode<T> *next;
};

template <typename T> class TLinkedList : public TContainer<T>
{
   TNode<T> *head, *tail;
   unsigned size_;

public:
   // Cutom iterator
   class TLinkedListIterator : public TIterator
   {
      TLinkedListIterator(TNode<T> *node); //const TNode<T> &node);

      // TODO: node storage format; pointer or object?
      //TNode<T> node_;
      TNode<T> *node_;

   public:
      TLinkedListIterator(const TLinkedListIterator &list);
      ~TLinkedListIterator();

      // Equality operators
      bool operator==(TIterator& rhs) const override;
      bool operator==(const TIterator& rhs) const override;

      // Increment operators
      const TLinkedListIterator& operator++() const override;

      friend class TLinkedList<T>;
   };

   TLinkedList();
   ~TLinkedList();

   unsigned size() const override;

   bool contains(const T &item) const override;

   void add_item(const T &item) override;

   void remove_item(const T &item) override;

   void clear() override;

   // Traversal
   TLinkedListIterator begin() const;
   TLinkedListIterator end() const;

   friend class TLinkedListIterator;
};

////////////////////////////////////////////////////////////////
// TNode
template <typename T> TNode<T>::TNode(const T &initial_data)
   :data(initial_data), next(0)
{
}

template <typename T> TNode<T>::TNode(const TNode &rhs)
   :data(rhs.data), next(rhs.next)
{
}

template <typename T> TNode<T>::~TNode()
{
}

////////////////////////////////////////////////////////////////
// TLinkedListIterator
//template <typename T> TLinkedList<T>::TLinkedListIterator::TLinkedListIterator(const TNode<T> &node)
//   : node_(node)
template <typename T> TLinkedList<T>::TLinkedListIterator::TLinkedListIterator(TNode<T> *node)
   : node_(node)
{
   // ...
}

template <typename T> TLinkedList<T>::TLinkedListIterator::TLinkedListIterator(const TLinkedListIterator &TLinkedListIterator)
{
   // ...
}

template <typename T> TLinkedList<T>::TLinkedListIterator::~TLinkedListIterator()
{
   // ...
}

template <typename T> bool TLinkedList<T>::TLinkedListIterator::operator==(TIterator& rhs) const
{
   // ...
}

template <typename T> bool TLinkedList<T>::TLinkedListIterator::operator==(const TIterator& rhs) const
{
   // ...
}

template <typename T> const typename TLinkedList<T>::TLinkedListIterator& TLinkedList<T>::TLinkedListIterator::operator++() const
{
   // ...
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

template <typename T> typename TLinkedList<T>::TLinkedListIterator TLinkedList<T>::begin() const
{
   //return TLinkedListIterator(*head);
   return TLinkedListIterator(head);
}

template <typename T> typename TLinkedList<T>::TLinkedListIterator TLinkedList<T>::end() const
{
   //return TLinkedListIterator(*tail);
   return TLinkedListIterator(tail);
}

#endif //__TLINKEDLIST_HPP__
