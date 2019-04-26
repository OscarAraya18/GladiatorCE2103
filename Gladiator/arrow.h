#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>


class Arrow: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    Arrow(QGraphicsItem *parent=0);
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
#endif // ARROW_H
