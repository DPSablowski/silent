#include "pthreed.h"
#include "ui_pthreed.h"
#include <fstream>
#include <sstream>

using namespace std;

double x13d, x23d, y13d, y23d;

pthreed::pthreed(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pthreed)
{
    ui->setupUi(this);
    this->setWindowTitle("3D Spectrograph Parameters");
    ui->checkBox_15->setChecked(true);

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
    ui->comboBox->addItem("Layout");
    ui->comboBox->addItem("Neon Spectrum");
    ui->comboBox->addItem("Planck Spectrum");
    ui->comboBox->addItem("Balmer Spectrum");

    ui->customPlot->axisRect()->setupFullAxesBox(true);
}

pthreed::~pthreed()
{
    delete ui;
}

// find values
void pthreed::on_pushButton_2_clicked()
{
    string zeile, one, two;
    this->setCursor(QCursor(Qt::WaitCursor));

        if(ui->comboBox->currentIndex()==0){

            ifstream toplot1("resolving3d.txt");

            QFile checkfile3("resolving3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }

        if(ui->comboBox->currentIndex()==1){

            ifstream toplot1("twopixR3d.txt");

            QFile checkfile3("twopixR3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }

        if(ui->comboBox->currentIndex()==2){

            ifstream toplot1("dispersion3d.txt");

            QFile checkfile3("dispersion3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==3){

            ifstream toplot1("anamorphism3d.txt");

            QFile checkfile3("anamorphism3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==4){

            ifstream toplot1("nyquist3d.txt");

            QFile checkfile3("nyquist3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==5){

            ifstream toplot1("slit3d.txt");

            QFile checkfile3("slit3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==6){

            ifstream toplot1("atmosphere3d.txt");

            QFile checkfile3("atmosphere3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==7){

            ifstream toplot1("telescope3d.txt");

            QFile checkfile3("telescope3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==8){

            ifstream toplot1("ccd3d.txt");

            QFile checkfile3("ccd3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==9){

            ifstream toplot1("grating3d.txt");

            QFile checkfile3("grating3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==10){

            ifstream toplot1("efficiency3d.txt");

            QFile checkfile3("efficiency3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==11){

            ifstream toplot1("overall3d.txt");

            QFile checkfile3("overall3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==12){

            ifstream toplot1("surfaces3d.txt");

            QFile checkfile3("surfaces3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==13){

            ifstream toplot1("layout3d.txt");

            QFile checkfile3("layout3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }
        if(ui->comboBox->currentIndex()==14){

            ifstream toplot1("neon3d.txt");

            QFile checkfile3("neon3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }


        if(ui->comboBox->currentIndex()==15){

            ifstream toplot1("planck3d.txt");

            QFile checkfile3("planck3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }

        if(ui->comboBox->currentIndex()==16){

            ifstream toplot1("balmer3d.txt");

            QFile checkfile3("balmer3d.txt");

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

           x13d=a[0];
           x23d=a[0];
           y13d=b[0];
           y23d=b[0];
            for(int i=0; i<number_of_lines; i++){
                if(a[i]<x13d){
                    x13d=a[i];
                }
                if(a[i]>x23d){
                    x23d=a[i];
                }
                if(b[i]<y13d){
                    y13d=b[i];
                }
                if(b[i]>y23d){
                    y23d=b[i];
                }
            }
            ui->doubleSpinBox->setValue(x13d);
            ui->doubleSpinBox_2->setValue(x23d);
            ui->doubleSpinBox_3->setValue(y13d);
            ui->doubleSpinBox_4->setValue(y23d);
        }

    this->setCursor(QCursor(Qt::ArrowCursor));
}

void pthreed::on_pushButton_3_clicked()
{
    x13d=ui->doubleSpinBox->value();
    x23d=ui->doubleSpinBox_2->value();
    y13d=ui->doubleSpinBox_3->value();
    y23d=ui->doubleSpinBox_4->value();

    ui->customPlot->clearPlottables();

    string zeile, one, two;

    this->setCursor(QCursor(Qt::ArrowCursor));

    if(ui->comboBox->currentIndex()==0){

        ifstream toplot1("resolving3d.txt");

        QFile checkfile3("resolving3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==1){

        ifstream toplot1("twopixR3d.txt");

        QFile checkfile3("twopixR3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==2){

        ifstream toplot1("dispersion3d.txt");

        QFile checkfile3("dispersion3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }

    if(ui->comboBox->currentIndex()==3){

        ifstream toplot1("anamorphism3d.txt");

        QFile checkfile3("anamorphism3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==4){

        ifstream toplot1("nyquist3d.txt");

        QFile checkfile3("nyquist3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==5){

        ifstream toplot1("slit3d.txt");

        QFile checkfile3("slit3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==6){

        ifstream toplot1("atmosphere3d.txt");

        QFile checkfile3("atmosphere3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==7){

        ifstream toplot1("telescope3d.txt");

        QFile checkfile3("telescope3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==8){

        ifstream toplot1("ccd3d.txt");

        QFile checkfile3("ccd3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==9){

        ifstream toplot1("grating3d.txt");

        QFile checkfile3("grating3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==10){

        ifstream toplot1("efficiency3d.txt");

        QFile checkfile3("efficiency3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==11){

        ifstream toplot1("overall3d.txt");

        QFile checkfile3("overall3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==12){

        ifstream toplot1("surfaces3d.txt");

        QFile checkfile3("surfaces3d.txt");

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
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==13){

        ifstream toplot1("layout3d.txt");

        QFile checkfile3("layout3d.txt");

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
        ui->customPlot->xAxis->setLabel("Pixel x");
        ui->customPlot->yAxis->setLabel("Pixel y");
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==14){

        ifstream toplot1("neon3d.txt");

        QFile checkfile3("neon3d.txt");

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
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("rel. Intensity");
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==15){

        ui->customPlot->clearPlottables();

        ifstream toplot1("planck3d.txt");

        QFile checkfile3("planck3d.txt");

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
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("rel. Intensity");
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }
    if(ui->comboBox->currentIndex()==16){

        ifstream toplot1("balmer3d.txt");

        QFile checkfile3("balmer3d.txt");

        if(!checkfile3.exists()){
            QMessageBox::information(this, "Error", "Parameters not calculated.");
            this->setCursor(QCursor(Qt::ArrowCursor));
           return;
        }

        ui->customPlot->clearPlottables();

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
        ui->customPlot->xAxis->setLabel("Wavelength [nm]");
        ui->customPlot->yAxis->setLabel("re Intensity");
        ui->customPlot->xAxis->setRange(x13d, x23d);
        ui->customPlot->yAxis->setRange(y13d, y23d);
        ui->customPlot->replot();
    }

    this->setCursor(QCursor(Qt::ArrowCursor));
}


void pthreed::on_pushButton_4_clicked()
{
    QString save=ui->lineEdit->text();
    if(ui->checkBox_15->isChecked()){
    ui->customPlot->savePdf(save);
    }

    if(ui->checkBox_16->isChecked()){
    ui->customPlot->savePng(save);
    }
}

void pthreed::on_checkBox_15_clicked()
{
    ui->checkBox_16->setChecked(false);
}

void pthreed::on_checkBox_16_clicked()
{
    ui->checkBox_15->setChecked(false);
}

void pthreed::on_spinBox_valueChanged()
{
    QFont legendFont = font();
    legendFont.setPointSize(ui->spinBox->value());
    ui->customPlot->xAxis->setLabelFont(legendFont);
    ui->customPlot->yAxis->setLabelFont(legendFont);
    ui->customPlot->xAxis->setTickLabelFont(legendFont);
    ui->customPlot->yAxis->setTickLabelFont(legendFont);
}
