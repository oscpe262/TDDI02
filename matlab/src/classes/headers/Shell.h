#ifndef SHELL_H
#define SHELL_H
#include <vector>
#include <string>
#include "Recipe.h"
#include "Ingredient.h"
#include "SearchTerm.h"
#include "DB.h"
#include "EditDB.h"
#include "SearchDB.h"

using namespace std;

string unit2str( const Unit& unitvalue );

class Shell
{
 public:

  void                exportTxt( string fileName = "null" );
  Recipe              importTxt( string fileName = "null" );
  void                exportXml( string );
  void                importXml( string );

  void                setScaling( double scaling ) { scaling_ = scaling; }
 

 
  // SearchDB-funktioner
  vector<MiniRecipe>  exactMatch( const string& ); //
  vector<MiniRecipe>  getRecipeResults( SearchTerm& ); // returnera konstreferens? RecipeList
  vector<string>      getIngredientNames(); // returnera konstreferens? IngredientNames
  Recipe              openRecipe( const string& ); // eller sträng?
  Ingredient          openIngredient( const string& );

  // EditDB-funktioner
  bool                addRecipe( const Recipe& ); // tillägg och redigering? bool?
  bool                removeRecipe( const Recipe& );
  bool                addIngredient( const Ingredient& );
  bool                removeIngredient( const Ingredient& ); // överlagring för Ingredient? string? currentMedlemmar?

  // private:

  SearchDB            sDB_;
  EditDB              eDB_;
  
  Recipe              currentRecipe_;
  Ingredient          currentIngredient_;
  vector<MiniRecipe>  recipeSearchResults_;     // RecipeList
  vector<string>      ingredientFullList_;      // IngredientNames 
  double              scaling_;
};


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

#endif
