#include "classes/headers/EditDB.h"
#include <iostream>
#include <QString>
using namespace std;

/*
  add_ingredient() adds a Ingredient object to the DB, if ingredient
  doesnt exist it adds it and returns true, if ingredient DOES exist
  the record is updated and return false
*/

bool EditDB::addIngredient(const Ingredient& ingredient)
{
  QSqlQuery tmp(db_);

  if(checkIngredient(ingredient))
    {
      tmp.finish();
      tmp.prepare("INSERT INTO Ingredient(price,kcal) VALUES(:price,:kcal) WHERE name=:name");
      tmp.bindValue(":name",ingredient.getName().c_str());
      tmp.bindValue(":price",ingredient.getPrice());
      tmp.bindValue(":kcal",ingredient.getKcal());
      tmp.exec();
      return false;
    }
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



