#include "classes/headers/EditDB.h"
#include <QtCore>
#include <QCoreApplication>
#include <iostream>
#include "classes/headers/Ingredient.h"


using namespace std;
void print_menu();

int main(int argc, char* argv[])
{
  QCoreApplication app(argc, argv);
  EditDB test_db;
  int menu = 0;
  string name;
  Ingredient ingredient("Korv",5,200);
  //Menu
  do
    {
      switch(menu)
	{
	case 1:
	  test_db.create_db();
	  break;
	case 2:
	  test_db.clear_db();
	  break;
	case 3:
	  test_db.print_tables();
	  break;
	case 4:
	  if(test_db.add_ingredient(ingredient))
	    cout << "Ingrediens lades till";
	  else
	    cout << "Ingrediens finns redan";
	  break;
	case 5:
	  cout << "Ange ingrediens: ";
	  cin >> name;
	  if(test_db.check_ingredient(name))
	    cout << "\nIngrediensen finns\n";
	  else
	    cout << "\nIngrediensen finns inte\n";
	  break;
	case 6:
	  cout << "Ange ingrediens: ";
	  cin >> name;
	  if(test_db.remove_ingredient(name))
	    cout << "Ingrediens togs bort";
	  else
	    cout << "Ingrediens finns inte";
	  break;
	}
      
      print_menu();
    }while(cin >> menu);
  
  return 0;

  return app.exec();
}

void print_menu()
{
  cout << "EditDB Test menun\n"
       << "1.CreateDB\n"
       << "2.ClearDB\n"
       << "3.Print tables\n"
       << "4.add_ingredient\n"
       << "5.Check ingredient\n"
       << "6.Remove_ingredient\n";
}
