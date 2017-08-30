#ifndef FRAMECL_H
#define FRAMECL_H

#include <QDialog>

namespace Ui {
class FrameCl;
}

class FrameCl : public QDialog
{
    Q_OBJECT

public:
    explicit FrameCl(QWidget *parent = 0);
    ~FrameCl();

public slots:
    void seData(QString str);

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_3_clicked();

    void on_checkBox_2_clicked();

    void on_checkBox_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinBox_3_valueChanged();

private:
    Ui::FrameCl *ui;
};

#endif // FRAMECL_H
