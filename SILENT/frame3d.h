#ifndef FRAME3D_H
#define FRAME3D_H

#include <QDialog>

namespace Ui {
class Frame3D;
}

class Frame3D : public QDialog
{
    Q_OBJECT

public:
    explicit Frame3D(QWidget *parent = 0);
    ~Frame3D();

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinBox_3_valueChanged();

private:
    Ui::Frame3D *ui;
};

#endif // FRAME3D_H
