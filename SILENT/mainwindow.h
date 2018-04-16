#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <classical.h>
#include <echelle.h>
#include <pclassical.h>
#include <threed.h>
#include <pthreed.h>
#include <frame3d.h>
#include <frameechelle.h>
#include <vphg.h>
#include <fibre.h>
#include <framecl.h>
#include <tsi.h>
#include <notes.h>
#include <QtCore>
#include <QtGui>
#include <fpe.h>
#include <czernyturner.h>
#include <petzval.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_spinBox_4_valueChanged();

    void on_actionClassical_triggered();

    void on_pushButton_2_clicked();

    void on_doubleSpinBox_4_valueChanged();

    void on_doubleSpinBox_3_valueChanged();

    void on_checkBox_8_clicked();

    void on_checkBox_9_clicked();

    void on_checkBox_clicked();

    void on_pushButton_3_clicked();

    void overview();

    void revectors();

    void Echellogram();

    void parameters();

    void on_doubleSpinBox_valueChanged();

    void on_doubleSpinBox_2_valueChanged();

    void on_pushButton_4_clicked();

    void on_spinBox_5_valueChanged();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_actionParameters_triggered();

    void on_doubleSpinBox_5_valueChanged();

    void on_doubleSpinBox_6_valueChanged();

    void on_doubleSpinBox_8_valueChanged();

    void on_doubleSpinBox_7_valueChanged();

    void on_doubleSpinBox_9_valueChanged();

    void on_doubleSpinBox_10_valueChanged();

    void on_doubleSpinBox_12_valueChanged();

    void on_doubleSpinBox_14_valueChanged();

    void on_doubleSpinBox_15_valueChanged();

    void on_doubleSpinBox_16_valueChanged();

    void on_doubleSpinBox_17_valueChanged();

    void on_spinBox_2_valueChanged();

    void on_spinBox_valueChanged();

    void on_spinBox_3_valueChanged();

    void on_spinBox_7_valueChanged();

    void on_spinBox_8_valueChanged();

    void on_checkBox_11_clicked();

    void on_spinBox_6_valueChanged();

    void on_doubleSpinBox_18_valueChanged();

    void on_doubleSpinBox_20_valueChanged();

    void on_doubleSpinBox_21_valueChanged();

    void on_actionClassical_2_triggered();

    void on_doubleSpinBox_22_valueChanged();

    void on_doubleSpinBox_23_valueChanged();

    void on_doubleSpinBox_24_valueChanged();

    void on_doubleSpinBox_25_valueChanged();

    void on_doubleSpinBox_27_valueChanged();

    void on_doubleSpinBox_28_valueChanged();

    void on_doubleSpinBox_29_valueChanged();

    void on_doubleSpinBox_26_valueChanged();

    void on_action3D_Spectrograph_triggered();

    void on_action3D_triggered();

    void on_action3D_Frame_triggered();

    void on_actionEchelle_Frame_triggered();

    void on_pushButton_7_clicked();

    void on_actionAbout_triggered();

    void on_actionBug_Report_triggered();

    void on_actionManual_triggered();

    void on_pushButton_8_clicked();

    void setvalues();

    void on_actionBasics_triggered();

    void on_actionVPHG_triggered();

    void on_actionOptical_Fibres_triggered();

    void on_comboBox_currentIndexChanged();

    void on_comboBox_2_currentIndexChanged();

    void on_spinBox_9_valueChanged();

    void on_doubleSpinBox_33_valueChanged();

    void on_spinBox_10_valueChanged();

    void on_spinBox_11_valueChanged();

    void on_doubleSpinBox_35_valueChanged();

    void on_doubleSpinBox_34_valueChanged();

    void on_actionClassical_Frame_triggered();

    void on_actionTSI_triggered();

    void warning1();

    void on_actionNotes_triggered();

    void on_actionNew_triggered();

    void on_actionUndo_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_AS_triggered();

    void on_actionSave_triggered();

    void showPointToolTip(QMouseEvent *event);

    void showPointToolTip_2(QMouseEvent *event);

    void showPointToolTip_3(QMouseEvent *event);

    void showPointToolTip_4(QMouseEvent *event);

    void showPointToolTip_5(QMouseEvent *event);

    void on_actionFPE_triggered();

    void on_actionCzerny_Turner_triggered();

    void on_actionPetzval_triggered();

    void on_pushButton_9_clicked();

    void on_comboBox_4_currentIndexChanged();

    void on_pushButton_10_clicked();

    void on_checkBox_2_clicked();

private:
    Ui::MainWindow *ui;
    classical *qClassical;
    Echelle *qEchelle;
    PClassical *qPClassical;
    threed *qThreed;
    pthreed *qPthreed;
    Frame3D *qFrame3D;
    FrameEchelle *qFrameEchelle;
    VPHG *qVPHG;
    Fibre *qFibre;
    FrameCl *qFrameCl;
    TSI *qTSI;
    Notes *qNotes;
    FPE *qFPE;
    QString mFilename;
    CzernyTurner *qCT;
    Petzval *qPetzval;

};

#endif // MAINWINDOW_H
