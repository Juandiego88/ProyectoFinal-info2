#ifndef ENEMIGO_H
#define ENEMIGO_H
#include "math.h"
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
# define PI 3.14159265359



class enemigo:public QObject, public QGraphicsPixmapItem
{
public:
    enemigo();
    enemigo(float posmx, float posmy,int tam,int vel);
    void movimiento();
private:
    int size=0;
    float x=0,y=0,auxx=0,auxy=0,r=65,the=0,v=0;
};

#endif // ENEMIGO_H
