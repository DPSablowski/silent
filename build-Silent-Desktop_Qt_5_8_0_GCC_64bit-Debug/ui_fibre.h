/********************************************************************************
** Form generated from reading UI file 'fibre.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIBRE_H
#define UI_FIBRE_H

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

class Ui_Fibre
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QDoubleSpinBox *doubleSpinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *doubleSpinBox_3;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QDoubleSpinBox *doubleSpinBox_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBox_9;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_12;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_8;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_5;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_7;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_13;
    QSpinBox *spinBox_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_18;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCustomPlot *customPlot;

    void setupUi(QDialog *Fibre)
    {
        if (Fibre->objectName().isEmpty())
            Fibre->setObjectName(QStringLiteral("Fibre"));
        Fibre->resize(1048, 692);
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Mono"));
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
        Fibre->setFont(font);
        gridLayout = new QGridLayout(Fibre);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        scrollArea = new QScrollArea(Fibre);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1030, 674));
        horizontalLayout_16 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
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
        doubleSpinBox->setDecimals(4);
        doubleSpinBox->setMaximum(9.99);
        doubleSpinBox->setSingleStep(0.005);

        horizontalLayout->addWidget(doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        doubleSpinBox_2 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        sizePolicy.setHeightForWidth(doubleSpinBox_2->sizePolicy().hasHeightForWidth());
        doubleSpinBox_2->setSizePolicy(sizePolicy);
        doubleSpinBox_2->setDecimals(4);
        doubleSpinBox_2->setMaximum(9.99);
        doubleSpinBox_2->setSingleStep(0.005);

        horizontalLayout_2->addWidget(doubleSpinBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        doubleSpinBox_3 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_3->sizePolicy().hasHeightForWidth());
        doubleSpinBox_3->setSizePolicy(sizePolicy);
        doubleSpinBox_3->setDecimals(3);
        doubleSpinBox_3->setMaximum(9.99);
        doubleSpinBox_3->setSingleStep(0.01);

        horizontalLayout_3->addWidget(doubleSpinBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QStringLiteral("label_10"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        horizontalLayout_13->addWidget(label_10);

        lineEdit_2 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setEnabled(false);
        sizePolicy.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy);
        lineEdit_2->setMinimumSize(QSize(50, 0));
        lineEdit_2->setMaximumSize(QSize(60, 30));

        horizontalLayout_13->addWidget(lineEdit_2);

        comboBox = new QComboBox(scrollAreaWidgetContents);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        sizePolicy.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy);

        horizontalLayout_13->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_13);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        doubleSpinBox_4 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        sizePolicy.setHeightForWidth(doubleSpinBox_4->sizePolicy().hasHeightForWidth());
        doubleSpinBox_4->setSizePolicy(sizePolicy);
        doubleSpinBox_4->setMaximum(999.99);

        horizontalLayout_4->addWidget(doubleSpinBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_5->addWidget(label_8);

        doubleSpinBox_5 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        sizePolicy.setHeightForWidth(doubleSpinBox_5->sizePolicy().hasHeightForWidth());
        doubleSpinBox_5->setSizePolicy(sizePolicy);
        doubleSpinBox_5->setDecimals(5);
        doubleSpinBox_5->setMaximum(9.99);

        horizontalLayout_5->addWidget(doubleSpinBox_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_6->addWidget(label_2);

        doubleSpinBox_6 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        sizePolicy.setHeightForWidth(doubleSpinBox_6->sizePolicy().hasHeightForWidth());
        doubleSpinBox_6->setSizePolicy(sizePolicy);
        doubleSpinBox_6->setMaximum(1e+6);

        horizontalLayout_6->addWidget(doubleSpinBox_6);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_7->addWidget(label_6);

        doubleSpinBox_7 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        sizePolicy.setHeightForWidth(doubleSpinBox_7->sizePolicy().hasHeightForWidth());
        doubleSpinBox_7->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(doubleSpinBox_7);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_8->addWidget(label_7);

        lineEdit = new QLineEdit(scrollAreaWidgetContents);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_8->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_14->addWidget(label_11);

        doubleSpinBox_9 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        sizePolicy.setHeightForWidth(doubleSpinBox_9->sizePolicy().hasHeightForWidth());
        doubleSpinBox_9->setSizePolicy(sizePolicy);
        doubleSpinBox_9->setDecimals(5);
        doubleSpinBox_9->setSingleStep(0.001);

        horizontalLayout_14->addWidget(doubleSpinBox_9);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_15->addWidget(label_12);

        spinBox = new QSpinBox(scrollAreaWidgetContents);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        sizePolicy.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy);

        horizontalLayout_15->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_15);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_10->addWidget(label_9);

        doubleSpinBox_8 = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setEnabled(false);
        sizePolicy.setHeightForWidth(doubleSpinBox_8->sizePolicy().hasHeightForWidth());
        doubleSpinBox_8->setSizePolicy(sizePolicy);
        doubleSpinBox_8->setMaximum(9999.99);

        horizontalLayout_10->addWidget(doubleSpinBox_8);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        checkBox = new QCheckBox(scrollAreaWidgetContents);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_9->addWidget(checkBox);

        checkBox_2 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        horizontalLayout_9->addWidget(checkBox_2);

        checkBox_3 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));

        horizontalLayout_9->addWidget(checkBox_3);

        checkBox_5 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));

        horizontalLayout_9->addWidget(checkBox_5);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        checkBox_4 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));

        horizontalLayout_12->addWidget(checkBox_4);

        checkBox_6 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));

        horizontalLayout_12->addWidget(checkBox_6);

        checkBox_10 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_10->setObjectName(QStringLiteral("checkBox_10"));

        horizontalLayout_12->addWidget(checkBox_10);

        checkBox_7 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_7->setObjectName(QStringLiteral("checkBox_7"));

        horizontalLayout_12->addWidget(checkBox_7);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_17->addWidget(label_13);

        spinBox_2 = new QSpinBox(scrollAreaWidgetContents);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        sizePolicy.setHeightForWidth(spinBox_2->sizePolicy().hasHeightForWidth());
        spinBox_2->setSizePolicy(sizePolicy);

        horizontalLayout_17->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_17);

        verticalSpacer = new QSpacerItem(287, 13, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        pushButton_3 = new QPushButton(scrollAreaWidgetContents);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout_18->addWidget(pushButton_3);

        lineEdit_3 = new QLineEdit(scrollAreaWidgetContents);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        sizePolicy.setHeightForWidth(lineEdit_3->sizePolicy().hasHeightForWidth());
        lineEdit_3->setSizePolicy(sizePolicy);

        horizontalLayout_18->addWidget(lineEdit_3);

        checkBox_8 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_8->setObjectName(QStringLiteral("checkBox_8"));

        horizontalLayout_18->addWidget(checkBox_8);

        checkBox_9 = new QCheckBox(scrollAreaWidgetContents);
        checkBox_9->setObjectName(QStringLiteral("checkBox_9"));

        horizontalLayout_18->addWidget(checkBox_9);


        verticalLayout->addLayout(horizontalLayout_18);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout_11->addWidget(pushButton);

        pushButton_2 = new QPushButton(scrollAreaWidgetContents);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout_11->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_11);


        horizontalLayout_16->addLayout(verticalLayout);

        customPlot = new QCustomPlot(scrollAreaWidgetContents);
        customPlot->setObjectName(QStringLiteral("customPlot"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(customPlot->sizePolicy().hasHeightForWidth());
        customPlot->setSizePolicy(sizePolicy2);
        customPlot->setMinimumSize(QSize(447, 503));

        horizontalLayout_16->addWidget(customPlot);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Fibre);
        QObject::connect(pushButton, SIGNAL(clicked()), Fibre, SLOT(close()));

        QMetaObject::connectSlotsByName(Fibre);
    } // setupUi

    void retranslateUi(QDialog *Fibre)
    {
        Fibre->setWindowTitle(QApplication::translate("Fibre", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Fibre", "<html><head/><body><p>Core Diameter [mm]:</p></body></html>", Q_NULLPTR));
        label_5->setText(QApplication::translate("Fibre", "<html><head/><body><p>Cladding Diameter [mm]:</p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("Fibre", "NA:", Q_NULLPTR));
        label_10->setText(QApplication::translate("Fibre", "Doped:", Q_NULLPTR));
        label_4->setText(QApplication::translate("Fibre", "Wavelength for NA:", Q_NULLPTR));
        label_8->setText(QApplication::translate("Fibre", "Environment Index:", Q_NULLPTR));
        label_2->setText(QApplication::translate("Fibre", "<html><head/><body><p>Length [mm]:</p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("Fibre", "Input F#:", Q_NULLPTR));
        label_7->setText(QApplication::translate("Fibre", "Absorption Data:", Q_NULLPTR));
        label_11->setText(QApplication::translate("Fibre", "<html><head/><body><p>2-Pixel Resolution  [nm]:</p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("Fibre", "<html><head/><body><p>Spectrum Width [pix]:</p></body></html>", Q_NULLPTR));
        label_9->setText(QApplication::translate("Fibre", "<html><head/><body><p>Min. Bend Radius [mm]:</p></body></html>", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Fibre", "Reflections", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("Fibre", "OPL", Q_NULLPTR));
        checkBox_3->setText(QApplication::translate("Fibre", "Trans", Q_NULLPTR));
        checkBox_5->setText(QApplication::translate("Fibre", "F#", Q_NULLPTR));
        checkBox_4->setText(QApplication::translate("Fibre", "Index", Q_NULLPTR));
        checkBox_6->setText(QApplication::translate("Fibre", "max. Modes", Q_NULLPTR));
        checkBox_10->setText(QApplication::translate("Fibre", "Modes", Q_NULLPTR));
        checkBox_7->setText(QApplication::translate("Fibre", "M-Noise", Q_NULLPTR));
        label_13->setText(QApplication::translate("Fibre", "Font Size:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Fibre", "Save As:", Q_NULLPTR));
        checkBox_8->setText(QApplication::translate("Fibre", "pdf", Q_NULLPTR));
        checkBox_9->setText(QApplication::translate("Fibre", "png", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Fibre", "Close", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Fibre", "Go", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Fibre: public Ui_Fibre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIBRE_H
