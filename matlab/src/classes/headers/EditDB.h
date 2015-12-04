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
 EditDB() : DB("edit") {}
  
  bool addRecipe(const Recipe& recipe);
  bool updateRecipe(const Recipe& recipe);
  
  bool bindRelated(const vector<string>& related,const string& name);
  
  bool addIngredient(const Ingredient& ingredient);
  bool updateIngredient(const Ingredient& ingredient); //ALLERGENER OCH DIETER OTESTAT

  bool addRecipeIngredient(const RecipeIngredient& ingredient, const string& recipe);
  bool updateRecipeIngredient(const RecipeIngredient& ingredient, const string& recipe); //otestad
  
  bool addComment();
  bool addTool();
  
  bool removeRecipe(const string& name); //otestad
  bool removeRecipe(const Recipe& recipe);
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

