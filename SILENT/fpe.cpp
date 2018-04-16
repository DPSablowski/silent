#include "fpe.h"
#include "ui_fpe.h"
#include <cmath>

FPE::FPE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FPE)
{
    ui->setupUi(this);
    this->setWindowTitle("Fabry-Perot-Etalon Tool");

    ui->doubleSpinBox->setValue(3);
    ui->doubleSpinBox_2->setValue(1);
    ui->doubleSpinBox_3->setValue(0.9);
    ui->doubleSpinBox_6->setValue(0);

    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabel("Wavelength [nm]");
    ui->customPlot->yAxis->setLabel("rel. Transmission");

    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));
}

FPE::~FPE()
{
    delete ui;
}

//********************************************************
//show mouse coordinates
//********************************************************
void FPE::showPointToolTip(QMouseEvent *event)
{

    double xc = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

//*********************************
// Plot Transmission
//*********************************
void FPE::on_pushButton_2_clicked()
{
    ui->customPlot->clearGraphs();

    double d = ui->doubleSpinBox->value()*1000000;
    double n = ui->doubleSpinBox_2->value();
    double R = ui->doubleSpinBox_3->value();
    double Fr = 4*R/(pow((1-R),2));
    double theta = ui->doubleSpinBox_6->value();
    double lw = ui->doubleSpinBox_4->value();
    double uw = ui->doubleSpinBox_5->value();
    double mw = (uw+lw)/2;
    double OPD = d*2*pow((pow(n,2)-pow(sin(theta),2)),0.5);
    int points = ui->spinBox->value();
    //int fl = ui->spinBox_2->value();
    //int pl = ui->spinBox_3->value();
    //double Ffl = fl/(2*1.414*n*cos(theta));
    //double Fpl = pl/(2*n*cos(theta));

    //double F = pow(1/(1/pow(Fr,2)+1/pow(Ffl,2)+1/pow(Fpl,2)),0.5);

    double dl = pow(mw,2)/OPD/points;

    int steps = (uw-lw)/dl;

    QVector<double> wl(steps), It(steps);

    for(int i =0; i<steps; i++){
        wl[i] = lw+i*dl;
        It[i] = 1/(1+Fr*pow(sin(OPD*M_PI/wl[i]),2));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph()->addData(wl, It);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();

}
