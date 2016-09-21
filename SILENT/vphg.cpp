#include "vphg.h"
#include "ui_vphg.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <mainwindow.h>

using namespace std;

double gv, cwv, uwv, lwv, twv, nv, dnv, dv, udv, ldv, alpha2b, dn_l, dd, dlv;
int steps=1000, test;
QVector<double> etav_s(steps), etav_p(steps), etav(steps), dvp(steps), lv(steps);

VPHG::VPHG(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VPHG)
{
    ui->setupUi(this);

    this->setWindowTitle("VPHG Tool");

    ui->checkBox->setChecked(true);

    ui->doubleSpinBox->setValue(2000);
    gv=ui->doubleSpinBox->value();

    ui->doubleSpinBox_2->setValue(600);
    cwv=ui->doubleSpinBox_2->value();

    ui->doubleSpinBox_3->setValue(800);
    uwv=ui->doubleSpinBox_3->value();

    ui->doubleSpinBox_4->setValue(400);
    lwv=ui->doubleSpinBox_4->value();

    ui->doubleSpinBox_5->setValue(600);
    twv=ui->doubleSpinBox_5->value();

    ui->doubleSpinBox_6->setValue(1.4987);
    nv=ui->doubleSpinBox_6->value();

    ui->doubleSpinBox_7->setValue(0.07);
    dnv=ui->doubleSpinBox_7->value();

    ui->doubleSpinBox_8->setValue(0.005);
    dv=ui->doubleSpinBox_8->value();

    ui->doubleSpinBox_9->setValue(0.02);
    udv=ui->doubleSpinBox_9->value();

    ui->doubleSpinBox_10->setValue(0);
    ldv=ui->doubleSpinBox_10->value();

    alpha2b=asin(cwv/2/nv*gv/1000000)*180/3.14;
    ui->doubleSpinBox_11->setValue(alpha2b);
    ui->doubleSpinBox_13->setValue(alpha2b);

    dn_l = 4*nv*sin(alpha2b*3.14/180)*sin(alpha2b*3.14/180)/10;
    ui->doubleSpinBox_12->setValue(dn_l);

    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->legend->setVisible(true);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);

    VPHG::calculateVPH();


}

VPHG::~VPHG()
{
    delete ui;
}

// vs. Thickness
void VPHG::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void VPHG::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

//
void VPHG::calculateVPH()
{
    // vs. Thickness
    if(ui->checkBox->isChecked()){

        ui->customPlot->clearGraphs();

        alpha2b=asin(cwv/2/nv*gv/1000000)*180/3.14;
        dd=(udv-ldv)/steps;

        for (int i=0; i < steps; i++){
            dvp[i] = ldv + i*dd;

            etav_s[i] = pow((sin(M_PI*dnv*dvp[i]/cwv*1000000/cos(alpha2b*M_PI/180))),2);

            etav_p[i] = pow((sin(M_PI*dnv*dvp[i]*cos(M_PI/180*2*alpha2b)/cwv*1000000/cos(alpha2b*M_PI/180))),2);

            etav[i] = (etav_s[i] + etav_p[i])/2;

            dvp[i]=dvp[i]*1000;
            }

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setPen(QPen(Qt::red));
        ui->customPlot->graph(0)->setName("s Pol");
        ui->customPlot->graph(0)->setData(dvp, etav_s);
        ui->customPlot->addGraph();
        ui->customPlot->graph(1)->setPen(QPen(Qt::green));
        ui->customPlot->graph(1)->setName("p Pol");
        ui->customPlot->graph(1)->setData(dvp, etav_p);
        ui->customPlot->addGraph();
        ui->customPlot->graph(2)->setPen(QPen(Qt::blue));
        ui->customPlot->graph(2)->setName("ave Pol");
        ui->customPlot->graph(2)->setData(dvp, etav);
        ui->customPlot->xAxis->setLabel("Thickness [um]");
        ui->customPlot->yAxis->setLabel("Efficiency");
        ui->customPlot->xAxis->setRange(ldv*1000, udv*1000);
        ui->customPlot->yAxis->setRange(0, 1.05);
        ui->customPlot->replot();

    }

    // vs. Wavelength
    if(ui->checkBox_2->isChecked()){

        ui->customPlot->clearGraphs();

        dlv=(uwv-lwv)/steps;

        for (int i=0; i < steps; i++){
           lv[i] = (lwv + i*dlv)/1000000;

           etav_s[i] = pow((sin(M_PI*dnv*dv/lv[i]/cos(alpha2b*M_PI/180))),2);

           etav_p[i] = pow((sin(M_PI*dnv*dv*cos(M_PI/180*2*alpha2b)/lv[i]/cos(alpha2b*M_PI/180))),2);

           etav[i] = (etav_s[i] + etav_p[i])/2;

           lv[i]=lv[i]*1000000;
        }

           ui->customPlot->addGraph();
           ui->customPlot->graph(0)->setPen(QPen(Qt::red));
           ui->customPlot->graph(0)->setName("s Pol");
           ui->customPlot->graph(0)->setData(lv, etav_s);
           ui->customPlot->addGraph();
           ui->customPlot->graph(1)->setPen(QPen(Qt::green));
           ui->customPlot->graph(1)->setName("p Pol");
           ui->customPlot->graph(1)->setData(lv, etav_p);
           ui->customPlot->addGraph();
           ui->customPlot->graph(2)->setPen(QPen(Qt::blue));
           ui->customPlot->graph(2)->setName("ave Pol");
           ui->customPlot->graph(2)->setData(lv, etav);
           ui->customPlot->xAxis->setLabel("Wavlength [nm]");
           ui->customPlot->yAxis->setLabel("Efficiency");
           ui->customPlot->xAxis->setRange(lwv, uwv);
           ui->customPlot->yAxis->setRange(0, 1.05);
           ui->customPlot->replot();


    }

    if(ui->checkBox_3->isChecked()){

        ui->customPlot->clearGraphs();

        double alpha2bt=asin(twv/2/nv*gv/1000000)*180/M_PI;
        ui->doubleSpinBox_13->setValue(alpha2bt);

        dlv=(uwv-lwv)/steps;

        for (int i = 0; i < steps; i++){

                      lv[i] =  (lwv + i*dlv)/1000000;

                      etav_s[i] = pow((sin(M_PI*dnv*dv/lv[i]/cos(alpha2bt*M_PI/180))),2);

                      etav_p[i] = pow((sin(M_PI*dnv*dv*cos(M_PI/180*2*alpha2bt)/lv[i]/cos(alpha2bt*M_PI/180))),2);

                      etav[i] = (etav_s[i] + etav_p[i])/2;

                      lv[i]=lv[i]*1000000;

                      }

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setPen(QPen(Qt::red));
        ui->customPlot->graph(0)->setName("s Pol");
        ui->customPlot->graph(0)->setData(lv, etav_s);
        ui->customPlot->addGraph();
        ui->customPlot->graph(1)->setPen(QPen(Qt::green));
        ui->customPlot->graph(1)->setName("p Pol");
        ui->customPlot->graph(1)->setData(lv, etav_p);
        ui->customPlot->addGraph();
        ui->customPlot->graph(2)->setPen(QPen(Qt::blue));
        ui->customPlot->graph(2)->setName("ave Pol");
        ui->customPlot->graph(2)->setData(lv, etav);
        ui->customPlot->xAxis->setLabel("Wavlength [nm]");
        ui->customPlot->yAxis->setLabel("Efficiency");
        ui->customPlot->xAxis->setRange(lwv, uwv);
        ui->customPlot->yAxis->setRange(0, 1.05);
        ui->customPlot->replot();
    }
}

