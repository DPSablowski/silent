#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <classical.h>
#include <echelle.h>
#include <qcustomplot.h>
#include <pclassical.h>
#include <threed.h>
#include <frame3d.h>
#include <frameechelle.h>
#include <vphg.h>
#include <QColor>
#include <QtGui>
#include <QFileDialog>
#include <QDir>


using namespace std;

double l1; // lower wavelength
  double l2; // upper wavelength
  double f1; // collimator focal length
  double f2; // camera focal length
  double g; // grating groove density
  double t; // total angle at grating
  double p; // pixel size
  int lx; // number of CCD pixels in x
  int ly; // number of CCD pixels in y
  double dl; // wavelength increment
  double a; // angle of incidence
  double b; // angle of diffraction
  double Pi = 3.14159265;
  double dl12; // wavelength resolution
  double s; // slit width
  double sl;//slit length
  double slitEff; //efficiency at slit
  int Bx=1; // Binningfactor in x
  int By=1; // Binningfactor in y
  int al=0;   // number aluminium surfaces
  int ag=0;   // number silver surfaces
  int bb=0;   // number broabdand surfaces
  int aluv=0;   // number uv enhanced alu surfaces
  int au=0;     // number of gold surfaces
  int unc=0;  // number uncoated surfaces
  double d; // groove space
  double theta; // blaze angle
  double thetac;
  double dc;
  double at; // sin(a - theta)
  double atc;// sin(acc-thetac)
  double eta; // grating peak efficiency
  double etac;// CD grating peak efficiency
  double ftel; // telescope focal length
  double seeing; // seeing in arcsec
  double sdisc; // FWHM seeing disc
  double lz; // central wavelength
  int offset; // CCD offset ADU
  double readnoise; // CCD readnoise
  double gain;
  double CCDl;
  double CCDp;
  double CCDT;
  double CCDm;
  double peak; // signal peak
  double gc; // grating densitiy of cross disperser
  double tc; // totoal angle cross-disperser
  double nc; // central order
  double ncd=1; // CD order
  double llc; // central lower wavelength
  double llh; // central upper wavelenth
  double B1, B2, B3, C1, C2, C3; //Sellmeier Coeff.
  double np; //Index of refraction Sellmeier
  double k = 143877500;
  double dtel;
  double ap = 1.87088e24;
  double BC=0;
  int e=1;
  double T;//effective temperature
  double vm;//visual magnitude
  double z;//zenit distance
  double exptime; //exposure time
  double bm;
  double acc;
  double bcc;
  double bmc;
  double nl1;
  double nh1;
  int nl=1;
  int nh=0;
  int aal=0, aag=0, abb=0, aaluv=0, aau=0;
  double llow;
  double lhigh;
  double nDCG; // refractive index of DCG layer
  double dDCG; // thickness of DCG layer
  double dnDCG; // semiamplitude of modulation of DCG layer
  double tDCG;  // tune wavelength of VPH Grating
  double I, b2, summe, skyslit, theta2, gamma2, indexlz, FWHM;
  QVector<double> n(nl-nh), o(nl-nh), Ef(nl-nh), bt(nl-nh), In(nl-nh), Ip(nl-nh), overlap(nl-nh), separation(nl-nh), average(nl-nh), I1(nl-nh), I1c(nl-nh), b1(nl-nh), D(nl-nh), lw(nl-nh), lh(nl-nh), l11(nl-nh), D1(nl-nh), l(nl-nh), b1c(nl-nh), btc(nl-nh), R(nl-nh), A(nl-nh), Nf(nl-nh), s2(nl-nh), P(nl-nh), Tr(nl-nh), CCD(nl-nh);
  QVector<double> Frea(unc), sign(nl-nh), snr(nl-nh), ali(nl-nh), agi(nl-nh), bbi(nl-nh), aluvi(nl-nh), aui(nl-nh), aluvw(nl-nh), alw(nl-nh), ctit(nl-nh), cti(nl-nh), ctw(nl-nh), agw(nl-nh), bbw(nl-nh), auw(nl-nh), alt(nl-nh), agt(nl-nh), bbt(nl-nh), aluvt(nl-nh), aut(nl-nh);
  QVector<double> Fren(unc);
  QVector<double> Frp(unc);
  QVector<double> Frs(unc);
  QVector<double> Fr(unc);
  int vars=47;
  QVector<double> variables(vars);

  double Frenl=1;
  string line, eins, zwei;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("SILENT - Spectrograph sImuLation & EmulatioN Tool");
/*
    ui->lineEdit->setStyleSheet("color: rgb(197, 82, 82, 255); background-color: rgb(52, 42, 114, 255) ");
    ui->lineEdit_2->setStyleSheet("color: rgb(197, 82, 82, 255); background-color: rgb(52, 42, 114, 255) ");
    ui->lineEdit_10->setStyleSheet("color: rgb(197, 82, 82, 255); background-color: rgb(52, 42, 114, 255) ");
    ui->lineEdit_11->setStyleSheet("color: rgb(197, 82, 82, 255); background-color: rgb(52, 42, 114, 255) ");
    */

    ui->progressBar->setValue(0);

    ui->checkBox_8->setChecked(true);
    ui->doubleSpinBox_15->setEnabled(false);
    ui->lineEdit->setEnabled(false);
    ui->comboBox->setEnabled(false);
    ui->doubleSpinBox_6->setEnabled(true);
    ui->doubleSpinBox_7->setEnabled(true);
    ui->doubleSpinBox_18->setEnabled(false);
    ui->doubleSpinBox_19->setEnabled(false);
    ui->doubleSpinBox_20->setEnabled(false);
    ui->doubleSpinBox_21->setEnabled(false);
    ui->doubleSpinBox_28->setEnabled(true);
    ui->doubleSpinBox_27->setEnabled(true);

    ui->lineEdit_2->setText(QDir::currentPath());

    B1=1.39757037;
    B2=0.159201403;
    B3=1.26865432;
    C1=0.00995906143;
    C2=0.0546931752;
    C3=119.248346;

    l1=ui->doubleSpinBox->value();
    l2=ui->doubleSpinBox_2->value();

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Index"<<"Angle");

    ui->doubleSpinBox_22->setValue(75);
    g=ui->doubleSpinBox_22->value();

    ui->doubleSpinBox_23->setValue(63);
    theta=ui->doubleSpinBox_23->value();

    ui->doubleSpinBox_24->setValue(5);
    t=ui->doubleSpinBox_24->value();

    ui->doubleSpinBox_27->setValue(300);
    gc=ui->doubleSpinBox_27->value();

    ui->doubleSpinBox_25->setValue(125);
    f1=ui->doubleSpinBox_25->value();

    ui->doubleSpinBox_26->setValue(120);
    f2=ui->doubleSpinBox_26->value();

    ui->doubleSpinBox_28->setValue(5);
    tc=ui->doubleSpinBox_28->value();

    ui->doubleSpinBox_14->setValue(0.05);
    s=ui->doubleSpinBox_14->value();

    ui->doubleSpinBox_9->setValue(4000);
    T=ui->doubleSpinBox_9->value();

    if (log10(T)<4){
         BC = -64741.46+67717*log10(T)-26566.141*log10(T)*log10(T)+4632.926*log10(T)*log10(T)*log10(T)-303.0307*log10(T)*log10(T)*log10(T)*log10(T);
         }
         else {
              BC = -888.82+884.69*log10(T)-326.85*log10(T)*log10(T)+53.4*log10(T)*log10(T)*log10(T)-3.2744*log10(T)*log10(T)*log10(T)*log10(T);
              }

    ui->doubleSpinBox_11->setValue(BC);

    ui->doubleSpinBox_10->setValue(2);
    vm=ui->doubleSpinBox_10->value();

    ui->doubleSpinBox_12->setValue(20);
    z=ui->doubleSpinBox_12->value();

    ui->doubleSpinBox_29->setValue(4);
    seeing=ui->doubleSpinBox_29->value();

    ui->doubleSpinBox_35->setValue(2500);
    ftel=ui->doubleSpinBox_35->value();

    ui->doubleSpinBox_34->setValue(254);
    dtel=ui->doubleSpinBox_34->value();

    ui->doubleSpinBox_33->setValue(0.009);
    p=ui->doubleSpinBox_33->value();

    ui->spinBox_10->setValue(1500);
    lx=ui->spinBox_10->value();

    ui->spinBox_11->setValue(1024);
    ly=ui->spinBox_11->value();

    ui->doubleSpinBox_17->setValue(7);
    readnoise=ui->doubleSpinBox_17->value();

    ui->doubleSpinBox_15->setValue(0);
    sl=ui->doubleSpinBox_15->value();

    ui->spinBox_4->setValue(1);
    Bx=ui->spinBox_4->value();

    ui->spinBox_5->setValue(1);
    By=ui->spinBox_5->value();

    ui->doubleSpinBox_4->setValue(550);
    CCDl=ui->doubleSpinBox_4->value();

    ui->doubleSpinBox_3->setValue(0.85);
    CCDp=ui->doubleSpinBox_3->value();

    ui->doubleSpinBox_6->setValue(4.25);
    thetac=ui->doubleSpinBox_6->value();

    ui->doubleSpinBox->setValue(400);
    l1=ui->doubleSpinBox->value();
    ui->doubleSpinBox_2->setValue(700);
    l2=ui->doubleSpinBox_2->value();

    ui->doubleSpinBox_5->setValue(0.75);
    eta=ui->doubleSpinBox_5->value();

    CCDT=2897.8/CCDl*1000;
    CCDm = 1.87088e19/(CCDl*CCDl*CCDl*CCDl*CCDl)/(exp(14387750/CCDl/CCDT)-1);

    d=cos(M_PI/180*theta)/g;
    dc=cos(M_PI/180*thetac)/gc;
    sdisc = tan(M_PI/180*seeing/3600)*ftel;

    skyslit=atan(s/ftel)*3600*180/M_PI;
    ui->doubleSpinBox_31->setValue(skyslit);

    ui->doubleSpinBox_8->setValue(10);
    exptime=ui->doubleSpinBox_8->value();

    ui->doubleSpinBox_7->setValue(0.75);
    etac=ui->doubleSpinBox_7->value();

    ui->doubleSpinBox_16->setValue(1.5);
    gain=ui->doubleSpinBox_16->value();

    ui->spinBox_9->setValue(200);
    offset=ui->spinBox_9->value();

    ui->spinBox->setValue(2);
    ag=ui->spinBox->value();

    ui->spinBox_2->setValue(1);
    al=ui->spinBox_2->value();

    ui->spinBox_3->setValue(9);
    bb=ui->spinBox_3->value();

    ui->doubleSpinBox_18->setValue(1.4987);
    nDCG=ui->doubleSpinBox_18->value();

    ui->doubleSpinBox_19->setValue(0.005);
    dDCG=ui->doubleSpinBox_19->value();

    ui->doubleSpinBox_20->setValue(0.06);
    dnDCG=ui->doubleSpinBox_20->value();

    ui->doubleSpinBox_21->setValue((l2-l1)/2+l1);
    tDCG=ui->doubleSpinBox_21->value();

    ui->comboBox->addItem("N-F2");
    ui->comboBox->addItem("N-SF2");
    ui->comboBox->addItem("N-BK7");
    ui->comboBox->addItem("N-SF5");
    ui->comboBox->addItem("CaF2");
    ui->comboBox->addItem("F2");
    ui->comboBox->addItem("F5");
    ui->comboBox->addItem("K10");
    ui->comboBox->addItem("K7");
    ui->comboBox->addItem("KZFS12");
    ui->comboBox->addItem("KZFS5");
    ui->comboBox->addItem("LAFN7");
    ui->comboBox->addItem("LF5");
    ui->comboBox->addItem("LLF1");
    ui->comboBox->addItem("N-BAF10");
    ui->comboBox->addItem("N-BAF4");
    ui->comboBox->addItem("N-BAF51");
    ui->comboBox->addItem("N-BAF52");
    ui->comboBox->addItem("N-BAK1");
    ui->comboBox->addItem("N-BAK2");
    ui->comboBox->addItem("N-BAK4");
    ui->comboBox->addItem("N-BALF4");
    ui->comboBox->addItem("N-BALF5");
    ui->comboBox->addItem("N-BASF2");
    ui->comboBox->addItem("N-BASF64");
    ui->comboBox->addItem("N-BK10");
    ui->comboBox->addItem("N-FK5");
    ui->comboBox->addItem("N-KF9");
    ui->comboBox->addItem("N-KZFS11");
    ui->comboBox->addItem("N-SF11");
    ui->comboBox->addItem("ZnSe");
    ui->comboBox->addItem("N-SF10");
    ui->comboBox->addItem("Fused Silica");

    ui->comboBox_2->addItem("Grating");
    ui->comboBox_2->addItem("Prism");
    ui->comboBox_2->addItem("VPH Grating");
    ui->comboBox_2->addItem("VPH Grism");

    ui->comboBox_3->addItem("Planck");
    ui->comboBox_3->addItem("Neon Emission");
    ui->comboBox_3->addItem("Balmer Absorption");
    ui->comboBox_3->addItem("UVES Th/Ar");

    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot_2->axisRect()->setupFullAxesBox(true);
    ui->customPlot_3->axisRect()->setupFullAxesBox(true);
    ui->customPlot_4->axisRect()->setupFullAxesBox(true);
    ui->customPlot_5->axisRect()->setupFullAxesBox(true);

    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));
    connect(ui->customPlot_2, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip_2(QMouseEvent*)));
    connect(ui->customPlot_3, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip_3(QMouseEvent*)));
    connect(ui->customPlot_4, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip_4(QMouseEvent*)));
    connect(ui->customPlot_5, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip_5(QMouseEvent*)));

}


MainWindow::~MainWindow()
{
    delete ui;
}

