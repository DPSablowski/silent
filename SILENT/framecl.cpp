#include "framecl.h"
#include "ui_framecl.h"
#include <cmath>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;
string cFPath;
QString qCFPath;

FrameCl::FrameCl(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrameCl)
{
    ui->setupUi(this);
    this->setWindowTitle("Frame Classical Spectrograph");

    ui->spinBox->setValue(2048);
    ui->spinBox_2->setValue(1024);

    ui->checkBox->setChecked(true);

    ui->comboBox->addItem("Planck Continuum");
    ui->comboBox->addItem("Neon Spectrum");
    ui->comboBox->addItem("Balmer Spectrum");

    ui->lineEdit_3->setText("/home/");

    ui->customPlot->axisRect()->setupFullAxesBox(true);
}


FrameCl::~FrameCl()
{
    delete ui;
}

void FrameCl::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    ui->customPlot->clearGraphs();
    ui->customPlot->clearPlottables();

    qCFPath = ui->lineEdit_3->text();
    cFPath = qCFPath.toUtf8().constData();

    string zeile, one, two, three;
    int llx=ui->spinBox->value(), lly=ui->spinBox_2->value();

    //Planck
    if(ui->comboBox->currentIndex()==0){

        std::ostringstream datNameStream(cFPath);
        datNameStream<<cFPath<<"/planckfcl.txt";
        std::string datName = datNameStream.str();
        ifstream input(datName.c_str());


    QFile checkfile2(datName.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "File with Continuum not available! Calculate first.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "File with Continuum is empty! Calculate first.");
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
    colorMap->data()->setSize(llx, lly); // we want the color map to have llx * lly data points
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

    //Neon
    if(ui->comboBox->currentIndex()==1){

        std::ostringstream datNameStream(cFPath);
        datNameStream<<cFPath<<"/neonfcl.txt";
        std::string datName = datNameStream.str();
        ifstream input(datName.c_str());

    QFile checkfile2(datName.c_str());

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
    colorMap->data()->setSize(llx, lly); // we want the color map to have llx * lly data points
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

    //Balmer
    if(ui->comboBox->currentIndex()==2){

        std::ostringstream datNameStream(cFPath);
        datNameStream<<cFPath<<"/balmerfcl";
        std::string datName = datNameStream.str();
        ifstream input(datName.c_str());

    QFile checkfile2(datName.c_str());

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
    colorMap->data()->setSize(llx, lly); // we want the color map to have llx * lly data points
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

void FrameCl::on_checkBox_3_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_2->setChecked(false);
}

void FrameCl::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void FrameCl::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void FrameCl::on_pushButton_3_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    QString save=ui->lineEdit->text();

    if(ui->checkBox->isChecked()){
        ui->customPlot->savePdf(qCFPath+save+".pdf");
    }

    if(ui->checkBox_2->isChecked()){
        ui->customPlot->savePng(qCFPath+save+".png");
    }
    if(ui->checkBox_3->isChecked()){
        QString output=ui->lineEdit->text();
            string data = output.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<cFPath<<data<<".txt";
            std::string datName = datNameStream.str();
            ofstream dat(datName.c_str());

            string zeile, one, two, three;

            if(ui->comboBox->currentIndex()==0){

                std::ostringstream dat2NameStream(cFPath);
                dat2NameStream<<cFPath<<"/planckfcl.txt";
                std::string dat2Name = dat2NameStream.str();
                ifstream input(dat2Name.c_str());

            QFile checkfile2(dat2Name.c_str());

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

            if(ui->comboBox->currentIndex()==1){

                std::ostringstream dat2NameStream(cFPath);
                dat2NameStream<<cFPath<<"/neonfcl.txt";
                std::string dat2Name = dat2NameStream.str();
                ifstream input(dat2Name.c_str());

            QFile checkfile2(dat2Name.c_str());

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

            if(ui->comboBox->currentIndex()==2){
                std::ostringstream dat2NameStream(cFPath);
                dat2NameStream<<cFPath<<"/balmerfcl.txt";
                std::string dat2Name = dat2NameStream.str();
                ifstream input(dat2Name.c_str());

            QFile checkfile2(dat2Name.c_str());

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

void FrameCl::on_pushButton_4_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    ui->customPlot->clearGraphs();
    ui->customPlot->clearPlottables();

    qCFPath = ui->lineEdit_3->text();
    cFPath = qCFPath.toUtf8().constData();

    string zeile, one, two, three;
    int llx=ui->spinBox->value(), lly=ui->spinBox_2->value();


    QString output=ui->lineEdit_2->text();
        string data = output.toUtf8().constData();
        std::ostringstream datNameStream(data);
        datNameStream<<cFPath<<data;
        std::string datName = datNameStream.str();
        ifstream dat(datName.c_str());

        QFile checkfile2(datName.c_str());

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

void FrameCl::on_spinBox_3_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}
