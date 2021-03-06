#QT moduler
  QT += sql
  QT += core

  #Include paths
  INCLUDEPATH += "$$PWD/../../src"
  
  #Config
  CONFIG += c++11
  
  #Filer som används
  HEADERS += "$$PWD/../../src/classes/headers/SearchDB.h"          
  HEADERS += "$$PWD/../../src/classes/headers/EditDB.h"
  HEADERS += "$$PWD/../../src/classes/headers/Ingredient.h"
  HEADERS += "$$PWD/../../src/classes/headers/RecipeIngredient.h"
  HEADERS += "$$PWD/../../src/classes/headers/DB.h"
  HEADERS += "$$PWD/../../src/classes/headers/SearchDB.h"
  HEADERS += "$$PWD/../../src/classes/headers/SearchTerm.h"
  
  SOURCES += "$$PWD/../../src/classes/SearchDB.cc"
  SOURCES += "$$PWD/../../src/classes/EditDB.cc"
  SOURCES += "$$PWD/../../src/classes/Ingredient.cc"
  SOURCES += "$$PWD/../../src/classes/RecipeIngredient.cc"
  SOURCES += "$$PWD/../../src/classes/DB.cc"
  SOURCES += "$$PWD/../../src/DB_test.cc"
  SOURCES += "$$PWD/../../src/classes/SearchTerm.cc"
  # LIBS += "$$PWD/../src/classes/headers"

  #Namn på filen
  TARGET = "$$PWD/../../exe/DB_test"


