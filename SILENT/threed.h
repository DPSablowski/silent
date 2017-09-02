#ifndef THREED_H
#define THREED_H

#include <QDialog>
#include <pthreed.h>
namespace Ui {
class threed;
}

class threed : public QDialog
{
    Q_OBJECT

public:
    explicit threed(QWidget *parent = 0);
    ~threed();

public slots:
    void seData(QString str);

private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_doubleSpinBox_valueChanged();

    void on_spinBox_valueChanged();

    void on_doubleSpinBox_5_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_doubleSpinBox_4_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_doubleSpinBox_7_valueChanged();

    void on_doubleSpinBox_8_valueChanged();

    void on_doubleSpinBox_9_valueChanged();

    void on_doubleSpinBox_10_valueChanged();

    void on_doubleSpinBox_29_valueChanged();

    void on_doubleSpinBox_11_valueChanged();

    void on_doubleSpinBox_12_valueChanged();

    void on_doubleSpinBox_13_valueChanged();

    void on_doubleSpinBox_14_valueChanged();

    void on_spinBox_2_valueChanged();

    void on_spinBox_3_valueChanged();

    void on_spinBox_4_valueChanged();

    void on_spinBox_5_valueChanged();

    void on_doubleSpinBox_15_valueChanged();

    void on_doubleSpinBox_16_valueChanged();

    void on_doubleSpinBox_17_valueChanged();

    void on_doubleSpinBox_18_valueChanged();

    void on_doubleSpinBox_19_valueChanged();

    void on_checkBox_3_clicked();

    void on_checkBox_4_clicked();

    void on_checkBox_5_clicked();

    void on_spinBox_6_valueChanged();

    void on_doubleSpinBox_20_valueChanged();

    void on_doubleSpinBox_21_valueChanged();

    void on_pushButton_2_clicked();

    void on_spinBox_7_valueChanged();

    void on_spinBox_8_valueChanged();

    void on_spinBox_9_valueChanged();

    void on_spinBox_10_valueChanged();

    void on_spinBox_11_valueChanged();

    void on_doubleSpinBox_24_valueChanged();

    void on_doubleSpinBox_26_valueChanged();

    void on_doubleSpinBox_27_valueChanged();

    void on_doubleSpinBox_28_valueChanged();

    void on_pushButton_3_clicked();

    void vecresize();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void setvalues3d();

    void on_pushButton_6_clicked();

    void showPointToolTip(QMouseEvent *event);

    void showPointToolTip_2(QMouseEvent *event);


private:
    Ui::threed *ui;
    pthreed *qPthreed;
};

#endif // THREED_H
