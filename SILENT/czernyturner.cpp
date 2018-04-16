#include "czernyturner.h"
#include "ui_czernyturner.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

CzernyTurner::CzernyTurner(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CzernyTurner)
{
    ui->setupUi(this);
    this->setWindowTitle("Czerny-Turner Tool");

    ui->doubleSpinBox->setValue(1500);
    ui->doubleSpinBox_2->setValue(1500);
    ui->doubleSpinBox_3->setValue(500);
    ui->doubleSpinBox_5->setValue(3.464);
    ui->doubleSpinBox_6->setValue(14);
    ui->doubleSpinBox_7->setValue(1200);
    ui->doubleSpinBox_10->setValue(50);
    ui->doubleSpinBox_13->setValue(50);
    ui->spinBox->setValue(1);

    ui->checkBox->setChecked(true);
}

CzernyTurner::~CzernyTurner()
{
    delete ui;
}

void CzernyTurner::on_pushButton_2_clicked()
{

    double collct=ui->doubleSpinBox->value();
    double camct = ui->doubleSpinBox_2->value();
    double wavect = ui->doubleSpinBox_3->value()/1000000;

    double totct = ui->doubleSpinBox_6->value();
    int nct = ui->spinBox->value();
    double Zctp=0, Zctn=0;
    double gct = ui->doubleSpinBox_7->value();
    double alphact = asin(nct*wavect*gct/2/cos(totct/2))*180/M_PI+totct/2;
    double betact = alphact - totct;
    double dwl = ui->doubleSpinBox_13->value()/1000000;
    ui->doubleSpinBox_8->setValue(alphact);
    ui->doubleSpinBox_9->setValue(betact);
    double theta1=0, theta2=0;
    double d1 = ui->doubleSpinBox_10->value();
    double F1 = collct/d1;

    if(ui->checkBox->isChecked()){  // flat-field
        theta2 = ui->doubleSpinBox_5->value();
        theta1 = theta2/(pow((camct/collct),2)*pow((cos(alphact/180*M_PI)/cos(betact/180*M_PI)),3));
        ui->doubleSpinBox_4->setValue(theta1);

        double delct1 = 1/((8+pow((64+10*pow(camct,4)+pow(camct,5)),0.5))/pow(camct,3));
        double delct2 = 1/((8-pow((64+10*pow(camct,4)+pow(camct,5)),0.5))/pow(camct,3));

        if(delct1>=0){
            Zctp = delct1+camct/(pow(3,0.5));
            Zctn = delct1-camct/(pow(3,0.5));
        }
        else{
            Zctp = delct2+camct/(pow(3,0.5));
            Zctn = delct2-camct/(pow(3,0.5));
        }
        if(Zctp>=0){
            ui->doubleSpinBox_11->setValue(Zctp);
            double curvect = pow((theta2/180*M_PI),4)*(1-30*pow((Zctp/camct/2),2)+48*pow((Zctp/camct/2),3)-27*pow((Zctp/camct/2),4))/48-pow((theta2/180*M_PI),2)*(1-3*pow((Zctp/camct/2),2))/4;
            ui->doubleSpinBox_12->setValue(1/curvect);
        }
        else{
            ui->doubleSpinBox_11->setValue(Zctn);
            double curvect = pow((theta2/180*M_PI),4)*(1-30*pow((Zctn/camct/2),2)+48*pow((Zctn/camct/2),3)-27*pow((Zctn/camct/2),4))/48-pow((theta2/180*M_PI),2)*(1-3*pow((Zctp/camct/2),2))/4;
            ui->doubleSpinBox_12->setValue(1/curvect);
        }

        cout<<delct1<<"\t"<<delct2<<endl;
        cout<<Zctp<<"\t"<<Zctn<<endl;
    }
    else{
        if(ui->checkBox_2->isChecked()){// coma corrected
            theta1 = ui->doubleSpinBox_4->value();
            theta2 = theta1*(pow((camct/collct),2)*pow((cos(alphact/180*M_PI)/cos(betact/180*M_PI)),3));
            ui->doubleSpinBox_5->setValue(theta2);
            double Zct = ui->doubleSpinBox_11->value();
            double curvect = pow((theta2/180*M_PI),4)*(1-30*pow((Zct/camct/2),2)+48*pow((Zct/camct/2),3)-27*pow((Zct/camct/2),4))/48-pow((theta2/180*M_PI),2)*(1-3*pow((Zct/camct/2),2))/4;
            ui->doubleSpinBox_12->setValue(1/curvect);
        }
        else{
            theta1 = ui->doubleSpinBox_4->value();
            theta2 = ui->doubleSpinBox_5->value();
            double Zct = ui->doubleSpinBox_11->value();
            double curvect = pow((theta2/180*M_PI),4)*(1-30*pow((Zct/camct/2),2)+48*pow((Zct/camct/2),3)-27*pow((Zct/camct/2),4))/48-pow((theta2/180*M_PI),2)*(1-3*pow((Zct/camct/2),2))/4;
            ui->doubleSpinBox_12->setValue(1/curvect);
        }
    }
    double DAT = pow(theta1/180*M_PI,2)*d1/2*camct/collct*(1+pow((camct/collct),3)*pow((cos(alphact/180*M_PI)/cos(betact/180*M_PI)),6));
    ui->doubleSpinBox_14->setValue(DAT*1000);

    double aup = asin(nct*(wavect+dwl)*gct/2/cos(totct/2))*180/M_PI+totct/2;
    double bup = aup - totct;
    double alo = asin(nct*(wavect-dwl)*gct/2/cos(totct/2))*180/M_PI+totct/2;
    double blo = alo - totct;
    double DKTTup = theta1/180*M_PI*d1/16*3/F1*camct/collct*(1-pow((cos(alphact/180*M_PI)*cos(aup/180*M_PI)/cos(bup/180*M_PI)/cos(betact/180*M_PI)),3));
    double DKTTlo = theta1/180*M_PI*d1/16*3/F1*camct/collct*(1-pow((cos(alphact/180*M_PI)*cos(alo/180*M_PI)/cos(blo/180*M_PI)/cos(betact/180*M_PI)),3));
    ui->doubleSpinBox_15->setValue(DKTTup*1000);
    ui->doubleSpinBox_17->setValue(DKTTlo*1000);

    double DST = d1/64/pow(F1,2)*camct/collct*(1+pow((collct/camct),3));
    ui->doubleSpinBox_16->setValue(DST*1000);

}

