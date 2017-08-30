#ifndef FRAMEECHELLE_H
#define FRAMEECHELLE_H

#include <QDialog>

namespace Ui {
class FrameEchelle;
}

class FrameEchelle : public QDialog
{
    Q_OBJECT

public:
    explicit FrameEchelle(QWidget *parent = 0);
    ~FrameEchelle();

public slots:
    void seData(QString str);

private slots:
    void on_pushButton_2_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_pushButton_3_clicked();

    void on_checkBox_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinBox_3_valueChanged();

private:
    Ui::FrameEchelle *ui;
};

#endif // FRAMEECHELLE_H
