#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem()
{
    //Asignamos la imagen a la bala
    setPixmap(QPixmap(":/imagenes/bala.png").scaled(40,20));

    //Creamos timer para que se vaya moviendo
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    //movemos la bala en el eje x
    setPos(x()+15,y());
}
