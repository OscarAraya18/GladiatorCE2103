#include "NodoMatriz.h"
#include <iostream>
using namespace std;


NodoMatriz::NodoMatriz(int H, int ID, NodoMatriz* posicionIzquierda, NodoMatriz* posicionArriba,
        NodoMatriz* posicionDerecha, NodoMatriz* posicionAbajo, int fila, int columna) {
    this->H = H;
    G=0;
    this->ID = ID;
    this->posicionIzquierda = posicionIzquierda;
    this->posicionArriba = posicionArriba;
    this->posicionDerecha = posicionDerecha;
    this->posicionAbajo = posicionAbajo;

    this->fila = fila;
    this->columna = columna;

    presenciaTorre = false;
    torreEnemiga = nullptr;
}




NodoMatriz* NodoMatriz::getPosicionAbajo() {
    return posicionAbajo;
}

NodoMatriz* NodoMatriz::getPosicionArriba() {
    return posicionArriba;
}

NodoMatriz* NodoMatriz::getPosicionIzquierda() {
    return posicionIzquierda;
}

NodoMatriz* NodoMatriz::getPosicionDerecha() {
    return posicionDerecha;
}

void NodoMatriz::setPosicionAbajo(NodoMatriz *posicionAbajo) {
    this->posicionAbajo = posicionAbajo;
}

void NodoMatriz::setPosicionDerecha(NodoMatriz *posicionDerecha) {
    this->posicionDerecha = posicionDerecha;
}



void NodoMatriz::setTorreEnemiga(TorreEnemiga *torreEnemiga) {
    this->torreEnemiga = torreEnemiga;
    presenciaTorre = true;
}

TorreEnemiga* NodoMatriz::getTorreEnemiga() {
    return torreEnemiga;
}


int NodoMatriz::getID() {
    return ID;
}

int NodoMatriz::getG() {
    return G;
}


void NodoMatriz::actualizarF() {
    F = G + H;
}
