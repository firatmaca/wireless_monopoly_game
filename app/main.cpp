#include "mainwindow.h"
#include <QApplication>
#include "mserver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    mserver m;
    m.StartServer();
    w.show();
    return a.exec();
}
