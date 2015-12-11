#include "classes/headers/Shell.h"
#include "classes/headers/Recipe.h"
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include "classes/headers/DB.h"
#include "classes/headers/EditDB.h"
#include "classes/headers/SearchDB.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

/*
 *** [local_dec] ***
 *
 *** [SHELL] ***
 * exportTxt ( string & Recipe )
 * *importTxt
 * exportXml ( string & Recipe )
 * importXml
 * *setScaling
 *
 *
 *** [SDB] ***
 * exactMatch
 * getRecipeResults
 * getIngredientList
 * openRecipe
 * openIngredient
 *
 *
 *** [EDB] ***
 * addRecipe
 * removeRecipe ( Recipe & string )
 * addIngredient
 * removeIngredient ( Recipe & string )
 *
 *
 *** [local] ***
 * unit2str
 *
 * clearAnnotations
 * extractStep1_Header
 * extractStep2_IngList
 *
 * fileRename
 * fileExists
 * readFromFile
 *
 * findName
 * findPortions
 * findTime
 * findIngredients
 */



/*******************
 *** [local_dec] ***
 ******************/

namespace{

  string unit2str( const Unit& unitvalue );

  void clearAnnotations( string& recipeTxt );
  string extractStep1_Header( string& str );
  string extractStep2_IngList( string& str );

  void fileRename( string& oldFileName );
  bool fileExists( const string& name );
  void readFromFile( istream& is, string& str );

  string findName( const string& fieldstr );
  int findPortions( const string& fieldstr );
  int findTime( const string& fieldstr );
  IngredientList findIngredients( const string& fieldstr );

  
  
  string tagStringCont(ifstream & fs);
  int tagIntCont(ifstream & fs);
  double tagDblCont(ifstream & fs);

  bool replaceAll(string& str, const string& from, const string& to);
}





/***************
 *** [SHELL] ***
 **************/


void Shell::exportTxt( const string& recipeName, string fileName )
{
  Recipe recipe { openRecipe(recipeName) };
  exportTxt(recipe, fileName);
}

void Shell::exportTxt( const Recipe& recipe, string fileName )
{
  if( fileName == "null" )
    fileName = recipe.getName();

  if( fileName.substr(fileName.length()-5, string::npos) != ".txt" )
    fileName += ".txt";

  if( fileExists(fileName) ) 
    {
      // Observera att currentRecipe_ har ändrats enligt openRecipe om exportTxt(string, string).
      throw Shell_Exception{ "Shell :: exportTxt :\n En fil med namnet " + fileName + " existerar redan!" };
    }

  ofstream recipeTxt {fileName};
  if( !recipeTxt )
    {
      // Observera att currentRecipe_ har ändrats enligt openRecipe om exportTxt(string, string).
      recipeTxt.close();
      throw Shell_Exception{ "Shell :: exportTxt :\nUtfilströmmen till fil " + fileName + " kunde ej startas!" };
    }

  recipeTxt << "<!-- " << fileName << " -->\n"
	    << "# " << recipe.getName() << " (" << recipe.getPortions() << " portioner)\n"
	    << "Tillagningstid: c:a " << recipe.getMinutesTime() << " min\n"
	    << "============\n"; // godtyckligt antal?

  for( RecipeIngredient& ri : recipe.getIngredients() )
    {
      recipeTxt << ri.getName() << " " << ri.getAmount() << " " << unit2str( ri.getUnit() ) << "\n";
    }

  recipeTxt << "\n" << recipe.getMethod() << "\n\n";

  recipeTxt << "Uppskattat energiinnehåll: " << recipe.getKcal() << " kcal\n"
	    << "Uppskattat pris: " << recipe.getPrice() << " kr\n"
	    << "Betyg: " << recipe.getGrade() << "/5\n"
	    << "<!-- EOF -->";

  recipeTxt.close();
}



