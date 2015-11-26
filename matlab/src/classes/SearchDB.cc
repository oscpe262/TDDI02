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
    query.bindValue(":offset",++list_pos_*2); // this 2 should be 10
					      // when we have more
					      // test data
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
RecipeList SearchDB::queryAllergene(const Allergene& allergene)
{
  QSqlQuery query(db_);
  RecipeList recipe_list;
  query.prepare("SELECT Recipe.name, Recipe.score, Recipe.time FROM Recipe WHERE Recipe.name IN (SELECT Used_for.recipe_name FROM Used_for WHERE Used_for.ingredient_name IN (SELECT Allergene_in.ingredient_name FROM Allergene_in WHERE Allergene_in.allergene_name = :allergene_name))");
  cerr << getAllergeneString(allergene);
  query.bindValue(":allergene_name",getAllergeneString(allergene).c_str());
  query.exec();
  cerr << query.lastError().text().toStdString();
  recipe_list = makeRecipeList(query); 
  return recipe_list;
}
RecipeList SearchDB::queryAllergeneList(const AllergeneArray& allergenes)
{
  RecipeList recipe_list{}, result_list{};
  for(int i = 0; i < 14; ++i)
    {
      if(allergenes[i]) 
	{
	  recipe_list = queryAllergene(Allergene(i));
	  if(result_list.empty()) //first ingredients RecipeList goes straight into result
	    result_list = recipe_list;
	  else //other ingredients results gets unioned with old result
	    result_list = unionize(result_list,recipe_list);
	}
    }
  return result_list;
}
/*
  queryDiet works exactly as allergenes
*/
RecipeList SearchDB::queryDiet(const Diet& diet)
{
  QSqlQuery query(db_);
  RecipeList recipe_list;
  query.prepare("SELECT Recipe.name, Recipe.score, Recipe.time FROM Recipe WHERE Recipe.name IN (SELECT Used_for.recipe_name FROM Used_for WHERE Used_for.ingredient_name IN (SELECT Diet_in.ingredient_name FROM Diet_in WHERE Diet_in.diet_name != :diet_name))");
  query.bindValue(":diet_name",getDietString(diet).c_str());
  query.exec();
  cerr << query.lastError().text().toStdString();
  recipe_list = makeRecipeList(query);
  return recipe_list;
}
RecipeList SearchDB::queryDietList(const DietArray& diets)
{
 RecipeList recipe_list{}, result_list{};
  for(int i = 0; i < 4; ++i)
    {
      cout << "varv: " << i << " i loopen" << endl;
      if(diets[i]) 
	{
	  recipe_list = queryDiet(Diet(i));
	  if(result_list.empty()) //first ingredients RecipeList goes straight into result
	    result_list = recipe_list;
	  else //other ingredients results gets unioned with old result
	    result_list = unionize(result_list,recipe_list);
	}
    }
  return result_list;

}

/*
  queryPrice() accepts a price struct with an upper bound and a lower
  bound and returns all recipes in that interval
*/

RecipeList SearchDB::queryPrice(const Price& price)
{
  QSqlQuery query(db_);
  query.prepare("Select Recipe.name,Recipe.score,Recipe.time FROM Recipe WHERE (Recipe.price <= :upper AND Recipe.price >= :lower)");
  query.bindValue(":upper",price.upper_bound);
  query.bindValue(":lower",price.lower_bound);
  query.exec();
  cerr << query.lastError().text().toStdString();
  return makeRecipeList(query);
}
/*
  queryPrice() accepts a kcal struct with an upper bound and a lower
  bound and returns all recipes in that interval
*/
RecipeList SearchDB::queryKcal(const Cal& kcal)
{
  QSqlQuery query(db_);
  query.prepare("Select Recipe.name,Recipe.score,Recipe.time FROM Recipe WHERE (Recipe.kcal <= :upper AND Recipe.kcal >= :lower)");
  query.bindValue(":upper",kcal.upper_bound);
  query.bindValue(":lower",kcal.lower_bound);
  query.exec();
  cerr << query.lastError().text().toStdString();
  return makeRecipeList(query);
} 
/*
  termSearch() The big baus, uses all the functions above to generate
  a multisearch using the data members from the provided SearchTerm
  object
*/
RecipeList SearchDB::termSearch(const SearchTerm& search_term)
{
  RecipeList rl;
  return rl;
}



/*
  queryIngredientName returns a vector containing all the ingredients
  in the database as strings.
*/
IngredientNames SearchDB::queryIngredientNames()
{
  QSqlQuery query(db_);
  IngredientNames ingredient_names;
  query.exec("SELECT name FROM Ingredient");
  while(query.next())
    {
      ingredient_names.push_back(query.value(0).toString().toStdString());
    }
    
  return ingredient_names;
}


//////////////////////////////////////////
//PRIVATE
//////////////////////////////////////////

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
RecipeList SearchDB::unionize(RecipeList l1, RecipeList l2)
{
  RecipeList result;
  sort(l1.begin(),l1.end());
  sort(l2.begin(),l2.end());
  set_union(l1.begin(),l1.end(),
		 l2.begin(),l2.end(),
		 back_inserter(result));
  return result;
}

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
