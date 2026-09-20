#ifndef FORMMENU_H
#define FORMMENU_H
#include <QWidget>
#include <QtGui>
#include <QPainter>
#include <QPixmap>
#include <QLabel>
#include <QWidget>
#include <QString>
#include<QFile>
#include<QTextStream>
namespace Ui {
class Formmenu;
}

class Formmenu : public QWidget
{
    Q_OBJECT

public:
    explicit Formmenu(QWidget *parent = nullptr);
    ~Formmenu();
signals:
    void emit_game();
    void emit_ins();


private slots:
    void on_game_clicked();
    void on_pushButton_clicked();

private:
    Ui::Formmenu *ui;

};

#endif // FORMMENU_H
