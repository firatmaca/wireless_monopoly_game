#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sec.h"
#include "ui_sec.h"
#include "plyrs.h"
#include "mserver.h"
#include <QFile>
#include <QTextStream>
#include <QCoreApplication>
#include <QTimer>
#include <QTime>
#include "cards.h"
#include "plyrs.h"
#include "lucky.h"
#include "mythread.h"
#include "mserver.h"
#include "qtimer.h"
#include "qmutex.h"
MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
this->setWindowState(Qt::WindowFullScreen);
    array[0].setval(0,740,"GO",0,0,0,0,0,0,0,false,"bank",0," ");
    array[1].setval(0,670,"VISNELIK",140,10,50,150,450,625,750,false,"bank",0,"purple");
    array[2].setval(0,600,"ELEKTRIK ISLERI",150,30,0,0,0,0,0,false,"bank",0,"1");
    array[3].setval(0,530,"VADISEHIR",140,10,50,150,450,625,750,false,"bank",0,"purple");
    array[4].setval(0,460,"SUMER",160,12,60,180,500,700,900,false,"bank",0,"purple");
    array[5].setval(0,390,"TREN GARI",200,50,0,0,0,0,0,false,"bank",0,"2");
    array[6].setval(0,320,"PASA",180,14,70,200,550,750,950,false,"bank",0,"orange");
    array[7].setval(0,250,"CHEST",0,0,0,0,0,0,0,false,"bank",0,"3");
    array[8].setval(0,180,"EMEK",180,14,70,200,550,750,950,false,"bank",0,"orange");
    array[9].setval(0,110,"GOZTEPE",200,16,80,220,600,800,1000,false,"bank",0,"orange");
    array[10].setval(0,0,"INJAIL",0,0,0,0,0,0,0,false,"bank",0,"4");
    array[11].setval(110,0,"ARIFIYE",220,18,90,250,700,875,1050,false,"bank",0,"red");
    array[12].setval(180,0,"CHANCE",0,0,0,0,0,0,0,false,"bank",0,"5");
    array[13].setval(250,0,"DEDE",220,18,90,250,700,875,1050,false,"bank",0,"red");
    array[14].setval(320,0,"HUZUR",240,20,100,300,750,925,1100,false,"bank",0,"red");
    array[15].setval(390,0,"PORSUKGEZINTISI",200,50,0,0,0,0,0,false,"bank",0,"6");
    array[16].setval(460,0,"CAVLUM",260,22,110,330,800,975,1150,false,"bank",0,"yellow");
    array[17].setval(530,0,"GOKMEYDAN",260,22,110,330,800,975,1150,false,"bank",0,"yellow");
    array[18].setval(600,0,"SUISLERI",150,30,0,0,0,0,0,false,"bank",0,"7");
    array[19].setval(670,0,"ISTIKLAL",280,24,120,360,850,1025,1200,false,"bank",0,"yellow");
    array[20].setval(740,0,"FREEPARKING",0,0,0,0,0,0,0,false,"bank",0,"8");
    array[21].setval(750,110,"ALANONU",300,26,130,390,900,1100,1275,false,"bank",0,"green");
    array[22].setval(750,180,"CUMHURIYE",300,26,130,390,900,1100,1275,false,"bank",0,"green");
    array[23].setval(750,250,"CHEST",0,0,0,0,0,0,0,false,"bank",0,"9");
    array[24].setval(750,320,"KALKANLI",320,28,150,450,1000,1200,1400,false,"bank",0,"green");
    array[25].setval(750,390,"OTOGAR",200,50,0,0,0,0,0,false,"bank",0,"10");
    array[26].setval(750,460,"CHANCE",0,0,0,0,0,0,0,false,"bank",0,"11");
    array[27].setval(750,530,"75.YIL",350,35,175,500,1100,1300,1500,false,"bank",0,"blue");
    array[28].setval(750,600,"LUXARYTAX",0,0,0,0,0,0,0,false,"bank",0,"12");
    array[29].setval(750,670,"71EVLER",400,50,200,600,1400,1700,2000,false,"bank",0,"blue");
    array[30].setval(740,740,"GOTOJAIL",0,0,0,0,0,0,0,false,"bank",0,"13");
    array[31].setval(670,750,"TEPEBASI",60,2,10,30,90,160,250,false,"bank",0,"brown");
    array[32].setval(600,750,"CHEST",0,0,0,0,0,0,0,false,"bank",0,"14");
    array[33].setval(530,750,"ODUNPAZARI",60,4,20,60,180,320,450,false,"bank",0,"brown");
    array[34].setval(460,750,"GELIRVERGISI",0,0,0,0,0,0,0,false,"bank",0,"15");
    array[35].setval(390,750,"HIZLITREN",200,40,0,0,0,0,0,false,"bank",0,"16");
    array[36].setval(320,750,"GUNDOGDU",100,6,30,90,270,400,550,false,"bank",0,"aqua");
    array[37].setval(250,750,"CHANCE",0,0,0,0,0,0,0,false,"bank",0,"17");
    array[38].setval(180,750,"ERENKOY",120,8,40,100,300,450,600,false,"bank",0,"aqua");
    array[39].setval(110,750,"GULTEPE",120,8,40,100,300,450,600,false,"bank",0,"aqua");

    for (int k=0;k<8;k++) {
     i[k]=1;
     y[k]=1;
    }
    kamu[0].setit("Çekilişten 50m Kazandın ");
    kamu[1].setit("Bugün Doğum Günü Her Oyuncudan 25m Al");
    kamu[2].setit("Tramvaya Kaçak Bindiğin İçin 100m öde");
    kamu[3].setit(" 6 Ganyandan 50m Kazandın ");
    kamu[4].setit("Yıllık Faizlerden 100m Al ");
    kamu[5].setit("Vergi Kaçırdğın İçin 50m öde ");
    kamu[6].setit("Köpeğin Hastalandı Doktor Ücreti 50m Öde ");
    kamu[7].setit("Okul Taksidini Öde 50m ");
    kamu[8].setit("Banka Hesabında Yanlışlık Olmuş 200m Al ");
    kamu[9].setit("Dedenden Miras Geldi 100m Al ");
    kamu[10].setit("Sigoratadan Para geldi 100m Al");
    kamu[11].setit("Güzellik Yarışmasında 3. Oldun 25 Al ");
    kamu[12].setit("Araban Bozulmuş 200m Öde ");
    kamu[13].setit("Lotodan Amorti Çıktı 200m Al");
    kamu[14].setit("Borsadan 50m Kazandın ");
    kamu[15].setit("Vergi İadesi 25m Al");






    //    Şans[15].Şans("Radara Yakalanmışsın 200m Ver","Yönetim Kurulu Başkanı Seçildin Her Oyuncuya 50m Öde",
    //                   "Kırmızıda Geçmişsin 25m Öde","Banka Kar Payı Ödüyor 50m Al",
    //                  "Maliye Denetime Geldi 100m ver","Evini Kiraya verdin 150m Al",
    //                  "İmzaladığın Çekler Karşılıksız Çıktı Doğrudan Hapise Git","Arazi Maftası,150m Öde",
    //                   "Başlangıç Noktasına İlerle 200m Al","Çekilişten 50m Kazandın",
    //                    "Telefonun Bozuldu 100m Öde","Başlangıç Noktasına İlerle 200m Al",
    //                  "1 Mayıs Eylemlerinde Yaralandın 75 Hastane Masrafı Öde","");

    sans[0].setit("Radara Yakalanmışsın 200m Ver");
    sans[1].setit("Yönetim Kurulu Başkanı Seçildin Her Oyuncuya 50m Öde");
    sans[2].setit("Kırmızıda Geçmişsin 25m Öde");
    sans[3].setit("Banka Kar Payı Ödüyor 50m Al");
    sans[4].setit("Maliye Denetime Geldi 100m ver");
    sans[5].setit("Evini Kiraya verdin 150m Al");
    sans[6].setit("İmzaladığın Çekler Karşılıksız Çıktı 50m Öde");
    sans[7].setit("Arazi Mafyası,150m Öde");
    sans[8].setit("ESTÜ'de Yılın Öğrencisi Seçildin 200m Al");
    sans[9].setit("Çekilişten 50m Kazandın");
    sans[10].setit("Telefonun Bozuldu 100m Öde");
    sans[11].setit("Sportotodan 14 bildin  200m Kazandın");
    sans[12].setit("1 Mayıs Eylemlerinde Yaralandın 75 Hastane Masrafı Öde");
    ui->messagebox->setText("WELCOME");
      ui->label_7->setVisible(true);
      ui->buybutton->setEnabled(false);
      ui->sellbutton->setEnabled(false);
      ui->buildbutton->setEnabled(false);
      ui->label_7->setVisible(false);
      ui->z1->setVisible(false);
      ui->z2->setVisible(false);
      ui->z3->setVisible(false);
      ui->z4->setVisible(false);
      ui->z5->setVisible(false);
      ui->z6->setVisible(false);
      ui->z11->setVisible(false);
      ui->z22->setVisible(false);
      ui->z33->setVisible(false);
      ui->z44->setVisible(false);
      ui->z55->setVisible(false);
      ui->z66->setVisible(false);
      ui->pushButton_34->setVisible(false);
      ui->buildbutton->setVisible(false);

       QTimer *t1 =new QTimer (this);
  connect(t1,SIGNAL(timeout()),this,SLOT(controller()));

  qDebug()<<" "; t1->start(1000);

}

