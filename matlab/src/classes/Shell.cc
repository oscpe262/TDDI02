#include "classes/headers/Shell.h"
#include "classes/headers/Recipe.h"
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

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
 * *addRecipe
 * *removeReciope
 * *addIngredient
 * *removeIngredient
 */


void Shell::exportTxt( string& fileName = "null" )
{
  if( fileName == "null" )
    fileName = currentRecipe_.getName() + ".txt"; // fixa så att .txt-ändelsen är garanterad!!!

  // lägg till test för att filen inte redan existerar!!!

  ofstream recipeTxt {fileName};
  if( !recipeTxt )
    {
      recipeTxt.close();
      // kasta undantag!!!
    }
      
  recipeTxt << "# " << currentRecipe_.getName() << "\n"
	    << "Tillagningstid: c:a " << currentRecipe_.getMinutesTime() << " min\n"
	    << "============\n" // godtyckligt antal?

    for( RecipeIngredient& ri : currentRecipe_.getIngredients() )
      {
	recipeTxt << ri.getName() << " " << ri.getAmount() << " " << ri.getUnit() << "\n\n"; // convertToString( ri.getUnit() )?
      }

  recipeTxt << currentRecipe_.getMethod() << "\n\n";

  recipeTxt << "Uppskattat energiinnehåll: " << currentRecipe_.calcKcal(scaling_) << " kcal\n"
	    << "Uppskattat pris: " << currentRecipe_.calcPrice(scaling_) << " kr\n"
	    << "Betyg: " << currentRecipe_.getGrade() << "/5\n"
	    << "<!-- EOF -->";

  recipeTxt.close();
}

/*************
 *** [SDB] ***
 ************/

vector<MiniRecipe>& Shell::exactMatch( const string& name )
{
  currentRecipe_ = sDB_.receptmatchning(name);
  vector<MiniRecipe> vmr { MiniRecipe( currentRecipe_.getName(), currentRecipe_.getMinutesTime(), currentRecipe_.getGrade() ) };
  return vmr;
}

vector<MiniRecipe> Shell::getRecipeResults( SearchTerm& searchTerms )
{
  recipeSearchResults_ = sDB_.receptsökning(searchTerms); // Ersätt receptsökning med verkliga namnet!!!
  return recipeSearchResults_;
} 

vector<string> Shell::getIngredientList()
{
  ingredientFullList = sDB_.ingredienslistsökning(); // Ersätt ingredienslistsökning med verkliga namnet!!!
      return ingredientFullList_;
}

/*************
 *** [EDB] ***
 ************/
