#ifndef MUERTE_H
#define MUERTE_H

#include <QWidget>
#include "mainwindow.h"
#include "score.h"
#include <QString>
#include "multijugador.h"

namespace Ui {
class muerte;
}

class muerte : public QWidget
{
    Q_OBJECT

public:
    explicit muerte(QString _nombre,int _score,QWidget *parent = nullptr);
    ~muerte();

private slots:


    void on_siguientejugador_clicked();

    void on_Salir_clicked();

private:
    Ui::muerte *ui;
    int score=0;
     QString nombre;
};

#endif // MUERTE_H
