#include "classes/headers/Ingredient.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool Ingredient::addAllergene(string name)
{
  if( find( allergenes_.begin(), allergenes_.end(), name ) != allergenes_.end() )
    return false;

  allergenes_.push_back(name);
  return true;
}

bool Ingredient::removeAllergene(string name)
{
  if( find( allergenes_.begin(), allergenes_.end(), name ) == allergenes_.end() )
    return false;
  
  allergenes_.erase( remove( allergenes_.begin(), allergenes_.end(), name ), allergenes_.end() );
  return true;
}

bool Ingredient::addClassing(string)
{
   if( find( classings_.begin(), classings_.end(), name ) != classings_.end() )
    return false;

  classings_.push_back(name);
  return true;
}

bool Ingredient::removeClassing(string)
{
  if( find( classings_.begin(), classings_.end(), name ) == classings_.end() )
    return false;
  
  classings_.erase( remove( classings_.begin(), classings_.end(), name ), classings_.end() );
  return true;
}
