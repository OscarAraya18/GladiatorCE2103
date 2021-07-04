#include "Matriz.h"
#include "../logica/AStar.h"

vector<NodoMatriz*> Matriz::listaRutaConVida(vector<NodoMatriz*> listaRuta, int vidaGladiador) {
    NodoMatriz* nodoDeLista;
    NodoMatriz* nodoDeMatriz;

    for(int i=0; i<listaRuta.size();i++){

        nodoDeLista = listaRuta.at(i);
        nodoDeMatriz = mostrarPosicion(nodoDeLista->fila,nodoDeLista->columna);
        nodoDeLista->vida = vidaGladiador;

        //ASIGNACION

        NodoMatriz* norte = nodoDeMatriz->getPosicionArriba();
        NodoMatriz* este = nodoDeMatriz->getPosicionDerecha();
        NodoMatriz* sur = nodoDeMatriz->getPosicionAbajo();
        NodoMatriz* oeste = nodoDeMatriz->getPosicionIzquierda();

        NodoMatriz *noreste = nullptr;
        NodoMatriz *sureste = nullptr;
        NodoMatriz *suroeste = nullptr;
        NodoMatriz *noroeste = nullptr;

        if(norte!= nullptr){
            if(oeste!= nullptr) {
                noroeste = nodoDeMatriz->getPosicionArriba()->getPosicionIzquierda();
            }
            if(este!= nullptr){
                noreste = nodoDeMatriz->getPosicionArriba()->getPosicionDerecha();
            }
        }

        if(sur!= nullptr){
            if(oeste!= nullptr){
                suroeste = nodoDeMatriz->getPosicionAbajo()->getPosicionIzquierda();
            }
            if(este!= nullptr){
                sureste = nodoDeMatriz->getPosicionAbajo()->getPosicionDerecha();
            }
        }


        //VALIDACION DE DAÑO

        if(norte!= nullptr){
            if(norte->presenciaTorre){
                if(norte->getTorreEnemiga()->getTipoTorre()==1 && vidaGladiador>0){
                    vidaGladiador--;
                }else if(norte->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                    vidaGladiador -=2;
                }else{
                    if(vidaGladiador>0) {
                        vidaGladiador -= 4;
                    }
                }
                nodoDeLista->vida = vidaGladiador;
            }
            if(norte->getPosicionArriba()!= nullptr){
                if(norte->getPosicionArriba()->presenciaTorre) {
                    if (norte->getPosicionArriba()->getTorreEnemiga()->getTipoTorre() == 2 && vidaGladiador > 0) {
                        vidaGladiador -= 2;
                    } else if (norte->getPosicionArriba()->getTorreEnemiga()->getTipoTorre() == 3 && vidaGladiador > 0) {
                        vidaGladiador -= 4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }
            }
        }


        if(vidaGladiador<=0){
            nodoDeLista->vida = 0;
            return listaRuta;
        }




        if(noreste!= nullptr){
            if(noreste->presenciaTorre){
                if(noreste->getTorreEnemiga()->getTipoTorre()==1 && vidaGladiador>0){
                    vidaGladiador--;
                }else if(noreste->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                    vidaGladiador -=2;
                }else{
                    if(vidaGladiador>0) {
                        vidaGladiador -= 4;
                    }
                }
                nodoDeLista->vida = vidaGladiador;
            }

            if(noreste->getPosicionArriba()!= nullptr){

                if(noreste->getPosicionArriba()->presenciaTorre){
                    if(noreste->getPosicionArriba()->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                        vidaGladiador-=2;
                    }else if(noreste->getPosicionArriba()->getTorreEnemiga()->getTipoTorre()==3 && vidaGladiador>0){
                        vidaGladiador-=4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }

                if(noreste->getPosicionArriba()->getPosicionDerecha()!= nullptr) {
                    if(noreste->getPosicionArriba()->getPosicionDerecha()->presenciaTorre) {
                        if (noreste->getPosicionArriba()->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre() ==
                            2 && vidaGladiador > 0) {
                            vidaGladiador -= 2;
                        } else if (noreste->getPosicionArriba()->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre() == 3 && vidaGladiador > 0) {
                            vidaGladiador -= 4;
                        }
                        nodoDeLista->vida = vidaGladiador;
                    }
                }
            }

            if(noreste->getPosicionDerecha() != nullptr){
                if(noreste->getPosicionDerecha()->presenciaTorre){
                    if(noreste->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                        vidaGladiador-=2;
                    }else if(noreste->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre()==3 && vidaGladiador >0){
                        vidaGladiador -=4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }
            }
        }


        if(vidaGladiador<=0){
            nodoDeLista->vida = 0;
            return listaRuta;
        }



        if(este!= nullptr){
            if(este->presenciaTorre){
                if(este->getTorreEnemiga()->getTipoTorre()==1 && vidaGladiador>0){
                    vidaGladiador--;
                }else if(este->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                    vidaGladiador -=2;
                }else{
                    if(vidaGladiador>0) {
                        vidaGladiador -= 4;
                    }
                }
                nodoDeLista->vida = vidaGladiador;
            }
            if(este->getPosicionDerecha()!= nullptr){
                if(este->getPosicionDerecha()->presenciaTorre) {
                    if (este->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre() == 2 && vidaGladiador > 0) {
                        vidaGladiador -= 2;
                    } else if (este->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre() == 3 && vidaGladiador > 0) {
                        vidaGladiador -= 4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }
            }
        }

        if(vidaGladiador<=0){
            nodoDeLista->vida = 0;
            return listaRuta;
        }




        if(sureste!= nullptr){
            if(sureste->presenciaTorre){
                if(sureste->getTorreEnemiga()->getTipoTorre()==1 && vidaGladiador>0){
                    vidaGladiador--;
                }else if(sureste->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                    vidaGladiador -=2;
                }else{
                    if(vidaGladiador>0) {
                        vidaGladiador -= 4;
                    }
                }
                nodoDeLista->vida = vidaGladiador;
            }

            if(sureste->getPosicionAbajo()!= nullptr){

                if(sureste->getPosicionAbajo()->presenciaTorre){
                    if(sureste->getPosicionAbajo()->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                        vidaGladiador-=2;
                    }else if(sureste->getPosicionAbajo()->getTorreEnemiga()->getTipoTorre()==3 && vidaGladiador>0){
                        vidaGladiador-=4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }

                if(sureste->getPosicionAbajo()->getPosicionDerecha()!= nullptr) {
                    if(sureste->getPosicionAbajo()->getPosicionDerecha()->presenciaTorre) {
                        if (sureste->getPosicionAbajo()->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre() == 2 &&
                            vidaGladiador > 0) {
                            vidaGladiador -= 2;
                        } else if (sureste->getPosicionAbajo()->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre() == 3 && vidaGladiador > 0) {
                            vidaGladiador -= 4;
                        }
                        nodoDeLista->vida = vidaGladiador;
                    }
                }
            }

            if(sureste->getPosicionDerecha() != nullptr){
                if(sureste->getPosicionDerecha()->presenciaTorre){
                    if(sureste->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                        vidaGladiador-=2;
                    }else if(sureste->getPosicionDerecha()->getTorreEnemiga()->getTipoTorre()==3 && vidaGladiador >0){
                        vidaGladiador -=4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }
            }
        }

        if(vidaGladiador<=0){
            nodoDeLista->vida = 0;
            return listaRuta;
        }



        if(sur!= nullptr){
            if(sur->presenciaTorre){
                if(sur->getTorreEnemiga()->getTipoTorre()==1 && vidaGladiador>0){
                    vidaGladiador--;
                }else if(sur->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                    vidaGladiador -=2;
                }else{
                    if(vidaGladiador>0) {
                        vidaGladiador -= 4;
                    }
                }
                nodoDeLista->vida = vidaGladiador;
            }
            if(sur->getPosicionAbajo()!= nullptr){
                if(sur->getPosicionAbajo()->presenciaTorre) {
                    if (sur->getPosicionAbajo()->getTorreEnemiga()->getTipoTorre() == 2 && vidaGladiador > 0) {
                        vidaGladiador -= 2;
                    } else if (sur->getPosicionAbajo()->getTorreEnemiga()->getTipoTorre() == 3 && vidaGladiador > 0) {
                        vidaGladiador -= 4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }
            }
        }

        if(vidaGladiador<=0){
            nodoDeLista->vida = 0;
            return listaRuta;
        }



        if(suroeste!= nullptr){
            if(suroeste->presenciaTorre){
                if(suroeste->getTorreEnemiga()->getTipoTorre()==1 && vidaGladiador>0){
                    vidaGladiador--;
                }else if(suroeste->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                    vidaGladiador -=2;
                }else{
                    if(vidaGladiador>0) {
                        vidaGladiador -= 4;
                    }
                }
                nodoDeLista->vida = vidaGladiador;
            }

            if(suroeste->getPosicionAbajo()!= nullptr){

                if(suroeste->getPosicionAbajo()->presenciaTorre){
                    if(suroeste->getPosicionAbajo()->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                        vidaGladiador-=2;
                    }else if(suroeste->getPosicionAbajo()->getTorreEnemiga()->getTipoTorre()==3 && vidaGladiador>0){
                        vidaGladiador-=4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }

                if(suroeste->getPosicionAbajo()->getPosicionIzquierda()!= nullptr) {
                    if(suroeste->getPosicionAbajo()->getPosicionIzquierda()->presenciaTorre) {
                        if (suroeste->getPosicionAbajo()->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre() == 2 && vidaGladiador > 0) {
                            vidaGladiador -= 2;
                        } else if (suroeste->getPosicionAbajo()->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre() == 3 && vidaGladiador > 0) {
                            vidaGladiador -= 4;
                        }
                        nodoDeLista->vida = vidaGladiador;
                    }
                }
            }

            if(suroeste->getPosicionIzquierda() != nullptr){
                if(suroeste->getPosicionIzquierda()->presenciaTorre){
                    if(suroeste->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                        vidaGladiador-=2;
                    }else if(suroeste->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre()==3 && vidaGladiador >0){
                        vidaGladiador -=4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }
            }
        }

        if(vidaGladiador<=0){
            nodoDeLista->vida = 0;
            return listaRuta;
        }



        if(oeste!= nullptr){
            if(oeste->presenciaTorre){
                if(oeste->getTorreEnemiga()->getTipoTorre()==1 && vidaGladiador>0){
                    vidaGladiador--;
                }else if(oeste->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                    vidaGladiador -=2;
                }else{
                    if(vidaGladiador>0) {
                        vidaGladiador -= 4;
                    }
                }
                nodoDeLista->vida = vidaGladiador;
            }
            if(oeste->getPosicionIzquierda()!= nullptr){
                if(oeste->getPosicionIzquierda()->presenciaTorre) {
                    if (oeste->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre() == 2 && vidaGladiador > 0) {
                        vidaGladiador -= 2;
                    } else if (oeste->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre() == 3 && vidaGladiador > 0) {
                        vidaGladiador -= 4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }
            }
        }

        if(vidaGladiador<=0){
            nodoDeLista->vida = 0;
            return listaRuta;
        }





        if(noroeste!= nullptr){
            if(noroeste->presenciaTorre){
                if(noroeste->getTorreEnemiga()->getTipoTorre()==1 && vidaGladiador>0){
                    vidaGladiador--;
                }else if(noroeste->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                    vidaGladiador -=2;
                }else{
                    if(vidaGladiador>0) {
                        vidaGladiador -= 4;
                    }
                }
                nodoDeLista->vida = vidaGladiador;
            }

            if(noroeste->getPosicionArriba()!= nullptr){

                if(noroeste->getPosicionArriba()->presenciaTorre){
                    if(noroeste->getPosicionArriba()->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                        vidaGladiador-=2;
                    }else if(noroeste->getPosicionArriba()->getTorreEnemiga()->getTipoTorre()==3 && vidaGladiador>0){
                        vidaGladiador-=4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }


                if(noroeste->getPosicionArriba()->getPosicionIzquierda()!= nullptr) {
                    if(noroeste->getPosicionArriba()->getPosicionIzquierda()->presenciaTorre) {
                        if (noroeste->getPosicionArriba()->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre() == 2 && vidaGladiador > 0) {
                            vidaGladiador -= 2;
                        } else if (noroeste->getPosicionArriba()->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre() == 3 && vidaGladiador > 0) {
                            vidaGladiador -= 4;
                        }
                        nodoDeLista->vida = vidaGladiador;
                    }
                }
            }

            if(noroeste->getPosicionIzquierda() != nullptr){
                if(noroeste->getPosicionIzquierda()->presenciaTorre){
                    if(noroeste->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre()==2 && vidaGladiador>0){
                        vidaGladiador-=2;
                    }else if(noroeste->getPosicionIzquierda()->getTorreEnemiga()->getTipoTorre()==3 && vidaGladiador >0){
                        vidaGladiador -=4;
                    }
                    nodoDeLista->vida = vidaGladiador;
                }
            }
        }

        //cout<<"LA VIDA EN LA POSICION ("<<nodoDeLista->fila<<" , "<<nodoDeLista->columna<<") ES "<<nodoDeLista->vida<<endl;

        if(vidaGladiador<=0){
            nodoDeLista->vida = 0;
            return listaRuta;
        }

    }
    return listaRuta;
}




int Matriz::calculoDistancia(int cantidadFilas, int cantidadColumnas) {
    int distancia = 0;
    for (int columna = 0; columna < cantidadColumnas-1; columna++){
        distancia++;
    }
    for (int fila = 0; fila < cantidadFilas-1; fila++) {
        distancia++;
    }
    return abs(distancia-18);
}






Matriz::Matriz(int cantidadFilas, int cantidadColumnas) {
    this->cantidadFilas = cantidadFilas+1;
    this->cantidadColumnas = cantidadColumnas;
    cantidadTorres = 0;
    NodoMatriz *posicionIzquierda = nullptr;
    NodoMatriz *posicionArriba = nullptr;
    NodoMatriz *posicionDerecha = nullptr;
    NodoMatriz *posicionAbajo = nullptr;
    NodoMatriz *primeroEnColumna = nullptr;
    int contador = 1;

    for (int columna = 1; columna <= cantidadColumnas ; columna++) {
        for (int fila = 1; fila <= cantidadFilas; fila++) {


            /* USO
             * DEL
             * HEAP
             */

            NodoMatriz *nodoPosicion = (NodoMatriz*)malloc(sizeof(NodoMatriz));


            nodoPosicion->H = calculoDistancia(fila,columna);
            nodoPosicion->ID = contador;
            nodoPosicion->posicionIzquierda = posicionIzquierda;
            nodoPosicion->posicionArriba = posicionArriba;
            nodoPosicion->posicionDerecha = posicionDerecha;
            nodoPosicion->posicionAbajo = posicionAbajo;
            nodoPosicion->fila = fila;
            nodoPosicion->columna = columna;

            if (columna==1 && fila==1){
                primeraPosicion = nodoPosicion;
                primeroEnColumna = nodoPosicion;}
            if (fila==1){
                nodoPosicion->setPosicionAbajo(nodoPosicion);
                primeroEnColumna = nodoPosicion;
            }else{
                nodoPosicion->getPosicionArriba()->setPosicionAbajo(nodoPosicion);}
            if (columna!=1){
                nodoPosicion->getPosicionIzquierda()->setPosicionDerecha(nodoPosicion);
                posicionIzquierda = posicionIzquierda->getPosicionAbajo();}
            posicionArriba = nodoPosicion;
            contador++;
        }
        posicionArriba = nullptr;
        posicionDerecha = nullptr;
        posicionAbajo = nullptr;
        if(columna==1) {
            posicionIzquierda = primeraPosicion;
        }else{
            posicionIzquierda = primeroEnColumna;}
    }


}



NodoMatriz* Matriz::mostrarPosicion(int fila, int columna) {
    NodoMatriz *posicionSolicitada = primeraPosicion;
    while(fila!=1){
        posicionSolicitada = posicionSolicitada->getPosicionAbajo();
        fila--;
    }
    while(columna>1){
        posicionSolicitada = posicionSolicitada->getPosicionDerecha();
        columna--;
    }

    return posicionSolicitada;
}





void Matriz::mostrarMatriz() {
    NodoMatriz *contadorPosicion = primeraPosicion;
    int contadorFilas = cantidadFilas;
    int contadorColumnas = cantidadColumnas;
    int contadorAuxiliar = 1;

    cout<<"IMPRIMIENDO MATRIZ QUE INDICA SI HAY TORRES (1 HAY, 0 NO HAY)"<<endl;
    while(contadorFilas>1) {
        while (contadorColumnas>0) {
            cout << "[" <<contadorPosicion->presenciaTorre<< "]  ";
            contadorColumnas--;
            contadorPosicion = contadorPosicion->getPosicionDerecha();
        }
        cout<<endl;
        contadorFilas--;
        contadorAuxiliar++;
        contadorColumnas = cantidadColumnas;
        contadorPosicion = mostrarPosicion(contadorAuxiliar, 1);
    }

    cout<<endl<<endl;

    contadorPosicion = primeraPosicion;
    contadorFilas = cantidadFilas;
    contadorColumnas = cantidadColumnas;
    contadorAuxiliar = 1;

    cout<<"IMPRIMIENDO MATRIZ QUE INDICA EL ID DEL NODO"<<endl;
    while(contadorFilas>1) {
        while (contadorColumnas>0) {
            cout << "[" <<contadorPosicion->getID()<< "]  ";
            contadorColumnas--;
            contadorPosicion = contadorPosicion->getPosicionDerecha();
        }
        cout<<endl;
        contadorFilas--;
        contadorAuxiliar++;
        contadorColumnas = cantidadColumnas;
        contadorPosicion = mostrarPosicion(contadorAuxiliar, 1);
    }
}



void Matriz::colocarTorres() {
    random_device generadorAzar;
    mt19937 auxiliarAzar(generadorAzar());
    uniform_int_distribution<int> uni(1, cantidadFilas - 1);


    AStar* astar = new AStar();


    if(cantidadTorres<78) {
        for (int i = 1; i <= 3; i++) {

            auto filaAleatoria = uni(auxiliarAzar);
            auto columnaAleatoria = uni(auxiliarAzar);

            while ((filaAleatoria == 1 && columnaAleatoria == 1) || (filaAleatoria == 10 && columnaAleatoria == 10) ||
                   (mostrarPosicion(filaAleatoria, columnaAleatoria)->presenciaTorre)) {
                filaAleatoria = uni(auxiliarAzar);
                columnaAleatoria = uni(auxiliarAzar);
            }


            TorreEnemiga *torrePrueba = new TorreEnemiga(i);


            NodoMatriz* colocar = mostrarPosicion(filaAleatoria,columnaAleatoria);
            colocar->setTorreEnemiga(torrePrueba);
            astar->iniciar(this);

            if (!astar->destinoEncontrado) {
                colocar->setTorreEnemiga(nullptr);
                colocar->presenciaTorre = false;
            } else {

                cout<<"SE HA COLOCADO UNA TORRE EN LA POSICION (" <<colocar->fila<<" , "<<colocar->columna<<")"<<endl;

                cantidadTorres++;
                if(columnaAleatoria==1){
                    colocar->correccion = true;
                }
                listaTorres.push_back(colocar);
            }

        }
    }
}

void Matriz::moverTorres() {


    NodoMatriz *nodoActual = primeraPosicion;
    int contadorFilas = cantidadFilas;
    int contadorColumnas = cantidadColumnas;
    int contadorAuxiliar = 1;

    while(contadorFilas>1) {
        while (contadorColumnas>0) {
            if(nodoActual->presenciaTorre){
                AStar* astar = new AStar();
                bool flag = false;
                TorreEnemiga* torrePrueba = new TorreEnemiga(nodoActual->getTorreEnemiga()->getTipoTorre());


                    NodoMatriz* norte = nodoActual->getPosicionArriba();
                    NodoMatriz* este = nodoActual->getPosicionDerecha();
                    NodoMatriz* sur = nodoActual->getPosicionAbajo();
                    NodoMatriz* oeste = nodoActual->getPosicionIzquierda();

                    NodoMatriz *noreste = nullptr;
                    NodoMatriz *sureste = nullptr;
                    NodoMatriz *suroeste = nullptr;
                    NodoMatriz *noroeste = nullptr;

                    if(norte!= nullptr){
                        if(oeste!= nullptr) {
                            noroeste = nodoActual->getPosicionArriba()->getPosicionIzquierda();
                        }
                        if(este!= nullptr){
                            noreste = nodoActual->getPosicionArriba()->getPosicionDerecha();
                        }
                    }

                    if(sur!= nullptr){
                        if(oeste!= nullptr){
                            suroeste = nodoActual->getPosicionAbajo()->getPosicionIzquierda();
                        }
                        if(este!= nullptr){
                            sureste = nodoActual->getPosicionAbajo()->getPosicionDerecha();
                        }
                    }



                    if(norte!= nullptr && !flag){
                        if(!norte->presenciaTorre && (norte->getID() != 1)){
                            nodoActual->getPosicionArriba()->setTorreEnemiga(torrePrueba);
                            astar->iniciar(this);
                            if(!astar->destinoEncontrado){
                                nodoActual->getPosicionArriba()->setTorreEnemiga(nullptr);
                                nodoActual->getPosicionArriba()->presenciaTorre = false;
                            }else{
                                flag = true;
                            }
                        }

                    }

                    if(noreste!= nullptr && !flag){
                        if(!noreste->presenciaTorre){
                            nodoActual->getPosicionArriba()->getPosicionDerecha()->setTorreEnemiga(torrePrueba);
                            astar->iniciar(this);
                            if(!astar->destinoEncontrado){
                                nodoActual->getPosicionArriba()->getPosicionDerecha()->setTorreEnemiga(nullptr);
                                nodoActual->getPosicionArriba()->getPosicionDerecha()->presenciaTorre = false;
                            }else{
                                flag = true;
                            }
                        }
                    }

                    if(este!= nullptr && !flag){
                        if(!este->presenciaTorre && (este->getID()!=100)){
                            nodoActual->getPosicionDerecha()->setTorreEnemiga(torrePrueba);
                            astar->iniciar(this);
                            if(!astar->destinoEncontrado){
                                nodoActual->getPosicionDerecha()->setTorreEnemiga(nullptr);
                                nodoActual->getPosicionDerecha()->presenciaTorre = false;
                            }else{
                                flag = true;
                            }
                        }
                    }

                    if(sureste!= nullptr && !flag){
                        if(!sureste->presenciaTorre && (sureste->getID()!=100)){
                            nodoActual->getPosicionAbajo()->getPosicionDerecha()->setTorreEnemiga(torrePrueba);
                            astar->iniciar(this);
                            if(!astar->destinoEncontrado ){
                                nodoActual->getPosicionAbajo()->getPosicionDerecha()->setTorreEnemiga(nullptr);
                                nodoActual->getPosicionAbajo()->getPosicionDerecha()->presenciaTorre = false;
                            }else{
                                flag = true;
                            }
                        }
                    }

                    if(sur!= nullptr && !flag){
                        if(!sur->presenciaTorre && (sur->getID()!=100)){
                            nodoActual->getPosicionAbajo()->setTorreEnemiga(torrePrueba);
                            astar->iniciar(this);
                            if(!astar->destinoEncontrado){
                                nodoActual->getPosicionAbajo()->setTorreEnemiga(nullptr);
                                nodoActual->getPosicionAbajo()->presenciaTorre = false;
                            }else{
                                flag = true;
                            }
                        }
                    }

                    if(suroeste!= nullptr && !flag){
                        if(!suroeste->presenciaTorre){
                            nodoActual->getPosicionAbajo()->getPosicionIzquierda()->setTorreEnemiga(torrePrueba);
                            astar->iniciar(this);
                            if(!astar->destinoEncontrado){
                                nodoActual->getPosicionAbajo()->getPosicionIzquierda()->setTorreEnemiga(nullptr);
                                nodoActual->getPosicionAbajo()->getPosicionIzquierda()->presenciaTorre = false;
                            }else{
                                flag = true;
                            }
                        }
                    }

                    if(oeste!= nullptr && !flag){
                        if(!oeste->presenciaTorre && (oeste->getID()!=1)){
                            nodoActual->getPosicionIzquierda()->setTorreEnemiga(torrePrueba);
                            astar->iniciar(this);
                            if(!astar->destinoEncontrado){
                                nodoActual->getPosicionIzquierda()->setTorreEnemiga(nullptr);
                                nodoActual->getPosicionIzquierda()->presenciaTorre = false;
                            }else{
                                flag = true;
                            }
                        }
                    }

                    if(noroeste!= nullptr && !flag){
                        if(!noroeste->presenciaTorre && (noroeste->getID()!=1)){
                            nodoActual->getPosicionIzquierda()->getPosicionArriba()->setTorreEnemiga(torrePrueba);
                            astar->iniciar(this);
                            if(!astar->destinoEncontrado){
                                nodoActual->getPosicionIzquierda()->getPosicionArriba()->setTorreEnemiga(nullptr);
                                nodoActual->getPosicionIzquierda()->getPosicionArriba()->presenciaTorre = false;
                            }else{
                                flag = true;
                            }
                        }
                    }

                    if(flag){

                        nodoActual->setTorreEnemiga(nullptr);
                        nodoActual->presenciaTorre = false;
                    }


                }
                contadorColumnas--;
                nodoActual = nodoActual->getPosicionDerecha();

            }

            contadorFilas--;
            contadorAuxiliar++;
            contadorColumnas = cantidadColumnas;
            nodoActual = mostrarPosicion(contadorAuxiliar, 1);
        }


    }

void Matriz::generarListaTorres() {
    listaTorres.clear();
    NodoMatriz *contadorPosicion = primeraPosicion;
    int contadorFilas = cantidadFilas;
    int contadorColumnas = cantidadColumnas;
    int contadorAuxiliar = 1;

    while(contadorFilas>1) {
        while (contadorColumnas>0) {
            if(contadorPosicion->presenciaTorre){
                listaTorres.push_back(contadorPosicion);
            }
            contadorColumnas--;
            contadorPosicion = contadorPosicion->getPosicionDerecha();
        }
        contadorFilas--;
        contadorAuxiliar++;
        contadorColumnas = cantidadColumnas;
        contadorPosicion = mostrarPosicion(contadorAuxiliar, 1);
    }
}