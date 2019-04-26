#include "arrow.h"
#include "enemy.h"
#include "game.h"
#include "towera.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QPen>
#include <QTimer>
#include <iostream>

using namespace std;

extern Game *game;

TowerA::TowerA(QGraphicsItem *parent): QObject (), QGraphicsPixmapItem (parent){
    //se crea los graficos
    setPixmap(QPixmap(":/images/tower1.png"));


    //se crea el vector de puntos
    QVector<QPointF> points;

    points <<  QPoint(0,0) <<  QPoint(1,0) <<  QPoint(1,1) <<  QPoint(0,1);


    //escalar puntos
    int SCALE_FACTOR = 200;
    for(int i=0; i<points.size();i++){
        points[i] *= SCALE_FACTOR;
    }

    //se crea el QGraphicsPolygonItem
    attack_area = new QGraphicsPolygonItem(QPolygonF(points), this);
    attack_area->setPen(QPen(Qt::DotLine));

    //se mueve el poligono
    QPointF poly_center(0.5,0.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);
    QPointF tower_center(x()+40, y()+40);
    QLineF ln(poly_center, tower_center);
    attack_area->setPos(x()+ ln.dx(), y() + ln.dy());

    //se conecta un timer con attack_target
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(aquire_target()));
    timer->start(1000);


}

void TowerA::fire(){
    Arrow *arrow = new Arrow();
    arrow->setPos(x()+40, y()+40);

    QLineF ln(QPointF(x()+40, y()+40), attack_dest);
    int angle = -1 * ln.angle();

    arrow->setRotation(angle);
    game->scene->addItem(arrow);

}

void TowerA::asingPos(int fil, int col){
    setPos(col*70+ 485, fil*70);

}

double TowerA::distanceTo(QGraphicsItem *item){
    QLineF ln(pos(), item->pos());
    return ln.length();

}

void TowerA::aquire_target(){
    QList<QGraphicsItem *> colliding_items = attack_area->collidingItems();

    if(colliding_items.size()== 1){
        has_target = false;
        return;
    }
    double closest_dist = 200;
    QPointF closest_pt = QPointF(0,0);
    for(size_t i =0; i < colliding_items.size(); i++){
        Enemy *enemy = dynamic_cast<Enemy*>(colliding_items[i]);
        if(enemy){
            double this_dist = distanceTo(enemy);
            if(this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = QPointF(colliding_items[i]->x()+32.5, colliding_items[i]->y()+20.5);
                attack_dest = closest_pt;
                //has_target = true;
                fire();
            }
        }
    }
    attack_dest = closest_pt;
}
