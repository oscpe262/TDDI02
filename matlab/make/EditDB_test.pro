INCLUDEPATH += "$$PWD/../src"
INCLUDEPATH += "/usr/lib/x86_64-linux-gnu/libmysqlclient.so.18"
CONFIG += c++11

  #Filer som används
  HEADERS += $$PWD/../src/classes/headers/SearchDB.h            
             HEADERS += $$PWD/../src/classes/headers/EditDB.h
             #HEADERS += $$PWD/../src/classes/headers/Recipe.h

             #HEADERS += $$PWD/../src/classes/headers/SearchDB.h
             #SOURCES += $$PWD/../src/classes/SearchDB.cc
             SOURCES += $$PWD/../src/classes/EditDB.cc
             #SOURCES += $$PWD/../src/classes/Recipe.cc
             SOURCES += $$PWD/../src/EditDB_test.cc
             
            # LIBS += $$PWD/../src/classes/headers
             
             #Namn på filen
  TARGET = $$PWD/../exe/EditDB_test
           
           #QT moduler
  QT += sql