MainWindow::~MainWindow()
{

    delete ui;
}
void MainWindow::player2()
{
nop=2;
ui->siyahpiyon->setVisible(true);
ui->beyazpiyon->setVisible(true);
ui->kirmizipiyon->setVisible(false);
ui->yesilpiyon->setVisible(false);
ui->mavipiyon->setVisible(false);
ui->kahvepiyon->setVisible(false);
ui->morpiyon->setVisible(false);
ui->saripiyon->setVisible(false);
players[0].setplayer("Player-1",1500,0,plist.at(0));
players[1].setplayer("Player-2",1500,0,plist.at(1));
players[2].setplayer("  ",1500,0,plist.at(2));
players[3].setplayer("  ",1500,0,plist.at(3));
players[4].setplayer("  ",1500,0,plist.at(4));
players[5].setplayer("  ",1500,0,plist.at(5));
players[6].setplayer("  ",1500,0,plist.at(6));
players[7].setplayer("  ",1500,0,plist.at(7));
ui->PLAYER1->setText( players[0].name + "\n"+ "Amount:" + QString::number( players[0].balance));
ui->PLAYER2->setText( players[1].name + "\n"+ "Amount:" + QString::number( players[1].balance));
}

void MainWindow::player3()
{
nop=3;
ui->siyahpiyon->setVisible(true);
ui->beyazpiyon->setVisible(true);
ui->kirmizipiyon->setVisible(true);
ui->yesilpiyon->setVisible(false);
ui->mavipiyon->setVisible(false);
ui->kahvepiyon->setVisible(false);
ui->morpiyon->setVisible(false);
ui->saripiyon->setVisible(false);
players[0].setplayer("Player-1",1500,0,plist.at(0));
players[1].setplayer("Player-2",1500,0,plist.at(1));
players[2].setplayer("Player-3",1500,0,plist.at(2));
players[3].setplayer("  ",1500,0,plist.at(3));
players[4].setplayer("  ",1500,0,plist.at(4));
players[5].setplayer("  ",1500,0,plist.at(5));
players[6].setplayer("  ",1500,0,plist.at(6));
players[7].setplayer("  ",1500,0,plist.at(7));
ui->PLAYER1->setText( players[0].name + "\n"+ "Amount:" + QString::number( players[0].balance));
ui->PLAYER2->setText( players[1].name + "\n"+ "Amount:" + QString::number( players[1].balance));
ui->PLAYER3->setText( players[2].name + "\n"+ "Amount:" + QString::number( players[2].balance));
}
void MainWindow::player4()
{
nop=4;
ui->siyahpiyon->setVisible(true);
ui->beyazpiyon->setVisible(true);
ui->kirmizipiyon->setVisible(true);
ui->yesilpiyon->setVisible(true);
ui->mavipiyon->setVisible(false);
ui->kahvepiyon->setVisible(false);
ui->morpiyon->setVisible(false);
ui->saripiyon->setVisible(false);
players[0].setplayer("Player-1",1500,0,plist.at(0));
players[1].setplayer("Player-2",1500,0,plist.at(1));
players[2].setplayer("Player-3",1500,0,plist.at(2));
players[3].setplayer("Player-4",1500,0,plist.at(3));
players[4].setplayer("  ",1500,0,plist.at(4));
players[5].setplayer("  ",1500,0,plist.at(5));
players[6].setplayer("  ",1500,0,plist.at(6));
players[7].setplayer("  ",1500,0,plist.at(7));
ui->PLAYER1->setText( players[0].name + "\n"+ "Amount:" + QString::number(players[0].balance));
ui->PLAYER2->setText(players[1].name + "\n"+ "Amount:" + QString::number( players[1].balance));
ui->PLAYER3->setText( players[2].name + "\n"+ "Amount:" + QString::number( players[2].balance));
ui->PLAYER4->setText( players[3].name + "\n"+ "Amount:" + QString::number( players[3].balance));
}
void MainWindow::player5()
{
nop=5;
ui->siyahpiyon->setVisible(true);
ui->beyazpiyon->setVisible(true);
ui->kirmizipiyon->setVisible(true);
ui->yesilpiyon->setVisible(true);
ui->mavipiyon->setVisible(true);
ui->kahvepiyon->setVisible(false);
ui->morpiyon->setVisible(false);
ui->saripiyon->setVisible(false);
players[0].setplayer("Player-1",1500,0,plist.at(0));
players[1].setplayer("Player-2",1500,0,plist.at(1));
players[2].setplayer("Player-3",1500,0,plist.at(2));
players[3].setplayer("Player-4",1500,0,plist.at(3));
players[4].setplayer("Player-5",1500,0,plist.at(4));
players[5].setplayer("  ",1500,0,plist.at(5));
players[6].setplayer("  ",1500,0,plist.at(6));
players[7].setplayer("  ",1500,0,plist.at(7));
ui->PLAYER1->setText(players[0].name + "\n"+ "Amount:" + QString::number( players[0].balance));
ui->PLAYER2->setText( players[1].name + "\n"+ "Amount:" + QString::number( players[1].balance));
ui->PLAYER3->setText( players[2].name + "\n"+ "Amount:" + QString::number( players[2].balance));
ui->PLAYER4->setText( players[3].name + "\n"+ "Amount:" + QString::number(players[3].balance));
ui->PLAYER5->setText( players[4].name + "\n"+ "Amount:" + QString::number( players[4].balance));
}
void MainWindow::player6(){

nop=6;
ui->siyahpiyon->setVisible(true);
ui->beyazpiyon->setVisible(true);
ui->kirmizipiyon->setVisible(true);
ui->yesilpiyon->setVisible(true);
ui->mavipiyon->setVisible(true);
ui->kahvepiyon->setVisible(true);
ui->morpiyon->setVisible(false);
ui->saripiyon->setVisible(false);
players[0].setplayer("Player-1",1500,0,plist.at(0));
players[1].setplayer("Player-2",1500,0,plist.at(1));
players[2].setplayer("Player-3",1500,0,plist.at(2));
players[3].setplayer("Player-4",1500,0,plist.at(3));
players[4].setplayer("Player-5",1500,0,plist.at(4));
players[5].setplayer("Player-6",1500,0,plist.at(5));
players[6].setplayer("  ",1500,0,plist.at(6));
players[7].setplayer("  ",1500,0,plist.at(7));
ui->PLAYER1->setText( players[0].name + "\n"+ "Amount:" + QString::number( players[0].balance));
ui->PLAYER2->setText( players[1].name + "\n"+ "Amount:" + QString::number( players[1].balance));
ui->PLAYER3->setText( players[2].name + "\n"+ "Amount:" + QString::number( players[2].balance));
ui->PLAYER4->setText( players[3].name + "\n"+ "Amount:" + QString::number( players[3].balance));
ui->PLAYER5->setText( players[4].name + "\n"+ "Amount:" + QString::number( players[4].balance));
ui->PLAYER6->setText( players[5].name + "\n"+ "Amount:" + QString::number( players[5].balance));
}
void MainWindow::player7()
{
    MainWindow se;
nop=7;
ui->siyahpiyon->setVisible(true);
ui->beyazpiyon->setVisible(true);
ui->kirmizipiyon->setVisible(true);
ui->yesilpiyon->setVisible(true);
ui->mavipiyon->setVisible(true);
ui->kahvepiyon->setVisible(true);
ui->morpiyon->setVisible(true);
ui->saripiyon->setVisible(false);
players[0].setplayer("Player-1",1500,0,plist.at(0));
players[1].setplayer("Player-2",1500,0,plist.at(1));
players[2].setplayer("Player-3",1500,0,plist.at(2));
players[3].setplayer("Player-4",1500,0,plist.at(3));
players[4].setplayer("Player-5",1500,0,plist.at(4));
players[5].setplayer("Player-6",1500,0,plist.at(5));
players[6].setplayer("Player-7",1500,0,plist.at(6));
players[7].setplayer("  ",1500,0,plist.at(7));
ui->PLAYER1->setText( players[0].name + "\n"+ "Amount:" + QString::number( players[0].balance));
ui->PLAYER2->setText( players[1].name + "\n"+ "Amount:" + QString::number( players[1].balance));
ui->PLAYER3->setText( players[2].name + "\n"+ "Amount:" + QString::number( players[2].balance));
ui->PLAYER4->setText(players[3].name + "\n"+ "Amount:" + QString::number( players[3].balance));
ui->PLAYER5->setText( players[4].name + "\n"+ "Amount:" + QString::number( players[4].balance));
ui->PLAYER6->setText( players[5].name + "\n"+ "Amount:" + QString::number( players[5].balance));
ui->PLAYER7->setText( players[6].name + "\n"+ "Amount:" + QString::number( players[6].balance));
}
void MainWindow::player8()
{
nop=8;
ui->siyahpiyon->setVisible(true);
ui->beyazpiyon->setVisible(true);
ui->kirmizipiyon->setVisible(true);
ui->yesilpiyon->setVisible(true);
ui->mavipiyon->setVisible(false);
ui->kahvepiyon->setVisible(true);
ui->morpiyon->setVisible(true);
ui->saripiyon->setVisible(true);
players[0].setplayer("Player-1",1500,0,plist.at(0));
players[1].setplayer("Player-2",1500,0,plist.at(1));
players[2].setplayer("Player-3",1500,0,plist.at(2));
players[3].setplayer("Player-4",1500,0,plist.at(3));
players[4].setplayer("Player-5",1500,0,plist.at(4));
players[5].setplayer("Player-6",1500,0,plist.at(5));
players[6].setplayer("Player-7",1500,0,plist.at(6));
players[7].setplayer("Player-8",1500,0,plist.at(7));
ui->PLAYER1->setText( players[0].name + "\n"+ "Amount:" + QString::number( players[0].balance));
ui->PLAYER2->setText( players[1].name + "\n"+ "Amount:" + QString::number( players[1].balance));
ui->PLAYER3->setText( players[2].name + "\n"+ "Amount:" + QString::number( players[2].balance));
ui->PLAYER4->setText( players[3].name + "\n"+ "Amount:" + QString::number( players[3].balance));
ui->PLAYER5->setText( players[4].name + "\n"+ "Amount:" + QString::number( players[4].balance));
ui->PLAYER6->setText( players[5].name + "\n"+ "Amount:" + QString::number( players[5].balance));
ui->PLAYER7->setText( players[6].name + "\n"+ "Amount:" + QString::number( players[6].balance));
ui->PLAYER8->setText( players[7].name + "\n"+ "Amount:" + QString::number( players[7].balance));
}
void MainWindow::controller(){


if(count==30){

   qDebug()<<"üç";
    QFile file ("c:/nop.txt");
     if(!file.open(QFile:: ReadOnly | QFile:: Text)){

       qDebug()<<"okunmuyor";
     }
     QTextStream inn(&file);
     text2 = inn.readLine();
      plist= text2.split(" ", QString::SkipEmptyParts);
     file.close();
    numberofplayer=8-text2.count(" 0 ");

  con=plist.at(ccc);
   qDebug()<<"numofplayer"<<numberofplayer;
   switch (numberofplayer){
   case 2:
       connect(this,SIGNAL(p2()),this,SLOT(player2()));
       emit p2();
       break;
   case 3:
       connect(this,SIGNAL(p3()),this,SLOT(player3()));
       emit p3();
       break;
   case 4:
       connect(this,SIGNAL(p4()),this,SLOT(player4()));
       emit p4();
       break;
   case 5:
       connect(this,SIGNAL(p5()),this,SLOT(player5()));
       emit p5();
       break;
   case 6:
       connect(this,SIGNAL(p6()),this,SLOT(player6()));
       emit p6();
       break;
   case 7:
       connect(this,SIGNAL(p7()),this,SLOT(player7()));
       emit p7();
       break;
   case 8:
       connect(this,SIGNAL(p8()),this,SLOT(player8()));
       emit p8();
       break;
   }

}
if(count>35){
    QFile file ("c:/Data.txt");
     if(!file.open(QFile:: ReadOnly | QFile:: Text)){
       qDebug()<<"okunmuyor";
     }
     QTextStream in(&file);

      text1 = in.readAll();
      mlist=text1.split(" ",QString::SkipEmptyParts);
      qDebug()<<mlist;
     file.close();

  if(test==text1 && con!=mlist.at(0)){
     }
    else {
    //  if(con==mlist.at(0)){

         ui->label_4->setText(text1);
         if(mlist.at(1)=="Zar\n" && b==0){
             connect(this,SIGNAL(zarr()),this,SLOT(zar()));
             emit zarr();
             disconnect(this,SIGNAL(zarr()),this,SLOT(zar()));
             qDebug()<<"ggggggg";
         }
         else if (mlist.at(1)=="al\n") {
             connect(this,SIGNAL(al()),this,SLOT(buy()));
             emit al();
             disconnect(this,SIGNAL(al()),this,SLOT(buy()));

         }
         else if (mlist.at(1)=="done\n") {

             connect(this,SIGNAL(done()),this,SLOT(donee()));
             emit done();
             disconnect(this,SIGNAL(done()),this,SLOT(donee()));
             b=0;


         }
         else if (mlist.at(1)=="build\n"){
             qDebug()<<text1<<test<<mlist.at(0);
             connect(this,SIGNAL(bbb()),this,SLOT(build()));
             emit bbb();
             disconnect(this,SIGNAL(bbb()),this,SLOT(build()));
          }
         else if (mlist.at(1)=="sat") {
             connect(this,SIGNAL(sat()),this,SLOT(satt()));
             emit sat();
             disconnect(this,SIGNAL(sat()),this,SLOT(satt()));
         }
         else if (mlist.at(1)=="teklif\n"){
             connect(this,SIGNAL(offer()),this,SLOT(offer()));
             emit offer();
             disconnect(this,SIGNAL(offer()),this,SLOT(offer()));
          }

         else {
qDebug()<<"else";
         }
         test=text1;
//}
}


}
qDebug ()<<count;
count1++;
 count++;

}

 int top[8],son[8],queue=0,qop;
