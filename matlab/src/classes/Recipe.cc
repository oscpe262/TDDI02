#include "classes/headers/Recipe.h"
#include <string>
#include <vector>

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
