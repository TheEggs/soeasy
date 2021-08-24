#include "secondwin.h"
#include "ui_secondwin.h"

secondwin::secondwin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::secondwin)
{
    ui->setupUi(this);
}

secondwin::~secondwin()
{
    delete ui;
}


void secondwin::logged()
{
    this->show();
}
