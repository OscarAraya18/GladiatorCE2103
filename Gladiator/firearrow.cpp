#include "enemy.h"
#include "firearrow.h"
#include "game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <qmath.h>

extern Game *game;

FireArrow::FireArrow(QGraphicsItem *parent){
    setPixmap(QPixmap(":/images/firearrow.png"));

    //se crea un timer
    QTimer *move_timer= new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this, SLOT(move()));
    move_timer->start(50);

    //inicializo valores
    maxRange= 100;
    distanceTravelled = 0;


}

double FireArrow::getMaxRange()
{
    return maxRange;
}

double FireArrow::getDistanceTravelled()
{
    return distanceTravelled;
}

void FireArrow::setMaxRange(double rng)
{
    maxRange = rng;
}

void FireArrow::setDistanceTravelled(double dis)
{
    distanceTravelled = dis;
}

void FireArrow::move(){
    QList<QGraphicsItem*> colliding_items =collidingItems();
    for( int i = 0; i < colliding_items.size(); i++){
        if(typeid(*(colliding_items[i])) == typeid (Enemy) || typeid(*(colliding_items[i])) == typeid (Enemy2)
                || 500>x() || x()>1000 || y()<5 || y() > 1000){

            if(typeid(*(colliding_items[i])) == typeid (Enemy)){
                //Sgame->board->enemy->delete_gladiator(game->board->enemy->x(), game->board->enemy->y());

            }
            else if(typeid(*(colliding_items[i])) == typeid (Enemy2)){
                //game->board->enemy2->delete_gladiator(game->board->enemy->x(), game->board->enemy->y());
            }
            //remueve la bala
            scene()->removeItem(this);
            // libera memoria
            delete this;
            return;
        }
    }
    int STEP_SIZE = 30;
    double cita = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(cita));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(cita));

    setPos(x()+ dx, y()+dy);

}
