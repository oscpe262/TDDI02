#include "classes/headers/EditDB.h"
#include <iostream>
using namespace std;
//bool EditDB::add_ingredient(){}
/*
EditDB::EditDB()
{
  db_ = QSqlDatabase::addDatabase("matlabb");
  db_.setHostName("db-und.ida.liu.se");
  db_.setDatabaseName("TDDI02_HT15_01");
  db_.setUserName("TDDI02_HT15_01");
  db_.setPassword("TDDI02_HT15_0177a3");
}
*/

void EditDB::create_db()
{
  int num;
  query_.exec("SELECT * FROM Booking");
  query_.next();
  num = query_.value(0).toInt();
cout << num;
}
