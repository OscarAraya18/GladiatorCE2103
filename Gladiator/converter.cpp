#include "converter.h"
#include "game.h"
#include "towera.h"
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

}

void Converter:: funcionGeneral(const char* json){

    Document document;

    document.Parse(json);

    if(document.HasMember("torres")){
        const Value& a = document["torres"];
        for (auto& v : a.GetArray()){
            leerTorres(v.GetString());
        }
        string r = respuesta(1);
        game->sendMessage(r.c_str());
    }
    else if(document.HasMember("G1")){
        leerAtri1(json);
    }
    else if(document.HasMember("G2")){
        leerAtri2(json);
    }
    else if(document.HasMember("camino1")){
        leerCamino1(json);

        string r = respuesta(2);
        game->sendMessage(r.c_str());
    }
    else if(document.HasMember("camino2")){
        leerCamino2(json);
    }


}

void Converter::leerItera(const char *json)
{
    Document document;

    document.Parse(json);

    if(document.HasMember("E1")){
        leerEnemy1(document["E1"].GetString());
    }
    else if(document.HasMember("E2")){
       leerEnemy1(document["E2"].GetString());

    }
    else if(document.HasMember("Torres")){
        const Value& a = document["torres"];
        for (auto& v : a.GetArray()){
            leerTorres(v.GetString());
        }
    }

}

void Converter::leerEnemy1(const char *json)
{
    Document document;

    document.Parse(json);

    if(document.HasMember("Atri")){
        const Value& a = document["Atri"];
        for (auto& v : a.GetArray()){
           leerAtri1(v.GetString());
        }
    }
    else if(document.HasMember("camino")){
        leerCamino1(document["camino"].GetString());
    }
}

void Converter::leerEnemy2(const char *json)
{
    Document document;

    document.Parse(json);

    if (document.HasMember("Atri")){
            const Value& a = document["Atri"];
            for (auto& v : a.GetArray()){
               leerAtri2(v.GetString());
            }
        }
        else if(document.HasMember("camino")){
            leerCamino2(document["camino"].GetString());
        }

}

void Converter::leerTorres(const char *json)
{
    Document document;

    document.Parse(json);

    int t = document["tipo"].GetInt();

    if(t == 1){
      pasarTorre1(json);
    }
    else if(t ==2){
        pasarTorre2(json);
    }
    else if(t == 3){
      pasarTorre3(json);
        }
}

void Converter::leerAtri1(const char *json)
{
    game->board->agregarGladiator1();

    Document document;

    document.Parse(json);

    int id;
    int edad;
    int probSupervivencia;
    int genEsperadas;
    int iEmocional;
    int condFisica;
    int fTroncoSupe;
    int fTroncoInfe;
    double resistencia;


   id = document["ID"].GetInt();
   edad = document["edad"].GetInt();
   probSupervivencia = document["super"].GetInt();
   genEsperadas = document["gen"].GetInt();
   iEmocional = document["emo"].GetInt();
   condFisica = document["fisica"].GetInt();
   fTroncoSupe = document["supe"].GetInt();
   fTroncoInfe = document["infe"].GetInt();
   resistencia = document["res"].GetDouble();

   //se rellenan las specs1
   game->board->specs->setIdT(QString::number(id));
   game->board->specs->setEdadT(QString::number(edad));
   game->board->specs->setProbSuperT(QString::number(probSupervivencia));
   game->board->specs->setGenEsperadasT(QString::number(genEsperadas));
   game->board->specs->setIEmocionalT(QString::number(iEmocional));
   game->board->specs->setCondFisicaT(QString::number(condFisica));
   game->board->specs->setFTroncoSupT(QString::number(fTroncoSupe));
   game->board->specs->setFTroncoInfT(QString::number(fTroncoInfe));
   game->board->specs->setResistenciaT(QString::number(resistencia));


}

void Converter::leerCamino1(const char *json)
{
    Document document;

    document.Parse(json);

    const Value& a = document["camino1"];

    for (auto& v : a.GetArray()){
        pasarPunto1(v.GetString());
    }

    game->board->enemy->move_gladiator();
}

void Converter::leerAtri2(const char *json)
{
    game->board->agregarGladiator2();

    Document document;

    document.Parse(json);

    int id;
    int edad;
    int probSupervivencia;
    int genEsperadas;
    int iEmocional;
    int condFisica;
    int fTroncoSupe;
    int fTroncoInfe;
    double resistencia;


   id = document["ID"].GetInt();
   edad = document["edad"].GetInt();
   probSupervivencia = document["super"].GetInt();
   genEsperadas = document["gen"].GetInt();
   iEmocional = document["emo"].GetInt();
   condFisica = document["fisica"].GetInt();
   fTroncoSupe = document["supe"].GetInt();
   fTroncoInfe = document["infe"].GetInt();
   resistencia = document["res"].GetDouble();

   //se rellenan las specs2
   game->board->specs2->setIdT(QString::number(id));
   game->board->specs2->setEdadT(QString::number(edad));
   game->board->specs2->setProbSuperT(QString::number(probSupervivencia));
   game->board->specs2->setGenEsperadasT(QString::number(genEsperadas));
   game->board->specs2->setIEmocionalT(QString::number(iEmocional));
   game->board->specs2->setCondFisicaT(QString::number(condFisica));
   game->board->specs2->setFTroncoSupT(QString::number(fTroncoSupe));
   game->board->specs2->setFTroncoInfT(QString::number(fTroncoInfe));
   game->board->specs2->setResistenciaT(QString::number(resistencia));


}

void Converter::leerCamino2(const char *json)
{
    Document document;

    document.Parse(json);

    const Value& a = document["camino2"];

    for (auto& v : a.GetArray()){
        pasarPunto2(v.GetString());
    }
    //game->board->enemy2->move_gladiator();
    //game->board->enemy->move_gladiator();

}

void Converter::pasarPunto1(const char *json)
{
    Document document;

    document.Parse(json);

    int x;
    int y;
    int vida;

    x = document["x"].GetInt();
    y = document["y"].GetInt();
    vida = document["vida"].GetInt();

    Point *p = new Point(x,y,vida);
    game->board->enemy->camino.append(p);
}

void Converter::pasarPunto2(const char *json)
{
    Document document;

    document.Parse(json);

    int x;
    int y;
    int vida;

    x = document["x"].GetInt();
    y = document["y"].GetInt();
    vida = document["vida"].GetInt();

    Point *p = new Point(x,y,vida);
    game->board->enemy2->camino.append(p);

}

void Converter::pasarTorre1(const char *json)
{
    Document document;

    document.Parse(json);

    int x;
    int y;

    x = document["x"].GetInt();
    y = document["y"].GetInt();

    game->board->agregarTorre1(x,y);
}

void Converter::pasarTorre2(const char *json)
{
    Document document;

    document.Parse(json);

    int x;
    int y;

    x = document["x"].GetInt();
    y = document["y"].GetInt();

    game->board->agregarTorre2(x,y);
}

void Converter::pasarTorre3(const char *json)
{
    Document document;

    document.Parse(json);

    int x;
    int y;

    x = document["x"].GetInt();
    y = document["y"].GetInt();

    game->board->agregarTorre3(x,y);
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

string Converter:: respuesta(int i){
    StringBuffer a;
    Writer<StringBuffer> writer(a);

    writer.StartObject();
    writer.Key("respuesta");
    writer.Int(i);
    writer.EndObject();

    string mensaje = a.GetString();

    return mensaje;
}
