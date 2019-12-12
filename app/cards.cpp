#include "cards.h"
#include "QString"
#include "plyrs.h"
Cards::Cards()
{

    x=0;
    y=0;
    name=" ";
    cost=0;
    rent=0;
    rent1h=0;
    rent2h=0;
    rent3h=0;
    rent4h=0;
    renthotel=0;
    buy=false;
    owner="bank";
    levelofcard=0;
    renk=" ";
}
void Cards::setval(int n,int m,QString nameofhouse,int costofhouse,int rentf,int rentone,int renttwo,int rentthree,int rentfour,int renth,bool b,QString o,int c,QString r)
{
    x=n;
    y=m;
    name=nameofhouse;
    cost=costofhouse;
    rent=rentf;
    rent1h=rentone;
    rent2h=renttwo;
    rent3h=rentthree;
    rent4h=rentfour;
    renthotel=renth;
    buy=b;
    owner=o;
    levelofcard=c;
    renk=r;
}
