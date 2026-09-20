#ifndef PINGFEN_H
#define PINGFEN_H
#include <QDialog>
#include <QLineEdit>
#include <QSlider>
#include <QPushButton>
#include <QWidget>
#include <QDebug>

namespace Ui {
class pingfen;
}

class pingfen : public QWidget
{
    Q_OBJECT

public:
    explicit pingfen(QWidget *parent = nullptr);
    ~pingfen();

public slots:
    void slots_pingfen1();
    void slots_pingfen2();
    void slots_pingfen3();
    void slots_pingfen4();
    void slots_pingfen5();
    void slots_pingfen6();
    void slots_pingfen7();
    void slots_pingfen8();
    void slots_pingfen9();
    void slots_pingfen10();



private slots:

    void on_pushButton_clicked();

private:
    Ui::pingfen *ui;
    QString NTK;
};

#endif // PINGFEN_H
