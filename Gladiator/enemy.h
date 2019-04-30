#ifndef ENEMY_H
#define ENEMY_H
#include "point.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Enemy:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QGraphicsItem *parent = 0);
    void rotateToPoint(QPointF p);
    void setPosDef(int fil, int col);
    void move_gladiator();
    void delete_gladiator(int x, int y);
    QList<Point*> camino;
    QTimer *timer;
    QTimer *t;
    QTimer *crono;

    QGraphicsPixmapItem *rip;
public slots:
    void move();
    void rip_g();
    void actualizar_crono();
private:
    QList<QPointF> points;
    int tiempo;


};

#endif // ENEMY_H
