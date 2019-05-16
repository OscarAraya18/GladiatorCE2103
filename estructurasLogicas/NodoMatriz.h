#ifndef GLADIATORCE2103_NODOMATRIZ_H
#define GLADIATORCE2103_NODOMATRIZ_H

#include "../entidades/TorreEnemiga.h"

/**
 * @brief Elemento para almacenar datos
 */
class NodoMatriz {
public:

    /**
     * Constructor de la clase NodoMatriz. Compone la matriz de juego
     * @param H el heuristico que determina la distancia entre el punto y la salida
     * @param ID identificador de las posiciones de la matriz
     * @param posicionIzquierda un puntero al nodo matriz que se encuantra hacia la izquierda
     * @param posicionArriba un puntero al nodo matriz que se encuantra hacia arriba
     * @param posicionDerecha un puntero al nodo matriz que se encuantra hacia la derecha
     * @param posicionAbajo un puntero al nodo matriz que se encuantra hacia abajo
     * @param fila la fila donde se encuentra el nodo
     * @param columna la columna donde se encuentra el nodo
     */
    NodoMatriz(int H, int ID, NodoMatriz* posicionIzquierda,
            NodoMatriz* posicionArriba, NodoMatriz* posicionDerecha,
            NodoMatriz* posicionAbajo, int fila, int columna);


    NodoMatriz* getPosicionIzquierda();
    NodoMatriz* getPosicionDerecha();
    NodoMatriz* getPosicionArriba();
    NodoMatriz* getPosicionAbajo();
    void setPosicionAbajo(NodoMatriz* posicionAbajo);
    void setPosicionDerecha(NodoMatriz* posicionDerecha);
    void setTorreEnemiga(TorreEnemiga* torreEnemiga);


    /**
     * Devuelve la torre que se encuentra en ese nodo
     * @return la torre
     */
    TorreEnemiga* getTorreEnemiga();

    /**
     * Indica si hay torre en el nodo
     */
    bool presenciaTorre;

    int getID();
    int getG();

    /**
     * Recalcula el F cada vez que se cambia la posicion dentro del algoritmo pathfinding A*
     */
    void actualizarF();

    /**
     * Auxiliar que determina si se tiene que corregir una posicion
     */
    bool correccion;

    /**
     * Vida del gladiador en cada NodoMatriz. Se calcula en el metodo getRutaConVida();
     */
    int vida;
    int fila;
    int columna;

    TorreEnemiga* torreEnemiga;
    NodoMatriz* posicionIzquierda;
    NodoMatriz* posicionDerecha;
    NodoMatriz* posicionArriba;
    NodoMatriz* posicionAbajo;

    int ID;
    int H;

private:

    /**
     * Es el nodo padre asignado dentro del algoritmo Pathfinding A*
     */
    NodoMatriz* padre;
    int F;


    /**
     * Costo de movimiento desde la posicion actual hasta alguna de las posiciones
     * adyacentes del NodoMatriz
     */
    int G;

};

#endif //GLADIATORCE2103_NODOMATRIZ_H