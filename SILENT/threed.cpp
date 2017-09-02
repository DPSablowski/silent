#include "threed.h"
#include "ui_threed.h"
#include <pthreed.h>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iostream>
#include <QFile>
#include <QMessageBox>

using namespace std;

string tdpath;
double g3d, t3d, theta3d, eta3d, l3d, index3d, dn3d, d3d, dg3d, f13d, f23d, tune3d, seeing3d, T3d, BC3d, vm3d, z3d, ftel3d, dtel3d, sky3d, sdisc3d, slitEff3d, p3d, s3d, sl3d, offset3d, noise3d, gain3d, CCDp3d, CCDl3d, CCDT3d, CCDm3d;
double a3d, b3d, exptime3d, at3d, b13d, bt3d, Il13d, Il23d;
double k3d = 143877500;
double ap3d = 1.87088e24;
int n3d, slits3d, lx3d, ly3d, Bx3d, By3d, ag3d, al3d, aluv3d, au3d, bb3d, aal3d=0, aag3d=0, abb3d=0, aaluv3d=0, aau3d=0;
QVector<double> w3d(lx3d), R3d(lx3d), A3d(lx3d), s23d(lx3d), Nf3d(lx3d), Tr3d(lx3d), D3d(lx3d), CCD3d(lx3d), P3d(lx3d), I13d(lx3d), Ef3d(lx3d), al3dt(lx3d), aluv3dt(lx3d), au3dt(lx3d), ag3dt(lx3d), bb3dt(lx3d);
QVector<double> al3di(1), al3dw(1), ag3di(1), ag3dw(1), aluv3di(1), aluv3dw(1), au3di(1), au3dw(1), bb3di(1), bb3dw(1), emi3d(1), reflectance3d(lx3d);
int var3d=40;
QString qtdpath;

QVector<double> variables3d(var3d);
threed::threed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::threed)
{
    ui->setupUi(this);
    this->setWindowTitle("3D Spectrograph");

    ui->progressBar->setValue(0);

    ui->checkBox->setChecked(true);
    ui->checkBox_3->setChecked(true);
    ui->doubleSpinBox_21->setEnabled(false);

    ui->doubleSpinBox->setValue(300);
    g3d=ui->doubleSpinBox->value();

    ui->doubleSpinBox_2->setValue(4);
    theta3d=ui->doubleSpinBox_2->value();

    ui->doubleSpinBox_3->setValue(0.75);
    eta3d=ui->doubleSpinBox_3->value();

    ui->doubleSpinBox_4->setValue(550);
    l3d=ui->doubleSpinBox_4->value();

    ui->doubleSpinBox_5->setValue(20);
    t3d=ui->doubleSpinBox_5->value();

    a3d = asin(n3d*l3d/1000000*g3d/(2*cos(M_PI/180*t3d/2)))*180/M_PI+t3d/2;
    b3d = a3d-t3d;

    ui->doubleSpinBox_6->setValue(1.4987);
    index3d=ui->doubleSpinBox_6->value();

    ui->doubleSpinBox_7->setValue(0.06);
    dn3d=ui->doubleSpinBox_7->value();

    ui->doubleSpinBox_8->setValue(0.005);
    d3d=ui->doubleSpinBox_8->value();

    ui->doubleSpinBox_9->setValue(120);
    f13d=ui->doubleSpinBox_9->value();

    ui->doubleSpinBox_10->setValue(120);
    f23d=ui->doubleSpinBox_10->value();

    ui->doubleSpinBox_11->setValue(4);
    seeing3d=ui->doubleSpinBox_11->value();

    ui->doubleSpinBox_12->setValue(2500);
    ftel3d=ui->doubleSpinBox_12->value();

    ui->doubleSpinBox_13->setValue(254);
    dtel3d=ui->doubleSpinBox_13->value();

    ui->doubleSpinBox_14->setValue(0.009);
    p3d=ui->doubleSpinBox_14->value();

    ui->doubleSpinBox_15->setValue(200);
    offset3d=ui->doubleSpinBox_15->value();

    ui->doubleSpinBox_16->setValue(8);
    noise3d=ui->doubleSpinBox_16->value();

    ui->doubleSpinBox_17->setValue(1.5);
    gain3d=ui->doubleSpinBox_17->value();

    ui->doubleSpinBox_18->setValue(550);
    CCDl3d=ui->doubleSpinBox_18->value();

    ui->doubleSpinBox_19->setValue(0.85);
    CCDp3d=ui->doubleSpinBox_19->value();

    CCDT3d=2897.8/CCDl3d*1000;
    CCDm3d = 1.87088e19/(pow(CCDl3d,5))/(exp(14387750/CCDl3d/CCDT3d)-1);

    dg3d=cos(M_PI/180*theta3d)/g3d;

    ui->doubleSpinBox_20->setValue(0.05);
    s3d=ui->doubleSpinBox_20->value();

    sky3d=atan(s3d*3600/ftel3d)*180/M_PI;
    ui->doubleSpinBox_23->setValue(sky3d);

    sdisc3d=ftel3d*tan(seeing3d/3600*M_PI/180);

    ui->doubleSpinBox_21->setValue(0);
    sl3d=ui->doubleSpinBox_21->value();

    ui->doubleSpinBox_24->setValue(4000);
    T3d=ui->doubleSpinBox_24->value();

    if (log10(T3d)<4){
         BC3d = -64741.46+67717*log10(T3d)-26566.141*log10(T3d)*log10(T3d)+4632.926*log10(T3d)*log10(T3d)*log10(T3d)-303.0307*log10(T3d)*log10(T3d)*log10(T3d)*log10(T3d);
         }
         else {
              BC3d = -888.82+884.69*log10(T3d)-326.85*log10(T3d)*log10(T3d)+53.4*log10(T3d)*log10(T3d)*log10(T3d)-3.2744*log10(T3d)*log10(T3d)*log10(T3d)*log10(T3d);
              }
    ui->doubleSpinBox_25->setValue(BC3d);

    ui->doubleSpinBox_26->setValue(4);
    vm3d=ui->doubleSpinBox_26->value();

    ui->doubleSpinBox_27->setValue(20);
    z3d=ui->doubleSpinBox_27->value();

    ui->doubleSpinBox_28->setValue(10);
    exptime3d=ui->doubleSpinBox_28->value();

    ui->doubleSpinBox_29->setValue(550);
    tune3d=ui->doubleSpinBox_29->value();

    ui->spinBox->setValue(1);
    n3d=ui->spinBox->value();

    ui->spinBox_2->setValue(2048);
    lx3d=ui->spinBox_2->value();

    ui->spinBox_3->setValue(1024);
    ly3d=ui->spinBox_3->value();

    ui->spinBox_4->setValue(1);
    Bx3d=ui->spinBox_4->value();

    ui->spinBox_5->setValue(1);
    By3d=ui->spinBox_5->value();

    ui->spinBox_6->setValue(35);
    slits3d=ui->spinBox_6->value();

    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot_2->axisRect()->setupFullAxesBox(true);

    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));
    connect(ui->customPlot_2, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip_2(QMouseEvent*)));


    ui->comboBox->addItem("Planck");
    ui->comboBox->addItem("Balmer");
    ui->comboBox->addItem("Neon");

}

