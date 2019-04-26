#ifndef EXPLOSIVEARROW_H
#define EXPLOSIVEARROW_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class ExplosiveArrow: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    ExplosiveArrow(QGraphicsItem *parent=0);
    double getMaxRange();
    double getDistanceTravelled();
    void setMaxRange(double rng);
    void setDistanceTravelled(double dis);
public slots:
    void move();
private:
    double maxRange;
    double distanceTravelled;
};

#endif // EXPLOSIVEARROW_H
