#include "classes/headers/Recipe.h"
#include <string>
#include <vector>

struct MiniRecipe
{
  string name_;
  int minutesTime_;
  double grade_;

  void operator=(Recipe& recipe)
  {
    name_ = recipe.getName();
    minutesTime_ = recipe.getMinutesTime();
    grade_ = recipe.getGrade();
  }
};

void Recipe::setTime( int minutes )
{
  minutesTime_ = minutes;
}

void Recipe::addComment( const string& comment )
{
  comments_.push_back(comment);
}

void Recipe::setGrade( double grade )
{
  grade_ = grade;
}

double Recipe::calcPrice( double scaling ) const
{
  double priceSum { };

  for( RecipeIngredient ri : ingredients_ )
    {
      priceSum += priceSum + ri.calcPrice(scaling); // Behöver vi skicka ner scaling? Kanske räcker med att scala resultatet innan vi returnerar till GUI
    }

  return priceSum;
}

double Recipe::calcKcal( double scaling ) const
{
  double kcalSum { };

  for( RecipeIngredient ri : ingredients_ )
    {
      kcalSum += kcalSum + ri.calcKcal(scaling); // Behöver vi skicka ner scaling? Kanske räcker med att scala resultatet innan vi returnerar till GUI
    }

  return priceSum;
}
