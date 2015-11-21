#include "classes/headers/SearchDB.h"
#include "classes/headers/Ingredient.h"
#include <algorithm>
using namespace std;

/*
  queryList() queries the 10 recipes next using the pos_ variable to
  decide which 10
*/ 

RecipeList SearchDB::queryList()
{
  QSqlQuery query(db_);
  query.prepare("SELECT name, score, time FROM Recipe WHERE" );

  /*
    name_
    minutesTime_
    grade_
  */ 
}


/*
  queryIngredientList() accepts a RecipeList and generates a vector
  containing  MiniRecipes of all recipes containing ingredients from
  that list 
*/

RecipeList SearchDB::queryIngredientList(vector<string> ingredients)
{
  QSqlQuery query(db_);
  RecipeList recipe_list;
  for(auto i : ingredients)
    {
      query.prepare("Select Recipe.name, Recipe.score, Recipe.time FROM Recipe WHERE Recipe.name IN (select recipe_name from Used_for where ingredient_name = :ingredient_name)");
      query.bindValue(":ingredient_name",i.c_str());
      query.exec();
      while(query.next())
	{
	  recipe_list.push_back(MiniRecipe(query.value(0).toString().toStdString(),
					   query.value(1).toInt(),
					   query.value(2).toDouble()));
	}
    }
  cerr << query.lastError().text().toStdString() << endl;
  //unique(recipe_list.begin(),recipe_list.end(),[](const MiniRecipe& i,const MiniRecipe& u){return i.name_ == u.name_;});
  return recipe_list;
}