void CzernyTurner::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
        ui->checkBox_2->setChecked(false);
        ui->doubleSpinBox_5->setEnabled(false);
        ui->doubleSpinBox_5->setValue(3.464);
        ui->doubleSpinBox_4->setEnabled(false);
        ui->doubleSpinBox_11->setEnabled(false);
        ui->doubleSpinBox_11->setValue(0.00);

        double gct = ui->doubleSpinBox_7->value();
        double collct=ui->doubleSpinBox->value();
        double camct = ui->doubleSpinBox_2->value();
        double wavect = ui->doubleSpinBox_3->value()/1000000;
        int nct = ui->spinBox->value();
        double totct = ui->doubleSpinBox_6->value();
        double alphact = asin(nct*wavect*gct/2/cos(totct/2))*180/M_PI+totct/2;
        double betact = alphact - totct;
        ui->doubleSpinBox_8->setValue(alphact);
        ui->doubleSpinBox_9->setValue(betact);
        double theta2 = ui->doubleSpinBox_5->value();
        double theta1 = theta2/(pow((camct/collct),2)*pow((cos(alphact/180*M_PI)/cos(betact/180*M_PI)),3));
        ui->doubleSpinBox_4->setValue(theta1);
    }
    else{
        if(ui->checkBox_2->isChecked()){
            ui->doubleSpinBox_4->setEnabled(true);
            ui->doubleSpinBox_5->setEnabled(false);
            ui->doubleSpinBox_5->setValue(0.00);
        }
        else{
            ui->doubleSpinBox_4->setEnabled(true);
            ui->doubleSpinBox_5->setEnabled(true);
            ui->doubleSpinBox_11->setEnabled(true);
        }
    }
}

void CzernyTurner::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked()){
        ui->checkBox->setChecked(false);
        ui->doubleSpinBox_4->setEnabled(true);
        ui->doubleSpinBox_5->setEnabled(false);
        ui->doubleSpinBox_11->setEnabled(true);
        ui->doubleSpinBox_5->setValue(0.00);
    }
    else{
        if(ui->checkBox->isChecked()){
            ui->doubleSpinBox_5->setEnabled(false);
            ui->doubleSpinBox_5->setValue(3.464);
            ui->doubleSpinBox_4->setEnabled(false);
            ui->doubleSpinBox_11->setEnabled(false);
            ui->doubleSpinBox_11->setValue(0.00);

            double gct = ui->doubleSpinBox_7->value();
            double collct=ui->doubleSpinBox->value();
            double camct = ui->doubleSpinBox_2->value();
            double wavect = ui->doubleSpinBox_3->value()/1000000;
            int nct = ui->spinBox->value();
            double totct = ui->doubleSpinBox_6->value();
            double alphact = asin(nct*wavect*gct/2/cos(totct/2))*180/M_PI+totct/2;
            double betact = alphact - totct;
            ui->doubleSpinBox_8->setValue(alphact);
            ui->doubleSpinBox_9->setValue(betact);
            double theta2 = ui->doubleSpinBox_5->value();
            double theta1 = theta2/(pow((camct/collct),2)*pow((cos(alphact/180*M_PI)/cos(betact/180*M_PI)),3));
            ui->doubleSpinBox_4->setValue(theta1);
        }
        else{
            ui->doubleSpinBox_4->setEnabled(true);
            ui->doubleSpinBox_5->setEnabled(true);
            ui->doubleSpinBox_11->setEnabled(true);
        }
    }
}
