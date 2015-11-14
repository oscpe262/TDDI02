#include "classes/headers/EditDB.h"
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include "classes/headers/Recipe.h"
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
  tmp.finish();
  tmp.prepare("INSERT INTO Recipe(name,method,score,time) VALUES(:name,:method,:score,:time)");
  tmp.bindValue(":name", recipe.getName().c_str());
  tmp.bindValue(":method", recipe.getMethod().c_str());
  cerr << recipe.getGrade() << endl;
  tmp.bindValue(":score", recipe.getGrade());
  cerr << recipe.getMinutesTime() << endl;
  tmp.bindValue(":time", recipe.getMinutesTime());
  tmp.exec();
  //db_error_ = tmp.lastError();
  cerr << tmp.lastError().text().toStdString();
  tmp.finish();
  /*
  IngredientList ingredient_list = recipe.getIngredients();
  for(auto i : ingredient_list)
    if(!addRecipeIngredient(i, recipe.getName())) return false ;
  */
  return true;
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
   addRecipeIngredient() like above for recipeingredients
*/
bool EditDB::addRecipeIngredient(const RecipeIngredient& ingredient, const string& recipe)
{
  QSqlQuery tmp(db_);
  if(checkIngredient(ingredient.getName())) return false;
  tmp.prepare("INSERT INTO Needed_for(recipe_name,ingredient_name,amount), Values(:recipe_name, :ingredient_name, :amount)");
  tmp.bindValue(":recipe_name", recipe.c_str());
  tmp.bindValue(":ingredient_name",ingredient.getName().c_str());
  tmp.bindValue(":amount",ingredient.getAmount());
  tmp.exec();
  return true;
}
/*
  updateRecipeIngredient updates already added RecipeIngredient
*/

bool EditDB::updateRecipeIngredient(const RecipeIngredient& ingredient,const string& recipe)
{
  QSqlQuery tmp(db_);
  if(!checkIngredient(ingredient.getName()) || !checkRecipe(recipe)) return false;
  tmp.prepare("INSERT INTO Needed_for(amount), Values( :amount) WHERE recipe_name = :recipe_name AND ingredient_name=:ingredient_name");
  tmp.bindValue(":recipe_name", recipe.c_str());
  tmp.bindValue(":ingredient_name",ingredient.getName().c_str());
  tmp.bindValue(":amount",ingredient.getAmount());
  tmp.exec();
  return true;
}

/*
  remove_ingredient() removes a ingredient from the database and
  returns true, can be called both using string and Ingredient objects
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



