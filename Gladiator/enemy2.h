#ifndef ENEMY2_H
#define ENEMY2_H
#include "point.h"

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList>
#include <QPointF>
/**
 * @brief The Enemy2 class Maneja de manera gràfica al segundo gladiador.
 */
class Enemy2:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    /**
     * @brief Enemy2 Constructor de la clase Enemy2.
     * @param parent
     */
    Enemy2(QGraphicsItem *parent = 0);
    /**
     * @brief rotateToPoint Permite la rotacion del personaje.
     * @param p Un punto.
     */
    void rotateToPoint(QPointF p);
    /**
     * @brief setPosDef Define las posiciones del gladiador en el tablero.
     * @param fil La fila.
     * @param col La columna.
     */
    void setPosDef(int fil, int col);
    /**
     * @brief move_gladiator Mueve al gladiador.
     */
    void move_gladiator();
    /**
     * @brief delete_gladiator Elimina al gladiador.
     * @param x Su posicion en x.
     * @param y Su posicion en y.
     */
    void delete_gladiator(int x, int y);
    QList<Point*> camino;
    QTimer *timer;
    QTimer *t;
    QTimer *crono;

    QGraphicsPixmapItem *rip;

public slots:
    /**
     * @brief move Mueve al gladiador en la pantalla.
     */
    void move();
    /**
     * @brief rip_g Elimina al gladiador del juego.
     */
    void rip_g();
    /**
     * @brief actualizar_crono Actualiza el cronometro.
     */
    void actualizar_crono();

private:
    QList<QPointF> points;
    int tiempo;



};

#endif // ENEMY2_H
