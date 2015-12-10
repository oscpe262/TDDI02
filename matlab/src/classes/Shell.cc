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
	    str = str.substr(stringPos);
	    return header;
	  }
	  
	++stringPos;
      }
    throw Shell_Exception{ "Shell :: importTxt :: extractStep1_Header :\nInfil har ogiltigt format" };
  }


  /*string extractStep2_IngList( string& str )
  {
    
  }*/


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

}
bool fileExists( const string& name );
void readFromFile( istream& is, string& str );

bool findName( const string& fieldstr, string& returnstr );
bool findPortions( const string& fieldstr, string& returnstr );
bool findTime( const string& fieldstr, string& returnstr );


/*
 *** [local] ***
 * unit2str
 *
 * clearAnnotations
 * extractStep1_Header
 * extractStep2_IngList
 *
 * fileRename
 *
 *
 *** [SHELL] ***
 * exportTxt ( string & Recipe )
 * *importTxt
 * *exportXml
 * *importXml
 * *setScaling
 *
 *
 *** [SDB] ***
 * exactMatch
 * getRecipeResults
 * getIngredientList
 * openRecipe
 * *openIngredient
 *
 *
 *** [EDB] ***
 * addRecipe
 * removeRecipe ( Recipe & string )
 * addIngredient
 * removeIngredient ( Recipe & string )
 *
 *
 *** [extra] ***
 * fileExists
 * readFromFile
 *
 * findName
 * findPortions
 * findTime
 */


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
  string header  { extractStep1_Header(  fileContents) };
  stirng ingList { extractStep2_IngList( fileContents) };
  string tail    { extractStep3_Tail(    fileContents) };

  
  

  Recipe recipe;

  // Namn (, portioner, tid)
  istringstream iss {fileContents};
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
    }

  // header

  // ingredient list

  // description & tail


  findName(fileSection, fileLine);
  recipe.setName(fileLine);

  if( findPortions(fileSection, fileLine) )
    recipe.setPortions( stoi(fileLine) );

  if( findTime(fileSection, fileLine) )
    recipe.setTime( stoi(fileLine) );

  IngredientList ingList { findIngredients(;

  recipe.setIngredients(ingList);

  // Ingredienser
  
  // first << second << third
  // first << secondthird



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
  
  fs << "  <instruction>" << recipe.getMethod() << "</instruction>\n"
     << "  <time>" << recipe.getMinutesTime() << "</time>\n"
     << "  <price>" << recipe.getPrice() << "</price>\n"
     << "  <energy>" << recipe.getKcal() << "</energy>\n"
     << "  <rating>" << recipe.getGrade() << "</rating>\n"
     << "</recipe>" << endl;

  fs.close();
};



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
 *** [extra] ***
 **************/

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



bool findName( const string& fieldstr, string& returnstr )
{
  istringstream iss {fieldstr};
  char c;

  while( !isalpha( iss.peek() ) )
    {
      iss.get(c);
    }

  getline(iss, returnstr);
  size_t junkCheck { returnstr.find('(') };

  if( junkCheck != string::npos )
    returnstr = returnstr.substr(0, junkCheck-1);

  return true;
}



bool findPortions( const string& fieldstr, string& returnstr )
{
  istringstream iss {fieldstr};
  string portionCheck;
  char c {'n'};
  
  returnstr.clear();
  
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
	return true;
    }
  return false;
}


bool findTime( const string& fieldstr, string& returnstr )
{
  istringstream iss {fieldstr};
  string minCheck;
  char c {'n'};
  
  returnstr.clear();
  
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
	return true;
    }
  return false;

}




