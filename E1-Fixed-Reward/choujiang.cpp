#include "choujiang.h"
#include "qtimer.h"
#include "shuoming.h"
#include "ui_choujiang.h"
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
#include"mainwindow.h"
#include<QButtonGroup>


const QStringList imageList = {
    ":/Images/A1.png",
    ":/Images/A2.png",
    ":/Images/A3.png",
    ":/Images/A4.png",
    ":/Images/A5.png",
    ":/Images/A6.png",
    ":/Images/A7.png",
    ":/Images/A8.png",
    ":/Images/A9.png",
    ":/Images/A10.png",
    ":/Images/A11.png",
    ":/Images/A12.png",
    ":/Images/A13.png",
    ":/Images/A14.png",
    ":/Images/A15.png",
    ":/Images/A16.png",
    ":/Images/A17.png",
    ":/Images/A18.png",
    ":/Images/A19.png",
    ":/Images/A20.png",
    ":/Images/A21.png",
    ":/Images/A22.png",
    ":/Images/A23.png",
    ":/Images/A24.png",
    ":/Images/A25.png",
    ":/Images/A26.png",
    ":/Images/A27.png",
    ":/Images/A28.png",
    ":/Images/A29.png",
    ":/Images/A30.png",
    ":/Images/A31.png",
    ":/Images/A32.png",
    ":/Images/A33.png",
    ":/Images/A34.png",
    ":/Images/A35.png",
    ":/Images/A36.png",
    ":/Images/A37.png",
    ":/Images/A38.png",
    ":/Images/A39.png",
    ":/Images/A40.png",
    ":/Images/A41.png",
    ":/Images/A42.png",
    ":/Images/A43.png",
    ":/Images/A44.png",
    ":/Images/A45.png",
    ":/Images/A46.png",
    ":/Images/A47.png",
    ":/Images/A48.png",
    ":/Images/A49.png",
    ":/Images/A50.png",
    ":/Images/A51.png",
    ":/Images/A52.png",
    ":/Images/A53.png",
    ":/Images/A54.png",
    ":/Images/A55.png",
    ":/Images/A56.png",
    ":/Images/A57.png",
    ":/Images/A58.png",
    ":/Images/A59.png",
    ":/Images/A60.png",
    ":/Images/A61.png",
    ":/Images/A62.png",
    ":/Images/A63.png",
    ":/Images/A64.png",
    ":/Images/A65.png",
    ":/Images/A66.png",
    ":/Images/A67.png",
    ":/Images/A68.png",
    ":/Images/A69.png",
    ":/Images/A70.png",
    ":/Images/A71.png",
    ":/Images/A72.png",
    ":/Images/A73.png",
    ":/Images/A74.png",
    ":/Images/A75.png",
    ":/Images/A76.png",
    ":/Images/A77.png",
    ":/Images/A78.png",
    ":/Images/A79.png",
    ":/Images/A80.png",
    ":/Images/A81.png",
    ":/Images/A82.png",
    ":/Images/A83.png",
    ":/Images/A84.png",
};

    int CJmunber=0;
    int randNum=0;

