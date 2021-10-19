#include "bolita.h"

bolita::bolita()
{

}

bolita::bolita(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=10;
    setPos(posx,posy);

}

QRectF bolita::boundingRect() const
{
    return QRectF(0,0,radio*2,radio*2);
}

void bolita::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Así lo pintamos de un color especifico
//    painter->setBrush(Qt::red);
//    painter->drawEllipse(boundingRect());

//    Así le ponemos una imagen
    QPixmap pxMap(":/nave/nave2.png"); //para la ruta le damos click izq a la imagen y copy path
    painter->drawPixmap(boundingRect(), pxMap, pxMap.rect());

}

void bolita::MoveRight()
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void bolita::MoveLeft()
{
    this->posx-=velocidad;
    setPos(posx,posy);
}

void bolita::MoveUp()
{
    this->posy-=velocidad;
    setPos(posx,posy);

}

void bolita::MoveDown()
{
    this->posy+=velocidad;
    setPos(posx,posy);
}

void bolita::Mover(int posx, int posy)
{
    setPos(posx,posy);
}

