#include "classes/headers/Shell.h"
#include "classes/headers/Recipe.h"
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include <string>
#include <fstream>

using namespace std;

void Shell::exportTxt( string& fileName = "null" )
{
  if( fileName == "null" )
    fileName = currentRecipe_.getName() + ".txt";

  ofstream recipeTxt {fileName};
  if( !recipeTxt )
    {
      recipeTxt.close();
      // kasta undantag
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
