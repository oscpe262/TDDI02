#ifndef INGREDIENT_H
#define INGREDIENT_H

#include <string>
using namespace std;

class Ingredient
{
 public:
  Ingredient() = default;
 Ingredient(string name,int price, int kcal) : name_(name), price_(price), kcal_(kcal) {}
  
  string get_name() const {return name_;}
  int get_price()   const {return price_;}
  int get_kcal()    const {return kcal_;}

  void set_name(string name){name_ = name;}
  void set_price(int price) {price_ = price;}
  void set_kcal(int kcal)   {kcal_ = kcal;}
 private:
  string name_;
  int price_;
  int kcal_;
};

#endif
