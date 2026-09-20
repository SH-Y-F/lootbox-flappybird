#ifndef SHUOMING_H
#define SHUOMING_H

#include <QWidget>

namespace Ui {
class Shuoming;
}

class Shuoming : public QWidget
{
    Q_OBJECT

public:
    explicit Shuoming(QWidget *parent = nullptr);
    ~Shuoming();
public slots:
    void slots_shuoming();
private slots:
    void on_pushButton_2_clicked();


private:
    Ui::Shuoming *ui;

};

#endif // SHUOMING_H
