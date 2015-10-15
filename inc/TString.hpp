#ifndef __TSTRING_H__
#define __TSTRING_H__

/*
   The TString class is a custom string class to allow for additional functionality not provided in the standard template library.

   Todo:
   - implement internally as a dynamic array of characters?
   - should the string class be a subclass of the std::string class?
   - implement operator==(...)
*/

#include <string>
#include <vector>
#include <ostream>

class TString
{
   std::string string_;

public:
   TString();
   TString(const std::string &s);
   TString(const char *s);
   ~TString();

   // return a pointer to the char array associated with the string
   const char* c_str() const;

   // return the number of characters in the string
   unsigned size() const;

   // split the string by the specified delimiter, return the results in a list
   std::vector<TString> split(const TString &delimiter) const;
};

#endif //__TSTRING_H__
