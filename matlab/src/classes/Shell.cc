#include "classes/headers/Shell.h"
#include "classes/headers/Recipe.h"
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

/* extra function declarations */

bool fileExists( const string& name );


/*
 * exportTxt
 * *importTxt
 * *exportXml
 * *importXml
 * *setScaling
 *** [SDB] ***
 * exactMatch
 * getRecipeResults
 * getIngredientList
 * *openRecipe
 * *openIngredient
 *** [EDB] ***
 * addRecipe
 * removeReciope
 * addIngredient
 * removeIngredient
 *
 *** [extra] ***
 * fileExists
 */


void Shell::exportTxt( string fileName )
{
  if( fileName == "null" )
    fileName = currentRecipe_.getName() + ".txt"; // fixa så att .txt-ändelsen är garanterad!!!

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
      
  recipeTxt << "# " << currentRecipe_.getName() << "\n"
	    << "Tillagningstid: c:a " << currentRecipe_.getMinutesTime() << " min\n"
	    << "============\n"; // godtyckligt antal?

    for( RecipeIngredient& ri : currentRecipe_.getIngredients() )
      {
	recipeTxt << ri.getName() << " " << ri.getAmount() << " " << ri.getUnit() << "\n\n"; // convertToString( ri.getUnit() )?
      }

  recipeTxt << currentRecipe_.getMethod() << "\n\n";

  recipeTxt << "Uppskattat energiinnehåll: " << currentRecipe_.getKcal() << " kcal\n"
	    << "Uppskattat pris: " << currentRecipe_.getPrice() << " kr\n"
	    << "Betyg: " << currentRecipe_.getGrade() << "/5\n"
	    << "<!-- EOF -->";

  recipeTxt.close();
}

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
  ifstream filetest {name}; // lägg till test för att filen inte redan existerar!!!
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
