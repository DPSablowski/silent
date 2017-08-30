#include "frame3d.h"
#include "ui_frame3d.h"
#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>
#include <QMessageBox>
#include <QFile>

using namespace std;

Frame3D::Frame3D(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Frame3D)
{
    ui->setupUi(this);
    this->setWindowTitle("Frame 3D Spectrograph");

    ui->spinBox->setValue(2048);
    ui->spinBox_2->setValue(1024);

    ui->checkBox->setChecked(true);

    ui->comboBox->addItem("Planck Continuum");
    ui->comboBox->addItem("Balmer Absorption");
    ui->comboBox->addItem("Neon Emission");

    ui->customPlot->axisRect()->setupFullAxesBox(true);
}

Frame3D::~Frame3D()
{
    delete ui;
}

void Frame3D::seData(QString str)
{
    ui->lineEdit_3->setText(str);
}

void Frame3D::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    ui->customPlot->clearGraphs();
    ui->customPlot->clearPlottables();

    string zeile, one, two, three;
    int llx=ui->spinBox->value(), lly=ui->spinBox_2->value();

    if(ui->comboBox->currentIndex()==0){
    ifstream input("planck3d.txt");
    QFile checkfile2("planck3d.txt");

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "File with continuum not available! Calculate first.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "File with continuum is empty! Calculate first.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }


    int number_of_lines =0;

    while(std::getline(input, zeile))
       ++ number_of_lines;

    input.clear();
    input.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines), c(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
        input >> one >>two>>three;
    istringstream ist(one);
    ist >> a[i];

    istringstream ist2(two);
    ist2 >> b[i];
    istringstream ist3(three);
    ist3 >> c[i];
    }
    input.close();

    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    // set up the QCPColorMap:
    QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(colorMap);
    colorMap->data()->setSize(llx, lly); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(0, llx), QCPRange(0, lly));

    for(int i=0; i<llx; i++){
        for(int e=0; e<lly; e++){
    colorMap->data()->setCell(i, e, c[i*lly+e]);
        }
    }
    // add a color scale:
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorMap->setColorScale(colorScale); // associate the color map with the color scale
    colorScale->axis()->setLabel("rel. Intensity");

    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange();
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();

    }

    if(ui->comboBox->currentIndex()==1){
    ifstream input("balmer3d.txt");
    QFile checkfile2("balmer3d.txt");

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "File with Balmer absorption not available! Calculate first.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "File with Balmer absorption is empty! Calculate first.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    int number_of_lines =0;

    while(std::getline(input, zeile))
       ++ number_of_lines;

    input.clear();
    input.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines), c(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
        input >> one >>two>>three;
    istringstream ist(one);
    ist >> a[i];

    istringstream ist2(two);
    ist2 >> b[i];
    istringstream ist3(three);
    ist3 >> c[i];
    }
    input.close();

    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    // set up the QCPColorMap:
    QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(colorMap);
    colorMap->data()->setSize(llx, lly); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(0, llx), QCPRange(0, lly));

    for(int i=0; i<llx; i++){
        for(int e=0; e<lly; e++){
    colorMap->data()->setCell(i, e, c[i*lly+e]);
        }
    }
    // add a color scale:
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorMap->setColorScale(colorScale); // associate the color map with the color scale
    colorScale->axis()->setLabel("rel. Intensity");

    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange();
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();

    }

    if(ui->comboBox->currentIndex()==2){
    ifstream input("neon3d.txt");
    QFile checkfile2("neon3d.txt");

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "File with Neon emission not available! Calculate first.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "File with Neon emission is empty! Calculate first.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    int number_of_lines =0;

    while(std::getline(input, zeile))
       ++ number_of_lines;

    input.clear();
    input.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines), c(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
        input >> one >>two>>three;
    istringstream ist(one);
    ist >> a[i];

    istringstream ist2(two);
    ist2 >> b[i];
    istringstream ist3(three);
    ist3 >> c[i];
    }
    input.close();

    ui->customPlot->addGraph();
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    // set up the QCPColorMap:
    QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
    ui->customPlot->addPlottable(colorMap);
    colorMap->data()->setSize(llx, lly); // we want the color map to have nx * ny data points
    colorMap->data()->setRange(QCPRange(0, llx), QCPRange(0, lly));

    for(int i=0; i<llx; i++){
        for(int e=0; e<lly; e++){
    colorMap->data()->setCell(i, e, c[i*lly+e]);
        }
    }
    // add a color scale:
    QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    colorMap->setColorScale(colorScale); // associate the color map with the color scale
    colorScale->axis()->setLabel("rel. Intensity");

    colorMap->setGradient(QCPColorGradient::gpPolar);
    colorMap->rescaleDataRange();
    QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();

    }

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void Frame3D::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void Frame3D::on_checkBox_2_clicked()
{
     ui->checkBox->setChecked(false);
     ui->checkBox_3->setChecked(false);
}

