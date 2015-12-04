/*
  Class: EditDB
  Description: Responsible for making changes in the database
  Author: Erik Peyronson
*/

#include "classes/headers/EditDB.h"
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include "classes/headers/Recipe.h"
#include <iostream>
#include <QString>
#include <algorithm>
using namespace std;

/*
  Add and update recipe add does what the name suggests both return
  true if a recipe is added or updated and false if its already there
  respectivly not there
*/

bool EditDB::addRecipe(const Recipe& recipe)
{
  QSqlQuery tmp(db_);
  if(recipe.getName().size() == 0)
    return false;
  if(checkRecipe(recipe))
  {
    return updateRecipe(recipe);
  }
  else
    {
      tmp.finish();
      tmp.prepare("INSERT INTO Recipe(name,method,score,time,price,kcal,portions) VALUES(:name,:method,:score,:time,:price,:kcal,:portions)");
      tmp.bindValue(":name", recipe.getName().c_str());
      tmp.bindValue(":method", recipe.getMethod().c_str());
      tmp.bindValue(":score", recipe.getGrade());
      tmp.bindValue(":time", recipe.getMinutesTime());
      cerr << endl << recipe.getName() << " kcal: " << calculateKcal(recipe);
      cerr << endl << recipe.getName() << " kcal: " << calculateKcal(recipe);
      tmp.bindValue(":price", calculatePrice(recipe));
      tmp.bindValue(":kcal", calculateKcal(recipe));
      tmp.bindValue(":portions", recipe.getPortions());
      cerr << tmp.lastError().text().toStdString();		
      tmp.exec();
      //tmp.finish();
      IngredientList ingredient_list = recipe.getIngredients();
      for(auto i : ingredient_list)
	{
	  addRecipeIngredient(i, recipe.getName());
	  tmp.finish();
	}
      bindRelated(recipe.getRelated(),recipe.getName());
    }
  return true;
}

bool EditDB::bindRelated(const vector<string>& related,const string& name)
{
  QSqlQuery query(db_);
  for(auto i : related)
    {
      if(!checkRecipe(i)) throw DB_Exception("Fel: " + i + " finns ej i databasen");
      query.prepare("INSERT INTO Related_to(recipe,related) VALUES(:recipe,:related)");
      query.bindValue(":recipe", name.c_str());
      query.bindValue(":related", i.c_str());
      lastQuery(query);
      cerr << query.lastError().text().toStdString();
      query.exec();
    }
}

bool EditDB::updateRecipe(const Recipe& recipe)
{
  QSqlQuery query(db_);
  // if(checkRecipe(recipe)) return false;
  query.prepare("INSERT INTO recipe(method,score,time,price,kcal,portions) VALUES(:method,:score,:time,:price,:kcal,:portions WHERE name= :name)");
  query.bindValue(":method", recipe.getMethod().c_str());
  query.bindValue(":score", recipe.getGrade());
  query.bindValue(":time", recipe.getMinutesTime());
  query.bindValue(":price",recipe.getPrice());
  query.bindValue(":kcal", recipe.getKcal());
  query.bindValue(":portions",recipe.getPortions());
  
  query.finish();
  query.prepare("DELETE FROM Used_for WHERE recipe_name =:recipe_name");
  query.bindValue(":recipe_name", recipe.getName().c_str());
  query.exec();
  
  IngredientList ingredient_list = recipe.getIngredients();
  for(auto i : ingredient_list)
    {
      addRecipeIngredient(i, recipe.getName());
      query.finish();
    } 
  
  query.finish();
  query.prepare("DELETE FROM Related_to WHERE Recipe = :Recipe");
  query.bindValue(":Recipe", recipe.getName().c_str());
  bindRelated(recipe.getRelated(),recipe.getName()); 
    
  return true;
}

/*
  add_ingredient() adds a Ingredient object to the DB, if ingredient
  doesnt exist it adds it and returns true, if ingredient DOES exist
  the record is updated and return false
*/

bool EditDB::addIngredient(const Ingredient& ingredient)
{
  AllergeneArray allergenes = ingredient.getAllergenes();
  DietArray diets = ingredient.getDiets();
  QSqlQuery tmp(db_);
  if(checkIngredient(ingredient)) 
    return updateIngredient(ingredient);
  tmp.finish();
  tmp.prepare("INSERT INTO Ingredient(name,price,kcal) VALUES(:name,:price,:kcal)");
  tmp.bindValue(":name",ingredient.getName().c_str());
  tmp.bindValue(":price",ingredient.getPrice());
  tmp.bindValue(":kcal",ingredient.getKcal());
  tmp.exec();
  tmp.clear();
  for(int i = 0; i < 14; ++i)
    {
      if (allergenes[i])
	{
	  tmp.prepare("INSERT INTO Allergene_in(ingredient_name, allergene_name) VALUES(:ingredient_name,:allergene_name)");
	  tmp.bindValue(":ingredient_name",ingredient.getName().c_str());
	  cerr << "GetAllergene: " << getAllergeneString(Allergene(i));
	  tmp.bindValue(":allergene_name",getAllergeneString(Allergene(i)).c_str());
	  tmp.exec();
	  cerr << tmp.lastError().text().toStdString();
	  tmp.clear();
	}
    }
  
  for(int i=0; i < 4; ++i)
    {
        if (diets[i])
  	{
  	  tmp.prepare("INSERT INTO Diet_in(ingredient_name, diet_name) VALUES(:ingredient_name,:diet_name)");
  	  tmp.bindValue(":ingredient_name",ingredient.getName().c_str());
  	  tmp.bindValue(":diet_name",getDietString(Diet(i)).c_str());
  	  tmp.exec();
	  cout << endl << "DIET!\n";
	  lastQuery(tmp);
	  cout << endl;
  	  cerr << tmp.lastError().text().toStdString();
  	  tmp.clear();
	}
    }
	return true;
   
}
 
