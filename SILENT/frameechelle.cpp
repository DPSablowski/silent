#include "frameechelle.h"
#include "ui_frameechelle.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <qapplication.h>

using namespace std;

FrameEchelle::FrameEchelle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FrameEchelle)
{
    ui->setupUi(this);
    this->setWindowTitle("Frame Echelle Spectrograph");

    ui->spinBox->setValue(1500);
    ui->spinBox_2->setValue(1024);

    ui->checkBox->setChecked(true);

    ui->comboBox->addItem("Planck Continuum");
    ui->comboBox->addItem("Neon Emission");
    ui->comboBox->addItem("Balmer Absorption");
    ui->comboBox->addItem("Th/Ar Emission");

    ui->customPlot->axisRect()->setupFullAxesBox(true);
}

FrameEchelle::~FrameEchelle()
{
    delete ui;
}

void FrameEchelle::seData(QString str, int pix, int piy)
{
    ui->lineEdit_3->setText(str);
    ui->spinBox->setValue(pix);
    ui->spinBox_2->setValue(piy);
}

void FrameEchelle::on_pushButton_2_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    QString qPath = ui->lineEdit_3->text();
    string path = qPath.toUtf8().constData();

    string zeile, one, two, three;
    int llx=ui->spinBox->value(), lly=ui->spinBox_2->value();

    if(ui->comboBox->currentIndex()==0){

        std::ostringstream dat2NameStream(path);
        dat2NameStream<<path<<"/planckech.txt";
        std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Continuum file "+checkfile2.fileName()+" does not exist.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "Continuum "+checkfile2.fileName()+" file is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream input(dat2Name.c_str());

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

        std::ostringstream dat2NameStream(path);
        dat2NameStream<<path<<"/neonech.txt";
        std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());


    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Neon emission frame "+checkfile2.fileName()+" does not exist.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "Neon emission frame "+checkfile2.fileName()+" is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream input(dat2Name.c_str());

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
        std::ostringstream dat2NameStream(path);
        dat2NameStream<<path<<"/balmerech.txt";
        std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Balmer frame "+checkfile2.fileName()+" does not exist.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "Balmer frame "+checkfile2.fileName()+" is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
        ifstream input(dat2Name.c_str());

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
    if(ui->comboBox->currentIndex()==3){

        std::ostringstream dat2NameStream(path);
        dat2NameStream<<path<<"/tharech.txt";
        std::string dat2Name = dat2NameStream.str();

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Th/Ar frame "+checkfile2.fileName()+" does not exist.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    if(checkfile2.size()==0){
        QMessageBox::information(this, "Error", "Th/Ar frame "+checkfile2.fileName()+" is empty.");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }
    ifstream input(dat2Name.c_str());

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

void FrameEchelle::on_checkBox_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void FrameEchelle::on_checkBox_2_clicked()
{
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void FrameEchelle::on_pushButton_3_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));

    QString qPath = ui->lineEdit_3->text();
    string path = qPath.toUtf8().constData();

    if(ui->checkBox->isChecked()){
        QString save=qPath+"/"+ui->lineEdit->text()+".pdf";
        ui->customPlot->savePdf(save);
    }

    if(ui->checkBox_2->isChecked()){
        QString save=qPath+"/"+ui->lineEdit->text()+".png";
        ui->customPlot->savePng(save);
    }
    if(ui->checkBox_3->isChecked()){
        QString output=ui->lineEdit->text();
            string data = output.toUtf8().constData();
            std::ostringstream datNameStream(data);
            datNameStream<<path<<"/"<<data<<".txt";
            std::string datName = datNameStream.str();
            ofstream dat(datName.c_str());

            string zeile, one, two, three;

            if(ui->comboBox->currentIndex()==0){
                std::ostringstream dat2NameStream(path);
                dat2NameStream<<path<<"/planckech.txt";
                std::string dat2Name = dat2NameStream.str();

            QFile checkfile2(dat2Name.c_str());


            if(!checkfile2.exists()){
                QMessageBox::information(this, "Error", "Planck frame does not exist.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            if(checkfile2.size()==0){
                QMessageBox::information(this, "Error", "Planck frame is empty.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream input(dat2Name.c_str());

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
                std::ostringstream dat2NameStream(path);
                dat2NameStream<<path<<"/neonech.txt";
                std::string dat2Name = dat2NameStream.str();

            QFile checkfile2(dat2Name.c_str());

            if(!checkfile2.exists()){
                QMessageBox::information(this, "Error", "Neon frame does not exist.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            if(checkfile2.size()==0){
                QMessageBox::information(this, "Error", "Neon frame is empty.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream input(dat2Name.c_str());

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
                std::ostringstream dat2NameStream(path);
                dat2NameStream<<path<<"/balmerech.txt";
                std::string dat2Name = dat2NameStream.str();

            QFile checkfile2(dat2Name.c_str());

            if(!checkfile2.exists()){
                QMessageBox::information(this, "Error", "Balmer frame does not exist.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            if(checkfile2.size()==0){
                QMessageBox::information(this, "Error", "Balmer frame is empty.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream input(dat2Name.c_str());

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
            if(ui->comboBox->currentIndex()==3){
                std::ostringstream dat2NameStream(path);
                dat2NameStream<<path<<"/tharech.txt";
                std::string dat2Name = dat2NameStream.str();

            QFile checkfile2(dat2Name.c_str());

            if(!checkfile2.exists()){
                QMessageBox::information(this, "Error", "Th/Ar frame does not exist.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            if(checkfile2.size()==0){
                QMessageBox::information(this, "Error", "Th/Ar frame is empty.");
                this->setCursor(QCursor(Qt::ArrowCursor));
               return;
            }
            ifstream input(dat2Name.c_str());

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

void FrameEchelle::on_checkBox_3_clicked()
{
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
}

void FrameEchelle::on_pushButton_4_clicked()
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

void FrameEchelle::on_spinBox_3_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}
