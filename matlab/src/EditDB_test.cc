#include "classes/headers/EditDB.h"
#include <QtCore>
#include <QCoreApplication>
#include <iostream>
using namespace std;
void print_menu();

int main(int argc, char* argv[])
{
  QCoreApplication app(argc, argv);
  EditDB test_db;

  int menu = 0;
 //Menu
  print_menu();
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
	}
      print_menu()
    }while(cin >> menu);
  
  return 0;

  return app.exec();
}

void print_menu()
{
  cout << "EditDB Test menun\n"
       << "1.CreateDB\n"
       << "2.ClearDB\n"
       << "3.Print tables\n";
}
