#include "enemy.h"
#include <QTimer>
#include <qmath.h>

Enemy::Enemy(QGraphicsItem *parent ){
    setPixmap(QPixmap(":/images/enemy.png"));

    //se agregan los puntos
    points << QPointF(200,200) << QPointF(400,200);
    //rotateToPoint(dest);

    timer = new QTimer();

}


void Enemy::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1* ln.angle());

}

void Enemy::setPosDef(int fil, int col){
    setPos(col*70 + 485, fil*70-5);

}

void Enemy::move_gladiator()
{
    //conectar el timer con move()

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(1500);
}

void Enemy::move(){
    if(camino.length() >0){
        setPosDef(camino[0]->getFila(), camino[0]->getColumna());
        camino.removeAt(0);
    }
    else {
        timer->stop();
    }

}


