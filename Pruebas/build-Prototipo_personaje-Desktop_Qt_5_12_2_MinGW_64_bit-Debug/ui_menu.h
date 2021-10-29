/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Menu
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *maximos_puntajes;
    QLabel *label;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Menu)
    {
        if (Menu->objectName().isEmpty())
            Menu->setObjectName(QString::fromUtf8("Menu"));
        Menu->resize(431, 300);
        Menu->setStyleSheet(QString::fromUtf8("background-image: url(:/imagenes/fondo.jpg);"));
        verticalLayout = new QVBoxLayout(Menu);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(Menu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(Menu);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_2);

        maximos_puntajes = new QPushButton(Menu);
        maximos_puntajes->setObjectName(QString::fromUtf8("maximos_puntajes"));
        maximos_puntajes->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(maximos_puntajes);

        label = new QLabel(Menu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI"));
        font.setPointSize(14);
        label->setFont(font);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        pushButton_4 = new QPushButton(Menu);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_2->raise();
        label->raise();
        pushButton_4->raise();
        pushButton->raise();
        maximos_puntajes->raise();

        retranslateUi(Menu);

        QMetaObject::connectSlotsByName(Menu);
    } // setupUi

    void retranslateUi(QWidget *Menu)
    {
        Menu->setWindowTitle(QApplication::translate("Menu", "Form", nullptr));
        pushButton->setText(QApplication::translate("Menu", "Un jugador", nullptr));
        pushButton_2->setText(QApplication::translate("Menu", "Multijugador", nullptr));
        maximos_puntajes->setText(QApplication::translate("Menu", "Maximos Puntajes", nullptr));
        label->setText(QString());
        pushButton_4->setText(QApplication::translate("Menu", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Menu: public Ui_Menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
