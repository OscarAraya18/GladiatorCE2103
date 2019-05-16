//
// Created by oscar_araya_x on 13/05/19.
//

#include "Backtraking.h"
#include <iostream>
using namespace std;

extern Matriz *matrizJuego;

Backtracking::Backtracking(){
    cantidadColumnas =10;
    cantidadFilas = 10;
    TORRE = 2;
    LIBRE = 0;
    RUTA = 1;

}

void Backtracking::runBackTracking(int xo, int yo, int xf, int yf) {

/**
 * Stop condition of the recursive method, in this case the list of
 * pointers to area is returned with the free path that is in the zone of intimidation
 *
 * */

    if (xo == xf && yo == yf) {
        solucion[xf][yf] = 1;
        return imprimirMatriz();

    }


    if (yo < yf) {
        if ((solucion[xo][yo+1] != TORRE) && (solucion[xo][yo] != RUTA) && (solucion[xo][yo] != TORRE)){
            solucion[xo][yo] = 1;
            return runBackTracking(xo, yo + 1, xf, yf);
        }
        else {
            if (solucion[xo + 1][yo] != TORRE) {
                if (solucion[xo][yo] != RUTA) {
                    solucion[xo][yo] = RUTA;
                }
                return runBackTracking(xo + 1, yo, xf, yf);

            }
            else if(solucion[xo + 1][yo+1] != TORRE){
                if (solucion[xo][yo] != RUTA) {
                    solucion[xo][yo] = RUTA;
                }
                return runBackTracking(xo + 1, yo+1, xf, yf);
            }
            else if(solucion[xo + 1][yo-1] != TORRE && yo > 0){
                if (solucion[xo][yo] != RUTA) {
                    solucion[xo][yo] = RUTA;
                }
                return runBackTracking(xo + 1, yo-1, xf, yf);
            }
            else if (solucion[xo][yo] != RUTA) {
                solucion[xo][yo] = 2;
                if (solucion[xo][yo - 1] == TORRE) {
                    cout << "LEGUE" <<endl;
                    return runBackTracking(xo - 1, yo, xf, yf);
                }
                else if(solucion[xo-1][yo] == TORRE){
                    if(solucion[xo-1][yo-1] == TORRE){
                        return runBackTracking(xo - 1, yo +1, xf, yf);
                    }
                    return runBackTracking(xo - 1, yo-1, xf, yf);
                }
                return runBackTracking(xo, yo - 1, xf, yf);
            }
            else if(solucion[xo][yo] == RUTA){
                if (solucion[xo][yo - 1] == TORRE) {
                    return runBackTracking(xo - 1, yo, xf, yf);
                }
                else if(solucion[xo-1][yo] == TORRE){
                    if(solucion[xo-1][yo-1] == TORRE){
                        return runBackTracking(xo - 1, yo +1, xf, yf);
                    }
                    return runBackTracking(xo - 1, yo-1, xf, yf);
                }
                return runBackTracking(xo, yo - 1, xf, yf);
            }


        }
    }

    if (yo == yf ) {

        if (solucion[xo+1][yo] != TORRE) {
            solucion[xo][yo] = 1;
            return runBackTracking(xo +1, yo, xf, yf);

        }

        else if(solucion[xo][yo-1] != TORRE ) {
            if (solucion[xo][yo] != RUTA) {
                solucion[xo][yo] = RUTA;
            }
            solucion[xo][yo] = TORRE;
            return runBackTracking(xo, yo - 1, xf, yf);

        }
        else if(solucion[xo+1][yo-1] != TORRE){
            if (solucion[xo][yo] != RUTA) {
                solucion[xo][yo] = RUTA;
            }

            return runBackTracking(xo+1, yo - 1, xf, yf);
        }
        else if (solucion[xo][yo] != RUTA) {
            if (solucion[xo][yo - 1] == TORRE) {
                solucion[xo][yo] = 2;
                return runBackTracking(xo - 1, yo, xf, yf);
            }
            else if(solucion[xo-1][yo] == TORRE){
                if(solucion[xo-1][yo-1] != TORRE){
                    solucion[xo][yo] = 2;
                    return runBackTracking(xo - 1, yo -1, xf, yf);
                }
            }
            return runBackTracking(xo, yo - 1, xf, yf);
        }
        else if(solucion[xo][yo] == RUTA){
            if (solucion[xo][yo - 1] == TORRE) {
                return runBackTracking(xo - 1, yo, xf, yf);
            }
            else if(solucion[xo][yo-1] != TORRE){
                solucion[xo][yo] = 1;
                return runBackTracking(xo, yo - 1, xf, yf);
            }
            else if(solucion[xo-1][yo] == TORRE){
                if(solucion[xo-1][yo-1] != TORRE){
                    return runBackTracking(xo - 1, yo -1, xf, yf);
                }
            }

            return runBackTracking(xo, yo - 1, xf, yf);
        }


    }

}

void Backtracking::imprimirMatriz() {
    for (int i = 0; i < cantidadFilas; ++i) {
        for (int j = 0; j < cantidadColumnas; ++j) {
            cout << solucion[i][j] <<  " ";
        }
        cout<<endl;
    }

}

void Backtracking::actualizarMatrizLogica(Matriz *matrizJuego) {
    for(int i=0; i<cantidadFilas;i++){
        for(int j=0; j<cantidadColumnas; j++){
            if(matrizJuego->mostrarPosicion(i+1,j+1)->presenciaTorre){
                solucion[i][j] = 2;
            }
            else{
                solucion[i][j] = 0;
            }
        }
    }
}

vector<NodoMatriz *> Backtracking::getListaRuta() {
    listaDeRuta.clear();
    for(int i=0; i<cantidadFilas;i++){
        for(int j=0; j<cantidadColumnas; j++) {
            if (solucion[i][j] == 1) {
                NodoMatriz *aux = matrizJuego->mostrarPosicion(i+1, j+1);
                listaDeRuta.push_back(aux);
            }
        }
    }
    return listaDeRuta;
}

