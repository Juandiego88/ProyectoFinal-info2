#include "movimiento_p.h"

double Movimiento_p::getPosx() const
{
    return posx;
}

double Movimiento_p::getPosy() const
{
    return posy;
}

void Movimiento_p::setPosy(double value)
{
    posy = value;
}

void Movimiento_p::setVel(double value)
{
    vel = value;
}

void Movimiento_p::setAng(double value)
{
    ang = value;
}

Movimiento_p::Movimiento_p()
{

}

Movimiento_p::Movimiento_p(double x, double y, double v, double ang)
{
    this->posx=x;
    this->posy=y;
    this->vel=v;
    this->ang=ang;
}

void Movimiento_p::CalcularVelocidad()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*DT;
    vel=sqrt(pow(vel_x,2)+pow(vel_y,2));
    ang=atan2(vel_y,vel_x);//usamos "atan2" siempre
}

void Movimiento_p::CalcularPosicion()
{
    posx=posx+vel_x*DT;
    posy=posy+vel_y*DT-0.5*g*DT*DT;
}
