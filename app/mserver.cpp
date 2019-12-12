#include"qtcpserver.h"
#include"qtcpsocket.h"
#include "mserver.h"
#include "mythread.h"
#include "sec.h"
#include "qnetworkaccessmanager.h"
#include "mainwindow.h"
#include "qmutex.h"
#include "qtimer.h"
mserver::mserver()
{
    QNetworkAccessManager networkAccessManager;
    networkAccessManager.setNetworkAccessible(QNetworkAccessManager::Accessible);

}
void mserver::StartServer(){
    if(!this->listen(QHostAddress::AnyIPv4,9988)){
        qDebug()<<"not start server";
    }else{
        MainWindow ff;
        ff.comingdata="opoo";
        qDebug()<<"listening";


    }
}
void mserver:: incomingConnection(qintptr socketDescriptor){
    nop[count]=socketDescriptor;
qDebug()<<socketDescriptor<<"connecting";
 mythread *thread=new mythread(socketDescriptor,this);
connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
/*connect(thread,SIGNAL(getdata(QByteArray)),s,SLOT(getim(QByteArray)));*/
QFile file ("c:/nop.txt");
if(!file.open(QFile:: WriteOnly | QFile:: Text)){
   qDebug()<<"yazılamıyor";
}
QTextStream out(&file);
out<<nop[0]<<" "<<nop[1]<<" "<<nop[2]<<" "<<nop[3]<<" "<<nop[4]<<" "<<nop[5]<<" "<<nop[6]<<" "<<nop[7]<<" ";
file.flush();
file.close();
count++;
        thread->start();



}

