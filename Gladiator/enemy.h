#ifndef ENEMY_H
#define ENEMY_H
#include "point.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
/**
 * @brief The Enemy class Maneja de manera gràfica el primer gladiador.
 */
class Enemy:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /**
     * @brief Enemy Constructor de la clase Enemy.
     * @param parent
     */
    Enemy(QGraphicsItem *parent = 0);
    /**
     * @brief rotateToPoint Permite la rotacion del personaje.
     * @param p Un punto.
     */
    void rotateToPoint(QPointF p);
    /**
     * @brief setPosDef Define las posiciones del gladiador.
     * @param fil La fila en el tablero.
     * @param col La columna en el tablero.
     */
    void setPosDef(int fil, int col);
    /**
     * @brief move_gladiator Mueve al gladiador en el tablero.
     */
    void move_gladiator();
    /**
     * @brief delete_gladiator Elimina al gladiador de la pantalla.
     * @param x La nueva posicion en x.
     * @param y La nueva posicion en y.
     */
    void delete_gladiator(int x, int y);
    QList<Point*> camino;
    QTimer *timer;
    QTimer *t;
    QTimer *crono;

    QGraphicsPixmapItem *rip;
public slots:
    /**
     * @brief move Mueve al gladiador en la pantalla siguiendo su ruta.
     */
    void move();
    /**
     * @brief rip_g Elimina al gladiador del juego.
     */
    void rip_g();
    /**
     * @brief actualizar_crono Actualiza el cronòmetro.
     */
    void actualizar_crono();
private:
    QList<QPointF> points;
    int tiempo;


};

#endif // ENEMY_H
