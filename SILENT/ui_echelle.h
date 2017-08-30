/********************************************************************************
** Form generated from reading UI file 'echelle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ECHELLE_H
#define UI_ECHELLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_Echelle
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_17;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_5;
    QSpinBox *spinBox;
    QLabel *label_6;
    QSpinBox *spinBox_2;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *Echelle)
    {
        if (Echelle->objectName().isEmpty())
            Echelle->setObjectName(QStringLiteral("Echelle"));
        Echelle->resize(1193, 520);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        Echelle->setFont(font);
        gridLayout = new QGridLayout(Echelle);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(Echelle);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1305, 477));
        horizontalLayout_5 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        checkBox_16 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_16->setObjectName(QStringLiteral("checkBox_16"));

        horizontalLayout_2->addWidget(checkBox_16);

        checkBox_17 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_17->setObjectName(QStringLiteral("checkBox_17"));

        horizontalLayout_2->addWidget(checkBox_17);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinBox_3 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        sizePolicy.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy);

        horizontalLayout_6->addWidget(spinBox_3);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(lineEdit);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_7);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout_5->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy2);
        customPlot->setMinimumSize(QSize(0, 300));

        verticalLayout_2->addWidget(customPlot);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(99);
        doubleSpinBox->setMaximum(999);
        doubleSpinBox->setValue(400);

        horizontalLayout_4->addWidget(doubleSpinBox);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_4->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMinimum(99);
        doubleSpinBox_2->setMaximum(999);
        doubleSpinBox_2->setValue(700);

        horizontalLayout_4->addWidget(doubleSpinBox_2);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMaximum(999999);

        horizontalLayout_4->addWidget(doubleSpinBox_3);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMaximum(999999);

        horizontalLayout_4->addWidget(doubleSpinBox_4);

        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_4->addWidget(label_5);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(99999);

        horizontalLayout_4->addWidget(spinBox);

        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_4->addWidget(label_6);

        spinBox_2 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMaximum(99999);

        horizontalLayout_4->addWidget(spinBox_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);


        verticalLayout_2->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Echelle);

        QMetaObject::connectSlotsByName(Echelle);
    } // setupUi

    void retranslateUi(QDialog *Echelle)
    {
        Echelle->setWindowTitle(QApplication::translate("Echelle", "Dialog", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Echelle", "find values", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Echelle", "Plot", Q_NULLPTR));
        checkBox_16->setText(QApplication::translate("Echelle", "pdf", Q_NULLPTR));
        checkBox_17->setText(QApplication::translate("Echelle", "png", Q_NULLPTR));
        label_7->setText(QApplication::translate("Echelle", "Font Size:", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Echelle", "Save", Q_NULLPTR));
        label_8->setText(QApplication::translate("Echelle", "Work Path:", Q_NULLPTR));
        label->setText(QApplication::translate("Echelle", "x1:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Echelle", "x2:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Echelle", "y1:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Echelle", "y2:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Echelle", "Pixel x:", Q_NULLPTR));
        label_6->setText(QApplication::translate("Echelle", "Pixel y:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Echelle: public Ui_Echelle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ECHELLE_H
