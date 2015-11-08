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
	  test_db.add_ingredient(ingredient);
	  break;
	case 5:
	  string str;
	  cout << "Ange ingrediens: ";
	  cin >> str;
	  if(test_db.check_ingredient(str))
	    cout << "\nIngrediensen finns\n";
	  else
	    cout << "\nIngrediensen finns inte\n";
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
       << "4.Insert test ingredient\n"
       << "5.Check ingredient\n";
}
