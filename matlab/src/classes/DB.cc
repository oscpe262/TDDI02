/*
  Class: DB
  Description: Abstract base class for EditDB and SearchDB hold
  general database functionality
  Author: Erik Peyronson
*/

#include "classes/headers/DB.h"
#include <iostream>

/*
  constructor connects private member db_ to the database
*/

DB::DB()
{
  db_ = QSqlDatabase::addDatabase("QMYSQL");
  db_.setHostName("db-und.ida.liu.se");
  db_.setDatabaseName("TDDI02_HT15_02");
  db_.setUserName("TDDI02_HT15_02");
  db_.setPassword("TDDI02_HT15_02b957");
  bool ok = db_.open();
  //if(!ok) throw DB_Exception("ERROR: Database could not be opened");
  QSqlQuery tmp_query(db_);
  query_ = tmp_query;
}

DB::DB(string name)
{
  db_ = QSqlDatabase::addDatabase("QMYSQL", name.c_str());
  db_.setHostName("db-und.ida.liu.se");
  db_.setDatabaseName("TDDI02_HT15_02");
  db_.setUserName("TDDI02_HT15_02");
  db_.setPassword("TDDI02_HT15_02b957");
  bool ok = db_.open();
  // if(!ok) throw DB_Exception("ERROR: Database could not be opened");
  QSqlQuery tmp_query(db_);
  query_ = tmp_query;
}

/*
  create_db() builds the database tables
*/ 

void DB::createDb()
{ 
  //Creating tables for strong entitys
  
  query_ = db_.exec("CREATE TABLE Recipe(name VARCHAR(255),method VARCHAR(1023), score float(10), time int(10), price int(10), kcal int(10), portions int(10), PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Ingredient(name VARCHAR(255),price INT(10),kcal INT(10),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Allergene(name VARCHAR(255),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Diet(name VARCHAR(255),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Tool(name varchar(255),PRIMARY KEY(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Comments(id int(5),recipe_name VARCHAR(255), comment VARCHAR(255), PRIMARY KEY(ID), FOREIGN KEY(recipe_name) REFERENCES Recipe(name))");

  //Creating tables for M-N relations

  query_ = db_.exec("CREATE TABLE Used_for(recipe_name VARCHAR(255), ingredient_name VARCHAR(255), amount INT(10), unit INT(5), FOREIGN KEY(recipe_name) REFERENCES Recipe(name) ON DELETE CASCADE, FOREIGN KEY(ingredient_name) REFERENCES Ingredient(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Allergene_in(ingredient_name VARCHAR(255), allergene_name VARCHAR(255), FOREIGN KEY(ingredient_name) REFERENCES Ingredient(name) ON DELETE CASCADE, FOREIGN KEY(allergene_name) REFERENCES Allergene(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Diet_in(ingredient_name VARCHAR(255), diet_name VARCHAR(255), FOREIGN KEY(ingredient_name) REFERENCES Ingredient(name), FOREIGN KEY(diet_name) REFERENCES Diet(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Needed_for(recipe_name VARCHAR(255), tool_name VARCHAR(255),FOREIGN KEY(recipe_name) REFERENCES Recipe(name),  FOREIGN KEY(tool_name) REFERENCES Tool(name))");
  lastQuery(query_);
  query_ = db_.exec("CREATE TABLE Related_to(recipe VARCHAR(255), related VARCHAR(255), FOREIGN KEY(recipe) REFERENCES Recipe(name)");

  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('fruit')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('garlic')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('hot_peppers')");   
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('oats')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('wheat')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('gluten')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('peanut')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('tree_nut')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('shellfish')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('alpha_gal')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('egg')"); 
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('milk')");
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('lactose')");  
  query_ = db_.exec("INSERT INTO Allergene(name) VALUES ('soy')");
  query_ = db_.exec("INSERT INTO Diet(name) VALUES ('vegetarian')");  
  query_ = db_.exec("INSERT INTO Diet(name) VALUES ('vegan')");
  query_ = db_.exec("INSERT INTO Diet(name) VALUES ('halal')");
  query_ = db_.exec("INSERT INTO Diet(name) VALUES ('kosher')");



  //, ,, , , , , , , , , , )");
  lastQuery(query_);
  //Error message print
  cerr << db_.lastError().text().toStdString() << endl;
}

/*
  Clear_db() Clears the database tables
*/

void DB::clearDb()
{
  //Drop m-n tables
  query_ = db_.exec("DROP TABLE Used_for");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Allergene_in");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Diet_in");
  lastQuery(query_);
 query_ = db_.exec("DROP TABLE Needed_for");
 lastQuery(query_);
 query_ = db_.exec("DROP TABLE Related_to");
  
  //Drop Strong entitys
  query_ = db_.exec("DROP TABLE Ingredient");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Allergene");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Diet");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Tool");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Comments");
  lastQuery(query_);
  query_ = db_.exec("DROP TABLE Recipe");
  lastQuery(query_);

  db_error_ = db_.lastError();
  cerr << db_.lastError().text().toStdString();

  query_.finish();
}

