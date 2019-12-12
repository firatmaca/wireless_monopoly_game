#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sec.h"
#include <QMainWindow>
#include"plyrs.h"
#include <plyrs.h>
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
#include "mythread.h"
#include "qevent.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
        Ui::MainWindow *ui;
    QString citylist1[10];
    QString citylist2[10];
    QString citylist3[10];
    QString citylist4[10];
    QString citylist5[10];
    QString citylist6[10];
    QString citylist7[10];
    QString citylist8[10];
    QStringList plist,mlist,tlist;
    int count=0;
    int count1=0,ccc=0,s=0,ll=0,lll=0;
    int sount=0;
     QString con="";
     QString varlik="";
       QString conn="";
       QString dist="";
       QString sdk="";
    QString comindata;
    int numberofplayer;
    explicit MainWindow(QWidget *parent = 0);
    bool b=0;
    ~MainWindow();
 void ex();
 QString comingdata;
 void set(QByteArray);
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
QString test=" ";
 QString text1="  ";
 QString text2=" ";
 QString text3=" ";
 signals:
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();
void p8();
void zarr();
void al();
void sat();
void done();
void ggg();
void bbb();
public slots:
     void buy();
     void build();
    void player2();
    void player3();
    void player4();
    void player5();
    void player6();
    void player7();
    void player8();
    void  controller();
    void zar();
    void satt();
    void donee();
    void offer();
   // void getim(QByteArray);
private slots:
    void on_EXITBUTTON_clicked();
};



#endif // MAINWINDOW_H
