#ifndef SEARCHTERM_H
#define SEARCHTERM_H
#include "classes/headers/Recipe.h"
#include <iostream>
using namespace std;

struct Price
{
  double upper_bound;
  double lower_bound;
};
struct Cal
{
  int upper_bound;
  int lower_bound;
};

struct Time
{
  int upper_bound;
  int lower_bound;
};
struct Allergies{
  bool allergy;
};

class SearchTerm
{
  
 public:
  
  vector<string> getIngredients()    const {return ingredients_;}
  vector<string> getNotIngredients() const {return ingredients_;}
  Allergies getAllergies()           const {return allergies_;}
  Price getPrice()                   const {return price_;}
  Cal getCal()                       const {return cal_;}
  Time getTime()                     const {return time_;}
  RecipeList getSerchResult()        const {return search_result_;}

  void setIngredients(const vector<string>& ingredients)    {ingredients_ = ingredients;}
  void setNotIngredients(const vector<string>& ingredients) {not_ingredients_ = ingredients;}
  void setAllergies(const Allergies& allergies)             {allergies_ = allergies;}
  void setPrice(Price& price)                               {price_ = price;}
  void setCal(const Cal& cal)                               {cal_ = cal;}
  void setTime(const Time& time)                            {time_ = time;}
  void setSearchResult(const RecipeList& search_result)     {search_result_ =  search_result;}
  
 private:
  vector<string> ingredients_;
  vector<string> not_ingredients_;
  Allergies allergies_;
  Price price_;
  Cal cal_;
  Time time_;
  RecipeList search_result_;
};

#endif
