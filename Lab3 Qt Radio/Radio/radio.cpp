#include "radio.h"
#include "ui_radio.h"

Radio::Radio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Radio)
{
    ui->setupUi(this);
    ui->preset_1->SetTuner(ui->tuner);
    ui->preset_2->SetTuner(ui->tuner);
    ui->preset_3->SetTuner(ui->tuner);
    ui->preset_4->SetTuner(ui->tuner);
    ui->preset_5->SetTuner(ui->tuner);
}

Radio::~Radio()
{
    delete ui;
}

