#ifndef MYTHREAD_H
#define MYTHREAD_H
#include<QThread>
#include<QDebug>
#include<QTcpServer>
#include<QTcpSocket>
#include<QDebug>
#include<QThread>
#include <QObject>
#include <qsharedmemory.h>
class mythread : public QThread
{
    Q_OBJECT
public:
    QString tekliflist[8];
    int z=0;
    QByteArray Data;
    explicit mythread(int ID,QObject *parent=0);
    mythread();
    void run();
signals:
    void getdata(QByteArray);
 void Error(QTcpSocket::SocketError socketerror);
private slots:
    void readyRead();
    void disconnected();
public:
    QSharedMemory sharedMemory;
    QTcpSocket *socket;
    int socketDescriptor;
};

#endif // MYTHREAD_H
