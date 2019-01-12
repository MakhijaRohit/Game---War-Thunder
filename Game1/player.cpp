#include <QDebug>
#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "bullet.h"
#include "enemy.h"

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

}

void Player::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-50, y());
        }
    }
    else if(event->key() == Qt::Key_Right){
        if(pos().x() + 100 < 1280)
        setPos(x()+50, y());
    }
    else if(event->key() == Qt::Key_Space){
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x() + 45, y());
        scene()->addItem(bullet);
    }
}

void Player::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
