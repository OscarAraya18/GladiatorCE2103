//
// Created by oscar_araya_x on 13/05/19.
//

#ifndef GLADIATORCE2103_BACKTRAKING_H
#define GLADIATORCE2103_BACKTRAKING_H


#include <estructurasLogicas/Matriz.h>

/**
 * @brief Clase Backtracking
 */
class Backtracking
{
public:
/**
 *constructor de la clase
 */
    Backtracking();
/**
 *
 * @param xo es la pocisión de la fila en la que se evalua el backtracking
 * @param yo es la pocisión de la columna en la que se evalua el backtracking
 * @param xf es la pocisión de la fila limite para el backtracking no se salga de la matriz
 * @param yf es la pocisión de la columna limite para el backtracking no se salga de la matriz
 */
    void runBackTracking(int xo, int yo, int xf, int yf);
/**
 *metodo que convierte la matriz logica a un matriz de enteros para trabajar el algoritmo
 * @param matrizJuego matriz logica donde se encuentran las torres
 */
    void actualizarMatrizLogica(Matriz *matrizJuego);

/**
 *metodo para obtener la lista final de las posiciones por donde pasa la ruta final del algoritmo
 * @return un vector con las posiciones de la matriz
 */
    vector<NodoMatriz*> getListaRuta();
/**
 *imprime la matriz para ver la ruta en consola y un entendimiento mas facil
 */
    void imprimirMatriz();


private:
/**
 *diferentes atributos para el funcionamiento del algoritmo
 */
    int solucion[10][10];
    int cantidadFilas;
    int cantidadColumnas;
    vector<NodoMatriz*> listaDeRuta;

    int TORRE;
    int LIBRE;
    int RUTA;
    int PASE;
};


#endif //GLADIATORCE2103_BACKTRAKING_H
