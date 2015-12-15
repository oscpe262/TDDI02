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
    string allergenetostring( Allergene a )
    {
      switch(a)
        {
        case fruit:
          return "Frukt";
        case garlic:
          return "Vitlök";
        case hot_peppers:
          return "Chilipeppar";
        case oats:
          return "Havre";
        case wheat:
          return "Vete";
        case gluten:
          return "Gluten";
        case peanut:
          return "Jordnötter";
        case tree_nut:
          return "Trädnötter";
        case shellfish:
          return "Skaldjur";
        case alpha_gal:
          return "Kött";
        case egg:
          return "Ägg";
        case milk:
          return "Mjölk";
        case lactose:
          return "Laktos";
        default:
          return "Soja";
        }
    }

    string diettostring( Diet d )
    {
        switch(d)
        {
        case vegetarian:
            return "Vegetarian";
        case vegan:
            return "Vegan";
        case halal:
            return "Halal";
        default:
            return "Kosher";
        }
    }

    Unit QStringtounit ( const QString & s ) //enum Unit{gram, deciliter, teaspoon, tablespoon,pcs};
    {
        if (s == "g")
            return gram;
        if (s == "dl")
            return deciliter;
        if (s == "tsk")
            return teaspoon;
        if (s == "msk")
            return tablespoon;
            return pcs;
    }

}
void MatLabb::OpenRecipe(const string s)
{
recipe_ = shell.openRecipe(s);
ui->RIngredient_amount->clear();
ui->RIngredient_unit->clear();
ui->ServSpinBox->setValue(static_cast<double>(recipe_.getPortions()));
ui->Method->clear();
ui->Method->append(QString::fromStdString(recipe_.getMethod()));
ui->RecipeIngredients->clear();
ui->RecipeIngredients->append(IngredientListToQString(recipe_.getIngredients(), 1));
ui->rating_spinBox->clear();
ui->rating_spinBox->setValue(static_cast<int>(recipe_.getGrade()));
ui->tabs->setCurrentIndex(1);
ui->RecipeInfo->clear();
ui->RecipeInfo->addItem(QString::fromStdString(recipe_.getName()));
ui->RecipeInfo->addItem(QString::number(recipe_.getKcal()) + " kcal per portion, " + QString::number(recipe_.getPrice()) + " kr per portion, " + QString::number(recipe_.getMinutesTime()) +" min tillagningstid");
ui->RecipeInfo->addItem("Kan innehålla: " + MatLabb::AllergeneListToQString(recipe_.getAllergenes()));

ui->relatedList->clear();
vector<string> rel = recipe_.related_;
cerr << "related_.size(): " << recipe_.related_.size() << " Relaterade recep: ";
for (auto i : rel)
{
    cerr << i << " ";
    ui->relatedList->addItem(QString::fromStdString(i));
}
cerr << endl;

}
void MatLabb::OpenForEdit(Recipe r)
{
    ui->relatedListEdit->clear();
    for (auto i : r.related_)
    {
        ui->relatedListEdit->addItem(QString::fromStdString(i));
    }
    ui->RIngredient_amount->clear();
    ui->RIngredient_unit->clear();
    vector<string> ing = shell.getIngredientNames();
    ui->ingredientlist_deselected_2->clear();
    ui->RI_selected->clear();
    for (auto i : ing)
    {
        ui->ingredientlist_deselected_2->addItem(QString::fromStdString(i));
    }
    ui->tabs->setCurrentIndex(2);
    ui->titleEdit->clear();
    ui->titleEdit->insert(QString::fromStdString(r.getName()));

    ui->ratingEdit->clear();
    ui->ratingEdit->setValue(static_cast<int>(r.getGrade()));

    ui->methodEdit->clear();
    ui->methodEdit->appendPlainText(QString::fromStdString(r.getMethod()));

    ui->timeEdit->clear();
    ui->timeEdit->setValue(r.getMinutesTime());

    ui->servingsEdit->clear();
    ui->servingsEdit->setValue(r.getPortions());

    for ( auto i : r.ingredients_ )
    {
        for ( int j{}; j < ui->ingredientlist_deselected_2->count(); ++j )
        {
            ui->ingredientlist_deselected_2->setCurrentRow(j);
            if ( i.getName() == ui->ingredientlist_deselected_2->currentItem()->text().toStdString())
            {
                    ui->unitBox->setCurrentIndex(ui->unitBox->findText(QString::fromStdString(unittostring(i.getUnit()))));
                    ui->amountBox->setValue(i.getAmount());
                on_RI_select_clicked();
            }
        }

    }
}
MiniRecipe_strings MatLabb::MiniRecipeToQString(MiniRecipe & mr)
{
    MiniRecipe_strings mrs;
    mrs.name_ = QString::fromStdString(mr.name_);
    mrs.info_ = QString::number(mr.minutesTime_) + " min " + QString::number(mr.grade_) +" betyg " + QString::number(mr.kcal_) + " kcal";
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
    return qs;
}
QString MatLabb::IngredientListToQString(const IngredientList il, double d)
{
    QString s{};
    for(auto i : il)
    {
        if (((d*(i.getAmount()))) < 1000 )
        s +=  QString::fromStdString(i.getName()) + " " + QString::number((d*(i.getAmount()))) + " " +  QString::fromStdString(unittostring(i.getUnit())) + "\n";
        else
        s +=  QString::fromStdString(i.getName()) + " " + QString::number((d*(i.getAmount()))/1000) + " k" +  QString::fromStdString(unittostring(i.getUnit())) + "\n";
    }
    return s;
}