void MainWindow ::zar(){
    int el=0;
    for(int b=0; b<8 ; b++){

        if( players[b].name== " " || players[b].name=="  ")
        {
         el++;
        }
       }
    if(el==7){
        for(int b=0 ; b<8;b++){

            if(players[b].name!= " "  && players[b].name!="  "){
                ui->messagebox->setText("WINNER =>" + players[b].name);
            }
        }
    }
    qDebug()<<"selin yaptı";
if(b==0){
    b=1;
   qop=queue%nop;
   switch(qop){
p1:case 0:
       if(players[qop].code==mlist.at(0)){
            ll=0;
           for(int g=0;g<citylist1->length();g++){
               citylist1[g]=" ";
           }
           for(int i=0;i<40;i++){
               if(array[i].owner==players[qop].name){
                    citylist1[ll]=array[i].name;
                    ll++;
               }
           }
            ui->cityname->setText(" ");
           ui->cityname->setText(citylist1[0]+"  "+citylist1[1]+"  "+citylist1[2]+"\n"+citylist1[3]+"  "+citylist1[4]+"  "+citylist1[5]+"\n"+citylist1[6]+"  "+citylist1[7]+"  "+citylist1[8]+"  "+citylist1[9]);

           int zar1=(rand()%6+1);
           int zar2=(rand()%6+1);
           switch(zar1){
           case 1:ui->z1->setVisible(true); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
               break;
           case 2:ui->z1->setVisible(false);ui->z2->setVisible(true); ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
               break;
           case 3:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(true);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
               break;
           case 4:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(true); ui->z5->setVisible(false);ui->z6->setVisible(false);
               break;
           case 5:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false); ui->z5->setVisible(true);ui->z6->setVisible(false);
               break;
           case 6:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(true);
               break;
           }
           switch(zar2){
           case 1:ui->z11->setVisible(true); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
               break;
           case 2:ui->z11->setVisible(false); ui->z22->setVisible(true); ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
               break;
           case 3:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(true);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(false);
               break;
           case 4:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false); ui->z44->setVisible(true);ui->z55->setVisible(false);ui->z66->setVisible(false);
               break;
           case 5:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(true); ui->z66->setVisible(false);
               break;
           case 6:ui->z11->setVisible(false);ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(true);
               break;
           }
           int topz=zar1+zar2;
           qDebug()<<"p1"<<topz<<top[0];
       if((array[son[qop]].x==0 && array[son[qop]].y==0) ||(array[son[qop]].x==740 && array[son[qop]].y==740) ){
          ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
           if(y[qop]==3){
               players[qop].balance=players[qop].balance-50;
               y[qop]=1;
           }
           else{
           if(zar1==zar2){
               y[qop]=1;
               goto p11;
           }
           else {
               y[qop]++;
               goto son;
           }
           }
       }
      /* if(players[0].name==" "){
           queue=queue+1;
       goto p2;
       }
       else if(players[0].name=="  "){
       goto p2;
       }
               else{*/
   p11:     top[0]=top[0]+topz;
        son[0]=top[0]%40;
        qDebug() <<topz << top[0];
       ui->siyahpiyon->move(array[son[0]].x,array[son[0]].y);
         ui->siyahpiyon->setVisible(true);
       qDebug()<<"siyah"<< topz<<top[0];
      ui->INFPLAYER->setText("\n Name =>" + players[0].name + "\n\n"+ "Money =>" + QString::number( players[0].balance) + "\n\n");
      ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[0]].name +
                               "\n Owner =>" + array[son[0]].owner +
                                "\n Price of City =>" + QString::number(array[son[0]].cost) +
                                 "\n Rent of City  =>" +  QString::number(array[son[0]].rent) +
                                "\n Rent of City For One House =>" +  QString::number(array[son[0]].rent1h) +
                                "\n Rent of City For Two House =>" + QString::number(array[son[0]].rent2h) +
                                "\n Rent of City For Three House =>" + QString::number(array[son[0]].rent3h) +
                                "\n Rent of City For Four House =>" + QString::number(array[son[0]].rent4h) +
                                 "\n Rent of City For Hotel =>" + QString::number(array[son[0]].renthotel) );



      if(array[son[0]].owner=="bank"){
      ui->buybutton->setEnabled(true);
      ui->buildbutton->setEnabled(true);
     }else{
        ui->buybutton->setEnabled(false);
        ui->sellbutton->setEnabled(false);
        ui->buildbutton->setEnabled(false);
        for(int i=0;i<8;i++){
            if(array[son[qop]].owner==players[qop].name){
                  ui->buildbutton->setEnabled(true);
                  break;
            }
            if(array[son[qop]].owner==players[i].name){
                switch(array[son[qop]].levelofcard){
                case 0:players[i].balance=players[i].balance+array[son[qop]].rent;
                    players[qop].balance=players[qop].balance-array[son[qop]].rent;
                    ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                    break;
                case 1: players[i].balance=players[i].balance+array[son[qop]].rent1h;
                    players[qop].balance=players[qop].balance-array[son[qop]].rent1h;
                    ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                    break;
                case 2: players[i].balance=players[i].balance+array[son[qop]].rent2h;
                    players[qop].balance=players[qop].balance-array[son[qop]].rent2h;
                    ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                    break;
                case 3: players[i].balance=players[i].balance+array[son[qop]].rent3h;
                    players[qop].balance=players[qop].balance-array[son[qop]].rent3h;
                    ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                    break;
                case 4: players[i].balance=players[i].balance+array[son[qop]].rent4h;
                    players[qop].balance=players[qop].balance-array[son[qop]].rent4h;
                    ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                    break;
                case 5: players[i].balance=players[i].balance+array[son[qop]].renthotel;
                    players[qop].balance=players[qop].balance-array[son[qop]].renthotel;
                    ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                    break;
                }

            }
        }
       }


       }
       else {
           goto zarson;
       }
       if(players[1].name==" "){
                  queue=queue+1;
              }



