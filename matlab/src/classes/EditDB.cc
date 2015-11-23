#include "classes/headers/EditDB.h"
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include "classes/headers/Recipe.h"
#include <iostream>
#include <QString>
#include <algorithm>
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
  tmp.bindValue(":score", recipe.getGrade());
  tmp.bindValue(":time", recipe.getMinutesTime());
  tmp.exec();
  tmp.finish();
  IngredientList ingredient_list = recipe.getIngredients();
  for(auto i : ingredient_list)
    {
      addRecipeIngredient(i, recipe.getName());
      tmp.finish();
    } 
  return true;
}
  bool EditDB::addIngredient(const Ingredient& ingredient)
{
  AllergeneArray allergenes = ingredient.getAllergenes();
  QSqlQuery tmp(db_);
  if(checkIngredient(ingredient)) return false;
  tmp.finish();
  tmp.prepare("INSERT INTO Ingredient(name,price,kcal) VALUES(:name,:price,:kcal)");
  tmp.bindValue(":name",ingredient.getName().c_str());
  tmp.bindValue(":price",ingredient.getPrice());
  tmp.bindValue(":kcal",ingredient.getKcal());
  tmp.exec();
  tmp.clear();
  for(int i = 0; i < 14; ++i)
    {
      if (allergenes.at(i))
	{
	  tmp.prepare("INSERT INTO Allergene_in(ingredient_name, allergene_name) VALUES(:ingredient_name,:allergene_name)");
	  tmp.bindValue(":ingredient_name",ingredient.getName().c_str());
	  tmp.bindValue("allergene_name",getAllergeneString(Allergene(i)));
	  tmp.exec();
	  tmp.clear();
	  cerr << tmp.lastError().text().toStdString();
	}
    }
  return true;
   
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
  if(!checkIngredient(ingredient.getName())) return false;  
  tmp.prepare("INSERT INTO Used_for(recipe_name,ingredient_name,amount,unit) VALUES(:recipe_name,:ingredient_name,:amount,:unit)");
  tmp.bindValue(":recipe_name", recipe.c_str());
  tmp.bindValue(":ingredient_name", ingredient.getName().c_str());
  tmp.bindValue(":amount",ingredient.getAmount());
  tmp.bindValue(":unit",static_cast<int>(ingredient.getUnit()));
  cerr << tmp.lastError().text().toStdString();
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

/*
  getAllergeneString() is a help function that accepts allergy enum
  and returns a c-string as a result to be used while adding
  ingredients in the database
*/
char const* EditDB::getAllergeneString(Allergene allergene)
{
  switch((int)allergene)
    {
    case 0:
      return "fruit";
      break;
    case 1:
      return "garlic";
      break;
    case 2:
      return "hot_peppers";
      break;
    case 3:
      return "oats";
      break;
    case 4:
      return "wheat";
      break;
    case 5:
      return "gluten";
      break;
    case 6:
      return "peanut";
      break; 
    case 7:
      return "tree_nut";
      break;
    case 8:
      return "shellfish";
      break;
    case 9:
      return "alpha_gal";
      break;
    case 10:
      return "egg";
      break;
    case 11:
      return "milk";
      break;
    case 12:
      return "lactose";
      break;
    case 13:
      return "soy";
      break;
    }

}