void Frame3D::on_checkBox_3_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
}

void Frame3D::on_pushButton_3_clicked()
{

    this->setCursor(QCursor(Qt::WaitCursor));

    QString save=ui->lineEdit->text();
    if(ui->checkBox->isChecked()){
    ui->customPlot->savePdf(save +".pdf");
    }

    if(ui->checkBox_2->isChecked()){
    ui->customPlot->savePng(save+"png");
    }

if(ui->checkBox_3->isChecked()){
    QString output=ui->lineEdit->text();
        string data = output.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<data<<".txt";
        std::string datName = datNameStream.str();
        ofstream dat(datName.c_str());

        string zeile, one, two, three;

        if(ui->comboBox->currentIndex()==0){
        ifstream input("planckf3d.txt");
        QFile checkfile2("planckf3d.txt");

        if(!checkfile2.exists()){
            QMessageBox::information(this, "Error", "Continuum file does not exist.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        if(checkfile2.size()==0){
            QMessageBox::information(this, "Error", "Continuum file is empty.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        int number_of_lines =0;

        while(std::getline(input, zeile))
           ++ number_of_lines;

        input.clear();
        input.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines), c(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            input >> one >>two>>three;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        istringstream ist3(three);
        ist3 >> c[i];
        dat<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
        }
        input.close();
        }
        if(ui->comboBox->currentIndex()==2){
        ifstream input("neonf3d.txt");

        QFile checkfile2("neonf3d.txt");

        if(!checkfile2.exists()){
            QMessageBox::information(this, "Error", "Neon file does not exist.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        if(checkfile2.size()==0){
            QMessageBox::information(this, "Error", "Neon file is empty.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        int number_of_lines =0;

        while(std::getline(input, zeile))
           ++ number_of_lines;

        input.clear();
        input.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines), c(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            input >> one >>two>>three;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        istringstream ist3(three);
        ist3 >> c[i];
        dat<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
        }
        input.close();
        }

        if(ui->comboBox->currentIndex()==1){
        ifstream input("balmerf3d.txt");
        QFile checkfile2("balmerf3d.txt");

        if(!checkfile2.exists()){
            QMessageBox::information(this, "Error", "Balmer file does not exist.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        if(checkfile2.size()==0){
            QMessageBox::information(this, "Error", "Balmer file is empty.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        int number_of_lines =0;

        while(std::getline(input, zeile))
           ++ number_of_lines;

        input.clear();
        input.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines), c(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
            input >> one >>two>>three;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        istringstream ist3(three);
        ist3 >> c[i];
        dat<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
        }
        input.close();
        }
}
 this->setCursor(QCursor(Qt::ArrowCursor));

}


void Frame3D::on_pushButton_4_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    ui->customPlot->clearGraphs();
    ui->customPlot->clearPlottables();

    string zeile, one, two, three;
    int llx=ui->spinBox->value(), lly=ui->spinBox_2->value();


    QString output=ui->lineEdit_2->text();
        string data = output.toUtf8().constData();
        std::ostringstream datNameStream(data);
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile2(output);

        if(!checkfile2.exists()){
            QMessageBox::information(this, "Error", "File does not exist.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }
        if(checkfile2.size()==0){
            QMessageBox::information(this, "Error", "File is empty.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        int number_of_lines =0;

        while(std::getline(dat, zeile))
           ++ number_of_lines;

        dat.clear();
        dat.seekg(0, ios::beg);

        QVector<double> a(number_of_lines), b(number_of_lines), c(number_of_lines);

        for (int i=0; i<number_of_lines; i++){
        dat >> one >>two>>three;
        istringstream ist(one);
        ist >> a[i];
        istringstream ist2(two);
        ist2 >> b[i];
        istringstream ist3(three);
        ist3 >> c[i];
        }
        dat.close();

        ui->customPlot->addGraph();
        ui->customPlot->xAxis->setLabel("x");
        ui->customPlot->yAxis->setLabel("y");

        // set up the QCPColorMap:
        QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
        ui->customPlot->addPlottable(colorMap);
        colorMap->data()->setSize(llx, lly); // we want the color map to have nx * ny data points
        colorMap->data()->setRange(QCPRange(0, llx), QCPRange(0, lly));

        for(int i=0; i<llx; i++){
            for(int e=0; e<lly; e++){
        colorMap->data()->setCell(i, e, c[i*lly+e]);
            }
        }
        // add a color scale:
        QCPColorScale *colorScale = new QCPColorScale(ui->customPlot);
        ui->customPlot->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect
        colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
        colorMap->setColorScale(colorScale); // associate the color map with the color scale
        colorScale->axis()->setLabel("rel. Intensity");

        colorMap->setGradient(QCPColorGradient::gpPolar);
        colorMap->rescaleDataRange();
        QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
        ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
        ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
        colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
        ui->customPlot->rescaleAxes();
        ui->customPlot->replot();

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void Frame3D::on_spinBox_3_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}
