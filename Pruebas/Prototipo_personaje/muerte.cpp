#include "muerte.h"
#include "ui_muerte.h"
#include <string.h>


muerte::muerte(QString _nombre,int _score,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::muerte)
{
    ui->setupUi(this);
    score=_score;
    nombre=_nombre;
    if(nombre=="Jugador2" || nombre=="Jugador"){
        ui->siguientejugador->setVisible(false);
    }
    else if(nombre=="Jugador1"){
        ui->Salir->setVisible(false);
    }
    ui->label_muerte->setText(QString(nombre));
    ui->label->setNum(score);
}

muerte::~muerte()
{
    delete ui;
}



void muerte::on_siguientejugador_clicked()
{
    close();
    Multijugador *a;
    a=new Multijugador(1,"Jugador2");

    a->show();


}

void muerte::on_Salir_clicked()
{
    close();
}
