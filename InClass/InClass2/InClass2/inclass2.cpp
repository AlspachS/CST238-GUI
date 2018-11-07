#include "inclass2.h"
#include "ui_inclass2.h"

InClass2::InClass2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::InClass2)
{
    ui->setupUi(this);
}

void InClass2::SetText()
{
    ui->checkBox_2->setText("This is a much longer string!");
}

InClass2::~InClass2()
{
    delete ui;
}
