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
#include <QtWidgets/QSpinBox>
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
    QTabWidget *tabs;
    QWidget *search_view;
    QWidget *layoutWidget;
    QHBoxLayout *SearchResultLayout;
    QListWidget *listWresults;
    QListWidget *listWresultsinfo;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *OpenButton;
    QPushButton *AddButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_14;
    QVBoxLayout *IngredientLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_dbsearch;
    QPushButton *pushButton_dbsearch;
    QVBoxLayout *IngredientLayout;
    QLabel *Ingredienser;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *ingredientlist_deselected;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_select;
    QPushButton *pushButton_deselect;
    QListWidget *ingredientlist_selected;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *AllergeneLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_5;
    QListWidget *allergenes_deselected;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_allergenes_select;
    QPushButton *pushButton_allergenes_deselect;
    QListWidget *allergenes_selected;
    QVBoxLayout *DietLayouts;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_6;
    QListWidget *diet_deselected;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_diet_select;
    QPushButton *pushButton_diet_deselect;
    QListWidget *diet_selected;
    QVBoxLayout *IntervalLayout;
    QHBoxLayout *EnergyLayout;
    QLabel *energyLabel;
    QSpinBox *energyMin;
    QSpinBox *energyMax;
    QHBoxLayout *TimeLayout;
    QLabel *label_16;
    QSpinBox *timeMin;
    QSpinBox *timeMax;
    QHBoxLayout *CostLayout;
    QLabel *label_14;
    QSpinBox *costMin;
    QSpinBox *costMax;
    QPushButton *searchButton;
    QWidget *recipe_view;
    QWidget *widget;
    QVBoxLayout *RecipeViewLayout;
    QListWidget *RecipeInfo;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_8;
    QTextBrowser *RecipeIngredients;
    QTextBrowser *Method;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *commentVerticalLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *Kommentar;
    QPlainTextEdit *comment_plainTextEdit;
    QPushButton *comment;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSlider *horizontalSlider;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout_7;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QSpinBox *rating_spinBox;
    QWidget *add_recipe_view;
    QWidget *layoutWidget_2;
    QVBoxLayout *IngredientLayout_2;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_11;
    QListWidget *ingredientlist_deselected_2;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pushButton_select_2;
    QPushButton *pushButton_deselect_2;
    QListWidget *ingredientlist_selected_2;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_8;
    QWidget *add_ingredient_view;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_13;
    QHBoxLayout *name_horizontal;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QHBoxLayout *cost_horizontal;
    QLabel *label_10;
    QSpinBox *spinBox;
    QHBoxLayout *energy_horizontal;
    QLabel *label_11;
    QSpinBox *spinBox1;
    QVBoxLayout *BlackListVertical_2;
    QVBoxLayout *AllergenLayout_2;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_12;
    QListWidget *allergenes_deselected_2;
    QVBoxLayout *verticalLayout_11;
    QPushButton *pushButton_allergenes_select_2;
    QPushButton *pushButton_allergenes_deselect_2;
    QListWidget *allergenes_selected_2;
    QVBoxLayout *DietLayouts_2;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_13;
    QListWidget *diet_deselected_2;
    QVBoxLayout *verticalLayout_12;
    QPushButton *pushButton_diet_select_2;
    QPushButton *pushButton_diet_deselect_2;
    QListWidget *diet_selected_2;
    QPushButton *pushButton_5;

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
        tabs = new QTabWidget(MatLabb);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setMinimumSize(QSize(786, 0));
        tabs->setLayoutDirection(Qt::LeftToRight);
        tabs->setAutoFillBackground(false);
        tabs->setStyleSheet(QStringLiteral(""));
        tabs->setTabPosition(QTabWidget::North);
        tabs->setTabShape(QTabWidget::Rounded);
        tabs->setMovable(false);
        search_view = new QWidget();
        search_view->setObjectName(QStringLiteral("search_view"));
        layoutWidget = new QWidget(search_view);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(620, 10, 371, 521));
        SearchResultLayout = new QHBoxLayout(layoutWidget);
        SearchResultLayout->setSpacing(6);
        SearchResultLayout->setContentsMargins(11, 11, 11, 11);
        SearchResultLayout->setObjectName(QStringLiteral("SearchResultLayout"));
        SearchResultLayout->setContentsMargins(0, 0, 0, 0);
        listWresults = new QListWidget(layoutWidget);
        listWresults->setObjectName(QStringLiteral("listWresults"));

        SearchResultLayout->addWidget(listWresults);

        listWresultsinfo = new QListWidget(layoutWidget);
        listWresultsinfo->setObjectName(QStringLiteral("listWresultsinfo"));
        listWresultsinfo->setSelectionMode(QAbstractItemView::NoSelection);

        SearchResultLayout->addWidget(listWresultsinfo);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 408, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        OpenButton = new QPushButton(layoutWidget);
        OpenButton->setObjectName(QStringLiteral("OpenButton"));

        verticalLayout_3->addWidget(OpenButton);

        AddButton = new QPushButton(layoutWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        verticalLayout_3->addWidget(AddButton);


        SearchResultLayout->addLayout(verticalLayout_3);

        layoutWidget1 = new QWidget(search_view);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 10, 603, 521));
        horizontalLayout_14 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        IngredientLayout_3 = new QVBoxLayout();
        IngredientLayout_3->setSpacing(6);
        IngredientLayout_3->setObjectName(QStringLiteral("IngredientLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lineEdit_dbsearch = new QLineEdit(layoutWidget1);
        lineEdit_dbsearch->setObjectName(QStringLiteral("lineEdit_dbsearch"));

        horizontalLayout_2->addWidget(lineEdit_dbsearch);

        pushButton_dbsearch = new QPushButton(layoutWidget1);
        pushButton_dbsearch->setObjectName(QStringLiteral("pushButton_dbsearch"));

        horizontalLayout_2->addWidget(pushButton_dbsearch);


        IngredientLayout_3->addLayout(horizontalLayout_2);

        IngredientLayout = new QVBoxLayout();
        IngredientLayout->setSpacing(6);
        IngredientLayout->setObjectName(QStringLiteral("IngredientLayout"));
        Ingredienser = new QLabel(layoutWidget1);
        Ingredienser->setObjectName(QStringLiteral("Ingredienser"));

        IngredientLayout->addWidget(Ingredienser);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ingredientlist_deselected = new QListWidget(layoutWidget1);
        ingredientlist_deselected->setObjectName(QStringLiteral("ingredientlist_deselected"));
        ingredientlist_deselected->setAutoFillBackground(false);
        ingredientlist_deselected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(ingredientlist_deselected);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pushButton_select = new QPushButton(layoutWidget1);
        pushButton_select->setObjectName(QStringLiteral("pushButton_select"));

        verticalLayout->addWidget(pushButton_select);

        pushButton_deselect = new QPushButton(layoutWidget1);
        pushButton_deselect->setObjectName(QStringLiteral("pushButton_deselect"));

        verticalLayout->addWidget(pushButton_deselect);


        horizontalLayout_3->addLayout(verticalLayout);

        ingredientlist_selected = new QListWidget(layoutWidget1);
        ingredientlist_selected->setObjectName(QStringLiteral("ingredientlist_selected"));
        ingredientlist_selected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(ingredientlist_selected);

        horizontalLayout_3->setStretch(1, 1);

        IngredientLayout->addLayout(horizontalLayout_3);


        IngredientLayout_3->addLayout(IngredientLayout);


        horizontalLayout_14->addLayout(IngredientLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        AllergeneLayout = new QVBoxLayout();
        AllergeneLayout->setSpacing(6);
        AllergeneLayout->setObjectName(QStringLiteral("AllergeneLayout"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        AllergeneLayout->addWidget(label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        allergenes_deselected = new QListWidget(layoutWidget1);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        new QListWidgetItem(allergenes_deselected);
        allergenes_deselected->setObjectName(QStringLiteral("allergenes_deselected"));
        allergenes_deselected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_5->addWidget(allergenes_deselected);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_allergenes_select = new QPushButton(layoutWidget1);
        pushButton_allergenes_select->setObjectName(QStringLiteral("pushButton_allergenes_select"));

        verticalLayout_4->addWidget(pushButton_allergenes_select);

        pushButton_allergenes_deselect = new QPushButton(layoutWidget1);
        pushButton_allergenes_deselect->setObjectName(QStringLiteral("pushButton_allergenes_deselect"));

        verticalLayout_4->addWidget(pushButton_allergenes_deselect);


        horizontalLayout_5->addLayout(verticalLayout_4);

        allergenes_selected = new QListWidget(layoutWidget1);
        allergenes_selected->setObjectName(QStringLiteral("allergenes_selected"));
        allergenes_selected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_5->addWidget(allergenes_selected);


        AllergeneLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addLayout(AllergeneLayout);

        DietLayouts = new QVBoxLayout();
        DietLayouts->setSpacing(6);
        DietLayouts->setObjectName(QStringLiteral("DietLayouts"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        DietLayouts->addWidget(label_3);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        diet_deselected = new QListWidget(layoutWidget1);
        new QListWidgetItem(diet_deselected);
        new QListWidgetItem(diet_deselected);
        new QListWidgetItem(diet_deselected);
        new QListWidgetItem(diet_deselected);
        diet_deselected->setObjectName(QStringLiteral("diet_deselected"));
        diet_deselected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_6->addWidget(diet_deselected);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        pushButton_diet_select = new QPushButton(layoutWidget1);
        pushButton_diet_select->setObjectName(QStringLiteral("pushButton_diet_select"));

        verticalLayout_5->addWidget(pushButton_diet_select);

        pushButton_diet_deselect = new QPushButton(layoutWidget1);
        pushButton_diet_deselect->setObjectName(QStringLiteral("pushButton_diet_deselect"));

        verticalLayout_5->addWidget(pushButton_diet_deselect);


        horizontalLayout_6->addLayout(verticalLayout_5);

        diet_selected = new QListWidget(layoutWidget1);
        diet_selected->setObjectName(QStringLiteral("diet_selected"));
        diet_selected->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_6->addWidget(diet_selected);


        DietLayouts->addLayout(horizontalLayout_6);


        verticalLayout_2->addLayout(DietLayouts);

        IntervalLayout = new QVBoxLayout();
        IntervalLayout->setSpacing(6);
        IntervalLayout->setObjectName(QStringLiteral("IntervalLayout"));
        EnergyLayout = new QHBoxLayout();
        EnergyLayout->setSpacing(6);
        EnergyLayout->setObjectName(QStringLiteral("EnergyLayout"));
        energyLabel = new QLabel(layoutWidget1);
        energyLabel->setObjectName(QStringLiteral("energyLabel"));

        EnergyLayout->addWidget(energyLabel);

        energyMin = new QSpinBox(layoutWidget1);
        energyMin->setObjectName(QStringLiteral("energyMin"));

        EnergyLayout->addWidget(energyMin);

        energyMax = new QSpinBox(layoutWidget1);
        energyMax->setObjectName(QStringLiteral("energyMax"));
        energyMax->setMaximum(99999);

        EnergyLayout->addWidget(energyMax);


        IntervalLayout->addLayout(EnergyLayout);

        TimeLayout = new QHBoxLayout();
        TimeLayout->setSpacing(6);
        TimeLayout->setObjectName(QStringLiteral("TimeLayout"));
        label_16 = new QLabel(layoutWidget1);
        label_16->setObjectName(QStringLiteral("label_16"));

        TimeLayout->addWidget(label_16);

        timeMin = new QSpinBox(layoutWidget1);
        timeMin->setObjectName(QStringLiteral("timeMin"));

        TimeLayout->addWidget(timeMin);

        timeMax = new QSpinBox(layoutWidget1);
        timeMax->setObjectName(QStringLiteral("timeMax"));
        timeMax->setMaximum(99999);

        TimeLayout->addWidget(timeMax);


        IntervalLayout->addLayout(TimeLayout);

        CostLayout = new QHBoxLayout();
        CostLayout->setSpacing(6);
        CostLayout->setObjectName(QStringLiteral("CostLayout"));
        label_14 = new QLabel(layoutWidget1);
        label_14->setObjectName(QStringLiteral("label_14"));

        CostLayout->addWidget(label_14);

        costMin = new QSpinBox(layoutWidget1);
        costMin->setObjectName(QStringLiteral("costMin"));

        CostLayout->addWidget(costMin);

        costMax = new QSpinBox(layoutWidget1);
        costMax->setObjectName(QStringLiteral("costMax"));
        costMax->setMaximum(99999);

        CostLayout->addWidget(costMax);


        IntervalLayout->addLayout(CostLayout);

        searchButton = new QPushButton(layoutWidget1);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        IntervalLayout->addWidget(searchButton);


        verticalLayout_2->addLayout(IntervalLayout);


        horizontalLayout_14->addLayout(verticalLayout_2);

        tabs->addTab(search_view, QString());
        recipe_view = new QWidget();
        recipe_view->setObjectName(QStringLiteral("recipe_view"));
        widget = new QWidget(recipe_view);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 981, 521));
        RecipeViewLayout = new QVBoxLayout(widget);
        RecipeViewLayout->setSpacing(6);
        RecipeViewLayout->setContentsMargins(11, 11, 11, 11);
        RecipeViewLayout->setObjectName(QStringLiteral("RecipeViewLayout"));
        RecipeViewLayout->setContentsMargins(0, 0, 0, 0);
        RecipeInfo = new QListWidget(widget);
        RecipeInfo->setObjectName(QStringLiteral("RecipeInfo"));
        RecipeInfo->setMaximumSize(QSize(16777215, 60));

        RecipeViewLayout->addWidget(RecipeInfo);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        RecipeIngredients = new QTextBrowser(widget);
        RecipeIngredients->setObjectName(QStringLiteral("RecipeIngredients"));

        horizontalLayout_8->addWidget(RecipeIngredients);

        Method = new QTextBrowser(widget);
        Method->setObjectName(QStringLiteral("Method"));
        Method->setAcceptDrops(false);
        Method->setUndoRedoEnabled(false);

        horizontalLayout_8->addWidget(Method);


        horizontalLayout_10->addLayout(horizontalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        commentVerticalLayout = new QVBoxLayout();
        commentVerticalLayout->setSpacing(6);
        commentVerticalLayout->setObjectName(QStringLiteral("commentVerticalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        Kommentar = new QLabel(widget);
        Kommentar->setObjectName(QStringLiteral("Kommentar"));

        verticalLayout_6->addWidget(Kommentar);

        comment_plainTextEdit = new QPlainTextEdit(widget);
        comment_plainTextEdit->setObjectName(QStringLiteral("comment_plainTextEdit"));

        verticalLayout_6->addWidget(comment_plainTextEdit);

        comment = new QPushButton(widget);
        comment->setObjectName(QStringLiteral("comment"));

        verticalLayout_6->addWidget(comment);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);


        verticalLayout_6->addLayout(horizontalLayout_4);


        commentVerticalLayout->addLayout(verticalLayout_6);


        verticalLayout_9->addLayout(commentVerticalLayout);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(horizontalSlider);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_7->addWidget(pushButton);


        verticalLayout_8->addLayout(horizontalLayout_7);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_7->addWidget(pushButton_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_9->addWidget(label_6);

        rating_spinBox = new QSpinBox(widget);
        rating_spinBox->setObjectName(QStringLiteral("rating_spinBox"));

        horizontalLayout_9->addWidget(rating_spinBox);


        verticalLayout_7->addLayout(horizontalLayout_9);


        verticalLayout_8->addLayout(verticalLayout_7);


        verticalLayout_9->addLayout(verticalLayout_8);


        horizontalLayout_10->addLayout(verticalLayout_9);


        RecipeViewLayout->addLayout(horizontalLayout_10);

        tabs->addTab(recipe_view, QString());
        add_recipe_view = new QWidget();
        add_recipe_view->setObjectName(QStringLiteral("add_recipe_view"));
        layoutWidget_2 = new QWidget(add_recipe_view);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 10, 271, 401));
        IngredientLayout_2 = new QVBoxLayout(layoutWidget_2);
        IngredientLayout_2->setSpacing(6);
        IngredientLayout_2->setContentsMargins(11, 11, 11, 11);
        IngredientLayout_2->setObjectName(QStringLiteral("IngredientLayout_2"));
        IngredientLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        IngredientLayout_2->addWidget(label_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        ingredientlist_deselected_2 = new QListWidget(layoutWidget_2);
        ingredientlist_deselected_2->setObjectName(QStringLiteral("ingredientlist_deselected_2"));
        ingredientlist_deselected_2->setAutoFillBackground(false);
        ingredientlist_deselected_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_11->addWidget(ingredientlist_deselected_2);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(2);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        pushButton_select_2 = new QPushButton(layoutWidget_2);
        pushButton_select_2->setObjectName(QStringLiteral("pushButton_select_2"));

        verticalLayout_10->addWidget(pushButton_select_2);

        pushButton_deselect_2 = new QPushButton(layoutWidget_2);
        pushButton_deselect_2->setObjectName(QStringLiteral("pushButton_deselect_2"));

        verticalLayout_10->addWidget(pushButton_deselect_2);


        horizontalLayout_11->addLayout(verticalLayout_10);

        ingredientlist_selected_2 = new QListWidget(layoutWidget_2);
        ingredientlist_selected_2->setObjectName(QStringLiteral("ingredientlist_selected_2"));
        ingredientlist_selected_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_11->addWidget(ingredientlist_selected_2);

        horizontalLayout_11->setStretch(1, 1);

        IngredientLayout_2->addLayout(horizontalLayout_11);

        plainTextEdit_2 = new QPlainTextEdit(add_recipe_view);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(440, 160, 104, 78));
        label_8 = new QLabel(add_recipe_view);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(440, 140, 269, 17));
        tabs->addTab(add_recipe_view, QString());
        add_ingredient_view = new QWidget();
        add_ingredient_view->setObjectName(QStringLiteral("add_ingredient_view"));
        layoutWidget2 = new QWidget(add_ingredient_view);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 321, 721));
        verticalLayout_14 = new QVBoxLayout(layoutWidget2);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        name_horizontal = new QHBoxLayout();
        name_horizontal->setSpacing(6);
        name_horizontal->setObjectName(QStringLiteral("name_horizontal"));
        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        name_horizontal->addWidget(label_9);

        lineEdit = new QLineEdit(layoutWidget2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        name_horizontal->addWidget(lineEdit);


        verticalLayout_13->addLayout(name_horizontal);

        cost_horizontal = new QHBoxLayout();
        cost_horizontal->setSpacing(6);
        cost_horizontal->setObjectName(QStringLiteral("cost_horizontal"));
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));

        cost_horizontal->addWidget(label_10);

        spinBox = new QSpinBox(layoutWidget2);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        cost_horizontal->addWidget(spinBox);


        verticalLayout_13->addLayout(cost_horizontal);

        energy_horizontal = new QHBoxLayout();
        energy_horizontal->setSpacing(6);
        energy_horizontal->setObjectName(QStringLiteral("energy_horizontal"));
        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));

        energy_horizontal->addWidget(label_11);

        spinBox1 = new QSpinBox(layoutWidget2);
        spinBox1->setObjectName(QStringLiteral("spinBox1"));

        energy_horizontal->addWidget(spinBox1);


        verticalLayout_13->addLayout(energy_horizontal);


        verticalLayout_14->addLayout(verticalLayout_13);

        BlackListVertical_2 = new QVBoxLayout();
        BlackListVertical_2->setSpacing(6);
        BlackListVertical_2->setObjectName(QStringLiteral("BlackListVertical_2"));
        AllergenLayout_2 = new QVBoxLayout();
        AllergenLayout_2->setSpacing(6);
        AllergenLayout_2->setObjectName(QStringLiteral("AllergenLayout_2"));
        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QStringLiteral("label_12"));

        AllergenLayout_2->addWidget(label_12);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        allergenes_deselected_2 = new QListWidget(layoutWidget2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        new QListWidgetItem(allergenes_deselected_2);
        allergenes_deselected_2->setObjectName(QStringLiteral("allergenes_deselected_2"));
        allergenes_deselected_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_12->addWidget(allergenes_deselected_2);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        pushButton_allergenes_select_2 = new QPushButton(layoutWidget2);
        pushButton_allergenes_select_2->setObjectName(QStringLiteral("pushButton_allergenes_select_2"));

        verticalLayout_11->addWidget(pushButton_allergenes_select_2);

        pushButton_allergenes_deselect_2 = new QPushButton(layoutWidget2);
        pushButton_allergenes_deselect_2->setObjectName(QStringLiteral("pushButton_allergenes_deselect_2"));

        verticalLayout_11->addWidget(pushButton_allergenes_deselect_2);


        horizontalLayout_12->addLayout(verticalLayout_11);

        allergenes_selected_2 = new QListWidget(layoutWidget2);
        allergenes_selected_2->setObjectName(QStringLiteral("allergenes_selected_2"));
        allergenes_selected_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_12->addWidget(allergenes_selected_2);


        AllergenLayout_2->addLayout(horizontalLayout_12);


        BlackListVertical_2->addLayout(AllergenLayout_2);

        DietLayouts_2 = new QVBoxLayout();
        DietLayouts_2->setSpacing(6);
        DietLayouts_2->setObjectName(QStringLiteral("DietLayouts_2"));
        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QStringLiteral("label_13"));

        DietLayouts_2->addWidget(label_13);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        diet_deselected_2 = new QListWidget(layoutWidget2);
        new QListWidgetItem(diet_deselected_2);
        new QListWidgetItem(diet_deselected_2);
        new QListWidgetItem(diet_deselected_2);
        new QListWidgetItem(diet_deselected_2);
        diet_deselected_2->setObjectName(QStringLiteral("diet_deselected_2"));
        diet_deselected_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_13->addWidget(diet_deselected_2);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        pushButton_diet_select_2 = new QPushButton(layoutWidget2);
        pushButton_diet_select_2->setObjectName(QStringLiteral("pushButton_diet_select_2"));

        verticalLayout_12->addWidget(pushButton_diet_select_2);

        pushButton_diet_deselect_2 = new QPushButton(layoutWidget2);
        pushButton_diet_deselect_2->setObjectName(QStringLiteral("pushButton_diet_deselect_2"));

        verticalLayout_12->addWidget(pushButton_diet_deselect_2);


        horizontalLayout_13->addLayout(verticalLayout_12);

        diet_selected_2 = new QListWidget(layoutWidget2);
        diet_selected_2->setObjectName(QStringLiteral("diet_selected_2"));
        diet_selected_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_13->addWidget(diet_selected_2);


        DietLayouts_2->addLayout(horizontalLayout_13);


        BlackListVertical_2->addLayout(DietLayouts_2);


        verticalLayout_14->addLayout(BlackListVertical_2);

        pushButton_5 = new QPushButton(layoutWidget2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_14->addWidget(pushButton_5);

        tabs->addTab(add_ingredient_view, QString());

        horizontalLayout->addWidget(tabs);


        retranslateUi(MatLabb);

        tabs->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MatLabb);
    } // setupUi

    void retranslateUi(QWidget *MatLabb)
    {
        MatLabb->setWindowTitle(QApplication::translate("MatLabb", "MatLabb", 0));
        actionAyy_lmao->setText(QApplication::translate("MatLabb", "ayy lmao", 0));
        OpenButton->setText(QApplication::translate("MatLabb", "\303\226ppna", 0));
        AddButton->setText(QApplication::translate("MatLabb", "L\303\244gg till", 0));
        pushButton_dbsearch->setText(QApplication::translate("MatLabb", "Titels\303\266k", 0));
        Ingredienser->setText(QApplication::translate("MatLabb", "Ingredienser", 0));
        pushButton_select->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_deselect->setText(QApplication::translate("MatLabb", "<<", 0));
        label->setText(QApplication::translate("MatLabb", "Genetiska Tillkortakommanden", 0));

        const bool __sortingEnabled = allergenes_deselected->isSortingEnabled();
        allergenes_deselected->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = allergenes_deselected->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MatLabb", "Chilipeppar", 0));
        QListWidgetItem *___qlistwidgetitem1 = allergenes_deselected->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MatLabb", "Frukt", 0));
        QListWidgetItem *___qlistwidgetitem2 = allergenes_deselected->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MatLabb", "Gluten", 0));
        QListWidgetItem *___qlistwidgetitem3 = allergenes_deselected->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MatLabb", "Havre", 0));
        QListWidgetItem *___qlistwidgetitem4 = allergenes_deselected->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MatLabb", "Jordn\303\266tter", 0));
        QListWidgetItem *___qlistwidgetitem5 = allergenes_deselected->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MatLabb", "K\303\266tt", 0));
        QListWidgetItem *___qlistwidgetitem6 = allergenes_deselected->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("MatLabb", "Laktos", 0));
        QListWidgetItem *___qlistwidgetitem7 = allergenes_deselected->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("MatLabb", "Mj\303\266lk", 0));
        QListWidgetItem *___qlistwidgetitem8 = allergenes_deselected->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("MatLabb", "Skaldjur", 0));
        QListWidgetItem *___qlistwidgetitem9 = allergenes_deselected->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("MatLabb", "Soja", 0));
        QListWidgetItem *___qlistwidgetitem10 = allergenes_deselected->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("MatLabb", "Tr\303\244dn\303\266tter", 0));
        QListWidgetItem *___qlistwidgetitem11 = allergenes_deselected->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("MatLabb", "Vitl\303\266k", 0));
        QListWidgetItem *___qlistwidgetitem12 = allergenes_deselected->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("MatLabb", "Vete", 0));
        QListWidgetItem *___qlistwidgetitem13 = allergenes_deselected->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("MatLabb", "\303\204gg", 0));
        allergenes_deselected->setSortingEnabled(__sortingEnabled);

        pushButton_allergenes_select->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_allergenes_deselect->setText(QApplication::translate("MatLabb", "<<", 0));
        label_3->setText(QApplication::translate("MatLabb", "Kosth\303\245llning", 0));

        const bool __sortingEnabled1 = diet_deselected->isSortingEnabled();
        diet_deselected->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem14 = diet_deselected->item(0);
        ___qlistwidgetitem14->setText(QApplication::translate("MatLabb", "Halal", 0));
        QListWidgetItem *___qlistwidgetitem15 = diet_deselected->item(1);
        ___qlistwidgetitem15->setText(QApplication::translate("MatLabb", "Kosher", 0));
        QListWidgetItem *___qlistwidgetitem16 = diet_deselected->item(2);
        ___qlistwidgetitem16->setText(QApplication::translate("MatLabb", "Vegan", 0));
        QListWidgetItem *___qlistwidgetitem17 = diet_deselected->item(3);
        ___qlistwidgetitem17->setText(QApplication::translate("MatLabb", "Vegetarian", 0));
        diet_deselected->setSortingEnabled(__sortingEnabled1);

        pushButton_diet_select->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_diet_deselect->setText(QApplication::translate("MatLabb", "<<", 0));
        energyLabel->setText(QApplication::translate("MatLabb", "Energiintervall", 0));
        energyMin->setSuffix(QApplication::translate("MatLabb", " kcal", 0));
        energyMax->setSuffix(QApplication::translate("MatLabb", " kcal", 0));
        label_16->setText(QApplication::translate("MatLabb", "Tidsintervall", 0));
        timeMin->setSuffix(QApplication::translate("MatLabb", " m", 0));
        timeMax->setSuffix(QApplication::translate("MatLabb", " m", 0));
        label_14->setText(QApplication::translate("MatLabb", "Kostnadsintervall", 0));
        costMin->setSuffix(QApplication::translate("MatLabb", " kr", 0));
        costMax->setSuffix(QApplication::translate("MatLabb", " kr", 0));
        searchButton->setText(QApplication::translate("MatLabb", "S\303\266k", 0));
        tabs->setTabText(tabs->indexOf(search_view), QApplication::translate("MatLabb", "S\303\266k", 0));
        Method->setHtml(QApplication::translate("MatLabb", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Noto Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        Kommentar->setText(QApplication::translate("MatLabb", "Kommentar", 0));
        comment->setText(QApplication::translate("MatLabb", "Spara Kommentar", 0));
        pushButton_3->setText(QApplication::translate("MatLabb", "F\303\266reg\303\245ende", 0));
        pushButton_2->setText(QApplication::translate("MatLabb", "N\303\244sta", 0));
        label_5->setText(QApplication::translate("MatLabb", "Portionsfaktor", 0));
        pushButton->setText(QApplication::translate("MatLabb", "Ber\303\244kna", 0));
        pushButton_4->setText(QApplication::translate("MatLabb", "Redigera", 0));
        label_6->setText(QApplication::translate("MatLabb", "Betyg", 0));
        tabs->setTabText(tabs->indexOf(recipe_view), QApplication::translate("MatLabb", "Recept", 0));
        label_7->setText(QApplication::translate("MatLabb", "Ingredienser", 0));
        pushButton_select_2->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_deselect_2->setText(QApplication::translate("MatLabb", "<<", 0));
        label_8->setText(QApplication::translate("MatLabb", "Instruktioner", 0));
        tabs->setTabText(tabs->indexOf(add_recipe_view), QApplication::translate("MatLabb", "L\303\244gg Till Recept", 0));
        label_9->setText(QApplication::translate("MatLabb", "Namn", 0));
        label_10->setText(QApplication::translate("MatLabb", "Kostnad", 0));
        spinBox->setSuffix(QApplication::translate("MatLabb", " kr", 0));
        label_11->setText(QApplication::translate("MatLabb", "Energi", 0));
        spinBox1->setSuffix(QApplication::translate("MatLabb", " kcal", 0));
        label_12->setText(QApplication::translate("MatLabb", "Genetiska Tillkortakommanden", 0));

        const bool __sortingEnabled2 = allergenes_deselected_2->isSortingEnabled();
        allergenes_deselected_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem18 = allergenes_deselected_2->item(0);
        ___qlistwidgetitem18->setText(QApplication::translate("MatLabb", "Chilipeppar", 0));
        QListWidgetItem *___qlistwidgetitem19 = allergenes_deselected_2->item(1);
        ___qlistwidgetitem19->setText(QApplication::translate("MatLabb", "Frukt", 0));
        QListWidgetItem *___qlistwidgetitem20 = allergenes_deselected_2->item(2);
        ___qlistwidgetitem20->setText(QApplication::translate("MatLabb", "Gluten", 0));
        QListWidgetItem *___qlistwidgetitem21 = allergenes_deselected_2->item(3);
        ___qlistwidgetitem21->setText(QApplication::translate("MatLabb", "Havre", 0));
        QListWidgetItem *___qlistwidgetitem22 = allergenes_deselected_2->item(4);
        ___qlistwidgetitem22->setText(QApplication::translate("MatLabb", "Jordn\303\266tter", 0));
        QListWidgetItem *___qlistwidgetitem23 = allergenes_deselected_2->item(5);
        ___qlistwidgetitem23->setText(QApplication::translate("MatLabb", "K\303\266tt", 0));
        QListWidgetItem *___qlistwidgetitem24 = allergenes_deselected_2->item(6);
        ___qlistwidgetitem24->setText(QApplication::translate("MatLabb", "Laktos", 0));
        QListWidgetItem *___qlistwidgetitem25 = allergenes_deselected_2->item(7);
        ___qlistwidgetitem25->setText(QApplication::translate("MatLabb", "Mj\303\266lk", 0));
        QListWidgetItem *___qlistwidgetitem26 = allergenes_deselected_2->item(8);
        ___qlistwidgetitem26->setText(QApplication::translate("MatLabb", "Skaldjur", 0));
        QListWidgetItem *___qlistwidgetitem27 = allergenes_deselected_2->item(9);
        ___qlistwidgetitem27->setText(QApplication::translate("MatLabb", "Soja", 0));
        QListWidgetItem *___qlistwidgetitem28 = allergenes_deselected_2->item(10);
        ___qlistwidgetitem28->setText(QApplication::translate("MatLabb", "Tr\303\244dn\303\266tter", 0));
        QListWidgetItem *___qlistwidgetitem29 = allergenes_deselected_2->item(11);
        ___qlistwidgetitem29->setText(QApplication::translate("MatLabb", "Vitl\303\266k", 0));
        QListWidgetItem *___qlistwidgetitem30 = allergenes_deselected_2->item(12);
        ___qlistwidgetitem30->setText(QApplication::translate("MatLabb", "Vete", 0));
        QListWidgetItem *___qlistwidgetitem31 = allergenes_deselected_2->item(13);
        ___qlistwidgetitem31->setText(QApplication::translate("MatLabb", "\303\204gg", 0));
        allergenes_deselected_2->setSortingEnabled(__sortingEnabled2);

        pushButton_allergenes_select_2->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_allergenes_deselect_2->setText(QApplication::translate("MatLabb", "<<", 0));
        label_13->setText(QApplication::translate("MatLabb", "Kosth\303\245llning", 0));

        const bool __sortingEnabled3 = diet_deselected_2->isSortingEnabled();
        diet_deselected_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem32 = diet_deselected_2->item(0);
        ___qlistwidgetitem32->setText(QApplication::translate("MatLabb", "Halal", 0));
        QListWidgetItem *___qlistwidgetitem33 = diet_deselected_2->item(1);
        ___qlistwidgetitem33->setText(QApplication::translate("MatLabb", "Kosher", 0));
        QListWidgetItem *___qlistwidgetitem34 = diet_deselected_2->item(2);
        ___qlistwidgetitem34->setText(QApplication::translate("MatLabb", "Vegetarian", 0));
        QListWidgetItem *___qlistwidgetitem35 = diet_deselected_2->item(3);
        ___qlistwidgetitem35->setText(QApplication::translate("MatLabb", "Vegan", 0));
        diet_deselected_2->setSortingEnabled(__sortingEnabled3);

        pushButton_diet_select_2->setText(QApplication::translate("MatLabb", ">>", 0));
        pushButton_diet_deselect_2->setText(QApplication::translate("MatLabb", "<<", 0));
        pushButton_5->setText(QApplication::translate("MatLabb", "Spara", 0));
        tabs->setTabText(tabs->indexOf(add_ingredient_view), QApplication::translate("MatLabb", "L\303\244gg till Ingrediens", 0));
    } // retranslateUi

};

namespace Ui {
    class MatLabb: public Ui_MatLabb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MATLABB_H
