#ifndef FPE_H
#define FPE_H

#include <QDialog>

namespace Ui {
class FPE;
}

class FPE : public QDialog
{
    Q_OBJECT

public:
    explicit FPE(QWidget *parent = 0);
    ~FPE();

private slots:
    void on_pushButton_2_clicked();

    void showPointToolTip(QMouseEvent *event);

private:
    Ui::FPE *ui;
};

#endif // FPE_H
