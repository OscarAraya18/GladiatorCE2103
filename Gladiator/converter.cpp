#include "converter.h"
#include "game.h"
#include <include/rapidjson/document.h>
#include <vector>
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <include/rapidjson/writer.h>
#include <string>
#include <string.h>
#include <QDebug>
#include <iostream>
#include <sys/socket.h>

extern Game *game;

using namespace std;

Converter* Converter::instance = 0;

Converter* Converter::getInstance()
{
    if (instance == 0)
    {
        instance = new Converter();
    }

    return instance;
}

Converter::Converter() {
    claveGenerada = NULL;
    aceptado = false;
    //reparta = false;
}

void Converter:: funcionGeneral(const char* json){

    Document document;

    document.Parse(json);

    if(document.HasMember("clave")){
        //assert(document["clave"].IsObject());
       //claveGenerada = document["clave"].GetInt();
    }
    else if(document.HasMember("palabra")){

    }
    else if(document.HasMember("inicial")){
        //generarClave(document["inicial"].GetInt());
    }
    else if(document.HasMember("respuesta")){
        if(document["respuesta"].GetBool()){
            //aceptado = true;
            //reparta = true;
        }
        else{
            aceptado = false;
        }
    }
    else if(document.HasMember("fichas")){
        cout << "cerote" << endl;
    }

}

string Converter::iniciarIte()
{
    StringBuffer a;
    Writer<StringBuffer> writer(a);

    writer.StartObject();
    writer.Key("Iteracion");
    writer.Int(1);
    writer.EndObject();

    string mensaje = a.GetString();

    return mensaje;
}

