#include <fstream>
#include <string>
#include <algorithm>
#include "classes/headers/Recipe.h"

string tagStringCont(fstream & fs) {
  string value{};
  getline(fs,value,'<');
  return value;
};

int tagIntCont(fstream & fs) {
  int value{};
  fs >> value;
  return value;
};

double tagDblCont(fstream & fs) {
  double value{};
  fs >> value;
  return value;
};

IngredientList tagIngredient(fstream & fs) {
   string tagIng{"ingredient"};
   string name{"foo"};
   string unitString{};
   double price{0};
   int kcal{0};
   double amount{0};
   Unit unit{gram};
   char peekIng{};
   char trash{};
   IngredientList IL{};

   peekIng = fs.peek();

   while (tagIng != "ingredient" && peekIng != '/') {
     if (peekIng == '!' || peekIng == '?') {
       fs.get(peekIng);
       fs.ignore(1000,'>');       
     }
     else if (peekIng == '/') {
       getline(fs,tagIng,'>');
       if (tagIng == "/ingredient"){
	 RecipeIngredient omnom{name, price, kcal, amount, unit};
	 if (DB::checkIngredient == name) {
	   IL.push_back(omnom);
	 }
	 return IL;
       }
     }
     else {
       if (tagIng == "ingredient") {
	 getline(fs,name,'<');
       }
       else if (tagIng == "amount") {
	 fs >> amount;
	 fs.get(trash);
       }
       else if (tagIng == "kcal") {
	 fs >> kcal;
	 fs.get(trash);
       }
       else if (tagIng == "price") {
	 fs >> price;
	 fs.get(trash);
       }
       else if (tagIng == "unit") {
	 getline(fs,unitString,'<');	
	 std::transform(unitString.begin(), unitString.end(), unitString.begin(), ::tolower);
	
	 if ( unitString == "dl" || unitString == "deciliter")
	   unit = deciliter;
	 else if ( unitString == "tsk" || unitString == "tesked" || unitString == "teskedar" || unitString == "teaspoon" )
	   unit = teaspoon;
	 else if ( unitString == "msk" || unitString == "matsked" || unitString == "matskedar" || unitString == "tablespoon" )
	   unit = tablespoon;
	 else if ( unitString == "st" || unitString == "styck" || unitString == "stycken" ||  unitString == "pcs" )
	   unit = pcs;
	 else
	   unit = gram;
       }	 
     }       
   }
}
 

Recipe importXml (std::string filepath) {
  ifstream fs;

  //filecheck
  
  fs.open(filepath);

  string tmp{};
  string value{};
  string trash{};
  char peek{};
  Recipe yumyum;
  //  bool dirtyRead{0};
 
  while (fs.peek() != EOF) {
    fs.ignore(1000,'<');
    peek = fs.peek();
    
    if (peek == '?') { // ignore xml version tag
      fs.ignore(1000,'>');
    }

    else if (peek == '!') { // ignore comments
      fs.get(peek);
      fs.ignore(1000,'>');
      peek = {};
    }

    else if (peek == '/') { // close tag
      fs.get(peek);
      getline(fs,tmp,'>');
      if (tmp ==  "recipe")
	break;
    }

    else { //är alla med?
      getline(fs, tmp, '>'); // open tag
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
      }
    }
  }
  fs.close();
  return yumyum;
}
