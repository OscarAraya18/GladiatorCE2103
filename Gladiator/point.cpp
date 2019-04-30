#include "point.h"

Point::Point(int fil,int col, int v){
    this->fila = fil;
    this->columna = col;
    this->vida = v;
}

int Point::getFila() const
{
    return fila;
}

void Point::setFila(int value)
{
    fila = value;
}

int Point::getColumna() const
{
    return columna;
}

void Point::setColumna(int value)
{
    columna = value;
}

int Point::getVida() const
{
    return vida;
}

void Point::setVida(int value)
{
    vida = value;
}
