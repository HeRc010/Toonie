#include "TFile.hpp"

using namespace std;

/*
TODO:
- change internal structure; it doesn't make much sense to make an fstream every time you read from or write to the file.
- add file writing interface
*/

TFile::TFile(const std::string &path)
   : path_(path)
{
}

TFile::~TFile()
{
}

vector<TString> TFile::get_lines() const
{
   vector<TString> lines;

   // TODO: add check to ensure that the file exists
   ifstream input_file(path_.c_str());

   string next_line;
   while(getline(input_file, next_line))
   {
      lines.push_back(TString(next_line));
   }

   return lines;
}
