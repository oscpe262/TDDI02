#ifndef RECIPEINGREDIENT_H
#define RECIPEINGREDIENT_H
#include "Ingredient.h"

enum Unit{gram, deciliter, teaspoon, tablespoon,pcs};

class RecipeIngredient : public Ingredient
{
 public:
  RecipeIngredient() = default;
  //Lade till konstruktor för initiering med Ingredientobjekt, behövdes för att skapa recept från databasen //erik
  /* RecipeIngredient(const Ingredient& i) : Ingredient(i.getName(),i.getPrice(),i.getKcal()), amount_{0}, unit_{gram} {} */
 RecipeIngredient(const Ingredient& i) : Ingredient(i), amount_{0}, unit_{gram} {} 
 RecipeIngredient(string name, double price = 0, int kcal = 0,double amount = 0, Unit unit = gram)
   : Ingredient(name,price,kcal), amount_(amount),unit_(unit) {}

 RecipeIngredient& operator=( const Ingredient& i )
    {
      name_ = i.name_; //getfunktioner om private, om protected går detta bra
      price_ = i.price_;
      kcal_ = i.kcal_;
      allergenes_ = i.allergenes_;
      diets_ = i.diets_;
    }

  Unit   getUnit() const { return unit_; }
  double getAmount() const { return amount_; }

  void   setUnit(Unit unit) { unit_ = unit; }
  void   setAmount(double amount) { amount_ = amount; }

  double calcPrice(double scaling) const { return getPrice()*getAmount()*scaling;}
  int calcKcal(double scaling) const { return getKcal()*getAmount()*scaling;}

  //private:

  double amount_;
  Unit unit_;

};

#endif
