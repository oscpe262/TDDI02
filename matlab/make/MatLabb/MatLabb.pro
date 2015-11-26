#-------------------------------------------------
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
#SOURCES += "$$PWD/../../src/classes/Shell.cc"
SOURCES += "$$PWD/../../src/classes/SearchTerm.cc"

HEADERS  += "$$PWD/../../src/classes/headers/matlabb.h"
HEADERS  += "$$PWD/../../src/classes/headers/EditDB.h"
HEADERS  += "$$PWD/../../src/classes/headers/DB.h"
HEADERS  += "$$PWD/../../src/classes/headers/Ingredient.h"
#HEADERS  += "$$PWD/../../src/classes/headers/Shell.h"
HEADERS  += "$$PWD/../../src/classes/headers/SearchTerm.h"

FORMS    += matlabb.ui
