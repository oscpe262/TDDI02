INCLUDEPATH += "$$PWD/../src"

#Filer som används
  HEADERS += $$PWD/../src/classes/headers/SearchDB.h            
             HEADERS += $$PWD/../src/classes/headers/EditDB.h
             HEADERS += $$PWD/../src/classes/headers/Recipe.h
             #HEADERS += $$PWD/../src/classes/headers/SearchDB.h
             #SOURCES += $$PWD/../src/classes/SearchDB.cc
             SOURCES += $$PWD/../src/classes/EditDB.cc
             SOURCES += $$PWD/../src/classes/Recipe.cc
             SOURCES += $$PWD/../src/SearchDB_test.cc
  
  
  
  #Namn på filen
  TARGET = $$PWD/../exe/searchtest

  #QT moduler
  QT += sql
