#include "menu.h"
#include "ui_menu.h"


Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);


}

Menu::~Menu()
{
    delete ui;

}

void Menu::on_pushButton_clicked()
{
    MainWindow *a;
    a=new MainWindow();
    a->show();
}

void Menu::on_pushButton_2_clicked()
{
    Multijugador *b;
    b=new Multijugador(0,"Jugador1");
    b->show();
}

void Menu::on_pushButton_4_clicked()
{
    close();
}

void Menu::on_pushButton_3_clicked()
{

}

void Menu::on_maximos_puntajes_clicked()
{
    //Agregamos los mayores marcadores, desde un archivo
    QFile a;
    QByteArray contenido;
    a.setFileName("../max_puntajes.txt");
    if(!a.exists()) {
        qDebug() << "El archivo no existe!";
    }
    else if(a.exists()) {
        a.open(QIODevice::ReadWrite | QIODevice::Text);
        if(a.isOpen()) {
            contenido = a.readAll();
        }
    }
    ui->label->setText(contenido);
    qDebug() << contenido;
}
