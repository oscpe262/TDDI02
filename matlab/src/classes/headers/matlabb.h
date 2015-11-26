#ifndef MATLABB_H
#define MATLABB_H

#include <QWidget>
#include <QToolBar>
#include <QListWidgetItem>


namespace Ui {
class MatLabb;
}

class MatLabb : public QWidget
{
    Q_OBJECT

public:
    explicit MatLabb(QWidget *parent = 0);
    ~MatLabb();

private slots:
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

private:
    Ui::MatLabb *ui;
};

#endif // MATLABB_H
