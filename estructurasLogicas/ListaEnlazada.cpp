#include "ListaEnlazada.h"

listaEnlazada::listaEnlazada() {
    tamano = 0;
    primero = nullptr;
}


void listaEnlazada::agregarAlFinal(Nodo* nodoAgregar) {
    if(primero== nullptr){
        primero = nodoAgregar;
    }else{
        Nodo *nodoAuxiliar = primero;
        while (nodoAuxiliar->getSiguiente() != NULL) {
            nodoAuxiliar = nodoAuxiliar->getSiguiente();
        }
        nodoAuxiliar->setSiguiente(nodoAgregar);
        ultimo = nodoAgregar;
        penultimo = nodoAuxiliar;
    }
    tamano++;
}

Nodo* listaEnlazada::recorrerLista(int posicion) {
    Nodo* nodoAuxiliar = primero;
    while (posicion!=0){
        nodoAuxiliar = nodoAuxiliar->getSiguiente();
        posicion--;
    }
    return nodoAuxiliar;
}



int listaEnlazada::getTamano() {
    return tamano;
}




