#ifndef CLASSICAL_H
#define CLASSICAL_H

#include <QDialog>
#include <pclassical.h>

namespace Ui {
class classical;
}

class classical : public QDialog
{
    Q_OBJECT

public:
    explicit classical(QWidget *parent = 0);
    ~classical();

public slots:
    void seData(QString str);

private slots:

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_pushButton_2_clicked();

    void on_doubleSpinBox_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_doubleSpinBox_4_valueChanged();

    void on_doubleSpinBox_5_valueChanged();

    void on_spinBox_3_valueChanged();

    void on_spinBox_4_valueChanged();

    void on_spinBox_valueChanged();

    void on_spinBox_2_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_pushButton_3_clicked();

    void on_doubleSpinBox_7_valueChanged();

    void vecresize();

    void on_doubleSpinBox_8_valueChanged();

    void on_doubleSpinBox_10_valueChanged();

    void on_doubleSpinBox_11_valueChanged();

    void on_doubleSpinBox_12_valueChanged();

    void on_doubleSpinBox_13_valueChanged();

    void on_doubleSpinBox_14_valueChanged();

    void on_doubleSpinBox_15_valueChanged();

    void on_doubleSpinBox_16_valueChanged();

    void on_pushButton_4_clicked();

    void on_doubleSpinBox_17_valueChanged();

    void on_doubleSpinBox_18_valueChanged();

    void on_spinBox_10_valueChanged();

    void on_doubleSpinBox_19_valueChanged();

    void on_doubleSpinBox_20_valueChanged();

    void on_doubleSpinBox_21_valueChanged();

    void on_doubleSpinBox_22_valueChanged();

    void on_doubleSpinBox_23_valueChanged();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void setvaluescl();

    void on_spinBox_5_valueChanged();

    void on_spinBox_6_valueChanged();

    void on_spinBox_7_valueChanged();

    void on_spinBox_8_valueChanged();

    void on_spinBox_9_valueChanged();

    void ReadTSI();

private:
    Ui::classical *ui;
    PClassical *qPClassical;
};

#endif // CLASSICAL_H
