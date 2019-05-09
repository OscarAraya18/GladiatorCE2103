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
    //connect(crono, SIGNAL(timeout()), this, SLOT(actualizar_crono()));
    //crono->start(1000);

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
    timer->start(600);
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
    t->start(1000);
}

void Enemy::move(){
    if(camino.length() >0){
        setPosDef(camino[0]->getFila(), camino[0]->getColumna());
        game->board->specs->setResistenciaT(QString::number(camino[0]->getVida()));
        if(camino[0]->getVida()== 0){
            delete_gladiator(camino[0]->getColumna()*70 +485, camino[0]->getFila()*70 -5);
        }
        if(camino[0]->getVida() > 0 && camino[0]->getFila() == 10 && camino[0]->getColumna()==10){
            QVector<double> gen1, fitness1, gen2, fitness2;
            gen1 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13 << 14 << 15 << 16 << 17 << 18 << 19 << 20;
            gen2 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13 << 14 << 15 << 16 << 17 << 18 << 19 << 20;
            fitness1 << 1.23 << 1.89 << 2.43  << 4.65 << 6.32 << 25.32 << 30.56 << 43.23 << 54.24 << 57.23 << 63.78 << 63.78 << 68.9 << 72.13 << 76.23 << 81.48 << 87.23 << 93.45 << 94.2 << 97.32;
            fitness2 << 1.34 << 2.45 << 10.43  << 16.67 << 18.45 << 24.23 << 26.67 << 45.23 << 50.23 << 55.7 << 55.9 << 57.98 << 60.34 << 64.33 << 66.45 << 75.67 << 82.45 << 86.34 << 95.34 << 96.45;
            Grafico->desplegarGrafica(gen1,fitness1,gen2,fitness2);

            Grafico->show();
           game->close();
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




