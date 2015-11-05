#ifndef EDITDB_H
#define EDITDB_H
#include <iostream>
//#include <QtSql>
//#include <QSqlDatabase>

class EditDB{
 public:
  //EditDB();

  /* /\* bool add_recipe(); *\/ */
  bool add_ingredient();
  bool add_comment();
  bool add_tool();
  
  bool remove_recipe();
  bool remove_ingredient();
  bool remove_tool();
  bool remove_comment();
 private:

  
};

#endif

