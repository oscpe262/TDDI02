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
 SearchDB() : DB(), list_pos_(0) {};
 SearchDB(string name) : DB(name), list_pos_(0) {};
  //Search functions
  
  RecipeList queryList(bool forward);
  RecipeList queryIngredient(const string& name);
  RecipeList queryIngredientList(IngredientNames ingredients);
  RecipeList queryNotIngredientList(IngredientNames ingredients);
  RecipeList queryAllergene(const Allergene& allergene);
  RecipeList queryAllergeneList(const AllergeneArray& allergenes);
  vector<string> queryIngredientNames();

  void queryIngredient_list_explicit();
  void queryAllergy_list();
  void queryPrice_list();
  void queryCalory_list();
  int getPos() const {return list_pos_;}
  
  RecipeList termSearch(const SearchTerm& search_term); 
  
  //Functions for data acess
  //Recipe_List getList();
  //Recipe_List getRecipe();
  //Recipe_List getRecipeIngredient();
  
  //Functions for merging recipie lists
  //Recipe_List make_union();
  //Recipe_List intersect();
  //Recipe_List complement();

 private:
  int          list_pos_;
  SearchTerm search_term_;
  RecipeList intersect(RecipeList l1, RecipeList l2);
  RecipeList complement(RecipeList l1, RecipeList l2);
  RecipeList unionize(RecipeList l1, RecipeList l2);
  RecipeList makeRecipeList(QSqlQuery& query);
  //Recipe_List make_union();
  //Recipe_List intersect();
  //Recipe_List complement();

};
#endif
