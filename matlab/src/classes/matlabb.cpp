#include "classes/headers/matlabb.h"
#include "../build-MatLabb-Desktop-Debug/ui_matlabb.h"
#include <QVector>
#include <QString>
#include <vector>
#include <string>
#include <QList>
#include "classes/headers/Ingredient.h"
#include "classes/headers/RecipeIngredient.h"
#include "classes/headers/EditDB.h"
#include "classes/headers/DB.h"
#include "classes/headers/Shell.h"
#include "classes/headers/SearchTerm.h"
#include <algorithm>
using namespace std;

namespace{
    string unittostring( const Unit& unitvalue )
    {
      switch(unitvalue)
        {
        case gram:
          return "g";
        case deciliter:
          return "dl";
        case teaspoon:
          return "tsk";
        case tablespoon:
          return "msk";
        case pcs:
          return "st";
        default:
          return "null";
        }
    }
}


MiniRecipe_strings MatLabb::MiniRecipeToQString(MiniRecipe & mr)
{
    MiniRecipe_strings mrs;
    mrs.name_ = QString::fromStdString(mr.name_);
    mrs.info_ = QString::number(mr.minutesTime_) + " min " + QString::number(mr.grade_) +" pts ";

   /* QString qs = QString::fromStdString(mr.name_);
            qs += "   ";
            qs += QString::number(mr.minutesTime_);
            qs += " min   ";

            qs += QString::number(mr.grade_);
            qs += " pts   ";*/

            return mrs;
}
void MatLabb::showResults(vector<MiniRecipe> vmr)
{
    ui->listWresults->clear();
    ui->listWresultsinfo->clear();
    for (auto i : vmr)
    {
        ui->listWresults->addItem(MiniRecipeToQString(i).name_);
        ui->listWresultsinfo->addItem(MiniRecipeToQString(i).info_);

    }
}



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
    ui->costMax->setValue(99999);
    ui->timeMax->setValue(99999);
    ui->energyMax->setValue(99999);
    vector<string> ing{shell.getIngredientNames()};
    for (auto i : ing)
    {
        ui->ingredientlist_deselected->addItem(QString::fromStdString(i));
        ui->ingredientlist_deselected_2->addItem(QString::fromStdString(i));
    }

}

MatLabb::~MatLabb()
{
    delete ui;
}


/*
 * SearchView
 */
    //Titelsökknappen
QString searchstring = "";
void MatLabb::on_pushButton_dbsearch_clicked()
{
    vector<MiniRecipe> searchresults;
    searchstring = ui->lineEdit_dbsearch->displayText();
    try{
    searchresults = shell.exactMatch(searchstring.toStdString());
    }
    catch (DB_Exception e)
    {
        ui->listWresults->clear();
        ui->listWresults->addItem(QString::fromStdString(e.what()));
    }
    if (!searchresults.empty())
    showResults(searchresults);
}
    /*
     * Ingredients. flyttar markerade ingredienser, när man klickar på ">>" & "<<"
     */
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
void MatLabb::on_ingredientlist_deselected_itemPressed(QListWidgetItem *item){
    ui->ingredientlist_deselected->setCurrentItem(item);
}
void MatLabb::on_ingredientlist_selected_itemPressed(QListWidgetItem *item){
    ui->ingredientlist_selected->setCurrentItem(item);
}
    /*
     * Allergenes
     */
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
void MatLabb::on_allergenes_deselected_itemPressed(QListWidgetItem *item){
    ui->allergenes_deselected->setCurrentItem(item);
}
void MatLabb::on_allergenes_selected_itemPressed(QListWidgetItem *item){
    ui->allergenes_selected->setCurrentItem(item);
}
    /*
     * Diet
     */
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
void MatLabb::on_diet_deselected_itemPressed(QListWidgetItem *item){
    ui->diet_deselected->setCurrentItem(item);
}
void MatLabb::on_diet_selected_itemPressed(QListWidgetItem *item){
    ui->diet_selected->setCurrentItem(item);
}
    /*
     * Sökfunktion via SearchTermobjekt
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

    vector<MiniRecipe> vMR;
    try{
    vMR = shell.getRecipeResults( st );
    }
    catch (DB_Exception e)
    {
        ui->listWresults->clear();
        ui->listWresults->addItem(QString::fromStdString(e.what()));
    }
    showResults(vMR);

}
/*
 * OpenRecipe
 */
