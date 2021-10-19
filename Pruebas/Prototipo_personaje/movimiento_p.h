#ifndef MOVIMIENTO_P_H
#define MOVIMIENTO_P_H

#include <math.h>

#define DT 0.05
//#define DT 0.01 (con esto variamos la velocidad en la que se muestra la animación)
#define g 9.8


class Movimiento_p
{//Atributos
    double posx, posy, vel_x, vel_y, vel, ang;

public:
    //Métodos:
    Movimiento_p();
    Movimiento_p(double x, double y, double v, double ang);
    void CalcularVelocidad();
    void CalcularPosicion();
    double getPosx() const;
    double getPosy() const;
};

#endif // MOVIMIENTO_P_H
