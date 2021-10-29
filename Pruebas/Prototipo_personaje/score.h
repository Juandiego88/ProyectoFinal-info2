#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

#include <iostream>
#include <fstream>

class score : public QGraphicsTextItem
{
private:
    //atributos de posición
    int puntos;
    int posx,posy;




public:
    //constructor
    score(QGraphicsItem * parent = 0);

    //funciones de movimiento e incremento
    void incrementar();
    void mover();
    int getpuntos();
    void lectura();
};

#endif // SCORE_H
