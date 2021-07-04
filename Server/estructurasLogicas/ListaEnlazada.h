#ifndef GLADIATORCE2103_LISTAENLAZADA_H
#define GLADIATORCE2103_LISTAENLAZADA_H

#include "Nodo.h"

/**
 * @brief esta clase sirve para manejar la lista enlazada
 */
class listaEnlazada {
public:
    /**
     * Constructor de la clase listaEnlazada, es una lista simplemente enlazada
     */
    listaEnlazada();

    /**
     * Agrega un nodo al final de la lista enlazada
     * @param nodoAgregar el nodo que se quiere agregar al final
     */
    void agregarAlFinal(Nodo* nodoAgregar);

    /**
     * Accede a una posicion dentro de la lista enlazada
     * @param posicion la posicion a buscar dentro de la lista
     * @return el nodo en la posicion solicitada
     */
    Nodo* recorrerLista(int posicion);

    /**
     * Cantidad de elementos dentro de la lista enlazada
     * @return la cantidad de elementos dentro de la lista enlazada
     */
    int getTamano();

private:


    int tamano;
    Nodo* primero;
    Nodo* ultimo;
    Nodo* penultimo;
};


#endif //GLADIATORCE2103_LISTAENLAZADA_t
