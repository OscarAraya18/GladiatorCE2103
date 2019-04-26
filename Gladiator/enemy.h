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
    QList<Point*> camino;
    QTimer *timer;
public slots:
    void move();
private:
    QList<QPointF> points;


};

#endif // ENEMY_H
