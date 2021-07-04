#include "ManejadorArchivos.h"

void manejadorArchivos::eliminarArchivo() {
    remove(ruta.c_str());
}

manejadorArchivos::manejadorArchivos(string nombre) {
    this->ruta += nombre += ".txt";
    this->nombre = nombre;

    if (!verificarExistenciaArchivo()){
        crearArchivo();
    }
}

bool manejadorArchivos::verificarExistenciaArchivo() {
    ifstream archivo (ruta);
    return archivo.good();
}

void manejadorArchivos::crearArchivo() {
    ofstream file {ruta};
}

void manejadorArchivos::escribirEnArchivo(string linea) {
    ofstream archivo(ruta, ios::app);
    archivo<<linea<<endl;
    archivo.close();
}



listaEnlazada* manejadorArchivos::leerArchivo() {
    listaEnlazada *listaAux = new listaEnlazada();
    char cadena[128];
    ifstream baseDeDatos(ruta);
    int contador = 1;


    int id=0;
    int edad=0;
    int probabilidadSupervivencia=0;
    int generacionesParaLaSupervivencia=0;
    int inteligenciaEmocional=0;
    int condicionFisica=0;
    int fuerzaTroncoInferior=0;
    int fuerzaTroncoSuperior=0;


    while (!baseDeDatos.eof()) {
        baseDeDatos >> cadena;

        int dato = stoi(cadena);

        if(contador==1){
            id = dato;
        }else if(contador==2){
            edad = dato;
        }else if(contador==3){
            probabilidadSupervivencia = dato;
        }else if(contador==4){
            generacionesParaLaSupervivencia = dato;
        }else if(contador==5){
            inteligenciaEmocional = dato;
        }else if(contador==6){
            condicionFisica = dato;
        }else if(contador==7){
            fuerzaTroncoInferior = dato;
        }else if(contador==8){
            fuerzaTroncoSuperior = dato;
        }else if(contador==9){
            contador = 1;

            //cout<<id<<" "<<edad<<" "<<probabilidadSupervivencia<<" "<<generacionesParaLaSupervivencia<<" "<<inteligenciaEmocional<<" "<<condicionFisica<<" "<<fuerzaTroncoInferior<<" "<<fuerzaTroncoSuperior<<endl;
            Nodo *gladiador = new Nodo(id,edad,probabilidadSupervivencia,generacionesParaLaSupervivencia,inteligenciaEmocional,condicionFisica,fuerzaTroncoInferior,fuerzaTroncoSuperior);
            listaAux->agregarAlFinal(gladiador);
        }

        contador ++;
    }
    baseDeDatos.close();
    return listaAux;
}


void manejadorArchivos::generarPoblacionInicial(listaEnlazada *listaGenetica) {
    random_device generadorAzar;
    mt19937 aux(generadorAzar());
    uniform_int_distribution<int> uni(1,5);
    uniform_int_distribution<int> idUni(10000000,99999999);

    for(int i=0; i<100; i++){
        int id = idUni(aux);
        int edad = uni(aux);
        int probabilidadSupervivencia = uni(aux);
        int generacionesParaSupervivencia = uni(aux);
        int inteligenciaEmocional = uni(aux);
        int condicionFisica = uni(aux);
        int fuerzaTroncoSuperior = uni(aux);
        int fueraTroncoInferior = uni(aux);

        Nodo *gladiador = new Nodo(id,edad,probabilidadSupervivencia,generacionesParaSupervivencia,inteligenciaEmocional,
        condicionFisica,fueraTroncoInferior,fuerzaTroncoSuperior);
        listaGenetica->agregarAlFinal(gladiador);

        escribirEnArchivo(to_string(id) + " " + to_string(edad) + " " + to_string(probabilidadSupervivencia) + " " +
      to_string(generacionesParaSupervivencia) + " " + to_string(inteligenciaEmocional) + " " + to_string(condicionFisica) +
      " " + to_string(fueraTroncoInferior) + " " + to_string(fuerzaTroncoSuperior));


    }
}

void manejadorArchivos::escribirNuevaPoblacion(vector<Nodo> listaPoblacion) {
    eliminarArchivo();
    for(int i=0; i<listaPoblacion.size()-1; i++){
        Nodo gladiador = listaPoblacion.at(i);
        escribirEnArchivo(to_string(gladiador.getId()) + " " + to_string(gladiador.getEdad()) + " " +
        to_string(gladiador.getProbabilidadSupervivencia()) + " " + to_string(gladiador.getGeneracionesParaLaSupervivencia()) +
        " " + to_string(gladiador.getInteligenciaEmocional()) + " " + to_string(gladiador.getCondicionFisica()) + " " +
        to_string(gladiador.getFuerzaTroncoInferior()) + " " + to_string(gladiador.getFuerzaTroncoSuperior()));
    }
}
