#include <QFont>
#include <QDebug>
#include "health.h"
#include <QGraphicsObject>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to zero
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // health = 3
    setDefaultTextColor(Qt::green);
    setFont(QFont("times", 16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // health = 2
}

int Health::getHealth(){
    return health;
}
