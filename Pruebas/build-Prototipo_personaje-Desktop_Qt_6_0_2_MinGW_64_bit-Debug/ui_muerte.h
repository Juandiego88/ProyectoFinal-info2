/********************************************************************************
** Form generated from reading UI file 'muerte.ui'
**
** Created by: Qt User Interface Compiler version 6.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUERTE_H
#define UI_MUERTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_muerte
{
public:
    QPushButton *siguientejugador;
    QPushButton *Salir;
    QLabel *label;
    QLabel *label_muerte;

    void setupUi(QWidget *muerte)
    {
        if (muerte->objectName().isEmpty())
            muerte->setObjectName(QString::fromUtf8("muerte"));
        muerte->resize(400, 300);
        muerte->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        siguientejugador = new QPushButton(muerte);
        siguientejugador->setObjectName(QString::fromUtf8("siguientejugador"));
        siguientejugador->setGeometry(QRect(140, 170, 101, 31));
        siguientejugador->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        Salir = new QPushButton(muerte);
        Salir->setObjectName(QString::fromUtf8("Salir"));
        Salir->setGeometry(QRect(140, 220, 101, 23));
        Salir->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(muerte);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 50, 121, 41));
        QFont font;
        font.setPointSize(13);
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label_muerte = new QLabel(muerte);
        label_muerte->setObjectName(QString::fromUtf8("label_muerte"));
        label_muerte->setGeometry(QRect(50, 50, 111, 41));
        label_muerte->setFont(font);
        label_muerte->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label->raise();
        label_muerte->raise();
        siguientejugador->raise();
        Salir->raise();

        retranslateUi(muerte);

        QMetaObject::connectSlotsByName(muerte);
    } // setupUi

    void retranslateUi(QWidget *muerte)
    {
        muerte->setWindowTitle(QCoreApplication::translate("muerte", "Form", nullptr));
#if QT_CONFIG(whatsthis)
        muerte->setWhatsThis(QCoreApplication::translate("muerte", "<html><head/><body><p><img src=\":/imagenes/multiverso.png\"/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        siguientejugador->setText(QCoreApplication::translate("muerte", "Siguiente jugador", nullptr));
        Salir->setText(QCoreApplication::translate("muerte", "Salir", nullptr));
        label->setText(QCoreApplication::translate("muerte", "TextLabel", nullptr));
        label_muerte->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class muerte: public Ui_muerte {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUERTE_H
