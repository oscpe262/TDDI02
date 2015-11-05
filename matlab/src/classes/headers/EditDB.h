/*
  Klassen EditDB Är ansvarig ändringar i databasen

  kontouppgifter till databasen:
  User:              Password:             Databas:
  TDDI02_HT15_01     TDDI02_HT15_0177a3    TDDI02_HT15_01
 */

#ifndef EDITDB_H
#define EDITDB_H
#include <iostream>
#include <QtSql>
#include <QSqlDatabase>

class EditDB{
 public:
  EditDB()
    {
      db_ = QSqlDatabase::addDatabase("QMYSQL");
      db_.setHostName("db-und.ida.liu.se");
      db_.setDatabaseName("TDDI02_HT15_01");
      db_.setUserName("TDDI02_HT15_01");
      db_.setPassword("TDDI02_HT15_0177a3");
    }
  
  void create_db();
  
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

  
  
};

#endif

