#ifndef SHELL_H
#define SHELL_H
#include <vector>
#include <string>
#include <stdexcept>
#include "Recipe.h"
#include "Ingredient.h"
#include "SearchTerm.h"
#include "DB.h"
#include "EditDB.h"
#include "SearchDB.h"

using namespace std;

class Shell_Exception : public std::exception
{
 public:
  explicit Shell_Exception( const std::string& what_arg )
    : msg_{ what_arg } {}
  explicit Shell_Exception( const char* what_arg )
    : msg_{ what_arg } {}

  virtual char const * what() const noexcept { return msg_.c_str(); }

 private:
  string msg_;
};


// string unit2string( const Unit& unitvalue );

class Shell
{
 public:

  void                exportTxt( const string& recipeName, string fileName = "null" );
  void                exportTxt( const Recipe& recipe, string fileName = "null" );
  Recipe              importTxt( string fileName = "null" );

  void                exportXml( const string& recipeName, string filepath = "null" );
  void                exportXml( const Recipe& recipe, string filepath = "null" );
  Recipe              importXml( const string& );

  //  void                setScaling( double scaling ) { scaling_ = scaling; }
 

 
  // SearchDB-funktioner
  vector<MiniRecipe>  exactMatch( const string& ); //
  vector<MiniRecipe>  getRecipeResults( SearchTerm& ); // returnera konstreferens? RecipeList
  vector<string>      getIngredientNames(); // returnera konstreferens? IngredientNames
  Recipe              openRecipe( const string& );
  Ingredient          openIngredient( const string& );

  // EditDB-funktioner
  bool                addRecipe( const Recipe& );
  bool                removeRecipe( const Recipe& );
  bool                removeRecipe( const string& );
  bool                addIngredient( const Ingredient& );
  bool                removeIngredient( const Ingredient& );
  bool                removeIngredient( const string& );

  // Hjälpfunktioner
  void                tagIngredient(ifstream & fs, IngredientList & IL);

  // private:

  SearchDB            sDB_;
  EditDB              eDB_;
  
  Recipe              currentRecipe_;
  Ingredient          currentIngredient_;
  vector<MiniRecipe>  recipeSearchResults_;     // RecipeList
  vector<string>      ingredientFullList_;      // IngredientNames 
  // double              scaling_;
};



#endif