void DB::printTables()
{
  query_.exec("SHOW TABLES");

  query_.finish();
}

/*
  Last query prints the last executed query executed by q
*/

void DB::lastQuery(QSqlQuery q)
{
  cout << q.lastQuery().toStdString() << endl << endl;
}

/*
  check_ingredient() checks if a ingredient is stored in the db returns
  true if ingredient exists else false can be called both using string
  and Ingredient objects
*/

bool DB::checkIngredient(const string& ingredient)
{
  QSqlQuery tmp_query(db_);
  tmp_query.prepare("SELECT 1 FROM Ingredient WHERE name=:name");
  tmp_query.bindValue(":name", ingredient.c_str());
  tmp_query.exec();
  if(tmp_query.next()) return true;
  else return false;
}

bool DB::checkIngredient(const Ingredient& ingredient)
{
  return checkIngredient(ingredient.getName());
}

/*
  checkRecipe() checks if a recipe is stored in the db returns
  true if recipe exists else false can be called both using string
  and recipe objects
*/

bool DB::checkRecipe(const string& recipe)
{
  QSqlQuery tmp_query(db_);
  tmp_query.prepare("SELECT 1 FROM Recipe WHERE name=:name");
  tmp_query.bindValue(":name", recipe.c_str());
  tmp_query.exec();
  if(tmp_query.next()) return true;
  else return false;
}

bool DB::checkRecipe(const Recipe& recipe)
{
  return checkRecipe(recipe.getName());
}

bool DB::checkRelated(const string& recipe)
{
  QSqlQuery tmp_query(db_);
  tmp_query.prepare("SELECT 1 FROM Related_to WHERE Recipe=:name");
  tmp_query.bindValue(":name", recipe.c_str());
  tmp_query.exec();
  if(tmp_query.next()) return true;
  else return false;
}
/*
 fetchIngredient() fetches ingredient information from the db and
 returns a Ingredient object 
 */

Ingredient DB::fetchIngredient(const string & name)
{
  QSqlQuery query(db_);
  if(!checkIngredient(name))
    throw DB_Exception("Ingredient: " + name + " could not be found in the database");
  query.prepare("SELECT * FROM Ingredient WHERE name = :name");
  query.bindValue(":name",name.c_str());
  query.exec();
  query.next();
  Ingredient ingredient(query.value(0).toString().toStdString(),query.value(1).toInt(),query.value(2).toInt());
  ingredient.setAllergenes(fetchAllergenes(name));
  ingredient.setDiets(fetchDiets(name));
  return ingredient; 
}

/*
  fetchRecipeIngredient() fetches ingredient information from the db and
 returns a RecipeIngredient object 
*/

