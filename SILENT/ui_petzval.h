/********************************************************************************
** Form generated from reading UI file 'petzval.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PETZVAL_H
#define UI_PETZVAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Petzval
{
public:
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QLabel *label_20;
    QDoubleSpinBox *doubleSpinBox_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_10;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBox_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButton;
    QLineEdit *lineEdit_5;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_12;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit_6;
    QCheckBox *checkBox_4;
    QSpinBox *spinBox_8;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QSpinBox *spinBox_5;
    QLabel *label_12;
    QSpinBox *spinBox_4;
    QLabel *label_19;
    QSpinBox *spinBox_7;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_19;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QFrame *line;
    QHBoxLayout *horizontalLayout_16;
    QPushButton *pushButton_7;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBox_7;
    QLabel *label_15;
    QDoubleSpinBox *doubleSpinBox_8;
    QLabel *label_18;
    QSpinBox *spinBox_6;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_17;
    QComboBox *comboBox_2;
    QLabel *label_16;
    QLineEdit *lineEdit_8;
    QLabel *label_17;
    QLineEdit *lineEdit_9;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot_3;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_4;
    QCustomPlot *customPlot;
    QCustomPlot *customPlot_4;
    QVBoxLayout *verticalLayout_5;
    QCustomPlot *customPlot_5;
    QCustomPlot *customPlot_6;
    QVBoxLayout *verticalLayout_6;
    QCustomPlot *customPlot_2;
    QCustomPlot *customPlot_7;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QSpinBox *spinBox;
    QLabel *label_11;
    QSpinBox *spinBox_3;
    QLabel *label_10;
    QSpinBox *spinBox_2;
    QCheckBox *checkBox_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_6;
    QLineEdit *lineEdit_7;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *Petzval)
    {
        if (Petzval->objectName().isEmpty())
            Petzval->setObjectName(QStringLiteral("Petzval"));
        Petzval->resize(1146, 648);
        gridLayout_2 = new QGridLayout(Petzval);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(Petzval);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1189, 622));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setMaximum(999.99);

        horizontalLayout_2->addWidget(doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        sizePolicy.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy);
        doubleSpinBox_2->setMaximum(9999.99);

        horizontalLayout_3->addWidget(doubleSpinBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        sizePolicy.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(doubleSpinBox_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        sizePolicy.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(doubleSpinBox_4);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_11->addWidget(label_8);

        doubleSpinBox_9 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(doubleSpinBox_9->sizePolicy().hasHeightForWidth());
        doubleSpinBox_9->setSizePolicy(sizePolicy1);
        doubleSpinBox_9->setMaximum(999.99);
        doubleSpinBox_9->setValue(0);

        horizontalLayout_11->addWidget(doubleSpinBox_9);

        label_20 = new QLabel(scrollAreaWidgetContents);
        label_20->setObjectName(QStringLiteral("label_20"));

        horizontalLayout_11->addWidget(label_20);

        doubleSpinBox_6 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_6->sizePolicy().hasHeightForWidth());
        doubleSpinBox_6->setSizePolicy(sizePolicy1);
        doubleSpinBox_6->setMaximum(999.99);

        horizontalLayout_11->addWidget(doubleSpinBox_6);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        doubleSpinBox_10 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_10->sizePolicy().hasHeightForWidth());
        doubleSpinBox_10->setSizePolicy(sizePolicy1);
        doubleSpinBox_10->setMaximum(999.99);

        horizontalLayout_8->addWidget(doubleSpinBox_10);

        label_21 = new QLabel(scrollAreaWidgetContents);
        label_21->setObjectName(QStringLiteral("label_21"));

        horizontalLayout_8->addWidget(label_21);

        doubleSpinBox_5 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        sizePolicy1.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy1);
        doubleSpinBox_5->setMaximum(999.99);

        horizontalLayout_8->addWidget(doubleSpinBox_5);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pushButton_3);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_5 = new QPushButton(scrollAreaWidgetContents);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy1.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(pushButton_5);

        lineEdit_4 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy1.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(pushButton);

        lineEdit_5 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        sizePolicy1.setHeightForWidth(lineEdit_5->sizePolicy().hasHeightForWidth());
        lineEdit_5->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(lineEdit_5);

        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy1);

        horizontalLayout_9->addWidget(lineEdit_3);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(pushButton_4);

        lineEdit_6 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        sizePolicy1.setHeightForWidth(lineEdit_6->sizePolicy().hasHeightForWidth());
        lineEdit_6->setSizePolicy(sizePolicy1);

        horizontalLayout_12->addWidget(lineEdit_6);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        sizePolicy.setHeightForWidth(checkBox_4->sizePolicy().hasHeightForWidth());
        checkBox_4->setSizePolicy(sizePolicy);

        horizontalLayout_12->addWidget(checkBox_4);

        spinBox_8 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        sizePolicy1.setHeightForWidth(spinBox_8->sizePolicy().hasHeightForWidth());
        spinBox_8->setSizePolicy(sizePolicy1);
        spinBox_8->setMaximum(9999);

        horizontalLayout_12->addWidget(spinBox_8);


        verticalLayout->addLayout(horizontalLayout_12);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_14->addWidget(label_13);

        spinBox_5 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        sizePolicy1.setHeightForWidth(spinBox_5->sizePolicy().hasHeightForWidth());
        spinBox_5->setSizePolicy(sizePolicy1);
        spinBox_5->setMinimum(1);
        spinBox_5->setMaximum(13);
        spinBox_5->setValue(5);

        horizontalLayout_14->addWidget(spinBox_5);

        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_14->addWidget(label_12);

        spinBox_4 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        sizePolicy1.setHeightForWidth(spinBox_4->sizePolicy().hasHeightForWidth());
        spinBox_4->setSizePolicy(sizePolicy1);
        spinBox_4->setMinimum(2);
        spinBox_4->setValue(5);

        horizontalLayout_14->addWidget(spinBox_4);

        label_19 = new QLabel(scrollAreaWidgetContents);
        label_19->setObjectName(QStringLiteral("label_19"));

        horizontalLayout_14->addWidget(label_19);

        spinBox_7 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setMinimum(1);

        horizontalLayout_14->addWidget(spinBox_7);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_14);


        verticalLayout->addLayout(verticalLayout_3);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        tableWidget = new QTableWidget(scrollAreaWidgetContents);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);

        horizontalLayout_19->addWidget(tableWidget);

        tableWidget_2 = new QTableWidget(scrollAreaWidgetContents);
        if (tableWidget_2->columnCount() < 2)
            tableWidget_2->setColumnCount(2);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget_2->sizePolicy().hasHeightForWidth());
        tableWidget_2->setSizePolicy(sizePolicy3);
        tableWidget_2->setColumnCount(2);

        horizontalLayout_19->addWidget(tableWidget_2);


        verticalLayout->addLayout(horizontalLayout_19);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        pushButton_7 = new QPushButton(scrollAreaWidgetContents);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        horizontalLayout_16->addWidget(pushButton_7);

        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_16->addWidget(label_14);

        doubleSpinBox_7 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setDecimals(4);
        doubleSpinBox_7->setMaximum(9.99);
        doubleSpinBox_7->setValue(1.5);

        horizontalLayout_16->addWidget(doubleSpinBox_7);

        label_15 = new QLabel(scrollAreaWidgetContents);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_16->addWidget(label_15);

        doubleSpinBox_8 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setDecimals(4);
        doubleSpinBox_8->setMaximum(999.99);
        doubleSpinBox_8->setValue(35);

        horizontalLayout_16->addWidget(doubleSpinBox_8);

        label_18 = new QLabel(scrollAreaWidgetContents);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_16->addWidget(label_18);

        spinBox_6 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setMinimum(1);

        horizontalLayout_16->addWidget(spinBox_6);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_16->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        comboBox_2 = new QComboBox(scrollAreaWidgetContents);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        sizePolicy1.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy1);

        horizontalLayout_17->addWidget(comboBox_2);

        label_16 = new QLabel(scrollAreaWidgetContents);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_17->addWidget(label_16);

        lineEdit_8 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        sizePolicy.setHeightForWidth(lineEdit_8->sizePolicy().hasHeightForWidth());
        lineEdit_8->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(lineEdit_8);

        label_17 = new QLabel(scrollAreaWidgetContents);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_17->addWidget(label_17);

        lineEdit_9 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        sizePolicy.setHeightForWidth(lineEdit_9->sizePolicy().hasHeightForWidth());
        lineEdit_9->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(lineEdit_9);


        verticalLayout->addLayout(horizontalLayout_17);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout_6->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        customPlot_3 = new QCustomPlot(scrollAreaWidgetContents);
        customPlot_3->setObjectName(QStringLiteral("customPlot_3"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(customPlot_3->sizePolicy().hasHeightForWidth());
        customPlot_3->setSizePolicy(sizePolicy4);
        customPlot_3->setMinimumSize(QSize(0, 0));
        customPlot_3->setMaximumSize(QSize(16777215, 250));

        verticalLayout_2->addWidget(customPlot_3);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        sizePolicy4.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy4);

        verticalLayout_4->addWidget(customPlot);

        customPlot_4 = new QCustomPlot(scrollAreaWidgetContents);
        customPlot_4->setObjectName(QStringLiteral("customPlot_4"));
        sizePolicy4.setHeightForWidth(customPlot_4->sizePolicy().hasHeightForWidth());
        customPlot_4->setSizePolicy(sizePolicy4);

        verticalLayout_4->addWidget(customPlot_4);


        horizontalLayout_15->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        customPlot_5 = new QCustomPlot(scrollAreaWidgetContents);
        customPlot_5->setObjectName(QStringLiteral("customPlot_5"));
        sizePolicy4.setHeightForWidth(customPlot_5->sizePolicy().hasHeightForWidth());
        customPlot_5->setSizePolicy(sizePolicy4);

        verticalLayout_5->addWidget(customPlot_5);

        customPlot_6 = new QCustomPlot(scrollAreaWidgetContents);
        customPlot_6->setObjectName(QStringLiteral("customPlot_6"));
        sizePolicy4.setHeightForWidth(customPlot_6->sizePolicy().hasHeightForWidth());
        customPlot_6->setSizePolicy(sizePolicy4);

        verticalLayout_5->addWidget(customPlot_6);


        horizontalLayout_15->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        customPlot_2 = new QCustomPlot(scrollAreaWidgetContents);
        customPlot_2->setObjectName(QStringLiteral("customPlot_2"));
        sizePolicy4.setHeightForWidth(customPlot_2->sizePolicy().hasHeightForWidth());
        customPlot_2->setSizePolicy(sizePolicy4);

        verticalLayout_6->addWidget(customPlot_2);

        customPlot_7 = new QCustomPlot(scrollAreaWidgetContents);
        customPlot_7->setObjectName(QStringLiteral("customPlot_7"));
        sizePolicy4.setHeightForWidth(customPlot_7->sizePolicy().hasHeightForWidth());
        customPlot_7->setSizePolicy(sizePolicy4);

        verticalLayout_6->addWidget(customPlot_7);


        horizontalLayout_15->addLayout(verticalLayout_6);


        verticalLayout_2->addLayout(horizontalLayout_15);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_13->addWidget(label_9);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(9999);

        horizontalLayout_13->addWidget(spinBox);

        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_13->addWidget(label_11);

        spinBox_3 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setValue(12);

        horizontalLayout_13->addWidget(spinBox_3);

        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_13->addWidget(label_10);

        spinBox_2 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setValue(4);

        horizontalLayout_13->addWidget(spinBox_2);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_13->addWidget(checkBox_3);

        pushButton_8 = new QPushButton(scrollAreaWidgetContents);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        sizePolicy1.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(pushButton_8);

        pushButton_6 = new QPushButton(scrollAreaWidgetContents);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_13->addWidget(pushButton_6);

        lineEdit_7 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        sizePolicy1.setHeightForWidth(lineEdit_7->sizePolicy().hasHeightForWidth());
        lineEdit_7->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(lineEdit_7);

        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_13->addWidget(checkBox);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_13->addWidget(checkBox_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_13);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Petzval);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Petzval, SLOT(close()));

        QMetaObject::connectSlotsByName(Petzval);
    } // setupUi

    void retranslateUi(QDialog *Petzval)
    {
        Petzval->setWindowTitle(QApplication::translate("Petzval", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Petzval", "Diameter [mm]:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Petzval", "Focal Length [mm]:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Petzval", "Allowed Focal Length Tolerance [mm]:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Petzval", "Minimum Backfocus[mm]:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Petzval", "Front Lens larger than:", Q_NULLPTR));
        label_20->setText(QApplication::translate("Petzval", "and smaller", Q_NULLPTR));
        label_6->setText(QApplication::translate("Petzval", "Second Lens larger than:", Q_NULLPTR));
        label_21->setText(QApplication::translate("Petzval", "and smaller", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Petzval", "Load Lens Catalog", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Petzval", "Load Glass Catalog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Petzval", "Search", Q_NULLPTR));
        label_7->setText(QApplication::translate("Petzval", ".pet; # Combs:", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Petzval", "Evaluate", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("Petzval", "all", Q_NULLPTR));
        label_13->setText(QApplication::translate("Petzval", "# Wavelengths:", Q_NULLPTR));
        label_12->setText(QApplication::translate("Petzval", "# Rays", Q_NULLPTR));
        label_19->setText(QApplication::translate("Petzval", "# Fields:", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Petzval", "Find Glass", Q_NULLPTR));
        label_14->setText(QApplication::translate("Petzval", "Nd:", Q_NULLPTR));
        label_15->setText(QApplication::translate("Petzval", "Vd:", Q_NULLPTR));
        label_18->setText(QApplication::translate("Petzval", ", list", Q_NULLPTR));
        label_16->setText(QApplication::translate("Petzval", "% dev Nd:", Q_NULLPTR));
        label_17->setText(QApplication::translate("Petzval", "% dev Vd:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Petzval", "Work Path:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Petzval", "Close", Q_NULLPTR));
        label_9->setText(QApplication::translate("Petzval", "Box:", Q_NULLPTR));
        label_11->setText(QApplication::translate("Petzval", "Font", Q_NULLPTR));
        label_10->setText(QApplication::translate("Petzval", "Symbol:", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("Petzval", "Center", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Petzval", "Replot", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Petzval", "Save Spots", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Petzval", "pdf", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Petzval", "png", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Petzval: public Ui_Petzval {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PETZVAL_H
