#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "xmlimport.cc"

string unit2str( const Unit& unitvalue ) // Ripped from Shell.cc
  {
    switch(unitvalue)
      {
      case gram:
	return "g";
      case deciliter:
	return "dl";
      case teaspoon:
	return "tsk";
      case tablespoon:
	return "msk";
      case pcs:
	return "st";
      default:
	return "null";
      }
  }


using namespace std;
int main (int argc, char* argv[]){
  std::string filepath {argv[1]};

  Recipe yumyum = importXml(filepath);
      
  cout << "\n\n\033[1;31m Imported Recipe:"
       << "\n==================\n"
       << "\033[1;34mTitel: " << yumyum.name_ << endl
       << "\033[1;33mPortioner: " << yumyum.portions_ << "\033[1;35m " << endl;
  for ( RecipeIngredient it : yumyum.getIngredients() ) {
    cout << it.getName() << " " << it.getAmount() << " " << unit2str(it.getUnit()) << endl;
  }
  cout << "\033[1;32m" << "Instruktion: " << yumyum.method_ << endl
       << "\033[1;33m" << "Tillagningstid: " << yumyum.minutesTime_ << endl
       << "Pris: " << yumyum.price_ << endl
     //<< "Kcal: " << yumyum.kcal_ << endl
       << "Betyg: " << yumyum.grade_ << endl
    // << "\033[1;33m" << yumyum.comments_
       << endl;
}
