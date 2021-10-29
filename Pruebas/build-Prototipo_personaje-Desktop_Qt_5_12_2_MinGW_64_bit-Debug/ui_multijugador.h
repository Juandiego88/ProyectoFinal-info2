/********************************************************************************
** Form generated from reading UI file 'multijugador.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIJUGADOR_H
#define UI_MULTIJUGADOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multijugador
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Multijugador)
    {
        if (Multijugador->objectName().isEmpty())
            Multijugador->setObjectName(QString::fromUtf8("Multijugador"));
        Multijugador->resize(1537, 753);
        centralwidget = new QWidget(Multijugador);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 25, 1500, 750));
        Multijugador->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Multijugador);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1537, 21));
        Multijugador->setMenuBar(menubar);
        statusbar = new QStatusBar(Multijugador);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Multijugador->setStatusBar(statusbar);

        retranslateUi(Multijugador);

        QMetaObject::connectSlotsByName(Multijugador);
    } // setupUi

    void retranslateUi(QMainWindow *Multijugador)
    {
        Multijugador->setWindowTitle(QApplication::translate("Multijugador", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multijugador: public Ui_Multijugador {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIJUGADOR_H
