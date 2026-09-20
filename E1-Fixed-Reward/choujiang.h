#ifndef CHOUJIANG_H
#define CHOUJIANG_H

#include "qbuttongroup.h"
#include <QWidget>
#include "shuoming.h"
#include "pingfen.h"


namespace Ui {
class choujiang;
}

class choujiang : public QWidget
{
    Q_OBJECT

public:
    explicit choujiang(QWidget *parent = nullptr);
    ~choujiang();

    protected:
    void showEvent(QShowEvent *event);
signals:
    void emit_regame();
    void emit_tujian();
    void emit_shuoming();
    void emit_pingfen1();
    void emit_pingfen2();
    void emit_pingfen3();
    void emit_pingfen4();
    void emit_pingfen5();
    void emit_pingfen6();
    void emit_pingfen7();
    void emit_pingfen8();
    void emit_pingfen9();
    void emit_pingfen10();

public slots:
    void slots_choujiang();
    void onUpdateAB();


private slots:

    void on_startCJ_clicked();

    void on_regame_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:

    Ui::choujiang *ui;
    QButtonGroup *QButtonG;

    Shuoming *m_pshuoming;
    pingfen *m_ppingfen1;
    pingfen *m_ppingfen2;
    pingfen *m_ppingfen3;
    pingfen *m_ppingfen4;
    pingfen *m_ppingfen5;
    pingfen *m_ppingfen6;
    pingfen *m_ppingfen7;
    pingfen *m_ppingfen8;
    pingfen *m_ppingfen9;
    pingfen *m_ppingfen10;
};

#endif // CHOUJIANG_H
