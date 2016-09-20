#ifndef PTHREED_H
#define PTHREED_H

#include <QDialog>

namespace Ui {
class pthreed;
}

class pthreed : public QDialog
{
    Q_OBJECT

public:
    explicit pthreed(QWidget *parent = 0);
    ~pthreed();

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_checkBox_15_clicked();

    void on_checkBox_16_clicked();

    void on_spinBox_valueChanged();

private:
    Ui::pthreed *ui;
};

#endif // PTHREED_H