void VPHG::on_doubleSpinBox_valueChanged()
{
    gv=ui->doubleSpinBox->value();

    alpha2b=asin(cwv/2/nv*gv/1000000)*180/M_PI;
    ui->doubleSpinBox_11->setValue(alpha2b);

    dn_l = 4*nv*sin(alpha2b*M_PI/180)*sin(alpha2b*M_PI/180)/10;
    ui->doubleSpinBox_12->setValue(dn_l);

    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_2_valueChanged()
{
    cwv=ui->doubleSpinBox_2->value();

    alpha2b=asin(cwv/2/nv*gv/1000000)*180/3.14;
    ui->doubleSpinBox_11->setValue(alpha2b);

    dn_l = 4*nv*sin(alpha2b*3.14/180)*sin(alpha2b*3.14/180)/10;
    ui->doubleSpinBox_12->setValue(dn_l);

    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_6_valueChanged()
{
    nv=ui->doubleSpinBox_6->value();

    alpha2b=asin(cwv/2/nv*gv/1000000)*180/3.14;
    ui->doubleSpinBox_11->setValue(alpha2b);

    dn_l = 4*nv*sin(alpha2b*3.14/180)*sin(alpha2b*3.14/180)/10;
    ui->doubleSpinBox_12->setValue(dn_l);

    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_7_valueChanged()
{
    dnv=ui->doubleSpinBox_7->value();

    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_8_valueChanged()
{
    dv=ui->doubleSpinBox_8->value();

    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_3_valueChanged()
{
    uwv=ui->doubleSpinBox_3->value();
    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_4_valueChanged()
{
    lwv=ui->doubleSpinBox_4->value();
    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_5_valueChanged()
{
    twv=ui->doubleSpinBox_5->value();
    double alpha2bt=asin(twv/2/nv*gv/1000000)*180/M_PI;
    ui->doubleSpinBox_13->setValue(alpha2bt);

    dn_l = 4*nv*sin(alpha2bt*3.14/180)*sin(alpha2bt*3.14/180)/10;
    ui->doubleSpinBox_12->setValue(dn_l);

    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_9_valueChanged()
{
    udv=ui->doubleSpinBox_9->value();
    VPHG::calculateVPH();
}

void VPHG::on_doubleSpinBox_10_valueChanged()
{
    ldv=ui->doubleSpinBox_10->value();
    VPHG::calculateVPH();
}

void VPHG::on_checkBox_3_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
}


void VPHG::on_spinBox_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox->value());
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}

void VPHG::on_pushButton_2_clicked()
{
    if(ui->checkBox_4->isChecked()){
        QString save=ui->lineEdit->text();
        ui->customPlot->savePdf(save+".pdf");
    }
    if(ui->checkBox_5->isChecked()){
        QString save=ui->lineEdit->text();
        ui->customPlot->savePng(save+".png");
    }
}

