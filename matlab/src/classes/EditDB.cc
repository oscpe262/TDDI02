#include "classes/headers/EditDB.h"
#include <iostream>
#include <QString>
using namespace std;

/*
  add_ingredient() adds a Ingredient object to the DB, if ingredient
  doesnt exist it adds it and returns true, if ingredient DOES exist
  the record is updated and return false
*/

bool EditDB::addRecipe(const Recipe& recipe)
{
  QSqlQuery tmp(db_);
  if(checkRecipe(recipe)) return false;
  else
    {
      tmp.finish();
      tmp.prepare("INSERT INTO Recipe(name,method,score,time) VALUES(:name,:price,:kcal)");
      tmp.bindValue(":name", recipe.getName().c_str());
      tmp.bindValue(":method", recpie.getMethod().c_str());
      tmp.bindValue(":score", recipe.getScore());
      tmp.bindValue(":time", recipe.getTime());
}


bool EditDB::addIngredient(const Ingredient& ingredient)
{
  QSqlQuery tmp(db_);
  if(checkIngredient(ingredient)) return false;
  else
    {
      tmp.finish();
      tmp.prepare("INSERT INTO Ingredient(name,price,kcal) VALUES(:name,:price,:kcal)");
      tmp.bindValue(":name",ingredient.getName().c_str());
      tmp.bindValue(":price",ingredient.getPrice());
      tmp.bindValue(":kcal",ingredient.getKcal());
      tmp.exec();
      return true;
    } 
 }
 

/*
  updateIngredient() updates price and kcal value of the ingredient added
*/

bool EditDB::updateIngredient(const Ingredient& ingredient)
{
  QSqlQuery tmp(db_);
  if(!checkIngredient(ingredient)) return false;
  else
    {
      tmp.finish();
      tmp.prepare("INSERT INTO Ingredient(price,kcal) VALUES(:price,:kcal) WHERE name=:name");
      tmp.bindValue(":name",ingredient.getName().c_str());
      tmp.bindValue(":price",ingredient.getPrice());
      tmp.bindValue(":kcal",ingredient.getKcal());
      tmp.exec();
      return false;
    }
}

  
/*
  remove_ingredient() removes a ingredient from the database and returns
  true, can be called both using string and Ingredient objects
*/

bool EditDB::removeIngredient(const string& ingredient)
{
  QSqlQuery tmp(db_);
  if(checkIngredient(ingredient))
    {
      tmp.prepare("DELETE FROM Ingredient WHERE name=:name");
      tmp.bindValue(":name",ingredient.c_str());
      tmp.exec();
      return true;
    }
  else return false;
}
bool EditDB::removeIngredient(const Ingredient& ingredient)
{
  return removeIngredient(ingredient.getName());
}