//********************************************************
//show mouse coordinates
//********************************************************
void MainWindow::showPointToolTip(QMouseEvent *event)
{

    double xc = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

//********************************************************
//show mouse coordinates
//********************************************************
void MainWindow::showPointToolTip_2(QMouseEvent *event)
{

    double xc = ui->customPlot_2->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot_2->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

//********************************************************
//show mouse coordinates
//********************************************************
void MainWindow::showPointToolTip_3(QMouseEvent *event)
{

    double xc = ui->customPlot_3->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot_3->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

//********************************************************
//show mouse coordinates
//********************************************************
void MainWindow::showPointToolTip_4(QMouseEvent *event)
{

    double xc = ui->customPlot_4->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot_4->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

//********************************************************
//show mouse coordinates
//********************************************************
void MainWindow::showPointToolTip_5(QMouseEvent *event)
{

    double xc = ui->customPlot_5->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot_5->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

inline double std_rand()
{
       return rand() / (RAND_MAX + 1.0);
}

double gauss (){
       double p1, p2, u, e1;// e2;
       do {
           p1 = 2.0*std_rand() - 1.0;
           p2 = 2.0*std_rand() - 1.0;
           u = p1*p1 + p2*p2;
           } while (u >= 1.0);
           u = sqrt((-2.0 * log(u))/u);
           return e1 = p1 * u;
           //e2 = p2 * u;
           }

void MainWindow::on_comboBox_2_currentIndexChanged()
{
    int ec=ui->comboBox_2->currentIndex();

    //grating
    if(ec==0){
        e=1;
        ui->doubleSpinBox_6->setEnabled(true);
        ui->doubleSpinBox_7->setEnabled(true);
        ui->doubleSpinBox_18->setEnabled(false);
        ui->doubleSpinBox_19->setEnabled(false);
        ui->doubleSpinBox_20->setEnabled(false);
        ui->doubleSpinBox_21->setEnabled(false);
        ui->doubleSpinBox_28->setEnabled(true);
        ui->doubleSpinBox_27->setEnabled(true);
    }

    //prism
    if(ec==1){
        e=0;
        ui->comboBox->setEnabled(true);
        ui->doubleSpinBox_6->setEnabled(false);
        ui->doubleSpinBox_7->setEnabled(false);
        ui->doubleSpinBox_18->setEnabled(false);
        ui->doubleSpinBox_19->setEnabled(false);
        ui->doubleSpinBox_20->setEnabled(false);
        ui->doubleSpinBox_21->setEnabled(false);
        ui->doubleSpinBox_27->setEnabled(false);
        ui->doubleSpinBox_28->setEnabled(false);
    }
    //VPH Grating
    if(ec==2){
        ui->comboBox->setEnabled(false);
        e=2;
        ui->doubleSpinBox_6->setEnabled(false);
        ui->doubleSpinBox_7->setEnabled(false);
        ui->doubleSpinBox_18->setEnabled(true);
        ui->doubleSpinBox_19->setEnabled(true);
        ui->doubleSpinBox_20->setEnabled(true);
        ui->doubleSpinBox_21->setEnabled(true);
        ui->doubleSpinBox_28->setEnabled(false);
        ui->doubleSpinBox_27->setEnabled(true);
    }
    //VPH Grism
    if(ec==3){
        e=3;
        ui->comboBox->setEnabled(true);
        ui->doubleSpinBox_6->setEnabled(false);
        ui->doubleSpinBox_7->setEnabled(false);
        ui->doubleSpinBox_18->setEnabled(true);
        ui->doubleSpinBox_19->setEnabled(true);
        ui->doubleSpinBox_20->setEnabled(true);
        ui->doubleSpinBox_21->setEnabled(false);
        ui->doubleSpinBox_28->setEnabled(false);
        ui->doubleSpinBox_27->setEnabled(true);
    }

}


//lower wavelength
void MainWindow::on_doubleSpinBox_valueChanged()
{
    l1=ui->doubleSpinBox->value();
    lz=l1+(l2-l1)/2;
    tDCG=l1+(l2-l1)/2;
    ui->doubleSpinBox_21->setValue(tDCG);
}

//upper wavelength
void MainWindow::on_doubleSpinBox_2_valueChanged()
{
    l2=ui->doubleSpinBox_2->value();
    lz=l1+(l2-l1)/2;
    tDCG=l1+(l2-l1)/2;
    ui->doubleSpinBox_21->setValue(tDCG);
}


void MainWindow::on_doubleSpinBox_35_valueChanged()
{
    ftel=ui->doubleSpinBox_35->value();
    sdisc = tan(M_PI/180*seeing/3600)*ftel;
    skyslit=atan(s/ftel)*3600*180/M_PI;
    ui->doubleSpinBox_31->setValue(skyslit);
}


void MainWindow::on_spinBox_4_valueChanged()
{
    Bx=ui->spinBox_4->value();
}


void MainWindow::on_actionClassical_triggered()
{
    qClassical = new classical(this);
    qClassical->seData(ui->lineEdit_2->text());
    qClassical->show();
}



void MainWindow::on_pushButton_2_clicked()
{
    QTableWidgetItem *Findex, *Fangle;
    QString itab1, itab2;
    Frenl=1;
    unc=ui->spinBox_6->value();
    if (unc > 0){
             for (int i =0; i < unc; i++){

                 Findex=ui->tableWidget->item(i,0);
                 itab1=Findex->text();
                 Fren[i]=itab1.toDouble();
                 Fangle=ui->tableWidget->item(i,1);
                 itab2=Fangle->text();
                 Frea[i]=itab2.toDouble();
                 Frp[i] = pow((sqrt(1-1/Fren[i]/Fren[i]*sin(M_PI/180*Frea[i])*sin(M_PI/180*Frea[i]))-Fren[i]*cos(M_PI/180*Frea[i])),2)/pow((sqrt(1-1/Fren[i]/Fren[i]*sin(M_PI/180*Frea[i])*sin(M_PI/180*Frea[i]))+Fren[i]*cos(M_PI/180*Frea[i])),2);
                 Frs[i] = pow((cos(M_PI/180*Frea[i])-Fren[i]*sqrt(1-1/Fren[i]/Fren[i]*sin(Frea[i]*M_PI/180)*sin(Frea[i]*M_PI/180))),2)/pow((cos(M_PI/180*Frea[i])+Fren[i]*sqrt(1-1/Fren[i]/Fren[i]*sin(Frea[i]*M_PI/180)*sin(Frea[i]*M_PI/180))),2);
                     Fr[i] = 1-(Frp[i]+Frs[i])/2;

                     }
                 }
                 for (int i =0; i < unc; i++){
                     Frenl = Frenl * Fr[i];

                     }

     ui->doubleSpinBox_13->setValue(Frenl*100);
}

void MainWindow::on_doubleSpinBox_4_valueChanged()
{
    CCDl=ui->doubleSpinBox_4->value();
    CCDT=2897.8/CCDl*1000;
    CCDm = 1.87088e19/(CCDl*CCDl*CCDl*CCDl*CCDl)/(exp(14387750/CCDl/CCDT)-1);
}

void MainWindow::on_doubleSpinBox_3_valueChanged()
{
    CCDp=ui->doubleSpinBox_3->value();
    CCDT=2897.8/CCDl*1000;
    CCDm = 1.87088e19/(CCDl*CCDl*CCDl*CCDl*CCDl)/(exp(14387750/CCDl/CCDT)-1);
}

// circular slit
void MainWindow::on_checkBox_8_clicked()
{
    ui->checkBox_9->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->doubleSpinBox_15->setEnabled(false);
}

//rectangular slit
void MainWindow::on_checkBox_9_clicked()
{
    ui->checkBox_8->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->doubleSpinBox_15->setEnabled(true);
}

// slitless
void MainWindow::on_checkBox_clicked()
{
    ui->checkBox_8->setChecked(false);
    ui->checkBox_9->setChecked(false);
    ui->doubleSpinBox_15->setEnabled(false);
}


// slit efficiency
void MainWindow::on_pushButton_3_clicked()
{
    // circular slit
    if(ui->checkBox_8->isChecked()){

        double slitstep=0.0001;
        int steps=s/2/slitstep+1;
        double relativ=0;
        for(int i =0; i<steps-1; i++){
            relativ+=(exp(-2*i*slitstep*i*slitstep/sdisc/sdisc)+exp(-2*(i+1)*slitstep*(i+1)*slitstep/sdisc/sdisc))/2*slitstep;
        }
        slitEff=pow((2*relativ/(sdisc*sqrt(M_PI/2))),2);
        ui->doubleSpinBox_30->setValue(slitEff*100);
    }

    // rectangular slit
    if(ui->checkBox_9->isChecked()){

        double slitstep=0.0001;
        int steps1=s/2/slitstep+1;
        int steps2=sl/2/slitstep+1;
        double relativ1=0, relativ2=0;
        for(int i =0; i<steps1-1; i++){
            relativ1+=(exp(-2*i*slitstep*i*slitstep/sdisc/sdisc)+exp(-2*(i+1)*slitstep*(i+1)*slitstep/sdisc/sdisc))/2*slitstep;
        }
        if(sl!=0){
        for(int i =0; i<steps2-1; i++){
            relativ2+=(exp(-2*i*slitstep*i*slitstep/sdisc/sdisc)+exp(-2*(i+1)*slitstep*(i+1)*slitstep/sdisc/sdisc))/2*slitstep;
        }}
        else{
            relativ2+=sdisc*sqrt(M_PI/2)/2;
        }
        slitEff=2*relativ1*2*relativ2/pow((sdisc*sqrt(M_PI/2)),2);
        ui->doubleSpinBox_30->setValue(slitEff*100);
    }

    // slitless
    if(ui->checkBox->isChecked()){
        slitEff=1.0;
        ui->doubleSpinBox_30->setValue(100);
    }

}

//overview of wavelength coverage
void MainWindow::overview(){

    d=cos(M_PI/180*theta)/g;

    QString Output;
    // for grating CD
    if(e==1){
    bm = atan(lx*p/2/f2)*180/M_PI;
    lz = (l1+(l2-l1)/2)/1000000;

    dc = cos(M_PI/180*thetac)/gc;

    a = theta+t/2;
    b = theta-t/2;

    acc = asin(ncd*l1/1000000*gc/(2*cos(M_PI/180*tc/2)))*180/M_PI+tc/2;
    bcc = acc-tc;
    bmc = atan(ly*p/2/f2)*180/M_PI;
    atc = sin(M_PI/180*(acc-thetac));
    at = sin(M_PI/180*(a-theta));

    nl = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l1*1000000;
    nh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l2*1000000;

    llc = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nl*g);
    llh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nh*g);

    nl1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llc;
    nh1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llh;

    llow = llc - p*Bx*cos(b*M_PI/180)/(f2*nl*g)*lx/2;
    lhigh = llh + p*Bx*cos(b*M_PI/180)/(f2*nh*g)*lx/2;

    Output=QString::number(lz*1000000);
    ui->lineEdit_25->setText(Output);

    Output=QString::number(acc);
    ui->lineEdit_26->setText(Output);

    Output=QString::number(bcc);
    ui->lineEdit_27->setText(Output);

    //lower central wavelength
    Output=QString::number(llc*1000000);
    ui->lineEdit_28->setText(Output);

    Output=QString::number(llh*1000000);
    ui->lineEdit_29->setText(Output);

    Output=QString::number(llow*1000000);
    ui->lineEdit_30->setText(Output);

    Output=QString::number(lhigh*1000000);
    ui->lineEdit_31->setText(Output);

    Output=QString::number(nl1);
    ui->lineEdit_32->setText(Output);

    Output=QString::number(nh1);
    ui->lineEdit_33->setText(Output);
    }

    // for prism CD
    if(e==0){
        bm = atan(lx*p/2/f2)*180/M_PI;
           lz = (l1+(l2-l1)/2)/1000000;
           a = theta+t/2;
           b = theta-t/2;
           at = sin(M_PI/180*(a-theta));

           l1 = l1/1000;
               np = sqrt(1+B1*l1*l1/(l1*l1-C1)+B2*l1*l1/(l1*l1-C2)+B3*l1*l1/(l1*l1-C3));
               l1 = l1*1000;

               bmc = atan(ly*p/2/f2)*180/M_PI;
               acc = asin(ncd*l1/1000000*gc/(2*cos(M_PI/180*tc/2)))*180/M_PI+tc/2;
               bcc = acc-tc;
               atc = sin(M_PI/180*(acc-thetac));

               nl = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l1*1000000;
               nh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l2*1000000;

               llc = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nl*g);
               llh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nh*g);

               nl1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llc;
               nh1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llh;

               llow = llc - p*Bx*cos(b*M_PI/180)/(f2*nl*g)*lx/2;
               lhigh = llh + p*Bx*cos(b*M_PI/180)/(f2*nh*g)*lx/2;

               Output=QString::number(lz*1000000);
               ui->lineEdit_25->setText(Output);

               Output=QString::number(acc);
               ui->lineEdit_26->setText(Output);

               Output=QString::number(bcc);
               ui->lineEdit_27->setText(Output);

               //lower central wavelength
               Output=QString::number(llc*1000000);
               ui->lineEdit_28->setText(Output);

               Output=QString::number(llh*1000000);
               ui->lineEdit_29->setText(Output);

               Output=QString::number(llow*1000000);
               ui->lineEdit_30->setText(Output);

               Output=QString::number(lhigh*1000000);
               ui->lineEdit_31->setText(Output);

               Output=QString::number(nl1);
               ui->lineEdit_32->setText(Output);

               Output=QString::number(nh1);
               ui->lineEdit_33->setText(Output);
    }

    // for VPH Grating CD
    if(e==2){
        lz = (l1+(l2-l1)/2)/1000000;

        a = theta+t/2;
        b = theta-t/2;
        at = sin(M_PI/180*(a-theta));
        acc = asin(ncd*l1/1000000*gc/(2*cos(M_PI/180*tc/2)))*180/M_PI+tc/2;
        bcc = acc-tc;
        bmc = atan(ly*p/2/f2)*180/M_PI;
        atc = sin(M_PI/180*(acc-thetac));

            nl = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l1*1000000;
            nh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l2*1000000;

            llc = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nl*g);
            llh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nh*g);

            nl1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llc;
            nh1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llh;

            llow = llc - p*Bx*cos(b*M_PI/180)/(f2*nl*g)*lx/2;
            lhigh = llh + p*Bx*cos(b*M_PI/180)/(f2*nh*g)*lx/2;

            Output=QString::number(lz*1000000);
            ui->lineEdit_25->setText(Output);

            Output=QString::number(acc);
            ui->lineEdit_26->setText(Output);

            Output=QString::number(bcc);
            ui->lineEdit_27->setText(Output);

            //lower central wavelength
            Output=QString::number(llc*1000000);
            ui->lineEdit_28->setText(Output);

            Output=QString::number(llh*1000000);
            ui->lineEdit_29->setText(Output);

            Output=QString::number(llow*1000000);
            ui->lineEdit_30->setText(Output);

            Output=QString::number(lhigh*1000000);
            ui->lineEdit_31->setText(Output);

            Output=QString::number(nl1);
            ui->lineEdit_32->setText(Output);

            Output=QString::number(nh1);
            ui->lineEdit_33->setText(Output);

    }

    // for VPH Grism
    if(e==3){
        lz = (l1+(l2-l1)/2)/1000000;

        a = theta+t/2;
        b = theta-t/2;
        at = sin(M_PI/180*(a-theta));

            nl = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l1*1000000;
            nh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l2*1000000;

            llc = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nl*g);
            llh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nh*g);

            nl1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llc;
            nh1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llh;

            llow = llc - p*Bx*cos(b*M_PI/180)/(f2*nl*g)*lx/2;
            lhigh = llh + p*Bx*cos(b*M_PI/180)/(f2*nh*g)*lx/2;

            Output=QString::number(lz*1000000);
            ui->lineEdit_25->setText(Output);

            Output=QString::number(acc);
            ui->lineEdit_26->setText(Output);

            Output=QString::number(bcc);
            ui->lineEdit_27->setText(Output);

            //lower central wavelength
            Output=QString::number(llc*1000000);
            ui->lineEdit_28->setText(Output);

            Output=QString::number(llh*1000000);
            ui->lineEdit_29->setText(Output);

            Output=QString::number(llow*1000000);
            ui->lineEdit_30->setText(Output);

            Output=QString::number(lhigh*1000000);
            ui->lineEdit_31->setText(Output);

            Output=QString::number(nl1);
            ui->lineEdit_32->setText(Output);

            Output=QString::number(nh1);
            ui->lineEdit_33->setText(Output);
    }
}


// calculate
void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    MainWindow::overview();
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
}

void MainWindow::on_spinBox_5_valueChanged()
{
    By=ui->spinBox_5->value();
}

// resize vectors
void MainWindow::revectors()
{

    n.resize(nl-nh);
    o.resize(nl-nh);
    bt.resize(nl-nh);
    In.resize(nl-nh);
    Ip.resize(nl-nh);
    I1.resize(nl-nh);
    I1c.resize(nl-nh);
    b1.resize(nl-nh);
    D.resize(nl-nh);
    lw.resize(nl-nh);
    lh.resize(nl-nh);
    l11.resize(nl-nh);
    D1.resize(nl-nh);
    l.resize(nl-nh);
    b1c.resize(nl-nh);
    btc.resize(nl-nh);
    R.resize(nl-nh);
    A.resize(nl-nh);
    Nf.resize(nl-nh);
    s2.resize(nl-nh);
    P.resize(nl-nh);
    Tr.resize(nl-nh);
    CCD.resize(nl-nh);
    overlap.resize(nl-nh);
    separation.resize(nl-nh);
    average.resize(nl-nh);
    sign.resize(nl-nh);
    snr.resize(nl-nh);

}

