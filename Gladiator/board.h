#ifndef BOARD_H
#define BOARD_H

#include "enemy.h"
#include "enemy2.h"
#include "specs.h"

/**
 * @brief The Board class Constrola un tablero gràfico en el juego.
 */
class Board
{
public:
    /**
     * @brief Board Cosntructor de la clase Board.
     */
    Board();
    /**
     * @brief drawBoard Despliega el tablero en pantalla.
     */
    void drawBoard();
    /**
     * @brief enemy El primer gladiador.
     */
    Enemy *enemy;
    /**
     * @brief enemy2 El segundo gladiador.
     */
    Enemy2 *enemy2;
    /**
     * @brief getC2 Retorna el valor del contador 2.
     * @return El valor del contador 2.
     */
    QGraphicsTextItem *getC2() const;
    /**
     * @brief setC2 Modifica el valor del contador 2.
     * @param value El nuevo valor del contador 2.
     */
    void setC2(QString value);
    /**
     * @brief getC1 Retorna el valor del contador 1.
     * @return El valor del contador 1.
     */
    QGraphicsTextItem *getC1() const;
    /**
     * @brief setC1 Modifica el valor del contador 1.
     * @param value El nuevo valor del contador 1.
     */
    void setC1(QString value);
    /**
     * @brief agregarGladiator1 Coloca el gladiador 1 en la pantalla del juego.
     */
    void agregarGladiator1();
    /**
     * @brief agregarGladiator2 Coloca el gladiador 2 en la pantalla del juego.
     */
    void agregarGladiator2();
    /**
     * @brief agregarTorre1 Coloca una torre de tipo 1 en la pantalla.
     * @param x Posiciòn en x.
     * @param y Posiciòn en y.
     */
    void agregarTorre1(int x, int y);
    /**
     * @brief agregarTorre2 Coloca una torre de tipo 2 en la pantalla.
     * @param x Posiciòn en x.
     * @param y Posiciòn en y.
     */
    void agregarTorre2(int x, int y);
    /**
     * @brief agregarTorre3 Coloca una torre de tipo 3 en la pantalla.
     * @param x Posiciòn en x.
     * @param y Posiciòn en y.
     */
    void agregarTorre3(int x, int y);
    Specs *specs;
    Specs *specs2;

    QGraphicsRectItem *inicio;
    QGraphicsRectItem *final;

private:
    QGraphicsRectItem *crono1;
    QGraphicsRectItem *crono2;

    QGraphicsTextItem *c1;
    QGraphicsTextItem *c2;

};

#endif // BOARD_H