choujiang::choujiang(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::choujiang)
    {
    m_pshuoming = new Shuoming;
    m_ppingfen1 = new pingfen;
    m_ppingfen2 = new pingfen;
    m_ppingfen3 = new pingfen;
    m_ppingfen4 = new pingfen;
    m_ppingfen5 = new pingfen;
    m_ppingfen6 = new pingfen;
    m_ppingfen7 = new pingfen;
    m_ppingfen8 = new pingfen;
    m_ppingfen9 = new pingfen;
    m_ppingfen10 = new pingfen;
    QObject::connect(this,&choujiang::emit_shuoming,m_pshuoming,&Shuoming::slots_shuoming);
    QObject::connect(this,&choujiang::emit_pingfen1,m_ppingfen1,&pingfen::slots_pingfen1);
    QObject::connect(this,&choujiang::emit_pingfen2,m_ppingfen2,&pingfen::slots_pingfen2);
    QObject::connect(this,&choujiang::emit_pingfen3,m_ppingfen3,&pingfen::slots_pingfen3);
    QObject::connect(this,&choujiang::emit_pingfen4,m_ppingfen4,&pingfen::slots_pingfen4);
    QObject::connect(this,&choujiang::emit_pingfen5,m_ppingfen5,&pingfen::slots_pingfen5);
    QObject::connect(this,&choujiang::emit_pingfen6,m_ppingfen6,&pingfen::slots_pingfen6);
    QObject::connect(this,&choujiang::emit_pingfen7,m_ppingfen7,&pingfen::slots_pingfen7);
    QObject::connect(this,&choujiang::emit_pingfen8,m_ppingfen8,&pingfen::slots_pingfen8);
    QObject::connect(this,&choujiang::emit_pingfen9,m_ppingfen9,&pingfen::slots_pingfen9);
    QObject::connect(this,&choujiang::emit_pingfen10,m_ppingfen10,&pingfen::slots_pingfen10);
    ui->setupUi(this);


    QButtonG =new QButtonGroup(this);
    QButtonG->addButton(ui->pb1);
    QButtonG->addButton(ui->pb2);
    QButtonG->addButton(ui->pb3);
    QButtonG->addButton(ui->pb4);
    QButtonG->addButton(ui->pb5);
    QButtonG->addButton(ui->pb6);
    QButtonG->addButton(ui->pb7);
    QButtonG->addButton(ui->pb8);
    QButtonG->addButton(ui->pb9);
    QButtonG->addButton(ui->pb10);
    QButtonG->addButton(ui->pb11);
    QButtonG->addButton(ui->pb12);
    QButtonG->addButton(ui->pb13);
    QButtonG->addButton(ui->pb14);
    QButtonG->addButton(ui->pb15);
    QButtonG->addButton(ui->pb16);
    QButtonG->addButton(ui->pb17);
    QButtonG->addButton(ui->pb18);
    QButtonG->addButton(ui->pb19);
    QButtonG->addButton(ui->pb20);
    QButtonG->addButton(ui->pb21);
    QButtonG->addButton(ui->pb22);
    QButtonG->addButton(ui->pb23);
    QButtonG->addButton(ui->pb24);
    QButtonG->addButton(ui->pb25);
    QButtonG->addButton(ui->pb26);
    QButtonG->addButton(ui->pb27);
    QButtonG->addButton(ui->pb28);
    QButtonG->addButton(ui->pb29);
    QButtonG->addButton(ui->pb30);
    QButtonG->addButton(ui->pb31);
    QButtonG->addButton(ui->pb32);
    QButtonG->addButton(ui->pb33);
    QButtonG->addButton(ui->pb34);
    QButtonG->addButton(ui->pb35);
    QButtonG->addButton(ui->pb36);
    QButtonG->addButton(ui->pb37);
    QButtonG->addButton(ui->pb38);
    QButtonG->addButton(ui->pb39);
    QButtonG->addButton(ui->pb40);
    QButtonG->addButton(ui->pb41);
    QButtonG->addButton(ui->pb42);
    QButtonG->addButton(ui->pb43);
    QButtonG->addButton(ui->pb44);
    QButtonG->addButton(ui->pb45);
    QButtonG->addButton(ui->pb46);
    QButtonG->addButton(ui->pb47);
    QButtonG->addButton(ui->pb48);
    QButtonG->addButton(ui->pb49);
    QButtonG->addButton(ui->pb50);
    QButtonG->addButton(ui->pb51);
    QButtonG->addButton(ui->pb52);
    QButtonG->addButton(ui->pb53);
    QButtonG->addButton(ui->pb54);
    QButtonG->addButton(ui->pb55);
    QButtonG->addButton(ui->pb56);
    QButtonG->addButton(ui->pb57);
    QButtonG->addButton(ui->pb58);
    QButtonG->addButton(ui->pb59);
    QButtonG->addButton(ui->pb60);
    QButtonG->addButton(ui->pb61);
    QButtonG->addButton(ui->pb62);
    QButtonG->addButton(ui->pb63);
    QButtonG->addButton(ui->pb64);
    QButtonG->addButton(ui->pb65);
    QButtonG->addButton(ui->pb66);
    QButtonG->addButton(ui->pb67);
    QButtonG->addButton(ui->pb68);
    QButtonG->addButton(ui->pb69);
    QButtonG->addButton(ui->pb70);
    QButtonG->addButton(ui->pb71);
    QButtonG->addButton(ui->pb72);
    QButtonG->addButton(ui->pb73);
    QButtonG->addButton(ui->pb74);
    QButtonG->addButton(ui->pb75);
    QButtonG->addButton(ui->pb76);
    QButtonG->addButton(ui->pb77);
    QButtonG->addButton(ui->pb78);
    QButtonG->addButton(ui->pb79);
    QButtonG->addButton(ui->pb80);
    QButtonG->addButton(ui->pb81);
    QButtonG->addButton(ui->pb82);
    QButtonG->addButton(ui->pb83);
    QButtonG->addButton(ui->pb84);


}
choujiang::~choujiang()
{
    delete ui;



}

void choujiang::showEvent(QShowEvent *event)
{
   onUpdateAB();
}

void choujiang::slots_choujiang()
{
    this->show();
}



