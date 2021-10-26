#ifndef ENEMIGO1_H
#define ENEMIGO1_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>





class enemigo1:public QObject, public QGraphicsPixmapItem
{
public:
    enemigo1();
    enemigo1(float posmx, float posmy,int tam,float velo);
    void movimiento1();
private:
    int tam=0;
    float x1=0,y1=0,auxx1=0,auxy1=0,r=50, v=5, t=2,vel=0;
};


#endif // ENEMIGO1_H
