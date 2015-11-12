#ifndef RECIPEINGREDIENT_H
#define RECIPEINGREDIENT_H
#include "Ingredient.h"

enum Unit{gram, deciliter, teaspoon, tablespoon};

class RecipeIngredient : public Ingredient
{
 public:
  RecipeIngredient() = default;
  RecipeIngredient(string name, int price = 0, int kcal = 0,Unit unit = gram,double amount = 0)
    : Ingredient(name,price,kcal), unit_(unit), amount_(amount) {}

  Unit   getUnit() const {return unit_;}
  double getAmount() const {return amount_;}

  void   setUnit(Unit unit) {unit_ = unit;}
  void   setAmount(double amount) {amount_ = amount;}


  Unit unit_;
  double amount_;
};

#endif