// calculate parameters
void MainWindow::parameters()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    MainWindow::overview();
    MainWindow::revectors();
    MainWindow::on_pushButton_3_clicked();
    MainWindow::on_pushButton_2_clicked();
    ui->progressBar->setValue(0);

    if(ui->checkBox->isChecked()){
        s = tan(ui->doubleSpinBox_29->value()/3600*M_PI/180)*ui->doubleSpinBox_35->value();
    }
    else{
        s = ui->doubleSpinBox_14->value();
    }

    int counter=0, bini=0, bini2=0, bini3=0, bini4=0, bini5=0, bini6=0, progress=0;
    double Il1, Il2, Il1c, Il2c, reflectance=1, index;

    ofstream file1("resolution.txt");
    ofstream file2("anamorphism.txt");
    ofstream file3("slit.txt");
    ofstream file4("nyquist.txt");
    ofstream file5("dispersion.txt");
    ofstream file6("atmosphere.txt");
    ofstream file7("telescope.txt");
    ofstream file8("ccd.txt");
    ofstream file9("echelle.txt");
    ofstream file10("grating.txt");
    ofstream file11("gratings.txt");
    ofstream file12("efficiency.txt");
    ofstream file13("overall.txt");
    ofstream file14("surfaces.txt");
    ofstream file15("twopixR.txt");

    if(al>0){
    ifstream input("protected_Al.txt");

    QFile checkfile1("protected_Al.txt");

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Error", "Reflection data of protected aluminium not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile1.size()==0){
        QMessageBox::information(this, "Error", "Reflection data of protected aluminium is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input, line))
       ++ bini;

    input.clear();
    input.seekg(0, ios::beg);

    ali.resize(bini);
    alw.resize(bini);

    for (int i =0; i < bini; i++){
    input >> eins >> zwei;
    istringstream istr(eins);
    istr >> ali[i];
    istringstream istr1(zwei);
    istr1 >> alw[i];
    }
    input.close();
}
    if(aluv>0){
    ifstream input2("UVEnhanced_Al.txt");

    QFile checkfile2("UVEnhanced_Al.txt");

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Reflection data of UV enhanced aluminium not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "Reflection data of UV enhanced aluminium is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input2, line))
       ++ bini2;

    input2.clear();
    input2.seekg(0, ios::beg);

    aluvi.resize(bini2);
    aluvw.resize(bini2);

    for (int i =0; i < bini2; i++){
    input2 >> eins >> zwei;
    istringstream istr2(eins);
    istr2 >> aluvw[i];
    istringstream istr3(zwei);
    istr3 >> aluvi[i];
    }
    input2.close();
}
    if(ag>0){
    ifstream input3("protected_Ag.txt");

    QFile checkfile3("protected_Ag.txt");

    if(!checkfile3.exists()){
        QMessageBox::information(this, "Error", "Reflection data of protected silver not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile3.size()==0){
        QMessageBox::information(this, "Error", "Reflection data of protected silver is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }


    while(std::getline(input3, line))
       ++ bini3;

    input3.clear();
    input3.seekg(0, ios::beg);

    agi.resize(bini3);
    agw.resize(bini3);

    for (int i =0; i < bini3; i++){
    input3 >> eins >> zwei;
    istringstream istr4(eins);
    istr4 >> agw[i];
    istringstream istr5(zwei);
    istr5 >> agi[i];
    }
    input3.close();
}

    if(au>0){
    ifstream input4("protected_Au.txt");

    QFile checkfile4("protected_Au.txt");

    if(!checkfile4.exists()){
        QMessageBox::information(this, "Error", "Reflection data of protected gold not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile4.size()==0){
        QMessageBox::information(this, "Error", "Reflection data of protected gold is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input4, line))
       ++ bini4;

    input4.clear();
    input4.seekg(0, ios::beg);

    aui.resize(bini4);
    auw.resize(bini4);

    for (int i =0; i < bini4; i++){
    input4 >> eins >> zwei;
    istringstream istr6(eins);
    istr6 >> auw[i];
    istringstream istr7(zwei);
    istr7 >> aui[i];
    }
    input4.close();
}

    if(bb>0){
    ifstream input5("vis_ar.txt");

    QFile checkfile5("vis_ar.txt");

    if(!checkfile5.exists()){
        QMessageBox::information(this, "Error", "Transmission data of VIS AR coating not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile5.size()==0){
        QMessageBox::information(this, "Error", "Transmission data of VIS AR coating is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input5, line))
       ++ bini5;

    input5.clear();
    input5.seekg(0, ios::beg);

    bbi.resize(bini5);
    bbw.resize(bini5);

    for (int i =0; i < bini5; i++){
    input5 >> eins >> zwei;
    istringstream istr8(eins);
    istr8 >> bbw[i];
    istringstream istr9(zwei);
    istr9 >> bbi[i];
    }
    input5.close();
}

    if(ui->checkBox_11->isChecked()){

        QString in16=ui->lineEdit->text();
        string in6 = in16.toUtf8().constData();
        std::ostringstream in6NameStream(in6);
        std::string in6Name = in6NameStream.str();
        ifstream input6(in6Name.c_str());


        QFile checkfile6(in6Name.c_str());

        if(!checkfile6.exists()){
            QMessageBox::information(this, "Error", "Transmission file not available!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        if(checkfile6.size()==0){
            QMessageBox::information(this, "Error", "Transmission file is empty.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        while(std::getline(input6, line))
           ++ bini6;

        input6.clear();
        input6.seekg(0, ios::beg);

        cti.resize(bini6);
        ctw.resize(bini6);

        for (int i =0; i < bini6; i++){
        input6 >> eins >> zwei;
        istringstream istr8(eins);
        istr8 >> ctw[i];
        istringstream istr9(zwei);
        istr9 >> cti[i];
        }
        input6.close();
    }

    // grating CD
    if(ui->comboBox_2->currentIndex()==0){

        bm = atan((lx/2)*p/f2)*180/M_PI;

        for(int i=0; i<nl-nh; i++){
            n[i]=nl-i;
            lw[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[i]*g);
            b1c[i] = asin(ncd*lw[i]*gc-sin(M_PI/180*acc))*180/M_PI;
            o[i] = -((ly-4*sdisc/p)-tan((b1c[i]-b1c[0])*M_PI/180)*f2/p);
            if(o[i]>0){
                ++counter;
            }
        }

        D.resize(lx/Bx);
        l11.resize(lx/Bx);
        R.resize(lx/Bx);
        A.resize(lx/Bx);
        s2.resize(lx/Bx);
        Nf.resize(lx/Bx);
        Tr.resize(lx/Bx);
        P.resize(lx/Bx);
        CCD.resize(lx/Bx);
        I1.resize(lx/Bx);
        I1c.resize(lx/Bx);
        btc.resize(lx/Bx);
        bt.resize(lx/Bx);
        b1.resize(lx/Bx);
        Ef.resize(lx/Bx);
        alt.resize(lx/Bx);
        aluvt.resize(lx/Bx);
        agt.resize(lx/Bx);
        aut.resize(lx/Bx);
        bbt.resize(lx/Bx);
        ctit.resize(lx/Bx);
        b1c.resize(lx/Bx);

    QString Output;
    Output=QString::number(-o[nl-nh-1]);
    ui->lineEdit_37->setText(Output);

    for(int m=0; m<nl-nh; m++){

        average[m]=0;
        sign[m]=0;
        snr[m]=0;

        if(m>0){
            bm = atan((lx/2)*p/f2)*180/M_PI;
            l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

            overlap[m]=(l11[lx/Bx-1]-l11[0])*1000000;
            separation[m]=o[m]-o[m-1];
        }

        for(int i=0; i<lx/Bx; i++){
            bm = atan((lx/2-i)*p*Bx/f2)*180/M_PI;
            l11[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

            if(al>0){
            if(i==0){
                for (int n=0; n<bini; n++){
                    if((alw[n]>l11[i]*1000) &(alw[n+1]<l11[i]*1000)){
                        alt[i]=ali[n+1]+(l11[i]*1000-alw[n+1])/(alw[n]-alw[n+1])*(ali[n]-ali[n+1]);
                        aal=n;
                    }
                }
            }
            else{
                for(int n=aal-2; n<aal+3; n++){
                    if((alw[n]>l11[i]*1000) &(alw[n+1]<l11[i]*1000)){
                        alt[i]=ali[n+1]+(l11[i]*1000-alw[n+1])/(alw[n]-alw[n+1])*(ali[n]-ali[n+1]);
                        aal=n;
                    }
                }
            }
            alt[i]=pow(alt[i]/100,al);
            reflectance=reflectance*alt[i];
            }

            if(aluv>0){
            if(i==0){
                for (int n=0; n<bini2; n++){
                    if((aluvw[n]>l11[i]*1000) &(aluvw[n+1]<l11[i]*1000)){
                        aluvt[i]=aluvi[n+1]+(l11[i]*1000-aluvw[n+1])/(aluvw[n]-aluvw[n+1])*(aluvi[n]-aluvi[n+1]);
                        aaluv=n;
                    }
                }
            }
            else{
                for(int n=aaluv-2; n<aaluv+3; n++){
                    if((aluvw[n]>l11[i]*1000) &(aluvw[n+1]<l11[i]*1000)){
                        aluvt[i]=aluvi[n+1]+(l11[i]*1000-aluvw[n+1])/(aluvw[n]-aluvw[n+1])*(aluvi[n]-aluvi[n+1]);
                        aaluv=n;
                    }
                }
            }
            aluvt[i]=pow(aluvt[i]/100,aluv);
            reflectance=reflectance*aluvt[i];
            }

            if(ag>0){
            if(i==0){
                for (int n=0; n<bini3; n++){
                    if((agw[n]>l11[i]*1000) &(agw[n+1]<l11[i]*1000)){
                        agt[i]=agi[n+1]+(l11[i]*1000-agw[n+1])/(agw[n]-agw[n+1])*(agi[n]-agi[n+1]);
                        aag=n;
                    }
                }
            }
            else{
                for(int n=aag-2; n<aag+3; n++){
                    if((agw[n]>l11[i]*1000) &(agw[n+1]<l11[i]*1000)){
                        agt[i]=agi[n+1]+(l11[i]*1000-agw[n+1])/(agw[n]-agw[n+1])*(agi[n]-agi[n+1]);
                        aag=n;
                    }
                }
            }
            agt[i]=pow(agt[i]/100,ag);
            reflectance=reflectance*agt[i];
            }

            if(au>0){
            if(i==0){
                for (int n=0; n<bini4; n++){
                    if((auw[n]>l11[i]*1000) &(auw[n+1]<l11[i]*1000)){
                        aut[i]=aui[n+1]+(l11[i]*1000-auw[n+1])/(auw[n]-auw[n+1])*(aui[n]-aui[n+1]);
                        aau=n;
                    }
                }
            }
            else{
                for(int n=aau-2; n<aau+3; n++){
                    if((auw[n]>l11[i]*1000) &(auw[n+1]<l11[i]*1000)){
                        aut[i]=aui[n+1]+(l11[i]*1000-auw[n+1])/(auw[n]-auw[n+1])*(aui[n]-aui[n+1]);
                        aau=n;
                    }
                }
            }
            aut[i]=pow(aut[i]/100,au);
            reflectance=reflectance*aut[i];
            }

            if(bb>0){
            if(i==0){
                for (int n=0; n<bini5; n++){
                    if((bbw[n]<l11[i]*1000000) &(bbw[n+1]>l11[i]*1000000)){
                        bbt[i]=bbi[n]+(l11[i]*1000000-bbw[n])/(bbw[n+1]-bbw[n])*(bbi[n+1]-bbi[n]);
                        abb=n;
                    }
                }
            }
            else{
                for(int n=abb-2; n<abb+3; n++){
                    if((bbw[n]<l11[i]*1000000) &(bbw[n+1]>l11[i]*1000000)){
                        bbt[i]=bbi[n]+(l11[i]*1000000-bbw[n])/(bbw[n+1]-bbw[n])*(bbi[n+1]-bbi[n]);
                        abb=n;
                    }
                }
            }
            bbt[i]=pow((100-bbt[i])/100,bb);
            reflectance=reflectance*bbt[i];
            }

            b1c[i] = asin(ncd*l11[i]*gc-sin(M_PI/180*acc))*180/M_PI;
            btc[i] = sin(M_PI/180*(b1c[i]-thetac));

            b1[i] = asin(n[m]*l11[i]*g-sin(M_PI/180*a))*180/M_PI;
            bt[i] = sin(M_PI/180*(b1[i]-theta));

            R[i] = l11[i]*n[m]*f1*g/(cos(M_PI/180*a)*s);

            A[i] = cos(M_PI/180*a)/cos(M_PI/180*(b-bm));
            s2[i] = A[i] * f2/f1*s;
            Nf[i] = s2[i]/p/2;
            Tr[i] = 1-0.0091224/cos(M_PI/180*z)/(pow(l11[i]*1000,4));
            D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g);
            l11[i]=l11[i]*10000000;
            P[i] = Tr[i]*dtel*dtel/400*M_PI*ap/(l11[i]*l11[i]*l11[i]*l11[i])/(exp(k/T/l11[i])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
            CCD[i] = ap/(l11[i]*l11[i]*l11[i]*l11[i]*l11[i])/(exp(143877500/l11[i]/CCDT)-1)/CCDm*CCDp;
            l11[i]=l11[i]/10000000;

            Il1c = sin(M_PI*dc/l11[i]*(atc+btc[i]));
            Il2c = M_PI*dc/l11[i]*(atc+btc[i]);
            I1c[i] = etac*Il1c*Il1c/Il2c/Il2c;

            Il1 = sin(M_PI*d/l11[i]*(at+bt[i]));
            Il2 = M_PI*d/l11[i]*(at+bt[i]);
            I1[i] = eta*Il1*Il1/Il2/Il2;

            Ef[i]=I1[i]*I1c[i]*CCD[i]*slitEff*reflectance*Frenl;

                   file1<<l11[i]*1000000<<" "<<R[i]<<endl;
                   file2<<l11[i]*1000000<<" "<<A[i]<<endl;
                   file3<<l11[i]*1000000<<" "<<s2[i]<<endl;
                   file4<<l11[i]*1000000<<" "<<Nf[i]<<endl;
                   file5<<l11[i]*1000000<<" "<<D[i]*1000000<<endl;
                   file6<<l11[i]*1000000<<" "<<Tr[i]<<endl;
                   file7<<l11[i]*1000000<<" "<<P[i]<<endl;
                   file8<<l11[i]*1000000<<" "<<CCD[i]<<endl;
                   file9<<l11[i]*1000000<<" "<<I1[i]<<endl;
                   file10<<l11[i]*1000000<<" "<<I1c[i]<<endl;
                   file11<<l11[i]*1000000<<" "<<I1c[i]*I1[i]<<endl;
                   file12<<l11[i]*1000000<<" "<<Ef[i]<<endl;
                   Ef[i]=Ef[i]*Tr[i];
                   file13<<l11[i]*1000000<<" "<<Ef[i]<<endl;
                   file14<<l11[i]*1000000<<" "<<reflectance<<endl;
                   file15<<l11[i]*1000000<<" "<<l11[i]/2/D[i]<<endl;
                   reflectance=1;
        }
        for(int i=0; i<lx/Bx; i++){
            if((Ef[i]>=0)&(Tr[i]>=0)&(P[i]>=0)){
            average[m]+=Ef[i]*100/(lx/Bx)/Tr[i];
            sign[m]+=Ef[i]*P[i]*exptime/gain/(lx/Bx);
            }}
        snr[m]=sign[m]/(sqrt(sign[m]+lx/Bx*pow((readnoise),2)));
        ui->progressBar->setValue((m+1)*100/(nl-nh));
        qApp->processEvents(QEventLoop::AllEvents);
    }

    Output=QString::number(nh+counter);
    ui->lineEdit_34->setText(Output);

    bm= atan((lx/2)*p*Bx/f2)*180/M_PI;
    Output=QString::number((sin(M_PI/180*a)+sin(M_PI/180*(b+bm)))/(g*(nh+counter))*1000000);
    ui->lineEdit_35->setText(Output);

    double y11=overlap[0], y12=overlap[0];
    for(int i=0; i<nl-nh; i++){
        if(overlap[i]<y11){
            y11=overlap[i];
        }
        if(overlap[i]>y12){
            y12=overlap[i];
        }
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(n, overlap);
    ui->customPlot->xAxis->setLabel("Diffraction Order");
    ui->customPlot->yAxis->setLabel("Overlap [nm]");
    ui->customPlot->xAxis->setRange(nh, nl);
    ui->customPlot->yAxis->setRange(y11, y12);
    ui->customPlot->replot();

    ui->customPlot_2->addGraph();
    ui->customPlot_2->graph(0)->setData(n, separation);
    ui->customPlot_2->xAxis->setLabel("Diffraction Order");
    ui->customPlot_2->yAxis->setLabel("Separation [pix]");
    ui->customPlot_2->xAxis->setRange(nh, nl);
    ui->customPlot_2->yAxis->setRange(separation[nl-nh-1], separation[1]);
    ui->customPlot_2->replot();

    y11=average[0], y12=average[0];
    for(int i=0; i<nl-nh; i++){
        if(average[i]<y11){
            y11=average[i];
        }
        if(average[i]>y12){
            y12=average[i];
        }
    }

    ui->customPlot_3->addGraph();
    ui->customPlot_3->graph(0)->setData(n, average);
    ui->customPlot_3->xAxis->setLabel("Diffraction Order");
    ui->customPlot_3->yAxis->setLabel("Av. Efficiency [%]");
    ui->customPlot_3->xAxis->setRange(nh, nl);
    ui->customPlot_3->yAxis->setRange(y11, y12);
    ui->customPlot_3->replot();

    y11=sign[0];
    y12=sign[0];
    for(int i=0; i<nl-nh; i++){
        if(sign[i]<y11){
            y11=sign[i];
        }
        if(sign[i]>y12){
            y12=sign[i];
        }
    }

    ui->customPlot_4->addGraph();
    ui->customPlot_4->graph(0)->setData(n, sign);
    ui->customPlot_4->xAxis->setLabel("Diffraction Order");
    ui->customPlot_4->yAxis->setLabel("Av. Signal [ADU]");
    ui->customPlot_4->xAxis->setRange(nh, nl);
    ui->customPlot_4->yAxis->setRange(y11, y12);
    ui->customPlot_4->replot();

    y11=snr[0];
    y12=snr[0];
    for(int i=0; i<nl-nh; i++){
        if(snr[i]<y11){
            y11=snr[i];
        }
        if(snr[i]>y12){
            y12=snr[i];
        }
    }

    ui->customPlot_5->addGraph();
    ui->customPlot_5->graph(0)->setData(n, snr);
    ui->customPlot_5->xAxis->setLabel("Diffraction Order");
    ui->customPlot_5->yAxis->setLabel("Av. SNR [ADU]");
    ui->customPlot_5->xAxis->setRange(nh, nl);
    ui->customPlot_5->yAxis->setRange(y11, y12);
    ui->customPlot_5->replot();

    }

    // for prism
    if(e==0){

        b1c.resize(lx/Bx);
        l11.resize(lx/Bx);
        b1.resize(lx/Bx);
        bt.resize(lx/Bx);
        R.resize(lx/Bx);
        D.resize(lx/Bx);
        A.resize(lx/Bx);
        s2.resize(lx/Bx);
        Nf.resize(lx/Bx);
        Tr.resize(lx/Bx);
        P.resize(lx/Bx);
        CCD.resize(lx/Bx);
        I1.resize(lx/Bx);
        Ef.resize(lx/Bx);
        alt.resize(lx/Bx);
        aluvt.resize(lx/Bx);
        agt.resize(lx/Bx);
        aut.resize(lx/Bx);
        bbt.resize(lx/Bx);

        o[0] = -(ly-4*sdisc/p)/Bx;
        separation[0]=0;
        summe =o[0]+ly;
        bm = atan(lx/2*p/f2)*180/M_PI;
        l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g)*1000;
        double index=sqrt(1+B1*l11[0]*l11[0]/(l11[0]*l11[0]-C1)+B2*l11[0]*l11[0]/(l11[0]*l11[0]-C2)+B3*l11[0]*l11[0]/(l11[0]*l11[0]-C3));
        //b1c[0] = 2*asin(sqrt(1+B1*l11[0]*l11[0]/(l11[0]*l11[0]-C1)+B2*l11[0]*l11[0]/(l11[0]*l11[0]-C2)+B3*l11[0]*l11[0]/(l11[0]*l11[0]-C3))*sin(M_PI/180*30))*180/M_PI-60;
        lz=lz*1000;
        indexlz=sqrt(1+B1*lz*lz/(lz*lz-C1)+B2*lz*lz/(lz*lz-C2)+B3*lz*lz/(lz*lz-C3));
        lz=lz/1000;
        double einf=asin(indexlz*sin(M_PI/180*30))*180/M_PI;
        double startb= einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;

        for(int m=0; m<nl-nh; m++){

            average[m]=0;
            sign[m]=0;
            snr[m]=0;

            n[m]=nl-m;
            if(m>0){
               bm = atan(lx*p/2/f2)*180/M_PI;
               l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
               index=sqrt(1+B1*l11[m]*l11[m]/(l11[m]*l11[m]-C1)+B2*l11[m]*l11[m]/(l11[m]*l11[m]-C2)+B3*l11[m]*l11[m]/(l11[m]*l11[m]-C3));
               l11[m]=l11[m]/1000;
               b1c[m]=einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;
               gamma2=einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;
               o[m] = -((ly-4*sdisc/p)-tan((startb-b1c[m])*M_PI/180)*f2/p);
                //cout<<b1c[m]<<endl;
               summe+=o[m];
               if(o[m]>0){
                   ++counter;
               }

               overlap[m]=(l11[lx/Bx-1]-l11[m])*1000000;
               separation[0]=0;
               if(m>0){
               separation[m]=-o[m-1]+o[m];
               }
            }

            for(int i=0; i<lx/Bx; i++){

                bm = atan((lx/2-i)*p*Bx/f2)*180/M_PI;
                l11[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
                index=sqrt(1+B1*l11[i]*l11[i]/(l11[i]*l11[i]-C1)+B2*l11[i]*l11[i]/(l11[i]*l11[i]-C2)+B3*l11[i]*l11[i]/(l11[i]*l11[i]-C3));
                l11[i]=l11[i]/1000;

                if(al>0){
                if(i==0){
                    for (int n=0; n<bini; n++){
                        if((alw[n]>l11[i]*1000) &(alw[n+1]<l11[i]*1000)){
                            alt[i]=ali[n+1]+(l11[i]*1000-alw[n+1])/(alw[n]-alw[n+1])*(ali[n]-ali[n+1]);
                            aal=n;
                        }
                    }
                }
                else{
                    for(int n=aal-2; n<aal+3; n++){
                        if((alw[n]>l11[i]*1000) &(alw[n+1]<l11[i]*1000)){
                            alt[i]=ali[n+1]+(l11[i]*1000-alw[n+1])/(alw[n]-alw[n+1])*(ali[n]-ali[n+1]);
                            aal=n;
                        }
                    }
                }
                alt[i]=pow(alt[i]/100,al);
                reflectance=reflectance*alt[i];
                }

                if(aluv>0){
                if(i==0){
                    for (int n=0; n<bini2; n++){
                        if((aluvw[n]>l11[i]*1000) &(aluvw[n+1]<l11[i]*1000)){
                            aluvt[i]=aluvi[n+1]+(l11[i]*1000-aluvw[n+1])/(aluvw[n]-aluvw[n+1])*(aluvi[n]-aluvi[n+1]);
                            aaluv=n;
                        }
                    }
                }
                else{
                    for(int n=aaluv-2; n<aaluv+3; n++){
                        if((aluvw[n]>l11[i]*1000) &(aluvw[n+1]<l11[i]*1000)){
                            aluvt[i]=aluvi[n+1]+(l11[i]*1000-aluvw[n+1])/(aluvw[n]-aluvw[n+1])*(aluvi[n]-aluvi[n+1]);
                            aaluv=n;
                        }
                    }
                }
                aluvt[i]=pow(aluvt[i]/100,aluv);
                reflectance=reflectance*aluvt[i];
                }

                if(ag>0){
                if(i==0){
                    for (int n=0; n<bini3; n++){
                        if((agw[n]>l11[i]*1000) &(agw[n+1]<l11[i]*1000)){
                            agt[i]=agi[n+1]+(l11[i]*1000-agw[n+1])/(agw[n]-agw[n+1])*(agi[n]-agi[n+1]);
                            aag=n;
                        }
                    }
                }
                else{
                    for(int n=aag-2; n<aag+3; n++){
                        if((agw[n]>l11[i]*1000) &(agw[n+1]<l11[i]*1000)){
                            agt[i]=agi[n+1]+(l11[i]*1000-agw[n+1])/(agw[n]-agw[n+1])*(agi[n]-agi[n+1]);
                            aag=n;
                        }
                    }
                }
                agt[i]=pow(agt[i]/100,ag);
                reflectance=reflectance*agt[i];
                }

                if(au>0){
                if(i==0){
                    for (int n=0; n<bini4; n++){
                        if((auw[n]>l11[i]*1000) &(auw[n+1]<l11[i]*1000)){
                            aut[i]=aui[n+1]+(l11[i]*1000-auw[n+1])/(auw[n]-auw[n+1])*(aui[n]-aui[n+1]);
                            aau=n;
                        }
                    }
                }
                else{
                    for(int n=aau-2; n<aau+3; n++){
                        if((auw[n]>l11[i]*1000) &(auw[n+1]<l11[i]*1000)){
                            aut[i]=aui[n+1]+(l11[i]*1000-auw[n+1])/(auw[n]-auw[n+1])*(aui[n]-aui[n+1]);
                            aau=n;
                        }
                    }
                }
                aut[i]=pow(aut[i]/100,au);
                reflectance=reflectance*aut[i];
                }

                if(bb>0){
                if(i==0){
                    for (int n=0; n<bini5; n++){
                        if((bbw[n]<l11[i]*1000000) &(bbw[n+1]>l11[i]*1000000)){
                            bbt[i]=bbi[n]+(l11[i]*1000000-bbw[n])/(bbw[n+1]-bbw[n])*(bbi[n+1]-bbi[n]);
                            abb=n;
                        }
                    }
                }
                else{
                    for(int n=abb-2; n<abb+3; n++){
                        if((bbw[n]<l11[i]*1000000) &(bbw[n+1]>l11[i]*1000000)){
                            bbt[i]=bbi[n]+(l11[i]*1000000-bbw[n])/(bbw[n+1]-bbw[n])*(bbi[n+1]-bbi[n]);
                            abb=n;
                        }
                    }
                }
                bbt[i]=pow((100-bbt[i])/100,bb);
                reflectance=reflectance*bbt[i];
                }

                b1[i] = asin(n[m]*l11[i]*g-sin(M_PI/180*a))*180/M_PI;
                bt[i] = sin(M_PI/180*(b1[i]-theta));

                R[i] = l11[i]*n[m]*f1*g/(cos(M_PI/180*a)*s);
                D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g);
                A[i] = cos(M_PI/180*a)/cos(M_PI/180*(b-bm));
                s2[i] = A[i] * f2/f1*s;
                Nf[i] = s2[i]/p/2;
                Tr[i] = 1-0.0091224/cos(M_PI/180*z)/(pow(l11[i]*1000,4));
                l11[i]=l11[i]*10000000;
                P[i] = Tr[i]*dtel*dtel/400*M_PI*ap/(l11[i]*l11[i]*l11[i]*l11[i])/(exp(k/T/l11[i])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                CCD[i] = ap/(l11[i]*l11[i]*l11[i]*l11[i]*l11[i])/(exp(143877500/l11[i]/CCDT)-1)/CCDm*CCDp;
                l11[i]=l11[i]/10000000;

                Il1 = sin(M_PI*d/l11[i]*(at+bt[i]));
                Il2 = M_PI*d/l11[i]*(at+bt[i]);
                I1[i] = eta*Il1*Il1/Il2/Il2;

                Ef[i]=I1[i]*CCD[i]*slitEff*reflectance*Frenl;


                file1<<l11[i]*1000000<<" "<<R[i]<<endl;
                file2<<l11[i]*1000000<<" "<<A[i]<<endl;
                file3<<l11[i]*1000000<<" "<<s2[i]<<endl;
                file4<<l11[i]*1000000<<" "<<Nf[i]<<endl;
                file5<<l11[i]*1000000<<" "<<D[i]*1000000<<endl;
                file6<<l11[i]*1000000<<" "<<Tr[i]<<endl;
                file7<<l11[i]*1000000<<" "<<P[i]<<endl;
                file8<<l11[i]*1000000<<" "<<CCD[i]<<endl;
                file9<<l11[i]*1000000<<" "<<I1[i]<<endl;
                file10<<l11[i]*1000000<<" "<<"1"<<endl;
                file11<<l11[i]*1000000<<" "<<I1[i]<<endl;
                file12<<l11[i]*1000000<<" "<<Ef[i]<<endl;
                Ef[i]=Ef[i]*Tr[i];
                file13<<l11[i]*1000000<<" "<<Ef[i]<<endl;
                file14<<l11[i]*1000000<<" "<<reflectance<<endl;
                file15<<l11[i]*1000000<<" "<<l11[i]/2/D[i]<<endl;
                reflectance=1;
            }
            for(int i=0; i<lx/Bx; i++){
                if((Ef[i]>=0)&(Tr[i]>=0)&(P[i]>=0)){
                average[m]+=Ef[i]*100/(lx/Bx)/Tr[i];
                sign[m]+=Ef[i]*P[i]*exptime/gain/(lx/Bx);
                }}
            snr[m]=sign[m]/(sqrt(sign[m]+lx/Bx*pow((readnoise),2)));
            ui->progressBar->setValue((m+1)*100/(nl-nh));
            qApp->processEvents(QEventLoop::AllEvents);
        }

        QString Output;
        Output=QString::number(o[nl-nh-1]);
        ui->lineEdit_37->setText(Output);

        Output=QString::number(nh+counter);
        ui->lineEdit_34->setText(Output);

        bm= atan((lx/2)*p*Bx/f2)*180/M_PI;
        Output=QString::number((sin(M_PI/180*a)+sin(M_PI/180*(b+bm)))/(g*(nh+counter))*1000000);
        ui->lineEdit_35->setText(Output);

        double y11=overlap[0], y12=overlap[0];
        for(int i=0; i<nl-nh; i++){
            if(overlap[i]<y11){
                y11=overlap[i];
            }
            if(overlap[i]>y12){
                y12=overlap[i];
            }
        }


        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(n, overlap);
        ui->customPlot->xAxis->setLabel("Diffraction Order");
        ui->customPlot->yAxis->setLabel("Overlap [nm]");
        ui->customPlot->xAxis->setRange(nh, nl);
        ui->customPlot->yAxis->setRange(y11, y12);
        ui->customPlot->replot();

        ui->customPlot_2->addGraph();
        ui->customPlot_2->graph(0)->setData(n, separation);
        ui->customPlot_2->xAxis->setLabel("Diffraction Order");
        ui->customPlot_2->yAxis->setLabel("Separation [pix]");
        ui->customPlot_2->xAxis->setRange(nh, nl);
        ui->customPlot_2->yAxis->setRange(separation[nl-nh-1], separation[1]);
        ui->customPlot_2->replot();

        y11=average[0];
        y12=average[0];
        for(int i=0; i<nl-nh; i++){
            if(average[i]<y11){
                y11=average[i];
            }
            if(average[i]>y12){
                y12=average[i];
            }
        }

        ui->customPlot_3->addGraph();
        ui->customPlot_3->graph(0)->setData(n, average);
        ui->customPlot_3->xAxis->setLabel("Diffraction Order");
        ui->customPlot_3->yAxis->setLabel("Av. Efficiency [%]");
        ui->customPlot_3->xAxis->setRange(nh, nl);
        ui->customPlot_3->yAxis->setRange(y11, y12);
        ui->customPlot_3->replot();

        y11=sign[0];
        y12=sign[0];
        for(int i=0; i<nl-nh; i++){
            if(sign[i]<y11){
                y11=sign[i];
            }
            if(sign[i]>y12){
                y12=sign[i];
            }
        }

        ui->customPlot_4->addGraph();
        ui->customPlot_4->graph(0)->setData(n, sign);
        ui->customPlot_4->xAxis->setLabel("Diffraction Order");
        ui->customPlot_4->yAxis->setLabel("Av. Signal [ADU]");
        ui->customPlot_4->xAxis->setRange(nh, nl);
        ui->customPlot_4->yAxis->setRange(y11, y12);
        ui->customPlot_4->replot();

        y11=snr[0];
        y12=snr[0];
        for(int i=0; i<nl-nh; i++){
            if(snr[i]<y11){
                y11=snr[i];
            }
            if(snr[i]>y12){
                y12=snr[i];
            }
        }

        ui->customPlot_5->addGraph();
        ui->customPlot_5->graph(0)->setData(n, snr);
        ui->customPlot_5->xAxis->setLabel("Diffraction Order");
        ui->customPlot_5->yAxis->setLabel("Av. SNR [ADU]");
        ui->customPlot_5->xAxis->setRange(nh, nl);
        ui->customPlot_5->yAxis->setRange(y11, y12);
        ui->customPlot_5->replot();
    }

    // for VPH Grating
    if(e==2){

        double alpha_2b, eta_s, eta_p;

        b1c.resize(lx/Bx);
        l11.resize(lx/Bx);
        b1.resize(lx/Bx);
        bt.resize(lx/Bx);
        R.resize(lx/Bx);
        D.resize(lx/Bx);
        A.resize(lx/Bx);
        s2.resize(lx/Bx);
        Nf.resize(lx/Bx);
        Tr.resize(lx/Bx);
        P.resize(lx/Bx);
        CCD.resize(lx/Bx);
        I1.resize(lx/Bx);
        Ef.resize(lx/Bx);
        alt.resize(lx/Bx);
        aluvt.resize(lx/Bx);
        agt.resize(lx/Bx);
        aut.resize(lx/Bx);
        bbt.resize(lx/Bx);

        lz=lz*1000;
        indexlz=sqrt(1+B1*lz*lz/(lz*lz-C1)+B2*lz*lz/(lz*lz-C2)+B3*lz*lz/(lz*lz-C3));
        lz=lz/1000;

        bm = atan(lx/2*p/f2)*180/M_PI;
        alpha_2b=asin(ncd*tDCG/1000000/nDCG/2*gc)*180/M_PI;

        for(int i=0; i<nl-nh; i++){
            n[i]=nl-i;
            lw[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[i]*g);
            b1c[i] = asin(ncd*lw[i]*gc-sin(M_PI/180*acc))*180/M_PI;
            o[i] = -((ly-4*sdisc/p)-tan((b1c[i]-b1c[0])*M_PI/180)*f2/p);
            if(o[i]>0){
                ++counter;
            }

        }

        for(int m=0; m<nl-nh; m++){

            average[m]=0;
            sign[m]=0;
            snr[m]=0;

            n[m]=nl-m;
            if(m>0){
            bm = atan((lx/2)*p/f2)*180/M_PI;
            l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

            overlap[m]=(l11[lx/Bx-1]-l11[0])*1000000;
            separation[m]=o[m]-o[m-1];
            }

        for(int i=0; i<lx/Bx; i++){
            bm = atan((lx/2-i)*p*Bx/f2)*180/M_PI;
            l11[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

            if(al>0){
            if(i==0){
                for (int n=0; n<bini; n++){
                    if((alw[n]>l11[i]*1000) &(alw[n+1]<l11[i]*1000)){
                        alt[i]=ali[n+1]+(l11[i]*1000-alw[n+1])/(alw[n]-alw[n+1])*(ali[n]-ali[n+1]);
                        aal=n;
                    }
                }
            }
            else{
                for(int n=aal-2; n<aal+3; n++){
                    if((alw[n]>l11[i]*1000) &(alw[n+1]<l11[i]*1000)){
                        alt[i]=ali[n+1]+(l11[i]*1000-alw[n+1])/(alw[n]-alw[n+1])*(ali[n]-ali[n+1]);
                        aal=n;
                    }
                }
            }
            alt[i]=pow(alt[i]/100,al);
            reflectance=reflectance*alt[i];
            }

            if(aluv>0){
            if(i==0){
                for (int n=0; n<bini2; n++){
                    if((aluvw[n]>l11[i]*1000) &(aluvw[n+1]<l11[i]*1000)){
                        aluvt[i]=aluvi[n+1]+(l11[i]*1000-aluvw[n+1])/(aluvw[n]-aluvw[n+1])*(aluvi[n]-aluvi[n+1]);
                        aaluv=n;
                    }
                }
            }
            else{
                for(int n=aaluv-2; n<aaluv+3; n++){
                    if((aluvw[n]>l11[i]*1000) &(aluvw[n+1]<l11[i]*1000)){
                        aluvt[i]=aluvi[n+1]+(l11[i]*1000-aluvw[n+1])/(aluvw[n]-aluvw[n+1])*(aluvi[n]-aluvi[n+1]);
                        aaluv=n;
                    }
                }
            }
            aluvt[i]=pow(aluvt[i]/100,aluv);
            reflectance=reflectance*aluvt[i];
            }

            if(ag>0){
            if(i==0){
                for (int n=0; n<bini3; n++){
                    if((agw[n]>l11[i]*1000) &(agw[n+1]<l11[i]*1000)){
                        agt[i]=agi[n+1]+(l11[i]*1000-agw[n+1])/(agw[n]-agw[n+1])*(agi[n]-agi[n+1]);
                        aag=n;
                    }
                }
            }
            else{
                for(int n=aag-2; n<aag+3; n++){
                    if((agw[n]>l11[i]*1000) &(agw[n+1]<l11[i]*1000)){
                        agt[i]=agi[n+1]+(l11[i]*1000-agw[n+1])/(agw[n]-agw[n+1])*(agi[n]-agi[n+1]);
                        aag=n;
                    }
                }
            }
            agt[i]=pow(agt[i]/100,ag);
            reflectance=reflectance*agt[i];
            }

            if(au>0){
            if(i==0){
                for (int n=0; n<bini4; n++){
                    if((auw[n]>l11[i]*1000) &(auw[n+1]<l11[i]*1000)){
                        aut[i]=aui[n+1]+(l11[i]*1000-auw[n+1])/(auw[n]-auw[n+1])*(aui[n]-aui[n+1]);
                        aau=n;
                    }
                }
            }
            else{
                for(int n=aau-2; n<aau+3; n++){
                    if((auw[n]>l11[i]*1000) &(auw[n+1]<l11[i]*1000)){
                        aut[i]=aui[n+1]+(l11[i]*1000-auw[n+1])/(auw[n]-auw[n+1])*(aui[n]-aui[n+1]);
                        aau=n;
                    }
                }
            }
            aut[i]=pow(aut[i]/100,au);
            reflectance=reflectance*aut[i];
            }

            if(bb>0){
            if(i==0){
                for (int n=0; n<bini5; n++){
                    if((bbw[n]<l11[i]*1000000) &(bbw[n+1]>l11[i]*1000000)){
                        bbt[i]=bbi[n]+(l11[i]*1000000-bbw[n])/(bbw[n+1]-bbw[n])*(bbi[n+1]-bbi[n]);
                        abb=n;
                    }
                }
            }
            else{
                for(int n=abb-2; n<abb+3; n++){
                    if((bbw[n]<l11[i]*1000000) &(bbw[n+1]>l11[i]*1000000)){
                        bbt[i]=bbi[n]+(l11[i]*1000000-bbw[n])/(bbw[n+1]-bbw[n])*(bbi[n+1]-bbi[n]);
                        abb=n;
                    }
                }
            }
            bbt[i]=pow((100-bbt[i])/100,bb);
            reflectance=reflectance*bbt[i];
            }

            b1[i] = asin(n[m]*l11[i]*g-sin(M_PI/180*a))*180/M_PI;
            bt[i] = sin(M_PI/180*(b1[i]-theta));

            R[i] = l11[i]*n[m]*f1*g/(cos(M_PI/180*a)*s);

            A[i] = cos(M_PI/180*a)/cos(M_PI/180*(b-bm));
            s2[i] = A[i] * f2/f1*s;
            Nf[i] = s2[i]/p/2;
            Tr[i] = 1-0.0091224/cos(M_PI/180*z)/(pow(l11[i]*1000,4));
            D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g);
            l11[i]=l11[i]*10000000;
            P[i] = Tr[i]*dtel*dtel/400*M_PI*ap/(l11[i]*l11[i]*l11[i]*l11[i])/(exp(k/T/l11[i])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
            CCD[i] = ap/(l11[i]*l11[i]*l11[i]*l11[i]*l11[i])/(exp(143877500/l11[i]/CCDT)-1)/CCDm*CCDp;
            l11[i]=l11[i]/10000000;

            Il1 = sin(M_PI*d/l11[i]*(at+bt[i]));
            Il2 = M_PI*d/l11[i]*(at+bt[i]);
            I1[i] = eta*Il1*Il1/Il2/Il2;

            eta_s=pow(sin(M_PI*dnDCG*dDCG/l11[i]/cos(alpha_2b*M_PI/180)),2);
            eta_p=pow(sin(M_PI*dnDCG*dDCG*cos(M_PI/180*2*alpha_2b)/l11[i]/cos(alpha_2b*M_PI/180)),2);

            Ef[i]=I1[i]*(eta_s+eta_p)/2*CCD[i]*slitEff*reflectance*Frenl;

                   file1<<l11[i]*1000000<<" "<<R[i]<<endl;
                   file2<<l11[i]*1000000<<" "<<A[i]<<endl;
                   file3<<l11[i]*1000000<<" "<<s2[i]<<endl;
                   file4<<l11[i]*1000000<<" "<<Nf[i]<<endl;
                   file5<<l11[i]*1000000<<" "<<D[i]*1000000<<endl;
                   file6<<l11[i]*1000000<<" "<<Tr[i]<<endl;
                   file7<<l11[i]*1000000<<" "<<P[i]<<endl;
                   file8<<l11[i]*1000000<<" "<<CCD[i]<<endl;
                   file9<<l11[i]*1000000<<" "<<I1[i]<<endl;
                   file10<<l11[i]*1000000<<" "<<(eta_s+eta_p)/2<<endl;
                   file11<<l11[i]*1000000<<" "<<(eta_s+eta_p)/2*I1[i]<<endl;
                   file12<<l11[i]*1000000<<" "<<Ef[i]<<endl;
                   Ef[i]=Ef[i]*Tr[i];
                   file13<<l11[i]*1000000<<" "<<Ef[i]<<endl;
                   file14<<l11[i]*1000000<<" "<<reflectance<<endl;
                   file15<<l11[i]*1000000<<" "<<l11[i]/2/D[i]<<endl;
                   reflectance=1;
        }
        for(int i=0; i<lx/Bx; i++){
            if((Ef[i]>=0)&(Tr[i]>=0)&(P[i]>=0)){
            average[m]+=Ef[i]*100/(lx/Bx)/Tr[i];
            sign[m]+=Ef[i]*P[i]*exptime/gain/(lx/Bx);
            }}
        snr[m]=sign[m]/(sqrt(sign[m]+lx/Bx*pow(readnoise,2)));
        ui->progressBar->setValue((m+1)*100/(nl-nh));
        qApp->processEvents(QEventLoop::AllEvents);
    }

        QString Output;
        Output=QString::number(-o[nl-nh-1]);
        ui->lineEdit_37->setText(Output);

        Output=QString::number(nh+counter);
        ui->lineEdit_34->setText(Output);

        bm= atan((lx/2)*p*Bx/f2)*180/M_PI;
        Output=QString::number((sin(M_PI/180*a)+sin(M_PI/180*(b+bm)))/(g*(nh+counter))*1000000);
        ui->lineEdit_35->setText(Output);

        double y11=overlap[0], y12=overlap[0];
        for(int i=0; i<nl-nh; i++){
            if(overlap[i]<y11){
                y11=overlap[i];
            }
            if(overlap[i]>y12){
                y12=overlap[i];
            }
        }

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(n, overlap);
        ui->customPlot->xAxis->setLabel("Diffraction Order");
        ui->customPlot->yAxis->setLabel("Overlap [nm]");
        ui->customPlot->xAxis->setRange(nh, nl);
        ui->customPlot->yAxis->setRange(y11, y12);
        ui->customPlot->replot();

        ui->customPlot_2->addGraph();
        ui->customPlot_2->graph(0)->setData(n, separation);
        ui->customPlot_2->xAxis->setLabel("Diffraction Order");
        ui->customPlot_2->yAxis->setLabel("Separation [pix]");
        ui->customPlot_2->xAxis->setRange(nh, nl);
        ui->customPlot_2->yAxis->setRange(separation[nl-nh-1], separation[1]);
        ui->customPlot_2->replot();

        y11=average[0], y12=average[0];
        for(int i=0; i<nl-nh; i++){
            if(average[i]<y11){
                y11=average[i];
            }
            if(average[i]>y12){
                y12=average[i];
            }
        }

        ui->customPlot_3->addGraph();
        ui->customPlot_3->graph(0)->setData(n, average);
        ui->customPlot_3->xAxis->setLabel("Diffraction Order");
        ui->customPlot_3->yAxis->setLabel("Av. Efficiency [%]");
        ui->customPlot_3->xAxis->setRange(nh, nl);
        ui->customPlot_3->yAxis->setRange(y11, y12);
        ui->customPlot_3->replot();

        y11=sign[0];
        y12=sign[0];
        for(int i=0; i<nl-nh; i++){
            if(sign[i]<y11){
                y11=sign[i];
            }
            if(sign[i]>y12){
                y12=sign[i];
            }
        }

        ui->customPlot_4->addGraph();
        ui->customPlot_4->graph(0)->setData(n, sign);
        ui->customPlot_4->xAxis->setLabel("Diffraction Order");
        ui->customPlot_4->yAxis->setLabel("Av. Signal [ADU]");
        ui->customPlot_4->xAxis->setRange(nh, nl);
        ui->customPlot_4->yAxis->setRange(y11, y12);
        ui->customPlot_4->replot();

        y11=snr[0];
        y12=snr[0];
        for(int i=0; i<nl-nh; i++){
            if(snr[i]<y11){
                y11=snr[i];
            }
            if(snr[i]>y12){
                y12=snr[i];
            }
        }

        ui->customPlot_5->addGraph();
        ui->customPlot_5->graph(0)->setData(n, snr);
        ui->customPlot_5->xAxis->setLabel("Diffraction Order");
        ui->customPlot_5->yAxis->setLabel("Av. SNR [ADU]");
        ui->customPlot_5->xAxis->setRange(nh, nl);
        ui->customPlot_5->yAxis->setRange(y11, y12);
        ui->customPlot_5->replot();
    }

    // for VPH Grism
    if(e==3){

        b1c.resize(lx/Bx);
        l11.resize(lx/Bx);
        b1.resize(lx/Bx);
        bt.resize(lx/Bx);
        R.resize(lx/Bx);
        D.resize(lx/Bx);
        A.resize(lx/Bx);
        s2.resize(lx/Bx);
        Nf.resize(lx/Bx);
        Tr.resize(lx/Bx);
        P.resize(lx/Bx);
        CCD.resize(lx/Bx);
        I1.resize(lx/Bx);
        Ef.resize(lx/Bx);
        alt.resize(lx/Bx);
        aluvt.resize(lx/Bx);
        agt.resize(lx/Bx);
        aut.resize(lx/Bx);
        bbt.resize(lx/Bx);

        bm = atan(lx/2*p/f2)*180/M_PI;
        lz=lz*1000;
        indexlz=sqrt(1+B1*lz*lz/(lz*lz-C1)+B2*lz*lz/(lz*lz-C2)+B3*lz*lz/(lz*lz-C3));
        lz=lz/1000;
        double theta1, difference, b11, b12, eta_s, eta_p, alpha_2b;

        // find theta2 of grism prisms
        for(int i=0; i<900; i++){
            theta1=0.1*i;
            difference=(theta1-(asin(ncd*lz*gc/2/indexlz)+asin(sin(theta1*M_PI/180)/indexlz))*180/M_PI);
            if(difference>=0){
                theta2=theta1;
                i=900;
            }
        }

        ui->doubleSpinBox_36->setValue(theta2);

        alpha_2b=asin(ncd*lz/indexlz/2*g)*180/M_PI;

        for(int m=0; m<nl-nh; m++){

            average[m]=0;
            sign[m]=0;
            snr[m]=0;

            n[m]=nl-m;
            bm = atan((lx/2)*p/f2)*180/M_PI;
            lw[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
            index=sqrt(1+B1*lw[m]*lw[m]/(lw[m]*lw[m]-C1)+B2*lw[m]*lw[m]/(lw[m]*lw[m]-C2)+B3*lw[m]*lw[m]/(lw[m]*lw[m]-C3));
            lw[m]=lw[m]/1000;

            b11=asin(sin(theta2*M_PI/180/index))*180/M_PI;
            b12=asin(lw[m]*gc/index*ncd-sin(theta2*M_PI/180-b11*M_PI/180))*180/M_PI;

            b1c[m]=asin(index*sin(theta2*M_PI/180-b12*M_PI/180))*180/M_PI;
            o[m] = -((ly-4*sdisc/p)-tan((b1c[0]-b1c[m])*M_PI/180)*f2/p);
            if(m>0){
            separation[m]=o[m]-o[m-1];
            overlap[m]=(l11[lx/Bx-1]-lw[m])*1000000;
            }
            if(o[m]>0){
                ++counter;
            }

            for(int i=0; i<lx/Bx; i++){

                bm = atan((lx/2-i*Bx)*p/f2)*180/M_PI;
                l11[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

                if(al>0){
                if(i==0){
                    for (int n=0; n<bini; n++){
                        if((alw[n]>l11[i]*1000) &(alw[n+1]<l11[i]*1000)){
                            alt[i]=ali[n+1]+(l11[i]*1000-alw[n+1])/(alw[n]-alw[n+1])*(ali[n]-ali[n+1]);
                            aal=n;
                        }
                    }
                }
                else{
                    for(int n=aal-2; n<aal+3; n++){
                        if((alw[n]>l11[i]*1000) &(alw[n+1]<l11[i]*1000)){
                            alt[i]=ali[n+1]+(l11[i]*1000-alw[n+1])/(alw[n]-alw[n+1])*(ali[n]-ali[n+1]);
                            aal=n;
                        }
                    }
                }
                alt[i]=pow(alt[i]/100,al);
                reflectance=reflectance*alt[i];
                }

                if(aluv>0){
                if(i==0){
                    for (int n=0; n<bini2; n++){
                        if((aluvw[n]>l11[i]*1000) &(aluvw[n+1]<l11[i]*1000)){
                            aluvt[i]=aluvi[n+1]+(l11[i]*1000-aluvw[n+1])/(aluvw[n]-aluvw[n+1])*(aluvi[n]-aluvi[n+1]);
                            aaluv=n;
                        }
                    }
                }
                else{
                    for(int n=aaluv-2; n<aaluv+3; n++){
                        if((aluvw[n]>l11[i]*1000) &(aluvw[n+1]<l11[i]*1000)){
                            aluvt[i]=aluvi[n+1]+(l11[i]*1000-aluvw[n+1])/(aluvw[n]-aluvw[n+1])*(aluvi[n]-aluvi[n+1]);
                            aaluv=n;
                        }
                    }
                }
                aluvt[i]=pow(aluvt[i]/100,aluv);
                reflectance=reflectance*aluvt[i];
                }

                if(ag>0){
                if(i==0){
                    for (int n=0; n<bini3; n++){
                        if((agw[n]>l11[i]*1000) &(agw[n+1]<l11[i]*1000)){
                            agt[i]=agi[n+1]+(l11[i]*1000-agw[n+1])/(agw[n]-agw[n+1])*(agi[n]-agi[n+1]);
                            aag=n;
                        }
                    }
                }
                else{
                    for(int n=aag-2; n<aag+3; n++){
                        if((agw[n]>l11[i]*1000) &(agw[n+1]<l11[i]*1000)){
                            agt[i]=agi[n+1]+(l11[i]*1000-agw[n+1])/(agw[n]-agw[n+1])*(agi[n]-agi[n+1]);
                            aag=n;
                        }
                    }
                }
                agt[i]=pow(agt[i]/100,ag);
                reflectance=reflectance*agt[i];
                }

                if(au>0){
                if(i==0){
                    for (int n=0; n<bini4; n++){
                        if((auw[n]>l11[i]*1000) &(auw[n+1]<l11[i]*1000)){
                            aut[i]=aui[n+1]+(l11[i]*1000-auw[n+1])/(auw[n]-auw[n+1])*(aui[n]-aui[n+1]);
                            aau=n;
                        }
                    }
                }
                else{
                    for(int n=aau-2; n<aau+3; n++){
                        if((auw[n]>l11[i]*1000) &(auw[n+1]<l11[i]*1000)){
                            aut[i]=aui[n+1]+(l11[i]*1000-auw[n+1])/(auw[n]-auw[n+1])*(aui[n]-aui[n+1]);
                            aau=n;
                        }
                    }
                }
                aut[i]=pow(aut[i]/100,au);
                reflectance=reflectance*aut[i];
                }

                if(bb>0){
                if(i==0){
                    for (int n=0; n<bini5; n++){
                        if((bbw[n]<l11[i]*1000000) &(bbw[n+1]>l11[i]*1000000)){
                            bbt[i]=bbi[n]+(l11[i]*1000000-bbw[n])/(bbw[n+1]-bbw[n])*(bbi[n+1]-bbi[n]);
                            abb=n;
                        }
                    }
                }
                else{
                    for(int n=abb-2; n<abb+3; n++){
                        if((bbw[n]<l11[i]*1000000) &(bbw[n+1]>l11[i]*1000000)){
                            bbt[i]=bbi[n]+(l11[i]*1000000-bbw[n])/(bbw[n+1]-bbw[n])*(bbi[n+1]-bbi[n]);
                            abb=n;
                        }
                    }
                }
                bbt[i]=pow((100-bbt[i])/100,bb);
                reflectance=reflectance*bbt[i];
                }

                b1[i] = asin(n[m]*l11[i]*g-sin(M_PI/180*a))*180/M_PI;
                bt[i] = sin(M_PI/180*(b1[i]-theta));

                R[i] = l11[i]*n[m]*f1*g/(cos(M_PI/180*a)*s);
                D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g);
                A[i] = cos(M_PI/180*a)/cos(M_PI/180*(b-bm));
                s2[i] = A[i] * f2/f1*s;
                Nf[i] = s2[i]/p/2;
                Tr[i] = 1-0.0091224/cos(M_PI/180*z)/(pow(l11[i]*1000,4));
                l11[i]=l11[i]*10000000;
                P[i] = Tr[i]*dtel*dtel/400*M_PI*ap/(l11[i]*l11[i]*l11[i]*l11[i])/(exp(k/T/l11[i])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                CCD[i] = ap/(l11[i]*l11[i]*l11[i]*l11[i]*l11[i])/(exp(143877500/l11[i]/CCDT)-1)/CCDm*CCDp;
                l11[i]=l11[i]/10000000;

                Il1 = sin(M_PI*d/l11[i]*(at+bt[i]));
                Il2 = M_PI*d/l11[i]*(at+bt[i]);
                I1[i] = eta*Il1*Il1/Il2/Il2;

                eta_s=pow(sin(M_PI*dnDCG*dDCG/l11[i]/cos(alpha_2b*M_PI/180)),2);
                eta_p=pow(sin(M_PI*dnDCG*dDCG*cos(M_PI/180*2*alpha_2b)/l11[i]/cos(alpha_2b*M_PI/180)),2);

                Ef[i]=I1[i]*CCD[i]*slitEff*reflectance*Frenl*(eta_s+eta_p)/2;

                file1<<l11[i]*1000000<<" "<<R[i]<<endl;
                file2<<l11[i]*1000000<<" "<<A[i]<<endl;
                file3<<l11[i]*1000000<<" "<<s2[i]<<endl;
                file4<<l11[i]*1000000<<" "<<Nf[i]<<endl;
                file5<<l11[i]*1000000<<" "<<D[i]*1000000<<endl;
                file6<<l11[i]*1000000<<" "<<Tr[i]<<endl;
                file7<<l11[i]*1000000<<" "<<P[i]<<endl;
                file8<<l11[i]*1000000<<" "<<CCD[i]<<endl;
                file9<<l11[i]*1000000<<" "<<I1[i]<<endl;
                file10<<l11[i]*1000000<<" "<<(eta_s+eta_p)/2<<endl;
                file11<<l11[i]*1000000<<" "<<I1[i]*(eta_s+eta_p)/2<<endl;
                file12<<l11[i]*1000000<<" "<<Ef[i]<<endl;
                Ef[i]=Ef[i]*Tr[i];
                file13<<l11[i]*1000000<<" "<<Ef[i]<<endl;
                file14<<l11[i]*1000000<<" "<<reflectance<<endl;
                file15<<l11[i]*1000000<<" "<<l11[i]/2/D[i]<<endl;
                reflectance=1;
            }
            for(int i=0; i<lx/Bx; i++){
                if((Ef[i]>=0)&(Tr[i]>=0)&(P[i]>=0)){
                average[m]+=Ef[i]*100/(lx/Bx)/Tr[i];
                sign[m]+=Ef[i]*P[i]*exptime/gain/(lx/Bx);
                }}
            snr[m]=sign[m]/(sqrt(sign[m]+lx/Bx*pow(readnoise,2)));
            ui->progressBar->setValue((m+1)*100/(nl-nh));
            qApp->processEvents(QEventLoop::AllEvents);
        }

    QString Output;
    Output=QString::number(-o[nl-nh-1]);
    ui->lineEdit_37->setText(Output);

    Output=QString::number(nh+counter);
    ui->lineEdit_34->setText(Output);

    bm= atan((lx/2)*p*Bx/f2)*180/M_PI;
    Output=QString::number((sin(M_PI/180*a)+sin(M_PI/180*(b+bm)))/(g*(nh+counter))*1000000);
    ui->lineEdit_35->setText(Output);

    double y11=overlap[0], y12=overlap[0];
    for(int i=0; i<nl-nh; i++){
        if(overlap[i]<y11){
            y11=overlap[i];
        }
        if(overlap[i]>y12){
            y12=overlap[i];
        }
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(n, overlap);
    ui->customPlot->xAxis->setLabel("Diffraction Order");
    ui->customPlot->yAxis->setLabel("Overlap [nm]");
    ui->customPlot->xAxis->setRange(nh, nl);
    ui->customPlot->yAxis->setRange(y11, y12);
    ui->customPlot->replot();

    ui->customPlot_2->addGraph();
    ui->customPlot_2->graph(0)->setData(n, separation);
    ui->customPlot_2->xAxis->setLabel("Diffraction Order");
    ui->customPlot_2->yAxis->setLabel("Separation [pix]");
    ui->customPlot_2->xAxis->setRange(nh, nl);
    ui->customPlot_2->yAxis->setRange(separation[1], separation[nl-nh-1]);
    ui->customPlot_2->replot();

    y11=average[0], y12=average[0];
    for(int i=0; i<nl-nh; i++){
        if(average[i]<y11){
            y11=average[i];
        }
        if(average[i]>y12){
            y12=average[i];
        }
    }

    ui->customPlot_3->addGraph();
    ui->customPlot_3->graph(0)->setData(n, average);
    ui->customPlot_3->xAxis->setLabel("Diffraction Order");
    ui->customPlot_3->yAxis->setLabel("Av. Efficiency [%]");
    ui->customPlot_3->xAxis->setRange(nh, nl);
    ui->customPlot_3->yAxis->setRange(y11, y12);
    ui->customPlot_3->replot();

    y11=sign[0];
    y12=sign[0];
    for(int i=0; i<nl-nh; i++){
        if(sign[i]<y11){
            y11=sign[i];
        }
        if(sign[i]>y12){
            y12=sign[i];
        }
    }

    ui->customPlot_4->addGraph();
    ui->customPlot_4->graph(0)->setData(n, sign);
    ui->customPlot_4->xAxis->setLabel("Diffraction Order");
    ui->customPlot_4->yAxis->setLabel("Av. Signal [ADU]");
    ui->customPlot_4->xAxis->setRange(nh, nl);
    ui->customPlot_4->yAxis->setRange(y11, y12);
    ui->customPlot_4->replot();

    y11=snr[0];
    y12=snr[0];
    for(int i=0; i<nl-nh; i++){
        if(snr[i]<y11){
            y11=snr[i];
        }
        if(snr[i]>y12){
            y12=snr[i];
        }
    }

    ui->customPlot_5->addGraph();
    ui->customPlot_5->graph(0)->setData(n, snr);
    ui->customPlot_5->xAxis->setLabel("Diffraction Order");
    ui->customPlot_5->yAxis->setLabel("Av. SNR [ADU]");
    ui->customPlot_5->xAxis->setRange(nh, nl);
    ui->customPlot_5->yAxis->setRange(y11, y12);
    ui->customPlot_5->replot();

    }

    this->setCursor(QCursor(Qt::ArrowCursor));
}

// calculate Échellogram
void MainWindow::Echellogram()
{

    this->setCursor(QCursor(Qt::WaitCursor));

    if(ui->checkBox->isChecked()){
        s = tan(ui->doubleSpinBox_29->value()/3600*M_PI/180)*ui->doubleSpinBox_35->value();
    }
    else{
        s = ui->doubleSpinBox_14->value();
    }


    lw.resize(lx/Bx);
    b1c.resize(lx/Bx);
    o.resize(lx/Bx);
    l11.resize(lx/Bx);

    double startb, index;

    ofstream file1("echello.txt");

    if(ui->checkBox_8->isChecked()){
        FWHM=s/p*f2/f1;
    }
    if(ui->checkBox_9->isChecked()){
        FWHM=sl/p*f2/f1;
    }

    int ovlap=0;

     ofstream egram("echellogram.dat");
     egram<<"rel. order.\tabs. order\tlower wave\tmiddle wave\tupper wave\toverlap"<<endl;

     // Échellogram Prism
    if(e==0){

        bm = atan((lx)*p/2/f2)*180/M_PI;
        o[0]=(ly-4*sdisc/p);
        l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g)*1000;
        index=sqrt(1+B1*l11[0]*l11[0]/(l11[0]*l11[0]-C1)+B2*l11[0]*l11[0]/(l11[0]*l11[0]-C2)+B3*l11[0]*l11[0]/(l11[0]*l11[0]-C3));
        l11[0]=l11[0]/1000;
        lz=lz*1000;
        indexlz=sqrt(1+B1*lz*lz/(lz*lz-C1)+B2*lz*lz/(lz*lz-C2)+B3*lz*lz/(lz*lz-C3));
        lz=lz/1000;
        double einf=asin(indexlz*sin(M_PI/180*30))*180/M_PI;
        startb= einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;
        //startb=180/M_PI*asin(sin(M_PI/180*60)*sqrt(index*index-sin(einf*M_PI/180)*sin(M_PI/180*einf))-sin(einf*M_PI/180)*cos(M_PI/180*60));


        for(int m=0; m<nl-nh; m++){
            n[m]=nl-m;
            egram<<m<<"\t\t"<<n[m]<<"\t\t";
            for(int i=0; i<lx/Bx; i++){
               bm = atan((lx/2-i*Bx)*p/f2)*180/M_PI;
               l11[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
               index=sqrt(1+B1*l11[i]*l11[i]/(l11[i]*l11[i]-C1)+B2*l11[i]*l11[i]/(l11[i]*l11[i]-C2)+B3*l11[i]*l11[i]/(l11[i]*l11[i]-C3));
               l11[i]=l11[i]/1000;
               b1c[i]=einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;
               //b1c[i]=180/M_PI*asin(sin(M_PI/180*60)*sqrt(index*index-sin(einf*M_PI/180)*sin(M_PI/180*einf))-sin(einf*M_PI/180)*cos(M_PI/180*60));
               o[i] = ((ly-4*sdisc/p)-tan((startb-b1c[i])*M_PI/180)*f2/p);
             file1<<i<<" "<<o[i]<<endl;
             file1<<i<<" "<<o[i]+FWHM<<endl;
             file1<<i<<" "<<o[i]-FWHM<<endl;

             if((i==0) or (i==lx/Bx/2) or (i==lx/Bx-1)){
                 egram<<l11[i]*1000000<<"\t\t";
             }
             if(i==0){
                 if(l11[0]<l11[lx/Bx-1]){
                     ovlap=1;
                 }
             }

                    }
            if(ovlap==1){
                ovlap=0;
                egram<<"yes";
            }
            else egram<<"no";
            egram<<endl;
            ui->progressBar->setValue((m+1)*100/(nl-nh));
            qApp->processEvents(QEventLoop::AllEvents);
            }
    }

    // Échellogram Grating
    if(e==1){

        bm = atan((lx/2)*p/f2)*180/M_PI;
        lw[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g);
        startb= asin(ncd*lw[0]*gc-sin(M_PI/180*acc))*180/M_PI;

        for(int i=0; i<nl-nh; i++){
            n[i]=nl-i;
            egram<<i<<"\t\t"<<n[i]<<"\t\t";

            for(int m=0; m<lx/Bx; m++){
            bm = atan((lx/2-m*Bx)*p/f2)*180/M_PI;
            lw[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[i]*g);
            b1c[m] = asin(ncd*lw[m]*gc-sin(M_PI/180*acc))*180/M_PI;
            o[m] = (ly-4*sdisc/p)-tan((b1c[m]-startb)*M_PI/180)*f2/p;

           file1<<m<<" "<<o[m]<<endl;
           file1<<m<<" "<<o[m]+FWHM<<endl;
           file1<<m<<" "<<o[m]-FWHM<<endl;

           if((m==0) or (m==lx/Bx/2) or (m==lx/Bx-1)){
               egram<<lw[m]*1000000<<"\t\t";
           }
           if(m==0){
               if(lw[0]<lw[lx/Bx-1]){
                   ovlap=1;
               }

                }
            }
           if(ovlap==1){
               ovlap=0;
               egram<<"yes";
           }
           else egram<<"no";
           egram<<endl;
            ui->progressBar->setValue((i+1)*100/(nl-nh));
            qApp->processEvents(QEventLoop::AllEvents);
            }
        }

    // Échellogram VPH Grating
    if(e==2){

        bm = atan(lx/2*p/f2)*180/M_PI;
        double alpha_2b=asin(ncd*tDCG/1000000/nDCG/2*gc)*180/M_PI;

        lw[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g);
        startb = asin(ncd*lw[0]*gc-sin(M_PI/180*acc))*180/M_PI;

        for(int m=0; m<nl-nh; m++){
            n[m]=nl-m;
            egram<<m<<"\t\t"<<n[m]<<"\t\t";
            for(int i=0; i<lx/Bx; i++){
            bm = atan((lx/2-i*Bx)*p/f2)*180/M_PI;
            lw[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);
            b1c[i] = asin(ncd*lw[i]*gc-sin(M_PI/180*acc))*180/M_PI;
            o[i] = (ly-4*sdisc/p)-tan((b1c[i]-startb)*M_PI/180)*f2/p;
            file1<<i<<" "<<o[i]<<endl;
            file1<<i<<" "<<o[i]+FWHM<<endl;
            file1<<i<<" "<<o[i]-FWHM<<endl;

            if((i==0) or (i==lx/Bx/2) or (i==lx/Bx-1)){
                egram<<lw[i]*1000000<<"\t\t";
            }
            if(i==0){
                if(lw[0]<lw[lx/Bx-1]){
                    ovlap=1;
                }

                 }
            }
            if(ovlap==1){
                ovlap=0;
                egram<<"yes";
            }
            else egram<<"no";
            egram<<endl;

            ui->progressBar->setValue((m+1)*100/(nl-nh));
            qApp->processEvents(QEventLoop::AllEvents);
            }
    }

    // Échellogram VPH Grism
    if(e==3){


        lz=lz*1000;
        indexlz=sqrt(1+B1*lz*lz/(lz*lz-C1)+B2*lz*lz/(lz*lz-C2)+B3*lz*lz/(lz*lz-C3));
        lz=lz/1000;
        double theta1, difference, b11, b12;

        // find theta2 of grism prisms
        for(int i=0; i<900; i++){
            theta1=0.1*i;
            difference=(theta1-(asin(ncd*lz*gc/2/indexlz)+asin(sin(theta1*M_PI/180)/indexlz))*180/M_PI);
            if(difference>=0){
                theta2=theta1;
                i=900;
            }
        }

        bm = atan(lx/2*p/f2)*180/M_PI;
        l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g)*1000;
        index=sqrt(1+B1*l11[0]*l11[0]/(l11[0]*l11[0]-C1)+B2*l11[0]*l11[0]/(l11[0]*l11[0]-C2)+B3*l11[0]*l11[0]/(l11[0]*l11[0]-C3));
        l11[0]=l11[0]/1000;
        b11=asin(sin(theta2*M_PI/180/index))*180/M_PI;
        b12=asin(l11[0]*gc/index*ncd-sin(theta2*M_PI/180-b11*M_PI/180))*180/M_PI;
        startb=asin(index*sin(theta2*M_PI/180-b12*M_PI/180))*180/M_PI;

        for(int i=0; i<nl-nh; i++){
            n[i]=nl-i;
            egram<<i<<"\t\t"<<n[i]<<"\t\t";
            for(int m=0; m<lx/Bx; m++){
            bm = atan((lx/2-m*Bx)*p/f2)*180/M_PI;
            lw[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[i]*g)*1000;
            index=sqrt(1+B1*lw[m]*lw[m]/(lw[m]*lw[m]-C1)+B2*lw[m]*lw[m]/(lw[m]*lw[m]-C2)+B3*lw[m]*lw[m]/(lw[m]*lw[m]-C3));
            lw[m]=lw[m]/1000;

            b11=asin(sin(theta2*M_PI/180/index))*180/M_PI;
            b12=asin(lw[m]*gc/index*ncd-sin(theta2*M_PI/180-b11*M_PI/180))*180/M_PI;

            b1c[m]=asin(index*sin(theta2*M_PI/180-b12*M_PI/180))*180/M_PI;
            o[m] = (ly-4*sdisc/p)-tan((startb-b1c[m])*M_PI/180)*f2/p;
            file1<<m<<" "<<o[m]<<endl;
            file1<<m<<" "<<o[m]+FWHM<<endl;
            file1<<m<<" "<<o[m]-FWHM<<endl;

            if((m==0) or (m==lx/Bx/2) or (m==lx/Bx-1)){
                egram<<lw[m]*1000000<<"\t\t";
            }
            if(m==0){
                if(lw[0]<lw[lx/Bx-1]){
                    ovlap=1;
                }

                 }
            }
            if(ovlap==1){
                ovlap=0;
                egram<<"yes";
            }
            else egram<<"no";
            egram<<endl;
            ui->progressBar->setValue((i+1)*100/(nl-nh));
            qApp->processEvents(QEventLoop::AllEvents);
        }
    }

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
    MainWindow::parameters();
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_6->setEnabled(true);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    MainWindow::overview();
    MainWindow::revectors();
    MainWindow::Echellogram();
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
}

void MainWindow::on_actionParameters_triggered()
{
    qEchelle = new Echelle(this);
    qEchelle->seData(ui->lineEdit_2->text());
    qEchelle->show();
}

void MainWindow::on_doubleSpinBox_5_valueChanged()
{
    eta=ui->doubleSpinBox_5->value();
}

void MainWindow::on_doubleSpinBox_6_valueChanged()
{
    thetac=ui->doubleSpinBox_6->value();
    dc=cos(M_PI/180*thetac)/gc;
}

void MainWindow::on_doubleSpinBox_8_valueChanged()
{
    exptime=ui->doubleSpinBox_8->value();
}

void MainWindow::on_doubleSpinBox_7_valueChanged()
{
    etac=ui->doubleSpinBox_7->value();
}

void MainWindow::on_doubleSpinBox_9_valueChanged()
{
    T=ui->doubleSpinBox_9->value();

    if (log10(T)<4){
         BC = -64741.6+67717*log10(T)-26566.141*log10(T)*log10(T)+4632.926*log10(T)*log10(T)*log10(T)-303.0307*log10(T)*log10(T)*log10(T)*log10(T);
         }
         else {
              BC = -888.82+884.69*log10(T)-326.85*log10(T)*log10(T)+53.4*log10(T)*log10(T)*log10(T)-3.2744*log10(T)*log10(T)*log10(T)*log10(T);
              }


    ui->doubleSpinBox_11->setValue(BC);
}

void MainWindow::on_doubleSpinBox_10_valueChanged()
{
    vm=ui->doubleSpinBox_10->value();
}

void MainWindow::on_doubleSpinBox_12_valueChanged()
{
    z=ui->doubleSpinBox_12->value();
}


void MainWindow::on_doubleSpinBox_14_valueChanged()
{
    s=ui->doubleSpinBox_14->value();
    skyslit=atan(s/ftel)*3600*180/M_PI;
    ui->doubleSpinBox_31->setValue(skyslit);
}

void MainWindow::on_doubleSpinBox_15_valueChanged()
{
    sl=ui->doubleSpinBox_15->value();
}

void MainWindow::on_doubleSpinBox_16_valueChanged()
{
    gain=ui->doubleSpinBox_16->value();
}

void MainWindow::on_doubleSpinBox_17_valueChanged()
{
    readnoise=ui->doubleSpinBox_17->value();
}

void MainWindow::on_spinBox_2_valueChanged()
{
    al=ui->spinBox_2->value();
}

void MainWindow::on_spinBox_valueChanged()
{
    ag=ui->spinBox->value();
}

void MainWindow::on_spinBox_3_valueChanged()
{
    bb=ui->spinBox_3->value();
}

void MainWindow::on_spinBox_7_valueChanged()
{
    aluv=ui->spinBox_7->value();
}

void MainWindow::on_spinBox_8_valueChanged()
{
    au=ui->spinBox_8->value();
}

void MainWindow::on_checkBox_11_clicked()
{
    if(ui->checkBox_11->isChecked()){
    ui->lineEdit->setEnabled(true);
    }
    else{
       ui->lineEdit->setEnabled(false);
    }
}

void MainWindow::on_doubleSpinBox_18_valueChanged()
{
    nDCG=ui->doubleSpinBox_18->value();
}

void MainWindow::on_doubleSpinBox_20_valueChanged()
{
    dnDCG=ui->doubleSpinBox_20->value();
}

void MainWindow::on_doubleSpinBox_21_valueChanged()
{
    tDCG=ui->doubleSpinBox_21->value();
}

void MainWindow::on_actionClassical_2_triggered()
{
    qPClassical = new PClassical(this);
    qPClassical->seData(ui->lineEdit_2->text());
    qPClassical->show();
}

void MainWindow::on_doubleSpinBox_22_valueChanged()
{
    g=ui->doubleSpinBox_22->value();
    d=cos(M_PI/180*theta)/g;
}

void MainWindow::on_doubleSpinBox_23_valueChanged()
{
    theta=ui->doubleSpinBox_23->value();
    d=cos(M_PI/180*theta)/g;
}

void MainWindow::on_doubleSpinBox_24_valueChanged()
{
     t=ui->doubleSpinBox_24->value();
}

void MainWindow::on_doubleSpinBox_25_valueChanged()
{
    f1=ui->doubleSpinBox_25->value();
}

void MainWindow::on_doubleSpinBox_27_valueChanged()
{
    gc=ui->doubleSpinBox_27->value();
    dc=cos(M_PI/180*thetac)/gc;
}

void MainWindow::on_doubleSpinBox_28_valueChanged()
{
    tc=ui->doubleSpinBox_28->value();
}

void MainWindow::on_doubleSpinBox_29_valueChanged()
{
    seeing=ui->doubleSpinBox_29->value();

    sdisc = tan(M_PI/180*seeing/3600)*ftel;
}

void MainWindow::on_doubleSpinBox_26_valueChanged()
{
    f2=ui->doubleSpinBox_26->value();
}

void MainWindow::on_action3D_Spectrograph_triggered()
{
    qThreed = new threed(this);
    qThreed->seData(ui->lineEdit_2->text());
    qThreed->show();
}

void MainWindow::on_action3D_triggered()
{
    qPthreed = new pthreed(this);
    qPthreed->seData(ui->lineEdit_2->text());
    qPthreed->show();
}


void MainWindow::on_action3D_Frame_triggered()
{
    qFrame3D = new Frame3D(this);
    qFrame3D->seData(ui->lineEdit_2->text());
    qFrame3D->show();
}

void MainWindow::on_actionEchelle_Frame_triggered()
{
    qFrameEchelle = new FrameEchelle(this);
    qFrameEchelle->seData(ui->lineEdit_2->text());
    qFrameEchelle->show();
}


// Create CCD Frame
void MainWindow::on_pushButton_7_clicked()
{   
    ui->progressBar->setValue(0);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Warning!", "This will delete all existing frames.\n\nSave or export them first, if you want to keep.\n\nDo you wish to continue?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
      qDebug() << "Yes was clicked";
    } else {
      qDebug() << "Yes was *not* clicked";
      return;
    }

    int progress=0;

    ofstream out1("neonech.txt");
    ofstream out2("balmerech.txt");
    ofstream out3("planckech.txt");
    ofstream out4("tharech.txt");
    ofstream file1("framech1.txt");

    MainWindow::revectors();
    MainWindow::overview();
    MainWindow::parameters();

    double Il1, Il2, Il1c, Il2c;
    QVector<double> al(1), bl(1), lineech(1);
    int number_of_lines;
    string zeile, one, two;

    this->setCursor(QCursor(Qt::WaitCursor));

    if(ui->comboBox_3->currentIndex()==1){
    ifstream input("neon_line.txt");
    QFile checkfile2("neon_line.txt");

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Neon line list neon_line.txt not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "Neon line list neon_line.txt is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    number_of_lines =0;

    while(std::getline(input, zeile))
       ++ number_of_lines;

    input.clear();
    input.seekg(0, ios::beg);

    al.resize(number_of_lines);
    bl.resize(number_of_lines);
    lineech.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    input >> one >>two;
    istringstream ist(one);
    ist >> al[i];
    istringstream ist2(two);
    ist2 >> bl[i];
    }
    input.close();
    }
    if(ui->comboBox_3->currentIndex()==2){
    ifstream input("absor_line.txt");

    QFile checkfile2("absor_line.txt");

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Absorption line list absor_line.txt not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "Absorption line list absor_line.txt is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    number_of_lines =0;

    while(std::getline(input, zeile))
       ++ number_of_lines;

    input.clear();
    input.seekg(0, ios::beg);

    al.resize(number_of_lines);
    bl.resize(number_of_lines);
    lineech.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    input >> one >>two;
    istringstream ist(one);
    ist >> al[i];
    istringstream ist2(two);
    ist2 >> bl[i];
    }
    input.close();
    }

    if(ui->comboBox_3->currentIndex()==3){
    ifstream input("thar_uves.txt");

    QFile checkfile2("thar_uves.txt");

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Th/Ar line list thar_uves.txt not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "Th/Ar line list thar_uves.txt is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    number_of_lines =0;

    while(std::getline(input, zeile))
       ++ number_of_lines;

    input.clear();
    input.seekg(0, ios::beg);

    al.resize(number_of_lines);
    bl.resize(number_of_lines);
    lineech.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    input >> one;
    istringstream ist(one);
    ist >> al[i];
    bl[i]=0.8;
    }
    input.close();
    }


    // Prism
    if(e==0){

        bm = atan((lx)*p/2/f2)*180/M_PI;
        l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g)*1000;
                double index=sqrt(1+B1*l11[0]*l11[0]/(l11[0]*l11[0]-C1)+B2*l11[0]*l11[0]/(l11[0]*l11[0]-C2)+B3*l11[0]*l11[0]/(l11[0]*l11[0]-C3));
                l11[0]=l11[0]/1000;
                lz=lz*1000;
                indexlz=sqrt(1+B1*lz*lz/(lz*lz-C1)+B2*lz*lz/(lz*lz-C2)+B3*lz*lz/(lz*lz-C3));
                lz=lz/1000;
                cout<<indexlz<<endl;
                double einf=asin(indexlz*sin(M_PI/180*30))*180/M_PI;
                double startb= einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;

        for (int i=0; i < lx/Bx; i++){
            bm = atan((lx/2-i*Bx)*p/f2)*180/M_PI;

             for (int v=0; v < ly/By; v++){

                  for (int m =0; m < nl-nh; m++){
                      I1[m]=0;

                        n[m]=nl-m;
                        l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
                        index=sqrt(1+B1*l11[m]*l11[m]/(l11[m]*l11[m]-C1)+B2*l11[m]*l11[m]/(l11[m]*l11[m]-C2)+B3*l11[m]*l11[m]/(l11[m]*l11[m]-C3));
                        Tr[m] = 1-0.0091224/cos(M_PI/180*z)/(pow(l11[m],4));
                        CCD[m] = ap/(l11[m]*l11[m]*l11[m]*l11[m]*l11[m])/(exp(143877500/l11[m]/CCDT)-1)/CCDm*CCDp;
                        b1c[m]=einf-60+180/M_PI*asin(sin(60*M_PI/180)*sqrt(index*index-sin(einf*M_PI/180)*sin(einf*M_PI/180))-sin(einf*M_PI/180)*cos(60*M_PI/180));
                        l11[m]=l11[m]/1000;
                        b1[m] = asin(n[m]*l11[m]*g-sin(M_PI/180*a))*180/M_PI;
                        bt[m] = sin(M_PI/180*(b1[m]-theta));
                        D[m] = p*Bx*cos(b1[m]*M_PI/180)/(f2*n[m]*g);
                        A[m] = cos(M_PI/180*a)/cos(M_PI/180*b1[m]);
                        s2[m] = A[m] * f2/f1*s;

                        o[m] = -((ly-4*sdisc/p)-tan((startb-b1c[m])*M_PI/180)*f2/p)/By;
                        Il1 = sin(M_PI*d/l11[m]*(at+bt[m]));
                        Il2 = M_PI*d/l11[m]*(at+bt[m]);
                        In[m] = eta*Il1*Il1/Il2/Il2;
                        Ip[m] = exp(-2.77254/sdisc/sdisc/f2/f2*f1*f1*p*p*pow((o[m]+v),2));

                        // Planck
                        if(ui->comboBox_3->currentIndex()==0){
                        l11[m] = l11[m]*10000000;
                        P[m] = Tr[m]*dtel*dtel/400*M_PI*ap/(l11[m]*l11[m]*l11[m]*l11[m])/(exp(k/T/l11[m])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                        l11[m] = l11[m]/10000000;
                        I1[m] = In[m]*Ip[m]*P[m]*CCD[m];
                        }

                        // Neon
                        if(ui->comboBox_3->currentIndex()==1){

                            for (int e=0; e < number_of_lines; e++){
                                 lineech[e] = exp(-2.77254*p*p/s2[m]/s2[m]*100*pow((l11[m]*10000000-al[e]),2))*bl[e];
                                 I1[m] += lineech[e];
                            }

                            I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                         }

                        // Balmer
                        if(ui->comboBox_3->currentIndex()==2){
                            l11[m] = l11[m]*10000000;
                            P[m] = Tr[m]*dtel*dtel/400*M_PI*ap/(l11[m]*l11[m]*l11[m]*l11[m])/(exp(k/T/l11[m])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                            l11[m] = l11[m]/10000000;
                            for (int e=0; e < number_of_lines; e++){
                                 lineech[e] = (1-exp(-2.77254*p*p/s2[m]/s2[m]*pow((l11[m]*10000000-al[e]),2))*bl[e]*number_of_lines)/(nl-nh);
                            }

                            for (int e=0; e < number_of_lines; e++){
                                I1[m] += lineech[e];
                            }
                           I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                        }
                        // Th/Ar
                        if(ui->comboBox_3->currentIndex()==3){

                            for (int e=0; e < number_of_lines; e++){
                                            lineech[e] = exp(-2.77254*p*p/s2[m]/s2[m]*100*pow((l11[m]*10000000-al[e]),2))*bl[e];
                                            }

                                        for (int e=0; e < number_of_lines; e++){
                                            I1[m] += lineech[e];
                                            }
                                        I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                        }


                              }

                  for (int m=0; m < nl-nh; m++){
                      I += I1[m];

                         }
                  if(ui->comboBox_3->currentIndex()==0){
                  out3<<i<<" "<<v<<" "<<I<<endl;
                  }
                  if(ui->comboBox_3->currentIndex()==1){
                  out1<<i<<" "<<v<<" "<<I<<endl;
                  }
                  if(ui->comboBox_3->currentIndex()==2){
                  out2<<i<<" "<<v<<" "<<I<<endl;
                  }
                  if(ui->comboBox_3->currentIndex()==3){
                  out4<<i<<" "<<v<<" "<<I<<endl;
                  }
                  file1<<I<<" ";
                  I = 0;
                  }
             file1<<endl;
             progress++;
             if(progress>=lx/Bx/100){
             ui->progressBar->setValue((i+1)*100/(lx/Bx));
                  qApp->processEvents(QEventLoop::AllEvents);
                  progress=0;
             }
             }
        if(ui->comboBox_3->currentIndex()==0){
            out3.close();
        }
        if(ui->comboBox_3->currentIndex()==1){
            out1.close();
        }
        if(ui->comboBox_3->currentIndex()==2){
            out2.close();
        }
        if(ui->comboBox_3->currentIndex()==3){
            out4.close();
        }
    }

    // Grating
    if(e==1){

        n[0]=nl;
        o[0] = -(ly-4*sdisc/p)/By;
        l[0] = (sin(Pi/180*a)+sin(Pi/180*(b)))/(nl*g);
        lw[0] = (sin(Pi/180*a)+sin(Pi/180*(b-bm)))/(nl*g);
        b1c[0] = asin(ncd*lw[0]*gc-sin(Pi/180*acc))*180/Pi;
        b1[0] = asin(nl*lw[0]*g-sin(Pi/180*a))*180/Pi;

        bm = atan(lx/2*p/f2)*180/M_PI;

        lw[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g);
        double startb = asin(ncd*lw[0]*gc-sin(M_PI/180*acc))*180/M_PI;

        for (int m = 1; m <= nl-nh; m++){
            n[m] = nl-m;
            l[m] = (sin(Pi/180*a)+sin(Pi/180*(b)))/(n[m]*g);
            D[m] = p*Bx*cos((b-bm)*Pi/180)/(f2*n[m]*g)*ly/2;
            lw[m] = (sin(Pi/180*a)+sin(Pi/180*(b-bm)))/(n[m]*g);
            lh[m] = (sin(Pi/180*a)+sin(Pi/180*(b+bm)))/(n[m]*g);
            b1c[m] = asin(ncd*lw[m]*gc-sin(Pi/180*acc))*180/Pi;
            b1[m] = asin(n[m]*lw[m]*g-sin(Pi/180*a))*180/Pi;
            o[m] = -((ly-4*sdisc/p)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
                                    }

        for (int i=0; i < lx/Bx; i++){

             for (int v=0; v < ly/By; v++){

                 for (int m =0; m < nl-nh; m++){
                    n[m]=nl-m;
                    bm = atan((lx/2-i)*p/f2)*180/M_PI;
                    l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

                    b1c[m] = asin(ncd*l11[m]*gc-sin(M_PI/180*acc))*180/M_PI;
                    btc[m] = sin(M_PI/180*(b1c[m]-thetac));

                    b1[m] = asin(n[m]*l11[m]*g-sin(M_PI/180*a))*180/M_PI;
                    bt[m] = sin(M_PI/180*(b1[m]-theta));

                    D[m] = p*Bx*cos(b1[m]*Pi/180)/(f2*n[m]*g);
                    A[m] = cos(Pi/180*a)/cos(Pi/180*b1[m]);
                    s2[m] = A[m] * f2/f1*s;

                    o[m] = -((ly-4*sdisc/p)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
                    l11[m]=l11[m]*1000;
                    Tr[m] = 1-0.0091224/cos(Pi/180*z)/(pow(l11[m],4));
                    l11[m] = l11[m]*10000;
                    CCD[m] = ap/(l11[m]*l11[m]*l11[m]*l11[m]*l11[m])/(exp(143877500/l11[m]/CCDT)-1)/CCDm*CCDp;
                    l11[m] = l11[m]/10000000;

                    Il1c = sin(Pi*dc/l11[m]*(atc+btc[m]));
                    Il2c = Pi*dc/l11[m]*(atc+btc[m]);
                    I1c[m] = etac*Il1c*Il1c/Il2c/Il2c;

                    Il1 = sin(Pi*d/l11[m]*(at+bt[m]));
                    Il2 = Pi*d/l11[m]*(at+bt[m]);
                    In[m] = eta*Il1*Il1/Il2/Il2*I1c[m];
                    Ip[m] = exp(-2/sdisc/sdisc*p*p*pow((o[m]+v),2));

                    // Planck
                    if(ui->comboBox_3->currentIndex()==0){
                    l11[m] = l11[m]*10000000;
                    P[m] = Tr[m]*dtel*dtel/400*M_PI*ap/(l11[m]*l11[m]*l11[m]*l11[m])/(exp(k/T/l11[m])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                    l11[m] = l11[m]/10000000;
                    I1[m] = In[m]*Ip[m]*P[m]*CCD[m];
                    }

                    // Neon
                    if(ui->comboBox_3->currentIndex()==1){

                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = exp(-2.77254*p*p/s2[m]/s2[m]*100*pow((l11[m]*10000000-al[e]),2))*bl[e];
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }

                    // Balmer
                    if(ui->comboBox_3->currentIndex()==2){
                        l11[m] = l11[m]*10000000;
                        P[m] = Tr[m]*dtel*dtel/400*M_PI*ap/(l11[m]*l11[m]*l11[m]*l11[m])/(exp(k/T/l11[m])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                        l11[m] = l11[m]/10000000;
                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = (1-exp(-2.77254*p*p/s2[m]/s2[m]*pow((l11[m]*10000000-al[e]),2))*bl[e]*number_of_lines)/(nl-nh);
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }
                    // Th/Ar
                    if(ui->comboBox_3->currentIndex()==3){

                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = exp(-2.77254*p*p/s2[m]/s2[m]*100*pow((l11[m]*10000000-al[e]),2))*bl[e];
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }

                    }

                    for (int m=0; m < nl-nh; m++){
                        I += I1[m];
                        I1[m]=0;
                        }

                    if(ui->comboBox_3->currentIndex()==0){
                    out3<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==1){
                    out1<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==2){
                    out2<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==3){
                    out4<<i<<" "<<v<<" "<<I<<endl;
                    }
                  file1<<I<<" ";
                  I = 0;
                 }
                  file1<<endl;
                  progress++;
                  if(progress>=lx/Bx/100){
                  ui->progressBar->setValue((i+1)*100/(lx/Bx));
                       qApp->processEvents(QEventLoop::AllEvents);
                       progress=0;
                  }
              }
        if(ui->comboBox_3->currentIndex()==0){
            out3.close();
        }
        if(ui->comboBox_3->currentIndex()==1){
            out1.close();
        }
        if(ui->comboBox_3->currentIndex()==2){
            out2.close();
        }
        if(ui->comboBox_3->currentIndex()==3){
            out4.close();
        }

        }

    // VPH Grating
    if(e==2){

        double alpha_2b, eta_s, eta_p;
        alpha_2b=asin(ncd*lz/indexlz/2*g)*180/M_PI;

        bm = atan(lx/2*p/f2)*180/M_PI;

        lw[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g);
        double startb = asin(ncd*lw[0]*gc-sin(M_PI/180*acc))*180/M_PI;

        n[0]=nl;
        o[0] = -(ly-4*sdisc/p)/By;
        l[0] = (sin(Pi/180*a)+sin(Pi/180*(b)))/(nl*g);
        lw[0] = (sin(Pi/180*a)+sin(Pi/180*(b-bm)))/(nl*g);
        b1c[0] = asin(ncd*lw[0]*gc-sin(Pi/180*acc))*180/Pi;

        for (int m = 1; m <= nl-nh; m++){
            n[m] = nl-m;
            l[m] = (sin(Pi/180*a)+sin(Pi/180*(b)))/(n[m]*g);
            D[m] = p*Bx*cos((b-bm)*Pi/180)/(f2*n[m]*g)*ly/2;
            lw[m] = (sin(Pi/180*a)+sin(Pi/180*(b-bm)))/(n[m]*g);
            lh[m] = (sin(Pi/180*a)+sin(Pi/180*(b+bm)))/(n[m]*g);
            b1c[m] = asin(ncd*lw[m]*gc-sin(Pi/180*acc))*180/Pi;
            o[m] = -((ly-4*sdisc/p)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
                                    }

        for (int i=0; i < lx/Bx; i++){

            for (int v=0; v < ly/By; v++){

                for (int m =0; m < nl-nh; m++){
                    n[m]=nl-m;
                    bm = atan((lx/2-i)*p/f2)*180/M_PI;
                    l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

                    b1c[m] = asin(ncd*l11[m]*gc-sin(M_PI/180*acc))*180/M_PI;
                    btc[m] = sin(M_PI/180*(b1c[m]-thetac));

                    b1[m] = asin(n[m]*l11[m]*g-sin(M_PI/180*a))*180/M_PI;
                    bt[m] = sin(M_PI/180*(b1[m]-theta));

                    D[m] = p*Bx*cos(b1[m]*Pi/180)/(f2*n[m]*g);

                    A[m] = cos(Pi/180*a)/cos(Pi/180*b1[m]);
                    s2[m] = A[m] * f2/f1*s;

                    o[m] = -((ly-4*sdisc/p)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
                    l11[m]=l11[m]*1000;
                    Tr[m] = 1-0.0091224/cos(Pi/180*z)/(pow(l11[m],4));
                    l11[m] = l11[m]*10000;
                    CCD[m] = ap/(l11[m]*l11[m]*l11[m]*l11[m]*l11[m])/(exp(143877500/l11[m]/CCDT)-1)/CCDm*CCDp;
                    l11[m] = l11[m]/10000000;

                    eta_s=pow(sin(M_PI*dnDCG*dDCG/l11[i]/cos(alpha_2b*M_PI/180)),2);
                    eta_p=pow(sin(M_PI*dnDCG*dDCG*cos(M_PI/180*2*alpha_2b)/l11[i]/cos(alpha_2b*M_PI/180)),2);

                    Il1 = sin(Pi*d/l11[m]*(at+bt[m]));
                    Il2 = Pi*d/l11[m]*(at+bt[m]);
                    In[m] =(eta_s+eta_p)/2*eta*Il1*Il1/Il2/Il2;
                    Ip[m] = exp(-2/sdisc/sdisc*p*p*pow((o[m]+v),2));

                    // Planck
                    if(ui->comboBox_3->currentIndex()==0){
                    l11[m] = l11[m]*10000000;
                    P[m] = Tr[m]*dtel*dtel/400*M_PI*ap/(l11[m]*l11[m]*l11[m]*l11[m])/(exp(k/T/l11[m])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                    l11[m] = l11[m]/10000000;
                    I1[m] = In[m]*Ip[m]*P[m]*CCD[m];
                    }

                    // Neon
                    if(ui->comboBox_3->currentIndex()==1){

                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = exp(-2.77254*p*p/s2[m]/s2[m]*100*pow((l11[m]*10000000-al[e]),2))*bl[e];
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }

                    // Balmer
                    if(ui->comboBox_3->currentIndex()==2){
                        l11[m] = l11[m]*10000000;
                        P[m] = Tr[m]*dtel*dtel/400*M_PI*ap/(l11[m]*l11[m]*l11[m]*l11[m])/(exp(k/T/l11[m])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                        l11[m] = l11[m]/10000000;
                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = (1-exp(-2.77254*p*p/s2[m]/s2[m]*pow((l11[m]*10000000-al[e]),2))*bl[e]*number_of_lines)/(nl-nh);
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }
                    // Th/Ar
                    if(ui->comboBox_3->currentIndex()==3){

                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = exp(-2.77254*p*p/s2[m]/s2[m]*100*pow((l11[m]*10000000-al[e]),2))*bl[e];
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }

                    }

                    for (int m=0; m < nl-nh; m++){
                        I += I1[m];
                        I1[m]=0;
                        }

                    if(ui->comboBox_3->currentIndex()==0){
                    out3<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==1){
                    out1<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==2){
                    out2<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==3){
                    out4<<i<<" "<<v<<" "<<I<<endl;
                    }
              file1<<I<<" ";
              I = 0;
              }
              file1<<endl;
              progress++;
              if(progress>=lx/Bx/100){
              ui->progressBar->setValue((i+1)*100/(lx/Bx));
              qApp->processEvents(QEventLoop::AllEvents);
              progress=0;
              }
          }
        if(ui->comboBox_3->currentIndex()==0){
            out3.close();
        }
        if(ui->comboBox_3->currentIndex()==1){
            out1.close();
        }
        if(ui->comboBox_3->currentIndex()==2){
            out2.close();
        }
        if(ui->comboBox_3->currentIndex()==3){
            out4.close();
        }
    }

    // Frame VPH Grism
    if(e==3){

        double alpha_2b, eta_s, eta_p, index, b11, b12, startb;
        alpha_2b=asin(ncd*lz/indexlz/2*g)*180/M_PI;

        n[0]=nl;
        o[0] = -(ly-4*sdisc/p)/By;
        l[0] = (sin(Pi/180*a)+sin(Pi/180*(b)))/(nl*g);
        lw[0] = (sin(Pi/180*a)+sin(Pi/180*(b-bm)))/(nl*g);
        b1c[0] = asin(ncd*lw[0]*gc-sin(Pi/180*acc))*180/Pi;
        bm = atan(lx/2*p/f2)*180/M_PI;
        l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g)*1000;
        index=sqrt(1+B1*l11[0]*l11[0]/(l11[0]*l11[0]-C1)+B2*l11[0]*l11[0]/(l11[0]*l11[0]-C2)+B3*l11[0]*l11[0]/(l11[0]*l11[0]-C3));
        l11[0]=l11[0]/1000;
        b11=asin(sin(theta2*M_PI/180/index))*180/M_PI;
        b12=asin(l11[0]*gc/index*ncd-sin(theta2*M_PI/180-b11*M_PI/180))*180/M_PI;
        startb=asin(index*sin(theta2*M_PI/180-b12*M_PI/180))*180/M_PI;

        for (int m = 1; m <= nl-nh; m++){
            n[m] = nl-m;
            l[m] = (sin(Pi/180*a)+sin(Pi/180*(b)))/(n[m]*g);
            D[m] = p*Bx*cos((b-bm)*Pi/180)/(f2*n[m]*g)*ly/2;
            lw[m] = (sin(Pi/180*a)+sin(Pi/180*(b-bm)))/(n[m]*g);
            lh[m] = (sin(Pi/180*a)+sin(Pi/180*(b+bm)))/(n[m]*g);
            b1c[m] = asin(ncd*lw[m]*gc-sin(Pi/180*acc))*180/Pi;
            o[m] = -((ly-4*sdisc/p)-tan((startb-b1c[m])*Pi/180)*f2/p)/By;
                                   }

        for (int i=0; i < lx/Bx; i++){

            for (int v=0; v < ly/By; v++){

                for (int m =0; m < nl-nh; m++){
                    n[m]=nl-m;
                    bm = atan((lx/2-i)*p/f2)*180/M_PI;
                    l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

                    b1[m] = asin(n[m]*l11[m]*g-sin(M_PI/180*a))*180/M_PI;
                    bt[m] = sin(M_PI/180*(b1[m]-theta));

                    lw[m] = l11[m]*1000;
                    index=sqrt(1+B1*lw[m]*lw[m]/(lw[m]*lw[m]-C1)+B2*lw[m]*lw[m]/(lw[m]*lw[m]-C2)+B3*lw[m]*lw[m]/(lw[m]*lw[m]-C3));
                    lw[m]=lw[m]/1000;

                    b11=asin(sin(theta2*M_PI/180/index))*180/M_PI;
                    b12=asin(l11[m]*gc/index*ncd-sin(theta2*M_PI/180-b11*M_PI/180))*180/M_PI;

                    b1c[m]=asin(index*sin(theta2*M_PI/180-b12*M_PI/180))*180/M_PI;

                    D[m] = p*Bx*cos(b1[m]*Pi/180)/(f2*n[m]*g);

                    A[m] = cos(Pi/180*a)/cos(Pi/180*b1[m]);
                    s2[m] = A[m] * f2/f1*s;

                    o[m] = -((ly-4*sdisc/p)-tan((startb-b1c[m])*Pi/180)*f2/p)/By;
                    l11[m]=l11[m]*1000;
                    Tr[m] = 1-0.0091224/cos(Pi/180*z)/(pow(l11[m],4));
                    l11[m] = l11[m]*10000;
                    CCD[m] = ap/(l11[m]*l11[m]*l11[m]*l11[m]*l11[m])/(exp(143877500/l11[m]/CCDT)-1)/CCDm*CCDp;
                    l11[m] = l11[m]/10000000;

                    eta_s=pow(sin(M_PI*dnDCG*dDCG/l11[i]/cos(alpha_2b*M_PI/180)),2);
                    eta_p=pow(sin(M_PI*dnDCG*dDCG*cos(M_PI/180*2*alpha_2b)/l11[i]/cos(alpha_2b*M_PI/180)),2);

                    Il1 = sin(Pi*d/l11[m]*(at+bt[m]));
                    Il2 = Pi*d/l11[m]*(at+bt[m]);
                    In[m] = (eta_s+eta_p)/2*Il1*Il1/Il2/Il2;
                    Ip[m] = exp(-2/sdisc/sdisc*p*p*pow((o[m]+v),2));

                    // Planck
                    if(ui->comboBox_3->currentIndex()==0){
                    l11[m] = l11[m]*10000000;
                    P[m] = Tr[m]*dtel*dtel/400*M_PI*ap/(l11[m]*l11[m]*l11[m]*l11[m])/(exp(k/T/l11[m])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                    l11[m] = l11[m]/10000000;
                    I1[m] = In[m]*Ip[m]*P[m]*CCD[m];
                    }

                    // Neon
                    if(ui->comboBox_3->currentIndex()==1){

                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = exp(-2.77254*p*p/s2[m]/s2[m]*100*pow((l11[m]*10000000-al[e]),2))*bl[e];
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }

                    // Balmer
                    if(ui->comboBox_3->currentIndex()==2){
                        l11[m] = l11[m]*10000000;
                        P[m] = Tr[m]*dtel*dtel/400*M_PI*ap/(l11[m]*l11[m]*l11[m]*l11[m])/(exp(k/T/l11[m])-1)*pow(10,-0.4*(vm-BC))/(pow(T,4)*1.986e-11);
                        l11[m] = l11[m]/10000000;
                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = (1-exp(-2.77254*p*p/s2[m]/s2[m]*pow((l11[m]*10000000-al[e]),2))*bl[e]*number_of_lines)/(nl-nh);
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }
                    // Th/Ar
                    if(ui->comboBox_3->currentIndex()==3){

                        for (int e=0; e < number_of_lines; e++){
                                        lineech[e] = exp(-2.77254*p*p/s2[m]/s2[m]*100*pow((l11[m]*10000000-al[e]),2))*bl[e];
                                        }

                                    for (int e=0; e < number_of_lines; e++){
                                        I1[m] += lineech[e];
                                        }
                                    I1[m]=I1[m]*Ip[m]*CCD[m]*In[m];
                    }

                    }

                    for (int m=0; m < nl-nh; m++){
                        I += I1[m];
                        I1[m]=0;
                        }

                    if(ui->comboBox_3->currentIndex()==0){
                    out3<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==1){
                    out1<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==2){
                    out2<<i<<" "<<v<<" "<<I<<endl;
                    }
                    if(ui->comboBox_3->currentIndex()==3){
                    out4<<i<<" "<<v<<" "<<I<<endl;
                    }
                  file1<<I<<" ";
                  I = 0;
                 }
                  file1<<endl;
                  progress++;
                  if(progress>=lx/Bx/100){
                  ui->progressBar->setValue((i+1)*100/(lx/Bx));
                       qApp->processEvents(QEventLoop::AllEvents);
                       progress=0;
                  }
              }
        if(ui->comboBox_3->currentIndex()==0){
            out3.close();
        }
        if(ui->comboBox_3->currentIndex()==1){
            out1.close();
        }
        if(ui->comboBox_3->currentIndex()==2){
            out2.close();
        }
        if(ui->comboBox_3->currentIndex()==3){
            out4.close();
        }

    }

    qFrameEchelle = new FrameEchelle(this);
    qFrameEchelle->seData(ui->lineEdit_2->text());
    qFrameEchelle->show();

    this->setCursor(QCursor(Qt::ArrowCursor));
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "About", "SILENT - Spectrograph sImuLation & EmulatioN Tool (opensource)\n\nPre-Alpha\n\nby D. P. Sablowski\n\nThe program is provided as is with no warranty of any kind.");
   return;
}

void MainWindow::on_actionBug_Report_triggered()
{
    QMessageBox::information(this, "Bug Report", "Troubles?\n\n See https://dpsablowski.wordpress.com/silent/ \n\ncontact: dsablowski@aip.de\n\nBe as precise as possible.");
    return;
}

void MainWindow::on_actionManual_triggered()
{
    QDesktopServices::openUrl(QUrl("Manual.pdf"));
}

// write values to config file
void MainWindow::on_pushButton_8_clicked()
{
    ofstream file("config.conf");

    file<<g<<endl;
    file<<eta<<endl;
    file<<theta<<endl;
    file<<t<<endl;
    file<<l1<<endl;
    file<<l2<<endl;
    file<<f1<<endl;
    file<<f2<<endl;
    file<<gc<<endl;
    file<<tc<<endl;
    file<<thetac<<endl;
    file<<etac<<endl;
    file<<nDCG<<endl;
    file<<dDCG<<endl;
    file<<dnDCG<<endl;
    file<<tDCG<<endl;
    file<<ag<<endl;
    file<<al<<endl;
    file<<aluv<<endl;
    file<<au<<endl;
    file<<bb<<endl;
    file<<unc<<endl;
    file<<T<<endl;
    file<<BC<<endl;
    file<<vm<<endl;
    file<<z<<endl;
    file<<exptime<<endl;
    file<<seeing<<endl;
    file<<ftel<<endl;
    file<<dtel<<endl;
    file<<s<<endl;
    file<<sl<<endl;
    file<<slitEff<<endl;
    file<<skyslit<<endl;
    file<<p<<endl;
    file<<lx<<endl;
    file<<ly<<endl;
    file<<Bx<<endl;
    file<<By<<endl;
    file<<offset<<endl;
    file<<readnoise<<endl;
    file<<CCDl<<endl;
    file<<CCDp<<endl;
    file<<gain<<endl;

    file.close();
}


void MainWindow::on_actionBasics_triggered()
{
    QDesktopServices::openUrl(QUrl("Spektrum49.pdf"));
}

void MainWindow::on_actionVPHG_triggered()
{
    qVPHG = new VPHG(this);
    qVPHG->show();
}


void MainWindow::on_actionOptical_Fibres_triggered()
{
    qFibre = new Fibre(this);
    qFibre->show();
}

void MainWindow::on_comboBox_currentIndexChanged()
{
    int ce = ui->comboBox->currentIndex();

    //N-F2
    if(ce==0){
        B1=1.39757037;
        B2=0.159201403;
        B3=1.26865432;
        C1=0.00995906143;
        C2=0.0546931752;
        C3=119.248346;
    }
    //N-SF2
    if(ce==1){
        B1=1.47460789;
        B2=0.193584488;
        B3=1.26589974;
        C1=0.00986143816;
        C2=0.0445477583;
        C3=106.436258;
    }
    //N-BK7
    if(ce==2){
        B1=1.03961212;
        B2=0.231792344;
        B3=1.01046945;
        C1=6.00069867e-3;
        C2=2.00179144e-2;
        C3=103.560653;
    }
    //N-SF5
    if(ce==3){
        B1=1.52481889;
        B2=0.187085527;
        B3=1.42729015;
        C1=0.011254756;
        C2=0.0588995392;
        C3=129.141675;
    }
    // CaF2
    if(ce==4){
        B1=0.5676;
        B2=0.4711;
        B3=3.848;
        C1=0.002526;
        C2=0.01008;
        C3=120.1;
    }
    //F2
    if(ce==5){
        B1=1.34533359;
        B2=0.209073176;
        B3=0.937357162;
        C1=0.00997743871;
        C2=0.0470450767;
        C3=111.886764;
    }
    // F5
    if(ce==6){
        B1=1.31044630;
        B2=0.19603426;
        B3=0.96612977;
        C1=0.0095633048;
        C2=0.0457627627;
        C3=115.011883;
    }
    // K10
    if(ce==7){
        B1=1.15687082;
        B2=0.0642625444;
        B3=0.872376139;
        C1=0.00809424251;
        C2=0.0386051284;
        C3=104.74773;
    }
    // K7
    if(ce==8){
        B1=1.1273555;
        B2=0.124412303;
        B3=0.827100531;
        C1=0.00720341707;
        C2=0.0269835916;
        C3=100.384588;
    }
    // KZFS12
    if(ce==9){
        B1=1.55624873;
        B2=0.239769276;
        B3=0.947887658;
        C1=0.0102012744;
        C2=0.0469277969;
        C3=60.98370722;
    }
    //KZFSN5
    if(ce==10){
        B1=1.47727858;
        B2=0.191686941;
        B3=0.897333608;
        C1=0.00975488335;
        C2=0.0450495404;
        C3=67.8786495;
    }
    //LAFN7
    if(ce==11){
        B1=1.66842615;
        B2=0.298512803;
        B3=1.0774376;
        C1=0.0103159999;
        C2=0.0469216348;
        C3=82.5078509;
    }
    //LF5
    if(ce==12){
        B1=1.28035628;
        B2=0.163505973;
        B3=0.893930112;
        C1=0.00929854416;
        C2=0.0449135769;
        C3=110.493685;
    }
    //LLF1
    if(ce==13){
        B1=1.21640125;
        B2=0.133664540;
        B3=0.883399468;
        C1=0.00857807248;
        C2=0.0420143003;
        C3=107.59306;
    }
    //N-BAF10
    if(ce==14){
        B1=1.5851495;
        B2=0.143559385;
        B3=1.08521269;
        C1=0.00926681282;
        C2=0.0424489805;
        C3=105.613573;
    }
    //N-BAF4
    if(ce==15){
        B1=1.42056328;
        B2=0.102721269;
        B3=1.14380976;
        C1=0.00942015382;
        C2=0.0531087291;
        C3=110.278856;
    }
    //N-BAF51
    if(ce==16){
        B1=1.51503623;
        B2=0.153621958;
        B3=1.15427909;
        C1=0.00942734715;
        C2=0.04308265;
        C3=124.889868;
    }
    //N-BAF52
    if(ce==17){
        B1=1.43903433;
        B2=0.0967046052;
        B3=1.09875818;
        C1=0.00907800128;
        C2=0.050821208;
        C3=105.691856;
    }
    //N-BAK1
    if(ce==18){
        B1=1.12365662;
        B2=0.309276848;
        B3=0.0881511957;
        C1=0.00644742752;
        C2=0.0222284402;
        C3=107.297751;
    }
    //N-BAK2
    if(ce==19){
        B1=1.01662154;
        B2=0.319903051;
        B3=0.937232995;
        C1=0.00592383763;
        C2=0.0203828415;
        C3=113.118417;
    }
    //N-BAK4
    if(ce==20){
        B1=1.28834642;
        B2=0.132817724;
        B3=0.945395373;
        C1=0.00779980626;
        C2=0.0315631177;
        C3=105.965875;
    }
    //N-BALF4
    if(ce==21){
        B1=1.31004128;
        B2=0.142038259;
        B3=0.964929351;
        C1=0.0079659645;
        C2=0.0330672072;
        C3=109.19732;
    }
    //N-BALF5
    if(ce==22){
        B1=1.28385965;
        B2=0.0719300942;
        B3=1.05048927;
        C1=0.00825815975;
        C2=0.0441920027;
        C3=107.097324;
    }
    //N-BASF2
    if(ce==23){
        B1=1.53652081;
        B2=0.156971102;
        B3=1.30196815;
        C1=0.0108435729;
        C2=0.0562278762;
        C3=131.3397;
    }
    //N-BASF64
    if(ce==24){
        B1=1.65554268;
        B2=0.17131977;
        B3=1.33664448;
        C1=0.0104485644;
        C2=0.0499394756;
        C3=118.961472;
    }
    //N-BK10
    if(ce==25){
        B1=0.888308131;
        B2=0.328964475;
        B3=0.984610769;
        C1=0.00516900822;
        C2=0.0161190045;
        C3=99.7575331;
    }
    //N-FK5
    if(ce==26){
        B1=0.844309338;
        B2=0.344147824;
        B3=0.910790213;
        C1=0.00475111955;
        C2=0.0149814849;
        C3=97.8600293;
    }
    //N-FK51A
    if(ce==27){
        B1=0.971247817;
        B2=0.216901417;
        B3=0.904651666;
        C1=0.00472301995;
        C2=0.0153575612;
        C3=168.68133;
    }
    //N-K5
    if(ce==28){
        B1=1.08511833;
        B2=0.199562005;
        B3=0.930511663;
        C1=0.00661099503;
        C2=0.024110866;
        C3=111.982777;
    }
    //N-KZFS11
    if(ce==29){
        B1=1.3322245;
        B2=0.28924161;
        B3=1.15161734;
        C1=0.0084029848;
        C2=0.034423972;
        C3=88.4310532;
    }
    //N-SF11
    if(ce==30){
        B1=1.737;
        B2=0.3137;
        B3=1.899;
        C1=0.01319;
        C2=0.06231;
        C3=1552;
    }
    //ZnSe
    if(ce==31){
        B1=4.298;
        B2=0.6278;
        B3=2.896;
        C1=0.03689;
        C2=0.1435;
        C3=220.8;
    }
    //N-SF10
    if(ce==32){
        B1=1.62153902;
        B2=0.256287842;
        B3=1.64447552;
        C1=0.0122241457;
        C2=0.0595736775;
        C3=147.468793;
    }
    //Fused Silica
    if(ce==33){
        B1=0.6961663;
        B2=0.4079426;
        B3=0.8974794;
        C1=0.00467914826;
        C2=0.0135120631;
        C3=97.9340025;
    }
}

// uncoated Surfaces
void MainWindow::on_spinBox_6_valueChanged()
{
    Frenl=1;

    unc=ui->spinBox_6->value();
    Frea.resize(unc);
    Fren.resize(unc);
    Frp.resize(unc);
    Frs.resize(unc);
    Fr.resize(unc);
    ui->tableWidget->setRowCount(unc);
    for(int i=0; i<unc; i++){
    ui->tableWidget->setItem(i,0,new QTableWidgetItem("1"));
    ui->tableWidget->setItem(i,1,new QTableWidgetItem("1"));
    }
}



void MainWindow::on_spinBox_9_valueChanged()
{
    offset=ui->spinBox_9->value();
}

void MainWindow::on_doubleSpinBox_33_valueChanged()
{
    p=ui->doubleSpinBox_33->value();
}

void MainWindow::on_spinBox_10_valueChanged()
{
    lx=ui->spinBox_10->value();
}

void MainWindow::on_spinBox_11_valueChanged()
{
    ly=ui->spinBox_11->value();
}


void MainWindow::on_doubleSpinBox_34_valueChanged()
{
    dtel=ui->doubleSpinBox_34->value();
}

void MainWindow::on_actionClassical_Frame_triggered()
{
    qFrameCl = new FrameCl(this);
    qFrameCl->seData(ui->lineEdit_2->text());
    qFrameCl->show();
}

void MainWindow::on_actionTSI_triggered()
{
    qTSI = new TSI(this);
    qTSI->show();
}

void MainWindow::warning1() {
  QMessageBox::StandardButton reply;
  reply = QMessageBox::question(this, "Warning!", "Quit?",
                                QMessageBox::Yes|QMessageBox::No);
  if (reply == QMessageBox::Yes) {
    qDebug() << "Yes was clicked";
    return;
  } else {
    qDebug() << "Yes was *not* clicked";
  }
}

void MainWindow::on_actionNotes_triggered()
{
    qNotes = new Notes(this);
    qNotes->show();
}

void MainWindow::on_actionNew_triggered()
{

}

void MainWindow::on_actionUndo_triggered()
{

}

void MainWindow::setvalues(){

    g=variables[0];
    ui->doubleSpinBox_22->setValue(g);
    eta=variables[1];
    ui->doubleSpinBox_5->setValue(eta);
    theta=variables[2];
    ui->doubleSpinBox_23->setValue(theta);
    t=variables[3];
    ui->doubleSpinBox_24->setValue(t);
    l1=variables[4];
    ui->doubleSpinBox->setValue(l1);
    l2=variables[5];
    ui->doubleSpinBox_2->setValue(l2);
    f1=variables[6];
    ui->doubleSpinBox_25->setValue(f1);
    f2=variables[7];
    ui->doubleSpinBox_26->setValue(f2);
    gc=variables[8];
    ui->doubleSpinBox_27->setValue(gc);
    tc=variables[9];
    ui->doubleSpinBox_28->setValue(tc);
    thetac=variables[10];
    ui->doubleSpinBox_6->setValue(thetac);
    etac=variables[11];
    ui->doubleSpinBox_7->setValue(etac);
    nDCG=variables[12];
    ui->doubleSpinBox_18->setValue(nDCG);
    dDCG=variables[13];
    ui->doubleSpinBox_19->setValue(dDCG);
    dnDCG=variables[14];
    ui->doubleSpinBox_20->setValue(dnDCG);
    tDCG=variables[15];
    ui->doubleSpinBox_21->setValue(tDCG);
    ag=variables[16];
    ui->spinBox->setValue(ag);
    al=variables[17];
    ui->spinBox_2->setValue(al);
    aluv=variables[18];
    ui->spinBox_7->setValue(aluv);
    au=variables[19];
    ui->spinBox_8->setValue(au);
    bb=variables[20];
    ui->spinBox_3->setValue(bb);
    T=variables[21];
    ui->doubleSpinBox_9->setValue(T);
    BC=variables[22];
    ui->doubleSpinBox_11->setValue(BC);
    vm=variables[23];
    ui->doubleSpinBox_10->setValue(vm);
    z=variables[24];
    ui->doubleSpinBox_12->setValue(z);
    exptime=variables[25];
    ui->doubleSpinBox_8->setValue(exptime);
    seeing=variables[26];
    ui->doubleSpinBox_29->setValue(seeing);
    ftel=variables[27];
    ui->doubleSpinBox_35->setValue(ftel);
    dtel=variables[28];
    ui->doubleSpinBox_34->setValue(dtel);
    s=variables[29];
    ui->doubleSpinBox_14->setValue(s);
    sl=variables[30];
    ui->doubleSpinBox_15->setValue(sl);
    skyslit=variables[31];
    ui->doubleSpinBox_31->setValue(skyslit);
    lx=variables[32];
    ui->spinBox_10->setValue(lx);
    ly=variables[33];
    ui->spinBox_11->setValue(ly);
    Bx=variables[34];
    ui->spinBox_4->setValue(Bx);
    By=variables[35];
    ui->spinBox_5->setValue(By);
    offset=variables[36];
    ui->spinBox_9->setValue(offset);
    readnoise=variables[37];
    ui->doubleSpinBox_17->setValue(readnoise);
    CCDl=variables[38];
    ui->doubleSpinBox_4->setValue(CCDl);
    CCDp=variables[39];
    ui->doubleSpinBox_3->setValue(CCDp);
    gain=variables[40];
    ui->doubleSpinBox_16->setValue(gain);
    p=variables[41];
    ui->doubleSpinBox_33->setValue(p);

    slitEff=variables[42];
    ui->doubleSpinBox_30->setValue(slitEff);

    unc=variables[43];
    ui->spinBox_6->setValue(unc);

    ui->comboBox->setCurrentIndex(variables[44]);
    ui->comboBox_2->setCurrentIndex(variables[45]);
    ui->comboBox_3->setCurrentIndex(variables[46]);


      qApp->processEvents(QEventLoop::AllEvents);
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open", "","config files (*.conf);;");

    if(file.isEmpty()){
        QMessageBox::information(this, "Empty File", "This file is empty");
        return;
    }

    if(!file.isEmpty()){
        string eins;
        //ifstream data("config.conf");
        string data = file.toUtf8().constData();
        std::ostringstream datNameStream(data);
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        for(int i=0; i<vars; i++){
        dat >> eins;
        stringstream str(eins);
        str>> variables[i];
        }


        dat.close();

        MainWindow::setvalues();
    }
}

void MainWindow::on_actionSave_AS_triggered()
{

    QFileDialog dialog(this);
    dialog.setDefaultSuffix("txt");
    QString file1 = dialog.getSaveFileName(this,
                                                 "Save As",
                                                 "",
                                                 "Config Files (*.conf)");
    mFilename = file1;

    on_actionSave_triggered();
}

void MainWindow::on_actionSave_triggered()
{
    int cint=0;

    QString file1 = mFilename;

    string data = file1.toUtf8().constData();
    std::ostringstream datNameStream(data);
    std::string datName = datNameStream.str();
    ofstream file(datName.c_str());

    file<<g<<endl;
    file<<eta<<endl;
    file<<theta<<endl;
    file<<t<<endl;
    file<<l1<<endl;
    file<<l2<<endl;
    file<<f1<<endl;
    file<<f2<<endl;
    file<<gc<<endl;
    file<<tc<<endl;
    file<<thetac<<endl;
    file<<etac<<endl;
    file<<nDCG<<endl;
    file<<dDCG<<endl;
    file<<dnDCG<<endl;
    file<<tDCG<<endl;
    file<<ag<<endl;
    file<<al<<endl;
    file<<aluv<<endl;
    file<<au<<endl;
    file<<bb<<endl;
    file<<T<<endl;
    file<<BC<<endl;
    file<<vm<<endl;
    file<<z<<endl;
    file<<exptime<<endl;
    file<<seeing<<endl;
    file<<ftel<<endl;
    file<<dtel<<endl;
    file<<s<<endl;
    file<<sl<<endl;
    file<<skyslit<<endl;
    file<<lx<<endl;
    file<<ly<<endl;
    file<<Bx<<endl;
    file<<By<<endl;
    file<<offset<<endl;
    file<<readnoise<<endl;
    file<<CCDl<<endl;
    file<<CCDp<<endl;
    file<<gain<<endl;
    file<<p<<endl;
    file<<slitEff<<endl;
    file<<unc<<endl;
    cint = ui->comboBox->currentIndex();
    file<<cint<<endl;
    cint = ui->comboBox_2->currentIndex();
    file<<cint<<endl;
    cint = ui->comboBox_3->currentIndex();

    file.close();
}

