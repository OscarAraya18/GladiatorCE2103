#include "Nodo.h"

Nodo::Nodo(int id, int edad, int probabilidadSupervivencia, int generacionesParaLaSupervivencia, int inteligenciaEmocional,
           int condicionFisica, int fuerzaTroncoInferior, int fuerzaTroncoSuperior) {
    this->id=id;
    this->edad=edad;
    this->probabilidadSupervivencia=probabilidadSupervivencia;
    this->generacionesParaLaSupervivencia=generacionesParaLaSupervivencia;
    this->inteligenciaEmocional=inteligenciaEmocional;
    this->condicionFisica=condicionFisica;
    this->fuerzaTroncoInferior=fuerzaTroncoInferior;
    this->fuerzaTroncoSuperior=fuerzaTroncoSuperior;

}

void Nodo::setSiguiente(Nodo* siguiente) {
    this->siguiente = siguiente;
}

Nodo* Nodo::getSiguiente() {
    return siguiente;
}


int Nodo::getEdad()
{
    return edad;
}



int Nodo::getId()
{
    return id;
}


int Nodo::getProbabilidadSupervivencia()
{
    return probabilidadSupervivencia;
}



int Nodo::getGeneracionesParaLaSupervivencia()
{
    return generacionesParaLaSupervivencia;
}



int Nodo::getInteligenciaEmocional()
{
    return inteligenciaEmocional;
}



int Nodo::getCondicionFisica()
{
    return condicionFisica;
}



int Nodo::getFuerzaTroncoInferior()
{
    return fuerzaTroncoInferior;
}



int Nodo::getFuerzaTroncoSuperior()
{
    return fuerzaTroncoSuperior;
}



int Nodo::getResistencia()
{
    return resistencia;
}


int Nodo::getFitness() {
    return fitness;
}

void Nodo::setFitness(int fitness) {
    this->fitness = fitness;
}

void Nodo::setResistencia(int resistencia) {
    Nodo::resistencia = resistencia;
}
