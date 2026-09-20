 #include "formmenu.h"
#include "ui_formmenu.h"
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
Formmenu::Formmenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Formmenu)
{
    ui->setupUi(this);
    ui->lineEdit_5->setPlaceholderText("请输入你的实验编号");
    ui->lineEdit_4->setPlaceholderText("请输入你的性别");
    ui->lineEdit_6->setPlaceholderText("请输入你的姓名");
}

Formmenu::~Formmenu()
{
    delete ui;
}

void Formmenu::on_game_clicked()
{
    emit emit_game();
    this->hide();
    // 获取所有 QLineEdit 控件
    QList<QLineEdit*> lineEditList = findChildren<QLineEdit*>();

    // 创建要写入的文件
    QFile file("testee.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;

    // 创建一个 QTextStream 对象，用于写入文件
    QTextStream out(&file);

    // 将所有 QLineEdit 的文本合并为单个字符串，并写入文件
    for (auto lineEdit : lineEditList)
        out << lineEdit->text() << "\n";

    // 关闭文件
    file.close();
}


void Formmenu::on_pushButton_clicked()
{
    emit emit_ins();


}

