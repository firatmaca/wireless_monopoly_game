#ifndef MSERVER_H
#define MSERVER_H
#include <QTcpServer>
#include <QDebug>
#include "mythread.h"
#include "qfile.h"
class mserver : public QTcpServer
{
public:
    int count=0;
    int nop[8]={0,0,0,0,0,0,0,0};
        void incomingConnection(qintptr socketDescriptor);
    /*explicit server(QObject *parent=0);*/
    void StartServer();
    mserver();
signals:

private slots:
protected:
};


#endif // MSERVER_H
