#include <QtCore>
#include <QCoreApplication>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <iomanip>
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include "classes/headers/SearchDB.h"
#include "classes/headers/EditDB.h"
using namespace std::chrono;
using namespace std::this_thread;


using namespace std;
void print_menu();
void print_recipe(MiniRecipe& recipe);
void print_recipe_list(RecipeList& recipe_list);
bool import_ingredients(ifstream& stream,EditDB& db);
bool import_recipes(ifstream& stream, EditDB& db);
bool add_ingredient(EditDB& db);
bool add_recipe(Recipe& recipe);
bool fetch_ingredient(EditDB& db);
bool query_ingredient_test(SearchDB& db);
bool query_not_ingredient_test(SearchDB& db);
bool query_list_test(SearchDB& db);
bool allergene_test(SearchDB& db);
void calculate_price_test(EditDB& db);
void query_ingredient_names_test(SearchDB& db);
void query_price_test(SearchDB& db);
void query_kcal_test(SearchDB& db);
bool diet_test(SearchDB& db);


int main(int argc, char* argv[])
{
  
  string db_name = "matlabb2";
  QCoreApplication app(argc, argv);
  EditDB test_editDB;
  SearchDB test_searchDB(db_name);
  int menu = 0;
  string name;
  Ingredient ingredient("Korv",5,200);
  ifstream importstream;

  if(argc > 2)
    {
      if(!strcmp(argv[1], "-i"))
	{
	  importstream.open(argv[2]);
	  if(importstream.fail() || !import_ingredients(importstream,test_editDB))
	    {
	      cerr << "Ingredient list could not be imported, check fileame or clear db \n";
	      return 1;
	    }
	  cout << "\nImport sucessfull!\n\n";
	}
      
      else if(!strcmp(argv[1], "-r"))
	{
	  importstream.open(argv[2]);
	  if(importstream.fail() || !import_recipes(importstream,test_editDB))
	    {
	      cerr << "Recipe list could not be imported, check fileame or clear db \n";
	      return 1;
	    }
	  cout << "\nImport sucessfull!\n\n";
	}
      else
	{
	  cerr << "usage: ./DB_test -F filename.txt \n"
	       << "Flags: \n"
	       << "-i import ingredients\n"
	       << "-r import recipies\n"
	       << "-reset \n";
	}
     return 1;
    }
  else if(argc == 2)
    {
      if(!strcmp(argv[1], "-reset"))
	{
	  test_editDB.clearDb();
	  test_editDB.createDb();
	  importstream.open("ingredient_input.txt");
	  import_ingredients(importstream,test_editDB);
	  importstream.close();
	  importstream.clear();
	  importstream.open("recipe_input.txt");
	  import_recipes(importstream,test_editDB);
	  importstream.close();
	  cout << "DB reset, ingredients and recipes imported \n";
	}
      else
	{
	  cerr << "usage: ./DB_test -F \n"
	       << "Flags: \n"
	       << "-i import ingredients.txt\n"
	       << "-r import recipies.txt\n"
	       << "-reset \n";
	  return 1;
	}
    }
		    
  do
  {
    cout << endl;
    switch(menu)
      {
      case 1:
	test_editDB.createDb();
	break;
      case 2:
	test_editDB.clearDb();
	break;
      case 3:
	test_editDB.printTables();
	break;
      case 4:
	if(add_ingredient(test_editDB))
	  cout << "Ingredient added\n";
	else
	  cout << "something went wrong, ingredient probably exists try again \n";
	break;
      case 5:
	cout << "Ange ingrediens: ";
	cin >> name;
	if(test_editDB.checkIngredient(name))
	  cout << "\nIngrediensen finns\n";
	else
	  cout << "\nIngrediensen finns inte\n";
	break;
      case 6:
	cout << "Ange ingrediens: ";
	cin >> name;
	if(test_editDB.removeIngredient(name))
	  cout << "Ingrediens togs bort";
	else
	  cout << "Ingrediens finns inte";
	break;
      case 7:
	fetch_ingredient(test_editDB);
	break;
      case 8:
	query_ingredient_test(test_searchDB);
	break;
      case 9:
	query_not_ingredient_test(test_searchDB);
	break;
      case 10:
	query_list_test(test_searchDB);
	break;
      case 11:
	allergene_test(test_searchDB);
	break;
      case 12:
	calculate_price_test(test_editDB);
	break;
      case 13:
	query_ingredient_names_test(test_searchDB);
	break;
      case 14:
	query_price_test(test_searchDB);
	break;
      case 15:
	query_kcal_test(test_searchDB);
	break;
      case 16:
	diet_test(test_searchDB);
	break;
      }
      
    print_menu();
  }while(cin >> menu);
  

  return app.exec();
}

