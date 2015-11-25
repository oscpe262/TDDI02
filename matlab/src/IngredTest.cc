#include "classes/headers/Ingredient.h"
#include "classes/Ingredient.cc"
#include "classes/headers/RecipeIngredient.h"
#include <iostream>
#include <string>
#include <array>
#include <stdexcept>

void IngCreateTest (const Ingredient& foo ) {
  std::cout << "Ingredient " << foo.name_ << " added:" << endl;
  std::cout << "Price: " << foo.price_ << endl;
  std::cout << "Kcal: " << foo.kcal_ << endl;
  std::cout << "Allergenfält: ";
  for (int i = 0; i<14;i++) {
    std::cout << foo.allergenes_.at(i);
  }
  std::cout << endl << "Dietfält: ";
  for (int j = 0; j<4; j++) {
    std::cout << foo.diets_.at(j);
  }
  std::cout << endl << endl;
  return;
};

// Ing, RecIng, InfoIng
int main() {
  // Pröva konstruktorer
  std::cout << "Initierar \"Mjöl\"" << endl;
  Ingredient Mjol = {"Mjöl",10,100};
  IngCreateTest (Mjol);

  std::cout << "Kopierar " << Mjol.name_ << ", ändrar namn, pris och kcal-värde" << endl;
  Ingredient Mjol2 = Mjol;
  Mjol2.setName("Vetemjöl");
  Mjol2.setPrice(11);
  Mjol2.setKcal(50);
  IngCreateTest (Mjol2);

  std::cout << "Lägger till allergen \"vete\" samt diet \"vegan\"." << endl;
  Mjol2.addAllergene(4);
  Mjol2.addDiet(1);
  IngCreateTest (Mjol2);
  // Pröva medlemsfunktioner
  // Pröva åtkomst av medlemsvariabler

};
