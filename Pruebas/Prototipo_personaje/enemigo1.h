#ifndef ENEMIGO1_H
#define ENEMIGO1_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>


class enemigo1: public QObject, public QGraphicsPixmapItem
{
public:
    enemigo1(double pox,double poy,double vx, double vy);
    enemigo1(QGraphicsItem * parent=0);
    double getPosx() const;
    void setPosx(double value);
    double getPosy() const;
    void setPosy(double value);
private:
    double posx=0;
    double posy=0;
    double velx=0;
    double vely=0;
public slots:
    void move(double x, double y);
};

#endif // ENEMIGO1_H
