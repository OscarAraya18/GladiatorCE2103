#include "board.h"
#include "enemy.h"
#include "game.h"
#include "piece.h"
#include "towera.h"
#include "towerb.h"
#include "towerc.h"
#include <iostream>
#include "point.h"
#include "specs.h"

using namespace std;

extern Game *game;

Board::Board(){


}

void Board::drawBoard(){
    int x = 490;

    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            Piece *piece = new Piece();
            piece->setPos(x + i*70, 5 + j*70);
            game->scene->addItem(piece);
        }
    }
    Point *point = new Point(0,0);
    Point *point2 = new Point(1,0);
    Point *point3 = new Point(2,0);
    Point *point4 = new Point(3,0);
    Point *point5 = new Point(4,0);
    Point *point6 = new Point(5,0);
    Point *point7 = new Point(6,0);
    Point *point8 = new Point(7,0);
    Point *point9 = new Point(8,0);
    Point *point10 = new Point(8,1);
    Point *point11 = new Point(7,1);
    Point *point12 = new Point(6,1);
    Point *point13 = new Point(5,1);
    Point *point14 = new Point(5,2);
    Point *point15 = new Point(5,3);
    Point *point16 = new Point(5,4);
    Point *point17 = new Point(6,4);
    Point *point18 = new Point(7,4);

    TowerA *tower1 = new TowerA();
    TowerB *tower2 = new TowerB();
    TowerC *tower3 = new TowerC();
    Enemy *enemy = new Enemy();

    Specs *specs = new Specs();
    Specs *specs2 = new Specs();


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
    enemy->setPosDef(2,2);

    specs->setPos(100, 60);
    specs2->setPos(100, 380);
    game->scene->addItem(specs);
    game->scene->addItem(specs2);

    enemy->move_gladiator();
    specs->crearSpecs();
    specs2->crearSpecs();

    game->scene->addItem(tower1);
    game->scene->addItem(tower2);
    game->scene->addItem(tower3);
    game->scene->addItem(enemy);

}
