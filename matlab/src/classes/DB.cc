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
  if(!ok) cerr << "FEL DATABAS KUNDE INTE ÖPPNAS";
  QSqlQuery tmp(db_);
  query_ = tmp;
}

/*
  create_db() builds the database tables
*/ 

void DB::createDb()
{ 
  //Creating tables for strong entitys
  
  query_ = db_.exec("CREATE TABLE Recipe(name VARCHAR(20),method VARCHAR(200), score int(10), time int(10), PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Ingredient(name VARCHAR(20),price INT(10),kcal INT(10),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Allergy(name VARCHAR(10),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Tool(name varchar(20),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Comments(id int(5),recipe_name VARCHAR(20), comment VARCHAR(50), PRIMARY KEY(ID), FOREIGN KEY(recipe_name) REFERENCES Recipe(name))");

  //Creating tables for M-N relations

  query_ = db_.exec("CREATE TABLE Used_for(recipe_name VARCHAR(20), ingredient_name VARCHAR(20), amount INT(10), FOREIGN KEY(recipe_name) REFERENCES Recipe(name), FOREIGN KEY(ingredient_name) REFERENCES Ingredient(name))");
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
  QSqlQuery tmp(db_);
  tmp.prepare("SELECT 1 FROM Ingredient WHERE name=:name");
  tmp.bindValue(":name", ingredient.c_str());
  tmp.exec();
  if(tmp.next()) return true;
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
  QSqlQuery tmp(db_);
  tmp.prepare("SELECT 1 FROM Recipe WHERE name=:name");
  tmp.bindValue(":name", recipe.c_str());
  tmp.exec();
  if(tmp.next()) return true;
  else return false;
}

bool DB::checkRecipe(const Ingredient& recipe)
{
  return checkRecipe(recipe.getName());
}
