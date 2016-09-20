#include "warning1.h"
#include "ui_warning1.h"

Warning1::Warning1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warning1)
{
    ui->setupUi(this);
}

Warning1::~Warning1()
{
    delete ui;
}
