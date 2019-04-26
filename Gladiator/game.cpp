#include "board.h"
#include "game.h"

Game::Game(QWidget *parent){

    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,1200,800);
    setBackgroundBrush(QBrush(QImage(":/images/madera.png")));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);
    setScene(scene);

    board = new Board();


}
