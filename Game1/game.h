#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include "player.h"
#include "score.h"
#include "health.h"
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>

class Game: public QGraphicsView{
public:
    Game(QWidget * parent = 0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;
public slots:
    void CloseGame();
};

#endif // GAME_H
