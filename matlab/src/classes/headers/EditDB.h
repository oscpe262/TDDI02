/*
  Klassen EditDB Är ansvarig ändringar i databasen

  kontouppgifter till databasen:
  User:              Password:             Databas:
  TDDI02_HT15_02     TDDI02_HT15_02b957
 */

#ifndef EDITDB_H
#define EDITDB_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include "classes/headers/Ingredient.h"
#include "classes/headers/DB.h"
#include "classes/headers/Recipe.h"
#include <iostream>

class EditDB : public DB{
 public:
 EditDB() : DB() {}
  
  bool addRecipe(const Recipe& recipe);
  
  bool addIngredient(const Ingredient& ingredient);
  bool updateIngredient(const Ingredient& ingredient);

  bool addRecipeIngredient(const RecipeIngredient& ingredient, const string& recipe);
  bool updateRecipeIngredient(const RecipeIngredient& ingredient, const string& recipe);
  
  bool addComment();
  bool addTool();
  
  bool removeRecipe(const string& name);
  bool removeRecipe(const Recipe& name);
  bool removeIngredient(const string& ingredient);
  bool removeIngredient(const Ingredient& ingredient);
  bool removeTool();
  bool removeComment();

  int calculatePrice(const Recipe& recipe);
   int calculateKcal(const Recipe& recipe);
 private:
  int calculateIngredientPrice(const RecipeIngredient ingredient);
  int calculateIngredientKcal(const RecipeIngredient ingredient);
  
  
 
};

#endif

