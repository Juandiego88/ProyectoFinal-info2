#ifndef BOLITA_H
#define BOLITA_H
#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <math.h>
#include <QObject>
#include <QGraphicsPixmapItem>
#include <enemigo1.h>
#include <QGraphicsScene>

class bolita : QObject, public QGraphicsPixmapItem
{

    int posx;
    int posy;
    int radio;
    int velocidad;

public:
    bolita();
    bolita(int x, int y , int r);

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
