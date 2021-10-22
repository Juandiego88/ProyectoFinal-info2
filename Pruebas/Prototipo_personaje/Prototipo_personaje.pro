QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala.cpp \
    bolita.cpp \
    enemigo.cpp \
    enemigo1.cpp \
    main.cpp \
    mainwindow.cpp \
    moneda.cpp \
    movimiento_p.cpp \
    pared.cpp

HEADERS += \
    bala.h \
    bolita.h \
    enemigo.h \
    enemigo1.h \
    mainwindow.h \
    moneda.h \
    movimiento_p.h \
    pared.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc
