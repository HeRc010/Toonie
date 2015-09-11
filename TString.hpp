#ifndef __TSTRING_H__
#define __TSTRING_H__

/*
   The TString class is a custom string class to allow for additional functionality not provided in the standard template library.

   Todo:
   - should the string class be a subclass of the std::string class?
*/

#include <string>
#include <vector>
#include <ostream>

class TString
{
   std::string string_;

public:
   TString(const std::string &s);
   TString(const char *s);
   ~TString();

   const char* c_str() const;
   unsigned size() const;

   std::vector<TString> split(const TString &delimiter) const;
};

#endif //__TSTRING_H__
