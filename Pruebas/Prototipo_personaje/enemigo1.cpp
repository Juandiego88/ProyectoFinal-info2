#include "enemigo1.h"
#include <stdlib.h>



enemigo1::enemigo1()
{

}

enemigo1::enemigo1(float posmx, float posmy, int tam1)
{
    tam=tam1;
    auxx1=posmx;
    auxy1=posmy;
    setPixmap(QPixmap(":/enemy1.png").scaled(tam,tam));
    setPos(auxx1,auxy1);
}

void enemigo1::movimiento1()
{
    x1=auxx1-(v*t);
    y1=auxy1;
    v=v+4;

    setPos(x1,y1);

}