break;

p2:case 1:
       if(players[qop].code==mlist.at(0)){
            lll=0;
           for(int g=0;g<citylist2->length();g++){
               citylist2[g]=" ";
           }
           for(int i=0;i<40;i++){
               if(array[i].owner==players[qop].name){
                    citylist2[lll]=array[i].name;
                    lll++;
               }
           }
           ui->cityname->setText(" ");
          ui->cityname->setText(citylist2[0]+"  "+citylist2[1]+"  "+citylist2[2]+"\n"+citylist2[3]+"  "+citylist2[4]+"  "+
                  citylist2[5]+"\n"+citylist2[6]+"  "+citylist2[7]+"  "+citylist2[8]+"  "+citylist2[9]);
 if(players[qop].code==mlist.at(0)){
     int zar1=(rand()%6+1);
     int zar2=(rand()%6+1);
     switch(zar1){
     case 1:ui->z1->setVisible(true); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
         break;
     case 2:ui->z1->setVisible(false);ui->z2->setVisible(true); ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
         break;
     case 3:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(true);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
         break;
     case 4:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(true); ui->z5->setVisible(false);ui->z6->setVisible(false);
         break;
     case 5:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false); ui->z5->setVisible(true);ui->z6->setVisible(false);
         break;
     case 6:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(true);
         break;
     }
     switch(zar2){
     case 1:ui->z11->setVisible(true); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
         break;
     case 2:ui->z11->setVisible(false); ui->z22->setVisible(true); ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
         break;
     case 3:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(true);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(false);
         break;
     case 4:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false); ui->z44->setVisible(true);ui->z55->setVisible(false);ui->z66->setVisible(false);
         break;
     case 5:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(true); ui->z66->setVisible(false);
         break;
     case 6:ui->z11->setVisible(false);ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(true);
         break;
     }
     int topz=zar1+zar2;
                qDebug()<<topz<<top[1];
       if((array[son[qop]].x==0 && array[son[qop]].y==0) ||(array[son[qop]].x==740 && array[son[qop]].y==740)){
     ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
           if(y[qop]==3){
               players[qop].balance=players[qop].balance-50;
               y[qop]=1;
           }
           else{
           if(zar1==zar2){
               y[qop]=1;
               goto p22;
           }
           else {
               y[qop]++;
               goto son;
           }
           }
       }
       /*if(players[1].name==" "){
           queue=queue+1;
           goto p3;
           }
       else if(players[1].name=="  "){
       goto p3;
       }else{*/
    p22:    top[1]=top[1]+topz;
        son[1]=top[1]%40;
        qDebug()<<"p2"<<topz<<top[1];
       ui->beyazpiyon->move(array[son[1]].x,array[son[1]].y);
       ui->beyazpiyon->setVisible(true);
       ui->INFPLAYER->setText("\n Name =>" + players[1].name + "\n\n"+ "Money =>" + QString::number( players[1].balance) + "\n\n");
       ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[1]].name +
                                "\n Owner =>" + array[son[1]].owner +
                                 "\n Price of City =>" + QString::number(array[son[1]].cost) +
                                  "\n Rent of City  =>" +  QString::number(array[son[1]].rent) +
                                 "\n Rent of City For One House =>" +  QString::number(array[son[1]].rent1h) +
                                 "\n Rent of City For Two House =>" + QString::number(array[son[1]].rent2h) +
                                 "\n Rent of City For Three House =>" + QString::number(array[son[1]].rent3h) +
                                 "\n Rent of City For Four House =>" + QString::number(array[son[1]].rent4h) +
                                  "\n Rent of City For Hotel =>" + QString::number(array[son[1]].renthotel) );


       if(array[son[qop]].owner=="bank"){
         ui->buybutton->setEnabled(true);
         ui->buildbutton->setEnabled(true);
        }else{
           ui->buybutton->setEnabled(false);
           ui->sellbutton->setEnabled(false);
           ui->buildbutton->setEnabled(false);
           for(int i=0;i<8;i++){
               if(array[son[qop]].owner==players[qop].name){
                     ui->buildbutton->setEnabled(true);
                     break;
               }
               if(array[son[qop]].owner==players[i].name){
                   switch(array[son[qop]].levelofcard){
                   case 0:players[i].balance=players[i].balance+array[son[qop]].rent;
                       players[qop].balance=players[qop].balance-array[son[qop]].rent;
                       ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                       break;
                   case 1: players[i].balance=players[i].balance+array[son[qop]].rent1h;
                       players[qop].balance=players[qop].balance-array[son[qop]].rent1h;
                       ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                       break;
                   case 2: players[i].balance=players[i].balance+array[son[qop]].rent2h;
                       players[qop].balance=players[qop].balance-array[son[qop]].rent2h;
                       ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                       break;
                   case 3: players[i].balance=players[i].balance+array[son[qop]].rent3h;
                       players[qop].balance=players[qop].balance-array[son[qop]].rent3h;
                       ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                       break;
                   case 4: players[i].balance=players[i].balance+array[son[qop]].rent4h;
                       players[qop].balance=players[qop].balance-array[son[qop]].rent4h;
                       ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                       break;
                   case 5: players[i].balance=players[i].balance+array[son[qop]].renthotel;
                       players[qop].balance=players[qop].balance-array[son[qop]].renthotel;
                       ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                       break;
                   }

               }
           }
       }


       }
}
 else {
     goto zarson;
 }
if(players[2].name==" "){
            queue=queue+1;
        }
 else if(players[2].name=="  "){
     if(players[0].name==" "){
         queue=queue+1;
     }
 }
break;

