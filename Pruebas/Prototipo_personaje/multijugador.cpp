#include "multijugador.h"
#include "ui_multijugador.h"
#include <iostream>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>
Multijugador::Multijugador(int num,QString _nombre,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Multijugador)
{


    nombre=_nombre;
    //creamos escena
    nave[0]=":/nave4.png";
    nave[1]=":/nave5.png";

    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    setGeometry(0,0,ancho,largo);
    ui->graphicsView->setGeometry(0,0,ancho*100,largo);
    scene->setSceneRect(0,0,ancho*50,largo);
    scene->setBackgroundBrush(QBrush(QImage(":/imagenes/HD-wallpaper-thousand-galaxies-galaxies-black-far-space.jpg")));
    ui->graphicsView->setScene(scene);
    //creamos personaje
    ball = new bolita(30,80,40);
    ball->setPixmap(QPixmap(nave[num]).scaled(80,80));


    //Creamos paredes (arriba y abajo)
    paredes.push_back(new pared(0,0,1480*100,60));
    scene->addItem(paredes.back());
    paredes.push_back(new pared(0,330,1480*100,50));
    scene->addItem(paredes.back());


    //agregamos monedas
    srand(time(NULL));
    for(int i=1;i<200;i++){
         int random_numbery = rand() % 530 + 70;
         coins1.append((new moneda(i*560,random_numbery,20)));
         scene->addItem(coins1.back());
     }

    //Inicializamos la ec. de mov
    movimiento = new Movimiento_p(30,80,100,0);

    scene->addItem(ball);

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




    //creamos los enemigos
    srand(time(NULL));
    for(int i=0;i<100;i++){
        if(aleatorio(0.5)){
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
    }
    timer1 = new QTimer(this);
    timer1->start(50);
    connect(timer1,SIGNAL(timeout()),this,SLOT(Movimiento()));



    srand(time(NULL));
    for(int i1=0;i1<100;i1++){
        if(aleatorio(0.5)){
            float random_numberx1 = rand() % 80000+20000;
            float random_numbery1 = rand() % 500;
                                           //coeficiente de friccion: 0.5 - velocidad: 4
            enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,(0.5*4))));
                        }
     }

    for(int i1=0;i1<150;i1++){
        if(aleatorio(0.6)){
            float random_numberx1 = rand() % 80000+40000;
            float random_numbery1 = rand() % 500;
                                          //coeficiente de friccion: 0.65 - velocidad: 4
            enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,0.65*4)));
                        }
     }

    for(int i1=0;i1<200;i1++){
        if(aleatorio(0.7)){
            float random_numberx1 = rand() % 80000+60000;
            float random_numbery1 = rand() % 500;
                                           //coeficiente de friccion: 0.75 - velocidad: 4
            enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,(0.75*4))));
                        }
     }

    for(int i1=0;i1<300;i1++){
        if(aleatorio(0.8)){
            float random_numberx1 = rand() % 80000+80000;
            float random_numbery1 = rand() % 500;
                                           //coeficiente de friccion: 0.875 - velocidad: 4
            enemy1.append((new enemigo1(random_numberx1,random_numbery1,60,(0.875*4))));
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
    }

        timer2 = new QTimer(this);
        timer2->start(50);
        connect(timer2,SIGNAL(timeout()),this,SLOT(Movimiento1()));


        //Agregamos segunda ventana para el puntaje [esto hay que dejarlo]
        w2 =  new QMainWindow(this);
        scene2 = new QGraphicsScene();
        v2 = new QGraphicsView(scene2, w2);
        v2->setGeometry(0,0,400,400);
        ui->graphicsView->setScene(scene2);
        w2->setGeometry(1200,50,150,50);
//            w2->show();

        //vamos a poner el score
        puntos = new class score();
        scene->addItem(puntos);

        balas = new class score2();
        scene->addItem(balas);

}

Multijugador::~Multijugador()
{
    delete ui;
}

bool Multijugador::EvaluarColision()
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

bool Multijugador::ComerMoneda()
{
    QList<moneda*>::iterator it;
    for(it=coins1.begin();it!=coins1.end();it++) {
        if((*it)->collidesWithItem(ball)) {
            scene->removeItem(*it);
            it=coins1.erase(it);
            balas->setBalas(balas->getBalas()+5);
            //qDebug() << "Balas: "<<no_balas;
            return true;
        }
    }
    return false;

}

