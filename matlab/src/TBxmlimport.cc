#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include "xmlimport.cc"

using namespace std;
int main (int argc, char* argv[]){
  std::string filepath {argv[1]};
  fstream fs;

  fs.open(argv[1], std::fstream::in);

  string tmp{};
  string value{};
  string trash{};
  char peek{};
  Recipe yumyum;
 
  while (fs.peek() != EOF) {
    fs.ignore(1000,'<');
    peek = fs.peek();
    
    if (peek == '?') { // ignore xml version tag
      //getline(fs,trash,'>');
      fs.ignore(1000,'>');
      //cout << "\033[1;31mTrashing init: <" << trash << ">" << endl << endl;
    }

    else if (peek == '!') { // ignore comments
      fs.get(peek);
      //getline(fs,trash,'>');
      fs.ignore(1000,'>');
      //cout << "\033[1;31mTrashing comment: <!" << trash << ">" << endl << endl;
      peek = {};
    }

    else if (peek == '/') { // close tag
      fs.get(peek);
      getline(fs,tmp,'>');
      cout << "\033[1;33mEnd tag: \033[1;36m" << tmp << endl << endl;
      if (tmp ==  "recipe") {
	break;
      }
    }

    else { //är alla med?
      getline(fs, tmp, '>'); // open tag
      cout << "\033[1;32mStart tag: \033[1;35m" << tmp;
      if (tmp != "recipe") {
	if (tmp == "name")
	  yumyum.setName(tagStringCont(fs));
	else if (tmp == "instruction")
	  yumyum.setMethod(tagStringCont(fs));
	else if (tmp == "time")
	  yumyum.setMinutesTime(tagIntCont(fs));
	else if (tmp == "rating")
	  yumyum.setGrade(tagDblCont(fs));
	else if (tmp == "price")
	  yumyum.setPrice(tagIntCont(fs));
	else if (tmp == "portionsize")
	  yumyum.setPortions(tagIntCont(fs));
	else if (tmp == "ingredient")
	  yumyum.setIngredients(tagIngredient(fs));
	else 
	  tagStringCont(fs);
      }}
    
    cout << endl << endl;
  }
    //    cout << "\033[1;38mpeek: " << peek << endl;
    
  cout << "\033[1;31m Printing Recipe: \n==================\nTitel: " << yumyum.name_ << endl
       << "\033[1;32m" << "Instruktion: " << yumyum.method_ << endl
       << "\033[1;33m" << "Tillagningstid: " << yumyum.minutesTime_ << endl
       << "Betyg: " << yumyum.grade_ << endl
    //<< "\033[1;35m" << yumyum.ingredients_ << endl
       << "Pris: " << yumyum.price_ << endl
       << "Kcal: " << yumyum.kcal_ << endl
       << "Portioner: " << yumyum.portions_ << endl
    // << "\033[1;33m" << yumyum.comments_
       << endl;
    
  
  fs.close();
}