p3:case 2:
        if(players[qop].code==mlist.at(0)){
            ll=0;
           for(int g=0;g<citylist3->length();g++){
               citylist3[g]=" ";
           }
           for(int i=0;i<40;i++){
               if(array[i].owner==players[qop].name){
                    citylist3[ll]=array[i].name;
                    ll++;
               }
           }
            int zar1=(rand()%6+1);
            int zar2=(rand()%6+1);
            switch(zar1){
            case 1:ui->z1->setVisible(true); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 2:ui->z1->setVisible(false);ui->z2->setVisible(true); ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 3:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(true);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 4:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(true); ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 5:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false); ui->z5->setVisible(true);ui->z6->setVisible(false);
                break;
            case 6:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(true);
                break;
            }
            switch(zar2){
            case 1:ui->z11->setVisible(true); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 2:ui->z11->setVisible(false); ui->z22->setVisible(true); ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 3:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(true);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 4:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false); ui->z44->setVisible(true);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 5:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(true); ui->z66->setVisible(false);
                break;
            case 6:ui->z11->setVisible(false);ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(true);
                break;
            }
            int topz=zar1+zar2;
       if((array[son[qop]].x==0 && array[son[qop]].y==0) ||(array[son[qop]].x==740 && array[son[qop]].y==740)){
  ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
           if(y[qop]==3){
               players[qop].balance=players[qop].balance-50;
               y[qop]=1;
           }
           else{
           if(zar1==zar2){
               y[qop]=1;
               goto p33;
           }
           else {
               y[qop]++;
               goto son;
           }
           }
       }
       /*if(players[2].name==" "){
           queue=queue+1;
           goto p4;
           } else if(players[2].name=="  "){
           goto p4;
           }else{*/
   p33:     top[2]=top[2]+topz;
        son[2]=top[2]%40;
         ui->kirmizipiyon->move(array[son[2]].x,array[son[2]].y);
         ui->INFPLAYER->setText("\n Name =>" + players[2].name + "\n\n"+ "Money =>" + QString::number( players[2].balance) + "\n\n");
         ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[2]].name +
                                  "\n Owner =>" + array[son[2]].owner +
                                   "\n Price of City =>" + QString::number(array[son[2]].cost) +
                                    "\n Rent of City  =>" +  QString::number(array[son[2]].rent) +
                                   "\n Rent of City For One House =>" +  QString::number(array[son[2]].rent1h) +
                                   "\n Rent of City For Two House =>" + QString::number(array[son[2]].rent2h) +
                                   "\n Rent of City For Three House =>" + QString::number(array[son[2]].rent3h) +
                                   "\n Rent of City For Four House =>" + QString::number(array[son[2]].rent4h) +
                                    "\n Rent of City For Hotel =>" + QString::number(array[son[2]].renthotel) );


         if(array[son[qop]].owner=="bank"){
           ui->buybutton->setEnabled(true);
           ui->buildbutton->setEnabled(true);
          }else{
             ui->buybutton->setEnabled(false);
             ui->sellbutton->setEnabled(false);
             ui->buildbutton->setEnabled(false);
             for(int i=0;i<8;i++){
                 if(array[son[qop]].owner==players[qop].name){
                       ui->buildbutton->setEnabled(true);
                       break;
                 }
                 if(array[son[qop]].owner==players[i].name){
                     switch(array[son[qop]].levelofcard){
                     case 0:players[i].balance=players[i].balance+array[son[qop]].rent;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 1: players[i].balance=players[i].balance+array[son[qop]].rent1h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent1h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 2: players[i].balance=players[i].balance+array[son[qop]].rent2h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent2h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 3: players[i].balance=players[i].balance+array[son[qop]].rent3h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent3h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 4: players[i].balance=players[i].balance+array[son[qop]].rent4h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent4h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 5: players[i].balance=players[i].balance+array[son[qop]].renthotel;
                         players[qop].balance=players[qop].balance-array[son[qop]].renthotel;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     }

                 }
             }
         }
       }

        else {
            goto zarson;
        }
        if(players[3].name==" "){
                   queue=queue+1;
               }
        else if(players[3].name=="  "){
            if(players[0].name==" "){
                queue=queue+1;
            }
        }
  break;
p4:case 3:
        if(players[qop].code==mlist.at(0)){
            ll=0;
           for(int g=0;g<citylist4->length();g++){
               citylist4[g]=" ";
           }
           for(int i=0;i<40;i++){
               if(array[i].owner==players[qop].name){
                    citylist4[ll]=array[i].name;
                    ll++;
               }
           }
            int zar1=(rand()%6+1);
            int zar2=(rand()%6+1);
            switch(zar1){
            case 1:ui->z1->setVisible(true); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 2:ui->z1->setVisible(false);ui->z2->setVisible(true); ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 3:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(true);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 4:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(true); ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 5:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false); ui->z5->setVisible(true);ui->z6->setVisible(false);
                break;
            case 6:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(true);
                break;
            }
            switch(zar2){
            case 1:ui->z11->setVisible(true); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 2:ui->z11->setVisible(false); ui->z22->setVisible(true); ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 3:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(true);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 4:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false); ui->z44->setVisible(true);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 5:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(true); ui->z66->setVisible(false);
                break;
            case 6:ui->z11->setVisible(false);ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(true);
                break;
            }
            int topz=zar1+zar2;
       if((array[son[qop]].x==0 && array[son[qop]].y==0) ||(array[son[qop]].x==740 && array[son[qop]].y==740)){
ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
           if(y[qop]%3==0){
               players[qop].balance=players[qop].balance-50;
               y[qop]=1;
           }
           else{
           if(zar1==zar2){
               y[qop]=1;
               goto p44;
           }
           else {
               y[qop]++;
               goto son;
           }
           }
       }
       if(players[3].name==" "){
           queue=queue+1;
           goto p5;
           }
       else if(players[3].name=="  "){
       goto p5;
       }else{
    p44:    top[3]=top[3]+topz;
        son[3]=top[3]%40;
         ui->yesilpiyon->move(array[son[3]].x,array[son[3]].y);
         ui->INFPLAYER->setText("\n Name =>" + players[3].name + "\n\n"+ "Money =>" + QString::number( players[3].balance) + "\n\n");

         ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[3]].name +
                                  "\n Owner =>" + array[son[3]].owner +
                                   "\n Price of City =>" + QString::number(array[son[3]].cost) +
                                    "\n Rent of City  =>" +  QString::number(array[son[3]].rent) +
                                   "\n Rent of City For One House =>" +  QString::number(array[son[3]].rent1h) +
                                   "\n Rent of City For Two House =>" + QString::number(array[son[3]].rent2h) +
                                   "\n Rent of City For Three House =>" + QString::number(array[son[3]].rent3h) +
                                   "\n Rent of City For Four House =>" + QString::number(array[son[3]].rent4h) +
                                    "\n Rent of City For Hotel =>" + QString::number(array[son[3]].renthotel) );


         if(array[son[qop]].owner=="bank"){
           ui->buybutton->setEnabled(true);
           ui->buildbutton->setEnabled(true);
          }else{
             ui->buybutton->setEnabled(false);
             ui->sellbutton->setEnabled(false);
             ui->buildbutton->setEnabled(false);
             for(int i=0;i<8;i++){
                 if(array[son[qop]].owner==players[qop].name){
                       ui->buildbutton->setEnabled(true);
                       break;
                 }
                 if(array[son[qop]].owner==players[i].name){
                     switch(array[son[qop]].levelofcard){
                     case 0:players[i].balance=players[i].balance+array[son[qop]].rent;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 1: players[i].balance=players[i].balance+array[son[qop]].rent1h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent1h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 2: players[i].balance=players[i].balance+array[son[qop]].rent2h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent2h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 3: players[i].balance=players[i].balance+array[son[qop]].rent3h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent3h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 4: players[i].balance=players[i].balance+array[son[qop]].rent4h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent4h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 5: players[i].balance=players[i].balance+array[son[qop]].renthotel;
                         players[qop].balance=players[qop].balance-array[son[qop]].renthotel;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     }

                 }
             }
         }
       }
        }
        else {
            goto zarson;
        }
        if(players[4].name==" "){
                   queue=queue+1;
               }
        else if(players[4].name=="  "){
            if(players[0].name==" "){
                queue=queue+1;
            }
        }
break;

p5:case 4:
        if(players[qop].code==mlist.at(0)){
            ll=0;
           for(int g=0;g<citylist5->length();g++){
               citylist5[g]=" ";
           }
           for(int i=0;i<40;i++){
               if(array[i].owner==players[qop].name){
                    citylist5[ll]=array[i].name;
                    ll++;
               }
           }
            int zar1=(rand()%6+1);
            int zar2=(rand()%6+1);
            switch(zar1){
            case 1:ui->z1->setVisible(true); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 2:ui->z1->setVisible(false);ui->z2->setVisible(true); ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 3:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(true);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 4:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(true); ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 5:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false); ui->z5->setVisible(true);ui->z6->setVisible(false);
                break;
            case 6:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(true);
                break;
            }
            switch(zar2){
            case 1:ui->z11->setVisible(true); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 2:ui->z11->setVisible(false); ui->z22->setVisible(true); ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 3:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(true);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 4:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false); ui->z44->setVisible(true);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 5:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(true); ui->z66->setVisible(false);
                break;
            case 6:ui->z11->setVisible(false);ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(true);
                break;
            }
            int topz=zar1+zar2;
       if((array[son[qop]].x==0 && array[son[qop]].y==0) ||(array[son[qop]].x==740 && array[son[qop]].y==740)){
ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
           if(y[qop]%3==0){
               players[qop].balance=players[qop].balance-50;
               y[qop]=1;
           }
           else{
           if(zar1==zar2){
               y[qop]=1;
               goto p55;
           }
           else {
               y[qop]++;
               goto son;
           }
           }
       }
       /*if(players[4].name==" "){
           queue=queue+1;
           goto p6;
           }
       else if(players[4].name=="  "){
       goto p6;
       }else{*/
   p55:     top[4]=top[4]+topz;
        son[4]=top[4]%40;
         ui->mavipiyon->move(array[son[4]].x,array[son[4]].y);
         ui->INFPLAYER->setText("\n Name =>" + players[4].name + "\n\n"+ "Money =>" + QString::number( players[4].balance) + "\n\n");
         ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[4]].name +
                                  "\n Owner =>" + array[son[4]].owner +
                                   "\n Price of City =>" + QString::number(array[son[4]].cost) +
                                    "\n Rent of City  =>" +  QString::number(array[son[4]].rent) +
                                   "\n Rent of City For One House =>" +  QString::number(array[son[4]].rent1h) +
                                   "\n Rent of City For Two House =>" + QString::number(array[son[4]].rent2h) +
                                   "\n Rent of City For Three House =>" + QString::number(array[son[4]].rent3h) +
                                   "\n Rent of City For Four House =>" + QString::number(array[son[4]].rent4h) +
                                    "\n Rent of City For Hotel =>" + QString::number(array[son[4]].renthotel) );


         if(array[son[qop]].owner=="bank"){
           ui->buybutton->setEnabled(true);
           ui->buildbutton->setEnabled(true);
          }else{
             ui->buybutton->setEnabled(false);
             ui->sellbutton->setEnabled(false);
             ui->buildbutton->setEnabled(false);
             for(int i=0;i<8;i++){
                 if(array[son[qop]].owner==players[qop].name){
                       ui->buildbutton->setEnabled(true);
                       break;
                 }
                 if(array[son[qop]].owner==players[i].name){
                     switch(array[son[qop]].levelofcard){
                     case 0:players[i].balance=players[i].balance+array[son[qop]].rent;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 1: players[i].balance=players[i].balance+array[son[qop]].rent1h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent1h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 2: players[i].balance=players[i].balance+array[son[qop]].rent2h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent2h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 3: players[i].balance=players[i].balance+array[son[qop]].rent3h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent3h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 4: players[i].balance=players[i].balance+array[son[qop]].rent4h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent4h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 5: players[i].balance=players[i].balance+array[son[qop]].renthotel;
                         players[qop].balance=players[qop].balance-array[son[qop]].renthotel;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     }

                 }
             }
         }
       }else {
goto zarson;
}
        if(players[5].name==" "){
                   queue=queue+1;
               }
        else if(players[5].name=="  "){
            if(players[0].name==" "){
                queue=queue+1;
            }
        }
