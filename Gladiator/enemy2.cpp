#include "enemy2.h"
#include "game.h"
#include <QTimer>
#include <qmath.h>

extern Game *game;

Enemy2::Enemy2(QGraphicsItem *parent ){
    setPixmap(QPixmap(":/images/enemy.png"));
    tiempo =0;

    //se agregan los puntos
    points << QPointF(200,200) << QPointF(400,200);
    //rotateToPoint(dest);

    timer = new QTimer();
    crono = new QTimer();
    //connect(crono, SIGNAL(timeout()), this, SLOT(actualizar_crono()));
    //crono->start(1000);

}


void Enemy2::rotateToPoint(QPointF p){
    QLineF ln(pos(),p);
    setRotation(-1* ln.angle());

}

void Enemy2::setPosDef(int fil, int col){
    setPos(col*70 + 485, fil*70+30);

}

void Enemy2::move_gladiator()
{
    //conectar el timer con move()

    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(800);
    connect(crono, SIGNAL(timeout()), this, SLOT(actualizar_crono()));
    crono->start(1000);
}

void Enemy2::move(){
    if(camino.length() >0){
        setPosDef(camino[0]->getFila(), camino[0]->getColumna());
        game->board->specs2->setResistenciaT(QString::number(camino[0]->getVida()));
        if(camino[0]->getVida()== 0){
            game->board->specs2->setResistenciaT(QString::number(0));
            //game->scene->removeItem(game->board->enemy2);
            delete_gladiator(camino[0]->getColumna()*70 +485, camino[0]->getFila()*70 -5);
        }
        if(camino[0]->getFila() == 9 && camino[0]->getColumna()==9){

            game->sendMessage(game->converter->pedirDatosGrafica().c_str());
            game->scene->removeItem(this);
        }
        camino.removeAt(0);
    }
    else {
        timer->stop();
        delete timer;
    }
}

void Enemy2::rip_g()
{
    game->scene->removeItem(rip);

    delete rip;
    t->stop();
    delete crono;
    delete t;
    delete this;

}

void Enemy2::actualizar_crono()
{
    tiempo++;
    game->board->setC2(QString::number(tiempo));
}
void Enemy2::delete_gladiator(int x, int y)
{
    t = new QTimer();
    game->scene->removeItem(this);
    rip = new QGraphicsPixmapItem();
    rip->setPixmap(QPixmap(":/images/rip.png"));
    rip->setPos(x,y);
    game->scene->addItem(rip);
    crono->stop();
    connect(t, SIGNAL(timeout()), this, SLOT(rip_g()));
    t->start(500);
}