/*Recipe Shell::importTxt( string fileName )
{
  if( !fileExists(fileName) )
    {
      throw Shell_Exception{ "Shell :: importTxt :\nFilen " + fileName + " existerar ej!" };
    }

  ifstream ifs {fileName};

  if( !ifs )
    {
      ifs.close();
      throw Shell_Exception{ "Shell :: importTxt :\nInfilströmmen från fil " + fileName + " kunde ej startas!" };
    }

  // Läs till string fileContents
  string fileContents;
  readFromStream(ifs, fileContents);
  ifs.close();

  // Rensa bort kommentarer: <!-- kommentar -->
  clearAnnotations(fileContents);

  // Dela upp
  string header  { extractStep1_Header(fileContents) };
  stirng ingList { extractStep2_IngList(fileContents) };
  string tail    { fileContents };

  // Försök tilldela
  Recipe recipe;
  
  recipe.setName(findName(header));
  recipe.setPortions(findPortions(header));
  recipe.setTime(findTime(header));

  recipe.setIngredients(findIngredients(ingList));



  // Namn (, portioner, tid)
  /*  istringstream iss {fileContents};
      string fileLine, fileSection;
  
      for( int i {} ; i < 5 ; ++i )
      {
      getline(iss, fileLine);
      if( fileLine.find('=') != string::npos )
      {
      break;
      }
      fileSection += fileLine;
      fileSection.push_back('\n');
      }*/

  // header

  // ingredient list

  // description & tail
  /*

    IngredientList ingList { findIngredients(;

    recipe.setIngredients(ingList);

    // Ingredienser
  
    // first << second << third
    // first << secondthird



    }
}*/


void Shell::exportXml( const string& recipeName, string filepath )
{
  Recipe recipe { openRecipe(recipeName) };
  exportXml(recipe, filepath);
}


void Shell::exportXml( const Recipe& recipe, string filepath )
{
  if( filepath == "null" )
    filepath = recipe.getName();
  
  if( filepath.substr(filepath.length()-5, string::npos) != ".xml" )
    filepath += ".xml";
  
  while( fileExists(filepath) ) 
    {
      fileRename(filepath);
    }

  ofstream fs {filepath};
  if( !fs )
    {
      // Observera att currentRecipe_ har ändrats enligt openRecipe om exportTxt(string, string).
      fs.close();
      throw Shell_Exception{ "Shell :: exportTxt :\nUtfilströmmen till fil " + filepath + " kunde ej startas!" };
    }

  fs << "<?xml version=\"1.0\"?>\n"
     << "<!-- " << filepath << " -->\n"
     << "<recipe>\n"
     << "  <name>" << recipe.getName() << "</name>\n"
     << "  <portionsize>" << recipe.getPortions() << "</portionsize>\n";
  
  for( RecipeIngredient& ri : recipe.getIngredients() )
    {
      fs << "  <ingredient>" << ri.getName()
	 << "<amount>" << ri.getAmount()
	 << "<unit>" << unit2str( ri.getUnit() )
	 << "</unit></amount></ingredient>\n";
    }

  string instruction { recipe.getMethod() };
  replaceAll(instruction, "&", "&amp;");

  fs << "  <instruction>" << instruction << "</instruction>\n"
     << "  <time>" << recipe.getMinutesTime() << "</time>\n"
     << "  <price>" << recipe.getPrice() << "</price>\n"
     << "  <energy>" << recipe.getKcal() << "</energy>\n"
     << "  <rating>" << recipe.getGrade() << "</rating>\n"
     << "</recipe>" << endl;
  
  fs.close();
}
 
