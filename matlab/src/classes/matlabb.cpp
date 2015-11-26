#include "classes/headers/matlabb.h"
#include "../build-MatLabb-Desktop-Debug/ui_matlabb.h"
#include <QVector>
#include <QString>
#include <vector>
#include <string>
#include <QList>
#include "classes/headers/Ingredient.h"
#include "classes/headers/EditDB.h"
#include "classes/headers/DB.h"
//#include "classes/headers/Shell.h"
#include "classes/headers/SearchTerm.h"
#include <algorithm>
using namespace std;


MatLabb::MatLabb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatLabb)
{
    ui->setupUi(this);
    //####################################
    //######Test för Ingredienslista######
    /*EditDB db;
    vector<Ingredient> hiv{db.fetchIngredient("Ägg"),db.fetchIngredient("Smör"),db.fetchIngredient("Vetemjöl")};
    for(int i{}; i<hiv.size(); ++i)
    {
      ui->ingredientlist_deselected->addItem(QString::fromStdString(hiv.at(i).getName()));
    };*/


    //Search_view init
    /*
    Shell sh;
    vector<string> iv = sh.getIngredientNames();
    for( auto i : iv )
        ui->ingredientlist_deselected->addItem(QString::fromStdString(iv.at(i).getName));
    */
    //Allergene lists init




    //Recipe_view init
    ui->rating_spinBox->setMinimum(1);
    ui->rating_spinBox->setMaximum(5);
    ui->costMax->setValue(5000);
    ui->timeMax->setValue(5000);
    ui->energyMax->setValue(5000);
}

MatLabb::~MatLabb()
{
    delete ui;
}




//Sökknappen
QString searchstring = "";
void MatLabb::on_pushButton_dbsearch_clicked()
{
    searchstring = ui->lineEdit_dbsearch->displayText();
    //anropa receptsökfunktionen från shell




}

//Ingredients
//
//flyttar markerade ingredienser, när man klickar på ">>" & "<<"
void MatLabb::on_pushButton_select_clicked(){
    if(!ui->ingredientlist_deselected->selectedItems().isEmpty()){
        ui->ingredientlist_selected->addItem(ui->ingredientlist_deselected->takeItem(ui->ingredientlist_deselected->currentRow()));
        ui->ingredientlist_selected->sortItems();
    }
    ui->ingredientlist_selected->clearSelection();
    ui->ingredientlist_deselected->clearSelection();
}
void MatLabb::on_pushButton_deselect_clicked(){
    if(!ui->ingredientlist_selected->selectedItems().isEmpty()){
        ui->ingredientlist_deselected->addItem(ui->ingredientlist_selected->takeItem(ui->ingredientlist_selected->currentRow()));
        ui->ingredientlist_deselected->sortItems();
    }
    ui->ingredientlist_selected->clearSelection();
    ui->ingredientlist_deselected->clearSelection();
}

//select items
void MatLabb::on_ingredientlist_deselected_itemPressed(QListWidgetItem *item){
    ui->ingredientlist_deselected->setCurrentItem(item);
}
void MatLabb::on_ingredientlist_selected_itemPressed(QListWidgetItem *item){
    ui->ingredientlist_selected->setCurrentItem(item);
}

//allergenes
//
//
void MatLabb::on_pushButton_allergenes_select_clicked(){
    if(!ui->allergenes_deselected->selectedItems().isEmpty()){
        ui->allergenes_selected->addItem(ui->allergenes_deselected->takeItem(ui->allergenes_deselected->currentRow()));
        ui->allergenes_selected->sortItems();
    }
    ui->allergenes_selected->clearSelection();
    ui->allergenes_deselected->clearSelection();
}
void MatLabb::on_pushButton_allergenes_deselect_clicked(){
    if(!ui->allergenes_selected->selectedItems().isEmpty()){
        ui->allergenes_deselected->addItem(ui->allergenes_selected->takeItem(ui->allergenes_selected->currentRow()));
        ui->allergenes_deselected->sortItems();
    }
    ui->allergenes_selected->clearSelection();
    ui->allergenes_deselected->clearSelection();
}
//select items
void MatLabb::on_allergenes_deselected_itemPressed(QListWidgetItem *item){
    ui->allergenes_deselected->setCurrentItem(item);
}
void MatLabb::on_allergenes_selected_itemPressed(QListWidgetItem *item){
    ui->allergenes_selected->setCurrentItem(item);
}

//Dietary preferences
//
//
void MatLabb::on_pushButton_diet_select_clicked(){
    if(!ui->diet_deselected->selectedItems().isEmpty()){
        ui->diet_selected->addItem(ui->diet_deselected->takeItem(ui->diet_deselected->currentRow()));
        ui->diet_selected->sortItems();
    }
    ui->diet_selected->clearSelection();
    ui->diet_deselected->clearSelection();
}
void MatLabb::on_pushButton_diet_deselect_clicked(){
    if(!ui->diet_selected->selectedItems().isEmpty()){
        ui->diet_deselected->addItem(ui->diet_selected->takeItem(ui->diet_selected->currentRow()));
        ui->diet_deselected->sortItems();
    }
    ui->diet_selected->clearSelection();
    ui->diet_deselected->clearSelection();
}
//select items
void MatLabb::on_diet_deselected_itemPressed(QListWidgetItem *item){
    ui->diet_deselected->setCurrentItem(item);
}
void MatLabb::on_diet_selected_itemPressed(QListWidgetItem *item){
    ui->diet_selected->setCurrentItem(item);
}

void MatLabb::on_rating_spinBox_valueChanged(int arg1)
{
    //skriv nytt betyg till databassen
}




/*
 *
 *  Huvudsökfunktion via SearchTermobjekt
 *
 */
void MatLabb::on_searchButton_clicked()
{

    SearchTerm st;
    AllergeneArray aa{{}};
    vector<string> vs;

    if(ui->allergenes_selected->count() != 0)
        for (int i{}; i<ui->allergenes_selected->count(); ++i)
        {
            if(ui->allergenes_selected->item(i)->text() == "Chilipeppar")
            {
                aa[hot_peppers] = true;
            }
            if(ui->allergenes_selected->item(i)->text() == "Frukt")
            {
                aa[fruit] = true;
            }
            if(ui->allergenes_selected->item(i)->text() == "Gluten")
            {
                aa[gluten] = true;
            }
            if(ui->allergenes_selected->item(i)->text() == "Havre")
            {
                aa[oats] = true;
            }
            if(ui->allergenes_selected->item(i)->text() == "Jordnötter")
            {
                aa[peanut] = true;
            }
            if(ui->allergenes_selected->item(i)->text() == "Kött")
            {
                aa[alpha_gal] = true;
            }
            if(ui->allergenes_selected->item(i)->text() == "Laktos")
            {
                aa[lactose] = true;
            }
            if(ui->allergenes_selected->item(i)->text() == "Mjölk")
            {
                aa[milk] = true;
            }
        }
    st.setAllergenes(aa);
    st.setPrice(Price(ui->costMin->value(),ui->costMax->value()));
    st.setTime(Time(ui->timeMin->value(),ui->timeMax->value()));
    st.setCal(Cal(ui->energyMin->value(),ui->energyMax->value()));
    if(!ui->ingredientlist_selected->count() != 0)
        for (int i{}; i<ui->ingredientlist_selected->count(); ++i)
        {
            vs.push_back(ui->ingredientlist_selected->item(i)->text().toStdString());
        }

    //anropa sök i shell med st

}