RecipeIngredient DB::fetchRecipeIngredient(const string & name)
{
  QSqlQuery tmp_query(db_);
  // if(!checkIngredient(name)) throw DB_Exception("ERROR: Ingredient not in database");
  tmp_query.prepare("SELECT * FROM Ingredient WHERE name = :name");
  tmp_query.bindValue(":name",name.c_str());
  tmp_query.exec();
  tmp_query.next();
  RecipeIngredient recipe_ingredient(tmp_query.value(0).toString().toStdString(),
		    tmp_query.value(1).toInt(),
		    tmp_query.value(2).toInt());
  recipe_ingredient.setAllergenes(fetchAllergenes(name));
  recipe_ingredient.setDiets(fetchDiets(name));
  return recipe_ingredient;
				  
}
/*
  Fetch Allergenes and diets, Creates allergene and diet arrays for ingredients
*/
AllergeneArray DB::fetchAllergenes(const string& name)
{
  QSqlQuery query(db_);
  AllergeneArray allergenes{{}};
  query.prepare("SELECT allergene_name FROM Allergene_in WHERE ingredient_name = :ingredient_name");
  query.bindValue(":ingredient_name",name.c_str());
  query.exec();
  while(query.next())
    {
      cerr << name << ": ";
      cerr << query.value(0).toString().toStdString() << endl;
      if(query.value(0).toString().toStdString() == "fruit") allergenes[(int)fruit] = true;
      else if(query.value(0).toString().toStdString() == "garlic") allergenes[(int)garlic] = true;
      else if(query.value(0).toString().toStdString() == "hot_peppers") allergenes[(int)hot_peppers] = true;
      else if(query.value(0).toString().toStdString() == "oats") allergenes[(int)oats] = true;
      else if(query.value(0).toString().toStdString() == "wheat") allergenes[(int)wheat] = true;
      else if(query.value(0).toString().toStdString() == "gluten") allergenes[(int)gluten] = true;
      else if(query.value(0).toString().toStdString() == "peanut") allergenes[(int)peanut] = true;
      else if(query.value(0).toString().toStdString() == "tree_nut") allergenes[(int)tree_nut] = true;
      else if(query.value(0).toString().toStdString() == "shellfish") allergenes[(int)shellfish] = true;
      else if(query.value(0).toString().toStdString() == "alpha_gal") allergenes[(int)alpha_gal] = true;
      else if(query.value(0).toString().toStdString() == "egg") allergenes[egg] = true;
      else if(query.value(0).toString().toStdString() == "milk") allergenes[milk] = true;
      else if(query.value(0).toString().toStdString() == "lactose") allergenes[lactose] = true;
      else if(query.value(0).toString().toStdString() == "soy") allergenes[soy] = true;
    }
  cerr << query.lastError().text().toStdString();
  return allergenes;
}
DietArray DB::fetchDiets(const string& name)
{
  QSqlQuery query(db_);
  DietArray diets;
  query.prepare("SELECT diet_name FROM Diet_in WHERE ingredient_name = :ingredient_name");
  query.bindValue(":ingredient_name",name.c_str());
  query.exec();
  while(query.next())
    {
      if(query.value(0).toString().toStdString() == "vegetarian") diets[vegetarian] = true;
      else if(query.value(0).toString().toStdString() == "vegan") diets[vegan] = true;
      else if(query.value(0).toString().toStdString() == "halal") diets[halal] = true;
      else if(query.value(0).toString().toStdString() == "kosher") diets[kosher] = true;
    }
}
/*
  Fetches IngredientList for recipe
*/
IngredientList DB::fetchIngredientList(const string & recipe)
{
  QSqlQuery query(db_);
  IngredientList ingredients;
  query.prepare("SELECT Ingredient.name, Ingredient.price, Ingredient.kcal, Used_for.amount, Used_for.unit FROM Ingredient INNER JOIN Used_for ON Ingredient.name=Used_for.ingredient_name WHERE Used_for.recipe_name = :recipe");
  query.bindValue(":recipe",recipe.c_str());
  query.exec();
  while(query.next())
    {
      RecipeIngredient recipe_ingredient(query.value(0).toString().toStdString(),
					 query.value(1).toInt(),
					 query.value(2).toInt(),
					 query.value(3).toDouble(),
					 static_cast<Unit>(query.value(4).toInt()));
      recipe_ingredient.setAllergenes(fetchAllergenes(query.value(0).toString().toStdString()));
      recipe_ingredient.setDiets(fetchDiets(query.value(0).toString().toStdString()));
      ingredients.push_back(recipe_ingredient);
    }
  return ingredients;
   
}
/*
  fetchRecipe() Fetches Recipie info from db and returns recipe object
*/

Recipe DB::fetchRecipe(const string & name)
{
  QSqlQuery query(db_);
  IngredientList ingredients;
  if(!checkRecipe(name))
    throw DB_Exception("ERROR: Recipe " + name + " could not be found in the database");
  query.prepare("SELECT * FROM Recipe WHERE name = :name");
  query.bindValue(":name",name.c_str());
  query.exec();
  query.next();
  Recipe recipe(query.value(0).toString().toStdString(),
		query.value(1).toString().toStdString(),
		query.value(3).toDouble(),
		query.value(2).toInt(),
		fetchIngredientList(name),
		query.value(4).toInt(),
		query.value(5).toInt(),
		query.value(6).toInt());
  vector<string> related = fetchRelated(name);
  recipe.setRelated(related);
  return recipe;
}
/*
  fetchRelated() Fetches Recipie related recipes and returns a vector
*/


vector<string> DB::fetchRelated(const string& name)
{
  QSqlQuery query(db_);
  vector<string> related_recipes{};
  if(checkRelated(name))
    {
      query.prepare("SELECT related FROM Related_to WHERE recipe = :recipe");
      query.bindValue(":recipe",name.c_str());
      query.exec();
      while(query.next())
	{
	  cerr << "query value(0): " << query.value(0).toString().toStdString();
	  related_recipes.push_back(query.value(0).toString().toStdString());
	}
    }
  return related_recipes;
    

}
/*
  getAllergeneString() is a help function that accepts allergy enum
  and returns a c-string as a result to be used while adding
  ingredients in the database
*/


string DB::getAllergeneString(Allergene allergene)
{
  switch((int)allergene)
    {
    case 0:
      return "fruit";
      break;
    case 1:
      return "garlic";
      break;
    case 2:
      return "hot_peppers";
      break;
    case 3:
      return "oats";
      break;
    case 4:
      return "wheat";
      break;
    case 5:
      return "gluten";
      break;
    case 6:
      return "peanut";
      break; 
    case 7:
      return "tree_nut";
      break;
    case 8:
      return "shellfish";
      break;
    case 9:
      return "alpha_gal";
      break;
    case 10:
      return "egg";
      break;
    case 11:
      return "milk";
      break;
    case 12:
      return "lactose";
      break;
    case 13:
      return "soy";
      break;
    }

}
string DB::getDietString(Diet allergene)
{
  switch((int)allergene)
    {
    case 0:
      return "vegetarian";
      break;
    case 1:
      return "vegan";
      break;
    case 2:
      return "halal";
      break;
    case 3:
      return "kosher";
      break;
    }
}
