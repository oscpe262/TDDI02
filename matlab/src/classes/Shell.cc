#include "classes/headers/Shell.h"
#include "classes/headers/Recipe.h"
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include "classes/headers/DB.h"
#include "classes/headers/EditDB.h"
#include "classes/headers/SearchDB.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

/* extra function declarations */
namespace{
  string unit2str( const Unit& unitvalue )
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
}
bool fileExists( const string& name );
void readFromFile( istream& is, string& str );

bool findName( const string& fieldstr, string& returnstr );
bool findPortions( const string& fieldstr, string& returnstr );
bool findTime( const string& fieldstr, string& returnstr );


/*
 * unit2str
 *
 *** [SHELL] ***
 * exportTxt
 * *importTxt
 * *exportXml
 * *importXml
 * *setScaling
 *
 *** [SDB] ***
 * exactMatch
 * getRecipeResults
 * getIngredientList
 * openRecipe
 * *openIngredient
 *
 *** [EDB] ***
 * addRecipe
 * removeReciope
 * addIngredient
 * removeIngredient
 *
 *** [extra] ***
 * fileExists
 * readFromFile
 *
 * findName
 * findPortions
 * findTime
 */


/***************
 *** [SHELL] ***
 **************/

void Shell::exportTxt( string fileName )
{
  if( fileName == "null" )
    fileName = currentRecipe_.getName();

  if( fileName.substr(fileName.length()-5, string::npos) != ".txt" )
    fileName += ".txt";

  if( fileExists(fileName) ) 
    {
      // kasta undantag!!
      // Beep boop, "Fil med samma namn existerar redan!"
    }

  ofstream recipeTxt {fileName};
  if( !recipeTxt )
    {
      recipeTxt.close();
      // kasta undantag!!!
    }
  // lägg till <!-- kommentar --> med filnamn?
  recipeTxt << "# " << currentRecipe_.getName() << " (" << currentRecipe_.getPortions() << " portioner)\n"
	    << "Tillagningstid: c:a " << currentRecipe_.getMinutesTime() << " min\n"
	    << "============\n"; // godtyckligt antal?

    for( RecipeIngredient& ri : currentRecipe_.getIngredients() )
      {
    recipeTxt << ri.getName() << " " << ri.getAmount() << " " << unit2str( ri.getUnit() ) << "\n\n";
      }

  recipeTxt << currentRecipe_.getMethod() << "\n\n";

  recipeTxt << "Uppskattat energiinnehåll: " << currentRecipe_.getKcal() << " kcal\n"
	    << "Uppskattat pris: " << currentRecipe_.getPrice() << " kr\n"
	    << "Betyg: " << currentRecipe_.getGrade() << "/5\n"
	    << "<!-- EOF -->";

  recipeTxt.close();
}



/*Recipe Shell::importTxt( string fileName )
{
  if( !fileExists(fileName) )
    {
      // kasta undantag!!
      // Beep boop, "Filen existerar ej"
    }

  // Öppna fil
  ifstream ifs {fileName};
  if( !ifs )
    {
      ifs.close();
      // kasta undantag
    }

  Recipe recipe;
  string fileContents;

  // Läs till sträng fileContents och Stäng fil
  readFromStream(ifs, fileContents);
  ifs.close();

  // Rensa bort kommentarer: <!-- kommentar -->
  while( fileContents.find("<!--") != string::npos && fileContents.find("-->") != string::npos )
    {
      size_t filePos { fileContents.find("<!--") };
      size_t filePosEnd { fileContents.find("-->") };
      fileContents = fileContents.substr(0, filePos) + fileContents.substr(filePosEnd + 3);
    }

  // Namn (, portioner, tid)
  istringstream iss {fileContents};
  string fileLine, fileSection;
  
  for( int i {} ; i < 5 ; ++i )
    {
      getline(iss, fileLine);
      if( fileLine.find('=') != string::npos )
	{
	  break;
	}
      fileSection += fileLine;
      fileSection.push_back('\n');
    }

  // header

  // ingredient list

  // description & tail


  findName(fileSection, fileLine);
  recipe.setName(fileLine);

  if( findPortions(fileSection, fileLine) )
    recipe.setPortions( stoi(fileLine) );

  if( findTime(fileSection, fileLine) )
    recipe.setTime( stoi(fileLine) );

  IngredientList ingList { findIngredients(;

  recipe.setIngredients(ingList);

  // Ingredienser
  
  // first << second << third
  // first << secondthird



}*/



