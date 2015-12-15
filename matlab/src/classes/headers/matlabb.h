#ifndef MATLABB_H
#define MATLABB_H

#include <QWidget>
#include <QToolBar>
#include <QListWidgetItem>
#include <vector>
#include "classes/headers/Recipe.h"
#include "classes/headers/Shell.h"
using namespace std;



namespace Ui {
class MatLabb;
}
struct MiniRecipe_strings{
    QString name_{};
    QString info_{};
};

class MatLabb : public QWidget
{
    Q_OBJECT

public:
    explicit MatLabb(QWidget *parent = 0);
    ~MatLabb();

private slots:
    //
    void showResults(vector<MiniRecipe> vmr);
    MiniRecipe_strings MiniRecipeToQString(MiniRecipe & mr);
    void OpenRecipe(const string s);
    QString IngredientListToQString(const IngredientList il, double d);
    QString AllergeneListToQString(const AllergeneArray a);
    void OpenForEdit(Recipe r);
    //

    void on_pushButton_dbsearch_clicked();

    void on_ingredientlist_selected_activated(const QModelIndex &index);

    void on_pushButton_select_clicked();

    void on_ingredientlist_deselected_itemDoubleClicked(QListWidgetItem *item);

    void on_ingredientlist_deselected_itemClicked(QListWidgetItem *item);

    void on_pushButton_deselect_clicked();

    void on_ingredientlist_deselected_itemSelectionChanged();

    void on_ingredientlist_deselected_itemPressed(QListWidgetItem *item);

    void on_ingredientlist_selected_itemPressed(QListWidgetItem *item);

    void on_pushButton_allergenes_select_clicked();

    void on_pushButton_allergenes_deselect_clicked();

    void on_allergenes_deselected_itemPressed(QListWidgetItem *item);

    void on_allergenes_selected_itemPressed(QListWidgetItem *item);

    void on_pushButton_diet_select_clicked();

    void on_pushButton_diet_deselect_clicked();

    void on_diet_deselected_itemPressed(QListWidgetItem *item);

    void on_diet_selected_itemPressed(QListWidgetItem *item);

    void on_rating_spinBox_valueChanged(int arg1);

    void on_searchButton_clicked();

    void on_listWresults_itemPressed(QListWidgetItem *item);

    void on_OpenButton_clicked();

    void on_allergenes_deselected_2_itemPressed(QListWidgetItem *item);

    void on_allergenes_selected_2_itemPressed(QListWidgetItem *item);

    void on_diet_deselected_2_itemPressed(QListWidgetItem *item);

    void on_diet_selected_2_itemPressed(QListWidgetItem *item);

    void on_pushButton_allergenes_select_2_clicked();

    void on_pushButton_allergenes_deselect_2_clicked();

    void on_pushButton_diet_select_2_clicked();

    void on_pushButton_diet_deselect_2_clicked();

    void on_pushButton_5_clicked();

    void on_addIngredientButton_clicked();

    void on_saveRecipe_clicked();

    void on_RI_select_clicked();

    void on_ingredientlist_deselected_2_itemSelectionChanged();

    void on_ingredientlist_deselected_2_itemPressed(QListWidgetItem *item);

    void on_deleteRecipe_clicked();

    void on_removeIngredientButton_clicked();

    void on_editOpenRecipe_clicked();

    void on_RI_edit_clicked();

    void on_openIngredient_clicked();

    void on_pushButton_clicked();

    void on_RI_clear_clicked();

    void on_exportTxt_clicked();

    void on_relatedList_itemPressed(QListWidgetItem *item);

    void on_relatedOpen_clicked();

    void on_relatedButton_clicked();

    void on_relatedClear_clicked();

    void on_fileButton_clicked();

    void on_exportXml_clicked();

private:
    Ui::MatLabb *ui;
    Shell shell;
    Recipe recipe_;
    Ingredient ingredient_;
};

#endif // MATLABB_H
