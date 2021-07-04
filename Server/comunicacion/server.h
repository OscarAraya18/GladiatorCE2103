#ifndef SERVER_H
#define SERVER_H
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <unistd.h>



using namespace std;

struct dataSocket{
    int descriptor;
    sockaddr_in info;
};
/**
 * @brief Esta clase se encarga de establecer una comunicacion con clinetes mediante Sockets.
 */
class Server
{
public:
    /**
     * Inicia un hilo en donde tiene como objetivo iniciar la conexion del servidor.
     */
    void run();
    /**
     * Se encarga de enviar un mensaje JSON hacia el cliente.
     * @param msn Un mensaje JSON.
     */
    void setMensaje(const char *msn);
    /**
     * Se encarga de enviar un mensaje INT hacia el cliente.
     */
    void setMensaje(int);
    /**
     * Se encarga de enviar un mensaje hacia el cliente.
     */
    void setMensaje(int, string, bool);
    /**
     * Elimina la conexion establecida con el cliente.
     */
    void eliminar();
    /**
     * Se encarga de retornar la instancia del servidor.
     * @return La instancia del servidor.
     */
    static Server* getInstance();
    vector<int> clientes;
    /**
     * Retorna el descriptor del cliente.
     * @return El descriptor del cliente.
     */
    int getCliente();
    /**
     * Modifica el descriptor del cliente.
     * @param value El nuevo descriptor del cliente.
     */
    void setCliente(int value);
    /**
     * Retorna un booleano para verificar si el cliente esta conectado.
     * @return Un booleano true o false.
     */
    bool getClienteConectado() const;
    /**
     * Modifica el valor del clienteConectado.
     * @param value El nuevo valor booleano para el atributo cliente conectado.
     */
    void setClienteConectado(bool value);

private:
    /**
     * Un entero que hace referencia al cliente.
     */
    int descriptor;
    /**
     * La insformacion del cliente.
     */
    sockaddr_in info;
    /**
     * Crea el socket para poder establecer la conexion.
     * @return Un booleano que dice si se creo correctamente o no.
     */
    bool crear_Socket();
    /**
     * Enlaza una conexion con los clientes.
     * @return Un booleano que dice si ha podido establecer la conexion.
     */
    bool enlazar();
    /**
     * La instancia del servidor.
     */
    static Server* instance;
    /**
     * El identificador del cliente.
     */
    int Cliente;
    /**
     * Indica el estado de la conexion del cliente.
     */
    bool ClienteConectado;
    /**
     * Constructor de la clase Server.
     */
    Server();
    /**
     * Una vez que un cliente se ha conectado, inicia un bucle para atenderlo directamente.
     * @param obj Puntero.
     * @return Un estado.
     */
    static void * atenderCliente(void *obj);

};


#endif // SERVER_H
