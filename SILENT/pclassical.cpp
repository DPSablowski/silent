#include "pclassical.h"
#include "ui_pclassical.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stdio.h>
#include <QCheckBox>
#include <QPen>

using namespace std;

double x1cl, x2cl, y1cl, y2cl;

PClassical::PClassical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PClassical)
{
    ui->setupUi(this);
    this->setWindowTitle("Parameters Classical Spectrograph");
    ui->checkBox_14->setChecked(true);

    ui->customPlot->setInteraction(QCP::iRangeDrag, true);
    ui->customPlot->setInteraction(QCP::iRangeZoom, true);
    ui->customPlot->setInteraction(QCP::iSelectPlottables, true);

    ui->comboBox->addItem("Resolving Power");
    ui->comboBox->addItem("2-Pixel Resolving Power");
    ui->comboBox->addItem("Dispersion");
    ui->comboBox->addItem("Anamorphism");
    ui->comboBox->addItem("Nyquist");
    ui->comboBox->addItem("Slit Width");
    ui->comboBox->addItem("Earth Transmission");
    ui->comboBox->addItem("Photons/s @ Telescope");
    ui->comboBox->addItem("QE CCD");
    ui->comboBox->addItem("Grating Efficiency");
    ui->comboBox->addItem("Instrument Efficiency");
    ui->comboBox->addItem("Overall Efficiency");
    ui->comboBox->addItem("Surface Efficiency");
    ui->comboBox->addItem("Neon Spectrum");
    ui->comboBox->addItem("Balmer Spectrum");

    ui->customPlot->axisRect()->setupFullAxesBox(true);
}

PClassical::~PClassical()
{
    delete ui;
}

