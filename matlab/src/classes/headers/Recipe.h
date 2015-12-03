#ifndef RECIPE_H
#define RECIPE_H
#include <string>
#include <vector>
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"



struct MiniRecipe
{
  
MiniRecipe(string name = "null" ,int time = 0,double grade = 0)
: name_(name),minutesTime_(time),grade_(grade) {}
  string name_;
  int minutesTime_;
  double grade_;

  //  bool  operator == (const MiniRecipe& rhs) const  {return name_ == rhs.name_;}
  bool  operator <  (const MiniRecipe& rhs) const  {return name_ < rhs.name_;}
  bool  operator >  (const MiniRecipe& rhs) const  {return name_ > rhs.name_;}
};

typedef vector<RecipeIngredient> IngredientList;
typedef vector<string> IngredientNames;
typedef vector<MiniRecipe> RecipeList;

class Recipe
{
 public:
  //Konstruktorer
 Recipe()
   : name_{}, method_{"Empty"}, minutesTime_{}
  {}
  
 Recipe( const string& name,
	 const string& method,
	 const int& minutes, 
	 const double& grade,
	 const IngredientList& ingredients,
	 const int& price = 0,
	 const int& kcal = 0,
	 const int& portions = 4 )
   : name_{name}, method_{method}, minutesTime_{minutes}, grade_{grade}, ingredients_{ingredients}, price_{price}, kcal_{kcal}, portions_{portions}
  {}
  
  Recipe( const Recipe& ) = default;
  Recipe( Recipe&& ) = default;


  //Destruktor
  


  //Operatorer

  Recipe& operator=(const Recipe&) = default;



  //Medlemsfunktioner
  void setName(const string& name){name_ = name;}
  void setMethod(const string& method){method_ = method;}
  void setMinutesTime(const int& minutesTime){minutesTime_ = minutesTime;}
  void setGrade(const double grade){grade_ = grade;}
  void setTime(const int& minutesTime){minutesTime_ = minutesTime;}
  void setPrice(const int& price){price_ = price;}
  void setPortions(const int& portions){portions_ = portions;}
  void setIngredients(const IngredientList& ingredients){ingredients_ = ingredients;}

  string getName() const {return name_;}
  string getMethod() const {return method_;}
  int getMinutesTime() const {return minutesTime_;}
  double getGrade() const {return grade_;}
  int getPrice() const {return price_;}
  int getKcal() const {return kcal_;}
  int getPortions() const {return portions_;}

  AllergeneArray getAllergenes() const;
  DietArray getDiets() const;

  IngredientList getIngredients() const {return ingredients_;}

  void addComment( const string& );
  //double calcPrice(double) const; //se motivering nedan
  //double calcKcal(double) const;
  
  //  void addIngredient(s)?
  




  //Datamedlemmar
  string name_;
  string method_;
  int minutesTime_;
  double grade_;
  IngredientList ingredients_;
  int price_;    //Som vi pratade om så lägger vi till denna infon i recipe och sparar i databasen
  int kcal_;
  int portions_; //Priset kommer att beräknas då receptet läggs in mha addRecipe i EditDB så det
  
  vector<string> comments_;
 

 // vector<RelatedRecipe> relatedRecipes_;
  // something something image_;



 private:

};
#endif
