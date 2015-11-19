#ifndef SEARCHDB_H
#define SEARCHDB_H
#include <QtSql>
#include <QSqlDatabase>
#include <vector>
#include "DB.h"
#include "Ingredient.h"
#include "Recipe.h"
#include "SearchTerm.h"

using namespace std;
using namespace QSql;

class SearchDB : public DB
{
 public:
 SearchDB() : DB() {};
 SearchDB(string name) : DB(name) {};
  //Search functions
  RecipeList queryList();
  RecipeList queryIngredientList(vector<string> ingredients);
  void queryIngredient_list_explicit();
  void queryAllergy_list();
  void queryPrice_list();
  void queryCalory_list();
  
  //Functions for data acess
  //Recipe_List getList();
  //Recipe_List getRecipe();
  //Recipe_List getRecipeIngredient();
  
  
  //Functions for merging recipie lists
  //  Recipe_List make_union();
  //Recipe_List intersect();
  //Recipe_List complement();

 private:
  int          list_pos_;
  SearchTerm search_term_;

};
#endif
