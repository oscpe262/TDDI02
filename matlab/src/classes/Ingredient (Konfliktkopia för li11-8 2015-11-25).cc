#include "headers/Ingredient.h"
#include <string>

using namespace std;

bool Ingredient::addAllergene(int i)
{
  if( allergenes_[i] == false )
    {
      allergenes_[i] = true;
      return true;
    }
  return false;
}

bool Ingredient::removeAllergene(int i)
{
  if( allergenes_[i] == true )
    {
      allergenes_[i] = false;
      return true;
    }
  return false;
}

bool Ingredient::addDiet(int i)
{
  if( diets_[i] == false )
    {
      diets_[i] = true;
      return true;
    }
  return false;
}

bool Ingredient::removeDiet(int i)
{
  if( diets_[i] == true )
    {
      diets_[i] = false;
      return true;
    }
  return false;
}

  
