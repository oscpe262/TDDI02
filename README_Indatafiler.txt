Syntax för att lägga till testdata i testdatafilerna, dom följer inte
kravspec men det blev hemskt mycket enklare att koda såhär.


Allt anges i strängar och heltal, unit anges i heltal enligt följande:
1 gram
2 deciliter 
3 tesked 
4 st



*****************************
*syntax Ingredient_input.txt*
*****************************
ingredient_1 price cal
ingredient_2 price cal

*********
*exempel*
*********
Ägg 5 500
Smör 50 1000
Vetemjöl 5 400

*************************
*syntax Recipe_input.txt*
*************************
Recipe_1
description of recipe in one line
Time
grade
ingredient_1 amount unit
ingredient_2 amount unit
%ENDRECIPE
Recipe_2
dscription of recipe in one line
Time
grade
ingredient_1 amount unit
ingredient_2 amount unit
%ENDLIST

*********
*exempel*
*********
Stekt ägg
Kläck ägg, stek
10
5
Ägg 1 5
%ENDRECIPE
Morotsbiffar
Riv morot, blanda med ägg och ströbröd forma till biffar stek.
40
5
Morot 2 5
Ägg 1 5
Ströbröd 1 2
%ENDLIST
