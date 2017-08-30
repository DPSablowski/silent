/********************************************************************************
** Form generated from reading UI file 'vphg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VPHG_H
#define UI_VPHG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_VPHG
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_10;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBox_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_11;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_13;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_14;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_17;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QCustomPlot *customPlot;

    void setupUi(QDialog *VPHG)
    {
        if (VPHG->objectName().isEmpty())
            VPHG->setObjectName(QStringLiteral("VPHG"));
        VPHG->resize(945, 536);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        VPHG->setFont(font);
        gridLayout = new QGridLayout(VPHG);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(VPHG);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -122, 977, 627));
        horizontalLayout_15 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(doubleSpinBox->sizePolicy().hasHeightForWidth());
        doubleSpinBox->setSizePolicy(sizePolicy);
        doubleSpinBox->setMaximum(9999.99);

        horizontalLayout->addWidget(doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        sizePolicy.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy);
        doubleSpinBox_2->setMaximum(999.99);

        horizontalLayout_2->addWidget(doubleSpinBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_3->addWidget(label_7);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        sizePolicy.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy);
        doubleSpinBox_3->setMaximum(999.99);

        horizontalLayout_3->addWidget(doubleSpinBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        sizePolicy.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy);
        doubleSpinBox_4->setMaximum(999.99);

        horizontalLayout_4->addWidget(doubleSpinBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_5->addWidget(label_10);

        doubleSpinBox_5 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        sizePolicy.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy);
        doubleSpinBox_5->setMaximum(999.99);

        horizontalLayout_5->addWidget(doubleSpinBox_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        doubleSpinBox_6 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        sizePolicy.setHeightForWidth(doubleSpinBox_6->sizePolicy().hasHeightForWidth());
        doubleSpinBox_6->setSizePolicy(sizePolicy);
        doubleSpinBox_6->setDecimals(4);
        doubleSpinBox_6->setMaximum(4);

        horizontalLayout_6->addWidget(doubleSpinBox_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_7->addWidget(label_4);

        doubleSpinBox_7 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        sizePolicy.setHeightForWidth(doubleSpinBox_7->sizePolicy().hasHeightForWidth());
        doubleSpinBox_7->setSizePolicy(sizePolicy);
        doubleSpinBox_7->setDecimals(4);
        doubleSpinBox_7->setMaximum(1);

        horizontalLayout_7->addWidget(doubleSpinBox_7);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_8->addWidget(label_9);

        doubleSpinBox_8 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        sizePolicy.setHeightForWidth(doubleSpinBox_8->sizePolicy().hasHeightForWidth());
        doubleSpinBox_8->setSizePolicy(sizePolicy);
        doubleSpinBox_8->setDecimals(4);
        doubleSpinBox_8->setMaximum(1);

        horizontalLayout_8->addWidget(doubleSpinBox_8);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_9->addWidget(label_5);

        doubleSpinBox_9 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        sizePolicy.setHeightForWidth(doubleSpinBox_9->sizePolicy().hasHeightForWidth());
        doubleSpinBox_9->setSizePolicy(sizePolicy);
        doubleSpinBox_9->setDecimals(4);
        doubleSpinBox_9->setMaximum(1);

        horizontalLayout_9->addWidget(doubleSpinBox_9);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_10->addWidget(label_6);

        doubleSpinBox_10 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        sizePolicy.setHeightForWidth(doubleSpinBox_10->sizePolicy().hasHeightForWidth());
        doubleSpinBox_10->setSizePolicy(sizePolicy);
        doubleSpinBox_10->setDecimals(4);
        doubleSpinBox_10->setMaximum(1);

        horizontalLayout_10->addWidget(doubleSpinBox_10);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(checkBox);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        sizePolicy1.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy1);

        horizontalLayout_11->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_11->addWidget(checkBox_3);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_12->addWidget(label_12);

        doubleSpinBox_12 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        doubleSpinBox_12->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_12->sizePolicy().hasHeightForWidth());
        doubleSpinBox_12->setSizePolicy(sizePolicy);
        doubleSpinBox_12->setDecimals(4);

        horizontalLayout_12->addWidget(doubleSpinBox_12);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_13->addWidget(label_11);

        doubleSpinBox_11 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_11->sizePolicy().hasHeightForWidth());
        doubleSpinBox_11->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(doubleSpinBox_11);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_14->addWidget(label_13);

        doubleSpinBox_13 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        doubleSpinBox_13->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_13->sizePolicy().hasHeightForWidth());
        doubleSpinBox_13->setSizePolicy(sizePolicy);

        horizontalLayout_14->addWidget(doubleSpinBox_13);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_14 = new QLabel(scrollAreaWidgetContents);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_16->addWidget(label_14);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);

        horizontalLayout_16->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(pushButton_2);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(lineEdit);

        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_17->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        horizontalLayout_17->addWidget(checkBox_5);


        verticalLayout->addLayout(horizontalLayout_17);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton);


        horizontalLayout_15->addLayout(verticalLayout);

        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy2);
        customPlot->setMinimumSize(QSize(540, 506));

        horizontalLayout_15->addWidget(customPlot);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(VPHG);
        QObject::connect(pushButton, SIGNAL(clicked()), VPHG, SLOT(close()));

        QMetaObject::connectSlotsByName(VPHG);
    } // setupUi

    void retranslateUi(QDialog *VPHG)
    {
        VPHG->setWindowTitle(QApplication::translate("VPHG", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("VPHG", "<html><head/><body><p>Grating Line Density [l/mm]:</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("VPHG", "<html><head/><body><p>Center Wavelength [nm]:</p></body></html>", Q_NULLPTR));
        label_7->setText(QApplication::translate("VPHG", "<html><head/><body><p>Upper Wavelength [nm]:</p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("VPHG", "<html><head/><body><p>Lower Wavelength [nm]:</p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("VPHG", "<html><head/><body><p>Tune Wavelength [nm]:</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("VPHG", "Index of Refraction of DCG Layer:", Q_NULLPTR));
        label_4->setText(QApplication::translate("VPHG", "Semiamplitude of Index Modulation:", Q_NULLPTR));
        label_9->setText(QApplication::translate("VPHG", "<html><head/><body><p>Thickness of DCG Layer [mm]:</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("VPHG", "<html><head/><body><p>Upper Thickness of DCG Layer [mm]:</p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("VPHG", "<html><head/><body><p>Lower Thickness of DCG Layer [mm]:</p></body></html>", Q_NULLPTR));
        checkBox->setText(QApplication::translate("VPHG", "vs. Thickness", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("VPHG", "vs. Wavelength", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("VPHG", "Tune", Q_NULLPTR));
        label_12->setText(QApplication::translate("VPHG", "Maximum Index Modulation:", Q_NULLPTR));
        label_11->setText(QApplication::translate("VPHG", "Bragg Angle:", Q_NULLPTR));
        label_13->setText(QApplication::translate("VPHG", "Tune Bragg Angle:", Q_NULLPTR));
        label_14->setText(QApplication::translate("VPHG", "Font Size:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("VPHG", "Save As:", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("VPHG", "pdf", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("VPHG", "png", Q_NULLPTR));
        pushButton->setText(QApplication::translate("VPHG", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VPHG: public Ui_VPHG {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VPHG_H
