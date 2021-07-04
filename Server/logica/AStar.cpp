#include "AStar.h"


#define ROW 10
#define COL 10


vector<NodoMatriz*> AStar::getListaRuta() {
    return listaDeRuta;
}


bool AStar::revisarValidezNodo(int fila, int columna){
    return (fila >= 0) && (fila < ROW) && (columna >= 0) && (columna < COL);
}


bool isUnBlocked(int matrizLogica[][COL], int fila, int columna){
    if (matrizLogica[fila][columna] == 1)
        return (true);
    else
        return (false);
}



bool isDestination(int fila, int columna, Pair posicionFinal){
    if (fila == posicionFinal.first && columna == posicionFinal.second)
        return (true);
    else
        return (false);
}


double calculateHValue(int fila, int columna, Pair posicionFinal){
    return ((double)sqrt ((fila-posicionFinal.first)*(fila-posicionFinal.first)
                          + (columna-posicionFinal.second)*(columna-posicionFinal.second)));
}



void AStar::tracePath(cell detallesPosicion[][COL], Pair posicionFinal){
    printf ("\n El camino calculado por el algoritmo A* es ");
    int fila = posicionFinal.first;
    int columna = posicionFinal.second;

    stack<Pair> mejorRuta;

    while (!(detallesPosicion[fila][columna].padreX == fila && detallesPosicion[fila][columna].padreY == columna )){

        mejorRuta.push (make_pair (fila, columna));
        int filaTemporal = detallesPosicion[fila][columna].padreX;
        int columnaTemporal = detallesPosicion[fila][columna].padreY;
        fila = filaTemporal;
        columna = columnaTemporal;
    }

    mejorRuta.push(make_pair (fila, columna));
    listaDeRuta.clear();

    while (!mejorRuta.empty()){
        pair<int,int> p = mejorRuta.top();
        mejorRuta.pop();

        NodoMatriz* nodoAgregar = matrizJuego->mostrarPosicion((p.first+1,p.second+1),0);

        nodoAgregar->fila = p.first+1;
        nodoAgregar->columna = p.second+1;

        listaDeRuta.push_back(nodoAgregar);
        printf("-> (%d,%d) ",p.first,p.second);

    }


}



















