#ifndef __TFILE_HPP__
#define __TFILE_HPP__

/*
   The TFile class is a wrapper for files. Ideally the interface will allow for both reading and writing.
*/

#include "TString.hpp"

#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

class TFile
{
   const std::string path_;

public:
   TFile(const std::string &path);
   ~TFile();

   bool exists() const;

   std::vector<TString> get_lines() const;
};

#endif //__TFILE_HPP__
