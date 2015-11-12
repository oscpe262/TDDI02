#ifndef RECIPEINGREDIENT_H
#define RECIPEINGREDIENT_H
#include "Ingredient.h"

enum Unit{gram, deciliter, teaspoon, tablespoon};

class RecipeIngredient : public Ingredient
{
  RecipeIngredient() = default;
  RecipeIngredient(string name, int price, int kcal,Unit unit,double amount)
    : Ingredient(name,price,kcal), unit_(unit), amount_(amount) {}

  Unit   getUnit() {return unit_;}
  double getAmount() {return amount_;}

  void   setUnit(Unit unit) {unit_ = unit;}
  void   setAmount(double amount) {amount_ = amount;}


  Unit unit_;
  double amount_;
};

#endif
