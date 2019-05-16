#ifndef GLADIATORCE2103_MANEJADORARCHIVOS_H
#define GLADIATORCE2103_MANEJADORARCHIVOS_H

#include <string>
#include <fstream>
#include <iostream>
#include <random>

#include "ListaEnlazada.h"

using namespace std;

/**
 * @brief Esta clase maneja la base de datos del proyecto
 */
class manejadorArchivos {
public:
    /**
     * Constructor de la clase manejadorArchivos. Genera una interfaz entre el resto del sistema y las
     * bases de datos de los gladiadores
     * @param nombre
     */
    manejadorArchivos(string nombre);

    /**
     * Crea un archivo .txt en la ruta del atributo ruta. Guarda la informacion de los gladiadores
     */
    void crearArchivo();

    /**
     * Lee la base de datos y genera nodos con la informacion de cada gladiador
     * @param listaGenetica la lista enlazada que almacenara a los gladiadores
     * @return la lista enlazada con los gladiadores
     */
    listaEnlazada* leerArchivo();

    /**
     * Escribe en una nueva linea dentro de la base de datos
     * @param linea recibe un string con la informacion de cada gladiador que se va a guardar en la base de datos
     */
    void escribirEnArchivo(string linea);

    /**
     * Se genera un archivo nuevo con el nombre del anterior y se almacena la informacion de
     * la nueva poblacion calculada en el algoritmo genetico
     * @param listaPoblacion la lista a guardar dentro de la base de datos
     */
    void escribirNuevaPoblacion(vector<Nodo> listaPoblacion);

    /**
     * Verifica si existe la base de datos a la que se quiere acceder, con la finalidad de evitar
     * un acceso nulo
     * @return true si el archivo existe, false en caso contrario
     */
    bool verificarExistenciaArchivo();

    /**
     * Elimina el archivo con la ruta especificada
     */
    void eliminarArchivo();

    /**
     * Genera la poblacion inicial al correr el programa
     * @param listaGenetica lista enlazada donde almacenar los datos en esta poblacion
     */
    void generarPoblacionInicial(listaEnlazada *listaGenetica);

private:
    /**
     * Es la direccion dentro la carpeta del proyecto donde se guardara
     * la base de datos
     */
    string ruta = "../recursos/basesDeDatos/";
    string nombre;
};


#endif //GLADIATORCE2103_MANEJADORARCHIVOS_H