void choujiang::on_startCJ_clicked(){

    ui->startCJ->setEnabled(false); // 禁用按钮
    QTimer::singleShot(3500, [&](){
        ui->startCJ->setEnabled(true); // 启用按钮
    });


    if(randNum>83)
    {
        QMessageBox::warning(this, "背包已满", "您的背包已满，请结束实验。");
    }
    else{
    if(QPos::Fcoin>=0)
{
        CJmunber++;
    // 创建一个新的对话框以显示随机图片
    QDialog *dialog = new QDialog();
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->setWindowTitle("开箱ing...");

    // 添加一个标签用于显示随机图片
    QLabel *imageLabel = new QLabel(dialog);
    imageLabel->setAlignment(Qt::AlignCenter);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setVisible(false);   // 初始隐藏

    // 随机选择一张图片并在标签上显示
    int index = QRandomGenerator::global()->bounded(imageList.count());
    QPixmap pixmap(imageList.at(index));



    if (!pixmap.isNull()) {
        dialog->resize(pixmap.size());  // 调整对话框大小以适应图片
    }

    // CTRL Xed

    randNum++;

    // 查找随机数对应的按钮
    QPushButton *button = this->findChild<QPushButton *>(QString("pb%1").arg(randNum));

    // 如果找到了按钮，设置按钮图标和大小
    if (button && !pixmap.isNull()) {
        button->setIcon(QIcon(pixmap));
        button->setIconSize(button->size());
    }
    // 创建一个动画
    QPropertyAnimation *animation = new QPropertyAnimation(imageLabel, "geometry", dialog);
    animation->setDuration(1000);
    animation->setStartValue(imageLabel->geometry());
    animation->setEndValue(pixmap.rect());
    animation->setEndValue(QRect(0, 0, pixmap.width(), pixmap.height()));

    // 在对话框中显示标签并播放动画
    QVBoxLayout *layout = new QVBoxLayout(dialog);

    QMovie *movie = new QMovie(":/Images/KX.gif", QByteArray(), dialog);
    QLabel *loadingLabel = new QLabel(dialog);
    loadingLabel->setAlignment(Qt::AlignCenter);
    loadingLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    movie->setScaledSize(QSize(400, 400));
    loadingLabel->setMovie(movie);
    movie->start();


    // 调整动画大小以与图片标签一致
    movie->setScaledSize(pixmap.size());
    loadingLabel->setMovie(movie);

    layout->addWidget(loadingLabel);
    dialog->setLayout(layout);

    // 播放动画前隐藏图片标签
    imageLabel->setVisible(false);

    QTimer::singleShot(1500, [=]() {
        layout->removeWidget(loadingLabel);
        delete loadingLabel;

        // 显示图片标签并开始动画
        imageLabel->setPixmap(pixmap);
        imageLabel->setVisible(true);
        layout->addWidget(imageLabel);
        dialog->resize(pixmap.size());  // 调整对话框大小以适应图片
        animation->start();

        // 创建一个计时器，在3秒后关闭对话框
        QTimer *timer = new QTimer(dialog);
        timer->setSingleShot(true);
        QObject::connect(timer, &QTimer::timeout, dialog, &QDialog::close);
        timer->start(2000); // 设置计时器的时间为2秒
    });




    QPos::Fcoin-=0;
    onUpdateAB();
    dialog->show();


    }
else
  QMessageBox::warning(this, "抽奖次数不足", "您的抽奖次数不足，无法抽奖。");
    }

}



void choujiang::on_regame_clicked()
{
    emit emit_regame();
    this->hide();
}

void choujiang::onUpdateAB()
{


    QString AT=QString("你的总分为： %1").arg(QPos::Fscore/2);
    QString AMT = QString("你的抽奖次数为： %1").arg(QString::number(QPos::Fcoin/20));;
        ui->label_Fscore->setText(AT);
        ui->label_Fcoin->setText(AMT);
        QString AFK = QString("抽奖次数： %1").arg(CJmunber);;
          ui->label_CJnum->setText(AFK);


}

void choujiang::on_pushButton_clicked()
{
          emit  emit_shuoming();

}



void choujiang::on_pushButton_3_clicked()
{

  // 延迟3秒后停止程序
  QTimer::singleShot(3000, qApp, SLOT(quit()));

  // 将数据写入TXT文档
  int data1 =QPos::Fscore/2; // 你需要上传的数据1
  int data2 = CJmunber; // 你需要上传的数据2
  QFile file("testee.txt");
  if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
  out <<"TOTALSCORE:"<< data1 << ",  CJNUM:" << data2 << endl;
        file.close();
  }

  // 弹出感谢配合的消息框
  QMessageBox::information(this, "消息", "实验结束，感谢您的配合！");


}

