#include "classes/headers/EditDB.h"
#include <iostream>
#include <QString>
using namespace std;

EditDB::EditDB()
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

void EditDB::create_db()
{ 
  //Creating tables for strong entitys
  
  query_ = db_.exec("CREATE TABLE Recipe(name VARCHAR(20),method VARCHAR(200), score int(10), time int(10), PRIMARY KEY(name))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Ingredient(name VARCHAR(20),price INT(10),kcal INT(10),PRIMARY KEY(name))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Allergy(name VARCHAR(10),PRIMARY KEY(name))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Tool(name varchar(20),PRIMARY KEY(name))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Comments(id int(5),recipe_name VARCHAR(20), comment VARCHAR(50), PRIMARY KEY(ID), FOREIGN KEY(recipe_name) REFERENCES Recipe(name))");

  //Creating tables for M-N relations

  query_ = db_.exec("CREATE TABLE Used_for(recipe_name VARCHAR(20), ingredient_name VARCHAR(20), amount INT(10), FOREIGN KEY(recipe_name) REFERENCES Recipe(name), FOREIGN KEY(ingredient_name) REFERENCES Ingredient(name))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Contained_in(ingredient_name VARCHAR(20), allergy_name VARCHAR(20), FOREIGN KEY(ingredient_name) REFERENCES Ingredient(name), FOREIGN KEY(allergy_name) REFERENCES Allergy(name))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Needed_for(recipe_name VARCHAR(20), tool_name VARCHAR(20),FOREIGN KEY(recipe_name) REFERENCES Recipe(name),  FOREIGN KEY(tool_name) REFERENCES Tool(name))");
  last_query(query_);
  
  //Error message print
  cerr << db_.lastError().text().toStdString() << endl;
}

void EditDB::clear_db()
{
  //Drop m-n tables
  query_ = db_.exec("DROP TABLE Used_for");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Contained_in");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Needed_for");
  last_query(query_);
  
  //Drop Strong entitys
  query_ = db_.exec("DROP TABLE Ingredient");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Allergy");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Tool");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Comments");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Recipe");
  last_query(query_);

  db_error_ = db_.lastError();
  cerr << db_.lastError().text().toStdString();
}

void EditDB::print_tables()
{
  query_.exec("SHOW TABLES");

  query_.finish();
}

void EditDB::last_query(QSqlQuery q)
{
  cout << q.lastQuery().toStdString() << endl << endl;
}

bool EditDB::add_ingredient(const Ingredient& ingredient)
{
  QSqlQuery tmp(db_);

  if(check_ingredient(ingredient))
    {
      tmp.finish();
      tmp.prepare("INSERT INTO Ingredient(name,price,kcal) VALUES(:name,:price,:kcal)");
      tmp.bindValue(":name",ingredient.get_name().c_str());
      tmp.bindValue(":price",ingredient.get_price());
      tmp.bindValue(":kcal",ingredient.get_kcal());
      tmp.exec();
      return false;
    }
  else
    {
      tmp.finish();
      tmp.prepare("INSERT INTO Ingredient(price,kcal) VALUES(:price,:kcal) WHERE name=:name");
      tmp.bindValue(":name",ingredient.get_name().c_str());
      tmp.bindValue(":price",ingredient.get_price());
      tmp.bindValue(":kcal",ingredient.get_kcal());
      tmp.exec();
      return true;
    }
}

bool EditDB::check_ingredient(const string& ingredient)
{
  QSqlQuery tmp(db_);
  tmp.prepare("SELECT 1 FROM Ingredient WHERE name=:name");
  tmp.bindValue(":name", ingredient.c_str());
  tmp.exec();
  if(tmp.next()) return true;
  else return false;
}

bool EditDB::check_ingredient(const Ingredient& ingredient)
{
  return check_ingredient(ingredient.get_name());
}

