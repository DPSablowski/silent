#include "petzval.h"
#include "ui_petzval.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include <QFile>
#include <QMessageBox>


using namespace std;
QVector<double> radius1(1), radius2(1), radius3(1), focal(1), diameter(1), thick1(1), thick2(1), SB1(1), SB2(1), SB3(1), SC1(1), SC2(1), SC3(1), d2N(1), d2V(1), havex(1), havey(1), lambda(1);
QVector<string> supplier(1), product(1), Glass1(1), Glass2(1), SGlass(1), dGlass(1);
int llines=0, nwaves=5, nfields=1, nrays=1;

Petzval::Petzval(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Petzval)
{
    ui->setupUi(this);
    this->setWindowTitle("Petzval Tool");

    ui->lineEdit->setText("LensData.slib");
    ui->lineEdit_4->setText("GlassData.slib");
    ui->lineEdit_5->setText("combinations");
    ui->lineEdit_6->setText("evaluated");

    ui->checkBox_3->setChecked(true);

    ui->doubleSpinBox->setValue(20.0);
    ui->doubleSpinBox_2->setValue(130.0);
    ui->doubleSpinBox_3->setValue(10.0);
    ui->doubleSpinBox_4->setValue(40.0);
    ui->doubleSpinBox_5->setValue(26.0);
    ui->doubleSpinBox_6->setValue(26.0);
    ui->doubleSpinBox_9->setValue(10.0);
    ui->doubleSpinBox_10->setValue(10.0);

    ui->checkBox->setChecked(true);

    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->xAxis2->setLabel("Spot Field 1");
    ui->customPlot->yAxis->setLabel("y");
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot_2->axisRect()->setupFullAxesBox(true);
    ui->customPlot_3->axisRect()->setupFullAxesBox(true);
    ui->customPlot_4->axisRect()->setupFullAxesBox(true);
    ui->customPlot_4->xAxis2->setLabel("Spot Field 3");
    ui->customPlot_4->yAxis->setLabel("y");
    ui->customPlot_4->xAxis->setLabel("x");
    ui->customPlot_5->axisRect()->setupFullAxesBox(true);
    ui->customPlot_5->xAxis2->setLabel("Spot Field 2");
    ui->customPlot_5->yAxis->setLabel("y");
    ui->customPlot_5->xAxis->setLabel("x");
    ui->customPlot_6->axisRect()->setupFullAxesBox(true);
    ui->customPlot_6->xAxis2->setLabel("Spot Field 4");
    ui->customPlot_6->yAxis->setLabel("y");
    ui->customPlot_6->xAxis->setLabel("x");
    ui->customPlot_7->axisRect()->setupFullAxesBox(true);

    ui->customPlot_3->yAxis->setLabel("y");
    ui->customPlot_3->xAxis->setLabel("z");
    ui->customPlot_3->xAxis2->setLabel("Layout 2D");
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->customPlot_4->legend->setVisible(true);
    ui->customPlot_4->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->customPlot_5->legend->setVisible(true);
    ui->customPlot_5->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->customPlot_6->legend->setVisible(true);
    ui->customPlot_6->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->customPlot_2->legend->setVisible(true);
    ui->customPlot_2->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->customPlot_2->xAxis2->setLabel("Field 1");
    ui->customPlot_2->yAxis->setLabel("Transmission");
    ui->customPlot_2->xAxis->setLabel("Wavelength");
    ui->customPlot_7->legend->setVisible(true);
    ui->customPlot_7->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignBottom|Qt::AlignRight);
    ui->customPlot_7->xAxis2->setLabel("Field 2");
    ui->customPlot_7->yAxis->setLabel("Transmission");
    ui->customPlot_7->xAxis->setLabel("Wavelength");

    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"Wavel."<<"Color");
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setRowCount(nwaves);

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("0.4"));
    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("0.5"));
    ui->tableWidget->setItem(2, 0, new QTableWidgetItem("0.6"));
    ui->tableWidget->setItem(3, 0, new QTableWidgetItem("0.7"));
    ui->tableWidget->setItem(4, 0, new QTableWidgetItem("0.8"));
    for(int i =0; i<5; i++){
        QComboBox *combo = new QComboBox();
        ui->tableWidget->setCellWidget(i, 1, combo);
        combo->addItem("Dark Blue");
        combo->addItem("Blue");
        combo->addItem("Dark Green");
        combo->addItem("Green");
        combo->addItem("Dark Yellow");
        combo->addItem("Yellow");
        combo->addItem("Dark Red");
        combo->addItem("Red");
        combo->addItem("Dark Magenta");
        combo->addItem("Magenta");
        combo->addItem("Dark Cyan");
        combo->addItem("Cyan");
        combo->addItem("black");
        combo->setCurrentIndex(2*i+1);
    }

    ui->tableWidget_2->setRowCount(nfields);
    ui->tableWidget_2->setHorizontalHeaderLabels(QStringList()<<"x"<<"y");
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->setItem(0, 0, new QTableWidgetItem("0.0"));
    ui->tableWidget_2->setItem(0, 1, new QTableWidgetItem("0.0"));

}

Petzval::~Petzval()
{
    delete ui;
}

void Petzval::seData(QString str)
{
    ui->lineEdit_2->setText(str);
}

//*****************************
// load lens data
//*****************************
void Petzval::loadDatabase(){

    QString qLib = ui->lineEdit_2->text()+"/"+ui->lineEdit->text();
    string sbin = qLib.toUtf8().constData();
    ifstream lenses(sbin.c_str());

    QFile qBin(qLib);

    if(!qBin.exists()){
        QMessageBox::information(this, "Error", "Lens database "+qLib+" not present.");
        return;
    }

    else{
        llines=0;
        string zeile1, eins, zwei, drei, vier, fuenf, sechs, sieben, acht, neun, zehn, elf;

        while(std::getline(lenses, zeile1))
        ++ llines;

        lenses.clear();
        lenses.seekg(0, ios::beg);

        radius1.resize(llines);
        radius2.resize(llines);
        radius3.resize(llines);
        focal.resize(llines);
        diameter.resize(llines);
        thick1.resize(llines);
        thick2.resize(llines);
        supplier.resize(llines);
        product.resize(llines);
        Glass1.resize(llines);
        Glass2.resize(llines);

        for(int i=0; i < llines; i++){
            lenses >> eins >> zwei >> drei >> vier >> fuenf >> sechs >> sieben >> acht >> neun >> zehn >> elf;
            istringstream str1(eins);
            str1 >> supplier[i];
            istringstream str2(zwei);
            str2 >> product[i];
            istringstream str3(drei);
            str3 >> diameter[i];
            istringstream str4(vier);
            str4 >> focal[i];
            istringstream str5(fuenf);
            str5 >> radius1[i];
            istringstream str6(sechs);
            str6 >> radius2[i];
            istringstream str7(sieben);
            str7 >> radius3[i];
            istringstream str8(acht);
            str8 >> thick1[i];
            istringstream str9(neun);
            str9 >> thick2[i];
            istringstream str10(zehn);
            str10 >> Glass1[i];
            istringstream str11(elf);
            str11 >> Glass2[i];
        }


    }
}

//*****************************
// load catalog
//*****************************
void Petzval::on_pushButton_3_clicked()
{
    Petzval::loadDatabase();
}

