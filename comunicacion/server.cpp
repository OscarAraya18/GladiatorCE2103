#include "server.h"
#include "transformer.h"
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <include/rapidjson/writer.h>

Server* Server::instance = 0;

Server* Server:: getInstance(){
    if (instance == 0)
        {
            instance = new Server();
        }

        return instance;
}

Server::Server()
{
    Cliente = NULL;
    ClienteConectado = false;

}


bool Server::crear_Socket()
{
    descriptor = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);


    if(descriptor < 0)
        return false;
    info.sin_family = AF_INET;
    info.sin_addr.s_addr = INADDR_ANY;
    info.sin_port = htons(4050);
    memset(&info.sin_zero,0,sizeof(info.sin_zero));

    return true;
}

bool Server::enlazar()
{
    if((bind(descriptor,(sockaddr *)&info,(socklen_t)sizeof(info))) < 0)
        return false;

    listen(descriptor,1);
    return true;
}

bool Server::getClienteConectado() const
{
    return ClienteConectado;
}

void Server::setClienteConectado(bool value)
{
    ClienteConectado = value;
}

int Server::getCliente()
{
    return Cliente;
}

void Server::setCliente(int value)
{
    Cliente = value;
}

void Server::run()
{
    if(!crear_Socket())
        throw string("ERROR AL CREAR EL SOCKET");
    if(!enlazar())
        throw string("ERROR AL LIGAR EL KERNEL");

    while (!ClienteConectado) {
        cout << "ESPERANDO NUEVO CLIENTE....."<<endl;
        dataSocket *data=(struct dataSocket *)malloc(sizeof(dataSocket));
        socklen_t tam = sizeof(data->info);
        data->descriptor = accept(descriptor,(sockaddr*)&data->info,&tam);
        if(data->descriptor < 0)
            cout << "¡ERROR AL ACEPTAR AL CLIENTE!"<<endl;
        else
        {
            cout << "--CLIENTE ACEPTADO CON EXITO--"<<endl;
            //identifico el cliente y lo agrego al atributo de la clase
            setCliente(data->descriptor);
            ClienteConectado = true;
            pthread_t hilo;
            pthread_create(&hilo,0,Server::atenderCliente,(void *)data);
            pthread_detach(hilo);
            }
        }

    close(descriptor);
}

void * Server::atenderCliente(void *obj)
{   auto transformer = Transformer::getInstance();
    dataSocket *data=(dataSocket*)obj;
    char *buffer=(char*)calloc(1024,sizeof (char));
    while (true) {
        string mensaje;
        while (1) {

            int bytes = recv(data->descriptor,buffer,1024,0);
            mensaje.append(buffer,bytes);
            if(bytes < 1024)
                break;
        }
        transformer->funcionGeneral(mensaje.c_str());
        cout<<mensaje<<endl;
        memset(buffer,0,sizeof (buffer));
    }
    close(data->descriptor);
    pthread_exit(nullptr);
}

void Server::setMensaje(const char *msn)
{
    send(getCliente(),msn,strlen(msn),0);

}

void Server::setMensaje(int)
{
    cout<<"enviando a cliente"<<endl;

}

void Server:: setMensaje(int jugador, string mensaje, bool operacion){
    if(operacion){
        send(jugador,mensaje.c_str(),strlen(mensaje.c_str()),0);
    }
    else{
        for(int i=0; i<clientes.size(); i++){
            if(clientes[i]!=jugador){
            send(clientes[i],mensaje.c_str(),strlen(mensaje.c_str()),0);
            }
    }
}
}
void Server::eliminar(){
    Cliente = NULL;

}

