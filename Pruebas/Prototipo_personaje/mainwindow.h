#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <bolita.h>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <pared.h>
#include <QList>
#include <QTimer>
#include <QGraphicsView>
#include "enemigo.h"

#include "bolita.h"
#include "movimiento_p.h"


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

    void mousePressEvent(QMouseEvent *event);



private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    bolita *ball;

    QList<pared*>paredes;
    QList<enemigo*>enemy;
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer1;


    Movimiento_p *movimiento;
    void keyPressEvent(QKeyEvent *evento);
    bool aleatorio();
    float p=0.5;
};
#endif // MAINWINDOW_H