//*****************************
// search combinations
//*****************************
void Petzval::on_pushButton_clicked()
{
    Petzval::loadDatabase();

    QString qLib = ui->lineEdit_2->text()+"/"+ui->lineEdit_5->text()+".pet";
    string sbin = qLib.toUtf8().constData();
    ofstream evals(sbin.c_str());

    ui->comboBox->clear();
    double diam = ui->doubleSpinBox->value();
    double foc = ui->doubleSpinBox_2->value();
    double focup = foc + ui->doubleSpinBox_3->value();
    double foclo = foc - ui->doubleSpinBox_3->value();
    double back = ui->doubleSpinBox_4->value();
    double d2max = ui->doubleSpinBox_5->value();
    double d1min = ui->doubleSpinBox_9->value();
    double d1max = ui->doubleSpinBox_6->value();
    double d2min = ui->doubleSpinBox_9->value();

    if(d1max < diam){
        QString Qdi = QString::number(diam);
        QString Qdi1 = QString::number(d1max);
        QMessageBox::information(this, "Warning", "Specified diameter of "+Qdi+" larger than allowed maximum "+Qdi1);
    }
    double tup, tlo, dup, dlo, F1, F2, H2up, H2lo, H1up, H1lo, backup;
    int cnum=0;

    for(int i =0; i<llines; i++){
        if((diameter[i]>= diam) & (diameter[i]<=d1max) & (diameter[i]>=d1min)){
            F1 = focal[i]/diam;
            for(int e =0; e<llines; e++){
                tup = focal[i]+focal[e]-focal[i]*focal[e]/focup;
                tlo = focal[i]+focal[e]-focal[i]*focal[e]/foclo;
                backup = (foclo-tlo)/(1-tlo/focal[e]);
                if((tup<focal[i]) & (backup>=back) & (diameter[e]<d2max) & (diameter[e]>=d2min)){
                    dup = (focal[i]-tup)/F1;
                    dlo = (focal[i]-tlo)/F1;
                    H2up = -dup*focal[e]/(focal[i]+focal[e]-dup);
                    H2lo = -dlo*focal[e]/(focal[i]+focal[e]-dlo);
                    H1up = dup*focal[i]/(focal[i]+focal[e]-dup);
                    H1lo = dlo*focal[i]/(focal[i]+focal[e]-dlo);
                    if((dlo<=diameter[e]) & (tlo<focal[i])){
                        cout<<product[i]<<"\t\t"<<product[e]<<"\t"<<tup<<"\t"<<tlo<<"\t"<<dup<<"\t"<<dlo<<"\t"<<H1up<<"\t"<<H1lo<<"\t"<<H2up<<"\t"<<H2lo<<"\t"<<backup<<endl;
                        //string pro1 = product[i];
                        //string pro2 = product[e];
                        evals<<i<<"\t"<<e<<"\t"<<tlo<<"\t"<<backup<<endl;
                        //QString qstr = QString::fromStdString(pro1.c_str())+" & "+QString::fromStdString(pro2.c_str());
                        //ui->comboBox->addItem(qstr);
                        ++cnum;
                    }
                    else{

                    }
                }
                else{

                }
            }
        }
        else{

        }
    }
    ui->lineEdit_3->setText(QString::number(cnum));
    ui->spinBox_8->setMaximum(cnum);

}

