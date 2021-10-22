#ifndef BALA_H
#define BALA_H
#include <QGraphicsItem>
#include <QPainter>

class bala : public QGraphicsItem
{
private:
    int posx;
    int posy;
    int w;
    int h;

public:
    bala();
    bala(int x, int y, int w, int h);
    void mover();
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // BALA_H
