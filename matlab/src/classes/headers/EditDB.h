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
#include <iostream>

class EditDB : public DB{
 public:
 EditDB() : DB() {}
  
  bool addRecipe();
  bool addIngredient(const Ingredient& ingredient);
  bool addComment();
  bool addTool();
  
  bool removeRecipe();
  bool removeIngredient(const string& ingredient);
  bool removeIngredient(const Ingredient& ingredient);
  bool removeTool();
  bool removeComment();

 private:


  
  
};

#endif

