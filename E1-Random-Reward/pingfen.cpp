#include "pingfen.h"
#include "qdebug.h"
#include "ui_pingfen.h"
#include <QDebug>
#include <QDesktopWidget>
#include <QMessageBox>
#include <ctime>
#include <iostream>
#include <QPushButton>
#include <QDialog>
#include <QLabel>
#include<QRandomGenerator>
#include<QPropertyAnimation>
#include<QMovie>
#include<QVBoxLayout>
#include<QButtonGroup>
#include <QFile>
#include<Qtimer>

pingfen::pingfen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pingfen)
{
    ui->setupUi(this);
    ui->Slider->setMaximum(7);
    ui->Slider->setMinimum(1);
    ui->Slider->setPageStep(1);
    setWindowTitle(QObject::tr("评分"));
    setWindowFlag(Qt::WindowStaysOnTopHint,true);

}


pingfen::~pingfen()
{
    delete ui;
}

void pingfen::slots_pingfen1()
{
    QTimer::singleShot(3000,this,[this](){
    this->show();
    NTK = "大奖1:";
    });
}
void pingfen::slots_pingfen2()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "大奖2:";
    });
}
void pingfen::slots_pingfen3()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "大奖3:";
    });
}
void pingfen::slots_pingfen4()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "小奖1:";
    });
}
void pingfen::slots_pingfen5()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "小奖2:";
    });
}
void pingfen::slots_pingfen6()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "小奖3:";
    });

}
void pingfen::slots_pingfen7()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "小奖4:";
    });

}
void pingfen::slots_pingfen8()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "小奖5:";
    });

}
void pingfen::slots_pingfen9()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "小奖6:";
    });

}
void pingfen::slots_pingfen10()
{
    QTimer::singleShot(3000,this,[this](){
        this->show();
        NTK = "小奖7:";
    });

}
void pingfen::on_pushButton_clicked()
{
    int rating = ui->Slider->value();

    // Save the comment and rating to wherever you want
    QFile file("testee.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out <<NTK<< rating << endl;
        file.close();
    }
    // Close the dialog
    this->hide();
}

