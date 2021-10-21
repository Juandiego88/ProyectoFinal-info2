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
    scene = new QGraphicsScene(this);
    setGeometry(0,0,1366,768);
    ui->graphicsView->setGeometry(0,0,1366*100,768);
    scene->setSceneRect(0,0,1366*100,768); //definimos el 0,0 de la escena
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/HD-wallpaper-thousand-galaxies-galaxies-black-far-space.jpg")));
    ui->graphicsView->setScene(scene);
    //ui->graphicsView->setFixedSize(500,280);
    ;
    //scene->setBackgroundBrush(QBrush(QImage(":/nave/imagenes/nebulosa.jpg")));


    //creamos personaje
    ball = new bolita(30,30,30);



    //Creamos paredes
    /*paredes.push_back(new pared(0,0,1480,20));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(0,330,1480,20));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(0,0,20,660));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(730,0,20,660));
    scene->addItem(paredes.back());*/

    //Inicializamos la ec. de mov
    //double rad = (45*3.141598)/180;
    movimiento = new Movimiento_p(30,30,0,0);
    scene->addItem(ball);
    ball->setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();
    view= new QGraphicsView(this);
    view->setScene(scene);
    view->resize(1366,768);
    this->resize(1366,768);
    view->centerOn(ball->x(),ball->y());
    //timer para que vaya cayendo
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    //connect(timer,SIGNAL(timeout()),this,SLOT(movers(60,180)));
    timer->start(100);



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


    movimiento->CalcularVelocidad();
    movimiento->CalcularPosicion();
    ball->Mover(movimiento->getPosx(),movimiento->getPosy());
    ball->MoveRight();
    view->centerOn(ball->x(),ball->y());
}