/*
  updateIngredient() updates price and kcal value of the ingredient added
*/

bool EditDB::updateIngredient(const Ingredient& ingredient)
{
  AllergeneArray allergenes = ingredient.getAllergenes();
  DietArray diets = ingredient.getDiets();
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
      tmp.finish();
      tmp.prepare("DELETE FROM Allergene_in WHERE ingredient_name = :name");
      tmp.bindValue(":name",ingredient.getName().c_str());
      tmp.exec();
      tmp.finish();
      tmp.prepare("DELETE FROM Diet_in WHERE ingredient_name = :name");
      tmp.bindValue(":name",ingredient.getName().c_str());
      tmp.exec();

      for(int i = 0; i < 14; ++i)
	{
	  if (allergenes[i])
	    {
	      tmp.prepare("INSERT INTO Allergene_in(ingredient_name, allergene_name) VALUES(:ingredient_name,:allergene_name)");
	      tmp.bindValue(":ingredient_name",ingredient.getName().c_str());
	      cerr << "GetAllergene: " << getAllergeneString(Allergene(i));
	      tmp.bindValue(":allergene_name",getAllergeneString(Allergene(i)).c_str());
	      tmp.exec();
	      cerr << tmp.lastError().text().toStdString();
	      tmp.clear();
	    }
	}
  
      for(int i=0; i < 4; ++i)
	{
	  if (diets[i])
	    {
	      tmp.prepare("INSERT INTO Diet_in(ingredient_name, diet_name) VALUES(:ingredient_name,:diet_name)");
	      tmp.bindValue(":ingredient_name",ingredient.getName().c_str());
	      tmp.bindValue(":diet_name",getDietString(Diet(i)).c_str());
	      tmp.exec();
	      cout << endl << "DIET!\n";
	      lastQuery(tmp);
	      cout << endl;
	      cerr << tmp.lastError().text().toStdString();
	      tmp.clear();
	    }
	}
      return true;
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
  removeRecipe() removes a recipe from the DB can be called both using
  a string and a recipe object
*/
bool EditDB::removeRecipe(const string& name)
{
  if(checkRecipe(name))
    {
      QSqlQuery query(db_);
      query.prepare("DELETE FROM Recipe WHERE name=:name");
      query.bindValue(":name",name.c_str());
      query.exec();
      query.finish();
      query.prepare("DELETE FROM Used_for WHERE recipe_name=:name");
      query.bindValue(":name",name.c_str());
      query.exec();
      return true;
    }
  return false;
  
}
bool EditDB::removeRecipe(const Recipe& recipe)
{
  return removeRecipe(recipe.getName());
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
  calculatePrice() and calculateKcal() calculates a recipes price and
  kcal per portion in the recipe.
*/
int EditDB::calculatePrice(const Recipe& recipe)
{
  int total_price = 0;
  IngredientList ingredients = recipe.getIngredients();
  for(auto i : ingredients)
    total_price += calculateIngredientPrice(i);
  cout << endl << recipe.getName() << " total price " << total_price 
       << " per portion: " << total_price/recipe.getPortions();

  return total_price/recipe.getPortions();
}
int EditDB::calculateKcal(const Recipe& recipe)
{
  int total_kcal = 0;
  IngredientList ingredients = recipe.getIngredients();
  for(auto i : ingredients)
    total_kcal += calculateIngredientKcal(i);
  return total_kcal/recipe.getPortions();
}

int EditDB::calculateIngredientPrice(const RecipeIngredient ingredient)
{
  QSqlQuery query(db_);
  double price;
  query.prepare("SELECT Ingredient.price FROM Ingredient WHERE Ingredient.name = :name");
  query.bindValue(":name",ingredient.getName().c_str());
  query.exec();
  query.next();
  price = query.value(0).toDouble();
  cerr << ingredient.getName() << " costs: " << price << endl;
  switch(ingredient.getUnit())
  {
  case gram:
    return static_cast<int>((price/1000)*ingredient.getAmount()); //Price is in kr/kg
    break;					//amount is in gram
  case deciliter:
    return static_cast<int>((price/10)*ingredient.getAmount());  //price is in kr/l amount is in deciliter
    break;
  case tablespoon:
    return static_cast<int>(((price/1000)*15)*ingredient.getAmount()); //price in kr/l amount is in n*15ml
    break;
  case teaspoon:
    return static_cast<int>(((price/1000)*5)*ingredient.getAmount());
    break;
  case pcs:
    return static_cast<int>(price*ingredient.getAmount());
    break;
  default:
    return 0;
    break;
  }

}

int EditDB::calculateIngredientKcal(const RecipeIngredient ingredient)
{
  QSqlQuery query(db_);
  double kcal;
  query.prepare("SELECT Ingredient.kcal FROM Ingredient WHERE Ingredient.name = :name");
  query.bindValue(":name",ingredient.getName().c_str());
  query.exec();
  query.next();
  kcal = query.value(0).toDouble();
  switch(ingredient.getUnit()) //Kcal is allways given in kcal/100g
    {
     case gram:
    return static_cast<int>((kcal/100)*ingredient.getAmount()); 
    break;					
  case deciliter:
    return static_cast<int>(kcal*ingredient.getAmount());  
    break;
  case tablespoon:
    return static_cast<int>(((kcal/100)*15)*ingredient.getAmount()); 
    break;
  case teaspoon:
    return static_cast<int>(((kcal/100)*5)*ingredient.getAmount());
    break;
  case pcs:
    return static_cast<int>(kcal*ingredient.getAmount());
    break;
  default:
    return 0;
    break; 
    }
}