QString MatLabb::AllergeneListToQString(const AllergeneArray a)
{
    QString qs{};
    int cnt{};
    for (auto i : a)
    {
        if (i)
        {
            if(cnt == 0)
            {
                qs += "Frukt ";
            }
            if(cnt == 1)
            {
                qs += "Vitlök ";
            }
            if(cnt == 2)
            {
                qs += "Chilipeppar ";
            }
            if(cnt == 3)
            {
                qs += "Havre ";
            }
            if(cnt == 4)
            {
                qs += "Vete ";
            }
            if(cnt == 5)
            {
                qs += "Gluten ";
            }
            if(cnt == 6)
            {
                qs += "Jordnötter ";
            }
            if(cnt == 7)
            {
                qs += "Trädnötter ";
            }

            if(cnt == 8)
            {
                qs += "Skaldjur ";
            }
            if(cnt == 9)
            {
                qs += "Kött ";
            }
            if(cnt == 10)
            {
                qs += "Ägg ";
            }

            if(cnt == 11)
            {
                qs += "Mjölk ";
            }
            if(cnt == 12)
            {
                qs += "Laktos ";
            }
            if(cnt == 13)
            {
                qs += "Soja";
            }
        }
    ++cnt;
    }
}
QString MatLabb::IngredientListToQString(const IngredientList il)
{
    QString s{};
    for(auto i : il)
    {
        s +=  QString::fromStdString(i.getName()) + " " + QString::number(i.getAmount()) + " " +  QString::fromStdString(unittostring(i.getUnit())) + "\n";
    }
    return s;
}
void MatLabb::OpenRecipe(const string s)
{
Recipe r = shell.openRecipe(s);
ui->Method->clear();
ui->Method->append(QString::fromStdString(r.getMethod()));
ui->RecipeIngredients->clear();
ui->RecipeIngredients->append(IngredientListToQString(r.getIngredients()));
ui->rating_spinBox->clear();
ui->rating_spinBox->setValue((int)r.getGrade());
ui->tabs->setCurrentIndex(1);
ui->RecipeInfo->clear();
ui->RecipeInfo->addItem(QString::fromStdString(r.getName()));
ui->RecipeInfo->addItem(QString::number(r.getKcal()) + " kcal, " + QString::number(r.getPrice()) + " kr, " + QString::number(r.getMinutesTime()) +" min ");
//ui->RecipeInfo->addItem("Kan innehålla: " + MatLabb::AllergeneListToQString(r.getAllergenes()));
//ta bort kommentarstecken när peyron har gjort r.getAllergenes();

}
void MatLabb::on_listWresults_itemPressed(QListWidgetItem *item)
{
    ui->listWresults->setCurrentItem(item);
}
void MatLabb::on_OpenButton_clicked()
{
    if(!ui->listWresults->selectedItems().isEmpty()){
    OpenRecipe((ui->listWresults->currentItem()->text()).toStdString());
    }
}
/*
 * RecipeView
 */
void MatLabb::on_rating_spinBox_valueChanged(int arg1)
{
    //skriv nytt betyg till databassen
}

/*
 * AddIngredientView
 */




void MatLabb::on_allergenes_deselected_2_itemPressed(QListWidgetItem *item)
{
    ui->allergenes_deselected_2->setCurrentItem(item);
}
void MatLabb::on_allergenes_selected_2_itemPressed(QListWidgetItem *item)
{
    ui->allergenes_selected_2->setCurrentItem(item);
}
void MatLabb::on_diet_deselected_2_itemPressed(QListWidgetItem *item)
{
    ui->diet_deselected_2->setCurrentItem(item);
}
void MatLabb::on_diet_selected_2_itemPressed(QListWidgetItem *item)
{
    ui->diet_selected_2->setCurrentItem(item);
}
void MatLabb::on_pushButton_allergenes_select_2_clicked()
{
    if(!ui->allergenes_deselected_2->selectedItems().isEmpty()){
        ui->allergenes_selected_2->addItem(ui->allergenes_deselected_2->takeItem(ui->allergenes_deselected_2->currentRow()));
        ui->allergenes_selected_2->sortItems();
    }
    ui->allergenes_selected_2->clearSelection();
    ui->allergenes_deselected_2->clearSelection();
}
void MatLabb::on_pushButton_allergenes_deselect_2_clicked()
{
    if(!ui->allergenes_selected_2->selectedItems().isEmpty()){
        ui->allergenes_deselected_2->addItem(ui->allergenes_selected_2->takeItem(ui->allergenes_selected_2->currentRow()));
        ui->allergenes_deselected_2->sortItems();
    }
    ui->allergenes_selected_2->clearSelection();
    ui->allergenes_deselected_2->clearSelection();
}
void MatLabb::on_pushButton_diet_select_2_clicked()
{
    if(!ui->diet_deselected_2->selectedItems().isEmpty()){
        ui->diet_selected_2->addItem(ui->diet_deselected_2->takeItem(ui->diet_deselected_2->currentRow()));
        ui->diet_selected_2->sortItems();
    }
    ui->diet_selected_2->clearSelection();
    ui->diet_deselected_2->clearSelection();
}
void MatLabb::on_pushButton_diet_deselect_2_clicked()
{
    if(!ui->diet_selected_2->selectedItems().isEmpty()){
        ui->diet_deselected_2->addItem(ui->diet_selected_2->takeItem(ui->diet_selected_2->currentRow()));
        ui->diet_deselected_2->sortItems();
    }
    ui->diet_selected_2->clearSelection();
    ui->diet_deselected_2->clearSelection();
}
