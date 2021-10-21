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


private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    bolita *ball;
    QList<pared*>paredes;
    Ui::MainWindow *ui;
    QTimer *timer;
    Movimiento_p *movimiento;
    void keyPressEvent(QKeyEvent *evento);
};
#endif // MAINWINDOW_H
