/*
   Used for testing at the moment.
*/

#include "../inc/TFile.hpp"
#include "../inc/TString.hpp"
#include "../inc/containers/TDynamicArray.hpp"
#include "../inc/containers/TLinkedList.hpp"

#include <iostream>

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
}

int main()
{
   test_linked_list();

   return 0;
}
