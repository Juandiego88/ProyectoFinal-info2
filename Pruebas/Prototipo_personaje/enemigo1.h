#ifndef ENEMIGO1_H
#define ENEMIGO1_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>

class enemigo1:public QObject, public QGraphicsPixmapItem
{
private:
    //atributos de posición
    int tam=0;
    float x1=0, y1=0, auxx1=0, auxy1=0, r=50, v=5, t=2, vel=0;

public:
    //constructores
    enemigo1();
    enemigo1(float posmx, float posmy,int tam,float velo);

    //funciones de movimiento
    void movimiento1();
};

#endif // ENEMIGO1_H