break;
p6:case 5:
        if(players[qop].code==mlist.at(0)){
            ll=0;
           for(int g=0;g<citylist6->length();g++){
               citylist6[g]=" ";
           }
           for(int i=0;i<40;i++){
               if(array[i].owner==players[qop].name){
                    citylist6[ll]=array[i].name;
                    ll++;
               }
           }
            int zar1=(rand()%6+1);
            int zar2=(rand()%6+1);
            switch(zar1){
            case 1:ui->z1->setVisible(true); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 2:ui->z1->setVisible(false);ui->z2->setVisible(true); ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 3:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(true);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 4:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(true); ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 5:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false); ui->z5->setVisible(true);ui->z6->setVisible(false);
                break;
            case 6:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(true);
                break;
            }
            switch(zar2){
            case 1:ui->z11->setVisible(true); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 2:ui->z11->setVisible(false); ui->z22->setVisible(true); ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 3:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(true);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 4:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false); ui->z44->setVisible(true);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 5:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(true); ui->z66->setVisible(false);
                break;
            case 6:ui->z11->setVisible(false);ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(true);
                break;
            }
            int topz=zar1+zar2;
       if((array[son[qop]].x==0 && array[son[qop]].y==0) ||(array[son[qop]].x==740 && array[son[qop]].y==740)){
ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
           if(y[qop]%3==0){
               players[qop].balance=players[qop].balance-50;
               y[qop]=1;
           }
           else{
           if(zar1==zar2){
               y[qop]=1;
               goto p66;
           }
           else {
               y[qop]++;
               goto son;
           }
           }
       }
       /*if(players[5].name==" "){
           queue=queue+1;
           goto p7;
           }
       else if(players[5].name=="  "){
       goto p7;
       }else{*/
   p66:     top[5]=top[5]+topz;
        son[5]=top[5]%40;
         ui->kahvepiyon->move(array[son[5]].x,array[son[5]].y);
         ui->INFPLAYER->setText("\n Name =>" + players[5].name + "\n\n"+ "Money =>" + QString::number( players[5].balance) + "\n\n");
         ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[5]].name +
                                  "\n Owner =>" + array[son[5]].owner +
                                   "\n Price of City =>" + QString::number(array[son[5]].cost) +
                                    "\n Rent of City  =>" +  QString::number(array[son[5]].rent) +
                                   "\n Rent of City For One House =>" +  QString::number(array[son[5]].rent1h) +
                                   "\n Rent of City For Two House =>" + QString::number(array[son[5]].rent2h) +
                                   "\n Rent of City For Three House =>" + QString::number(array[son[5]].rent3h) +
                                   "\n Rent of City For Four House =>" + QString::number(array[son[5]].rent4h) +
                                    "\n Rent of City For Hotel =>" + QString::number(array[son[5]].renthotel) );


         if(array[son[qop]].owner=="bank"){
           ui->buybutton->setEnabled(true);
           ui->buildbutton->setEnabled(true);
          }else{
             ui->buybutton->setEnabled(false);
             ui->sellbutton->setEnabled(false);
             ui->buildbutton->setEnabled(false);
             for(int i=0;i<8;i++){
                 if(array[son[qop]].owner==players[qop].name){
                       ui->buildbutton->setEnabled(true);
                       break;
                 }
                 if(array[son[qop]].owner==players[i].name){
                     switch(array[son[qop]].levelofcard){
                     case 0:players[i].balance=players[i].balance+array[son[qop]].rent;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 1: players[i].balance=players[i].balance+array[son[qop]].rent1h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent1h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 2: players[i].balance=players[i].balance+array[son[qop]].rent2h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent2h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 3: players[i].balance=players[i].balance+array[son[qop]].rent3h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent3h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 4: players[i].balance=players[i].balance+array[son[qop]].rent4h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent4h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 5: players[i].balance=players[i].balance+array[son[qop]].renthotel;
                         players[qop].balance=players[qop].balance-array[son[qop]].renthotel;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     }

                 }
             }
         }
       }

        else {
            goto zarson;
        }
        if(players[6].name==" "){
                   queue=queue+1;
               }
        else if(players[6].name=="  "){
            if(players[0].name==" "){
                queue=queue+1;
            }
        }
break;

p7:case 6:
        if(players[qop].code==mlist.at(0)){
            ll=0;
           for(int g=0;g<citylist7->length();g++){
               citylist7[g]=" ";
           }
           for(int i=0;i<40;i++){
               if(array[i].owner==players[qop].name){
                    citylist7[ll]=array[i].name;
                    ll++;
               }
           }
            int zar1=(rand()%6+1);
            int zar2=(rand()%6+1);
            switch(zar1){
            case 1:ui->z1->setVisible(true); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 2:ui->z1->setVisible(false);ui->z2->setVisible(true); ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 3:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(true);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 4:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(true); ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 5:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false); ui->z5->setVisible(true);ui->z6->setVisible(false);
                break;
            case 6:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(true);
                break;
            }
            switch(zar2){
            case 1:ui->z11->setVisible(true); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 2:ui->z11->setVisible(false); ui->z22->setVisible(true); ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 3:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(true);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 4:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false); ui->z44->setVisible(true);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 5:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(true); ui->z66->setVisible(false);
                break;
            case 6:ui->z11->setVisible(false);ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(true);
                break;
            }
            int topz=zar1+zar2;
       if((array[son[qop]].x==0 && array[son[qop]].y==0) ||(array[son[qop]].x==740 && array[son[qop]].y==740)){
ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
           if(y[qop]%3==0){
               players[qop].balance=players[qop].balance-50;
               y[qop]=1;
           }
           else{
           if(zar1==zar2){
               y[qop]=1;
               goto p77;
           }
           else {
               y[qop]++;
               goto son;
           }
           }
       }
      /* if(players[6].name==" "){
           queue=queue+1;
           goto p8;
           }
       else if(players[6].name=="  "){
       goto p8;
       }else{*/
  p77:      top[6]=top[6]+topz;
        son[6]=top[6]%40;
         ui->morpiyon->move(array[son[6]].x,array[son[6]].y);
         ui->INFPLAYER->setText("\n Name =>" + players[6].name + "\n\n"+ "Money =>" + QString::number( players[6].balance) + "\n\n");
         ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[6]].name +
                                  "\n Owner =>" + array[son[6]].owner +
                                   "\n Price of City =>" + QString::number(array[son[6]].cost) +
                                    "\n Rent of City  =>" +  QString::number(array[son[6]].rent) +
                                   "\n Rent of City For One House =>" +  QString::number(array[son[6]].rent1h) +
                                   "\n Rent of City For Two House =>" + QString::number(array[son[6]].rent2h) +
                                   "\n Rent of City For Three House =>" + QString::number(array[son[6]].rent3h) +
                                   "\n Rent of City For Four House =>" + QString::number(array[son[6]].rent4h) +
                                    "\n Rent of City For Hotel =>" + QString::number(array[son[6]].renthotel) );


         if(array[son[qop]].owner=="bank"){
           ui->buybutton->setEnabled(true);
           ui->buildbutton->setEnabled(true);
          }else{
             ui->buybutton->setEnabled(false);
             ui->sellbutton->setEnabled(false);
             ui->buildbutton->setEnabled(false);
             for(int i=0;i<8;i++){
                 if(array[son[qop]].owner==players[qop].name){
                       ui->buildbutton->setEnabled(true);
                       break;
                 }
                 if(array[son[qop]].owner==players[i].name){
                     switch(array[son[qop]].levelofcard){
                     case 0:players[i].balance=players[i].balance+array[son[qop]].rent;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 1: players[i].balance=players[i].balance+array[son[qop]].rent1h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent1h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 2: players[i].balance=players[i].balance+array[son[qop]].rent2h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent2h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 3: players[i].balance=players[i].balance+array[son[qop]].rent3h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent3h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 4: players[i].balance=players[i].balance+array[son[qop]].rent4h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent4h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 5: players[i].balance=players[i].balance+array[son[qop]].renthotel;
                         players[qop].balance=players[qop].balance-array[son[qop]].renthotel;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     }

                 }
             }
         }
       }

        else {
            goto zarson;
        }
        if(players[7].name==" "){
                   queue=queue+1;
               }
        else if(players[7].name=="  "){
            if(players[0].name==" "){
                queue=queue+1;
            }
        }
