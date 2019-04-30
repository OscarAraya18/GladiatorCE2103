#ifndef POINT_H
#define POINT_H


class Point{

public:
    Point(int fila, int columna, int vida);

    int getFila() const;

    void setFila(int value);

    int getColumna() const;

    void setColumna(int value);

    int getVida() const;

    void setVida(int value);

private:
    int fila;
    int columna;
    int vida;
};

#endif // POINT_H
