#ifndef SEARCHDB_H
#define SEARCHDB_H
#include <QtSql>
#include <QSqlDatabase>
#include <vector>
#include "Recipe.h"

using namespace std;
using namespace QSql;


//typedef vector<MiniRecipe> Recipe_List;

class SearchDB
{
 public:
  SearchDB();
  //Search functions
  void query_list();
  void query_ingredient_list();
  void query_ingredient_list_explicit();
  void query_allergy_list();
  void query_price_list();
  void query_calory_list();

  //Functions for data acess
  //  Recipe_List get_list();
  //Recipe_List get_recipe();
  //Recipe_List get_recipe_ingredient();
  //Recipe_List get_info_ingredient();

  //Functions for merging recipie lists
  //  Recipe_List make_union();
  //Recipe_List intersect();
  //Recipe_List complement();

 private:
  QSqlDatabase db_;
  QSqlQuery    list_db_;
  QSqlQuery    ingredient_db_;
  int          list_pos_;



};

//#include "SearchDB.cc"
#endif