MatLabb::MatLabb(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatLabb)
{
    ui->setupUi(this);
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
    if(ui->ingredientlist_selected->count() != 0)
        for (int i{}; i<ui->ingredientlist_selected->count(); ++i)
        {
            ui->ingredientlist_selected->setCurrentRow(i);
            vs.push_back(ui->ingredientlist_selected->currentItem()->text().toStdString());
        }
    st.setIngredients(vs);
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

    /*cerr << "price bounds " << st.getPrice().lower_bound << " " << st.getPrice().upper_bound << endl
            << "enrgy bounds " << st.getCal().lower_bound << " "<< st.getCal().upper_bound << endl
               << "time bounds " << st.getTime().lower_bound << " "<< st.getTime().upper_bound << endl;

    cerr << "allergenes " << endl;
    for (auto i : aa)
        cerr << i << endl;*/

}

/*OpenRecipe*/
void MatLabb::on_pushButton_clicked()
{
    double sf = (ui->ServSpinBox->value())/(recipe_.getPortions());
    ui->RecipeIngredients->clear();
    ui->RecipeIngredients->append(IngredientListToQString(recipe_.getIngredients(), sf));

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

void MatLabb::on_openIngredient_clicked()
{
    for(int i{}; i<ui->allergenes_selected_2->count(); ++i)
    {
        ui->allergenes_selected_2->setCurrentRow(i);
        on_pushButton_allergenes_deselect_2_clicked();
    }
    for(int i{}; i<ui->diet_selected_2->count(); ++i)
    {
        ui->diet_selected_2->setCurrentRow(i);
        on_pushButton_diet_deselect_2_clicked();
    }

    if(!ui->ingredientlist_deselected->selectedItems().isEmpty())
    {
        ingredient_ = shell.openIngredient(ui->ingredientlist_deselected->currentItem()->text().toStdString());
        ui->tabs->setCurrentIndex(3);
        while(ui->diet_selected_2->count()<0)
        {
            ui->diet_selected_2->setCurrentRow(0);
            on_pushButton_diet_deselect_2_clicked();
        }
        while(ui->allergenes_selected_2->count()<0)
        {
            ui->allergenes_selected_2->setCurrentRow(0);
            on_pushButton_allergenes_deselect_2_clicked();
        }
        ui->IngredientName->clear();
        ui->IngredientName->insert(QString::fromStdString(ingredient_.getName()));
        ui->costSpinBox->setValue(static_cast<int>(ingredient_.getPrice()));
        ui->energyspinbox->setValue(ingredient_.getKcal());

        AllergeneArray aa = ingredient_.getAllergenes();

        cerr << "allergenearray: ";
        for (auto i : aa)
            cerr << i << " ";
        cerr << endl;

        DietArray da = ingredient_.getDiets();
        //enum Allergene {fruit = 0, garlic = 1, hot_peppers = 2, oats = 3, wheat = 4, gluten = 5, peanut = 6, tree_nut =8, shellfish = 8, alpha_gal = 9, egg = 10, milk = 11, lactose = 12, soy =13 };
        int cnt{}; //fungerar inte förutsägbart
        for ( auto i : aa )
        {
            if (i)
            {

                for (int j{}; j<ui->allergenes_deselected_2->count(); ++j)
                {
                cerr << "Comparing " << ui->allergenes_deselected_2->item(j)->text().toStdString() << " and " << allergenetostring(Allergene(cnt)) << endl;
                if(ui->allergenes_deselected_2->item(j)->text() == QString::fromStdString(allergenetostring(Allergene(cnt))))
                    {
                        ui->allergenes_deselected_2->setCurrentRow(j);
                        on_pushButton_allergenes_select_2_clicked();
                        break;
                    }
                }
            }
            cnt++;
        }
        cnt = 0;

        cerr << "dietarray:      ";
        for (auto i : da)
            cerr << i << " ";
        cerr << endl;

        for ( auto j : da )
        {
            if (j)
            {
                for (int k{}; k<ui->diet_deselected_2->count(); ++k)
                {
                if(ui->diet_deselected_2->item(k)->text() == QString::fromStdString(diettostring(Diet(cnt))))
                    {
                        ui->diet_deselected_2->setCurrentRow(k);
                        on_pushButton_diet_select_2_clicked();
                        //cnt--;
                    }
                }
            }
            cnt++;
        }
    }
    ui->diet_selected_2->clearSelection();
    ui->diet_deselected_2->clearSelection();
}
/*
 * RecipeView
 */
void MatLabb::on_rating_spinBox_valueChanged(int arg1)
{
    recipe_.setGrade(static_cast<double>(arg1));
    shell.addRecipe(recipe_);
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
void MatLabb::on_addIngredientButton_clicked()
{
  Ingredient ing(ui->IngredientName->displayText().toStdString(), static_cast<double>(ui->costSpinBox->value()), ui->energyspinbox->value());
  if(ui->allergenes_selected_2->count() != 0)
      for (int i{}; i<ui->allergenes_selected_2->count(); ++i)
      {
          if(ui->allergenes_selected_2->item(i)->text() == "Chilipeppar")
          {
              ing.addAllergene(Unit(hot_peppers));
          }
          if(ui->allergenes_selected_2->item(i)->text() == "Frukt")
          {
              ing.addAllergene(fruit);
          }
          if(ui->allergenes_selected_2->item(i)->text() == "Gluten")
          {
              ing.addAllergene(gluten);
          }
          if(ui->allergenes_selected_2->item(i)->text() == "Havre")
          {
              ing.addAllergene(oats);
          }
          if(ui->allergenes_selected_2->item(i)->text() == "Jordnötter")
          {
              ing.addAllergene(peanut);
          }
          if(ui->allergenes_selected_2->item(i)->text() == "Kött")
          {
              ing.addAllergene(alpha_gal);
          }
          if(ui->allergenes_selected_2->item(i)->text() == "Laktos")
          {
              ing.addAllergene(lactose);
          }
          if(ui->allergenes_selected_2->item(i)->text() == "Mjölk")
          {
              ing.addAllergene(milk);
          }
      }
  if(ui->diet_selected_2->count() != 0)
      for (int i{}; i<ui->diet_selected_2->count(); ++i)
      {
          if ( ui->diet_selected_2->item(i)->text() == "Vegetarian")
              ing.addDiet(vegetarian);
          else
          if ( ui->diet_selected_2->item(i)->text() == "Vegan")
              ing.addDiet(vegan);
          else
          if ( ui->diet_selected_2->item(i)->text() == "Halal")
              ing.addDiet(halal);
          else
          if ( ui->diet_selected_2->item(i)->text() == "Kosher")
              ing.addDiet(kosher);
      }
  shell.addIngredient(ing);

}

/*
 * AddRecipeView
 */

void MatLabb::on_saveRecipe_clicked()
{
    recipe_.setMethod(ui->methodEdit->toPlainText().toStdString());
    //cerr << ui->methodEdit->toPlainText().toStdString();
    // method uppdateras inte
    // receptets kcal omberäknas inte
    // tidsåtgången är fel
    recipe_.setName(ui->titleEdit->text().toStdString());
    recipe_.setGrade(static_cast<double>(ui->ratingEdit->value()));
    recipe_.setTime(ui->timeEdit->value());
    recipe_.setPortions(ui->servingsEdit->value());
    IngredientList il{};
    RecipeIngredient ri{};
    for (int i{}; i<ui->RI_selected->count(); ++i)
    {
      ri = shell.openIngredient( ui->RI_selected->item(i)->text().toStdString() );
      cerr << ri.getPrice() << endl;
      ri.setUnit(QStringtounit(ui->RIngredient_unit->item(i)->text()));
      ri.setAmount(ui->RIngredient_amount->item(i)->text().toDouble());
      il.push_back(ri);
    }
    recipe_.setIngredients(il);

    recipe_.related_.clear();
    cerr << "Adding related: ";
    while(ui->relatedListEdit->count()>0)
    {
        cerr << ui->relatedListEdit->item(0)->text().toStdString() << " ";
        recipe_.related_.push_back(ui->relatedListEdit->item(0)->text().toStdString());
        ui->relatedListEdit->takeItem(0);
    }
cerr << endl;
    for(auto i : recipe_.related_)
    {
        ui->relatedListEdit->addItem(QString::fromStdString(i));
    }

    shell.addRecipe(recipe_);
    cerr << "related: " << recipe_.related_.size();
}
void MatLabb::on_RI_select_clicked()
{
    if(!ui->ingredientlist_deselected_2->selectedItems().isEmpty())
    {
        ui->RI_selected->addItem(ui->ingredientlist_deselected_2->takeItem(ui->ingredientlist_deselected_2->currentRow()));
        ui->RIngredient_amount->addItem(QString::number(ui->amountBox->value()));
        ui->RIngredient_unit->addItem(ui->unitBox->currentText());
    }

    ui->ingredientlist_deselected_2->clearSelection();
}
void MatLabb::on_ingredientlist_deselected_2_itemPressed(QListWidgetItem *item)
{
    ui->ingredientlist_deselected_2->setCurrentItem(item);
}
void MatLabb::on_deleteRecipe_clicked()
{
    shell.removeRecipe(ui->titleEdit->text().toStdString());
}
void MatLabb::on_removeIngredientButton_clicked()
{
    shell.removeIngredient(ui->IngredientName->text().toStdString());
}

void MatLabb::on_editOpenRecipe_clicked()
{
  OpenForEdit(recipe_);


}

void MatLabb::on_RI_edit_clicked()
{
    if (!ui->RI_selected->selectedItems().isEmpty())
    {
        ui->RIngredient_unit->setCurrentRow(ui->RI_selected->currentRow());
        ui->RIngredient_amount->setCurrentRow(ui->RI_selected->currentRow());
        ui->RIngredient_unit->currentItem()->setText(ui->unitBox->currentText());
        ui->RIngredient_amount->currentItem()->setText(QString::number(ui->amountBox->value()));
    }
}




void MatLabb::on_RI_clear_clicked()
{
    ui->ingredientlist_deselected_2->clear();
    ui->RIngredient_amount->clear();
    ui->RIngredient_unit->clear();
    ui->RI_selected->clear();
    ui->amountBox->clear();
    vector<string> ing{shell.getIngredientNames()};
    for (auto i : ing)
    {
        ui->ingredientlist_deselected_2->addItem(QString::fromStdString(i));
    }

}

void MatLabb::on_exportTxt_clicked()
{
    shell.exportTxt(recipe_.getName());
}

void MatLabb::on_relatedList_itemPressed(QListWidgetItem *item)
{
    ui->relatedList->setCurrentItem(item);
}

void MatLabb::on_relatedOpen_clicked()
{
    if(!ui->relatedList->selectedItems().isEmpty())
    {
        OpenRecipe(ui->relatedList->currentItem()->text().toStdString());
    }
}
//    if(!ui->ingredientlist_deselected->selectedItems().isEmpty()){
//ui->ingredientlist_selected->addItem(ui->ingredientlist_deselected->takeItem(ui->ingredientlist_deselected->currentRow()));
//ui->ingredientlist_selected->sortItems();
//}
//ui->ingredientlist_selected->clearSelection();
//ui->ingredientlist_deselected->clearSelection();

void MatLabb::on_relatedButton_clicked()
{
    QString s = ui->relatedLine->text();
    ui->relatedListEdit->addItem(s);
    ui->relatedLine->clear();
}

void MatLabb::on_relatedClear_clicked()
{
    ui->relatedListEdit->clear();
}

void MatLabb::on_fileButton_clicked()
{
    string qs = ui->fileLine->text().toStdString();
    if (qs.at(qs.size()-1 == 'l' || qs.at(qs.size()-1 == 'L')))
    {
        OpenForEdit(shell.importXml(qs));
    }
}

void MatLabb::on_exportXml_clicked()
{
    shell.exportXml(recipe_);
}
