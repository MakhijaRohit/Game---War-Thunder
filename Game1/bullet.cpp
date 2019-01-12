#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo>

extern Game * game; // external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw bullet
    setPixmap(QPixmap(":/images/bullet.svg"));

    // Timer
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move(){
    // if bullet collides with enemy, destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i =0, n = colliding_items.size(); i < n; ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();

            // remove both of them
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move the bullet Up
    setPos(x(), y()-50);
    if(pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
