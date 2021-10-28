#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <pared.h>
#include <QList>
#include <QTimer>
#include <QGraphicsView>

#include "enemigo.h"
#include "bolita.h"
#include "movimiento_p.h"
#include "moneda.h"
#include "bullet.h"
#include "score.h"
#include "score2.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool EvaluarColision();
    bool ComerMoneda();
    bool Morir();
    bool ExplotarBalas();
    int getmulti();
    void setmulti(int band);
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
    score *puntos;
    score2 *balas;

    QList<pared*>paredes;
    QList<enemigo*>enemy;
    QList<enemigo1*>enemy1;
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    QList<moneda*> coins1;
    QList<Bullet*> bullets;
    QString nave[2];

    Movimiento_p *movimiento;
    bool aleatorio(float p);
    int bandera=0;
    double ancho=1366;
    double largo=700;
};
#endif // MAINWINDOW_H
