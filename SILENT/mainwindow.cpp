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
  double f2nd; //2nd collimator focal length
  double ftrans; // tranfer collimator focal length
  double PhiWP; // WP imaging constant f2nd/ftrans
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
  int aal=0, aag=0, abb=0, aaluv=0, aau=0, nglass=0;
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
  QVector<double> SeB1(1), SeB2(1),SeB3(1),SeC1(1),SeC2(1),SeC3(1);
  QVector<string> GLASS(1);
  QVector<double> CGain(1), CNoise(1), CEff(1), Cpx(1), Cpy(1), Cpsx(1), Cpsy(1), CEw(1);
  QVector<string> CCDt(1);
  int vars=49;
  int nccd=0;
  QVector<double> variables(vars);

  double Frenl=1;
  string line, eins, zwei, drei, vier, fuenf, sechs, sieben, acht, neun;


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
    ui->lineEdit_5->setText(QDir::currentPath());
    ui->lineEdit_3->setText("GlassData.slib");

    QString qPath = ui->lineEdit_2->text()+"/GlassData.slib";

    string path = qPath.toUtf8().constData();
    std::ostringstream datNameStream(path);
    datNameStream<<path;
    std::string datName = datNameStream.str();

    QFile checkfile1(datName.c_str());

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Warning", "Glass data "+checkfile1.fileName()+" not available!");
    }

    else{

    ifstream glass(datName.c_str());

    while(std::getline(glass, line))
       ++ nglass;

    glass.clear();
    glass.seekg(0, ios::beg);

    SeB1.resize(nglass);
    SeB2.resize(nglass);
    SeB3.resize(nglass);
    SeC1.resize(nglass);
    SeC2.resize(nglass);
    SeC3.resize(nglass);
    GLASS.resize(nglass);

    for (int i =0; i < nglass; i++){
        glass >> eins >> zwei >> drei >> vier >> fuenf >> sechs >> sieben;
        istringstream istr(eins);
        istr >> GLASS[i];
        istringstream istr1(zwei);
        istr1 >> SeB1[i];
        istringstream istr2(drei);
        istr2 >> SeB2[i];
        istringstream istr3(vier);
        istr3 >> SeB3[i];
        istringstream istr4(fuenf);
        istr4 >> SeC1[i];
        istringstream istr5(sechs);
        istr5 >> SeC2[i];
        istringstream istr6(sieben);
        istr6 >> SeC3[i];

        QString gele=QString::fromStdString(istr.str());
        ui->comboBox->addItem(gele);
    }
    glass.close();


    B1=SeB1[0];
    B2=SeB2[0];
    B3=SeB3[0];
    C1=SeC1[0];
    C2=SeC2[0];
    C3=SeC3[0];
    }

    ui->lineEdit_4->setText("CCD_Data.slib");

    QString cPath = ui->lineEdit_2->text()+"/CCD_Data.slib";

    string cpath = cPath.toUtf8().constData();
    std::ostringstream dat2NameStream(cpath);
    dat2NameStream<<cpath;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Warning", "CCD data "+checkfile2.fileName()+" not available!");
    }

    else{

    ifstream ccd(dat2Name.c_str());

    while(std::getline(ccd, line))
       ++ nccd;

    ccd.clear();
    ccd.seekg(0, ios::beg);

    CGain.resize(nccd);
    CEff.resize(nccd);
    CNoise.resize(nccd);
    Cpx.resize(nccd);
    Cpy.resize(nccd);
    Cpsx.resize(nccd);
    Cpsy.resize(nccd);
    CEw.resize(nccd);
    CCDt.resize(nccd);

    for (int i =0; i < nccd; i++){
        ccd >> eins >> zwei >> drei >> vier >> fuenf >> sechs >> sieben >> acht >> neun;
        istringstream istr(eins);
        istr >> CCDt[i];
        istringstream istr1(zwei);
        istr1 >> Cpx[i];
        istringstream istr2(drei);
        istr2 >> Cpy[i];
        istringstream istr3(vier);
        istr3 >> Cpsx[i];
        Cpsx[i]=Cpsx[i]/1000;
        istringstream istr4(fuenf);
        istr4 >> Cpsy[i];
        Cpsy[i]=Cpsy[i]/1000;
        istringstream istr5(sechs);
        istr5 >> CNoise[i];
        istringstream istr6(sieben);
        istr6 >> CGain[i];
        istringstream istr7(acht);
        istr7 >> CEw[i];
        istringstream istr8(neun);
        istr8 >> CEff[i];

        QString gele=QString::fromStdString(istr.str());
        ui->comboBox_4->addItem(gele);
    }
    ccd.close();

    lx = Cpx[0];
    ly = Cpy[0];
    p = Cpsx[0];
    readnoise = CNoise[0];
    CCDl = CEw[0];
    CCDp = CEff[0];
    gain = CGain[0];
    }

    l1=ui->doubleSpinBox->value();
    l2=ui->doubleSpinBox_2->value();

    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Index"<<"Angle");

    ui->doubleSpinBox_22->setValue(79);
    g=ui->doubleSpinBox_22->value();

    ui->doubleSpinBox_23->setValue(63.4);
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

    // CCD Data
    ui->doubleSpinBox_33->setValue(p);

    ui->spinBox_10->setValue(lx);

    ui->spinBox_11->setValue(ly);

    ui->doubleSpinBox_17->setValue(readnoise);

    ui->doubleSpinBox_4->setValue(CCDl);

    ui->doubleSpinBox_3->setValue(CCDp);

    ui->doubleSpinBox_16->setValue(gain);


    ui->doubleSpinBox_15->setValue(0);
    sl=ui->doubleSpinBox_15->value();

    ui->spinBox_4->setValue(1);
    Bx=ui->spinBox_4->value();

    ui->spinBox_5->setValue(1);
    By=ui->spinBox_5->value();

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

    ui->doubleSpinBox_37->setEnabled(false);
    ui->doubleSpinBox_32->setEnabled(false);
    ui->checkBox_3->setEnabled(false);


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
    sdisc = sdisc/2.3548;
    // circular slit
    if(ui->checkBox_8->isChecked()){

        double slitstep=0.0001;
        int steps=s/2/slitstep+1;
        double relativ=0;
        for(int i =0; i<steps-1; i++){
            relativ+=(exp(-i*slitstep*i*slitstep/2/sdisc/sdisc)+exp(-(i+1)*slitstep*(i+1)*slitstep/2/sdisc/sdisc))/2*slitstep;//relativ+=(exp(-2*i*slitstep*i*slitstep/sdisc/sdisc)+exp(-2*(i+1)*slitstep*(i+1)*slitstep/sdisc/sdisc))/2*slitstep;
        }
        slitEff=pow((2*relativ/(sdisc*sqrt(M_PI*2))),2);
        ui->doubleSpinBox_30->setValue(slitEff*100);
    }

    // rectangular slit
    if(ui->checkBox_9->isChecked()){

        double slitstep=0.0001;
        int steps1=s/2/slitstep+1;
        int steps2=sl/2/slitstep+1;
        double relativ1=0, relativ2=0;
        for(int i =0; i<steps1-1; i++){
            relativ1+=(exp(-i*slitstep*i*slitstep/2/sdisc/sdisc)+exp(-(i+1)*slitstep*(i+1)*slitstep/2/sdisc/sdisc))/2*slitstep;
        }
        if(sl!=0){
            for(int i =0; i<steps2-1; i++){
                relativ2+=(exp(-i*slitstep*i*slitstep/2/sdisc/sdisc)+exp(-(i+1)*slitstep*(i+1)*slitstep/2/sdisc/sdisc))/2*slitstep;
            }
        }
        else{
            relativ2+=sdisc*sqrt(M_PI*2)/2;
        }
        slitEff=2*relativ1*2*relativ2/pow((sdisc*sqrt(2*M_PI)),2);
        ui->doubleSpinBox_30->setValue(slitEff*100);
    }

    // slitless
    if(ui->checkBox->isChecked()){
        slitEff=1.0;
        ui->doubleSpinBox_30->setValue(100);
    }
    sdisc=sdisc*2.3548;

}

