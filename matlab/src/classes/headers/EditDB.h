/*
  Klassen EditDB Är ansvarig ändringar i databasen

  kontouppgifter till databasen:
  User:              Password:             Databas:
  TDDI02_HT15_02     TDDI02_HT15_02b957
 */

#ifndef EDITDB_H
#define EDITDB_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <iostream>

class EditDB{
 public:
  EditDB();
  
  void create_db();               //Creates database
  void clear_db();                //Clears database
  void print_tables();            
  void last_query(QSqlQuery q);   //prints last query on cout
  
  bool add_recipe();
  bool add_ingredient();
  bool add_comment();
  bool add_tool();
  
  bool remove_recipe();
  bool remove_ingredient();
  bool remove_tool();
  bool remove_comment();
 private:
  QSqlDatabase db_;
  QSqlQuery    query_;
  QSqlError    db_error_;

  
  
};

#endif

