QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bolita.cpp \
    bullet.cpp \
    enemigo.cpp \
    enemigo1.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    moneda.cpp \
    movimiento_p.cpp \
    muerte.cpp \
    multijugador.cpp \
    pared.cpp \
    score.cpp \
    score2.cpp

HEADERS += \
    bolita.h \
    bullet.h \
    enemigo.h \
    enemigo1.h \
    mainwindow.h \
    menu.h \
    moneda.h \
    movimiento_p.h \
    muerte.h \
    multijugador.h \
    pared.h \
    score.h \
    score2.h

FORMS += \
    mainwindow.ui \
    menu.ui \
    muerte.ui \
    multijugador.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
