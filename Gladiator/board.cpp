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

    inicio = new QGraphicsRectItem(493,7,65,65);

    final = new QGraphicsRectItem(1121,637, 65,65);
    QPen *pen2 = new QPen(Qt::red);
    pen2->setStyle(Qt::SolidLine);
    pen2->setWidth(3);

    QPen *pen3 = new QPen(Qt::green);
    pen3->setStyle(Qt::SolidLine);
    pen3->setWidth(3);

    inicio->setPen(*pen3);
    final->setPen(*pen2);


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

    //Cronometro para el gladiador 1
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

    game->scene->addItem(inicio);
    game->scene->addItem(final);


    //Cronometro para el gladiador 1
    crono2 = new QGraphicsRectItem();
    crono2->setPen(*pen);
    crono2->setBrush(QBrush(Qt::lightGray));
    QGraphicsTextItem *title2 = new QGraphicsTextItem("Tiempo G2:");
    title2->setFont(fuente);
    title2->setPos(350,428);
    crono2->setRect(350, 428, 100,70);
    c2 = new QGraphicsTextItem("0");
    c2->setPos(350, 448);
    c2->setFont(fuente);


    game->scene->addItem(crono2);
    game->scene->addItem(c2);
    game->scene->addItem(title2);

    specs = new Specs();
    specs2 = new Specs();


    specs->setPos(25, 60);
    specs2->setPos(25, 428);
    game->scene->addItem(specs);
    game->scene->addItem(specs2);

    specs->crearSpecs();
    specs2->crearSpecs();

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

void Board::agregarGladiator1()
{
    enemy = new Enemy();
    enemy->setPosDef(0,0);
    game->scene->addItem(enemy);
}

void Board::agregarGladiator2()
{
    enemy2 = new Enemy2();
    enemy2->setPosDef(0,0);
    game->scene->addItem(enemy2);
}

void Board::agregarTorre1(int x, int y)
{
    TowerA *t = new TowerA();
    t->asingPos(x,y);
    game->scene->addItem(t);
}

void Board::agregarTorre2(int x, int y)
{
    TowerB *t = new TowerB();
    t->asingPos(x,y);
    game->scene->addItem(t);
}

void Board::agregarTorre3(int x, int y)
{
    TowerC *t = new TowerC();
    t->asingPos(x,y);
    game->scene->addItem(t);
}
