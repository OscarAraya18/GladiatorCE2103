#include "board.h"
#include "enemy.h"
#include "game.h"
#include "towera.h"
#include "towerb.h"
#include "towerc.h"
#include <iostream>
#include "point.h"
#include "specs.h"
#include "square.h"
#include "include/rapidjson/document.h"

using namespace std;

extern Game *game;

Board::Board(){


}

void Board::drawBoard(){
    int x = 490;
    QFont fuente("comic sans", 12);

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            Square *piece = new Square();
            piece->setPos(x + i*70, 5 + j*70);
            game->scene->addItem(piece);
        }
    }

    QPen *pen = new QPen();
    pen->setStyle(Qt::SolidLine);
    pen->setWidth(3);
    crono1 = new QGraphicsRectItem();
    crono1->setPen(*pen);
    crono1->setBrush(QBrush(Qt::lightGray));
    QGraphicsTextItem *title1 = new QGraphicsTextItem("Tiempo G1:");
    title1->setFont(fuente);
    title1->setPos(350,65);
    crono1->setRect(350, 60, 100,70);
    c1 = new QGraphicsTextItem("0");
    c1->setPos(350, 85);
    c1->setFont(fuente);
    game->scene->addItem(crono1);
    game->scene->addItem(c1);
    game->scene->addItem(title1);

    crono2 = new QGraphicsRectItem();
    crono2->setPen(*pen);
    crono2->setBrush(QBrush(Qt::lightGray));
    QGraphicsTextItem *title2 = new QGraphicsTextItem("Tiempo G2:");
    title2->setFont(fuente);
    title2->setPos(350,385);
    crono2->setRect(350, 380, 100,70);
    c2 = new QGraphicsTextItem("0");
    c2->setPos(350, 410);
    c2->setFont(fuente);
    game->scene->addItem(crono2);
    game->scene->addItem(c2);
    game->scene->addItem(title2);


    Point *point = new Point(0,0,17);
    Point *point2 = new Point(1,0,16);
    Point *point3 = new Point(2,0,15);
    Point *point4 = new Point(3,0,14);
    Point *point5 = new Point(4,0,13);
    Point *point6 = new Point(5,0,12);
    Point *point7 = new Point(6,0,11);
    Point *point8 = new Point(7,0,10);
    Point *point9 = new Point(8,0,9);
    Point *point10 = new Point(8,1,8);
    Point *point11 = new Point(7,1,7);
    Point *point12 = new Point(6,1,6);
    Point *point13 = new Point(5,1,5);
    Point *point14 = new Point(5,2,4);
    Point *point15 = new Point(5,3,3);
    Point *point16 = new Point(5,4,2);
    Point *point17 = new Point(6,4,1);
    Point *point18 = new Point(7,4,0);

    TowerA *tower1 = new TowerA();
    TowerB *tower2 = new TowerB();
    TowerC *tower3 = new TowerC();
    enemy = new Enemy();
    enemy2 = new Enemy2();

    specs = new Specs();
    specs2 = new Specs();


    enemy->camino.append(point);
    enemy->camino.append(point2);
    enemy->camino.append(point3);
    enemy->camino.append(point4);
    enemy->camino.append(point5);
    enemy->camino.append(point6);
    enemy->camino.append(point7);
    enemy->camino.append(point8);
    enemy->camino.append(point9);
    enemy->camino.append(point10);
    enemy->camino.append(point11);
    enemy->camino.append(point12);
    enemy->camino.append(point13);
    enemy->camino.append(point14);
    enemy->camino.append(point15);
    enemy->camino.append(point16);
    enemy->camino.append(point17);
    enemy->camino.append(point18);


    tower1->asingPos(1,1);
    tower2->asingPos(5,5);
    tower3->asingPos(4,7);
    enemy->setPosDef(0,0);
    enemy2->setPosDef(0,0);

    specs->setPos(25, 60);
    specs2->setPos(25, 380);
    game->scene->addItem(specs);
    game->scene->addItem(specs2);

    enemy->move_gladiator();
    specs->crearSpecs();
    specs2->crearSpecs();

    game->scene->addItem(tower1);
    game->scene->addItem(tower2);
    game->scene->addItem(tower3);
    game->scene->addItem(enemy);
    game->scene->addItem(enemy2);

}

QGraphicsTextItem *Board::getC2() const
{
    return c2;
}

void Board::setC2(QString value)
{
    c2->setPlainText(value);
}

QGraphicsTextItem *Board::getC1() const
{
    return c1;
}

void Board::setC1(QString value)
{
    c1->setPlainText(value);
}
