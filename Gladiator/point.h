#ifndef POINT_H
#define POINT_H


class Point{

public:
    Point(int fila, int columna);

    int getFila() const;

    void setFila(int value);

    int getColumna() const;

    void setColumna(int value);

private:
    int fila;
    int columna;
};

#endif // POINT_H