bool Multijugador::Morir()
{
    QList<enemigo*>::iterator it;
    for(it=enemy.begin();it!=enemy.end();it++) {
        if((*it)->collidesWithItem(ball)) {
            qDebug() << "MUERTE";
//            timer->stop();
//            timer1->stop();
//            timer2->stop();


            scene->removeItem(*it);
            it=enemy.erase(it);
//            bandera=true;

             return true;
           // setBandera(true);

        }
    }
    QList<enemigo1*>::iterator it1;
    for(it1=enemy1.begin();it1!=enemy1.end();it1++) {
        if((*it1)->collidesWithItem(ball)) {
            qDebug() << "MUERTE";
            scene->removeItem(*it1);
            it1=enemy1.erase(it1);
            //setBandera(true);
            return true;
        }
    }
    QList<pared*>::iterator it2;
    for(it2=paredes.begin();it2!=paredes.end();it2++) {
        if((*it2)->collidesWithItem(ball)) {
            qDebug() << "MUERTE";
            scene->removeItem(*it2);
            it2=paredes.erase(it2);
            //setBandera(true);
            return true;
        }
    }
    //setBandera(false);
    return false;

}

bool Multijugador::ExplotarBalas()
{
    QList<enemigo*>::iterator it;
    QList<enemigo1*>::iterator itr;
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
    for(itr=enemy1.begin();itr!=enemy1.end();itr++) {
        for(it2=bullets.begin();it2!=bullets.end();it2++) {
            if((*itr)->collidesWithItem(*it2)) {
                qDebug() << "BALA";
                scene->removeItem(*itr);
                itr=enemy1.erase(itr);
                scene->removeItem(*it2);
                it2=bullets.erase(it2);
                return true;
            }
        }
    }
    return false;
}

void Multijugador::Mover()
{
    //mov. parabolico (en caida de la nave)
    movimiento->CalcularVelocidad();
    movimiento->CalcularPosicion();
    ball->Mover(movimiento->getPosx(),movimiento->getPosy());

//    ball->setPixmap(QPixmap(nave[1]).scaled(60,60));


    //ejecución de funciones que se necesitan ejecutar en todo momento
    view->centerOn(ball->x(),ball->y());
//    score++;
  //  qDebug()<<score;

    QFile archivo;
    QByteArray contenido;
    archivo.setFileName("../max_puntajes.txt");
    if(!archivo.exists()) {
        qDebug() << "El archivo no existe!";
    }
    else if(archivo.exists()) {
        archivo.open(QIODevice::ReadWrite | QIODevice::Text);
        if(archivo.isOpen()) {
            contenido = archivo.readAll();
        }
    }
    bool ok;
    int puntaje = contenido.toInt(&ok, 10);
//    qDebug() << puntaje+1;

    ComerMoneda();
    if(Morir()==true){
        muerte *a;
        timer->stop();
        timer1->stop();
        timer2->stop();

        close();
        a =new muerte(nombre,puntos->getpuntos());
        if(puntos->getpuntos()>puntaje) {
            contenido.setNum(puntos->getpuntos());
            archivo.remove();
            archivo.open(QIODevice::ReadWrite | QIODevice::Text);
            archivo.write(contenido);
        }
        a->show();
    }

    ExplotarBalas();
    puntos->incrementar();
    puntos->mover();
    balas->mover();

}

void Multijugador::Movimiento()
{
    for(int j=0;j<enemy.length();j++){
             enemy.at(j)->movimiento();
    }
}

void Multijugador::Movimiento1()
{

    for(int j=0;j<enemy1.length();j++){
           enemy1.at(j)->movimiento1();
    }
}

void Multijugador::mousePressEvent(QMouseEvent *event)
{

    if(event->button() == Qt::RightButton) {
        if(balas->getBalas()>0) {
            qDebug() << "Boton Der (Aux)";
            bullets.push_back(new Bullet());
            bullets.back()->setPos((movimiento->getPosx()+60),(movimiento->getPosy()+28));
            scene->addItem(bullets.back());
            balas->setBalas(balas->getBalas()-1);
        }
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
//        ball->setPixmap(QPixmap(nave[0]).scaled(60,60));
        puntos->mover();
        balas->mover();
    }
    else if(event->button() == Qt::MiddleButton) {
        qDebug() << "Boton del Medio (Centro)";
    }
}

bool Multijugador::aleatorio(float p)
{

    int n, x;
    n=rand();
    x=p*(RAND_MAX+1)-1;
    return n<=x;
}
