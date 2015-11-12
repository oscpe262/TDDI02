/*
  Klassen DB är abstrakt basklass för EditDB och SearchDB

  kontouppgifter till databasen:
  User:              Password:             Databas:
  TDDI02_HT15_02     TDDI02_HT15_02b957
 */
#ifndef DB_H
#define DB_H
#include <QtSql>
#include <QSqlDatabase>
#include <string>
#include "classes/headers/Ingredient.h"
#include "classes/headers/Recipe.h"
using namespace std;

class DB_Exception : public std::exception
{
 public:
  explicit DB_Exception(const std::string& message):
  msg_(message){}
  virtual char const * what() const noexcept {return msg_.c_str();}

 private:
  string msg_;
};

class DB
{
 public:
  //Constructors
  DB();
  DB(const DB&) = default;
  DB(DB&& ) = default;
  //Destructor
  ~DB() {db_.close();}
  
  void createDb();               //Creates database
  void clearDb();                //Clears database
  
  void printTables();                       
  void lastQuery(QSqlQuery q);   //prints last query on cout

  bool checkIngredient(const string& ingredient);
  bool checkIngredient(const Ingredient& ingredient);

  bool checkRecipe(const string& recipe);
  bool checkRecipe(const Recipe& recipe);

  Ingredient fetchIngredient(const string & name);
  RecipeIngredient fetchRecipeIngredient(const string & name);

  Recipe fetchRecipe(const string & name);
  
 protected:
  QSqlDatabase db_;
  QSqlQuery    query_;
  QSqlError    db_error_;

};


#endif
