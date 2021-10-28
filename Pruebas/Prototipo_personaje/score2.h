#ifndef SCORE2_H
#define SCORE2_H

#include <QGraphicsTextItem>

class score2 : public QGraphicsTextItem
{
private:
    //atributos de posición
    int balas;
    int posx,posy;


public:
    //constructor
    score2(QGraphicsItem * parent = 0);

    //funcion para ir moviendo el score
    void mover();

    //Get & Set
    int getBalas() const;
    void setBalas(int value);
};

#endif // SCORE_H
