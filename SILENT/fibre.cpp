#include "fibre.h"
#include "ui_fibre.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <pclassical.h>
#include <QFile>
#include <QMessageBox>

using namespace std;

double nen, res, length, dcla, dco, inputf, B1f, B2f, B3f, C1f, C2f, C3f, B1cla, B2cla, B3cla, C1cla, C2cla, C3cla, NA, NAw, dFz, dOPL, nco, RMin, ncla;
int fsteps=100, specw;
QVector<double> refl(fsteps), Fz(fsteps), opl(fsteps);
double upperl=1.0, lowerw=0.3;


Fibre::Fibre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Fibre)
{
    ui->setupUi(this);

    this->setWindowTitle("Optical Fibre Tool");

    ui->comboBox->addItem("F 0 wt% Cl 0.6 wt%");
    ui->comboBox->addItem("F 0.15 wt% Cl 0.38 wt%");
    ui->comboBox->addItem("F 0.9 wt% Cl 0.13 wt%");
    ui->comboBox->addItem("F 1.47 wt% Cl 0.22 wt%");
    ui->comboBox->addItem("F 1.97 wt% Cl 0.54wt%");
    ui->comboBox->addItem("Cl 0.06 wt%");
    ui->comboBox->addItem("Cl 0.05 wt%");
    ui->comboBox->addItem("Cl 0.3 wt%");
    ui->comboBox->addItem("Cl 3.4 wt%");
    ui->comboBox->addItem("B ?% Cl 0.06 wt%");
    ui->comboBox->addItem("Al 4.9 wt% Cl 0.06 wt%");
    ui->comboBox->addItem("GeO2 4.5mol.% Cl 0.16 wt%");
    ui->comboBox->addItem("GeO2 11.6 mol.%");
    ui->comboBox->addItem("P 12.5 wt% Cl 0.03 wt%");
    ui->comboBox->addItem("N 1.6 wt% Cl 0.9 wt%");
    ui->comboBox->addItem("GeO2 13.5 %");
    ui->comboBox->addItem("P2O2 9.1 %");
    ui->comboBox->addItem("B2O3 13.3 %");
    ui->comboBox->addItem("F 1 %");
    ui->comboBox->addItem("GeO2 3.1 %");
    ui->comboBox->addItem("GeO2 3.5 %");
    ui->comboBox->addItem("GeO2 4.1 %");
    ui->comboBox->addItem("GeO2 5.8 %");
    ui->comboBox->addItem("GeO2 6.3 %");
    ui->comboBox->addItem("GeO2 7.0 %");
    ui->comboBox->addItem("GeO2 7.9 %");
    ui->comboBox->addItem("GeO2 8.7 %");
    ui->comboBox->addItem("GeO2 11.2 %");
    ui->comboBox->addItem("GeO2 15.9 %");
    ui->comboBox->addItem("GeO2 19.3 %");

    ui->comboBox->setCurrentIndex(0);

    ui->checkBox->setChecked(true);

    ui->doubleSpinBox->setValue(0.1);
    dco = ui->doubleSpinBox->value();

    ui->doubleSpinBox_2->setValue(0.14);
    dcla=ui->doubleSpinBox_2->value();

    ui->doubleSpinBox_4->setValue(500);
    NAw = ui->doubleSpinBox_4->value();

    ui->doubleSpinBox_5->setValue(1.0002772);
    nen = ui->doubleSpinBox_5->value();

    ui->doubleSpinBox_6->setValue(25000);
    length = ui->doubleSpinBox_6->value();

    ui->doubleSpinBox_7->setValue(5);
    inputf = ui->doubleSpinBox_7->value();

    ui->doubleSpinBox_9->setValue(0.004);
    res=ui->doubleSpinBox_9->value();

    ui->spinBox->setValue(4);
    specw=ui->spinBox->value();

    // silica http://refractiveindex.info/?shelf=main&book=SiO2&page=Malitson
    // https://en.wikipedia.org/wiki/Sellmeier_equation
    B1f = 0.6961663;
    B2f = 0.4079426;
    B3f = 0.8974794;
    C1f = 0.00467914826;
    C2f = 0.0135120631;
    C3f = 97.9340025;

    B1cla=0.69913;
    B2cla=0.40697;
    B3cla=1.06869;
    C1cla=0.0077317;
    C2cla=0.008731034;
    C3cla=112.685656;

    dFz=inputf/fsteps;

    NAw = NAw/1000;
    nco=sqrt(1+B1f*NAw*NAw/(NAw*NAw-C1f)+B2f*NAw*NAw/(NAw*NAw-C2f)+B3f*NAw*NAw/(NAw*NAw-C3f));

    ncla = sqrt(1+B1cla*NAw*NAw/(NAw*NAw-C1cla)+B2cla*NAw*NAw/(NAw*NAw-C2cla)+B3cla*NAw*NAw/(NAw*NAw-C3cla));
    NAw = NAw*1000;

    NA=sqrt(ncla*ncla-nco*nco);

    ui->doubleSpinBox_3->setValue(NA);

    ui->customPlot->clearGraphs();
    ui->customPlot->axisRect()->setupFullAxesBox(true);
}

