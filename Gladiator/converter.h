#ifndef CONVERTER_H
#define CONVERTER_H
#include <include/rapidjson/document.h>
using namespace rapidjson;
using namespace std;
/**
 * @brief The Converter class Se encarga de traducir los mensajes JSON y tambien
 * està en la capacidad de transformar los mensajes a tipo JSON.
 */
class Converter {
private:
    /**
     * @brief instance Una ùnica instancia para la clase Converter.
     */
    static Converter* instance;
    /**
     * @brief Converter Constructor de la clase Converter.
     */
    Converter();
public:
    /**
     * @brief getInstance Retorna la ùnica instancia de la clase.
     * @return Una instancia.
     */
    static Converter* getInstance();
    /**
     * @brief funcionGeneral Un metodo que se encarga de direccionar diferentes tipos de solicitudes
     * enviando los mensajes recibidos hacia un mètodo especìfico.
     */
    void funcionGeneral(const char*);
    /**
     * @brief leerItera Lee el primer mensaje de la iteraciòn.
     * @param json El mensaje.
     */
    void leerItera(const char *json);
    /**
     * @brief leerEnemy1 Recibe un JSON que contiene las caracteristicas del primer
     * gladiador.
     * @param json El mensaje.
     */
    void leerEnemy1(const char* json);
    /**
     * @brief leerEnemy2 Recibe un JSON que contiene las caracteristicas del segundo
     * gladiador.
     * @param json El mensaje.
     */
    void leerEnemy2(const char *json);
    /**
     * @brief leerTorres Recibe un JSON que contiene las pociciones de las torres y ademas
     * indica las respectivas posiciones en el tablero.
     * @param json El mensaje.
     */
    void leerTorres(const char* json);

    void leerAtri1(const char *json);
    /**
     * @brief leerCamino1 Recibe un JSON que contiene la ruta que debe seguir el primer gladiador en el tablero.
     * @param json El mensaje.
     */
    void leerCamino1(const char* json);
    void leerAtri2(const char *json);
    /**
     * @brief leerCamino2 Recibe un JSON que contiene la ruta que debe seguir el segundo gladiador en el tablero.
     * @param json El mensaje.
     */
    void leerCamino2(const char* json);
    /**
     * @brief pasarPunto1 Le pasa la ruta que debe seguir el gladiador 1 al juego.
     * @param json La ruta 1.
     */
    void pasarPunto1(const char* json);
    /**
     * @brief pasarPunto2 Le pasa la ruta que debe seguir el gladiador 2 al juego.
     * @param json La ruta 2.
     */
    void pasarPunto2(const char* json);
    /**
     * @brief pasarTorre1 Le pasa las posiciones de las torres tipo 1 al juego.
     * @param json Las posiciones de las torres tipo 1.
     */
    void pasarTorre1(const char* json);
    /**
     * @brief pasarTorre2 Le pasa las posiciones de las torres tipo 2 al juego.
     * @param json Las posiciones de las torres tipo 2.
     */
    void pasarTorre2(const char *json);
    /**
     * @brief pasarTorre3 Le pasa las posiciones de las torres tipo 3 al juego.
     * @param json Las posiciones de las torres tipo 3.
     */
    void pasarTorre3(const char *json);
    /**
     * @brief iniciarIte Redacta un mensaje al servidor indicàndole que le envìe los primeros datos.
     * @return El mensaje tipo JSON.
     */
    string iniciarIte();
    /**
     * @brief respuesta Redacta un mensaje al servidor indicandole que le envie los segundos datos.
     * @param i El identificador de solicitud.
     * @return El mensaje tipo JSON.
     */
    string respuesta(int i);
    /**
     * @brief pedirDatosGrafica Realiza una peticion al servidor para que le envie los datos de la grafica.
     * @return
     */
    string pedirDatosGrafica();
    /**
     * @brief pasarFitness1 Toma la informacion del JSON y llena una lista de fitness para la primera poblacion.
     * @param json Una lista de fitness de la primera poblacion.
     */
    void pasarFitness1(const char *json);
    /**
     * @brief pasarFitness2 Toma la informacion del JSON y llena una lista de fitness para la segunda informacion.
     * @param json Una lista de fitness de la segunda poblacion.
     */
    void pasarFitness2(const char *json);

};
#endif // CONVERTER_H
