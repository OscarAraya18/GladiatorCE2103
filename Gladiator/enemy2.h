#ifndef ENEMY2_H
#define ENEMY2_H
#include "point.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>

class Enemy2:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy2(QGraphicsItem *parent = 0);
    void rotateToPoint(QPointF p);
    void setPosDef(int fil, int col);
    void move_gladiator();
    void delete_gladiator(int x, int y);
    QList<Point*> camino;
    QTimer *timer;
    QTimer *t;

    QGraphicsPixmapItem *rip;

public slots:
    void move();
    void rip_g();

private:
    QList<QPointF> points;


};

#endif // ENEMY2_H
