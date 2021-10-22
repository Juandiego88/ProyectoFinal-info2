#ifndef BOLITA_H
#define BOLITA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <math.h>
#include <enemigo1.h>
#include <QGraphicsScene>

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
    int getposx();
    int getPosx() const;
    int getPosy() const;

public slots:

};

#endif // BOLITA_H
