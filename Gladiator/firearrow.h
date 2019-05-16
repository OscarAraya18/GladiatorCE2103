#ifndef FIREARROW_H
#define FIREARROW_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

/**
 * @brief The FireArrow class Maneja graficamente las flechas con fuego.
 */
class FireArrow: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    /**
     * @brief FireArrow Constructor de la clase FireArrow.
     * @param parent
     */
    FireArrow(QGraphicsItem *parent=0);
    /**
     * @brief getMaxRange Devuelve el valor del alcance màximo.
     * @return El valor del alcance màximo.
     */
    double getMaxRange();
    /**
     * @brief getDistanceTravelled Devuelve el valor de la distancia recorrida.
     * @return El valor de la distancia recorrida.
     */
    double getDistanceTravelled();
    /**
     * @brief setMaxRange Modifica el valor del alcance màximo.
     * @param rng El nuevo valor del alcance màximo.
     */
    void setMaxRange(double rng);
    /**
     * @brief setDistanceTravelled Modifica el valor de la distancia recorrida.
     * @param dis El nuevo valor de la distancia recorrida.
     */
    void setDistanceTravelled(double dis);
public slots:
    /**
     * @brief move Mueve las flechas graficamente.
     */
    void move();
private:
    double maxRange;
    double distanceTravelled;
};
#endif // FIREARROW_H
