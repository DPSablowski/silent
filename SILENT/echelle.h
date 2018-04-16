#ifndef ECHELLE_H
#define ECHELLE_H

#include <QDialog>

namespace Ui {
class Echelle;
}

class Echelle : public QDialog
{
    Q_OBJECT

public:
    explicit Echelle(QWidget *parent = 0);
    ~Echelle();

public slots:
    void seData(QString str, int pix, int piy);

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_checkBox_16_clicked();

    void on_checkBox_17_clicked();

    void on_spinBox_3_valueChanged();

    void showPointToolTip(QMouseEvent *event);

private:
    Ui::Echelle *ui;
};

#endif // ECHELLE_H