break;

p8:case 7:
        if(players[qop].code==mlist.at(0)){
            ll=0;
           for(int g=0;g<citylist8->length();g++){
               citylist8[g]=" ";
           }
           for(int i=0;i<40;i++){
               if(array[i].owner==players[qop].name){
                    citylist8[ll]=array[i].name;
                    ll++;
               }
           }
            int zar1=(rand()%6+1);
            int zar2=(rand()%6+1);
            switch(zar1){
            case 1:ui->z1->setVisible(true); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 2:ui->z1->setVisible(false);ui->z2->setVisible(true); ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 3:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(true);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 4:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(true); ui->z5->setVisible(false);ui->z6->setVisible(false);
                break;
            case 5:ui->z1->setVisible(false);ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false); ui->z5->setVisible(true);ui->z6->setVisible(false);
                break;
            case 6:ui->z1->setVisible(false); ui->z2->setVisible(false);ui->z3->setVisible(false);ui->z4->setVisible(false);ui->z5->setVisible(false);ui->z6->setVisible(true);
                break;
            }
            switch(zar2){
            case 1:ui->z11->setVisible(true); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 2:ui->z11->setVisible(false); ui->z22->setVisible(true); ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false); ui->z66->setVisible(false);
                break;
            case 3:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(true);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 4:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false); ui->z44->setVisible(true);ui->z55->setVisible(false);ui->z66->setVisible(false);
                break;
            case 5:ui->z11->setVisible(false); ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(true); ui->z66->setVisible(false);
                break;
            case 6:ui->z11->setVisible(false);ui->z22->setVisible(false);ui->z33->setVisible(false);ui->z44->setVisible(false);ui->z55->setVisible(false);ui->z66->setVisible(true);
                break;
            }
            int topz=zar1+zar2;
       if((array[son[qop]].x==0 && array[son[qop]].y==0) ||(array[son[qop]].x==740 && array[son[qop]].y==740)){
ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
           if(y[qop]%3==0){
               players[qop].balance=players[qop].balance-50;
               y[qop]=1;
           }
           else{
           if(zar1==zar2){
               y[qop]=1;
               goto p88;
           }
           else {
               y[qop]++;
               goto son;
           }
           }
       }
       /*if(players[7].name==" "){
           queue=queue+1;
           goto p1;
           }
       else if(players[7].name=="  "){
       goto p1;
       }else{*/
    p88:    top[7]=top[7]+topz;
        son[7]=top[7]%40;
         ui->saripiyon->move(array[son[7]].x,array[son[7]].y);
         ui->INFPLAYER->setText("\n Name =>" + players[7].name + "\n\n"+ "Money =>" + QString::number( players[7].balance) + "\n\n");
         ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[7]].name +
                                  "\n Owner =>" + array[son[7]].owner +
                                   "\n Price of City =>" + QString::number(array[son[7]].cost) +
                                    "\n Rent of City  =>" +  QString::number(array[son[7]].rent) +
                                   "\n Rent of City For One House =>" +  QString::number(array[son[7]].rent1h) +
                                   "\n Rent of City For Two House =>" + QString::number(array[son[7]].rent2h) +
                                   "\n Rent of City For Three House =>" + QString::number(array[son[7]].rent3h) +
                                   "\n Rent of City For Four House =>" + QString::number(array[son[7]].rent4h) +
                                    "\n Rent of City For Hotel =>" + QString::number(array[son[7]].renthotel) );


         if(array[son[qop]].owner=="bank"){
           ui->buybutton->setEnabled(true);
           ui->buildbutton->setEnabled(true);
          }else{
             ui->buybutton->setEnabled(false);
             ui->sellbutton->setEnabled(false);
             ui->buildbutton->setEnabled(false);
             for(int i=0;i<8;i++){
                 if(array[son[qop]].owner==players[qop].name){
                       ui->buildbutton->setEnabled(true);
                       break;
                 }
                 if(array[son[qop]].owner==players[i].name){
                     switch(array[son[qop]].levelofcard){
                     case 0:players[i].balance=players[i].balance+array[son[qop]].rent;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 1: players[i].balance=players[i].balance+array[son[qop]].rent1h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent1h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 2: players[i].balance=players[i].balance+array[son[qop]].rent2h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent2h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 3: players[i].balance=players[i].balance+array[son[qop]].rent3h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent3h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 4: players[i].balance=players[i].balance+array[son[qop]].rent4h;
                         players[qop].balance=players[qop].balance-array[son[qop]].rent4h;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     case 5: players[i].balance=players[i].balance+array[son[qop]].renthotel;
                         players[qop].balance=players[qop].balance-array[son[qop]].renthotel;
                         ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                         break;
                     }

                 }
             }
         }
       }

        else {
            goto zarson;
        }
        if(players[0].name==" "){
                   queue=queue+1;
               }
