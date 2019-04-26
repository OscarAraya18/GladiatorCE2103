#ifndef FIREARROW_H
#define FIREARROW_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class FireArrow: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    FireArrow(QGraphicsItem *parent=0);
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
#endif // FIREARROW_H
