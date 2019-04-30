#include "board.h"
#include "game.h"

#include <QMediaPlayer>

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,1200,800);
    setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg")));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);
    setScene(scene);

    board = new Board();
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/music.mp3"));
    music->play();


}
