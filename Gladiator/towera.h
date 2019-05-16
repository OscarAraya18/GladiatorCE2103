#ifndef TOWERA_H
#define TOWERA_H
#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
/**
 * @brief The TowerA class Maneja de manera grafica las torres tipo A.
 */
class TowerA:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /**
     * @brief TowerA Constructor de la clase TowerA.
     * @param parent
     */
    TowerA(QGraphicsItem *parent = 0);
    /**
     * @brief fire Realiza un ataque.
     */
    void fire();
    /**
     * @brief asingPos Define las posiciones de la torre.
     * @param fil La fila.
     * @param col La columna.
     */
    void asingPos(int fil, int col);
    /**
     * @brief distanceTo Define la distancia que tiene hasta el enemigo.
     * @param item
     * @return
     */
    double distanceTo(QGraphicsItem *item);

private:
    QGraphicsPolygonItem *attack_area;
    QPointF attack_dest;
    bool has_target;

public slots:/**
     * @brief aquire_target Valida si un enemigo se encuentra dentro del rango.
     */
    void aquire_target();
};

#endif // TOWERA_H
