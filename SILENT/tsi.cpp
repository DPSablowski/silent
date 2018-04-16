#include "tsi.h"
#include "ui_tsi.h"
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

int slices, distx, disty, in, widt, heigh, magni, fibred, rs, ys, xs;

TSI::TSI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TSI)
{
    ui->setupUi(this);
    this->setWindowTitle("Telescope-Spectrograph-Interface");

    ui->spinBox->setValue(2);
    magni=ui->spinBox->value();

    ui->spinBox_2->setValue(2);
    slices=ui->spinBox_2->value();

    ui->spinBox_5->setValue(50);
    fibred=ui->spinBox_5->value();

    ui->spinBox_3->setValue(0);
    distx=ui->spinBox_3->value();

    ui->spinBox_4->setValue(100);
    disty=ui->spinBox_4->value();


    ui->comboBox->addItem("None");
    ui->comboBox->addItem("Bowen-Walraven");
    ui->comboBox->addItem("Waveguide");

    ui->customPlot->axisRect()->setupFullAxesBox(true);

}

TSI::~TSI()
{
    delete ui;
}

void TSI::on_pushButton_2_clicked()
{

    ui->customPlot->clearPlottables();
    ofstream file1("slicer.txt");

    // no slicer
    if(ui->comboBox->currentIndex()==0){
        QMessageBox::information(this, "No Slicer", "No Slicer has been selected.");
        return;
    }

    in=fibred*magni;
    widt=in/slices;
    rs=in/2;
    int size;
    heigh=disty*(slices-1)+in;
    size=heigh;

    //Bowen-Walraven
    if(ui->comboBox->currentIndex()==1){

        //distx=0;//distx*size/widt;
        //disty=disty/2;//20;//disty*size/widt;
        int counter=0;

        ui->customPlot->addGraph();
        ui->customPlot->xAxis->setLabel("x [um]");
        ui->customPlot->yAxis->setLabel("y [um]");

        // set up the QCPColorMap:
        QCPColorMap *colorMap = new QCPColorMap(ui->customPlot->xAxis, ui->customPlot->yAxis);
        ui->customPlot->addPlottable(colorMap);
        colorMap->data()->setSize(size, size); // we want the color map to have nx * ny data points
        colorMap->data()->setRange(QCPRange(-size/2, size/2), QCPRange(-size/2, size/2));

        if(slices==2){

      for(int i=0; i<size; i++){
          xs=heigh/size*i;
          for(int m=0; m<size; m++){
                ys=widt/size*m;
              if(sqrt(pow((i+distx/2-size/2),2)+pow((m-disty/2-size/2),2))<=rs & (i>size/2-rs-distx/2&i<size/2-distx/2) or (sqrt(pow((i-distx/2-size/2),2)+pow((m+disty/2-size/2),2))<=rs) & i>size/2+distx/2&i<size/2+rs+distx/2){
                  file1<<1<<" ";
                  colorMap->data()->setCell(i, m, 1);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

              else{
                  file1<<0<<" ";
                  colorMap->data()->setCell(i, m, 0);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

          }

          file1<<endl;
      }}

        if(slices==3){

      for(int i=0; i<size; i++){
          xs=heigh/size*i;
          for(int m=0; m<size; m++){
                ys=widt/size*m;
              if(sqrt(pow((i-size/2),2)+pow((m-size/2),2))<=rs&i>size/2-rs/3&i<size/2+rs/3 or sqrt(pow((i+distx-size/2),2)+pow((m-disty-size/2),2))<=rs&i>size/2-rs-distx&i<size/2-rs/3-distx or sqrt(pow((i-distx-size/2),2)+pow((m+disty-size/2),2))<=rs&i>size/2+rs/3+distx&i<size/2+rs+distx){
                file1<<1<<" ";
                  colorMap->data()->setCell(i, m, 1);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

              else{
                  file1<<0<<" ";
                  colorMap->data()->setCell(i, m, 0);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

          }

          file1<<endl;
      }}


        if(slices==4){

      for(int i=0; i<size; i++){
          xs=heigh/size*i;
          for(int m=0; m<size; m++){
                ys=widt/size*m;
              if(sqrt(pow((i-size/2+distx*1.5),2)+pow((m-size/2-disty*1.5),2))<=rs&i>size/2-rs-distx*1.5&i<size/2-rs/2-distx*1.5 or sqrt(pow((i-size/2-distx*1.5),2)+pow((m-size/2+disty*1.5),2))<=rs&i>size/2+rs/2+distx*1.5&i<size/2+rs+distx*1.5 or sqrt(pow((i-size/2+distx/2),2)+pow((m-size/2-disty/2),2))<=rs&i>size/2-rs/2-distx/2&i<size/2-distx/2 or sqrt(pow((i-size/2-distx/2),2)+pow((m-size/2+disty/2),2))<=rs&i>size/2+distx/2&i<size/2+rs/2+distx/2){
                file1<<1<<" ";
                  colorMap->data()->setCell(i, m, 1);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

              else{
                  file1<<0<<" ";
                  colorMap->data()->setCell(i, m, 0);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

          }

          file1<<endl;
      }}

        if(slices==5){

      for(int i=0; i<size; i++){
          xs=heigh/size*i;
          for(int m=0; m<size; m++){
                ys=widt/size*m;
              if(sqrt(pow((i-size/2),2)+pow((m-size/2),2))<=rs&i>size/2-rs/5&i<size/2+rs/5 or sqrt(pow((i-size/2+distx),2)+pow((m-size/2-disty),2))<=rs&i>size/2-distx-3*rs/5&i<size/2-distx-rs/5 or sqrt(pow((i-size/2-distx),2)+pow((m-size/2+disty),2))<=rs&i<size/2+distx+3*rs/5&i>size/2+distx+rs/5 or sqrt(pow((i-size/2-2*distx),2)+pow((m-size/2+2*disty),2))<=rs&i>size/2+2*distx+3*rs/5&i<size/2+2*distx+rs or sqrt(pow((i-size/2+2*distx),2)+pow((m-size/2-2*disty),2))<=rs&i<size/2-2*distx-3*rs/5&i>size/2-2*distx-rs){
                file1<<1<<" ";
                  colorMap->data()->setCell(i, m, 1);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

              else{
                  file1<<0<<" ";
                  colorMap->data()->setCell(i, m, 0);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

          }

          file1<<endl;
      }}

        if(slices==6){

      for(int i=0; i<size; i++){
          xs=heigh/size*i;
          for(int m=0; m<size; m++){
                ys=widt/size*m;
              if(sqrt(pow((i-size/2+distx*2.5),2)+pow((m-size/2-disty*2.5),2))<=rs&i>size/2-rs-distx*2.5&i<size/2-2*rs/3-distx*2.5 or sqrt(pow((i-size/2-distx*2.5),2)+pow((m-size/2+disty*2.5),2))<=rs&i<size/2+rs+distx*2.5&i>size/2+2*rs/3+distx*2.5 or sqrt(pow((i-size/2+distx*1.5),2)+pow((m-size/2-disty*1.5),2))<=rs&i>size/2-2*rs/3-distx*1.5&i<size/2-rs/3-distx*1.5 or sqrt(pow((i-size/2-distx*1.5),2)+pow((m-size/2+disty*1.5),2))<=rs&i<size/2+2*rs/3+distx*1.5&i>size/2+rs/3+distx*1.5 or sqrt(pow((i-size/2-distx*0.5),2)+pow((m-size/2+disty*0.5),2))<=rs&i<size/2+rs/3+distx*0.5&i>size/2+distx*0.5 or sqrt(pow((i-size/2+distx*0.5),2)+pow((m-size/2-disty*0.5),2))<=rs&i>size/2-rs/3-distx*0.5&i<size/2-distx*0.5){
                file1<<1<<" ";
                  colorMap->data()->setCell(i, m, 1);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

              else{
                  file1<<0<<" ";
                  colorMap->data()->setCell(i, m, 0);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

          }

          file1<<endl;
      }}

        if(slices==7    ){

      for(int i=0; i<size; i++){
          xs=heigh/size*i;
          for(int m=0; m<size; m++){
                ys=widt/size*m;
              if(sqrt(pow((i-size/2),2)+pow((m-size/2),2))<=rs&i>size/2-rs/7&i<size/2+rs/7 or sqrt(pow((i-size/2+distx),2)+pow((m-size/2-disty),2))<=rs&i>size/2-distx-3*rs/7&i<size/2-distx-rs/7 or sqrt(pow((i-size/2-distx),2)+pow((m-size/2+disty),2))<=rs&i<size/2+distx+3*rs/7&i>size/2+distx+rs/7 or sqrt(pow((i-size/2-2*distx),2)+pow((m-size/2+2*disty),2))<=rs&i>size/2+2*distx+3*rs/7&i<size/2+2*distx+5*rs/7 or sqrt(pow((i-size/2-3*distx),2)+pow((m-size/2+3*disty),2))<=rs&i>size/2+3*distx+5*rs/7&i<size/2+3*distx+rs or sqrt(pow((i-size/2+2*distx),2)+pow((m-size/2-2*disty),2))<=rs&i<size/2-2*distx-3*rs/7&i>size/2-2*distx-5*rs/7 or sqrt(pow((i-size/2+3*distx),2)+pow((m-size/2-3*disty),2))<=rs&i<size/2-3*distx-5*rs/7&i>size/2-3*distx-rs){
                file1<<1<<" ";
                  colorMap->data()->setCell(i, m, 1);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

              else{
                  file1<<0<<" ";
                  colorMap->data()->setCell(i, m, 0);
                  counter++;
                  if(counter==size){
                      m=size;
                      counter=0;
                  }
              }

          }

          file1<<endl;
      }}

      colorMap->setGradient(QCPColorGradient::gpPolar);
      colorMap->rescaleDataRange();
      QCPMarginGroup *marginGroup = new QCPMarginGroup(ui->customPlot);
      ui->customPlot->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);
      ui->customPlot->rescaleAxes();
      ui->customPlot->replot();

    }

    //Waveguide
    if(ui->comboBox->currentIndex()==2){

    }
}

void TSI::on_spinBox_3_valueChanged()
{
    distx=ui->spinBox_3->value();
}

void TSI::on_spinBox_4_valueChanged()
{
    disty=ui->spinBox_4->value();
}

void TSI::on_spinBox_5_valueChanged()
{
    fibred=ui->spinBox_5->value();
}

void TSI::on_spinBox_valueChanged()
{
    magni=ui->spinBox->value();
}

void TSI::on_spinBox_2_valueChanged()
{
    slices=ui->spinBox_2->value();
}

void TSI::on_pushButton_3_clicked()
{
    ofstream file1("tsi.txt");

    file1<<ui->comboBox->currentIndex()<<endl;
    file1<<slices<<endl;
    file1<<fibred*magni<<endl;
    file1<<distx+fibred*magni/slices<<endl;
    file1<<disty<<endl;
}

void TSI::on_pushButton_4_clicked()
{
    remove("tsi.txt");
}
