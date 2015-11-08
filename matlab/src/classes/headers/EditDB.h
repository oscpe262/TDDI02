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
  
  bool add_recipe();
  bool add_ingredient(const Ingredient& ingredient);
  bool add_comment();
  bool add_tool();
  
  bool remove_recipe();
  bool remove_ingredient(const string& ingredient);
  bool remove_ingredient(const Ingredient& ingredient);
  bool remove_tool();
  bool remove_comment();

 private:


  
  
};

#endif

