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
