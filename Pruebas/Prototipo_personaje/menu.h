#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QGraphicsScene>
#include "mainwindow.h"
#include "multijugador.h"
#include "muerte.h"
#include <QDebug>
#include <QFile>

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);

    ~Menu();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();

    void on_maximos_puntajes_clicked();
private:
    Ui::Menu *ui;


};

#endif // MENU_H
