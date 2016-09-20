/********************************************************************************
** Form generated from reading UI file 'frame3d.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME3D_H
#define UI_FRAME3D_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
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

class Ui_Frame3D
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSpinBox *spinBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Frame3D)
    {
        if (Frame3D->objectName().isEmpty())
            Frame3D->setObjectName(QStringLiteral("Frame3D"));
        Frame3D->resize(1071, 498);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        Frame3D->setFont(font);
        gridLayout = new QGridLayout(Frame3D);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(Frame3D);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1053, 480));
        horizontalLayout_6 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(comboBox);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(lineEdit_2);

        pushButton_4 = new QPushButton(scrollAreaWidgetContents);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        sizePolicy.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);
        spinBox->setMaximum(99999);

        horizontalLayout_2->addWidget(spinBox);

        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox_2 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        sizePolicy.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy);
        spinBox_2->setMaximum(99999);

        horizontalLayout_2->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        sizePolicy.setHeightForWidth(checkBox->sizePolicy().hasHeightForWidth());
        checkBox->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(checkBox);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        sizePolicy.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        sizePolicy.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(checkBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_7->addWidget(label_3);

        spinBox_3 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        sizePolicy.setHeightForWidth(spinBox_3->sizePolicy().hasHeightForWidth());
        spinBox_3->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(spinBox_3);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(lineEdit);

        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(pushButton);


        horizontalLayout_6->addLayout(verticalLayout);

        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy1);
        customPlot->setMinimumSize(QSize(500, 300));

        horizontalLayout_6->addWidget(customPlot);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Frame3D);
        QObject::connect(pushButton, SIGNAL(clicked()), Frame3D, SLOT(close()));

        QMetaObject::connectSlotsByName(Frame3D);
    } // setupUi

    void retranslateUi(QDialog *Frame3D)
    {
        Frame3D->setWindowTitle(QApplication::translate("Frame3D", "Dialog", 0));
        pushButton_2->setText(QApplication::translate("Frame3D", "Show", 0));
        pushButton_4->setText(QApplication::translate("Frame3D", "Show", 0));
        label->setText(QApplication::translate("Frame3D", "Pixel x:", 0));
        label_2->setText(QApplication::translate("Frame3D", "Pixel y:", 0));
        checkBox->setText(QApplication::translate("Frame3D", "pdf", 0));
        checkBox_2->setText(QApplication::translate("Frame3D", "png", 0));
        checkBox_3->setText(QApplication::translate("Frame3D", "txt", 0));
        label_3->setText(QApplication::translate("Frame3D", "Font Size:", 0));
        pushButton_3->setText(QApplication::translate("Frame3D", "Save", 0));
        pushButton->setText(QApplication::translate("Frame3D", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class Frame3D: public Ui_Frame3D {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME3D_H
