/*
  Class: DB
  Description: Abstract base class for EditDB and SearchDB hold
  general database functionality
  Author: Erik Peyronson
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
  DB(string name);
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

  Ingredient       fetchIngredient(const string & name); //ALLERGENER OCH DIETER!!
  RecipeIngredient fetchRecipeIngredient(const string & name);
  IngredientList   fetchIngredientList(const string & recipe);
  Recipe           fetchRecipe(const string & name);
  
 string getAllergeneString(Allergene allergene);
 string getDietString(Diet allergene);
 protected:


  QSqlDatabase db_;
  QSqlQuery    query_;
  QSqlError    db_error_;

};


#endif
