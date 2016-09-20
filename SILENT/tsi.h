#ifndef TSI_H
#define TSI_H

#include <QDialog>

namespace Ui {
class TSI;
}

class TSI : public QDialog
{
    Q_OBJECT

public:
    explicit TSI(QWidget *parent = 0);
    ~TSI();

private slots:
    void on_pushButton_2_clicked();

    void on_spinBox_3_valueChanged();

    void on_spinBox_4_valueChanged();

    void on_spinBox_5_valueChanged();

    void on_spinBox_valueChanged();

    void on_spinBox_2_valueChanged();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::TSI *ui;
};

#endif // TSI_H
