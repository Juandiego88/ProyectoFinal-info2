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
