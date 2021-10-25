#include "bala.h"
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include <QObject>
#include <QDebug>

bala::bala()
{

}

bala::bala(int x, int y, int w, int h)
{
   this->posx=x;
   this->posy=y;
   this->w=w;
   this->h=h;
   setPos(posx,posy);
   //connect
   QTimer *timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this, SLOT(mover()));
   timer->start(100);
}

void bala::mover()
{
    this->posx+=10;
    setPos(posx,posy);
    qDebug() << "Prueba\n";
}

QRectF bala::boundingRect() const
{
    return QRectF(posx,posy,w,h);
}

void bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{/*
    painter->setBrush(Qt::blue);
    painter->drawRect(boundingRect());*/
    //    Así le ponemos una imagen
    QPixmap pxMap(":/imagenes/bala.png"); //para la ruta le damos click izq a la imagen y copy path
    painter->drawPixmap(boundingRect(), pxMap, pxMap.rect());
}
