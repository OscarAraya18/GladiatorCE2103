#ifndef GLADIATORCE2103_NODO_H
#define GLADIATORCE2103_NODO_H

#include "Nodo.h"

#include <iostream>


using namespace std;

/**
 * @brief Elemento de la lista enlazada
 */
class Nodo {
public:
    /**
     * El constructor de la clase Nodo. Los nodos almacenan la informacion de cada gladiador que es leido
     * desde la base de datos
     * @param id identificador de 8 digitos
     * @param edad la edad del gladiador. Se le genera de manera aleatoria
     * @param probabilidadSuperviviencia probabilidad de que un gladiador permanezca en la poblacion
     * @param generacionesParaLaSupervivencia generaciones para que un gladiador logre salir de la zona de intimidacion
     * @param inteligenciaEmocional inteligencia emocional del gladiador
     * @param condicionFisica condicion fisica del gladiador
     * @param fuerzaTroncoInferior fuerza en el tronco inferior del gladiador
     * @param fuerzaTroncoSuperior fuerza en el tronco superior del gladiador
     */
    Nodo(int id, int edad, int probabilidadSuperviviencia, int generacionesParaLaSupervivencia, int inteligenciaEmocional,
         int condicionFisica, int fuerzaTroncoInferior, int fuerzaTroncoSuperior);

    /**
     * Asigna el nodo siguiente dentro de la lista enlazada que los almacena
     * @param siguiente el nodo siguiente dentro de la lista enlazada
     */
    void setSiguiente(Nodo* siguiente);

    /**
     * Accede al nodo siguiente
     * @return el nodo siguiente
     */
    Nodo* getSiguiente();

    /**
     * Accede a la edad del gladiador
     * @return la edad del gladiador
     */
    int getEdad() ;

    /**
     * Accede al ID del gladiador
     * @return el ID del gladiador
     */
    int getId() ;

    /**
     * Accede a la probabilidad de supervivencia del gladiador
     * @return la probabilidad de supervivencia del gladiador
     */
    int getProbabilidadSupervivencia() ;

    /**
     * Accede a las generaciones esperadas para la supervivencia del gladiador
     * @return las generaciones esperadas para la supervivencia del gladiador
     */
    int getGeneracionesParaLaSupervivencia();

    /**
     * Accede a la inteligencia emocional del gladiador
     * @return la inteligencia emocional del gladiador
     */
    int getInteligenciaEmocional();

    /**
     * Accede a la condicion fisica del gladiador
     * @return la condicion fisica del gladiador
     */
    int getCondicionFisica();

    /**
     * Accede a la fuerza del tronco inferior del gladiador
     * @return la fuerza del tronco inferior del gladiador
     */
    int getFuerzaTroncoInferior();

    /**
     * Accede a la fuerza del tronco superior del gladiador
     * @return la fuerza del tronco superior del gladiador
     */
    int getFuerzaTroncoSuperior();

    /**
     * Accede a la resistencia del gladiador
     * @return la resistencia del gladiador
     */
    int getResistencia();

    /**
     * Asigna el fitness al gladiador
     * @param fitness fitness del gladiador
     */
    void setFitness(int fitness);

    /**
     * Accede al fitness del gladiador
     * @return el fitness del gladiador
     */
    int getFitness();
private:
    /**
     * Nodo siguiente al nodo actual
     */
    Nodo* siguiente = NULL;

    int numero;
    int id;
    int edad;
    int probabilidadSupervivencia;
    int generacionesParaLaSupervivencia;
    int inteligenciaEmocional;
    int condicionFisica;
    int fuerzaTroncoInferior;
    int fuerzaTroncoSuperior;
    int resistencia;
public:
    void setResistencia(int resistencia);

private:
    int fitness;
};


#endif //GLADIATORCE2103_NODO_H
