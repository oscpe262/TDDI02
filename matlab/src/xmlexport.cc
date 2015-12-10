#include <fstream>
#include <string>
#include <algorithm>
#include "classes/headers/Recipe.h"

class XMLException : public std::exception {
public:
  explicit XMLException(const std::string& message):
    msg_(message){}
  virtual char const * what() const noexcept {return msg_.c_str();}

private:
  string msg_;
};

std::string(std::string oldFilename) {
  return "New." + oldFilename;  
};

void exportXml (std::string filepath, Recipe recipe) {
  ofstream fs;
  std::string unit{};

  /*
  if(file exists) {
  filepath = rename(filepath);
  }
  */  
  fs.open(filepath);
  fs << "<?xml version=\"1.0\"?>\n"
     << "<!-- " << filepath << " -->\n"
     << "<recipe>\n"
     << "  <name>" << recipe.name_ << "</name>\n"
     << "  <portionsize>" << recipe.portions_ << "</portionsize>\n";
  
  for (auto it = begin (recipe.ingredients_); it != end (recipe.ingredients_); ++it) {
  fs << "  <ingredient>" << it->name_
     << "<amount>" << it->amount_;
  switch (it->unit_) {
  case 1 : unit = "dl";   break;
  case 2 : unit = "tsk";  break;
  case 3 : unit = "msk";  break;
  case 4 : unit = "st";   break;
  default: unit = "gram"; break;
  }
  fs << "<unit>" << unit << "</unit>"
     << "</amount></ingredient>" << endl;
  }
  
  fs << "  <instruction>" << recipe.method_ << "</instruction>\n"
     << "  <time>" << recipe.minutesTime_ << "</time>\n"
     << "  <price>" << recipe.price_ << "</price>\n"
     << "  <energy>" << recipe.kcal_ << "</energy>\n"
     << "  <rating>" << recipe.grade_ << "</rating>\n"
     << "</recipe>" << endl;
  fs.close();
};
