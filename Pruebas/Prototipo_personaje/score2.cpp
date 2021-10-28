#include "score2.h"
#include <QFont>//para cambiar el tipo de letra

score2::score2(QGraphicsItem *parent) : QGraphicsTextItem(parent) {
    //inicializamos los puntos en 0
    balas = 0;
    posx = 500, posy = 20;

    //escribimos el texto
    setPlainText(QString("Balas: ") + QString::number(balas)); //puntos=0
    setDefaultTextColor(Qt::white);
    setFont(QFont("Courier",20));
    setPos(posx,posy);
}

void score2::mover()
{
    posx+=5;
    setPlainText(QString("Balas: ") + QString::number(balas));
    setPos(posx,posy);
}


int score2::getBalas() const
{
    return balas;
}

void score2::setBalas(int value)
{
    balas = value;
}


