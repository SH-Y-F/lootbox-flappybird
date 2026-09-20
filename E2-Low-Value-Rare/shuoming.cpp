#include "shuoming.h"
#include "ui_shuoming.h"

Shuoming::Shuoming(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Shuoming)
{
    ui->setupUi(this);
}

Shuoming::~Shuoming()
{
    delete ui;
}

void Shuoming::on_pushButton_2_clicked()
{
    this->hide();
}

void Shuoming::slots_shuoming()
{
    this->show();
}
