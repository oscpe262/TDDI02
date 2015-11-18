#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void IngCreateTest (const Ingredient& foo ) {
  std::cout << "Ingredient " << foo.name_ << " added:" << endl 
	    << "Price: " << foo.price_ << endl
	    << "Kcal: " << foo.kcal_ << endl;
  return;
};

// Ing, RecIng, InfoIng
int main() {
  // Pröva konstruktorer
  std::cout << "Initierar \"Mjöl\"" << endl;
  Ingredient Mjol = {"Mjöl",10,100};
  IngCreateTest (Mjol);
  // Pröva destruktorer
  // Pröva medlemsfunktioner
  // Pröva åtkomst av medlemsvariabler

};
