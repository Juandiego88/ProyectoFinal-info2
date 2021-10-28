#ifndef PARED_H
#define PARED_H
#include <QGraphicsItem>
#include <QPainter>

class pared : public QGraphicsItem
{
public:
    //atributos de posición
    int posx;
    int posy;
    int w;
    int h;

    //constructores
    pared();
    pared(int x, int y, int w, int h);

    //funciones para dibujar y asignar imagenes
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
};

#endif // PARED_H