void print_menu()
{
  cout << "\nEditDB Test menu\n"
       << "1.CreateDB\n"
       << "2.ClearDB\n"
       << "3.printTables\n"
       << "4.addIngredient\n"
       << "5.checkIngredient\n"
       << "6.removeIngredient\n"
       << "7.fetchIngredient\n"
       << "8.queryIngredients\n"
       << "9.queryNotIngredients\n"
       << "10.queryList\n"
       << "11.allergene_test\n"
       << "12.calculatePrice_test\n"
       << "13.queryIngredientNames test\n"
       << "14.queryPrice test\n"
       << "15.queryKcal test\n"
       << "16 queryDietlist test\n"
       << "Choice: ";

}
void print_recipe(MiniRecipe& recipe)
{
  cout << "Recipe: " << recipe.name_ << endl
       << "Grade: " << recipe.grade_ << endl
       << "Time: " << recipe.minutesTime_ << endl << endl;
}

void print_recipe_list(RecipeList& recipe_list)
{
  for(auto i : recipe_list)
    print_recipe(i);
}

bool import_ingredients(ifstream& stream,EditDB& db)
{
 
  istringstream isstream;
  Ingredient ingredient;
  string row,tmpStr;
  int tmpInt;
  cout << "*************************\n"
       << "**INGREDIENTS IMPORTED:**\n"
       << "*************************\n";
  while(stream.peek() != EOF)
    {
      row.clear();
      getline(stream,row);
      istringstream isstream(row);
      try{
	isstream >> tmpStr;

	if (tmpStr.compare("ingredient:") == 0)
	  {
	    isstream >> tmpStr;
	    ingredient.setName(tmpStr);
	  }	
	else if(tmpStr.compare("price:") == 0)
	  {
	    isstream >> tmpInt;
	    ingredient.setPrice(tmpInt);
	  }
	else if(tmpStr.compare("kcal:") == 0)
	  {
	    isstream >> tmpInt;
	    ingredient.setKcal(tmpInt);
	  }
	else if(tmpStr.compare("allergenes:") == 0 )
	  {
	    while(isstream >> tmpInt)
	      {
		ingredient.addAllergene(tmpInt);
	      }
	    isstream.clear();
	  }
	else if(tmpStr.compare("diets:") == 0)
	  {
	    while(isstream >> tmpInt)
	      {
		ingredient.addDiet(tmpInt);
	      }
	    isstream.clear();
	  }
	else if(tmpStr.compare("%end") == 0)
	  {
	    AllergeneArray al = ingredient.getAllergenes();
	    int alint = 0;
	    db.addIngredient(ingredient);
	    for(int i = 0; i < 14; ++i) ingredient.removeAllergene(i);
	    cout << ingredient.getName() << " contains allergies: "; 
	    for(int i = 0; i<14 ;++i)
	      {
		if (al[i])
		  cout << i << " ";
	      } 
	    cout << ingredient.getName() <<" Was added \n";
	  }

	if(isstream.fail())
	  throw DB_Exception("File could not be read, check syntax \n");
      }
      catch(DB_Exception e)
	{
	  cerr << e.what();
	  return false;
	}
    }
  cout << endl;
  return true;
}
 