/*************
 *** [SDB] ***
 ************/

vector<MiniRecipe> Shell::exactMatch( const string& name )
{
  currentRecipe_ = sDB_.fetchRecipe(name);
  vector<MiniRecipe> vmr { MiniRecipe( currentRecipe_.getName(), currentRecipe_.getMinutesTime(), currentRecipe_.getGrade() ) };
  return vmr;
}

vector<MiniRecipe> Shell::getRecipeResults( SearchTerm& searchTerms )
{
  recipeSearchResults_ = sDB_.termSearch(searchTerms); 
  return recipeSearchResults_;
} 

vector<string> Shell::getIngredientNames()
{
  ingredientFullList_ = sDB_.queryIngredientNames();
  return ingredientFullList_;
}
 
Recipe Shell::openRecipe( const string& name )
{
  currentRecipe_ = sDB_.fetchRecipe(name);
  return currentRecipe_;
}
 
Ingredient Shell::openIngredient( const string& name )
{
  currentIngredient_ = sDB_.fetchIngredient(name);
  return currentIngredient_; 
}



/*************
 *** [EDB] ***
 ************/

bool Shell::addRecipe( const Recipe& recipe )
{
  return eDB_.addRecipe(recipe); // Rätt funktion?
}

bool Shell::removeRecipe( const Recipe& recipe )
{
  return eDB_.removeRecipe(recipe); // Rätt funktion?
}

bool Shell::removeRecipe( const string& name )
{
  return eDB_.removeRecipe(name);
}

bool Shell::addIngredient( const Ingredient& ingredient )
{
  return eDB_.addIngredient(ingredient); // Rätt funktion?
}

bool Shell::removeIngredient( const Ingredient& ingredient )
{
  return eDB_.removeIngredient(ingredient);
}

bool Shell::removeIngredient( const string& name )
{
  return eDB_.removeIngredient(name);
}



/***************
 *** [extra] ***
 **************/

bool fileExists( const string& name )
{
  ifstream filetest {name};
  if( filetest.good() )
    {
      filetest.close();
      return true;
    }
  else
    {
      filetest.close();
      return false;
    }
}



void readFromStream( istream& is, string& str )
{
  string temp;
  while( getline(is, temp) )
    {
      str += temp;
      str.push_back('\n');
    }
}



bool findName( const string& fieldstr, string& returnstr )
{
  istringstream iss {fieldstr};
  char c;

  while( !isalpha( iss.peek() ) )
    {
      iss.get(c);
    }

  getline(iss, returnstr);
  size_t junkCheck { returnstr.find('(') };

  if( junkCheck != string::npos )
    returnstr = returnstr.substr(0, junkCheck-1);

  return true;
}



bool findPortions( const string& fieldstr, string& returnstr )
{
  istringstream iss {fieldstr};
  string portionCheck;
  char c {'n'};
  
  returnstr.clear();
  
  while( iss )
    {
      while( !isdigit(c) )
	{
	  iss.get(c);
	}
      
      while( isdigit(c) )
	{
	  returnstr += c;
	  iss.get(c);
	}
      
      iss >> portionCheck;

      if( !isspace(c) )
	portionCheck = c + portionCheck;
      
      if( portionCheck.find("portion") != string::npos )
	return true;
    }
  return false;
}


bool findTime( const string& fieldstr, string& returnstr )
{
  istringstream iss {fieldstr};
  string minCheck;
  char c {'n'};
  
  returnstr.clear();
  
  while( iss )
    {
      while( !isdigit(c) )
	{
	  iss.get(c);
	}
      
      while( isdigit(c) )
	{
	  returnstr += c;
	  iss.get(c);
	}

      iss >> minCheck;

      if( !isspace(c) )
	minCheck = c + minCheck;
      
      if( minCheck.find("min") != string::npos )
	return true;
    }
  return false;

}




