/*
   Used for testing at the moment.
*/

#include "../inc/TFile.hpp"
#include "../inc/TString.hpp"

#include "../inc/algorithms/TIterator.hpp"

#include "../inc/containers/TDynamicArray.hpp"
#include "../inc/containers/TLinkedList.hpp"

#include <iostream>
#include <iterator>

using namespace std;

void test_file_io()
{
   TFile input_file("input.txt");

   vector<TString> lines = input_file.get_lines();

   for (auto &line : lines)
   {
      cout << "next line is: " << line.c_str() << endl;
      for (auto &s : line.split(TString(" ")))
      {
         cout << "next space separated string: " << s.c_str() << endl;
      }
   }

   //input_file.append_lines({TString("test line"), TString("test line 2"), TString("test line 3")});
   input_file.overwrite_lines({TString("test line a"), TString("test line b"), TString("test line c")});
}

void test_darray()
{
   int array[5];
   for (unsigned i = 0; i < 5; ++i)
   {
      array[i] = i + 1;
   }

   TDynamicArray<int> a_test(array, 5);

   cout << "array size: " << a_test.size() << endl;

   cout << "does array contain 1?: " << a_test.contains(1) << endl;

   cout << "does array contain 10?: " << a_test.contains(10) << endl;

   a_test.add_item(10);

   cout << "array size: " << a_test.size() << endl;

   cout << "does array contain 10?: " << a_test.contains(10) << endl;

   a_test.remove_item(10);

   cout << "array size: " << a_test.size() << endl;

   cout << "does array contain 10?: " << a_test.contains(10) << endl;

   a_test.remove_item(3);

   cout << "array size: " << a_test.size() << endl;

   for (unsigned i = 0; i < a_test.size() + 2; ++i)
   {
      cout << "does array contain " << i + 1 << "?: " << a_test.contains(i + 1) << endl;
   }

   a_test.clear();

   cout << "array size: " << a_test.size() << endl;

   for (unsigned i = 0; i < a_test.size() + 6; ++i)
   {
      cout << "does array contain " << i + 1 << "?: " << a_test.contains(i + 1) << endl;
   }

   // test iterators
   // auto it = a_test.begin();
   // ++it;
   //
   // TDynamicArrayIterator<int> darray_it(a_test);
   // ++darray_it;
}

void test_linked_list()
{
   TLinkedList<int> list;

   cout << "list size: " << list.size() << endl;

   list.add_item(1);

   cout << "list size: " << list.size() << endl;
   cout << "list contains 1?: " << list.contains(1) << endl;

   list.add_item(3);

   cout << "list size: " << list.size() << endl;
   cout << "list contains 3?: " << list.contains(3) << endl;

   list.remove_item(3);

   cout << "list size: " << list.size() << endl;
   cout << "list contains 3?: " << list.contains(3) << endl;

   list.add_item(5);
   list.add_item(7);
   list.add_item(9);

   cout << "list size: " << list.size() << endl;
   cout << "list contains 5?: " << list.contains(5) << endl;
   cout << "list contains 7?: " << list.contains(7) << endl;
   cout << "list contains 9?: " << list.contains(9) << endl;

   list.remove_item(10);
   cout << "list size: " << list.size() << endl;

   list.remove_item(7);
   cout << "list size: " << list.size() << endl;
   cout << "list contains 5?: " << list.contains(5) << endl;
   cout << "list contains 7?: " << list.contains(7) << endl;

   list.clear();
   cout << "list size: " << list.size() << endl;
   cout << "list contains 1?: " << list.contains(1) << endl;
   cout << "list contains 5?: " << list.contains(5) << endl;
   cout << "list contains 7?: " << list.contains(7) << endl;
   cout << "list contains 9?: " << list.contains(9) << endl;

   // Iterator test

}

// swap function test
void swap(int &a, int &b)
{
   a = a + b;
   b = a - b;
   a = a - b;
}

int max(int a, int b)
{
   return a - ((a - b) & ((a - b) >> 31));
}

class BaseIterator
{
public:
   BaseIterator() {}
   virtual ~BaseIterator() {}

   virtual void operator++() { cout << "base class operator" << endl; }
};

class SubIterator : public BaseIterator
{
public:
   SubIterator() {}
   ~SubIterator() {}

   void operator++() override { cout << "sub class operator" << endl; }
};

class Iterator
{
public:
   Iterator() {}
   ~Iterator() {}

   // Equality operators
   virtual bool operator==(Iterator& rhs) const = 0;
   bool operator!=(Iterator& rhs) const { return !this->operator==(rhs); }

   virtual bool operator==(const Iterator& rhs) const = 0;
   bool operator!=(const Iterator& rhs) const { return !this->operator==(rhs); }

   // Increment operators
   virtual void operator++() const = 0; // { cout << "base iterator operator" << endl; }
};

class Container
{
public:
   Container() {}
   ~Container() {}

   //virtual Iterator begin() const = 0;
};

class ListIterator : public Iterator
{
public:
   ListIterator() {}
   ~ListIterator() {}

   virtual bool operator==(Iterator& rhs) const override { return false; }
   virtual bool operator==(const Iterator& rhs) const override { return false; }

   virtual void operator++() const override {}
};

class List : public Container
{
public:
   List() {}
   ~List() {}

   ListIterator begin() const { return ListIterator(); }
   ListIterator end() const { return ListIterator(); }
};

class VectorIterator : public Iterator
{
public:
   VectorIterator() {}
   ~VectorIterator() {}

   virtual bool operator==(Iterator& rhs) const override { return false; }
   virtual bool operator==(const Iterator& rhs) const override { return false; }

   void operator++() const override {}
};

class Vector : public Container
{
public:
   Vector() {}
   ~Vector() {}

   VectorIterator begin() const { return VectorIterator(); }
   VectorIterator end() const { return VectorIterator(); }
};

// Algorithm test function
void algor(const Iterator &start, const Iterator &end)
{
   for (; start != end; ++start)
   {

   }
}

int main()
{
   // Iterator test
   BaseIterator bi;
   SubIterator si;

   bi = si;
   ++bi;
   ++si;

   BaseIterator *bi_pointer = &si;
   ++(*bi_pointer);

   BaseIterator *heap_allocated_bi = new SubIterator();

   ++(*heap_allocated_bi);

   delete heap_allocated_bi;

   // Using iterators from STL
   vector<int> test_vec = {1, 2, 3};
   auto it = test_vec.begin();
   for (; it != test_vec.end(); ++it)
   {
      cout << *it << endl;
   }

   // Test
   Vector v;
   List l;

   algor(l.begin(), l.end());

   return 0;
}