bool import_recipes(ifstream& stream, EditDB& db)
{
  istringstream isstream;
  RecipeIngredient ingredient;
  string name,method,row,ingr;
  int time, amount;
  Unit unit;
  double grade;
  IngredientList ingredients;
  char c;
  cout << "*************************\n"
       << "****RECIPES IMPORTED:****\n"
       << "*************************\n";
  do 
    {
      getline(stream,name);
      cout << name << " Was added\n";
      getline(stream,method);     
      stream >> time;
      stream >> grade;
      for(;;)
	{
	  stream >> ingr;
	  if(ingr == "%ENDRECIPE" || ingr == "%ENDLIST")
	    {
	      stream.ignore(1);
	      break;
	    }
	  stream >> amount;
	  ingredient = RecipeIngredient(db.fetchIngredient(ingr));
	  ingredient.setAmount(amount);
	  stream >> amount;
	  unit = static_cast<Unit>(amount);
	  ingredient.setUnit(unit);
	  ingredients.push_back(ingredient);
	}
      db.addRecipe(Recipe(name,method,time,grade,ingredients));
      ingredients.clear();
      // cout << left << name << " Was added\n";
    } while(ingr != "%ENDLIST");
  cout << endl;
  return true;
}
bool add_ingredient(EditDB& db)
{
  int tmpInt;
  string tmpStr;
  Ingredient ingredient;
  cout << "Input ingredient (format: name price kcal): \n";
  cin >> tmpStr;
  ingredient.setName(tmpStr);
  cin >> tmpInt;
  ingredient.setPrice(tmpInt);
  cin >> tmpInt;
  ingredient.setKcal(tmpInt);
  return db.addIngredient(ingredient);
}
bool fetch_ingredient(EditDB& db)
{
  string ingredient_name;
  Ingredient ingredient;
  cout << "Enter ingredient: ";
  cin >> ingredient_name;
  try{
    ingredient = db.fetchIngredient(ingredient_name);
  }
  catch(DB_Exception e)
    {
      cerr << endl << e.what() << endl << endl;
      return false;
    }
  cout << endl << ingredient.getName() << " price: " << ingredient.getPrice()
       << " kcal: " << ingredient.getKcal() << endl << endl;
  return true;
}

bool query_ingredient_test(SearchDB& db)
{ 
  RecipeList recipes;
  vector<string> ingredients;
  string name;
  while(name != "exit")
    {
      cout << "Enter ingredient to add (exit to quit)\n"
	   << "Choice: ";
      cin >> name;
      if(!db.checkIngredient(name) && name != "exit")
	cout << "Ingredient not found in database \n";
      else if (name != "exit")
	{
	  ingredients.push_back(name);
	  cout << name << " was added!\n\n";
	}
    }
  recipes = db.queryIngredientList(ingredients);
  cout << "Recipies containing: ";
  for(auto i : ingredients) cout << i << " ";
  cout << "\n\n";
  print_recipe_list(recipes);
  return true;
}
bool query_not_ingredient_test(SearchDB& db)
{
  RecipeList recipes;
  vector<string> ingredients;
  string name;
  while(name != "exit")
    {
      cout << "Enter ingredient to add (exit to quit)\n"
	   << "Choice: ";
      cin >> name;
      if(!db.checkIngredient(name) && name != "exit")
	cout << "Ingredient not found in database \n";
      else if (name != "exit")
	{
	  ingredients.push_back(name);
	  cout << name << " was added!\n\n";
	}
    }
  recipes = db.queryNotIngredientList(ingredients);
  cout << "Recipies not containing: ";
  for(auto i : ingredients) cout << i << " ";
  cout << "\n\n";
  print_recipe_list(recipes);
  return true;
}

