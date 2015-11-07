#ifndef __TCONTAINER_HPP__
#define __TCONTAINER_HPP__

/*
   Abstract class which defines the interface to be implemented by specific containers.
*/

template <typename T> class TContainer
{
public:
   // TODO: potential problem; this function uses the assumption that the type being used supports comparison of two objects of that type; can this be rectified?

   // return the number of items in the container
   virtual unsigned size() const = 0;

   // return true if the container contains
   virtual bool contains(const T &item) const = 0;

   // add the given item to the container
   virtual void add_item(const T &item) = 0;

   // remove the given item from the container
   virtual void remove_item(const T &item) = 0;

   // remove all items from the container
   virtual void clear() = 0;
};

#endif //__TCONTAINER_HPP__