break;
}
if(players[qop].balance<=0){
ui->messagebox->setText("GAME OVER!!!!!.");
players[qop].name=" ";
switch(qop){
case 0:ui->siyahpiyon->setVisible(false);
    break;
case 1:ui->beyazpiyon->setVisible(false);
    break;
case 2:ui->kirmizipiyon->setVisible(false);
    break;
case 3:ui->yesilpiyon->setVisible(false);
    break;
case 4:ui->mavipiyon->setVisible(false);
    break;
case 5:ui->kahvepiyon->setVisible(false);
    break;
case 6:ui->morpiyon->setVisible(false);
    break;
case 7:ui->saripiyon->setVisible(false);
    break;
}
for(int i=0;i<40;i++){
    if(array[i].owner==players[qop].name){
        array[i].owner="bank";
    }
}
}
switch(qop){
case 0:if(top[0]>(40*i[0])){
        players[0].balance+=200;
        i[0]=i[0]+1;
        ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
        qDebug()<<"2";
    }
    break;
case 1:if(top[1]>(40*i[1])){
        players[1].balance+=200;
      i[1]=i[1]+1;
      ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
    qDebug()<<"3";
    }
    break;
case 2:if(top[2]>40*i[qop]){
        players[2].balance+=200;
        i[2]++;
        ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
    }
    break;
case 3:if(top[qop]>40*i[qop]){
        players[qop].balance+=200;
        i[qop]++;
        ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
    }
    break;
case 4:if(top[qop]>40*i[qop]){
        players[qop].balance+=200;
        i[qop]++;
        ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
    }
    break;
case 5:if(top[qop]>40*i[qop]){
        players[qop].balance+=200;
        i[qop]++;
        ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
    }
    break;
case 6:if(top[qop]>40*i[qop]){
        players[qop].balance+=200;
        i[qop]++;
        ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
    }
    break;
case 7:if(top[qop]>40*i[qop]){
        players[qop].balance+=200;
        i[qop]++;
        ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
    }
    break;
}
    /*if(array[son[qop]].x==0 && array[son[qop]].y==250) || (array[son[qop]].x==750 && array[son[qop]].y==250) || (array[son[qop]].x==600 && array[son[qop]].y==750) ){*/
        if(array[son[qop]].name=="CHEST"){
switch (k1) {
 case 0: players[qop].balance+=50;
         ui->messagebox->setText(players[qop].name + "=> " + kamu[0].name);
ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
            break;

        case 1: for(int x=0 ; x<8 ; x++){
                if(players[x].name!= "  "  && players[x].name!= " " )
                {
                    players[x].balance-=25;
                    players[qop].balance+=25;
                }
            }
                ui->messagebox->setText(players[qop].name + "=> " + kamu[1].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 2: players[qop].balance-=100;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[2].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 3: players[qop].balance+=50;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[3].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 4: players[qop].balance+=100;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[4].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 5:
            players[qop].balance-=50;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[5].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 6:
            players[qop].balance-=50;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[6].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 7:
            players[qop].balance-=50;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[7].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 8:
            players[qop].balance+=200;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[8].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 9:
            players[qop].balance+=100;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[9].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 10:
            players[qop].balance+=100;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[10].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 11:
            players[qop].balance+=25;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[11].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 12:
            players[qop].balance-=200;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[12].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 13:
            players[qop].balance+=200;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[13].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 14:
            players[qop].balance+=50;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[14].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 15:
            players[qop].balance+=25;
                ui->messagebox->setText(players[qop].name + "=> " + kamu[15].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;

        }
        k1=k1+1;
        if(k1==16){
            k1=0;
        }
    }



  /*  if((array[son[qop]].x==180 && array[son[qop]].y==0) || (array[son[qop]].x==750 && array[son[qop]].y==460) || (array[son[qop]].x==250 && array[son[qop]].y==750) ){*/
if(array[son[qop]].name=="CHANCE"){
        switch (k2) {
 case 0: players[qop].balance-=200;
         ui->messagebox->setText(players[qop].name + "=> " + sans[0].name);
ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
            break;

        case 1: for(int x=0 ; x<8 ; x++){
                if(players[x].name!= "  "  && players[x].name!= " " )
                {
                    players[x].balance+=50;
                    players[qop].balance-=50;
                }
            }
                 ui->messagebox->setText(players[qop].name + "=> " + sans[1].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 2: players[qop].balance-=25;
                 ui->messagebox->setText(players[qop].name + "=> " + sans[2].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 3: players[qop].balance+=50;
                  ui->messagebox->setText(players[qop].name + "=> " + sans[3].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 4: players[qop].balance-=100;
                 ui->messagebox->setText(players[qop].name + "=> " + sans[4].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 5:
            players[qop].balance+=150;
                ui->messagebox->setText(players[qop].name + "=> " + sans[5].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 6:
            players[qop].balance-=50;
               ui->messagebox->setText(players[qop].name + "=> " + sans[6].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 7:
            players[qop].balance-=150;
                  ui->messagebox->setText(players[qop].name + "=> " + sans[7].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 8:
            players[qop].balance+=200;
                ui->messagebox->setText(players[qop].name + "=> " + sans[8].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 9:
            players[qop].balance+=50;
                ui->messagebox->setText(players[qop].name + "=> " + sans[9].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 10:
            players[qop].balance-=100;
                 ui->messagebox->setText(players[qop].name + "=> " + sans[10].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 11:
            players[qop].balance+=200;
                ui->messagebox->setText(players[qop].name + "=> " + sans[11].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        case 12:
            players[qop].balance-=75;
               ui->messagebox->setText(players[qop].name + "=> " + sans[12].name);
                ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
                   break;
        }
        k2=k2+1;
        if(k2==16){
            k2=0;
        }
    }

if(array[son[qop]].x==460 && array[son[qop]].y==750)
{
    players[qop].balance-=200;
    ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
}

if(array[son[qop]].x==750 && array[son[qop]].y==600){
    players[qop].balance-=100;
    ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
}
      son:  queue=queue;
 /*int el=0;
for(int b=0; b<8 ; b++){

    if( players[b].name== " " || players[b].name=="  ")
    {
     el++;
    }
   }
if(el==7){
    for(int b=0 ; b<8;b++){

        if(players[b].name!= " "  && players[b].name!="  "){
            ui->messagebox->setText("WINNER =>" + players[b].name);
        }
    }
}*/
zarson:qDebug()<<"wrong player";
}
}

void MainWindow ::offer(){
    qDebug()<<"offera geldi";

    if(sount==30){
    QFile file ("c:/nop.txt");
     if(!file.open(QFile:: ReadOnly | QFile:: Text)){

       qDebug()<<"okunmuyor";
     }
     QTextStream inn(&file);
     text3 = inn.readLine();
      tlist= text3.split(" ", QString::SkipEmptyParts);
      int m=tlist.at(2).toInt();
      for (int i=2;i<25;i+3) {
          if(tlist.at(i).toInt()>m){
              m=tlist.at(i).toInt();
          }
      }

      for(int k=0;k<mlist.length();k++){
          if(m==tlist.at(k).toInt()){
              dist=tlist.at(k-2);
          }
      }
      for(int j=0;j<8;j++){
          if(players[j].code==dist){
              for(int z=0 ; z<40;z++){
                  if(array[z].name==sdk){
                     players[qop].balance-=m;
                     players[j].balance+=m;
                     qDebug()<<array[z].owner;
                  }
              }

          }
      }
     file.close();
  qDebug()<<m;

  sount++;
  qDebug() << sount;
}

}
void MainWindow::buy()
{
    if(array[son[qop]].name=="GELIRVERGISI"||array[son[qop]].name=="GO"||array[son[qop]].name=="CHEST"||array[son[qop]].name=="INJAIL"||
   array[son[qop]].name=="CHANCE"||array[son[qop]].name=="FREEPAEKING"||array[son[qop]].name=="LUXARYTAX"||array[son[qop]].name=="GOTOJAIL"){
        ui->messagebox->setText("you cannot buy this ctiy.");
}else{
    qDebug()<<"buya geldi";
    qDebug()<<array[son[qop]].name;
    if(players[qop].balance-array[son[qop]].cost<=0){
        ui->messagebox->setText("You cannot buy this city!!!");
    }else{
        if(array[son[qop]].owner=="bank"){
array[son[qop]].owner=players[qop].name;
players[qop].balance=players[qop].balance-array[son[qop]].cost;
ui->INFPLAYER->setText("\n Name =>" + players[qop].name + "\n\n"+ "Money =>" + QString::number( players[qop].balance) + "\n\n");
ui->INFPLAYER_2->setText("\n Name of City =>"+  array[son[0]].name +
                         "\n Owner =>" + array[son[0]].owner +
                          "\n Price of City =>" + QString::number(array[son[0]].cost) +
                           "\n Rent of City  =>" +  QString::number(array[son[0]].rent) +
                          "\n Rent of City For One House =>" +  QString::number(array[son[0]].rent1h) +
                          "\n Rent of City For Two House =>" + QString::number(array[son[0]].rent2h) +
                          "\n Rent of City For Three House =>" + QString::number(array[son[0]].rent3h) +
                          "\n Rent of City For Four House =>" + QString::number(array[son[0]].rent4h) +
                           "\n Rent of City For Hotel =>" + QString::number(array[son[0]].renthotel) );
 }
    else{
         ui->messagebox->setText("You cannot buy this city!!!");
    }
}
    }
   // citylist.clear();
    //for(int i=0;i<40;i++){
      //  if(array[i].owner==players[qop].name){
        //     citylist.push_back("  ");
        //    citylist.push_back(array[i].name);
     //   }
                           /* for (QStringList::Iterator S = citylist.begin(); S != citylist.end(); ++S)
                        {
                                 ui->cityname->setText(*S);
                        }*/
  //  }
    //ui->cityname->setText(citylist.at(0)+" "+citylist.at(1)+" "+citylist.at(2)+" "+citylist.at(3)+" ");
}
void MainWindow::ex()
{
    this->close();
}
void MainWindow::satt(){
    qDebug()<<"satageldi";
    for(int i=0;i<40;i++){
         qDebug()<<"owner"<<array[i].owner<<"pname"<<players[qop].name<<"aname"<<array[i].name<<"mlist"<<mlist.at(2);
        if(array[i].owner==players[qop].name && array[i].name==mlist.at(2)){
              array[i].owner="bank";
              players[qop].balance=players[qop].balance+array[i].cost/2;
              qDebug()<<players[qop].balance;

        }
    }
}
void MainWindow::donee(){
    qDebug()<<"doneeeageldi";

    queue=queue+1;
    b=0;
qDebug()<<ccc<<"plist";
//ccc=ccc%numberofplayer;


if(ccc==numberofplayer-1){
    ccc=0;
   con=plist.at(ccc);
    qDebug()<<ccc<<"clist";
}else{
    ccc=ccc+1;
con=plist.at(ccc);
qDebug()<<ccc<<"cecelist";
}
qDebug()<<numberofplayer<<"formert";
}
void MainWindow::build()
{
    qDebug()<<"builddddddd";

    int counter=0,counter1=0,counter2=0;
    if(array[son[qop]].owner==players[qop].name){
        for(int i=0;i<40;i++){
            qDebug()<<counter1<< "for"<<array[i].renk<<array[son[qop]].renk;

            if(array[i].owner==players[qop].name && array[i].renk==array[son[qop]].renk && array[son[qop]].renk=="brown"){
                              counter1=counter1+1;
                              qDebug()<<counter1<<"buil ";
                            }
            else if(array[i].owner==players[qop].name && array[i].renk==array[son[qop]].renk && array[son[qop]].renk=="blue"){
                                counter2=counter2+1;
                            }
           else if(array[i].owner==players[qop].name && array[i].renk==array[son[qop]].renk){
                counter=counter+1;
            }
            else {

            }
            }

        }
    else {
    }
    if(counter==3||counter1==2||counter2==2){
        switch(array[son[qop]].levelofcard){
        case 0:
        array[son[qop]].levelofcard=1;
        players[qop].balance=players[qop].balance-500;
        counter=0,counter1=0,counter2=0;
        qDebug()<<"casedsin tatlım";
            break;
        case 1:
        array[son[qop]].levelofcard=2;
        players[qop].balance=players[qop].balance-500;

        qDebug()<<"caser";
            break;
        case 2:
        array[son[qop]].levelofcard=3;
        players[qop].balance=players[qop].balance-500;
         qDebug()<<"caser2";
            break;
        case 3:
        array[son[qop]].levelofcard=4;
        players[qop].balance=players[qop].balance-500;
            break;
        case 4:
        array[son[qop]].levelofcard=5;
        players[qop].balance=players[qop].balance-500;
            break;
        case 5:
        array[son[qop]].levelofcard=5;
         break;
    }
    }
    else{

    }
}


void MainWindow::on_EXITBUTTON_clicked()
{
    this->close();
}
