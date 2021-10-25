#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QDebug>
#include <stdlib.h>
#include <QMouseEvent>
int score=0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //creamos escena

    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    setGeometry(0,0,ancho,largo);
    ui->graphicsView->setGeometry(0,0,ancho*100,largo);
    scene->setSceneRect(0,0,ancho*100,largo);
    /*setGeometry(0,0,1366,768);
    ui->graphicsView->setGeometry(0,0,1366*100,768);
    scene->setSceneRect(0,0,1366*100,768); *///definimos el 0,0 de la escena
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/HD-wallpaper-thousand-galaxies-galaxies-black-far-space.jpg")));
    ui->graphicsView->setScene(scene);

    //ui->graphicsView->setFixedSize(500,280);
    ;
    //scene->setBackgroundBrush(QBrush(QImage(":/nave/imagenes/nebulosa.jpg")));


    //creamos personaje
    ball = new bolita(30,30,30);
    //enemy = new enemigo1();





    //Creamos paredes
    /*paredes.push_back(new pared(0,0,1480,20));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(0,330,1480,20));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(0,0,20,660));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(730,0,20,660));
    scene->addItem(paredes.back());*/

    //agregamos monedas
    for(int i=1; i<100; i++) {
        coins1.push_back(new moneda(i*700,50,20));
        scene->addItem(coins1.back());
        coins1.push_back(new moneda(i*300,470,20));
        scene->addItem(coins1.back());
    }

    //Inicializamos la ec. de mov
    //double rad = (45*3.141598)/180;
    movimiento = new Movimiento_p(30,30,100,0);
    scene->addItem(ball);
    //scene->addItem(enemy);
    ball->setFlag(QGraphicsItem::ItemIsFocusable);
    ball->setFocus();
    view= new QGraphicsView(this);
    view->setScene(scene);
    view->resize(ancho,largo);
    this->resize(ancho,largo);
    view->centerOn(ball->x(),ball->y());
    //timer para que vaya cayendo
    timer = new QTimer(this);
    timer->start(50);
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));

    /*enemy.append(new enemigo(900,30,200));
    scene->addItem(enemy.back());
    timer1 = new QTimer(this);
    timer1->start(50);
    connect(timer1,SIGNAL(timeout()),this,SLOT(Movimiento()));*/
    srand(time(NULL));
    for(int i=0;i<200;i++){
        if(aleatorio()){

            int random_numberx = rand() % (100000+2000);
            int random_numbery = rand() % 500;
            enemy.append((new enemigo(random_numberx,random_numbery,100)));
                        }
     }


    for(int j=0;j<enemy.size();j++){
                scene->addItem(enemy.at(j));
                /*timer1 = new QTimer(this);
                timer1->start(50);
                connect(timer1,SIGNAL(timeout()),this,SLOT(Movimiento()));*/
    }
    timer1 = new QTimer(this);
    timer1->start(50);
    connect(timer1,SIGNAL(timeout()),this,SLOT(Movimiento()));


    srand(time(NULL));
    for(int i1=0;i1<200;i1++){
        if(aleatorio()){

            float random_numberx1 = rand() % (100000+500000);
            float random_numbery1 = rand() % 500;
            enemy1.append((new enemigo1(random_numberx1,random_numbery1,60)));
                        }
     }


    for(int j1=0;j1<enemy1.size();j1++){
                scene->addItem(enemy1.at(j1));
                /*timer1 = new QTimer(this);
                timer1->start(50);
                connect(timer1,SIGNAL(timeout()),this,SLOT(Movimiento()));*/
    }

        timer2 = new QTimer(this);
        timer2->start(50);
        connect(timer2,SIGNAL(timeout()),this,SLOT(Movimiento1()));







    //connect(timer,SIGNAL(timeout()),this,SLOT(movers(60,180)));
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

bool MainWindow::aleatorio()
{
    int n, x;
    n=rand();
    x=p*(RAND_MAX+1)-1;
    return n<=x;

}

void MainWindow::Mover()
{
    movimiento->CalcularVelocidad();
    movimiento->CalcularPosicion();
    ball->Mover(movimiento->getPosx(),movimiento->getPosy());

//    ball->MoveRight();
    view->centerOn(ball->x(),ball->y());

}

void MainWindow::Movimiento()
{
    for(int j=0;j<enemy.length();j++){
             enemy.at(j)->movimiento();

    }
}

void MainWindow::Movimiento1()
{
    for(int j=0;j<enemy1.length();j++){
             enemy1.at(j)->movimiento1();

    }

}



void MainWindow::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::RightButton) {
    qDebug() << "Boton Der (Aux)";
    bullets.push_back(new Bullet());
    bullets.back()->setPos((movimiento->getPosx()+35),(movimiento->getPosy()-8));
    scene->addItem(bullets.back());
    }
    else if(event->button() == Qt::LeftButton) {
        qDebug() << "Boton Izq (Principal)";
        //modificamos el mov de caida libre que tiene, para subir
        movimiento->setPosy(movimiento->getPosy()-10);
        movimiento->setVel(100);
        movimiento->setAng(0);
        movimiento->CalcularVelocidad();
        movimiento->CalcularPosicion();
        ball->Mover(movimiento->getPosx(),movimiento->getPosy());
    }
    else if(event->button() == Qt::MiddleButton) {
        qDebug() << "Boton del Medio (Centro)";
    }
}





