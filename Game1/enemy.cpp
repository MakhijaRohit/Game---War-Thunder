#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <stdlib.h>

extern Game * game;

Enemy::Enemy(): QObject(), QGraphicsPixmapItem(){
    // set random number
    int random_number = rand() % 1200;
    setPos(random_number, 0);
    setPixmap(QPixmap(":/images/enemy.svg"));

    // Timer
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move(){
    // move the enemy down
    setPos(x(), y() + 15);
    if(pos().y() > 720){
        // decrease the health
        game->health->decrease();

        // delete the enemy after it goes out of the screen.
        scene()->removeItem(this);
        delete this;
    }
}
