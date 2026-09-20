#ifndef FORMINSTRUCTION_H
#define FORMINSTRUCTION_H

#include <QWidget>

namespace Ui {
class Forminstruction;
}

class Forminstruction : public QWidget
{
    Q_OBJECT

public:
    explicit Forminstruction(QWidget *parent = nullptr);
    ~Forminstruction();
public slots:
    void slots_int();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Forminstruction *ui;
};

#endif // FORMINSTRUCTION_H
