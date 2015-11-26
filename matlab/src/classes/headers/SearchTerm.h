#ifndef SEARCHTERM_H
#define SEARCHTERM_H
#include "classes/headers/Recipe.h"
#include <iostream>
using namespace std;

struct Price
{
  Price() = default;
  Price(int lower, int upper) : lower_bound(lower), upper_bound(upper) {}
  int lower_bound;
  int upper_bound;

};
struct Cal
{
  Cal() = default;
  Cal(int lower, int upper) : lower_bound(lower), upper_bound(upper) {}
  int lower_bound;
  int upper_bound;
};

struct Time
{
    Time() = default;
    Time(int lower, int upper) : lower_bound(lower), upper_bound(upper) {}

    int lower_bound;
    int upper_bound;
};
struct Allergies{
  bool allergy;
};

class SearchTerm
{
  
 public:
  SearchTerm()
  {
      ingredients_ = {};
      not_ingredients_={};
      allergenes_={};
      price_={};
      cal_={};
      time_={};
      search_result_={};
  }

  vector<string> getIngredients()    const {return ingredients_;}
  vector<string> getNotIngredients() const {return ingredients_;}
  AllergeneArray getAllergenes()           const {return allergenes_;}
  Price getPrice()                   const {return price_;}
  Cal getCal()                       const {return cal_;}
  Time getTime()                     const {return time_;}
  RecipeList getSerchResult()        const {return search_result_;}

  void setIngredients(const vector<string>& ingredients)    {ingredients_ = ingredients;}
  void setNotIngredients(const vector<string>& ingredients) {not_ingredients_ = ingredients;}
  void setAllergenes(const AllergeneArray& allergenes)      {allergenes_ = allergenes;}
  void setPrice(const Price& price)                               {price_ = price;}
  void setCal(const Cal& cal)                               {cal_ = cal;}
  void setTime(const Time& time)                            {time_ = time;}
  void setSearchResult(const RecipeList& search_result)     {search_result_ =  search_result;}
  
 private:
  vector<string> ingredients_;
  vector<string> not_ingredients_;
  AllergeneArray allergenes_;
  Price price_;
  Cal cal_;
  Time time_;
  RecipeList search_result_;
};

#endif
