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
typepef vector<RecipeIngredient> IngredientList;



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
  void setName(const string& name){name_ = name;}
  void setMethod(const string& description){description_ = description;}
  void setMinutesTime(const string& minutesTime_){minutesTime_ = minutesTime;}
  void setGrade(const double grade){grade_ = grade;}
  void setTime(const int& time){time_ = time;}
  void setIngredients(const IngredientList& ingredients){ingredients_ = ingredients}

  void getName() const {return name_}
  void getMethod() const {return decription_;}
  void getMinutesTime() const {return minutesTime_;}
  void getGrade() const {return grade_;}
  void getIngredients() const {return ingredients;}

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
