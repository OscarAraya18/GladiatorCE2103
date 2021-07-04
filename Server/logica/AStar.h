#ifndef GLADIATORCE2103_ASTAR_H
#define GLADIATORCE2103_ASTAR_H
#include<bits/stdc++.h>

#include "estructurasLogicas/Matriz.h"

/**
 * Genera una estructura de tipo pair a partir de una posicion x y una posicion y
 */
typedef pair<int, int> Pair;

/**
 * Genera una estructura de tipo pair a partir de un double y un pair
 */
typedef pair<double, pair<int, int>> pPair;


using namespace std;

/**
 * @brief Clase encargada de calcular el Pathfinding A* utilizando una matriz de juego
 */
class AStar {

    /**
     * Estructura que contiene la informacion de cada una de las celdas
     * de la matriz
     */
    struct cell{
        int padreX;
        int padreY;
        double f;
        double g;
        double h;
    };


public:
    /**
     * Constructor de la clase AStar. Define la posicion inicial y la posicion final
     */
    AStar();

    /**
     * Actualiza la matriz interna con las torres que se han colocado. Inicia el algoritmo de manera iterativa
     * hasta que se encuantre una ruta o el programa determine que no hay camino posible
     * @param matrizJuego Matriz logica del programa para actualizar los obstaculos
     */
    void iniciar(Matriz* matrizJuego);

    /**
     * Valida si la posicion a la que se quiere acceder dentro de la ejecucion del algoritmo
     * esta dentro de la matriz y no es una torre
     * @param fila fila de la pocision analizada
     * @param columna columna de la pocision analizada
     * @return true si es valida, false en caso contrario
     */
    bool revisarValidezNodo(int fila, int columna);

    /**
     * Actualiza la matriz interna con la informacion de la matriz logica
     */
    void actualizarMatrizLogica();

    /**
     * Inicia el calculo de la ruta
     * @param matrizLogica matriz sobre la cual se busca la ruta
     * @param posicionInicial donde se inicia el calculo de la ruta
     * @param posicionFinal donde se desea llegar
     */
    void aStarSearch(int matrizLogica[10][10], Pair posicionInicial, Pair posicionFinal);

    /**
     * Genera el camino encontrado
     * @param cellDetails es la informacion de las posiciones por donde pasa el camino
     * @param dest el destino
     */
    void tracePath(cell cellDetails[][10], Pair dest);

    /**
     * Accede a la lista con la ruta encontrada
     * @return la lista con la ruta encontrada
     */
    vector<NodoMatriz*> getListaRuta();

    /**
     * Es un flag que indica si el algoritmo A* ha encontrado al menos
     * una ruta posible desde la posicion inicial hasta la final. Se utiliza para validar si
     * cuando se colocan torres queda al menos una ruta para que los gladiadores puedan cruzar
     */
    bool destinoEncontrado;

private:
    const int cantidadColumnas = 10;
    const int cantidadFilas = 10;

    Matriz* matrizJuego;

    /**
     * Se hace una conversion desde la estructura de datos MatrizJuego
     * a un arreglo en dos dimensiones
     */
    int matrizLogica[10][10];

    Pair posicionInicial;
    Pair posicionFinal;

    vector<NodoMatriz*> listaDeRuta;


};


#endif //GLADIATORCE2103_ASTAR_H
