#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "cliente.h"
#include "converter.h"

#include <QGraphicsView>
#include <QGraphicsScene>

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget *parent=NULL);
    //atributos

    QGraphicsScene *scene;
    Board *board;
    void iniciarConexion();
    void sendMessage(string m);
    Converter *converter;
    Cliente *conexion;
public slots:
    void recibirMensaje(QString mensaje);
    void iniciarIteracion();

};

#endif // GAME_H
