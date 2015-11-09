#ifndef SEARCHDB_H
#define SEARCHDB_H
#include <QtSql>
#include <QSqlDatabase>
#include <vector>
#include "classes/headers/DB.h"
#include "classes/headers/Ingredient.h"
//#include "Recipe.h"

using namespace std;
using namespace QSql;


//typedef vector<MiniRecipe> Recipe_List;

class SearchDB : public DB{
 public:
  SearchDB() : DB() {};
  //Search functions
  void queryList();
  void queryIngredient_list();
  void queryIngredient_list_explicit();
  void queryAllergy_list();
  void queryPrice_list();
  void queryCalory_list();

  //Functions for data acess
  //Recipe_List getList();
  //Recipe_List getRecipe();
  //Recipe_List getRecipeIngredient();
  Ingredient makeIngredient(const string& name);


  //Functions for merging recipie lists
  //  Recipe_List make_union();
  //Recipe_List intersect();
  //Recipe_List complement();

 private:
  int          list_pos_;

};

#endif
