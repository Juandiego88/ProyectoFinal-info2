#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>
#include <QLabel>
//#include <stdlib.h>
#include <QMouseEvent>
int score=0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

        //creamos escena
        nave[0]=":/nave1.png";
        nave[1]=":/nave2.png";

        ui->setupUi(this);
        scene = new QGraphicsScene(this);
        setGeometry(0,0,ancho,largo);
        ui->graphicsView->setGeometry(0,0,ancho*100,largo);
        scene->setSceneRect(0,0,ancho*50,largo);
        /*setGeometry(0,0,1366,768);
        ui->graphicsView->setGeometry(0,0,1366*100,768);
        scene->setSceneRect(0,0,1366*100,768); *///definimos el 0,0 de la escena
        //scene->setBackgroundBrush(QBrush(QImage(":/imagenes/fondo.jpg")));
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
        for(int i=0;i<100;i++){
            if(aleatorio(0.5)){

                //int random_numberx = rand() % 99200+800;
                int random_numberx = rand() % 9000+1000;
                int random_numbery = rand() % 500;
                enemy.append((new enemigo(random_numberx,random_numbery,100,1)));
                            }
         }

        for(int i=0;i<200;i++){
            if(aleatorio(0.6)){

                int random_numberx = rand() % 10000+10000;
                int random_numbery = rand() % 500;
                enemy.append((new enemigo(random_numberx,random_numbery,100,2)));
                            }
         }
        for(int i=0;i<300;i++){
            if(aleatorio(0.7)){

                int random_numberx = rand() % 10000+20000;
                int random_numbery = rand() % 500;
                enemy.append((new enemigo(random_numberx,random_numbery,100,3)));
                            }
         }
        for(int i=0;i<500;i++){
            if(aleatorio(0.8)){

                int random_numberx = rand() % 30000+30000;
                int random_numbery = rand() % 500;
                enemy.append((new enemigo(random_numberx,random_numbery,100,4)));
                            }
         }
        for(int i=0;i<800;i++){
            if(aleatorio(0.9)){

                int random_numberx = rand() % 40000+60000;
                int random_numbery = rand() % 500;
                enemy.append((new enemigo(random_numberx,random_numbery,100,5)));
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
        for(int i1=0;i1<100;i1++){
            if(aleatorio(0.5)){

                float random_numberx1 = rand() % 80000+20000;
                float random_numbery1 = rand() % 500;
                enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,2)));
                            }
         }

        for(int i1=0;i1<150;i1++){
            if(aleatorio(0.6)){

                float random_numberx1 = rand() % 80000+40000;
                float random_numbery1 = rand() % 500;
                enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,2.5)));
                            }
         }

        for(int i1=0;i1<200;i1++){
            if(aleatorio(0.7)){

                float random_numberx1 = rand() % 80000+60000;
                float random_numbery1 = rand() % 500;
                enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,3)));
                            }
         }

        for(int i1=0;i1<300;i1++){
            if(aleatorio(0.8)){

                float random_numberx1 = rand() % 80000+80000;
                float random_numbery1 = rand() % 500;
                enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,3.5)));
                            }
         }
        for(int i1=0;i1<1000;i1++){
            if(aleatorio(0.8)){

                float random_numberx1 = rand() % 160000+160000;
                float random_numbery1 = rand() % 500;
                enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,4)));
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

            //Agregamos segunda ventana para el puntaje
            w2 =  new QMainWindow(this);
            scene2 = new QGraphicsScene();

            v2 = new QGraphicsView(scene2, w2);
            v2->setGeometry(0,0,400,400);

            ui->graphicsView->setScene(scene2);
            w2->setGeometry(1200,50,150,50);

            QLabel *label = new QLabel(this);
            label->setText("Puntuacion: ");
    //        setBaseSize(QSize(600, 400));
    //        label->resize(label->baseSize());
    //        label->setScaledContents(true);
            scene2->addWidget(label);
            ui->graphicsView->setScene(scene2);

            w2->show();









    //connect(timer,SIGNAL(timeout()),this,SLOT(movers(60,180)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::EvaluarColision()//recorremos toda la lista evaluando si choca con alguna pared
{
    QList<moneda*>::iterator it;
    for(it=coins1.begin();it!=coins1.end();it++) {
        if((*it)->collidesWithItem(ball)) {
            qDebug() << "COLISIONEEEEEEEEEES";
            scene->removeItem(*it);
            it=coins1.erase(it);
            return true;
        }
    }
    return false;
}

bool MainWindow::ComerMoneda()//recorremos toda la lista de monedas y vamos eliminando las que chocamos
{
    QList<moneda*>::iterator it;
    for(it=coins1.begin();it!=coins1.end();it++) {
        if((*it)->collidesWithItem(ball)) {
            qDebug() << "COLISIONEEEEEEEEEES";
            scene->removeItem(*it);
            it=coins1.erase(it);
            return true;
        }
    }
    return false;
}

bool MainWindow::ExplotarBalas()//recorremos toda la lista de monedas y vamos eliminando las que chocamos
{
    QList<enemigo*>::iterator it;
    QList<Bullet*>::iterator it2;
    for(it=enemy.begin();it!=enemy.end();it++) {
        for(it2=bullets.begin();it2!=bullets.end();it2++) {
            if((*it)->collidesWithItem(*it2)) {
                qDebug() << "BALA";
                scene->removeItem(*it);
                it=enemy.erase(it);
                scene->removeItem(*it2);
                it2=bullets.erase(it2);
                return true;
            }
        }
    }
    return false;
}
bool MainWindow::Morir() //Evaluamos cuando la nave choca con algun enemigo
{
    QList<enemigo*>::iterator it;
    for(it=enemy.begin();it!=enemy.end();it++) {
        if((*it)->collidesWithItem(ball)) {
            qDebug() << "MUERTE";
            scene->removeItem(*it);
            it=enemy.erase(it);
            return true;
        }
    }
    QList<enemigo1*>::iterator it1;
    for(it1=enemy1.begin();it1!=enemy1.end();it1++) {
        if((*it1)->collidesWithItem(ball)) {
            qDebug() << "MUERTE";
            scene->removeItem(*it1);
            it1=enemy1.erase(it1);
            return true;
        }
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

bool MainWindow::aleatorio(float p)
{
    int n, x;
    n=rand();
    x=p*(RAND_MAX+1)-1;
    return n<=x;

}

int MainWindow::getmulti()
{
    return bandera;
}

void MainWindow::setmulti(int band)
{
    bandera=band;
}


void MainWindow::Mover()
{
    movimiento->CalcularVelocidad();
    movimiento->CalcularPosicion();
    ball->Mover(movimiento->getPosx(),movimiento->getPosy());
    ball->setPixmap(QPixmap(nave[1]).scaled(60,60));


//    ball->MoveRight();
    view->centerOn(ball->x(),ball->y());
    score++;
    qDebug()<<score;
    ComerMoneda();
    Morir();
    ExplotarBalas();

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
        //ball->setPixmap(QPixmap(nave[0]).scaled(60,60));
        movimiento->setPosy(movimiento->getPosy()-10);
        movimiento->setVel(100);
        movimiento->setAng(0);
        movimiento->CalcularVelocidad();
        movimiento->CalcularPosicion();
        ball->Mover(movimiento->getPosx(),movimiento->getPosy());
        ball->setPixmap(QPixmap(nave[0]).scaled(60,60));
    }
    else if(event->button() == Qt::MiddleButton) {
        qDebug() << "Boton del Medio (Centro)";
    }
}