threed::~threed()
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

void threed::seData(QString str)
{
    ui->lineEdit_3->setText(str);
}

void threed::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
}

void threed::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
}

// line density
void threed::on_doubleSpinBox_valueChanged()
{
    g3d=ui->doubleSpinBox->value();

    a3d = asin(n3d*l3d/1000000*g3d/(2*cos(M_PI/180*t3d/2)))*180/M_PI+t3d/2;
    b3d = a3d-t3d;

    dg3d=cos(M_PI/180*theta3d)/g3d;
}

void threed::on_spinBox_valueChanged()
{
    n3d=ui->spinBox->value();

    a3d = asin(n3d*l3d/1000000*g3d/(2*cos(M_PI/180*t3d/2)))*180/M_PI+t3d/2;
    b3d = a3d-t3d;
}

void threed::on_doubleSpinBox_5_valueChanged()
{
    t3d=ui->doubleSpinBox_5->value();

    a3d = asin(n3d*l3d/1000000*g3d/(2*cos(M_PI/180*t3d/2)))*180/M_PI+t3d/2;
    b3d = a3d-t3d;
}

void threed::on_doubleSpinBox_2_valueChanged()
{
    theta3d=ui->doubleSpinBox_2->value();

    dg3d=cos(M_PI/180*theta3d)/g3d;
}

void threed::on_doubleSpinBox_3_valueChanged()
{
    eta3d=ui->doubleSpinBox_3->value();
}

void threed::on_doubleSpinBox_4_valueChanged()
{
    l3d=ui->doubleSpinBox_4->value();

    a3d = asin(n3d*l3d/1000000*g3d/(2*cos(M_PI/180*t3d/2)))*180/M_PI+t3d/2;
    b3d = a3d-t3d;
}

void threed::on_doubleSpinBox_6_valueChanged()
{
    index3d=ui->doubleSpinBox_6->value();
}

void threed::on_doubleSpinBox_7_valueChanged()
{
    dn3d=ui->doubleSpinBox_7->value();
}

void threed::on_doubleSpinBox_8_valueChanged()
{
    d3d=ui->doubleSpinBox_8->value();
}

void threed::on_doubleSpinBox_9_valueChanged()
{
    f13d=ui->doubleSpinBox_9->value();
}

void threed::on_doubleSpinBox_10_valueChanged()
{
    f23d=ui->doubleSpinBox_10->value();
}

void threed::on_doubleSpinBox_29_valueChanged()
{
    tune3d=ui->doubleSpinBox_29->value();
}

void threed::on_doubleSpinBox_11_valueChanged()
{
    seeing3d=ui->doubleSpinBox_11->value();
    sdisc3d=ftel3d*tan(seeing3d/3600*M_PI/180);
}

void threed::on_doubleSpinBox_12_valueChanged()
{
    ftel3d=ui->doubleSpinBox_12->value();
    sdisc3d=ftel3d*tan(seeing3d/3600*M_PI/180);
}

void threed::on_doubleSpinBox_13_valueChanged()
{
    dtel3d=ui->doubleSpinBox_13->value();
}

void threed::on_doubleSpinBox_14_valueChanged()
{
    p3d=ui->doubleSpinBox_14->value();
}

void threed::on_spinBox_2_valueChanged()
{
    lx3d=ui->spinBox_2->value();
}

void threed::on_spinBox_3_valueChanged()
{
    ly3d=ui->spinBox_3->value();
}

void threed::on_spinBox_4_valueChanged()
{
    Bx3d=ui->spinBox_4->value();
}

void threed::on_spinBox_5_valueChanged()
{
    By3d=ui->spinBox_5->value();
}

void threed::on_doubleSpinBox_15_valueChanged()
{
    offset3d=ui->doubleSpinBox_15->value();
}

void threed::on_doubleSpinBox_16_valueChanged()
{
    noise3d=ui->doubleSpinBox_16->value();
}

void threed::on_doubleSpinBox_17_valueChanged()
{
    gain3d=ui->doubleSpinBox_17->value();
}

void threed::on_doubleSpinBox_18_valueChanged()
{
    CCDl3d=ui->doubleSpinBox_18->value();

    CCDT3d=2897.8/CCDl3d*1000;
    CCDm3d = 1.87088e19/(pow(CCDl3d,5))/(exp(14387750/CCDl3d/CCDT3d)-1);
}

void threed::on_doubleSpinBox_19_valueChanged()
{
    CCDp3d=ui->doubleSpinBox_19->value();
}

void threed::on_checkBox_3_clicked()
{
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->doubleSpinBox_21->setEnabled(false);
}

void threed::on_checkBox_4_clicked()
{
    ui->checkBox_3->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->doubleSpinBox_21->setEnabled(true);
}

void threed::on_checkBox_5_clicked()
{
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->doubleSpinBox_21->setEnabled(false);
}

void threed::on_spinBox_6_valueChanged()
{
    slits3d=ui->spinBox_6->value();
}

void threed::on_doubleSpinBox_20_valueChanged()
{
    s3d=ui->doubleSpinBox_20->value();
}

void threed::on_doubleSpinBox_21_valueChanged()
{
    sl3d=ui->doubleSpinBox_21->value();
}

// slit efficiency
void threed::on_pushButton_2_clicked()
{
    // circular slit
    if(ui->checkBox_3->isChecked()){

        double slitstep=0.0001;
        int steps=s3d/2/slitstep+1;
        double relativ=0;
        for(int i =0; i<steps-1; i++){
            relativ+=(exp(-2*i*slitstep*i*slitstep/sdisc3d/sdisc3d)+exp(-2*(i+1)*slitstep*(i+1)*slitstep/sdisc3d/sdisc3d))/2*slitstep;
        }
        slitEff3d=pow((2*relativ/(sdisc3d*sqrt(M_PI/2))),2);
        ui->doubleSpinBox_22->setValue(slitEff3d*100);
    }

    // rectangular slit
    if(ui->checkBox_4->isChecked()){

        double slitstep=0.0001;
        int steps1=s3d/2/slitstep+1;
        int steps2=sl3d/2/slitstep+1;
        double relativ1=0, relativ2=0;
        for(int i =0; i<steps1-1; i++){
            relativ1+=(exp(-2*i*slitstep*i*slitstep/sdisc3d/sdisc3d)+exp(-2*(i+1)*slitstep*(i+1)*slitstep/sdisc3d/sdisc3d))/2*slitstep;
        }
        if(sl3d!=0){
        for(int i =0; i<steps2-1; i++){
            relativ2+=(exp(-2*i*slitstep*i*slitstep/sdisc3d/sdisc3d)+exp(-2*(i+1)*slitstep*(i+1)*slitstep/sdisc3d/sdisc3d))/2*slitstep;
        }}
        else{
            relativ2+=sdisc3d*sqrt(M_PI/2)/2;
        }
        slitEff3d=2*relativ1*2*relativ2/pow((sdisc3d*sqrt(M_PI/2)),2);
        ui->doubleSpinBox_22->setValue(slitEff3d*100);
    }

    // slitless
    if(ui->checkBox_5->isChecked()){
        slitEff3d=1.0;
        ui->doubleSpinBox_22->setValue(100);
    }
}

