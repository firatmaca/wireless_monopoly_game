#include "mythread.h"
#include "qthread.h"
#include"qtcpserver.h"
#include"qtcpsocket.h"
#include "qthread.h"
#include"qstring.h"
#include"qdatastream.h"
#include"qchar.h"
#include "qfile.h"
#include "qbuffer.h"
#include "sec.h"
#include "ui_sec.h"
#include "qmutex.h"
#include "qprocess.h"
mythread::mythread(int ID,QObject *parent):

    QThread(parent)
{
this->socketDescriptor=ID;
}
void mythread::run()
{
  qDebug()<< socketDescriptor<<"starting thread";
  socket=new QTcpSocket();
  if(!socket->setSocketDescriptor(this->socketDescriptor)){
      qDebug()<<"error";
      /*emit Error(socket->error());*/
      return;
  }

  connect(socket,SIGNAL (readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
   connect(socket,SIGNAL (disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);
   qDebug()<< socketDescriptor<<"client connected";
   exec();
}
void mythread::readyRead(){
     Data=socket->readAll();
     emit getdata("sırasende");

    qDebug()<<socketDescriptor<<"data in"<<Data;
    socket->write(Data);
    QFile file ("c:/Data.txt");
   if(!file.open(QFile:: WriteOnly | QFile:: Text)){
       qDebug()<<"yazılamıyor";
   }
   QTextStream out(&file);
   QString text =Data;
   out<<socketDescriptor<<" "<<text;
   file.flush();
   file.close();
   if(Data=="teklif")
   {
       QFile file ("c:/nop.txt");
      if(!file.open(QFile:: WriteOnly | QFile:: Text)){
          qDebug()<<"yazılamıyor";
      }
      QTextStream out(&file);
      QString textim =Data;
      tekliflist[z]=socketDescriptor+" "+textim;
      out<<tekliflist[0]<< " " <<tekliflist[1]<< " " <<tekliflist[2]<<" "  <<tekliflist[3]<<" " <<tekliflist[4]<<
                         " "<<tekliflist[5]<<" "<<tekliflist[6]<<" "<<tekliflist[7];
      file.flush();
      file.close();
   }
}
void mythread::disconnected(){
     qDebug()<<socketDescriptor<<"disconnected";
    socket->deleteLater();
exit(0);

}