Fibre::~Fibre()
{
    delete ui;
}

// number of reflections
void Fibre::reflections(){

    NAw = NAw/1000;
    nco=sqrt(1+B1f*NAw*NAw/(NAw*NAw-C1f)+B2f*NAw*NAw/(NAw*NAw-C2f)+B3f*NAw*NAw/(NAw*NAw-C3f));
    NAw = NAw*1000;

    ui->customPlot->clearGraphs();

    for(int i=0; i<fsteps; i++){
        Fz[i]=i*dFz+0.5;
        refl[i]=length/dco*sin(atan(1/(Fz[i]*2*nen)))/(sqrt(nco*nco-sin(atan(1/(Fz[i]*2*nen)))*sin(atan(1/(Fz[i]*2*nen)))));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(Fz, refl);
    ui->customPlot->xAxis->setLabel("Input F#");
    ui->customPlot->yAxis->setLabel("Reflections");
    ui->customPlot->xAxis->setRange(Fz[0], inputf);
    ui->customPlot->yAxis->setRange(refl[fsteps-1], refl[0]);
    ui->customPlot->replot();
}

// optical path length
void Fibre::OPL(){

    ui->customPlot->clearGraphs();

    for(int i=0; i<fsteps; i++){
        Fz[i]=i*dFz+0.5;
        opl[i]=length/(sqrt(1-pow((sin(sin(atan(1/(Fz[i]*2*nen))))),2)));
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(Fz, opl);
    ui->customPlot->xAxis->setLabel("Input F#");
    ui->customPlot->yAxis->setLabel("OPL");
    ui->customPlot->xAxis->setRange(Fz[0], inputf);
    ui->customPlot->yAxis->setRange(opl[0], opl[fsteps-1]);
    ui->customPlot->replot();
}

// transmission
void Fibre::transmission(){


}

// maximum bend
void Fibre::bending(){

    double beta, thetac;

    beta = (1-pow((nen/nco*sin(atan(1/(inputf*2*nen)))),2));

    thetac =sqrt(nco*nco-NA*NA)/nco;

    RMin=abs(dco*(thetac-beta/2)/(beta-thetac));
    ui->doubleSpinBox_8->setValue(RMin);
}

// index
void Fibre::IndexCo(){

    ui->customPlot->clearGraphs();

    QVector<double> Nw(fsteps), ncov(fsteps);

    for(int i=0; i<fsteps; i++){

    Nw[i]=lowerw+(upperl-lowerw)/fsteps*i;
    ncov[i]=sqrt(1+B1f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1f)+B2f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2f)+B3f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3f));
    Nw[i]=Nw[i]*1000;
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(Nw, ncov);
    ui->customPlot->xAxis->setLabel("Wavelength [nm]");
    ui->customPlot->yAxis->setLabel("Index of Refraction");
    ui->customPlot->xAxis->setRange(Nw[0], Nw[fsteps-1]);
    ui->customPlot->yAxis->setRange(ncov[0], ncov[fsteps-1]);
    ui->customPlot->replot();

}

