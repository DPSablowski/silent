#ifndef VPHG_H
#define VPHG_H

#include <QDialog>

namespace Ui {
class VPHG;
}

class VPHG : public QDialog
{
    Q_OBJECT

public:
    explicit VPHG(QWidget *parent = 0);
    ~VPHG();

private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void calculateVPH();

    void on_doubleSpinBox_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_doubleSpinBox_7_valueChanged();

    void on_doubleSpinBox_8_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_doubleSpinBox_4_valueChanged();

    void on_doubleSpinBox_5_valueChanged();

    void on_doubleSpinBox_9_valueChanged();

    void on_doubleSpinBox_10_valueChanged();

    void on_checkBox_3_clicked();

    void on_spinBox_valueChanged();

    void on_pushButton_2_clicked();

private:
    Ui::VPHG *ui;
};

#endif // VPHG_H
