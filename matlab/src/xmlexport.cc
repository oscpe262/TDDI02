#include <fstream>
#include <string>
#include <algorithm>
#include "classes/headers/Recipe.h"

// NOT DONE OMG!

void XMLExport (std::string filepath, Recipe recipe) {
  ofstream fs;

  //filecheck

  fs.open(filepath);
  fs << "<?xml version=\"1.0\"?>\n"
     << "<!-- " << filepath << " -->\n"
     << "<recipe>\n"
     << "  <name>" << recipe.name_ << "</name>\n"
     << "  <portionsize>" << recipe.portion_ << "</portionsize>\n";
  // iterate over ingredientlist
  fs << "  <instruction>" << recipe.method_ << "</instruction>\n"
     << "  <time>" << recipe.minutesTime_ << "</time>\n"
     << "  <price>" << recipe.price_ << "</price>\n"
     << "  <energy>" << recipe.kcal_ << "</energy>\n"
     << "  <rating>" << recipe.grade_ << "</rating>\n"
     << "</recipe>" << endl;
  fs.close;
}
