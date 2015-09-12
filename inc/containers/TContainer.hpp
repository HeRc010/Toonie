#ifndef __TCONTAINER_HPP__
#define __TCONTAINER_HPP__

/*
   Abstract class which defines the interface to be implemented by specific containers.
*/

template <typename T> class TContainer
{
public:
   // ctor & ~ctor needed? - prob not
   TContainer();
   ~TContainer();

   // TODO: potential problem; this function uses the assumption that the type being used supports comparison of two objects of that type
   // return true if the container contains
   virtual bool contains(const T &item) const = 0;
};

#endif //__TCONTAINER_HPP__
