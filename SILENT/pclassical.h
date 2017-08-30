#ifndef PCLASSICAL_H
#define PCLASSICAL_H

#include <QDialog>

namespace Ui {
class PClassical;
}

class PClassical : public QDialog
{
    Q_OBJECT

public:
    explicit PClassical(QWidget *parent = 0);
    ~PClassical();

public slots:
    void seData(QString str);

private slots:

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_checkBox_14_clicked();

    void on_checkBox_15_clicked();

    void on_spinBox_valueChanged();

    void showPointToolTip(QMouseEvent *event);

private:
    Ui::PClassical *ui;
};

#endif // PCLASSICAL_H
