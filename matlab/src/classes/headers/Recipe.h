#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include <vector>
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"

struct MiniRecipe
{
  string name_;
  int minutesTime_;
  double grade_;
};
typedef vector<RecipeIngredient> IngredientList;



class Recipe
{
 public:
  //Konstruktorer
 Recipe()
   : name_{}, method_{"Empty"}, minutesTime_{}
  {}
  
 Recipe( const string& name, const string& method, const int& minutes, const double& grade, const IngredientList& ingredients)
   : name_{name}, method_{method}, minutesTime_{minutes}, grade_{grade}, ingredients_{ingredients}
  {}
  
  Recipe( const Recipe& ) = default;
  Recipe( Recipe&& ) = default;


  //Destruktor
  


  //Operatorer





  //Medlemsfunktioner
  void setName(const string& name){name_ = name;}
  void setMethod(const string& method){method_ = method;}
  void setMinutesTime(const int& minutesTime){minutesTime_ = minutesTime;}
  void setGrade(const double grade){grade_ = grade;}
  void setTime(const int& minutesTime){minutesTime_ = minutesTime;}
  void setIngredients(const IngredientList& ingredients){ingredients_ = ingredients;}

  string getName() const {return name_;}
  string getMethod() const {return method_;}
  int getMinutesTime() const {return minutesTime_;}
  double getGrade() const {return grade_;}
  IngredientList getIngredients() const {return ingredients_;}

  void addComment(const string& );
  
  
  //  void addIngredient(s)?
  




  //Datamedlemmar
  string name_;
  string method_;
  int minutesTime_;
  double grade_;
  
  vector<string> comments_;
  IngredientList ingredients_;

 // vector<RelatedRecipe> relatedRecipes_;
  // something something image_;



 private:

};

#endif
