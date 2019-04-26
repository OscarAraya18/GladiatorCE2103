#include "enemy.h"
#include "firearrow.h"
#include <QTimer>
#include <QGraphicsScene>
#include <qmath.h>

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
        if(typeid(*(colliding_items[i])) == typeid (Enemy)){

            //remueve la bala
            //scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // libera memoria
            delete this;
           // delete colliding_items[i];
            return;
        }
    }
    int STEP_SIZE = 30;
    double cita = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(cita));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(cita));

    setPos(x()+ dx, y()+dy);

}
