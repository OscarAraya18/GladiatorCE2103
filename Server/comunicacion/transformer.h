#ifndef TRANSFORMER_H
#define TRANSFORMER_H
#include <include/rapidjson/document.h>
#include <comunicacion/server.h>
#include <iostream>
#include "estructurasLogicas/NodoMatriz.h"
#include "logica/AStar.h"
using namespace rapidjson;
using namespace std;
/**
 * @brief Esta clase funciona como traductor y escritor de mensajes JSON para lograr establecer una
 * buena comunicacion con el cliente y viceversa.
 */
class Transformer {

private:
    /**
     * Me devuelve la instancia de la clase Transformer.
     */
    static Transformer* instance;
    /**
     * Constructor de la clase transformer.
     */
    Transformer();
    /**
     * Redacta un mensaje JSON con rutas y caracteristicas de gladiador.
     * @return Un mensaje escrito en JSON.
     */
    const char* generarJSON ();
    /**
     * Redacta un mensaje JSON que contiene las posiciones de las torres y el tipo de torre.
     * @return Un mensaje escrito en JSON.
     */
    string mensajeTorres();
    /**
     * Redacta un mensaje JSON que contiene las caracteristicas del gladiador 1.
     * @return Un mensaje JSON.
     */
    string mensajeGladiador1();
    /**
     * Redacta un mensaje JSON que contiene las caracteristicas del gladiador 2.
     * @return Un mensaje JSON.
     */
    string mensajeGladiador2();
    /**
     * Redacta un mensaje JSON que contiene la ruta que debe seguir el gladiador 1.
     * @return Un mensaje JSON.
     */
    string mensajeCamino1();
    /**
     * Redacta un mensaje JSON que contiene la ruta que debe seguir el gladiador 2.
     * @return Un mensaje JSON.
     */
    string mensajeCamino2();
    /**
     * Redacta un mensaje JSON que contiene los datos del fitness promedio de todas las generaciones pertenecientes
     * a la primera poblacion de gladiadores.
     * @return Un mensaje JSON.
     */
    string mensajeGraficaPoblacion1();
    /**
     * Redacta un mensaje JSON que contiene los  datos del fitness promedio de todas las generaciones pertenecientes
     * a la segunda poblacion de gladiadores.
     * @return Un mensaje JSON.
     */
    string mensajeGraficaPoblacion2();


public:
    /**
     * Devuelve la instancia de la clase Transformer.
     * @return La instancia de la clase Transformer.
     */
    static Transformer* getInstance();
    /**
     * Recibe todos los mensajes y dependiendo de los JSON KEYS, transfiere dichos mensajes a otros metodos
     * para que sean atendidos.
     */
    void funcionGeneral(const char*);
    /**
     * Envia mensajes hacia el servidor.
     */
    void enviar();
    /**
     * La fila logica.
     */
    int fila;
    /**
     * La columna logica.
     */
    int columna;
    /**
     * Un vector que almacena las rutas con vida del primer gladiador.
     */
    vector<NodoMatriz*> rutaConVida1;
    /**
     * Un vector que almacena las rutas con vida del segundo gladiador.
     */
    vector<NodoMatriz*> rutaConVida2;

    int contador;


};


#endif // TRANSFORMER_H
