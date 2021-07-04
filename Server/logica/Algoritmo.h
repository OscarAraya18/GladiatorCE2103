//
// Created by oscar_araya_x on 05/05/19.
//

#ifndef GLADIATORCE2103_ALGORITMO_H
#define GLADIATORCE2103_ALGORITMO_H

#include <iostream>
#include "estructurasLogicas/ListaEnlazada.h"
#include "estructurasLogicas/Nodo.h"
#include <vector>
using namespace std;

/**
 * @brief Clase del algoritmo genetico
 */
class Algoritmo
{
public:/**
 * constructor de algoritmo
 */
    Algoritmo();
    /**
     * convierte un numero de binario a decimal
     * @param num1 el string que es el numero binario
     * @return retornar el nuero binario en base decimal
     */
    int convertidorbin_dec(string num1);
    /**
     * convierte un numero decimal a binario
     * @param num2 el numero en decimal para convertir
     * @return retorna en un string el cual es numero en binario
     */
    string convertidordec_bin(int num2);
    /**
     * funcion para sumar dos numeros binarios los cuales son los atributos de cada gladiador
     * @param num1 atributo en binario de un gladiador para el cruce
     * @param num2 atributo en binario de un gladiador para el cruce
     * @return atributo en binario del nuevo gladiador para el cruce
     */
    string sumabin(string num1, string num2);
    /**
     * funcion para calcular el fitness de un gladiador ṕor una multiplicación
     * @param gladiador nodo al que quiere calcular el fitness
     */
    void calcular_fitness(Nodo gladiador);
    /**
     * funcion para eliminar los 10 peores gladiadores de la poblacion
     */
    void fitness_menor();
    /**
     * funcion que que guarda a los mejores 20 mejores gladiadores para el cruce genético
     */
    void fitness_mejor();
    /**
     * crea a los nuevos hijos por medio diferentes llamados
     */
    void nuevos_hijos();
    /**
     * funcion para calcular el fitness de cada hijo
     * @param hijo nodo del hijo creado
     * @return retorna el nodo hijo con su fitness ya editado
     */
    int cal_fitness_hijos(Nodo hijo);
    /**
     * funcion para calcular el mejor gladiador
     * @return retorna al mejor jugador
     */
    Nodo* mejor_jugador();
    /**
     * funcion que calcula el promedio del fitness de la poblacion
     * @return retornar el promedio
     */
    double pro_fitness();
    /**
     * metodo para iniciar el algoritmo genetico haciendo las llamadas necesarias para el funcionamiento
     * @param listaGenetica la lista de la poblacion
     */
    void rungenetico(listaEnlazada *listaGenetica);
    /**
     *cambia las posiciones en el vector de los nodos ingresados
     * @param a primer nodo
     * @param b segundo nodo
     */
    void swap(Nodo *a,Nodo *b);

/**
 * funcion para encontrar el pivote
 * @param low un numero minimo
 * @param high un numero maximo
 * @return retorna el pivote para el quicksort
 */
    int partition(int low, int high);

/**
 * algoritmo que ordena el vector de de los gladiadores
 * @param low posicion minima del vector
 * @param high posicion maxima del vector
 */
    void quickSort(int low, int high);

/**
 * metodo para calcular la resistencia del mejor gladiador
 * @param mejorGladiador parametro para obtener los atributos del mejor gladiador
 * @return retorna el valor de la resistencia
 */
    int calcularResistencia(Nodo* mejorGladiador);
/**
 *diferentes atributos para el funcionamiento del algoritmo
 */
    vector<Nodo> vec_gladiadores;
    vector<int> vect_posiciones;
    vector<Nodo> vec_hijos;
    vector<Nodo> vec_mejores_gladiadores;
private:


    listaEnlazada *listaGenetica;

};


#endif //GLADIATORCE2103_ALGORITMO_H
