#include <QtCore>
#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include "classes/headers/Ingredient.h"
#include "classes/headers/EditDB.h"
using namespace std::chrono;
using namespace std::this_thread; 


using namespace std;
void print_menu();
bool import_ingredients(ifstream& stream,EditDB& db);
bool import_recipes(ifstream& stream, EditDB& db);
bool add_ingredient(EditDB& db);
bool add_recipe(Recipe& recipe);

int main(int argc, char* argv[])
{
  QCoreApplication app(argc, argv);
  EditDB test_db;
  int menu = 0;
  string name;
  Ingredient ingredient("Korv",5,200);
  ifstream importstream;
  /*
  if(!(argc == 1 || argc ==3))
    {
      cerr << "usage: ./DB_test -F filename.txt \n"
	   << "Flags: \n"
	   << "-i import ingredients\n"
	   << "-r import recipies\n";
      return app.exec();
    }
  */
  if(argc > 1)
    {
      if(!strcmp(argv[1], "-i"))
	{
	  importstream.open(argv[2]);
	  if(importstream.fail() || !import_ingredients(importstream,test_db))
	    {
	      cerr << "Ingredient list could not be imported, check fileame or clear db \n";
	      return 1;
	    }
	  cout << "\nImport sucessfull!\n\n";
	}
      
      else if(!strcmp(argv[1], "-r"))
	{
	  importstream.open(argv[2]);
	  if(importstream.fail() || !import_recipes(importstream,test_db))
	    {
	      cerr << "Recipe list could not be imported, check fileame or clear db \n";
	      return 1;
	    }
	  cout << "\nImport sucessfull!\n\n";
	}
      else if(!strcmp(argv[1], "-reset"))
	{
	  test_db.clearDb();
	  test_db.createDb();
	  importstream.open("ingredient_input.txt");
	  import_ingredients(importstream,test_db);
	  importstream.close();
	  /*
	  importstream.clear();
	  importstream.open("recipe_input.txt");
	  import_recipes(importstream,test_db);
	  importstream.close();
	  cout << "DB reset, ingredients and recipes imported \n";
	  */
	}
      else
	{
	  cerr << "usage: ./DB_test -F filename.txt \n"
	       << "Flags: \n"
	       << "-i import ingredients\n"
	       << "-r import recipies\n";
	  return 1;
	}
    }
		    
  do
    {
      switch(menu)
	{
	case 1:
	  test_db.createDb();
	  break;
	case 2:
	  test_db.clearDb();
	  break;
	case 3:
	  test_db.printTables();
	  break;
	case 4:
	  if(add_ingredient(test_db))
	    cout << "Ingredient added\n";
	  else
	    cout << "something went wrong, ingredient probably exists try again \n";
	  break;
	case 5:
	  cout << "Ange ingrediens: ";
	  cin >> name;
	  if(test_db.checkIngredient(name))
	    cout << "\nIngrediensen finns\n";
	  else
	    cout << "\nIngrediensen finns inte\n";
	  break;
	case 6:
	  cout << "Ange ingrediens: ";
	  cin >> name;
	  if(test_db.removeIngredient(name))
	    cout << "Ingrediens togs bort";
	  else
	    cout << "Ingrediens finns inte";
	  break;
	case 7:
	  //add_recipe();
	  break;
	
	
	}
      
      print_menu();
    }while(cin >> menu);
  

  return app.exec();
}

void print_menu()
{
  cout << "EditDB Test menu\n"
       << "1.CreateDB\n"
       << "2.ClearDB\n"
       << "3.printTables\n"
       << "4.addIngredient\n"
       << "5.checkIngredient\n"
       << "6.removeIngredient\n"
       << "7.addRecipe";

}
bool import_ingredients(ifstream& stream,EditDB& db)
{
 
  istringstream isstream;
  Ingredient ingredient;
  string row,tmpStr;
  int tmpInt;
  while(stream.peek() != EOF)
    {
      getline(stream,row);
      istringstream isstream(row);
      try{
	isstream >> tmpStr;
	ingredient.setName(tmpStr);
	isstream >> tmpInt;
	ingredient.setPrice(tmpInt);
	isstream >> tmpInt;
	ingredient.setKcal(tmpInt);
	if(isstream.fail())
	  throw DB_Exception("File could not be read, check syntax \n");
	db.addIngredient(ingredient);
	cout << ingredient.getName() << " Was added \n";
      }
      catch(DB_Exception e)
	{
	  cerr << e.what();
	  return false;
	}
    }
    return true;
}
 
bool import_recipes(ifstream& stream, EditDB& db)
{
  istringstream isstream;
  RecipeIngredient ingredient;
  string name,method,row,ingr;
  int time;
  double grade;
  IngredientList ingredients;
  char c;

  while(!stream.eof())
    {
      //try{
      stream.ignore(100,'%');
      getline(stream,name,'\n');
	cerr << name << endl;
	getline(stream,method,'\n');
	cerr << method << endl;
	stream >> time; stream.ignore(1);
	cerr << time << endl;
	stream >> grade; stream.ignore(1);
	cerr << grade << endl;
	stream >> ingr;
	while(stream != "%")
	  {
	    cerr << ingr << endl;
	    ingredient = db.fetchIngredient(ingr);
	    ingredients.push_back(RecipeIngredient(ingr));
	    stream >> ingr;
	  }
	stream.clear();
	stream.ignore(1);
	
	//Recipe recipe(name,method,time,grade,ingredients);
	
	//	cerr << recipe.getName() << " " << recipe.getMethod() << " " << recipe.getMinutesTime()
	//   << " " << recipe.getGrade() << endl;
	
	//	if(!db.addRecipe(recipe)) cerr << " fel" << endl;
    }
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
/*
bool add_recipe(Recipe& recipe)
{

}
*/

  