void threed::on_spinBox_7_valueChanged()
{
    ag3d=ui->spinBox_7->value();
}

void threed::on_spinBox_8_valueChanged()
{
    al3d=ui->spinBox_8->value();
}

void threed::on_spinBox_9_valueChanged()
{
    aluv3d=ui->spinBox_9->value();
}

void threed::on_spinBox_10_valueChanged()
{
    au3d=ui->spinBox_10->value();
}

void threed::on_spinBox_11_valueChanged()
{
    bb3d=ui->spinBox_11->value();
}

void threed::on_doubleSpinBox_24_valueChanged()
{
    T3d=ui->doubleSpinBox_24->value();

    if (log10(T3d)<4){
         BC3d = -64741.46+67717*log10(T3d)-26566.141*log10(T3d)*log10(T3d)+4632.926*log10(T3d)*log10(T3d)*log10(T3d)-303.0307*log10(T3d)*log10(T3d)*log10(T3d)*log10(T3d);
         }
         else {
              BC3d = -888.82+884.69*log10(T3d)-326.85*log10(T3d)*log10(T3d)+53.4*log10(T3d)*log10(T3d)*log10(T3d)-3.2744*log10(T3d)*log10(T3d)*log10(T3d)*log10(T3d);
              }
    ui->doubleSpinBox_25->setValue(BC3d);
}

void threed::on_doubleSpinBox_26_valueChanged()
{
    vm3d=ui->doubleSpinBox_26->value();
}

void threed::on_doubleSpinBox_27_valueChanged()
{
    z3d=ui->doubleSpinBox_27->value();
}

void threed::on_doubleSpinBox_28_valueChanged()
{
    exptime3d=ui->doubleSpinBox_28->value();
}

void threed::vecresize(){
    w3d.resize(lx3d/Bx3d);
    R3d.resize(lx3d/Bx3d);
    A3d.resize(lx3d/Bx3d);
    s23d.resize(lx3d/Bx3d);
    Nf3d.resize(lx3d/Bx3d);
    Tr3d.resize(lx3d/Bx3d);
    D3d.resize(lx3d/Bx3d);
    CCD3d.resize(lx3d/Bx3d);
    P3d.resize(lx3d/Bx3d);
    I13d.resize(lx3d/Bx3d);
    Ef3d.resize(lx3d/Bx3d);
    al3dt.resize(lx3d/Bx3d);
    aluv3dt.resize(lx3d/Bx3d);
    ag3dt.resize(lx3d/Bx3d);
    au3dt.resize(lx3d/Bx3d);
    bb3dt.resize(lx3d/Bx3d);
    reflectance3d.resize(lx3d/Bx3d);
}

