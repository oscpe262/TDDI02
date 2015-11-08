/*
  Klassen DB är abstrakt basklass för EditDB och SearchDB

  kontouppgifter till databasen:
  User:              Password:             Databas:
  TDDI02_HT15_02     TDDI02_HT15_02b957
 */
#ifndef DB_H
#define DB_H
#include <QtSql>
#include <QSqlDatabase>
#include <string>
#include "classes/headers/Ingredient.h"

class DB
{
 public:
  DB();
  
  void create_db();               //Creates database
  void clear_db();                //Clears database
  
  void print_tables();                       
  void last_query(QSqlQuery q);   //prints last query on cout

  bool check_ingredient(const string& ingredient);
  bool check_ingredient(const Ingredient& ingredient);
  
 protected:
  QSqlDatabase db_;
  QSqlQuery    query_;
  QSqlError    db_error_;

};


#endif
