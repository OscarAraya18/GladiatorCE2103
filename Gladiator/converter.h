#ifndef CONVERTER_H
#define CONVERTER_H
#include <include/rapidjson/document.h>


using namespace rapidjson;
using namespace std;

class Converter {


private:

    static Converter* instance;
    Converter();

public:

    int claveGenerada;
    //booleano para saber si ya puedo abrir el juego o no
    bool aceptado;
    static Converter* getInstance();
    //void PalabraToJson(QList<Ficha*> fichasJugadas);
    void mostrarClave(const char*);
    void funcionGeneral(const char*);
    string iniciarIte();

};
#endif // CONVERTER_H
