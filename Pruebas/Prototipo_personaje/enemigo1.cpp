#include "enemigo1.h"
#include <stdlib.h>

enemigo1::enemigo1(double pox, double poy, double vx, double vy)
{
    posx=pox;
    posy=poy;
    velx=vx;
    vely=vy;
}

enemigo1::enemigo1(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem()
{
    /*int random_number = rand() % 600;
    setPos(900,random_number);
    //(900,30);*/


    setPixmap(QPixmap(":/enemigo.png").scaled(200,200));

    //connect
    /*QTimer * timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this, SLOT(move()));

    timer2->start(50);*/
}

double enemigo1::getPosx() const
{
    return posx;
}

void enemigo1::setPosx(double value)
{
    posx=value;

}

double enemigo1::getPosy() const
{
    return posy;

}

void enemigo1::setPosy(double value)
{
    posy=value;
}

void enemigo1::move(double x , double y)
{
    posx=x;
    posy=y;
    this->posx-=velx;
    setPos(posx,posy);
}