// numerical aperture
void Fibre::naperture(){

    ui->customPlot->clearGraphs();

    QVector<double> Nav(fsteps), Nw(fsteps), ncov(fsteps), Fz(fsteps), ncov2(fsteps);
    double Fzmax, Fzmin;
    int defi=0;

    for(int i=0; i<fsteps; i++){

        Nw[i]=lowerw+(upperl-lowerw)/fsteps*i;
        ncov[i]=(1+B1f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1f)+B2f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2f)+B3f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3f));
        ncov2[i]=(1+B1cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1cla)+B2cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2cla)+B3cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3cla));
        if(ncov[i]-ncov2[i]>0){
           Nav[i]=sqrt(ncov[i]-ncov2[i]);
        }
        if(ncov[i]-ncov2[i]<0){
           Nav[i]=sqrt(ncov2[i]-ncov[i]);
           defi=1;
        }
        Fz[i]=1/(2*Nav[i]);
        Nw[i]=Nw[i]*1000;
    }

    Fzmax=Fz[0];
    Fzmin=Fz[0];
    for(int i=0; i<fsteps; i++){
        if(Fz[i]<Fzmin){
            Fzmin=Fz[i];
        }
        if(Fz[i]>Fzmax){
            Fzmax=Fz[i];
        }
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(Nw, Fz);
    ui->customPlot->xAxis->setLabel("Wavelength [nm]");
    ui->customPlot->yAxis->setLabel("F#");
    ui->customPlot->xAxis->setRange(Nw[0], Nw[fsteps-1]);
    ui->customPlot->yAxis->setRange(Fzmin, Fzmax);
    ui->customPlot->replot();

    if(defi==0){
        ui->lineEdit_2->setText("Cladd");
    }

    if(defi==1){
        ui->lineEdit_2->setText("Core");
    }
}

void Fibre::evanescent(){

    double skale, theta;
    QVector<double> Nw(fsteps), ncov(fsteps), ncov2(fsteps), evan(fsteps);

    for (int i=0; i<fsteps; i++){
        Nw[i]=lowerw+(upperl-lowerw)/fsteps*i;
        ncov[i]=(1+B1f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1f)+B2f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2f)+B3f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3f));
        ncov2[i]=(1+B1cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1cla)+B2cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2cla)+B3cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3cla));
        theta=90-asin(nen/ncov[i]*sin(atan(1/(inputf*2*nen))))*180/M_PI;
        skale=2*M_PI*sqrt(ncov[i]*pow((sin(theta*M_PI/180)),2)-ncov2[i])/Nw[i];
        refl[i]=length/dco*sin(atan(1/(inputf*2*nen)))/(sqrt(ncov[i]*ncov[i]-sin(atan(1/(inputf*2*nen)))*sin(atan(1/(inputf*2*nen)))));
        evan[i]=pow((1-exp(-(dcla-dco)/2/skale)),refl[i]);
        cout<<evan[i]<<endl;
    }
}

//max number of modes
void Fibre::nmodes(){

     ui->customPlot->clearGraphs();

    QVector<double> M(fsteps), Nw(fsteps), ncov(fsteps), ncov2(fsteps), Nav(fsteps);
    double Mmax, Mmin;
    int defi=0;

    for (int i=0; i<fsteps; i++){
        Nw[i]=lowerw+(upperl-lowerw)/fsteps*i;
        ncov[i]=(1+B1f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1f)+B2f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2f)+B3f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3f));
        ncov2[i]=(1+B1cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1cla)+B2cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2cla)+B3cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3cla));
        if(ncov[i]-ncov2[i]>0){
           Nav[i]=sqrt(ncov[i]-ncov2[i]);
        }
        if(ncov[i]-ncov2[i]<0){
           Nav[i]=sqrt(ncov2[i]-ncov[i]);
           defi=1;
        }
        M[i]=4*pow((dco*Nav[i]/(Nw[i]/1000)),2)+2;
        Nw[i]=Nw[i]*1000;

    }

    Mmax=M[0];
    Mmin=M[0];
    for(int i=0; i<fsteps; i++){
        if(M[i]<Mmin){
            Mmin=M[i];
        }
        if(M[i]>Mmax){
            Mmax=M[i];
        }
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(Nw, M);
    ui->customPlot->xAxis->setLabel("Wavelength [nm]");
    ui->customPlot->yAxis->setLabel("Max. # Modes");
    ui->customPlot->xAxis->setRange(Nw[0], Nw[fsteps-1]);
    ui->customPlot->yAxis->setRange(Mmin, Mmax);
    ui->customPlot->replot();

    if(defi==0){
        ui->lineEdit_2->setText("Cladd");
    }

    if(defi==1){
        ui->lineEdit_2->setText("Core");
    }
}

