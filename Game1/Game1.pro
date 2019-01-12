#-------------------------------------------------
#
# Project created by QtCreator 2017-04-14T01:43:22
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game1
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    player.cpp \
    score.cpp \
    health.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    player.h \
    score.h \
    health.h

RESOURCES += \
    res.qrc