//overview of wavelength coverage
void MainWindow::overview(){

    d=cos(M_PI/180*theta)/g;

    QString Output;

    f2nd = ui->doubleSpinBox_37->value();
    ftrans = ui->doubleSpinBox_32->value();
    PhiWP = f2nd/ftrans;

    // for grating CD
    if(e==1){

        if(ui->checkBox_2->isChecked()){
            bm = atan(lx*p/2/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx*p/2/f2)*180/M_PI;
        }

        lz = (l1+(l2-l1)/2)/1000000;
        dc = cos(M_PI/180*thetac)/gc;
        a = theta+t/2;
        b = theta-t/2;

        acc = asin(ncd*l1/1000000*gc/(2*cos(M_PI/180*tc/2)))*180/M_PI+tc/2;
        bcc = acc-tc;

        if(ui->checkBox_2->isChecked()){
            bmc = atan(ly*p/2/f2)*180/M_PI;
        }
        else{
            bmc = atan(ly*p/2/f2/PhiWP)*180/M_PI;
        }

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
        if(ui->checkBox_2->isChecked()){
            bm = atan(lx*p/2/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx*p/2/f2)*180/M_PI;
        }

        lz = (l1+(l2-l1)/2);
        a = theta+t/2;
        b = theta-t/2;
        at = sin(M_PI/180*(a-theta));

        l1 = l1/1000;
        l2 = l2/1000;
        lz = lz/1000;
        np = sqrt(1+B1*l1*l1/(l1*l1-C1)+B2*l1*l1/(l1*l1-C2)+B3*l1*l1/(l1*l1-C3));
        double n2 = sqrt(1+B1*l2*l2/(l2*l2-C1)+B2*l2*l2/(l2*l2-C2)+B3*l2*l2/(l2*l2-C3));
        double nz = sqrt(1+B1*lz*lz/(lz*lz-C1)+B2*lz*lz/(lz*lz-C2)+B3*lz*lz/(lz*lz-C3));
        cout<<np<<endl;
        cout<<n2<<endl;
        cout<<nz<<endl;
        l1 = l1*1000;
        l2 = l2*1000;
        lz = lz*1000;

        if(ui->checkBox_2->isChecked()){
            bmc = atan(ly*p/2/f2/PhiWP)*180/M_PI;
        }
        else{
            bmc = atan(ly*p/2/f2)*180/M_PI;
        }

        acc = asin(nz*sin(M_PI/180*30))*180/M_PI;
        double acp = asin(np*sin(M_PI/180*30))*180/M_PI;
        double ac2 = asin(n2*sin(M_PI/180*30))*180/M_PI;
        double lyp=0, ly2=0;
        if(ui->checkBox_2->isChecked()){
            if(ui->checkBox_3->isChecked()){
                lyp = tan(2*(acp-acc)/180*M_PI)*f2*PhiWP;
                ly2 = tan(2*(ac2-acc)/180*M_PI)*f2*PhiWP;
            }
            else{
                lyp = tan((acp-acc)/180*M_PI)*f2*PhiWP;
                ly2 = tan((ac2-acc)/180*M_PI)*f2*PhiWP;
            }
        }
        else{
            lyp = tan((acp-acc)/180*M_PI)*f2;
            ly2 = tan((ac2-acc)/180*M_PI)*f2;
        }

        cout<<"ly: "<<ly*p<<"; lyp: "<<lyp<<"; ly2"<<ly2<<endl;
        bcc = acc;
        atc = sin(M_PI/180*(acc-thetac));

        nl = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l1*1000000;
        nh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/l2*1000000;

        llc = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nl*g);
        llh = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/(nh*g);

        nl1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llc;
        nh1 = (sin(M_PI/180*a)+sin(M_PI/180*(b)))/g/llh;

        llow = llc - p*Bx*cos(b*M_PI/180)/(f2*nl*g)*lx/2;
        lhigh = llh + p*Bx*cos(b*M_PI/180)/(f2*nh*g)*lx/2;

        Output=QString::number(lz);
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

    QString qPath = ui->lineEdit_2->text();
    string path = qPath.toUtf8().constData();

    if(ui->checkBox->isChecked()){
        s = tan(ui->doubleSpinBox_29->value()/3600*M_PI/180)*ui->doubleSpinBox_35->value();
    }
    else{
        s = ui->doubleSpinBox_14->value();
    }

    int counter=0, bini=0, bini2=0, bini3=0, bini4=0, bini5=0, bini6=0;
    double Il1, Il2, Il1c, Il2c, reflectance=1, index;

    std::ostringstream datNameStream(path);
    datNameStream<<path<<"/resolution.txt";
    std::string datName = datNameStream.str();
    ofstream file1(datName.c_str());

    std::ostringstream dat2NameStream(path);
    dat2NameStream<<path<<"/anamorphism.txt";
    std::string dat2Name = dat2NameStream.str();
    ofstream file2(dat2Name.c_str());

    std::ostringstream dat3NameStream(path);
    dat3NameStream<<path<<"/slit.txt";
    std::string dat3Name = dat3NameStream.str();
    ofstream file3(dat3Name.c_str());

    std::ostringstream dat4NameStream(path);
    dat4NameStream<<path<<"/nyquist.txt";
    std::string dat4Name = dat4NameStream.str();
    ofstream file4(dat4Name.c_str());

    std::ostringstream dat5NameStream(path);
    dat5NameStream<<path<<"/dispersion.txt";
    std::string dat5Name = dat5NameStream.str();
    ofstream file5(dat5Name.c_str());

    std::ostringstream dat6NameStream(path);
    dat6NameStream<<path<<"/atmosphere.txt";
    std::string dat6Name = dat6NameStream.str();
    ofstream file6(dat6Name.c_str());

    std::ostringstream dat7NameStream(path);
    dat7NameStream<<path<<"/telescope.txt";
    std::string dat7Name = dat7NameStream.str();
    ofstream file7(dat7Name.c_str());

    std::ostringstream dat8NameStream(path);
    dat8NameStream<<path<<"/ccd.txt";
    std::string dat8Name = dat8NameStream.str();
    ofstream file8(dat8Name.c_str());

    std::ostringstream dat9NameStream(path);
    dat9NameStream<<path<<"/echelle.txt";
    std::string dat9Name = dat9NameStream.str();
    ofstream file9(dat9Name.c_str());

    std::ostringstream dat10NameStream(path);
    dat10NameStream<<path<<"/grating.txt";
    std::string dat10Name = dat10NameStream.str();
    ofstream file10(dat10Name.c_str());

    std::ostringstream dat11NameStream(path);
    dat11NameStream<<path<<"/gratings.txt";
    std::string dat11Name = dat11NameStream.str();
    ofstream file11(dat11Name.c_str());

    std::ostringstream dat12NameStream(path);
    dat12NameStream<<path<<"/efficiency.txt";
    std::string dat12Name = dat12NameStream.str();
    ofstream file12(dat12Name.c_str());

    std::ostringstream dat13NameStream(path);
    dat13NameStream<<path<<"/overall.txt";
    std::string dat13Name = dat13NameStream.str();
    ofstream file13(dat13Name.c_str());

    std::ostringstream dat14NameStream(path);
    dat14NameStream<<path<<"/surfaces.txt";
    std::string dat14Name = dat14NameStream.str();
    ofstream file14(dat14Name.c_str());

    std::ostringstream dat15NameStream(path);
    dat15NameStream<<path<<"/twopixR.txt";
    std::string dat15Name = dat15NameStream.str();
    ofstream file15(dat15Name.c_str());


    if(al>0){

        std::ostringstream datNameStream(path);
        datNameStream<<path<<"/protected_Al.txt";
        std::string datName = datNameStream.str();

    QFile checkfile1(datName.c_str());

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
    ifstream input1(datName.c_str());

    while(std::getline(input1, line))
       ++ bini;

    input1.clear();
    input1.seekg(0, ios::beg);

    ali.resize(bini);
    alw.resize(bini);

    for (int i =0; i < bini; i++){
        input1 >> eins >> zwei;
        istringstream istr(eins);
        istr >> ali[i];
        istringstream istr1(zwei);
        istr1 >> alw[i];
    }
    input1.close();
}
    if(aluv>0){
        std::ostringstream dat2NameStream(path);
        dat2NameStream<<path<<"/UVEnhanced_Al.txt";
        std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

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
    ifstream input2(dat2Name.c_str());

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
        std::ostringstream dat3NameStream(path);
        dat3NameStream<<path<<"/protected_Ag.txt";
        std::string dat3Name = dat3NameStream.str();

    QFile checkfile3(dat3Name.c_str());

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
    ifstream input3(dat3Name.c_str());

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
        std::ostringstream dat4NameStream(path);
        dat4NameStream<<path<<"/protected_Au.txt";
        std::string dat4Name = dat4NameStream.str();

    QFile checkfile4(dat4Name.c_str());

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
    ifstream input4(dat4Name.c_str());

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
        std::ostringstream dat5NameStream(path);
        dat5NameStream<<path<<"/vis_ar.txt";
        std::string dat5Name = dat5NameStream.str();

    QFile checkfile5(dat5Name.c_str());

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
    ifstream input5(dat5Name.c_str());

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

        std::ostringstream dat6NameStream(path);
        dat6NameStream<<path<<in6;
        std::string dat6Name = dat6NameStream.str();

        QFile checkfile6(dat6Name.c_str());

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
        ifstream input6(dat6Name.c_str());

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

        if(ui->checkBox_2->isChecked()){
            bm = atan((lx/2)*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan((lx/2)*p/f2)*180/M_PI;
        }

        for(int i=0; i<nl-nh; i++){
            n[i]=nl-i;
            lw[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[i]*g);
            b1c[i] = asin(ncd*lw[i]*gc-sin(M_PI/180*acc))*180/M_PI;
            if(ui->checkBox_2->isChecked()){
                o[i] = -((ly-4*sdisc/p)-tan((b1c[i]-b1c[0])*M_PI/180)*f2*PhiWP/p);
            }
            else{
                o[i] = -((ly-4*sdisc/p)-tan((b1c[i]-b1c[0])*M_PI/180)*f2/p);
            }

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
            if(ui->checkBox_2->isChecked()){
                bm = atan((lx/2)*p/f2/PhiWP)*180/M_PI;
            }
            else{
                bm = atan((lx/2)*p/f2)*180/M_PI;
            }

            l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

            overlap[m]=(l11[lx/Bx-1]-l11[0])*1000000;
            separation[m]=o[m]-o[m-1];
        }

        for(int i=0; i<lx/Bx; i++){
            if(ui->checkBox_2->isChecked()){
                bm = atan((lx/2-i)*p*Bx/f2/PhiWP)*180/M_PI;
            }
            else{
                bm = atan((lx/2-i)*p*Bx/f2)*180/M_PI;
            }

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

            A[i] = cos(M_PI/180*a)/cos(M_PI/180*(b-bm));

            if(ui->checkBox_2->isChecked()){
                s2[i] = A[i] * f2/f1*s*PhiWP;
            }
            else{
                s2[i] = A[i] * f2/f1*s;
            }

            R[i] = l11[i]*n[m]*f1*g/(cos(M_PI/180*a)*s*A[i]);

            Nf[i] = s2[i]/p/2;
            Tr[i] = 1-0.0091224/cos(M_PI/180*z)/(pow(l11[i]*1000,4));
            if(ui->checkBox_2->isChecked()){
                D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g*PhiWP);
            }
            else{
                D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g);
            }

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
            }
        }
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
                if(ui->checkBox_2->isChecked()){
                    bm = atan(lx*p/2/f2/PhiWP)*180/M_PI;
                }
                else{
                    bm = atan(lx*p/2/f2)*180/M_PI;
                }

               l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
               index=sqrt(1+B1*l11[m]*l11[m]/(l11[m]*l11[m]-C1)+B2*l11[m]*l11[m]/(l11[m]*l11[m]-C2)+B3*l11[m]*l11[m]/(l11[m]*l11[m]-C3));
               l11[m]=l11[m]/1000;
               b1c[m]=einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;
               gamma2=einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;

               if(ui->checkBox_2->isChecked()){
                   if(ui->checkBox_3->isChecked()){
                       o[m] = -((ly-4*sdisc/p)-tan(2*(startb-b1c[m])*M_PI/180)*f2*PhiWP/p);
                   }
                   else{
                       o[m] = -((ly-4*sdisc/p)-tan((startb-b1c[m])*M_PI/180)*f2*PhiWP/p);
                   }

               }
               else{
                   o[m] = -((ly-4*sdisc/p)-tan((startb-b1c[m])*M_PI/180)*f2/p);
               }

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

                if(ui->checkBox_2->isChecked()){
                    bm = atan((lx/2-i)*p*Bx/f2/PhiWP)*180/M_PI;
                }
                else{
                    bm = atan((lx/2-i)*p*Bx/f2)*180/M_PI;
                }

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

                A[i] = cos(M_PI/180*a)/cos(M_PI/180*(b-bm));

                if(ui->checkBox_2->isChecked()){
                    s2[i] = A[i] * f2/f1*s*PhiWP;
                }
                else{
                    s2[i] = A[i] * f2/f1*s;
                }

                R[i] = l11[i]*n[m]*f1*g/(cos(M_PI/180*a)*s*A[i]);
                if(ui->checkBox_2->isChecked()){
                    D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g*PhiWP);
                }
                else{
                    D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g);
                }

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
                }
            }

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

        if(ui->checkBox_2->isChecked()){
            bm = atan(lx/2*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx/2*p/f2)*180/M_PI;
        }

        alpha_2b=asin(ncd*tDCG/1000000/nDCG/2*gc)*180/M_PI;

        for(int i=0; i<nl-nh; i++){
            n[i]=nl-i;
            lw[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[i]*g);
            b1c[i] = asin(ncd*lw[i]*gc-sin(M_PI/180*acc))*180/M_PI;
            if(ui->checkBox_2->isChecked()){
                o[i] = -((ly-4*sdisc/p)-tan((b1c[i]-b1c[0])*M_PI/180)*f2*PhiWP/p);
            }
            else{
                o[i] = -((ly-4*sdisc/p)-tan((b1c[i]-b1c[0])*M_PI/180)*f2/p);
            }

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
                if(ui->checkBox_2->isChecked()){
                    bm = atan(lx/2*p/f2/PhiWP)*180/M_PI;
                }
                else{
                    bm = atan(lx/2*p/f2)*180/M_PI;
                }

                l11[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

                overlap[m]=(l11[lx/Bx-1]-l11[0])*1000000;
                separation[m]=o[m]-o[m-1];
            }

        for(int i=0; i<lx/Bx; i++){
            if(ui->checkBox_2->isChecked()){
                bm = atan((lx/2-i)*Bx*p/f2/PhiWP)*180/M_PI;
            }
            else{
                bm = atan((lx/2-i)*Bx*p/f2)*180/M_PI;
            }

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

            A[i] = cos(M_PI/180*a)/cos(M_PI/180*(b-bm));

            if(ui->checkBox_2->isChecked()){
                s2[i] = A[i] * f2/f1*s*PhiWP;
            }
            else{
                s2[i] = A[i] * f2/f1*s;
            }

            R[i] = l11[i]*n[m]*f1*g/(cos(M_PI/180*a)*s*A[i]);

            Nf[i] = s2[i]/p/2;
            Tr[i] = 1-0.0091224/cos(M_PI/180*z)/(pow(l11[i]*1000,4));

            if(ui->checkBox_2->isChecked()){
                D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g*PhiWP);
            }
            else{
                D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g);
            }

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
            }
        }
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
            if(ui->checkBox_2->isChecked()){
                bm = atan((lx/2)*p/f2/PhiWP)*180/M_PI;
            }
            else{
                bm = atan((lx/2)*p/f2)*180/M_PI;
            }

            lw[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
            index=sqrt(1+B1*lw[m]*lw[m]/(lw[m]*lw[m]-C1)+B2*lw[m]*lw[m]/(lw[m]*lw[m]-C2)+B3*lw[m]*lw[m]/(lw[m]*lw[m]-C3));
            lw[m]=lw[m]/1000;

            b11=asin(sin(theta2*M_PI/180/index))*180/M_PI;
            b12=asin(lw[m]*gc/index*ncd-sin(theta2*M_PI/180-b11*M_PI/180))*180/M_PI;

            b1c[m]=asin(index*sin(theta2*M_PI/180-b12*M_PI/180))*180/M_PI;
            if(ui->checkBox_2->isChecked()){
                o[m] = -((ly-4*sdisc/p)-tan((b1c[0]-b1c[m])*M_PI/180)*f2*PhiWP/p);
            }
            else{
                o[m] = -((ly-4*sdisc/p)-tan((b1c[0]-b1c[m])*M_PI/180)*f2/p);
            }

            if(m>0){
                separation[m]=o[m]-o[m-1];
                overlap[m]=(l11[lx/Bx-1]-lw[m])*1000000;
            }
            if(o[m]>0){
                ++counter;
            }

            for(int i=0; i<lx/Bx; i++){

                if(ui->checkBox_2->isChecked()){
                    bm = atan((lx/2-i*Bx)*p/f2/PhiWP)*180/M_PI;
                }
                else{
                    bm = atan((lx/2-i*Bx)*p/f2)*180/M_PI;
                }

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

                A[i] = cos(M_PI/180*a)/cos(M_PI/180*(b-bm));
                if(ui->checkBox_2->isChecked()){
                    s2[i] = A[i] * f2/f1*s*PhiWP;
                }
                else{
                    s2[i] = A[i] * f2/f1*s;
                }

                R[i] = l11[i]*n[m]*f1*g/(cos(M_PI/180*a)*s*A[i]);

                if(ui->checkBox_2->isChecked()){
                    D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g*PhiWP);
                }
                else{
                    D[i] = p*Bx*cos((b-bm)*M_PI/180)/(f2*n[m]*g);
                }

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
                }
            }
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

