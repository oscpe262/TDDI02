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

class Shell
{
 public:

  void                exportTxt( string& );
  void                importTxt( string& );
  void                exportXml( string& );
  void                importXml( string& );

  void                setScaling( double scaling ) { scaling_ = scaling; }
 

 
  // SearchDB-funktioner
  vector<MiniRecipe>& exactMatch( const string& );
  vector<MiniRecipe>  getRecipeResults( SearchTerm& söktermer ); // returnera konstreferens?
  vector<string>      getIngredientList(); // returnera konstreferens?
  Recipe              openRecipe( const MiniRecipe& ); // eller sträng?
  Ingredient          openIngredient( const string& );

  // EditDB-funktioner
  void                addRecipe( const Recipe& ); // tillägg och redigering?
  void                removeRecipe( const Recipe& );
  void                addIngredient( const Ingredient& );
  void                removeIngredient( const string& ); // överlagring för Ingredient?

  // private:

  SearchDB            sDB_;
  EditDB              eDB_;
  
  Recipe              currentRecipe_;
  Ingredient          currentIngredient_;
  vector<MiniRecipe>  recipeSearchResults_;     // RecipeList
  vector<string>      ingredientFullList_;      // IngredientList // IngredientList = RecipeIngredient-listan i ett receptet just nu
  double              scaling_;
};
#endif
