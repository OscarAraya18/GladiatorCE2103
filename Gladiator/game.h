#ifndef GAME_H
#define GAME_H
#include "board.h"

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView
{
public:
    Game(QWidget *parent=0);
    //atributos

    QGraphicsScene *scene;
    Board *board;

};

#endif // GAME_H