//********************************
// calculate Échellogram
//********************************
void MainWindow::Echellogram()
{

    this->setCursor(QCursor(Qt::WaitCursor));

    QString qPath = ui->lineEdit_2->text();
    string path = qPath.toUtf8().constData();

    std::ostringstream datNameStream(path);
    datNameStream<<path<<"/echello.txt";
    std::string datName = datNameStream.str();
    ofstream file1(datName.c_str());

    int yoff = ui->spinBox_12->value();


    if(ui->checkBox->isChecked()){
        s = tan(ui->doubleSpinBox_29->value()/3600*M_PI/180)*ui->doubleSpinBox_35->value();
        if(ui->checkBox_2->isChecked()){
            FWHM=s/p*f2/f1*PhiWP;
        }
        else{
           FWHM=s/p*f2/f1;
        }
    }
    else{
        s = ui->doubleSpinBox_14->value();
        if(ui->checkBox_8->isChecked()){
            if(ui->checkBox_2->isChecked()){
                FWHM=s/p*f2/f1*PhiWP;
            }
            else{
                FWHM=s/p*f2/f1;
            }
        }
        else{
            if(ui->checkBox_2->isChecked()){
                FWHM=sl/p*f2/f1*PhiWP;
            }
            else{
               FWHM=sl/p*f2/f1;
            }
        }
    }


    lw.resize(lx/Bx);
    b1c.resize(lx/Bx);
    o.resize(lx/Bx);
    l11.resize(lx/Bx);

    double startb, index;

    int ovlap=0;

    std::ostringstream dat2NameStream(path);
    dat2NameStream<<path<<"/echellogram.dat";
    std::string dat2Name = dat2NameStream.str();
    ofstream egram(dat2Name.c_str());

    egram<<"rel. order.\tabs. order\tlower wave\tmiddle wave\tupper wave\toverlap"<<endl;

    // Échellogram Prism
    if(e==0){

        if(ui->checkBox_2->isChecked()){
            bm = atan((lx)*p/2/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan((lx)*p/2/f2)*180/M_PI;
        }

        o[0]=(ly-4*sdisc/p+yoff);
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
                if(ui->checkBox_2->isChecked()){
                    bm = atan((lx/2-i*Bx)*p/f2/PhiWP)*180/M_PI;
                }
                else{
                    bm = atan((lx/2-i*Bx)*p/f2)*180/M_PI;
                }

                l11[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
                index=sqrt(1+B1*l11[i]*l11[i]/(l11[i]*l11[i]-C1)+B2*l11[i]*l11[i]/(l11[i]*l11[i]-C2)+B3*l11[i]*l11[i]/(l11[i]*l11[i]-C3));
                l11[i]=l11[i]/1000;
                b1c[i]=einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;
                //b1c[i]=180/M_PI*asin(sin(M_PI/180*60)*sqrt(index*index-sin(einf*M_PI/180)*sin(M_PI/180*einf))-sin(einf*M_PI/180)*cos(M_PI/180*60));
                if(ui->checkBox_2->isChecked()){
                    if(ui->checkBox_3->isChecked()){
                        o[i] = ((ly-4*sdisc/p+yoff)-tan(2*(startb-b1c[i])*M_PI/180)*f2*PhiWP/p);
                    }
                    else{
                        o[i] = ((ly-4*sdisc/p+yoff)-tan((startb-b1c[i])*M_PI/180)*f2*PhiWP/p);
                    }
                }
                else{
                    o[i] = ((ly-4*sdisc/p+yoff)-tan((startb-b1c[i])*M_PI/180)*f2/p);
                }


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

        if(ui->checkBox_2->isChecked()){
            bm = atan((lx/2)*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan((lx/2)*p/f2)*180/M_PI;
        }

        lw[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g);
        startb= asin(ncd*lw[0]*gc-sin(M_PI/180*acc))*180/M_PI;

        for(int i=0; i<nl-nh; i++){
            n[i]=nl-i;
            egram<<i<<"\t\t"<<n[i]<<"\t\t";

            for(int m=0; m<lx/Bx; m++){
                if(ui->checkBox_2->isChecked()){
                    bm = atan((lx/2-m*Bx)*p/f2/PhiWP)*180/M_PI;
                }
                else{
                    bm = atan((lx/2-m*Bx)*p/f2)*180/M_PI;
                }

                lw[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[i]*g);
                b1c[m] = asin(ncd*lw[m]*gc-sin(M_PI/180*acc))*180/M_PI;
                if(ui->checkBox_2->isChecked()){
                    o[m] = (ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*M_PI/180)*f2*PhiWP/p;
                }
                else{
                    o[m] = (ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*M_PI/180)*f2/p;
                }

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

        if(ui->checkBox_2->isChecked()){
            bm = atan(lx/2*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx/2*p/f2)*180/M_PI;
        }

        double alpha_2b=asin(ncd*tDCG/1000000/nDCG/2*gc)*180/M_PI;

        lw[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g);
        startb = asin(ncd*lw[0]*gc-sin(M_PI/180*acc))*180/M_PI;

        for(int m=0; m<nl-nh; m++){
            n[m]=nl-m;
            egram<<m<<"\t\t"<<n[m]<<"\t\t";
            for(int i=0; i<lx/Bx; i++){
                if(ui->checkBox_2->isChecked()){
                    bm = atan((lx/2-i*Bx)*p/f2/PhiWP)*180/M_PI;
                }
                else{
                    bm = atan((lx/2-i*Bx)*p/f2)*180/M_PI;
                }

                lw[i] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);
                b1c[i] = asin(ncd*lw[i]*gc-sin(M_PI/180*acc))*180/M_PI;
                if(ui->checkBox_2->isChecked()){
                    o[i] = (ly-4*sdisc/p+yoff)-tan((b1c[i]-startb)*M_PI/180)*f2*PhiWP/p;
                }
                else{
                    o[i] = (ly-4*sdisc/p+yoff)-tan((b1c[i]-startb)*M_PI/180)*f2/p;
                }

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

        if(ui->checkBox_2->isChecked()){
            bm = atan(lx/2*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx/2*p/f2)*180/M_PI;
        }

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
                if(ui->checkBox_2->isChecked()){
                    bm = atan((lx/2-m*Bx)*p/f2/PhiWP)*180/M_PI;
                }
                else{
                   bm = atan((lx/2-m*Bx)*p/f2)*180/M_PI;
                }

                lw[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[i]*g)*1000;
                index=sqrt(1+B1*lw[m]*lw[m]/(lw[m]*lw[m]-C1)+B2*lw[m]*lw[m]/(lw[m]*lw[m]-C2)+B3*lw[m]*lw[m]/(lw[m]*lw[m]-C3));
                lw[m]=lw[m]/1000;

                b11=asin(sin(theta2*M_PI/180/index))*180/M_PI;
                b12=asin(lw[m]*gc/index*ncd-sin(theta2*M_PI/180-b11*M_PI/180))*180/M_PI;

                b1c[m]=asin(index*sin(theta2*M_PI/180-b12*M_PI/180))*180/M_PI;
                if(ui->checkBox_2->isChecked()){
                    o[m] = (ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*M_PI/180)*f2*PhiWP/p;
                }
                else{
                    o[m] = (ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*M_PI/180)*f2/p;
                }

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
    qEchelle->seData(ui->lineEdit_2->text(), ui->spinBox_10->value(), ui->spinBox_11->value());
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
    qFrameEchelle->seData(ui->lineEdit_2->text(), ui->spinBox_10->value(), ui->spinBox_11->value());
    qFrameEchelle->show();
}

//**********************************
// Create CCD Frame
//**********************************
void MainWindow::on_pushButton_7_clicked()
{   
    this->setCursor(QCursor(Qt::WaitCursor));

    ui->progressBar->setValue(0);

    QString qPath = ui->lineEdit_2->text();
    string path = qPath.toUtf8().constData();

    int yoff = ui->spinBox_12->value();


    //ofstream file1(datName.c_str());

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

    std::ostringstream datNameStream(path);

    if(ui->comboBox_3->currentIndex()==0){
      datNameStream<<path<<"/planckech.txt";
    }
    if(ui->comboBox_3->currentIndex()==1){
      datNameStream<<path<<"/neonech.txt";
    }
    if(ui->comboBox_3->currentIndex()==2){
      datNameStream<<path<<"/balmerech.txt";
    }
    if(ui->comboBox_3->currentIndex()==3){
      datNameStream<<path<<"/tharech.txt";
    }

    std::string datName = datNameStream.str();

    ofstream out1(datName.c_str());
    /*ofstream out2("balmerech.txt");
    ofstream out3("planckech.txt");
    ofstream out4("tharech.txt");*/

    std::ostringstream dat2NameStream(path);
    dat2NameStream<<path<<"/framech1.txt";
    std::string dat2Name = dat2NameStream.str();
    ofstream file1(dat2Name.c_str());

    MainWindow::revectors();
    MainWindow::overview();
    MainWindow::parameters();

    double Il1, Il2, Il1c, Il2c;
    QVector<double> al(1), bl(1), lineech(1);
    int number_of_lines;
    string zeile, one, two;

    if(ui->comboBox_3->currentIndex()==1){

        std::ostringstream datNameStream(path);
        datNameStream<<path<<"/neon_line.txt";
        std::string datName = datNameStream.str();

        QFile checkfile2(datName.c_str());

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
        ifstream input(datName.c_str());

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
        std::ostringstream datNameStream(path);
        datNameStream<<path<<"/absor_line.txt";
        std::string datName = datNameStream.str();

        QFile checkfile2(datName.c_str());

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

        ifstream input(datName.c_str());

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
        std::ostringstream datNameStream(path);
        datNameStream<<path<<"/thar_uves.txt";
        std::string datName = datNameStream.str();

        QFile checkfile2(datName.c_str());

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
        ifstream input(datName.c_str());

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

    if(ui->checkBox_9->isChecked()){
        sdisc = ui->doubleSpinBox_15->value();
    }
    else{
        if(ui->checkBox_8->isChecked()){
            sdisc = ui->doubleSpinBox_14->value();
        }
        else{
            sdisc = sdisc;
        }
    }


    // Prism
    if(e==0){

        if(ui->checkBox_2->isChecked()){
            bm = atan(lx/2*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx/2*p/f2)*180/M_PI;
        }

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
            if(ui->checkBox_2->isChecked()){
                bm = atan((lx/2-i)*p/f2/PhiWP)*180/M_PI;
            }
            else{
                bm = atan((lx/2-i)*p/f2)*180/M_PI;
            }

             for (int v=0; v < ly/By; v++){

                  for (int m =0; m < nl-nh; m++){
                      I1[m]=0;

                        n[m]=nl-m;
                        l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g)*1000;
                        index=sqrt(1+B1*l11[m]*l11[m]/(l11[m]*l11[m]-C1)+B2*l11[m]*l11[m]/(l11[m]*l11[m]-C2)+B3*l11[m]*l11[m]/(l11[m]*l11[m]-C3));

                        Tr[m] = 1-0.0091224/cos(M_PI/180*z)/(pow(l11[m],4));
                        //l11[m]=l11[m]/1000;
                        l11[m]=l11[m]*10000;
                        CCD[m] = ap/(l11[m]*l11[m]*l11[m]*l11[m]*l11[m])/(exp(143877500/l11[m]/CCDT)-1)/CCDm*CCDp;
                        l11[m]=l11[m]/10000000;
                        b1c[m]=einf-60+asin(index*sin(M_PI/180*(60-asin(indexlz/2/index)*180/M_PI)))*180/M_PI;
                        //b1c[m]=einf-60+180/M_PI*asin(sin(60*M_PI/180)*sqrt(index*index-sin(einf*M_PI/180)*sin(einf*M_PI/180))-sin(einf*M_PI/180)*cos(60*M_PI/180));
                        //l11[m]=l11[m]/1000;
                        b1[m] = asin(n[m]*l11[m]*g-sin(M_PI/180*a))*180/M_PI;
                        bt[m] = sin(M_PI/180*(b1[m]-theta));
                        D[m] = p*Bx*cos(b1[m]*M_PI/180)/(f2*n[m]*g);
                        A[m] = cos(M_PI/180*a)/cos(M_PI/180*b1[m]);
                        if(ui->checkBox_2->isChecked()){
                            s2[m] = A[m] * f2/f1*s*PhiWP;
                        }
                        else{
                            s2[m] = A[m] * f2/f1*s;
                        }

                        if(ui->checkBox_2->isChecked()){
                            if(ui->checkBox_3->isChecked()){
                                o[m] = -((ly-4*sdisc/p+yoff)-tan(2*(startb-b1c[m])*M_PI/180)*f2*PhiWP/p)/By;
                            }
                            else{
                                o[m] = -((ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*M_PI/180)*f2*PhiWP/p)/By;
                            }
                        }
                        else{
                            o[m] = -((ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*M_PI/180)*f2/p)/By;
                        }

                        //o[m] = -((ly-4*sdisc/p)-tan((startb-b1c[m])*M_PI/180)*f2/p)/By;
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

                    out1<<scientific<<i<<" "<<v<<" "<<I<<endl;

                    file1<<scientific<<I<<" ";
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

            out1.close();

    }

    // Grating
    if(e==1){

        n[0]=nl;
        o[0] = -(ly-4*sdisc/p+yoff)/By;
        l[0] = (sin(Pi/180*a)+sin(Pi/180*(b)))/(nl*g);
        lw[0] = (sin(Pi/180*a)+sin(Pi/180*(b-bm)))/(nl*g);
        b1c[0] = asin(ncd*lw[0]*gc-sin(Pi/180*acc))*180/Pi;
        b1[0] = asin(nl*lw[0]*g-sin(Pi/180*a))*180/Pi;

        if(ui->checkBox_2->isChecked()){
            bm = atan(lx/2*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx/2*p/f2)*180/M_PI;
        }


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
            if(ui->checkBox_2->isChecked()){
                o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2*PhiWP/p)/By;
            }
            else{
                o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
            }
            //o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
                                    }

        for (int i=0; i < lx/Bx; i++){

             for (int v=0; v < ly/By; v++){

                 for (int m =0; m < nl-nh; m++){
                    n[m]=nl-m;
                    if(ui->checkBox_2->isChecked()){
                        bm = atan((lx/2-i)*p/f2/PhiWP)*180/M_PI;
                    }
                    else{
                        bm = atan((lx/2-i)*p/f2)*180/M_PI;
                    }

                    l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

                    b1c[m] = asin(ncd*l11[m]*gc-sin(M_PI/180*acc))*180/M_PI;
                    btc[m] = sin(M_PI/180*(b1c[m]-thetac));

                    b1[m] = asin(n[m]*l11[m]*g-sin(M_PI/180*a))*180/M_PI;
                    bt[m] = sin(M_PI/180*(b1[m]-theta));

                    D[m] = p*Bx*cos(b1[m]*Pi/180)/(f2*n[m]*g);
                    A[m] = cos(Pi/180*a)/cos(Pi/180*b1[m]);
                    if(ui->checkBox_2->isChecked()){
                        s2[m] = A[m] * f2/f1*s*PhiWP;
                    }
                    else{
                        s2[m] = A[m] * f2/f1*s;
                    }
                    if(ui->checkBox_2->isChecked()){
                        o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2*PhiWP/p)/By;
                    }
                    else{
                        o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
                    }

                    //o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
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


                    out1<<i<<" "<<v<<" "<<I<<endl;

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

            out1.close();
    }

    // VPH Grating
    if(e==2){

        double alpha_2b, eta_s, eta_p;
        alpha_2b=asin(ncd*lz/indexlz/2*g)*180/M_PI;

        if(ui->checkBox_2->isChecked()){
            bm = atan(lx/2*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx/2*p/f2)*180/M_PI;
        }

        lw[0] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(nl*g);
        double startb = asin(ncd*lw[0]*gc-sin(M_PI/180*acc))*180/M_PI;

        n[0]=nl;
        o[0] = -(ly-4*sdisc/p+yoff)/By;
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
            if(ui->checkBox_2->isChecked()){
                o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2*PhiWP/p)/By;
            }
            else{
                o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
            }

            //o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
        }

        for (int i=0; i < lx/Bx; i++){

            for (int v=0; v < ly/By; v++){

                for (int m =0; m < nl-nh; m++){
                    n[m]=nl-m;
                    if(ui->checkBox_2->isChecked()){
                        bm = atan((lx/2-i)*p/f2/PhiWP)*180/M_PI;
                    }
                    else{
                        bm = atan((lx/2-i)*p/f2)*180/M_PI;
                    }

                    l11[m] = (sin(M_PI/180*a)+sin(M_PI/180*(b-bm)))/(n[m]*g);

                    b1c[m] = asin(ncd*l11[m]*gc-sin(M_PI/180*acc))*180/M_PI;
                    btc[m] = sin(M_PI/180*(b1c[m]-thetac));

                    b1[m] = asin(n[m]*l11[m]*g-sin(M_PI/180*a))*180/M_PI;
                    bt[m] = sin(M_PI/180*(b1[m]-theta));

                    D[m] = p*Bx*cos(b1[m]*Pi/180)/(f2*n[m]*g);

                    A[m] = cos(Pi/180*a)/cos(Pi/180*b1[m]);
                    if(ui->checkBox_2->isChecked()){
                        s2[m] = A[m] * f2/f1*s*PhiWP;
                    }
                    else{
                        s2[m] = A[m] * f2/f1*s;
                    }

                    if(ui->checkBox_2->isChecked()){
                        o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2*PhiWP/p)/By;
                    }
                    else{
                        o[m] = -((ly-4*sdisc/p+yoff)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
                    }

                    //o[m] = -((ly-4*sdisc/p)-tan((b1c[m]-startb)*Pi/180)*f2/p)/By;
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


                        out1<<i<<" "<<v<<" "<<I<<endl;

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

            out1.close();

    }

    // Frame VPH Grism
    if(e==3){

        double alpha_2b, eta_s, eta_p, index, b11, b12, startb;
        alpha_2b=asin(ncd*lz/indexlz/2*g)*180/M_PI;

        n[0]=nl;
        o[0] = -(ly-4*sdisc/p+yoff)/By;
        l[0] = (sin(Pi/180*a)+sin(Pi/180*(b)))/(nl*g);
        lw[0] = (sin(Pi/180*a)+sin(Pi/180*(b-bm)))/(nl*g);
        b1c[0] = asin(ncd*lw[0]*gc-sin(Pi/180*acc))*180/Pi;
        if(ui->checkBox_2->isChecked()){
            bm = atan(lx/2*p/f2/PhiWP)*180/M_PI;
        }
        else{
            bm = atan(lx/2*p/f2)*180/M_PI;
        }

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
            if(ui->checkBox_2->isChecked()){
                o[m] = -((ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*Pi/180)*f2*PhiWP/p)/By;
            }
            else{
                o[m] = -((ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*Pi/180)*f2/p)/By;
            }
            //o[m] = -((ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*Pi/180)*f2/p)/By;
        }

        for (int i=0; i < lx/Bx; i++){

            for (int v=0; v < ly/By; v++){

                for (int m =0; m < nl-nh; m++){
                    n[m]=nl-m;
                    if(ui->checkBox_2->isChecked()){
                        bm = atan((lx/2-i)*p/f2/PhiWP)*180/M_PI;
                    }
                    else{
                        bm = atan((lx/2-i)*p/f2)*180/M_PI;
                    }

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
                    if(ui->checkBox_2->isChecked()){
                        s2[m] = A[m] * f2/f1*s*PhiWP;
                    }
                    else{
                        s2[m] = A[m] * f2/f1*s;
                    }

                    if(ui->checkBox_2->isChecked()){
                        o[m] = -((ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*Pi/180)*f2*PhiWP/p)/By;
                    }
                    else{
                        o[m] = -((ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*Pi/180)*f2/p)/By;
                    }

                    //o[m] = -((ly-4*sdisc/p+yoff)-tan((startb-b1c[m])*Pi/180)*f2/p)/By;
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

                    out1<<i<<" "<<v<<" "<<I<<endl;

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

            out1.close();

    }

    qFrameEchelle = new FrameEchelle(this);
    qFrameEchelle->seData(ui->lineEdit_2->text(), ui->spinBox_10->value(), ui->spinBox_11->value());
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

// reload Glass data
void MainWindow::on_pushButton_8_clicked()
{
    QString qPath = ui->lineEdit_2->text()+"/GlassData.slib";

    string path = qPath.toUtf8().constData();
    std::ostringstream datNameStream(path);
    datNameStream<<path;
    std::string datName = datNameStream.str();

    QFile checkfile1(datName.c_str());

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Error", "Glass data "+checkfile1.fileName()+" not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    else{

    ifstream glass(datName.c_str());

    while(std::getline(glass, line))
       ++ nglass;

    glass.clear();
    glass.seekg(0, ios::beg);

    SeB1.resize(nglass);
    SeB2.resize(nglass);
    SeB3.resize(nglass);
    SeC1.resize(nglass);
    SeC2.resize(nglass);
    SeC3.resize(nglass);
    GLASS.resize(nglass);

    for (int i =0; i < nglass; i++){
        glass >> eins >> zwei >> drei >> vier >> fuenf >> sechs >> sieben;
        istringstream istr(eins);
        istr >> GLASS[i];
        istringstream istr1(zwei);
        istr1 >> SeB1[i];
        istringstream istr2(drei);
        istr2 >> SeB2[i];
        istringstream istr3(vier);
        istr3 >> SeB3[i];
        istringstream istr4(fuenf);
        istr4 >> SeC1[i];
        istringstream istr5(sechs);
        istr5 >> SeC2[i];
        istringstream istr6(sieben);
        istr6 >> SeC3[i];

        QString gele=QString::fromStdString(istr.str());
        ui->comboBox->addItem(gele);
    }
    glass.close();


    B1=SeB1[0];
    B2=SeB2[0];
    B3=SeB3[0];
    C1=SeC1[0];
    C2=SeC2[0];
    C3=SeC3[0];
    }

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

   B1=SeB1[ce];
   B2=SeB2[ce];
   B3=SeB3[ce];
   C1=SeC1[ce];
   C2=SeC2[ce];
   C3=SeC3[ce];
}

// uncoated Surfaces
void MainWindow::on_spinBox_6_valueChanged()
{
    Frenl=1;

    unc=ui->spinBox_6->value();
    int unc2=ui->tableWidget->rowCount();
    Frea.resize(unc);
    Fren.resize(unc);
    Frp.resize(unc);
    Frs.resize(unc);
    Fr.resize(unc);

        if(unc>unc2){
            for(int i=0; i<unc-unc2; i++){
                ui->tableWidget->insertRow(unc2+i);
            }
        }
        if(unc<unc2){
            for(int i=0; i<unc2-unc; i++){
                ui->tableWidget->removeRow(unc2-i-1);
            }
        }
        ui->tableWidget->setRowCount(unc);

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
  }
  else {
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
    ui->doubleSpinBox_37->setValue(variables[47]);
    ui->doubleSpinBox_32->setValue(variables[48]);


      qApp->processEvents(QEventLoop::AllEvents);
}

void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open", "","conf files (*.conf);;");

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
    file<<cint<<endl;
    file<<ui->doubleSpinBox_37->value()<<endl;
    file<<ui->doubleSpinBox_32->value()<<endl;

    file.close();
}


void MainWindow::on_actionFPE_triggered()
{
    qFPE = new FPE(this);
    qFPE->show();
}

void MainWindow::on_actionCzerny_Turner_triggered()
{
    qCT = new CzernyTurner(this);
    qCT->show();
}

void MainWindow::on_actionPetzval_triggered()
{
    qPetzval = new Petzval(this);
    qPetzval->seData(ui->lineEdit_2->text());
    qPetzval->show();
}

// Reload CCD Data
void MainWindow::on_pushButton_9_clicked()
{
    QString cPath = ui->lineEdit_2->text()+"/"+ui->lineEdit_4->text();

    string cpath = cPath.toUtf8().constData();
    std::ostringstream dat2NameStream(cpath);
    dat2NameStream<<cpath;
    std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Warning", "CCD data "+checkfile2.fileName()+" not available!");
    }

    else{
        nccd=0;
        ui->comboBox_4->clear();

    ifstream ccd(dat2Name.c_str());

    while(std::getline(ccd, line))
       ++ nccd;

    ccd.clear();
    ccd.seekg(0, ios::beg);

    CGain.resize(nccd);
    CEff.resize(nccd);
    CNoise.resize(nccd);
    Cpx.resize(nccd);
    Cpy.resize(nccd);
    Cpsx.resize(nccd);
    Cpsy.resize(nccd);
    CEw.resize(nccd);
    CCDt.resize(nccd);

    for (int i =0; i < nccd; i++){
        ccd >> eins >> zwei >> drei >> vier >> fuenf >> sechs >> sieben >> acht >> neun;
        istringstream istr(eins);
        istr >> CCDt[i];
        istringstream istr1(zwei);
        istr1 >> Cpx[i];
        istringstream istr2(drei);
        istr2 >> Cpy[i];
        istringstream istr3(vier);
        istr3 >> Cpsx[i];
        Cpsx[i]=Cpsx[i]/1000;
        istringstream istr4(fuenf);
        istr4 >> Cpsy[i];
        Cpsy[i]=Cpsy[i]/1000;
        istringstream istr5(sechs);
        istr5 >> CNoise[i];
        istringstream istr6(sieben);
        istr6 >> CGain[i];
        istringstream istr7(acht);
        istr7 >> CEw[i];
        istringstream istr8(neun);
        istr8 >> CEff[i];

        QString gele=QString::fromStdString(istr.str());
        ui->comboBox_4->addItem(gele);
    }
    ccd.close();

    lx = Cpx[0];
    ly = Cpy[0];
    p = Cpsx[0];
    readnoise = CNoise[0];
    CCDl = CEw[0];
    CCDp = CEff[0];
    gain = CGain[0];
    }
}

void MainWindow::on_comboBox_4_currentIndexChanged()
{
    int cc=ui->comboBox_4->currentIndex();

    lx = Cpx[cc];
    ly = Cpy[cc];
    p = Cpsx[cc];
    readnoise = CNoise[cc];
    CCDl = CEw[cc];
    CCDp = CEff[cc];
    gain = CGain[cc];

    ui->doubleSpinBox_33->setValue(p);

    ui->spinBox_10->setValue(lx);

    ui->spinBox_11->setValue(ly);

    ui->doubleSpinBox_17->setValue(readnoise);

    ui->doubleSpinBox_4->setValue(CCDl);

    ui->doubleSpinBox_3->setValue(CCDp);

    ui->doubleSpinBox_16->setValue(gain);

}

void MainWindow::on_pushButton_10_clicked()
{
    QFile::copy(ui->lineEdit_5->text()+"/al.txt", ui->lineEdit_2->text()+"/al.txt");
    QFile::copy(ui->lineEdit_5->text()+"/GlassData.slib", ui->lineEdit_2->text()+"/GlassData.slib");
    QFile::copy(ui->lineEdit_5->text()+"/LensData.slib", ui->lineEdit_2->text()+"/LensData.slib");
    QFile::copy(ui->lineEdit_5->text()+"/CCD_Data.slib", ui->lineEdit_2->text()+"/CCD_Data.slib");
    QFile::copy(ui->lineEdit_5->text()+"/neon_line.txt", ui->lineEdit_2->text()+"/neon_line.txt");
    QFile::copy(ui->lineEdit_5->text()+"/protected_Ag.txt", ui->lineEdit_2->text()+"/protected_Ag.txt");
    QFile::copy(ui->lineEdit_5->text()+"/protected_Al.txt", ui->lineEdit_2->text()+"/protected_Al.txt");
    QFile::copy(ui->lineEdit_5->text()+"/protected_Au.txt", ui->lineEdit_2->text()+"/protected_Au.txt");
    QFile::copy(ui->lineEdit_5->text()+"/absor_line.txt", ui->lineEdit_2->text()+"/absor_line.txt");
    QFile::copy(ui->lineEdit_5->text()+"/UVEnhanced_Al.txt", ui->lineEdit_2->text()+"/UVEnhanced_Al.txt");
    QFile::copy(ui->lineEdit_5->text()+"/unprotected_Au.txt", ui->lineEdit_2->text()+"/unprotected_Au.txt");
    QFile::copy(ui->lineEdit_5->text()+"/thar_uves.txt", ui->lineEdit_2->text()+"/thar_uves.txt");
    QFile::copy(ui->lineEdit_5->text()+"/vis_ar.txt", ui->lineEdit_2->text()+"/vis_ar.txt");
}

void MainWindow::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked()){
        ui->doubleSpinBox_37->setEnabled(true);
        ui->doubleSpinBox_32->setEnabled(true);
        ui->checkBox_3->setEnabled(true);
    }
    else{
        ui->doubleSpinBox_37->setEnabled(false);
        ui->doubleSpinBox_32->setEnabled(false);
        ui->checkBox_3->setEnabled(false);
    }
}
