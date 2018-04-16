/********************************************************************************
** Form generated from reading UI file 'fpe.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FPE_H
#define UI_FPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_FPE
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSpinBox *spinBox;
    QSpacerItem *verticalSpacer;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_5;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *FPE)
    {
        if (FPE->objectName().isEmpty())
            FPE->setObjectName(QStringLiteral("FPE"));
        FPE->resize(943, 362);
        gridLayout = new QGridLayout(FPE);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(FPE);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(FPE);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setSingleStep(0.1);

        horizontalLayout_4->addWidget(doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(FPE);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(FPE);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(5);

        horizontalLayout_3->addWidget(doubleSpinBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(FPE);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(FPE);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(3);
        doubleSpinBox_3->setMaximum(1);
        doubleSpinBox_3->setSingleStep(0.1);

        horizontalLayout_2->addWidget(doubleSpinBox_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(FPE);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_6->addWidget(label_6);

        doubleSpinBox_6 = new QDoubleSpinBox(FPE);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));

        horizontalLayout_6->addWidget(doubleSpinBox_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_7 = new QLabel(FPE);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_7->addWidget(label_7);

        spinBox = new QSpinBox(FPE);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(999);
        spinBox->setValue(20);

        horizontalLayout_7->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);

        customPlot = new QCustomPlot(FPE);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(customPlot);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(FPE);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(FPE);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setMaximum(999.99);
        doubleSpinBox_4->setValue(500);

        horizontalLayout->addWidget(doubleSpinBox_4);

        label_5 = new QLabel(FPE);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout->addWidget(label_5);

        doubleSpinBox_5 = new QDoubleSpinBox(FPE);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setMaximum(999.99);
        doubleSpinBox_5->setValue(502);

        horizontalLayout->addWidget(doubleSpinBox_5);

        pushButton_2 = new QPushButton(FPE);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(FPE);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout_2->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(FPE);
        QObject::connect(pushButton, SIGNAL(clicked()), FPE, SLOT(close()));

        QMetaObject::connectSlotsByName(FPE);
    } // setupUi

    void retranslateUi(QDialog *FPE)
    {
        FPE->setWindowTitle(QApplication::translate("FPE", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("FPE", "Gap Length [mm]:", Q_NULLPTR));
        label_2->setText(QApplication::translate("FPE", "Refractive Index:", Q_NULLPTR));
        label_3->setText(QApplication::translate("FPE", "Reflectivity:", Q_NULLPTR));
        label_6->setText(QApplication::translate("FPE", "Angle:", Q_NULLPTR));
        label_7->setText(QApplication::translate("FPE", "Points/FSR:", Q_NULLPTR));
        label_4->setText(QApplication::translate("FPE", "Lower Wavelength [nm]:", Q_NULLPTR));
        label_5->setText(QApplication::translate("FPE", "Upper Wavelength[nm]:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("FPE", "Plot", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FPE", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FPE: public Ui_FPE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FPE_H
