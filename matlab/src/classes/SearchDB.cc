#include "classes/headers/SearchDB.h"
#include "classes/headers/Ingredient.h"
#include <algorithm>
using namespace std;


/*
  queryList() queries the 10 recipes next using the pos_ variable to
  decide which 10
*/ 

RecipeList SearchDB::queryList(bool forward)
{
  QSqlQuery query(db_);
  query.prepare("SELECT name, score, time FROM Recipe LIMIT 2 OFFSET :offset" );  
  if(forward)
    query.bindValue(":offset",++list_pos_*2);
  else
    query.bindValue(":offset",--list_pos_*2);
  query.exec();
  return makeRecipeList(query);

}

/*
  queryIngredient() accepts a ingredient name as a string and
  generates a vector containing MiniRecipes of all recipes containing
  that ingredient
*/

RecipeList SearchDB::queryIngredient(const string& name)
{
  QSqlQuery query(db_);
  RecipeList recipe_list;
  query.prepare("SELECT Recipe.name, Recipe.score, Recipe.time FROM Recipe WHERE Recipe.name IN (select recipe_name from Used_for where ingredient_name = :ingredient_name)");
  query.bindValue(":ingredient_name",name.c_str());
  query.exec();
  recipe_list = makeRecipeList(query);
  return recipe_list;
}

/*
  queryIngredientList() accepts a RecipeList and generates a vector
  containing  MiniRecipes of all recipes containing ingredients from
  that list 
*/

RecipeList SearchDB::queryIngredientList(IngredientNames ingredients)
{
  RecipeList recipe_list{}, result_list{};
  for(auto i : ingredients)
    {
      recipe_list = queryIngredient(i);
      if(result_list.empty()) //first ingredients RecipeList goes straight into result
	result_list = recipe_list;
      else //other ingredients results gets intersected with old result
	result_list = intersect(result_list,recipe_list);
    }
  return result_list;
}

RecipeList SearchDB::queryNotIngredientList(IngredientNames ingredients)
{
  QSqlQuery query(db_);
  RecipeList result_list;
  query.prepare("SELECT Recipe.name, Recipe.score, Recipe.time FROM Recipe");
  query.exec();
  result_list = makeRecipeList(query);
  for(auto i : ingredients) 
    result_list = complement(result_list,queryIngredient(i));
  return result_list;
}


/*
  intersect() accepts two recipe lists and returns the intersection
  using std::set_intersection()
*/

RecipeList SearchDB::intersect(RecipeList l1, RecipeList l2)
{
  RecipeList result;
  sort(l1.begin(),l1.end());
  sort(l2.begin(),l2.end());
  set_intersection(l1.begin(), l1.end(),
		   l2.begin(), l2.end(),
		   back_inserter(result));	 
  return result;	
}

/*
  complement() accepts two recipe lists and returns the l1\l2
  using std::set_difference()
*/

RecipeList SearchDB::complement(RecipeList l1, RecipeList l2)
{
  RecipeList result;
  sort(l1.begin(),l1.end());
  sort(l2.begin(),l2.end());
  set_difference(l1.begin(),l1.end(),
		 l2.begin(),l2.end(),
		 back_inserter(result));
  return result;
}
/*
  makeList() accepts pre executed QSqlQuery and generates a RecipeList
  from the result
*/
RecipeList SearchDB::makeRecipeList(QSqlQuery& query)
{
  RecipeList recipe_list;
  while(query.next()) //Push back all recipies containing current ingreient
    {
      recipe_list.push_back(MiniRecipe(query.value(0).toString().toStdString(),
				       query.value(1).toInt(),
				       query.value(2).toDouble()));
    }
  query.clear();
  return recipe_list;
}
