/*
  Class: SearchDB
  Description: Class for making queries in the database
  Author: Erik Peyronson
*/

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
 SearchDB() : DB("search"), list_pos_(0) {};
  //Search functions  
  RecipeList queryList(bool forward);
  RecipeList termSearch(const SearchTerm& search_term);
  IngredientNames queryIngredientNames();
  
  //functions for data acees
  int getPos() const {return list_pos_;}
  
 private:
  //Data members:
  int        list_pos_;
  SearchTerm search_term_;

  //Help-functions for searching
  RecipeList queryIngredient(const string& name);
  RecipeList queryIngredientList(IngredientNames ingredients);
  RecipeList queryNotIngredientList(IngredientNames ingredients);
  RecipeList queryAllergene(const Allergene& allergene);
  RecipeList queryAllergeneList(const AllergeneArray& allergenes);
  RecipeList queryDiet(const Diet& diet);

  RecipeList queryDietList(const DietArray& diets);
  RecipeList queryPrice(const Price& price);
  RecipeList queryKcal(const Cal& kcal); 
  RecipeList queryTime(const Time& time);

  //Set functions for merging RecipeLists:
  RecipeList intersect(RecipeList l1, RecipeList l2);
  RecipeList complement(RecipeList l1, RecipeList l2);
  RecipeList unionize(RecipeList l1, RecipeList l2);
  //etc
  RecipeList makeRecipeList(QSqlQuery& query);


};
#endif
