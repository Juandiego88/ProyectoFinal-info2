#ifndef MONEDA_H
#define MONEDA_H
#include <QGraphicsItem>
#include <QPainter>


class moneda : public QGraphicsItem
{

    int posx;
    int posy;
    int radio;

public:
    moneda();
    moneda(int x, int y , int r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // MONEDA_H
