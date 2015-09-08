/*
   Used for testing at the moment.
*/

#include "TFile.hpp"
#include "TString.hpp"

#include <iostream>

using namespace std;

int main()
{
   TFile input_file("input.txt");

   vector<TString> lines = input_file.get_lines();

   for (auto &line : lines)
   {
      cout << "next line is: " << line.c_str() << endl;
      for (auto &s : line.split(' '))
      {
         cout << "next space separated string: " << s.c_str() << endl;
      }
   }

   return 0;
}
