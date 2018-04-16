/********************************************************************************
** Form generated from reading UI file 'warning1.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING1_H
#define UI_WARNING1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Warning1
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Warning1)
    {
        if (Warning1->objectName().isEmpty())
            Warning1->setObjectName(QStringLiteral("Warning1"));
        Warning1->resize(400, 181);
        verticalLayout_2 = new QVBoxLayout(Warning1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(Warning1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(Warning1);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(Warning1);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Warning1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Warning1);

        QMetaObject::connectSlotsByName(Warning1);
    } // setupUi

    void retranslateUi(QDialog *Warning1)
    {
        Warning1->setWindowTitle(QApplication::translate("Warning1", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Warning1", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; color:#ed1f1f;\">Warning !</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("Warning1", "<html><head/><body><p align=\"center\">This will delete all existing frames already calculated.</p><p align=\"center\">Save or export them first!<br/></p><p align=\"center\">Do you wish to continue?</p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Warning1", "OK", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Warning1", "STOP", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Warning1: public Ui_Warning1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING1_H
