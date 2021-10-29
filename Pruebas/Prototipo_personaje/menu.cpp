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
//    MainWindow *a;
      a=new MainWindow();
      a->show();
//    a->numero=1;
//    a->show();
}

void Menu::on_pushButton_2_clicked()
{
//    MainWindow *a;
//    a=new MainWindow();
//    a->numero=2;
//    a->show();
}

void Menu::on_pushButton_4_clicked()
{

}

void Menu::on_maximos_puntajes_clicked()
{
    //Agregamos los mayores marcadores, desde un archivo
    QFile a;
    QByteArray contenido;
    a.setFileName("C:/Users/dsroj/Documents/GitHub/ProyectoFinal-info2/Pruebas/build-Prototipo_personaje-Desktop_Qt_6_0_2_MinGW_64_bit-Debug/max_puntajes.txt");
    if(!a.exists()) {
        qDebug() << "El archivo no existe!";
    }
    else if(a.exists()) {
        a.open(QIODevice::ReadWrite | QIODevice::Text);
        if(a.isOpen()) {
            contenido = a.readAll();
        }
    }
//    ui->label->setText(QString("MAXIMOS PUNTAJES: "));
    ui->label->setText(contenido);
    qDebug() << contenido;
}
