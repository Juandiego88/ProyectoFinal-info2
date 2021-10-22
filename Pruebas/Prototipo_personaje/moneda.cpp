#include "moneda.h"

moneda::moneda()
{

}

moneda::moneda(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    setPos(posx,posy);
}

QRectF moneda::boundingRect() const
{
    return QRectF(0,0,radio*2,radio*2);
}

void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::darkYellow);
//    painter->drawEllipse(boundingRect());
    //    Así le ponemos una imagen
    QPixmap pxMap(":/imagenes/agujero.png"); //para la ruta le damos click izq a la imagen y copy path
    painter->drawPixmap(boundingRect(), pxMap, pxMap.rect());
}

