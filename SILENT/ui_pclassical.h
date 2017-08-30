/********************************************************************************
** Form generated from reading UI file 'pclassical.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PCLASSICAL_H
#define UI_PCLASSICAL_H

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

class Ui_PClassical
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_15;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *customPlot;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *PClassical)
    {
        if (PClassical->objectName().isEmpty())
            PClassical->setObjectName(QStringLiteral("PClassical"));
        PClassical->resize(783, 370);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        PClassical->setFont(font);
        gridLayout = new QGridLayout(PClassical);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(PClassical);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1033, 356));
        horizontalLayout_6 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(comboBox);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy1.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_7->addWidget(label_5);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox_14 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_14->setObjectName(QStringLiteral("checkBox_14"));
        sizePolicy.setHeightForWidth(checkBox_14->sizePolicy().hasHeightForWidth());
        checkBox_14->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(checkBox_14);

        checkBox_15 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_15->setObjectName(QStringLiteral("checkBox_15"));
        sizePolicy.setHeightForWidth(checkBox_15->sizePolicy().hasHeightForWidth());
        checkBox_15->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(checkBox_15);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(lineEdit);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_8->addWidget(label_6);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy1.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy1);

        horizontalLayout_8->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_8);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_6->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy2);
        customPlot->setMinimumSize(QSize(800, 300));

        verticalLayout_2->addWidget(customPlot);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        doubleSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(99);
        doubleSpinBox->setMaximum(9999);

        horizontalLayout_3->addWidget(doubleSpinBox);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_3->addWidget(label_2);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setMinimum(99);
        doubleSpinBox_2->setMaximum(9999);

        horizontalLayout_3->addWidget(doubleSpinBox_2);

        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(4);
        doubleSpinBox_3->setMinimum(0);
        doubleSpinBox_3->setMaximum(99999);
        doubleSpinBox_3->setValue(0);

        horizontalLayout_3->addWidget(doubleSpinBox_3);

        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(4);
        doubleSpinBox_4->setMaximum(99999);

        horizontalLayout_3->addWidget(doubleSpinBox_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(verticalLayout_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(PClassical);
        QObject::connect(pushButton, SIGNAL(clicked()), PClassical, SLOT(close()));

        QMetaObject::connectSlotsByName(PClassical);
    } // setupUi

    void retranslateUi(QDialog *PClassical)
    {
        PClassical->setWindowTitle(QApplication::translate("PClassical", "Dialog", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("PClassical", "find values", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("PClassical", "Plot", Q_NULLPTR));
        label_5->setText(QApplication::translate("PClassical", "Font Size:", Q_NULLPTR));
        checkBox_14->setText(QApplication::translate("PClassical", "pdf", Q_NULLPTR));
        checkBox_15->setText(QApplication::translate("PClassical", "png", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("PClassical", "Save", Q_NULLPTR));
        label_6->setText(QApplication::translate("PClassical", "Work Path:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("PClassical", "Close", Q_NULLPTR));
        label->setText(QApplication::translate("PClassical", "x1:", Q_NULLPTR));
        label_2->setText(QApplication::translate("PClassical", "x2:", Q_NULLPTR));
        label_3->setText(QApplication::translate("PClassical", "y1:", Q_NULLPTR));
        label_4->setText(QApplication::translate("PClassical", "y2:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PClassical: public Ui_PClassical {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PCLASSICAL_H
