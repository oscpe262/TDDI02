#-------------------------------------------------
#
# Project created by QtCreator 2015-10-19T10:20:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#Include paths
  INCLUDEPATH += "$$PWD/../../src"

TARGET = MatLabb
TEMPLATE = app


SOURCES += "$$PWD/../../src/classes/main.cpp"
SOURCES += "$$PWD/../../src/classes/matlabb.cpp"

HEADERS  += "$$PWD/../../src/classes/headers/matlabb.h"

FORMS    += matlabb.ui
