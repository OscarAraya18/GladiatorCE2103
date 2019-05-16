#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
/**
 * @brief The Arrow class Esta clase maneja las flechas para la torre normal.
 */
class Arrow: public QObject, public QGraphicsPixmapItem{
        Q_OBJECT
public:
    /**
     * @brief Arrow Constructor de la clase arrow.
     * @param parent
     */
    Arrow(QGraphicsItem *parent=0);
    /**
     * @brief getMaxRange Me devuelve el alcance màximo.
     * @return El alcance màximo.
     */
    double getMaxRange();
    /**
     * @brief getDistanceTravelled Devuelve la distancia recorrida.
     * @return  La distancia recorrida.
     */
    double getDistanceTravelled();
    /**
     * @brief setMaxRange Modifica el rango màximo.
     * @param rng El nuevo valor para el alcance màximo.
     */
    void setMaxRange(double rng);
    /**
     * @brief setDistanceTravelled Modifica la distancia recorrida.
     * @param dis El nuevo valor de la distancia recorrida.
     */
    void setDistanceTravelled(double dis);
public slots:
    /**
     * @brief move Mueve la flecha gràficamente en el juego.
     */
    void move();
private:
    /**
     * @brief maxRange El rango màximo.
     */
    double maxRange;
    /**
     * @brief distanceTravelled La distancia recorrida.
     */
    double distanceTravelled;
};
#endif // ARROW_H
