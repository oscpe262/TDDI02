#include "classes/headers/DB.h"
#include <iostream>

/*
  constructor connects private member db_ to the database
*/

DB::DB()
{
  db_ = QSqlDatabase::addDatabase("QMYSQL");
  db_.setHostName("localhost");
  db_.setDatabaseName("matlabb");
  db_.setUserName("root");
  db_.setPassword("hejhejhej");
  bool ok = db_.open();
  if(!ok) throw DB_Exception("ERROR: Database could not be opened");
  QSqlQuery tmp_query(db_);
  query_ = tmp_query;
}

/*
  create_db() builds the database tables
*/ 

void DB::createDb()
{ 
  //Creating tables for strong entitys
  
  query_ = db_.exec("CREATE TABLE Recipe(name VARCHAR(50),method VARCHAR(200), score float(10), time int(10), PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Ingredient(name VARCHAR(30),price INT(10),kcal INT(10),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Allergy(name VARCHAR(10),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Tool(name varchar(20),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Comments(id int(5),recipe_name VARCHAR(20), comment VARCHAR(50), PRIMARY KEY(ID), FOREIGN KEY(recipe_name) REFERENCES Recipe(name))");

  //Creating tables for M-N relations

  query_ = db_.exec("CREATE TABLE Used_for(recipe_name VARCHAR(50), ingredient_name VARCHAR(20), amount INT(10), FOREIGN KEY(recipe_name) REFERENCES Recipe(name), FOREIGN KEY(ingredient_name) REFERENCES Ingredient(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Contained_in(ingredient_name VARCHAR(20), allergy_name VARCHAR(20), FOREIGN KEY(ingredient_name) REFERENCES Ingredient(name), FOREIGN KEY(allergy_name) REFERENCES Allergy(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Needed_for(recipe_name VARCHAR(20), tool_name VARCHAR(20),FOREIGN KEY(recipe_name) REFERENCES Recipe(name),  FOREIGN KEY(tool_name) REFERENCES Tool(name))");
  lastQuery(query_);
  
  //Error message print
  cerr << db_.lastError().text().toStdString() << endl;
}

/*
  Clear_db() Clears the database tables
*/

void DB::clearDb()
{
  //Drop m-n tables
  query_ = db_.exec("DROP TABLE Used_for");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Contained_in");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Needed_for");
  lastQuery(query_);
  
  //Drop Strong entitys
  query_ = db_.exec("DROP TABLE Ingredient");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Allergy");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Tool");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Comments");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Recipe");
  lastQuery(query_);

  db_error_ = db_.lastError();
  cerr << db_.lastError().text().toStdString();

  query_.finish();
}

void DB::printTables()
{
  query_.exec("SHOW TABLES");

  query_.finish();
}

/*
  Last query prints the last executed query executed by q
*/

void DB::lastQuery(QSqlQuery q)
{
  cout << q.lastQuery().toStdString() << endl << endl;
}

/*
  check_ingredient() checks if a ingredient is stored in the db returns
  true if ingredient exists else false can be called both using string
  and Ingredient objects
*/

bool DB::checkIngredient(const string& ingredient)
{
  QSqlQuery tmp_query(db_);
  tmp_query.prepare("SELECT 1 FROM Ingredient WHERE name=:name");
  tmp_query.bindValue(":name", ingredient.c_str());
  tmp_query.exec();
  if(tmp_query.next()) return true;
  else return false;
}

bool DB::checkIngredient(const Ingredient& ingredient)
{
  return checkIngredient(ingredient.getName());
}

/*
  checkRecipe() checks if a recipe is stored in the db returns
  true if recipe exists else false can be called both using string
  and recipe objects
*/

bool DB::checkRecipe(const string& recipe)
{
  QSqlQuery tmp_query(db_);
  tmp_query.prepare("SELECT 1 FROM Recipe WHERE name=:name");
  tmp_query.bindValue(":name", recipe.c_str());
  tmp_query.exec();
  if(tmp_query.next()) return true;
  else return false;
}

bool DB::checkRecipe(const Recipe& recipe)
{
  return checkRecipe(recipe.getName());
}

/*
 fetchIngredient() fetches ingredient information from the db and
 returns a Ingredient object 
 */

Ingredient DB::fetchIngredient(const string & name)
{
  QSqlQuery tmp_query(db_);
  tmp_query.prepare("SELECT * FROM Ingredient WHERE name = :name");
  tmp_query.bindValue(":name",name.c_str());
  tmp_query.exec();
  tmp_query.next();
  return Ingredient(tmp_query.value(0).toString().toStdString(),tmp_query.value(1).toInt(),tmp_query.value(2).toInt());
}

/*
 fetchRecipeIngredient() fetches ingredient information from the db and
 returns a RecipeIngredient object 
*/

RecipeIngredient DB::fetchRecipeIngredient(const string & name)
{
  QSqlQuery tmp_query(db_);
  // if(!checkIngredient(name)) throw DB_Exception("ERROR: Ingredient not in database");
  tmp_query.prepare("SELECT * FROM Ingredient WHERE name = :name");
  tmp_query.bindValue(":name",name.c_str());
  tmp_query.exec();
  tmp_query.next();
  return RecipeIngredient(tmp_query.value(0).toString().toStdString(),
		    tmp_query.value(1).toInt(),
		    tmp_query.value(2).toInt());
}
/*
  fetchRecipe() Fetches Recipie info from db and returns recipe object
*/

Recipe DB::fetchRecipe(const string & name)
{
  QSqlQuery query(db_);
  if(!checkRecipe(name)) throw DB_Exception("ERROR: Recipe not in database");
  query.prepare("SELECT * FROM Recipe WHERE name = :name");
  query.bindValue(":name",name.c_str());
  query.exec();
  query.next();
 
  Recipe recipe;
 /*
  (query.value(0).toString().toStdString(),
		query.value(1).toString().toStdString(),
		query.value(2).toInt(),query.value(3).toInt());
  */
  return recipe;
}
