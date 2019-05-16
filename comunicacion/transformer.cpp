#include "transformer.h"
#include <include/rapidjson/document.h>
#include <vector>
#include <include/rapidjson/fwd.h>
#include <include/rapidjson/stringbuffer.h>
#include <include/rapidjson/writer.h>
#include <thread>
#include "server.h"
#include <sys/socket.h>
#include <Backtraking/Backtraking.h>
#include <estructurasLogicas/ManejadorArchivos.h>
#include <logica/Algoritmo.h>


extern Server *server;
extern Matriz *matrizJuego;
extern AStar *astar;
extern Backtracking *backtracking;
extern Algoritmo *genetico1;
extern Algoritmo *genetico2;
extern manejadorArchivos *baseDeDatosPoblacion1;
extern manejadorArchivos *baseDeDatosPoblacion2;
extern listaEnlazada *listaGeneticaPoblacion1;
extern listaEnlazada *listaGeneticaPoblacion2;

using namespace std;
using namespace rapidjson;

Transformer* Transformer::instance = 0;

Transformer* Transformer::getInstance()
{
    if (instance == 0)
    {
        instance = new Transformer();
    }

    return instance;
}

Transformer::Transformer() {
}


void Transformer:: funcionGeneral(const char* json){

    Document document;

    document.Parse(json);

    if(document.HasMember("Iteracion")){

        matrizJuego->colocarTorres();

        //Genetico 1
        genetico1->rungenetico(listaGeneticaPoblacion1);
        cout<<"ya hice el genetico 1"<<endl;
        baseDeDatosPoblacion1->eliminarArchivo();
        double  prom1 = genetico1->pro_fitness();
        matrizJuego->promedioPoblacion1.push_back(prom1);
        baseDeDatosPoblacion1->escribirNuevaPoblacion(genetico1->vec_gladiadores);
        listaGeneticaPoblacion1 = baseDeDatosPoblacion1->leerArchivo();


        //Genetico 2
        genetico2->rungenetico(listaGeneticaPoblacion2);
        cout<<"ya hice el genetico 1"<<endl;

        baseDeDatosPoblacion2->eliminarArchivo();
        double  prom2 = genetico2->pro_fitness();
        matrizJuego->promedioPoblacion2.push_back(prom2);
        baseDeDatosPoblacion2->escribirNuevaPoblacion(genetico2->vec_gladiadores);
        listaGeneticaPoblacion2 = baseDeDatosPoblacion2->leerArchivo();

        astar->iniciar(matrizJuego);
        backtracking->actualizarMatrizLogica(matrizJuego);
        backtracking->runBackTracking(0,0,9,9);

        vector<NodoMatriz*> rutaSinVida1 = astar->getListaRuta();
        rutaConVida1 = matrizJuego->listaRutaConVida(rutaSinVida1, genetico1->mejor_jugador()->getResistencia());

        vector<NodoMatriz*> rutaSinVida2 = backtracking->getListaRuta();
        rutaConVida2 = matrizJuego->listaRutaConVida(rutaSinVida2, genetico2->mejor_jugador()->getResistencia());


        string torres = mensajeTorres();

        server->setMensaje(torres.c_str());


    }
    else if(document.HasMember("inicial")) {
        const Value &a = document["inicial"];
    }

    else if(document.HasMember("respuesta")){
        int n =document["respuesta"].GetInt();
        if(n == 2){
            string mG2 = mensajeGladiador2();
            string c2 = mensajeCamino2();

            server->setMensaje(mG2.c_str());
            server->setMensaje(c2.c_str());
        }
        else if(n == 1){
            string mG1 = mensajeGladiador1();
            string c1 = mensajeCamino1();

            server->setMensaje(mG1.c_str());
            server->setMensaje(c1.c_str());
        }
        else if(n == 3){
            string promedio2 = mensajeGraficaPoblacion2();

            server->setMensaje(promedio2.c_str());
        }


    }
    else if(document.HasMember("grafica")){
        string promedio1 = mensajeGraficaPoblacion1();

        server->setMensaje(promedio1.c_str());

    }
}


void Transformer::enviar(){
    server->setMensaje(server->getCliente());
}