//# modes
void Fibre::modes(){
    ui->customPlot->clearGraphs();

   QVector<double> M(fsteps), Nw(fsteps);
   double Mmax, Mmin, Num;
   Num = 1/(2*ui->doubleSpinBox_7->value());

   for (int i=0; i<fsteps; i++){
       Nw[i]=lowerw+(upperl-lowerw)/fsteps*i;
       M[i]=4*pow((dco*Num/(Nw[i]/1000)),2)+2;
       Nw[i]=Nw[i]*1000;

   }

   Mmax=M[0];
   Mmin=M[0];
   for(int i=0; i<fsteps; i++){
       if(M[i]<Mmin){
           Mmin=M[i];
       }
       if(M[i]>Mmax){
           Mmax=M[i];
       }
   }

   ui->customPlot->addGraph();
   ui->customPlot->graph(0)->setData(Nw, M);
   ui->customPlot->xAxis->setLabel("Wavelength [nm]");
   ui->customPlot->yAxis->setLabel("# Modes");
   ui->customPlot->xAxis->setRange(Nw[0], Nw[fsteps-1]);
   ui->customPlot->yAxis->setRange(Mmin, Mmax);
   ui->customPlot->replot();

}

//modal noise
void Fibre::mnoise(){

    ui->customPlot->clearGraphs();

    QVector<double> N(fsteps), Nw(fsteps), ncov(fsteps), ncov2(fsteps), Nav(fsteps), gauss(100), modaln(fsteps);
    double Nmax, Nmin, gaussmin, gaussmax, dx, Num;
    Num = 1/(2*ui->doubleSpinBox_7->value());

    for (int i=0; i<fsteps; i++){
        Nw[i]=lowerw+(upperl-lowerw)/fsteps*i;
        ncov[i]=(1+B1f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1f)+B2f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2f)+B3f*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3f));
        ncov2[i]=(1+B1cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C1cla)+B2cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C2cla)+B3cla*Nw[i]*Nw[i]/(Nw[i]*Nw[i]-C3cla));

        N[i]=(8*pow((dco*Num/(Nw[i]/1000)),2)/(Nw[i]/1000)+2)*res/1000000;

        for(int g=0; g<100; g++){
            dx=2/N[i]/100*g;
            gauss[g]=exp(-dx*dx)+exp(-(dx-2/N[i])*(dx-2/N[i]));
        }
        gaussmin=gauss[0];
        gaussmax=gauss[0];
        for(int g=0; g<100; g++){
            if(gauss[g]<gaussmin){
                gaussmin=gauss[g];
            }
            if(gauss[g]>gaussmax){
                gaussmax=gauss[g];
            }
        }
        modaln[i]=(gaussmax+gaussmin)/2*N[i]/res*1000/specw/(gaussmax-gaussmin);
        Nw[i]=Nw[i]*1000;
    }

    Nmax=modaln[0];
    Nmin=modaln[0];
    for(int i=0; i<fsteps; i++){
        if(modaln[i]<Nmin){
            Nmin=modaln[i];
        }
        if(modaln[i]>Nmax){
            Nmax=modaln[i];
        }
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(Nw, modaln);
    ui->customPlot->xAxis->setLabel("Wavelength [nm]");
    ui->customPlot->yAxis->setLabel("M-Noise");
    ui->customPlot->xAxis->setRange(Nw[0], Nw[fsteps-1]);
    ui->customPlot->yAxis->setRange(Nmin, Nmax);
    ui->customPlot->replot();


}

void Fibre::on_doubleSpinBox_valueChanged()
{
    dco = ui->doubleSpinBox->value();
}

void Fibre::on_doubleSpinBox_2_valueChanged()
{
    dcla = ui->doubleSpinBox_2->value();
}

// wavelength for NA
void Fibre::on_doubleSpinBox_4_valueChanged()
{
    NAw = ui->doubleSpinBox_4->value();

    NAw = NAw/1000;
    nco=(1+B1f*NAw*NAw/(NAw*NAw-C1f)+B2f*NAw*NAw/(NAw*NAw-C2f)+B3f*NAw*NAw/(NAw*NAw-C3f));

    ncla = (1+B1cla*NAw*NAw/(NAw*NAw-C1cla)+B2cla*NAw*NAw/(NAw*NAw-C2cla)+B3cla*NAw*NAw/(NAw*NAw-C3cla));
    NAw = NAw*1000;

    if(nco-ncla<0){
    NA=sqrt(ncla-nco);
    }
    if(nco-ncla>=0){
    NA=sqrt(nco-ncla);
    }

    ui->doubleSpinBox_3->setValue(NA);
}

void Fibre::on_doubleSpinBox_5_valueChanged()
{
    nen = ui->doubleSpinBox_5->value();
}

void Fibre::on_doubleSpinBox_6_valueChanged()
{
    length = ui->doubleSpinBox_6->value();
}

