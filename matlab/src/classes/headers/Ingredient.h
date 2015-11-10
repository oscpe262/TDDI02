#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
#include <vector>
using namespace std;

class Ingredient
{
 public:
  Ingredient() = default;
 Ingredient(string name, int price, int kcal) : name_(name), price_(price), kcal_(kcal) {}
  
  string getName() const {return name_;}
  int getPrice()   const {return price_;}
  int getKcal()    const {return kcal_;}

  void setName(string name){name_ = name;}
  void setPrice(int price) {price_ = price;}
  void setKcal(int kcal)   {kcal_ = kcal;}

  bool addAllergene(string);
  bool removeAllergene(string);
  bool addClassing(string);
  bool removeClassing(string);

  //private:
  string name_;
  int price_;
  int kcal_;
  vector<string> allergenes_;
  vector<string> classings_;
};

#endif