string Transformer::mensajeGladiador1() {
    StringBuffer a;
    Writer<StringBuffer> writer2(a);


    Nodo *aux = genetico1->mejor_jugador();
    writer2.StartObject();
    writer2.Key("G1");

    writer2.String("Gladiador 1");
    writer2.Key("ID");
    writer2.Int(aux->getId());
    writer2.Key("edad");
    writer2.Int(aux->getEdad());
    writer2.Key("super");
    writer2.Int(aux->getProbabilidadSupervivencia());
    writer2.Key("gen");
    writer2.Int(aux->getGeneracionesParaLaSupervivencia());
    writer2.Key("emo");
    writer2.Int(aux->getInteligenciaEmocional());
    writer2.Key("fisica");
    writer2.Int(aux->getCondicionFisica());
    writer2.Key("supe");
    writer2.Int(aux->getFuerzaTroncoSuperior());
    writer2.Key("infe");
    writer2.Int(aux->getFuerzaTroncoInferior());
    writer2.Key("res");
    writer2.Double(aux->getResistencia());

    writer2.EndObject();


    return a.GetString();
}
string Transformer::mensajeGladiador2() {
    StringBuffer a;
    Writer<StringBuffer> writer2(a);

    writer2.StartObject();
    writer2.Key("G2");

    Nodo *aux = genetico2->mejor_jugador();

    writer2.String("Gladiador 2");
    writer2.Key("ID");
    writer2.Int(aux->getId());
    writer2.Key("edad");
    writer2.Int(aux->getEdad());
    writer2.Key("super");
    writer2.Int(aux->getProbabilidadSupervivencia());
    writer2.Key("gen");
    writer2.Int(aux->getGeneracionesParaLaSupervivencia());
    writer2.Key("emo");
    writer2.Int(aux->getInteligenciaEmocional());
    writer2.Key("fisica");
    writer2.Int(aux->getCondicionFisica());
    writer2.Key("supe");
    writer2.Int(aux->getFuerzaTroncoSuperior());
    writer2.Key("infe");
    writer2.Int(aux->getFuerzaTroncoInferior());
    writer2.Key("res");
    writer2.Double(aux->getResistencia());

    writer2.EndObject();


    return a.GetString();
}
string Transformer::mensajeCamino1() {



    StringBuffer a;
    Writer<StringBuffer> writer2(a);
    writer2.StartObject();
    writer2.Key("camino1");
    writer2.StartArray();

    for(int i = 0; i < rutaConVida1.size(); i++){
        StringBuffer b;
        Writer<StringBuffer> writer(b);
        writer.StartObject();
        writer.Key("x");
        writer.Int(rutaConVida1.at(i)->fila);
        writer.Key("y");
        writer.Int(rutaConVida1.at(i)->columna);
        writer.Key("vida");
        writer.Int(rutaConVida1.at(i)->vida);
        writer.EndObject();

        writer2.String(b.GetString());
    }
    writer2.EndArray();
    writer2.EndObject();

    return a.GetString();
}

string Transformer::mensajeCamino2() {
    StringBuffer a;
    Writer<StringBuffer> writer2(a);
    writer2.StartObject();
    writer2.Key("camino2");
    writer2.StartArray();

    for(int i = 0; i < rutaConVida2.size(); i++){
        StringBuffer b;
        Writer<StringBuffer> writer(b);
        writer.StartObject();
        writer.Key("x");
        writer.Int(rutaConVida2.at(i)->columna);
        writer.Key("y");
        writer.Int(rutaConVida2.at(i)->fila);
        writer.Key("vida");
        writer.Int(rutaConVida2.at(i)->vida);
        writer.EndObject();

        writer2.String(b.GetString());
    }
    writer2.EndArray();
    writer2.EndObject();

    return a.GetString();
}

