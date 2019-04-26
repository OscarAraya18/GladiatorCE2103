#include "arrow.h"
#include "enemy.h"
#include <QTimer>
#include <qmath.h>
#include <QGraphicsScene>

Arrow::Arrow(QGraphicsItem *parent){
    setPixmap(QPixmap(":/images/arrow.png"));

    //se crea un timer
    QTimer *move_timer= new QTimer(this);
    connect(move_timer,SIGNAL(timeout()),this, SLOT(move()));
    move_timer->start(50);

    //inicializo valores
    maxRange= 100;
    distanceTravelled = 0;

}

double Arrow::getMaxRange()
{
    return maxRange;
}

double Arrow::getDistanceTravelled()
{
    return distanceTravelled;
}

void Arrow::setMaxRange(double rng)
{
    maxRange = rng;
}

void Arrow::setDistanceTravelled(double dis)
{
    distanceTravelled = dis;
}

void Arrow::move(){
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