//*****************************
// Evaluate found combinations
//*****************************
void Petzval::on_pushButton_4_clicked()
{
    QString qSpot = ui->lineEdit_2->text()+"/spot.pet";
    string sspot = qSpot.toUtf8().constData();
    ofstream spot(sspot.c_str());

    int symbol=ui->spinBox_2->value();

    QVector<QPen> qColors(13);

    QPen pen0;
    pen0.setWidth(symbol);
    pen0.setColor(Qt::darkBlue);
    qColors[0]=pen0;
    QPen pen1;
    pen1.setWidth(symbol);
    pen1.setColor(Qt::blue);
    qColors[1]=pen1;
    QPen pen2;
    pen2.setWidth(symbol);
    pen2.setColor(Qt::darkGreen);
    qColors[2]=pen2;
    QPen pen3;
    pen3.setWidth(symbol);
    pen3.setColor(Qt::green);
    qColors[3]=pen3;
    QPen pen4;
    pen4.setWidth(symbol);
    pen4.setColor(Qt::darkYellow);
    qColors[4]=pen4;
    QPen pen5;
    pen5.setWidth(symbol);
    pen5.setColor(Qt::yellow);
    qColors[5]=pen5;
    QPen pen6;
    pen6.setWidth(symbol);
    pen6.setColor(Qt::darkRed);
    qColors[6]=pen6;
    QPen pen7;
    pen7.setWidth(symbol);
    pen7.setColor(Qt::red);
    qColors[7]=pen7;
    QPen pen8;
    pen8.setWidth(symbol);
    pen8.setColor(Qt::darkMagenta);
    qColors[8]=pen8;
    QPen pen9;
    pen9.setWidth(symbol);
    pen9.setColor(Qt::magenta);
    qColors[9]=pen9;
    QPen pen10;
    pen10.setWidth(symbol);
    pen10.setColor(Qt::darkCyan);
    qColors[10]=pen10;
    QPen pen11;
    pen11.setWidth(symbol);
    pen11.setColor(Qt::cyan);
    qColors[11]=pen11;
    QPen pen12;
    pen12.setWidth(symbol);
    pen12.setColor(Qt::black);
    qColors[12]=pen12;

    QVector<int> nColor(13);

    for(int i=0; i<ui->spinBox_5->value(); i++){
        QComboBox* combo = (QComboBox*)ui->tableWidget->cellWidget(i, 1);
        nColor[i]=combo->currentIndex();
    }

    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());

    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot_2->legend->setFont(legendFont);
    ui->customPlot_4->legend->setFont(legendFont);
    ui->customPlot_5->legend->setFont(legendFont);
    ui->customPlot_6->legend->setFont(legendFont);

    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
    ui->customPlot_2->xAxis->setLabelFont(legendFont);
    ui->customPlot_2->yAxis->setLabelFont(legendFont);
    ui->customPlot_2->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_2->yAxis->setTickLabelFont(legendFont);
    ui->customPlot_3->xAxis->setLabelFont(legendFont);
    ui->customPlot_3->yAxis->setLabelFont(legendFont);
    ui->customPlot_3->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_3->yAxis->setTickLabelFont(legendFont);
    ui->customPlot_4->xAxis->setLabelFont(legendFont);
    ui->customPlot_4->yAxis->setLabelFont(legendFont);
    ui->customPlot_4->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_4->yAxis->setTickLabelFont(legendFont);
    ui->customPlot_5->xAxis->setLabelFont(legendFont);
    ui->customPlot_5->yAxis->setLabelFont(legendFont);
    ui->customPlot_5->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_5->yAxis->setTickLabelFont(legendFont);
    ui->customPlot_6->xAxis->setLabelFont(legendFont);
    ui->customPlot_6->yAxis->setLabelFont(legendFont);
    ui->customPlot_6->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_6->yAxis->setTickLabelFont(legendFont);
    ui->customPlot_7->xAxis->setLabelFont(legendFont);
    ui->customPlot_7->yAxis->setLabelFont(legendFont);
    ui->customPlot_7->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_7->yAxis->setTickLabelFont(legendFont);


    QString qLib, qEval;
    if(ui->checkBox_4->isChecked()){
        qLib= ui->lineEdit_2->text()+"/"+ui->lineEdit_5->text()+".pet";
        qEval= ui->lineEdit_2->text()+"/"+ui->lineEdit_6->text()+".pet";
    }
    else{
        qLib= ui->lineEdit_2->text()+"/"+ui->lineEdit_6->text()+".pet";
    }

    QFileInfo qeval(qLib);
    if(!qeval.exists()){
        QMessageBox::information(this, "Error", "Error: No file with evaluated combinations found.");
        return;
    }
    string sbin = qLib.toUtf8().constData();
    string sEval = qEval.toUtf8().constData();
    ofstream oEval;
    ifstream evals(sbin.c_str());

    int nsystems=0;
    string zeile, eins, zwei, drei, vier;

    while(std::getline(evals, zeile))
    ++ nsystems;

    evals.clear();
    evals.seekg(0, ios::beg);

    Petzval::on_pushButton_5_clicked();
    Petzval::loadDatabase();

    QVector<int> first(nsystems), second(nsystems), gl1(nsystems), gl2(nsystems), gl3(nsystems), gl4(nsystems);
    QVector<double> nthi(nsystems), bthi(nsystems), rms(nsystems), oback(nsystems);
    int checker=0;
    nrays=ui->spinBox_4->value();

    for(int i =0; i<nsystems; i++){
        evals>>eins>>zwei>>drei>>vier;
        istringstream str1(eins);
        str1 >> first[i];
        istringstream str2(zwei);
        str2 >> second[i];
        istringstream str3(drei);
        str3 >> nthi[i];
        for(int r=0; r<SB1.size(); r++){
            if(Glass1[first[i]]==SGlass[r]){
                gl1[i]=r;
                checker=1;
            }
            else{
                if(Glass2[first[i]]==SGlass[r]){
                    gl2[i]=r;
                    checker=1;
                }
                else{
                    //
                }
            }

            if(Glass1[second[i]]==SGlass[r]){
                gl3[i]=r;
                checker=1;
            }
            else{
                if(Glass2[second[i]]==SGlass[r]){
                    gl4[i]=r;
                    checker=1;
                }
                else{
                    //
                }
            }
        }
            if(checker==0){
                QMessageBox::information(this, "Error", "Error: Glass of combination "+QString::number(i)+" not found.");
                return;
            }
            checker=0;

        istringstream str4(vier);
        str4 >> bthi[i];
    }
    evals.close();

    int lensd=20;
    double th=0, Frenp, Frens, llp=0.0;
    QVector<double> radi(7), thi(7), ind(7), diam(6), lxk(7), rayy(7), rayx(7), trans(nwaves), transp(nwaves), transs(nwaves), lensx(lensd), lensy(lensd);

    ind[0]=1.0;
    ind[3]=1.0;
    ind[6]=1.0;

    double mx=0.0, my=0.0, h1=ui->doubleSpinBox->value()/2, h1y, h1x, alpha1=0, alpha2, alpha1y, alpha2y, ax, bx, cx, dap, ay, by, cy, h2x=0.0, h2y=0.0;
    double hx, hy, x1=0.0, y1=0.0, x2=0, y2=0.0, Tr=1.0, Trs=1.0, Trp=1.0;

    lambda.resize(nwaves);

    QTableWidgetItem *item;

    for(int i=0; i<nwaves; i++){
        item = ui->tableWidget->item(i, 0);
        if (!item || item->text().isEmpty())
        {
           QMessageBox::information(this, "Error", "Error: No wavelength defined at "+QString::number(i+1)+".");
           return;
        }
        else{
            lambda[i]=item->text().toDouble();
        }
    }

    int gray=0;

    if(ui->checkBox_4->isChecked()){
        nfields=1;
    }
    else{
        nfields = ui->spinBox_7->value();
    }
        QVector<double> fieldx(nfields), fieldy(nfields), mxv(nwaves*nrays), hxv(nwaves*nrays);

        havex.resize(nfields);
        havey.resize(nfields);

        for(int i =0; i<nfields; i++){
            item = ui->tableWidget_2->item(i,0);
            if (!item || item->text().isEmpty())
            {
               QMessageBox::information(this, "Error", "Error: No Field defined at "+QString::number(i+1)+".");
               return;
            }
            else{
                fieldx[i]=item->text().toDouble();
            }
            item = ui->tableWidget_2->item(i,1);
            if (!item || item->text().isEmpty())
            {
               QMessageBox::information(this, "Error", "Error: No Field defined at "+QString::number(i+1)+".");
               return;
            }
            else{
                fieldy[i]=item->text().toDouble();
            }
        }
        int nstar=0, nend=1, nmin=0;
        if(ui->checkBox_4->isChecked()){
            nstar=0;
            nend=radius1.size();
        }
        else{
            nstar=ui->spinBox_8->value();
            nend=ui->spinBox_8->value()+1;
        }


    for(int gg=nstar; gg<nend; gg++){
        nmin=0;
        ui->customPlot->clearGraphs();
        ui->customPlot_2->clearGraphs();
        ui->customPlot_3->clearGraphs();
        ui->customPlot_4->clearGraphs();
        ui->customPlot_5->clearGraphs();
        ui->customPlot_6->clearGraphs();
        ui->customPlot_7->clearGraphs();
        gray=0;

        radi[0]=radius1[first[gg]];
        radi[1]=radius2[first[gg]];
        radi[2]=radius3[first[gg]];
        radi[3]=radius1[second[gg]];
        radi[4]=radius2[second[gg]];
        radi[5]=radius3[second[gg]];
        radi[6]=10e10;
        diam[0]=diameter[first[gg]];
        diam[1]=diameter[first[gg]];
        diam[2]=diameter[first[gg]];
        diam[3]=diameter[second[gg]];
        diam[4]=diameter[second[gg]];
        diam[5]=diameter[second[gg]];

        thi[0]=0;
        thi[1]=thick1[first[gg]];
        thi[2]=thick2[first[gg]];;
        thi[3]=nthi[gg];
        thi[4]=thick1[second[gg]];
        thi[5]=thick2[second[gg]];
        llp=thi[1]+thi[2]+thi[3]+thi[4]+thi[5];
        thi[6]=bthi[gg];

        for(int ra=0; ra<6; ra++){
            th = th+thi[ra];
            lxk[ra] = radi[ra]+th;
            lensd = diam[ra]*2;
            lensy.resize(lensd);
            lensx.resize(lensd);

            for(int fl=0; fl<lensd; fl++){
                lensy[fl]=diam[ra]/2-diam[ra]/lensd*fl;
                if(radi[ra]>0){
                    lensx[fl]=-sqrt(pow(radi[ra],2)-pow(lensy[fl],2))+lxk[ra];
                }
                else   {
                    lensx[fl]=sqrt(pow(radi[ra],2)-pow(lensy[fl],2))+lxk[ra];
                }
            }
            ui->customPlot_3->addGraph();
            ui->customPlot_3->graph(gray)->addData(lensx, lensy);
            ui->customPlot_3->graph(gray)->setPen(pen12);
            ui->customPlot_3->graph(gray)->setLineStyle(QCPGraph::lsNone);
            ui->customPlot_3->graph(gray)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
            if(ra==0){
                ui->customPlot_3->rescaleAxes();
            }
            else{
                ui->customPlot_3->rescaleAxes(true);
            }
            ui->customPlot_3->replot();
            ++gray;
        }
        th=0;

        for(int fi=0; fi<nfields; fi++){
            havex[fi]=0;
            havey[fi]=0;

            for(int e =0; e<lambda.size(); e++){ // loop for wavelengths

                ind[1]=sqrt(1+SB1[gl1[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC1[gl1[gg]])+SB2[gl1[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC2[gl1[gg]])+SB3[gl1[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC3[gl1[gg]]));
                ind[2]=sqrt(1+SB1[gl2[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC1[gl2[gg]])+SB2[gl2[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC2[gl2[gg]])+SB3[gl2[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC3[gl2[gg]]));
                ind[4]=sqrt(1+SB1[gl3[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC1[gl3[gg]])+SB2[gl3[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC2[gl3[gg]])+SB3[gl3[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC3[gl3[gg]]));
                ind[5]=sqrt(1+SB1[gl4[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC1[gl4[gg]])+SB2[gl4[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC2[gl4[gg]])+SB3[gl4[gg]]*pow(lambda[e],2)/(pow(lambda[e],2)-SC3[gl4[gg]]));

                //cout<<"n(1): "<<ind[1]<<"; n(2): "<<ind[2]<<"; n(4): "<<ind[4]<<"; n(5): "<<ind[5]<<endl;

                for(int u=0; u<nrays; u++){ // loop for radial distributed rays
                    dap=u;
                    h1x=h1*cos(dap/nrays*M_PI);
                    h1y=h1*sin(dap/nrays*M_PI);
                    trans[e] =0.0;
                    transp[e]=0.0;
                    transs[e]=0.0;

                    for(int g=0; g<nrays; g++){ // loop for number of rays distributed transverse
                        hx=h1x-g*h1x/(nrays-1)*2;
                        hy=h1y-g*h1y/(nrays-1)*2;
                        mx = tan(fieldx[fi]/180*M_PI);
                        my = tan(fieldy[fi]/180*M_PI);
                        Tr=1.0;
                        Trs=1.0;
                        Trp=1.0;

                        for(int i =0; i<radi.size(); i++){

                            // calculate lxk, the position of radius intersection with x-axi
                            th = th+thi[i];
                            lxk[i] = radi[i]+th;

                            ax = pow(mx,2)+1;
                            bx = 2*hx*mx-2*lxk[i];
                            cx = pow(hx,2)+pow(lxk[i],2)-pow(radi[i],2);

                            x1=(-bx+pow((bx*bx-4*ax*cx),0.5))/(2*ax);
                            x2=(-bx-pow((bx*bx-4*ax*cx),0.5))/(2*ax);

                            ay = pow(my,2)+1;
                            by = 2*hy*my-2*lxk[i];
                            cy = pow(hy,2)+pow(lxk[i],2)-pow(radi[i],2);

                            y1=(-by+pow((by*by-4*ay*cy),0.5))/(2*ay);
                            y2=(-by-pow((by*by-4*ay*cy),0.5))/(2*ay);

                            if(radi[i]>0){
                                if(x1<x2){
                                    h2x=mx*x1+hx;
                                    rayx[i]=x1;
                                    alpha1 = (asin(h2x/radi[i])+atan(mx))*180/M_PI;//+ang;
                                    alpha2 = asin(ind[i]*sin(alpha1/180*M_PI)/ind[i+1])*180/M_PI;
                                    mx = tan((alpha2-asin(h2x/radi[i])*180/M_PI)/180*M_PI);
                                    hx=h2x-mx*x1;
                                }
                                else{
                                    h2x=mx*x2+hx;
                                    rayx[i]=x2;
                                    alpha1 = (asin(h2x/radi[i])+atan(mx))*180/M_PI;//+ang;
                                    alpha2 = asin(ind[i]*sin(alpha1/180*M_PI)/ind[i+1])*180/M_PI;
                                    mx = tan((alpha2-asin(h2x/radi[i])*180/M_PI)/180*M_PI);
                                    hx=h2x-mx*x2;
                                }
                                if(y1<y2){
                                    h2y=my*y1+hy;
                                    alpha1y = (asin(h2y/radi[i])+atan(my))*180/M_PI;//+ang;
                                    alpha2y = asin(ind[i]*sin(alpha1y/180*M_PI)/ind[i+1])*180/M_PI;
                                    my = tan((alpha2y-asin(h2y/radi[i])*180/M_PI)/180*M_PI);
                                    hy=h2y-my*y1;
                                }
                                else{
                                    h2y=my*y2+hy;
                                    alpha1y = (asin(h2y/radi[i])+atan(my))*180/M_PI;//+ang;
                                    alpha2y = asin(ind[i]*sin(alpha1y/180*M_PI)/ind[i+1])*180/M_PI;
                                    my = tan((alpha2y-asin(h2y/radi[i])*180/M_PI)/180*M_PI);
                                    hy=h2y-my*y2;
                                }
                            }
                            else{
                                if(x1>x2){
                                    h2x=mx*x1+hx;
                                    rayx[i]=x1;
                                    alpha1 = (asin(h2x/radi[i])+atan(mx))*180/M_PI;//+ang;
                                    alpha2 = asin(ind[i]*sin(alpha1/180*M_PI)/ind[i+1])*180/M_PI;
                                    mx = tan((alpha2-asin(h2x/radi[i])*180/M_PI)/180*M_PI);
                                    hx=h2x-mx*x1;
                                }
                                else{
                                    h2x = mx*x2+hx;
                                    rayx[i]=x2;
                                    alpha1 = (asin(h2x/radi[i])+atan(mx))*180/M_PI;//+ang;
                                    alpha2 = asin(ind[i]*sin(alpha1/180*M_PI)/ind[i+1])*180/M_PI;
                                    mx = tan((alpha2-asin(h2x/radi[i])*180/M_PI)/180*M_PI);
                                    hx=h2x-mx*x2;
                                }
                                if(y1>y2){
                                    h2y=my*y1+hy;
                                    alpha1y = (asin(h2y/radi[i])+atan(my))*180/M_PI;//+ang;
                                    alpha2y = asin(ind[i]*sin(alpha1y/180*M_PI)/ind[i+1])*180/M_PI;
                                    my = tan((alpha2y-asin(h2y/radi[i])*180/M_PI)/180*M_PI);
                                    hy=h2y-my*y1;
                                }
                                else{
                                    h2y = my*y2+hy;
                                    alpha1y = (asin(h2y/radi[i])+atan(my))*180/M_PI;//+ang;
                                    alpha2y = asin(ind[i]*sin(alpha1y/180*M_PI)/ind[i+1])*180/M_PI;
                                    my = tan((alpha2-asin(h2y/radi[i])*180/M_PI)/180*M_PI);
                                    hy=h2y-my*y2;
                                }
                            }

                            Frenp = pow((sqrt(1-ind[i]*ind[i]/ind[i+1]/ind[i+1]*sin(M_PI/180*alpha2)*sin(M_PI/180*alpha2))*ind[i+1]-ind[i]*cos(M_PI/180*alpha2)),2)/pow((sqrt(1-ind[i]*ind[i]/ind[i+1]/ind[i+1]*sin(M_PI/180*alpha2)*sin(M_PI/180*alpha2))*ind[i+1]+ind[i]*cos(M_PI/180*alpha2)),2);
                            Frens = pow(ind[i+1]*(cos(M_PI/180*alpha2)-ind[i]*sqrt(1-ind[i]*ind[i]/ind[i+1]/ind[i+1]*sin(alpha2*M_PI/180)*sin(alpha2*M_PI/180))),2)/pow(ind[i+1]*(cos(M_PI/180*alpha2)+ind[i]*sqrt(1-ind[i]*ind[i]/ind[i+1]/ind[i+1]*sin(alpha2*M_PI/180)*sin(alpha2*M_PI/180))),2);
                            if(i<radi.size()-1){
                                Tr =Tr*(1-(Frenp+Frens)/2);
                                Trs=Trs*(1-Frens);
                                Trp=Trp*(1-Frenp);
                            }
                            else{
                                Tr=Tr;
                                Trs=Trs;
                                Trp=Trp;
                            }

                            rayy[i]=h2x;
                            //cout<<rayx[i]<<"\t"<<rayy[i]<<endl;
                            //cout<<x1<<"\t"<<x2<<"\t"<<alpha1<<"\t"<<alpha2<<"\t"<<m<<"\t"<<h<<"\t"<<ang<<"\t"<<h2<<endl;

                            if(fi==0 & i==5 & u==0){
                                //cout<<fi<<"\t"<<e<<"\t"<<u<<"\t"<<g<<"\t"<<i<<"\t"<<mx<<"\t"<<hx<<endl;
                                mxv[nmin]=mx;
                                hxv[nmin]=hx;
                                //cout<<mxv[min]<<"\t"<<hxv[min]<<endl;
                                ++nmin;
                            }

                        }   // end loop for surface to surface calculation


                        trans[e]+=Tr/nrays;
                        transs[e]+=Trs/nrays;
                        transp[e]+=Trp/nrays;
                        spot<<h2x*1000<<"\t"<<h2y*1000<<endl;
                        th =0;

                        havex[fi]+=h2x*1000/(nrays*nrays*nwaves);
                        havey[fi]+=h2y*1000/(nrays*nrays*nwaves);

                        if((e==0) & (u==0)){
                            ui->customPlot_3->addGraph();
                            ui->customPlot_3->graph(gray)->setData(rayx, rayy);
                            ui->customPlot_3->graph(gray)->setPen(qColors[nColor[e]]);

                            if((g==0) & (e==0)){
                                ui->customPlot_3->rescaleAxes(true);
                            }
                            else{
                                //ui->customPlot_3->rescaleAxes(true);
                            }
                            ui->customPlot_3->replot();
                            ++gray;
                        }
                        // end loop for transverse rays
                    } // end loop for radial rays

                }
            }   // end wavelengths loop
            if(fi==0){
                ui->customPlot_2->addGraph();
                ui->customPlot_2->graph(0)->setData(lambda, trans);
                ui->customPlot_2->graph(0)->setName("uncoated ave");
                ui->customPlot_2->graph(0)->setPen(pen1);
                ui->customPlot_2->rescaleAxes();
                ui->customPlot_2->addGraph();
                ui->customPlot_2->graph(1)->setData(lambda, transs);
                ui->customPlot_2->graph(1)->setName("uncoated s-pol");
                ui->customPlot_2->graph(1)->setPen(pen3);
                ui->customPlot_2->rescaleAxes(true);
                ui->customPlot_2->addGraph();
                ui->customPlot_2->graph(2)->setData(lambda, transp);
                ui->customPlot_2->graph(2)->setName("uncoated p-pol");
                ui->customPlot_2->graph(2)->setPen(pen7);
                ui->customPlot_2->rescaleAxes(true);
                ui->customPlot_2->replot();
            }
            if(fi==1){
                ui->customPlot_7->addGraph();
                ui->customPlot_7->graph(0)->setData(lambda, trans);
                ui->customPlot_7->graph(0)->setName("uncoated ave");
                ui->customPlot_7->graph(0)->setPen(pen1);
                ui->customPlot_7->rescaleAxes();
                ui->customPlot_7->addGraph();
                ui->customPlot_7->graph(1)->setData(lambda, transs);
                ui->customPlot_7->graph(1)->setName("uncoated s-pol");
                ui->customPlot_7->graph(1)->setPen(pen3);
                ui->customPlot_7->rescaleAxes(true);
                ui->customPlot_7->addGraph();
                ui->customPlot_7->graph(2)->setData(lambda, transp);
                ui->customPlot_7->graph(2)->setName("uncoated p-pol");
                ui->customPlot_7->graph(2)->setPen(pen7);
                ui->customPlot_7->rescaleAxes(true);
                ui->customPlot_7->replot();
            }

            // find focus on-axis
            if(ui->checkBox_4->isChecked()){
                    double x=llp;
                    double dx1=1.0, dx=1.0, xsta=llp, xend=llp+thi[6]+10, nx=0.0, mean1=0.0, mean2=0.0;
                    int ref=3;
                    //cout<<xsta<<"\t"<<xend<<"\t"<<x<<endl;

                    for(int i=0; i<ref; i++){
                        dx=dx1/(pow(10,i));
                        nx=(xend-xsta)/dx;
                        //cout<<i<<"\t"<<dx<<"\t"<<nx<<endl;
                        for(int tt=0; tt<nx; tt++){
                            x=xsta+tt*dx;
                            mean1=0.0;
                            for(int zz=0; zz<mxv.size(); zz++){
                                mean1+=pow((mxv[zz]*x+hxv[zz]),2);
                            }
                            mean1=sqrt(mean1)/mxv.size();
                            //cout<<x<<"\t"<<mean1<<endl;
                            if(tt>0){
                                if(mean1>=mean2){
                                    tt=nx;
                                    xsta=x-2*dx;
                                    xend=x;
                                    oback[gg]=(x-dx)-llp;
                                    rms[gg]=mean2;
                                    //cout<<mean1<<"\t"<<mean2<<"\t"<<rms[gg]<<endl;
                                }
                                else{
                                    mean2=mean1;
                                }
                            }
                            else{
                                mean2=mean1;
                            }
                        }   // end loop for discrete search on x

                    }   // end loop for refinements

            }
            //*********************

        } // end field loop
    }
    spot.close();

    if(ui->checkBox_4->isChecked()){
       oEval.open(sEval.c_str());

       QString qBest = ui->lineEdit_2->text()+"/bestcomp.pet";
       string sbest = qBest.toUtf8().constData();
       ofstream best(sbest.c_str());

       double rmsmin, ssrms;
       int gmin=0, counter=0;
       //QVector<double>
       for(int i=0; i<nsystems; i++){
           if(oback[i]>=ui->doubleSpinBox_4->value()){
                oEval<<first[i]<<"\t"<<second[i]<<"\t"<<nthi[i]<<"\t"<<oback[i]<<endl;//"\t"<<rms[i]<<endl;
           }
       }
       for(int e=0; e<10; e++){
           counter=0;
           rmsmin=rms[0];
           gmin=0;
            for(int i =0; i<rms.size(); i++){
                if((rms[i]<rmsmin) & (oback[i]>=ui->doubleSpinBox_4->value())){
                    gmin=i;
                    rmsmin=rms[i];
                }
            }
            string pro1 = product[first[gmin]];
            string pro2 = product[second[gmin]];
            cout<<rms[gmin]<<"\t"<<rms.size()<<"\t"<<gmin<<endl;
            ssrms=rms[gmin]*1000;
            QString srms = QString::number(ssrms);
            QString qstr = QString::fromStdString(pro1.c_str())+" & "+QString::fromStdString(pro2.c_str())+" rms: "+srms;
            ui->comboBox->addItem(qstr);
            best<<first[gmin]<<"\t"<<second[gmin]<<"\t"<<nthi[gmin]<<"\t"<<oback[gmin]<<endl;

            for(int i=0; i<rms.size(); i++){
                if(i!=gmin){
                    rms[counter]=rms[i];
                    first[counter]=first[i];
                    second[counter]=second[i];
                    nthi[counter]=nthi[i];
                    oback[counter]=oback[i];
                    ++counter;
                }
                else{
                    //
                }
            }
            rms.resize(counter);
            first.resize(counter);
            second.resize(counter);
            oback.resize(counter);
            nthi.resize(counter);
       }

    }

    // plot spots
    if(!ui->checkBox_4->isChecked()){
    ifstream ispot(sspot.c_str());

    QVector<double> pspotx(nrays*nrays), pspoty(nrays*nrays);

    for(int fi=0; fi<nfields; fi++){
        for(int e =0; e<nwaves; e++){
            for(int i=0; i<nrays*nrays; i++){
                ispot>>eins>>zwei;
                istringstream str(eins);
                str >> pspotx[i];
                istringstream str2(zwei);
                str2 >> pspoty[i];
                if(ui->checkBox_3->isChecked()){
                    pspotx[i]=pspotx[i]-havex[fi];
                    pspoty[i]=pspoty[i]-havey[fi];
                }
                else{

                }
            }
            if(fi==0){
                ui->customPlot->addGraph();
                ui->customPlot->graph(e)->setData(pspotx, pspoty);
                if(ui->spinBox->value()!=0){
                    if(ui->checkBox_3->isChecked()){
                        ui->customPlot->xAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                        ui->customPlot->yAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                    }
                    else{
                        ui->customPlot->xAxis->setRange(havex[0]-ui->spinBox->value(), havex[0]+ui->spinBox->value());
                        ui->customPlot->yAxis->setRange(havey[0]-ui->spinBox->value(), havey[0]+ui->spinBox->value());
                    }
                }
                else{
                    if(e==0){
                        ui->customPlot->rescaleAxes();
                    }
                    else{
                        ui->customPlot->rescaleAxes(true);
                    }
                }
                ui->customPlot->graph(e)->setPen(qColors[nColor[e]]);
                ui->customPlot->graph(e)->setName(QString::number(lambda[e]));
                ui->customPlot->graph(e)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot->graph(e)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
                ui->customPlot->replot();
            }
            if(fi==1){
                ui->customPlot_5->addGraph();
                ui->customPlot_5->graph(e)->setData(pspotx, pspoty);
                if(ui->spinBox->value()!=0){
                    if(ui->checkBox_3->isChecked()){
                        ui->customPlot_5->xAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                        ui->customPlot_5->yAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                    }
                    else{
                        ui->customPlot_5->xAxis->setRange(havex[1]-ui->spinBox->value(), havex[1]+ui->spinBox->value());
                        ui->customPlot_5->yAxis->setRange(havey[1]-ui->spinBox->value(), havey[1]+ui->spinBox->value());
                    }
                }
                else{
                    if(e==0){
                        ui->customPlot_5->rescaleAxes();
                    }
                    else{
                        ui->customPlot_5->rescaleAxes(true);
                    }
                }
                ui->customPlot_5->graph(e)->setPen(qColors[nColor[e]]);
                ui->customPlot_5->graph(e)->setName(QString::number(lambda[e]));
                ui->customPlot_5->graph(e)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot_5->graph(e)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
                ui->customPlot_5->replot();
            }
            if(fi==2){
                ui->customPlot_4->addGraph();
                ui->customPlot_4->graph(e)->setData(pspotx, pspoty);
                if(ui->spinBox->value()!=0){
                    if(ui->checkBox_3->isChecked()){
                        ui->customPlot_4->xAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                        ui->customPlot_4->yAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                    }
                    else{
                        ui->customPlot_4->xAxis->setRange(havex[2]-ui->spinBox->value(), havex[2]+ui->spinBox->value());
                        ui->customPlot_4->yAxis->setRange(havey[2]-ui->spinBox->value(), havey[2]+ui->spinBox->value());
                    }
                }
                else{
                    if(e==0){
                        ui->customPlot_4->rescaleAxes();
                    }
                    else{
                        ui->customPlot_4->rescaleAxes(true);
                    }
                }
                ui->customPlot_4->graph(e)->setPen(qColors[nColor[e]]);
                ui->customPlot_4->graph(e)->setName(QString::number(lambda[e]));
                ui->customPlot_4->graph(e)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot_4->graph(e)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
                ui->customPlot_4->replot();
            }
            if(fi==3){
                ui->customPlot_6->addGraph();
                ui->customPlot_6->graph(e)->setData(pspotx, pspoty);
                if(ui->spinBox->value()!=0){
                    if(ui->checkBox_3->isChecked()){
                        ui->customPlot_6->xAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                        ui->customPlot_6->yAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                    }
                    else{
                        ui->customPlot_6->xAxis->setRange(havex[3]-ui->spinBox->value(), havex[3]+ui->spinBox->value());
                        ui->customPlot_6->yAxis->setRange(havey[3]-ui->spinBox->value(), havey[3]+ui->spinBox->value());
                    }
                }
                else{
                    if(e==0){
                        ui->customPlot_6->rescaleAxes();
                    }
                    else{
                        ui->customPlot_6->rescaleAxes(true);
                    }
                }
                ui->customPlot_6->graph(e)->setPen(qColors[nColor[e]]);
                ui->customPlot_6->graph(e)->setName(QString::number(lambda[e]));
                ui->customPlot_6->graph(e)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot_6->graph(e)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
                ui->customPlot_6->replot();
            }
        }
    }
    }

}

//**********************************
// Load glass catalog
//**********************************
void Petzval::on_pushButton_5_clicked()
{
    QString qLib = ui->lineEdit_2->text()+"/"+ui->lineEdit_4->text();
    string sbin = qLib.toUtf8().constData();
    ifstream glass(sbin.c_str());

    QFile qBin(qLib);

    if(!qBin.exists()){
        QMessageBox::information(this, "Error", "Glass database "+qLib+" not present.");
        return;
    }

    else{
        llines=0;
        string zeile1, eins, zwei, drei, vier, fuenf, sechs, sieben;

        while(std::getline(glass, zeile1))
        ++ llines;

        glass.clear();
        glass.seekg(0, ios::beg);

        SB1.resize(llines);
        SB2.resize(llines);
        SB3.resize(llines);
        SC1.resize(llines);
        SC2.resize(llines);
        SC3.resize(llines);
        SGlass.resize(llines);

        for(int i=0; i < llines; i++){
            glass >> eins >> zwei >> drei >> vier >> fuenf >> sechs >> sieben;
            istringstream str1(eins);
            str1 >> SGlass[i];
            istringstream str2(zwei);
            str2 >> SB1[i];
            istringstream str3(drei);
            str3 >> SB2[i];
            istringstream str4(vier);
            str4 >> SB3[i];
            istringstream str5(fuenf);
            str5 >> SC1[i];
            istringstream str6(sechs);
            str6 >> SC2[i];
            istringstream str7(sieben);
            str7 >> SC3[i];
        }
    }
}

void Petzval::on_spinBox_5_valueChanged()
{
    nwaves = ui->spinBox_5->value();
    int nwaves2=ui->tableWidget->rowCount();
    if(nwaves>nwaves2){
        for(int i=0; i<nwaves-nwaves2; i++){
            ui->tableWidget->insertRow(nwaves2+i);
            QComboBox *combo = new QComboBox();
            ui->tableWidget->setCellWidget(nwaves2+i, 1, combo);
            combo->addItem("Dark Blue");
            combo->addItem("Blue");
            combo->addItem("Dark Green");
            combo->addItem("Green");
            combo->addItem("Dark Yellow");
            combo->addItem("Yellow");
            combo->addItem("Dark Red");
            combo->addItem("Red");
            combo->addItem("Dark Magenta");
            combo->addItem("Magenta");
            combo->addItem("Dark Cyan");
            combo->addItem("Cyan");
            combo->addItem("black");
        }
    }
    if(nwaves<nwaves2){
        for(int i=0; i<nwaves2-nwaves; i++){
            ui->tableWidget->removeRow(nwaves2-i-1);
        }
    }
    ui->tableWidget->setRowCount(nwaves);
}

void Petzval::on_checkBox_clicked()
{
    if(ui->checkBox->isChecked()){
        ui->checkBox_2->setChecked(false);
    }
    else{
        ui->checkBox_2->setChecked(true);
    }
}

void Petzval::on_checkBox_2_clicked()
{
    if(ui->checkBox_2->isChecked()){
        ui->checkBox->setChecked(false);
    }
    else{
        ui->checkBox->setChecked(true);
    }
}

//************************************
// save spot diagram
//************************************
void Petzval::on_pushButton_6_clicked()
{
    QString save=ui->lineEdit_2->text()+"/"+ui->lineEdit_7->text();

    if(ui->checkBox->isChecked()){
        ui->customPlot->savePdf(save+"_1.pdf");
    }
    else{
        ui->customPlot->savePng(save+"_1.png");
    }
    if(nfields>1){
        if(ui->checkBox->isChecked()){
            ui->customPlot_5->savePdf(save+"_2.pdf");
        }
        else{
            ui->customPlot_5->savePng(save+"_2.png");
        }
    }
    if(nfields>2){
        if(ui->checkBox->isChecked()){
            ui->customPlot_4->savePdf(save+"_3.pdf");
        }
        else{
            ui->customPlot_4->savePng(save+"_3.png");
        }
    }
    if(nfields>3){
        if(ui->checkBox->isChecked()){
            ui->customPlot_6->savePdf(save+"_4.pdf");
        }
        else{
            ui->customPlot_6->savePng(save+"_4.png");
        }
    }
}


// Find Glass substitution
void Petzval::on_pushButton_7_clicked()
{
    Petzval::on_pushButton_5_clicked();

    double Nd = ui->doubleSpinBox_7->value(), Vd = ui->doubleSpinBox_8->value(), Nd2=0, NC2=0, NF2=0, Vd2=0;
    double wd = 0.5875618, wC = 0.6562725, wF = 0.4861327;
    int gsize = SGlass.size(), nlist = ui->spinBox_6->value();
    QVector<double> dN(gsize), dV(gsize), dif(nlist);
    d2N.resize(nlist);
    d2V.resize(nlist);
    dGlass.resize(nlist);


    for(int i=0; i<gsize; i++){
        Nd2 = sqrt(1+SB1[i]*pow(wd,2)/(pow(wd,2)-SC1[i])+SB2[i]*pow(wd,2)/(pow(wd,2)-SC2[i])+SB3[i]*pow(wd,2)/(pow(wd,2)-SC3[i]));
        NC2 = sqrt(1+SB1[i]*pow(wC,2)/(pow(wC,2)-SC1[i])+SB2[i]*pow(wC,2)/(pow(wC,2)-SC2[i])+SB3[i]*pow(wC,2)/(pow(wC,2)-SC3[i]));
        NF2 = sqrt(1+SB1[i]*pow(wF,2)/(pow(wF,2)-SC1[i])+SB2[i]*pow(wF,2)/(pow(wF,2)-SC2[i])+SB3[i]*pow(wF,2)/(pow(wF,2)-SC3[i]));
        Vd2 = (Nd2-1)/(NF2-NC2);
        dN[i]=abs((Nd-Nd2)/Nd);
        dV[i]=abs((Vd-Vd2)/Vd);
    }
    int checker=0;

    for(int i=0; i<nlist; i++){
        dif[i]=(dN[0]+dV[0])/2;
        for(int e =0; e<gsize; e++){

            if((dN[e]+dV[e])/2<dif[i]){
                for(int g=0; g<i; g++){
                    if((dN[e]+dV[e])/2>dif[g]){
                        ++checker;
                    }
                    else{
                        //
                    }
                }
                if(checker==i){
                    dif[i]=(dN[e]+dV[e])/2;
                    d2N[i]=dN[e]*100;
                    d2V[i]=dV[e]*100;
                    dGlass[i]=SGlass[e];
                }
                else{
                    //
                }
                checker=0;
            }
            else{
                //
            }
        }
    }
    ui->comboBox_2->clear();

    for(int i=0; i<nlist; i++){
        ui->comboBox_2->addItem(QString::fromStdString(dGlass[i]));
    }
}

void Petzval::on_comboBox_2_currentIndexChanged()
{
    int indd=ui->comboBox_2->currentIndex();
    ui->lineEdit_8->setText(QString::number(d2N[indd], 'G', 5));
    ui->lineEdit_9->setText(QString::number(d2V[indd], 'G', 5));
}

//*******************************
// adding field to table widget
//*******************************
void Petzval::on_spinBox_7_valueChanged()
{
    int nfields2=ui->tableWidget_2->rowCount();
    nfields = ui->spinBox_7->value();
    if(nfields>nfields2){
        for(int i=0; i<nfields-nfields2; i++){
            ui->tableWidget_2->insertRow(nfields2+i);

        }
    }
    if(nfields<nfields2){
        for(int i=0; i<nfields2-nfields; i++){
            ui->tableWidget_2->removeRow(nfields2-i-1);
        }
    }
    ui->tableWidget_2->setRowCount(nfields);
}


//****************************
// replot spots
//****************************
void Petzval::on_pushButton_8_clicked()
{
    QString qSpot = ui->lineEdit_2->text()+"/spot.pet";
    string sspot = qSpot.toUtf8().constData();
    ifstream ispot(sspot.c_str());

    int symbol=ui->spinBox_2->value();

    ui->customPlot->clearGraphs();
    ui->customPlot_4->clearGraphs();
    ui->customPlot_5->clearGraphs();
    ui->customPlot_6->clearGraphs();

    QVector<QPen> qColors(13);

    QPen pen0;
    pen0.setWidth(symbol);
    pen0.setColor(Qt::darkBlue);
    qColors[0]=pen0;
    QPen pen1;
    pen1.setWidth(symbol);
    pen1.setColor(Qt::blue);
    qColors[1]=pen1;
    QPen pen2;
    pen2.setWidth(symbol);
    pen2.setColor(Qt::darkGreen);
    qColors[2]=pen2;
    QPen pen3;
    pen3.setWidth(symbol);
    pen3.setColor(Qt::green);
    qColors[3]=pen3;
    QPen pen4;
    pen4.setWidth(symbol);
    pen4.setColor(Qt::darkYellow);
    qColors[4]=pen4;
    QPen pen5;
    pen5.setWidth(symbol);
    pen5.setColor(Qt::yellow);
    qColors[5]=pen5;
    QPen pen6;
    pen6.setWidth(symbol);
    pen6.setColor(Qt::darkRed);
    qColors[6]=pen6;
    QPen pen7;
    pen7.setWidth(symbol);
    pen7.setColor(Qt::red);
    qColors[7]=pen7;
    QPen pen8;
    pen8.setWidth(symbol);
    pen8.setColor(Qt::darkMagenta);
    qColors[8]=pen8;
    QPen pen9;
    pen9.setWidth(symbol);
    pen9.setColor(Qt::magenta);
    qColors[9]=pen9;
    QPen pen10;
    pen10.setWidth(symbol);
    pen10.setColor(Qt::darkCyan);
    qColors[10]=pen10;
    QPen pen11;
    pen11.setWidth(symbol);
    pen11.setColor(Qt::cyan);
    qColors[11]=pen11;
    QPen pen12;
    pen12.setWidth(symbol);
    pen12.setColor(Qt::black);
    qColors[12]=pen12;

    QVector<int> nColor(13);

    for(int i=0; i<ui->spinBox_5->value(); i++){
        QComboBox* combo = (QComboBox*)ui->tableWidget->cellWidget(i, 1);
        nColor[i]=combo->currentIndex();
    }

    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox_3->value());

    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot_4->legend->setFont(legendFont);
    ui->customPlot_5->legend->setFont(legendFont);
    ui->customPlot_6->legend->setFont(legendFont);

    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);

    ui->customPlot_4->xAxis->setLabelFont(legendFont);
    ui->customPlot_4->yAxis->setLabelFont(legendFont);
    ui->customPlot_4->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_4->yAxis->setTickLabelFont(legendFont);
    ui->customPlot_5->xAxis->setLabelFont(legendFont);
    ui->customPlot_5->yAxis->setLabelFont(legendFont);
    ui->customPlot_5->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_5->yAxis->setTickLabelFont(legendFont);
    ui->customPlot_6->xAxis->setLabelFont(legendFont);
    ui->customPlot_6->yAxis->setLabelFont(legendFont);
    ui->customPlot_6->xAxis->setTickLabelFont(legendFont);
    ui->customPlot_6->yAxis->setTickLabelFont(legendFont);

    QVector<double> pspotx(nrays*nrays), pspoty(nrays*nrays);
    string eins, zwei;

    for(int fi=0; fi<nfields; fi++){
        for(int e =0; e<nwaves; e++){
            for(int i=0; i<nrays*nrays; i++){
                ispot>>eins>>zwei;
                istringstream str(eins);
                str >> pspotx[i];
                istringstream str2(zwei);
                str2 >> pspoty[i];
                if(ui->checkBox_3->isChecked()){
                    pspotx[i]=pspotx[i]-havex[fi];
                    pspoty[i]=pspoty[i]-havey[fi];
                }
            }
            if(fi==0){
                ui->customPlot->addGraph();
                ui->customPlot->graph(e)->setData(pspotx, pspoty);
                if(ui->spinBox->value()!=0){
                    if(ui->checkBox_3->isChecked()){
                        ui->customPlot->xAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                        ui->customPlot->yAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                    }
                    else{
                        ui->customPlot->xAxis->setRange(havex[0]-ui->spinBox->value(), havex[0]+ui->spinBox->value());
                        ui->customPlot->yAxis->setRange(havey[0]-ui->spinBox->value(), havey[0]+ui->spinBox->value());
                    }
                }
                else{
                    if(e==0){
                        ui->customPlot->rescaleAxes();
                    }
                    else{
                        ui->customPlot->rescaleAxes(true);
                    }
                }
                ui->customPlot->graph(e)->setPen(qColors[nColor[e]]);
                ui->customPlot->graph(e)->setName(QString::number(lambda[e]));
                ui->customPlot->graph(e)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot->graph(e)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
                ui->customPlot->replot();
            }
            if(fi==1){
                ui->customPlot_5->addGraph();
                ui->customPlot_5->graph(e)->setData(pspotx, pspoty);
                if(ui->spinBox->value()!=0){
                    if(ui->checkBox_3->isChecked()){
                        ui->customPlot_5->xAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                        ui->customPlot_5->yAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                    }
                    else{
                        ui->customPlot_5->xAxis->setRange(havex[1]-ui->spinBox->value(), havex[1]+ui->spinBox->value());
                        ui->customPlot_5->yAxis->setRange(havey[1]-ui->spinBox->value(), havey[1]+ui->spinBox->value());
                    }
                }
                else{
                    if(e==0){
                        ui->customPlot_5->rescaleAxes();
                    }
                    else{
                        ui->customPlot_5->rescaleAxes(true);
                    }
                }
                ui->customPlot_5->graph(e)->setPen(qColors[nColor[e]]);
                ui->customPlot_5->graph(e)->setName(QString::number(lambda[e]));
                ui->customPlot_5->graph(e)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot_5->graph(e)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
                ui->customPlot_5->replot();
            }
            if(fi==2){
                ui->customPlot_4->addGraph();
                ui->customPlot_4->graph(e)->setData(pspotx, pspoty);
                if(ui->spinBox->value()!=0){
                    if(ui->checkBox_3->isChecked()){
                        ui->customPlot_4->xAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                        ui->customPlot_4->yAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                    }
                    else{
                        ui->customPlot_4->xAxis->setRange(havex[2]-ui->spinBox->value(), havex[2]+ui->spinBox->value());
                        ui->customPlot_4->yAxis->setRange(havey[2]-ui->spinBox->value(), havey[2]+ui->spinBox->value());
                    }
                }
                else{
                    if(e==0){
                        ui->customPlot_4->rescaleAxes();
                    }
                    else{
                        ui->customPlot_4->rescaleAxes(true);
                    }
                }
                ui->customPlot_4->graph(e)->setPen(qColors[nColor[e]]);
                ui->customPlot_4->graph(e)->setName(QString::number(lambda[e]));
                ui->customPlot_4->graph(e)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot_4->graph(e)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
                ui->customPlot_4->replot();
            }
            if(fi==3){
                ui->customPlot_6->addGraph();
                ui->customPlot_6->graph(e)->setData(pspotx, pspoty);
                if(ui->spinBox->value()!=0){
                    if(ui->checkBox_3->isChecked()){
                        ui->customPlot_6->xAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                        ui->customPlot_6->yAxis->setRange(-ui->spinBox->value(), ui->spinBox->value());
                    }
                    else{
                        ui->customPlot_6->xAxis->setRange(havex[3]-ui->spinBox->value(), havex[3]+ui->spinBox->value());
                        ui->customPlot_6->yAxis->setRange(havey[3]-ui->spinBox->value(), havey[3]+ui->spinBox->value());
                    }
                }
                else{
                    if(e==0){
                        ui->customPlot_6->rescaleAxes();
                    }
                    else{
                        ui->customPlot_6->rescaleAxes(true);
                    }
                }
                ui->customPlot_6->graph(e)->setPen(qColors[nColor[e]]);
                ui->customPlot_6->graph(e)->setName(QString::number(lambda[e]));
                ui->customPlot_6->graph(e)->setLineStyle(QCPGraph::lsNone);
                ui->customPlot_6->graph(e)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, symbol));
                ui->customPlot_6->replot();
            }
        }
    }
}

void Petzval::on_checkBox_4_clicked()
{
    if(ui->checkBox_4->isChecked()){
        ui->spinBox_8->setEnabled(false);
    }
    else{
        ui->spinBox_8->setEnabled(true);
    }
}
