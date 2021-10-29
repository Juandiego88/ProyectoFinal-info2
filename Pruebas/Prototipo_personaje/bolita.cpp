#include "bolita.h"

int bolita::getPosx() const
{
    return posx;
}

int bolita::getPosy() const
{
    return posy;
}

bolita::bolita()
{

}

bolita::bolita(int x, int y, int r)
{
    this->posx=x;
    this->posy=y;
    this->radio=r;
    this->velocidad=10;
    setPixmap(QPixmap(":/nave3").scaled(radio*2,radio*2));
    setPos(posx,posy);

}

void bolita::MoveRight()
{
    this->posx+=velocidad;
    setPos(posx,posy);
}

void bolita::MoveLeft()
{
    this->posx-=velocidad;
    setPos(posx,posy);
}

void bolita::MoveUp()
{
    this->posy-=velocidad;
    setPos(posx,posy);

}

void bolita::MoveDown()
{
    this->posy+=velocidad;
    setPos(posx,posy);
}

void bolita::Mover(int posx, int posy)
{
    setPos(posx,posy);
}

int bolita::getposx()
{
    return posx;
}



