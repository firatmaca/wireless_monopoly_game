#include "plyrs.h"

plyrs::plyrs()
{
    name=" ";
    rounds=0;
    balance=1500;
    code=" ";
}

void plyrs ::setplayer(QString Names, int b , int r,QString c){
    name=Names;
     code=c;
    balance=b;
    rounds=r;

}
