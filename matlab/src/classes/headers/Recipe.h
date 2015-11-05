#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include <vector>


struct MiniRecipe
{
  string name_;
  int minutesTime_;
  double grade_;
};

class Recipe
{
 public:
  //Konstruktorer
 Recipe()
   : name_{}, description_{"Empty"}, minutesTime_{}
  {}
  
 Recipe( const string& name, const string& description = "Empty2", int minutes = -1 )
   : name_{name}, description_{description}, minutesTime_{minutes}
  {}
  
  Recipe( const Recipe& ) = default;
  Recipe( Recipe&& ) = default;


  //Destruktor
  


  //Operatorer





  //Medlemsfunktioner
  void setTime( int );
  void addComment( const string& );
  void setGrade( double );
  //  void addIngredient(s)?
 




  //Datamedlemmar
  string name_;
  string description_;
  int minutesTime_;

  vector<string> comments_;
  double grade_;
  // vector<RecipeIngredient> ingredients_;
  // vector<RelatedRecipe> relatedRecipes_;
  // something something image_;



 private:

};

#endif
