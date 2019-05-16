#include <iostream>
#include "estructurasLogicas/ManejadorArchivos.h"
#include "estructurasLogicas/Nodo.h"
#include "estructurasLogicas/ListaEnlazada.h"
#include "estructurasLogicas/Matriz.h"
#include "comunicacion/server.h"
#include "logica/AStar.h"
#include "logica/Algoritmo.h"
#include <stdlib.h>
#include "Backtraking/Backtraking.h"


Server *server;
Matriz *matrizJuego;
AStar *astar;
Backtracking *backtracking;
Algoritmo *genetico1;
Algoritmo *genetico2;
manejadorArchivos *baseDeDatosPoblacion1;
manejadorArchivos *baseDeDatosPoblacion2;
listaEnlazada *listaGeneticaPoblacion1;
listaEnlazada *listaGeneticaPoblacion2;

using namespace std;

void *serverRun(void *){
    try{
        server->run();
    }
    catch(string ex){
       cout<<ex<<endl;
    }
    pthread_exit(NULL);
}


int main() {

    baseDeDatosPoblacion1 = new manejadorArchivos("Poblacion 1");
    baseDeDatosPoblacion2 = new manejadorArchivos("Poblacion 2");
    listaGeneticaPoblacion1 = new listaEnlazada();
    listaGeneticaPoblacion2 = new listaEnlazada();
    baseDeDatosPoblacion1->generarPoblacionInicial(listaGeneticaPoblacion1);
    baseDeDatosPoblacion2->generarPoblacionInicial(listaGeneticaPoblacion2);

    matrizJuego = new Matriz(10,10);

    genetico1 = new Algoritmo();
    genetico2 = new Algoritmo();


    astar = new AStar();

    backtracking = new Backtracking();


    server = Server::getInstance();
    pthread_t hiloServer;
    pthread_create(&hiloServer,0,serverRun,NULL);
    pthread_detach(hiloServer);


    while(true){
        string mensaje;

        cin>> mensaje;
        server->setMensaje(mensaje.c_str());
    }

}
