#include <fstream>
#include <string>
#include <algorithm>
#include "xmlexport.cc"

int main(int argc, char* argv[]) {
  std::string filepath {argv[1]};
  RecipeIngredient fooIng{"Blod", 10, 30, 50, deciliter};
  IngredientList ingList{fooIng};
  Recipe foo{"Blodpudding", "Blanda blod till en pudding.", 3, 4, ingList, 100, 300, 10};

  exportXml (filepath, foo);

  return 0; 
}