Recipe Shell::importXml( const string& filepath )
{
  if( !fileExists(filepath) )
    {
      throw Shell_Exception{ "Shell :: importXml :\nFilen " + filepath + " existerar ej!" };
    }

  ifstream fs {filepath};

  if( !fs )
    {
      fs.close();
      throw Shell_Exception{ "Shell :: importXml :\nInfilströmmen från fil " + filepath + " kunde ej startas!" };
    }


  string tmp{};
  string value{};
  string trash{};
  char peek{};
  Recipe yumyum;
  IngredientList IL{};
 
  while (fs.peek() != EOF) {
    fs.ignore(1000,'<');
    peek = fs.peek();
    
    if (peek == '?') { // ignore xml version tag
      fs.ignore(1000,'>');
    }

    else if (peek == '!') { // ignore comments
      fs.ignore(1000,'>');
    }

    else if (peek == '/') { // close tag
      fs.get(peek);
      getline(fs,tmp,'>');
      if (tmp ==  "recipe")
	yumyum.setIngredients(IL);
      return yumyum;
    }

    else { //är alla med?
      getline(fs, tmp, '>'); // open tag
      if (tmp != "recipe") {
	if (tmp == "name")
	  yumyum.setName(tagStringCont(fs));
	else if (tmp == "instruction") {
	  std::string instruction (tagStringCont(fs));
	  replaceAll(instruction, "&amp;", "&");
	  yumyum.setMethod(instruction);
	}
	else if (tmp == "time")
	  yumyum.setMinutesTime(tagIntCont(fs));
	else if (tmp == "rating")
	  yumyum.setGrade(tagDblCont(fs));
	else if (tmp == "price")
	  yumyum.setPrice(tagIntCont(fs));
	else if (tmp == "portionsize")
	  yumyum.setPortions(tagIntCont(fs));
	else if (tmp == "ingredient")
	  tagIngredient(fs, IL);
	else 
	  tagStringCont(fs);
      }
    }
  }
  fs.close();
  return yumyum;
}



/*************
 *** [SDB] ***
 ************/

vector<MiniRecipe> Shell::exactMatch( const string& name )
{
  currentRecipe_ = sDB_.fetchRecipe(name);
  vector<MiniRecipe> vmr { MiniRecipe( currentRecipe_.getName(), currentRecipe_.getMinutesTime(), currentRecipe_.getGrade() ) };
  return vmr;
}

vector<MiniRecipe> Shell::getRecipeResults( SearchTerm& searchTerms )
{
  recipeSearchResults_ = sDB_.termSearch(searchTerms); 
  return recipeSearchResults_;
} 

vector<string> Shell::getIngredientNames()
{
  ingredientFullList_ = sDB_.queryIngredientNames();
  return ingredientFullList_;
}
 
Recipe Shell::openRecipe( const string& name )
{
  currentRecipe_ = sDB_.fetchRecipe(name);
  return currentRecipe_;
}
 
Ingredient Shell::openIngredient( const string& name )
{
  currentIngredient_ = sDB_.fetchIngredient(name);
  return currentIngredient_; 
}



/*************
 *** [EDB] ***
 ************/

bool Shell::addRecipe( const Recipe& recipe )
{
  return eDB_.addRecipe(recipe); // Rätt funktion?
}

bool Shell::removeRecipe( const Recipe& recipe )
{
  return eDB_.removeRecipe(recipe); // Rätt funktion?
}

bool Shell::removeRecipe( const string& name )
{
  return eDB_.removeRecipe(name);
}

bool Shell::addIngredient( const Ingredient& ingredient )
{
  return eDB_.addIngredient(ingredient); // Rätt funktion?
}

bool Shell::removeIngredient( const Ingredient& ingredient )
{
  return eDB_.removeIngredient(ingredient);
}

bool Shell::removeIngredient( const string& name )
{
  return eDB_.removeIngredient(name);
}



/***************
 *** [local] ***
 **************/

namespace{

  string unit2str( const Unit& unitvalue )
  {
    switch(unitvalue)
      {
      case gram:
	return "g";
      case deciliter:
	return "dl";
      case teaspoon:
	return "tsk";
      case tablespoon:
	return "msk";
      case pcs:
	return "st";
      default:
	return "null";
      }
  }





