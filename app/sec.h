#ifndef SEC_H
#define SEC_H

#include <QDialog>
#include<QGraphicsView>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include<QGraphicsScene>
#include<cards.h>
#include <mainwindow.h>
#include <plyrs.h>
#include <lucky.h>
#include "mythread.h"
#include "qevent.h"
/*
namespace Ui {
class sec;
}

class sec : public QDialog
{
    Q_OBJECT

public:
    QString comingdata;
    void set(QByteArray);
    QSharedMemory sharedMemory;
    QByteArray Data;
     QString d;
    plyrs players[8];
    int i[8],y[8];
    plyrs currentplayer;
   QString text;
    Cards array[41];
    lucky kamu[15];
    lucky sans[15];
    int k1=0 ,k2 =0;
    int nop=0,deneme=0;
    void numofplayer();
   //void set(QByteArray);
    explicit sec(QWidget *parent = 0);
    ~sec();
signals:
public slots:
    void on_pushButton_34_clicked();

     void getdat(QByteArray);

public:
    Ui::sec *ui;
private slots:
    void on_buybutton_clicked();
    void on_buildbutton_clicked();
    void on_EXITBUTTON_clicked();
private:
};
*/
#endif // SEC_H
