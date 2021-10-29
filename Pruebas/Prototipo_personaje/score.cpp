#include "score.h"
#include <QFont>//para cambiar el tipo de letra

score::score(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //inicializamos los puntos en 0
    puntos = 0;
    posx = 250, posy = 20;

    //escribimos el texto
    setPlainText(QString("Puntuacion: ") + QString::number(puntos)); //puntos=0
    setDefaultTextColor(Qt::white);
    setFont(QFont("Courier",20));
    setPos(posx,posy);
}

void score::incrementar()
{
    puntos++;
}

void score::mover()
{
    posx+=5;
    setPlainText(QString("Puntuacion: ") + QString::number(puntos)); //puntos=0
    setPos(posx,posy);
}


int score::getpuntos()
{
    return puntos;

}