  void clearAnnotations( string& recipeTxt )
  {
    while( recipeTxt.find("<!--") != string::npos && recipeTxt.find("-->") != string::npos )
      {
	size_t stringPos { recipeTxt.find("<!--") };
	size_t stringPosEnd { recipeTxt.find("-->") };
	recipeTxt = recipeTxt.substr(0, stringPos) + recipeTxt.substr(stringPosEnd + 3);
      }
  }


  string extractStep1_Header( string& str )
  {
    size_t stringPos {};
    string header;

    while( str.find('\n', stringPos) != string::npos )
      {
	stringPos = str.find('\n', stringPos);
	if( str.at(stringPos + 1) == '\n' || str.at(stringPos + 1) == '=' )
	  {
	    header = str.substr(0, stringPos);
	    str = str.substr( str.find('\n', stringPos + 1) );
	    return header;
	  }
	  
	++stringPos;
      }
    throw Shell_Exception{ "Shell :: importTxt :: extractStep1_Header :\nInfil har ogiltigt format" };
  }


  string extractStep2_IngList( string& str )
  {
    size_t stringPos {};
    size_t wordsThisLine {};
    string ingList;

    while( wordsThisLine <= 4 )
      {
	if( str.at(stringPos) == '\n' ) // "\n"
	  wordsThisLine = 0;
	else if( isblank( str.at(stringPos) ) && !isspace( str.at(stringPos + 1) ) ) // " A"
	  ++wordsThisLine;
	else if( str.at(stringPos - 1) == '\n' && !isspace( str.at(stringPos) ) ) // "\nA"
	  ++wordsThisLine;

	++stringPos;
      }

    stringPos = str.rfind('\n', stringPos);

    ingList = str.substr(0, stringPos);
    str = str.substr(stringPos);
    return ingList;
  }





  void fileRename( string& oldFileName )
  {
    if( oldFileName.substr(0,3) == "New" )
      {
	if( oldFileName.at(3) == '.' )
	  oldFileName.insert(3, "(1)");
	else if( oldFileName.at(3) == '(' && oldFileName.at(4) != '9' )
	  ++oldFileName.at(4);
	else
	  oldFileName.insert(0, "New.");
      }
    else
      oldFileName.insert(0, "New.");
  }


  bool fileExists( const string& name )
  {
    ifstream filetest {name};
    if( filetest.good() )
      {
	filetest.close();
	return true;
      }
    else
      {
	filetest.close();
	return false;
      }
  }


  void readFromStream( istream& is, string& str )
  {
    string temp;
    while( getline(is, temp) )
      {
	str += temp;
	str.push_back('\n');
      }
  }





  string findName( const string& fieldstr )
  {
    istringstream iss {fieldstr};
    char c;
    string returnstr;

    // Discard until alphabetic character
    while( !isalpha( iss.peek() ) )
      {
	iss.get(c);
      }

    // Get the line and remove junk parenthesis enclosing if it exists
    getline(iss, returnstr);

    size_t junkCheck { returnstr.find('(') };

    if( junkCheck != string::npos )
      returnstr = returnstr.substr(0, junkCheck-1);

    return returnstr;
  }


  int findPortions( const string& fieldstr )
  {
    istringstream iss {fieldstr};
    string portionCheck;
    char c {'n'};
    string returnstr;
  
    while( iss )
      {
	while( !isdigit(c) )
	  {
	    iss.get(c);
	  }
      
	while( isdigit(c) )
	  {
	    returnstr += c;
	    iss.get(c);
	  }
      
	iss >> portionCheck;

	if( !isspace(c) )
	  portionCheck = c + portionCheck;
      
	if( portionCheck.find("portion") != string::npos )
	  return stoi(returnstr);
      }
    return 4; // Standardvärde
  }