// calculate parameters
void threed::on_pushButton_3_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    threed::vecresize();

    string zeile, one, two, line, eins, zwei;
    int bini=0, bini2=0, bini3=0, bini4=0, bini5=0;

    qtdpath = ui->lineEdit_3->text();
    tdpath = qtdpath.toUtf8().constData();

    ag3d=ui->spinBox_7->value();
    al3d=ui->spinBox_8->value();
    aluv3d=ui->spinBox_9->value();
    au3d=ui->spinBox_10->value();
    bb3d=ui->spinBox_11->value();

    if(al3d>0){

    QFile checkfile1(qtdpath+"/protected_Al.txt");

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Error", "Reflection data of aluminium not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    std::ostringstream datNameStream(tdpath);
    datNameStream<<tdpath<<"/protected_Al.txt";
    std::string datName = datNameStream.str();
    ifstream input1(datName.c_str());

    while(std::getline(input1, line))
       ++ bini;

    input1.clear();
    input1.seekg(0, ios::beg);

    al3di.resize(bini);
    al3dw.resize(bini);

    for (int i =0; i < bini; i++){
    input1 >> eins >> zwei;
    istringstream istr(eins);
    istr >> al3di[i];
    istringstream istr1(zwei);
    istr1 >> al3dw[i];
    }
    input1.close();
}
    if(aluv3d>0){

    QFile checkfile2(qtdpath+"/UVEnhanced_Al.txt");

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Reflection data of UV enhanced aluminium not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    std::ostringstream datNameStream(tdpath);
    datNameStream<<tdpath<<"/UVEnhanced_Al.txt";
    std::string datName = datNameStream.str();
    ifstream input2(datName.c_str());

    while(std::getline(input2, line))
       ++ bini2;

    input2.clear();
    input2.seekg(0, ios::beg);

    aluv3di.resize(bini2);
    aluv3dw.resize(bini2);

    for (int i =0; i < bini2; i++){
    input2 >> eins >> zwei;
    istringstream istr2(eins);
    istr2 >> aluv3dw[i];
    istringstream istr3(zwei);
    istr3 >> aluv3di[i];
    }
    input2.close();
}
    if(ag3d>0){

    QFile checkfile3(qtdpath+"/protected_Ag.txt");

    if(!checkfile3.exists()){
        QMessageBox::information(this, "Error", "Reflection data of protected silver not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    std::ostringstream datNameStream(tdpath);
    datNameStream<<tdpath<<"/protected_Ag.txt";
    std::string datName = datNameStream.str();
    ifstream input3(datName.c_str());

    while(std::getline(input3, line))
       ++ bini3;

    input3.clear();
    input3.seekg(0, ios::beg);

    ag3di.resize(bini3);
    ag3dw.resize(bini3);

    for (int i =0; i < bini3; i++){
    input3 >> eins >> zwei;
    istringstream istr4(eins);
    istr4 >> ag3dw[i];
    istringstream istr5(zwei);
    istr5 >> ag3di[i];
    }
    input3.close();
}

    if(au3d>0){

    QFile checkfile4(qtdpath+"/protected_Au.txt");

    if(!checkfile4.exists()){
        QMessageBox::information(this, "Error", "Reflection data of protected gold not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    std::ostringstream datNameStream(tdpath);
    datNameStream<<tdpath<<"/protected_Au.txt";
    std::string datName = datNameStream.str();
    ifstream input4(datName.c_str());

    while(std::getline(input4, line))
       ++ bini4;

    input4.clear();
    input4.seekg(0, ios::beg);

    au3di.resize(bini4);
    au3dw.resize(bini4);

    for (int i =0; i < bini4; i++){
    input4 >> eins >> zwei;
    istringstream istr6(eins);
    istr6 >> au3dw[i];
    istringstream istr7(zwei);
    istr7 >> au3di[i];
    }
    input4.close();
}

    if(bb3d>0){

    QFile checkfile5(qtdpath+"/vis_ar.txt");

    if(!checkfile5.exists()){
        QMessageBox::information(this, "Error", "Transmission data of VIS AR coating not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    std::ostringstream datNameStream(tdpath);
    datNameStream<<tdpath<<"/vis_ar.txt";
    std::string datName = datNameStream.str();
    ifstream input5(datName.c_str());

    while(std::getline(input5, line))
       ++ bini5;

    input5.clear();
    input5.seekg(0, ios::beg);

    bb3di.resize(bini5);
    bb3dw.resize(bini5);

    for (int i =0; i < bini5; i++){
    input5 >> eins >> zwei;
    istringstream istr8(eins);
    istr8 >> bb3dw[i];
    istringstream istr9(zwei);
    istr9 >> bb3di[i];
    }
    input5.close();
}

    threed::on_pushButton_2_clicked();

    string spectrum3d;

    std::ostringstream o1Stream(tdpath);
    o1Stream<<tdpath<<"/efficiency3d.txt";
    std::string o1Name = o1Stream.str();
    ofstream file1(o1Name.c_str());

    std::ostringstream o2Stream(tdpath);
    o2Stream<<tdpath<<"/ccd3d.txt";
    std::string o2Name = o2Stream.str();
    ofstream file2(o2Name.c_str());


    std::ostringstream o3Stream(tdpath);
    o3Stream<<tdpath<<"/anamorphism3d.txt";
    std::string o3Name = o3Stream.str();
    ofstream file3(o3Name.c_str());

    std::ostringstream o4Stream(tdpath);
    o4Stream<<tdpath<<"/nyquist3d.txt";
    std::string o4Name = o4Stream.str();
    ofstream file4(o4Name.c_str());

    std::ostringstream o5Stream(tdpath);
    o5Stream<<tdpath<<"/slit3d.txt";
    std::string o5Name = o5Stream.str();
    ofstream file5(o5Name.c_str());

    std::ostringstream o6Stream(tdpath);
    o6Stream<<tdpath<<"/resolving3d.txt";
    std::string o6Name = o6Stream.str();
    ofstream file6(o6Name.c_str());

    std::ostringstream o7Stream(tdpath);
    o7Stream<<tdpath<<"/dispersion3d.txt";
    std::string o7Name = o7Stream.str();
    ofstream file7(o7Name.c_str());

    std::ostringstream o8Stream(tdpath);
    o8Stream<<tdpath<<"/atmosphere3d.txt";
    std::string o8Name = o8Stream.str();
    ofstream file8(o8Name.c_str());

    std::ostringstream o9Stream(tdpath);
    o9Stream<<tdpath<<"/overall3d.txt";
    std::string o9Name = o9Stream.str();
    ofstream file9(o9Name.c_str());

    std::ostringstream o10Stream(tdpath);
    o10Stream<<tdpath<<"/signal3d.txt";
    std::string o10Name = o10Stream.str();
    ofstream file10(o10Name.c_str());

    std::ostringstream o11Stream(tdpath);
    o11Stream<<tdpath<<"/telescope3d.txt";
    std::string o11Name = o11Stream.str();
    ofstream file11(o11Name.c_str());

    std::ostringstream o12Stream(tdpath);
    o12Stream<<tdpath<<"/grating3d.txt";
    std::string o12Name = o12Stream.str();
    ofstream file12(o12Name.c_str());

    std::ostringstream o13Stream(tdpath);
    o13Stream<<tdpath<<"/surfaces3d.txt";
    std::string o13Name = o13Stream.str();
    ofstream file14(o13Name.c_str());

    std::ostringstream o14Stream(tdpath);
    o14Stream<<tdpath<<"/layout3d.txt";
    std::string o14Name = o14Stream.str();
    ofstream file15(o14Name.c_str());

    if(ui->comboBox->currentIndex()==0){
        std::ostringstream o15Stream(tdpath);
        o15Stream<<tdpath<<"/planck3d.txt";
        spectrum3d = o15Stream.str();
    }
    if(ui->comboBox->currentIndex()==1){
        std::ostringstream o15Stream(tdpath);
        o15Stream<<tdpath<<"/balmer3d.txt";
        spectrum3d = o15Stream.str();
    }
    if(ui->comboBox->currentIndex()==2){
        std::ostringstream o15Stream(tdpath);
        o15Stream<<tdpath<<"/neon3d.txt";
        spectrum3d = o15Stream.str();
    }
    ofstream file13(spectrum3d.c_str());

    ofstream file18("twopixR3d.txt");

    ui->customPlot_2->clearGraphs();

    CCDT3d=2897.8/CCDl3d*1000;
    CCDm3d = 1.87088e19/(pow(CCDl3d,5))/(exp(14387750/CCDl3d/CCDT3d)-1);

    dg3d=cos(M_PI/180*theta3d)/g3d;

    a3d = asin(n3d*l3d/1000000*g3d/(2*cos(M_PI/180*t3d/2)))*180/M_PI+t3d/2;
    b3d = a3d-t3d;

    at3d = sin(M_PI/180*(a3d-theta3d));
    double  bm3d;
    int number_of_lines=0;
    QVector<double> a(1), b(1), Ineons(lx3d/Bx3d);

    if(ui->comboBox->currentIndex()==2){

        QFile checkfile6(qtdpath+"/neon_line.txt");

        if(!checkfile6.exists()){
            QMessageBox::information(this, "Error", "Neon line list "+checkfile6.fileName()+" not available!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        std::ostringstream dat2NameStream(tdpath);
        dat2NameStream<<tdpath<<"/neon_line.txt";
        std::string dat2Name = dat2NameStream.str();
        ifstream input(dat2Name.c_str());

        number_of_lines =0;

        while(std::getline(input, zeile))
            ++ number_of_lines;

        input.clear();
        input.seekg(0, ios::beg);

        a.resize(number_of_lines);
        b.resize(number_of_lines);
        emi3d.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            input >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
        }
        input.close();
    }

    if(ui->comboBox->currentIndex()==1){

        QFile checkfile7(qtdpath+"/absor_line.txt");

        if(!checkfile7.exists()){
            QMessageBox::information(this, "Error", "Balmer line list "+checkfile7.fileName()+" not available!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        std::ostringstream dat2NameStream(tdpath);
        dat2NameStream<<tdpath<<"/absor_line.txt";
        std::string dat2Name = dat2NameStream.str();
        ifstream input(dat2Name.c_str());

        number_of_lines =0;

        while(std::getline(input, zeile))
            ++ number_of_lines;

        input.clear();
        input.seekg(0, ios::beg);

        a.resize(number_of_lines);
        b.resize(number_of_lines);
        emi3d.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            input >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
        }
        input.close();
    }

    double eta_s, eta_p, y13d=0, y23d=0;
    double alpha_2b=asin(n3d*tune3d/1000000/index3d/2*g3d)*180/M_PI;
    double sepa=ly3d/(slits3d+1);
    double FWHM=0;

    if(ui->checkBox_3->isChecked()){
        FWHM=s3d/p3d*f23d/f13d;
    }

    else if(ui->checkBox_4->isChecked()){
        FWHM=sl3d/p3d*f23d/f13d;
    }

        for(int i=0; i<lx3d/Bx3d; i++){

            bm3d = atan((lx3d/2-i)*p3d/f23d)*180/M_PI;
            w3d[i] = (sin(M_PI/180*a3d)+sin(M_PI/180*(b3d-bm3d)))/(n3d*g3d);
            reflectance3d[i]=1;

            if(al3d>0){
            if(i==0){
                for (int n=0; n<bini; n++){
                    if((al3dw[n]>w3d[i]*1000) &(al3dw[n+1]<w3d[i]*1000)){
                        al3dt[i]=al3di[n+1]+(w3d[i]*1000-al3dw[n+1])/(al3dw[n]-al3dw[n+1])*(al3di[n]-al3di[n+1]);
                        aal3d=n;
                    }
                }
            }
            else{
                for(int n=aal3d-2; n<aal3d+3; n++){
                    if((al3dw[n]>w3d[i]*1000) &(al3dw[n+1]<w3d[i]*1000)){
                        al3dt[i]=al3di[n+1]+(w3d[i]*1000-al3dw[n+1])/(al3dw[n]-al3dw[n+1])*(al3di[n]-al3di[n+1]);
                        aal3d=n;
                    }
                }
            }
            al3dt[i]=pow(al3dt[i]/100,al3d);
            reflectance3d[i]=reflectance3d[i]*al3dt[i];
            }

            if(aluv3d>0){
            if(i==0){
                for (int n=0; n<bini2; n++){
                    if((aluv3dw[n]>w3d[i]*1000) &(aluv3dw[n+1]<w3d[i]*1000)){
                        aluv3dt[i]=aluv3di[n+1]+(w3d[i]*1000-aluv3dw[n+1])/(aluv3dw[n]-aluv3dw[n+1])*(aluv3di[n]-aluv3di[n+1]);
                        aaluv3d=n;
                    }
                }
            }
            else{
                for(int n=aaluv3d-2; n<aaluv3d+3; n++){
                    if((aluv3dw[n]>w3d[i]*1000) &(aluv3dw[n+1]<w3d[i]*1000)){
                        aluv3dt[i]=aluv3di[n+1]+(w3d[i]*1000-aluv3dw[n+1])/(aluv3dw[n]-aluv3dw[n+1])*(aluv3di[n]-aluv3di[n+1]);
                        aaluv3d=n;
                    }
                }
            }
            aluv3dt[i]=pow(aluv3dt[i]/100,aluv3d);
            reflectance3d[i]=reflectance3d[i]*aluv3dt[i];
            }

            if(ag3d>0){
            if(i==0){
                for (int n=0; n<bini3; n++){
                    if((ag3dw[n]>w3d[i]*1000) &(ag3dw[n+1]<w3d[i]*1000)){
                        ag3dt[i]=ag3di[n+1]+(w3d[i]*1000-ag3dw[n+1])/(ag3dw[n]-ag3dw[n+1])*(ag3di[n]-ag3di[n+1]);
                        aag3d=n;
                    }
                }
            }
            else{
                for(int n=aag3d-2; n<aag3d+3; n++){
                    if((ag3dw[n]>w3d[i]*1000) &(ag3dw[n+1]<w3d[i]*1000)){
                        ag3dt[i]=ag3di[n+1]+(w3d[i]*1000-ag3dw[n+1])/(ag3dw[n]-ag3dw[n+1])*(ag3di[n]-ag3di[n+1]);
                        aag3d=n;
                    }
                }
            }
            ag3dt[i]=pow(ag3dt[i]/100,ag3d);
            reflectance3d[i]=reflectance3d[i]*ag3dt[i];
            }

            if(au3d>0){
            if(i==0){
                for (int n=0; n<bini4; n++){
                    if((au3dw[n]>w3d[i]*1000) &(au3dw[n+1]<w3d[i]*1000)){
                        au3dt[i]=au3di[n+1]+(w3d[i]*1000-au3dw[n+1])/(au3dw[n]-au3dw[n+1])*(au3di[n]-au3di[n+1]);
                        aau3d=n;
                    }
                }
            }
            else{
                for(int n=aau3d-2; n<aau3d+3; n++){
                    if((au3dw[n]>w3d[i]*1000) &(au3dw[n+1]<w3d[i]*1000)){
                        au3dt[i]=au3di[n+1]+(w3d[i]*1000-au3dw[n+1])/(au3dw[n]-au3dw[n+1])*(au3di[n]-au3di[n+1]);
                        aau3d=n;
                    }
                }
            }
            au3dt[i]=pow(au3dt[i]/100,au3d);
            reflectance3d[i]=reflectance3d[i]*au3dt[i];
            }

            if(bb3d>0){
            if(i==0){
                for (int n=0; n<bini5; n++){
                    if((bb3dw[n]<w3d[i]*1000000) &(bb3dw[n+1]>w3d[i]*1000000)){
                        bb3dt[i]=bb3di[n]+(w3d[i]*1000000-bb3dw[n])/(bb3dw[n+1]-bb3dw[n])*(bb3di[n+1]-bb3di[n]);
                        abb3d=n;
                    }
                }
            }
            else{
                for(int n=abb3d-2; n<abb3d+3; n++){
                    if((bb3dw[n]<w3d[i]*1000000) &(bb3dw[n+1]>w3d[i]*1000000)){
                        bb3dt[i]=bb3di[n]+(w3d[i]*1000000-bb3dw[n])/(bb3dw[n+1]-bb3dw[n])*(bb3di[n+1]-bb3di[n]);
                        abb3d=n;
                    }
                }
            }
            bb3dt[i]=pow((100-bb3dt[i])/100,bb3d);
            reflectance3d[i]=reflectance3d[i]*bb3dt[i];
            }

            R3d[i] = w3d[i]*n3d*f13d*g3d/(cos(M_PI/180*a3d)*s3d);
            A3d[i] = cos(M_PI/180*a3d)/cos(M_PI/180*(b3d-bm3d));
            s23d[i] = A3d[i] * f23d/f13d*s3d;
            Nf3d[i] = s23d[i]/p3d/2;
            Tr3d[i] = 1-0.0091224/cos(M_PI/180*z3d)/(pow(w3d[i]*1000,4));
            D3d[i] = p3d*Bx3d*cos((b3d-bm3d)*M_PI/180)/(f23d*n3d*g3d);
            w3d[i]=w3d[i]*10000000;
            P3d[i] = Tr3d[i]*dtel3d*dtel3d/400*M_PI*ap3d/(w3d[i]*w3d[i]*w3d[i]*w3d[i])/(exp(k3d/T3d/w3d[i])-1)*pow(10,-0.4*(vm3d-BC3d))/(pow(T3d,4)*1.986e-11);
            CCD3d[i] = ap3d/(pow(w3d[i],5))/(exp(143877500/w3d[i]/CCDT3d)-1)/CCDm3d*CCDp3d;
            w3d[i]=w3d[i]/10000000;

        if(ui->checkBox->isChecked()){
            b13d = asin(n3d*w3d[i]*g3d-sin(M_PI/180*a3d))*180/M_PI;
            bt3d = sin(M_PI/180*(b13d-theta3d));

            Il13d = sin(M_PI*dg3d/w3d[i]*(at3d+bt3d));
            Il23d = M_PI*dg3d/w3d[i]*(at3d+bt3d);
            I13d[i] = eta3d*Il13d*Il13d/Il23d/Il23d;
            }

            if(ui->checkBox_2->isChecked()){
            eta_s=pow(sin(M_PI*dn3d*d3d/w3d[i]/cos(alpha_2b*M_PI/180)),2);
            eta_p=pow(sin(M_PI*dn3d*d3d*cos(M_PI/180*2*alpha_2b)/w3d[i]/cos(alpha_2b*M_PI/180)),2);
            I13d[i]=(eta_p+eta_s)/2;
            }

            Ef3d[i]=I13d[i]*CCD3d[i]*reflectance3d[i]*slitEff3d;

            // Planck
            if(ui->comboBox->currentIndex()==0){
                Ineons[i]=P3d[i]*Ef3d[i];
            }

            // Balmer
            if(ui->comboBox->currentIndex()==1){
                for (int e=0; e < number_of_lines; e++){
                emi3d[e] = 1-exp(-5.545*p3d*p3d/s23d[i]/s23d[i]/2*pow((a[e]-w3d[i]*10000000),2))*b[e]*number_of_lines;
                }
                for(int e=0; e<number_of_lines; e++){
                Ineons[i] += emi3d[e];
                }
                Ineons[i]=Ineons[i]*P3d[i]*Ef3d[i];
            }

            // Neon
            if(ui->comboBox->currentIndex()==2){
            for (int e=0; e < number_of_lines; e++){
                            emi3d[e] = exp(-5.545*p3d*p3d/s23d[i]/s23d[i]/2*pow((a[e]-w3d[i]*10000000),2))*b[e];
                            Ineons[i] += emi3d[e];
                            }
            Ineons[i]=Ineons[i]*Ef3d[i]*Tr3d[i];
            }
            if(Ineons[i]<y13d){
                y13d=Ineons[i];
            }
            if(Ineons[i]>y23d){
                y23d=Ineons[i];
            }

            w3d[i]=w3d[i]*1000000;

            file1<<w3d[i]<<" "<<Ef3d[i]<<endl;
            file2<<w3d[i]<<" "<<CCD3d[i]<<endl;
            file3<<w3d[i]<<" "<<A3d[i]<<endl;
            file4<<w3d[i]<<" "<<Nf3d[i]<<endl;
            file5<<w3d[i]<<" "<<s23d[i]<<endl;
            file6<<w3d[i]<<" "<<R3d[i]<<endl;
            file7<<w3d[i]<<" "<<D3d[i]*1000000<<endl;
            file8<<w3d[i]<<" "<<Tr3d[i]<<endl;
            file18<<w3d[i]<<" "<<w3d[i]/2/D3d[i]/1000000<<endl;

            Ef3d[i]=Ef3d[i]*Tr3d[i];

            file9<<w3d[i]<<" "<<Ef3d[i]<<endl;

            Ef3d[i]=Ef3d[i]*P3d[i]/Tr3d[i]*exptime3d;

            file10<<w3d[i]<<" "<<Ef3d[i]<<endl;
            file11<<w3d[i]<<" "<<P3d[i]<<endl;
            file12<<w3d[i]<<" "<<I13d[i]<<endl;
            file13<<w3d[i]<<" "<<Ineons[i]<<endl;

            file14<<w3d[i]<<" "<<reflectance3d[i]<<endl;

            for(int e=0; e<slits3d; e++){
                file15<<w3d[i]<<" "<<sepa*(e+1)<<endl;
                file15<<w3d[i]<<" "<<sepa*(e+1)+FWHM<<endl;
                file15<<w3d[i]<<" "<<sepa*(e+1)-FWHM<<endl;
            }
            ui->progressBar->setValue((i+1)*100/(lx3d/Bx3d));
            qApp->processEvents(QEventLoop::AllEvents);
        }

        ui->customPlot_2->addGraph();
        ui->customPlot_2->graph(0)->setData(w3d, Ineons);
        ui->customPlot_2->graph(0)->setLineStyle(QCPGraph::lsLine);
        //ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot_2->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot_2->yAxis->setLabel("rel. Intensity");
        ui->customPlot_2->xAxis->setRange(w3d[0], w3d[lx3d/Bx3d-1]);
        ui->customPlot_2->yAxis->setRange(y13d, y23d);
        ui->customPlot_2->replot();

    this->setCursor(QCursor(Qt::ArrowCursor));
}


// Frame
void threed::on_pushButton_4_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    qtdpath = ui->lineEdit_3->text();
    tdpath = qtdpath.toUtf8().constBegin();

    ui->customPlot->clearGraphs();

    threed::vecresize();

    threed::on_pushButton_3_clicked();

    this->setCursor(QCursor(Qt::WaitCursor));

    if(sl3d==0){
        sl3d=s3d;
    }

    double Intens3d, bm3d, Ineon;
    string zeile, one, two;
    int progress=0;

    a3d = asin(n3d*l3d/1000000*g3d/(2*cos(M_PI/180*t3d/2)))*180/M_PI+t3d/2;
    b3d = a3d-t3d;

    bm3d = atan((lx3d/2)*p3d/f23d)*180/M_PI;
    //double loww3d = (sin(M_PI/180*a3d)+sin(M_PI/180*(b3d-bm3d)))/(n3d*g3d)*1000000;
    //double upperw3d = (sin(M_PI/180*a3d)+sin(M_PI/180*(b3d+bm3d)))/(n3d*g3d)*1000000;

    std::ostringstream o1Stream(tdpath);
    o1Stream<<tdpath<<"/planck3d.txt";
    std::string o1Name = o1Stream.str();
    ofstream file1(o1Name.c_str());

    std::ostringstream o2Stream(tdpath);
    o2Stream<<tdpath<<"/balmer3d.txt";
    std::string o2Name = o2Stream.str();
    ofstream file2(o2Name.c_str());


    std::ostringstream o3Stream(tdpath);
    o3Stream<<tdpath<<"/neon3d.txt";
    std::string o3Name = o3Stream.str();
    ofstream file3(o3Name.c_str());

    QVector<double> a(1), b(1);
    int number_of_lines;

    if(ui->comboBox->currentIndex()==2){

        QFile checkfile(qtdpath+"/neon_line.txt");

        if(!checkfile.exists()){
            QMessageBox::information(this, "Error", "Neon line list "+checkfile.fileName()+" not available!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        std::ostringstream datNameStream(tdpath);
        datNameStream<<tdpath<<"/neon_line.txt";
        std::string datName = datNameStream.str();
        ifstream input(datName.c_str());

        number_of_lines =0;

        while(std::getline(input, zeile))
            ++ number_of_lines;

        input.clear();
        input.seekg(0, ios::beg);

        a.resize(number_of_lines);
        b.resize(number_of_lines);
        emi3d.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            input >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
        }
        input.close();
    }
    if(ui->comboBox->currentIndex()==1){

        QFile checkfile1(qtdpath+"/absor_line.txt");

        if(!checkfile1.exists()){
            QMessageBox::information(this, "Error", "Balmer line list "+checkfile1.fileName()+" not available!");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        std::ostringstream dat2NameStream(tdpath);
        dat2NameStream<<tdpath<<"/absor_line.txt";
        std::string dat2Name = dat2NameStream.str();
        ifstream input(dat2Name.c_str());

        number_of_lines =0;

        while(std::getline(input, zeile))
           ++ number_of_lines;

        input.clear();
        input.seekg(0, ios::beg);

        a.resize(number_of_lines);
        b.resize(number_of_lines);
        emi3d.resize(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            input >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
        }
        input.close();
    }

    double sepa=ly3d/(slits3d+1), Il13d, Il23d, eta_s, eta_p;
    QVector<double> o3d(slits3d), b13d(lx3d/Bx3d), bt3d(lx3d/Bx3d), I13d(lx3d/Bx3d);

    double at3d = sin(M_PI/180*(a3d-theta3d));
    double dg3d = cos(M_PI/180*theta3d)/g3d;
    double alpha_2b=asin(n3d*tune3d/1000000/index3d/2*g3d)*180/M_PI;

    for(int e=0; e<slits3d; e++){
        o3d[e]=sepa*(e+1);
    }

    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    // set up the QCPColorMap:
    QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(colorMap);
    colorMap->data()->setSize(lx3d/Bx3d, ly3d/By3d); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(0, lx3d/Bx3d), QCPRange(0, ly3d/Bx3d));

    for(int i=0; i<lx3d/Bx3d; i++){
        bm3d = atan((lx3d/2-i/Bx3d)*p3d/f23d)*180/M_PI;
        w3d[i] = (sin(M_PI/180*a3d)+sin(M_PI/180*(b3d-bm3d)))/(n3d*g3d);
        A3d[i] = cos(M_PI/180*a3d)/cos(M_PI/180*(b3d-bm3d));
        s23d[i] = A3d[i] * f23d/f13d*s3d;
        w3d[i]=w3d[i]*1000;
        Tr3d[i] = 1-0.0091224/cos(M_PI/180*z3d)/(pow(w3d[i],4));
        w3d[i] = w3d[i]*10000;
        CCD3d[i] = ap3d/(w3d[i]*w3d[i]*w3d[i]*w3d[i]*w3d[i])/(exp(143877500/w3d[i]/CCDT3d)-1)/CCDm3d*CCDp3d;
        w3d[i] = w3d[i]/10000000;

        // Diffraction Grating Efficiency
        if(ui->checkBox->isChecked()){
        b13d[i] = asin(n3d*w3d[i]*g3d-sin(M_PI/180*a3d))*180/M_PI;
        bt3d[i] = sin(M_PI/180*(b13d[i]-theta3d));
        Il13d = sin(M_PI*dg3d/w3d[i]*(at3d+bt3d[i]));
        Il23d = M_PI*dg3d/w3d[i]*(at3d+bt3d[i]);
        I13d[i] = eta3d*Il13d*Il13d/Il23d/Il23d;
        }

        // VPH Grating Efficiency
        if(ui->checkBox_2->isChecked()){
            eta_s=pow(sin(M_PI*dn3d*d3d/w3d[i]/cos(alpha_2b*M_PI/180)),2);
            eta_p=pow(sin(M_PI*dn3d*d3d*cos(M_PI/180*2*alpha_2b)/w3d[i]/cos(alpha_2b*M_PI/180)),2);
            I13d[i]=(eta_s+eta_p)/2;
        }

        // Planck
        if(ui->comboBox->currentIndex()==0){
            w3d[i] = w3d[i]*10000000;
            P3d[i] = Tr3d[i]*dtel3d*dtel3d/400*M_PI*ap3d/(w3d[i]*w3d[i]*w3d[i]*w3d[i])/(exp(k3d/T3d/w3d[i])-1)*pow(10,-0.4*(vm3d-BC3d))/(pow(T3d,4)*1.986e-11);
            w3d[i] = w3d[i]/10000000;
            Ineon = I13d[i]*P3d[i]*CCD3d[i]*slitEff3d*reflectance3d[i];

        }

        // Balmer
        if(ui->comboBox->currentIndex()==1){
            w3d[i] = w3d[i]*10000000;
            P3d[i] = Tr3d[i]*dtel3d*dtel3d/400*M_PI*ap3d/(w3d[i]*w3d[i]*w3d[i]*w3d[i])/(exp(k3d/T3d/w3d[i])-1)*pow(10,-0.4*(vm3d-BC3d))/(pow(T3d,4)*1.986e-11);
            w3d[i] = w3d[i]/10000000;
            for (int e=0; e < number_of_lines; e++){
                            emi3d[e] = 1-exp(-2.77254*p3d*p3d/s23d[i]/s23d[i]*pow((a[e]-w3d[i]*10000000),2))*b[e]*number_of_lines;
                            //Ineon += emi3d[e];
                            }

                        for (int e=0; e < number_of_lines; e++){
                            Ineon += emi3d[e]/number_of_lines;
                            }
                        Ineon=Ineon*I13d[i]*CCD3d[i]*P3d[i]*slitEff3d*reflectance3d[i];
        }

        // Neon
        if(ui->comboBox->currentIndex()==2){
        for (int e=0; e < number_of_lines; e++){
                        emi3d[e] = exp(-2.77254*p3d*p3d/s23d[i]/s23d[i]*pow((a[e]-w3d[i]*10000000),2))*b[e];
                        Ineon += emi3d[e];
                        }
                    Ineon=Ineon*I13d[i]*CCD3d[i]*slitEff3d*reflectance3d[i];
        }

        for(int m=0; m<ly3d/By3d; m++){
            for(int e=0; e<slits3d; e++){
            Intens3d+=exp(-2.77254*p3d*p3d/sl3d/sl3d*pow((o3d[e]-m),2));
            }
            if(ui->comboBox->currentIndex()==0){
                file1<<i<<" "<<m<<" "<<Intens3d*Ineon<<endl;
            }
            if(ui->comboBox->currentIndex()==1){
                file2<<i<<" "<<m<<" "<<Intens3d*Ineon<<endl;
            }
            if(ui->comboBox->currentIndex()==2){
                file3<<i<<" "<<m<<" "<<Intens3d*Ineon<<endl;
            }
            colorMap->data()->setCell(i, m, Intens3d*Ineon);
            Intens3d=0;
        }
        Ineon=0;
        progress++;
        if(progress>=lx3d/Bx3d/100){
        ui->progressBar->setValue((i+1)*100/(lx3d/Bx3d));
             qApp->processEvents(QEventLoop::AllEvents);
             progress=0;
        }
    }

    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange();
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
    colorMap->clearData();

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void threed::setvalues3d(){
    g3d=variables3d[0];
    ui->doubleSpinBox->setValue(g3d);

    theta3d=variables3d[2];
    ui->doubleSpinBox_2->setValue(theta3d);

    eta3d=variables3d[3];
    ui->doubleSpinBox_3->setValue(eta3d);

    l3d=variables3d[4];
    ui->doubleSpinBox_4->setValue(l3d);

    t3d=variables3d[5];
    ui->doubleSpinBox_5->setValue(t3d);

    a3d = asin(n3d*l3d/1000000*g3d/(2*cos(M_PI/180*t3d/2)))*180/M_PI+t3d/2;
    b3d = a3d-t3d;

    index3d=variables3d[36];
    ui->doubleSpinBox_6->setValue(index3d);

    dn3d=variables3d[37];
    ui->doubleSpinBox_7->setValue(dn3d);

    d3d=variables3d[38];
    ui->doubleSpinBox_8->setValue(d3d);

    f13d=variables3d[6];
    ui->doubleSpinBox_9->setValue(f13d);

    f23d=variables3d[7];
    ui->doubleSpinBox_10->setValue(f23d);

    seeing3d=variables3d[12];;
    ui->doubleSpinBox_11->setValue(seeing3d);

    ftel3d=variables3d[13];
    ui->doubleSpinBox_12->setValue(ftel3d);

    dtel3d=variables3d[14];
    ui->doubleSpinBox_13->setValue(dtel3d);

    p3d=variables3d[15];
    ui->doubleSpinBox_14->setValue(p3d);

    offset3d=variables3d[20];
    ui->doubleSpinBox_15->setValue(offset3d);

    noise3d=variables3d[21];
    ui->doubleSpinBox_16->setValue(noise3d);

    gain3d=variables3d[22];
    ui->doubleSpinBox_17->setValue(gain3d);

    CCDl3d=variables3d[23];
    ui->doubleSpinBox_18->setValue(CCDl3d);

    CCDp3d=variables3d[24];
    ui->doubleSpinBox_19->setValue(CCDp3d);

    CCDT3d=2897.8/CCDl3d*1000;
    CCDm3d = 1.87088e19/(pow(CCDl3d,5))/(exp(14387750/CCDl3d/CCDT3d)-1);

    dg3d=cos(M_PI/180*theta3d)/g3d;

    s3d=variables3d[8];
    ui->doubleSpinBox_20->setValue(s3d);

    sky3d=variables3d[11];
    ui->doubleSpinBox_23->setValue(sky3d);

    sdisc3d=ftel3d*tan(seeing3d/3600*M_PI/180);

    sl3d=variables3d[9];
    ui->doubleSpinBox_21->setValue(sl3d);

    slitEff3d=variables3d[10];

    T3d=variables3d[25];
    ui->doubleSpinBox_24->setValue(T3d);

    BC3d=variables3d[26];
    ui->doubleSpinBox_25->setValue(BC3d);

    vm3d=variables3d[27];
    ui->doubleSpinBox_26->setValue(vm3d);

    z3d=variables3d[28];
    ui->doubleSpinBox_27->setValue(z3d);

    exptime3d=variables3d[29];
    ui->doubleSpinBox_28->setValue(exptime3d);

    tune3d=variables3d[39];
    ui->doubleSpinBox_29->setValue(tune3d);

    n3d=variables3d[1];;
    ui->spinBox->setValue(n3d);

    lx3d=variables3d[16];
    ui->spinBox_2->setValue(lx3d);

    ly3d=variables3d[17];
    ui->spinBox_3->setValue(ly3d);

    Bx3d=variables3d[18];
    ui->spinBox_4->setValue(Bx3d);

    By3d=variables3d[19];
    ui->spinBox_5->setValue(By3d);

    slits3d=variables3d[35];
    ui->spinBox_6->setValue(slits3d);

    ag3d=variables3d[30];
    ui->spinBox_7->setValue(ag3d);

    al3d=variables3d[31];
    ui->spinBox_8->setValue(al3d);

    aluv3d=variables3d[32];
    ui->spinBox_9->setValue(aluv3d);

    au3d=variables3d[33];
    ui->spinBox_10->setValue(au3d);

    bb3d=variables3d[34];
    ui->spinBox_11->setValue(bb3d);
}

// Save
void threed::on_pushButton_5_clicked()
{
    QString qSaved = ui->lineEdit->text()+".dconf";
    string saved = qSaved.toUtf8().constData();
    ofstream file(saved.c_str());

    file<<g3d<<endl;
    file<<n3d<<endl;
    file<<theta3d<<endl;
    file<<eta3d<<endl;
    file<<l3d<<endl;
    file<<t3d<<endl;
    file<<f13d<<endl;
    file<<f23d<<endl;
    file<<s3d<<endl;
    file<<sl3d<<endl;
    file<<slitEff3d<<endl;
    file<<sky3d<<endl;
    file<<seeing3d<<endl;
    file<<ftel3d<<endl;
    file<<dtel3d<<endl;
    file<<p3d<<endl;
    file<<lx3d<<endl;
    file<<ly3d<<endl;
    file<<Bx3d<<endl;
    file<<By3d<<endl;
    file<<offset3d<<endl;
    file<<noise3d<<endl;
    file<<gain3d<<endl;
    file<<CCDl3d<<endl;
    file<<CCDp3d<<endl;
    file<<T3d<<endl;
    file<<BC3d<<endl;
    file<<vm3d<<endl;
    file<<z3d<<endl;
    file<<exptime3d<<endl;
    file<<ag3d<<endl;
    file<<al3d<<endl;
    file<<aluv3d<<endl;
    file<<au3d<<endl;
    file<<bb3d<<endl;
    file<<slits3d<<endl;
    file<<index3d<<endl;
    file<<dn3d<<endl;
    file<<d3d<<endl;
    file<<tune3d<<endl;

    file.close();
}

// Load
void threed::on_pushButton_6_clicked()
{
    QString qLoad3d = ui->lineEdit_2->text()+".dconf";
    string load3d = qLoad3d.toUtf8().constData();

    QFile checkfile(qLoad3d);

    if(!checkfile.exists()){
        QMessageBox::information(this, "Error", "File is not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    string eins;
    ifstream file(load3d.c_str());

    for(int i=0; i<var3d; i++){
        file >> eins;
        istringstream str(eins);
        str>> variables3d[i];
    }

    file.close();

    setvalues3d();
}
