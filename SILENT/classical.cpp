#include "classical.h"
#include "ui_classical.h"
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

double scl, gcl, dcl, ncl, thetacl, btcl, b1cl, Il1cl, Ineon, etacl, exptimecl, atcl, Il2cl, tcl, Tcl, vmcl, BCcl, zcl, f1cl, f2cl, acl, bcl, ftelcl, slcl, lcl, skyslitcl, dtelcl, seeingcl, sdisccl, slitEffcl, pcl, gaincl, biascl, noisecl, CCDmcl, CCDTcl, CCDwcl, CCDpcl;
int lxcl, lycl, Bxcl, Bycl, bbcl, alcl, agcl, aluvcl, aucl, aalcl=0, aagcl=0, abbcl=0, aaluvcl=0, aaucl=0, send=0, slicescl;
double kcl = 143877500, distycl, distxcl, fibredcl;
double apcl = 1.87088e24;

QVector<double> wcl(lxcl), Acl(lxcl), s2cl(lxcl), Rcl(lxcl), Trcl(lxcl), emi(lxcl), absor(lxcl), CCDcl(lxcl), Nfcl(lxcl), Dcl(lxcl), Pcl(lxcl), I1cl(lxcl), Efcl(lxcl);
QVector<double> alcli(1), alclw(1), aluvcli(1), aluvclw(1), agcli(1), agclw(1), aucli(1), auclw(1), bbcli(1), bbclw(1), alclt(1), agclt(1), bbclt(1), aluvclt(1), auclt(1);
int varcl=35;
QVector<double> variablescl(varcl);
QString qCPath;
string cPath;

classical::classical(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::classical)
{
    ui->setupUi(this);
    this->setWindowTitle("Classical Spectrograph");

    ui->progressBar->setValue(0);

    ui->checkBox->setChecked(true);
    ui->checkBox_2->setChecked(false);

    ui->doubleSpinBox_23->setEnabled(false);

    ui->doubleSpinBox_17->setValue(300);
    gcl=ui->doubleSpinBox_17->value();

    ui->spinBox_10->setValue(1);
    ncl=ui->spinBox_10->value();

    ui->doubleSpinBox_18->setValue(5);
    thetacl=ui->doubleSpinBox_18->value();

    ui->doubleSpinBox_19->setValue(20);
    tcl=ui->doubleSpinBox_19->value();

    ui->doubleSpinBox_20->setValue(200);
    f1cl=ui->doubleSpinBox_20->value();;

    ui->doubleSpinBox_21->setValue(200);
    f2cl=ui->doubleSpinBox_21->value();;

    ui->doubleSpinBox_22->setValue(0.05);

    ui->doubleSpinBox_23->setValue(0);
    slcl=ui->doubleSpinBox_23->value();

    ui->doubleSpinBox_14->setValue(2500);
    ftelcl=ui->doubleSpinBox_14->value();

    ui->doubleSpinBox_15->setValue(254);
    dtelcl=ui->doubleSpinBox_15->value();

    skyslitcl=atan(scl/ftelcl)*3600*180/M_PI;
    QString Output=QString::number(skyslitcl);
    ui->lineEdit_10->setText(Output);

    ui->doubleSpinBox_13->setValue(4);
    seeingcl=ui->doubleSpinBox_13->value();

    sdisccl=tan(M_PI/180*seeingcl/3600)*ftelcl;

    if(ui->checkBox_3->isChecked()){

        scl=sdisccl;
    }
    else{
         scl=ui->doubleSpinBox_22->value();
    }

    ui->doubleSpinBox->setValue(0.009);
    pcl=ui->doubleSpinBox->value();

    ui->spinBox_3->setValue(2024);
    lxcl=ui->spinBox_3->value();

    ui->spinBox_4->setValue(1024);
    lycl=ui->spinBox_4->value();

    ui->spinBox->setValue(1);
    Bxcl=ui->spinBox->value();

    ui->spinBox_2->setValue(1);
    Bycl=ui->spinBox_2->value();

    ui->doubleSpinBox_2->setValue(200);
    biascl=ui->doubleSpinBox_2->value();

    ui->doubleSpinBox_3->setValue(9);
    noisecl=ui->doubleSpinBox_3->value();

    ui->doubleSpinBox_4->setValue(550);
    CCDwcl=ui->doubleSpinBox_4->value();

    ui->doubleSpinBox_5->setValue(0.85);
    CCDpcl=ui->doubleSpinBox_5->value();

    ui->doubleSpinBox_6->setValue(1.5);
    gaincl=ui->doubleSpinBox_6->value();

    ui->doubleSpinBox_7->setValue(550);
    lcl=ui->doubleSpinBox_7->value();

    CCDTcl=2897.8/CCDwcl*1000;
    CCDmcl = 1.87088e19/(CCDwcl*CCDwcl*CCDwcl*CCDwcl*CCDwcl)/(exp(14387750/CCDwcl/CCDTcl)-1);

    dcl=cos(M_PI/180*thetacl)/gcl;

    ui->doubleSpinBox_8->setValue(5000);
    Tcl=ui->doubleSpinBox_8->value();

    ui->doubleSpinBox_10->setValue(5);
    vmcl=ui->doubleSpinBox_10->value();

    ui->doubleSpinBox_11->setValue(15);
    zcl=ui->doubleSpinBox_11->value();

    ui->doubleSpinBox_12->setValue(0.75);
    etacl=ui->doubleSpinBox_12->value();

    ui->doubleSpinBox_16->setValue(10);
    exptimecl=ui->doubleSpinBox_16->value();

    ui->comboBox->addItem("Planck Continuum");
    ui->comboBox->addItem("Balmer Absorption");
    ui->comboBox->addItem("Neon Emission");

}

classical::~classical()
{
    delete ui;
}

void classical::seData(QString str)
{
    ui->lineEdit_3->setText(str);
}

