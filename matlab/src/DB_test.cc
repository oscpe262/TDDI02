#include <QtCore>
#include <QCoreApplication>
#include <iostream>
#include <fstream>
#include "classes/headers/Ingredient.h"
#include "classes/headers/EditDB.h"

using namespace std;
void print_menu();
bool import_ingredients(ifstream& stream,EditDB& db);
bool import_recipes(ifstream& stream, EditDB& db);

int main(int argc, char* argv[])
{

  EditDB test_db;
  int menu = 0;
  string name;
  Ingredient ingredient("Korv",5,200);
  ifstream importstream;

  if(!(argc == 1 || argc ==3))
    {
      cerr << "usage: ./DB_test -F filename.txt \n"
	   << "Flags: \n"
	   << "-i import ingredients\n"
	   << "-r import recipies\n";
      return 1;
    }
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
	  if(test_db.addIngredient(ingredient))
	    cout << "Ingrediens lades till";
	  else
	    cout << "Ingrediens finns redan";
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
	}
      
      print_menu();
    }while(cin >> menu);
  
  QCoreApplication app(argc, argv);
  return app.exec();
}

void print_menu()
{
  cout << "EditDB Test menu\n"
       << "1.CreateDB\n"
       << "2.ClearDB\n"
       << "3.Print tables\n"
       << "4.add_ingredient\n"
       << "5.Check ingredient\n"
       << "6.Remove_ingredient\n";

}
bool import_ingredients(ifstream& stream,EditDB& db)
{}
bool import_recipes(ifstream& stream, EditDB& db)
{}

  
