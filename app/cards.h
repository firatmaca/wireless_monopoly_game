#ifndef CARDS_H
#define CARDS_H
#include "QString"
#include <plyrs.h>
class Cards
{
public:
            /*plyrs player;*/
    int x,y;
        QString name;
          int cost;
          int rent,rent1h,rent2h,rent3h,rent4h,renthotel;
          bool buy;
        QString owner;
        int levelofcard;
        QString renk;


    Cards();
    void setval(int ,int,QString,int ,int ,int ,int ,int ,int ,int,bool,QString,int,QString );
 //   KamuFonu();
  //  void kamu(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
  //   Şans();
  //  void şans(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
};

#endif // CARDS_H