string Transformer::mensajeTorres() {




    StringBuffer a;
    Writer<StringBuffer> writer2(a);
    writer2.StartObject();
    writer2.Key("torres");
    writer2.StartArray();

    for(int i = 0; i < matrizJuego->listaTorres.size(); i++){
        if((matrizJuego->listaTorres.at(i)->fila == matrizJuego->listaTorres.at(i)->columna)
                && (matrizJuego->listaTorres.at(i)->correccion)){
            matrizJuego->listaTorres.at(i)->columna=1;
        }

        StringBuffer b;
        Writer<StringBuffer> writer(b);
        writer.StartObject();
        writer.Key("x");
        cout<<"FILA "<<matrizJuego->listaTorres.at(i)->fila<<endl;
        writer.Int(matrizJuego->listaTorres.at(i)->fila);
        writer.Key("y");
        cout<<"COLUMNA "<<matrizJuego->listaTorres.at(i)->columna<<endl;
        writer.Int(matrizJuego->listaTorres.at(i)->columna);
        writer.Key("tipo");
        writer.Int(matrizJuego->listaTorres.at(i)->getTorreEnemiga()->getTipoTorre());
        writer.EndObject();

        writer2.String(b.GetString());
    }
    writer2.EndArray();
    writer2.EndObject();

    return a.GetString();
}




const char* Transformer::generarJSON() {
    StringBuffer a;

    Writer<StringBuffer> writer(a);

    writer.StartObject();
    writer.Key("Itera");

    writer.StartArray();

    StringBuffer b;
    Writer<StringBuffer> writer2(b);

    writer2.StartObject();
    writer2.Key("Enemy1");
    writer2.StartArray();

    StringBuffer c;
    Writer<StringBuffer> writer3(c);
    writer3.StartObject();
    writer3.Key("Atri");
    writer3.StartArray();

    StringBuffer d;
    Writer<StringBuffer> writer4(d);
    writer4.StartObject();

    writer4.Key("ID");
    writer4.Int(0);
    writer4.Key("edad");
    writer4.Int(0);
    writer4.Key("super");
    writer4.Int(0);
    writer4.Key("gen");
    writer4.Int(0);
    writer4.Key("emo");
    writer4.Int(0);
    writer4.Key("fisica");
    writer4.Int(0);
    writer4.Key("supe");
    writer4.Int(0);
    writer4.Key("infe");
    writer4.Int(0);
    writer4.Key("res");
    writer4.Int(0);
    writer4.EndObject();
    writer3.String(d.GetString());

    writer3.EndArray();
    writer3.EndObject();

    writer2.String(c.GetString());

    StringBuffer e;
    Writer<StringBuffer> writer5(e);
    writer5.StartObject();
    writer5.Key("camino");
    writer5.StartArray();

    for(int i=0; i< 10; i++){
        StringBuffer f;
        Writer<StringBuffer> writer6;
        writer6.StartObject();
        writer6.Key("x");
        srand(time(NULL));
        int n = 0 + rand() % 9;
        writer.Int(n);
        writer6.Key("y");
        srand(time(NULL));
        int n1 = 0 + rand() % 9;
        writer6.Int(n1);
        writer6.Key("vida");
        writer6.Int(10);
        writer6.EndObject();

        writer5.String(f.GetString());
    }
    writer5.EndArray();
    writer5.EndObject();

    writer2.String(e.GetString());

    writer2.EndArray();
    writer2.EndObject();

    writer.String(b.GetString());
    writer.EndArray();
    writer.EndObject();

    return a.GetString();

}

string Transformer::mensajeGraficaPoblacion1() {
    StringBuffer a;
    Writer<StringBuffer> writer2(a);
    writer2.StartObject();
    writer2.Key("poblacion1");
    writer2.StartArray();

    for(int i = 0; i < matrizJuego->promedioPoblacion1.size(); i++){

        StringBuffer b;
        Writer<StringBuffer> writer(b);
        writer.StartObject();
        writer.Key("fitness");
        writer.Double(matrizJuego->promedioPoblacion1.at(i));
        writer.EndObject();
        writer2.String(b.GetString());
    }
    writer2.EndArray();
    writer2.EndObject();

    return a.GetString();
}

string Transformer::mensajeGraficaPoblacion2() {
    StringBuffer a;
    Writer<StringBuffer> writer2(a);
    writer2.StartObject();
    writer2.Key("poblacion2");
    writer2.StartArray();

    for(int i = 0; i < matrizJuego->promedioPoblacion2.size(); i++){

        StringBuffer b;
        Writer<StringBuffer> writer(b);
        writer.StartObject();
        writer.Key("fitness");
        writer.Double(matrizJuego->promedioPoblacion2.at(i));
        writer.EndObject();
        writer2.String(b.GetString());
    }
    writer2.EndArray();
    writer2.EndObject();

    return a.GetString();
}




