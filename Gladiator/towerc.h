#ifndef TOWERC_H
#define TOWERC_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>

class TowerC:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    TowerC(QGraphicsItem *parent = 0);
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

#endif // TOWERC_H
