#include "point.h"

Point::Point(int fil,int col){
    this->fila = fil;
    this->columna = col;
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
