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

    QList<pared*>paredes;
    QList<enemigo*>enemy;
    QList<enemigo1*>enemy1;
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer1;
    QTimer *timer2;
    QList<moneda*> coins1;//monedas buenas
    QList<moneda*> coins2;//monedas malas
    QList<Bullet*> bullets;


    Movimiento_p *movimiento;
    void keyPressEvent(QKeyEvent *evento);
    bool aleatorio(float p);

    double ancho=1366;
    double largo=700;
};
#endif // MAINWINDOW_H
