#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class score : public QGraphicsTextItem
{
private:
    int puntos;
    int posx,posy;


public:
    score(QGraphicsItem * parent = 0);
    void incrementar();
    int getpuntos();
};

#endif // SCORE_H
