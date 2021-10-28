#ifndef MONEDA_H
#define MONEDA_H
#include <QGraphicsItem>
#include <QPainter>


class moneda : public QGraphicsItem
{
    //atributos de posición
    int posx;
    int posy;
    int radio;

public:
    //constructores
    moneda();
    moneda(int x, int y , int r);

    //funciones para dibujar y asignar imagenes
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // MONEDA_H