void AStar::aStarSearch(int grid[][COL], Pair posicionInicial, Pair posicionFinal){

    bool listaCerrada[ROW][COL];

    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            listaCerrada[i][j]=false;
        }
    }

    cell detallesPosicion[ROW][COL];

    int ejeX;
    int ejeY;

    for (ejeX=0; ejeX<ROW; ejeX++){
        for (ejeY=0; ejeY<COL; ejeY++){
            detallesPosicion[ejeX][ejeY].f = FLT_MAX;
            detallesPosicion[ejeX][ejeY].g = FLT_MAX;
            detallesPosicion[ejeX][ejeY].h = FLT_MAX;
            detallesPosicion[ejeX][ejeY].padreX = -1;
            detallesPosicion[ejeX][ejeY].padreY = -1;
        }
    }

    ejeX = posicionInicial.first, ejeY = posicionInicial.second;
    detallesPosicion[ejeX][ejeY].f = 0.0;
    detallesPosicion[ejeX][ejeY].g = 0.0;
    detallesPosicion[ejeX][ejeY].h = 0.0;
    detallesPosicion[ejeX][ejeY].padreX = ejeX;
    detallesPosicion[ejeX][ejeY].padreY = ejeY;

    set<pPair> listaAbierta;

    listaAbierta.insert(make_pair (0.0, make_pair (ejeX, ejeY)));


    while (!listaAbierta.empty()){


        pPair posicionAuxiliar = *listaAbierta.begin();

        listaAbierta.erase(listaAbierta.begin());

        ejeX = posicionAuxiliar.second.first;
        ejeY = posicionAuxiliar.second.second;
        listaCerrada[ejeX][ejeY] = true;

        double nuevoG;
        double nuevoH;
        double nuevoF;


        //NORTE
        if (revisarValidezNodo(ejeX-1, ejeY) == true){
            if (isDestination(ejeX-1, ejeY, posicionFinal) == true){
                detallesPosicion[ejeX-1][ejeY].padreX = ejeX;
                detallesPosicion[ejeX-1][ejeY].padreY = ejeY;
                tracePath (detallesPosicion, posicionFinal);
                destinoEncontrado = true;
                return;
            }else if (listaCerrada[ejeX-1][ejeY] == false && isUnBlocked(grid, ejeX-1, ejeY) == true){
                nuevoG = detallesPosicion[ejeX][ejeY].g + 1.0;
                nuevoH = calculateHValue (ejeX-1, ejeY, posicionFinal);
                nuevoF = nuevoG + nuevoH;


                if (detallesPosicion[ejeX-1][ejeY].f == FLT_MAX || detallesPosicion[ejeX-1][ejeY].f > nuevoF){
                    listaAbierta.insert(make_pair(nuevoF,make_pair(ejeX-1, ejeY)));

                    detallesPosicion[ejeX-1][ejeY].f = nuevoF;
                    detallesPosicion[ejeX-1][ejeY].g = nuevoG;
                    detallesPosicion[ejeX-1][ejeY].h = nuevoH;
                    detallesPosicion[ejeX-1][ejeY].padreX = ejeX;
                    detallesPosicion[ejeX-1][ejeY].padreY = ejeY;
                }
            }
        }


        //SUR
        if (revisarValidezNodo(ejeX+1, ejeY) == true){
            if (isDestination(ejeX+1, ejeY, posicionFinal) == true){
                detallesPosicion[ejeX+1][ejeY].padreX = ejeX;
                detallesPosicion[ejeX+1][ejeY].padreY = ejeY;
                tracePath(detallesPosicion, posicionFinal);
                destinoEncontrado = true;
                return;
            }else if (listaCerrada[ejeX+1][ejeY] == false && isUnBlocked(grid, ejeX+1, ejeY) == true){
                nuevoG = detallesPosicion[ejeX][ejeY].g + 1.0;
                nuevoH = calculateHValue(ejeX+1, ejeY, posicionFinal);
                nuevoF = nuevoG + nuevoH;


                if (detallesPosicion[ejeX+1][ejeY].f == FLT_MAX || detallesPosicion[ejeX+1][ejeY].f > nuevoF){
                    listaAbierta.insert( make_pair (nuevoF, make_pair (ejeX+1, ejeY)));

                    detallesPosicion[ejeX+1][ejeY].f = nuevoF;
                    detallesPosicion[ejeX+1][ejeY].g = nuevoG;
                    detallesPosicion[ejeX+1][ejeY].h = nuevoH;
                    detallesPosicion[ejeX+1][ejeY].padreX = ejeX;
                    detallesPosicion[ejeX+1][ejeY].padreY = ejeY;
                }
            }
        }


        //ESTE
        if (revisarValidezNodo (ejeX, ejeY+1) == true){
            if (isDestination(ejeX, ejeY+1, posicionFinal) == true){
                detallesPosicion[ejeX][ejeY+1].padreX = ejeX;
                detallesPosicion[ejeX][ejeY+1].padreY = ejeY;
                tracePath(detallesPosicion, posicionFinal);
                destinoEncontrado = true;
                return;
            }else if (listaCerrada[ejeX][ejeY+1] == false && isUnBlocked (grid, ejeX, ejeY+1) == true){
                nuevoG = detallesPosicion[ejeX][ejeY].g + 1.0;
                nuevoH = calculateHValue (ejeX, ejeY+1, posicionFinal);
                nuevoF = nuevoG + nuevoH;


                if (detallesPosicion[ejeX][ejeY+1].f == FLT_MAX || detallesPosicion[ejeX][ejeY+1].f > nuevoF){
                    listaAbierta.insert( make_pair(nuevoF,make_pair (ejeX, ejeY+1)));

                    detallesPosicion[ejeX][ejeY+1].f = nuevoF;
                    detallesPosicion[ejeX][ejeY+1].g = nuevoG;
                    detallesPosicion[ejeX][ejeY+1].h = nuevoH;
                    detallesPosicion[ejeX][ejeY+1].padreX = ejeX;
                    detallesPosicion[ejeX][ejeY+1].padreY = ejeY;
                }
            }
        }


        //OESTE
        if (revisarValidezNodo(ejeX, ejeY-1) == true){
            if (isDestination(ejeX, ejeY-1, posicionFinal) == true){
                detallesPosicion[ejeX][ejeY-1].padreX = ejeX;
                detallesPosicion[ejeX][ejeY-1].padreY = ejeY;
                tracePath(detallesPosicion, posicionFinal);
                destinoEncontrado = true;
                return;
            }else if (listaCerrada[ejeX][ejeY-1] == false && isUnBlocked(grid, ejeX, ejeY-1) == true){
                nuevoG = detallesPosicion[ejeX][ejeY].g + 1.0;
                nuevoH = calculateHValue(ejeX, ejeY-1, posicionFinal);
                nuevoF = nuevoG + nuevoH;


                if (detallesPosicion[ejeX][ejeY-1].f == FLT_MAX || detallesPosicion[ejeX][ejeY-1].f > nuevoF){
                    listaAbierta.insert( make_pair (nuevoF, make_pair (ejeX, ejeY-1)));

                    detallesPosicion[ejeX][ejeY-1].f = nuevoF;
                    detallesPosicion[ejeX][ejeY-1].g = nuevoG;
                    detallesPosicion[ejeX][ejeY-1].h = nuevoH;
                    detallesPosicion[ejeX][ejeY-1].padreX = ejeX;
                    detallesPosicion[ejeX][ejeY-1].padreY = ejeY;
                }
            }
        }


        //NORESTE
        if (revisarValidezNodo(ejeX-1, ejeY+1) == true){
            if (isDestination(ejeX-1, ejeY+1, posicionFinal) == true){
                detallesPosicion[ejeX-1][ejeY+1].padreX = ejeX;
                detallesPosicion[ejeX-1][ejeY+1].padreY = ejeY;
                tracePath (detallesPosicion, posicionFinal);
                destinoEncontrado = true;
                return;
            }else if (listaCerrada[ejeX-1][ejeY+1] == false && isUnBlocked(grid, ejeX-1, ejeY+1) == true){
                nuevoG = detallesPosicion[ejeX][ejeY].g + 1.414;
                nuevoH = calculateHValue(ejeX-1, ejeY+1, posicionFinal);
                nuevoF = nuevoG + nuevoH;


                if (detallesPosicion[ejeX-1][ejeY+1].f == FLT_MAX || detallesPosicion[ejeX-1][ejeY+1].f > nuevoF){
                    listaAbierta.insert( make_pair (nuevoF, make_pair(ejeX-1, ejeY+1)));

                    detallesPosicion[ejeX-1][ejeY+1].f = nuevoF;
                    detallesPosicion[ejeX-1][ejeY+1].g = nuevoG;
                    detallesPosicion[ejeX-1][ejeY+1].h = nuevoH;
                    detallesPosicion[ejeX-1][ejeY+1].padreX = ejeX;
                    detallesPosicion[ejeX-1][ejeY+1].padreY = ejeY;
                }
            }
        }


        //NOROESTE
        if (revisarValidezNodo (ejeX-1, ejeY-1) == true){
            if (isDestination (ejeX-1, ejeY-1, posicionFinal) == true){
                detallesPosicion[ejeX-1][ejeY-1].padreX = ejeX;
                detallesPosicion[ejeX-1][ejeY-1].padreY = ejeY;
                tracePath (detallesPosicion, posicionFinal);
                destinoEncontrado = true;
                return;
            }else if (listaCerrada[ejeX-1][ejeY-1] == false && isUnBlocked(grid, ejeX-1, ejeY-1) == true){
                nuevoG = detallesPosicion[ejeX][ejeY].g + 1.414;
                nuevoH = calculateHValue(ejeX-1, ejeY-1, posicionFinal);
                nuevoF = nuevoG + nuevoH;


                if (detallesPosicion[ejeX-1][ejeY-1].f == FLT_MAX || detallesPosicion[ejeX-1][ejeY-1].f > nuevoF){
                    listaAbierta.insert( make_pair (nuevoF, make_pair (ejeX-1, ejeY-1)));

                    detallesPosicion[ejeX-1][ejeY-1].f = nuevoF;
                    detallesPosicion[ejeX-1][ejeY-1].g = nuevoG;
                    detallesPosicion[ejeX-1][ejeY-1].h = nuevoH;
                    detallesPosicion[ejeX-1][ejeY-1].padreX = ejeX;
                    detallesPosicion[ejeX-1][ejeY-1].padreY = ejeY;
                }
            }
        }


        //SURESTE
        if (revisarValidezNodo(ejeX+1, ejeY+1) == true){
            if (isDestination(ejeX+1, ejeY+1, posicionFinal) == true){
                detallesPosicion[ejeX+1][ejeY+1].padreX = ejeX;
                detallesPosicion[ejeX+1][ejeY+1].padreY = ejeY;;
                tracePath (detallesPosicion, posicionFinal);
                destinoEncontrado = true;
                return;
            }else if (listaCerrada[ejeX+1][ejeY+1] == false && isUnBlocked(grid, ejeX+1, ejeY+1) == true){
                nuevoG = detallesPosicion[ejeX][ejeY].g + 1.414;
                nuevoH = calculateHValue(ejeX+1, ejeY+1, posicionFinal);
                nuevoF = nuevoG + nuevoH;


                if (detallesPosicion[ejeX+1][ejeY+1].f == FLT_MAX ||detallesPosicion[ejeX+1][ejeY+1].f > nuevoF){
                    listaAbierta.insert(make_pair(nuevoF, make_pair (ejeX+1, ejeY+1)));

                    detallesPosicion[ejeX+1][ejeY+1].f = nuevoF;
                    detallesPosicion[ejeX+1][ejeY+1].g = nuevoG;
                    detallesPosicion[ejeX+1][ejeY+1].h = nuevoH;
                    detallesPosicion[ejeX+1][ejeY+1].padreX = ejeX;
                    detallesPosicion[ejeX+1][ejeY+1].padreY = ejeY;
                }
            }
        }


        //SUROESTE
        if (revisarValidezNodo(ejeX+1, ejeY-1) == true){
            if (isDestination(ejeX+1, ejeY-1, posicionFinal) == true){
                detallesPosicion[ejeX+1][ejeY-1].padreX = ejeX;
                detallesPosicion[ejeX+1][ejeY-1].padreY = ejeY;
                tracePath(detallesPosicion, posicionFinal);
                destinoEncontrado = true;
                return;
            }else if (listaCerrada[ejeX+1][ejeY-1] == false && isUnBlocked(grid, ejeX+1, ejeY-1) == true){
                nuevoG = detallesPosicion[ejeX][ejeY].g + 1.414;
                nuevoH = calculateHValue(ejeX+1, ejeY-1, posicionFinal);
                nuevoF = nuevoG + nuevoH;


                if (detallesPosicion[ejeX+1][ejeY-1].f == FLT_MAX || detallesPosicion[ejeX+1][ejeY-1].f > nuevoF){
                    listaAbierta.insert(make_pair(nuevoF, make_pair(ejeX+1, ejeY-1)));

                    detallesPosicion[ejeX+1][ejeY-1].f = nuevoF;
                    detallesPosicion[ejeX+1][ejeY-1].g = nuevoG;
                    detallesPosicion[ejeX+1][ejeY-1].h = nuevoH;
                    detallesPosicion[ejeX+1][ejeY-1].padreX = ejeX;
                    detallesPosicion[ejeX+1][ejeY-1].padreY = ejeY;
                }
            }
        }
    }


    if (!destinoEncontrado) {
        cout<<"NO SE HA ENCONTRADO UNA RUTA"<<endl;
    }



}


void AStar::actualizarMatrizLogica() {
    cout<<"MOSTRANDO MATRIZ DE ALGORITMO PATHFINDING A*"<<endl<<endl;
    for(int i=1; i<=cantidadColumnas; i++){
        for(int j=1; j<=cantidadFilas; j++){
            matrizJuego->mostrarPosicion(i,j)->vida =0;
            if(matrizJuego->mostrarPosicion(i,j)->presenciaTorre){
                matrizLogica[i-1][j-1] = 0;
                cout<<"0 ";
            }else{
                matrizLogica[i-1][j-1] = 1;
                cout<<"1 ";
            }
        }
        cout<<endl;
    }
}



void AStar::iniciar(Matriz* matrizJuego){
    this->matrizJuego = matrizJuego;
    actualizarMatrizLogica();
    destinoEncontrado = false;
    listaDeRuta.clear();
    aStarSearch(matrizLogica, posicionInicial, posicionFinal);
    cout<<endl;
}


AStar::AStar() {
    posicionInicial = make_pair(0,0);
    posicionFinal = make_pair(9,9);
}