  int findTime( const string& fieldstr )
  {
    istringstream iss {fieldstr};
    string minCheck;
    char c {'n'};
    string returnstr;
  
    while( iss )
      {
	while( !isdigit(c) )
	  {
	    iss.get(c);
	  }
      
	while( isdigit(c) )
	  {
	    returnstr += c;
	    iss.get(c);
	  }

	iss >> minCheck;

	if( !isspace(c) )
	  minCheck = c + minCheck;
      
	if( minCheck.find("min") != string::npos )
	  return stoi(returnstr);
      }
    return -1; // "Kunde ej hitta min-värde!"
  }


  /* IngredientList findIngredients( const string& fieldstr )
  {
    istringstream iss {fieldstr};
    string temp, ing, unitstr;
    double amount;
    RecipeIngredient ri;
    IngredientList ingredients;

    iss >> ws;

    while( getline(iss, temp) )
      {
	unitstr = "st";
	ss2.str(""); // set content of stringstream ss2
	ss2 << temp;
	ss2 >> ws;

	if( isdigit( ss2.peek() ) )
	  ss2 >> amount >> unitstr >> ing; // WHAT IF 3 ägg?
	else
	  ss2 >> ing >> amount >> unitstr;
	
	ss2.clear(); // clear på stringstream är "clear error state/flags"
	
	if( sDB_.checkIngredient(ing) )
	  {
	    ri = sDB_.fetchIngredient(ing);
	    ri.setAmount(amount);
	    if( unitstr.find
	    ri.setUnit();
	  }
	  
      }
  }*/





  string tagStringCont(ifstream & fs)
  {
    string value{};
    getline(fs,value,'<');
    return value;
  }

  int tagIntCont(ifstream & fs)
  {
    int value{};
    char c{};
    fs >> value;
    fs.get(c);
    return value;
  }
  
  double tagDblCont(ifstream & fs)
  {
    double value{};
    char c{};
    fs >> value;
    fs.get(c);
    return value;
  }
  
  bool replaceAll(string& str, const string& from, const string& to)
  {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
      return false;
    str.replace(start_pos, from.length(), to);
    return true;
  }
}



void Shell::tagIngredient(ifstream & fs, IngredientList & IL)
{
  string tagIng{"ingredient"};
  string name{"foo"};
  string unitString{};
  double price{0};
  int kcal{0};
  double amount{0};
  Unit unit{gram};
  char trash{};

  getline(fs,name,'<');

  while (true) {
    getline(fs,tagIng,'>');
     
    if (tagIng[0] == '!' || tagIng[0] == '?') {
      fs.ignore(1000,'>');
    }       
    else if (tagIng[0] == '/') {
      cout << "/tag detected: " << tagIng;
      if (tagIng == "/ingredient") {
	RecipeIngredient omnom{name, price, kcal, amount, unit};
	if ( sDB_.checkIngredient(name) ) {
	  IL.push_back(omnom);
	}
	return;
      }
      fs.ignore(1000,'<');
      cout << ", trashing ..." << endl;
    }
    else {
      if (tagIng == "ingredient") {
	getline(fs,name,'<');
      }
      else if (tagIng == "amount") {
	fs >> amount;
	fs.get(trash);
      }
      else if (tagIng == "kcal") {
	fs >> kcal;
	fs.get(trash);
      }
      else if (tagIng == "price") {
	fs >> price;
	fs.get(trash);
      }
      else if (tagIng == "unit") {
	getline(fs,unitString,'<');
	std::transform(unitString.begin(), unitString.end(), unitString.begin(), ::tolower);
	if ( unitString == "dl" || unitString == "deciliter")
	  unit = deciliter;
	else if ( unitString == "tsk" || unitString == "tesked" || unitString == "teskedar" || unitString == "teaspoon" )
	  unit = teaspoon;
	else if ( unitString == "msk" || unitString == "matsked" || unitString == "matskedar" || unitString == "tablespoon" )
	  unit = tablespoon;
	else if ( unitString == "st" || unitString == "styck" || unitString == "stycken" ||  unitString == "pcs" )
	  unit = pcs;
	else
	  unit = gram;
      } 
    }
  }
}
