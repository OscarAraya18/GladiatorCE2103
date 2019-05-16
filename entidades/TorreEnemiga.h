#ifndef GLADIATORCE2103_TORREENEMIGA_H
#define GLADIATORCE2103_TORREENEMIGA_H

/**
 * @brief Esta clase es para manejar las torres en el tablero
 */
class TorreEnemiga {
public:
    /**
     * Constructor de la clase TorreEnemiga
     * @param tipoTorre el tipo de torre a crear
     */
    TorreEnemiga(int tipoTorre);

    /**
     * Accede al tipo de torre
     * @return el tipo de torre
     */
    int getTipoTorre();


private:
    /**
     * Numero del 1 al 3 que indica si es una torre normal, torre con fuego o torre explosiva
     */
    int tipoTorre;

};


#endif //GLADIATORCE2103_TORREENEMIGA_H
