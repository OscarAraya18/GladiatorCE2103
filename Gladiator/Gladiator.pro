#-------------------------------------------------
#
# Project created by QtCreator 2019-04-20T13:36:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gladiator
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    game.cpp \
    piece.cpp \
    board.cpp \
    point.cpp \
    specs.cpp \
    towera.cpp \
    towerb.cpp \
    towerc.cpp \
    arrow.cpp \
    firearrow.cpp \
    explosivearrow.cpp \
    enemy.cpp

HEADERS += \
    game.h \
    piece.h \
    board.h \
    point.h \
    specs.h \
    towera.h \
    towerb.h \
    towerc.h \
    arrow.h \
    firearrow.h \
    explosivearrow.h \
    enemy.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
