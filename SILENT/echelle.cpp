#include "echelle.h"
#include "ui_echelle.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <QCheckBox>
#include <QPen>


using namespace std;

double x1, x2, y11, y2;
string zeile, one, two;

Echelle::Echelle(QWidget *parent) : QDialog(parent),
    ui(new Ui::Echelle)

{
    ui->setupUi(this);
    this->setWindowTitle("Echelle Parameters");

    ui->spinBox->setValue(1500);
    ui->spinBox_2->setValue(1024);

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
    ui->comboBox->addItem("Échelle Efficiency");
    ui->comboBox->addItem("XD Efficiency");
    ui->comboBox->addItem("XD * É Efficiency");
    ui->comboBox->addItem("Instrument Efficiency");
    ui->comboBox->addItem("Overall Efficiency");
    ui->comboBox->addItem("Surface Efficiency");
    ui->comboBox->addItem("Échellogram");

    QFont legendFont = font();
    legendFont.setPointSize(16);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);

    connect(ui->customPlot, SIGNAL(mouseMove(QMouseEvent*)), this ,SLOT(showPointToolTip(QMouseEvent*)));

}

Echelle::~Echelle()
{
    delete ui;
}

//********************************************************
//show mouse coordinates
//********************************************************
void Echelle::showPointToolTip(QMouseEvent *event)
{

    double xc = ui->customPlot->xAxis->pixelToCoord(event->pos().x());
    double yc = ui->customPlot->yAxis->pixelToCoord(event->pos().y());

    setToolTip(QString("%1 , %2").arg(xc).arg(yc));
}

void Echelle::seData(QString str)
{
    ui->lineEdit_2->setText(str);
}

//plot file
void Echelle::on_pushButton_2_clicked()
{
this->setCursor(QCursor(Qt::WaitCursor));

    x1=ui->doubleSpinBox->value();
    x2=ui->doubleSpinBox_2->value();
    y11=ui->doubleSpinBox_3->value();
    y2=ui->doubleSpinBox_4->value();



    if(ui->comboBox->currentIndex()==0){

        ifstream toplot1("resolution.txt");

        QFile checkfile3("resolution.txt");

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
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==1){

        ifstream toplot1("twopixR.txt");

        QFile checkfile3("twopixR.txt");

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
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==2){

        ifstream toplot2("dispersion.txt");

        QFile checkfile3("dispersion.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("Dispersion [nm/pix]");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }


    if(ui->comboBox->currentIndex()==3){

        ifstream toplot2("anamorphism.txt");

        QFile checkfile3("anamorphism.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("Anamorphism");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==4){

        ifstream toplot2("nyquist.txt");

        QFile checkfile3("nyquist.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("Nyquist Factor");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==5){

        ifstream toplot2("slit.txt");

        QFile checkfile3("slit.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("Projected Slit Width [mm]");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==6){

        ifstream toplot2("atmosphere.txt");

        QFile checkfile3("atmosphere.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("Earth Atm. Transmission");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->rescaleAxes();
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==7){

        ifstream toplot2("telescope.txt");

        QFile checkfile3("telescope.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("Photons/s @ Telescope");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==8){

        ifstream toplot2("ccd.txt");

        QFile checkfile3("ccd.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("CCD Efficiency");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==9){

        ifstream toplot2("echelle.txt");

        QFile checkfile3("echelle.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("Echelle Efficiency");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==10){

        ifstream toplot2("grating.txt");

        QFile checkfile3("grating.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("CD Efficiency");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==11){

        ifstream toplot2("gratings.txt");

        QFile checkfile3("gratings.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->yAxis->setLabel("Echelle * CD Efficiency");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==12){

        ifstream toplot2("efficiency.txt");

        QFile checkfile3("efficiency.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->yAxis->setLabel("Instrument Efficiency");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==13){

        ifstream toplot2("overall.txt");

        QFile checkfile3("overall.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->yAxis->setLabel("Overall Efficiency");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==14){

        ifstream toplot2("surfaces.txt");

        QFile checkfile3("surfaces.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();
        ui->customPlot->addGraph();
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->yAxis->setLabel("Surface Efficiency");
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->xAxis->setRange(x1, x2);
        ui->customPlot->yAxis->setRange(y11, y2);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==15){

        ifstream toplot2("echello.txt");

        QFile checkfile3("echello.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(toplot2, zeile))
           ++ number_of_lines;

        toplot2.clear();
        toplot2.seekg(0, ios::beg);

        QVector<double> c(number_of_lines), d(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        toplot2 >> one >>two;
        istringstream ist(one);
        ist >> c[i];
        istringstream ist2(two);
        ist2 >> d[i];
        }
        toplot2.close();

        ui->customPlot->addGraph(0);
        ui->customPlot->graph(0)->setData(c, d);
        ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsNone);
        ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 2));
        ui->customPlot->yAxis->setLabel("Pixel y");
        ui->customPlot->xAxis->setLabel("Pixel x");
        ui->customPlot->xAxis->setRange(0, ui->spinBox->value());
        ui->customPlot->yAxis->setRange(0, ui->spinBox_2->value());
        ui->customPlot->replot();
    }


this->setCursor(QCursor(Qt::ArrowCursor));
}

// find values
void Echelle::on_pushButton_3_clicked()
{
    ui->customPlot->clearGraphs();
this->setCursor(QCursor(Qt::WaitCursor));
    if(ui->comboBox->currentIndex()==0){

        ifstream toplot1("resolution.txt");

        QFile checkfile3("resolution.txt");

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
        ui->customPlot->rescaleAxes();

    }

    if(ui->comboBox->currentIndex()==1){

        ifstream toplot1("twopixR.txt");

        QFile checkfile3("twopixR.txt");

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
        ui->customPlot->rescaleAxes();

    }

    if(ui->comboBox->currentIndex()==2){

        ifstream toplot1("dispersion.txt");

        QFile checkfile3("dispersion.txt");

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
        ui->customPlot->rescaleAxes();

    }


    if(ui->comboBox->currentIndex()==3){

        ifstream toplot1("anamorphism.txt");

        QFile checkfile3("anamorphism.txt");

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
        ui->customPlot->rescaleAxes();

    }


    if(ui->comboBox->currentIndex()==4){

        ifstream toplot1("nyquist.txt");

        QFile checkfile3("nyquist.txt");

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
        ui->customPlot->rescaleAxes();

    }

    if(ui->comboBox->currentIndex()==5){

        ifstream toplot1("slit.txt");

        QFile checkfile3("slit.txt");

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
        ui->customPlot->rescaleAxes();

    }
    if(ui->comboBox->currentIndex()==6){

        ifstream toplot1("atmosphere.txt");

        QFile checkfile3("atmosphere.txt");

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
        ui->customPlot->rescaleAxes();

    }
    if(ui->comboBox->currentIndex()==7){

        ifstream toplot1("telescope.txt");

        QFile checkfile3("telescope.txt");

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
        ui->customPlot->rescaleAxes();

    }
    if(ui->comboBox->currentIndex()==8){

        ifstream toplot1("ccd.txt");

        QFile checkfile3("ccd.txt");

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
        ui->customPlot->rescaleAxes();

    }
    if(ui->comboBox->currentIndex()==9){

        ifstream toplot1("echelle.txt");

        QFile checkfile3("echelle.txt");

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
        ui->customPlot->rescaleAxes();

    }
    if(ui->comboBox->currentIndex()==10){

        ifstream toplot1("grating.txt");

        QFile checkfile3("grating.txt");

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
        ui->customPlot->rescaleAxes();

    }
    if(ui->comboBox->currentIndex()==11){

        ifstream toplot1("gratings.txt");

        QFile checkfile3("gratings.txt");

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
        ui->customPlot->rescaleAxes();


    }
        if(ui->comboBox->currentIndex()==12){

            ifstream toplot1("efficiency.txt");

            QFile checkfile3("efficiency.txt");

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
            ui->customPlot->rescaleAxes();

        }
            if(ui->comboBox->currentIndex()==13){

                ifstream toplot1("overall.txt");

                QFile checkfile3("overall.txt");

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
                ui->customPlot->rescaleAxes();
    }

            if(ui->comboBox->currentIndex()==14){

                ifstream toplot1("surfaces.txt");

                QFile checkfile3("surfaces.txt");

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
                ui->customPlot->rescaleAxes();
    }

this->setCursor(QCursor(Qt::ArrowCursor));
}


void Echelle::on_pushButton_4_clicked()
{
    QString save=ui->lineEdit->text();

    if(ui->checkBox_16->isChecked()){
        ui->customPlot->savePdf(save);
    }

    if(ui->checkBox_17->isChecked()){
        ui->customPlot->savePng(save);
    }
}

void Echelle::on_checkBox_16_clicked()
{
    ui->checkBox_17->setChecked(false);
}

void Echelle::on_checkBox_17_clicked()
{
    ui->checkBox_16->setChecked(false);
}

void Echelle::on_spinBox_3_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}
