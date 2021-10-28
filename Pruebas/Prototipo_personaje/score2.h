#ifndef SCORE2_H
#define SCORE2_H

#include <QGraphicsTextItem>

class score2 : public QGraphicsTextItem
{
private:
    int balas;
    int posx,posy;


public:
    score2(QGraphicsItem * parent = 0);
    void mover();
    int getBalas() const;
    void setBalas(int value);
};

#endif // SCORE_H
