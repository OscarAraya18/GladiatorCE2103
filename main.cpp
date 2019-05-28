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
#include <gtest/gtest.h>


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
/*int main() {

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

    matrizJuego->moverTorres();
    matrizJuego->mostrarMatriz();
    matrizJuego->generarListaTorres();

    server = Server::getInstance();
    pthread_t hiloServer;
    pthread_create(&hiloServer,0,serverRun,NULL);
    pthread_detach(hiloServer);

    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();

    while(true){
        string mensaje;

        cin>> mensaje;
        server->setMensaje(mensaje.c_str());
    }

}*/

int main(int ac, char* av[])
{
    matrizJuego = new Matriz(10,10);
    backtracking = new Backtracking();
    astar = new AStar();
    baseDeDatosPoblacion1 = new manejadorArchivos("Poblacion 1");
    baseDeDatosPoblacion2 = new manejadorArchivos("Poblacion 2");

    listaGeneticaPoblacion1 = new listaEnlazada();
    listaGeneticaPoblacion2 = new listaEnlazada();

    baseDeDatosPoblacion1->generarPoblacionInicial(listaGeneticaPoblacion1);
    baseDeDatosPoblacion2->generarPoblacionInicial(listaGeneticaPoblacion2);
    genetico1 = new Algoritmo();
    genetico2 = new Algoritmo();

    testing::InitGoogleTest(&ac, av);
    return RUN_ALL_TESTS();
}


TEST(BacktrackingTest, rutaBack){

    ASSERT_EQ(0, backtracking->getListaRuta().size());

    backtracking->actualizarMatrizLogica(matrizJuego);
    backtracking->runBackTracking(0,0,9,9);

    EXPECT_LT(9, backtracking->getListaRuta().size());
}


TEST(aStartTest, rutaAstar){

    ASSERT_EQ(0, astar->getListaRuta().size());

    backtracking->actualizarMatrizLogica(matrizJuego);
    backtracking->runBackTracking(0,0,9,9);

    EXPECT_LT(9, backtracking->getListaRuta().size());
}

TEST(GeneticoTest, generarPoblacion){

    //Se crea una poblacion1 inicial
    genetico1->rungenetico(listaGeneticaPoblacion1);
    baseDeDatosPoblacion1->eliminarArchivo();
    double  prom1 = genetico1->pro_fitness();
    matrizJuego->promedioPoblacion1.push_back(prom1);
    baseDeDatosPoblacion1->escribirNuevaPoblacion(genetico1->vec_gladiadores);
    listaGeneticaPoblacion1 = baseDeDatosPoblacion1->leerArchivo();

    //se guarda el promedio del fitness de la poblacion 1
    double aux1 = prom1;

    //se crea una poblacion2 inicial
    genetico2->rungenetico(listaGeneticaPoblacion2);
    baseDeDatosPoblacion2->eliminarArchivo();
    double  prom2 = genetico2->pro_fitness();
    matrizJuego->promedioPoblacion2.push_back(prom2);
    baseDeDatosPoblacion2->escribirNuevaPoblacion(genetico2->vec_gladiadores);
    listaGeneticaPoblacion2 = baseDeDatosPoblacion2->leerArchivo();

    //se guarda el promedio del fitness de la poblacion 2
    double aux2= prom2;

    //se compara si despues de la ejecucion del algoritmo
    //siguen habiendo 100 gladiadores
    EXPECT_LE(100,genetico1->vec_gladiadores.size());
    EXPECT_LE(100,genetico2->vec_gladiadores.size());

    //ordeno y elimino a los 10 peores gladiadores de cada poblacion
    genetico1->quickSort(0,99);
    genetico1->fitness_menor();
    genetico2->quickSort(0,99);
    genetico2->fitness_menor();

    //comparo si se eliminaron los 10 peores gladiadores de cada poblacion
    EXPECT_LE(90,genetico1->vec_gladiadores.size());
    EXPECT_LE(90,genetico2->vec_gladiadores.size());

    //se vuelven a ejecutar el algoritmo para cada poblacion
    genetico1->rungenetico(listaGeneticaPoblacion1);
    baseDeDatosPoblacion1->eliminarArchivo();
    prom1 = genetico1->pro_fitness();
    matrizJuego->promedioPoblacion1.push_back(prom1);
    baseDeDatosPoblacion1->escribirNuevaPoblacion(genetico1->vec_gladiadores);
    listaGeneticaPoblacion1 = baseDeDatosPoblacion1->leerArchivo();

    genetico2->rungenetico(listaGeneticaPoblacion2);
    baseDeDatosPoblacion2->eliminarArchivo();
    prom2 = genetico2->pro_fitness();
    matrizJuego->promedioPoblacion2.push_back(prom2);
    baseDeDatosPoblacion2->escribirNuevaPoblacion(genetico2->vec_gladiadores);
    listaGeneticaPoblacion2 = baseDeDatosPoblacion2->leerArchivo();

    //se compara a ver si el fitness promedio de cada poblacion mejora
    EXPECT_LE(aux1, prom1);
    EXPECT_LE(aux2, prom2);
}

TEST(matrizTest, rutaVida){
    matrizJuego->colocarTorres();
    astar->iniciar(matrizJuego);
    //vector<NodoMatriz*> vec = matrizJuego->listaRutaConVida(astar->getListaRuta(), 10);

    //cout << "PUTA " << vec.at(0)->vida << endl;
    //EXPECT_EQ(10, vec.at(0)->vida);


}