// find values
void PClassical::on_pushButton_3_clicked()
{
    string zeile, one, two;
    this->setCursor(QCursor(Qt::WaitCursor));

        if(ui->comboBox->currentIndex()==0){

            ifstream toplot1("resolvingcl.txt");

            QFile checkfile3("resolvingcl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }

        if(ui->comboBox->currentIndex()==1){

            ifstream toplot1("twopixRcl.txt");

            QFile checkfile3("twopixRcl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }

        if(ui->comboBox->currentIndex()==2){

            ifstream toplot1("dispersioncl.txt");

            QFile checkfile3("dispersioncl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==3){

            ifstream toplot1("anamorphismcl.txt");

            QFile checkfile3("anamorphismcl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==4){

            ifstream toplot1("nyquistcl.txt");

            QFile checkfile3("nyquistcl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }

        if(ui->comboBox->currentIndex()==5){

            ifstream toplot("slitcl.txt");

            QFile checkfile3("slitcl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot, zeile))
               ++ number_of_lines;

            toplot.clear();
            toplot.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }

        if(ui->comboBox->currentIndex()==6){

            ifstream toplot1("atmospherecl.txt");

            QFile checkfile3("atmospherecl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==7){

            ifstream toplot1("telescopecl.txt");

            QFile checkfile3("telescopecl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==8){

            ifstream toplot1("ccdcl.txt");

            QFile checkfile3("ccdcl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==9){

            ifstream toplot1("gratingcl.txt");

            QFile checkfile3("gratingcl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==10){

            ifstream toplot1("efficiencycl.txt");

            QFile checkfile3("efficiencycl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==11){

            ifstream toplot1("overallcl.txt");

            QFile checkfile3("overallcl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==12){

            ifstream toplot1("surfacescl.txt");

            QFile checkfile3("surfacescl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }
        if(ui->comboBox->currentIndex()==13){

            ifstream toplot1("neoncl.txt");

            QFile checkfile3("neoncl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }

        if(ui->comboBox->currentIndex()==14){

            ifstream toplot1("balmercl.txt");

            QFile checkfile3("balmercl.txt");

            if(!checkfile3.exists()){
                QMessageBox::information(this, "Error", "Parameters not calculated.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }

            int number_of_lines =0;

            while(std::getline(toplot1, zeile))
               ++ number_of_lines;

            toplot1.clear();
            toplot1.seekg(0, ios::beg);

            QVector<double> a(number_of_lines), b(number_of_lines);

            for (int i=0; i<number_of_lines; i++){
            toplot1 >> one >>two;
            istringstream ist(one);
            ist >> a[i];
            istringstream ist2(two);
            ist2 >> b[i];
            }
            toplot1.close();

           x1cl=a[0];
           x2cl=a[0];
           y1cl=b[0];
           y2cl=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x1cl){
                    x1cl=a[i];
                }
                if(a[i]>x2cl){
                    x2cl=a[i];
                }
                if(b[i]<y1cl){
                    y1cl=b[i];
                }
                if(b[i]>y2cl){
                    y2cl=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x1cl);
            ui->doubleSpinBox_2->setValue(x2cl);
            ui->doubleSpinBox_3->setValue(y1cl);
            ui->doubleSpinBox_4->setValue(y2cl);
        }

    this->setCursor(QCursor(Qt::ArrowCursor));
}

// plot
void PClassical::on_pushButton_2_clicked()
{
    x1cl=ui->doubleSpinBox->value();
    x2cl=ui->doubleSpinBox_2->value();
    y1cl=ui->doubleSpinBox_3->value();
    y2cl=ui->doubleSpinBox_4->value();

    string zeile, one, two;

    this->setCursor(QCursor(Qt::ArrowCursor));

    if(ui->comboBox->currentIndex()==0){

        ifstream toplot1("resolvingcl.txt");

        QFile checkfile3("resolvingcl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Resolving Power");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==1){

        ifstream toplot1("twopixRcl.txt");

        QFile checkfile3("twopixRcl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("2-Pixel Resolving Power");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==2){

        ifstream toplot1("dispersioncl.txt");

        QFile checkfile3("dispersioncl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Dispersion [nm/pix]");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==3){

        ifstream toplot1("anamorphismcl.txt");

        QFile checkfile3("anamorphismcl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Anamorphism");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==4){

        ifstream toplot1("nyquistcl.txt");

        QFile checkfile3("nyquistcl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Nyquist Factor");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==5){

        ifstream toplot1("slitcl.txt");

        QFile checkfile3("slitcl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Imaged Slit Width [mm]");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==6){

        ifstream toplot1("atmospherecl.txt");

        QFile checkfile3("atmospherecl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Earth Transmission");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==7){

        ifstream toplot1("telescopecl.txt");

        QFile checkfile3("telescopecl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Photons/s @ Telescope");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==8){

        ifstream toplot1("ccdcl.txt");

        QFile checkfile3("ccdcl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("CCD Efficiency");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==9){

        ifstream toplot1("gratingcl.txt");

        QFile checkfile3("gratingcl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Grating Efficiecy");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==10){

        ifstream toplot1("efficiencycl.txt");

        QFile checkfile3("efficiencycl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Instrument Efficiency");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==11){

        ifstream toplot1("overallcl.txt");

        QFile checkfile3("overallcl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Overall Efficiency");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==12){

        ifstream toplot1("surfacescl.txt");

        QFile checkfile3("surfacescl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("Surface Efficiency");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==13){

        ui->customPlot->clearGraphs();

        ifstream toplot1("neoncl.txt");

        QFile checkfile3("neoncl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
        //ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("rel. Intensity");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==14){

        ui->customPlot->clearGraphs();

        ifstream toplot1("balmercl.txt");

        QFile checkfile3("balmercl.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot1, zeile))
           ++ number_of_lines;

        toplot1.clear();
        toplot1.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot1 >> one >>two;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        }
        toplot1.close();

        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(a, b);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
        //ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("rel. Intensity");
        ui->customPlot->xAxis->setRange(x1cl, x2cl);
        ui->customPlot->yAxis->setRange(y1cl, y2cl);
        ui->customPlot->replot();
    }
    this->setCursor(QCursor(Qt::ArrowCursor));
}

void PClassical::on_pushButton_4_clicked()
{
    QString save=ui->lineEdit->text();
    if(ui->checkBox_14->isChecked()){
    ui->customPlot->savePdf(save);
    }

    if(ui->checkBox_15->isChecked()){
    ui->customPlot->savePng(save);
    }
}

void PClassical::on_checkBox_14_clicked()
{
    ui->checkBox_15->setChecked(false);
}

void PClassical::on_checkBox_15_clicked()
{
    ui->checkBox_14->setChecked(false);
}

void PClassical::on_spinBox_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}
