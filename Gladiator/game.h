#ifndef GAME_H
#define GAME_H
#include "board.h"
#include "cliente.h"
#include "converter.h"
#include <QGraphicsView>
#include <QGraphicsScene>
/**
 * @brief The Game class Une todos los elementos graficos y los controla.
 */
class Game: public QGraphicsView
{
    Q_OBJECT
public:
    /**
     * @brief Game Constructor de la clase Game.
     * @param parent
     */
    Game(QWidget *parent=NULL);
    /**
     * @brief scene La escena principal.
     */
    QGraphicsScene *scene;
    /**
     * @brief board El tablero grafico.
     */
    Board *board;
    /**
     * @brief iniciarConexion Usa la clase cliente para establecer una conexion con el servidor.
     */
    void iniciarConexion();
    /**
     * @brief sendMessage Envia los mensajes hacia el servidor.
     * @param m El mensaje deseado.
     */
    void sendMessage(string m);
    /**
     * @brief converter La instancia de la clase Converter.
     */
    Converter *converter;
    /**
     * @brief conexion La instancia del cliente.
     */
    Cliente *conexion;
     QVector<double> fitness1, fitness2;
public slots:
    /**
     * @brief recibirMensaje Recibe los mensajes que llegan de parte del servidor.
     * @param mensaje El mensaje JSON.
     */
    void recibirMensaje(QString mensaje);
    /**
     * @brief iniciarIteracion Pide los datos de la iteracion al servidor.
     */
    void iniciarIteracion();


};

#endif // GAME_H
