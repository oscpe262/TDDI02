#include "classes/headers/Ingredient.h"
#include "classes/Ingredient.cc"
#include "classes/headers/RecipeIngredient.h"
#include <iostream>
#include <string>
#include <array>
#include <stdexcept>

void IngCreateTest (const Ingredient& foo ) {
  std::cout << "Ingredient \033[1;36m" << foo.name_ << "\033[0m:" << endl;
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

void IngCheck (const Ingredient& foo, string name, double price, int kcal, AllergeneArray allergenes, DietArray diets) {
  if (foo.name_ == name && foo.price_ == price && foo.kcal_ == kcal && foo.allergenes_ == allergenes && foo.diets_ == diets)
    cout << "\033[1;32mCheck OK \033[0m\n" << endl;
  else
    cout << "\033[1;31mCheck Failed \033[0m\n" << endl;
  return;
}

// Ing, RecIng, InfoIng
int main() {

  std::cout << "Initierar \"Mjöl\"" << endl;
  Ingredient Mjol = {"Mjöl",10,100};
  IngCreateTest(Mjol);
  IngCheck(Mjol,"Mjöl",10,100,Mjol.allergenes_,Mjol.diets_);

  std::cout << "Kopierar " << Mjol.name_ << endl;

  Ingredient Mjol2 = Mjol;
 IngCheck(Mjol,Mjol2.name_,Mjol2.price_,Mjol2.kcal_,Mjol2.allergenes_,Mjol2.diets_);
  std::cout << "Ändrar namn, pris och kcal-värde" << endl;

  Mjol2.setName("Vetemjöl");
  Mjol2.setPrice(11);
  Mjol2.setKcal(50);
  IngCreateTest(Mjol2);
  IngCheck(Mjol2,"Vetemjöl",11,50,Mjol.allergenes_,Mjol.diets_);

  std::cout << "Lägger till allergen \"vete\" samt diet \"vegan\"." << endl;
  Mjol2.addAllergene(4);
  Mjol2.addDiet(1);
  AllergeneArray testArray1 {0,0,0,0,1,0,0,0,0,0,0,0,0,0};
  DietArray testArray2 {0,1,0,0};
  IngCreateTest(Mjol2);
  IngCheck(Mjol2,"Vetemjöl",11,50,testArray1,testArray2);

  std::cout << "Tar bort allergen, försöker lägga till befintlig diet." << endl;
  Mjol2.removeAllergene(4);
  Mjol2.addDiet(1);
  testArray1[4]=0;
  IngCheck(Mjol2,"Vetemjöl",11,50,testArray1,testArray2);

  std::cout << "Tar bort diet, läger till allergen dubbelt." << endl;
  Mjol2.addAllergene(4);
  Mjol2.removeDiet(1);
  Mjol2.addAllergene(4);
  testArray1[4]=1;
  testArray2[1]=0;

  IngCheck(Mjol2,"Vetemjöl",11,50,testArray1,testArray2);
  // Pröva medlemsfunktioner
  // Pröva åtkomst av medlemsvariabler

};
