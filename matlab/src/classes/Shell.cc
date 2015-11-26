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

using namespace std;

/* extra function declarations */

bool fileExists( const string& name );
string unit2str( const Unit& unitvalue );
/*void readFromFile( istream& is, string&*/


/*
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
 * *openRecipe
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
 * unit2str
 */


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
  // lägg till kommentar med filnamn?
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

  ifstream openedFile {fileName};
  if( !recipeTxt )
    {
      recipeTxt.close();
      // kasta undantag
    }

  Recipe recipe;
  string fileContents;

  readFromFile(openedFile, fileContents);

  recipeTxt


}*/



/*************
 *** [SDB] ***
 ************/

vector<MiniRecipe> Shell::exactMatch( const string& name )
{
  currentRecipe_ = sDB_.fetchRecipe(name); // Ersätt funktionsnamn!!!
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
  ingredientFullList_ = sDB_.queryIngredientNames(); // Ersätt ingredienslistsökning med verkliga namnet!!!
  return ingredientFullList_;
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

bool Shell::addIngredient( const Ingredient& ingredient )
{
  return eDB_.addIngredient(ingredient); // Rätt funktion?
}

bool Shell::removeIngredient( const Ingredient& ingredient )
{
  return eDB_.removeIngredient(ingredient);
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
