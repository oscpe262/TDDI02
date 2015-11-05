INCLUDEPATH += $$PWD/shell
               INCLUDEPATH += $$PWD/database
               
               #Filer som används
  HEADERS += $$PWD/SearchDB.h            
             HEADERS += $$PWD/EditDB.h
             HEADERS += $$PWD/Recipe.h
             SOURCES += $$PWD/SearchDB.cc
             SOURCES += $$PWD/EditDB.h
             SOURCES += $$PWD/Recipe.cc
             SOURCES += $$PWD/test_db.cc
  
  #Inkluderingsmappar
  
  
  #Namn på filen
  TARGET = searchtest

  #QT moduler
  QT += sql
