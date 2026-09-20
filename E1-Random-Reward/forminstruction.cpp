#include "forminstruction.h"
#include "ui_forminstruction.h"

Forminstruction::Forminstruction(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Forminstruction)
{
    ui->setupUi(this);
}

Forminstruction::~Forminstruction()
{
    delete ui;
}

void Forminstruction::slots_int()
{
    this->show();
}

void Forminstruction::on_pushButton_clicked()
{
    this->hide();
}

