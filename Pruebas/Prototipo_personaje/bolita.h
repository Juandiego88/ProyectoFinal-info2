#ifndef BOLITA_H
#define BOLITA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <math.h>

class bolita : public QGraphicsItem
{

    int posx;
    int posy;
    int radio;
    int velocidad;

public:
    bolita();
    bolita(int x, int y , int r);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    void Mover(int posx, int posy);
};

#endif // BOLITA_H
