#ifndef FIBRE_H
#define FIBRE_H

#include <QDialog>

namespace Ui {
class Fibre;
}

class Fibre : public QDialog
{
    Q_OBJECT

public:
    explicit Fibre(QWidget *parent = 0);
    ~Fibre();

private slots:
    void reflections();

    void on_doubleSpinBox_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_4_valueChanged();

    void on_doubleSpinBox_5_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_pushButton_2_clicked();

    void on_doubleSpinBox_7_valueChanged();

    void OPL();

    void transmission();

    void bending();

    void IndexCo();

    void naperture();

    void evanescent();

    void nmodes();

    void modes();

    void mnoise();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_checkBox_6_clicked();

    void on_comboBox_currentIndexChanged();

    void on_checkBox_7_clicked();

    void on_doubleSpinBox_9_valueChanged();

    void on_spinBox_valueChanged();

    void on_spinBox_2_valueChanged();

    void on_pushButton_3_clicked();

    void on_checkBox_10_clicked();

private:
    Ui::Fibre *ui;
};

#endif // FIBRE_H
