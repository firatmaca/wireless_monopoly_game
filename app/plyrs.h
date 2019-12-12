#ifndef PLYRS_H
#define PLYRS_H
#include "QString"
#include "cards.h"

class plyrs
{
public:
QString name;
int balance;
int rounds;
QString code;

   void setplayer(QString,int ,int,QString );
    plyrs();
};


#endif // PLYRS_H
