#include "classes/headers/matlabb.h"
#include "../build-MatLabb-Desktop-Debug/ui_matlabb.h"
#include <QVector>
#include <QString>
#include <QList>



MatLabb::MatLabb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatLabb)
{
    ui->setupUi(this);
}

MatLabb::~MatLabb()
{
    delete ui;
}



//sökknappen
QString searchstring = "";
void MatLabb::on_pushButton_dbsearch_clicked()
{
    searchstring = ui->lineEdit_dbsearch->displayText();
    //anropa receptsökfunktionen
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

//Allergens
//
//
void MatLabb::on_pushButton_allergens_select_clicked(){
    if(!ui->allergens_deselected->selectedItems().isEmpty()){
        ui->allergens_selected->addItem(ui->allergens_deselected->takeItem(ui->allergens_deselected->currentRow()));
        ui->allergens_selected->sortItems();
    }
    ui->allergens_selected->clearSelection();
    ui->allergens_deselected->clearSelection();
}
void MatLabb::on_pushButton_allergens_deselect_clicked(){
    if(!ui->allergens_selected->selectedItems().isEmpty()){
        ui->allergens_deselected->addItem(ui->allergens_selected->takeItem(ui->allergens_selected->currentRow()));
        ui->allergens_deselected->sortItems();
    }
    ui->allergens_selected->clearSelection();
    ui->allergens_deselected->clearSelection();
}
//select items
void MatLabb::on_allergens_deselected_itemPressed(QListWidgetItem *item){
    ui->allergens_deselected->setCurrentItem(item);
}
void MatLabb::on_allergens_selected_itemPressed(QListWidgetItem *item){
    ui->allergens_selected->setCurrentItem(item);
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
