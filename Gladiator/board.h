#ifndef BOARD_H
#define BOARD_H

#include "enemy.h"
#include "enemy2.h"
#include "specs.h"


class Board
{
public:
    Board();

    void drawBoard();

    Enemy *enemy;
    Enemy2 *enemy2;

    QGraphicsTextItem *getC2() const;
    void setC2(QString value);

    QGraphicsTextItem *getC1() const;
    void setC1(QString value);

    void agregarGladiator1();
    void agregarGladiator2();

    void agregarTorre1(int x, int y);
    void agregarTorre2(int x, int y);
    void agregarTorre3(int x, int y);


    Specs *specs;
    Specs *specs2;

private:
    QGraphicsRectItem *crono1;
    QGraphicsRectItem *crono2;

    QGraphicsTextItem *c1;
    QGraphicsTextItem *c2;

};

#endif // BOARD_H
