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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Petzval
{
public:
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
    QDoubleSpinBox *doubleSpinBox_6;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
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
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Petzval)
    {
        if (Petzval->objectName().isEmpty())
            Petzval->setObjectName(QStringLiteral("Petzval"));
        Petzval->resize(994, 395);
        gridLayout = new QGridLayout(Petzval);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(Petzval);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(Petzval);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(999.99);

        horizontalLayout_2->addWidget(doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(Petzval);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(Petzval);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMaximum(9999.99);

        horizontalLayout_3->addWidget(doubleSpinBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(Petzval);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(Petzval);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));

        horizontalLayout_4->addWidget(doubleSpinBox_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(Petzval);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        doubleSpinBox_4 = new QDoubleSpinBox(Petzval);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));

        horizontalLayout_7->addWidget(doubleSpinBox_4);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_8 = new QLabel(Petzval);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_11->addWidget(label_8);

        doubleSpinBox_6 = new QDoubleSpinBox(Petzval);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setMaximum(999.99);

        horizontalLayout_11->addWidget(doubleSpinBox_6);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(Petzval);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        doubleSpinBox_5 = new QDoubleSpinBox(Petzval);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setMaximum(999.99);

        horizontalLayout_8->addWidget(doubleSpinBox_5);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_3 = new QPushButton(Petzval);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(pushButton_3);

        lineEdit = new QLineEdit(Petzval);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit);

        comboBox = new QComboBox(Petzval);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_5->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        pushButton_5 = new QPushButton(Petzval);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        sizePolicy.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(pushButton_5);

        lineEdit_4 = new QLineEdit(Petzval);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        sizePolicy.setHeightForWidth(lineEdit_4->sizePolicy().hasHeightForWidth());
        lineEdit_4->setSizePolicy(sizePolicy);

        horizontalLayout_10->addWidget(lineEdit_4);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButton = new QPushButton(Petzval);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(pushButton);

        label_7 = new QLabel(Petzval);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_9->addWidget(label_7);

        lineEdit_3 = new QLineEdit(Petzval);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_9->addWidget(lineEdit_3);

        pushButton_4 = new QPushButton(Petzval);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_9->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_4 = new QLabel(Petzval);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_6->addWidget(label_4);

        lineEdit_2 = new QLineEdit(Petzval);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_2 = new QPushButton(Petzval);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        customPlot = new QCustomPlot(Petzval);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(customPlot, 0, 1, 1, 1);


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
        label_8->setText(QApplication::translate("Petzval", "Front Lens smaller than:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Petzval", "Second Lens smaller than [mm]:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Petzval", "Load Lens Catalog", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Petzval", "Load Glass Catalog", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Petzval", "Search", Q_NULLPTR));
        label_7->setText(QApplication::translate("Petzval", "# Combinations:", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Petzval", "Evaluate", Q_NULLPTR));
        label_4->setText(QApplication::translate("Petzval", "Work Path:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Petzval", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Petzval: public Ui_Petzval {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PETZVAL_H
