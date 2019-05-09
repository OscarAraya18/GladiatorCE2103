#ifndef EXPLOSIVEARROW_H
#define EXPLOSIVEARROW_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
/**
 * @brief The ExplosiveArrow class Maneja de manera gràfiica a las flechas explosivas.
 */
class ExplosiveArrow: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    /**
     * @brief ExplosiveArrow Constructor de la clase ExplosiveArrow.
     * @param parent
     */
    ExplosiveArrow(QGraphicsItem *parent=0);
    /**
     * @brief getMaxRange Devuelve el rango maximo.
     * @return El rango maximo.
     */
    double getMaxRange();
    /**
     * @brief getDistanceTravelled Devuelve la distancia recorrida.
     * @return La distancia recorrida.
     */
    double getDistanceTravelled();
    /**
     * @brief setMaxRange Modifica el valor del alcance maximo.
     * @param rng El nuevo valor del alcance maximo.
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

#endif // EXPLOSIVEARROW_H
