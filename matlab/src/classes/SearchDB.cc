#include "classes/headers/SearchDB.h"
#include "classes/headers/Ingredient.h"
/*
  Takes ingredient name as parameter and returns ingredient object
*/

Ingredient SearchDB::makeIngredient(const string& name)
{
  Ingredient tmp;
  query_.prepare("SELECT * FROM Ingredient where name=:name"); //exception måste till här ifall ingrediens inte finns
  query_.bindValue(":name",name.c_str());
  query_.exec();
  query_.next();
  tmp.setName(query_.value(0).toString().toStdString());
  tmp.setPrice(query_.value(1).toInt());
  tmp.setKcal(query_.value(2).toInt());
  
}
