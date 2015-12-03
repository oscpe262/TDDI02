r#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T10:20:24
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Include paths
  INCLUDEPATH += "$$PWD/../../src"

  #Config
  CONFIG += c++11

TARGET = MatLabb
TEMPLATE = app


SOURCES += "$$PWD/../../src/classes/main.cpp"
SOURCES += "$$PWD/../../src/classes/matlabb.cpp"
SOURCES += "$$PWD/../../src/classes/DB.cc"
SOURCES += "$$PWD/../../src/classes/EditDB.cc"
SOURCES += "$$PWD/../../src/classes/Shell.cc"
SOURCES += "$$PWD/../../src/classes/SearchTerm.cc"
SOURCES += "$$PWD/../../src/classes/SearchDB.cc"
SOURCES += "$$PWD/../../src/classes/RecipeIngredient.cc"
SOURCES += "$$PWD/../../src/classes/Recipe.cc"
SOURCES += "$$PWD/../../src/classes/Ingredient.cc"


HEADERS  += "$$PWD/../../src/classes/headers/matlabb.h"
HEADERS  += "$$PWD/../../src/classes/headers/EditDB.h"
HEADERS  += "$$PWD/../../src/classes/headers/DB.h"
HEADERS  += "$$PWD/../../src/classes/headers/Ingredient.h"
HEADERS  += "$$PWD/../../src/classes/headers/Shell.h"
HEADERS  += "$$PWD/../../src/classes/headers/SearchTerm.h"
HEADERS  += "$$PWD/../../src/classes/headers/SearchDB.h"
HEADERS  += "$$PWD/../../src/classes/headers/RecipeIngredient.h"
HEADERS  += "$$PWD/../../src/classes/headers/Recipe.h"

FORMS    += matlabb.ui