bool query_list_test(SearchDB& db)
{
  RecipeList recipe_list;
  char c;
  cout << "\n Enter + to query next n recipes - the last n recipes 0 to exit \n";
  while(c != '0')
    {
      cout << "Choice: ";
      cin >> c;
      if (c == '+')
	{
	  recipe_list = db.queryList(true);
	  print_recipe_list(recipe_list);
	  cout << db.getPos();
	}
      else if (c == '-')
	{
	  recipe_list = db.queryList(false);
	  print_recipe_list(recipe_list);
	  cout << db.getPos() << endl;
	}
      else
	cout << "Please enter + - or 0\n";   
    }
}

bool allergene_test(SearchDB& db)
{
  int selection = 99;
  AllergeneArray allergenes{};
  RecipeList recipe_list;
  while(selection != 14)
    {
      cout << left << setw(18) << "0.Fruit: "; if(allergenes[0]) cout << "Enabled\n"; else cout << endl;
      cout << setw(18) << "1.Garlic: "; if(allergenes[1]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "2.Hot peppers: "; if(allergenes[2]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "3.Oats : "; if(allergenes[3]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "4.Wheat: "; if(allergenes[4]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "5.Gluten: "; if(allergenes[5]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "6.Peanut: "; if(allergenes[6]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "7.Tree nut: "; if(allergenes[7]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "8.Shellfish: ";      if(allergenes[8]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "9.Meat/Alpha-gal: "; if(allergenes[9]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "10.Egg: "; if(allergenes[10]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "11.Milk: "; if(allergenes[11]) cout << "Enabled\n"; else cout << endl;
      cout << setw(18) << "12.Lactose: "; if(allergenes[12]) cout << "Enabled\n";  else cout << endl;
      cout << setw(18) << "13.Soy: "; if(allergenes[13]) cout << "Enabled\n";  else cout << endl;
      cout <<  "14.Search\n\n";
      cout <<  "Selection: ";
      cin  >> selection;

      allergenes[selection] = !allergenes[selection];
    }
  recipe_list = db.queryAllergeneList(allergenes);
  print_recipe_list(recipe_list);
}
void calculate_price_test(EditDB& db)
{
  Recipe recipe = db.fetchRecipe("Hallonkaka");
  cout << "Hallonkaka kostar: " << db.calculatePrice(recipe);
}

void query_ingredient_names_test(SearchDB& db)
{
  IngredientNames ingredient_names = db.queryIngredientNames();
  
  for(auto i : ingredient_names)
    {
      cout << i << endl;
    }
}
void query_price_test(SearchDB& db)
{
  Price price;
  cout << "Enter upper bound: ";
  cin >> price.upper_bound;
  cout << "Enter lower bound: ";
  cin >> price.lower_bound;
  RecipeList recipe_list = db.queryPrice(price);
  print_recipe_list(recipe_list);
}
void query_kcal_test(SearchDB& db)
{
  Cal kcal;
  cout << "Enter upper bound: ";
  cin >> kcal.upper_bound;
  cout << "Enter lower bound: ";
  cin >> kcal.lower_bound;
  RecipeList recipe_list = db.queryKcal(kcal);
  print_recipe_list(recipe_list);
}
bool diet_test(SearchDB& db)
{
  int selection = 99;
  DietArray diets{};
  RecipeList recipe_list;
  while(selection != 4)
    {
      cout << left << setw(18) << "0.vegetarian: "; 
      if(diets[0]) cout << "Enabled\n"; 
      else cout << endl;
      cout << setw(18) << "1.vegan: "; 
      if(diets[1]) cout << "Enabled\n";  
      else cout << endl;
      cout << setw(18) << "2.Halal: ";
      if(diets[2]) cout << "Enabled\n";  
      else cout << endl;
      cout << setw(18) << "3.kosher : ";
      if(diets[3]) cout << "Enabled\n"; 
      else cout << endl;
      cout << endl << "4.Search\n";
 
      cout <<  "Selection: ";
      cin  >> selection;
      diets[selection] = !diets[selection];
    }
  recipe_list = db.queryDietList(diets);
  print_recipe_list(recipe_list);
  return true;
}
