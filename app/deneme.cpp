#include "deneme.h"
#include "sec.h"
#include "qdebug.h"
deneme::deneme()
{

}
void deneme::set(QByteArray cdata){
 qDebug()<<"girdi";
data=cdata;
}
QString deneme::get(){
return data;
}
