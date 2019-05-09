#ifndef TOWERB_H
#define TOWERB_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
/**
 * @brief The TowerB class Maneja graficamente las torres tipo B.
 */
class TowerB:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /**
     * @brief TowerB Constructor de la clase TowerB
     * @param parent
     */
    TowerB(QGraphicsItem *parent = 0);
    /**
     * @brief fire Realiza un ataque.
     */
    void fire();
    /**
     * @brief asingPos Asigna las posiciones de la torre.
     * @param fil La fila.
     * @param col La columna.
     */
    void asingPos(int fil, int col);
    /**
     * @brief distanceTo Define la distancia que hay hasta el enemigo.
     * @param item
     * @return La distancia que hay hasta el enemigo.
     */
    double distanceTo(QGraphicsItem *item);
private:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_dest;
    bool has_target;

public slots:
    /**
     * @brief aquire_target Verifica si un enemigo se encuentra dentro del rango establecido.
     */
    void aquire_target();
};

#endif // TOWERB_H
