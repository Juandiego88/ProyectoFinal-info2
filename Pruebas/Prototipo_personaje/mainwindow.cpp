#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //creamos escena
    ui->setupUi(this);
    scene= new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,1480,670);

    //creamos personaje
    ball = new bolita(30,30,30);
//    scene->addItem(ball);


    //Creamos paredes
    paredes.push_back(new pared(0,0,1480,20));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(0,330,1480,20));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(0,0,20,660));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(730,0,20,660));
    scene->addItem(paredes.back());

    //Inicializamos la ec. de mov
    double rad = (45*3.141598)/180;
    movimiento = new Movimiento_p(30,30,60,rad);
    scene->addItem(ball);

    //timer para que vaya cayendo
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    timer->start(500);



}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::EvaluarColision()//recorremos toda la lista evaluando si choca con alguna pared
{
    QList<pared*>::iterator it;
    for(it=paredes.begin();it!=paredes.end();it++) {
        if((*it)->collidesWithItem(ball))
            return true;
    }
    return false;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D)
    {
        if(EvaluarColision()){
            std::cout<<"Prueba"<<std::endl;
           ball->MoveLeft();
        }
        else
           ball->MoveRight();
    }
    else if(evento->key()==Qt::Key_A)
     {
        if(EvaluarColision()){
            ball->MoveRight();
            std::cout<<"Prueba"<<std::endl;
        }
        else
            ball->MoveLeft();
     }
    else if(evento->key()==Qt::Key_W)
    {
      if(EvaluarColision()) {
            ball->MoveDown();
          std::cout<<"Prueba"<<std::endl;
      }
        else {
            ball->MoveUp();
            ball->MoveRight();
      }
    }
    else if(evento->key()==Qt::Key_S)
    {
        if(EvaluarColision()) {
            ball->MoveUp();
            std::cout<<"Prueba"<<std::endl;
        }
        else
           ball->MoveDown();
    }

}

void MainWindow::Mover()
{
    //PRUEBAS
//    ball->MoveRight();
//    ball->MoveDown();
//    qDebug() << "Verificando...\n";
//    std::cout<<"Prueba"<<std::endl;

    movimiento->CalcularVelocidad();
    movimiento->CalcularPosicion();
    ball->Mover(movimiento->getPosx(),movimiento->getPosy());
}



