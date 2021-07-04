#ifndef GLADIATORCE2103_MATRIZ_H
#define GLADIATORCE2103_MATRIZ_H

#include "NodoMatriz.h"
#include <iostream>
#include <random>


using namespace std;

/**
 * @brief esta Clase representa la matriz logica del juego
 */
class Matriz {
public:
    /**
     * Constructor de la clase Matriz
     * @param cantidadFilas define el tamano vertical de la matriz
     * @param cantidadColumnas define el tamano horizontal de la matriz
     */
    Matriz(int cantidadFilas, int cantidadColumnas);

    /**
     * Por medio de un parametro heuristico se le asigna a cada posicion de la matriz
     * un valor de H para el calculo del Pathfinding A*. Se basa en la formula de distancia
     * entre puntos
     * @param fila posicion vertical del nodo a calcular
     * @param columna posicion horizontal del nodo a calcular
     * @return el heuristico H calculado
     */
    int calculoDistancia(int fila, int columna);

    /**
     * Imprime la matriz en consola. Se puede modificar que dato de las posiciones se
     * desea imprimir
     */
    void mostrarMatriz();

    /**
     * Por cada iteracion se deben colocar 3 torres en la matriz. Primero se genera una posicion aleatoria donde colocar esta torre.
     * Luego se valida que esta posicion no sea el punto de inicio, el punto final o que ya cuente con una torre.
     * Finalmente se evalua que esta posicion no bloquee la unica ruta disponible para que los gladiadores
     * salgan de la zona de intimidacion
     */
    void colocarTorres();

    /**
     * Accede a una posicion de la matriz
     * @param fila posicion vertical del nodo deseado
     * @param columna posicion horozontal del nodo deseado
     * @return el nodo en la posicion deseada
     */
    NodoMatriz* mostrarPosicion(int fila, int columna);

    /**
     * Realiza el calculo de dano en la ruta calculada por el Pathfinding A* y Backtracking
     * @param listaRuta la ruta calculada por los algoritmos Pathfinding
     * @param vidaGladiador la vida del gladiador que recorre la matriz con esa ruta
     * @return un vector con las posiciones de la matriz y la vida respectiva en cada nodo
     */
    vector<NodoMatriz*> listaRutaConVida(vector<NodoMatriz*>listaRuta, int vidaGladiador);

    /**
     * Almacena todas las posiciones de la matriz que tengan torres
     */
    vector<NodoMatriz*> listaTorres;

    /**
     * Guarda el promedio de cada iteracion para la poblacion 1
     */
    vector<double> promedioPoblacion1;

    /**
     * Guarda el promedio de cada iteracion para la poblacion 2
     */
    vector<double > promedioPoblacion2;
    void moverTorres();
    void generarListaTorres();

private:
    /**
     * Almacena el nodo en la esquina superior izquierda de la matriz
     * A partir de ahi se recorren el resto de posiciones
     */
    NodoMatriz* primeraPosicion;

    /**
     * La cantidad de filas de la matriz
     */
    int cantidadFilas;

    /**
     * La cantidad de columnas de la matriz
     */
    int cantidadColumnas;

    /**
     * La cantidad de torres de la matriz
     */
    int cantidadTorres;
};






#endif //GLADIATORCE2103_MATRIZ_H
