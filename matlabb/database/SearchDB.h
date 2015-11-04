#ifndef SEARCHDB_H
#define SEARCHDB_H
//#include <QtSql>
#include <QSqlDatabase>

using namespace std;
using namespace QSql;


class SearchDB
{
 public:
  SearchDB();
  void query_list();
  void search_list();

 private:
  QSqlDatabase db_;
  QSqlQuery    list_db_;
  QSqlQuery    ingredient_db_;
  int          list_pos_;



};

#include "SearchDB.cc"
#endif
