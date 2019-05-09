#ifndef POINT_H
#define POINT_H

/**
 * @brief The Point class Maneja puntos facilmente en el juego.
 */
class Point{

public:
    /**
     * @brief Point Constructor de la clase Point.
     * @param fila La fila.
     * @param columna La columna.
     * @param vida La vida.
     */
    Point(int fila, int columna, int vida);
    /**
     * @brief getFila Devuelve la fila.
     * @return La fila.
     */
    int getFila() const;
    /**
     * @brief setFila Modifica el valor de la fila.
     * @param value El nuevo valor de la fila.
     */
    void setFila(int value);
    /**
     * @brief getColumna Devuelve el valor de la columna.
     * @return La columna.
     */
    int getColumna() const;
    /**
     * @brief setColumna Modifica el valor de la columna.
     * @param value El nuevo valor de la columna.
     */
    void setColumna(int value);
    /**
     * @brief getVida Devuelve el valor de la vida.
     * @return El valor de la vida.
     */
    int getVida() const;
    /**
     * @brief setVida Modifica el valor de la vida.
     * @param value El nuevo valor de la viida.
     */
    void setVida(int value);
private:
    int fila;
    int columna;
    int vida;
};

#endif // POINT_H
