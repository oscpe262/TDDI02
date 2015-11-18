#ifndef SHELL_H
#define SHELL_H
#include <vector>
#include <string>
#include "Recipe.h"
#include "Ingredient.h"

using namespace std;

class Shell
{
 public:

  void exportTxt( string& );



  // private:

  Recipe currentRecipe_;
  Ingredient currentIngredient_;
  vector<MiniRecipe> recipeSearchResults_;
  vector<string> ingredientFullList_;
  double scaling_;
  // searchterms_
};
#endif
