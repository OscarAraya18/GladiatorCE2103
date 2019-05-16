#ifndef CLIENTE_H
#define CLIENTE_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <QObject>
#include <arpa/inet.h>

using namespace std;
/**
 * @brief The Cliente class Permite la comunicaciòn con un servidor especìfico. Por ende
 * se debe especificar la direcciòn ip y el puerto del servidor.
 */
class Cliente: public QObject
{
    Q_OBJECT
public:
    /**
     * @brief Cliente Constructor de la clase Cliente.
     */
    Cliente();
    /**
     * @brief conectar Inicia la conexion con el servidor.
     * @return true en caso de una conexion exitosa y false en caso contrario.
     */
    bool conectar();
    /**
     * @brief setMensaje Envia mensajes hacia el servidor.
     * @param msn Un mensaje JSON.
     */
    void setMensaje(const char *msn);
private:
    /**
     * @brief descriptor El identificador del servidor.
     */
    int descriptor;
    /**
     * @brief info Toda la informaciòn de servidor.
     */
    sockaddr_in info;
    /**
     * @brief controlador Bucle que interactùa con el servidor  constantemente.
     * @param obj
     * @return
     */
    static void * controlador(void *obj);
signals:
    /**
     * @brief NewMensaje Cuando me llega un nuevo mensaje de parte del servidor.
     * @param msn Un mensaje JSON,
     */
    void NewMensaje(QString msn);
};
#endif // CLIENTE_H
