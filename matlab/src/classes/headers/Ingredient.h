#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <array>
using namespace std;

/* en.wikipedia.org/wiki/List_of_allergens - TO BE REVIEWED
 * Currently includes Lactose intolerance.
 * # 14
 *
 * Fruit
 * Garlic
 * Hot peppers
 * Oats
 * Wheat
 * Gluten
 * Peanut
 * Tree nut
 * Shellfish
 * Meat/Alpha-gal
 * Egg
 * Milk
 * Lactose
 * Soy
 */

/* Other preferences
 * # 4
 * 
 * Vegetarian
 * Vegan
 * Halal
 * Kosher
 */

typedef array<bool,14> AllergeneArray;
typedef array<bool,4> DietArray;

enum Allergene { fruit, garlic, hot_peppers, oats, wheat, gluten, peanut, tree_nut,
		 shellfish, alpha_gal, egg, milk, lactose, soy };

enum Diet { vegetarian, vegan, halal, kosher };

class Ingredient
{
 public:
  Ingredient() = default;
 Ingredient(string name, double price, int kcal) : name_(name), price_(price), kcal_(kcal) {}
  
  Ingredient( const Ingredient& ) = default;

  Ingredient& operator=( const Ingredient& ) = default;
  Ingredient& operator=( Ingredient&& ) = default;


  string getName() const {return name_;}
  double getPrice()   const {return price_;}
  int getKcal()    const {return kcal_;}

  void setName(string name){name_ = name;}
  void setPrice(double price) {price_ = price;}
  void setKcal(int kcal)   {kcal_ = kcal;}

  bool addAllergene(int);
  bool removeAllergene(int);
  bool addDiet(int);
  bool removeDiet(int);

  //private:
  string name_;
  double price_;
  int kcal_;
  AllergeneArray allergenes_ {{}};
  DietArray diets_ {{}};
};

#endif
