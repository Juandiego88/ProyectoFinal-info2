#ifndef MULTIJUGADOR_H
#define MULTIJUGADOR_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <pared.h>
#include <QList>
#include <QTimer>
#include <QGraphicsView>
#include <QString>

#include "enemigo.h"
#include "bolita.h"
#include "movimiento_p.h"
#include "moneda.h"
#include "bullet.h"
#include "score.h"
#include "score2.h"
#include "muerte.h"
namespace Ui {
class Multijugador;
}

class Multijugador : public QMainWindow
{
    Q_OBJECT

public:
    explicit Multijugador(int num,QString _nombre,QWidget *parent = nullptr);
    ~Multijugador();
    bool EvaluarColision();
    bool ComerMoneda();
    bool Morir();
    bool ExplotarBalas();

    int numero=0;



public slots:
    void Mover();
    void Movimiento();
    void Movimiento1();
    void mousePressEvent(QMouseEvent *event);



private:
    QGraphicsScene *scene, *scene2;
    QGraphicsView *view, *v2;
    QMainWindow *w2;
    bolita *ball;
    bolita *ball1;
    score *puntos;
    score2 *balas;

    QList<pared*>paredes;
    QList<enemigo*>enemy;
    QList<enemigo1*>enemy1;
    Ui::Multijugador *ui;
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    QTimer *timer3;
    QTimer *timer4;
    QTimer *timer5;

    QList<moneda*> coins1;
    QList<Bullet*> bullets;
    QString nave[2];

    Movimiento_p *movimiento;
    Movimiento_p *movimiento1;
    bool aleatorio(float p);
    bool bandera=true;
    double ancho=1366;
    double largo=700;
    QString nombre;


};

#endif // MULTIJUGADOR_H
