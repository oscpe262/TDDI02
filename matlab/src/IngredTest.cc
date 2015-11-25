#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

void IngCreateTest (const Ingredient& foo ) {
  std::cout << "Ingredient " << foo.name_ << " added:" << endl 
	    << "Price: " << foo.price_ << endl
	    << "Kcal: " << foo.kcal_ << endl << endl;
  return;
};

// Ing, RecIng, InfoIng
int main() {
  // Pröva konstruktorer
  std::cout << "Initierar \"Mjöl\"" << endl;
  Ingredient Mjol = {"Mjöl",10,100};
  IngCreateTest (Mjol);

  std::cout << "Kopierar " << Mjol.name_ << " med nytt namn." << endl;
  Ingredient Mjol2 = Mjol;
  Mjol2.setName("Vetemjöl");
  IngCreateTest (Mjol2);

  std::cout << "Initierar \"Rågmjöl\"" << endl;
  Ingredient Mjol3 {"Rågmjöl",10,100};
  IngCreateTest (Mjol3);
  
  // Pröva destruktorer
  std::cout << "Tar bort " << Mjol3.name_ << " ..." << endl;
  delete 
  // Pröva medlemsfunktioner
  // Pröva åtkomst av medlemsvariabler

};