void Fibre::on_doubleSpinBox_7_valueChanged()
{
    inputf = ui->doubleSpinBox_7->value();
    dFz=inputf/fsteps;
}

// Go Button
void Fibre::on_pushButton_2_clicked()
{

    if(ui->checkBox->isChecked()){
        reflections();
    }

    if(ui->checkBox_2->isChecked()){
        OPL();
    }

    if(ui->checkBox_3->isChecked()){
        transmission();
    }

    if(ui->checkBox_4->isChecked()){
        IndexCo();
    }
    if(ui->checkBox_5->isChecked()){
        naperture();
    }

    if(ui->checkBox_6->isChecked()){
        nmodes();
    }

    if(ui->checkBox_7->isChecked()){
        mnoise();
    }
    if(ui->checkBox_10->isChecked()){
        modes();
    }

    bending();
}


void Fibre::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_10->setChecked(false);
}

void Fibre::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_10->setChecked(false);
}

void Fibre::on_checkBox_3_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_10->setChecked(false);
}

void Fibre::on_checkBox_4_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_10->setChecked(false);
}

void Fibre::on_checkBox_5_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_10->setChecked(false);
}

void Fibre::on_checkBox_6_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_7->setChecked(false);
    ui->checkBox_10->setChecked(false);
}

void Fibre::on_checkBox_7_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_10->setChecked(false);
}

