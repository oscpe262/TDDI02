/********************************************************************************
** Form generated from reading UI file 'matlabb.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MATLABB_H
#define UI_MATLABB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MatLabb
{
public:
    QAction *actionAyy_lmao;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *search_view;
    QWidget *layoutWidget;
    QHBoxLayout *SearchResultLayout;
    QListWidget *listWidget_minirecipes;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_dbsearch;
    QPushButton *pushButton_dbsearch;
    QVBoxLayout *IngredientLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *ingredientlist_deselected;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_select;
    QPushButton *pushButton_deselect;
    QListWidget *ingredientlist_selected;
    QWidget *widget1;
    QVBoxLayout *BlackListVertical;
    QVBoxLayout *AllergenLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QListWidget *allergens_deselected;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_allergens_select;
    QPushButton *pushButton_allergens_deselect;
    QListWidget *allergens_selected;
    QVBoxLayout *DietLayouts;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *diet_deselected;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_diet_select;
    QPushButton *pushButton_diet_deselect;
    QListWidget *diet_selected;
    QWidget *tab_2;
    QTextBrowser *textBrowser;
    QSlider *horizontalSlider;
    QWidget *widget2;
    QVBoxLayout *commentVerticalLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;

    void setupUi(QWidget *MatLabb)
    {
        if (MatLabb->objectName().isEmpty())
            MatLabb->setObjectName(QStringLiteral("MatLabb"));
        MatLabb->setWindowModality(Qt::NonModal);
        MatLabb->resize(1022, 796);
        actionAyy_lmao = new QAction(MatLabb);
        actionAyy_lmao->setObjectName(QStringLiteral("actionAyy_lmao"));
        actionAyy_lmao->setCheckable(true);
        horizontalLayout = new QHBoxLayout(MatLabb);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(MatLabb);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(786, 0));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setAutoFillBackground(false);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setMovable(false);
        search_view = new QWidget();
        search_view->setObjectName(QStringLiteral("search_view"));
        layoutWidget = new QWidget(search_view);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(300, 20, 461, 671));
        SearchResultLayout = new QHBoxLayout(layoutWidget);
        SearchResultLayout->setSpacing(6);
        SearchResultLayout->setContentsMargins(11, 11, 11, 11);
        SearchResultLayout->setObjectName(QStringLiteral("SearchResultLayout"));
        SearchResultLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_minirecipes = new QListWidget(layoutWidget);
        listWidget_minirecipes->setObjectName(QStringLiteral("listWidget_minirecipes"));

        SearchResultLayout->addWidget(listWidget_minirecipes);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 408, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);


        SearchResultLayout->addLayout(verticalLayout_3);

        widget = new QWidget(search_view);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(32, 23, 261, 351));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_dbsearch = new QLineEdit(widget);
        lineEdit_dbsearch->setObjectName(QStringLiteral("lineEdit_dbsearch"));

        horizontalLayout_2->addWidget(lineEdit_dbsearch);

        pushButton_dbsearch = new QPushButton(widget);
        pushButton_dbsearch->setObjectName(QStringLiteral("pushButton_dbsearch"));

        horizontalLayout_2->addWidget(pushButton_dbsearch);


        verticalLayout_2->addLayout(horizontalLayout_2);

        IngredientLayout = new QVBoxLayout();
        IngredientLayout->setSpacing(6);
        IngredientLayout->setObjectName(QStringLiteral("IngredientLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        IngredientLayout->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ingredientlist_deselected = new QListWidget(widget);
        new QListWidgetItem(ingredientlist_deselected);
        new QListWidgetItem(ingredientlist_deselected);
        new QListWidgetItem(ingredientlist_deselected);
        ingredientlist_deselected->setObjectName(QStringLiteral("ingredientlist_deselected"));
        ingredientlist_deselected->setAutoFillBackground(false);
        ingredientlist_deselected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(ingredientlist_deselected);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_select = new QPushButton(widget);
        pushButton_select->setObjectName(QStringLiteral("pushButton_select"));

        verticalLayout->addWidget(pushButton_select);

        pushButton_deselect = new QPushButton(widget);
        pushButton_deselect->setObjectName(QStringLiteral("pushButton_deselect"));

        verticalLayout->addWidget(pushButton_deselect);


        horizontalLayout_3->addLayout(verticalLayout);

        ingredientlist_selected = new QListWidget(widget);
        new QListWidgetItem(ingredientlist_selected);
        ingredientlist_selected->setObjectName(QStringLiteral("ingredientlist_selected"));
        ingredientlist_selected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(ingredientlist_selected);

        horizontalLayout_3->setStretch(1, 1);

        IngredientLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(IngredientLayout);

        widget1 = new QWidget(search_view);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(30, 380, 261, 311));
        BlackListVertical = new QVBoxLayout(widget1);
        BlackListVertical->setSpacing(6);
        BlackListVertical->setContentsMargins(11, 11, 11, 11);
        BlackListVertical->setObjectName(QStringLiteral("BlackListVertical"));
        BlackListVertical->setContentsMargins(0, 0, 0, 0);
        AllergenLayout = new QVBoxLayout();
        AllergenLayout->setSpacing(6);
        AllergenLayout->setObjectName(QStringLiteral("AllergenLayout"));
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        AllergenLayout->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        allergens_deselected = new QListWidget(widget1);
        new QListWidgetItem(allergens_deselected);
        new QListWidgetItem(allergens_deselected);
        allergens_deselected->setObjectName(QStringLiteral("allergens_deselected"));
        allergens_deselected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_5->addWidget(allergens_deselected);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_allergens_select = new QPushButton(widget1);
        pushButton_allergens_select->setObjectName(QStringLiteral("pushButton_allergens_select"));

        verticalLayout_4->addWidget(pushButton_allergens_select);

        pushButton_allergens_deselect = new QPushButton(widget1);
        pushButton_allergens_deselect->setObjectName(QStringLiteral("pushButton_allergens_deselect"));

        verticalLayout_4->addWidget(pushButton_allergens_deselect);


        horizontalLayout_5->addLayout(verticalLayout_4);

        allergens_selected = new QListWidget(widget1);
        allergens_selected->setObjectName(QStringLiteral("allergens_selected"));
        allergens_selected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_5->addWidget(allergens_selected);


        AllergenLayout->addLayout(horizontalLayout_5);


        BlackListVertical->addLayout(AllergenLayout);

        DietLayouts = new QVBoxLayout();
        DietLayouts->setSpacing(6);
        DietLayouts->setObjectName(QStringLiteral("DietLayouts"));
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        DietLayouts->addWidget(label_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        diet_deselected = new QListWidget(widget1);
        new QListWidgetItem(diet_deselected);
        new QListWidgetItem(diet_deselected);
        diet_deselected->setObjectName(QStringLiteral("diet_deselected"));
        diet_deselected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_6->addWidget(diet_deselected);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_diet_select = new QPushButton(widget1);
        pushButton_diet_select->setObjectName(QStringLiteral("pushButton_diet_select"));

        verticalLayout_5->addWidget(pushButton_diet_select);

        pushButton_diet_deselect = new QPushButton(widget1);
        pushButton_diet_deselect->setObjectName(QStringLiteral("pushButton_diet_deselect"));

        verticalLayout_5->addWidget(pushButton_diet_deselect);


        horizontalLayout_6->addLayout(verticalLayout_5);

        diet_selected = new QListWidget(widget1);
        diet_selected->setObjectName(QStringLiteral("diet_selected"));
        diet_selected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_6->addWidget(diet_selected);


        DietLayouts->addLayout(horizontalLayout_6);


        BlackListVertical->addLayout(DietLayouts);

        tabWidget->addTab(search_view, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        textBrowser = new QTextBrowser(tab_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 20, 221, 261));
        horizontalSlider = new QSlider(tab_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(520, 340, 160, 18));
        horizontalSlider->setOrientation(Qt::Horizontal);
        widget2 = new QWidget(tab_2);
        widget2->setObjectName(QStringLiteral("widget2"));
        widget2->setGeometry(QRect(600, 30, 260, 254));
        commentVerticalLayout = new QVBoxLayout(widget2);
        commentVerticalLayout->setSpacing(6);
        commentVerticalLayout->setContentsMargins(11, 11, 11, 11);
        commentVerticalLayout->setObjectName(QStringLiteral("commentVerticalLayout"));
        commentVerticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_4 = new QLabel(widget2);
        label_4->setObjectName(QStringLiteral("label_4"));

        verticalLayout_6->addWidget(label_4);

        plainTextEdit = new QPlainTextEdit(widget2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        verticalLayout_6->addWidget(plainTextEdit);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_3 = new QPushButton(widget2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_6->addLayout(horizontalLayout_4);


        commentVerticalLayout->addLayout(verticalLayout_6);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(MatLabb);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MatLabb);
    } // setupUi

    void retranslateUi(QWidget *MatLabb)
    {
        MatLabb->setWindowTitle(QApplication::translate("MatLabb", "MatLabb", 0));
        actionAyy_lmao->setText(QApplication::translate("MatLabb", "ayy lmao", 0));
        pushButton->setText(QApplication::translate("MatLabb", "L\303\244gg till", 0));
        pushButton_dbsearch->setText(QApplication::translate("MatLabb", "Titels\303\266k", 0));
        label_2->setText(QApplication::translate("MatLabb", "Ingredienser", 0));

        const bool __sortingEnabled = ingredientlist_deselected->isSortingEnabled();
        ingredientlist_deselected->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = ingredientlist_deselected->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MatLabb", "fisk", 0));
        QListWidgetItem *___qlistwidgetitem1 = ingredientlist_deselected->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MatLabb", "pang kaka", 0));
        QListWidgetItem *___qlistwidgetitem2 = ingredientlist_deselected->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MatLabb", "kyckling bullar", 0));
        ingredientlist_deselected->setSortingEnabled(__sortingEnabled);

        pushButton_select->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_deselect->setText(QApplication::translate("MatLabb", "<<", 0));

        const bool __sortingEnabled1 = ingredientlist_selected->isSortingEnabled();
        ingredientlist_selected->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem3 = ingredientlist_selected->item(0);
        ___qlistwidgetitem3->setText(QApplication::translate("MatLabb", "dank", 0));
        ingredientlist_selected->setSortingEnabled(__sortingEnabled1);

        label->setText(QApplication::translate("MatLabb", "Genetiska Tillkortakommanden", 0));

        const bool __sortingEnabled2 = allergens_deselected->isSortingEnabled();
        allergens_deselected->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem4 = allergens_deselected->item(0);
        ___qlistwidgetitem4->setText(QApplication::translate("MatLabb", "gr\303\244spollen", 0));
        QListWidgetItem *___qlistwidgetitem5 = allergens_deselected->item(1);
        ___qlistwidgetitem5->setText(QApplication::translate("MatLabb", "laktos", 0));
        allergens_deselected->setSortingEnabled(__sortingEnabled2);

        pushButton_allergens_select->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_allergens_deselect->setText(QApplication::translate("MatLabb", "<<", 0));
        label_3->setText(QApplication::translate("MatLabb", "Kosth\303\245llning", 0));

        const bool __sortingEnabled3 = diet_deselected->isSortingEnabled();
        diet_deselected->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem6 = diet_deselected->item(0);
        ___qlistwidgetitem6->setText(QApplication::translate("MatLabb", "Halal", 0));
        QListWidgetItem *___qlistwidgetitem7 = diet_deselected->item(1);
        ___qlistwidgetitem7->setText(QApplication::translate("MatLabb", "Vegan", 0));
        diet_deselected->setSortingEnabled(__sortingEnabled3);

        pushButton_diet_select->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_diet_deselect->setText(QApplication::translate("MatLabb", "<<", 0));
        tabWidget->setTabText(tabWidget->indexOf(search_view), QApplication::translate("MatLabb", "S\303\266k", 0));
        textBrowser->setHtml(QApplication::translate("MatLabb", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">You gotta do the cooking by the book!</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        label_4->setText(QApplication::translate("MatLabb", "Kommentar", 0));
        pushButton_3->setText(QApplication::translate("MatLabb", "PushButton", 0));
        pushButton_2->setText(QApplication::translate("MatLabb", "PushButton", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MatLabb", "Recept", 0));
    } // retranslateUi

};

namespace Ui {
    class MatLabb: public Ui_MatLabb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATLABB_H
