#include "game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "enemy.h"
#include <QDebug>
#include <QMediaPlayer>

extern Game * game;

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1280,720); // make the scene 1280x720 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/bg_game1.jpg")));
    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1366,720);

    // create the player
    player = new Player();
    player->setPixmap(QPixmap(":/images/plane.svg")); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(640,620); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    //create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

//    // play music
//    QMediaPlayer * music = new QMediaPlayer();
//    music->setMedia(QUrl(":/sounds/bgsound.mp3"));
//    music->play();

    show();
}
