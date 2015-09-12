#ifndef __TFILE_HPP__
#define __TFILE_HPP__

/*
   The TFile class is a wrapper for files. Ideally the interface will allow for both reading and writing.

   TODO:
   - reformat internal structure? use an fstream instead? If this is done, access to the file will need to be controlled by the class; wouldn't want another process to modify the file in the interim
*/

#include "TString.hpp"

#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

class TFile
{
   const TString path_;

public:
   TFile(const std::string &path);
   ~TFile();

   // return true if the file exists, false otherwise
   bool exists() const;

   // get the lines in the file
   std::vector<TString> get_lines() const;

   // replace the contents of the file with the given lines
   // return true if successful, false otherwise
   bool overwrite_lines(const std::vector<TString> &lines) const;

   // append the given lines to the end of the file
   // return true if successful, false otherwise
   bool append_lines(const std::vector<TString> &lines) const;
};

#endif //__TFILE_HPP__
