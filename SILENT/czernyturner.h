#ifndef CZERNYTURNER_H
#define CZERNYTURNER_H

#include <QDialog>

namespace Ui {
class CzernyTurner;
}

class CzernyTurner : public QDialog
{
    Q_OBJECT

public:
    explicit CzernyTurner(QWidget *parent = 0);
    ~CzernyTurner();

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

private:
    Ui::CzernyTurner *ui;
};

#endif // CZERNYTURNER_H
