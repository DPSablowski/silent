#ifndef PETZVAL_H
#define PETZVAL_H

#include <QDialog>

namespace Ui {
class Petzval;
}

class Petzval : public QDialog
{
    Q_OBJECT

public:
    explicit Petzval(QWidget *parent = 0);
    ~Petzval();

public slots:
    void seData(QString str);

private slots:
    void loadDatabase();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_spinBox_5_valueChanged();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_comboBox_2_currentIndexChanged();

    void on_spinBox_7_valueChanged();

    void on_pushButton_8_clicked();

private:
    Ui::Petzval *ui;


};

#endif // PETZVAL_H
