#include "notes.h"
#include "ui_notes.h"

Notes::Notes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Notes)
{
    ui->setupUi(this);

    this->setWindowTitle("Notes");

}

Notes::~Notes()
{
    delete ui;
}
