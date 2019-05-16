#include "enemy.h"
#include "game.h"
#include <QThread>
#include <QTimer>
#include <qmath.h>
#include "grafico.h"
extern Game *game;
extern grafico *Grafico;
Enemy::Enemy(QGraphicsItem *parent ){
    setPixmap(QPixmap(":/images/enemy.png"));
    tiempo =0;
    //se agregan los puntos
    points << QPointF(200,200) << QPointF(400,200);

    game->board->setC1(QString::number(tiempo));

    timer = new QTimer();
    crono = new QTimer();

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
    timer->start(800);
    connect(crono, SIGNAL(timeout()), this, SLOT(actualizar_crono()));
    crono->start(1000);
}

void Enemy::delete_gladiator(int x, int y)
{
    t = new QTimer();
    crono->stop();
    game->scene->removeItem(this);
    rip = new QGraphicsPixmapItem();
    rip->setPixmap(QPixmap(":/images/rip.png"));
    rip->setPos(x+10,y);
    game->scene->addItem(rip);

    connect(t, SIGNAL(timeout()), this, SLOT(rip_g()));
    t->start(500);

}

void Enemy::move(){
    if(camino.length() >0){
        setPosDef(camino[0]->getFila(), camino[0]->getColumna());
        game->board->specs->setResistenciaT(QString::number(camino[0]->getVida()));
        if(camino[0]->getVida()== 0){
            game->board->specs->setResistenciaT(QString::number(0));
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

void Enemy::rip_g()
{
    game->scene->removeItem(rip);

    delete rip;
    t->stop();
    delete crono;
    delete t;
    delete this;
}

void Enemy::actualizar_crono()
{
    tiempo++;
    game->board->setC1(QString::number(tiempo));
}




