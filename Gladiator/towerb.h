#ifndef TOWERB_H
#define TOWERB_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>

class TowerB:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    TowerB(QGraphicsItem *parent = 0);
    void fire();
    void asingPos(int fil, int col);
    double distanceTo(QGraphicsItem *item);

private:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_dest;
    bool has_target;

public slots:
    void aquire_target();
};

#endif // TOWERB_H
