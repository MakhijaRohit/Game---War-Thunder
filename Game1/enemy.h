#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "game.h"
class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
private:
    int count = 3;
};

#endif // ENEMY_H
