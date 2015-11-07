#include "classes/headers/EditDB.h"
#include <iostream>
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
  query_ = db_.exec("CREATE TABLE Recipe(name VARCHAR(20),method VARCHAR(200), score int(10), time int(10))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Ingredient(name VARCHAR(20),price INT(10),kcal INT(10))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Allergy(name VARCHAR(10))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Tool(name varchar(20))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Comments(id int(5),comment VARCHAR(50))");

  //Creating tables for M-N relations
  query_ = db_.exec("CREATE TABLE Used_for(recipe_name VARCHAR(20), ingredient_name VARCHAR(20), amount INT(10))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Contained_in(ingredient_name VARCHAR(20), allergy_name VARCHAR(20))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Needed_for(recipe_name VARCHAR(20), tool_name VARCHAR(20))");
  last_query(query_);
  query_ = db_.exec("CREATE TABLE Commented_on(recipe_name VARCHAR(20), comment_id int(5))");
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
  query_ = db_.exec("DROP TABLE Commented_on");
  last_query(query_);
  
  //Drop Strong entitys
  query_ = db_.exec("DROP TABLE Recipe");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Ingredient");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Allergy");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Tool");
  last_query(query_);
  query_ = db_.exec("DROP TABLE Comments");
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
  cout << q.lastQuery().toStdString() << endl;
}
