#ifndef TOWERC_H
#define TOWERC_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
/**
 * @brief The TowerC class Maneja graficamente las torres tipo C.
 */
class TowerC:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /**
     * @brief TowerC Constructor de la clase TowerC.
     * @param parent
     */
    TowerC(QGraphicsItem *parent = 0);
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
     * @brief aquire_target Verifica si un enemigo se encuentra dentro del rango.
     */
    void aquire_target();
};

#endif // TOWERC_H