void Fibre::on_comboBox_currentIndexChanged()
{
    int e=ui->comboBox->currentIndex();

    if(e==0){
        B1cla=0.69913;
        B2cla=0.40697;
        B3cla=1.06869;
        C1cla=0.0077317;
        C2cla=0.008731034;
        C3cla=112.685656;
    }

    if(e==1){
        B1cla=0.69788;
        B2cla=0.40575;
        B3cla=1.01796;
        C1cla=0.0077845;
        C2cla=0.0081794;
        C3cla=108,66457;
    }

    if(e==2){
        B1cla=0.87219;
        B2cla=0.21238;
        B3cla=0.94959;
        C1cla=0.005501189;
        C2cla=0.01684804;
        C3cla=104.5733257;
    }

    if(e==3){
        B1cla=0.68943;
        B2cla=0.39965;
        B3cla=0.90574;
        C1cla=0.003839;
        C2cla=0.0145612;
        C3cla=99.3253417;
    }

    if(e==4){
        B1cla=0.68908;
        B2cla=0.39717;
        B3cla=0.95894;
        C1cla=0.0051094;
        C2cla=0.01282783;
        C3cla=101.322343;
    }

    if(e==5){
        B1cla=0.50716;
        B2cla=0.59707;
        B3cla=0.69879;
        C1cla=0.00161133;
        C2cla=0.012902688;
        C3cla=77.734904228;
    }

    if(e==6){
        B1cla=0.70209;
        B2cla=0.40292;
        B3cla=1.60979;
        C1cla=0.00326498;
        C2cla=0.01535121;
        C3cla=167.81829281;
    }

    if(e==7){
        B1cla=0.88671;
        B2cla=0.21675;
        B3cla=0.69401;
        C1cla=0.006326612;
        C2cla=0.01547536;
        C3cla=78.024538923;
    }

    if(e==8){
        B1cla=0.53502;
        B2cla=0.577;
        B3cla=0.65548;
        C1cla=0.002296326;
        C2cla=0.01333563;
        C3cla=68.285151291;
    }

    if(e==9){
        B1cla=0.54956;
        B2cla=0.55151;
        B3cla=1.52791;
        C1cla=0.001271636;
        C2cla=0.013978333;
        C3cla=157.427961821;
    }

    if(e==10){
        B1cla=0.91249;
        B2cla=0.21688;
        B3cla=0.77945;
        C1cla=0.006541574;
        C2cla=0.015770336;
        C3cla=88.358496006;
    }

    if(e==11){
        B1cla=0.49211;
        B2cla=0.62925;
        B3cla=0.59202;
        C1cla=0.002310725;
        C2cla=0.012712563;
        C3cla=68.7736814;
    }

    if(e==12){
        B1cla=0.49795;
        B2cla=0.65295;
        B3cla=0.83515;
        C1cla=0.001942165;
        C2cla=0.013815652;
        C3cla=97.290999504;
    }

    if(e==13){
        B1cla=0.51512;
        B2cla=0.62804;
        B3cla=1.0743;
        C1cla=0.00069485;
        C2cla=0.0134885;
        C3cla=114.34238761;
    }

    if(e==14){
        B1cla=0.49798;
        B2cla=0.64994;
        B3cla=1.39632;
        C1cla=0.002543185;
        C2cla=0.012443403;
        C3cla=147.519485978;
    }

    if(e==15){
        B1cla=0.711040;
        B2cla=0.451885;
        B3cla=0.704048;
        C1cla=0.004130633;
        C2cla=0.01674643;
        C3cla=88.839635528;
    }

    if(e==16){
        B1cla=0.695790;
        B2cla=0.452497;
        B3cla=0.712513;
        C1cla=0.003790619;
        C2cla=0.014381046;
        C3cla=74.937433403;
    }

    if(e==17){
        B1cla=0.690618;
        B2cla=0.401996;
        B3cla=0.898817;
        C1cla=0.00383161;
        C2cla=0.01529229;
        C3cla=82.791073082;
    }

    if(e==18){
        B1cla=0.691116;
        B2cla=0.399166;
        B3cla=0.890423;
        C1cla=0.004654924;
        C2cla=0.013562932;
        C3cla=99.874179602;
    }

    if(e==19){
        B1cla=0.7028554;
        B2cla=0.4146307;
        B3cla=0.8974540;
        C1cla=0.005295808;
        C2cla=0.013066433;
        C3cla=97.934002538;
    }

    if(e==20){
        B1cla=0.7042038;
        B2cla=0.4160032;
        B3cla=0.9074049;
        C1cla=0.002646228;
        C2cla=0.016682306;
        C3cla=97.933903576;
    }

    if(e==21){
        B1cla=0.6867178;
        B2cla=0.434815;
        B3cla=0.8965658;
        C1cla=0.005281685;
        C2cla=0.013258026;
        C3cla=100.04796575;
    }

    if(e==22){
        B1cla=0.7088876;
        B2cla=0.4206803;
        B3cla=0.8956551;
        C1cla=0.003709456;
        C2cla=0.015738054;
        C3cla=97.93402233;
    }

    if(e==23){
        B1cla=0.7083925;
        B2cla=0.4203993;
        B3cla=0.8663412;
        C1cla=0.007290086;
        C2cla=0.01050295;
        C3cla=97.934279631;
    }

    if(e==24){
        B1cla=0.6869829;
        B2cla=0.4447950;
        B3cla=0.7907351;
        C1cla=0.006097673;
        C2cla=0.013344501;
        C3cla=108.92320401;
    }

    if(e==25){
        B1cla=0.7136824;
        B2cla=0.4254807;
        B3cla=0.8964226;
        C1cla=0.003808951;
        C2cla=0.016149682;
        C3cla=97.934002538;
    }

    if(e==26){
        B1cla=0.7133103;
        B2cla=0.4254807;
        B3cla=0.863198;
        C1cla=0.006912908;
        C2cla=0.011656744;
        C3cla=97.933408769;
    }

    if(e==27){
        B1cla=0.7186243;
        B2cla=0.4301997;
        B3cla=0.8543265;
        C1cla=0.004026397;
        C2cla=0.016324738;
        C3cla=97.934398385;
    }

    if(e==28){
        B1cla=0.724918;
        B2cla=0.438122;
        B3cla=0.8221368;
        C1cla=0.007596378;
        C2cla=0.011623966;
        C3cla=97.934715063;
    }

    if(e==29){
        B1cla=0.7347008;
        B2cla=0.4461191;
        B3cla=0.8081698;
        C1cla=0.00584734;
        C2cla=0.015527179;
        C3cla=97.934833817;
    }

    naperture();
    on_doubleSpinBox_4_valueChanged();
}


void Fibre::on_doubleSpinBox_9_valueChanged()
{
    res=ui->doubleSpinBox_9->value();

    mnoise();
}

void Fibre::on_spinBox_valueChanged()
{
    specw=ui->spinBox->value();
    mnoise();
}

void Fibre::on_spinBox_2_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_2->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}

void Fibre::on_pushButton_3_clicked()
{
    if(ui->checkBox_8->isChecked()){
        QString save=ui->lineEdit_3->text();
        ui->customPlot->savePdf(save+".pdf");
    }
    if(ui->checkBox_9->isChecked()){
        QString save=ui->lineEdit_3->text();
        ui->customPlot->savePng(save+".png");
    }
}

void Fibre::on_checkBox_10_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
    ui->checkBox_5->setChecked(false);
    ui->checkBox_4->setChecked(false);
    ui->checkBox_6->setChecked(false);
    ui->checkBox_7->setChecked(false);
}
