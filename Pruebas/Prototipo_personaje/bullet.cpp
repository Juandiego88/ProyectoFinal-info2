#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{
    //draw the bullet
    setPixmap(QPixmap(":/imagenes/bala.png").scaled(40,20));


    //connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);

}

void Bullet::move()
{
    //move bullet up
    setPos(x()+15,y());
}