void classical::on_checkBox_clicked()
{
    ui->doubleSpinBox_23->setEnabled(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void classical::on_checkBox_2_clicked()
{
    ui->doubleSpinBox_23->setEnabled(true);
    ui->checkBox->setChecked(false);
    ui->checkBox_3->setChecked(false);
}

void classical::on_checkBox_3_clicked()
{
    ui->doubleSpinBox_23->setEnabled(false);
    ui->checkBox_2->setChecked(false);
    ui->checkBox->setChecked(false);
}


// efficiency at slit
void classical::on_pushButton_2_clicked()
{
    sdisccl = sdisccl/2.3548;
    // circular slit
    if(ui->checkBox->isChecked()){

        double slitstep=0.0001;
        int steps=scl/2/slitstep+1;
        double relativ=0;
        for(int i =0; i<steps-1; i++){
            relativ+=(exp(-i*slitstep*i*slitstep/2/sdisccl/sdisccl)+exp(-(i+1)*slitstep*(i+1)*slitstep/2/sdisccl/sdisccl))/2*slitstep;
        }
        slitEffcl=pow((2*relativ/(sdisccl*sqrt(M_PI*2))),2);
        QString SlitEffcl=QString::number(slitEffcl*100);
        ui->lineEdit_9->setText(SlitEffcl);
    }

    // rectangular slit
    if(ui->checkBox_2->isChecked()){

        double slitstep=0.0001;
        int steps1=scl/2/slitstep+1;
        int steps2=slcl/2/slitstep+1;
        double relativ1=0, relativ2=0;
        for(int i =0; i<steps1-1; i++){
            relativ1+=(exp(-i*slitstep*i*slitstep/2/sdisccl/sdisccl)+exp(-(i+1)*slitstep*(i+1)*slitstep/2/sdisccl/sdisccl))/2*slitstep;
        }
        if(slcl!=0){
        for(int i =0; i<steps2-1; i++){
            relativ2+=(exp(-i*slitstep*i*slitstep/2/sdisccl/sdisccl)+exp(-(i+1)*slitstep*(i+1)*slitstep/2/sdisccl/sdisccl))/2*slitstep;
        }}
        else{
            relativ2+=sdisccl*sqrt(M_PI*2)/2;
        }
        slitEffcl=2*relativ1*2*relativ2/pow((sdisccl*sqrt(M_PI*2)),2);
        QString SlitEffcl=QString::number(slitEffcl*100);
        ui->lineEdit_9->setText(SlitEffcl);
    }

    // slitless
    if(ui->checkBox_3->isChecked()){
        slitEffcl=1.0;
        QString SlitEffcl=QString::number(slitEffcl*100);
        ui->lineEdit_9->setText(SlitEffcl);
    }
    sdisccl = sdisccl*2.3548;

}

void classical::on_doubleSpinBox_valueChanged()
{
    pcl=ui->doubleSpinBox->value();
}

void classical::on_doubleSpinBox_2_valueChanged()
{
    biascl=ui->doubleSpinBox_2->value();
}

void classical::on_doubleSpinBox_3_valueChanged()
{
    noisecl=ui->doubleSpinBox_3->value();
}

void classical::on_doubleSpinBox_4_valueChanged()
{
    CCDwcl=ui->doubleSpinBox_4->value();
}

void classical::on_doubleSpinBox_5_valueChanged()
{
    CCDpcl=ui->doubleSpinBox_5->value();
}

void classical::on_spinBox_3_valueChanged()
{
    lxcl=ui->spinBox_3->value();
}

void classical::on_spinBox_4_valueChanged()
{
    lycl=ui->spinBox_4->value();
}

void classical::on_spinBox_valueChanged()
{
    Bxcl=ui->spinBox->value();
}

void classical::on_spinBox_2_valueChanged()
{
    Bycl=ui->spinBox_2->value();
}

void classical::on_doubleSpinBox_6_valueChanged()
{
    gaincl=ui->doubleSpinBox_6->value();
}

void classical::vecresize(){
    wcl.resize(lxcl/Bxcl);
    Rcl.resize(lxcl/Bxcl);
    Acl.resize(lxcl/Bxcl);
    s2cl.resize(lxcl/Bxcl);
    Nfcl.resize(lxcl/Bxcl);
    Trcl.resize(lxcl/Bxcl);
    Dcl.resize(lxcl/Bxcl);
    CCDcl.resize(lxcl/Bxcl);
    Pcl.resize(lxcl/Bxcl);
    I1cl.resize(lxcl/Bxcl);
    Efcl.resize(lxcl/Bxcl);
    alclt.resize(lxcl/Bxcl);
    aluvclt.resize(lxcl/Bxcl);
    agclt.resize(lxcl/Bxcl);
    auclt.resize(lxcl/Bxcl);
    bbclt.resize(lxcl/Bxcl);
}

//*****************************
// Parameters
//*****************************
void classical::on_pushButton_3_clicked()
{
    this->setCursor(QCursor(Qt::WaitCursor));
    classical::vecresize();

    if(ui->checkBox_3->isChecked()){
        scl=tan(ui->doubleSpinBox_13->value()/180*M_PI/3600)*ui->doubleSpinBox_14->value();
    }

    else{
        scl = ui->doubleSpinBox_22->value();
    }

    qCPath = ui->lineEdit_3->text();
    cPath = qCPath.toUtf8().constData();

    string zeile, one, two, line, eins, zwei;
    int bini=0, bini2=0, bini3=0, bini4=0, bini5=0;

    agcl=ui->spinBox_5->value();
    alcl=ui->spinBox_6->value();
    aluvcl=ui->spinBox_7->value();
    aucl=ui->spinBox_8->value();
    bbcl=ui->spinBox_9->value();

    if(alcl>0){

        std::ostringstream datNameStream(cPath);
        datNameStream<<cPath<<"/protected_Al.txt";
        std::string datName = datNameStream.str();
        ifstream input1(datName.c_str());

    QFile checkfile1(datName.c_str());

    if(!checkfile1.exists()){
        QMessageBox::information(this, "Error", "Reflection data "+checkfile1.fileName()+" of aluminium not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input1, line))
       ++ bini;

    input1.clear();
    input1.seekg(0, ios::beg);

    alcli.resize(bini);
    alclw.resize(bini);

    for (int i =0; i < bini; i++){
    input1 >> eins >> zwei;
    istringstream istr(eins);
    istr >> alcli[i];
    istringstream istr1(zwei);
    istr1 >> alclw[i];
    cout<<alclw[i]<<" "<<alcli[i]<<endl;
    }
    input1.close();
}
    if(aluvcl>0){

        std::ostringstream dat2NameStream(cPath);
        dat2NameStream<<cPath<<"/UVEnhanced_Al.txt";
        std::string dat2Name = dat2NameStream.str();
        ifstream input2(dat2Name.c_str());

    QFile checkfile2(dat2Name.c_str());

    if(!checkfile2.exists()){
        QMessageBox::information(this, "Error", "Reflection data "+checkfile2.fileName()+" of UV enhanced aluminium not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input2, line))
       ++ bini2;

    input2.clear();
    input2.seekg(0, ios::beg);

    aluvcli.resize(bini2);
    aluvclw.resize(bini2);

    for (int i =0; i < bini2; i++){
    input2 >> eins >> zwei;
    istringstream istr2(eins);
    istr2 >> aluvclw[i];
    istringstream istr3(zwei);
    istr3 >> aluvcli[i];
    }
    input2.close();
}
    if(agcl>0){

        std::ostringstream dat3NameStream(cPath);
        dat3NameStream<<cPath<<"/protected_Ag.txt";
        std::string dat3Name = dat3NameStream.str();
        ifstream input3(dat3Name.c_str());

    QFile checkfile3(dat3Name.c_str());

    if(!checkfile3.exists()){
        QMessageBox::information(this, "Error", "Reflection data "+checkfile3.fileName()+" of protected silver not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input3, line))
       ++ bini3;

    input3.clear();
    input3.seekg(0, ios::beg);

    agcli.resize(bini3);
    agclw.resize(bini3);

    for (int i =0; i < bini3; i++){
    input3 >> eins >> zwei;
    istringstream istr4(eins);
    istr4 >> agclw[i];
    istringstream istr5(zwei);
    istr5 >> agcli[i];
    }
    input3.close();
}

    if(aucl>0){

        std::ostringstream dat4NameStream(cPath);
        dat4NameStream<<cPath<<"/protected_Au.txt";
        std::string dat4Name = dat4NameStream.str();
        ifstream input4(dat4Name.c_str());

    QFile checkfile4(dat4Name.c_str());

    if(!checkfile4.exists()){
        QMessageBox::information(this, "Error", "Reflection data "+checkfile4.fileName()+" of protected gold not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input4, line))
       ++ bini4;

    input4.clear();
    input4.seekg(0, ios::beg);

    aucli.resize(bini4);
    auclw.resize(bini4);

    for (int i =0; i < bini4; i++){
    input4 >> eins >> zwei;
    istringstream istr6(eins);
    istr6 >> auclw[i];
    istringstream istr7(zwei);
    istr7 >> aucli[i];
    }
    input4.close();
}

    if(bbcl>0){

        std::ostringstream dat5NameStream(cPath);
        dat5NameStream<<cPath<<"/vis_ar.txt";
        std::string dat5Name = dat5NameStream.str();
        ifstream input5(dat5Name.c_str());

    QFile checkfile5(dat5Name.c_str());

    if(!checkfile5.exists()){
        QMessageBox::information(this, "Error", "Transmission data "+checkfile5.fileName()+" of VIS AR coating not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    while(std::getline(input5, line))
       ++ bini5;

    input5.clear();
    input5.seekg(0, ios::beg);

    bbcli.resize(bini5);
    bbclw.resize(bini5);

    for (int i =0; i < bini5; i++){
    input5 >> eins >> zwei;
    istringstream istr8(eins);
    istr8 >> bbclw[i];
    istringstream istr9(zwei);
    istr9 >> bbcli[i];
    }
    input5.close();
}

    classical::on_pushButton_2_clicked();

    std::ostringstream datNameStream(cPath);
    datNameStream<<cPath<<"/efficiencycl.txt";
    std::string datName = datNameStream.str();
    ofstream file1(datName.c_str());

    std::ostringstream dat2NameStream(cPath);
    dat2NameStream<<cPath<<"/ccdcl.txt";
    std::string dat2Name = dat2NameStream.str();
    ofstream file2(dat2Name.c_str());

    std::ostringstream dat3NameStream(cPath);
    dat3NameStream<<cPath<<"/amamorphismcl.txt";
    std::string dat3Name = dat3NameStream.str();
    ofstream file3(dat3Name.c_str());

    std::ostringstream dat4NameStream(cPath);
    dat4NameStream<<cPath<<"/nyquistcl.txt";
    std::string dat4Name = dat4NameStream.str();
    ofstream file4(dat4Name.c_str());

    std::ostringstream dat5NameStream(cPath);
    dat5NameStream<<cPath<<"/slitcl.txt";
    std::string dat5Name = dat5NameStream.str();
    ofstream file5(dat5Name.c_str());

    std::ostringstream dat6NameStream(cPath);
    dat6NameStream<<cPath<<"/resolvingcl.txt";
    std::string dat6Name = dat6NameStream.str();
    ofstream file6(dat6Name.c_str());

    std::ostringstream dat7NameStream(cPath);
    dat7NameStream<<cPath<<"/dispersioncl.txt";
    std::string dat7Name = dat7NameStream.str();
    ofstream file7(dat7Name.c_str());

    std::ostringstream dat8NameStream(cPath);
    dat8NameStream<<cPath<<"/atmospherecl.txt";
    std::string dat8Name = dat8NameStream.str();
    ofstream file8(dat8Name.c_str());

    std::ostringstream dat9NameStream(cPath);
    dat9NameStream<<cPath<<"/overallcl.txt";
    std::string dat9Name = dat9NameStream.str();
    ofstream file9(dat9Name.c_str());

    std::ostringstream dat10NameStream(cPath);
    dat10NameStream<<cPath<<"/signalcl.txt";
    std::string dat10Name = dat10NameStream.str();
    ofstream file10(dat10Name.c_str());

    std::ostringstream dat11NameStream(cPath);
    dat11NameStream<<cPath<<"/telescopecl.txt";
    std::string dat11Name = dat11NameStream.str();
    ofstream file11(dat11Name.c_str());

    std::ostringstream dat12NameStream(cPath);
    dat12NameStream<<cPath<<"/gratingcl.txt";
    std::string dat12Name = dat12NameStream.str();
    ofstream file12(dat12Name.c_str());

    std::ostringstream dat13NameStream(cPath);
    dat13NameStream<<cPath<<"/neoncl.txt";
    std::string dat13Name = dat13NameStream.str();
    ofstream file13(dat13Name.c_str());

    std::ostringstream dat14NameStream(cPath);
    dat14NameStream<<cPath<<"/surfacescl.txt";
    std::string dat14Name = dat14NameStream.str();
    ofstream file14(dat14Name.c_str());

    std::ostringstream dat15NameStream(cPath);
    dat15NameStream<<cPath<<"/balmercl.txt";
    std::string dat15Name = dat15NameStream.str();
    ofstream file15(dat15Name.c_str());

    std::ostringstream dat16NameStream(cPath);
    dat16NameStream<<cPath<<"/twopixRcl.txt";
    std::string dat16Name = dat16NameStream.str();
    ofstream file16(dat16Name.c_str());


    // read data from TSI
    QFile tsifile("tsi.txt");
    if(tsifile.exists()){

        classical::ReadTSI();

    }


    CCDTcl=2897.8/CCDwcl*1000;
    CCDmcl = 1.87088e19/(CCDwcl*CCDwcl*CCDwcl*CCDwcl*CCDwcl)/(exp(14387750/CCDwcl/CCDTcl)-1);

    dcl=cos(M_PI/180*thetacl)/gcl;

    acl = asin(ncl*lcl/1000000*gcl/(2*cos(M_PI/180*tcl/2)))*180/M_PI+tcl/2;
    bcl = acl-tcl;

    atcl = sin(M_PI/180*(acl-thetacl));
    double  bmcl, reflectance=1, Iabsor;

    scl=ui->doubleSpinBox_22->value();

    std::ostringstream dat17NameStream(cPath);
    dat17NameStream<<cPath<<"/neon_line.txt";
    std::string dat17Name = dat17NameStream.str();
    ifstream input(dat17Name.c_str());

    QFile checkfile6(dat17Name.c_str());

    if(!checkfile6.exists()){
        QMessageBox::information(this, "Error", "Neon line list "+checkfile6.fileName()+" not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    int number_of_lines =0;

    while(std::getline(input, zeile))
       ++ number_of_lines;

    input.clear();
    input.seekg(0, ios::beg);

    QVector<double> a(number_of_lines), b(number_of_lines);
    emi.resize(number_of_lines);

    for (int i=0; i<number_of_lines; i++){
    input >> one >>two;
    istringstream ist(one);
    ist >> a[i];
    istringstream ist2(two);
    ist2 >> b[i];
    }
    input.close();

    std::ostringstream dat18NameStream(cPath);
    dat18NameStream<<cPath<<"/absor_line.txt";
    std::string dat18Name = dat18NameStream.str();
    ifstream input1(dat18Name.c_str());

    QFile checkfile7(dat18Name.c_str());

    if(!checkfile7.exists()){
        QMessageBox::information(this, "Error", "Balmer line list "+checkfile7.fileName()+" not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    int number_of_lines_1 =0;

    while(std::getline(input1, zeile))
       ++ number_of_lines_1;

    input1.clear();
    input1.seekg(0, ios::beg);

    QVector<double> c(number_of_lines_1), d(number_of_lines_1);
    absor.resize(number_of_lines_1);

    for (int i=0; i<number_of_lines_1; i++){
    input1 >> one >>two;
    istringstream ist3(one);
    ist3 >> c[i];
    istringstream ist4(two);
    ist4 >> d[i];
    }
    input1.close();


    for(int i=0; i<lxcl/Bxcl; i++){

        bmcl = atan((lxcl/2-i)*pcl/f2cl)*180/M_PI;
        wcl[i] = (sin(M_PI/180*acl)+sin(M_PI/180*(bcl-bmcl)))/(ncl*gcl);

        if(alcl>0){
        if(i==0){
            for (int n=0; n<bini; n++){
                if((alclw[n]>wcl[i]*1000) &(alclw[n+1]<wcl[i]*1000)){
                    alclt[i]=alcli[n+1]+(wcl[i]*1000-alclw[n+1])/(alclw[n]-alclw[n+1])*(alcli[n]-alcli[n+1]);
                    aalcl=n;
                }
            }
        }
        else{
            for(int n=aalcl-2; n<aalcl+3; n++){
                if((alclw[n]>wcl[i]*1000) &(alclw[n+1]<wcl[i]*1000)){
                    alclt[i]=alcli[n+1]+(wcl[i]*1000-alclw[n+1])/(alclw[n]-alclw[n+1])*(alcli[n]-alcli[n+1]);
                    aalcl=n;
                }
            }
        }
        alclt[i]=pow(alclt[i]/100,alcl);
        reflectance=reflectance*alclt[i];
        }

        if(aluvcl>0){
        if(i==0){
            for (int n=0; n<bini2; n++){
                if((aluvclw[n]>wcl[i]*1000) &(aluvclw[n+1]<wcl[i]*1000)){
                    aluvclt[i]=aluvcli[n+1]+(wcl[i]*1000-aluvclw[n+1])/(aluvclw[n]-aluvclw[n+1])*(aluvcli[n]-aluvcli[n+1]);
                    aaluvcl=n;
                }
            }
        }
        else{
            for(int n=aaluvcl-2; n<aaluvcl+3; n++){
                if((aluvclw[n]>wcl[i]*1000) &(aluvclw[n+1]<wcl[i]*1000)){
                    aluvclt[i]=aluvcli[n+1]+(wcl[i]*1000-aluvclw[n+1])/(aluvclw[n]-aluvclw[n+1])*(aluvcli[n]-aluvcli[n+1]);
                    aaluvcl=n;
                }
            }
        }
        aluvclt[i]=pow(aluvclt[i]/100,aluvcl);
        reflectance=reflectance*aluvclt[i];
        }

        if(agcl>0){
        if(i==0){
            for (int n=0; n<bini3; n++){
                if((agclw[n]>wcl[i]*1000) &(agclw[n+1]<wcl[i]*1000)){
                    agclt[i]=agcli[n+1]+(wcl[i]*1000-agclw[n+1])/(agclw[n]-agclw[n+1])*(agcli[n]-agcli[n+1]);
                    aagcl=n;
                }
            }
        }
        else{
            for(int n=aagcl-2; n<aagcl+3; n++){
                if((agclw[n]>wcl[i]*1000) &(agclw[n+1]<wcl[i]*1000)){
                    agclt[i]=agcli[n+1]+(wcl[i]*1000-agclw[n+1])/(agclw[n]-agclw[n+1])*(agcli[n]-agcli[n+1]);
                    aagcl=n;
                }
            }
        }
        agclt[i]=pow(agclt[i]/100,agcl);
        reflectance=reflectance*agclt[i];
        }

        if(aucl>0){
        if(i==0){
            for (int n=0; n<bini4; n++){
                if((auclw[n]>wcl[i]*1000) &(auclw[n+1]<wcl[i]*1000)){
                    auclt[i]=aucli[n+1]+(wcl[i]*1000-auclw[n+1])/(auclw[n]-auclw[n+1])*(aucli[n]-aucli[n+1]);
                    aaucl=n;
                }
            }
        }
        else{
            for(int n=aaucl-2; n<aaucl+3; n++){
                if((auclw[n]>wcl[i]*1000) &(auclw[n+1]<wcl[i]*1000)){
                    auclt[i]=aucli[n+1]+(wcl[i]*1000-auclw[n+1])/(auclw[n]-auclw[n+1])*(aucli[n]-aucli[n+1]);
                    aaucl=n;
                }
            }
        }
        auclt[i]=pow(auclt[i]/100,aucl);
        reflectance=reflectance*auclt[i];
        }

        if(bbcl>0){
        if(i==0){
            for (int n=0; n<bini5; n++){
                if((bbclw[n]<wcl[i]*1000000) &(bbclw[n+1]>wcl[i]*1000000)){
                    bbclt[i]=bbcli[n]+(wcl[i]*1000000-bbclw[n])/(bbclw[n+1]-bbclw[n])*(bbcli[n+1]-bbcli[n]);
                    abbcl=n;
                }
            }
        }
        else{
            for(int n=abbcl-2; n<abbcl+3; n++){
                if((bbclw[n]<wcl[i]*1000000) &(bbclw[n+1]>wcl[i]*1000000)){
                    bbclt[i]=bbcli[n]+(wcl[i]*1000000-bbclw[n])/(bbclw[n+1]-bbclw[n])*(bbcli[n+1]-bbcli[n]);
                    abbcl=n;
                }
            }
        }
        bbclt[i]=pow((100-bbclt[i])/100,bbcl);
        reflectance=reflectance*bbclt[i];
        }

        Acl[i] = cos(M_PI/180*acl)/cos(M_PI/180*(bcl-bmcl));
        Rcl[i] = wcl[i]*ncl*f1cl*gcl/(cos(M_PI/180*acl)*scl*Acl[i]);

        s2cl[i] = Acl[i] * f2cl/f1cl*scl;
        Nfcl[i] = s2cl[i]/pcl/2;
        Trcl[i] = 1-0.0091224/cos(M_PI/180*zcl)/(pow(wcl[i]*1000,4));
        Dcl[i] = pcl*Bxcl*cos((bcl-bmcl)*M_PI/180)/(f2cl*ncl*gcl);
        wcl[i]=wcl[i]*10000000;
        Pcl[i] = Trcl[i]*dtelcl*dtelcl/400*M_PI*apcl/(wcl[i]*wcl[i]*wcl[i]*wcl[i])/(exp(kcl/Tcl/wcl[i])-1)*pow(10,-0.4*(vmcl-BCcl))/(pow(Tcl,4)*1.986e-11);
        CCDcl[i] = apcl/(pow(wcl[i],5))/(exp(143877500/wcl[i]/CCDTcl)-1)/CCDmcl*CCDpcl;
        wcl[i]=wcl[i]/10000000;


        b1cl = asin(ncl*wcl[i]*gcl-sin(M_PI/180*acl))*180/M_PI;
        btcl = sin(M_PI/180*(b1cl-thetacl));

        Il1cl = sin(M_PI*dcl/wcl[i]*(atcl+btcl));
        Il2cl = M_PI*dcl/wcl[i]*(atcl+btcl);
        I1cl[i] = etacl*Il1cl*Il1cl/Il2cl/Il2cl;

        Efcl[i]=I1cl[i]*CCDcl[i]*reflectance*slitEffcl;

        for (int e=0; e < number_of_lines; e++){
                        emi[e] = exp(-2.77254*pcl*pcl/s2cl[i]/s2cl[i]/2*pow((a[e]-wcl[i]*10000000),2))*b[e];
                        }

                    for (int e=0; e < number_of_lines; e++){
                        Ineon += emi[e];
                        }

                    for (int e=0; e < number_of_lines_1; e++){
                                    absor[e] = 1-number_of_lines_1*exp(-2.77254*pcl*pcl/s2cl[i]/s2cl[i]/2*pow((c[e]-wcl[i]*10000000),2))*d[e];
                                    }

                                for (int e=0; e < number_of_lines_1; e++){
                                    Iabsor += absor[e]/number_of_lines_1;
                                    }
                                Iabsor=Iabsor*Efcl[i];


        file1<<wcl[i]*1000000<<" "<<Efcl[i]<<endl;
        file2<<wcl[i]*1000000<<" "<<CCDcl[i]<<endl;
        file3<<wcl[i]*1000000<<" "<<Acl[i]<<endl;
        file4<<wcl[i]*1000000<<" "<<Nfcl[i]<<endl;
        file5<<wcl[i]*1000000<<" "<<s2cl[i]<<endl;
        file6<<wcl[i]*1000000<<" "<<Rcl[i]<<endl;
        file7<<wcl[i]*1000000<<" "<<Dcl[i]*1000000<<endl;
        file8<<wcl[i]*1000000<<" "<<Trcl[i]<<endl;
        Efcl[i]=Efcl[i]*Trcl[i];
        file9<<wcl[i]*1000000<<" "<<Efcl[i]<<endl;
        Efcl[i]=Efcl[i]*Pcl[i]/Trcl[i]*exptimecl;
        file10<<wcl[i]*1000000<<" "<<Efcl[i]<<endl;
        file11<<wcl[i]*1000000<<" "<<Pcl[i]<<endl;
        file12<<wcl[i]*1000000<<" "<<I1cl[i]<<endl;
        file13<<wcl[i]*1000000<<" "<<Ineon<<endl;
        file16<<wcl[i]*1000000<<" "<<wcl[i]/2/Dcl[i]<<endl;
        Ineon=0;
        file14<<wcl[i]*1000000<<" "<<reflectance<<endl;
        reflectance=1;
        file15<<wcl[i]*1000000<<" "<<Iabsor<<endl;
        Iabsor=0;

        ui->progressBar->setValue((i+1)*100/(lxcl/Bxcl));
        qApp->processEvents(QEventLoop::AllEvents);
    }

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void classical::on_doubleSpinBox_7_valueChanged()
{
    lcl=ui->doubleSpinBox_7->value();
}

void classical::on_doubleSpinBox_8_valueChanged()
{
    Tcl=ui->doubleSpinBox_8->value();

    if (log10(Tcl)<4){
         BCcl = -64741.46+67717*log10(Tcl)-26566.141*log10(Tcl)*log10(Tcl)+4632.926*log10(Tcl)*log10(Tcl)*log10(Tcl)-303.0307*log10(Tcl)*log10(Tcl)*log10(Tcl)*log10(Tcl);
         }
         else {
              BCcl = -888.82+884.69*log10(Tcl)-326.85*log10(Tcl)*log10(Tcl)+53.4*log10(Tcl)*log10(Tcl)*log10(Tcl)-3.2744*log10(Tcl)*log10(Tcl)*log10(Tcl)*log10(Tcl);
              }

    ui->doubleSpinBox_9->setValue(BCcl);
}

void classical::on_doubleSpinBox_10_valueChanged()
{
    vmcl=ui->doubleSpinBox_10->value();
}

void classical::on_doubleSpinBox_11_valueChanged()
{
    zcl=ui->doubleSpinBox_11->value();
}

void classical::on_doubleSpinBox_12_valueChanged()
{
    etacl=ui->doubleSpinBox_12->value();
}


void classical::on_doubleSpinBox_13_valueChanged()
{
    seeingcl=ui->doubleSpinBox_13->value();
    sdisccl=tan(M_PI/180*seeingcl/3600)*ftelcl;
}

void classical::on_doubleSpinBox_14_valueChanged()
{
    ftelcl=ui->doubleSpinBox_14->value();
    skyslitcl=atan(scl/ftelcl)*3600*180/M_PI;
    QString Output=QString::number(skyslitcl);
    ui->lineEdit_10->setText(Output);
    sdisccl=tan(M_PI/180*seeingcl/3600)*ftelcl;
}

void classical::on_doubleSpinBox_15_valueChanged()
{
    dtelcl=ui->doubleSpinBox_15->value();
}

void classical::on_doubleSpinBox_16_valueChanged()
{
    exptimecl=ui->doubleSpinBox_16->value();
}


//*****************************************
// Frame
//*****************************************
void classical::on_pushButton_4_clicked()
{
    qCPath = ui->lineEdit_3->text();
    cPath = qCPath.toUtf8().constData();

    double ficl=0, fycl;
    int number_of_lines;
    string zeile, one, two;
    QVector<double> a(1), b(1), emicl(1);
    send=1;
    classical::on_pushButton_3_clicked();
    send=0;

    // read data from TSI
    QFile tsifile("tsi.txt");
    if(tsifile.exists()){

        sdisccl=fibredcl/1000;

    }
    else{
        distycl=0;
        slicescl=1;
        distxcl=0;
    }

    this->setCursor(QCursor(Qt::WaitCursor));

    //Planck
        if(ui->comboBox->currentIndex()==0){

            std::ostringstream datNameStream(cPath);
            datNameStream<<cPath<<"/planckfcl.txt";
            std::string datName = datNameStream.str();
            ofstream framecl(datName.c_str());

            for(int i=0; i<lxcl/Bxcl; i++){
            for(int m=0; m<lycl/Bycl; m++){

                if(slicescl % 2==0){
                for(int n=0; n<slicescl/2; n++){
                ficl+=Efcl[i]*exp(-2.77254*pow((lycl/Bycl/2-m+distycl*(n+0.5)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                ficl+=Efcl[i]*exp(-2.77254*pow((lycl/Bycl/2-m-distycl*(n+0.5)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                    }
                }
                else{
                    ficl=Efcl[i]*exp(-2.77254*pow((lycl/Bycl/2-m),2)/pow((sdisccl/pcl),2));
                    for(int n=0; n<(slicescl-1)/2; n++){
                    ficl+=Efcl[i]*exp(-2.77254*pow((lycl/Bycl/2-m+distycl*(n+1)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                    ficl+=Efcl[i]*exp(-2.77254*pow((lycl/Bycl/2-m-distycl*(n+1)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                }}
                framecl<<i<<" "<<m<<" "<<ficl<<endl;
                ficl=0;
                }
            ui->progressBar->setValue((i+1)*100/(lxcl/Bxcl));
            qApp->processEvents(QEventLoop::AllEvents);
             }
    }

    // Balmer
     if(ui->comboBox->currentIndex()==1){

         std::ostringstream dat2NameStream(cPath);
         dat2NameStream<<cPath<<"/absor_line.txt";
         std::string dat2Name = dat2NameStream.str();
         ifstream input(dat2Name.c_str());

         number_of_lines =0;

         while(std::getline(input, zeile))
            ++ number_of_lines;

         input.clear();
         input.seekg(0, ios::beg);

         a.resize(number_of_lines);
         b.resize(number_of_lines);
         emicl.resize(number_of_lines);

         for (int i=0; i<number_of_lines; i++){
         input >> one >>two;
         istringstream ist(one);
         ist >> a[i];
         istringstream ist2(two);
         ist2 >> b[i];
         }
         input.close();

         fycl=0;

         std::ostringstream dat3NameStream(cPath);
         dat3NameStream<<cPath<<"/balmerfcl.txt";
         std::string dat3Name = dat3NameStream.str();
         ofstream framecl(dat3Name.c_str());

         for(int i=0; i<lxcl/Bxcl; i++){

             for(int e=0; e<number_of_lines; e++){
             emicl[e]=1-number_of_lines*b[e]*exp(-2.77254*pow((a[e]-wcl[i]*10000000),2)/pow((s2cl[i]/pcl),2));
             }

             for(int e=0; e<number_of_lines; e++){
             ficl+=emicl[e];
             }
             ficl=ficl*Efcl[i];

             for(int m=0; m<lycl/Bycl; m++){

                 if(slicescl % 2==0){
                 for(int n=0; n<slicescl/2; n++){
                 fycl+=exp(-2.77254*pow((lycl/Bycl/2-m+distycl*(n+0.5)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                 fycl+=exp(-2.77254*pow((lycl/Bycl/2-m-distycl*(n+0.5)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                     }
                 }
                 else{
                     fycl=exp(-2.77254*pow((lycl/Bycl/2-m),2)/pow((sdisccl/pcl),2));
                     for(int n=0; n<(slicescl-1)/2; n++){
                     fycl+=exp(-2.77254*pow((lycl/Bycl/2-m+distycl*(n+1)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                     fycl+=exp(-2.77254*pow((lycl/Bycl/2-m-distycl*(n+1)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                 }}
                 framecl<<i<<" "<<m<<" "<<ficl*fycl<<endl;
                 fycl=0;
                 }
             ficl=0;

             ui->progressBar->setValue((i+1)*100/(lxcl/Bxcl));
             qApp->processEvents(QEventLoop::AllEvents);
         }
}
     // Neon
      if(ui->comboBox->currentIndex()==2){

          std::ostringstream dat4NameStream(cPath);
          dat4NameStream<<cPath<<"/neon_line.txt";
          std::string dat4Name = dat4NameStream.str();
          ifstream input(dat4Name.c_str());

          number_of_lines =0;

          while(std::getline(input, zeile))
             ++ number_of_lines;

          input.clear();
          input.seekg(0, ios::beg);

          a.resize(number_of_lines);
          b.resize(number_of_lines);
          emicl.resize(number_of_lines);

          for (int i=0; i<number_of_lines; i++){
          input >> one >>two;
          istringstream ist(one);
          ist >> a[i];
          istringstream ist2(two);
          ist2 >> b[i];
          }
          input.close();

          fycl=0;
          ficl=0;

          std::ostringstream dat5NameStream(cPath);
          dat5NameStream<<cPath<<"/neonfcl.txt";
          std::string dat5Name = dat5NameStream.str();
          ofstream framecl(dat5Name.c_str());

          for(int i=0; i<lxcl/Bxcl; i++){
              for(int e=0; e<number_of_lines; e++){
              emicl[e]=b[e]*exp(-2.77254*pow((a[e]-wcl[i]*10000000),2)/pow((s2cl[i]/pcl),2));
              }

              for(int e=0; e<number_of_lines; e++){
              ficl+=emicl[e];
              }
              ficl=ficl*Efcl[i];

              for(int m=0; m<lycl/Bycl; m++){

                  if(slicescl % 2==0){
                  for(int n=0; n<slicescl/2; n++){
                  fycl+=exp(-2.77254*pow((lycl/Bycl/2-m+distycl*(n+0.5)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                  fycl+=exp(-2.77254*pow((lycl/Bycl/2-m-distycl*(n+0.5)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                      }
                  }
                  else{
                      fycl=exp(-2.77254*pow((lycl/Bycl/2-m),2)/pow((sdisccl/pcl),2));
                      for(int n=0; n<(slicescl-1)/2; n++){
                      fycl+=exp(-2.77254*pow((lycl/Bycl/2-m+distycl*(n+1)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                      fycl+=exp(-2.77254*pow((lycl/Bycl/2-m-distycl*(n+1)/pcl/Bycl),2)/pow((sdisccl/pcl/Bycl),2));
                  }}
                  framecl<<i<<" "<<m<<" "<<ficl*fycl<<endl;
                  fycl=0;
                  }
              ficl=0;

              ui->progressBar->setValue((i+1)*100/(lxcl/Bxcl));
              qApp->processEvents(QEventLoop::AllEvents);
      }
}

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void classical::on_doubleSpinBox_17_valueChanged()
{
    gcl=ui->doubleSpinBox_17->value();
    dcl=cos(M_PI/180*thetacl)/gcl;
}

void classical::on_doubleSpinBox_18_valueChanged()
{
    thetacl=ui->doubleSpinBox_18->value();
    dcl=cos(M_PI/180*thetacl)/gcl;
}

void classical::on_spinBox_10_valueChanged()
{
    ncl=ui->spinBox_10->value();
}

void classical::on_doubleSpinBox_19_valueChanged()
{
    tcl=ui->doubleSpinBox_19->value();

    acl = asin(ncl*lcl/1000000*gcl/(2*cos(M_PI/180*tcl/2)))*180/M_PI+tcl/2;
    bcl = acl-tcl;
}

void classical::on_doubleSpinBox_20_valueChanged()
{
    f1cl=ui->doubleSpinBox_20->value();
}

void classical::on_doubleSpinBox_21_valueChanged()
{
    f2cl=ui->doubleSpinBox_21->value();
}

void classical::on_doubleSpinBox_22_valueChanged()
{
    scl=ui->doubleSpinBox_22->value();
    skyslitcl=atan(scl/ftelcl)*3600*180/M_PI;
    QString Output=QString::number(skyslitcl);
    ui->lineEdit_10->setText(Output);

    if(ui->checkBox_3->isChecked()){

        scl=sdisccl;
    }
    else{
         scl=ui->doubleSpinBox_22->value();
    }
}

void classical::on_doubleSpinBox_23_valueChanged()
{
    slcl=ui->doubleSpinBox_23->value();
}

void classical::setvaluescl(){
    gcl=variablescl[0];
    ui->doubleSpinBox_17->setValue(gcl);

    ncl=variablescl[1];
    ui->spinBox_10->setValue(ncl);

    thetacl=variablescl[2];
    ui->doubleSpinBox_18->setValue(thetacl);

    tcl=variablescl[5];
    ui->doubleSpinBox_19->setValue(tcl);

    f1cl=variablescl[6];
    ui->doubleSpinBox_20->setValue(f1cl);

    f2cl=variablescl[7];
    ui->doubleSpinBox_21->setValue(f2cl);

    scl=variablescl[8];
    ui->doubleSpinBox_22->setValue(scl);

    slcl=variablescl[9];
    ui->doubleSpinBox_23->setValue(slcl);

    slitEffcl=variablescl[10];

    ftelcl=variablescl[13];
    ui->doubleSpinBox_14->setValue(ftelcl);

    dtelcl=variablescl[14];
    ui->doubleSpinBox_15->setValue(dtelcl);

    skyslitcl=atan(scl/ftelcl)*3600*180/M_PI;
    QString Output=QString::number(skyslitcl);
    ui->lineEdit_10->setText(Output);

    seeingcl=variablescl[12];
    ui->doubleSpinBox_13->setValue(seeingcl);

    sdisccl=tan(M_PI/180*seeingcl/3600)*ftelcl;

    pcl=variablescl[15];
    ui->doubleSpinBox->setValue(pcl);

    lxcl=variablescl[16];
    ui->spinBox_3->setValue(lxcl);

    lycl=variablescl[7];
    ui->spinBox_4->setValue(lycl);

    Bxcl=variablescl[18];
    ui->spinBox->setValue(Bxcl);

    Bycl=variablescl[19];
    ui->spinBox_2->setValue(Bycl);

    biascl=variablescl[20];
    ui->doubleSpinBox_2->setValue(biascl);

    noisecl=variablescl[21];
    ui->doubleSpinBox_3->setValue(noisecl);

    CCDwcl=variablescl[23];
    ui->doubleSpinBox_4->setValue(CCDwcl);

    CCDpcl=variablescl[24];
    ui->doubleSpinBox_5->setValue(CCDpcl);

    gaincl=variablescl[22];
    ui->doubleSpinBox_6->setValue(gaincl);

    lcl=variablescl[4];
    ui->doubleSpinBox_7->setValue(lcl);

    CCDTcl=2897.8/CCDwcl*1000;
    CCDmcl = 1.87088e19/(CCDwcl*CCDwcl*CCDwcl*CCDwcl*CCDwcl)/(exp(14387750/CCDwcl/CCDTcl)-1);

    dcl=cos(M_PI/180*thetacl)/gcl;

    Tcl=variablescl[25];
    ui->doubleSpinBox_8->setValue(Tcl);

    BCcl=variablescl[26];

    vmcl=variablescl[27];
    ui->doubleSpinBox_10->setValue(vmcl);

    zcl=variablescl[28];
    ui->doubleSpinBox_11->setValue(zcl);

    etacl=variablescl[3];
    ui->doubleSpinBox_12->setValue(etacl);

    exptimecl=variablescl[29];
    ui->doubleSpinBox_16->setValue(exptimecl);

    agcl=variablescl[30];
    ui->spinBox_5->setValue(agcl);

    alcl=variablescl[31];
    ui->spinBox_6->setValue(alcl);

    aluvcl=variablescl[32];
    ui->spinBox_7->setValue(aluvcl);

    aucl=variablescl[33];
    ui->spinBox_8->setValue(aucl);

    bbcl=variablescl[34];
    ui->spinBox_9->setValue(bbcl);
}


// Save
void classical::on_pushButton_5_clicked()
{
    qCPath = ui->lineEdit_3->text();
    cPath = qCPath.toUtf8().constData();

    QString qSavecl = ui->lineEdit->text()+".clconf";
    string savecl = qSavecl.toUtf8().constData();
    std::ostringstream datNameStream(savecl);
    datNameStream<<cPath<<"/"<<savecl;
    std::string datName = datNameStream.str();
    ofstream file(datName.c_str());

    file<<gcl<<endl;
    file<<ncl<<endl;
    file<<thetacl<<endl;
    file<<etacl<<endl;
    file<<lcl<<endl;
    file<<tcl<<endl;
    file<<f1cl<<endl;
    file<<f2cl<<endl;
    file<<scl<<endl;
    file<<slcl<<endl;
    file<<slitEffcl<<endl;
    file<<skyslitcl<<endl;
    file<<seeingcl<<endl;
    file<<ftelcl<<endl;
    file<<dtelcl<<endl;
    file<<pcl<<endl;
    file<<lxcl<<endl;
    file<<lycl<<endl;
    file<<Bxcl<<endl;
    file<<Bycl<<endl;
    file<<biascl<<endl;
    file<<noisecl<<endl;
    file<<gaincl<<endl;
    file<<CCDwcl<<endl;
    file<<CCDpcl<<endl;
    file<<Tcl<<endl;
    file<<BCcl<<endl;
    file<<vmcl<<endl;
    file<<zcl<<endl;
    file<<exptimecl<<endl;
    file<<agcl<<endl;
    file<<alcl<<endl;
    file<<aluvcl<<endl;
    file<<aucl<<endl;
    file<<bbcl<<endl;

    file.close();
}

//Load
void classical::on_pushButton_6_clicked()
{
    qCPath = ui->lineEdit_3->text();
    cPath = qCPath.toUtf8().constData();

    QString qLoadcl = ui->lineEdit_2->text()+".clconf";
    string loadcl = qLoadcl.toUtf8().constData();
    std::ostringstream datNameStream(loadcl);
    datNameStream<<cPath<<"/"<<loadcl;
    std::string datName = datNameStream.str();
    ifstream file(datName.c_str());

    QFile checkfile(datName.c_str());

    if(!checkfile.exists()){
        QMessageBox::information(this, "Error", "File is not available!");
        this->setCursor(QCursor(Qt::ArrowCursor));
       return;
    }

    string eins;

    for(int i=0; i<varcl; i++){
        file >> eins;
        istringstream str(eins);
        str>> variablescl[i];
    }

    file.close();

    setvaluescl();

}

void classical::on_spinBox_5_valueChanged()
{
    agcl=ui->spinBox_5->value();
}

void classical::on_spinBox_6_valueChanged()
{
    alcl=ui->spinBox_6->value();
}

void classical::on_spinBox_7_valueChanged()
{
    aluvcl=ui->spinBox_7->value();
}

void classical::on_spinBox_8_valueChanged()
{
    aucl=ui->spinBox_8->value();
}

void classical::on_spinBox_9_valueChanged()
{
    bbcl=ui->spinBox_9->value();
}

void classical::ReadTSI()
{
    ifstream tsif("tsi.txt");

    string one;

    int tsiv=5;
    double tsivec[tsiv];

    for(int i=0; i<tsiv; i++){
    tsif >> one;
    istringstream tsi1(one);
    tsi1 >> tsivec[i];
    }
    distycl=tsivec[4]/1000;
    distxcl=tsivec[3]/1000;
    fibredcl=tsivec[2];
    slicescl=tsivec[1];

    scl=fibredcl/slicescl/1000;

}
